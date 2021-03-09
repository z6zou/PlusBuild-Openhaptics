/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __fCalMainWindow_h
#define __fCalMainWindow_h

#include "PlusConfigure.h"
#include "ui_fCalMainWindow.h"
#include <QMainWindow>

class QAbstractToolbox;
class QPlusChannelAction;
class QLabel;
class QPlusStatusIcon;
class QProgressBar;
class QTimer;
class vtkPlusChannel;
class vtkPlusDevice;
class vtkPlusVisualizationController;

//-----------------------------------------------------------------------------

enum ToolboxType
{
  ToolboxType_Undefined = -1,
  ToolboxType_Configuration,
  ToolboxType_StylusCalibration,
  ToolboxType_PhantomRegistration,
  ToolboxType_TemporalCalibration,
  ToolboxType_SpatialCalibration,
  ToolboxType_Capturing,
  ToolboxType_VolumeReconstruction,
  ToolboxType_Count,
};

//-----------------------------------------------------------------------------

/*! \class fCalMainWindow
* \brief Main window of the fCal application
* \ingroup PlusAppFCal
*/
class fCalMainWindow : public QMainWindow
{
  Q_OBJECT

public:
  /*!
  * Constructor
  * \param aParent parent
  * \param aFlags widget flag
  */
  fCalMainWindow(QWidget* parent = 0, Qt::WindowFlags flags = 0);

  /*!
  * Destructor
  */
  ~fCalMainWindow();

  /*!
  * Initialize controller, toolboxes, canvas and connect to devices
  */
  void Initialize();

  /*!
  * Get object visualizer object
  * \return Object visualizer
  */
  vtkPlusVisualizationController* GetVisualizationController();

  /*!
  * Set status bar text
  * \param aText Status bar text
  */
  void SetStatusBarText(QString aText);

  /*!
  * Set status bar progress
  * \param aPercent Progress percent of the status bar (if -1 then hide progress bar)
  */
  void SetStatusBarProgress(int aPercent);

  /*!
  * Enable/disable toolbox changing
  * \param Enable/Disable flag
  */
  void SetToolboxesEnabled(bool);

  /*!
  * Enable/disable image manipulation
  * \param Enable/Disable flag
  */
  void SetImageManipulationMenuEnabled(bool);

  /*!
  * Enable/disable show 3d objects menu
  * \param Enable/Disable flag
  */
  void Set3DManipulationMenuEnabled(bool);

  /*!
  * Accessor to query the state of the check box
  */
  bool IsOrientationMarkersEnabled();

  /*!
  * Reset all toolboxes and hide all tools (called when disconnected from a device set)
  */
  void ResetAllToolboxes();

  /*!
  * Return a toolbox
  * \param aType Toolbox type identifier
  * \return Toolbox object
  */
  QAbstractToolbox* GetToolbox(ToolboxType aType);

  /*! Get image coordinate frame name */
  std::string GetImageCoordinateFrame();
  /*! Set image coordinate frame name */
  void SetImageCoordinateFrame(const char* aImageCoordinateFrame);

  /*! Get probe coordinate frame name */
  std::string GetProbeCoordinateFrame();
  /*! Set probe coordinate frame name */
  void SetProbeCoordinateFrame(const char* aProbeCoordinateFrame);

  /*! Get reference coordinate frame name */
  std::string GetReferenceCoordinateFrame();
  /*! Set reference coordinate frame name */
  void SetReferenceCoordinateFrame(const char* aReferenceCoordinateFrame);

  /*! Get transducer origin coordinate frame name */
  std::string GetTransducerOriginCoordinateFrame();
  /*! Set transducer origin coordinate frame name */
  void SetTransducerOriginCoordinateFrame(const char* aTransducerOriginCoordinateFrame);

  /*! Get transducer origin pixel coordinate frame name */
  std::string GetTransducerOriginPixelCoordinateFrame();
  /*! Set transducer origin pixel coordinate frame name */
  void SetTransducerOriginPixelCoordinateFrame(const char* aTransducerOriginPixelCoordinateFrame);

  /*! Get phantom model id */
  const char* GetPhantomModelId();
  /*! Set phantom model id */
  void SetPhantomModelId(const char* aObjectId);
  /*! Enable/disable the show phantom model action */
  void EnableShowPhantomModelToggle(bool aEnable);
  /*! Get phantom wires model id */
  const char* GetPhantomWiresModelId();
  /*! Set phantom wires model id */
  void SetPhantomWiresModelId(const char* aObjectId);
  /*! Enable/disable the show phantom wires action */
  void EnableShowPhantomWiresModelToggle(bool aEnable);

  /*! Get stylus model id */
  const char* GetStylusModelId();
  /*! Set stylus model id */
  void SetStylusModelId(const char* aObjectId);

  /*! Get probe object id */
  const char* GetTransducerModelId();
  /*! Set probe object id */
  void SetTransducerModelId(const char* aObjectId);

  /*! Get image object id */
  const char* GetImageObjectId();
  /*! Set image object id */
  void SetImageObjectId(const char* aObjectId);

  /*! Get force show devices status */
  bool IsForceShowDevicesEnabled();

  /*! Reset show devices toggle button (on disconnect from devices) */
  void ResetShowDevices();

  /*! Dynamically build the devices menu based on the values returned from the data collector */
  void BuildChannelMenu();

  /*! Accessors for selected channel functionality */
  void SetSelectedChannel(vtkPlusChannel* aChannel);
  vtkPlusChannel* GetSelectedChannel();

