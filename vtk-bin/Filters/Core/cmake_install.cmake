# Install script for directory: C:/Project/PlusB-bin/vtk/Filters/Core

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkFiltersCore-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkFiltersCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkFiltersCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkFiltersCore-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkFiltersCore-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkFiltersCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkFiltersCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkFiltersCore-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Filters/Core/CMakeFiles/vtkFiltersCore.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkAppendArcLength.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkAppendFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkAppendPolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkAppendSelection.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkArrayCalculator.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkAssignAttribute.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkAttributeDataToFieldDataFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkBinCellDataFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkCellDataToPointData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkCleanPolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkClipPolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkCompositeDataProbeFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkConnectivityFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkContourFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkContourGrid.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkContourHelper.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkContour3DLinearGrid.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkDataObjectGenerator.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkDataObjectToDataSetFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkDataSetEdgeSubdivisionCriterion.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkDataSetToDataObjectFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkDecimatePolylineFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkDecimatePro.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkDelaunay2D.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkDelaunay3D.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkElevationFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkExecutionTimer.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkFeatureEdges.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkFieldDataToAttributeDataFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkFlyingEdges2D.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkFlyingEdges3D.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkFlyingEdgesPlaneCutter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkGlyph2D.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkGlyph3D.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkHedgeHog.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkHull.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkIdFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkMarchingCubes.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkMarchingSquares.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkMaskFields.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkMaskPoints.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkMaskPolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkMassProperties.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkMergeDataObjectFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkMergeFields.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkMergeFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkMoleculeAppend.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkMultiObjectMassProperties.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkPlaneCutter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkPointDataToCellData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkPolyDataConnectivityFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkPolyDataNormals.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkProbeFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkQuadricClustering.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkQuadricDecimation.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkRearrangeFields.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkRemoveDuplicatePolys.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkResampleToImage.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkResampleWithDataSet.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkReverseSense.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkSimpleElevationFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkSmoothPolyDataFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkSphereTreeFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkStaticCleanPolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkStripper.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkStructuredGridOutlineFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkSynchronizedTemplates2D.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkSynchronizedTemplates3D.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkSynchronizedTemplatesCutter3D.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkTensorGlyph.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkThreshold.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkThresholdPoints.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkTransposeTable.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkTriangleFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkTriangleMeshPointNormals.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkTubeFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkUnstructuredGridQuadricDecimation.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkVectorDot.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkVectorNorm.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkVoronoi2D.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkWindowedSincPolyDataFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkCutter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkCompositeCutter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkGridSynchronizedTemplates3D.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkRectilinearSynchronizedTemplates.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkEdgeSubdivisionCriterion.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkStreamingTessellator.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkImplicitPolyDataDistance.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkStreamerBase.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkCenterOfMass.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkImageAppend.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkStructuredGridAppend.h"
    "C:/Project/PlusB-bin/vtk/Filters/Core/vtkAppendCompositeDataLeaves.h"
    "C:/Project/PlusB-bin/vtk-bin/Filters/Core/vtkFiltersCoreModule.h"
    )
endif()

