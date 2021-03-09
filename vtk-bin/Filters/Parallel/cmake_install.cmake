# Install script for directory: C:/Project/PlusB-bin/vtk/Filters/Parallel

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkFiltersParallel-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkFiltersParallel-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkFiltersParallel-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkFiltersParallel-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkFiltersParallel-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkFiltersParallel-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkFiltersParallel-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkFiltersParallel-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Filters/Parallel/CMakeFiles/vtkFiltersParallel.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkAggregateDataSetFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkAngularPeriodicFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkCollectGraph.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkCollectPolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkCollectTable.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkCutMaterial.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkDuplicatePolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkExtractCTHPart.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkExtractPolyDataPiece.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkExtractUnstructuredGridPiece.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkExtractUserDefinedPiece.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkIntegrateAttributes.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPassThroughFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPCellDataToPointData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPeriodicFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPExtractDataArraysOverTime.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPExtractSelectedArraysOverTime.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPieceRequestFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPieceScalars.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPipelineSize.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPKdTree.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPLinearExtrusionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPMaskPoints.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPOutlineCornerFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPOutlineFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPOutlineFilterInternals.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPPolyDataNormals.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPProbeFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPProjectSphereFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPReflectionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPResampleFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkProcessIdScalars.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPSphereSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPYoungsMaterialInterface.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkRectilinearGridOutlineFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkRemoveGhosts.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkTransmitPolyDataPiece.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkTransmitRectilinearGridPiece.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkTransmitStructuredDataPiece.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkTransmitStructuredGridPiece.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkTransmitUnstructuredGridPiece.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkUnstructuredGridGhostCellsGenerator.h"
    "C:/Project/PlusB-bin/vtk/Filters/Parallel/vtkPExtractArraysOverTime.h"
    "C:/Project/PlusB-bin/vtk-bin/Filters/Parallel/vtkFiltersParallelModule.h"
    )
endif()

