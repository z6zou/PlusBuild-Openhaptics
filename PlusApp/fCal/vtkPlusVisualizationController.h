/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __vtkVisualizationController_h
#define __vtkVisualizationController_h

// PlusLib includes
#include <PlusConfigure.h>
#include <PlusCommon.h>
#include <PlusVideoFrame.h>
#include <vtkPlusDataCollector.h>
#include <vtkPlusTransformRepository.h>

// Qt includes
#include <QObject>
#include <QTimer>

// VTK includes
#include <QVTKWidget.h>

class vtkPlusImageVisualizer;
class vtkPlus3DObjectVisualizer;
class vtkPlusDisplayableObject;

class vtkImageActor;
class vtkMatrix4x4;
class vtkPolyData;
class vtkPolyDataMapper;
class vtkRenderer;
class vtkSTLReader;
class vtkTransform;
class vtkXMLDataElement;

class QResizeEvent;

/*! \class vtkPlusVisualizationController
\brief Class that is responsible for managing a connection with tracked data and managing the visualization of said data

Usage: Instantiate, set the QVTKCanvas that is to be managed by this visualizer the call Initialize function. Updating the visualization is done by attaching Update() to a QTimer (self-managed).
Before calling this, force the data collector to provide new data by calling GetDataCollector()->Modified() function.

It has three modes, DISPLAY_MODE_2D, DISPLAY_MODE_3D and DISPLAY_MODE_NONE. In DISPLAY_MODE_2D it shows only the video input in the whole window. In DISPLAY_MODE_3D, all the devices and
the image is visible (that are defined in the device set configuration file's Rendering element). In DISPLAY_MODE_NONE the canvas is hidden and all renderers are detached.

Devices and objects can be shown and hidden (HideAll(), ShowAllObjects(), ShowObjectsByCoordinateFrame(), ShowInput(), ShowResult()). Internally, this class forwards these requests to the underlying visualization classes.

\ingroup PlusAppCommonWidgets
*/
class vtkPlusVisualizationController : public QObject, public vtkObject
{
  Q_OBJECT

public:
  enum DISPLAY_MODE
  {
    DISPLAY_MODE_2D,
    DISPLAY_MODE_3D,
    DISPLAY_MODE_NONE
  };

  /*! New */
  static vtkPlusVisualizationController* New();

  /*! Start data collection */
  PlusStatus StartDataCollection();

  /* Stop data collection and disconnect collector */
  PlusStatus StopAndDisconnectDataCollector();

  /*!
  * Hide all tools, other models and the image from main canvas
  */
  PlusStatus HideAll();

  /*! Hide the renderer */
  PlusStatus HideRenderer();

  /*!
  * Forward the request to the 3D visualizer
  * \param aOn Show if true, else hide
  */
  PlusStatus ShowInput(bool aOn);

  /*!
  * Show or hide result points
  * \param aOn Show if true, else hide
  */
  PlusStatus ShowResult(bool aOn);

  /*!
  * Forward the ShowObjectById request to the 3D visualizer
  * \param aModelId Model ID to operate on
  * \param aOn Show if true, else hide
  */
  PlusStatus ShowObjectById(const char* aModelId, bool aOn);

  /*!
  * Forward the AddObject request to the 3D visualizer
  * \param aObject the object to be added. Must have a valid actor.
  */
  PlusStatus AddObject(vtkPlusDisplayableObject* aObject);

  /*!
  * Forward the GetObjectById request to the 3D visualizer
  * \param aModelId Model ID to operate on
  */
  vtkPlusDisplayableObject* GetObjectById(const char* aId);

  /*!
  * Forward the ShowAllObjects request to the 3D visualizer
  * \param aShow Show if true, else hide
  */
  PlusStatus ShowAllObjects(bool aShow);

  /*!
  * Enable/disable image mode
  * \param aOn Image mode flag - true: show only the image and interactions are off - false: show all toola and the image and interactions are on
  */
  PlusStatus SetVisualizationMode(DISPLAY_MODE aMode);

  /*!
  * Show or hide the MF orientation markers
  * \param aEnable Show/Hide
  */
  PlusStatus ShowOrientationMarkers(bool aShow);

