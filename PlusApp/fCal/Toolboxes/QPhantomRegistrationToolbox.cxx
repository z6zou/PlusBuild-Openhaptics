/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

// Local includes
#include "QPhantomRegistrationToolbox.h"
#include "fCalMainWindow.h"
#include "vtkPlusDisplayableObject.h"
#include "vtkPlusVisualizationController.h"

// Qt includes
#include <QFileDialog>
#include <QTimer>

// PlusLib includes
#include <PlusMath.h>
#include <vtkPlusAccurateTimer.h>
#include <vtkPlusFakeTracker.h>
#include <vtkPlusLandmarkDetectionAlgo.h>
#include <vtkPlusPhantomLandmarkRegistrationAlgo.h>
#include <vtkPlusPhantomLinearObjectRegistrationAlgo.h>
#include <vtkPlusPivotCalibrationAlgo.h>

// VTK includes
#include <vtkCamera.h>
#include <vtkGlyph3D.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkSTLReader.h>
#include <vtkSphereSource.h>
#include <vtkXMLUtilities.h>

//-----------------------------------------------------------------------------
QPhantomRegistrationToolbox::QPhantomRegistrationToolbox(fCalMainWindow* aParentMainWindow, Qt::WindowFlags aFlags)
  : QAbstractToolbox(aParentMainWindow)
  , QWidget(aParentMainWindow, aFlags)
  , m_PhantomLandmarkRegistration(vtkSmartPointer<vtkPlusPhantomLandmarkRegistrationAlgo>::New())
  , m_PhantomLinearObjectRegistration(vtkSmartPointer<vtkPlusPhantomLinearObjectRegistrationAlgo>::New())
  , m_LandmarkDetection(vtkSmartPointer<vtkPlusLandmarkDetectionAlgo>::New())
  , m_PhantomActor(vtkSmartPointer<vtkActor>::New())
  , m_RequestedLandmarkActor(vtkSmartPointer<vtkActor>::New())
  , m_RequestedLandmarkPolyData(vtkSmartPointer<vtkPolyData>::New())
  , m_PhantomRenderer(vtkSmartPointer<vtkRenderer>::New())
  , m_CurrentLandmarkIndex(0)
  , m_LinearObjectRegistrationState(LinearObjectRegistrationState_Incomplete)
  , m_LandmarkPivotingState(LandmarkPivotingState_Incomplete)
  , m_PreviousStylusTipToReferenceTransformMatrix(vtkSmartPointer<vtkMatrix4x4>::New())
  , m_LandmarkDetected(-1)
{
  ui.setupUi(this);

  // Create and add renderer to phantom canvas
  m_PhantomRenderer->SetBackground(0.1, 0.1, 0.1);
  m_PhantomRenderer->SetBackground2(0.4, 0.4, 0.4);
  m_PhantomRenderer->SetGradientBackground(true);

  ui.canvasPhantom->GetRenderWindow()->AddRenderer(m_PhantomRenderer);

  // Initialize requested landmarks visualization in toolbox canvas
  m_RequestedLandmarkPolyData->Initialize();
  vtkSmartPointer<vtkPoints> requestedLandmarkPoints = vtkSmartPointer<vtkPoints>::New();
  m_RequestedLandmarkPolyData->SetPoints(requestedLandmarkPoints);

  vtkSmartPointer<vtkPolyDataMapper> requestedLandmarksMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  vtkSmartPointer<vtkGlyph3D> requestedLandmarksGlyph = vtkSmartPointer<vtkGlyph3D>::New();
  vtkSmartPointer<vtkSphereSource> requestedLandmarksSphereSource = vtkSmartPointer<vtkSphereSource>::New();
  requestedLandmarksSphereSource->SetRadius(1.5);   // mm

  requestedLandmarksGlyph->SetInputData(m_RequestedLandmarkPolyData);
  requestedLandmarksGlyph->SetSourceConnection(requestedLandmarksSphereSource->GetOutputPort());
  requestedLandmarksMapper->SetInputConnection(requestedLandmarksGlyph->GetOutputPort());
  m_RequestedLandmarkActor->SetMapper(requestedLandmarksMapper);
  m_RequestedLandmarkActor->GetProperty()->SetColor(1.0, 0.5, 0.0);

  m_PhantomRenderer->AddActor(m_RequestedLandmarkActor);
  m_PhantomRenderer->AddActor(m_PhantomActor);

  // Connect events
  connect(ui.pushButton_OpenStylusCalibration, SIGNAL(clicked()), this, SLOT(OpenStylusCalibration()));
  connect(ui.pushButton_RecordPoint, SIGNAL(clicked()), this, SLOT(RecordPoint()));
  connect(ui.pushButton_Undo, SIGNAL(clicked()), this, SLOT(Undo()));
  connect(ui.pushButton_Landmark_Reset, SIGNAL(clicked()), this, SLOT(Reset()));

  connect(ui.pushButton_StartStop_LandmarkDetection, SIGNAL(clicked()), this, SLOT(StartLandmarkDetectionRegistration()));

  connect(ui.pushButton_StartStop, SIGNAL(clicked()), this, SLOT(StartLinearObjectRegistration()));
  connect(ui.pushButton_LinearObject_Reset, SIGNAL(clicked()), this, SLOT(ResetLinearObjectRegistration()));
}

//-----------------------------------------------------------------------------
QPhantomRegistrationToolbox::~QPhantomRegistrationToolbox()
{
  ui.canvasPhantom->GetRenderWindow()->RemoveRenderer(m_PhantomRenderer);
}

