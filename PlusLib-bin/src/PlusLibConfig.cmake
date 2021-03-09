#-----------------------------------------------------------------------------
# Configuration file for the Public Library for Ultrasound (PLUS) toolkit
#
# © Copyright 2016 The Laboratory for Percutaneous Surgery, Queen's University, Canada
#
# This file can be passed to a CMake FIND_PACKAGE call with the following syntax:
#
# FIND_PACKAGE(PlusLib 2.8.0 <REQUIRED|QUIET> <NO_MODULE>)
#   If NO_MODULE is included, set the variable PlusLib_DIR:PATH=C:/Project/PlusB-bin/PlusLib-bin
# 
# Once successful, you can either use the USE_FILE approach by the following CMake command:
# INCLUDE(${PLUS_USE_FILE})
#
# Or you can use the following variables to configure your CMake project:
#  PlusLib_INCLUDE_DIRS - include directories for Plus headers
#  PlusLib_LIBRARIES - list of CMake targets produced by this build of Plus
#  PlusLib_DATA_DIR - directory containing data collector configuration files, sample images, and 3d models
#-----------------------------------------------------------------------------

# set the targets file (relative for install location)
SET(PlusLib_TARGETS_FILE "C:/Project/PlusB-bin/PlusLib-bin/PlusLibTargets.cmake")

IF(VTK_FOUND)
  IF(NOT ${VTK_VERSION} VERSION_EQUAL "8.2.0")
    MESSAGE(SEND_ERROR "Trying to use different VTK versions in PlusLib (8.2.0) and your superceeding project (${VTK_VERSION}), use the same version of VTK.")
  ENDIF()
ELSE()
  SET(VTK_DIR "C:/Project/PlusB-bin/vtk-int/lib/cmake/vtk-8.2" CACHE PATH "Path to VTK")
ENDIF()

FIND_PACKAGE(VTK "8.2.0" EXACT REQUIRED NO_MODULE)
INCLUDE(${VTK_USE_FILE}) # Must be included as VTK does not populate CMake target properties correctly

IF(1)
  IF(ITK_FOUND)
    IF(NOT ${ITK_VERSION} VERSION_EQUAL "4.12.0")
      MESSAGE(SEND_ERROR "Trying to use different ITK versions in PlusLib (4.12.0) and your superceeding project (${ITK_VERSION}), use the same version of ITK.")
    ENDIF()
  ELSE()
    SET(ITK_DIR "C:/Project/PlusB-bin/itk-int/lib/cmake/ITK-4.12" CACHE PATH "Path to ITK")
  ENDIF()
  FIND_PACKAGE(ITK "4.12.0" EXACT REQUIRED NO_MODULE)
  INCLUDE(${ITK_USE_FILE}) # Must be included as ITK does not populate CMake target properties correctly
ENDIF()

SET(PLUSLIB_QT_COMPONENTS Core;Widgets;Test;Xml)
FIND_PACKAGE(Qt5 REQUIRED COMPONENTS Core;Widgets;Test;Xml)

INCLUDE(${PlusLib_TARGETS_FILE})

