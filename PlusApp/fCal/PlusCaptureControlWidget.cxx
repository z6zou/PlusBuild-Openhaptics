/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

// Local includes
#include "PlusCaptureControlWidget.h"

// PlusLib includes
#include <vtkPlusChannel.h>
#include <vtkPlusDataCollector.h>
#include <vtkPlusVirtualCapture.h>

// VTK includes
#include <vtksys/SystemTools.hxx>

// Qt includes
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

//-----------------------------------------------------------------------------
PlusCaptureControlWidget::PlusCaptureControlWidget(QWidget* aParent)
  : QWidget(aParent)
  , m_Device(NULL)
{
  ui.setupUi(this);

  connect(ui.startStopButton, SIGNAL(clicked()), this, SLOT(StartStopButtonPressed()));
  connect(ui.saveButton, SIGNAL(clicked()), this, SLOT(SaveButtonPressed()));
  connect(ui.saveAsButton, SIGNAL(clicked()), this, SLOT(SaveAsButtonPressed()));
  connect(ui.clearRecordedFramesButton, SIGNAL(clicked()), this, SLOT(ClearButtonPressed()));
  connect(ui.samplingRateSlider, SIGNAL(valueChanged(int)), this, SLOT(SamplingRateChanged(int)));
  connect(ui.snapshotButton, SIGNAL(clicked()), this, SLOT(TakeSnapshot()));

  ui.startStopButton->setText("Start");

  QPalette palette;
  palette.setColor(ui.startStopButton->backgroundRole(), QColor::fromRgb(255, 255, 255));
  ui.startStopButton->setPalette(palette);
}

//-----------------------------------------------------------------------------
PlusCaptureControlWidget::~PlusCaptureControlWidget()
{
}

//-----------------------------------------------------------------------------
PlusStatus PlusCaptureControlWidget::WriteToFile(const QString& aFilename)
{
  // Force an update of the configuration
  if (this->GetCaptureDevice()->GetDataCollector() != NULL)
  {
    this->GetCaptureDevice()->GetDataCollector()->WriteConfiguration(vtkPlusConfig::GetInstance()->GetDeviceSetConfigurationData());
  }
  else
  {
    LOG_WARNING("DataCollector is not accessible from this capture widget. Configuration can't be flushed.");
  }

  // Save
  if (m_Device->CloseFile(aFilename.toLatin1()) != PLUS_SUCCESS)
  {
    LOG_ERROR("Saving failed. Unable to close device.");
    return PLUS_FAIL;
  }

  return PLUS_SUCCESS;
}

//-----------------------------------------------------------------------------
double PlusCaptureControlWidget::GetMaximumFrameRate() const
{
  LOG_TRACE("PlusCaptureControlWidget::GetMaximumFrameRate");

  if (m_Device == NULL)
  {
    LOG_ERROR("Unable to reach valid device!");
    return 0.0;
  }

  return m_Device->GetRequestedFrameRate();
}

