# Install script for directory: C:/Project/PlusB-bin/vtk/IO/XML

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkIOXML-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkIOXML-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkIOXML-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkIOXML-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkIOXML-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkIOXML-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkIOXML-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkIOXML-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/IO/XML/CMakeFiles/vtkIOXML.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkRTXMLPolyDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLCompositeDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLCompositeDataWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLDataSetWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLDataObjectWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLFileReadTester.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLGenericDataObjectReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLHierarchicalBoxDataFileConverter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLHierarchicalBoxDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLHierarchicalBoxDataWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLHierarchicalDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLHyperTreeGridReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLHyperTreeGridWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLImageDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLImageDataWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLMultiBlockDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLMultiBlockDataWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLMultiGroupDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPDataObjectReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPImageDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPolyDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPolyDataWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPPolyDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPRectilinearGridReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPStructuredDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPStructuredGridReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPTableReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPUnstructuredDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPUnstructuredGridReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPartitionedDataSetReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPartitionedDataSetWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPartitionedDataSetCollectionReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLPartitionedDataSetCollectionWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLRectilinearGridReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLRectilinearGridWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLStructuredDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLStructuredDataWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLStructuredGridReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLStructuredGridWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLTableReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLTableWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLUniformGridAMRReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLUniformGridAMRWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLUnstructuredDataReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLUnstructuredDataWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLUnstructuredGridReader.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLUnstructuredGridWriter.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLWriterC.h"
    "C:/Project/PlusB-bin/vtk/IO/XML/vtkXMLWriter.h"
    "C:/Project/PlusB-bin/vtk-bin/IO/XML/vtkIOXMLModule.h"
    )
endif()