# Tell the user project where to find our headers and libraries
SET(PlusLib_INCLUDE_DIRS "C:/Project/PlusB-bin/PlusLib/src;C:/Project/PlusB-bin/PlusLib-bin/src;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/Utilities/Ransac;C:/Project/PlusB-bin/PlusLib/src/Utilities/xio;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusCommon;C:/Project/PlusB-bin/PlusLib-bin;C:/Project/PlusB-bin/PlusLib-bin/src/PlusCommon;C:/Project/PlusB-bin/PlusLib/src/PlusCommon/IO;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusRendering;C:/Project/PlusB-bin/PlusLib-bin;C:/Project/PlusB-bin/PlusLib-bin/src/PlusRendering;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusOpenIGTLink;C:/Project/PlusB-bin/PlusLib-bin/src/PlusOpenIGTLink;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusImageProcessing;C:/Project/PlusB-bin/PlusLib-bin/src/PlusImageProcessing;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusUsSimulator;C:/Project/PlusB-bin/PlusLib-bin/src/PlusUsSimulator;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusVolumeReconstruction;C:/Project/PlusB-bin/PlusLib-bin/src/PlusVolumeReconstruction;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection;C:/Project/PlusB-bin/PlusLib-bin/src/PlusDataCollection;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/FakeTracking;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/ImageProcessor;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/SavedDataSource;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/UsSimulatorVideo;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/VirtualDevices;C:/Project/OpenHaptics/include;C:/Project/OpenHaptics/utilities/include;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/OpenHaptics;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/ChRobotics;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/MicrochipTracking;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/OpenIGTLink;C:/Project/PlusB-bin/PlusLib/src/PlusUsSimulator;C:/Project/PlusB-bin/PlusLib-bin/src/PlusUsSimulator;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib-bin/src/PlusCalibration;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/PatternLocAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkBrachyStepperPhantomRegistrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkCenterOfRotationCalibAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkLineSegmentationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLandmarkRegistrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLinearObjectRegistrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPivotCalibrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkProbeCalibrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkSpacingCalibAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkTemporalCalibrationAlgo;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusServer;C:/Project/PlusB-bin/PlusLib-bin/src/PlusServer;C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands;CACHE;INTERNAL;")
SET(PlusLib_DATA_DIR "C:/Project/PlusB-bin/PlusLibData")
SET(PlusLib_LIBRARIES "PlusWidgets;vtkxio;vtkPlusCommon;vtkPlusRendering;vtkPlusOpenIGTLink;vtkPlusImageProcessing;vtkPlusUsSimulator;vtkPlusVolumeReconstruction;vtkPlusHaptics;vtkPlusDataCollection;vtkPlusCalibration;vtkPlusServer")

# Tell the user project where to find Plus use file
SET(PlusLib_USE_FILE "C:/Project/PlusB-bin/PlusLib-bin/UsePlusLib.cmake")

IF(OFF AND NOT TARGET Epiphan)
  ADD_LIBRARY(Epiphan SHARED IMPORTED)
  SET_PROPERTY(TARGET Epiphan PROPERTY IMPORTED_IMPLIB "C:/Project/PlusB-bin/PlusLib/Tools/Epiphan/x64/frmgrab.lib")
  SET_PROPERTY(TARGET Epiphan PROPERTY IMPORTED_LOCATION "C:/Project/PlusB-bin/PlusLib/Tools/Epiphan/x64/frmgrab.dll")
  LIST(APPEND PlusLib_LIBRARIES Epiphan)
ENDIF()

IF(OFF AND NOT TARGET Ascension3DG)
  ADD_LIBRARY(Ascension3DG SHARED IMPORTED)
  SET_PROPERTY(TARGET Ascension3DG PROPERTY IMPORTED_IMPLIB "")
  SET_PROPERTY(TARGET Ascension3DG PROPERTY IMPORTED_LOCATION "")
  LIST(APPEND PlusLib_LIBRARIES Ascension3DG)
ENDIF()

IF(OFF AND NOT TARGET Ascension3DGm)
  ADD_LIBRARY(Ascension3DGm SHARED IMPORTED)
  SET_PROPERTY(TARGET Ascension3DGm PROPERTY IMPORTED_IMPLIB "C:/Project/PlusB-bin/PlusLib/Tools/Ascension/medSAFE_940033_Rev_F/lib/ATC3DGm.lib")
  SET_PROPERTY(TARGET Ascension3DGm PROPERTY IMPORTED_LOCATION "C:/Project/PlusB-bin/PlusLib/Tools/Ascension/medSAFE_940033_Rev_F/bin/ATC3DGm.dll")
  LIST(APPEND PlusLib_LIBRARIES Ascension3DGm)
ENDIF()

IF(OFF AND NOT TARGET phidget)
  ADD_LIBRARY(phidget SHARED IMPORTED)
  SET_PROPERTY(TARGET phidget PROPERTY IMPORTED_IMPLIB "C:/Project/PlusB-bin/PlusLib/Tools/Phidget/Phidget22/x64/phidget22.lib")
  SET_PROPERTY(TARGET phidget PROPERTY IMPORTED_LOCATION "C:/Project/PlusB-bin/PlusLib/Tools/Phidget/Phidget22/x64/phidget22.dll")
  LIST(APPEND PlusLib_LIBRARIES phidget)
ENDIF()

