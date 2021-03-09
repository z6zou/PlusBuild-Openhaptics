#
# This module is provided as PLUSLIB_USE_FILE
# It can be INCLUDEd in a project to load the needed compiler and linker
# settings to use Plus library.
#

IF(NOT PLUSLIB_USE_FILE_INCLUDED)
  SET(PLUSLIB_USE_FILE_INCLUDED 1)

  CMAKE_POLICY(PUSH)
  CMAKE_POLICY(SET CMP0012 NEW) # if() recognizes numbers and boolean constants

  IF()
    MESSAGE(FATAL_ERROR "PlusLib use file is not supported for INSTALL Builds. Please link directly to targets provided by PlusLibTargets.cmake.")
  ENDIF()


  ## Set Plus binary dir path
  SET(PLUSLIB_DIR "C:/Project/PlusB-bin/PlusLib-bin")

  ## Set Plus source dir path
  SET(PLUSLIB_SOURCE_DIR "C:/Project/PlusB-bin/PlusLib")

  ## Set Plus data dir path
  SET(PLUSLIB_DATA_DIR "C:/Project/PlusB-bin/PlusLibData")

  ## Set Plus executable output path
  SET(PLUS_EXECUTABLE_OUTPUT_PATH "C:/Project/PlusB-bin/bin")

  ## Set Plus scripts folder path
  SET(PLUSLIB_SCRIPTS_DIR "C:/Project/PlusB-bin/PlusLib/src/scripts")

  ## Find ITK
  FIND_PACKAGE(ITK PATHS "C:/Project/PlusB-bin/itk-int/lib/cmake/ITK-4.12" NO_DEFAULT_PATH)
  IF(ITK_FOUND)
    INCLUDE("C:/Project/PlusB-bin/itk-int/lib/cmake/ITK-4.12/UseITK.cmake")
  ELSE()
    MESSAGE(FATAL_ERROR "ITK not found in UsePlusLib.cmake. Please report this to the developers at https://github.com/PlusToolkit/PlusLib.")
  ENDIF()

  ## Find VTK
  FIND_PACKAGE(VTK PATHS "C:/Project/PlusB-bin/vtk-int/lib/cmake/vtk-8.2" NO_DEFAULT_PATH)
  IF (VTK_FOUND)
    INCLUDE("C:/Project/PlusB-bin/vtk-int/lib/cmake/vtk-8.2/UseVTK.cmake")
  ELSE()
    MESSAGE(FATAL_ERROR "VTK not found in UsePlusLib.cmake. Please report this to the developers at https://github.com/PlusToolkit/PlusLib.")
  ENDIF()

  SET(PLUS_USE_OpenIGTLink ON)
  IF(PLUS_USE_OpenIGTLink)
    SET(OpenIGTLink_DIR "C:/Project/PlusB-bin/OpenIGTLink-bin")
    FIND_PACKAGE(OpenIGTLink PATHS "C:/Project/PlusB-bin/OpenIGTLink-bin" NO_MODULE)
    IF(OpenIGTLink_USE_FILE)
      INCLUDE ("C:/Project/PlusB-bin/OpenIGTLink-bin/UseOpenIGTLink.cmake")
    ENDIF()

    SET(OpenIGTLinkIO_DIR "C:/Project/PlusB-bin/OpenIGTLinkIO-bin")
    FIND_PACKAGE(OpenIGTLinkIO PATHS "C:/Project/PlusB-bin/OpenIGTLinkIO-bin" NO_MODULE)
  ENDIF()

  IF(PLUS_USE_TextRecognizer)
    SET(tesseract_DIR "")
    FIND_PACKAGE(tesseract NO_MODULE)
  ENDIF()

  SET(PLUS_USE_OpenCV OFF)
  IF(PLUS_USE_OpenCV)
    SET(OpenCV_DIR "")
    FIND_PACKAGE(OpenCV)
  ENDIF()

  SET(PLUS_USE_SLICER OFF)
  IF(PLUS_USE_SLICER)
    SET(SLICER_BIN_DIRECTORY "")
  ENDIF()

  SET(PLUS_USE_IGSIO OFF)
  IF(PLUS_USE_IGSIO)
    SET(IGSIO_DIR "C:/Project/PlusB-bin/IGSIO-bin/inner-build")
    FIND_PACKAGE(IGSIO)
  ENDIF()

  # Add include directories needed to use PlusLib library
  # Use a temporary CMake variable to store the list of directory paths
  # (it is required because this way directory names
  # that do not contain space and those that do contain space
  # work equally well).
  SET(PLUSLIB_INCLUDE_DIRS_TEMP "C:/Project/PlusB-bin/PlusLib/src;C:/Project/PlusB-bin/PlusLib-bin/src;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/Utilities/Ransac;C:/Project/PlusB-bin/PlusLib/src/Utilities/xio;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusCommon;C:/Project/PlusB-bin/PlusLib-bin;C:/Project/PlusB-bin/PlusLib-bin/src/PlusCommon;C:/Project/PlusB-bin/PlusLib/src/PlusCommon/IO;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusRendering;C:/Project/PlusB-bin/PlusLib-bin;C:/Project/PlusB-bin/PlusLib-bin/src/PlusRendering;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusOpenIGTLink;C:/Project/PlusB-bin/PlusLib-bin/src/PlusOpenIGTLink;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusImageProcessing;C:/Project/PlusB-bin/PlusLib-bin/src/PlusImageProcessing;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusUsSimulator;C:/Project/PlusB-bin/PlusLib-bin/src/PlusUsSimulator;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusVolumeReconstruction;C:/Project/PlusB-bin/PlusLib-bin/src/PlusVolumeReconstruction;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection;C:/Project/PlusB-bin/PlusLib-bin/src/PlusDataCollection;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/FakeTracking;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/ImageProcessor;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/SavedDataSource;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/UsSimulatorVideo;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/VirtualDevices;C:/Project/OpenHaptics/include;C:/Project/OpenHaptics/utilities/include;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/OpenHaptics;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/ChRobotics;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/MicrochipTracking;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/OpenIGTLink;C:/Project/PlusB-bin/PlusLib/src/PlusUsSimulator;C:/Project/PlusB-bin/PlusLib-bin/src/PlusUsSimulator;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib-bin/src/PlusCalibration;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/PatternLocAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkBrachyStepperPhantomRegistrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkCenterOfRotationCalibAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkLineSegmentationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLandmarkRegistrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLinearObjectRegistrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPivotCalibrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkProbeCalibrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkSpacingCalibAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkTemporalCalibrationAlgo;CACHE;INTERNAL;;C:/Project/PlusB-bin/PlusLib/src/PlusServer;C:/Project/PlusB-bin/PlusLib-bin/src/PlusServer;C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands;CACHE;INTERNAL;")
  INCLUDE_DIRECTORIES(${PLUSLIB_INCLUDE_DIRS_TEMP})

  # Add link directories needed to use Plus library
  # Use a temporary CMake variable to store the list of directory paths
  # (it is required because this way directory names
  # that do not contain space and those that do contain space
  # work equally well).
  SET(PLUSLIB_LIBRARY_DIRS_TEMP "C:/Project/PlusB-bin/bin")
  LINK_DIRECTORIES(${PLUSLIB_LIBRARY_DIRS_TEMP})

  MESSAGE(STATUS "PlusLib use file triggered. In the future, consider linking directly to targets provided by PlusLibTargets.cmake.")

  SET(PLUSLIB_BUILD_SHARED_LIBS ON)

  ## Find SVN
  SET(SVN_FOUND )
  IF(SVN_FOUND)
    SET(Subversion_SVN_EXECUTABLE "" CACHE INTERNAL "")
  ENDIF()

  ## Set Plus version
  SET(PLUSLIB_VERSION "2.8.0")
  SET(PLUSLIB_VERSION_MAJOR 2)
  SET(PLUSLIB_VERSION_MINOR 8)
  SET(PLUSLIB_VERSION_PATCH 0)
  SET(PLUSLIB_PLATFORM Win64)
  SET(PLUSLIB_REVISION 62873a16c3c0b326648e51f0665c2804d1b97bd8)

  ## Set PlusLib commit date
  SET(PLUSLIB_COMMIT_DATE 2019-11-05)
  SET(PLUSLIB_COMMIT_DATE_NO_DASHES 20191105)

  ## Set third party lib path variables
  SET(ICCAPTURING_BIN_DIR "")
  SET(NDIOAPI_BINARY_DIR "")
  SET(ULTRASONIX_SDK_BINARY_DIR "")
  SET(ATC_TRAKSTAR_BINARY_DIR "C:/Project/PlusB-bin/PlusLib/Tools/Ascension/trakSTAR_940041_RevE/bin")
  SET(USDIGITAL_SEI_BINARY_DIR "C:/Project/PlusB-bin/PlusLib/Tools/UsDigital/SEI_5.22/bin")
  SET(NVIDIA_DVP_BINARY_DIR "C:/Project/PlusB-bin/PlusLib/Tools/NVidia/dvp170/bin/x64")

  ## Set Plus use variables
  SET(PLUS_USE_AGILENT OFF)
  SET(PLUS_USE_3dConnexion_TRACKER OFF)
  SET(PLUS_USE_aruco OFF)
  SET(PLUS_USE_Ascension3DG OFF)
  SET(PLUS_USE_Ascension3DGm OFF)
  SET(PLUS_USE_BKPROFOCUS_CAMERALINK )
  SET(PLUS_USE_BKPROFOCUS_VIDEO OFF)
  SET(PLUS_TEST_BKPROFOCUS OFF)
  SET(PLUS_USE_BRACHY_TRACKER OFF)
  SET(PLUS_USE_CAPISTRANO_VIDEO OFF)
  SET(PLUS_USE_EPIPHAN OFF)
  SET(PLUS_USE_ICCAPTURING_VIDEO OFF)
  SET(PLUS_USE_INTELREALSENSE OFF)
  SET(PLUS_USE_ATRACSYS OFF)
  SET(PLUS_USE_INTERSONSDKCXX_VIDEO OFF)
  SET(PLUS_USE_INTERSONARRAYSDKCXX_VIDEO OFF)
  SET(PLUS_USE_INTERSON_VIDEO OFF)
  SET(PLUS_USE_IntuitiveDaVinci OFF)
  SET(PLUS_USE_MICRONTRACKER OFF)
  SET(PLUS_USE_MMF_VIDEO OFF)
  SET(PLUS_USE_NDI OFF)
  SET(PLUS_USE_NDI_CERTUS OFF)
  SET(PLUS_USE_NVIDIA_DVP OFF)
  SET(PLUS_USE_OpenCV OFF)
  SET(PLUS_USE_OPTICAL_MARKER_TRACKER OFF)
  SET(PLUS_USE_OPTIMET_CONOPROBE OFF)
  SET(PLUS_USE_OPTITRACK OFF)
  SET(PLUS_USE_OvrvisionPro OFF)
  SET(PLUS_USE_PHIDGET_SPATIAL_TRACKER OFF)
  SET(PLUS_USE_PHILIPS_3D_ULTRASOUND OFF)
  SET(PLUS_USE_STEALTHLINK OFF)
  SET(PLUS_USE_TELEMED_VIDEO OFF)
  SET(PLUS_USE_THORLABS_VIDEO OFF)
  SET(PLUS_USE_ULTRASONIX_VIDEO OFF)
  SET(PLUS_USE_USDIGITALENCODERS_TRACKER OFF)
  SET(PLUS_USE_VFW_VIDEO OFF)
  SET(PLUS_USE_OpenCV_VIDEO OFF)
  SET(PLUS_USE_OPENHAPTICS ON)
  SET(PLUS_USE_V4L2 )
  SET(PLUS_USE_TextRecognizer OFF)
  SET(PLUS_USE_INFRARED_TEQ1_CAM OFF)
  SET(PLUS_USE_INFRARED_SEEK_CAM OFF)
  SET(PLUS_USE_INTELREALSENSE_CAM )
  SET(PLUS_USE_WITMOTIONTRACKER OFF)
  SET(PLUS_USE_MKV_IO OFF)
  SET(PLUS_USE_VP9 OFF)

  SET(PLUS_ENABLE_VIDEOSTREAMING OFF)

  SET(PLUSLIB_DEPENDENCIES PlusWidgets;vtkxio;vtkPlusCommon;vtkPlusRendering;vtkPlusOpenIGTLink;vtkPlusImageProcessing;vtkPlusUsSimulator;vtkPlusVolumeReconstruction;vtkPlusHaptics;vtkPlusDataCollection;vtkPlusCalibration;vtkPlusServer )

  IF(OFF)
    SET(PLUS_ULTRASONIX_SDK_MAJOR_VERSION )
    SET(PLUS_ULTRASONIX_SDK_MINOR_VERSION )
    SET(PLUS_ULTRASONIX_SDK_PATCH_VERSION )
  ENDIF()

  IF(OFF)
    SET(PLUS_MOTIVE_VERSION_MAJOR )
    SET(PLUS_MOTIVE_VERSION_MINOR )
    SET(PLUS_MOTIVE_VERSION_PATCH )
  ENDIF()

  MACRO(INCLUDE_PLUSLIB_MS_PROJECTS)
    IF(MSVC)
      IF(ON)
        INCLUDE_EXTERNAL_MSPROJECT(PlusWidgets;C:/Project/PlusB-bin/PlusLib-bin/src/PlusWidgets/PlusWidgets.vcxproj)
      ENDIF()
      INCLUDE_EXTERNAL_MSPROJECT(vtkPlusCommon;C:/Project/PlusB-bin/PlusLib-bin/src/PlusCommon/vtkPlusCommon.vcxproj)
      INCLUDE_EXTERNAL_MSPROJECT(vtkPlusUsSimulator;C:/Project/PlusB-bin/PlusLib-bin/src/PlusUsSimulator/vtkPlusUsSimulator.vcxproj;vtkPlusCommon)
      INCLUDE_EXTERNAL_MSPROJECT(vtkPlusImageProcessing;C:/Project/PlusB-bin/PlusLib-bin/src/PlusImageProcessing/vtkPlusImageProcessing.vcxproj;vtkPlusCommon)
      INCLUDE_EXTERNAL_MSPROJECT(vtkPlusDataCollection;C:/Project/PlusB-bin/PlusLib-bin/src/PlusDataCollection/vtkPlusDataCollection.vcxproj;vtkPlusCommon;vtkPlusUsSimulator;vtkPlusImageProcessing)
      INCLUDE_EXTERNAL_MSPROJECT(vtkPlusCalibration;C:/Project/PlusB-bin/PlusLib-bin/src/PlusCalibration/vtkPlusCalibration.vcxproj;vtkPlusCommon)
      INCLUDE_EXTERNAL_MSPROJECT(vtkPlusRendering;C:/Project/PlusB-bin/PlusLib-bin/src/PlusRendering/vtkPlusRendering.vcxproj)
      INCLUDE_EXTERNAL_MSPROJECT(vtkPlusVolumeReconstruction;C:/Project/PlusB-bin/PlusLib-bin/src/PlusVolumeReconstruction/vtkPlusVolumeReconstruction.vcxproj;vtkPlusCommon;vtkPlusDataCollection)
      INCLUDE_EXTERNAL_MSPROJECT(vtkxio;C:/Project/PlusB-bin/PlusLib-bin/src/Utilities/xio/vtkxio.vcxproj)
      IF(OFF)
        INCLUDE_EXTERNAL_MSPROJECT()
      ENDIF()
      IF(ON)
        INCLUDE_EXTERNAL_MSPROJECT(vtkPlusOpenIGTLink;C:/Project/PlusB-bin/PlusLib-bin/src/PlusOpenIGTLink/vtkPlusOpenIGTLink.vcxproj;vtkPlusCommon)
        INCLUDE_EXTERNAL_MSPROJECT(vtkPlusServer;C:/Project/PlusB-bin/PlusLib-bin/src/PlusServer/vtkPlusServer.vcxproj;vtkPlusCommon)
      ENDIF()
      IF(OFF)
        INCLUDE_EXTERNAL_MSPROJECT()
      ENDIF()
    ENDIF()
  ENDMACRO()

  MACRO(GROUP_PLUSLIB_MS_PROJECTS GROUPNAME)
    # Ensure targets exist
    INCLUDE_PLUSLIB_MS_PROJECTS()

    IF(MSVC)
      IF(ON)
        SET_TARGET_PROPERTIES(PlusWidgets PROPERTIES FOLDER ${GROUPNAME})
      ENDIF()
      SET_TARGET_PROPERTIES(vtkPlusCommon PROPERTIES FOLDER ${GROUPNAME})
      SET_TARGET_PROPERTIES(vtkPlusUsSimulator PROPERTIES FOLDER ${GROUPNAME})
      SET_TARGET_PROPERTIES(vtkPlusImageProcessing PROPERTIES FOLDER ${GROUPNAME})
      SET_TARGET_PROPERTIES(vtkPlusDataCollection PROPERTIES FOLDER ${GROUPNAME})
      SET_TARGET_PROPERTIES(vtkPlusCalibration PROPERTIES FOLDER ${GROUPNAME})
      SET_TARGET_PROPERTIES(vtkPlusRendering PROPERTIES FOLDER ${GROUPNAME})
      SET_TARGET_PROPERTIES(vtkPlusVolumeReconstruction PROPERTIES FOLDER ${GROUPNAME})
      SET_TARGET_PROPERTIES(vtkxio PROPERTIES FOLDER ${GROUPNAME})
      IF(OFF)
        SET_TARGET_PROPERTIES(MicronTrackerInterface PROPERTIES FOLDER ${GROUPNAME})
      ENDIF()
      IF(ON)
        SET_TARGET_PROPERTIES(vtkPlusOpenIGTLink PROPERTIES FOLDER ${GROUPNAME})
        SET_TARGET_PROPERTIES(vtkPlusServer PROPERTIES FOLDER ${GROUPNAME})
      ENDIF()
      IF(OFF)
        SET_TARGET_PROPERTIES(MfVideoCaptureLibrary PROPERTIES FOLDER ${GROUPNAME})
      ENDIF()
    ENDIF()
  ENDMACRO()

  SET(DOXYGEN_EXECUTABLE "")
  SET(DOXYGEN_DOT_EXECUTABLE "")
  SET(DOXYGEN_HHC_EXECUTABLE "")
  SET(PLUSLIB_DOCUMENTATION_TARGET_IN_ALL )
  SET(PLUSLIB_BUILD_DOCUMENTATION OFF)

  CMAKE_POLICY(POP)
ENDIF()
