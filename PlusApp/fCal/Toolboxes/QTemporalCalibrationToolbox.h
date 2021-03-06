/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#ifndef TEMPORALCALIBRATIONTOOLBOX_H
#define TEMPORALCALIBRATIONTOOLBOX_H

// Local includes
#include "QAbstractToolbox.h"
#include "ui_QTemporalCalibrationToolbox.h"

// PlusLib includes
#include <PlusConfigure.h>
#include <vtkPlusLineSegmentationAlgo.h>
#include <vtkPlusTemporalCalibrationAlgo.h>

// Qt includes
#include <QTimer>
#include <QWidget>

class vtkContextView;
class vtkPlusChannel;
class vtkTable;
class vtkPlusTrackedFrameList;

//-----------------------------------------------------------------------------

/*! \class TemporalCalibrationToolbox
* \brief Temporal calibration toolbox class
* \ingroup PlusAppFCal
*/
class QTemporalCalibrationToolbox : public QWidget, public QAbstractToolbox
{
  Q_OBJECT

public:
  /*!
  * Constructor
  * \param aParentMainWindow Parent main window
  * \param aFlags widget flag
  */
  QTemporalCalibrationToolbox(fCalMainWindow* aParentMainWindow, Qt::WindowFlags aFlags = 0);

  /*! Destructor */
  ~QTemporalCalibrationToolbox();

  /*! \brief Refresh contents (e.g. GUI elements) of toolbox according to the state in the toolbox controller - implementation of a pure virtual function */
  virtual void OnActivated();

  /*!
  * Finalize toolbox
  */
  virtual void OnDeactivated();

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
  * \brief Filters events if this object has been installed as an event filter for the watched object
  * \param obj object
  * \param ev event
  * \return if you want to filter the event out, i.e. stop it being handled further, return true; otherwise return false
  */
  bool eventFilter(QObject* obj, QEvent* ev);

  /*! Prints a time value in sec as a string in msec */
  static std::string GetTimeAsString(double timeSec);

  void SetFreeHandStartupDelaySec(int freeHandStartupDelaySec) {FreeHandStartupDelaySec = freeHandStartupDelaySec;};
  void SegmentAndDisplayLine(PlusTrackedFrame& frame);

protected slots:
  /*! Start the delay startup timer*/
  void StartDelayTimer();

  /*! Delay before startup calibration*/
  void DelayStartup();

  /*! Acquire tracked frames for temporal calibration and calls the algorithm when done */
  void DoCalibration();

  /*! Show/hide popup window with the plots in it when toggling the Show Plots button */
  void ShowPlotsToggled(bool aOn);

  /*! Slot handling start temporal calibration button click */
  void StartCalibration();

  /*! Slot handling cancel calibration event (button click or explicit call) */
  void CancelCalibration();

  /*! Compute calibration results from the collected data and display the results */
  void ComputeCalibrationResults();

  /*! A signal combo box was changed */
  void FixedSignalChanged(int newIndex);
  void MovingSignalChanged(int newIndex);

  /*! A source combo box was changed */
  void FixedSourceChanged(int newIndex);
  void MovingSourceChanged(int newIndex);

  /*! When the user requests to save the calibration plots */
  void OnSavePlotsRequested();

protected:
  /*! Tracked frame for tracking data for temporal calibration */
  vtkSmartPointer<vtkPlusTrackedFrameList>        TemporalCalibrationFixedData;
  /*! Tracked frame for video data for temporal calibration */
  vtkSmartPointer<vtkPlusTrackedFrameList>        TemporalCalibrationMovingData;
  /*! Delay time before start acquisition [s] */
  int                                             FreeHandStartupDelaySec;
  /*! Current time delayed before the acquisition [s] */
  int                                             StartupDelayRemainingTimeSec;
  /*! Timer before start acquisition*/
  QTimer                                          StartupDelayTimer;
  /*! Flag if cancel is requested */
  bool                                            CancelRequest;
  /*! Duration of the temporal calibration process in seconds */
  int                                             TemporalCalibrationDurationSec;
  /*! Timestamp of last recorded video item(items acquired since this timestamp will be recorded) */
  double                                          LastRecordedFixedItemTimestamp;
  /*! Timestamp of last recorded tracker item (items acquired since this timestamp will be recorded) */
  double                                          LastRecordedMovingItemTimestamp;
  /*! Time interval between recording (sampling) cycles (in milliseconds) */
  int                                             RecordingIntervalMs;
  /*! Time of starting temporal calibration*/
  double                                          StartTimeSec;
  /*! Saved tracker offset in case the temporal calibration is canceled or unsuccessful */
  double                                          PreviousFixedOffset;
  /*! Saved video offset in case the temporal calibration is canceled or unsuccessful */
  double                                          PreviousMovingOffset;
  /*! Metric table of video positions for temporal calibration */
  vtkSmartPointer<vtkTable>                       FixedPositionMetric;
  /*! Metric table of uncalibrated tracker positions for temporal calibration */
  vtkSmartPointer<vtkTable>                       UncalibratedMovingPositionMetric;
  /*! Metric table of calibrated tracker positions for temporal calibration */
  vtkSmartPointer<vtkTable>                       CalibratedMovingPositionMetric;
  /*! Window that is created/deleted when Show Plots button is toggled */
  QWidget*                                        TemporalCalibrationPlotsWindow;
  /*! Chart view for the uncalibrated plot */
  vtkContextView*                                 UncalibratedPlotContextView;
  /*! Chart view for the calibrated plot */
  vtkContextView*                                 CalibratedPlotContextView;

  vtkPlusChannel*                                 FixedChannel;
  vtkPlusTemporalCalibrationAlgo::FRAME_TYPE      FixedType;
  vtkPlusChannel*                                 MovingChannel;
  vtkPlusTemporalCalibrationAlgo::FRAME_TYPE      MovingType;

  PlusTransformName                               FixedValidationTransformName;
  PlusTransformName                               MovingValidationTransformName;

  vtkSmartPointer<vtkPlusTemporalCalibrationAlgo> TemporalCalibrationAlgo;

  std::string                                     RequestedFixedChannel;
  std::string                                     RequestedMovingChannel;
  std::string                                     RequestedFixedSource;
  std::string                                     RequestedMovingSource;

  std::string                                     LastSaveDirectory;
  QPushButton*                                    SaveFileButton;

  vtkSmartPointer<vtkPlusLineSegmentationAlgo>    LineSegmenter;

protected:
  Ui::TemporalCalibrationToolbox ui;
};

#endif