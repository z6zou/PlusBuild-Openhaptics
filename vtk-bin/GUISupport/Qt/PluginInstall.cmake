# Configured file and directory locations.
set(VTK_LIB_DIR "C:/Project/PlusB-bin/bin")
set(VTK_INSTALL_QT_DIR "plugins/designer")
set(VTK_INSTALL_QT_PLUGIN_DIR "${CMAKE_INSTALL_PREFIX}/${VTK_INSTALL_QT_DIR}")
set(BUILDTYPE_SUFFIX)
if (WIN32)
  if (BUILD_TYPE STREQUAL "Debug")
    set(BUILDTYPE_SUFFIX D)
  else ()
    set(BUILDTYPE_SUFFIX )
  endif ()
endif ()
set(VTK_INSTALL_QT_PLUGIN_FILE "QVTKWidgetPlugin${BUILDTYPE_SUFFIX}.dll")
set(VTK_CONFIGURATIONS "Debug;Release;MinSizeRel;RelWithDebInfo")

if(VTK_CONFIGURATIONS)
  set(VTK_LIBSUBDIR "/${BUILD_TYPE}")
endif()

# Install the file to the specified location.
file(INSTALL DESTINATION "${VTK_INSTALL_QT_PLUGIN_DIR}" TYPE SHARED_LIBRARY
  FILES "${VTK_LIB_DIR}${VTK_LIBSUBDIR}/${VTK_INSTALL_QT_PLUGIN_FILE}")
