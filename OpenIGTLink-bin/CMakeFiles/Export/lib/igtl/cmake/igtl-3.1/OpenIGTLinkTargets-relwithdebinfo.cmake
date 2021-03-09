#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "igtlutil" for configuration "RelWithDebInfo"
set_property(TARGET igtlutil APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(igtlutil PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/igtl/igtlutil.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/igtlutil.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS igtlutil )
list(APPEND _IMPORT_CHECK_FILES_FOR_igtlutil "${_IMPORT_PREFIX}/lib/igtl/igtlutil.lib" "${_IMPORT_PREFIX}/bin/igtlutil.dll" )

# Import target "OpenIGTLink" for configuration "RelWithDebInfo"
set_property(TARGET OpenIGTLink APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(OpenIGTLink PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/igtl/OpenIGTLink.lib"
  IMPORTED_LINK_INTERFACE_LIBRARIES_RELWITHDEBINFO "ws2_32;wsock32"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/OpenIGTLink.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS OpenIGTLink )
list(APPEND _IMPORT_CHECK_FILES_FOR_OpenIGTLink "${_IMPORT_PREFIX}/lib/igtl/OpenIGTLink.lib" "${_IMPORT_PREFIX}/bin/OpenIGTLink.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
