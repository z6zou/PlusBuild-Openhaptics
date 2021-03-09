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

set(OpenIGTLinkIO_INCLUDE_DIRS "C:/Project/PlusB-bin/OpenIGTLinkIO;C:/Project/PlusB-bin/OpenIGTLinkIO-bin;C:/Project/PlusB-bin/OpenIGTLinkIO/Logic;C:/Project/PlusB-bin/OpenIGTLinkIO/Converter;C:/Project/PlusB-bin/OpenIGTLinkIO/Devices;C:/Project/PlusB-bin/OpenIGTLinkIO/Tools")
set(OpenIGTLinkIO_LIBRARY_DIRS "C:/Project/PlusB-bin/bin")

include("C:/Project/PlusB-bin/OpenIGTLinkIO-bin/OpenIGTLinkIOTargets.cmake")

# Enable support for old style include/linking
# It is highly recommended to link to target names, thus 
#    includes/linking are handled automatically
SET(OpenIGTLinkIO_FOUND 1)
SET(OpenIGTLinkIO_LIBRARIES "igtlioLogic;igtlioDevices;igtlioConverter;igtlioTools")


