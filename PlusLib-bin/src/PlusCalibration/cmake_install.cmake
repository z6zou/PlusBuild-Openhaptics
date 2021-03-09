# Install script for directory: C:/Project/PlusB-bin/PlusLib/src/PlusCalibration

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/PlusLib-2.8" TYPE FILE FILES "C:/Project/PlusB-bin/PlusLib-bin/src/PlusCalibration/vtkPlusCalibrationExport.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeExecutablesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Debug/ConvertFcsvToXml.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Release/ConvertFcsvToXml.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/MinSizeRel/ConvertFcsvToXml.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/ConvertFcsvToXml.exe")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeExecutablesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Debug/ConvertXmlToFcsv.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Release/ConvertXmlToFcsv.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/MinSizeRel/ConvertXmlToFcsv.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/ConvertXmlToFcsv.exe")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeExecutablesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Debug/TemporalCalibration.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Release/TemporalCalibration.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/MinSizeRel/TemporalCalibration.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/TemporalCalibration.exe")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeExecutablesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Debug/ProbeCalibration.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/Release/ProbeCalibration.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/MinSizeRel/ProbeCalibration.exe")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/ProbeCalibration.exe")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkPlusCalibration.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkPlusCalibration.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/PlusLib-2.8" TYPE FILE FILES
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/PatternLocAlgo/PlusFidSegmentation.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/PatternLocAlgo/PlusFidLineFinder.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/PatternLocAlgo/PlusFidLabeling.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/PatternLocAlgo/PlusFidPatternRecognitionCommon.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/PatternLocAlgo/PlusFidPatternRecognition.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/PatternLocAlgo/PlusPatternLocResultFile.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkProbeCalibrationAlgo/vtkPlusProbeCalibrationAlgo.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkProbeCalibrationAlgo/vtkPlusProbeCalibrationOptimizerAlgo.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPivotCalibrationAlgo/vtkPlusPivotCalibrationAlgo.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLandmarkRegistrationAlgo/vtkPlusPhantomLandmarkRegistrationAlgo.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLandmarkRegistrationAlgo/vtkPlusLandmarkDetectionAlgo.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLandmarkRegistrationAlgo/vtkPlusReadTrackedSignals.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLinearObjectRegistrationAlgo/vtkPlusPhantomLinearObjectRegistrationAlgo.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkSpacingCalibAlgo/vtkPlusSpacingCalibAlgo.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkCenterOfRotationCalibAlgo/vtkPlusCenterOfRotationCalibAlgo.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkBrachyStepperPhantomRegistrationAlgo/vtkPlusBrachyStepperPhantomRegistrationAlgo.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkTemporalCalibrationAlgo/vtkPlusTemporalCalibrationAlgo.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkTemporalCalibrationAlgo/vtkPlusPrincipalMotionDetectionAlgo.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkLineSegmentationAlgo/vtkPlusLineSegmentationAlgo.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLinearObjectRegistrationAlgo/Line.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLinearObjectRegistrationAlgo/LinearObject.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLinearObjectRegistrationAlgo/LinearObjectBuffer.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLinearObjectRegistrationAlgo/Plane.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLinearObjectRegistrationAlgo/Planes.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLinearObjectRegistrationAlgo/PointObservation.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLinearObjectRegistrationAlgo/PointObservationBuffer.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLinearObjectRegistrationAlgo/Reference.h"
    "C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLinearObjectRegistrationAlgo/References.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE OPTIONAL FILES "C:/Project/PlusB-bin/bin/Debug/vtkPlusCalibration.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE OPTIONAL FILES "C:/Project/PlusB-bin/bin/Release/vtkPlusCalibration.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE OPTIONAL FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkPlusCalibration.pdb")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE OPTIONAL FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkPlusCalibration.pdb")
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusCalibration/Testing/cmake_install.cmake")

endif()

