# Install script for directory: C:/Project/PlusB-bin/vtk/Geovis/Core

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkGeovisCore-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkGeovisCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkGeovisCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkGeovisCore-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkGeovisCore-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkGeovisCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkGeovisCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkGeovisCore-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Geovis/Core/CMakeFiles/vtkGeovisCore.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoAdaptiveArcs.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoAlignedImageRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoAlignedImageSource.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoArcs.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoAssignCoordinates.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoCamera.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoFileImageSource.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoFileTerrainSource.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoGlobeSource.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoGraticule.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoImageNode.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoInteractorStyle.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoProjectionSource.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoRandomGraphSource.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoSampleArcs.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoSource.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoSphereTransform.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoTerrain.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoTerrain2D.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoTerrainNode.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoTreeNode.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoTreeNodeCache.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGlobeSource.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkCompassRepresentation.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkCompassWidget.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoProjection.h"
    "C:/Project/PlusB-bin/vtk/Geovis/Core/vtkGeoTransform.h"
    "C:/Project/PlusB-bin/vtk-bin/Geovis/Core/vtkGeovisCoreModule.h"
    )
endif()

