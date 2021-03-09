# Install script for directory: C:/Project/PlusB-bin/vtk/Filters/Extraction

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkFiltersExtraction-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkFiltersExtraction-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkFiltersExtraction-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkFiltersExtraction-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkFiltersExtraction-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkFiltersExtraction-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkFiltersExtraction-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkFiltersExtraction-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Filters/Extraction/CMakeFiles/vtkFiltersExtraction.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkBlockSelector.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkConvertSelection.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractBlock.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractCells.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractDataArraysOverTime.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractDataOverTime.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractDataSets.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractEdges.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractGeometry.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractGrid.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractLevel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractPolyDataGeometry.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractRectilinearGrid.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractSelectedArraysOverTime.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractSelectedBlock.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractSelectedIds.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractSelectedLocations.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractSelectedPolyDataIds.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractSelectedRows.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractSelectedThresholds.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractSelection.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractTemporalFieldData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractTensorComponents.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractTimeSteps.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractUnstructuredGrid.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractVectorComponents.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkFrustumSelector.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkHierarchicalDataExtractDataSets.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkHierarchicalDataExtractLevel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkLocationSelector.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkProbeSelectedLocations.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkSelector.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkValueSelector.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractArraysOverTime.h"
    "C:/Project/PlusB-bin/vtk/Filters/Extraction/vtkExtractSelectionLegacy.h"
    "C:/Project/PlusB-bin/vtk-bin/Filters/Extraction/vtkFiltersExtractionModule.h"
    )
endif()