//-----------------------------------------------------------------------------
void PlusCaptureControlWidget::UpdateBasedOnState()
{
  if (m_Device != NULL)
  {
    ui.startStopButton->setEnabled(true);
    ui.channelIdentifierLabel->setText(QString::fromStdString(m_Device->GetDeviceId()));
    ui.numberOfRecordedFramesValueLabel->setText(QString::number(m_Device->GetTotalFramesRecorded(), 10));

    ui.saveAsButton->setEnabled(this->CanSave());
    ui.saveButton->setEnabled(this->CanSave());
    ui.clearRecordedFramesButton->setEnabled(this->CanSave());

    if (m_Device->GetEnableCapturing())
    {
      ui.actualFrameRateValueLabel->setText(QString::number(m_Device->GetActualFrameRate(), 'f', 2));
      ui.samplingRateSlider->setEnabled(false);
      ui.startStopButton->setText(QString("Stop"));
      ui.startStopButton->setIcon(QPixmap(":/icons/Resources/icon_Stop.png"));
      ui.startStopButton->setEnabled(true);
      ui.snapshotButton->setEnabled(false);
    }
    else
    {
      ui.startStopButton->setText(QString("Record"));
      ui.startStopButton->setIcon(QPixmap(":/icons/Resources/icon_Record.png"));
      ui.startStopButton->setFocus();
      ui.startStopButton->setEnabled(true);
      ui.snapshotButton->setEnabled(true);

      ui.actualFrameRateValueLabel->setText(QString::number(0.0, 'f', 2));
      ui.samplingRateSlider->setEnabled(true);
    }
  }
  else
  {
    ui.startStopButton->setText("Record");
    ui.startStopButton->setIcon(QPixmap(":/icons/Resources/icon_Record.png"));
    ui.startStopButton->setEnabled(false);

    ui.startStopButton->setEnabled(false);
    ui.saveButton->setEnabled(false);
    ui.snapshotButton->setEnabled(false);
    ui.clearRecordedFramesButton->setEnabled(false);
    ui.channelIdentifierLabel->setText("");
    ui.samplingRateSlider->setEnabled(false);
    ui.actualFrameRateValueLabel->setText(QString::number(0.0, 'f', 2));
    ui.numberOfRecordedFramesValueLabel->setText(QString::number(0, 10));
  }
}

//-----------------------------------------------------------------------------
PlusStatus PlusCaptureControlWidget::SaveToMetafile(std::string aOutput)
{
  return PLUS_SUCCESS;
}

//-----------------------------------------------------------------------------
void PlusCaptureControlWidget::StartStopButtonPressed()
{
  if (m_Device != NULL)
  {
    QString text = ui.startStopButton->text();
    if (QString::compare(text, QString("Record")) == 0)
    {
      m_Device->SetEnableCapturing(true);
    }
    else
    {
      m_Device->SetEnableCapturing(false);
      ui.actualFrameRateValueLabel->setText(QString("0.0"));
    }

    this->UpdateBasedOnState();
  }
}

//-----------------------------------------------------------------------------
void PlusCaptureControlWidget::SetCaptureDevice(vtkPlusVirtualCapture& aDevice)
{
  m_Device = &aDevice;

  this->SamplingRateChanged(10);

  this->UpdateBasedOnState();
}

//-----------------------------------------------------------------------------
void PlusCaptureControlWidget::SaveButtonPressed()
{
  this->SaveFile();
}

//-----------------------------------------------------------------------------
void PlusCaptureControlWidget::SaveAsButtonPressed()
{
  bool isCapturing = m_Device->GetEnableCapturing();

  // Stop recording
  m_Device->SetEnableCapturing(false);

  // Present dialog, get filename
  QFileDialog* dialog = new QFileDialog(this, QString("Select save file"), QString(vtkPlusConfig::GetInstance()->GetOutputDirectory().c_str()), QString("All MetaSequence files (*.mha *.mhd)"));
  dialog->setMinimumSize(QSize(640, 480));
  dialog->setAcceptMode(QFileDialog::AcceptSave);
  dialog->setFileMode(QFileDialog::AnyFile);
  dialog->setViewMode(QFileDialog::Detail);
  dialog->setDefaultSuffix("mha");
  dialog->exec();

  QApplication::processEvents();

  if (dialog->selectedFiles().size() == 0)
  {
    m_Device->SetEnableCapturing(isCapturing);
    delete dialog;
    return;
  }

  QString fileName = dialog->selectedFiles().first();
  delete dialog;

  std::string message("");
  if (this->WriteToFile(fileName) != PLUS_FAIL)
  {
    message += "Successfully wrote: ";
  }
  else
  {
    message += "Failed to write: ";
  }
  message += fileName.toLatin1().constData();;

  this->UpdateBasedOnState();
}

