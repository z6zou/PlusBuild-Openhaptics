# Install script for directory: C:/Project/PlusB-bin/vtk/GUISupport/Qt

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkGUISupportQt-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkGUISupportQt-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkGUISupportQt-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkGUISupportQt-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkGUISupportQt-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkGUISupportQt-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkGUISupportQt-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkGUISupportQt-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/GUISupport/Qt/CMakeFiles/vtkGUISupportQt.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/QFilterTreeProxyModel.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/QVTKApplication.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/QVTKInteractorAdapter.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/QVTKInteractor.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/vtkEventQtSlotConnect.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/vtkQtAbstractModelAdapter.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/vtkQtAnnotationLayersModelAdapter.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/vtkQtConnection.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/vtkQtDebugLeaksModel.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/vtkQtDebugLeaksView.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/vtkQtTableModelAdapter.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/vtkQtTreeModelAdapter.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/QVTKOpenGLNativeWidget.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/QVTKOpenGLWidget.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/QVTKOpenGLWindow.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/QVTKPaintEngine.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/QVTKWidget.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/QVTKWin32Header.h"
    "C:/Project/PlusB-bin/vtk/GUISupport/Qt/QVTKInteractorInternal.h"
    "C:/Project/PlusB-bin/vtk-bin/GUISupport/Qt/vtkGUISupportQtModule.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xx" OR NOT CMAKE_INSTALL_COMPONENT)
  include("C:/Project/PlusB-bin/vtk-bin/GUISupport/Qt/PluginInstall.cmake")
endif()

