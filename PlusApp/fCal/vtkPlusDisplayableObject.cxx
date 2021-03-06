/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

// Local includes
#include "vtkPlusDisplayableObject.h"

// VTK includes
#include <vtkActor.h>
#include <vtkImageActor.h>
#include <vtkPlusToolAxesActor.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkSTLReader.h>
#include <vtkCylinderSource.h>
#include <vtkConeSource.h>
#include <vtkAppendPolyData.h>
#include <vtkTransformPolyDataFilter.h>
#include <vtkXMLUtilities.h>
#include <vtkObjectFactory.h>
#include <vtkPolyData.h>

//-----------------------------------------------------------------------------

vtkCxxSetObjectMacro(vtkPlusDisplayableObject, Actor, vtkProp3D);

//----------------------------------------------------------------------------
vtkPlusDisplayableObject* vtkPlusDisplayableObject::New(const char* aType)
{
  if (aType == NULL)
  {
    LOG_ERROR("vtkPlusDisplayableObject::New failed. Object type is not specified");
    return NULL;
  }
  if (STRCASECMP(aType, "Model") == 0)
  {
    return vtkDisplayableModel::New();
  }
  else if (STRCASECMP(aType, "Image") == 0)
  {
    return vtkDisplayableImage::New();
  }
  else if (STRCASECMP(aType, "Axes") == 0)
  {
    return vtkDisplayableAxes::New();
  }
  else if (STRCASECMP(aType, "PolyData") == 0)
  {
    return vtkDisplayablePolyData::New();
  }
  LOG_ERROR("vtkPlusDisplayableObject::New failed. Unkonwn object type: " << aType);
  return NULL;
}

//----------------------------------------------------------------------------
vtkPlusDisplayableObject* vtkPlusDisplayableObject::New()
{
  return NULL;
}

//-----------------------------------------------------------------------------
vtkPlusDisplayableObject::vtkPlusDisplayableObject()
  : Actor(NULL)
  , ObjectCoordinateFrame("")
  , ObjectId("")
  , LastOpacity(1.0)
  , Displayable(true)
{
}

//-----------------------------------------------------------------------------
vtkPlusDisplayableObject::~vtkPlusDisplayableObject()
{
  this->SetActor(NULL);
}

//-----------------------------------------------------------------------------
PlusStatus vtkPlusDisplayableObject::ReadConfiguration(vtkXMLDataElement* aConfig)
{
  LOG_TRACE("vtkPlusDisplayableObject::ReadConfiguration");

  // Object coordinate frame name
  const char* objectCoordinateFrame = aConfig->GetAttribute("ObjectCoordinateFrame");
  if (objectCoordinateFrame == NULL)
  {
    LOG_ERROR("ObjectCoordinateFrame is not specified in DisplayableObject element of the configuration!");
    return PLUS_FAIL;
  }
  this->SetObjectCoordinateFrame(objectCoordinateFrame);

  // Opacity
  double opacity = 0.0;
  if (aConfig->GetScalarAttribute("Opacity", opacity))
  {
    this->LastOpacity = opacity;
  }

  // ID
  const char* id = aConfig->GetAttribute("Id");
  if (id == NULL)
  {
    LOG_WARNING("Displayable object " << objectCoordinateFrame << " without an ID. Cannot perform a lookup by ID.");
  }
  this->SetObjectId(id == NULL ? "" : id);

  return PLUS_SUCCESS;
}

//-----------------------------------------------------------------------------

vtkStandardNewMacro(vtkDisplayableImage);

//-----------------------------------------------------------------------------
vtkDisplayableImage::vtkDisplayableImage()
  : vtkPlusDisplayableObject()
{
}

//-----------------------------------------------------------------------------
vtkDisplayableImage::~vtkDisplayableImage()
{
}

//-----------------------------------------------------------------------------
bool vtkDisplayableImage::IsDisplayable()
{
  return this->Displayable;
}

//-----------------------------------------------------------------------------
void vtkDisplayableImage::SetOpacity(double aOpacity)
{
  LOG_TRACE("vtkDisplayableImage::SetOpacity(" << aOpacity << ")");

  vtkImageActor* imageActor = dynamic_cast<vtkImageActor*>(this->Actor);
  if (imageActor)
  {
    imageActor->SetOpacity(aOpacity);
  }
  else
  {
    LOG_WARNING("Invalid actor - cannot set opacity!");
  }
}

//-----------------------------------------------------------------------------
double vtkDisplayableImage::GetOpacity()
{
  vtkImageActor* imageActor = dynamic_cast<vtkImageActor*>(this->Actor);
  if (imageActor)
  {
    return imageActor->GetOpacity();
  }
  else
  {
    LOG_WARNING("Invalid actor - cannot get opacity!");
  }

  return -1.0;
}

