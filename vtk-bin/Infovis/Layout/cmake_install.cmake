# Install script for directory: C:/Project/PlusB-bin/vtk/Infovis/Layout

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkInfovisLayout-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkInfovisLayout-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkInfovisLayout-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkInfovisLayout-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkInfovisLayout-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkInfovisLayout-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkInfovisLayout-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkInfovisLayout-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Infovis/Layout/CMakeFiles/vtkInfovisLayout.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkArcParallelEdgeStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkAreaLayout.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkAreaLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkAssignCoordinates.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkAssignCoordinatesLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkAttributeClustering2DLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkBoxLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkCirclePackFrontChainLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkCirclePackLayout.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkCirclePackLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkCirclePackToPolyData.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkCircularLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkClustering2DLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkCommunity2DLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkConeLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkConstrained2DLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkCosmicTreeLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkEdgeLayout.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkEdgeLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkFast2DLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkForceDirectedLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkGeoEdgeStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkGeoMath.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkGraphLayout.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkGraphLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkIncrementalForceLayout.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkPassThroughEdgeStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkPassThroughLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkPerturbCoincidentVertices.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkRandomLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkSimple2DLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkSimple3DCirclesStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkSliceAndDiceLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkSpanTreeLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkSplineGraphEdges.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkSquarifyLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkStackedTreeLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkTreeLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkTreeMapLayout.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkTreeMapLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkTreeMapToPolyData.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkTreeOrbitLayoutStrategy.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkTreeRingToPolyData.h"
    "C:/Project/PlusB-bin/vtk/Infovis/Layout/vtkKCoreLayout.h"
    "C:/Project/PlusB-bin/vtk-bin/Infovis/Layout/vtkInfovisLayoutModule.h"
    )
endif()