//-----------------------------------------------------------------------------
void PlusCaptureControlWidget::SamplingRateChanged(int aValue)
{
  LOG_TRACE("PlusCaptureControlWidget::RecordingFrameRateChanged(" << aValue << ")");

  double maxFrameRate = GetMaximumFrameRate();
  int samplingRate = (int)(pow(2.0, ui.samplingRateSlider->maximum() - aValue));
  double requestedFrameRate(0.0);

  if (samplingRate > 0)
  {
    requestedFrameRate = maxFrameRate / (double)samplingRate;
  }
  else
  {
    LOG_WARNING("samplingRate value is invalid");
    requestedFrameRate = maxFrameRate;
  }

  ui.samplingRateSlider->setToolTip(tr("1 / ").append(QString::number((int)samplingRate)));
  ui.requestedFrameRateValueLabel->setText(QString::number(requestedFrameRate, 'f', 2));

  LOG_INFO("Sampling rate changed to " << aValue << " (matching requested frame rate is " << requestedFrameRate << ")");
  this->m_Device->SetRequestedFrameRate(requestedFrameRate);
}

//-----------------------------------------------------------------------------
void PlusCaptureControlWidget::ClearButtonPressed()
{
  this->Clear();
}

//-----------------------------------------------------------------------------
void PlusCaptureControlWidget::SendStatusMessage(const std::string& aMessage)
{
  emit EmitStatusMessage(aMessage);
}

//-----------------------------------------------------------------------------
void PlusCaptureControlWidget::TakeSnapshot()
{
  LOG_TRACE("PlusCaptureControlWidget::TakeSnapshot");

  if (this->m_Device->TakeSnapshot() != PLUS_SUCCESS)
  {
    std::string message(this->m_Device->GetDeviceId());
    message += ": Unable to take snapshot.";
    LOG_ERROR(message);
    SendStatusMessage(message);
    return;
  }

  std::string message(this->m_Device->GetDeviceId());
  message += ": Snapshot taken.";
  LOG_INFO(message);
  SendStatusMessage(message);
}

//-----------------------------------------------------------------------------
void PlusCaptureControlWidget::SetEnableCapturing(bool aCapturing)
{
  if (m_Device != NULL)
  {
    this->m_Device->SetEnableCapturing(aCapturing);

    this->UpdateBasedOnState();
  }
}

//-----------------------------------------------------------------------------
void PlusCaptureControlWidget::SaveFile()
{
  LOG_TRACE("PlusCaptureControlWidget::SaveFile");

  // Stop recording
  m_Device->SetEnableCapturing(false);

  std::string baseFileName = m_Device->GetBaseFilename();
  if (baseFileName.empty())
  {
    baseFileName = std::string("TrackedImageSequence_") + m_Device->GetDeviceId();
  }
  std::string fileName = vtkPlusConfig::GetInstance()->GetOutputPath(
                           vtksys::SystemTools::GetFilenamePath(baseFileName) +
                           vtksys::SystemTools::GetFilenameWithoutLastExtension(baseFileName) + "_" +
                           vtksys::SystemTools::GetCurrentDateTime("%Y%m%d_%H%M%S") +
                           vtksys::SystemTools::GetFilenameLastExtension(baseFileName)
                         );

  std::string message;
  if (this->WriteToFile(QString(fileName.c_str())) != PLUS_FAIL)
  {
    message += "Successfully wrote: ";
  }
  else
  {
    message += "Failed to write: ";
  }
  message += fileName;

  this->SendStatusMessage(message);
  this->UpdateBasedOnState();

  LOG_INFO("Captured tracked frame list saved into '" << fileName << "'");
}

//-----------------------------------------------------------------------------
void PlusCaptureControlWidget::Clear()
{
  m_Device->SetEnableCapturing(false);
  m_Device->Reset();

  this->UpdateBasedOnState();

  std::string aMessage("Successfully cleared data for device: ");
  aMessage += this->m_Device->GetDeviceId();
  this->SendStatusMessage(aMessage);

  LOG_INFO("Captured tracked frame list was discarded");
}

//-----------------------------------------------------------------------------
bool PlusCaptureControlWidget::CanSave() const
{
  return !m_Device->GetEnableCapturing() && m_Device->HasUnsavedData();
}

//-----------------------------------------------------------------------------
bool PlusCaptureControlWidget::CanRecord() const
{
  return m_Device != NULL;
}