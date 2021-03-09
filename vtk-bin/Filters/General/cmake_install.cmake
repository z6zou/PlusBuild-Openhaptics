# Install script for directory: C:/Project/PlusB-bin/vtk/Filters/General

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkFiltersGeneral-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkFiltersGeneral-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkFiltersGeneral-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkFiltersGeneral-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkFiltersGeneral-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkFiltersGeneral-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkFiltersGeneral-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkFiltersGeneral-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Filters/General/CMakeFiles/vtkFiltersGeneral.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkAnnotationLink.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkAppendPoints.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkApproximatingSubdivisionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkAreaContourSpectrumFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkAxes.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkBlankStructuredGrid.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkBlankStructuredGridWithImage.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkBlockIdScalars.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkBoxClipDataSet.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkBrownianPoints.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkCellCenters.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkCellDerivatives.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkCellValidator.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkClipClosedSurface.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkClipConvexPolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkClipDataSet.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkClipVolume.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkCoincidentPoints.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkContourTriangulator.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkCountFaces.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkCountVertices.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkCursor2D.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkCursor3D.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkCurvatures.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkDataSetGradient.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkDataSetGradientPrecompute.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkDataSetTriangleFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkDeformPointSet.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkDensifyPolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkDicer.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkDiscreteFlyingEdges2D.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkDiscreteFlyingEdges3D.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkDiscreteFlyingEdgesClipper2D.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkDiscreteMarchingCubes.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkEdgePoints.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkExtractSelectedFrustum.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkExtractSelectionBase.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkGradientFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkGraphLayoutFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkGraphToPoints.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkHierarchicalDataLevelFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkHyperStreamline.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkIconGlyphFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkImageMarchingCubes.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkInterpolateDataSetAttributes.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkInterpolatingSubdivisionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkLevelIdScalars.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkLinkEdgels.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkMergeCells.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkMultiBlockDataGroupFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkMultiBlockFromTimeSeriesFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkMultiBlockMergeFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkMultiThreshold.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkOBBDicer.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkOBBTree.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkPassThrough.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkPointConnectivityFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkPolyDataStreamer.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkPolyDataToReebGraphFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkProbePolyhedron.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkQuadraturePointInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkQuadraturePointsGenerator.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkQuadratureSchemeDictionaryGenerator.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkQuantizePolyDataPoints.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkRandomAttributeGenerator.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkRectilinearGridClip.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkRectilinearGridToTetrahedra.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkRecursiveDividingCubes.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkReflectionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkRotationFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkSampleImplicitFunctionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkShrinkFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkShrinkPolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkSpatialRepresentationFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkSplineFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkSplitByCellScalarFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkSplitField.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkStructuredGridClip.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkSubdivisionFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkSubPixelPositionEdgels.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkSynchronizeTimeFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkTableBasedClipDataSet.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkTableToPolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkTableToStructuredGrid.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkTemporalPathLineFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkTemporalStatistics.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkTessellatorFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkTimeSourceExample.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkTransformFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkTransformPolyDataFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkUncertaintyTubeFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkVertexGlyphFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkVolumeContourSpectrumFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkVoxelContoursToSurfaceFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkWarpLens.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkWarpScalar.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkWarpTo.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkWarpVector.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkYoungsMaterialInterface.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkMarchingContourFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkRectilinearGridToPointSet.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkGraphWeightEuclideanDistanceFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkGraphWeightFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkImageDataToPointSet.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkIntersectionPolyDataFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkBooleanOperationPolyDataFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkLoopBooleanPolyDataFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkDistancePolyDataFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkOverlappingAMRLevelIdScalars.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkExtractArray.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkMatricizeArray.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkNormalizeMatrixVectors.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkPassArrays.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkSplitColumnComponents.h"
    "C:/Project/PlusB-bin/vtk/Filters/General/vtkCellTreeLocator.h"
    "C:/Project/PlusB-bin/vtk-bin/Filters/General/vtkFiltersGeneralModule.h"
    )
endif()

