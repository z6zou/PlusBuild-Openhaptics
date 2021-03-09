# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" LESS 2.5)
   message(FATAL_ERROR "CMake >= 2.6.0 required")
endif()
cmake_policy(PUSH)
cmake_policy(VERSION 2.6...3.17)
#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Protect against multiple inclusion, which would fail when already imported targets are added once more.
set(_targetsDefined)
set(_targetsNotDefined)
set(_expectedTargets)
foreach(_expectedTarget PlusWidgets vtkxio vtkPlusCommon vtkPlusRendering vtkPlusOpenIGTLink vtkPlusImageProcessing vtkPlusUsSimulator vtkPlusVolumeReconstruction vtkPlusHaptics vtkPlusDataCollection vtkPlusCalibration vtkPlusServer)
  list(APPEND _expectedTargets ${_expectedTarget})
  if(NOT TARGET ${_expectedTarget})
    list(APPEND _targetsNotDefined ${_expectedTarget})
  endif()
  if(TARGET ${_expectedTarget})
    list(APPEND _targetsDefined ${_expectedTarget})
  endif()
endforeach()
if("${_targetsDefined}" STREQUAL "${_expectedTargets}")
  unset(_targetsDefined)
  unset(_targetsNotDefined)
  unset(_expectedTargets)
  set(CMAKE_IMPORT_FILE_VERSION)
  cmake_policy(POP)
  return()
endif()
if(NOT "${_targetsDefined}" STREQUAL "")
  message(FATAL_ERROR "Some (but not all) targets in this export set were already defined.\nTargets Defined: ${_targetsDefined}\nTargets not yet defined: ${_targetsNotDefined}\n")
endif()
unset(_targetsDefined)
unset(_targetsNotDefined)
unset(_expectedTargets)


# Create imported target PlusWidgets
add_library(PlusWidgets SHARED IMPORTED)

set_target_properties(PlusWidgets PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Project/PlusB-bin/PlusLib-bin/src/PlusWidgets;C:/Project/PlusB-bin/PlusLib/src/PlusWidgets;C:/Project/PlusB-bin/PlusLib-bin/src/PlusWidgets/PlusWidgets_autogen/include;C:/Project/PlusB-bin/PlusLib-bin/src/PlusWidgets/PlusWidgets_autogen/include_Debug;C:/Project/PlusB-bin/PlusLib-bin/src/PlusWidgets/PlusWidgets_autogen/include_Release;C:/Project/PlusB-bin/PlusLib-bin/src/PlusWidgets/PlusWidgets_autogen/include_MinSizeRel;C:/Project/PlusB-bin/PlusLib-bin/src/PlusWidgets/PlusWidgets_autogen/include_RelWithDebInfo"
  INTERFACE_LINK_LIBRARIES "Qt5::Xml;Qt5::Widgets;vtkGUISupportQt;vtkPlusCalibration;vtkPlusCommon;vtkPlusDataCollection"
)

# Create imported target vtkxio
add_library(vtkxio STATIC IMPORTED)

set_target_properties(vtkxio PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Project/PlusB-bin/PlusLib/src/Utilities/xio"
)

# Create imported target vtkPlusCommon
add_library(vtkPlusCommon SHARED IMPORTED)

set_target_properties(vtkPlusCommon PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Project/PlusB-bin/PlusLib/src/PlusCommon;C:/Project/PlusB-bin/PlusLib-bin;C:/Project/PlusB-bin/PlusLib-bin/src/PlusCommon;C:/Project/PlusB-bin/PlusLib/src/PlusCommon/IO"
  INTERFACE_LINK_LIBRARIES "vtkCommonCore;vtkCommonDataModel;vtkImagingCore;vtkIOXMLParser;vtkIOImage;vtkCommonSystem;vtksys;itksys;vtkzlib;ITKIONIFTI;ITKIONRRD;ITKIOGIPL;ITKIOHDF5;ITKIOJPEG;ITKIOGDCM;ITKIOBMP;ITKIOLSM;ITKIOTIFF;ITKIOPNG;ITKIOVTK;ITKIOGE;ITKIOMRC;ITKIOBioRad;ITKIOStimulate;ITKIOMeta;itkvnl;itkvnl_algo;igtlioConverter;Winmm;OpenIGTLink"
)

