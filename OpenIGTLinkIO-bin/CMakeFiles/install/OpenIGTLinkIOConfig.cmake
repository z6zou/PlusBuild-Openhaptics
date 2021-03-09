if(NOT OpenIGTLink_FOUND)
  set(OpenIGTLink_DIR "C:/Project/PlusB-bin/OpenIGTLink-bin")
  find_package(OpenIGTLink REQUIRED NO_MODULE)
else()
  if(NOT "3.1.0" VERSION_EQUAL "${OpenIGTLink_VERSION_MAJOR}.${OpenIGTLink_VERSION_MINOR}.${OpenIGTLink_VERSION_PATCH}")
    message(SEND_ERROR "Different versions in OpenIGTLinkIO (3.1.0) and referencing project (${OpenIGTLink_VERSION_MAJOR}.${OpenIGTLink_VERSION_MINOR}.${OpenIGTLink_VERSION_PATCH}). Issues may arise.")
  endif()
endif()

if(EXISTS ${OpenIGTLink_USE_FILE})
  include(${OpenIGTLink_USE_FILE})
endif()

get_filename_component(OpenIGTLinkIO_CMAKE_PACKAGE_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)       # <prefix>/lib/cmake/igtlio
get_filename_component(_TEMP_DIRECTORY "${OpenIGTLinkIO_CMAKE_PACKAGE_DIR}" DIRECTORY)               # <prefix>/lib/cmake
get_filename_component(OpenIGTLinkIO_LIBRARY_DIR "${_TEMP_DIRECTORY}" DIRECTORY)                     # <prefix>/lib
get_filename_component(OpenIGTLinkIO_INSTALL_PREFIX "${OpenIGTLinkIO_LIBRARY_DIR}" DIRECTORY)        # <prefix>
  
set(OpenIGTLinkIO_INCLUDE_DIR "${OpenIGTLinkIO_INSTALL_PREFIX}/include/igtlio")
set(OpenIGTLinkIO_BINARY_DIR "${OpenIGTLinkIO_INSTALL_PREFIX}/bin")
set(OpenIGTLinkIO_LIBRARY_DIR "${OpenIGTLinkIO_INSTALL_PREFIX}/lib")
  
set(OpenIGTLinkIO_INCLUDE_DIRS "${OpenIGTLinkIO_INCLUDE_DIR}" "${OpenIGTLinkIO_INCLUDE_DIR}/DeviceWidgets")
set(OpenIGTLinkIO_LIBRARY_DIRS "${OpenIGTLinkIO_BINARY_DIR} ${OpenIGTLinkIO_LIBRARY_DIR}")

include("${OpenIGTLinkIO_CMAKE_PACKAGE_DIR}/OpenIGTLinkIOTargets.cmake")

# Enable support for old style include/linking
# It is highly recommended to link to target names, thus 
#    includes/linking are handled automatically
SET(OpenIGTLinkIO_FOUND 1)
SET(OpenIGTLinkIO_LIBRARIES "igtlioLogic;igtlioDevices;igtlioConverter;igtlioTools")