//-----------------------------------------------------------------------------

vtkStandardNewMacro(vtkDisplayableAxes);

//-----------------------------------------------------------------------------
vtkDisplayableAxes::vtkDisplayableAxes()
  : vtkPlusDisplayableObject()
{
  vtkSmartPointer<vtkPlusToolAxesActor> axesActor = vtkSmartPointer<vtkPlusToolAxesActor>::New();
  axesActor->SetShaftLength(50);
  this->SetActor(axesActor);
}

//-----------------------------------------------------------------------------
vtkDisplayableAxes::~vtkDisplayableAxes()
{
}

//-----------------------------------------------------------------------------
bool vtkDisplayableAxes::IsDisplayable()
{
  return this->Displayable;
}

//-----------------------------------------------------------------------------
void vtkDisplayableAxes::SetOpacity(double aOpacity)
{
  LOG_TRACE("vtkDisplayableAxes::SetOpacity(" << aOpacity << ")");

  LOG_DEBUG("Cannot set opacity of axes actor!");
}

//-----------------------------------------------------------------------------
double vtkDisplayableAxes::GetOpacity()
{
  vtkPlusToolAxesActor* axesActor = dynamic_cast<vtkPlusToolAxesActor*>(this->Actor);
  if (axesActor)
  {
    return axesActor->GetVisibility() ? 1.0 : 0.0;
  }
  else
  {
    LOG_WARNING("Invalid actor - cannot get opacity!");
  }

  return -1.0;
}

//-----------------------------------------------------------------------------
void vtkDisplayableAxes::SetObjectCoordinateFrame(const char* objectCoordinateFrame)
{
  Superclass::SetObjectCoordinateFrame(objectCoordinateFrame);

  vtkPlusToolAxesActor* axesActor = dynamic_cast<vtkPlusToolAxesActor*>(this->Actor);
  if (axesActor)
  {
    axesActor->SetName(this->ObjectCoordinateFrame);
    axesActor->SetShowName(true);
  }
  else
  {
    LOG_WARNING("Invalid actor - cannot get opacity!");
  }
}

//-----------------------------------------------------------------------------

vtkStandardNewMacro(vtkDisplayablePolyData);

//-----------------------------------------------------------------------------
vtkDisplayablePolyData::vtkDisplayablePolyData()
  : vtkPlusDisplayableObject()
  , PolyData(NULL)
{
  vtkSmartPointer<vtkPolyData> polyData = vtkSmartPointer<vtkPolyData>::New();
  this->SetPolyData(polyData);
}

//-----------------------------------------------------------------------------
vtkDisplayablePolyData::~vtkDisplayablePolyData()
{
  this->SetPolyData(NULL);
}

//-----------------------------------------------------------------------------
void vtkDisplayablePolyData::SetPolyData(vtkPolyData* aPolyData)
{
  if (this->PolyData == aPolyData)
  {
    return;
  }

  vtkPolyData* tempPolyData = this->PolyData;
  this->PolyData = aPolyData;
  if (this->PolyData != NULL)
  {
    this->PolyData->Register(this);
  }

  if (tempPolyData != NULL)
  {
    tempPolyData->UnRegister(this);
  }
  this->Modified();

  if (this->PolyData == NULL)
  {
    return;
  }

  if (this->Actor == NULL)
  {
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
    this->SetActor(actor);
  }

  vtkActor* actor = dynamic_cast<vtkActor*>(this->Actor);
  if (actor)
  {
    vtkSmartPointer<vtkPolyDataMapper> polyMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    polyMapper->SetInputData(this->PolyData);
    actor->SetMapper(polyMapper);
  }
}

//-----------------------------------------------------------------------------
void vtkDisplayablePolyData::SetPolyDataMapper(vtkPolyDataMapper* aPolyDataMapper)
{
  vtkActor* actor = dynamic_cast<vtkActor*>(this->Actor);
  if (actor)
  {
    actor->SetMapper(aPolyDataMapper);
    this->Modified();
  }
}

//-----------------------------------------------------------------------------
bool vtkDisplayablePolyData::IsDisplayable()
{
  bool mapperOK = false;
  vtkActor* actor = dynamic_cast<vtkActor*>(this->Actor);
  if ((actor && actor->GetMapper()) || (!actor))
  {
    mapperOK = true;
  }

  return (mapperOK && this->Displayable);
}

