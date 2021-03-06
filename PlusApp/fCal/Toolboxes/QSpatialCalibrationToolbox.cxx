/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

// Local includes
#include "QSpatialCalibrationToolbox.h"
#include "fCalMainWindow.h"
#include "vtkPlusDisplayableObject.h"
#include "vtkPlusVisualizationController.h"
#include "QPlusSegmentationParameterDialog.h"

// PlusLib includes
#include <PlusConfigure.h>
#include <PlusFidPatternRecognition.h>
#include <PlusTrackedFrame.h>
#include <vtkPlusDevice.h>
#include <vtkPlusProbeCalibrationAlgo.h>
#include <vtkPlusTrackedFrameList.h>

// VTK includes
#include <vtkPoints.h>
#include <vtkTransform.h>
#include <vtkXMLUtilities.h>

// Qt includes
#include <QFileDialog>
#include <QTimer>

//-----------------------------------------------------------------------------
QSpatialCalibrationToolbox::QSpatialCalibrationToolbox(fCalMainWindow* aParentMainWindow, Qt::WindowFlags aFlags)
  : QAbstractToolbox(aParentMainWindow)
  , QWidget(aParentMainWindow, aFlags)
  , m_Calibration(vtkSmartPointer<vtkPlusProbeCalibrationAlgo>::New())
  , m_PatternRecognition(new PlusFidPatternRecognition())
  , m_SpatialCalibrationData(vtkSmartPointer<vtkPlusTrackedFrameList>::New())
  , m_SpatialValidationData(vtkSmartPointer<vtkPlusTrackedFrameList>::New())
  , m_CancelRequest(false)
  , m_LastRecordedFrameTimestamp(UNDEFINED_TIMESTAMP)
  , m_FreeHandStartupDelaySec(5)
  , m_StartupDelayRemainingTimeSec(0)
  , m_StartupDelayTimer(NULL)
  , m_NumberOfCalibrationImagesToAcquire(200)
  , m_NumberOfValidationImagesToAcquire(100)
  , m_NumberOfSegmentedCalibrationImages(0)
  , m_NumberOfSegmentedValidationImages(0)
  , m_RecordingIntervalMs(200)
  , m_MaxTimeSpentWithProcessingMs(150)
  , m_LastProcessingTimePerFrameMs(-1)
{
  ui.setupUi(this);

  m_SpatialCalibrationData->SetValidationRequirements(REQUIRE_UNIQUE_TIMESTAMP | REQUIRE_TRACKING_OK);
  m_SpatialValidationData->SetValidationRequirements(REQUIRE_UNIQUE_TIMESTAMP | REQUIRE_TRACKING_OK);

  // Change result display properties
  ui.label_Results->setFont(QFont("Courier", 8));

  // Set up timer to wait before acquisition
  m_StartupDelayTimer = new QTimer(this);

  // Connect events
  connect(ui.pushButton_OpenPhantomRegistration, SIGNAL(clicked()), this, SLOT(OpenPhantomRegistration()));
  connect(ui.pushButton_OpenSegmentationParameters, SIGNAL(clicked()), this, SLOT(OpenSegmentationParameters()));
  connect(ui.pushButton_EditSegmentationParameters, SIGNAL(clicked()), this, SLOT(EditSegmentationParameters()));
  connect(ui.pushButton_StartCancelSpatial, SIGNAL(clicked()), this, SLOT(StartDelayTimer()));
  connect(m_StartupDelayTimer, SIGNAL(timeout()), this, SLOT(DelayStartup()));
}

//-----------------------------------------------------------------------------
QSpatialCalibrationToolbox::~QSpatialCalibrationToolbox()
{
  if (m_PatternRecognition != NULL)
  {
    delete m_PatternRecognition;
    m_PatternRecognition = NULL;
  }

  if (m_StartupDelayTimer != NULL)
  {
    if (m_StartupDelayTimer->isActive())
    {
      m_StartupDelayTimer->stop();
    }
    delete m_StartupDelayTimer;
    m_StartupDelayTimer = NULL;
  }
}

