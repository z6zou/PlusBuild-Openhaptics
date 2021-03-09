# Install script for directory: C:/Project/PlusB-bin/vtk/IO/Core

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkIOCore-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkIOCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkIOCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkIOCore-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkIOCore-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkIOCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkIOCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkIOCore-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/IO/Core/CMakeFiles/vtkIOCore.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkAbstractParticleWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkArrayReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkArrayWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkASCIITextCodec.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkBase64InputStream.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkBase64OutputStream.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkBase64Utilities.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkDataCompressor.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkDelimitedTextWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkGlobFileNames.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkInputStream.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkJavaScriptDataWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkLZ4DataCompressor.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkOutputStream.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkSortFileNames.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkTextCodec.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkTextCodecFactory.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkUTF16TextCodec.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkUTF8TextCodec.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkAbstractPolyDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkZLibDataCompressor.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkArrayDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkArrayDataWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkLZMADataCompressor.h"
    "C:/Project/PlusB-bin/vtk/IO/Core/vtkNumberToString.h"
    "C:/Project/PlusB-bin/vtk-bin/IO/Core/vtkIOCoreModule.h"
    )
endif()

