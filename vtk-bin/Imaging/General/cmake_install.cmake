# Install script for directory: C:/Project/PlusB-bin/vtk/Imaging/General

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkImagingGeneral-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkImagingGeneral-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkImagingGeneral-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkImagingGeneral-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkImagingGeneral-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkImagingGeneral-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkImagingGeneral-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkImagingGeneral-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Imaging/General/CMakeFiles/vtkImagingGeneral.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageAnisotropicDiffusion2D.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageAnisotropicDiffusion3D.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageCheckerboard.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageCityBlockDistance.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageConvolve.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageCorrelation.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageEuclideanDistance.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageEuclideanToPolar.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageGaussianSmooth.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageGradient.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageGradientMagnitude.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageHybridMedian2D.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageLaplacian.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageMedian3D.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageNormalize.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageRange3D.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageSeparableConvolution.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageSobel2D.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageSobel3D.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageSpatialAlgorithm.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageVariance3D.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkSimpleImageFilterExample.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageSlab.h"
    "C:/Project/PlusB-bin/vtk/Imaging/General/vtkImageSlabReslice.h"
    "C:/Project/PlusB-bin/vtk-bin/Imaging/General/vtkImagingGeneralModule.h"
    )
endif()

