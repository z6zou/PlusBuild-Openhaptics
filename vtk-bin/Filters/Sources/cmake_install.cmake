# Install script for directory: C:/Project/PlusB-bin/vtk/Filters/Sources

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkFiltersSources-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkFiltersSources-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkFiltersSources-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkFiltersSources-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkFiltersSources-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkFiltersSources-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkFiltersSources-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkFiltersSources-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Filters/Sources/CMakeFiles/vtkFiltersSources.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkArcSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkArrowSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkButtonSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkCellTypeSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkConeSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkCubeSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkCylinderSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkDiskSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkEllipseArcSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkEllipticalButtonSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkFrustumSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkGlyphSource2D.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkHyperTreeGridSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkLineSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkOutlineCornerFilter.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkOutlineCornerSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkOutlineSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkParametricFunctionSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkPlaneSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkPlatonicSolidSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkPointSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkPolyLineSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkProgrammableDataObjectSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkProgrammableSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkRandomHyperTreeGridSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkRectangularButtonSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkRegularPolygonSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkSelectionSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkSphereSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkSuperquadricSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkTessellatedBoxSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkTextSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkTexturedSphereSource.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkGraphToPolyData.h"
    "C:/Project/PlusB-bin/vtk/Filters/Sources/vtkDiagonalMatrixSource.h"
    "C:/Project/PlusB-bin/vtk-bin/Filters/Sources/vtkFiltersSourcesModule.h"
    )
endif()

