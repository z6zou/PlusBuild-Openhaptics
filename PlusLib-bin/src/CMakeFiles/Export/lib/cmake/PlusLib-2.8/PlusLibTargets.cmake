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
foreach(_expectedTarget PlusWidgets sphereEstimation planeEstimation vtkxio EditSequenceFile vtkPlusCommon vtkPlusRendering vtkPlusOpenIGTLink RfProcessor DrawScanLines ExtractScanLines ScanConvert EnhanceUsTrpSequence vtkPlusImageProcessing vtkPlusUsSimulator vtkPlusVolumeReconstruction vtkPlusHaptics PlusVersion ViewSequenceFile vtkPlusDataCollection ConvertFcsvToXml ConvertXmlToFcsv TemporalCalibration ProbeCalibration vtkPlusCalibration vtkPlusServer PlusServer PlusServerRemoteControl)
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


# Compute the installation prefix relative to this file.
get_filename_component(_IMPORT_PREFIX "${CMAKE_CURRENT_LIST_FILE}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
get_filename_component(_IMPORT_PREFIX "${_IMPORT_PREFIX}" PATH)
if(_IMPORT_PREFIX STREQUAL "/")
  set(_IMPORT_PREFIX "")
endif()

# Create imported target PlusWidgets
add_library(PlusWidgets SHARED IMPORTED)

set_target_properties(PlusWidgets PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8"
  INTERFACE_LINK_LIBRARIES "Qt5::Xml;Qt5::Widgets;vtkGUISupportQt;vtkPlusCalibration;vtkPlusCommon;vtkPlusDataCollection"
)

# Create imported target sphereEstimation
add_executable(sphereEstimation IMPORTED)

set_target_properties(sphereEstimation PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8"
)

# Create imported target planeEstimation
add_executable(planeEstimation IMPORTED)

set_target_properties(planeEstimation PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8"
)

# Create imported target vtkxio
add_library(vtkxio STATIC IMPORTED)

set_target_properties(vtkxio PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8/vtkxio"
)

# Create imported target EditSequenceFile
add_executable(EditSequenceFile IMPORTED)

# Create imported target vtkPlusCommon
add_library(vtkPlusCommon SHARED IMPORTED)

set_target_properties(vtkPlusCommon PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8"
  INTERFACE_LINK_LIBRARIES "vtkCommonCore;vtkCommonDataModel;vtkImagingCore;vtkIOXMLParser;vtkIOImage;vtkCommonSystem;vtksys;itksys;vtkzlib;ITKIONIFTI;ITKIONRRD;ITKIOGIPL;ITKIOHDF5;ITKIOJPEG;ITKIOGDCM;ITKIOBMP;ITKIOLSM;ITKIOTIFF;ITKIOPNG;ITKIOVTK;ITKIOGE;ITKIOMRC;ITKIOBioRad;ITKIOStimulate;ITKIOMeta;itkvnl;itkvnl_algo;igtlioConverter;Winmm;OpenIGTLink"
)

# Create imported target vtkPlusRendering
add_library(vtkPlusRendering SHARED IMPORTED)

set_target_properties(vtkPlusRendering PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8"
  INTERFACE_LINK_LIBRARIES "vtkPlusCommon;vtkCommonCore;vtkFiltersSources;vtkChartsCore;vtkViewsContext2D;vtkIOCore;vtkInteractionStyle;vtkRenderingFreeType;vtkRenderingAnnotation;vtkRenderingOpenGL2;vtkRenderingContextOpenGL2"
)

# Create imported target vtkPlusOpenIGTLink
add_library(vtkPlusOpenIGTLink SHARED IMPORTED)

set_target_properties(vtkPlusOpenIGTLink PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8"
  INTERFACE_LINK_LIBRARIES "vtkPlusCommon;OpenIGTLink;igtlioConverter"
)

# Create imported target RfProcessor
add_executable(RfProcessor IMPORTED)

# Create imported target DrawScanLines
add_executable(DrawScanLines IMPORTED)

# Create imported target ExtractScanLines
add_executable(ExtractScanLines IMPORTED)

# Create imported target ScanConvert
add_executable(ScanConvert IMPORTED)

# Create imported target EnhanceUsTrpSequence
add_executable(EnhanceUsTrpSequence IMPORTED)

# Create imported target vtkPlusImageProcessing
add_library(vtkPlusImageProcessing SHARED IMPORTED)

set_target_properties(vtkPlusImageProcessing PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8"
  INTERFACE_LINK_LIBRARIES "vtkPlusCommon;vtkImagingStatistics;vtkImagingGeneral;vtkImagingMorphological"
)

# Create imported target vtkPlusUsSimulator
add_library(vtkPlusUsSimulator SHARED IMPORTED)

set_target_properties(vtkPlusUsSimulator PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8"
  INTERFACE_LINK_LIBRARIES "vtkPlusCommon;vtkPlusRendering;vtkPlusImageProcessing;vtkFiltersSources;vtkFiltersFlowPaths;vtkIOGeometry;vtkIOXML"
)

# Create imported target vtkPlusVolumeReconstruction
add_library(vtkPlusVolumeReconstruction SHARED IMPORTED)

set_target_properties(vtkPlusVolumeReconstruction PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8"
  INTERFACE_LINK_LIBRARIES "vtkPlusCommon;vtkInteractionStyle;vtkRenderingFreeType;vtkRenderingOpenGL2;vtkRenderingVolumeOpenGL2"
)

# Create imported target vtkPlusHaptics
add_library(vtkPlusHaptics SHARED IMPORTED)

set_target_properties(vtkPlusHaptics PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8"
  INTERFACE_LINK_LIBRARIES "vtkCommonCore;vtkCommonDataModel;vtksys"
)

# Create imported target PlusVersion
add_executable(PlusVersion IMPORTED)

# Create imported target ViewSequenceFile
add_executable(ViewSequenceFile IMPORTED)

# Create imported target vtkPlusDataCollection
add_library(vtkPlusDataCollection SHARED IMPORTED)

set_target_properties(vtkPlusDataCollection PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8"
  INTERFACE_LINK_LIBRARIES "\$<\$<NOT:\$<CONFIG:DEBUG>>:C:/Project/OpenHaptics/lib/x64/Release/hd.lib>;\$<\$<NOT:\$<CONFIG:DEBUG>>:C:/Project/OpenHaptics/lib/x64/Release/hl.lib>;\$<\$<NOT:\$<CONFIG:DEBUG>>:C:/Project/OpenHaptics/utilities/lib/x64/Release/hdu.lib>;\$<\$<NOT:\$<CONFIG:DEBUG>>:C:/Project/OpenHaptics/utilities/lib/x64/Release/hlu.lib>;\$<\$<CONFIG:DEBUG>:C:/Project/OpenHaptics/lib/x64/Debug/hd.lib>;\$<\$<CONFIG:DEBUG>:C:/Project/OpenHaptics/lib/x64/Debug/hl.lib>;\$<\$<CONFIG:DEBUG>:C:/Project/OpenHaptics/utilities/lib/x64/Debug/hdu.lib>;\$<\$<CONFIG:DEBUG>:C:/Project/OpenHaptics/utilities/lib/x64/Debug/hlu.lib>;OpenIGTLink;vtkPlusOpenIGTLink;vtkPlusRendering;vtkPlusCommon;vtkPlusUsSimulator;vtkPlusVolumeReconstruction;vtkPlusImageProcessing"
)

# Create imported target ConvertFcsvToXml
add_executable(ConvertFcsvToXml IMPORTED)

# Create imported target ConvertXmlToFcsv
add_executable(ConvertXmlToFcsv IMPORTED)

# Create imported target TemporalCalibration
add_executable(TemporalCalibration IMPORTED)

# Create imported target ProbeCalibration
add_executable(ProbeCalibration IMPORTED)

# Create imported target vtkPlusCalibration
add_library(vtkPlusCalibration SHARED IMPORTED)

set_target_properties(vtkPlusCalibration PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8"
  INTERFACE_LINK_LIBRARIES "ITKCommon;ITKIOImageBase;ITKOptimizers;ITKTransform;vtkInteractionStyle;vtkRenderingFreeType;vtkFiltersStatistics;vtkPlusRendering;vtkPlusCommon"
)

# Create imported target vtkPlusServer
add_library(vtkPlusServer SHARED IMPORTED)

set_target_properties(vtkPlusServer PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${_IMPORT_PREFIX}/include/PlusLib-2.8"
  INTERFACE_LINK_LIBRARIES "vtkPlusCommon;vtkPlusDataCollection;vtkPlusVolumeReconstruction;vtkIOPLY"
)

# Create imported target PlusServer
add_executable(PlusServer IMPORTED)

# Create imported target PlusServerRemoteControl
add_executable(PlusServerRemoteControl IMPORTED)

if(CMAKE_VERSION VERSION_LESS 2.8.12)
  message(FATAL_ERROR "This file relies on consumers using CMake 2.8.12 or greater.")
endif()

# Load information for each installed configuration.
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
file(GLOB CONFIG_FILES "${_DIR}/PlusLibTargets-*.cmake")
foreach(f ${CONFIG_FILES})
  include(${f})
endforeach()

# Cleanup temporary variables.
set(_IMPORT_PREFIX)

# Loop over all imported files and verify that they actually exist
foreach(target ${_IMPORT_CHECK_TARGETS} )
  foreach(file ${_IMPORT_CHECK_FILES_FOR_${target}} )
    if(NOT EXISTS "${file}" )
      message(FATAL_ERROR "The imported target \"${target}\" references the file
   \"${file}\"
but this file does not exist.  Possible reasons include:
* The file was deleted, renamed, or moved to another location.
* An install or uninstall procedure did not complete successfully.
* The installation package was faulty and contained
   \"${CMAKE_CURRENT_LIST_FILE}\"
but not all the files it references.
")
    endif()
  endforeach()
  unset(_IMPORT_CHECK_FILES_FOR_${target})
endforeach()
unset(_IMPORT_CHECK_TARGETS)

# This file does not depend on other imported targets which have
# been exported from the same project but in a separate export set.

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
cmake_policy(POP)