//-----------------------------------------------------------------------------
//Set the camera to view the next detection landmark to be found and highlight it
PlusStatus SetCameraViewAndHighlightNextLandmark(vtkCamera* activeCamera, vtkPlusPhantomLandmarkRegistrationAlgo* phantomLandmarkRegistration, int nextLandmarkIndex, vtkPoints* nextLandmark_Reference)
{
  double tempPtr[4] = { -1, 0, 0, 1}; //up vector
  activeCamera->SetViewUp(tempPtr);
  phantomLandmarkRegistration->GetDefinedLandmarksCentroid_Reference(tempPtr);
  activeCamera->SetFocalPoint(tempPtr);
  phantomLandmarkRegistration->GetLandmarkCameraPosition_Reference(nextLandmarkIndex, tempPtr);
  activeCamera->SetPosition(tempPtr);
  phantomLandmarkRegistration->GetDefinedLandmark_Reference(nextLandmarkIndex, tempPtr);
  nextLandmark_Reference->InsertPoint(0, tempPtr);
  nextLandmark_Reference->Modified();
  return PLUS_SUCCESS;
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::OnActivated()
{
  LOG_TRACE("PhantomRegistrationToolbox::OnActivated");

  if (m_State == ToolboxState_Done)
  {
    SetDisplayAccordingToState();
    return;
  }

  // Clear input polydata
  m_ParentMainWindow->GetVisualizationController()->ClearInputPolyData();
  m_ParentMainWindow->GetVisualizationController()->SetInputColor(1.0, 0.5, 0.0);

  if ((m_ParentMainWindow->GetVisualizationController()->GetDataCollector() != NULL)
      && (m_ParentMainWindow->GetVisualizationController()->GetDataCollector()->GetConnected()))
  {
    if (m_PhantomLandmarkRegistration->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS &&
        m_PhantomLinearObjectRegistration->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
    {
      LOG_ERROR("Reading phantom registration algorithms configuration failed!");
      return;
    }
    else
    {
      if (m_PhantomLandmarkRegistration->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS
          && m_LandmarkDetection->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
      {
        ui.tabWidget->setTabEnabled(0, false);
        LOG_WARNING("Phantom landmark definitions not found in XML tree. Perform Linear Object Registration instead!");
      }
      if (m_PhantomLinearObjectRegistration->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
      {
        ui.tabWidget->setTabEnabled(1, false);
        LOG_WARNING("Phantom plane definitions not found in XML tree. Perform Landmark Registration instead!");
      }
    }

    if (ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
    {
      LOG_ERROR("Stylus tool name cannot be loaded from device set configuration data!");
      return;
    }

    // Check if stylus tip to reference transform is available
    if (m_ParentMainWindow->GetVisualizationController()->IsExistingTransform(
          m_PhantomLandmarkRegistration->GetStylusTipCoordinateFrame(), m_PhantomLandmarkRegistration->GetReferenceCoordinateFrame()) == PLUS_SUCCESS)
    {
      // Set to InProgress if both stylus calibration and phantom definition are available
      Start();
    }

    // Set state to idle
    if (m_State == ToolboxState_Uninitialized || m_State == ToolboxState_Error)
    {
      SetState(ToolboxState_Idle);
    }
    else
    {
      SetDisplayAccordingToState();
    }
  }
  else
  {
    SetState(ToolboxState_Uninitialized);
  }
}

//-----------------------------------------------------------------------------
PlusStatus QPhantomRegistrationToolbox::ReadConfiguration(vtkXMLDataElement* aConfig)
{
  LOG_TRACE("PhantomRegistrationToolbox::ReadConfiguration");

  if (aConfig == NULL)
  {
    LOG_ERROR("Unable to read configuration");
    return PLUS_FAIL;
  }

  return PLUS_SUCCESS;
}

//-----------------------------------------------------------------------------
PlusStatus QPhantomRegistrationToolbox::LoadPhantomModel()
{
  LOG_TRACE("PhantomRegistrationToolbox::InitializeVisualization");

  if (m_ParentMainWindow->GetPhantomModelId() == NULL)
  {
    LOG_ERROR("Unable to retrieve phantom model by ID. Is the phantom model ID well defined?");
    return PLUS_FAIL;
  }
  vtkPlusDisplayableObject* phantom = m_ParentMainWindow->GetVisualizationController()->GetObjectById(m_ParentMainWindow->GetPhantomModelId());
  vtkDisplayableModel* phantomDisplayableModel = dynamic_cast<vtkDisplayableModel*>(phantom);
  if (phantomDisplayableModel == NULL)
  {
    LOG_ERROR("Unable to retrieve phantom model by ID. Is the phantom model ID well defined?");
    return PLUS_FAIL;
  }

  vtkSmartPointer<vtkPolyDataMapper> stlMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  stlMapper->SetInputData(phantomDisplayableModel->GetPolyData());
  m_PhantomActor->SetMapper(stlMapper);
  m_PhantomActor->GetProperty()->SetOpacity(phantomDisplayableModel->GetLastOpacity());

  if (phantomDisplayableModel->GetModelToObjectTransform() != NULL)
  {
    m_PhantomActor->SetUserTransform(phantomDisplayableModel->GetModelToObjectTransform());
  }
  else
  {
    LOG_WARNING("Phantom cannot be visualized in toolbox canvas because model or model to object transform is invalid");
  }

  m_PhantomRenderer->ResetCamera();

  return PLUS_SUCCESS;
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::RefreshContent()
{
  //LOG_TRACE("PhantomRegistrationToolbox::RefreshContent");

  // If in progress
  if (m_State == ToolboxState_InProgress)
  {
    if (ui.tabWidget->currentIndex() == TabIndex_LinearObject)
    {
      if (GetLinearObjectRegistrationState() == LinearObjectRegistrationState_Incomplete)
      {
        ui.label_Instructions->setText("Press Start to begin identifying surfaces\n\n\n");
      }
      else if (GetLinearObjectRegistrationState() == LinearObjectRegistrationState_InProgress)
      {
        ui.label_Instructions->setText("Run the stylus along each linear object\nPress Stop when you have recorded each linear object\n");
      }
      else if (GetLinearObjectRegistrationState() == LinearObjectRegistrationState_Complete)
      {
        ui.label_Instructions->setText("Linear Object Registration is ready to be saved\nPress Reset to clear your current Linear Object registration");
      }
    }
    else if (ui.tabWidget->currentIndex() == TabIndex_Landmark)
    {
      if (GetLandmarkPivotingState() == LandmarkPivotingState_Incomplete)
      {
        ui.label_Instructions->setText("Press the Start Landmark Detection button\n\n");
      }
      else if (GetLandmarkPivotingState() == LandmarkPivotingState_InProgress)
      {
        if (m_LandmarkDetected >= 0)
        {
          ui.label_Instructions->setStyleSheet("QLabel { color : orange; }");
          ui.label_Instructions->setText(QString("The landmark %1 is already detected\n\n").arg(m_PhantomLandmarkRegistration->GetDefinedLandmarkName(m_LandmarkDetected).c_str()));
        }
        else
        {
          ui.label_Instructions->setStyleSheet("QLabel { color : black; }");
          ui.label_Instructions->setText(QString("Slowly pivot around landmark named %1 until detected \n\n").arg(m_PhantomLandmarkRegistration->GetDefinedLandmarkName(m_CurrentLandmarkIndex).c_str()));
        }
      }
      else if (GetLandmarkPivotingState() == LandmarkPivotingState_Complete)
      {
        ui.label_Instructions->setText("Landmark Object Registration is ready to be saved\nPress Reset to clear your current Landmark Object registration");
      }
    }
    else if (ui.tabWidget->currentIndex() == -1)
    {
      LOG_ERROR("No tabs in tab widget, how on earth did this happen!?");
    }

    if (GetLinearObjectRegistrationState() == LinearObjectRegistrationState_Incomplete)
    {
      ui.pushButton_LinearObject_Reset->setEnabled(false);
    }
    else if (GetLinearObjectRegistrationState() == LinearObjectRegistrationState_Complete)
    {
      ui.pushButton_LinearObject_Reset->setEnabled(true);
    }

    if (m_CurrentLandmarkIndex < 1)
    {
      ui.pushButton_Undo->setEnabled(false);
      ui.pushButton_Landmark_Reset->setEnabled(false);
    }
    else
    {
      ui.pushButton_Undo->setEnabled(true);
      ui.pushButton_Landmark_Reset->setEnabled(true);
    }

    m_ParentMainWindow->SetStatusBarProgress((int)(100.0 * (m_CurrentLandmarkIndex / m_PhantomLandmarkRegistration->GetDefinedLandmarks_Phantom()->GetNumberOfPoints()) + 0.5));
  }

  if (m_State == ToolboxState_Done || m_State == ToolboxState_InProgress)
  {
    // Get stylus tip position and display it
    std::string stylusTipPosition;
    ToolStatus status(TOOL_INVALID);
    if (m_ParentMainWindow->GetVisualizationController()->GetTransformTranslationString(m_PhantomLandmarkRegistration->GetStylusTipCoordinateFrame(), m_PhantomLandmarkRegistration->GetReferenceCoordinateFrame(), stylusTipPosition, &status) != PLUS_SUCCESS)
    {
      LOG_ERROR("Unable to get stylus tip to reference transform!");
      return;
    }

    switch (status)
    {
      default:
      case TOOL_UNKNOWN:
        {
          ui.label_StylusPositionText->setText(tr("Unknown error."));
        }
      case TOOL_OK:
      case TOOL_SWITCH1_IS_ON:
      case TOOL_SWITCH2_IS_ON:
      case TOOL_SWITCH3_IS_ON:
        {
          ui.label_StylusPositionText->setText(QString(stylusTipPosition.c_str()));
        }
      case TOOL_MISSING:
        {
          ui.label_StylusPositionText->setText(tr("Stylus is missing"));
        }
      case TOOL_OUT_OF_VIEW:
        {
          ui.label_StylusPositionText->setText(tr("Stylus is out of view"));
        }
      case TOOL_OUT_OF_VOLUME:
        {
          ui.label_StylusPositionText->setText(tr("Stylus is out of volume"));
        }
      case TOOL_REQ_TIMEOUT:
        {
          ui.label_StylusPositionText->setText(tr("Stylus request timed out"));
        }
      case TOOL_INVALID:
        {
          ui.label_StylusPositionText->setText(tr("Stylus is invalid"));
        }
      case TOOL_PATH_NOT_FOUND:
        {
          ui.label_StylusPositionText->setText(tr("Stylus cannot be calculated from given inputs"));
        }
    }
  }

  ui.canvasPhantom->update();
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::SetDisplayAccordingToState()
{
  LOG_TRACE("PhantomRegistrationToolbox::SetDisplayAccordingToState");

  // If connected
  if ((m_ParentMainWindow->GetVisualizationController()->GetDataCollector() != NULL)
      && (m_ParentMainWindow->GetVisualizationController()->GetDataCollector()->GetConnected()))
  {
    // If the force show devices isn't enabled, set it to 3D and hide all the devices
    // Later, we will re-enable only those that we wish shown for this toolbox
    if (!m_ParentMainWindow->IsForceShowDevicesEnabled())
    {
      m_ParentMainWindow->GetVisualizationController()->SetVisualizationMode(vtkPlusVisualizationController::DISPLAY_MODE_3D);
      m_ParentMainWindow->GetVisualizationController()->HideAll();
    }

    // Enable or disable the image manipulation menu
    m_ParentMainWindow->SetImageManipulationMenuEnabled(m_ParentMainWindow->GetVisualizationController()->Is2DMode());

    // Update state message according to available transforms
    if (m_PhantomLandmarkRegistration->GetPhantomCoordinateFrame() && m_PhantomLandmarkRegistration->GetReferenceCoordinateFrame())
    {
      if (m_ParentMainWindow->GetVisualizationController()->IsExistingTransform(m_PhantomLandmarkRegistration->GetStylusTipCoordinateFrame(),
          m_PhantomLandmarkRegistration->GetReferenceCoordinateFrame()) == PLUS_SUCCESS)
      {
        std::string phantomToReferenceTransformNameStr;
        PlusTransformName phantomToReferenceTransformName(
          m_PhantomLandmarkRegistration->GetPhantomCoordinateFrame(), m_PhantomLandmarkRegistration->GetReferenceCoordinateFrame());
        phantomToReferenceTransformName.GetTransformName(phantomToReferenceTransformNameStr);

        if (m_ParentMainWindow->GetVisualizationController()->IsExistingTransform(
              m_PhantomLandmarkRegistration->GetPhantomCoordinateFrame(), m_PhantomLandmarkRegistration->GetReferenceCoordinateFrame(), false) == PLUS_SUCCESS)
        {
          std::string date, errorStr;
          double error;
          if (m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->GetTransformDate(phantomToReferenceTransformName, date) != PLUS_SUCCESS)
          {
            date = "N/A";
          }
          if (m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->GetTransformError(phantomToReferenceTransformName, error) == PLUS_SUCCESS)
          {
            std::stringstream ss;
            ss << std::fixed << error;
            errorStr = ss.str();
          }
          else
          {
            errorStr = "N/A";
          }

          QPalette palette;
          palette.setColor(ui.label_State->foregroundRole(), Qt::black);
          ui.label_State->setPalette(palette);
          ui.label_State->setText(QString("%1 transform present.\nDate: %2, Error: %3").arg(phantomToReferenceTransformNameStr.c_str()).arg(date.c_str()).arg(errorStr.c_str()));
        }
        else
        {
          QPalette palette;
          palette.setColor(ui.label_State->foregroundRole(), QColor::fromRgb(255, 128, 0));
          ui.label_State->setPalette(palette);
          ui.label_State->setText(QString("%1 transform is absent, registration needs to be performed.").arg(phantomToReferenceTransformNameStr.c_str()));
          LOG_INFO(phantomToReferenceTransformNameStr << " transform is absent, registration needs to be performed");
        }
      }
      else
      {
        QPalette palette;
        palette.setColor(ui.label_State->foregroundRole(), QColor::fromRgb(255, 128, 0));
        ui.label_State->setPalette(palette);
        ui.label_State->setText(tr("Stylus calibration is missing. It needs to be performed or imported."));
        LOG_INFO("Stylus calibration is missing. It needs to be performed or imported");
        m_State = ToolboxState_Error;
      }
    }
    else
    {
      QPalette palette;
      palette.setColor(ui.label_State->foregroundRole(), QColor::fromRgb(255, 128, 0));
      ui.label_State->setPalette(palette);
      ui.label_State->setText(QString("Phantom registration configuration is missing!"));
      LOG_INFO("Phantom registration configuration is missing");
      m_State = ToolboxState_Error;
    }
  }
  else
  {
    QPalette palette;
    palette.setColor(ui.label_State->foregroundRole(), QColor::fromRgb(255, 128, 0));
    ui.label_State->setPalette(palette);
    ui.label_State->setText(tr("fCal is not connected to devices. Switch to Configuration toolbox to connect."));
    LOG_INFO("fCal is not connected to devices. Switch to Configuration toolbox to connect.");
    m_State = ToolboxState_Error;
  }

  // Set widget states according to state
  if (m_State == ToolboxState_Uninitialized)
  {
    ui.label_StylusPositionText->setText(tr("Stylus position unavailable"));
    ui.label_Instructions->setText("");

    ui.pushButton_OpenStylusCalibration->setEnabled(false);

    ui.pushButton_RecordPoint->setEnabled(false);
    ui.pushButton_Landmark_Reset->setEnabled(false);
    ui.pushButton_Undo->setEnabled(false);
    ui.pushButton_LinearObject_Reset->setEnabled(false);

    ui.pushButton_StartStop_LandmarkDetection->setEnabled(false);
    ui.pushButton_StartStop_LandmarkDetection->setText("Start Landmark Detection");

    ui.pushButton_StartStop->setEnabled(false);
    ui.pushButton_StartStop->setText("Start");

    m_ParentMainWindow->SetStatusBarText(QString(""));
    m_ParentMainWindow->SetStatusBarProgress(-1);
  }
  else if (m_State == ToolboxState_Idle)
  {
    ui.label_StylusPositionText->setText(tr("Stylus position unavailable"));

    ui.pushButton_OpenStylusCalibration->setEnabled(true);

    ui.pushButton_RecordPoint->setEnabled(false);
    ui.pushButton_Landmark_Reset->setEnabled(false);
    ui.pushButton_Undo->setEnabled(false);

    ui.pushButton_StartStop_LandmarkDetection->setEnabled(false);
    ui.pushButton_StartStop_LandmarkDetection->setText("Start Landmark Detection");

    ui.pushButton_LinearObject_Reset->setEnabled(false);
    ui.pushButton_StartStop->setEnabled(false);
    ui.pushButton_StartStop->setText("Start");

    m_ParentMainWindow->SetStatusBarText(QString(""));
    m_ParentMainWindow->SetStatusBarProgress(-1);
  }
  else if (m_State == ToolboxState_InProgress)
  {
    ui.pushButton_OpenStylusCalibration->setEnabled(true);
    ui.pushButton_StartStop_LandmarkDetection->setEnabled(true);
    if (m_LandmarkPivotingState == LandmarkPivotingState_InProgress)
    {
      ui.pushButton_RecordPoint->setEnabled(true);
      ui.pushButton_RecordPoint->setFocus();
      m_ParentMainWindow->GetVisualizationController()->ShowInput(true);
    }

    ui.pushButton_StartStop->setEnabled(true);

    if (m_CurrentLandmarkIndex < 1)
    {
      ui.pushButton_Undo->setEnabled(false);
      ui.pushButton_Landmark_Reset->setEnabled(false);
    }
    else
    {
      ui.pushButton_Undo->setEnabled(true);
      ui.pushButton_Landmark_Reset->setEnabled(true);
    }

    m_ParentMainWindow->SetStatusBarText(QString(" Recording phantom landmarks"));
    m_ParentMainWindow->SetStatusBarProgress(0);

    m_ParentMainWindow->GetVisualizationController()->ShowResult(true);
    m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetStylusModelId(), true);
    if (m_CurrentLandmarkIndex >= 3)
    {
      m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomModelId(), true);
      m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomWiresModelId(), true);
    }
  }
  else if (m_State == ToolboxState_Done)
  {
    ui.label_Instructions->setText(QString("Registration error is %1 mm\nTransform is ready to save\n\n").arg(m_PhantomLandmarkRegistration->GetRegistrationErrorMm(), 0, 'f', 6));

    ui.pushButton_OpenStylusCalibration->setEnabled(true);

    ui.pushButton_RecordPoint->setEnabled(false);
    ui.pushButton_Landmark_Reset->setEnabled(true);
    ui.pushButton_Undo->setEnabled(true);

    ui.pushButton_StartStop_LandmarkDetection->setEnabled(true);

    ui.pushButton_StartStop->setEnabled(true);

    m_ParentMainWindow->SetStatusBarText(QString(" Phantom registration done"));
    m_ParentMainWindow->SetStatusBarProgress(-1);

    m_ParentMainWindow->GetVisualizationController()->ShowInput(false);
    m_ParentMainWindow->GetVisualizationController()->ShowResult(true);
    m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomModelId(), true);
    m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomWiresModelId(), true);
    m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetStylusModelId(), true);
  }
  else if (m_State == ToolboxState_Error)
  {
    ui.label_StylusPositionText->setText(tr("N/A"));
    ui.label_Instructions->setText("");

    ui.pushButton_OpenStylusCalibration->setEnabled(true);
    ui.pushButton_RecordPoint->setEnabled(false);
    ui.pushButton_Landmark_Reset->setEnabled(false);
    ui.pushButton_Undo->setEnabled(false);

    ui.pushButton_StartStop_LandmarkDetection->setEnabled(false);
    ui.pushButton_StartStop_LandmarkDetection->setText("Start Landmark Detection");

    ui.pushButton_LinearObject_Reset->setEnabled(false);
    ui.pushButton_StartStop->setEnabled(false);
    ui.pushButton_StartStop->setText("Start");

    m_ParentMainWindow->SetStatusBarText(QString(""));
    m_ParentMainWindow->SetStatusBarProgress(-1);
  }
}

//-----------------------------------------------------------------------------
PlusStatus QPhantomRegistrationToolbox::Start()
{
  LOG_TRACE("PhantomRegistrationToolbox::Start");

  // Check number of landmarks
  if (m_PhantomLandmarkRegistration->GetDefinedLandmarks_Phantom()->GetNumberOfPoints() < 4)
  {
    LOG_ERROR("Not enough (" << m_PhantomLandmarkRegistration->GetDefinedLandmarks_Phantom()->GetNumberOfPoints() << ") defined landmarks (should be at least 4)!");
    return PLUS_FAIL;
  }

  // Initialize toolbox canvas
  if (LoadPhantomModel() != PLUS_SUCCESS)
  {
    LOG_ERROR("Initializing phantom registration visualization failed!");
    return PLUS_FAIL;
  }

  if (m_ParentMainWindow->GetVisualizationController()->IsExistingTransform(
        m_PhantomLandmarkRegistration->GetStylusTipCoordinateFrame(), m_PhantomLandmarkRegistration->GetReferenceCoordinateFrame()) == PLUS_SUCCESS)
  {
    m_CurrentLandmarkIndex = 0;

    // Initialize result points polydata in visualizer
    m_ParentMainWindow->GetVisualizationController()->ClearResultPolyData();

    // Highlight first landmark
    m_RequestedLandmarkPolyData->GetPoints()->InsertPoint(0, m_PhantomLandmarkRegistration->GetDefinedLandmarks_Phantom()->GetPoint(0));
    m_RequestedLandmarkPolyData->GetPoints()->Modified();

    SetState(ToolboxState_InProgress);
  }
  else
  {
    LOG_ERROR("No stylus tip to reference transform available!");
    SetState(ToolboxState_Error);
    return PLUS_FAIL;
  }

  vtkPlusDataCollector* dataCollector = m_ParentMainWindow->GetVisualizationController()->GetDataCollector();
  m_LandmarkDetection->SetMinimunDistanceBetweenLandmarksMm(m_PhantomLandmarkRegistration->GetMinimunDistanceBetweenTwoLandmarksMm());

  if (dataCollector)
  {
    for (DeviceCollectionConstIterator it = dataCollector->GetDeviceConstIteratorBegin(); it != dataCollector->GetDeviceConstIteratorEnd(); ++it)
    {
      vtkPlusDevice* vtkTracker = dynamic_cast<vtkPlusDevice*>(*it);
      if (vtkTracker != NULL)
      {
        if (vtkTracker->IsTracker())
        {
          m_LandmarkDetection->SetAcquisitionRate(vtkTracker->GetAcquisitionRate());
          break;
        }
      }
    }
  }
  //If acquisition rate and/or pivot threshold were specified in the configuration file,read them again and used those values.
  m_LandmarkDetection->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData());

  return PLUS_SUCCESS;
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::OpenStylusCalibration()
{
  LOG_TRACE("PhantomRegistrationToolbox::OpenStylusCalibration");

  // File open dialog for selecting phantom definition xml
  QString filter = QString(tr("XML files ( *.xml );;"));
  QString fileName = QFileDialog::getOpenFileName(NULL, QString(tr("Open stylus calibration XML")),
                     vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationDirectory().c_str(), filter);
  if (fileName.isNull())
  {
    return;
  }

  // Parse XML file
  vtkSmartPointer<vtkXMLDataElement> rootElement = vtkSmartPointer<vtkXMLDataElement>::Take(vtkXMLUtilities::ReadElementFromFile(fileName.toLatin1().constData()));
  if (rootElement == NULL)
  {
    LOG_ERROR("Unable to read the configuration file: " << fileName.toLatin1().constData());
    return;
  }

  // Read stylus coordinate frame name
  vtkPlusPivotCalibrationAlgo* pivotCalibrationAlgo = vtkPlusPivotCalibrationAlgo::New();
  if (pivotCalibrationAlgo->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
  {
    LOG_ERROR("Failed to read stylus coordinate frame name!");
    pivotCalibrationAlgo->Delete();
    return;
  }

  // Read stylus calibration transform
  PlusTransformName stylusTipToStylusTransformName(m_PhantomLandmarkRegistration->GetStylusTipCoordinateFrame(), pivotCalibrationAlgo->GetObjectMarkerCoordinateFrame());

  vtkSmartPointer<vtkMatrix4x4> stylusTipToStylusTransformMatrix = vtkSmartPointer<vtkMatrix4x4>::New();
  std::string transformDate;
  double transformError = 0.0;
  ToolStatus status(TOOL_INVALID);
  vtkPlusTransformRepository* tempTransformRepo = vtkPlusTransformRepository::New();
  if (tempTransformRepo->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS
      || tempTransformRepo->GetTransform(stylusTipToStylusTransformName, stylusTipToStylusTransformMatrix, &status) != PLUS_SUCCESS
      || tempTransformRepo->GetTransformDate(stylusTipToStylusTransformName, transformDate) != PLUS_SUCCESS
      || tempTransformRepo->GetTransformError(stylusTipToStylusTransformName, transformError) != PLUS_SUCCESS)
  {
    LOG_ERROR("Failed to read transform from opened file!");
    pivotCalibrationAlgo->Delete();
    tempTransformRepo->Delete();
    return;
  }

  tempTransformRepo->Delete();
  pivotCalibrationAlgo->Delete();

  if (status == TOOL_OK)
  {
    if (m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->SetTransform(stylusTipToStylusTransformName, stylusTipToStylusTransformMatrix) != PLUS_SUCCESS)
    {
      LOG_ERROR("Failed to set stylus calibration transform to transform repository!");
      return;
    }

    m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->SetTransformDate(stylusTipToStylusTransformName, transformDate.c_str());
    m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->SetTransformError(stylusTipToStylusTransformName, transformError);
    m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->SetTransformPersistent(stylusTipToStylusTransformName, true);
  }
  else
  {
    LOG_ERROR("Invalid stylus calibration transform found, it was not set!");
  }

  // Set to InProgress if both stylus calibration and phantom definition are available
  Start();
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::RecordPoint()
{
  LOG_TRACE("PhantomRegistrationToolbox::RecordPoint");

  //// disConnect acquisition function to timer, Maybe needed but it work without it.
  //disconnect( m_ParentMainWindow->GetVisualizationController()->GetAcquisitionTimer(), SIGNAL( timeout() ), this, SLOT( AddStylusTipPositionToLandmarkPivotingRegistration() ) );

  // If tracker is FakeTracker then set counter (trigger position change) and wait for it to apply the new position
  vtkPlusDataCollector* dataCollector = m_ParentMainWindow->GetVisualizationController()->GetDataCollector();

  if (dataCollector)
  {
    for (DeviceCollectionConstIterator it = dataCollector->GetDeviceConstIteratorBegin(); it != dataCollector->GetDeviceConstIteratorEnd(); ++it)
    {
      vtkPlusFakeTracker* fakeTracker = dynamic_cast<vtkPlusFakeTracker*>(*it);
      if (fakeTracker != NULL)
      {
        fakeTracker->SetCounter(m_CurrentLandmarkIndex);
        fakeTracker->SetTransformRepository(m_ParentMainWindow->GetVisualizationController()->GetTransformRepository());
        vtkPlusAccurateTimer::Delay(2.1 / fakeTracker->GetAcquisitionRate());
        break;
      }
    }
  }

  // Acquire point
  vtkSmartPointer<vtkMatrix4x4> stylusTipToReferenceTransformMatrix = vtkSmartPointer<vtkMatrix4x4>::New();
  ToolStatus status(TOOL_INVALID);
  if (m_ParentMainWindow->GetVisualizationController()->GetTransformMatrix(m_PhantomLandmarkRegistration->GetStylusTipCoordinateFrame(), m_PhantomLandmarkRegistration->GetReferenceCoordinateFrame(), stylusTipToReferenceTransformMatrix, &status) != PLUS_SUCCESS)
  {
    LOG_ERROR("No transform found between stylus and reference!");
    return;
  }

  // Add point to registration algorithm
  if (status != TOOL_OK)
  {
    LOG_WARNING("Invalid stylus tip to reference transform - cannot be added!");
    return;
  }

  double stylusTipPosition_Reference[4] = {stylusTipToReferenceTransformMatrix->GetElement(0, 3), stylusTipToReferenceTransformMatrix->GetElement(1, 3), stylusTipToReferenceTransformMatrix->GetElement(2, 3), 1.0 };

  //Insert the pivot position for the pivot detection and see if a new pivot is found (that only resets the pivot detection found flag).
  if (m_LandmarkDetection->InsertLandmark_Reference(stylusTipPosition_Reference) == PLUS_FAIL)
  {
    return;
  }

  // Add recorded point to registration algorithm
  m_PhantomLandmarkRegistration->GetRecordedLandmarks_Reference()->InsertPoint(m_CurrentLandmarkIndex, stylusTipPosition_Reference[0], stylusTipPosition_Reference[1], stylusTipPosition_Reference[2]);

  vtkPoints* points = m_ParentMainWindow->GetVisualizationController()->GetResultPolyDataPoints();
  // Add recorded point to visualization
  points->InsertPoint(m_CurrentLandmarkIndex, stylusTipPosition_Reference[0], stylusTipPosition_Reference[1], stylusTipPosition_Reference[2]);
  points->Modified();

  // Set new current landmark number and reset request flag
  ++m_CurrentLandmarkIndex;

  ui.tabWidget->setTabEnabled(1, false);

  // If there are at least 3 acquired points then register
  if (m_CurrentLandmarkIndex >= 3)
  {
    if (m_PhantomLandmarkRegistration->LandmarkRegister(m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()) == PLUS_SUCCESS)
    {
      m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomModelId(), true);
      m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomWiresModelId(), true);
      // Set the camera to face the new landmark to be found and highlight next landmark
      m_ParentMainWindow->GetVisualizationController()->ShowInput(true);
      SetCameraViewAndHighlightNextLandmark(m_ParentMainWindow->GetVisualizationController()->GetCanvasRenderer()->GetActiveCamera(), m_PhantomLandmarkRegistration,
                                            m_CurrentLandmarkIndex, m_ParentMainWindow->GetVisualizationController()->GetInputPolyDataPoints());
    }
    else
    {
      LOG_ERROR("Phantom landmark registration failed!");
    }
  }
  else
  {
    m_ParentMainWindow->GetVisualizationController()->GetCanvasRenderer()->ResetCamera();
  }

  // If it was the last landmark then write configuration, set status to done and reset landmark counter
  if (m_CurrentLandmarkIndex == m_PhantomLandmarkRegistration->GetDefinedLandmarks_Phantom()->GetNumberOfPoints())
  {
    ui.tabWidget->setTabEnabled(1, false);

    if (m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->WriteConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
    {
      LOG_ERROR("Unable to save phantom registration result in configuration XML tree!");
      SetState(ToolboxState_Error);
      return;
    }
    SetState(ToolboxState_Done);
    m_RequestedLandmarkPolyData->GetPoints()->GetData()->RemoveTuple(0);
    m_RequestedLandmarkPolyData->GetPoints()->Modified();

    LOG_INFO("Phantom landmark registration performed successfully");
    StopLandmarkPivotingRegistration();
  }
  else
  {
    // Highlight next landmark in left side render
    m_RequestedLandmarkPolyData->GetPoints()->InsertPoint(0, m_PhantomLandmarkRegistration->GetDefinedLandmarks_Phantom()->GetPoint(m_CurrentLandmarkIndex));
    m_RequestedLandmarkPolyData->GetPoints()->Modified();
  }
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::Undo()
{
  LOG_TRACE("PhantomRegistrationToolbox::Undo");

  if (m_State == ToolboxState_Done)
  {
    SetState(ToolboxState_InProgress);
    ui.tabWidget->setTabEnabled(1, false);
  }
  if (m_LandmarkPivotingState == LandmarkPivotingState_Complete)
  {
    SetLandmarkPivotingState(LandmarkPivotingState_InProgress);
    StartLandmarkDetectionRegistration();
  }
  if (m_CurrentLandmarkIndex > 0)
  {
    if (m_CurrentLandmarkIndex == 1)
    {
      ui.tabWidget->setTabEnabled(1, true);
    }

    // Decrease current landmark index
    --m_CurrentLandmarkIndex;

    // Reset result transform (in case Undo was pressed when the registration was ready)
    m_PhantomLandmarkRegistration->SetPhantomToReferenceTransformMatrix(NULL);

    // Delete previously acquired landmark
    m_ParentMainWindow->GetVisualizationController()->GetResultPolyDataPoints()->GetData()->RemoveTuple(m_CurrentLandmarkIndex);
    m_ParentMainWindow->GetVisualizationController()->GetResultPolyDataPoints()->Modified();
    m_LandmarkDetection->DeleteLastLandmark();

    // Highlight previous landmark in left side render
    m_RequestedLandmarkPolyData->GetPoints()->InsertPoint(0, m_PhantomLandmarkRegistration->GetDefinedLandmarks_Phantom()->GetPoint(m_CurrentLandmarkIndex));
    m_RequestedLandmarkPolyData->GetPoints()->Modified();

    // If there are at least 3 acquired points then register
    if (m_CurrentLandmarkIndex >= 3)
    {
      if (m_PhantomLandmarkRegistration->LandmarkRegister(m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()) == PLUS_SUCCESS)
      {
        m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomModelId(), true);
        m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomWiresModelId(), true);
        // Set the camera to face the new pivot to be found
        SetCameraViewAndHighlightNextLandmark(m_ParentMainWindow->GetVisualizationController()->GetCanvasRenderer()->GetActiveCamera(), m_PhantomLandmarkRegistration,
                                              m_CurrentLandmarkIndex, m_ParentMainWindow->GetVisualizationController()->GetInputPolyDataPoints());
      }
      else
      {
        LOG_ERROR("Phantom landmark registration failed!");
      }
    }
    else
    {
      if (m_CurrentLandmarkIndex == 2)
      {
        m_ParentMainWindow->GetVisualizationController()->GetInputPolyDataPoints()->GetData()->RemoveTuple(0);
        m_ParentMainWindow->GetVisualizationController()->GetInputPolyDataPoints()->GetData()->Modified();
      }
      // Hide phantom from main canvas
      m_ParentMainWindow->GetVisualizationController()->ShowInput(false);
      m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomModelId(), false);
      m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomWiresModelId(), false);
      m_ParentMainWindow->GetVisualizationController()->GetCanvasRenderer()->ResetCamera();
    }
  }

  // If tracker is FakeTracker then set counter
  vtkPlusDataCollector* dataCollector = m_ParentMainWindow->GetVisualizationController()->GetDataCollector();
  if (dataCollector)
  {
    for (DeviceCollectionConstIterator it = dataCollector->GetDeviceConstIteratorBegin(); it != dataCollector->GetDeviceConstIteratorEnd(); ++it)
    {
      vtkPlusFakeTracker* fakeTracker = dynamic_cast<vtkPlusFakeTracker*>(*it);

      if (fakeTracker != NULL)
      {
        fakeTracker->SetCounter(m_CurrentLandmarkIndex);
        break;
      }
    }
  }
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::Reset()
{
  LOG_TRACE("PhantomRegistrationToolbox::Reset");

  if (m_State == ToolboxState_Done)
  {
    SetState(ToolboxState_InProgress);
  }

  //In case the reset stops the detection as well.
  //StopLandmarkPivotingRegistration();
  m_LandmarkDetection->ResetDetection();
  if (m_LandmarkPivotingState == LandmarkPivotingState_Complete)
  {
    SetLandmarkPivotingState(LandmarkPivotingState_Incomplete);
  }

  // Delete acquired landmarks
  m_ParentMainWindow->GetVisualizationController()->ClearResultPolyData();
  // Delete next landmark point
  m_ParentMainWindow->GetVisualizationController()->ClearInputPolyData();

  // Reset current landmark index
  m_CurrentLandmarkIndex = 0;

  // Reset result transform (if Reset was pressed when the registration was ready we have to make it null)
  m_PhantomLandmarkRegistration->SetPhantomToReferenceTransformMatrix(NULL);

  // Highlight first landmark
  if ((m_State != ToolboxState_Uninitialized) && (m_PhantomLandmarkRegistration->GetDefinedLandmarks_Phantom()->GetNumberOfPoints() > 0))
  {
    m_RequestedLandmarkPolyData->GetPoints()->InsertPoint(0, m_PhantomLandmarkRegistration->GetDefinedLandmarks_Phantom()->GetPoint(0));
    m_RequestedLandmarkPolyData->GetPoints()->Modified();
  }

  // Hide phantom from main canvas
  if (m_PhantomLandmarkRegistration->GetReferenceCoordinateFrame())
  {
    m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomModelId(), false);
    m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomWiresModelId(), false);
  }

  // If tracker is FakeTracker then reset counter
  vtkPlusDataCollector* dataCollector = m_ParentMainWindow->GetVisualizationController()->GetDataCollector();
  if (dataCollector)
  {
    for (DeviceCollectionConstIterator it = dataCollector->GetDeviceConstIteratorBegin(); it != dataCollector->GetDeviceConstIteratorEnd(); ++it)
    {
      vtkPlusFakeTracker* fakeTracker = dynamic_cast<vtkPlusFakeTracker*>(*it);

      if (fakeTracker != NULL)
      {
        fakeTracker->SetCounter(m_CurrentLandmarkIndex);
        break;
      }
    }
  }

  ui.tabWidget->setTabEnabled(0, true);
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::OnDeactivated()
{
  StopLandmarkPivotingRegistration();
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::StartLinearObjectRegistration()
{
  LOG_TRACE("PhantomRegistrationToolbox::StartLinearObjectRegistration");

  disconnect(ui.pushButton_StartStop, SIGNAL(clicked()), this, SLOT(StartLinearObjectRegistration()));
  connect(ui.pushButton_StartStop, SIGNAL(clicked()), this, SLOT(StopLinearObjectRegistration()));

  ui.tabWidget->setTabEnabled(0, false);
  ui.pushButton_LinearObject_Reset->setEnabled(false);
  ui.pushButton_StartStop->setText(tr("Stop"));

  SetLinearObjectRegistrationState(LinearObjectRegistrationState_InProgress);

  m_CurrentPointNumber = 0;

  // Clear result points
  m_ParentMainWindow->GetVisualizationController()->ClearResultPolyData();

  // Initialize stylus tool
  vtkPlusDisplayableObject* object = m_ParentMainWindow->GetVisualizationController()->GetObjectById(m_ParentMainWindow->GetStylusModelId());
  if (object == NULL)
  {
    LOG_ERROR("No stylus tip displayable objects could be found!");
    return;
  }

  // Set state to in progress
  SetLinearObjectRegistrationState(LinearObjectRegistrationState_InProgress);

  // Connect acquisition function to timer
  connect(&m_ParentMainWindow->GetVisualizationController()->GetAcquisitionTimer(), SIGNAL(timeout()), this, SLOT(AddStylusTipTransformToLinearObjectRegistration()));
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::StopLinearObjectRegistration()
{
  LOG_TRACE("PhantomRegistrationToolbox::StopLinearObjectRegistration");

  disconnect(ui.pushButton_StartStop, SIGNAL(clicked()), this, SLOT(StopLinearObjectRegistration()));
  connect(ui.pushButton_StartStop, SIGNAL(clicked()), this, SLOT(StartLinearObjectRegistration()));

  ui.pushButton_LinearObject_Reset->setEnabled(true);
  ui.pushButton_StartStop->setEnabled(false);
  ui.pushButton_StartStop->setText(tr("Start"));

  SetLinearObjectRegistrationState(LinearObjectRegistrationState_Complete);

  // Disconnect acquisition function to timer
  disconnect(&m_ParentMainWindow->GetVisualizationController()->GetAcquisitionTimer(), SIGNAL(timeout()), this, SLOT(AddStylusTipTransformToLinearObjectRegistration()));

  //TODO:  send acquired points to algorithm [make sure to catch any errors and to replace any phantom landmark registration done prior] (logic)
  if (m_PhantomLinearObjectRegistration->LinearObjectRegister(m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()) != PLUS_SUCCESS)
  {
    LOG_WARNING("Unable to register phantom! Try again");
    ResetLinearObjectRegistration();
  }
  else
  {
    LOG_INFO("Phantom Linear Object Registration successful!");
  }
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::ResetLinearObjectRegistration()
{
  LOG_TRACE("PhantomRegistrationToolbox::ResetLinearObjectRegistration");

  ui.pushButton_StartStop->setEnabled(true);
  ui.tabWidget->setTabEnabled(0, true);

  SetLinearObjectRegistrationState(LinearObjectRegistrationState_Incomplete);

  //clear result points
  m_ParentMainWindow->GetVisualizationController()->ClearResultPolyData();
}


//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::StartLandmarkDetectionRegistration()
{
  LOG_TRACE("PhantomRegistrationToolbox::StartLandmarkPivotingRegistration");

  disconnect(ui.pushButton_StartStop_LandmarkDetection, SIGNAL(clicked()), this, SLOT(StartLandmarkDetectionRegistration()));
  connect(ui.pushButton_StartStop_LandmarkDetection, SIGNAL(clicked()), this, SLOT(StopLandmarkPivotingRegistration()));

  ui.tabWidget->setTabEnabled(1, false);
  ui.pushButton_StartStop_LandmarkDetection->setText(tr("Stop Detection"));

  if (m_State == ToolboxState_Done || m_LandmarkPivotingState != LandmarkPivotingState_InProgress)
  {
    Reset();
    m_CurrentLandmarkIndex = 0;
    m_CurrentPointNumber = 0;

    //// Clear input points Seem to be not needed!
    //vtkSmartPointer<vtkPoints> inputPoints = vtkSmartPointer<vtkPoints>::New();
    //m_ParentMainWindow->GetVisualizationController()->GetInputPolyData()->SetPoints(inputPoints);
    //// Clear input points
    //vtkSmartPointer<vtkPoints> nextInputPoint = vtkSmartPointer<vtkPoints>::New();
    //m_ParentMainWindow->GetVisualizationController()->GetResultPolyData()->SetPoints(nextInputPoint);

    // Initialize stylus tool
    vtkPlusDisplayableObject* object = m_ParentMainWindow->GetVisualizationController()->GetObjectById(m_ParentMainWindow->GetStylusModelId());
    if (object == NULL)
    {
      LOG_ERROR("No stylus tip displayable objects could be found!");
      return;
    }

    // Set state to in progress
    SetLandmarkPivotingState(LandmarkPivotingState_InProgress);
  }
  // Connect acquisition function to timer
  connect(&m_ParentMainWindow->GetVisualizationController()->GetAcquisitionTimer(), SIGNAL(timeout()), this, SLOT(AddStylusTipTransformToLandmarkPivotingRegistration()));
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::StopLandmarkPivotingRegistration()
{
  LOG_TRACE("PhantomRegistrationToolbox::StopLandmarkPivotingRegistration");

  disconnect(ui.pushButton_StartStop_LandmarkDetection, SIGNAL(clicked()), this, SLOT(StopLandmarkPivotingRegistration()));
  connect(ui.pushButton_StartStop_LandmarkDetection, SIGNAL(clicked()), this, SLOT(StartLandmarkDetectionRegistration()));

  ui.pushButton_StartStop_LandmarkDetection->setText(tr("Start Landmark Detection"));

  // Disconnect acquisition function to timer
  disconnect(&m_ParentMainWindow->GetVisualizationController()->GetAcquisitionTimer(), SIGNAL(timeout()), this, SLOT(AddStylusTipTransformToLandmarkPivotingRegistration()));
  if (m_CurrentLandmarkIndex > 2)
  {
    if (m_PhantomLandmarkRegistration->LandmarkRegister(m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()) != PLUS_SUCCESS)
    {
      LOG_WARNING("Unable to register phantom! Try again");
      //Reset();
      SetLandmarkPivotingState(LandmarkPivotingState_Incomplete);
      /*SetState(ToolboxState_Idle);*/
    }
    else
    {
      LOG_INFO("Stopped Phantom landmark Pivoting Registration successful!");
      SetLandmarkPivotingState(LandmarkPivotingState_Complete);
      SetState(ToolboxState_Done);
    }
  }
  else
  {
    LOG_INFO("Less than 3 landmarks! Try again");
    //Reset();
    SetLandmarkPivotingState(LandmarkPivotingState_Incomplete);
    SetState(ToolboxState_Done);
    SetState(ToolboxState_InProgress);
  }
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::AddStylusTipTransformToLandmarkPivotingRegistration()
{
  LOG_TRACE("PhantomRegistrationToolbox::AddStylusTipPositionToLandmarkPivotingRegistration");

  ToolStatus status(TOOL_INVALID);
  vtkSmartPointer<vtkMatrix4x4> stylusTipToReferenceTransformMatrix = vtkSmartPointer<vtkMatrix4x4>::New();
  if (m_ParentMainWindow->GetVisualizationController()->GetTransformMatrix(m_PhantomLandmarkRegistration->GetStylusTipCoordinateFrame(), m_PhantomLandmarkRegistration->GetReferenceCoordinateFrame(), stylusTipToReferenceTransformMatrix, &status) != PLUS_SUCCESS)
  {
    LOG_ERROR("No transform found between stylus tip and reference!");
    return;
  }

  if (status == TOOL_OK && ToolboxState_InProgress == GetState())
  {
    double positionDifferenceLowThresholdMm = 2.0;
    double positionDifferenceHighThresholdMm = 500.0;
    double positionDifferenceMm = -1.0;
    double orientationDifferenceLowThresholdDegrees = 1.0;
    double orientationDifferenceHighThresholdDegrees = 90.0;
    double orientationDifferenceDegrees = -1.0;

    if (m_CurrentPointNumber < 1)
    {
      // Always allow
      positionDifferenceMm = (positionDifferenceLowThresholdMm + positionDifferenceHighThresholdMm) / 2.0;
      orientationDifferenceDegrees = (orientationDifferenceLowThresholdDegrees + orientationDifferenceHighThresholdDegrees) / 2.0;
    }
    else
    {
      // Compute position and orientation difference of current and previous positions
      positionDifferenceMm = PlusMath::GetPositionDifference(stylusTipToReferenceTransformMatrix, m_PreviousStylusTipToReferenceTransformMatrix);
      orientationDifferenceDegrees = PlusMath::GetOrientationDifference(stylusTipToReferenceTransformMatrix, m_PreviousStylusTipToReferenceTransformMatrix);
    }

    if (positionDifferenceMm > positionDifferenceHighThresholdMm || orientationDifferenceDegrees > orientationDifferenceHighThresholdDegrees)
    {
      LOG_DEBUG("Acquired position seems to be an outlier - it is skipped");
      return;
    }

    // Assemble position string for toolbox
    double sylusTip_Reference[4] = {stylusTipToReferenceTransformMatrix->GetElement(0, 3), stylusTipToReferenceTransformMatrix->GetElement(1, 3), stylusTipToReferenceTransformMatrix->GetElement(2, 3), 1};
    std::stringstream ss;
    ss << sylusTip_Reference[0] << " " << sylusTip_Reference[1] << " " << sylusTip_Reference[2];
    m_StylusPositionString = QString(ss.str().c_str());

    m_LandmarkDetected = m_LandmarkDetection->GetNearExistingLandmarkId(sylusTip_Reference);
    if (m_LandmarkDetected >= 0)
    {
      LOG_DEBUG("There is a Landmark detected close to the stylus tip position.");
      return;
    }

    // Set new current point number
    ++m_CurrentPointNumber;
    int newLandmarkDetected = -1;
    m_LandmarkDetection->InsertNextStylusTipToReferenceTransform(stylusTipToReferenceTransformMatrix, newLandmarkDetected);
    if (newLandmarkDetected > 0)
    {
      double landmarkDetected_Reference[4] = {0, 0, 0, 1};
      LOG_DEBUG("\n" << m_LandmarkDetection->GetDetectedLandmarksString() << "\n");
      m_LandmarkDetection->GetDetectedLandmarkPoints_Reference()->GetPoint(m_LandmarkDetection->GetDetectedLandmarkPoints_Reference()->GetNumberOfPoints() - 1, landmarkDetected_Reference);

      // Add recorded point to visualization input if fulfills the criteria
      vtkPoints* detectedLandmarks_Reference = m_ParentMainWindow->GetVisualizationController()->GetResultPolyDataPoints();
      detectedLandmarks_Reference->InsertPoint(m_CurrentLandmarkIndex, landmarkDetected_Reference[0], landmarkDetected_Reference[1], landmarkDetected_Reference[2]);
      detectedLandmarks_Reference->Modified();
      LOG_DEBUG("\nLandmark detected Number " << m_CurrentLandmarkIndex << " found (" << landmarkDetected_Reference[0] << ", " << landmarkDetected_Reference[1] << ", " << landmarkDetected_Reference[2] << ") \nNumber of pivots in phantonReg " << m_PhantomLandmarkRegistration->GetRecordedLandmarks_Reference()->GetNumberOfPoints());
      m_CurrentLandmarkIndex++;

      int numberOfExpectedLandmarks = m_PhantomLandmarkRegistration->GetDefinedLandmarks_Phantom()->GetNumberOfPoints();
      vtkPlusLogger::PrintProgressbar((100.0 * m_LandmarkDetection->GetDetectedLandmarkPoints_Reference()->GetNumberOfPoints() - 1) / numberOfExpectedLandmarks);

      // Add recorded landmark to registration algorithm
      m_PhantomLandmarkRegistration->GetRecordedLandmarks_Reference()->InsertPoint(m_LandmarkDetection->GetDetectedLandmarkPoints_Reference()->GetNumberOfPoints() - 1, landmarkDetected_Reference);
      m_PhantomLandmarkRegistration->GetRecordedLandmarks_Reference()->Modified();

      // If there are at least 3 acquired landmarks then register
      if (m_CurrentLandmarkIndex >= 3)
      {
        if (m_PhantomLandmarkRegistration->LandmarkRegister(m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()) == PLUS_SUCCESS)
        {
          m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomModelId(), true);
          m_ParentMainWindow->GetVisualizationController()->ShowObjectById(m_ParentMainWindow->GetPhantomWiresModelId(), true);
        }
        else
        {
          LOG_ERROR("Phantom landmark registration failed!");
        }

        //stop registration
        if (newLandmarkDetected == numberOfExpectedLandmarks)
        {
          ui.tabWidget->setTabEnabled(1, false);
          if (m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->WriteConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
          {
            LOG_ERROR("Unable to save phantom registration result in configuration XML tree!");
            SetState(ToolboxState_Error);
            return;
          }
          SetState(ToolboxState_Done);

          m_RequestedLandmarkPolyData->GetPoints()->GetData()->RemoveTuple(0);
          m_RequestedLandmarkPolyData->GetPoints()->Modified();

          StopLandmarkPivotingRegistration();
          LOG_INFO("\n" << m_LandmarkDetection->GetDetectedLandmarksString() << "\n");
          m_PhantomLandmarkRegistration->PrintRecordedLandmarks_Phantom();
          return;
        }
        else
        {
          // Set the camera to face the new pivot to be found
          m_ParentMainWindow->GetVisualizationController()->ShowInput(true);
          SetCameraViewAndHighlightNextLandmark(m_ParentMainWindow->GetVisualizationController()->GetCanvasRenderer()->GetActiveCamera(), m_PhantomLandmarkRegistration,
                                                m_CurrentLandmarkIndex, m_ParentMainWindow->GetVisualizationController()->GetInputPolyDataPoints());
        }
      }
      else
      {
        m_ParentMainWindow->GetVisualizationController()->GetCanvasRenderer()->ResetCamera();
      }

      if (m_CurrentLandmarkIndex < numberOfExpectedLandmarks)
      {
        // Highlight next landmark
        m_RequestedLandmarkPolyData->GetPoints()->InsertPoint(0, m_PhantomLandmarkRegistration->GetDefinedLandmarks_Phantom()->GetPoint(m_CurrentLandmarkIndex));
        m_RequestedLandmarkPolyData->GetPoints()->Modified();
      }
    }
    m_PreviousStylusTipToReferenceTransformMatrix->DeepCopy(stylusTipToReferenceTransformMatrix);
  }
}

//-----------------------------------------------------------------------------
void QPhantomRegistrationToolbox::AddStylusTipTransformToLinearObjectRegistration()
{
  LOG_TRACE("PhantomRegistrationToolbox::AddStylusTipPositionToLinearObjectRegistration");

  // Get stylus tip position
  vtkSmartPointer<vtkMatrix4x4> stylusTipToReferenceTransformMatrix = vtkSmartPointer<vtkMatrix4x4>::New();
  ToolStatus status(TOOL_INVALID);
  if (m_ParentMainWindow->GetVisualizationController()->GetTransformMatrix(m_PhantomLinearObjectRegistration->GetStylusTipCoordinateFrame(), m_PhantomLinearObjectRegistration->GetReferenceCoordinateFrame(), stylusTipToReferenceTransformMatrix, &status) != PLUS_SUCCESS)
  {
    LOG_ERROR("No transform found between stylus tip and reference!");
    return;
  }

  if (status == TOOL_OK)
  {
    // Assemble position string for toolbox
    std::stringstream ss;
    ss << stylusTipToReferenceTransformMatrix->GetElement(0, 3) << " " << stylusTipToReferenceTransformMatrix->GetElement(1, 3) << " " << stylusTipToReferenceTransformMatrix->GetElement(2, 3);
    m_StylusPositionString = QString(ss.str().c_str());

    // Add point to the input if fulfills the criteria
    vtkPoints* points = m_ParentMainWindow->GetVisualizationController()->GetResultPolyDataPoints();

    double positionDifferenceLowThresholdMm = 2.0;
    double positionDifferenceHighThresholdMm = 500.0;
    double positionDifferenceMm = -1.0;
    double orientationDifferenceLowThresholdDegrees = 2.0;
    double orientationDifferenceHighThresholdDegrees = 90.0;
    double orientationDifferenceDegrees = -1.0;

    //TODO: make sure that when you switch planes you are recording, all the new points are not treated as outliers
    if (m_CurrentPointNumber < 1)
    {
      // Always allow
      positionDifferenceMm = (positionDifferenceLowThresholdMm + positionDifferenceHighThresholdMm) / 2.0;
      orientationDifferenceDegrees = (orientationDifferenceLowThresholdDegrees + orientationDifferenceHighThresholdDegrees) / 2.0;
    }
    else
    {
      // Compute position and orientation difference of current and previous positions
      positionDifferenceMm = PlusMath::GetPositionDifference(stylusTipToReferenceTransformMatrix, m_PreviousStylusTipToReferenceTransformMatrix);
      orientationDifferenceDegrees = PlusMath::GetOrientationDifference(stylusTipToReferenceTransformMatrix, m_PreviousStylusTipToReferenceTransformMatrix);
    }

    // If current point is close to the previous one, or too far (outlier), we do not insert it
    if (positionDifferenceMm < orientationDifferenceLowThresholdDegrees && orientationDifferenceDegrees < orientationDifferenceLowThresholdDegrees)
    {
      LOG_DEBUG("Acquired position is too close to the previous - it is skipped");
    }
    else if (positionDifferenceMm > positionDifferenceHighThresholdMm || orientationDifferenceDegrees > orientationDifferenceHighThresholdDegrees)
    {
      LOG_DEBUG("Acquired position seems to be an outlier - it is skipped");
    }
    else
    {
      // Add the point into the registration dataset
      m_PhantomLinearObjectRegistration->InsertNextCalibrationPoint(stylusTipToReferenceTransformMatrix);

      // Add to polydata for rendering
      points->InsertPoint(m_CurrentPointNumber, stylusTipToReferenceTransformMatrix->GetElement(0, 3), stylusTipToReferenceTransformMatrix->GetElement(1, 3), stylusTipToReferenceTransformMatrix->GetElement(2, 3));
      points->Modified();

      // Set new current point number
      ++m_CurrentPointNumber;

      // Reset the camera once in a while
      if ((m_CurrentPointNumber > 0) && ((m_CurrentPointNumber % 10 == 0) || (m_CurrentPointNumber == 5)))
      {
        m_ParentMainWindow->GetVisualizationController()->GetCanvasRenderer()->ResetCamera();
      }

      //TODO: if there are more than 3 planes recorded, try to add a visualization of the phantom to the GUI
      m_PreviousStylusTipToReferenceTransformMatrix->DeepCopy(stylusTipToReferenceTransformMatrix);
    }
  }
}

//-----------------------------------------------------------------------------

void QPhantomRegistrationToolbox::SetLinearObjectRegistrationState(LinearObjectRegistrationState state)
{
  m_LinearObjectRegistrationState = state;
}

//-----------------------------------------------------------------------------

LinearObjectRegistrationState QPhantomRegistrationToolbox::GetLinearObjectRegistrationState()
{
  return m_LinearObjectRegistrationState;
}
//-----------------------------------------------------------------------------

void QPhantomRegistrationToolbox::SetLandmarkPivotingState(LandmarkPivotingState state)
{
  m_LandmarkPivotingState = state;
  SetDisplayAccordingToState();
}

//-----------------------------------------------------------------------------

LandmarkPivotingState QPhantomRegistrationToolbox::GetLandmarkPivotingState()
{
  return m_LandmarkPivotingState;
}


//-----------------------------------------------------------------------------

vtkPlusPhantomLandmarkRegistrationAlgo* QPhantomRegistrationToolbox::GetPhantomLandmarkRegistrationAlgo()
{
  return m_PhantomLandmarkRegistration;
}

//-----------------------------------------------------------------------------

vtkPlusPhantomLinearObjectRegistrationAlgo* QPhantomRegistrationToolbox::GetPhantomLinearObjectRegistrationAlgo()
{
  return m_PhantomLinearObjectRegistration;
}
