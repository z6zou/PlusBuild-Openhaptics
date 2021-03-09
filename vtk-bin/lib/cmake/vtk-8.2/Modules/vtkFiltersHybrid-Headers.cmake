set(vtkFiltersHybrid_HEADERS_LOADED 1)
set(vtkFiltersHybrid_HEADERS "vtkAdaptiveDataSetSurfaceFilter;vtkBSplineTransform;vtkDepthSortPolyData;vtkDSPFilterDefinition;vtkDSPFilterGroup;vtkEarthSource;vtkFacetReader;vtkForceTime;vtkGreedyTerrainDecimation;vtkGridTransform;vtkImageToPolyDataFilter;vtkImplicitModeller;vtkPCAAnalysisFilter;vtkPolyDataSilhouette;vtkProcrustesAlignmentFilter;vtkProjectedTerrainPath;vtkRenderLargeImage;vtkTemporalArrayOperatorFilter;vtkTemporalDataSetCache;vtkTemporalFractal;vtkTemporalInterpolator;vtkTemporalShiftScale;vtkTemporalSnapToTimeStep;vtkTransformToGrid;vtkWeightedTransformFilter")

foreach(header ${vtkFiltersHybrid_HEADERS})
  set(vtkFiltersHybrid_HEADER_${header}_EXISTS 1)
endforeach()
