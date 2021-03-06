/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#include "PlusConfigure.h"
#include "PlusTrackedFrame.h"
#include "vtkObjectFactory.h"
#include "vtkPlusRecursiveCriticalSection.h"
#include "vtkTransform.h"
#include "vtkPlusTransformRepository.h"
#include "vtksys/SystemTools.hxx"

//----------------------------------------------------------------------------

vtkStandardNewMacro(vtkPlusTransformRepository);

//----------------------------------------------------------------------------
vtkPlusTransformRepository::TransformInfo::TransformInfo()
  : m_Transform(vtkTransform::New())
  , m_ToolStatus(TOOL_OK)
  , m_IsComputed(false)
  , m_IsPersistent(false)
  , m_Error(-1.0)
{

}

//----------------------------------------------------------------------------
vtkPlusTransformRepository::TransformInfo::~TransformInfo()
{
  if (m_Transform != NULL)
  {
    m_Transform->Delete();
    m_Transform = NULL;
  }
}

//----------------------------------------------------------------------------
vtkPlusTransformRepository::TransformInfo::TransformInfo(const TransformInfo& obj)
{
  m_Transform = obj.m_Transform;
  if (m_Transform != NULL)
  {
    m_Transform->Register(NULL);
  }
  m_IsComputed = obj.m_IsComputed;
  m_ToolStatus = obj.m_ToolStatus;
  m_IsPersistent = obj.m_IsPersistent;
  m_Date = obj.m_Date;
  m_Error = obj.m_Error;

}
//----------------------------------------------------------------------------
vtkPlusTransformRepository::TransformInfo& vtkPlusTransformRepository::TransformInfo::operator=(const TransformInfo& obj)
{
  if (m_Transform != NULL)
  {
    m_Transform->Delete();
    m_Transform = NULL;
  }
  m_Transform = obj.m_Transform;
  if (m_Transform != NULL)
  {
    m_Transform->Register(NULL);
  }
  m_IsComputed = obj.m_IsComputed;
  m_ToolStatus = obj.m_ToolStatus;
  m_IsPersistent = obj.m_IsPersistent;
  m_Date = obj.m_Date;
  m_Error = obj.m_Error;
  return *this;
}

//----------------------------------------------------------------------------
vtkPlusTransformRepository::vtkPlusTransformRepository()
  : CriticalSection(vtkPlusRecursiveCriticalSection::New())
{

}

//----------------------------------------------------------------------------
vtkPlusTransformRepository::~vtkPlusTransformRepository()
{
  this->CriticalSection->Delete();
  this->CriticalSection = NULL;
}

//----------------------------------------------------------------------------
void vtkPlusTransformRepository::PrintSelf(ostream& os, vtkIndent indent)
{
  vtkObject::PrintSelf(os, indent);

  for (CoordFrameToCoordFrameToTransformMapType::iterator coordFrame = this->CoordinateFrames.begin(); coordFrame != this->CoordinateFrames.end(); ++coordFrame)
  {
    os << indent << coordFrame->first << " coordinate frame transforms:\n";
    for (CoordFrameToTransformMapType::iterator transformInfo = coordFrame->second.begin(); transformInfo != coordFrame->second.end(); ++transformInfo)
    {
      os << indent << "  To " << transformInfo->first << ": "
         << (transformInfo->second.IsValid() ? "valid" : "invalid") << ", "
         << (transformInfo->second.m_IsPersistent ? "persistent" : "non-persistent") << ", "
         << (transformInfo->second.m_IsComputed ? "computed" : "original") << "\n";
      if (transformInfo->second.m_Transform != NULL && transformInfo->second.m_Transform->GetMatrix() != NULL)
      {
        vtkMatrix4x4* transformMx = transformInfo->second.m_Transform->GetMatrix();
        os << indent << "     " << transformMx->Element[0][0] << " " << transformMx->Element[0][1] << " " << transformMx->Element[0][2] << " " << transformMx->Element[0][3] << " " << "\n";
        os << indent << "     " << transformMx->Element[1][0] << " " << transformMx->Element[1][1] << " " << transformMx->Element[1][2] << " " << transformMx->Element[1][3] << " " << "\n";
        os << indent << "     " << transformMx->Element[2][0] << " " << transformMx->Element[2][1] << " " << transformMx->Element[2][2] << " " << transformMx->Element[2][3] << " " << "\n";
        os << indent << "     " << transformMx->Element[3][0] << " " << transformMx->Element[3][1] << " " << transformMx->Element[3][2] << " " << transformMx->Element[3][3] << " " << "\n";
      }
      else
      {
        os << indent << "     No transform is available\n";
      }
    }
  }
}

