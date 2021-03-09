# Install script for directory: C:/Project/PlusB-bin/vtk

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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk-bin/CMakeFiles/VTKConfig.cmake"
    "C:/Project/PlusB-bin/vtk-bin/VTKConfigVersion.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkexportheader.cmake.in"
    "C:/Project/PlusB-bin/vtk/CMake/VTKGenerateExportHeader.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkInitializeBuildType.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/pythonmodules.h.in"
    "C:/Project/PlusB-bin/vtk/CMake/UseVTK.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/TopologicalSort.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtk-forward.c.in"
    "C:/Project/PlusB-bin/vtk/CMake/vtkGroups.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkEncodeString.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkForwardingExecutable.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkHashSource.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkJavaWrapping.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkModuleAPI.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkModuleHeaders.cmake.in"
    "C:/Project/PlusB-bin/vtk/CMake/vtkModuleInfo.cmake.in"
    "C:/Project/PlusB-bin/vtk/CMake/vtkModuleMacros.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkModuleMacrosPython.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkMPI.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkExternalModuleMacros.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkObjectFactory.cxx.in"
    "C:/Project/PlusB-bin/vtk/CMake/vtkObjectFactory.h.in"
    "C:/Project/PlusB-bin/vtk/CMake/vtkPythonPackages.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkPythonWrapping.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkTargetLinkLibrariesWithDynamicLookup.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkThirdParty.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkWrapHierarchy.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkWrapJava.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkWrapperInit.data.in"
    "C:/Project/PlusB-bin/vtk/CMake/vtkWrapping.cmake"
    "C:/Project/PlusB-bin/vtk/CMake/vtkWrapPython.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/VTKTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/VTKTargets.cmake"
         "C:/Project/PlusB-bin/vtk-bin/CMakeFiles/Export/lib/cmake/vtk-8.2/VTKTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/VTKTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/VTKTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/CMakeFiles/Export/lib/cmake/vtk-8.2/VTKTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/CMakeFiles/Export/lib/cmake/vtk-8.2/VTKTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/CMakeFiles/Export/lib/cmake/vtk-8.2/VTKTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/CMakeFiles/Export/lib/cmake/vtk-8.2/VTKTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/CMakeFiles/Export/lib/cmake/vtk-8.2/VTKTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/vtk-8.2" TYPE FILE FILES "C:/Project/PlusB-bin/vtk/Copyright.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Project/PlusB-bin/vtk-bin/Remote/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Utilities/KWIML/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Utilities/KWSys/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/utf8/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Common/Core/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Common/Math/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Common/Misc/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Common/System/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Common/Transforms/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Common/DataModel/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Common/Color/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Common/ExecutionModel/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Common/ComputationalGeometry/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Core/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/General/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Imaging/Core/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Imaging/Fourier/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/eigen/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Statistics/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Extraction/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Infovis/Core/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Geometry/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Sources/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Rendering/Core/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/zlib/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/freetype/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Rendering/FreeType/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Rendering/Context2D/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Charts/Core/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Utilities/DICOMParser/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/doubleconversion/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/lz4/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/lzma/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/Core/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/Legacy/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/expat/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/XMLParser/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Domains/Chemistry/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/glew/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Domains/ChemistryOpenGL2/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/XML/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Parallel/Core/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/AMR/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/FlowPaths/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Generic/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Imaging/Sources/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Hybrid/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/HyperTree/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Imaging/General/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Imaging/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Modeling/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Parallel/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/ParallelImaging/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Points/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Programmable/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/SMP/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Selection/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Texture/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Topology/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/verdict/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Filters/Verdict/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Interaction/Style/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/GUISupport/Qt/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/sqlite/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/SQL/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/GUISupport/QtSQL/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Utilities/MetaIO/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/jpeg/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/png/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/tiff/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/Image/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Imaging/Hybrid/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Infovis/Layout/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Imaging/Color/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Rendering/Annotation/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Rendering/Volume/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Interaction/Widgets/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Views/Core/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/libproj/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Geovis/Core/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/hdf5/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/AMR/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/Asynchronous/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/pugixml/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/CityGML/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/EnSight/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/netcdf/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/exodusII/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/Exodus/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/gl2ps/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Rendering/GL2PSOpenGL2/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/Export/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/ExportOpenGL2/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/libharu/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/ExportPDF/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/Geometry/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/Import/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/libxml2/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/Infovis/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/LSDyna/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/MINC/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/ogg/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/theora/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/Movie/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/NetCDF/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/PLY/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/ThirdParty/jsoncpp/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/Parallel/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/ParallelXML/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/SegY/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/TecplotTable/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/VeraOut/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/IO/Video/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Imaging/Math/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Imaging/Morphological/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Imaging/Statistics/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Imaging/Stencil/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Interaction/Image/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Rendering/ContextOpenGL2/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Rendering/Image/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Rendering/LOD/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Rendering/Label/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Rendering/Qt/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Rendering/VolumeOpenGL2/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Views/Context2D/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Views/Infovis/cmake_install.cmake")
  include("C:/Project/PlusB-bin/vtk-bin/Views/Qt/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Project/PlusB-bin/vtk-bin/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
