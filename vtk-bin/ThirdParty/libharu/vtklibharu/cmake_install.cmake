# Install script for directory: C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Project/PlusB-bin/vtk-int")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2/vtklibharu/include" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_types.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_consts.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_version.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_annotation.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_catalog.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_conf.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_destination.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_doc.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_encoder.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_encrypt.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_encryptdict.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_error.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_ext_gstate.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_font.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_fontdef.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_gstate.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_image.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_info.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_list.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_mmgr.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_objects.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_outline.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_pages.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_page_label.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_streams.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_u3d.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_utils.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_pdfa.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_3dmeasure.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/hpdf_exdata.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/libharu/vtklibharu/include/vtk_haru_mangle.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libharu/vtklibharu/include/hpdf_config.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/libharu/vtklibharu/src/cmake_install.cmake")

endif()