//-----------------------------------------------------------------------------
void vtkDisplayablePolyData::SetColor(double aR, double aG, double aB)
{
  LOG_TRACE("vtkDisplayableModel::SetColor(" << aR << ", " << aG << ", " << aB << ")");

  vtkActor* actor = dynamic_cast<vtkActor*>(this->Actor);
  if (actor)
  {
    actor->GetProperty()->SetColor(aR, aG, aB);
  }
  else
  {
    LOG_WARNING("Invalid actor - cannot set color!");
  }
}

//-----------------------------------------------------------------------------
void vtkDisplayablePolyData::SetOpacity(double aOpacity)
{
  LOG_TRACE("vtkDisplayablePolyData::SetOpacity(" << aOpacity << ")");

  vtkActor* actor = dynamic_cast<vtkActor*>(this->Actor);
  if (actor)
  {
    actor->GetProperty()->SetOpacity(aOpacity);
    return;
  }
  else
  {
    LOG_WARNING("Invalid actor - cannot set opacity!");
  }
}

//-----------------------------------------------------------------------------
double vtkDisplayablePolyData::GetOpacity()
{
  vtkActor* actor = dynamic_cast<vtkActor*>(this->Actor);
  if (actor)
  {
    return actor->GetProperty()->GetOpacity();
  }
  else
  {
    LOG_WARNING("Invalid actor - cannot get opacity!");
  }

  return -1.0;
}

//-----------------------------------------------------------------------------
PlusStatus vtkDisplayablePolyData::AppendPolyData(vtkPolyData* aPolyData)
{
  LOG_TRACE("vtkDisplayablePolyData::AppendPolyData");

  vtkSmartPointer<vtkAppendPolyData> appendFilter = vtkSmartPointer<vtkAppendPolyData>::New();
  appendFilter->AddInputData(this->PolyData);
  appendFilter->AddInputData(aPolyData);
  appendFilter->Update();
  SetPolyData(appendFilter->GetOutput());

  return PLUS_SUCCESS;
}

//-----------------------------------------------------------------------------

vtkStandardNewMacro(vtkDisplayableModel);

//-----------------------------------------------------------------------------
vtkDisplayableModel::vtkDisplayableModel()
  : vtkDisplayablePolyData()
  , STLModelFileName(NULL)
  , ModelToObjectTransform(NULL)
{
  vtkSmartPointer<vtkTransform> ModelToObjectTransform = vtkSmartPointer<vtkTransform>::New();
  ModelToObjectTransform->Identity();
  this->SetModelToObjectTransform(ModelToObjectTransform);
}

//-----------------------------------------------------------------------------
vtkDisplayableModel::~vtkDisplayableModel()
{
  this->SetSTLModelFileName(NULL);
  this->SetModelToObjectTransform(NULL);
}

//-----------------------------------------------------------------------------
PlusStatus vtkDisplayableModel::ReadConfiguration(vtkXMLDataElement* aConfig)
{
  LOG_TRACE("vtkDisplayableModel::ReadConfiguration");

  if (Superclass::ReadConfiguration(aConfig) != PLUS_SUCCESS)
  {
    LOG_ERROR("Unable to read basic displayable object configuration!");
    return PLUS_FAIL;
  }

  // ModelToObjectTransform stays identity if no model file has been found
  double ModelToObjectTransformMatrixValue[16] = {0};
  if (aConfig->GetVectorAttribute("ModelToObjectTransform", 16, ModelToObjectTransformMatrixValue))
  {
    this->ModelToObjectTransform->Identity();
    this->ModelToObjectTransform->Concatenate(ModelToObjectTransformMatrixValue);
  }

  this->SetSTLModelFileName(NULL);
  this->Displayable = false;

  std::string objectId = (this->ObjectId.empty() ? "unknown" : this->ObjectId);

  // If the tool name contains stylus or volume then we consider it a stylus - and do a few things differently
  // TODO: It would be probably better to define this explicitly in the config file rather than trying to figure it out from the tool name
  bool isVolume = (objectId.find("Volume") != std::string::npos);
  bool isStylus = (this->ObjectCoordinateFrame.find("Stylus") != std::string::npos);

  const char* modelFileName = aConfig->GetAttribute("File");
  if (modelFileName == NULL || STRCASECMP(modelFileName, "") == 0)
  {
    // Handle missing object models if possible
    if (isStylus)
    {
      LOG_DEBUG("No stylus model file found - default model will be displayed");
      if (SetDefaultStylusModel() != PLUS_SUCCESS)
      {
        LOG_WARNING("Failed to load default stylus model for displayable object '" << this->ObjectCoordinateFrame << "'");
        return PLUS_FAIL;
      }
      this->Displayable = true;
      return PLUS_SUCCESS;
    }
    else if (isVolume)
    {
      LOG_DEBUG("File not defined for Model: '" << objectId << "'. Assume that a polydata will be assigned later.");
    }
    else
    {
      LOG_WARNING("File not defined for Model: '" << objectId << "'. This model will not be displayed until a polydata is defined.");
    }
  }

  // Find absolute path for the file
  std::string modelFileFullPath;
  if (modelFileName != NULL && vtkPlusConfig::GetInstance()->FindModelPath(modelFileName, modelFileFullPath) == PLUS_SUCCESS)
  {
    this->SetSTLModelFileName(modelFileFullPath.c_str());
  }

  vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();

  if (this->STLModelFileName != NULL)
  {
    vtkSmartPointer<vtkSTLReader> stlReader = vtkSmartPointer<vtkSTLReader>::New();
    stlReader->SetFileName(this->STLModelFileName);
    stlReader->Update();
    SetPolyData(stlReader->GetOutput());
    mapper->SetInputData(this->PolyData);
  }

  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
  this->SetActor(actor);
  this->SetOpacity(this->LastOpacity);

  // Stylus is always black (actually, dark gray so that it can be seen in front of the image)
  if (isStylus)
  {
    this->SetColor(0.2, 0.2, 0.2);
  }

  this->Displayable = true;

  return PLUS_SUCCESS;
}

