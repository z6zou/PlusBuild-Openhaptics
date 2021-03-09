set(vtkViewsQt_LOADED 1)
set(vtkViewsQt_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkCommonExecutionModel;vtkFiltersExtraction;vtkFiltersGeneral;vtkGUISupportQt;vtkInfovisCore;vtkViewsCore;vtkViewsInfovis")
set(vtkViewsQt_LIBRARIES "vtkViewsQt")
set(vtkViewsQt_INCLUDE_DIRS "C:/Project/PlusB-bin/vtk-bin/Views/Qt;C:/Project/PlusB-bin/vtk/Views/Qt")
set(vtkViewsQt_LIBRARY_DIRS "")
set(vtkViewsQt_RUNTIME_LIBRARY_DIRS "C:/Project/PlusB-bin/bin")
set(vtkViewsQt_WRAP_HIERARCHY_FILE "")
set(vtkViewsQt_KIT "")
set(vtkViewsQt_TARGETS_FILE "")
set(vtkViewsQt_EXCLUDE_FROM_WRAPPING 1)

if(NOT Qt5_DIR)
  set(Qt5_DIR "C:/Qt/Qt5.7.1/5.7/msvc2015_64/lib/cmake/Qt5")
endif()

find_package(Qt5 REQUIRED QUIET COMPONENTS Widgets)