  /* Control the behaviour of the status icon */
  void SetStatusIconMaxMessageCount(int count);

protected:
  /*!
  * Create toolboxes
  */
  void CreateToolboxes();

  /*!
  * Set up status bar (label and progress)
  */
  void SetupStatusBar();

  /*!
  * Filters events if this object has been installed as an event filter for the watched object
  * \param obj object
  * \param ev event
  * \return if you want to filter the event out, i.e. stop it being handled further, return true; otherwise return false
  */
  bool eventFilter(QObject* obj, QEvent* ev);

protected slots:
  /*!
  * Handle tab change
  * \param aToolboxIndex Index of the currently active toolbox
  */
  void CurrentToolboxChanged(int aToolboxIndex);

  /*!
  * Changes tab back to the locked one if tabbing is disabled
  * \param Mandatory but unused argument to match the signal
  */
  void ChangeBackToolbox(int);

  /*!
  * Updates every part of the GUI (called by ui refresh timer)
  */
  void UpdateGUI();

  /*!
  * Update the slicer number UI based on channel data
  */
  void UpdateSliceNumberUI();

  /*!
  * Slot handling show devices combobox state change
  */
  void ShowDevicesToggled();

  /*!
  * Slot handling show phantom
  */
  void ShowPhantomModelToggled();

  /*!
  * Slot handling show phantom wires
  */
  void ShowPhantomWiresModelToggled();

  /*!
  * Activate a certain device
  */
  void ChannelSelected(vtkPlusChannel* aChannel);

  /*!
  * Update the requested slice number
  */
  void SliceNumberSliderChanged(int number);

  /*!
  * Update the requested slice number
  */
  void SliceNumberSpinBoxChanged(int number);

  /*!
  * Resize event handler
  * \param aEvent Resize event
  */
  virtual void resizeEvent(QResizeEvent* aEvent);

  /*! Save buffers into files */
  void DumpBuffers();

  /*! Save current device set configuration */
  void SaveDeviceSetConfiguration();

  /*! Functions to set orientation of the 2D image */
  void SetOrientationMRightFUp();
  void SetOrientationMLeftFUp();
  void SetOrientationMRightFDown();
  void SetOrientationMLeftFDown();
  void EnableOrientationMarkers();
  void EnableROI();

protected:
  /*! Object visualizer */
  vtkPlusVisualizationController*     m_VisualizationController;

  /*! Label on the left of the statusbar */
  QLabel*                             m_StatusBarLabel;

  /*! Progress bar on the right of the statusbar */
  QProgressBar*                       m_StatusBarProgress;

  /*! Index of locked (current) tab if tabbing is disabled */
  int                                 m_LockedTabIndex;

  /*! Active toolbox identifier */
  ToolboxType                         m_ActiveToolbox;

  /*! Timer that refreshes the UI */
  QTimer*                             m_UiRefreshTimer;

  /*! Status icon instance */
  QPlusStatusIcon*                    m_StatusIcon;

  /*! List of toolbox objects (the indices are the type identifiers) */
  std::vector<QAbstractToolbox*>      m_ToolboxList;

  /*! Image coordinate frame name for Volume reconstruction */
  std::string                         m_ImageCoordinateFrame;

  /*! Probe coordinate frame name for Capturing */
  std::string                         m_ProbeCoordinateFrame;

  /*! Reference coordinate frame name for Capturing */
  std::string                         m_ReferenceCoordinateFrame;

  /*! Transducer origin (mm) coordinate frame name for Rendering */
  std::string                         m_TransducerOriginCoordinateFrame;

  /*! Transducer origin (pixel) coordinate frame name for Rendering */
  std::string                         m_TransducerOriginPixelCoordinateFrame;

  /*! phantom frame object ID for Rendering */
  std::string                         m_PhantomModelId;

  /*! phantom wires object ID for Rendering */
  std::string                         m_PhantomWiresModelId;

  /*! stylus object ID for Rendering */
  std::string                         m_StylusModelId;

  /*! transducer object ID for Rendering */
  std::string                         m_TransducerModelId;

  /*! image object ID for Rendering */
  std::string                         m_ImageObjectId;

  /*! Turn on/off showing input and result points in 3D canvas when show devices is on */
  bool                                m_ShowPoints;

  /*! Force display mode from toolbox default to show all devices */
  bool                                m_ForceShowAllDevicesIn3D;

  /*! Keep a reference to this action because we'll need to reference its state */
  QPlusChannelAction*                      m_ShowOrientationMarkerAction;

  /*! Keep a reference to this action because we'll need to reference its state */
  QPlusChannelAction*                      m_ShowROIAction;

  /*! Reference to all actions that will show up in ROI list */
  std::vector<QPlusChannelAction*>         m_ImageManipulationActionList;

  /*! Reference to the switch mode button */
  QPlusChannelAction*                      m_Show3DObjectsAction;

  /*! Reference to the show phantom action */
  QPlusChannelAction*                      m_ShowPhantomModelAction;

  /*! Reference to the show phantom wires action */
  QPlusChannelAction*                      m_ShowPhantomWiresModelAction;

  /*! Reference to all actions that will show up in ROI list */
  std::vector<QPlusChannelAction*>         m_3DActionList;

  /*! Selected channel */
  vtkPlusChannel*                     m_SelectedChannel;

private:
  Ui::fCalMainWindow ui;
};

#endif // FCALMAINWINDOW_H