# Create imported target vtkPlusRendering
add_library(vtkPlusRendering SHARED IMPORTED)

set_target_properties(vtkPlusRendering PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Project/PlusB-bin/PlusLib/src/PlusRendering;C:/Project/PlusB-bin/PlusLib-bin;C:/Project/PlusB-bin/PlusLib-bin/src/PlusRendering"
  INTERFACE_LINK_LIBRARIES "vtkPlusCommon;vtkCommonCore;vtkFiltersSources;vtkChartsCore;vtkViewsContext2D;vtkIOCore;vtkInteractionStyle;vtkRenderingFreeType;vtkRenderingAnnotation;vtkRenderingOpenGL2;vtkRenderingContextOpenGL2"
)

# Create imported target vtkPlusOpenIGTLink
add_library(vtkPlusOpenIGTLink SHARED IMPORTED)

set_target_properties(vtkPlusOpenIGTLink PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Project/PlusB-bin/PlusLib/src/PlusOpenIGTLink;C:/Project/PlusB-bin/PlusLib-bin/src/PlusOpenIGTLink"
  INTERFACE_LINK_LIBRARIES "vtkPlusCommon;OpenIGTLink;igtlioConverter"
)

# Create imported target vtkPlusImageProcessing
add_library(vtkPlusImageProcessing SHARED IMPORTED)

set_target_properties(vtkPlusImageProcessing PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Project/PlusB-bin/PlusLib/src/PlusImageProcessing;C:/Project/PlusB-bin/PlusLib-bin/src/PlusImageProcessing"
  INTERFACE_LINK_LIBRARIES "vtkPlusCommon;vtkImagingStatistics;vtkImagingGeneral;vtkImagingMorphological"
)

# Create imported target vtkPlusUsSimulator
add_library(vtkPlusUsSimulator SHARED IMPORTED)

set_target_properties(vtkPlusUsSimulator PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Project/PlusB-bin/PlusLib/src/PlusUsSimulator;C:/Project/PlusB-bin/PlusLib-bin/src/PlusUsSimulator"
  INTERFACE_LINK_LIBRARIES "vtkPlusCommon;vtkPlusRendering;vtkPlusImageProcessing;vtkFiltersSources;vtkFiltersFlowPaths;vtkIOGeometry;vtkIOXML"
)

# Create imported target vtkPlusVolumeReconstruction
add_library(vtkPlusVolumeReconstruction SHARED IMPORTED)

set_target_properties(vtkPlusVolumeReconstruction PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Project/PlusB-bin/PlusLib/src/PlusVolumeReconstruction;C:/Project/PlusB-bin/PlusLib-bin/src/PlusVolumeReconstruction"
  INTERFACE_LINK_LIBRARIES "vtkPlusCommon;vtkInteractionStyle;vtkRenderingFreeType;vtkRenderingOpenGL2;vtkRenderingVolumeOpenGL2"
)

# Create imported target vtkPlusHaptics
add_library(vtkPlusHaptics SHARED IMPORTED)

set_target_properties(vtkPlusHaptics PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/Haptics;C:/Project/PlusB-bin/PlusLib-bin/src/PlusDataCollection/Haptics"
  INTERFACE_LINK_LIBRARIES "vtkCommonCore;vtkCommonDataModel;vtksys"
)

# Create imported target vtkPlusDataCollection
add_library(vtkPlusDataCollection SHARED IMPORTED)

