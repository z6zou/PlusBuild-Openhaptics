# Install script for directory: C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/Debug/ITKMetaIO-4.12D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/Release/ITKMetaIO-4.12.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/MinSizeRel/ITKMetaIO-4.12.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/ITKMetaIO-4.12.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.12" TYPE FILE FILES
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/localMetaConfiguration.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaArray.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaArrow.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaBlob.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaCommand.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaContour.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaDTITube.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaEllipse.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaEvent.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaFEMObject.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaForm.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaGaussian.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaGroup.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaITKUtils.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaImage.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaImageTypes.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaImageUtils.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaLandmark.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaLine.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaMesh.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaObject.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaOutput.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaScene.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaSurface.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaTransform.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaTube.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaTubeGraph.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaTypes.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaUtils.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaVesselTube.h"
    "C:/Project/PlusB-bin/itk-bin/Modules/ThirdParty/MetaIO/src/MetaIO/src/metaIOConfig.h"
    )
endif()

