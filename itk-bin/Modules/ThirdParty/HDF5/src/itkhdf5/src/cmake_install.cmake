# Install script for directory: C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.12/itkhdf5" TYPE FILE FILES
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/hdf5.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5api_adpt.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5public.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5version.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5overflow.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Apkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Apublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5ACpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5ACpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5B2pkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5B2public.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Bpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Bpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Dpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Dpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Edefin.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Einit.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Epkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Epubgen.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Epublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Eterm.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Fpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Fpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDcore.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDdirect.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDfamily.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDlog.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDmpi.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDmpio.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDmulti.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDsec2.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDstdio.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FSpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FSpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Gpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Gpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HFpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HFpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HGpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HGpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HLpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HLpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5MPpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Opkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Opublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Oshared.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Ppkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Ppublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5PLextern.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5PLpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Rpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Rpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Spkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Spublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5SMpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Tpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Tpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Zpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Zpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Cpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Cpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Ipkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Ipublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Lpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Lpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5MMpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Rpkg.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Rpublic.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDwindows.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5private.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Aprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5ACprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5B2private.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Bprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5CSprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Dprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Eprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FDprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Fprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FLprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FOprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5MFprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5MMprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Cprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5FSprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Gprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HFprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HGprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HLprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5HPprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Iprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Lprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5MPprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Oprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Pprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5PLprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5RCprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Rprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5RSprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5SLprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5SMprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Sprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5STprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Tprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5TSprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5VMprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5WBprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5Zprivate.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/src/H5win32defs.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xlibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/Debug/libitkhdf5_DD.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/Release/libitkhdf5.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/MinSizeRel/libitkhdf5.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/libitkhdf5.lib")
  endif()
endif()