//----------------------------------------------------------------------------
vtkPlusTransformRepository::TransformInfo* vtkPlusTransformRepository::GetOriginalTransform(const PlusTransformName& aTransformName) const
{
  CoordFrameToTransformMapType& fromCoordFrame = this->CoordinateFrames[aTransformName.From()];

  // Check if the transform already exist
  CoordFrameToTransformMapType::iterator fromToTransformInfoIt = fromCoordFrame.find(aTransformName.To());
  if (fromToTransformInfoIt != fromCoordFrame.end())
  {
    // transform is found
    return &(fromToTransformInfoIt->second);
  }
  // transform is not found
  return NULL;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::SetTransforms(PlusTrackedFrame& trackedFrame)
{
  std::vector<PlusTransformName> transformNames;
  trackedFrame.GetFrameTransformNameList(transformNames);

  int numberOfErrors(0);

  for (std::vector<PlusTransformName>::iterator it = transformNames.begin(); it != transformNames.end(); ++it)
  {
    std::string trName;
    it->GetTransformName(trName);

    if (it->From() == it->To())
    {
      LOG_ERROR("Setting a transform to itself is not allowed: " << trName);
      continue;
    }

    vtkSmartPointer<vtkMatrix4x4> matrix = vtkSmartPointer<vtkMatrix4x4>::New();
    if (trackedFrame.GetFrameTransform(*it, matrix) != PLUS_SUCCESS)
    {
      LOG_ERROR("Failed to get frame transform from tracked frame: " << trName);
      numberOfErrors++;
      continue;
    }

    ToolStatus status = TOOL_INVALID;
    if (trackedFrame.GetFrameTransformStatus(*it, status) != PLUS_SUCCESS)
    {
      LOG_ERROR("Failed to get frame transform from tracked frame: " << trName);
      numberOfErrors++;
      continue;
    }

    if (this->SetTransform(*it, matrix, status) != PLUS_SUCCESS)
    {
      LOG_ERROR("Failed to set transform to repository: " << trName);
      numberOfErrors++;
      continue;
    }
  }

  return (numberOfErrors == 0 ? PLUS_SUCCESS : PLUS_FAIL);
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::SetTransform(const PlusTransformName& aTransformName, vtkMatrix4x4* matrix, ToolStatus toolStatus/*=TOOL_OK*/)
{
  if (!aTransformName.IsValid())
  {
    LOG_ERROR("Transform name is invalid");
    return PLUS_FAIL;
  }

  if (aTransformName.From() == aTransformName.To())
  {
    LOG_ERROR("Setting a transform to itself is not allowed: " << aTransformName.GetTransformName());
    return PLUS_FAIL;
  }

  PlusLockGuard<vtkPlusRecursiveCriticalSection> accessGuard(this->CriticalSection);

  // Check if the transform already exist
  TransformInfo* fromToTransformInfo = GetOriginalTransform(aTransformName);
  if (fromToTransformInfo != NULL)
  {
    // Transform already exists
    if (fromToTransformInfo->m_IsComputed)
    {
      // The transform already exists and it is computed (not original), so reject the transformation update
      LOG_ERROR("The " << aTransformName.From() << "To" << aTransformName.To() <<
                " transform cannot be set, as the inverse (" << aTransformName.To() << "To" <<
                aTransformName.From() << ") transform already exists");
      return PLUS_FAIL;
    }

    // This is an original transform that already exists, just update it
    // Update the matrix (the inverse matrix is automatically updated using vtkTransform pipeline)
    if (matrix != NULL)
    {
      fromToTransformInfo->m_Transform->SetMatrix(matrix);
    }
    // Set the status of the original transform
    fromToTransformInfo->m_ToolStatus = toolStatus;

    // Set the same status for the computed inverse transform
    PlusTransformName toFromTransformName(aTransformName.To(), aTransformName.From());
    TransformInfo* toFromTransformInfo = GetOriginalTransform(toFromTransformName);
    if (toFromTransformInfo == NULL)
    {
      LOG_ERROR("The computed " << aTransformName.To() << "To" << aTransformName.From()
                << " transform is missing. Cannot set its status");
      return PLUS_FAIL;
    }
    toFromTransformInfo->m_ToolStatus = toolStatus;
    return PLUS_SUCCESS;
  }
  // The transform does not exist yet, add it now

  TransformInfoListType transformInfoList;
  if (FindPath(aTransformName, transformInfoList, NULL, true /*silent*/) == PLUS_SUCCESS)
  {
    // a path already exist between the two coordinate frames
    // adding a new transform between these would result in a circle
    LOG_ERROR("A transform path already exists between " << aTransformName.From() <<
              " and " << aTransformName.To());
    return PLUS_FAIL;
  }

  // Create the from->to transform
  CoordFrameToTransformMapType& fromCoordFrame = this->CoordinateFrames[aTransformName.From()];
  fromCoordFrame[aTransformName.To()].m_IsComputed = false;
  if (matrix != NULL)
  {
    fromCoordFrame[aTransformName.To()].m_Transform->SetMatrix(matrix);
  }

  fromCoordFrame[aTransformName.To()].m_ToolStatus = toolStatus;

  // Create the to->from inverse transform
  CoordFrameToTransformMapType& toCoordFrame = this->CoordinateFrames[aTransformName.To()];
  toCoordFrame[aTransformName.From()].m_IsComputed = true;
  toCoordFrame[aTransformName.From()].m_Transform->SetInput(fromCoordFrame[aTransformName.To()].m_Transform);
  toCoordFrame[aTransformName.From()].m_Transform->Inverse();
  toCoordFrame[aTransformName.From()].m_ToolStatus = toolStatus;
  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::SetTransformStatus(const PlusTransformName& aTransformName, ToolStatus toolStatus)
{
  if (aTransformName.From() == aTransformName.To())
  {
    LOG_ERROR("Setting a transform to itself is not allowed: " << aTransformName.GetTransformName());
    return PLUS_FAIL;
  }
  return SetTransform(aTransformName, NULL, toolStatus);
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::GetTransform(const PlusTransformName& aTransformName, vtkMatrix4x4* matrix, ToolStatus* toolStatus /*=NULL*/) const
{
  if (!aTransformName.IsValid())
  {
    LOG_ERROR("Transform name is invalid");
    return PLUS_FAIL;
  }

  if (aTransformName.From() == aTransformName.To())
  {
    if (matrix != NULL)
    {
      matrix->Identity();
    }
    return PLUS_SUCCESS;
  }

  PlusLockGuard<vtkPlusRecursiveCriticalSection> accessGuard(this->CriticalSection);

  // Check if we can find the transform by combining the input transforms
  // To improve performance the already found paths could be stored in a map of transform name -> transformInfoList
  TransformInfoListType transformInfoList;
  if (FindPath(aTransformName, transformInfoList) != PLUS_SUCCESS)
  {
    // the transform cannot be computed, error has been already logged by FindPath
    *toolStatus = TOOL_PATH_NOT_FOUND;
    return PLUS_FAIL;
  }

  // Create transform chain and compute transform status
  vtkSmartPointer<vtkTransform> combinedTransform = vtkSmartPointer<vtkTransform>::New();
  ToolStatus combinedToolStatus(TOOL_OK);
  for (TransformInfoListType::iterator transformInfo = transformInfoList.begin(); transformInfo != transformInfoList.end(); ++transformInfo)
  {
    combinedTransform->Concatenate((*transformInfo)->m_Transform);
    combinedToolStatus = (ToolStatus)std::max(combinedToolStatus, (*transformInfo)->m_ToolStatus); // Not a perfect solution, as one error would overwrite another, but at least it provides some error information
  }
  // Save the results
  if (matrix != NULL)
  {
    matrix->DeepCopy(combinedTransform->GetMatrix());
  }

  if (toolStatus != NULL)
  {
    (*toolStatus) = combinedToolStatus;
  }

  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::GetTransformValid(const PlusTransformName& aTransformName, bool& isValid)
{
  ToolStatus status;
  if (GetTransform(aTransformName, NULL, &status) != PLUS_SUCCESS)
  {
    return PLUS_FAIL;
  }
  isValid = (status == TOOL_OK);
  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::SetTransformPersistent(const PlusTransformName& aTransformName, bool isPersistent)
{
  PlusLockGuard<vtkPlusRecursiveCriticalSection> accessGuard(this->CriticalSection);

  if (aTransformName.From() == aTransformName.To())
  {
    LOG_ERROR("Setting a transform to itself is not allowed: " << aTransformName.GetTransformName());
    return PLUS_FAIL;
  }

  TransformInfo* fromToTransformInfo = GetOriginalTransform(aTransformName);
  if (fromToTransformInfo != NULL)
  {
    fromToTransformInfo->m_IsPersistent = isPersistent;
    return PLUS_SUCCESS;
  }
  LOG_ERROR("The original " << aTransformName.From() << "To" << aTransformName.To() <<
            " transform is missing. Cannot set its persistent status");
  return PLUS_FAIL;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::GetTransformPersistent(const PlusTransformName& aTransformName, bool& isPersistent)
{
  PlusLockGuard<vtkPlusRecursiveCriticalSection> accessGuard(this->CriticalSection);

  if (aTransformName.From() == aTransformName.To())
  {
    isPersistent = false;
    return PLUS_SUCCESS;
  }

  TransformInfo* fromToTransformInfo = GetOriginalTransform(aTransformName);
  if (fromToTransformInfo != NULL)
  {
    isPersistent = fromToTransformInfo->m_IsPersistent;
    return PLUS_SUCCESS;
  }
  LOG_ERROR("The original " << aTransformName.From() << "To" << aTransformName.To() <<
            " transform is missing. Cannot get its persistent status");
  return PLUS_FAIL;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::SetTransformError(const PlusTransformName& aTransformName, double aError)
{
  PlusLockGuard<vtkPlusRecursiveCriticalSection> accessGuard(this->CriticalSection);

  if (aTransformName.From() == aTransformName.To())
  {
    LOG_ERROR("Setting a transform to itself is not allowed: " << aTransformName.GetTransformName());
    return PLUS_FAIL;
  }

  TransformInfo* fromToTransformInfo = GetOriginalTransform(aTransformName);
  if (fromToTransformInfo != NULL)
  {
    fromToTransformInfo->m_Error = aError;
    return PLUS_SUCCESS;
  }
  LOG_ERROR("The original " << aTransformName.From() << "To" << aTransformName.To() << " transform is missing. Cannot set computation error value.");
  return PLUS_FAIL;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::GetTransformError(const PlusTransformName& aTransformName, double& aError, bool quiet /* = false */)
{
  if (aTransformName.From() == aTransformName.To())
  {
    aError = 0.0;
    return PLUS_FAIL;
  }

  PlusLockGuard<vtkPlusRecursiveCriticalSection> accessGuard(this->CriticalSection);
  TransformInfo* fromToTransformInfo = GetOriginalTransform(aTransformName);
  if (fromToTransformInfo != NULL)
  {
    aError = fromToTransformInfo->m_Error;
    return PLUS_SUCCESS;
  }
  if (!quiet)
  {
    LOG_ERROR("The original " << aTransformName.From() << "To" << aTransformName.To() << " transform is missing. Cannot get computation error value.");
  }
  return PLUS_FAIL;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::SetTransformDate(const PlusTransformName& aTransformName, const std::string& aDate)
{
  if (aTransformName.From() == aTransformName.To())
  {
    LOG_ERROR("Setting a transform to itself is not allowed: " << aTransformName.GetTransformName());
    return PLUS_FAIL;
  }

  if (aDate.empty())
  {
    LOG_ERROR("Cannot set computation date if it's empty.");
    return PLUS_FAIL;
  }

  PlusLockGuard<vtkPlusRecursiveCriticalSection> accessGuard(this->CriticalSection);

  TransformInfo* fromToTransformInfo = GetOriginalTransform(aTransformName);
  if (fromToTransformInfo != NULL)
  {
    fromToTransformInfo->m_Date = aDate;
    return PLUS_SUCCESS;
  }
  LOG_ERROR("The original " << aTransformName.From() << "To" << aTransformName.To() << " transform is missing. Cannot set computation date.");
  return PLUS_FAIL;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::GetTransformDate(const PlusTransformName& aTransformName, std::string& aDate, bool quiet /* = false */)
{
  if (aTransformName.From() == aTransformName.To())
  {
    aDate.clear();
    return PLUS_SUCCESS;
  }

  PlusLockGuard<vtkPlusRecursiveCriticalSection> accessGuard(this->CriticalSection);

  TransformInfo* fromToTransformInfo = GetOriginalTransform(aTransformName);
  if (fromToTransformInfo != NULL)
  {
    aDate = fromToTransformInfo->m_Date;
    return PLUS_SUCCESS;
  }
  if (!quiet)
  {
    LOG_ERROR("The original " << aTransformName.From() << "To" << aTransformName.To() << " transform is missing. Cannot get computation date.");
  }
  return PLUS_FAIL;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::FindPath(const PlusTransformName& aTransformName, TransformInfoListType& transformInfoList, const char* skipCoordFrameName /*=NULL*/, bool silent /*=false*/) const
{
  if (aTransformName.From() == aTransformName.To())
  {
    LOG_ERROR("vtkPlusTransformRepository::FindPath failed: from and to transform names are the same - " << aTransformName.GetTransformName());
    return PLUS_FAIL;
  }

  TransformInfo* fromToTransformInfo = GetOriginalTransform(aTransformName);
  if (fromToTransformInfo != NULL)
  {
    // found a transform
    transformInfoList.push_back(fromToTransformInfo);
    return PLUS_SUCCESS;
  }
  // not found, so try to find a path through all the connected coordinate frames
  CoordFrameToTransformMapType& fromCoordFrame = this->CoordinateFrames[aTransformName.From()];
  for (CoordFrameToTransformMapType::iterator transformInfoIt = fromCoordFrame.begin(); transformInfoIt != fromCoordFrame.end(); ++transformInfoIt)
  {
    if (skipCoordFrameName != NULL && transformInfoIt->first.compare(skipCoordFrameName) == 0)
    {
      // coordinate frame shall be ignored
      // (probably it would just go back to the previous coordinate frame where we come from)
      continue;
    }
    PlusTransformName newTransformName(transformInfoIt->first, aTransformName.To());
    if (FindPath(newTransformName, transformInfoList, aTransformName.From().c_str(), true /*silent*/) == PLUS_SUCCESS)
    {
      transformInfoList.push_back(&(transformInfoIt->second));
      return PLUS_SUCCESS;
    }
  }
  if (!silent)
  {
    // Print available transforms into a string, for troubleshooting information
    std::ostringstream osAvailableTransforms;
    bool firstPrintedTransform = true;
    for (CoordFrameToCoordFrameToTransformMapType::iterator coordFrame = this->CoordinateFrames.begin(); coordFrame != this->CoordinateFrames.end(); ++coordFrame)
    {
      for (CoordFrameToTransformMapType::iterator transformInfo = coordFrame->second.begin(); transformInfo != coordFrame->second.end(); ++transformInfo)
      {
        if (transformInfo->second.m_IsComputed)
        {
          // only print original transforms
          continue;
        }
        // don't print separator before the first transform
        if (firstPrintedTransform)
        {
          firstPrintedTransform = false;
        }
        else
        {
          osAvailableTransforms << ", ";
        }
        osAvailableTransforms << coordFrame->first << "To" << transformInfo->first << " ("
                              << (transformInfo->second.IsValid() ? "valid" : "invalid") << ", "
                              << (transformInfo->second.m_IsPersistent ? "persistent" : "non-persistent") << ")";
      }
    }
    LOG_ERROR("Transform path not found from " << aTransformName.From() << " to " << aTransformName.To() << " coordinate system."
              << " Available transforms in the repository (including the inverse of these transforms): " << osAvailableTransforms.str());
  }
  return PLUS_FAIL;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::IsExistingTransform(PlusTransformName aTransformName, bool aSilent/* = true*/)
{
  if (aTransformName.From() == aTransformName.To())
  {
    return PLUS_SUCCESS;
  }
  PlusLockGuard<vtkPlusRecursiveCriticalSection> accessGuard(this->CriticalSection);
  TransformInfoListType transformInfoList;
  return FindPath(aTransformName, transformInfoList, NULL, aSilent);
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::DeleteTransform(const PlusTransformName& aTransformName)
{
  if (aTransformName.From() == aTransformName.To())
  {
    LOG_ERROR("Setting a transform to itself cannot be deleted: " << aTransformName.GetTransformName());
    return PLUS_FAIL;
  }

  PlusLockGuard<vtkPlusRecursiveCriticalSection> accessGuard(this->CriticalSection);

  CoordFrameToTransformMapType& fromCoordFrame = this->CoordinateFrames[aTransformName.From()];
  CoordFrameToTransformMapType::iterator fromToTransformInfoIt = fromCoordFrame.find(aTransformName.To());

  if (fromToTransformInfoIt != fromCoordFrame.end())
  {
    // from->to transform is found
    if (fromToTransformInfoIt->second.m_IsComputed)
    {
      // this is not an original transform (has not been set by the user)
      LOG_ERROR("The " << aTransformName.From() << " to " << aTransformName.To()
                << " transform cannot be deleted, only the inverse of the transform has been set in the repository ("
                << aTransformName.From() << " to " << aTransformName.To() << ")");
      return PLUS_FAIL;
    }
    fromCoordFrame.erase(fromToTransformInfoIt);
  }
  else
  {
    LOG_ERROR("Delete transform failed: could not find the " << aTransformName.From() << " to " << aTransformName.To() << " transform");
    // don't return yet, try to delete the inverse
    return PLUS_FAIL;
  }

  CoordFrameToTransformMapType& toCoordFrame = this->CoordinateFrames[aTransformName.To()];
  CoordFrameToTransformMapType::iterator toFromTransformInfoIt = toCoordFrame.find(aTransformName.From());
  if (toFromTransformInfoIt != toCoordFrame.end())
  {
    // to->from transform is found
    toCoordFrame.erase(toFromTransformInfoIt);
  }
  else
  {
    LOG_ERROR("Delete transform failed: could not find the " << aTransformName.To() << " to " << aTransformName.From() << " transform");
    return PLUS_FAIL;
  }
  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
void vtkPlusTransformRepository::Clear()
{
  this->CoordinateFrames.clear();
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::ReadConfiguration(vtkXMLDataElement* configRootElement)
{
  XML_FIND_NESTED_ELEMENT_OPTIONAL(coordinateDefinitions, configRootElement, "CoordinateDefinitions");

  PlusLockGuard<vtkPlusRecursiveCriticalSection> accessGuard(this->CriticalSection);

  // Clear the transforms
  this->Clear();

  if (coordinateDefinitions == NULL)
  {
    LOG_DEBUG("vtkPlusTransformRepository::ReadConfiguration: no CoordinateDefinitions element was found");
    return PLUS_SUCCESS;
  }

  int numberOfErrors(0);
  for (int nestedElementIndex = 0; nestedElementIndex < coordinateDefinitions->GetNumberOfNestedElements(); ++nestedElementIndex)
  {
    vtkXMLDataElement* nestedElement = coordinateDefinitions->GetNestedElement(nestedElementIndex);
    if (!PlusCommon::IsEqualInsensitive(nestedElement->GetName(), "Transform"))
    {
      // Not a transform element, skip it
      continue;
    }

    const char* fromAttribute = nestedElement->GetAttribute("From");
    const char* toAttribute = nestedElement->GetAttribute("To");

    if (!fromAttribute || !toAttribute)
    {
      LOG_ERROR("Failed to read transform of CoordinateDefinitions (nested element index: " << nestedElementIndex << ") - check 'From' and 'To' attributes in the configuration file!");
      numberOfErrors++;
      continue;
    }

    PlusTransformName transformName(fromAttribute, toAttribute);
    if (!transformName.IsValid())
    {
      LOG_ERROR("Invalid transform name (From: '" <<  fromAttribute << "'  To: '" << toAttribute << "')");
      numberOfErrors++;
      continue;
    }

    vtkSmartPointer<vtkMatrix4x4> transformMatrix = vtkSmartPointer<vtkMatrix4x4>::New();
    double vectorMatrix[16] = {0};
    if (nestedElement->GetVectorAttribute("Matrix", 16, vectorMatrix))
    {
      transformMatrix->DeepCopy(vectorMatrix);
    }
    else
    {
      LOG_ERROR("Unable to find 'Matrix' attribute of '" << fromAttribute << "' to '" << toAttribute << "' transform among the CoordinateDefinitions in the configuration file");
      numberOfErrors++;
      continue;
    }

    if (this->SetTransform(transformName, transformMatrix) != PLUS_SUCCESS)
    {
      LOG_ERROR("Unable to set transform: '" << fromAttribute << "' to '" << toAttribute << "' transform");
      numberOfErrors++;
      continue;
    }

    bool isPersistent = true;
    PlusCommon::XML::SafeCheckAttributeValueInsensitive(*nestedElement, "Persistent", "FALSE", isPersistent);
    if (this->SetTransformPersistent(transformName, isPersistent) != PLUS_SUCCESS)
    {
      LOG_ERROR("Unable to set transform to " << isPersistent << ": " << fromAttribute << "' to '" << toAttribute << "' transform");
      numberOfErrors++;
      continue;
    }

    ToolStatus toolStatus = TOOL_OK;
    std::string toolStatusStr;
    if (PlusCommon::XML::SafeGetAttributeValueInsensitive(*nestedElement, "Status", toolStatusStr) == PLUS_SUCCESS)
    {
      if (this->SetTransformStatus(transformName, PlusCommon::ConvertStringToToolStatus(toolStatusStr)) != PLUS_SUCCESS)
      {
        LOG_ERROR("Unable to set transform to " << toolStatusStr << " : " << fromAttribute << "' to '" << toAttribute << "' transform");
        numberOfErrors++;
        continue;
      }
    }

    double error(0);
    if (PlusCommon::XML::SafeGetAttributeValueInsensitive<double>(*nestedElement, "Error", error) == PLUS_SUCCESS &&
        this->SetTransformError(transformName, error) != PLUS_SUCCESS)
    {
      LOG_ERROR("Unable to set transform error: '" << fromAttribute << "' to '" << toAttribute << "' transform");
      numberOfErrors++;
      continue;
    }

    std::string date("");
    if (PlusCommon::XML::SafeGetAttributeValueInsensitive(*nestedElement, "Date", date) == PLUS_SUCCESS &&
        this->SetTransformDate(transformName, date) != PLUS_SUCCESS)
    {
      LOG_ERROR("Unable to set transform date: '" << fromAttribute << "' to '" << toAttribute << "' transform");
      numberOfErrors++;
      continue;
    }
  }

  return (numberOfErrors == 0 ? PLUS_SUCCESS : PLUS_FAIL);
}

//----------------------------------------------------------------------------
// copyAllTransforms: include non-persistent and invalid transforms
// Attributes: Persistent="TRUE/FALSE" Valid="TRUE/FALSE" => add it to ReadConfiguration, too
PlusStatus vtkPlusTransformRepository::WriteConfigurationGeneric(vtkXMLDataElement* configRootElement, bool copyAllTransforms)
{
  if (configRootElement == NULL)
  {
    LOG_ERROR("Failed to write transforms to CoordinateDefinitions - config root element is NULL");
    return PLUS_FAIL;
  }

  vtkSmartPointer<vtkXMLDataElement> coordinateDefinitions = configRootElement->FindNestedElementWithName("CoordinateDefinitions");
  if (coordinateDefinitions != NULL)
  {
    coordinateDefinitions->RemoveAllNestedElements();
  }
  else
  {
    coordinateDefinitions = vtkSmartPointer<vtkXMLDataElement>::New();
    coordinateDefinitions->SetName("CoordinateDefinitions");
    configRootElement->AddNestedElement(coordinateDefinitions);
  }

  int numberOfErrors(0);
  for (CoordFrameToCoordFrameToTransformMapType::iterator coordFrame = this->CoordinateFrames.begin(); coordFrame != this->CoordinateFrames.end(); ++coordFrame)
  {
    for (CoordFrameToTransformMapType::iterator transformInfo = coordFrame->second.begin(); transformInfo != coordFrame->second.end(); ++transformInfo)
    {
      // if copyAllTransforms is true => copy non persistent and persistent. if false => copy only persistent
      if ((transformInfo->second.m_IsPersistent || copyAllTransforms) && !transformInfo->second.m_IsComputed)
      {
        std::string fromCoordinateFrame = coordFrame->first;
        std::string toCoordinateFrame = transformInfo->first;
        std::string persistent = transformInfo->second.m_IsPersistent ? "true" : "false";
        ToolStatus status = transformInfo->second.m_ToolStatus;

        if (transformInfo->second.m_Transform == NULL)
        {
          LOG_ERROR("Transformation matrix is NULL between '" << fromCoordinateFrame << "' to '" << toCoordinateFrame << "' coordinate frames.");
          numberOfErrors++;
          continue;
        }

        if (!transformInfo->second.IsValid())
        {
          LOG_WARNING("Invalid transform saved to CoordinateDefinitions from  '" << fromCoordinateFrame << "' to '" << toCoordinateFrame << "' coordinate frame.");
        }

        double vectorMatrix[16] = {0};
        vtkMatrix4x4::DeepCopy(vectorMatrix, transformInfo->second.m_Transform->GetMatrix());

        vtkSmartPointer<vtkXMLDataElement> newTransformElement = vtkSmartPointer<vtkXMLDataElement>::New();
        newTransformElement->SetName("Transform");
        newTransformElement->SetAttribute("From", fromCoordinateFrame.c_str());
        newTransformElement->SetAttribute("To", toCoordinateFrame.c_str());
        if (PlusCommon::IsEqualInsensitive(persistent, "false"))
        {
          newTransformElement->SetAttribute("Persistent", persistent.c_str());
        }
        if (status != TOOL_OK)
        {
          newTransformElement->SetAttribute("Valid", PlusCommon::ConvertToolStatusToString(status).c_str());
        }
        newTransformElement->SetVectorAttribute("Matrix", 16, vectorMatrix);

        if (transformInfo->second.m_Error > 0)
        {
          newTransformElement->SetDoubleAttribute("Error", transformInfo->second.m_Error);
        }

        if (!transformInfo->second.m_Date.empty())
        {
          newTransformElement->SetAttribute("Date", transformInfo->second.m_Date.c_str());
        }
        else // Add current date if it was not explicitly specified
        {
          newTransformElement->SetAttribute("Date", vtksys::SystemTools::GetCurrentDateTime("%Y.%m.%d %X").c_str());
        }

        coordinateDefinitions->AddNestedElement(newTransformElement);

      }
    }
  }
  return (numberOfErrors == 0 ? PLUS_SUCCESS : PLUS_FAIL);
}
//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::WriteConfiguration(vtkXMLDataElement* configRootElement)
{
  return this->WriteConfigurationGeneric(configRootElement, false);
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTransformRepository::DeepCopy(vtkPlusTransformRepository* sourceRepositoryName, bool copyAllTransforms)
{
  PlusLockGuard<vtkPlusRecursiveCriticalSection> accessGuard(this->CriticalSection);
  vtkSmartPointer<vtkXMLDataElement> configRootElement = vtkSmartPointer<vtkXMLDataElement>::New();
  sourceRepositoryName->WriteConfigurationGeneric(configRootElement, copyAllTransforms);
  return ReadConfiguration(configRootElement);
}
