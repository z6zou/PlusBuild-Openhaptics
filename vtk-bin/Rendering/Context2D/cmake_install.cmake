# Install script for directory: C:/Project/PlusB-bin/vtk/Rendering/Context2D

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkRenderingContext2D-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkRenderingContext2D-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkRenderingContext2D-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkRenderingContext2D-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkRenderingContext2D-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkRenderingContext2D-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkRenderingContext2D-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkRenderingContext2D-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Rendering/Context2D/CMakeFiles/vtkRenderingContext2D.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkAbstractContextBufferId.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkAbstractContextItem.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkBlockItem.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkBrush.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkContext2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkContext3D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkContextActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkContextClip.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkContextDevice2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkContextDevice3D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkContextItem.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkContextKeyEvent.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkContextMapper2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkContextMouseEvent.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkContextScene.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkContextTransform.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkImageItem.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkMarkerUtilities.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkLabeledContourPolyDataItem.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkPen.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkPolyDataItem.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkPropItem.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Context2D/vtkTooltipItem.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/Context2D/vtkRenderingContext2DModule.h"
    )
endif()

