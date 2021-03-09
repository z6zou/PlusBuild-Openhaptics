# Install script for directory: C:/Project/PlusB-bin/vtk/Filters/Modeling

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkFiltersModeling-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkFiltersModeling-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkFiltersModeling-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkFiltersModeling-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkFiltersModeling-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkFiltersModeling-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkFiltersModeling-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkFiltersModeling-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Filters/Modeling/CMakeFiles/vtkFiltersModeling.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkAdaptiveSubdivisionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkBandedPolyDataContourFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkButterflySubdivisionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkContourLoopExtraction.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkCookieCutter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkDijkstraGraphGeodesicPath.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkDijkstraImageGeodesicPath.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkFitToHeightMapFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkFillHolesFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkGeodesicPath.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkGraphGeodesicPath.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkLinearExtrusionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkLinearSubdivisionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkLoopSubdivisionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkOutlineFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkPolyDataPointSampler.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkProjectedTexture.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkQuadRotationalExtrusionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkRibbonFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkRotationalExtrusionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkRuledSurfaceFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkSectorSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkSelectEnclosedPoints.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkSelectPolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkSpherePuzzleArrows.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkSpherePuzzle.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkSubdivideTetra.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkTrimmedExtrusionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Modeling/vtkVolumeOfRevolutionFilter.h"
    "C:/Project/PlusB-bin/vtk-bin/Filters/Modeling/vtkFiltersModelingModule.h"
    )
endif()

