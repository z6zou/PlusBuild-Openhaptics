/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#include "PlusConfigure.h"

#include "PlusMath.h"
#include "PlusTrackedFrame.h"
#include "vtkImageData.h"
#include "vtkMatrix4x4.h"
#include "vtkObjectFactory.h"
#include "vtkPlusMetaImageSequenceIO.h"
#include "vtkPlusNrrdSequenceIO.h"
#include "vtkPlusTrackedFrameList.h"
#include "vtkPlusTransformRepository.h"
#include "vtkXMLUtilities.h"
#include "vtksys/SystemTools.hxx"
#include <math.h>

#ifdef PLUS_USE_VTKVIDEOIO_MKV
#include <vtkPlusMkvSequenceIO.h>
#endif

//----------------------------------------------------------------------------
// ************************* vtkPlusTrackedFrameList *****************************
//----------------------------------------------------------------------------
vtkStandardNewMacro(vtkPlusTrackedFrameList);

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::vtkPlusTrackedFrameList()
{
  this->SetNumberOfUniqueFrames(5);

  this->MinRequiredTranslationDifferenceMm = 0.0;
  this->MinRequiredAngleDifferenceDeg = 0.0;
  this->MaxAllowedTranslationSpeedMmPerSec = 0.0;
  this->MaxAllowedRotationSpeedDegPerSec = 0.0;
  this->ValidationRequirements = 0;

}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::~vtkPlusTrackedFrameList()
{
  this->Clear();
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::RemoveTrackedFrame(int frameNumber)
{
  if (frameNumber < 0 || (unsigned int)frameNumber >= this->GetNumberOfTrackedFrames())
  {
    LOG_WARNING("Failed to remove tracked frame from list - invalid frame number: " << frameNumber);
    return PLUS_FAIL;
  }

  delete this->TrackedFrameList[frameNumber];
  this->TrackedFrameList.erase(this->TrackedFrameList.begin() + frameNumber);

  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::RemoveTrackedFrameRange(unsigned int frameNumberFrom, unsigned int frameNumberTo)
{
  if (frameNumberTo >= this->GetNumberOfTrackedFrames() || frameNumberFrom > frameNumberTo)
  {
    LOG_WARNING("Failed to remove tracked frame from list - invalid frame number range: (" << frameNumberFrom << ", " << frameNumberTo << ")");
    return PLUS_FAIL;
  }

  for (unsigned int i = frameNumberFrom; i <= frameNumberTo; ++i)
  {
    delete this->TrackedFrameList[i];
  }

  this->TrackedFrameList.erase(this->TrackedFrameList.begin() + frameNumberFrom, this->TrackedFrameList.begin() + frameNumberTo + 1);

  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
void vtkPlusTrackedFrameList::Clear()
{
  for (unsigned int i = 0; i < this->TrackedFrameList.size(); i++)
  {
    if (this->TrackedFrameList[i] != NULL)
    {
      delete this->TrackedFrameList[i];
      this->TrackedFrameList[i] = NULL;
    }
  }
  this->TrackedFrameList.clear();
}

//----------------------------------------------------------------------------
void vtkPlusTrackedFrameList::PrintSelf(std::ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);

  os << indent << "Number of frames = " << GetNumberOfTrackedFrames();
  for (FieldMapType::const_iterator it = this->CustomFields.begin(); it != this->CustomFields.end(); it++)
  {
    os << indent << it->first << " = " << it->second << std::endl;
  }
}

//----------------------------------------------------------------------------
PlusTrackedFrame* vtkPlusTrackedFrameList::GetTrackedFrame(int frameNumber)
{
  if ((unsigned int)frameNumber >= this->GetNumberOfTrackedFrames())
  {
    LOG_ERROR("vtkPlusTrackedFrameList::GetTrackedFrame requested a non-existing frame (framenumber=" << frameNumber);
    return NULL;
  }
  return this->TrackedFrameList[frameNumber];
}


//----------------------------------------------------------------------------
PlusTrackedFrame* vtkPlusTrackedFrameList::GetTrackedFrame(unsigned int frameNumber)
{
  if (frameNumber >= this->GetNumberOfTrackedFrames())
  {
    LOG_ERROR("vtkPlusTrackedFrameList::GetTrackedFrame requested a non-existing frame (framenumber=" << frameNumber);
    return NULL;
  }
  return this->TrackedFrameList[frameNumber];
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::AddTrackedFrameList(vtkPlusTrackedFrameList* inTrackedFrameList, InvalidFrameAction action /*=ADD_INVALID_FRAME_AND_REPORT_ERROR*/)
{
  PlusStatus status = PLUS_SUCCESS;
  for (unsigned int i = 0; i < inTrackedFrameList->GetNumberOfTrackedFrames(); ++i)
  {
    if (this->AddTrackedFrame(inTrackedFrameList->GetTrackedFrame(i), action) != PLUS_SUCCESS)
    {
      LOG_ERROR("Failed to add tracked frame to the list!");
      status = PLUS_FAIL;
      continue;
    }
  }

  return status;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::AddTrackedFrame(PlusTrackedFrame* trackedFrame, InvalidFrameAction action /*=ADD_INVALID_FRAME_AND_REPORT_ERROR*/)
{
  bool isFrameValid = true;
  if (action != ADD_INVALID_FRAME)
  {
    isFrameValid = this->ValidateData(trackedFrame);
  }

  if (!isFrameValid)
  {
    switch (action)
    {
      case ADD_INVALID_FRAME_AND_REPORT_ERROR:
        LOG_ERROR("Validation failed on frame, the frame is added to the list anyway");
        break;
      case ADD_INVALID_FRAME:
        LOG_DEBUG("Validation failed on frame, the frame is added to the list anyway");
        break;
      case SKIP_INVALID_FRAME_AND_REPORT_ERROR:
        LOG_ERROR("Validation failed on frame, the frame is ignored");
        return PLUS_FAIL;
      case SKIP_INVALID_FRAME:
        LOG_DEBUG("Validation failed on frame, the frame is ignored");
        return PLUS_SUCCESS;
    }
  }

  // Make a copy and add frame to the list
  PlusTrackedFrame* pTrackedFrame = new PlusTrackedFrame(*trackedFrame);
  this->TrackedFrameList.push_back(pTrackedFrame);
  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::TakeTrackedFrame(PlusTrackedFrame* trackedFrame, InvalidFrameAction action /*=ADD_INVALID_FRAME_AND_REPORT_ERROR*/)
{
  bool isFrameValid = true;
  if (action != ADD_INVALID_FRAME)
  {
    isFrameValid = this->ValidateData(trackedFrame);
  }
  if (!isFrameValid)
  {
    switch (action)
    {
      case ADD_INVALID_FRAME_AND_REPORT_ERROR:
        LOG_ERROR("Validation failed on frame, the frame is added to the list anyway");
        break;
      case ADD_INVALID_FRAME:
        LOG_DEBUG("Validation failed on frame, the frame is added to the list anyway");
        break;
      case SKIP_INVALID_FRAME_AND_REPORT_ERROR:
        LOG_ERROR("Validation failed on frame, the frame is ignored");
        delete trackedFrame;
        return PLUS_FAIL;
      case SKIP_INVALID_FRAME:
        LOG_DEBUG("Validation failed on frame, the frame is ignored");
        delete trackedFrame;
        return PLUS_SUCCESS;
    }
  }

  // Make a copy and add frame to the list
  this->TrackedFrameList.push_back(trackedFrame);
  return PLUS_SUCCESS;
}


//----------------------------------------------------------------------------
bool vtkPlusTrackedFrameList::ValidateData(PlusTrackedFrame* trackedFrame)
{
  if (this->ValidationRequirements == 0)
  {
    // If we don't want to validate return immediately
    return true;
  }

  if (this->ValidationRequirements & REQUIRE_UNIQUE_TIMESTAMP)
  {
    if (! this->ValidateTimestamp(trackedFrame))
    {
      LOG_DEBUG("Validation failed - timestamp is not unique: " << trackedFrame->GetTimestamp());
      return false;
    }
  }

  if (this->ValidationRequirements & REQUIRE_TRACKING_OK)
  {
    if (! this->ValidateStatus(trackedFrame))
    {
      LOG_DEBUG("Validation failed - tracking status in not OK");
      return false;
    }
  }

  if (this->ValidationRequirements & REQUIRE_CHANGED_TRANSFORM)
  {
    if (! this->ValidateTransform(trackedFrame))
    {
      LOG_DEBUG("Validation failed - transform is not changed");
      return false;
    }
  }

  if (this->ValidationRequirements & REQUIRE_CHANGED_ENCODER_POSITION)
  {
    if (! this->ValidateEncoderPosition(trackedFrame))
    {
      LOG_DEBUG("Validation failed - encoder position is not changed");
      return false;
    }
  }


  if (this->ValidationRequirements & REQUIRE_SPEED_BELOW_THRESHOLD)
  {
    if (! this->ValidateSpeed(trackedFrame))
    {
      LOG_DEBUG("Validation failed - speed is higher than threshold");
      return false;
    }
  }

  return true;
}

//----------------------------------------------------------------------------
bool vtkPlusTrackedFrameList::ValidateTimestamp(PlusTrackedFrame* trackedFrame)
{
  if (this->TrackedFrameList.size() == 0)
  {
    // the existing list is empty, so any frame has unique timestamp and therefore valid
    return true;
  }
  const bool isTimestampUnique = std::find_if(this->TrackedFrameList.begin(), this->TrackedFrameList.end(), TrackedFrameTimestampFinder(trackedFrame)) == this->TrackedFrameList.end();
  // validation passed if the timestamp is unique
  return isTimestampUnique;
}

//----------------------------------------------------------------------------
bool vtkPlusTrackedFrameList::ValidateEncoderPosition(PlusTrackedFrame* trackedFrame)
{
  TrackedFrameListType::iterator searchIndex;
  const int containerSize = this->TrackedFrameList.size();
  if (containerSize < this->NumberOfUniqueFrames)
  {
    searchIndex = this->TrackedFrameList.begin();
  }
  else
  {
    searchIndex = this->TrackedFrameList.end() - this->NumberOfUniqueFrames;
  }

  if (std::find_if(searchIndex, this->TrackedFrameList.end(), PlusTrackedFrameEncoderPositionFinder(trackedFrame,
                   this->MinRequiredTranslationDifferenceMm, this->MinRequiredAngleDifferenceDeg)) != this->TrackedFrameList.end())
  {
    // We've already inserted this frame
    LOG_DEBUG("Tracked frame encoder position validation result: we've already inserted this frame to container!");
    return false;
  }
  return true;
}

//----------------------------------------------------------------------------
bool vtkPlusTrackedFrameList::ValidateTransform(PlusTrackedFrame* trackedFrame)
{
  TrackedFrameListType::iterator searchIndex;
  const int containerSize = this->TrackedFrameList.size();
  if (containerSize < this->NumberOfUniqueFrames)
  {
    searchIndex = this->TrackedFrameList.begin();
  }
  else
  {
    searchIndex = this->TrackedFrameList.end() - this->NumberOfUniqueFrames;
  }

  if (std::find_if(searchIndex, this->TrackedFrameList.end(), TrackedFrameTransformFinder(trackedFrame, this->FrameTransformNameForValidation,
                   this->MinRequiredTranslationDifferenceMm, this->MinRequiredAngleDifferenceDeg)) != this->TrackedFrameList.end())
  {
    // We've already inserted this frame
    LOG_DEBUG("Tracked frame transform validation result: we've already inserted this frame to container!");
    return false;
  }

  return true;
}

//----------------------------------------------------------------------------
bool vtkPlusTrackedFrameList::ValidateStatus(PlusTrackedFrame* trackedFrame)
{
  vtkPlusTransformRepository* repo = vtkPlusTransformRepository::New();
  repo->SetTransforms(*trackedFrame);
  bool isValid(false);
  if (repo->GetTransformValid(this->FrameTransformNameForValidation, isValid) != PLUS_SUCCESS)
  {
    LOG_ERROR("Unable to retrieve transform \'" << this->FrameTransformNameForValidation.GetTransformName() << "\'.");
  }
  repo->Delete();

  return isValid;
}

//----------------------------------------------------------------------------
bool vtkPlusTrackedFrameList::ValidateSpeed(PlusTrackedFrame* trackedFrame)
{
  if (this->TrackedFrameList.size() < 1)
  {
    return true;
  }

  TrackedFrameListType::iterator latestFrameInList = this->TrackedFrameList.end() - 1;

  // Compute difference between the last two timestamps
  double diffTimeSec = fabs(trackedFrame->GetTimestamp() - (*latestFrameInList)->GetTimestamp());
  if (diffTimeSec < 0.0001)
  {
    // the frames are almost acquired at the same time, cannot compute speed reliably
    // better to invalidate the frame
    return false;
  }

  vtkSmartPointer<vtkMatrix4x4> inputTransformMatrix = vtkSmartPointer<vtkMatrix4x4>::New();
  double inputTransformVector[16] = {0};
  if (trackedFrame->GetFrameTransform(this->FrameTransformNameForValidation, inputTransformVector))
  {
    inputTransformMatrix->DeepCopy(inputTransformVector);
  }
  else
  {
    std::string strFrameTransformName;
    this->FrameTransformNameForValidation.GetTransformName(strFrameTransformName);
    LOG_ERROR("Unable to get frame transform '" << strFrameTransformName << "' from input tracked frame!");
    return false;
  }

  vtkSmartPointer<vtkMatrix4x4> latestTransformMatrix = vtkSmartPointer<vtkMatrix4x4>::New();
  double latestTransformVector[16] = {0};
  if ((*latestFrameInList)->GetFrameTransform(this->FrameTransformNameForValidation, latestTransformVector))
  {
    latestTransformMatrix->DeepCopy(latestTransformVector);
  }
  else
  {
    LOG_ERROR("Unable to get default frame transform for latest frame!");
    return false;
  }

  if (this->MaxAllowedTranslationSpeedMmPerSec > 0)
  {
    // Compute difference between the last two positions
    double diffPosition = PlusMath::GetPositionDifference(inputTransformMatrix, latestTransformMatrix);
    double velocityPositionMmPerSec = fabs(diffPosition / diffTimeSec);
    if (velocityPositionMmPerSec > this->MaxAllowedTranslationSpeedMmPerSec)
    {
      LOG_DEBUG("Tracked frame speed validation result: tracked frame position change too fast (VelocityPosition = " << velocityPositionMmPerSec << ">" << this->MaxAllowedTranslationSpeedMmPerSec << " mm/sec)");
      return false;
    }
  }

  if (this->MaxAllowedRotationSpeedDegPerSec > 0)
  {
    // Compute difference between the last two orientations
    double diffOrientationDeg = PlusMath::GetOrientationDifference(inputTransformMatrix, latestTransformMatrix);
    double velocityOrientationDegPerSec = fabs(diffOrientationDeg / diffTimeSec);
    if (velocityOrientationDegPerSec > this->MaxAllowedRotationSpeedDegPerSec)
    {
      LOG_DEBUG("Tracked frame speed validation result: tracked frame angle change too fast VelocityOrientation = " << velocityOrientationDegPerSec << ">" << this->MaxAllowedRotationSpeedDegPerSec << " deg/sec)");
      return false;
    }
  }

  return true;
}

//----------------------------------------------------------------------------
int vtkPlusTrackedFrameList::GetNumberOfBitsPerScalar()
{
  int numberOfBitsPerScalar = 0;
  if (this->GetNumberOfTrackedFrames() > 0)
  {
    numberOfBitsPerScalar = this->GetTrackedFrame(0)->GetNumberOfBitsPerScalar();
  }
  else
  {
    LOG_WARNING("Unable to get bits per scalar: there is no frame in the tracked frame list!");
  }

  return numberOfBitsPerScalar;
}

//----------------------------------------------------------------------------
int vtkPlusTrackedFrameList::GetNumberOfBitsPerPixel()
{
  int numberOfBitsPerPixel = 0;
  if (this->GetNumberOfTrackedFrames() > 0)
  {
    numberOfBitsPerPixel = this->GetTrackedFrame(0)->GetNumberOfBitsPerPixel();
  }
  else
  {
    LOG_WARNING("Unable to get bits per pixel: there is no frame in the tracked frame list!");
  }

  return numberOfBitsPerPixel;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::SaveToSequenceMetafile(const std::string& filename, US_IMAGE_ORIENTATION orientationInFile /*= US_IMG_ORIENT_MF*/, bool useCompression /*=true*/, bool enableImageDataWrite /*=true*/)
{
  vtkSmartPointer<vtkPlusMetaImageSequenceIO> writer = vtkSmartPointer<vtkPlusMetaImageSequenceIO>::New();
  writer->SetUseCompression(useCompression);
  writer->SetFileName(filename);
  writer->SetImageOrientationInFile(orientationInFile);
  writer->SetTrackedFrameList(this);
  writer->SetEnableImageDataWrite(enableImageDataWrite);
  if (this->GetNumberOfTrackedFrames() == 1)
  {
    writer->IsDataTimeSeriesOff();
  }
  if (writer->Write() != PLUS_SUCCESS)
  {
    LOG_ERROR("Couldn't write sequence metafile: " <<  filename);
    return PLUS_FAIL;
  }
  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::ReadFromSequenceMetafile(const std::string& trackedSequenceDataFileName)
{
  std::string trackedSequenceDataFilePath = trackedSequenceDataFileName;

  // If file is not found in the current directory then try to find it in the image directory, too
  if (!vtksys::SystemTools::FileExists(trackedSequenceDataFilePath.c_str(), true))
  {
    if (vtkPlusConfig::GetInstance()->FindImagePath(trackedSequenceDataFileName, trackedSequenceDataFilePath) == PLUS_FAIL)
    {
      LOG_ERROR("Cannot find sequence metafile: " << trackedSequenceDataFileName);
      return PLUS_FAIL;
    }
  }

  vtkSmartPointer<vtkPlusMetaImageSequenceIO> reader = vtkSmartPointer<vtkPlusMetaImageSequenceIO>::New();
  reader->SetFileName(trackedSequenceDataFilePath.c_str());
  reader->SetTrackedFrameList(this);
  if (reader->Read() != PLUS_SUCCESS)
  {
    LOG_ERROR("Couldn't read sequence metafile: " <<  trackedSequenceDataFileName);
    return PLUS_FAIL;
  }

  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::SaveToNrrdFile(const std::string& filename, US_IMAGE_ORIENTATION orientationInFile /*= US_IMG_ORIENT_MF*/, bool useCompression /*= true*/, bool enableImageDataWrite /*= true*/)
{
  vtkSmartPointer<vtkPlusNrrdSequenceIO> writer = vtkSmartPointer<vtkPlusNrrdSequenceIO>::New();
  writer->SetUseCompression(useCompression);
  writer->SetFileName(filename);
  writer->SetImageOrientationInFile(orientationInFile);
  writer->SetTrackedFrameList(this);
  writer->SetEnableImageDataWrite(enableImageDataWrite);
  if (this->GetNumberOfTrackedFrames() == 1)
  {
    writer->IsDataTimeSeriesOff();
  }
  if (writer->Write() != PLUS_SUCCESS)
  {
    LOG_ERROR("Couldn't write Nrrd file: " <<  filename);
    return PLUS_FAIL;
  }
  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::ReadFromNrrdFile(const std::string& trackedSequenceDataFileName)
{
  std::string trackedSequenceDataFilePath(trackedSequenceDataFileName);

  // If file is not found in the current directory then try to find it in the image directory, too
  if (!vtksys::SystemTools::FileExists(trackedSequenceDataFilePath.c_str(), true))
  {
    if (vtkPlusConfig::GetInstance()->FindImagePath(trackedSequenceDataFileName, trackedSequenceDataFilePath) == PLUS_FAIL)
    {
      LOG_ERROR("Cannot find Nrrd file: " << trackedSequenceDataFileName);
      return PLUS_FAIL;
    }
  }

  vtkSmartPointer<vtkPlusNrrdSequenceIO> reader = vtkSmartPointer<vtkPlusNrrdSequenceIO>::New();
  reader->SetFileName(trackedSequenceDataFilePath.c_str());
  reader->SetTrackedFrameList(this);
  if (reader->Read() != PLUS_SUCCESS)
  {
    LOG_ERROR("Couldn't read Nrrd file: " <<  trackedSequenceDataFileName);
    return PLUS_FAIL;
  }
  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::SaveToMatroskaFile(const std::string& filename, US_IMAGE_ORIENTATION orientationInFile /*= US_IMG_ORIENT_MF*/, bool useCompression /*= true*/, bool enableImageDataWrite /*= true*/)
{
#ifdef PLUS_USE_VTKVIDEOIO_MKV
  vtkSmartPointer<vtkPlusMkvSequenceIO> writer = vtkSmartPointer<vtkPlusMkvSequenceIO>::New();
  writer->SetUseCompression(useCompression);
  writer->SetFileName(filename);
  writer->SetTrackedFrameList(this);
  if (writer->Write() != PLUS_SUCCESS)
  {
    LOG_ERROR("Couldn't write MKV file: " << filename);
    return PLUS_FAIL;
  }
  return PLUS_SUCCESS;
#else
  LOG_ERROR(
    "Plus has not been compiled with MKV read/write support. "
    "Configure PlusBuild with PLUS_USE_VTKVIDEOIO_MKV enabled."
    );
  return PLUS_FAIL;
#endif
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::ReadFromMatroskaFile(const std::string& trackedSequenceDataFileName)
{
#ifdef PLUS_USE_VTKVIDEOIO_MKV
  std::string trackedSequenceDataFilePath(trackedSequenceDataFileName);

  // If file is not found in the current directory then try to find it in the image directory, too
  if (!vtksys::SystemTools::FileExists(trackedSequenceDataFilePath.c_str(), true))
  {
    if (vtkPlusConfig::GetInstance()->FindImagePath(trackedSequenceDataFileName, trackedSequenceDataFilePath) == PLUS_FAIL)
    {
      LOG_ERROR("Cannot find MKV file: " << trackedSequenceDataFileName);
      return PLUS_FAIL;
    }
  }

  vtkSmartPointer<vtkPlusMkvSequenceIO> reader = vtkSmartPointer<vtkPlusMkvSequenceIO>::New();
  reader->SetFileName(trackedSequenceDataFilePath.c_str());
  reader->SetTrackedFrameList(this);
  if (reader->Read() != PLUS_SUCCESS)
  {
    LOG_ERROR("Couldn't read MKV file: " << trackedSequenceDataFileName);
    return PLUS_FAIL;
  }
  return PLUS_SUCCESS;
#else
  LOG_ERROR(
    "Plus has not been compiled with MKV read/write support. "
    "Configure PlusBuild with PLUS_USE_VTKVIDEOIO_MKV enabled."
    );
  return PLUS_FAIL;
#endif
}

//-----------------------------------------------------------------------------
PlusCommon::VTKScalarPixelType vtkPlusTrackedFrameList::GetPixelType()
{
  if (this->GetNumberOfTrackedFrames() < 1)
  {
    LOG_ERROR("Unable to get pixel type size: there is no frame in the tracked frame list!");
    return VTK_VOID;
  }

  for (unsigned int i = 0; i < this->GetNumberOfTrackedFrames(); ++i)
  {
    if (this->GetTrackedFrame(i)->GetImageData()->IsImageValid())
    {
      return this->GetTrackedFrame(i)->GetImageData()->GetVTKScalarPixelType();
    }
  }

  LOG_WARNING("There are no valid images in the tracked frame list.");
  return VTK_VOID;
}

//-----------------------------------------------------------------------------
int vtkPlusTrackedFrameList::GetNumberOfScalarComponents()
{
  if (this->GetNumberOfTrackedFrames() < 1)
  {
    LOG_ERROR("Unable to get number of scalar components: there is no frame in the tracked frame list!");
    return 1;
  }

  for (unsigned int i = 0; i < this->GetNumberOfTrackedFrames(); ++i)
  {
    if (this->GetTrackedFrame(i)->GetImageData()->IsImageValid())
    {
      return this->GetTrackedFrame(i)->GetImageData()->GetImage()->GetNumberOfScalarComponents();
    }
  }

  LOG_WARNING("There are no valid images in the tracked frame list.");
  return 1;
}

//-----------------------------------------------------------------------------
US_IMAGE_ORIENTATION vtkPlusTrackedFrameList::GetImageOrientation()
{
  if (this->GetNumberOfTrackedFrames() < 1)
  {
    LOG_ERROR("Unable to get image orientation: there is no frame in the tracked frame list!");
    return US_IMG_ORIENT_XX;
  }

  for (unsigned int i = 0; i < this->GetNumberOfTrackedFrames(); ++i)
  {
    if (this->GetTrackedFrame(i)->GetImageData()->IsImageValid())
    {
      return this->GetTrackedFrame(i)->GetImageData()->GetImageOrientation();
    }
  }

  LOG_WARNING("There are no valid images in the tracked frame list.");
  return US_IMG_ORIENT_XX;
}

//-----------------------------------------------------------------------------
US_IMAGE_TYPE vtkPlusTrackedFrameList::GetImageType()
{
  if (this->GetNumberOfTrackedFrames() < 1)
  {
    LOG_ERROR("Unable to get image type: there is no frame in the tracked frame list!");
    return US_IMG_TYPE_XX;
  }

  for (unsigned int i = 0; i < this->GetNumberOfTrackedFrames(); ++i)
  {
    if (this->GetTrackedFrame(i)->GetImageData()->IsImageValid())
    {
      return this->GetTrackedFrame(i)->GetImageData()->GetImageType();
    }
  }

  LOG_WARNING("There are no valid images in the tracked frame list.");
  return US_IMG_TYPE_XX;
}


//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::GetFrameSize(FrameSizeType& outFrameSize)
{
  if (this->GetNumberOfTrackedFrames() < 1)
  {
    LOG_ERROR("Unable to get image type: there are no frames in the tracked frame list!");
    return PLUS_FAIL;
  }

  for (unsigned int i = 0; i < this->GetNumberOfTrackedFrames(); ++i)
  {
    if (this->GetTrackedFrame(i)->GetImageData() && this->GetTrackedFrame(i)->GetImageData()->IsImageValid())
    {
      outFrameSize = this->GetTrackedFrame(i)->GetFrameSize();
      return PLUS_SUCCESS;
    }
  }

  LOG_WARNING("There are no valid images in the tracked frame list.");
  return PLUS_FAIL;
}

//----------------------------------------------------------------------------
const char* vtkPlusTrackedFrameList::GetCustomString(const char* fieldName)
{
  FieldMapType::iterator fieldIterator;
  fieldIterator = this->CustomFields.find(fieldName);
  if (fieldIterator != this->CustomFields.end())
  {
    return fieldIterator->second.c_str();
  }
  return NULL;
}


//----------------------------------------------------------------------------
std::string vtkPlusTrackedFrameList::GetCustomString(const std::string& fieldName) const
{
  FieldMapType::const_iterator fieldIterator = this->CustomFields.find(fieldName);
  if (fieldIterator != this->CustomFields.end())
  {
    return fieldIterator->second;
  }
  return std::string("");
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::GetCustomTransform(const char* frameTransformName, vtkMatrix4x4* transformMatrix)
{
  double transform[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
  const PlusStatus retValue = this->GetCustomTransform(frameTransformName, transform);
  transformMatrix->DeepCopy(transform);

  return retValue;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::GetCustomTransform(const char* frameTransformName, double* transformMatrix)
{
  if (frameTransformName == NULL)
  {
    LOG_ERROR("Invalid frame transform name");
    return PLUS_FAIL;
  }
  const char* customString = this->GetCustomString(frameTransformName);
  if (customString == NULL)
  {
    LOG_ERROR("Cannot find frame transform " << frameTransformName);
    return PLUS_FAIL;
  }

  std::istringstream transformFieldValue(customString);
  double item;
  int i = 0;
  while (transformFieldValue >> item)
  {
    transformMatrix[i++] = item;
  }

  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
void vtkPlusTrackedFrameList::SetCustomTransform(const char* frameTransformName, vtkMatrix4x4* transformMatrix)
{
  double transform[16];
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      transform[i * 4 + j] = transformMatrix->GetElement(i, j);
    }
  }

  this->SetCustomTransform(frameTransformName, transform);
}

//----------------------------------------------------------------------------
void vtkPlusTrackedFrameList::SetCustomTransform(const char* frameTransformName, double* transformMatrix)
{
  std::ostringstream transform;

  transform  << transformMatrix[0]  << " " << transformMatrix[1]  << " " << transformMatrix[2]  << " " << transformMatrix[3]  << " "
             << transformMatrix[4]  << " " << transformMatrix[5]  << " " << transformMatrix[6]  << " " << transformMatrix[7]  << " "
             << transformMatrix[8]  << " " << transformMatrix[9]  << " " << transformMatrix[10] << " " << transformMatrix[11] << " "
             << transformMatrix[12] << " " << transformMatrix[13] << " " << transformMatrix[14] << " " << transformMatrix[15] << " ";

  this->SetCustomString(frameTransformName, transform.str().c_str());
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::SetCustomString(const char* fieldName, const char* fieldValue)
{
  if (fieldName == NULL)
  {
    LOG_ERROR("Field name is invalid");
    return PLUS_FAIL;
  }
  if (fieldValue == NULL)
  {
    this->CustomFields.erase(fieldName);
    return PLUS_SUCCESS;
  }
  this->CustomFields[fieldName] = fieldValue;
  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::SetCustomString(const std::string& fieldName, const std::string& fieldValue)
{
  if (fieldName.empty())
  {
    LOG_ERROR("Field name is invalid");
    return PLUS_FAIL;
  }
  if (fieldValue.empty())
  {
    this->CustomFields.erase(fieldName);
    return PLUS_SUCCESS;
  }
  this->CustomFields[fieldName] = fieldValue;
  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
void vtkPlusTrackedFrameList::GetCustomFieldNameList(std::vector<std::string>& fieldNames)
{
  fieldNames.clear();
  for (FieldMapType::const_iterator it = this->CustomFields.begin(); it != this->CustomFields.end(); it++)
  {
    fieldNames.push_back(it->first);
  }
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::GetGlobalTransform(vtkMatrix4x4* globalTransform)
{
  const char* offsetStr = GetCustomString("Offset");
  if (offsetStr == NULL)
  {
    LOG_ERROR("Cannot determine global transform, Offset is undefined");
    return PLUS_FAIL;
  }
  const char* transformStr = GetCustomString("TransformMatrix");
  if (transformStr == NULL)
  {
    LOG_ERROR("Cannot determine global transform, TransformMatrix is undefined");
    return PLUS_FAIL;
  }

  double item;
  int i = 0;

  const int offsetLen = 3;
  double offset[offsetLen];
  std::istringstream offsetFieldValue(offsetStr);
  for (i = 0; offsetFieldValue >> item && i < offsetLen; i++)
  {
    offset[i] = item;
  }
  if (i < offsetLen)
  {
    LOG_ERROR("Not enough elements in the Offset field (expected " << offsetLen << ", found " << i << ")");
    return PLUS_FAIL;
  }

  const int transformLen = 9;
  double transform[transformLen];
  std::istringstream transformFieldValue(transformStr);
  for (i = 0; transformFieldValue >> item && i < transformLen; i++)
  {
    transform[i] = item;
  }
  if (i < transformLen)
  {
    LOG_ERROR("Not enough elements in the TransformMatrix field (expected " << transformLen << ", found " << i << ")");
    return PLUS_FAIL;
  }

  globalTransform->Identity();

  globalTransform->SetElement(0, 3, offset[0]);
  globalTransform->SetElement(1, 3, offset[1]);
  globalTransform->SetElement(2, 3, offset[2]);

  globalTransform->SetElement(0, 0, transform[0]);
  globalTransform->SetElement(0, 1, transform[1]);
  globalTransform->SetElement(0, 2, transform[2]);
  globalTransform->SetElement(1, 0, transform[3]);
  globalTransform->SetElement(1, 1, transform[4]);
  globalTransform->SetElement(1, 2, transform[5]);
  globalTransform->SetElement(2, 0, transform[6]);
  globalTransform->SetElement(2, 1, transform[7]);
  globalTransform->SetElement(2, 2, transform[8]);

  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::SetGlobalTransform(vtkMatrix4x4* globalTransform)
{
  std::ostringstream strOffset;
  strOffset << globalTransform->GetElement(0, 3)
            << " " << globalTransform->GetElement(1, 3)
            << " " << globalTransform->GetElement(2, 3);
  SetCustomString("Offset", strOffset.str().c_str());

  std::ostringstream strTransform;
  strTransform << globalTransform->GetElement(0, 0) << " " << globalTransform->GetElement(0, 1) << " " << globalTransform->GetElement(0, 2) << " ";
  strTransform << globalTransform->GetElement(1, 0) << " " << globalTransform->GetElement(1, 1) << " " << globalTransform->GetElement(1, 2) << " ";
  strTransform << globalTransform->GetElement(2, 0) << " " << globalTransform->GetElement(2, 1) << " " << globalTransform->GetElement(2, 2);
  SetCustomString("TransformMatrix", strTransform.str().c_str());

  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus vtkPlusTrackedFrameList::VerifyProperties(vtkPlusTrackedFrameList* trackedFrameList, US_IMAGE_ORIENTATION expectedOrientation, US_IMAGE_TYPE expectedType)
{
  if (trackedFrameList == NULL)
  {
    LOG_ERROR("vtkPlusTrackedFrameList::VerifyProperties failed: tracked frame list is NULL!");
    return PLUS_FAIL;
  }
  if (trackedFrameList->GetImageOrientation() != expectedOrientation)
  {
    LOG_ERROR("vtkPlusTrackedFrameList::VerifyProperties failed: expected image orientation is "
              << PlusVideoFrame::GetStringFromUsImageOrientation(expectedOrientation)
              << ", actual orientation is "
              << PlusVideoFrame::GetStringFromUsImageOrientation(trackedFrameList->GetImageOrientation()));
    return PLUS_FAIL;
  }
  if (trackedFrameList->GetImageType() != expectedType)
  {
    LOG_ERROR("vtkPlusTrackedFrameList::VerifyProperties failed: expected image type is "
              << PlusVideoFrame::GetStringFromUsImageType(expectedType)
              << ", actual type is "
              << PlusVideoFrame::GetStringFromUsImageType(trackedFrameList->GetImageType()));
    return PLUS_FAIL;
  }

  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
double vtkPlusTrackedFrameList::GetMostRecentTimestamp()
{
  double mostRecentTimestamp = 0.0;

  for (unsigned int i = 0; i < this->GetNumberOfTrackedFrames(); ++i)
  {
    if (this->GetTrackedFrame(i)->GetTimestamp() > mostRecentTimestamp)
    {
      mostRecentTimestamp = this->GetTrackedFrame(i)->GetTimestamp();
    }
  }

  return mostRecentTimestamp;
}

//-----------------------------------------------------------------------------
bool vtkPlusTrackedFrameList::IsContainingValidImageData()
{
  for (unsigned int i = 0; i < this->GetNumberOfTrackedFrames(); ++i)
  {
    if (this->GetTrackedFrame(i)->GetImageData()->IsImageValid())
    {
      // found a valid image
      return true;
    }
  }
  // no valid images found
  return false;
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::iterator vtkPlusTrackedFrameList::begin()
{
  return TrackedFrameList.begin();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::const_iterator vtkPlusTrackedFrameList::begin() const
{
  return TrackedFrameList.begin();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::iterator vtkPlusTrackedFrameList::end()
{
  return TrackedFrameList.end();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::const_iterator vtkPlusTrackedFrameList::end() const
{
  return TrackedFrameList.end();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::iterator begin(vtkPlusTrackedFrameList& list)
{
  return list.begin();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::const_iterator begin(const vtkPlusTrackedFrameList& list)
{
  return list.begin();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::iterator end(vtkPlusTrackedFrameList& list)
{
  return list.end();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::const_iterator end(const vtkPlusTrackedFrameList& list)
{
  return list.end();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::reverse_iterator vtkPlusTrackedFrameList::rbegin()
{
  return TrackedFrameList.rbegin();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::const_reverse_iterator vtkPlusTrackedFrameList::rbegin() const
{
  return TrackedFrameList.rbegin();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::reverse_iterator vtkPlusTrackedFrameList::rend()
{
  return TrackedFrameList.rend();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::const_reverse_iterator vtkPlusTrackedFrameList::rend() const
{
  return TrackedFrameList.rend();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::reverse_iterator rbegin(vtkPlusTrackedFrameList& list)
{
  return list.rbegin();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::const_reverse_iterator rbegin(const vtkPlusTrackedFrameList& list)
{
  return list.rbegin();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::reverse_iterator rend(vtkPlusTrackedFrameList& list)
{
  return list.rend();
}

//----------------------------------------------------------------------------
vtkPlusTrackedFrameList::TrackedFrameListType::const_reverse_iterator rend(const vtkPlusTrackedFrameList& list)
{
  return list.rend();
}