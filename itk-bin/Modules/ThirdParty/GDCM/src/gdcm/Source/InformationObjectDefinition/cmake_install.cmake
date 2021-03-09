# Install script for directory: C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/Debug/itkgdcmIOD-4.12D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/Release/itkgdcmIOD-4.12.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/MinSizeRel/itkgdcmIOD-4.12.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/itkgdcmIOD-4.12.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.12" TYPE FILE FILES
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmDefinedTerms.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmDefs.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmEnumeratedValues.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmIOD.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmIODEntry.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmIODs.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmMacro.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmMacroEntry.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmMacros.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmModule.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmModuleEntry.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmModules.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmNestedModuleEntries.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmPatient.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmSeries.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmStudy.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmTable.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmTableEntry.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmTableReader.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmType.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmUsage.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmXMLDictReader.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/gdcmXMLPrivateDictReader.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ITK-4.12/gdcm/XML" TYPE FILE FILES
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/Part3.xml"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/InformationObjectDefinition/Part4.xml"
    )
endif()

