#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "igtlioConverter" for configuration "Release"
set_property(TARGET igtlioConverter APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(igtlioConverter PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/igtlioConverter.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/igtlioConverter.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS igtlioConverter )
list(APPEND _IMPORT_CHECK_FILES_FOR_igtlioConverter "${_IMPORT_PREFIX}/lib/igtlioConverter.lib" "${_IMPORT_PREFIX}/bin/igtlioConverter.dll" )

# Import target "igtlioDevices" for configuration "Release"
set_property(TARGET igtlioDevices APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(igtlioDevices PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/igtlioDevices.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/igtlioDevices.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS igtlioDevices )
list(APPEND _IMPORT_CHECK_FILES_FOR_igtlioDevices "${_IMPORT_PREFIX}/lib/igtlioDevices.lib" "${_IMPORT_PREFIX}/bin/igtlioDevices.dll" )

# Import target "igtlioLogic" for configuration "Release"
set_property(TARGET igtlioLogic APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(igtlioLogic PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/igtlioLogic.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/igtlioLogic.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS igtlioLogic )
list(APPEND _IMPORT_CHECK_FILES_FOR_igtlioLogic "${_IMPORT_PREFIX}/lib/igtlioLogic.lib" "${_IMPORT_PREFIX}/bin/igtlioLogic.dll" )

# Import target "igtlioTools" for configuration "Release"
set_property(TARGET igtlioTools APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(igtlioTools PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/igtlioTools.lib"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/igtlioTools.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS igtlioTools )
list(APPEND _IMPORT_CHECK_FILES_FOR_igtlioTools "${_IMPORT_PREFIX}/lib/igtlioTools.lib" "${_IMPORT_PREFIX}/bin/igtlioTools.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
