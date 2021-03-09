# Install script for directory: C:/Project/PlusB-bin/vtk/Rendering/Annotation

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkRenderingAnnotation-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkRenderingAnnotation-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkRenderingAnnotation-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkRenderingAnnotation-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkRenderingAnnotation-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkRenderingAnnotation-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkRenderingAnnotation-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkRenderingAnnotation-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Rendering/Annotation/CMakeFiles/vtkRenderingAnnotation.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkScalarBarActorInternal.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkAnnotatedCubeActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkArcPlotter.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkAxesActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkAxisActor2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkAxisActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkAxisFollower.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkBarChartActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkCaptionActor2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkConvexHull2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkCornerAnnotation.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkCubeAxesActor2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkCubeAxesActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkGraphAnnotationLayersFilter.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkLeaderActor2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkLegendBoxActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkLegendScaleActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkParallelCoordinatesActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkPieChartActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkPolarAxesActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkProp3DAxisFollower.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkScalarBarActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkSpiderPlotActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Annotation/vtkXYPlotActor.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/Annotation/vtkRenderingAnnotationModule.h"
    )
endif()

