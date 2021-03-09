# Install script for directory: C:/Project/PlusB-bin/vtk/Infovis/Core

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkInfovisCore-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkInfovisCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkInfovisCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkInfovisCore-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkInfovisCore-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkInfovisCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkInfovisCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkInfovisCore-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Infovis/Core/CMakeFiles/vtkInfovisCore.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkAddMembershipArray.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkAdjacencyMatrixToEdgeTable.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkArrayNorm.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkArrayToTable.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkCollapseGraph.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkCollapseVerticesByArray.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkContinuousScatterplot.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkDataObjectToTable.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkDotProductSimilarity.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkExtractSelectedTree.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkEdgeCenters.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkExpandSelectedGraph.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkExtractSelectedGraph.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkGenerateIndexArray.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkGraphHierarchicalBundleEdges.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkGroupLeafVertices.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkMergeColumns.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkMergeGraphs.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkMergeTables.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkMutableGraphHelper.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkNetworkHierarchy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkPipelineGraphSource.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkPruneTreeFilter.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkRandomGraphSource.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkReduceTable.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkRemoveIsolatedVertices.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkSparseArrayToTable.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkStreamGraph.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkStringToCategory.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkStringToNumeric.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkTableToArray.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkTableToGraph.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkTableToSparseArray.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkTableToTreeFilter.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkThresholdGraph.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkThresholdTable.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkTransferAttributes.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkTransposeMatrix.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkTreeFieldAggregator.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkTreeDifferenceFilter.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkTreeLevelsFilter.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkVertexDegree.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkRemoveHiddenData.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Core/vtkKCoreDecomposition.h"
    "C:/Project/PlusB-bin/vtk-bin/Infovis/Core/vtkInfovisCoreModule.h"
    )
endif()

