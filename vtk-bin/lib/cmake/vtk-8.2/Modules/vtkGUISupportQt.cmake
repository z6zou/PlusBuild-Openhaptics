set(vtkGUISupportQt_LOADED 1)
set(vtkGUISupportQt_DEPENDS "vtkCommonCore;vtkCommonDataModel;vtkFiltersExtraction;vtkInteractionStyle;vtkRenderingCore;vtkRenderingOpenGL2")
set(vtkGUISupportQt_LIBRARIES "vtkGUISupportQt")
set(vtkGUISupportQt_INCLUDE_DIRS "C:/Project/PlusB-bin/vtk-bin/GUISupport/Qt;C:/Project/PlusB-bin/vtk/GUISupport/Qt")
set(vtkGUISupportQt_LIBRARY_DIRS "")
set(vtkGUISupportQt_RUNTIME_LIBRARY_DIRS "C:/Project/PlusB-bin/bin")
set(vtkGUISupportQt_WRAP_HIERARCHY_FILE "")
set(vtkGUISupportQt_KIT "")
set(vtkGUISupportQt_TARGETS_FILE "")
set(VTK_QT_RCC_EXECUTABLE "")
set(VTK_QT_MOC_EXECUTABLE "C:/Qt/Qt5.7.1/5.7/msvc2015_64/bin/moc.exe")
set(VTK_QT_UIC_EXECUTABLE "")
set(VTK_QT_QMAKE_EXECUTABLE "")
set(vtkGUISupportQt_EXCLUDE_FROM_WRAPPING 1)

if(NOT Qt5_DIR)
  set(Qt5_DIR "C:/Qt/Qt5.7.1/5.7/msvc2015_64/lib/cmake/Qt5")
endif()

find_package(Qt5 REQUIRED QUIET COMPONENTS Widgets)


