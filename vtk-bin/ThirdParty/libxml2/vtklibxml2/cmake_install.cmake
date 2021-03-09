# Install script for directory: C:/Project/PlusB-bin/vtk/ThirdParty/libxml2/vtklibxml2

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtklibxml2-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtklibxml2-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtklibxml2-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtklibxml2-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtklibxml2-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtklibxml2-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtklibxml2-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtklibxml2-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2/vtklibxml2/libxml" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlversion.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/DOCBparser.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/HTMLparser.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/HTMLtree.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/SAX.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/SAX2.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/c14n.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/catalog.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/chvalid.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/debugXML.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/dict.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/encoding.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/entities.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/globals.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/hash.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/list.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/nanoftp.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/nanohttp.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/parser.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/parserInternals.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/pattern.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/relaxng.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/schemasInternals.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/schematron.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/threads.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/tree.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/uri.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/valid.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/vtk_libxml2_mangle.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xinclude.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xlink.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlIO.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlautomata.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlerror.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlexports.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlmemory.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlmodule.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlreader.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlregexp.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlsave.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlschemas.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlschemastypes.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlstring.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlunicode.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xmlwriter.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xpath.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xpathInternals.h"
    "C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/vtklibxml2/libxml/xpointer.h"
    )
endif()

