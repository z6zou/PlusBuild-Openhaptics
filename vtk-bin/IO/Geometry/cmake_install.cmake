# Install script for directory: C:/Project/PlusB-bin/vtk/IO/Geometry

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkIOGeometry-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkIOGeometry-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkIOGeometry-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkIOGeometry-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkIOGeometry-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkIOGeometry-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkIOGeometry-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkIOGeometry-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/IO/Geometry/CMakeFiles/vtkIOGeometry.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkAVSucdReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkBYUReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkBYUWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkChacoReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkFacetWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkFLUENTReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkGAMBITReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkGaussianCubeReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkHoudiniPolyDataWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkIVWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkMCubesReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkMCubesWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkMFIXReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkMoleculeReaderBase.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkOBJReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkOBJWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkOpenFOAMReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkParticleReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkPDBReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkProStarReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkPTSReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkSTLReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkSTLWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkTecplotReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkWindBladeReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Geometry/vtkXYZMolReader.h"
    "C:/Project/PlusB-bin/vtk-bin/IO/Geometry/vtkIOGeometryModule.h"
    )
endif()

