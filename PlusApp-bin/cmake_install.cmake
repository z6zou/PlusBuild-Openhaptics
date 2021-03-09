# Install script for directory: C:/Project/PlusB-bin/PlusApp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Project/PlusB-bin/PlusApp-bin/Install")
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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE PROGRAM FILES
    "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/redist/x64/Microsoft.VC140.CRT/msvcp140.dll"
    "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/redist/x64/Microsoft.VC140.CRT/vcruntime140.dll"
    "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/redist/x64/Microsoft.VC140.CRT/concrt140.dll"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE DIRECTORY FILES "")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES
    "C:/Qt/Qt5.7.1/5.7/msvc2015_64/bin/Qt5Core.dll"
    "C:/Qt/Qt5.7.1/5.7/msvc2015_64/bin/Qt5Widgets.dll"
    "C:/Qt/Qt5.7.1/5.7/msvc2015_64/bin/Qt5Test.dll"
    "C:/Qt/Qt5.7.1/5.7/msvc2015_64/bin/Qt5Xml.dll"
    "C:/Qt/Qt5.7.1/5.7/msvc2015_64/bin/Qt5Gui.dll"
    "C:/Qt/Qt5.7.1/5.7/msvc2015_64/bin/Qt5Network.dll"
    "C:/Qt/Qt5.7.1/5.7/msvc2015_64/bin/Qt5Sql.dll"
    "C:/Qt/Qt5.7.1/5.7/msvc2015_64/bin/Qt5XmlPatterns.dll"
    "C:/Qt/Qt5.7.1/5.7/msvc2015_64/bin/Qt5OpenGL.dll"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin/platforms" TYPE FILE FILES "C:/Qt/Qt5.7.1/5.7/msvc2015_64/plugins/platforms/qwindows.dll")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xScriptsx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES
    "C:/Project/PlusB-bin/PlusLib/src/scripts/StartPlusCommandPrompt.bat"
    "C:/Project/PlusB-bin/PlusLib/src/scripts/StartPlusCommandPrompt.ico"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDatax" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/config" TYPE FILE FILES
    "C:/Project/PlusB-bin/PlusLibData/ConfigFiles/PlusDeviceSet_fCal_Sim_PivotCalibration.xml"
    "C:/Project/PlusB-bin/PlusLibData/ConfigFiles/PlusDeviceSet_fCal_Sim_RecordPhantomLandmarks.xml"
    "C:/Project/PlusB-bin/PlusLibData/ConfigFiles/PlusDeviceSet_fCal_Sim_SpatialCalibration_2.0.xml"
    "C:/Project/PlusB-bin/PlusLibData/ConfigFiles/PlusDeviceSet_fCal_Sim_TemporalCalibration.xml"
    "C:/Project/PlusB-bin/PlusLibData/ConfigFiles/PlusDeviceSet_fCal_Sim_VolumeReconstruction.xml"
    "C:/Project/PlusB-bin/PlusLibData/ConfigFiles/PlusDeviceSet_Server_ChRobotics.xml"
    "C:/Project/PlusB-bin/PlusLibData/ConfigFiles/PlusDeviceSet_Server_Microchip.xml"
    "C:/Project/PlusB-bin/PlusLibData/ConfigFiles/PlusDeviceSet_Server_Sim_NwirePhantom.xml"
    "C:/Project/PlusB-bin/PlusLibData/ConfigFiles/PlusDeviceSet_Server_SimulatedUltrasound_3DSlicer.xml"
    "C:/Project/PlusB-bin/PlusLibData/ConfigFiles/SimulatedUltrasound_GelBlockModel_Reference.stl"
    "C:/Project/PlusB-bin/PlusLibData/ConfigFiles/SimulatedUltrasound_NeedleModel_NeedleTip.stl"
    "C:/Project/PlusB-bin/PlusLibData/ConfigFiles/SimulatedUltrasound_VesselModel_Reference.stl"
    "C:/Project/PlusB-bin/PlusLibData/ConfigFiles/SimulatedUltrasound_Scene.mrb"
    "C:/Project/PlusB-bin/PlusLibData/CADModels/fCalPhantom/fCal_1.0.stl"
    "C:/Project/PlusB-bin/PlusLibData/CADModels/fCalPhantom/fCal_1.2.stl"
    "C:/Project/PlusB-bin/PlusLibData/CADModels/fCalPhantom/fCal_2.0.stl"
    "C:/Project/PlusB-bin/PlusLibData/CADModels/fCalPhantom/fCal_3.1.stl"
    "C:/Project/PlusB-bin/PlusLibData/CADModels/fCalPhantom/fCal_L1.4.stl"
    "C:/Project/PlusB-bin/PlusLibData/CADModels/LinearProbe/Probe_L14-5_38.stl"
    "C:/Project/PlusB-bin/PlusLibData/CADModels/EndocavityProbe/Probe_EC9-5_10.stl"
    "C:/Project/PlusB-bin/PlusLibData/CADModels/CurvilinearProbe/Probe_C5-2_60.stl"
    "C:/Project/PlusB-bin/PlusLibData/CADModels/Stylus/Stylus_Example.stl"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDatax" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/data" TYPE FILE FILES
    "C:/Project/PlusB-bin/PlusLibData/TestImages/fCal_Test_Calibration_3NWires.igs.mha"
    "C:/Project/PlusB-bin/PlusLibData/TestImages/fCal_Test_Calibration_3NWires_fCal2.0.igs.mha"
    "C:/Project/PlusB-bin/PlusLibData/TestImages/WaterTankBottomTranslationTrackerBuffer-trimmed.igs.mha"
    "C:/Project/PlusB-bin/PlusLibData/TestImages/WaterTankBottomTranslationVideoBuffer.igs.mha"
    "C:/Project/PlusB-bin/PlusLibData/TestImages/EightLandmarkPointsTrackedForPhantomRegistration.igs.mha"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDatax" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE FILES "C:/Project/PlusB-bin/PlusApp-bin/PlusConfig.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Project/PlusB-bin/PlusApp-bin/PointSetExtractor/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusApp-bin/SpatialSensorFusion/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusApp-bin/PlusServerLauncher/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusApp-bin/DiagnosticTools/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusApp-bin/fCal/cmake_install.cmake")
  include("C:/Project/PlusB-bin/PlusApp-bin/Documentation/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Project/PlusB-bin/PlusApp-bin/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