set_target_properties(vtkPlusDataCollection PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection;C:/Project/PlusB-bin/PlusLib-bin/src/PlusDataCollection;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/FakeTracking;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/ImageProcessor;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/SavedDataSource;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/UsSimulatorVideo;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/VirtualDevices;C:/Project/OpenHaptics/include;C:/Project/OpenHaptics/utilities/include;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/OpenHaptics;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/ChRobotics;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/MicrochipTracking;C:/Project/PlusB-bin/PlusLib/src/PlusDataCollection/OpenIGTLink;C:/Project/PlusB-bin/PlusLib/src/PlusUsSimulator;C:/Project/PlusB-bin/PlusLib-bin/src/PlusUsSimulator"
  INTERFACE_LINK_LIBRARIES "\$<\$<NOT:\$<CONFIG:DEBUG>>:C:/Project/OpenHaptics/lib/x64/Release/hd.lib>;\$<\$<NOT:\$<CONFIG:DEBUG>>:C:/Project/OpenHaptics/lib/x64/Release/hl.lib>;\$<\$<NOT:\$<CONFIG:DEBUG>>:C:/Project/OpenHaptics/utilities/lib/x64/Release/hdu.lib>;\$<\$<NOT:\$<CONFIG:DEBUG>>:C:/Project/OpenHaptics/utilities/lib/x64/Release/hlu.lib>;\$<\$<CONFIG:DEBUG>:C:/Project/OpenHaptics/lib/x64/Debug/hd.lib>;\$<\$<CONFIG:DEBUG>:C:/Project/OpenHaptics/lib/x64/Debug/hl.lib>;\$<\$<CONFIG:DEBUG>:C:/Project/OpenHaptics/utilities/lib/x64/Debug/hdu.lib>;\$<\$<CONFIG:DEBUG>:C:/Project/OpenHaptics/utilities/lib/x64/Debug/hlu.lib>;OpenIGTLink;vtkPlusOpenIGTLink;vtkPlusRendering;vtkPlusCommon;vtkPlusUsSimulator;vtkPlusVolumeReconstruction;vtkPlusImageProcessing"
)

# Create imported target vtkPlusCalibration
add_library(vtkPlusCalibration SHARED IMPORTED)

set_target_properties(vtkPlusCalibration PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Project/PlusB-bin/PlusLib-bin/src/PlusCalibration;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/PatternLocAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkBrachyStepperPhantomRegistrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkCenterOfRotationCalibAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkLineSegmentationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLandmarkRegistrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPhantomLinearObjectRegistrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkPivotCalibrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkProbeCalibrationAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkSpacingCalibAlgo;C:/Project/PlusB-bin/PlusLib/src/PlusCalibration/vtkTemporalCalibrationAlgo"
  INTERFACE_LINK_LIBRARIES "ITKCommon;ITKIOImageBase;ITKOptimizers;ITKTransform;vtkInteractionStyle;vtkRenderingFreeType;vtkFiltersStatistics;vtkPlusRendering;vtkPlusCommon"
)

# Create imported target vtkPlusServer
add_library(vtkPlusServer SHARED IMPORTED)

set_target_properties(vtkPlusServer PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "C:/Project/PlusB-bin/PlusLib/src/PlusServer;C:/Project/PlusB-bin/PlusLib-bin/src/PlusServer;C:/Project/PlusB-bin/PlusLib/src/PlusServer/Commands"
  INTERFACE_LINK_LIBRARIES "vtkPlusCommon;vtkPlusDataCollection;vtkPlusVolumeReconstruction;vtkIOPLY"
)

