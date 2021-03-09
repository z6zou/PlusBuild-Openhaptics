# Install script for directory: C:/Project/PlusB-bin/OpenIGTLink/Source

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/igtl" TYPE FILE FILES
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_header.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_image.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_position.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_transform.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_types.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_util.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_capability.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_win32header.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlMessageHandler.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlMessageHandlerMacro.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlCapabilityMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlClientSocket.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlConditionVariable.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlCreateObjectFunction.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlFastMutexLock.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlImageMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlImageMessage2.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlLightObject.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlMacro.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlMath.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlMessageBase.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlMessageFactory.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlMessageHeader.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlMultiThreader.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlMutexLock.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlObjectFactory.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlOSUtil.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlObject.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlObjectFactoryBase.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlPositionMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlServerSocket.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlSessionManager.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlSimpleFastMutexLock.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlSmartPointer.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlSocket.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlStatusMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlTimeStamp.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlTransformMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlTypes.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlWin32Header.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlWindows.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlCommon.h"
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
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlColorTableMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlImageMetaMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlLabelMetaMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlPointMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlTrackingDataMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlPolyDataMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlQuaternionTrackingDataMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlTrajectoryMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlStringMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlUnit.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlSensorMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlBindMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlNDArrayMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlCommandMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlQueryMessage.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_command.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlutil/igtl_query.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlMessageRTPWrapper.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlGeneralSocket.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlUDPClientSocket.h"
    "C:/Project/PlusB-bin/OpenIGTLink/Source/igtlUDPServerSocket.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/igtl" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/OpenIGTLink.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/igtl" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/OpenIGTLink.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/igtl" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/OpenIGTLink.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/igtl" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/OpenIGTLink.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/OpenIGTLink.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/OpenIGTLink.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/OpenIGTLink.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/OpenIGTLink.dll")
  endif()
endif()

