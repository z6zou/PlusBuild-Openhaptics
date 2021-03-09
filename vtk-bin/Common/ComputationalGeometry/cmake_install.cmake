# Install script for directory: C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkCommonComputationalGeometry-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkCommonComputationalGeometry-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkCommonComputationalGeometry-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkCommonComputationalGeometry-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkCommonComputationalGeometry-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkCommonComputationalGeometry-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkCommonComputationalGeometry-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkCommonComputationalGeometry-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Common/ComputationalGeometry/CMakeFiles/vtkCommonComputationalGeometry.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkCardinalSpline.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkKochanekSpline.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricBoy.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricConicSpiral.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricCrossCap.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricDini.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricEllipsoid.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricEnneper.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricFigure8Klein.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricFunction.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricKlein.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricMobius.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricRandomHills.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricRoman.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricSpline.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricSuperEllipsoid.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricSuperToroid.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricTorus.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricKuen.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricPseudosphere.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricBohemianDome.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricHenneberg.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricCatalanMinimal.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricBour.h"
    "C:/Project/PlusB-bin/vtk/Common/ComputationalGeometry/vtkParametricPluckerConoid.h"
    "C:/Project/PlusB-bin/vtk-bin/Common/ComputationalGeometry/vtkCommonComputationalGeometryModule.h"
    )
endif()

