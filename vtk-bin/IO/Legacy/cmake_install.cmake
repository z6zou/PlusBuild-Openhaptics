# Install script for directory: C:/Project/PlusB-bin/vtk/IO/Legacy

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkIOLegacy-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkIOLegacy-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkIOLegacy-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkIOLegacy-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkIOLegacy-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkIOLegacy-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkIOLegacy-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkIOLegacy-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/IO/Legacy/CMakeFiles/vtkIOLegacy.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkCompositeDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkCompositeDataWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkDataObjectReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkDataObjectWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkDataSetReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkDataSetWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkDataWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkGenericDataObjectReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkGenericDataObjectWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkGraphReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkGraphWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkPixelExtentIO.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkPolyDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkPolyDataWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkRectilinearGridReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkRectilinearGridWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkSimplePointsReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkSimplePointsWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkStructuredGridReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkStructuredGridWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkStructuredPointsReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkStructuredPointsWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkTableReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkTableWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkTreeReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkTreeWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkUnstructuredGridReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Legacy/vtkUnstructuredGridWriter.h"
    "C:/Project/PlusB-bin/vtk-bin/IO/Legacy/vtkIOLegacyModule.h"
    )
endif()

