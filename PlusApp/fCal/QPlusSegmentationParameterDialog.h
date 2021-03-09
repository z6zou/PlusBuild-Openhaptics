/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#ifndef SEGMENTATIONPARAMETERDIALOG_H
#define SEGMENTATIONPARAMETERDIALOG_H

// Local includes
#include "ui_QPlusSegmentationParameterDialog.h"

// PlusLib includes
#include <PlusConfigure.h>
#include <PlusTrackedFrame.h>

// Qt includes
#include <QDialog>

class PlusFidPatternRecognition;
class QTimer;
class vtkActor;
class vtkPlusDataCollector;
class vtkImageActor;
class vtkPlusImageVisualizer;
class vtkPlusChannel;
class vtkPolyData;
class vtkROIModeHandler;
class vtkSpacingModeHandler;

//-----------------------------------------------------------------------------

/*! \class QPlusSegmentationParameterDialog
 * \brief Segmentation parameter setting dialog class
 * \ingroup PlusAppCommonWidgets
 */
class QPlusSegmentationParameterDialog : public QDialog
{
  Q_OBJECT

public:
  /*!
  * Constructor
  * \param aParent Parent object
  * \param aDataCollector Data collector (needed for the image output)
  */
  QPlusSegmentationParameterDialog(QWidget* aParent, vtkPlusDataCollector* aCollector, vtkPlusChannel* aChannel);

  /*!
  * Destructor
  */
  ~QPlusSegmentationParameterDialog();

  /*!
  * Return canvas renderer
  * \return Canvas Renderer
  */
  vtkRenderer* GetCanvasRenderer()
  {
    return m_CanvasRenderer;
  };

  /*!
  * Return image frame size
  * \param Output array for image dimensions
  * \return Success flag
  */
  PlusStatus GetFrameSize(FrameSizeType& aImageDimensions);

  /*!
  * Set ROI values to spinBoxes (if a values is -1, it is not set - because usually only 2 values change at a time)
  * \return Success flag
  */
  PlusStatus SetROI(unsigned int aXMin, unsigned int aYMin, unsigned int aXMax, unsigned int aYMax);

  /*!
  * Get ROI values from spinBoxes
  * \return Success flag
  */
  PlusStatus GetROI(unsigned int& aXMin, unsigned int& aYMin, unsigned int& aXMax, unsigned int& aYMax);

  PlusStatus SetROI(unsigned int roi[4]);
  PlusStatus GetROI(unsigned int roi[4]);

  /*!
  * Compute and set spacing according to summed measured length (got from the mode handler)
  * \return Success flag
  */
  PlusStatus ComputeSpacingFromMeasuredLengthSum();

  /*!
  * Get reference width from spinbox value
  * \return Reference width mm
  */
  double GetSpacingReferenceWidth();

  /*!
  * Get reference height from spinbox value
  * \return Reference height mm
  */
  double GetSpacingReferenceHeight();

  /*!
  * Get original spacing
  * \return Mm per pixel spacing (from input configuration)
  */
  double GetApproximateSpacingMmPerPixel()
  {
    return m_ApproximateSpacingMmPerPixel;
  };

protected:
  /*!
  * Initialize visualization (actors, cameras etc.)
  * \return Success flag
  */
  PlusStatus InitializeVisualization();

  /*!
  * Parses configuration data and fills form (segmentation parameters)
  * \return Success flag
  */
  PlusStatus ReadConfiguration();

  /*!
  * Write configuration XML data based on the input fields on the GUI
  * \return Success flag
  */
  PlusStatus WriteConfiguration();

  /*!
  * Switch to ROI mode - canvas events will answer to events of ROI mode
  * \return Success flag
  */
  PlusStatus SwitchToROIMode();

  /*!
  * Switch to Spacing mode - canvas events will answer to events of Spacing mode
  * \return Success flag
  */
  PlusStatus SwitchToSpacingMode();

  /*!
  * Segments the currently displayed image and draws the result on the canvas
  * \return Success flag
  */
  PlusStatus SegmentCurrentImage();

protected slots:
  /*!
  * Applies the configuration to the data element and closes window
  */
  void ApplyAndCloseClicked();

  /*!
  * Shows config file saver dialog, saves the configuration file and closes window
  */
  void SaveAndCloseClicked();

  /*!
  * Slot handling ROI groupbox toggle
  * \param aOn True if checked, false if unchecked
  */
  void GroupBoxROIToggled(bool aOn);

  /*!
  * Slot handling spacing groupbox toggle
  * \param aOn True if checked, false if unchecked
  */
  void GroupBoxSpacingToggled(bool aOn);

