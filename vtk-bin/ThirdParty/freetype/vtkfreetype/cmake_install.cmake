# Install script for directory: C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkfreetype-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkfreetype-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkfreetype-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkfreetype-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkfreetype-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkfreetype-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkfreetype-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkfreetype-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2/vtkfreetype/include" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/ft2build.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/vtk_freetype_mangle.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/vtk_ftmodule.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/freetype/vtkfreetype/include/vtkFreeTypeConfig.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2/vtkfreetype/include/freetype" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/freetype.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftadvanc.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftbbox.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftbdf.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftbitmap.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftbzip2.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftcache.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftchapters.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftcid.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/fterrdef.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/fterrors.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftgasp.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftglyph.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftgxval.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftgzip.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftimage.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftincrem.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftlcdfil.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftlist.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftlzw.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftmac.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftmm.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftmodapi.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftmoderr.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftotval.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftoutln.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftpfr.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftrender.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftsizes.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftsnames.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftstroke.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftsynth.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftsystem.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/fttrigon.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/fttypes.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftwinfnt.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ftxf86.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/t1tables.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ttnameid.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/tttables.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/tttags.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/ttunpat.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2/vtkfreetype/include/freetype/config" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/config/ftconfig.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/config/ftheader.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/config/ftmodule.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/config/ftoption.h"
    "C:/Project/PlusB-bin/vtk/ThirdParty/freetype/vtkfreetype/include/freetype/config/ftstdlib.h"
    )
endif()

