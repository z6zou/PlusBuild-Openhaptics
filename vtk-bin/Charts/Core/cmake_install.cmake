# Install script for directory: C:/Project/PlusB-bin/vtk/Charts/Core

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkChartsCore-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkChartsCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkChartsCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkChartsCore-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkChartsCore-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkChartsCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkChartsCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkChartsCore-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Charts/Core/CMakeFiles/vtkChartsCore.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkAxis.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkAxisExtended.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkCategoryLegend.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkChart.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkChartBox.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkChartHistogram2D.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkChartLegend.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkChartMatrix.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkChartParallelCoordinates.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkChartPie.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkChartXY.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkChartXYZ.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkColorLegend.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkColorTransferControlPointsItem.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkColorTransferFunctionItem.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkCompositeControlPointsItem.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkCompositeTransferFunctionItem.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkContextArea.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkContextPolygon.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkControlPointsItem.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkInteractiveArea.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkLookupTableItem.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPiecewiseControlPointsItem.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPiecewiseFunctionItem.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPiecewisePointHandleItem.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlot.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlot3D.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotArea.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotBag.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotBar.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotBox.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotFunctionalBag.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotGrid.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotHistogram2D.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotLine.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotLine3D.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotParallelCoordinates.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotPie.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotPoints.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotPoints3D.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotStacked.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkPlotSurface.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkScalarsToColorsItem.h"
    "C:/Project/PlusB-bin/vtk/Charts/Core/vtkScatterPlotMatrix.h"
    "C:/Project/PlusB-bin/vtk-bin/Charts/Core/vtkChartsCoreModule.h"
    )
endif()