# Import target "PlusWidgets" for configuration "Debug"
set_property(TARGET PlusWidgets APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(PlusWidgets PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Project/PlusB-bin/lib/Debug/PlusWidgets.lib"
  IMPORTED_LOCATION_DEBUG "C:/Project/PlusB-bin/bin/Debug/PlusWidgets.dll"
  )

# Import target "vtkxio" for configuration "Debug"
set_property(TARGET vtkxio APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkxio PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "C:/Project/PlusB-bin/lib/Debug/vtkxio.lib"
  )

# Import target "vtkPlusCommon" for configuration "Debug"
set_property(TARGET vtkPlusCommon APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkPlusCommon PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Project/PlusB-bin/lib/Debug/vtkPlusCommon.lib"
  IMPORTED_LOCATION_DEBUG "C:/Project/PlusB-bin/bin/Debug/vtkPlusCommon.dll"
  )

# Import target "vtkPlusRendering" for configuration "Debug"
set_property(TARGET vtkPlusRendering APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkPlusRendering PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Project/PlusB-bin/lib/Debug/vtkPlusRendering.lib"
  IMPORTED_LOCATION_DEBUG "C:/Project/PlusB-bin/bin/Debug/vtkPlusRendering.dll"
  )

# Import target "vtkPlusOpenIGTLink" for configuration "Debug"
set_property(TARGET vtkPlusOpenIGTLink APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkPlusOpenIGTLink PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Project/PlusB-bin/lib/Debug/vtkPlusOpenIGTLink.lib"
  IMPORTED_LOCATION_DEBUG "C:/Project/PlusB-bin/bin/Debug/vtkPlusOpenIGTLink.dll"
  )

# Import target "vtkPlusImageProcessing" for configuration "Debug"
set_property(TARGET vtkPlusImageProcessing APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkPlusImageProcessing PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Project/PlusB-bin/lib/Debug/vtkPlusImageProcessing.lib"
  IMPORTED_LOCATION_DEBUG "C:/Project/PlusB-bin/bin/Debug/vtkPlusImageProcessing.dll"
  )

# Import target "vtkPlusUsSimulator" for configuration "Debug"
set_property(TARGET vtkPlusUsSimulator APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkPlusUsSimulator PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Project/PlusB-bin/lib/Debug/vtkPlusUsSimulator.lib"
  IMPORTED_LOCATION_DEBUG "C:/Project/PlusB-bin/bin/Debug/vtkPlusUsSimulator.dll"
  )

# Import target "vtkPlusVolumeReconstruction" for configuration "Debug"
set_property(TARGET vtkPlusVolumeReconstruction APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkPlusVolumeReconstruction PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Project/PlusB-bin/lib/Debug/vtkPlusVolumeReconstruction.lib"
  IMPORTED_LOCATION_DEBUG "C:/Project/PlusB-bin/bin/Debug/vtkPlusVolumeReconstruction.dll"
  )

# Import target "vtkPlusHaptics" for configuration "Debug"
set_property(TARGET vtkPlusHaptics APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkPlusHaptics PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Project/PlusB-bin/lib/Debug/vtkPlusHaptics.lib"
  IMPORTED_LOCATION_DEBUG "C:/Project/PlusB-bin/bin/Debug/vtkPlusHaptics.dll"
  )

# Import target "vtkPlusDataCollection" for configuration "Debug"
set_property(TARGET vtkPlusDataCollection APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkPlusDataCollection PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Project/PlusB-bin/lib/Debug/vtkPlusDataCollection.lib"
  IMPORTED_LOCATION_DEBUG "C:/Project/PlusB-bin/bin/Debug/vtkPlusDataCollection.dll"
  )

# Import target "vtkPlusCalibration" for configuration "Debug"
set_property(TARGET vtkPlusCalibration APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkPlusCalibration PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Project/PlusB-bin/lib/Debug/vtkPlusCalibration.lib"
  IMPORTED_LOCATION_DEBUG "C:/Project/PlusB-bin/bin/Debug/vtkPlusCalibration.dll"
  )

# Import target "vtkPlusServer" for configuration "Debug"
set_property(TARGET vtkPlusServer APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(vtkPlusServer PROPERTIES
  IMPORTED_IMPLIB_DEBUG "C:/Project/PlusB-bin/lib/Debug/vtkPlusServer.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "igtlioConverter"
  IMPORTED_LOCATION_DEBUG "C:/Project/PlusB-bin/bin/Debug/vtkPlusServer.dll"
  )

# Import target "PlusWidgets" for configuration "Release"
set_property(TARGET PlusWidgets APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(PlusWidgets PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Project/PlusB-bin/lib/Release/PlusWidgets.lib"
  IMPORTED_LOCATION_RELEASE "C:/Project/PlusB-bin/bin/Release/PlusWidgets.dll"
  )

# Import target "vtkxio" for configuration "Release"
set_property(TARGET vtkxio APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkxio PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "C:/Project/PlusB-bin/lib/Release/vtkxio.lib"
  )

# Import target "vtkPlusCommon" for configuration "Release"
set_property(TARGET vtkPlusCommon APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkPlusCommon PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Project/PlusB-bin/lib/Release/vtkPlusCommon.lib"
  IMPORTED_LOCATION_RELEASE "C:/Project/PlusB-bin/bin/Release/vtkPlusCommon.dll"
  )

# Import target "vtkPlusRendering" for configuration "Release"
set_property(TARGET vtkPlusRendering APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkPlusRendering PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Project/PlusB-bin/lib/Release/vtkPlusRendering.lib"
  IMPORTED_LOCATION_RELEASE "C:/Project/PlusB-bin/bin/Release/vtkPlusRendering.dll"
  )

# Import target "vtkPlusOpenIGTLink" for configuration "Release"
set_property(TARGET vtkPlusOpenIGTLink APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkPlusOpenIGTLink PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Project/PlusB-bin/lib/Release/vtkPlusOpenIGTLink.lib"
  IMPORTED_LOCATION_RELEASE "C:/Project/PlusB-bin/bin/Release/vtkPlusOpenIGTLink.dll"
  )

# Import target "vtkPlusImageProcessing" for configuration "Release"
set_property(TARGET vtkPlusImageProcessing APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkPlusImageProcessing PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Project/PlusB-bin/lib/Release/vtkPlusImageProcessing.lib"
  IMPORTED_LOCATION_RELEASE "C:/Project/PlusB-bin/bin/Release/vtkPlusImageProcessing.dll"
  )

# Import target "vtkPlusUsSimulator" for configuration "Release"
set_property(TARGET vtkPlusUsSimulator APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkPlusUsSimulator PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Project/PlusB-bin/lib/Release/vtkPlusUsSimulator.lib"
  IMPORTED_LOCATION_RELEASE "C:/Project/PlusB-bin/bin/Release/vtkPlusUsSimulator.dll"
  )

# Import target "vtkPlusVolumeReconstruction" for configuration "Release"
set_property(TARGET vtkPlusVolumeReconstruction APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkPlusVolumeReconstruction PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Project/PlusB-bin/lib/Release/vtkPlusVolumeReconstruction.lib"
  IMPORTED_LOCATION_RELEASE "C:/Project/PlusB-bin/bin/Release/vtkPlusVolumeReconstruction.dll"
  )

# Import target "vtkPlusHaptics" for configuration "Release"
set_property(TARGET vtkPlusHaptics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkPlusHaptics PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Project/PlusB-bin/lib/Release/vtkPlusHaptics.lib"
  IMPORTED_LOCATION_RELEASE "C:/Project/PlusB-bin/bin/Release/vtkPlusHaptics.dll"
  )

# Import target "vtkPlusDataCollection" for configuration "Release"
set_property(TARGET vtkPlusDataCollection APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkPlusDataCollection PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Project/PlusB-bin/lib/Release/vtkPlusDataCollection.lib"
  IMPORTED_LOCATION_RELEASE "C:/Project/PlusB-bin/bin/Release/vtkPlusDataCollection.dll"
  )

# Import target "vtkPlusCalibration" for configuration "Release"
set_property(TARGET vtkPlusCalibration APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkPlusCalibration PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Project/PlusB-bin/lib/Release/vtkPlusCalibration.lib"
  IMPORTED_LOCATION_RELEASE "C:/Project/PlusB-bin/bin/Release/vtkPlusCalibration.dll"
  )

# Import target "vtkPlusServer" for configuration "Release"
set_property(TARGET vtkPlusServer APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(vtkPlusServer PROPERTIES
  IMPORTED_IMPLIB_RELEASE "C:/Project/PlusB-bin/lib/Release/vtkPlusServer.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "igtlioConverter"
  IMPORTED_LOCATION_RELEASE "C:/Project/PlusB-bin/bin/Release/vtkPlusServer.dll"
  )

# Import target "PlusWidgets" for configuration "MinSizeRel"
set_property(TARGET PlusWidgets APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(PlusWidgets PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Project/PlusB-bin/lib/MinSizeRel/PlusWidgets.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Project/PlusB-bin/bin/MinSizeRel/PlusWidgets.dll"
  )

# Import target "vtkxio" for configuration "MinSizeRel"
set_property(TARGET vtkxio APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(vtkxio PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_MINSIZEREL "CXX"
  IMPORTED_LOCATION_MINSIZEREL "C:/Project/PlusB-bin/lib/MinSizeRel/vtkxio.lib"
  )

# Import target "vtkPlusCommon" for configuration "MinSizeRel"
set_property(TARGET vtkPlusCommon APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(vtkPlusCommon PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Project/PlusB-bin/lib/MinSizeRel/vtkPlusCommon.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Project/PlusB-bin/bin/MinSizeRel/vtkPlusCommon.dll"
  )

# Import target "vtkPlusRendering" for configuration "MinSizeRel"
set_property(TARGET vtkPlusRendering APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(vtkPlusRendering PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Project/PlusB-bin/lib/MinSizeRel/vtkPlusRendering.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Project/PlusB-bin/bin/MinSizeRel/vtkPlusRendering.dll"
  )

# Import target "vtkPlusOpenIGTLink" for configuration "MinSizeRel"
set_property(TARGET vtkPlusOpenIGTLink APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(vtkPlusOpenIGTLink PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Project/PlusB-bin/lib/MinSizeRel/vtkPlusOpenIGTLink.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Project/PlusB-bin/bin/MinSizeRel/vtkPlusOpenIGTLink.dll"
  )

# Import target "vtkPlusImageProcessing" for configuration "MinSizeRel"
set_property(TARGET vtkPlusImageProcessing APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(vtkPlusImageProcessing PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Project/PlusB-bin/lib/MinSizeRel/vtkPlusImageProcessing.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Project/PlusB-bin/bin/MinSizeRel/vtkPlusImageProcessing.dll"
  )

# Import target "vtkPlusUsSimulator" for configuration "MinSizeRel"
set_property(TARGET vtkPlusUsSimulator APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(vtkPlusUsSimulator PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Project/PlusB-bin/lib/MinSizeRel/vtkPlusUsSimulator.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Project/PlusB-bin/bin/MinSizeRel/vtkPlusUsSimulator.dll"
  )

# Import target "vtkPlusVolumeReconstruction" for configuration "MinSizeRel"
set_property(TARGET vtkPlusVolumeReconstruction APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(vtkPlusVolumeReconstruction PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Project/PlusB-bin/lib/MinSizeRel/vtkPlusVolumeReconstruction.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Project/PlusB-bin/bin/MinSizeRel/vtkPlusVolumeReconstruction.dll"
  )

# Import target "vtkPlusHaptics" for configuration "MinSizeRel"
set_property(TARGET vtkPlusHaptics APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(vtkPlusHaptics PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Project/PlusB-bin/lib/MinSizeRel/vtkPlusHaptics.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Project/PlusB-bin/bin/MinSizeRel/vtkPlusHaptics.dll"
  )

# Import target "vtkPlusDataCollection" for configuration "MinSizeRel"
set_property(TARGET vtkPlusDataCollection APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(vtkPlusDataCollection PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Project/PlusB-bin/lib/MinSizeRel/vtkPlusDataCollection.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Project/PlusB-bin/bin/MinSizeRel/vtkPlusDataCollection.dll"
  )

# Import target "vtkPlusCalibration" for configuration "MinSizeRel"
set_property(TARGET vtkPlusCalibration APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(vtkPlusCalibration PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Project/PlusB-bin/lib/MinSizeRel/vtkPlusCalibration.lib"
  IMPORTED_LOCATION_MINSIZEREL "C:/Project/PlusB-bin/bin/MinSizeRel/vtkPlusCalibration.dll"
  )

# Import target "vtkPlusServer" for configuration "MinSizeRel"
set_property(TARGET vtkPlusServer APPEND PROPERTY IMPORTED_CONFIGURATIONS MINSIZEREL)
set_target_properties(vtkPlusServer PROPERTIES
  IMPORTED_IMPLIB_MINSIZEREL "C:/Project/PlusB-bin/lib/MinSizeRel/vtkPlusServer.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_MINSIZEREL "igtlioConverter"
  IMPORTED_LOCATION_MINSIZEREL "C:/Project/PlusB-bin/bin/MinSizeRel/vtkPlusServer.dll"
  )

# Import target "PlusWidgets" for configuration "RelWithDebInfo"
set_property(TARGET PlusWidgets APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(PlusWidgets PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Project/PlusB-bin/lib/RelWithDebInfo/PlusWidgets.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Project/PlusB-bin/bin/RelWithDebInfo/PlusWidgets.dll"
  )

# Import target "vtkxio" for configuration "RelWithDebInfo"
set_property(TARGET vtkxio APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(vtkxio PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELWITHDEBINFO "CXX"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkxio.lib"
  )

# Import target "vtkPlusCommon" for configuration "RelWithDebInfo"
set_property(TARGET vtkPlusCommon APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(vtkPlusCommon PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkPlusCommon.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkPlusCommon.dll"
  )

# Import target "vtkPlusRendering" for configuration "RelWithDebInfo"
set_property(TARGET vtkPlusRendering APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(vtkPlusRendering PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkPlusRendering.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkPlusRendering.dll"
  )

# Import target "vtkPlusOpenIGTLink" for configuration "RelWithDebInfo"
set_property(TARGET vtkPlusOpenIGTLink APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(vtkPlusOpenIGTLink PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkPlusOpenIGTLink.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkPlusOpenIGTLink.dll"
  )

# Import target "vtkPlusImageProcessing" for configuration "RelWithDebInfo"
set_property(TARGET vtkPlusImageProcessing APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(vtkPlusImageProcessing PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkPlusImageProcessing.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkPlusImageProcessing.dll"
  )

# Import target "vtkPlusUsSimulator" for configuration "RelWithDebInfo"
set_property(TARGET vtkPlusUsSimulator APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(vtkPlusUsSimulator PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkPlusUsSimulator.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkPlusUsSimulator.dll"
  )

# Import target "vtkPlusVolumeReconstruction" for configuration "RelWithDebInfo"
set_property(TARGET vtkPlusVolumeReconstruction APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(vtkPlusVolumeReconstruction PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkPlusVolumeReconstruction.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkPlusVolumeReconstruction.dll"
  )

# Import target "vtkPlusHaptics" for configuration "RelWithDebInfo"
set_property(TARGET vtkPlusHaptics APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(vtkPlusHaptics PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkPlusHaptics.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkPlusHaptics.dll"
  )

# Import target "vtkPlusDataCollection" for configuration "RelWithDebInfo"
set_property(TARGET vtkPlusDataCollection APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(vtkPlusDataCollection PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkPlusDataCollection.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkPlusDataCollection.dll"
  )

# Import target "vtkPlusCalibration" for configuration "RelWithDebInfo"
set_property(TARGET vtkPlusCalibration APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(vtkPlusCalibration PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkPlusCalibration.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkPlusCalibration.dll"
  )

# Import target "vtkPlusServer" for configuration "RelWithDebInfo"
set_property(TARGET vtkPlusServer APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(vtkPlusServer PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkPlusServer.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "igtlioConverter"
  IMPORTED_LOCATION_RELWITHDEBINFO "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkPlusServer.dll"
  )

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
