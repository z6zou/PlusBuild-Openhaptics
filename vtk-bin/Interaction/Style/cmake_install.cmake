# Install script for directory: C:/Project/PlusB-bin/vtk/Interaction/Style

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkInteractionStyle-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkInteractionStyle-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkInteractionStyle-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkInteractionStyle-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkInteractionStyle-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkInteractionStyle-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkInteractionStyle-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkInteractionStyle-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Interaction/Style/CMakeFiles/vtkInteractionStyle.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleDrawPolygon.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleFlight.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleImage.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleJoystickActor.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleJoystickCamera.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleMultiTouchCamera.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleRubberBand2D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleRubberBand3D.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleRubberBandPick.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleRubberBandZoom.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleTerrain.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleTrackballActor.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleTrackballCamera.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleTrackball.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleUnicam.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleUser.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkInteractorStyleSwitch.h"
    "C:/Project/PlusB-bin/vtk/Interaction/Style/vtkParallelCoordinatesInteractorStyle.h"
    "C:/Project/PlusB-bin/vtk-bin/Interaction/Style/vtkInteractionStyleObjectFactory.h"
    "C:/Project/PlusB-bin/vtk-bin/Interaction/Style/vtkInteractionStyleModule.h"
    )
endif()

