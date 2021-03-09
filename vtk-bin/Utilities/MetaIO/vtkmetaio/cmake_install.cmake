# Install script for directory: C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkmetaio-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkmetaio-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkmetaio-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkmetaio-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkmetaio-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkmetaio-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkmetaio-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkmetaio-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2/vtkmetaio" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/localMetaConfiguration.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaArray.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaArrow.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaBlob.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaCommand.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaContour.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaDTITube.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaEllipse.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaEvent.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaFEMObject.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaForm.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaGaussian.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaGroup.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaITKUtils.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaImage.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaImageTypes.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaImageUtils.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaLandmark.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaLine.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaMesh.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaObject.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaOutput.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaScene.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaSurface.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaTransform.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaTube.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaTubeGraph.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaTypes.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaUtils.h"
    "C:/Project/PlusB-bin/vtk/Utilities/MetaIO/vtkmetaio/metaVesselTube.h"
    "C:/Project/PlusB-bin/vtk-bin/Utilities/MetaIO/vtkmetaio/metaIOConfig.h"
    )
endif()