  /*!
  * Dump video and tracker buffers to a given directory
  * \param aDirectory Destination directory
  */
  PlusStatus DumpBuffersToDirectory(const char* aDirectory);

  /*!
  * Return acquisition timer (to be able to connect actions to it)
  * \return Acquisition timer object
  */
  QTimer& GetAcquisitionTimer()
  {
    return this->AcquisitionTimer;
  };

  /*!
  Acquire transform matrix from tracking and provide string containing the translation part
  /param aTransformTranslationString Out parameter for the position string
  /param aValid True if the transform is valid, false otherwise (optional parameter)
  */
  PlusStatus GetTransformTranslationString(const char* aTransformFrom, const char* aTransformTo, std::string& aTransformTranslationString, ToolStatus* aStatus = NULL);
  /*!
  Acquire transform matrix from tracking and provide string containing the translation part
  /param aTransformTranslationString Out parameter for the position string
  /param aValid True if the transform is valid, false otherwise (optional parameter)
  */
  PlusStatus GetTransformTranslationString(PlusTransformName aTransform, std::string& aTransformTranslationString, ToolStatus* aStatus = NULL);

  /*!
  Acquire transform matrix from tracking
  /param aOutputMatrix Out parameter for the transform matrix
  /param aValid True if the transform is valid, false otherwise (optional parameter)
  */
  PlusStatus GetTransformMatrix(const char* aTransformFrom, const char* aTransformTo, vtkMatrix4x4* aOutputMatrix, ToolStatus* aStatus = NULL);
  /*!
  Acquire transform matrix from tracking
  /param aOutputMatrix Out parameter for the transform matrix
  /param aValid True if the transform is valid, false otherwise (optional parameter)
  */
  PlusStatus GetTransformMatrix(PlusTransformName aTransform, vtkMatrix4x4* aOutputMatrix, ToolStatus* aStatus = NULL);

  /*!
  Check if a transform exists in transform repository
  /param aUseLatestTrackedFrame Get latest tracked frame and set its transforms to transform repository before checking
  */
  PlusStatus IsExistingTransform(const char* aTransformFrom, const char* aTransformTo, bool aUseLatestTrackedFrame = true);

  /*! Function to handle resize events */
  void resizeEvent(QResizeEvent* aEvent);

  /*!
  * Set MF orientation in 2D mode
  * \param aNewOrientation The new MF orientation
  */
  PlusStatus SetScreenRightDownAxesOrientation(US_IMAGE_ORIENTATION aOrientation = US_IMG_ORIENT_MF);

  /*!
  * Read from the active configuration to initialize any config based data dependency
  */
  PlusStatus ReadConfiguration(vtkXMLDataElement* aXMLElement);

  /*! Read clipping rectangle parameters from XML */
  PlusStatus ReadRoiConfiguration(vtkXMLDataElement* aXMLElement);

  /*!
  * Save the current device set configuration into XML
  */
  PlusStatus WriteConfiguration(vtkXMLDataElement* aXMLElement);

  /*!
  * Set the image visualizer ROI region
  * \param xMin min x bounds of ROI
  * \param xMax max x bounds of ROI
  * \param yMin min y bounds of ROI
  * \param yMax max y bounds of ROI
  */
  PlusStatus SetROIBounds(int xMin, int xMax, int yMin, int yMax);

  /*!
  * Enable/disable the image visualizer ROI visualization
  * \param aEnable enable/disable flag
  */
  PlusStatus EnableROI(bool aEnable);

  /*!
  * Pass the request to the image visualizer
  * \param aPointList x/y location for labels
  */
  PlusStatus SetWireLabelPositions(vtkPoints* aPointList);

  /*!
  * Enable/disable wire label visualization
  * \param aEnable enable/disable flag
  */
  PlusStatus EnableWireLabels(bool aEnable);

  /*!
  * Enable or disable the volume actor in 3D mode
  * \param aEnable enable/disable flag
  */
  PlusStatus EnableVolumeActor(bool aEnable);

  /*!
  * Set the volume actor mapper
  * \param aContourMapper new mapper to use
  */
  PlusStatus SetVolumeMapper(vtkPolyDataMapper* aContourMapper);

