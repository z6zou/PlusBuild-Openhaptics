# Install script for directory: C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/OpenIGTLink")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/igtl/igtlutil" TYPE FILE FILES
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_header.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_image.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_position.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_transform.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_types.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_util.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_capability.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_colortable.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_imgmeta.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_lbmeta.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_point.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_tdata.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_qtdata.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_trajectory.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_unit.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_sensor.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_string.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_ndarray.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_bind.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_qtrans.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_polydata.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_command.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/igtl" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/igtlutil.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/igtl" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/igtlutil.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/igtl" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/igtlutil.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/igtl" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/igtlutil.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/igtlutil.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/igtlutil.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/igtlutil.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/igtlutil.dll")
  endif()
endif()