IF(OFF AND NOT TARGET USDigitalEncoders)
  # should this be seperated out into BRACHY_TRACKER and USDigitalEncoders??
  # i.e. Options PLUS_USE_BRACHY_TRACKER and PLUS_USE_USDIGITALENCODERS_TRACKER
  ADD_LIBRARY(USDigitalEncoders SHARED IMPORTED)
  SET_PROPERTY(TARGET USDigitalEncoders PROPERTY IMPORTED_IMPLIB "C:/Project/PlusB-bin/PlusLib/Tools/UsDigital/SEI_5.22/lib/SEIDrv32.lib")
  SET_PROPERTY(TARGET USDigitalEncoders PROPERTY IMPORTED_LOCATION "C:/Project/PlusB-bin/PlusLib/Tools/UsDigital/SEI_5.22/bin/SEIDrv32.dll")
  LIST(APPEND PlusLib_LIBRARIES USDigitalEncoders)
ENDIF()

IF(WIN32 AND OFF AND NOT TARGET NVidiaDVP)
  ADD_LIBRARY(NVidiaDVP SHARED IMPORTED)
  SET_PROPERTY(TARGET NVidiaDVP PROPERTY IMPORTED_IMPLIB "C:/Project/PlusB-bin/PlusLib/Tools/NVidia/dvp170/lib/x64/dvp.lib")
  SET_PROPERTY(TARGET NVidiaDVP PROPERTY IMPORTED_LOCATION "C:/Project/PlusB-bin/PlusLib/Tools/NVidia/dvp170/bin/x64/dvp.dll")
  LIST(APPEND PlusLib_LIBRARIES NVidiaDVP)

  ADD_LIBRARY(QuadroSDI INTERFACE IMPORTED)
  SET_PROPERTY(TARGET QuadroSDI PROPERTY INTERFACE_INCLUDE_DIRECTORIES 
    ""
    )
  IF((MSVC AND ${CMAKE_GENERATOR} MATCHES "Win64") OR NOT MSVC)
    SET_PROPERTY(TARGET QuadroSDI PROPERTY INTERFACE_LINK_LIBRARIES 
      "/nvapi64.lib"
      "/ANCapi.lib"
      "/NvCpl.lib"
      "/cutil64.lib"
      )
  ELSE()
    SET_PROPERTY(TARGET QuadroSDI PROPERTY INTERFACE_LINK_LIBRARIES 
      "/nvapi.lib"
      "/ANCapi.lib"
      "/NvCpl.lib"
      "/cutil32.lib"
      )
  ENDIF()
ENDIF()

IF(OFF)
  ADD_LIBRARY(AgilentMD1 SHARED IMPORTED)
  SET_TARGET_PROPERTIES(AgilentMD1 PROPERTIES
    IMPORTED_IMPLIB ""
    IMPORTED_LOCATION "/AgMD1Fundamental.dll"
    INTERFACE_INCLUDE_DIRECTORIES ""
    )
ENDIF()

IF(ON)
  IF(NOT DEFINED OpenIGTLinkIO_DIR)
    SET(OpenIGTLinkIO_DIR "C:/Project/PlusB-bin/OpenIGTLinkIO-bin")
  ENDIF()
  FIND_PACKAGE(OpenIGTLinkIO NO_MODULE REQUIRED)
ENDIF()

IF(OFF)
  SET(OvrvisionPro_DIR "")
  FIND_PACKAGE(OvrvisionPro REQUIRED NO_MODULE)
ENDIF()

IF(ON)
  SET(PLUSLIB_WIDGETS_QRC C:/Project/PlusB-bin/PlusLib/src/PlusWidgets/PlusWidgets.qrc)
ENDIF()

IF(OFF)
  SET(ndicapi_DIR )
  FIND_PACKAGE(ndicapi REQUIRED NO_MODULE)
ENDIF()

IF(OFF)
  SET(OpenCV_DIR )
  FIND_PACKAGE(OpenCV NO_MODULE REQUIRED)
ENDIF()

IF(OFF)
  SET(aruco_DIR )
  FIND_PACKAGE(aruco REQUIRED NO_MODULE)
ENDIF()

IF(OFF)
  IF(NOT DEFINED IGSIO_DIR)
    SET(IGSIO_DIR "C:/Project/PlusB-bin/IGSIO-bin/inner-build")
  ENDIF()
  FIND_PACKAGE(IGSIO NO_MODULE REQUIRED)
ENDIF()