  /*!
  * Set the volume actor color
  * \param r red value
  * \param g green value
  * \param b blue value
  */
  PlusStatus SetVolumeColor(double r, double g, double b);

  /*!
  * Set the input actor color
  * \param r red value
  * \param g green value
  * \param b blue value
  */
  PlusStatus SetInputColor(double r, double g, double b);

  /*! Disconnect the image input */
  PlusStatus DisconnectInput();

  /*! Connect the image input to the DataCollector output */
  PlusStatus ConnectInput();

  /*! Clear the transform repository */
  PlusStatus ClearTransformRepository();

  /*! Reset the visualization */
  PlusStatus Reset();

  /*! Set the selected channel */
  void SetSelectedChannel(vtkPlusChannel* aChannel);
  vtkPlusChannel* GetSelectedChannel();

  /*! Set the slice number in the image visualizer */
  void SetSliceNumber(int number);

  /*! Set the location of the line actor for the line segmentation result */
  void SetLineSegmentationPoints(double startPoint_Image[2], double endPoint_Image[2]);

  /*! toggle visibility of the line actor for the line segmentation result */
  void SetLineSegmentationVisible(bool _arg);

  void SetCanvas(QVTKWidget* canvas);

  void ClearResultPolyData();
  void ClearInputPolyData();

  PlusStatus ResetCamera();

  void SetResultPolyDataPoints(vtkSmartPointer<vtkPoints> points);
  void SetInputPolyDataPoints(vtkSmartPointer<vtkPoints> points);
  vtkSmartPointer<vtkPoints> GetResultPolyDataPoints();
  vtkSmartPointer<vtkPoints> GetInputPolyDataPoints();

protected slots:
  /*!
  * Forward any updates to members that require it
  */
  PlusStatus Update();

public:
  // Set/Get macros for member variables
  PlusStatus SetAcquisitionFrameRate(int aFrameRate);
  vtkGetMacro(AcquisitionFrameRate, int);

  vtkGetObjectMacro(TransformRepository, vtkPlusTransformRepository);
  vtkGetObjectMacro(DataCollector, vtkPlusDataCollector);

  vtkRenderer* GetCanvasRenderer();

  bool Is2DMode();
  bool Is3DMode();

  void SetInputData(vtkImageData* input);

protected:
  vtkSetObjectMacro(TransformRepository, vtkPlusTransformRepository);
  vtkSetObjectMacro(DataCollector, vtkPlusDataCollector);

  vtkImageActor* GetImageActor();

  QVTKWidget* GetCanvas()
  {
    return Canvas;
  }

protected:
  /*!
  * Constructor
  */
  vtkPlusVisualizationController();

  /*!
  * Destructor
  */
  virtual ~vtkPlusVisualizationController();

protected:
  /*! 2D visualizer */
  vtkSmartPointer<vtkPlusImageVisualizer>     ImageVisualizer;
  /*! 3D visualizer */
  vtkSmartPointer<vtkPlus3DObjectVisualizer>  PerspectiveVisualizer;
  /*! Renderer to use when there is nothing to show */
  vtkSmartPointer<vtkRenderer>                BlankRenderer;
  /*! Timer for acquisition */
  QTimer                                      AcquisitionTimer;
  /*! Polydata holding the result points (eg. stylus tip, segmented points) */
  vtkSmartPointer<vtkPolyData>                ResultPolyData;
  vtkSmartPointer<vtkPoints>                  ResultPoints;
  /*! Polydata holding the input points */
  vtkSmartPointer<vtkPolyData>                InputPolyData;
  vtkSmartPointer<vtkPoints>                  InputPoints;
  /*! Flag indicating if the visualization is in image mode (show only the image and interactions are off) or device display mode (show all tools and the image and interactions are on) or none */
  DISPLAY_MODE                                CurrentMode;
  /*! Desired frame rate of synchronized recording */
  int                                         AcquisitionFrameRate;
  /// Cached variables from other systems
  QVTKWidget*                                 Canvas;
  vtkPlusTransformRepository*                 TransformRepository;
  vtkPlusChannel*                             SelectedChannel;
  vtkPlusDataCollector*                       DataCollector;
};

#endif  // __vtkVisualizationController_h
