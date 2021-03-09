#-----------------------------------------------------------------------------
#
# IGSIOConfig.cmake - IGSIO CMake configuration file for external projects.
#

# The vtkIGSIOCommon include file directories
SET(VTKIGSIOCOMMON_INCLUDE_DIRS "C:/Project/PlusB-bin/IGSIO/Source/IGSIOCommon;C:/Project/PlusB-bin/IGSIO-bin/inner-build/Source/IGSIOCommon;C:/Project/PlusB-bin/IGSIO-bin/inner-build;C:/Project/PlusB-bin/IGSIO-bin/vtkAddon;C:/Project/PlusB-bin/IGSIO-bin/vtkAddon-bin")

# The vtkSequenceIO include file directories.
SET(VTKSEQUENCEIO_INCLUDE_DIRS "C:/Project/PlusB-bin/IGSIO/Source/SequenceIO;C:/Project/PlusB-bin/IGSIO-bin/inner-build/Source/SequenceIO")

# The vtkVolumeReconstruction include file directories.
SET(VTKVOLUMERECONSTRUCTION_INCLUDE_DIRS "C:/Project/PlusB-bin/IGSIO/Source/VolumeReconstruction;C:/Project/PlusB-bin/IGSIO-bin/inner-build/Source/VolumeReconstruction;C:/Project/PlusB-bin/IGSIO/Source/SequenceIO;C:/Project/PlusB-bin/IGSIO-bin/inner-build/Source/SequenceIO")

SET(VTK_DIR "C:/Project/PlusB-bin/vtk-int/lib/cmake/vtk-8.2")

SET(VP9_DIR "")

IF (NOT OFF)
  SET(vtkAddon_DIR "C:/Project/PlusB-bin/IGSIO-bin/vtkAddon-bin")
  FIND_PACKAGE(vtkAddon REQUIRED)
ENDIF()

SET(IGSIO_BUILD_SEQUENCEIO "ON")
SET(IGSIO_SEQUENCEIO_ENABLE_MKV "OFF")
SET(IGSIO_BUILD_VOLUMERECONSTRUCTION "ON")
SET(IGSIO_USE_VP9 "OFF")

# The IGSIO library targets.
SET(IGSIO_LIBRARY_TARGETS_FILE "C:/Project/PlusB-bin/IGSIO-bin/inner-build/IGSIOTargets.cmake")
INCLUDE(${IGSIO_LIBRARY_TARGETS_FILE})
