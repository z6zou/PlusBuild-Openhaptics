# Install script for directory: C:/Project/PlusB-bin/vtk/Rendering/Core

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkRenderingCore-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkRenderingCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkRenderingCore-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkRenderingCore-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkRenderingCore-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkRenderingCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkRenderingCore-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkRenderingCore-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Rendering/Core/CMakeFiles/vtkRenderingCore.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkGPUInfoListArray.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkNoise200x200.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkPythagoreanQuadruples.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRayCastStructures.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRenderingCoreEnums.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTDxMotionEventInfo.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkAbstractMapper3D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkAbstractMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkAbstractPicker.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkAbstractVolumeMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkActor2DCollection.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkActor2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkActorCollection.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkAssembly.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkBackgroundColorMonitor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkBillboardTextActor3D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkCameraActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkCamera.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkCameraInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkCellCenterDepthSort.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkCIEDE2000.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkColorTransferFunction.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkCompositeDataDisplayAttributes.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkCompositeDataDisplayAttributesLegacy.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkCompositePolyDataMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkCoordinate.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkCullerCollection.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkCuller.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkDataSetMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkDiscretizableColorTransferFunction.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkDistanceToCamera.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkFollower.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkFrameBufferObjectBase.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkFrustumCoverageCuller.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkFXAAOptions.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkGenericRenderWindowInteractor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkGenericVertexAttributeMapping.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkGlyph3DMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkGPUInfo.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkGPUInfoList.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkGraphicsFactory.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkGraphMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkGraphToGlyphs.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkHardwareSelector.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkHierarchicalPolyDataMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkImageActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkImageMapper3D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkImageMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkImageProperty.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkImageSlice.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkImageSliceMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkInteractorEventRecorder.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkInteractorObserver.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkLabeledContourMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkLightActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkLightCollection.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkLight.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkLightKit.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkLogLookupTable.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkLookupTableWithEnabling.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkMapArrayValues.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkMapper2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkMapperCollection.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkObserverMediator.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkPointGaussianMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkPolyDataMapper2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkPolyDataMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkProp3DCollection.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkProp3D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkProp3DFollower.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkPropAssembly.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkPropCollection.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkProp.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkProperty2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkProperty.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRendererCollection.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRenderer.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRendererDelegate.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRendererSource.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRenderPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRenderState.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRenderTimerLog.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRenderWindowCollection.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRenderWindow.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRenderWindowInteractor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRenderWindowInteractor3D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkSelectVisiblePoints.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkShaderDeviceAdapter2.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkSkybox.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTextActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTextActor3D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTexture.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTexturedActor2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTransformCoordinateSystems.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTransformInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTupleInterpolator.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkViewDependentErrorMetric.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkViewport.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkVisibilitySort.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkVolumeCollection.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkVolume.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkVolumeProperty.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkWindowLevelLookupTable.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkWindowToImageFilter.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkAssemblyNode.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkAssemblyPath.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkAssemblyPaths.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkAreaPicker.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkPicker.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkAbstractPropPicker.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkPropPicker.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkPickingManager.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkLODProp3D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkWorldPointPicker.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkCellPicker.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkPointPicker.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRenderedAreaPicker.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkScenePicker.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkInteractorStyle.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkInteractorStyleSwitchBase.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkInteractorStyle3D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTDxInteractorStyle.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTDxInteractorStyleCamera.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTDxInteractorStyleSettings.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkStringToImage.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTextMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTextProperty.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTextPropertyCollection.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkTextRenderer.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkAbstractInteractionDevice.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkAbstractRenderDevice.h"
    "C:/Project/PlusB-bin/vtk/Rendering/Core/vtkRenderWidget.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/Core/vtkRenderingCoreModule.h"
    )
endif()

