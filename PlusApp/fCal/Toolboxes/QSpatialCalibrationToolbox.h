/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#ifndef SPATIALCALIBRATIONTOOLBOX_H
#define SPATIALCALIBRATIONTOOLBOX_H

#include "ui_QSpatialCalibrationToolbox.h"

#include "QAbstractToolbox.h"
#include "PlusConfigure.h"

#include "PlusFidPatternRecognitionCommon.h"

#include <QWidget>

class vtkPlusProbeCalibrationAlgo;
class PlusFidPatternRecognition;
class vtkPlusTrackedFrameList;

//-----------------------------------------------------------------------------

/*! \class SpatialCalibrationToolbox
* \brief Spatial calibration toolbox class
* \ingroup PlusAppFCal
*/
class QSpatialCalibrationToolbox : public QWidget, public QAbstractToolbox
{
  Q_OBJECT

public:
  /*!
  * Constructor
  * \param aParentMainWindow Parent main window
  * \param aFlags widget flag
  */
  QSpatialCalibrationToolbox(fCalMainWindow* aParentMainWindow, Qt::WindowFlags aFlags = 0);

  /*! Destructor */
  ~QSpatialCalibrationToolbox();

  /*! \brief Refresh contents (e.g. GUI elements) of toolbox according to the state in the toolbox controller - implementation of a pure virtual function */
  virtual void OnActivated();

  /*!
  * Finalize toolbox
  */
  virtual void OnDeactivated();

  /*! \brief Reset toolbox to initial state - */
  virtual void Reset();

  /*!
  * Read freehand calibration configuration for fCal
  * \param aConfig Root element of the input device set configuration XML data
  */
  PlusStatus ReadConfiguration(vtkXMLDataElement* aConfig);

  /*! Refresh contents (e.g. GUI elements) of toolbox according to the state in the toolbox controller - implementation of a pure virtual function */
  virtual void RefreshContent();

  /*! Sets display mode (visibility of actors) according to the current state - implementation of a pure virtual function */
  void SetDisplayAccordingToState();

protected:
  /*!
  * Determines if everything is OK to run spatial calibration
  * \return Ready flag
  */
  bool IsReadyToStartSpatialCalibration();

  /*!
    Prepares and shows the last segmented points from the current acquisition.
    If enable is false then segmented points are hidden (even if they were available).
  */
  void DisplaySegmentedPoints(bool enable);

  /*! Set and save calibration results */
  PlusStatus SetAndSaveResults();

  void SetFreeHandStartupDelaySec(int freeHandStartupDelaySec) {m_FreeHandStartupDelaySec = freeHandStartupDelaySec;};

protected slots:

  /*! Start the delay startup timer*/
  void StartDelayTimer();

  /*! Delay before startup calibration*/
  void DelayStartup();

  /*! Acquire tracked frames and segment them. Runs calibration if acquisition is ready */
  void DoCalibration();

  /*! Slot handling open phantom registration button click */
  void OpenPhantomRegistration();

  /*! Open XML file containing segmentation parameters and read the contents */
  void OpenSegmentationParameters();

  /*! Edit segmentation parameters */
  void EditSegmentationParameters();

  /*! Slot handling start spatial calibration button click */
  void StartCalibration();

  /*! Slot handling cancel calibration event (button click or explicit call) */
  void CancelCalibration();

protected:
  /*! Calibration algorithm */
  vtkSmartPointer<vtkPlusProbeCalibrationAlgo>  m_Calibration;

  /*! Pattern recognition algorithm */
  PlusFidPatternRecognition*                    m_PatternRecognition;

  /*! Tracked frame data for spatial calibration */
  vtkSmartPointer<vtkPlusTrackedFrameList>      m_SpatialCalibrationData;

  /*! Tracked frame data for validation of spatial calibration */
  vtkSmartPointer<vtkPlusTrackedFrameList>      m_SpatialValidationData;

  /*! Delay time before start acquisition [s] */
  int                           m_FreeHandStartupDelaySec;

  /*! Current time delayed before the acquisition [s] */
  int                           m_StartupDelayRemainingTimeSec;

  /*! Timer before start acquisition*/
  QTimer*                       m_StartupDelayTimer;

  /*! Timestamp of last recorded frame (the tracked frames acquired since this timestamp will be recorded) */
  double                        m_LastRecordedFrameTimestamp;

  /*! Flag if cancel is requested */
  bool                          m_CancelRequest;

  /*! Number of needed calibration images */
  int                           m_NumberOfCalibrationImagesToAcquire;

  /*! Number of needed validation images */
  int                           m_NumberOfValidationImagesToAcquire;

  /*! Number of segmented calibration images */
  int                           m_NumberOfSegmentedCalibrationImages;

  /*! Number of segmented validation images */
  int                           m_NumberOfSegmentedValidationImages;

  /*! Time interval between recording (sampling) cycles (in milliseconds) */
  int                           m_RecordingIntervalMs;

  /*! Maximum time spent with processing (getting tracked frames, segmentation) per second (in milliseconds) */
  int                           m_MaxTimeSpentWithProcessingMs;

  /*! Time needed to process one frame in the latest recording round (in milliseconds) */
  int                           m_LastProcessingTimePerFrameMs;

protected:
  Ui::SpatialCalibrationToolbox ui;

};

#endif