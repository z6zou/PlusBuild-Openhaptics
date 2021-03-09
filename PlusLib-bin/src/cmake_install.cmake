# Install script for directory: C:/Project/PlusB-bin/PlusLib/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/PlusLib")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/PlusLib-2.8" TYPE FILE FILES
    "C:/Project/PlusB-bin/PlusLib-bin/PlusConfigure.h"
    "C:/Project/PlusB-bin/PlusLib-bin/src/PlusRevision.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/PlusLib-2.8" TYPE FILE FILES "C:/Project/PlusB-bin/bin/Release/PlusConfig.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/PlusLib-2.8/PlusLibTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/PlusLib-2.8/PlusLibTargets.cmake"
         "C:/Project/PlusB-bin/PlusLib-bin/src/CMakeFiles/Export/lib/cmake/PlusLib-2.8/PlusLibTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/PlusLib-2.8/PlusLibTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/PlusLib-2.8/PlusLibTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/PlusLib-2.8" TYPE FILE FILES "C:/Project/PlusB-bin/PlusLib-bin/src/CMakeFiles/Export/lib/cmake/PlusLib-2.8/PlusLibTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/PlusLib-2.8" TYPE FILE FILES "C:/Project/PlusB-bin/PlusLib-bin/src/CMakeFiles/Export/lib/cmake/PlusLib-2.8/PlusLibTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/PlusLib-2.8" TYPE FILE FILES "C:/Project/PlusB-bin/PlusLib-bin/src/CMakeFiles/Export/lib/cmake/PlusLib-2.8/PlusLibTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/PlusLib-2.8" TYPE FILE FILES "C:/Project/PlusB-bin/PlusLib-bin/src/CMakeFiles/Export/lib/cmake/PlusLib-2.8/PlusLibTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/PlusLib-2.8" TYPE FILE FILES "C:/Project/PlusB-bin/PlusLib-bin/src/CMakeFiles/Export/lib/cmake/PlusLib-2.8/PlusLibTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/PlusLib-2.8" TYPE FILE FILES
    "C:/Project/PlusB-bin/PlusLib-bin/CMakeFiles/install/PlusLibConfig.cmake"
    "C:/Project/PlusB-bin/PlusLib-bin/CMakeFiles/install/UsePlusLib.cmake"
    "C:/Project/PlusB-bin/PlusLib-bin/src/PlusLibConfigVersion.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusWidgets/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusLib-bin/src/Utilities/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusCommon/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusRendering/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusOpenIGTLink/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusImageProcessing/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusUsSimulator/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusVolumeReconstruction/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusDataCollection/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusCalibration/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusLib-bin/src/PlusServer/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusLib-bin/src/scripts/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusLib-bin/src/Documentation/cmake_install.cmake")

endif()

