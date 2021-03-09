# Install script for directory: C:/Project/PlusB-bin/vtk/Filters/FlowPaths

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkFiltersFlowPaths-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkFiltersFlowPaths-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkFiltersFlowPaths-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkFiltersFlowPaths-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkFiltersFlowPaths-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkFiltersFlowPaths-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkFiltersFlowPaths-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkFiltersFlowPaths-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Filters/FlowPaths/CMakeFiles/vtkFiltersFlowPaths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkAbstractInterpolatedVelocityField.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkAMRInterpolatedVelocityField.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkCachingInterpolatedVelocityField.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkCellLocatorInterpolatedVelocityField.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkCompositeInterpolatedVelocityField.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkEvenlySpacedStreamlines2D.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkInterpolatedVelocityField.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkLagrangianParticleTracker.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkLagrangianBasicIntegrationModel.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkLagrangianParticle.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkLagrangianMatidaIntegrationModel.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkModifiedBSPTree.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkParticlePathFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkParticleTracer.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkParticleTracerBase.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkStreaklineFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkStreamTracer.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkTemporalInterpolatedVelocityField.h"
    "C:/Project/PlusB-bin/vtk/Filters/FlowPaths/vtkTemporalStreamTracer.h"
    "C:/Project/PlusB-bin/vtk-bin/Filters/FlowPaths/vtkFiltersFlowPathsModule.h"
    )
endif()

