# Install script for directory: C:/Project/PlusB-bin/vtk/IO/Image

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkIOImage-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkIOImage-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkIOImage-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkIOImage-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkIOImage-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkIOImage-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkIOImage-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkIOImage-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/IO/Image/CMakeFiles/vtkIOImage.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkBMPReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkBMPWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkDEMReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkDICOMImageReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkGESignaReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkImageExport.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkImageImport.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkImageImportExecutive.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkImageReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkImageReader2.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkImageReader2Collection.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkImageReader2Factory.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkImageWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkJPEGReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkJPEGWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkJSONImageWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkMedicalImageProperties.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkMedicalImageReader2.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkMetaImageReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkMetaImageWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkMRCReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkNIFTIImageHeader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkNIFTIImageReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkNIFTIImageWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkNrrdReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkPNGReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkPNGWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkPNMReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkPNMWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkPostScriptWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkSLCReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkTIFFReader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkTIFFWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkVolume16Reader.h"
    "C:/Project/PlusB-bin/vtk/IO/Image/vtkVolumeReader.h"
    "C:/Project/PlusB-bin/vtk-bin/IO/Image/vtkIOImageModule.h"
    )
endif()

