# Install script for directory: C:/Project/PlusB-bin/vtk/Filters/Points

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkFiltersPoints-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkFiltersPoints-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkFiltersPoints-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkFiltersPoints-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkFiltersPoints-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkFiltersPoints-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkFiltersPoints-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkFiltersPoints-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Filters/Points/CMakeFiles/vtkFiltersPoints.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkBoundedPointSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkConnectedPointsFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkDensifyPointCloudFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkEllipsoidalGaussianKernel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkEuclideanClusterExtraction.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkExtractHierarchicalBins.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkExtractEnclosedPoints.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkExtractPointCloudPiece.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkExtractPoints.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkExtractSurface.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkFitImplicitFunction.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkGaussianKernel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkGeneralizedKernel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkHierarchicalBinningFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkInterpolationKernel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkLinearKernel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkMaskPointsFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkPCACurvatureEstimation.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkPCANormalEstimation.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkPointCloudFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkPointDensityFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkPointInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkPointInterpolator2D.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkPointOccupancyFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkProbabilisticVoronoiKernel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkRadiusOutlierRemoval.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkSPHInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkSPHCubicKernel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkSPHKernel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkSPHQuarticKernel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkSPHQuinticKernel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkShepardKernel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkSignedDistance.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkStatisticalOutlierRemoval.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkUnsignedDistance.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkVoxelGrid.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkVoronoiKernel.h"
    "C:/Project/PlusB-bin/vtk/Filters/Points/vtkWendlandQuinticKernel.h"
    "C:/Project/PlusB-bin/vtk-bin/Filters/Points/vtkFiltersPointsModule.h"
    )
endif()

