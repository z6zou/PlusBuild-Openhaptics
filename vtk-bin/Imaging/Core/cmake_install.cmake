# Install script for directory: C:/Project/PlusB-bin/vtk/Imaging/Core

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkImagingCore-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkImagingCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkImagingCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkImagingCore-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkImagingCore-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkImagingCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkImagingCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkImagingCore-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Imaging/Core/CMakeFiles/vtkImagingCore.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkExtractVOI.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageAppendComponents.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageBlend.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageCacheFilter.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageCast.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageChangeInformation.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageClip.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageConstantPad.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageDataStreamer.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageDecomposeFilter.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageDifference.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageExtractComponents.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageFlip.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageIterateFilter.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageMagnify.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageMapToColors.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageMask.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageMirrorPad.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImagePadFilter.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImagePermute.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImagePointDataIterator.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImagePointIterator.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageResample.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageReslice.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageResliceToColors.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageShiftScale.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageShrink3D.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageStencilIterator.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageThreshold.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageTranslateExtent.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageWrapPad.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkRTAnalyticSource.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageResize.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageBSplineCoefficients.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageStencilData.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageStencilAlgorithm.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkAbstractImageInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageBSplineInternals.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageBSplineInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageSincInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Imaging/Core/vtkImageStencilSource.h"
    "C:/Project/PlusB-bin/vtk-bin/Imaging/Core/vtkImagingCoreModule.h"
    )
endif()

