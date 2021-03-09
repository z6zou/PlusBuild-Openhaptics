# Install script for directory: C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/PlusLib-2.8" TYPE FILE FILES "C:/Project/PlusB-bin/PlusLib-bin/src/PlusDataCollection/vtkPlusDataCollectionExport.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Debug/PlusVersion.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Release/PlusVersion.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/MinSizeRel/PlusVersion.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/PlusVersion.exe")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Debug/ViewSequenceFile.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Release/ViewSequenceFile.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/MinSizeRel/ViewSequenceFile.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/ViewSequenceFile.exe")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkPlusDataCollection.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkPlusDataCollection.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/PlusLib-2.8" TYPE FILE FILES
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/vtkPlusDataCollector.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/vtkPlusDevice.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/vtkPlusUsDevice.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/vtkPlusChannel.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/vtkPlusDeviceFactory.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/vtkPlusDataSource.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/vtkPlusTimestampedCircularBuffer.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/PlusStreamBufferItem.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/vtkPlusGenericSerialDevice.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/PlusSerialLine.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/vtkFcsvReader.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/vtkFcsvWriter.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/vtkPlusBuffer.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/vtkPlusUsImagingParameters.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/VirtualDevices/vtkPlusVirtualMixer.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/VirtualDevices/vtkPlusVirtualSwitcher.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/VirtualDevices/vtkPlusVirtualCapture.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/VirtualDevices/vtkPlusVirtualVolumeReconstructor.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/FakeTracking/vtkPlusFakeTracker.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/SavedDataSource/vtkPlusSavedDataSource.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/ImageProcessor/vtkPlusImageProcessorVideoSource.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/UsSimulatorVideo/vtkPlusUsSimulatorVideoSource.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/OpenHaptics/vtkPlusOpenHapticsDevice.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/ChRobotics/vtkPlusChRoboticsTracker.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/MicrochipTracking/vtkPlusMicrochipTracker.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/OpenIGTLink/vtkPlusOpenIGTLinkDevice.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/OpenIGTLink/vtkPlusOpenIGTLinkTracker.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/OpenIGTLink/vtkPlusOpenIGTLinkVideoSource.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE OPTIONAL FILES "C:/Project/PlusB-bin/bin/Debug/vtkPlusDataCollection.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE OPTIONAL FILES "C:/Project/PlusB-bin/bin/Release/vtkPlusDataCollection.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE OPTIONAL FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkPlusDataCollection.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE OPTIONAL FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkPlusDataCollection.pdb")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES
    "C:/Project/OpenHaptics/lib/x64/Release/hd.dll"
    "C:/Project/OpenHaptics/lib/x64/Release/hl.dll"
    "C:/Project/OpenHaptics/utilities/lib/x64/Release/glut32.dll"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusDataCollection/Haptics/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusDataCollection/Testing/cmake_install.cmake")

endif()

