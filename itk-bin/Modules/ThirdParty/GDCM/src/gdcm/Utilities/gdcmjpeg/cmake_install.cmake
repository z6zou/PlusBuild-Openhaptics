# Install script for directory: C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Project/PlusB-bin/itk-int")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.12/gdcmjpeg" TYPE FILE FILES
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jchuff.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jconfig.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jdct.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jdhuff.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jerror.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jinclude.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jlossls.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jlossy.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jmemsys.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jmorecfg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jpegint.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jpeglib.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/jversion.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Project/PlusB-bin/itk-bin/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/8/cmake_install.cmake")
  include("C:/Project/PlusB-bin/itk-bin/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/12/cmake_install.cmake")
  include("C:/Project/PlusB-bin/itk-bin/Modules/ThirdParty/GDCM/src/gdcm/Utilities/gdcmjpeg/16/cmake_install.cmake")

endif()

