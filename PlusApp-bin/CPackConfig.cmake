# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "C:/Project/PlusB-bin/PlusApp;C:/Project/PlusB-bin/PlusApp-bin")
set(CPACK_CMAKE_GENERATOR "Visual Studio 16 2019")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "C:/Program Files/CMake/share/cmake-3.19/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "PlusApp built using CMake")
set(CPACK_GENERATOR "ZIP;NSIS")
set(CPACK_INSTALL_CMAKE_PROJECTS "C:/Project/PlusB-bin/PlusApp-bin;PlusApp;ALL;/;C:/Project/PlusB-bin/PlusLib-bin;PlusLib;RuntimeExecutables;/;C:/Project/PlusB-bin/PlusLib-bin;PlusLib;RuntimeLibraries;/;C:/Project/PlusB-bin/PlusLib-bin;PlusLib;Scripts;/;C:/Project/PlusB-bin/OpenIGTLink-bin;OpenIGTLink;RuntimeLibraries;/;C:/Project/PlusB-bin/OpenIGTLinkIO-bin;OpenIGTLinkIO;RuntimeLibraries;/")
set(CPACK_INSTALL_PREFIX "C:/Project/PlusB-bin/PlusApp-bin/Install")
set(CPACK_MODULE_PATH "C:/Project/PlusBuild/Modules;C:/Project/PlusB-bin/vtk-int/lib/cmake/vtk-8.2")
set(CPACK_NSIS_DEFINES "RequestExecutionLevel user")
set(CPACK_NSIS_DISPLAY_NAME "PlusApp-2.8.0.20191105-Win64")
set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS "
    CreateShortCut \"$SMPROGRAMS\\$STARTMENU_FOLDER\\Plus command prompt.lnk\" \"$INSTDIR\\bin\\StartPlusCommandPrompt.bat\" \"$INSTDIR\\bin\\StartPlusCommandPrompt.bat\" \"$INSTDIR\\bin\\StartPlusCommandPrompt.ico\"
    ")
set(CPACK_NSIS_EXTRA_UNINSTALL_COMMANDS "
    !insertmacro MUI_STARTMENU_GETFOLDER Application $MUI_TEMP
    Delete \"$SMPROGRAMS\\$MUI_TEMP\\Plus command prompt.lnk\"
    ")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROFILE")
set(CPACK_NSIS_PACKAGE_NAME "Plus Applications 2.8.0.2019-11-05 (Win64)")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OUTPUT_CONFIG_FILE "C:/Project/PlusB-bin/PlusApp-bin/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "C:/Program Files/CMake/share/cmake-3.19/Templates/CPack.GenericDescription.txt")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Plus(Public software Library for UltraSound) for Win64")
set(CPACK_PACKAGE_EXECUTABLES "PlusServerLauncher;Plus Server Launcher;fCal;Free-hand calibration(fCal)")
set(CPACK_PACKAGE_FILE_NAME "PlusApp-2.8.0.20191105-Win64")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "PlusApp-2.8.0.20191105-Win64")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "PlusApp-2.8.0.20191105-Win64")
set(CPACK_PACKAGE_NAME "PlusApp")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "PerkLab, Queen's University")
set(CPACK_PACKAGE_VERSION "2.8.0")
set(CPACK_PACKAGE_VERSION_MAJOR "2")
set(CPACK_PACKAGE_VERSION_MINOR "8")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_RESOURCE_FILE_LICENSE "C:/Project/PlusB-bin/PlusLib/License.txt")
set(CPACK_RESOURCE_FILE_README "C:/Program Files/CMake/share/cmake-3.19/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "C:/Program Files/CMake/share/cmake-3.19/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_7Z "ON")
set(CPACK_SOURCE_GENERATOR "7Z;ZIP")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "C:/Project/PlusB-bin/PlusApp-bin/CPackSourceConfig.cmake")
set(CPACK_SOURCE_ZIP "ON")
set(CPACK_SYSTEM_NAME "win64")
set(CPACK_TOPLEVEL_TAG "win64")
set(CPACK_WIX_SIZEOF_VOID_P "8")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "C:/Project/PlusB-bin/PlusApp-bin/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
