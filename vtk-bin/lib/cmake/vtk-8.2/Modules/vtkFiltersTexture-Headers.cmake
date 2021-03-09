set(vtkFiltersTexture_HEADERS_LOADED 1)
set(vtkFiltersTexture_HEADERS "vtkTextureMapToCylinder;vtkTextureMapToPlane;vtkTextureMapToSphere;vtkImplicitTextureCoords;vtkThresholdTextureCoords;vtkTransformTextureCoords;vtkTriangularTCoords;vtkScalarsToTextureFilter")

foreach(header ${vtkFiltersTexture_HEADERS})
  set(vtkFiltersTexture_HEADER_${header}_EXISTS 1)
endforeach()
