# Install script for directory: C:/Project/PlusB-bin/vtk/Filters/Hybrid

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkFiltersHybrid-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkFiltersHybrid-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkFiltersHybrid-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkFiltersHybrid-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkFiltersHybrid-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkFiltersHybrid-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkFiltersHybrid-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkFiltersHybrid-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Filters/Hybrid/CMakeFiles/vtkFiltersHybrid.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkAdaptiveDataSetSurfaceFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkBSplineTransform.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkDepthSortPolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkDSPFilterDefinition.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkDSPFilterGroup.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkEarthSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkFacetReader.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkForceTime.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkGreedyTerrainDecimation.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkGridTransform.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkImageToPolyDataFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkImplicitModeller.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkPCAAnalysisFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkPolyDataSilhouette.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkProcrustesAlignmentFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkProjectedTerrainPath.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkRenderLargeImage.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkTemporalArrayOperatorFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkTemporalDataSetCache.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkTemporalFractal.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkTemporalInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkTemporalShiftScale.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkTemporalSnapToTimeStep.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkTransformToGrid.h"
    "C:/Project/PlusB-bin/vtk/Filters/Hybrid/vtkWeightedTransformFilter.h"
    "C:/Project/PlusB-bin/vtk-bin/Filters/Hybrid/vtkFiltersHybridModule.h"
    )
endif()

