# Install script for directory: C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDebugDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/Debug/itkgdcmCommon-4.12D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/Release/itkgdcmCommon-4.12.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/MinSizeRel/itkgdcmCommon-4.12.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/itkgdcmCommon-4.12.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.12" TYPE FILE FILES
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmASN1.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmBase64.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmBoxRegion.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmByteSwap.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmByteSwap.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmCAPICryptoFactory.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmCAPICryptographicMessageSyntax.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmCommand.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmCryptoFactory.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmCryptographicMessageSyntax.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmDataEvent.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmDeflateStream.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmDirectory.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmDummyValueGenerator.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmEvent.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmException.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmFileNameEvent.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmFilename.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmFilenameGenerator.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmLegacyMacro.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmMD5.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmObject.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmOpenSSLCryptoFactory.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmOpenSSLCryptographicMessageSyntax.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmOpenSSLP7CryptoFactory.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmOpenSSLP7CryptographicMessageSyntax.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmProgressEvent.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmRegion.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSHA1.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSmartPointer.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmStaticAssert.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmString.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSubject.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSwapCode.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSwapper.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSwapper.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSystem.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmTerminal.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmTestDriver.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmTesting.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmTrace.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmTypes.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmUnpacker12Bits.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmVersion.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmWin32.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/zipstreamimpl.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xHeadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.12" TYPE FILE FILES
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmASN1.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmBase64.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmBoxRegion.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmByteSwap.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmByteSwap.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmCAPICryptoFactory.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmCAPICryptographicMessageSyntax.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmCommand.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmCryptoFactory.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmCryptographicMessageSyntax.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmDataEvent.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmDeflateStream.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmDirectory.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmDummyValueGenerator.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmEvent.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmException.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmFileNameEvent.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmFilename.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmFilenameGenerator.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmLegacyMacro.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmMD5.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmObject.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmOpenSSLCryptoFactory.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmOpenSSLCryptographicMessageSyntax.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmOpenSSLP7CryptoFactory.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmOpenSSLP7CryptographicMessageSyntax.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmProgressEvent.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmRegion.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSHA1.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSmartPointer.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmStaticAssert.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmString.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSubject.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSwapCode.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSwapper.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSwapper.txx"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmSystem.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmTerminal.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmTestDriver.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmTesting.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmTrace.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmTypes.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmUnpacker12Bits.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmVersion.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmWin32.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/zipstreamimpl.h"
    "C:/Project/PlusB-bin/itk-bin/Modules/ThirdParty/GDCM/src/gdcm/Source/Common/gdcmConfigure.h"
    )
endif()

