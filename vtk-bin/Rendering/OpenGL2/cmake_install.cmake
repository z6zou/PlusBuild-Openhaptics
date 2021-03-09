# Install script for directory: C:/Project/PlusB-bin/vtk/Rendering/OpenGL2

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
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Debug/vtkRenderingOpenGL2-8.2D.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/Release/vtkRenderingOpenGL2-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/MinSizeRel/vtkRenderingOpenGL2-8.2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/vtkRenderingOpenGL2-8.2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xRuntimeLibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Debug/vtkRenderingOpenGL2-8.2D.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/Release/vtkRenderingOpenGL2-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/MinSizeRel/vtkRenderingOpenGL2-8.2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "C:/Project/PlusB-bin/bin/RelWithDebInfo/vtkRenderingOpenGL2-8.2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/vtk-8.2/Modules" TYPE FILE FILES "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/CMakeFiles/vtkRenderingOpenGL2.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelopmentx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/vtk-8.2" TYPE FILE FILES
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGL.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkStateStorage.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkTDxConfigure.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkOpenGLError.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkRenderingOpenGLConfigure.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkRenderingOpenGL2ObjectFactory.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkCameraPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkClearRGBPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkClearZPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkCompositePolyDataMapper2.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkDefaultPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkDepthOfFieldPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkDepthImageProcessingPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkDepthPeelingPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkDualDepthPeelingPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkEDLShading.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkFramebufferPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkGaussianBlurPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkGenericOpenGLRenderWindow.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkHiddenLineRemovalPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkImageProcessingPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkLightingMapPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkLightsPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpaquePass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLBillboardTextActor3D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLBufferObject.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLCamera.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLFXAAFilter.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLFramebufferObject.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLGL2PSHelper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLGlyph3DHelper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLGlyph3DMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLHardwareSelector.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLHelper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLImageAlgorithmHelper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLImageMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLImageSliceMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLIndexBufferObject.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLInstanceCulling.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLLabeledContourMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLLight.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLPointGaussianMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLPolyDataMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLPolyDataMapper2D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLProperty.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLQuadHelper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLRenderPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLRenderTimer.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLRenderTimerLog.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLRenderUtilities.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLRenderWindow.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLRenderer.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLShaderCache.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLSkybox.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLSphereMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLState.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLStickMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLTextActor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLTextActor3D.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLTextMapper.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLTexture.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLVertexArrayObject.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLVertexBufferObject.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLVertexBufferObjectCache.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOpenGLVertexBufferObjectGroup.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOrderIndependentTranslucentPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkOverlayPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkPanoramicProjectionPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkPixelBufferObject.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkPointFillPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkRenderPassCollection.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkRenderStepsPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkRenderbuffer.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkSSAAPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkSequencePass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkShader.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkShaderProgram.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkShadowMapBakerPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkShadowMapPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkSimpleMotionBlurPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkSobelGradientMagnitudePass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkTextureObject.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkTextureUnitManager.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkToneMappingPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkTransformFeedback.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkTranslucentPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkValuePass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkVolumetricPass.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkDataTransferHelper.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkDepthOfFieldPassFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkDepthPeelingPassFinalFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkDepthPeelingPassIntermediateFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkEDLBilateralFilterFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkEDLComposeFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkEDLShadeFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkFXAAFilterFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkGaussianBlurPassFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkGaussianBlurPassVS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkGlyph3DVS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkOrderIndependentTranslucentPassFinalFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkPointGaussianVS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkPointGaussianGS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkPointFillPassFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkPolyData2DFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkPolyData2DVS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkPolyDataFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkPolyDataVS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkPolyDataWideLineGS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkSSAAPassFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkSimpleMotionBlurPassFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkSobelGradientMagnitudePass1FS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkSobelGradientMagnitudePass2FS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkSphereMapperGS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkStickMapperGS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkTextureObjectFS.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkTextureObjectVS.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkDummyGPUInfoList.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkWin32RenderWindowInteractor.h"
    "C:/Project/PlusB-bin/vtk/Rendering/OpenGL2/vtkWin32OpenGLRenderWindow.h"
    "C:/Project/PlusB-bin/vtk-bin/Rendering/OpenGL2/vtkRenderingOpenGL2Module.h"
    )
endif()