  /*!
  * Resize event handler
  * \param aEvent Resize event
  */
  virtual void resizeEvent(QResizeEvent* aEvent);

  /*!
  * Slot catching refresh timer events and refreshing the canvas
  */
  void UpdateCanvas();

  /*!
  * Freeze / Unfreeze image
  * \param aOn True if checked (freeze), false if unchecked (unfreeze)
  */
  void OnFreezeImageClicked(bool aOn);

  /*!
  * Export frozen image into a single-frame metafile
  */
  void ExportImage();

  /*!
  * Slot handling ROI XMin value change
  * \param aValue New value
  */
  void ROIXMinChanged(int aValue);

  /*!
  * Slot handling ROI YMin value change
  * \param aValue New value
  */
  void ROIYMinChanged(int aValue);

  /*!
  * Slot handling ROI XMax value change
  * \param aValue New value
  */
  void ROIXMaxChanged(int aValue);

  /*!
  * Slot handling ROI YMax value change
  * \param aValue New value
  */
  void ROIYMaxChanged(int aValue);

  /*!
  * Slot handling reference width value change
  * \param aValue New value
  */
  void ReferenceWidthChanged(double aValue);

  /*!
  * Slot handling reference height value change
  * \param aValue New value
  */
  void ReferenceHeightChanged(double aValue);

  /*!
  * Slot handling opening circle radius value change
  * \param aValue New value
  */
  void OpeningCircleRadiusChanged(double aValue);

  /*!
  * Slot handling opening bar size value change
  * \param aValue New value
  */
  void OpeningBarSizeChanged(double aValue);

  /*!
  * Slot handling line pair distance error value change
  * \param aValue New value
  */
  void LinePairDistanceErrorChanged(double aValue);

  /*!
  * Slot handling angle difference value change
  * \param aValue New value
  */
  void AngleDifferenceChanged(double aValue);

  /*!
  * Slot handling minimum theta value change
  * \param aValue New value
  */
  void MinThetaChanged(double aValue);

  /*!
  * Slot handling maximum theta value change
  * \param aValue New value
  */
  void MaxThetaChanged(double aValue);

  /*!
  * Slot handling angle tolerance value change
  * \param aValue New value
  */
  void AngleToleranceChanged(double aValue);

  /*!
  * Slot handling line 3rd point distance value change
  * \param aValue New value
  */
  void CollinearPointsMaxDistanceFromLineChanged(double aValue);

  /*!
  * Slot handling image threshold value change
  * \param aValue New value
  */
  void ImageThresholdChanged(double aValue);

  /*!
  * Slot handling max line shift value change
  * \param aValue New value
  */
  void MaxLineShiftMmChanged(double aValue);

  /*!
  * Slot handling max candidates change
  * \param aValue New value
  */
  void MaxCandidatesChanged(double aValue);

  /*!
  * Slot handling original intensity for dots checkbox toggle
  * \param aOn New state
  */
  void OriginalIntensityForDotsToggled(bool aOn);

protected:
  /*! Cached reference to data collector */
  vtkPlusDataCollector*                   m_DataCollector;

  /*! Cached reference to active channel */
  vtkPlusChannel*                         m_SelectedChannel;

  /*! Cached pointer to renderer for the canvas */
  vtkRenderer*                            m_CanvasRenderer;

  /*! Actor for displaying segmented points */
  vtkSmartPointer<vtkActor>               m_SegmentedPointsActor;

  /*! Poly data for holding the segmented points */
  vtkSmartPointer<vtkPolyData>            m_SegmentedPointsPolyData;

  /*! Poly data for holding the fiducial candidates */
  vtkSmartPointer<vtkPolyData>            m_CandidatesPolyData;

  /*! ROI mode handler callback command instance */
  vtkSmartPointer<vtkROIModeHandler>      m_ROIModeHandler;

  /*! Spacing mode handler callback command instance */
  vtkSmartPointer<vtkSpacingModeHandler>  m_SpacingModeHandler;

  /*! 2D Image Visualization */
  vtkSmartPointer<vtkPlusImageVisualizer> m_ImageVisualizer;

  /*! Timer for refreshing the canvas */
  QTimer*                                 m_CanvasRefreshTimer;

  /*! Original mm per pixel spacing (from input configuration) */
  double                                  m_ApproximateSpacingMmPerPixel;

  /*! Pattern recognition object for segmenting the images */
  PlusFidPatternRecognition*              m_PatternRecognition;

  /*! Flag indicating if image is frozen (using Freeze button) */
  bool                                    m_ImageFrozen;

  /*! Tracked frame to hold the desired image to process*/
  PlusTrackedFrame                        m_Frame;

protected:
  Ui::SegmentationParameterDialog ui;
};

#endif
