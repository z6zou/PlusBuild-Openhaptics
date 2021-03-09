set(vtkFiltersExtraction_HEADERS_LOADED 1)
set(vtkFiltersExtraction_HEADERS "vtkBlockSelector;vtkConvertSelection;vtkExtractBlock;vtkExtractCells;vtkExtractDataArraysOverTime;vtkExtractDataOverTime;vtkExtractDataSets;vtkExtractEdges;vtkExtractGeometry;vtkExtractGrid;vtkExtractLevel;vtkExtractPolyDataGeometry;vtkExtractRectilinearGrid;vtkExtractSelectedArraysOverTime;vtkExtractSelectedBlock;vtkExtractSelectedIds;vtkExtractSelectedLocations;vtkExtractSelectedPolyDataIds;vtkExtractSelectedRows;vtkExtractSelectedThresholds;vtkExtractSelection;vtkExtractTemporalFieldData;vtkExtractTensorComponents;vtkExtractTimeSteps;vtkExtractUnstructuredGrid;vtkExtractVectorComponents;vtkFrustumSelector;vtkHierarchicalDataExtractDataSets;vtkHierarchicalDataExtractLevel;vtkLocationSelector;vtkProbeSelectedLocations;vtkSelector;vtkValueSelector;vtkExtractArraysOverTime;vtkExtractSelectionLegacy")

foreach(header ${vtkFiltersExtraction_HEADERS})
  set(vtkFiltersExtraction_HEADER_${header}_EXISTS 1)
endforeach()