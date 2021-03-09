# Install script for directory: C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Project/PlusB-bin/itk-int")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDebugDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/Debug/itkgdcmDSED-4.12D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/Release/itkgdcmDSED-4.12.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/MinSizeRel/itkgdcmDSED-4.12.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/itkgdcmDSED-4.12.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.12" TYPE FILE FILES
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmAttribute.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmBasicOffsetTable.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmByteBuffer.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmByteSwapFilter.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmByteValue.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmCP246ExplicitDataElement.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmCP246ExplicitDataElement.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmCSAElement.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmCSAHeader.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmCSAHeader.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmCodeString.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmDataElement.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmDataSet.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmDataSet.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmDataSetEvent.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmElement.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmExplicitDataElement.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmExplicitDataElement.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmExplicitImplicitDataElement.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmExplicitImplicitDataElement.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmFile.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmFileMetaInformation.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmFileSet.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmFragment.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmFragment.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmImplicitDataElement.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmImplicitDataElement.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmItem.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmItem.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmLO.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmMediaStorage.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmPDBElement.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmPDBHeader.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmParseException.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmParser.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmPreamble.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmPrivateTag.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmReader.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmSequenceOfFragments.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmSequenceOfFragments.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmSequenceOfItems.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmSequenceOfItems.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmTag.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmTagToVR.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmTransferSyntax.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmUNExplicitDataElement.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmUNExplicitDataElement.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmUNExplicitImplicitDataElement.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmUNExplicitImplicitDataElement.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmVL.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmVM.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmVR.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmVR16ExplicitDataElement.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmVR16ExplicitDataElement.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmValue.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmValue.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmValueIO.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmValueIO.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/DataStructureAndEncodingDefinition/gdcmWriter.h"
    )
endif()

