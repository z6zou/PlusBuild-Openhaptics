set(vtkGUISupportQtSQL_LOADED 1)
set(vtkGUISupportQtSQL_DEPENDS "vtkCommonCore;vtkIOSQL;vtksys")
set(vtkGUISupportQtSQL_LIBRARIES "vtkGUISupportQtSQL")
set(vtkGUISupportQtSQL_INCLUDE_DIRS "C:/Project/PlusB-bin/vtk-bin/GUISupport/QtSQL;C:/Project/PlusB-bin/vtk/GUISupport/QtSQL")
set(vtkGUISupportQtSQL_LIBRARY_DIRS "")
set(vtkGUISupportQtSQL_RUNTIME_LIBRARY_DIRS "C:/Project/PlusB-bin/bin")
set(vtkGUISupportQtSQL_WRAP_HIERARCHY_FILE "")
set(vtkGUISupportQtSQL_KIT "")
set(vtkGUISupportQtSQL_TARGETS_FILE "")
set(vtkGUISupportQtSQL_EXCLUDE_FROM_WRAPPING 1)

if(NOT Qt5_DIR)
  set(Qt5_DIR "C:/Qt/Qt5.7.1/5.7/msvc2015_64/lib/cmake/Qt5")
endif()

find_package(Qt5 REQUIRED QUIET COMPONENTS Sql Widgets)


