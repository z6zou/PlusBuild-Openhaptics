/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#ifndef RECORDPHANTOMPOINTSTOOLBOX_H
#define RECORDPHANTOMPOINTSTOOLBOX_H

#include "ui_QPhantomRegistrationToolbox.h"

#include "QAbstractToolbox.h"
#include "PlusConfigure.h"

#include <QWidget>

class vtkPlusPhantomLandmarkRegistrationAlgo;
class vtkPlusPhantomLinearObjectRegistrationAlgo;
class vtkPlusLandmarkDetectionAlgo;
class vtkActor;
class vtkPolyData;
class vtkRenderer;

enum TabIndex
{
  TabIndex_Landmark,
  TabIndex_LinearObject
};

enum LinearObjectRegistrationState
{
  LinearObjectRegistrationState_Incomplete,
  LinearObjectRegistrationState_InProgress,
  LinearObjectRegistrationState_Complete
};

enum LandmarkPivotingState
{
  LandmarkPivotingState_Incomplete,
  LandmarkPivotingState_InProgress,
  LandmarkPivotingState_Complete
};
//-----------------------------------------------------------------------------

/*! \class PhantomRegistrationToolbox
* \brief Phantom registration toolbox class
* \ingroup PlusAppFCal
*/
class QPhantomRegistrationToolbox : public QWidget, public QAbstractToolbox
{
  Q_OBJECT

public:
  /*!
  * Constructor
  * \param aParentMainWindow Parent main window
  * \param aFlags widget flag
  */
  QPhantomRegistrationToolbox(fCalMainWindow* aParentMainWindow, Qt::WindowFlags aFlags = 0);

  /*! Destructor */
  ~QPhantomRegistrationToolbox();

  /*! \brief Refresh contents (e.g. GUI elements) of toolbox according to the state in the toolbox controller - implementation of a pure virtual function */
  virtual void OnActivated();

  /*!
  * Finalize toolbox
  */
  virtual void OnDeactivated();

  /*!
  * Read stylus calibration configuration for fCal
  * \param aConfig Root element of the input device set configuration XML data
  */
  PlusStatus ReadConfiguration(vtkXMLDataElement* aConfig);

  /*!
  * Refresh contents (e.g. GUI elements) of toolbox according to the state in the toolbox controller - implementation of a pure virtual function
  */
  virtual void RefreshContent();

  /*!
  * Sets display mode (visibility of actors) according to the current state - implementation of a pure virtual function
  */
  void SetDisplayAccordingToState();



  /*!
  * Return phantom landmark registration algorithm object
  * \return Phantom registration algo
  */
  vtkPlusPhantomLandmarkRegistrationAlgo* GetPhantomLandmarkRegistrationAlgo();;

  /*!
  * Return phantom linear object registration algorithm object
  * \return Phantom registration algo
  */
  vtkPlusPhantomLinearObjectRegistrationAlgo* GetPhantomLinearObjectRegistrationAlgo();;

  /*!
  * Sets the state of the linear object registration
  */
  void SetLinearObjectRegistrationState(LinearObjectRegistrationState state);
  /*!
  * Return state of the linear object registration
  */
  LinearObjectRegistrationState GetLinearObjectRegistrationState();

  /*!
  * Sets the state of the landmark pivoting detection
  */
  void SetLandmarkPivotingState(LandmarkPivotingState state);
  /*!
  * Return state of the landmark pivoting detection
  */
  LandmarkPivotingState GetLandmarkPivotingState();

protected:
  /*!
  * Initialize 3D visualization of the phantom in toolbox canvas
  * \return Success flag
  */
  PlusStatus LoadPhantomModel();

  /*!
  * Put state into in progress if all prerequisites are done
  * \return Success flag
  */
  PlusStatus Start();

  /*! Get message telling the state of the calibration */
  QString GetCalibrationStateMessage();

protected slots:
  /*!
  * Slot handling open stylus calibration button click
  */
  void OpenStylusCalibration();

  /*!
  * Slot handling record button for the landmark registration click
  */
  void RecordPoint();

  /*!
  * Slot handling undo button for the landmark registration click
  */
  void Undo();

  /*!
  * Slot handling reset button for the landmark registration click (and also is an overridden method of QAbstractToolbox which is called when disconnecting from the device set)
  */
  void Reset();

  /*!
  Slot handling start button for the linear object registration click
  */
  void StartLinearObjectRegistration();

  /*!
  Slot handling stop button for the linear object registration click
  */
  void StopLinearObjectRegistration();

  /*!
  Slot handling reset button for the linear object registration click
  */
  void ResetLinearObjectRegistration();

  /*!
  Slot handling Start Landmark Detection button to activate the automatic Landmark detection for landmark registration, �pivoting instead of pressing the record button
  */
  void StartLandmarkDetectionRegistration();

  /*!
  Slot handling Stop landmark detection button to deactivate the automatic Landmark detection for landmark registration, �pivoting instead of pressing the record button
  */
  void StopLandmarkPivotingRegistration();

  /*!
  Slot handling the continuous point acquisition during the linear object registration
  */
  void AddStylusTipTransformToLinearObjectRegistration();

  /*!
  Slot handling the continuous point acquisition during the linear object registration
  */
  void AddStylusTipTransformToLandmarkPivotingRegistration();

protected:
  /*! Phantom landmark registration algorithm */
  vtkSmartPointer<vtkPlusPhantomLandmarkRegistrationAlgo>     m_PhantomLandmarkRegistration;

  /*! Phantom linear object registration algorithm */
  vtkSmartPointer<vtkPlusPhantomLinearObjectRegistrationAlgo> m_PhantomLinearObjectRegistration;

  /*! Stylus tip Landmark detection algorithm */
  vtkSmartPointer<vtkPlusLandmarkDetectionAlgo>               m_LandmarkDetection;

  /*! Landmark already detected */
  int                                     m_LandmarkDetected;

  /*! Renderer for the canvas */
  vtkSmartPointer<vtkRenderer>            m_PhantomRenderer;

  /*! Actor for displaying the phantom geometry in phantom canvas */
  vtkSmartPointer<vtkActor>               m_PhantomActor;

  /*! Actor for displaying the defined landmark from the configuration file */
  vtkSmartPointer<vtkActor>               m_RequestedLandmarkActor;

  /*! Polydata holding the requested landmark for highlighting in phantom canvas */
  vtkSmartPointer<vtkPolyData>            m_RequestedLandmarkPolyData;

  /*! Index of current landmark */
  int                                     m_CurrentLandmarkIndex;

  /*! State of the collection of linear objects */
  LinearObjectRegistrationState           m_LinearObjectRegistrationState;

  /*! State of the pivot detection */
  LandmarkPivotingState                   m_LandmarkPivotingState;

  /*! Number of points acquired for linear object registration so far */
  int                                     m_CurrentPointNumber;

  /*! Stylus or stylus tip position (depending on the state) as string */
  QString                                 m_StylusPositionString;

  /*! Object marker coordinate frame string (e.g. Stylus)*/
  QString                                 m_ObjectMarkerCoordinateFrame;


  /*! Previous stylus tip to reference transform matrix to determine the difference at each point acquisition */
  vtkSmartPointer<vtkMatrix4x4>           m_PreviousStylusTipToReferenceTransformMatrix;

protected:
  Ui::PhantomRegistrationToolbox ui;

};

#endif