# Install script for directory: C:/Project/PlusB-bin/vtk/Interaction/Widgets

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Project/PlusB-bin/vtk-int")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkInteractionWidgets-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkInteractionWidgets-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkInteractionWidgets-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkInteractionWidgets-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkInteractionWidgets-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkInteractionWidgets-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkInteractionWidgets-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkInteractionWidgets-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Interaction/Widgets/CMakeFiles/vtkInteractionWidgets.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtk3DWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkAbstractPolygonalHandleRepresentation3D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkAbstractWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkAffineRepresentation2D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkAffineRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkAffineWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkAngleRepresentation2D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkAngleRepresentation3D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkAngleRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkAngleWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkAxesTransformRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkAxesTransformWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkBalloonRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkBalloonWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkBezierContourLineInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkBiDimensionalRepresentation2D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkBiDimensionalRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkBiDimensionalWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkBorderRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkBorderWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkBoundedPlanePointPlacer.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkBoxRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkBoxWidget2.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkBoxWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkBrokenLineWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkButtonRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkButtonWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkCameraRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkCameraWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkCaptionRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkCaptionWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkCellCentersPointPlacer.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkCenteredSliderRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkCenteredSliderWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkCheckerboardRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkCheckerboardWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkClosedSurfacePointPlacer.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkConstrainedPointHandleRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkContinuousValueWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkContinuousValueWidgetRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkContourLineInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkContourRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkContourWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkCurveRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkDijkstraImageContourLineInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkDistanceRepresentation2D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkDistanceRepresentation3D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkDistanceRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkDistanceWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkEllipsoidTensorProbeRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkEvent.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkFinitePlaneRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkFinitePlaneWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkFixedSizeHandleRepresentation3D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkFocalPlaneContourRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkFocalPlanePointPlacer.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkHandleRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkHandleWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkHoverWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkImageActorPointPlacer.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkImageCroppingRegionsWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkImageOrthoPlanes.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkImagePlaneWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkImageTracerWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkImplicitCylinderRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkImplicitCylinderWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkImplicitPlaneRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkImplicitPlaneWidget2.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkImplicitPlaneWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkLinearContourLineInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkLineRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkLineWidget2.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkLineWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkLogoRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkLogoWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkMeasurementCubeHandleRepresentation3D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkOrientationMarkerWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkOrientedGlyphContourRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkOrientedGlyphFocalPlaneContourRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkOrientedPolygonalHandleRepresentation3D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkParallelopipedRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkParallelopipedWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPlaneWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPlaybackRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPlaybackWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPointHandleRepresentation2D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPointHandleRepresentation3D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPointPlacer.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPointWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPolyDataContourLineInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPolyDataPointPlacer.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPolyDataSourceWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPolyLineRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPolyLineWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPolygonalHandleRepresentation3D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPolygonalSurfaceContourLineInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkPolygonalSurfacePointPlacer.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkProgressBarRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkProgressBarWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkProp3DButtonRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkRectilinearWipeRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkRectilinearWipeWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkScalarBarRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkScalarBarWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkSeedRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkSeedWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkSliderRepresentation2D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkSliderRepresentation3D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkSliderRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkSliderWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkSphereHandleRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkSphereRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkSphereWidget2.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkSphereWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkSplineRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkSplineWidget2.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkSplineWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkTensorProbeRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkTensorProbeWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkTerrainContourLineInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkTerrainDataPointPlacer.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkTextRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkTexturedButtonRepresentation2D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkTexturedButtonRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkTextWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkWidgetCallbackMapper.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkWidgetEvent.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkWidgetEventTranslator.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkWidgetRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkWidgetSet.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkXYPlotWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkResliceCursorLineRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkResliceCursorRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkResliceCursorThickLineRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkResliceCursorWidget.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkResliceCursorActor.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkResliceCursorPicker.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkResliceCursor.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Widgets/vtkResliceCursorPolyDataAlgorithm.h"
    "C:/Project/PlusB-bin/vtk-bin/Interaction/Widgets/vtkInteractionWidgetsModule.h"
    )
endif()

