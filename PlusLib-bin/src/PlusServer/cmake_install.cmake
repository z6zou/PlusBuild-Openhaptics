# Install script for directory: C:/Project/PlusB-bin/PlusLib/src/PlusServer

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/PlusLib")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/PlusLib-2.8" TYPE FILE FILES "C:/Project/PlusB-bin/PlusLib-bin/src/PlusServer/vtkPlusServerExport.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkPlusServer.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkPlusServer.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/PlusLib-2.8" TYPE FILE FILES
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/vtkPlusOpenIGTLinkServer.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/vtkPlusOpenIGTLinkClient.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/vtkPlusCommandResponse.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/vtkPlusCommandProcessor.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusCommand.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusVersionCommand.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusReconstructVolumeCommand.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusStartStopRecordingCommand.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusRequestIdsCommand.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusUpdateTransformCommand.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusSaveConfigCommand.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusSendTextCommand.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusGetImageCommand.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusGetPolydataCommand.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusGetTransformCommand.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusSetUsParameterCommand.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusGetUsParameterCommand.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands/vtkPlusAddRecordingDeviceCommand.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE OPTIONAL FILES "C:/Project/PlusB-bin/bin/Debug/vtkPlusServer.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE OPTIONAL FILES "C:/Project/PlusB-bin/bin/Release/vtkPlusServer.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE OPTIONAL FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkPlusServer.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE OPTIONAL FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkPlusServer.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeExecutablesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Debug/PlusServer.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Release/PlusServer.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/MinSizeRel/PlusServer.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/PlusServer.exe")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeExecutablesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Debug/PlusServerRemoteControl.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Release/PlusServerRemoteControl.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/MinSizeRel/PlusServerRemoteControl.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/PlusServerRemoteControl.exe")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusServer/Testing/cmake_install.cmake")

endif()