//-----------------------------------------------------------------------------
PlusStatus vtkDisplayableModel::SetDefaultStylusModel()
{
  LOG_TRACE("vtkDisplayableModel::SetDefaultStylusModel");

  vtkActor* actor = dynamic_cast<vtkActor*>(this->Actor);
  if (actor == NULL)
  {
    LOG_ERROR("Unable to load stylus model to an uninitialized or invalid actor!");
    return PLUS_FAIL;
  }

  // Create default model
  vtkSmartPointer<vtkPolyDataMapper> stylusMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  vtkSmartPointer<vtkCylinderSource> stylusBigCylinderSource = vtkSmartPointer<vtkCylinderSource>::New();
  stylusBigCylinderSource->SetRadius(3.0);   // mm
  stylusBigCylinderSource->SetHeight(120.0);   // mm
  stylusBigCylinderSource->SetCenter(0.0, 150.0, 0.0);
  vtkSmartPointer<vtkCylinderSource> stylusSmallCylinderSource = vtkSmartPointer<vtkCylinderSource>::New();
  stylusSmallCylinderSource->SetRadius(1.5);   // mm
  stylusSmallCylinderSource->SetHeight(80.0);   // mm
  stylusSmallCylinderSource->SetCenter(0.0, 50.0, 0.0);
  vtkSmartPointer<vtkConeSource> resultConeSource = vtkSmartPointer<vtkConeSource>::New();
  resultConeSource->SetRadius(1.5);   // mm
  resultConeSource->SetHeight(10.0);   //mm
  vtkSmartPointer<vtkTransform> coneTransform = vtkSmartPointer<vtkTransform>::New();
  coneTransform->Identity();
  coneTransform->RotateZ(-90.0);
  coneTransform->Translate(-5.0, 0.0, 0.0);
  vtkSmartPointer<vtkTransformPolyDataFilter> coneTransformFilter = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
  coneTransformFilter->AddInputConnection(resultConeSource->GetOutputPort());
  coneTransformFilter->SetTransform(coneTransform);

  vtkSmartPointer<vtkAppendPolyData> appendFilter = vtkSmartPointer<vtkAppendPolyData>::New();
  appendFilter->AddInputConnection(stylusBigCylinderSource->GetOutputPort());
  appendFilter->AddInputConnection(stylusSmallCylinderSource->GetOutputPort());
  appendFilter->AddInputConnection(coneTransformFilter->GetOutputPort());
  vtkSmartPointer<vtkTransform> stylusTransform = vtkSmartPointer<vtkTransform>::New();
  stylusTransform->Identity();
  stylusTransform->RotateZ(90.0);
  vtkSmartPointer<vtkTransformPolyDataFilter> stylusTransformFilter = vtkSmartPointer<vtkTransformPolyDataFilter>::New();
  stylusTransformFilter->AddInputConnection(appendFilter->GetOutputPort());
  stylusTransformFilter->SetTransform(stylusTransform);

  stylusMapper->SetInputConnection(stylusTransformFilter->GetOutputPort());
  actor->SetMapper(stylusMapper);
  actor->GetProperty()->SetColor(0.2, 0.2, 0.2);
  actor->SetVisibility(false);

  return PLUS_SUCCESS;
}