//-----------------------------------------------------------------------------
void QSpatialCalibrationToolbox::OnActivated()
{
  LOG_TRACE("SpatialCalibrationToolbox::OnActivated");

  // Read and refresh spatial calibration configuration
  if (m_Calibration->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
  {
    LOG_ERROR("Reading probe calibration algorithm configuration failed");
    return;
  }

  if (ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
  {
    LOG_ERROR("Reading spatial calibration configuration failed");
    return;
  }

  if (m_State == ToolboxState_Done)
  {
    SetDisplayAccordingToState();
    return;
  }

  // Clear results polydata
  m_ParentMainWindow->GetVisualizationController()->ClearResultPolyData();

  if ((m_ParentMainWindow->GetVisualizationController()->GetDataCollector() != NULL)
      && (m_ParentMainWindow->GetVisualizationController()->GetDataCollector()->GetConnected()))
  {
    // Set initialized if it was uninitialized
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
PlusStatus QSpatialCalibrationToolbox::ReadConfiguration(vtkXMLDataElement* aConfig)
{
  LOG_TRACE("SpatialCalibrationToolbox::ReadConfiguration");

  if (aConfig == NULL)
  {
    LOG_ERROR("Unable to read configuration");
    return PLUS_FAIL;
  }

  vtkXMLDataElement* fCalElement = aConfig->FindNestedElementWithName("fCal");

  if (fCalElement == NULL)
  {
    LOG_ERROR("Unable to find fCal element in XML tree");
    return PLUS_FAIL;
  }

  // Read number of needed images
  int numberOfCalibrationImagesToAcquire = 0;
  if (fCalElement->GetScalarAttribute("NumberOfCalibrationImagesToAcquire", numberOfCalibrationImagesToAcquire))
  {
    m_NumberOfCalibrationImagesToAcquire = numberOfCalibrationImagesToAcquire;
  }
  else
  {
    LOG_WARNING("Unable to read NumberOfCalibrationImagesToAcquire attribute from fCal element of the device set configuration, default value '" << m_NumberOfCalibrationImagesToAcquire << "' will be used");
  }

  int numberOfValidationImagesToAcquire = 0;
  if (fCalElement->GetScalarAttribute("NumberOfValidationImagesToAcquire", numberOfValidationImagesToAcquire))
  {
    m_NumberOfValidationImagesToAcquire = numberOfValidationImagesToAcquire;
  }
  else
  {
    LOG_WARNING("Unable to read NumberOfValidationImagesToAcquire attribute from fCal element of the device set configuration, default value '" << m_NumberOfValidationImagesToAcquire << "' will be used");
  }

  // Recording interval and processing time
  int recordingIntervalMs = 0;
  if (fCalElement->GetScalarAttribute("RecordingIntervalMs", recordingIntervalMs))
  {
    m_RecordingIntervalMs = recordingIntervalMs;
  }
  else
  {
    LOG_WARNING("Unable to read RecordingIntervalMs attribute from fCal element of the device set configuration, default value '" << m_RecordingIntervalMs << "' will be used");
  }

  int maxTimeSpentWithProcessingMs = 0;
  if (fCalElement->GetScalarAttribute("MaxTimeSpentWithProcessingMs", maxTimeSpentWithProcessingMs))
  {
    m_MaxTimeSpentWithProcessingMs = maxTimeSpentWithProcessingMs;
  }
  else
  {
    LOG_WARNING("Unable to read MaxTimeSpentWithProcessingMs attribute from fCal element of the device set configuration, default value '" << m_MaxTimeSpentWithProcessingMs << "' will be used");
  }

  XML_READ_SCALAR_ATTRIBUTE_OPTIONAL(int, FreeHandStartupDelaySec, fCalElement);

  return m_PatternRecognition->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData());
}

//-----------------------------------------------------------------------------
void QSpatialCalibrationToolbox::RefreshContent()
{
}

//-----------------------------------------------------------------------------
void QSpatialCalibrationToolbox::SetDisplayAccordingToState()
{
  LOG_TRACE("SpatialCalibrationToolbox::SetDisplayAccordingToState");

  // If connected
  if ((m_ParentMainWindow->GetVisualizationController()->GetDataCollector() != NULL)
      && (m_ParentMainWindow->GetVisualizationController()->GetDataCollector()->GetConnected()))
  {
    // If the force show devices isn't enabled, set it to 2D
    if (!m_ParentMainWindow->IsForceShowDevicesEnabled())
    {
      // 2D mode auto-turns back on the image
      if (m_ParentMainWindow->GetVisualizationController()->SetVisualizationMode(vtkPlusVisualizationController::DISPLAY_MODE_2D) != PLUS_SUCCESS)
      {
        LOG_WARNING("Unable to switch to 2D visualization. Unable to use freehand calibration toolbox.");
        m_ParentMainWindow->GetVisualizationController()->HideRenderer();
        this->m_State = ToolboxState_Error;
      }
      else
      {
        // Enable or disable the image manipulation menu
        m_ParentMainWindow->SetImageManipulationMenuEnabled(m_ParentMainWindow->GetVisualizationController()->Is2DMode());

        // Hide or show the orientation markers based on the value of the checkbox
        m_ParentMainWindow->GetVisualizationController()->ShowOrientationMarkers(m_ParentMainWindow->IsOrientationMarkersEnabled());
      }
    }

    // Update state message according to available transforms
    if (m_Calibration->GetImageCoordinateFrame() && m_Calibration->GetProbeCoordinateFrame())
    {
      if (m_ParentMainWindow->GetVisualizationController()->IsExistingTransform(m_Calibration->GetProbeCoordinateFrame(), m_Calibration->GetReferenceCoordinateFrame()) == PLUS_SUCCESS)
      {
        std::string imageToProbeTransformNameStr;
        PlusTransformName imageToProbeTransformName(
          m_Calibration->GetImageCoordinateFrame(), m_Calibration->GetProbeCoordinateFrame());
        imageToProbeTransformName.GetTransformName(imageToProbeTransformNameStr);

        if (m_ParentMainWindow->GetVisualizationController()->IsExistingTransform(
              m_Calibration->GetImageCoordinateFrame(), m_Calibration->GetProbeCoordinateFrame(), false) == PLUS_SUCCESS)
        {
          std::string date, errorStr;
          double error;
          if (m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->GetTransformDate(imageToProbeTransformName, date) != PLUS_SUCCESS)
          {
            date = "N/A";
          }
          if (m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->GetTransformError(imageToProbeTransformName, error) == PLUS_SUCCESS)
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
          ui.label_State->setText(QString("%1 transform present.\nDate: %2, Error: %3").arg(imageToProbeTransformNameStr.c_str()).arg(date.c_str()).arg(errorStr.c_str()));
        }
        else
        {
          QPalette palette;
          palette.setColor(ui.label_State->foregroundRole(), QColor::fromRgb(255, 128, 0));
          ui.label_State->setPalette(palette);
          ui.label_State->setText(QString("%1 transform is absent, spatial calibration needs to be performed.").arg(imageToProbeTransformNameStr.c_str()));
          LOG_INFO(imageToProbeTransformNameStr << " transform is absent, spatial calibration needs to be performed");
        }
      }
      else
      {
        QPalette palette;
        palette.setColor(ui.label_State->foregroundRole(), QColor::fromRgb(255, 128, 0));
        ui.label_State->setPalette(palette);
        ui.label_State->setText(tr("Phantom registration is not available. If phantom registration has been already performed successfully"
                                   " then verify the coordinate frames in the device set configuration file (see the log for details)."));
        LOG_INFO("Phantom registration is not available: transform between " << m_Calibration->GetProbeCoordinateFrame()
                 << " and " << m_Calibration->GetReferenceCoordinateFrame() << " coordinate frames is missing. Either phantom registration has not performed yet"
                 " or the ProbeCoordinateFrame, ReferenceCoordinateFrame, or PhantomCoordinateFrame attributes in the device set configuration file are not set correctly.");
        m_State = ToolboxState_Error;
      }
    }
    else
    {
      QPalette palette;
      palette.setColor(ui.label_State->foregroundRole(), QColor::fromRgb(255, 128, 0));
      ui.label_State->setPalette(palette);
      ui.label_State->setText(QString("Probe calibration configuration is missing"));
      LOG_INFO("Probe calibration configuration is missing");
      m_State = ToolboxState_Error;
    }
  }
  else
  {
    QPalette palette;
    palette.setColor(ui.label_State->foregroundRole(), QColor::fromRgb(255, 128, 0));
    ui.label_State->setPalette(palette);
    ui.label_State->setText(tr("fCal is not connected to devices. Switch to Configuration toolbox to connect."));
    LOG_INFO("fCal is not connected to devices");
  }

  // Set widget states according to state
  if (m_State == ToolboxState_Uninitialized)
  {
    ui.pushButton_OpenPhantomRegistration->setEnabled(false);
    ui.pushButton_OpenSegmentationParameters->setEnabled(false);
    ui.pushButton_EditSegmentationParameters->setEnabled(false);

    ui.label_Warning->setVisible(false);
    ui.label_Results->setText(QString(""));

    ui.label_InstructionsSpatial->setText(QString(""));
    ui.pushButton_StartCancelSpatial->setEnabled(false);

    m_ParentMainWindow->SetStatusBarText(QString(""));
    m_ParentMainWindow->SetStatusBarProgress(-1);
  }
  else if (m_State == ToolboxState_Idle)
  {
    bool isReadyToStartSpatialCalibration = false;
    if ((m_ParentMainWindow->GetVisualizationController()->GetDataCollector() != NULL)
        && (m_ParentMainWindow->GetVisualizationController()->GetDataCollector()->GetConnected()))
    {
      isReadyToStartSpatialCalibration = IsReadyToStartSpatialCalibration();
    }

    ui.pushButton_OpenPhantomRegistration->setEnabled(true);
    ui.pushButton_OpenSegmentationParameters->setEnabled(true);
    ui.pushButton_EditSegmentationParameters->setEnabled(true);

    ui.label_Warning->setVisible(false);
    ui.label_Results->setText(QString(""));

    ui.label_InstructionsSpatial->setText(QString(""));
    ui.pushButton_StartCancelSpatial->setEnabled(isReadyToStartSpatialCalibration);
    ui.pushButton_StartCancelSpatial->setFocus();

    m_ParentMainWindow->SetStatusBarText(QString(""));
    m_ParentMainWindow->SetStatusBarProgress(-1);

    QApplication::restoreOverrideCursor();
  }
  else if (m_State == ToolboxState_StartupDelay)
  {
    ui.pushButton_StartCancelSpatial->setEnabled(true);
    ui.pushButton_StartCancelSpatial->setText("Cancel");

    m_ParentMainWindow->SetStatusBarText(QString("Get ready for spatial calibration"));
    m_ParentMainWindow->SetStatusBarProgress(-1);
  }
  else if (m_State == ToolboxState_InProgress)
  {
    ui.pushButton_OpenPhantomRegistration->setEnabled(false);
    ui.pushButton_OpenSegmentationParameters->setEnabled(false);
    ui.pushButton_EditSegmentationParameters->setEnabled(false);

    ui.label_Warning->setVisible(false);
    QPalette palette;
    palette.setColor(ui.label_State->foregroundRole(), Qt::black);
    ui.label_State->setPalette(palette);
    ui.label_State->setText(tr("Spatial calibration is in progress..."));
    ui.label_Results->setText(QString(""));

    m_ParentMainWindow->SetStatusBarText(QString(" Acquiring and adding images to calibrator"));
    m_ParentMainWindow->SetStatusBarProgress(0);

    ui.label_InstructionsSpatial->setText(tr("Scan the phantom until the progress bar is filled. Keep the image plane approximately orthogonal to the wires and translate in all directions.\nIf the segmentation does not work (green dots on wires do not appear) then cancel and edit segmentation parameters"));
    ui.pushButton_StartCancelSpatial->setEnabled(true);
  }
  else if (m_State == ToolboxState_Done)
  {
    ui.pushButton_OpenPhantomRegistration->setEnabled(true);
    ui.pushButton_OpenSegmentationParameters->setEnabled(true);
    ui.pushButton_EditSegmentationParameters->setEnabled(true);

    ui.label_InstructionsSpatial->setText(tr("Spatial calibration is ready to save"));

    if (m_Calibration->GetCalibrationReprojectionError3DMean() >= 2.0)
    {
      QPalette palette;
      palette.setColor(ui.label_Warning->foregroundRole(), QColor::fromRgb(233, 0, 0));
      ui.label_Warning->setPalette(palette);
      ui.label_Warning->setVisible(true);
      ui.label_Warning->setText(tr("Calibration error is too high!\n  Please re-calibrate"));
    }
    else if (m_Calibration->GetCalibrationReprojectionError3DMean() >= 1.0)
    {
      QPalette palette;
      palette.setColor(ui.label_Warning->foregroundRole(), QColor::fromRgb(255, 128, 0));
      ui.label_Warning->setPalette(palette);
      ui.label_Warning->setVisible(true);
      ui.label_Warning->setText(tr("Calibration error is relatively high!\n  Consider re-calibrating"));
    }
    else
    {
      ui.label_Warning->setVisible(false);
    }
    ui.label_Results->setText(m_Calibration->GetResultString().c_str());

    ui.pushButton_StartCancelSpatial->setEnabled(true);

    m_ParentMainWindow->SetStatusBarText(QString(" Calibration done"));
    m_ParentMainWindow->SetStatusBarProgress(-1);

    QApplication::restoreOverrideCursor();
  }
  else if (m_State == ToolboxState_Error)
  {
    ui.pushButton_OpenPhantomRegistration->setEnabled(false);
    ui.pushButton_OpenSegmentationParameters->setEnabled(false);

    ui.label_Warning->setVisible(false);
    ui.label_Results->setText(QString(""));

    ui.label_InstructionsSpatial->setText(QString(""));
    ui.pushButton_StartCancelSpatial->setEnabled(false);

    m_ParentMainWindow->SetStatusBarText(QString(""));
    m_ParentMainWindow->SetStatusBarProgress(-1);

    QApplication::restoreOverrideCursor();
  }
}

//-----------------------------------------------------------------------------
void QSpatialCalibrationToolbox::OpenPhantomRegistration()
{
  LOG_TRACE("SpatialCalibrationToolbox::OpenPhantomRegistrationClicked");

  // File open dialog for selecting phantom registration xml
  QString filter = QString(tr("XML files ( *.xml );;"));
  QString fileName = QFileDialog::getOpenFileName(NULL, QString(tr("Open phantom registration XML")),
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

  // Read phantom registration transform
  PlusTransformName phantomToReferenceTransformName(m_Calibration->GetPhantomCoordinateFrame(), m_Calibration->GetReferenceCoordinateFrame());
  vtkSmartPointer<vtkMatrix4x4> phantomToReferenceTransformMatrix = vtkSmartPointer<vtkMatrix4x4>::New();
  std::string transformDate;
  double transformError = 0.0;
  ToolStatus status(TOOL_INVALID);
  vtkPlusTransformRepository* tempTransformRepo = vtkPlusTransformRepository::New();
  if (tempTransformRepo->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS
      || tempTransformRepo->GetTransform(phantomToReferenceTransformName, phantomToReferenceTransformMatrix, &status) != PLUS_SUCCESS
      || tempTransformRepo->GetTransformDate(phantomToReferenceTransformName, transformDate) != PLUS_SUCCESS
      || tempTransformRepo->GetTransformError(phantomToReferenceTransformName, transformError) != PLUS_SUCCESS)
  {
    LOG_ERROR("Failed to read transform from opened file");
    tempTransformRepo->Delete();
    return;
  }

  tempTransformRepo->Delete();

  if (status == TOOL_OK)
  {
    if (m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->SetTransform(phantomToReferenceTransformName, phantomToReferenceTransformMatrix) != PLUS_SUCCESS)
    {
      LOG_ERROR("Failed to set phantom registration transform to transform repository");
      return;
    }

    m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->SetTransformDate(phantomToReferenceTransformName, transformDate.c_str());
    m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->SetTransformError(phantomToReferenceTransformName, transformError);
    m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->SetTransformPersistent(phantomToReferenceTransformName, true);
  }
  else
  {
    LOG_ERROR("Invalid phantom registration transform found, it was not set");
  }

  SetDisplayAccordingToState();

  LOG_INFO("Phantom registration imported in freehand calibration toolbox from file '" << fileName.toLatin1().constData() << "'");
}

//-----------------------------------------------------------------------------
void QSpatialCalibrationToolbox::OpenSegmentationParameters()
{
  LOG_TRACE("SpatialCalibrationToolbox::OpenSegmentationParameters");

  // File open dialog for selecting calibration configuration xml
  QString filter = QString(tr("XML files ( *.xml );;"));
  QString fileName = QFileDialog::getOpenFileName(NULL, QString(tr("Open calibration configuration XML")),
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

  // Load calibration configuration xml
  if (m_PatternRecognition->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
  {
    LOG_ERROR("Unable to import segmentation parameters");
    return;
  }

  // Replace USCalibration element with the one in the just read file
  vtkPlusConfig::GetInstance()->ReplaceElementInDeviceSetConfiguration("Segmentation", rootElement);

  SetDisplayAccordingToState();

  LOG_INFO("Segmentation parameters imported in freehand calibration toolbox from file '" << fileName.toLatin1().constData() << "'");
}

//-----------------------------------------------------------------------------
void QSpatialCalibrationToolbox::EditSegmentationParameters()
{
  LOG_INFO("Edit segmentation parameters started");

  // Disconnect realtime image from main canvas
  m_ParentMainWindow->GetVisualizationController()->SetVisualizationMode(vtkPlusVisualizationController::DISPLAY_MODE_NONE);
  if (m_ParentMainWindow->GetVisualizationController()->DisconnectInput() != PLUS_SUCCESS)
  {
    LOG_ERROR("Unable to disconnect input. Cannot show input in QPlusSegmentationParameterDialog.");
    return;
  }

  // Show segmentation parameter dialog
  QPlusSegmentationParameterDialog* segmentationParamDialog = new QPlusSegmentationParameterDialog(this, m_ParentMainWindow->GetVisualizationController()->GetDataCollector(), m_ParentMainWindow->GetSelectedChannel());
  segmentationParamDialog->exec();
  delete segmentationParamDialog;

  // Re-connect realtime image to canvas
  if (m_ParentMainWindow->GetVisualizationController()->ConnectInput() != PLUS_SUCCESS)
  {
    LOG_WARNING("Unable to reconnect input. Image will no longer show in main window.");
  }
  this->SetDisplayAccordingToState();

  // Update ROI
  m_ParentMainWindow->GetVisualizationController()->ReadRoiConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData());

  // Update segmentation parameters
  if (m_PatternRecognition->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
  {
    LOG_ERROR("Unable to update segmentation parameters");
    return;
  }

  LOG_INFO("Edit segmentation parameters ended");
}

//-----------------------------------------------------------------------------
void QSpatialCalibrationToolbox::StartDelayTimer()
{
  LOG_INFO("Delay start up " << m_StartupDelayRemainingTimeSec);

  disconnect(ui.pushButton_StartCancelSpatial, SIGNAL(clicked()), this, SLOT(StartDelayTimer()));
  connect(ui.pushButton_StartCancelSpatial, SIGNAL(clicked()), this, SLOT(CancelCalibration()));
  ui.pushButton_StartCancelSpatial->setText(tr("Cancel"));

  if (m_State != ToolboxState_InProgress)
  {
    LOG_INFO("set current Delay start up" << m_FreeHandStartupDelaySec);
    m_StartupDelayRemainingTimeSec = m_FreeHandStartupDelaySec;
    ui.label_InstructionsSpatial->setText(QString("Spatial calibration will start in %1").arg(m_StartupDelayRemainingTimeSec--));
    SetState(ToolboxState_StartupDelay);
    // Start timer every 1000 ms
    m_StartupDelayTimer->start(1000);
  }
}

//-----------------------------------------------------------------------------
void  QSpatialCalibrationToolbox::DelayStartup()
{
  if (m_StartupDelayRemainingTimeSec > 0)
  {
    ui.label_InstructionsSpatial->setText(QString("Spatial calibration will start in %1").arg(m_StartupDelayRemainingTimeSec--));
  }
  else
  {
    if (m_StartupDelayTimer->isActive())
    {
      m_StartupDelayTimer->stop();
    }
    StartCalibration();
  }
}

//-----------------------------------------------------------------------------
void QSpatialCalibrationToolbox::StartCalibration()
{
  LOG_INFO("Spatial calibration started");

  m_ParentMainWindow->SetToolboxesEnabled(false);

  QApplication::setOverrideCursor(QCursor(Qt::BusyCursor));

  // Set validation transform names for tracked frame lists
  std::string toolReferenceFrame = m_Calibration->GetReferenceCoordinateFrame();
  PlusTransformName transformNameForValidation(m_ParentMainWindow->GetProbeCoordinateFrame(), toolReferenceFrame.c_str());
  m_SpatialCalibrationData->SetFrameTransformNameForValidation(transformNameForValidation);
  m_SpatialValidationData->SetFrameTransformNameForValidation(transformNameForValidation);

  // Initialize algorithms and containers
  if ((this->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
      || (m_PatternRecognition->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS))
  {
    LOG_ERROR("Reading configuration failed");
    return;
  }

  m_SpatialCalibrationData->Clear();
  m_SpatialValidationData->Clear();

  m_NumberOfSegmentedCalibrationImages = 0;
  m_NumberOfSegmentedValidationImages = 0;
  m_LastRecordedFrameTimestamp = UNDEFINED_TIMESTAMP;

  m_CancelRequest = false;

  SetState(ToolboxState_InProgress);

  // Start calibration and compute results on success
  DoCalibration();
}

//-----------------------------------------------------------------------------
void QSpatialCalibrationToolbox::DoCalibration()
{
  LOG_TRACE("SpatialCalibrationToolbox::DoSpatialCalibration");

  // Enable wire label visualization
  m_ParentMainWindow->GetVisualizationController()->EnableWireLabels(true);

  // Get current time
  double startTimeSec = vtkPlusAccurateTimer::GetSystemTime();

  // Calibrate if acquisition is ready
  if (m_NumberOfSegmentedCalibrationImages >= m_NumberOfCalibrationImagesToAcquire
      && m_NumberOfSegmentedValidationImages >= m_NumberOfValidationImagesToAcquire)
  {
    LOG_INFO("Segmentation success rate: " << m_NumberOfSegmentedCalibrationImages + m_NumberOfSegmentedValidationImages << " out of " << m_SpatialCalibrationData->GetNumberOfTrackedFrames() + m_SpatialValidationData->GetNumberOfTrackedFrames() << " (" << (int)(((double)(m_NumberOfSegmentedCalibrationImages + m_NumberOfSegmentedValidationImages) / (double)(m_SpatialCalibrationData->GetNumberOfTrackedFrames() + m_SpatialValidationData->GetNumberOfTrackedFrames())) * 100.0 + 0.49) << " percent)");

    if (m_Calibration->Calibrate(m_SpatialValidationData, m_SpatialCalibrationData, m_ParentMainWindow->GetVisualizationController()->GetTransformRepository(), m_PatternRecognition->GetFidLineFinder()->GetNWires()) != PLUS_SUCCESS)
    {
      LOG_ERROR("Calibration failed");
      CancelCalibration();
      ui.label_Results->setText("Calibration failed.");
      return;
    }

    if (SetAndSaveResults() != PLUS_SUCCESS)
    {
      LOG_ERROR("Setting and saving results failed");
      CancelCalibration();
      return;
    }

    m_SpatialCalibrationData->Clear();
    m_SpatialValidationData->Clear();

    SetState(ToolboxState_Done);

    disconnect(ui.pushButton_StartCancelSpatial, SIGNAL(clicked()), this, SLOT(CancelCalibration()));
    connect(ui.pushButton_StartCancelSpatial, SIGNAL(clicked()), this, SLOT(StartDelayTimer()));
    ui.pushButton_StartCancelSpatial->setText(tr("Start"));

    m_ParentMainWindow->SetToolboxesEnabled(true);
    m_ParentMainWindow->GetVisualizationController()->EnableWireLabels(false);
    m_ParentMainWindow->GetVisualizationController()->ShowResult(false);

    return;
  }

  // Cancel if requested
  if (m_CancelRequest)
  {
    LOG_INFO("Calibration process cancelled by the user");
    CancelCalibration();
    return;
  }

  // Determine which data container to use
  vtkPlusTrackedFrameList* trackedFrameListToUse = NULL;
  if (m_NumberOfSegmentedValidationImages < m_NumberOfValidationImagesToAcquire)
  {
    trackedFrameListToUse = m_SpatialValidationData;
  }
  else
  {
    trackedFrameListToUse = m_SpatialCalibrationData;
  }

  unsigned int numberOfFramesBeforeRecording = trackedFrameListToUse->GetNumberOfTrackedFrames();

  // Acquire tracked frames since last acquisition (minimum 1 frame)
  if (m_LastProcessingTimePerFrameMs < 1)
  {
    // if processing was less than 1ms/frame then assume it was 1ms (1000FPS processing speed) to avoid division by zero
    m_LastProcessingTimePerFrameMs = 1;
  }
  int numberOfFramesToGet = std::max(m_MaxTimeSpentWithProcessingMs / m_LastProcessingTimePerFrameMs, 1);

  if (m_ParentMainWindow->GetSelectedChannel() != NULL &&
      m_ParentMainWindow->GetSelectedChannel()->GetTrackedFrameList(m_LastRecordedFrameTimestamp, trackedFrameListToUse, numberOfFramesToGet) != PLUS_SUCCESS)
  {
    LOG_ERROR("Failed to get tracked frame list from data collector (last recorded timestamp: " << std::fixed << m_LastRecordedFrameTimestamp);
    QTimer::singleShot(50, this, SLOT(DoCalibration()));
    return;
  }

  // Remove tracked frames without valid transforms
  PlusTransformName probeToPhantomTransformName = PlusTransformName(m_Calibration->GetProbeCoordinateFrame(), m_Calibration->GetPhantomCoordinateFrame());
  vtkPlusTransformRepository* transformRepository = m_ParentMainWindow->GetVisualizationController()->GetTransformRepository();
  bool probeToPhantomTransformValid = false;
  for (unsigned int frameIndex = numberOfFramesBeforeRecording; frameIndex < trackedFrameListToUse->GetNumberOfTrackedFrames(); frameIndex++)
  {
    PlusTrackedFrame* trackedFrame = trackedFrameListToUse->GetTrackedFrame(frameIndex);
    transformRepository->SetTransforms(*trackedFrame);
    transformRepository->GetTransformValid(probeToPhantomTransformName, probeToPhantomTransformValid);
    if (!probeToPhantomTransformValid)
    {
      trackedFrameListToUse->RemoveTrackedFrame(frameIndex);
      frameIndex--; // we've deleted the current frame, so continue with the same frameIndex
    }
  }

  if (probeToPhantomTransformValid)
  {
    ui.label_Warning->setVisible(false);
  }
  else
  {
    QPalette palette;
    palette.setColor(ui.label_Warning->foregroundRole(), QColor::fromRgb(255, 128, 0));
    ui.label_Warning->setPalette(palette);
    ui.label_Warning->setText(QString("Cannot determine transform between probe and phantom (%1 transform is invalid).\nMake sure all markers are in the field of view.").arg(probeToPhantomTransformName.GetTransformName().c_str()));
    ui.label_Warning->setVisible(true);
  }

  // Segment last recorded images
  int numberOfNewlySegmentedImages = 0;
  if (numberOfFramesBeforeRecording < trackedFrameListToUse->GetNumberOfTrackedFrames())
  {
    PlusFidPatternRecognition::PatternRecognitionError error;
    if (m_PatternRecognition->RecognizePattern(trackedFrameListToUse, error, &numberOfNewlySegmentedImages) != PLUS_SUCCESS)
    {
      LOG_ERROR("Failed to segment tracked frame list");
      QTimer::singleShot(50, this, SLOT(DoCalibration()));
      return;
    }
    if (error == PlusFidPatternRecognition::PATTERN_RECOGNITION_ERROR_TOO_MANY_CANDIDATES)
    {
      LOG_WARNING("Too many candidates in frame. Some candidates have been truncated to prevent freezing of the application.");
    }

    if (m_NumberOfSegmentedValidationImages < m_NumberOfValidationImagesToAcquire)
    {
      m_NumberOfSegmentedValidationImages += numberOfNewlySegmentedImages;
    }
    else
    {
      m_NumberOfSegmentedCalibrationImages += numberOfNewlySegmentedImages;
    }
  }

  LOG_DEBUG("Number of segmented images in this round: " << numberOfNewlySegmentedImages << " out of " << trackedFrameListToUse->GetNumberOfTrackedFrames() - numberOfFramesBeforeRecording);

  // Update progress if tracked frame has been successfully added
  int progressPercent = (int)(((m_NumberOfSegmentedCalibrationImages + m_NumberOfSegmentedValidationImages) / (double)(std::max(m_NumberOfValidationImagesToAcquire, m_NumberOfSegmentedValidationImages) + m_NumberOfCalibrationImagesToAcquire)) * 100.0);
  m_ParentMainWindow->SetStatusBarProgress(progressPercent);

  // Display segmented points (or hide them if unsuccessful)
  DisplaySegmentedPoints(probeToPhantomTransformValid);

  // Compute time spent with processing one frame in this round
  double computationTimeMs = (vtkPlusAccurateTimer::GetSystemTime() - startTimeSec) * 1000.0;
  // Update last processing time if new tracked frames have been acquired
  if (trackedFrameListToUse->GetNumberOfTrackedFrames() > numberOfFramesBeforeRecording)
  {
    m_LastProcessingTimePerFrameMs = computationTimeMs / (trackedFrameListToUse->GetNumberOfTrackedFrames() - numberOfFramesBeforeRecording);
  }

  // Launch timer to run acquisition again
  int waitTimeMs = std::max((int)(m_RecordingIntervalMs - computationTimeMs), 0);
  if (waitTimeMs == 0)
  {
    LOG_WARNING("Processing cannot keep up with aquisition! Try to decrease MaxTimeSpentWithProcessingMs parameter in device set configuration (it should be more than the processing time (the last one was " << m_LastProcessingTimePerFrameMs << "), so if it is already small, try to increase RecordingIntervalMs too)");
  }

  LOG_DEBUG("Number of requested frames: " << numberOfFramesToGet);
  LOG_DEBUG("Number of tracked frames in the list: " << std::setw(3) << numberOfFramesBeforeRecording << " => " << trackedFrameListToUse->GetNumberOfTrackedFrames());
  LOG_DEBUG("Last processing time: " << m_LastProcessingTimePerFrameMs);
  LOG_DEBUG("Computation time: " << computationTimeMs);
  LOG_DEBUG("Waiting time: " << waitTimeMs);

  QTimer::singleShot(waitTimeMs, this, SLOT(DoCalibration()));
}

//-----------------------------------------------------------------------------
PlusStatus QSpatialCalibrationToolbox::SetAndSaveResults()
{
  LOG_TRACE("SpatialCalibrationToolbox::SetAndSaveResults");

  // Set transducer origin related transforms
  vtkSmartPointer<vtkTransform> imageToProbeTransform = vtkSmartPointer<vtkTransform>::New();
  vtkSmartPointer<vtkMatrix4x4> imageToProbeTransformMatrix = vtkSmartPointer<vtkMatrix4x4>::New();
  m_Calibration->GetImageToProbeTransformMatrix(imageToProbeTransformMatrix);
  imageToProbeTransform->SetMatrix(imageToProbeTransformMatrix);
  double* imageToProbeScale = imageToProbeTransform->GetScale();
  vtkSmartPointer<vtkTransform> transducerOriginPixelToTransducerOriginTransform = vtkSmartPointer<vtkTransform>::New();
  transducerOriginPixelToTransducerOriginTransform->Identity();
  transducerOriginPixelToTransducerOriginTransform->Scale(imageToProbeScale);

  PlusTransformName transducerOriginPixelToTransducerOriginTransformName(m_ParentMainWindow->GetTransducerOriginPixelCoordinateFrame(), m_ParentMainWindow->GetTransducerOriginCoordinateFrame());
  m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->SetTransform(transducerOriginPixelToTransducerOriginTransformName, transducerOriginPixelToTransducerOriginTransform->GetMatrix());
  m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->SetTransformPersistent(transducerOriginPixelToTransducerOriginTransformName, true);
  m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->SetTransformDate(transducerOriginPixelToTransducerOriginTransformName, vtkPlusAccurateTimer::GetInstance()->GetDateAndTimeString().c_str());

  // Set result for visualization
  vtkPlusDisplayableObject* object = m_ParentMainWindow->GetVisualizationController()->GetObjectById(m_ParentMainWindow->GetTransducerModelId());
  if (object != NULL)
  {
    object->DisplayableOn();
  }
  else
  {
    LOG_WARNING("Missing probe displayable object.");
  }
  object = m_ParentMainWindow->GetVisualizationController()->GetObjectById(m_ParentMainWindow->GetImageObjectId());
  if (object != NULL)
  {
    object->DisplayableOn();
  }
  else
  {
    LOG_WARNING("Missing image displayable object.");
  }

  // Save result in configuration
  if (m_ParentMainWindow->GetVisualizationController()->GetTransformRepository()->WriteConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
  {
    LOG_ERROR("Unable to save freehand calibration result in configuration XML tree");
    SetState(ToolboxState_Error);
    return PLUS_FAIL;
  }

  return PLUS_SUCCESS;
}

//-----------------------------------------------------------------------------
void QSpatialCalibrationToolbox::CancelCalibration()
{
  LOG_INFO("Calibration cancelled");

  disconnect(ui.pushButton_StartCancelSpatial, SIGNAL(clicked()), this, SLOT(CancelCalibration()));
  connect(ui.pushButton_StartCancelSpatial, SIGNAL(clicked()), this, SLOT(StartDelayTimer()));
  ui.pushButton_StartCancelSpatial->setText(tr("Start"));

  if (m_State == ToolboxState_StartupDelay)
  {
    if (m_StartupDelayTimer->isActive())
    {
      m_StartupDelayTimer->stop();
    }
    LOG_TRACE("SpatialCalibrationToolbox::CancelCalibration before calibration delay timer finished");
  }
  else
  {

    m_CancelRequest = true;

    m_ParentMainWindow->SetToolboxesEnabled(true);
    m_ParentMainWindow->GetVisualizationController()->EnableWireLabels(false);
    m_ParentMainWindow->GetVisualizationController()->ShowResult(false);
  }
  SetState(ToolboxState_Idle);
}

//-----------------------------------------------------------------------------
bool QSpatialCalibrationToolbox::IsReadyToStartSpatialCalibration()
{
  LOG_TRACE("SpatialCalibrationToolbox::IsReadyToStartSpatialCalibration");

  // Try to load segmentation parameters from the device set configuration (see if it is there and correct)
  PlusFidPatternRecognition* patternRecognition = new PlusFidPatternRecognition();
  if (patternRecognition->ReadConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData()) != PLUS_SUCCESS)
  {
    ui.label_InstructionsSpatial->setText(tr("Pattern recognition configuration needs to be imported"));
    return false;
  }
  delete patternRecognition;

  // Determine if there is already a phantom registration present
  if (m_ParentMainWindow->GetVisualizationController()->IsExistingTransform(m_Calibration->GetPhantomCoordinateFrame(), m_Calibration->GetReferenceCoordinateFrame()) != PLUS_SUCCESS)
  {
    ui.label_InstructionsSpatial->setText(tr("Phantom registration needs to be imported"));
    return false;
  }

  // Everything is fine, ready for spatial calibration
  ui.label_InstructionsSpatial->setText(tr("Press Start and start scanning the phantom"));

  return true;
}

//-----------------------------------------------------------------------------
void QSpatialCalibrationToolbox::DisplaySegmentedPoints(bool enable)
{
  LOG_TRACE("SpatialCalibrationToolbox::DisplaySegmentedPoints");

  // Determine which data container to use
  vtkPlusTrackedFrameList* trackedFrameListToUse = NULL;
  if (m_NumberOfSegmentedValidationImages < m_NumberOfValidationImagesToAcquire)
  {
    trackedFrameListToUse = m_SpatialValidationData;
  }
  else
  {
    trackedFrameListToUse = m_SpatialCalibrationData;
  }

  // Display found wire intersections in the most recent frame
  vtkPoints* segmentedPoints = NULL;
  if (trackedFrameListToUse->GetNumberOfTrackedFrames() > 0 && enable)
  {
    PlusTrackedFrame* frame = trackedFrameListToUse->GetTrackedFrame(trackedFrameListToUse->GetNumberOfTrackedFrames() - 1);   // most recently acquired frame
    segmentedPoints = frame->GetFiducialPointsCoordinatePx();
  }
  if (segmentedPoints && segmentedPoints->GetNumberOfPoints() > 0)
  {
    m_ParentMainWindow->GetVisualizationController()->ShowResult(true);
  }
  else
  {
    m_ParentMainWindow->GetVisualizationController()->ShowResult(false);
  }
  m_ParentMainWindow->GetVisualizationController()->SetResultPolyDataPoints(segmentedPoints);
  m_ParentMainWindow->GetVisualizationController()->SetWireLabelPositions(segmentedPoints);
}

//-----------------------------------------------------------------------------
void QSpatialCalibrationToolbox::Reset()
{
  QAbstractToolbox::Reset();

  if (m_PatternRecognition != NULL)
  {
    delete m_PatternRecognition;
    m_PatternRecognition = NULL;
  }

  // Create algorithms
  m_Calibration = vtkSmartPointer<vtkPlusProbeCalibrationAlgo>::New();
  m_PatternRecognition = new PlusFidPatternRecognition();

  // Create tracked frame lists
  m_SpatialCalibrationData = vtkSmartPointer<vtkPlusTrackedFrameList>::New();
  m_SpatialCalibrationData->SetValidationRequirements(REQUIRE_UNIQUE_TIMESTAMP | REQUIRE_TRACKING_OK);

  m_SpatialValidationData = vtkSmartPointer<vtkPlusTrackedFrameList>::New();
  m_SpatialValidationData->SetValidationRequirements(REQUIRE_UNIQUE_TIMESTAMP | REQUIRE_TRACKING_OK);

  // Restore calibration and pattern recognition algorithm details
  this->OnActivated();
}

//-----------------------------------------------------------------------------
void QSpatialCalibrationToolbox::OnDeactivated()
{

}