# Install script for directory: C:/Project/PlusB-bin/vtk/Rendering/Volume

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkRenderingVolume-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkRenderingVolume-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkRenderingVolume-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkRenderingVolume-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkRenderingVolume-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkRenderingVolume-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkRenderingVolume-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkRenderingVolume-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Rendering/Volume/CMakeFiles/vtkRenderingVolume.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkDirectionEncoder.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkEncodedGradientEstimator.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkEncodedGradientShader.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkFiniteDifferenceGradientEstimator.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkFixedPointRayCastImage.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkFixedPointVolumeRayCastCompositeGOHelper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkFixedPointVolumeRayCastCompositeGOShadeHelper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkFixedPointVolumeRayCastCompositeHelper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkFixedPointVolumeRayCastCompositeShadeHelper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkFixedPointVolumeRayCastHelper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkFixedPointVolumeRayCastMIPHelper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkFixedPointVolumeRayCastMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkGPUVolumeRayCastMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkMultiVolume.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkOSPRayVolumeInterface.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkProjectedTetrahedraMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkRayCastImageDisplayHelper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkRecursiveSphereDirectionEncoder.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkSphericalDirectionEncoder.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkUnstructuredGridBunykRayCastFunction.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkUnstructuredGridHomogeneousRayIntegrator.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkUnstructuredGridLinearRayIntegrator.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkUnstructuredGridPartialPreIntegration.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkUnstructuredGridPreIntegration.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkUnstructuredGridVolumeMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkUnstructuredGridVolumeRayCastFunction.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkUnstructuredGridVolumeRayCastIterator.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkUnstructuredGridVolumeRayCastMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkUnstructuredGridVolumeRayIntegrator.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkUnstructuredGridVolumeZSweepMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkVolumeMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkVolumeOutlineSource.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkVolumePicker.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Volume/vtkVolumeRayCastSpaceLeapingImageFilter.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/Volume/vtkRenderingVolumeModule.h"
    )
endif()

