# Install script for directory: C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src

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
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkhdf5-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkhdf5-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkhdf5-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkhdf5-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkhdf5-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkhdf5-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkhdf5-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkhdf5-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2/vtkhdf5/src" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/hdf5.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5api_adpt.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5public.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/vtk_hdf5_mangle.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Apkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Apublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5ACpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5ACpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Bpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Bpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5B2pkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5B2public.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Cpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Cpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Dpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Dpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Epkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Epublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5EApkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Fpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Fpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FApkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FDcore.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FDdirect.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FDfamily.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FDlog.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FDmpi.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FDmpio.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FDmulti.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FDpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FDpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FDsec2.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FDstdio.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FDwindows.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FSpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5FSpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Gpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Gpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5HFpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5HFpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5HGpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5HGpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5HLpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5HLpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Ipkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Ipublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Lpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Lpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5MMpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5MPpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Opkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Opublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Oshared.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Ppkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Ppublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5PBpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5PLextern.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5PLpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5PLpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Rpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Rpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Spkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Spublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5SMpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Tpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Tpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Zpkg.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Zpublic.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/vtk_hdf5_mangle.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Edefin.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Einit.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Epubgen.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5Eterm.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5version.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/hdf5/vtkhdf5/src/H5overflow.h"
    )
endif()

