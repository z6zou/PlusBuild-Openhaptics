/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkTrimmedExtrusionFilter.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkTrimmedExtrusionFilter
 * @brief   extrude polygonal data trimmed by a second input surface
 *
 * vtkTrimmedExtrusionFilter is a modeling filter. It takes polygonal data as
 * input and generates polygonal data on output. The input dataset is swept
 * along a specified direction forming a "skirt" from the boundary edges 2D
 * primitives (i.e., edges used by only one polygon); and/or from vertices
 * and lines. The extent of the sweeping is limited by a second input:
 * defined where the sweep intersects a user-specified surface.
 *
 * Capping of the extrusion can be enabled. In this case the input,
 * generating primitive is copied inplace as well as to the end of the
 * extrusion skirt. (See warnings below on what happens if the intersecting
 * sweep does not intersect, or partially intersects the trim surface.)
 *
 * Note that this filter operates in two fundamentally different modes based
 * on the extrusion strategy. If the strategy is BOUNDARY_EDGES, then only the
 * boundary edges of the input's 2D primitives are extruded (verts and lines
 * are extruded to generate lines and quads). However, if the extrusions
 * strategy is ALL_EDGES, then every edge of the 2D primitives is used to
 * sweep out a quadrilateral polygon (again verts and lines are swept to
 * produce lines and quads).
 *
 * @warning
 * The extrusion direction is assumed to define an infinite line. The
 * intersection with the trim surface is along a ray from the - to +
 * direction, however only the first intersection is taken.
 *
 * @warning
 * Some polygonal objects have no free edges (e.g., sphere). When swept, this
 * will result in two separate surfaces if capping is on and BOUNDARY_EDGES
 * enabled, or no surface if capping is off and BOUNDARY_EDGES is enabled.
 *
 * @warning
 * If all the extrusion lines emanating from an extruding primitive do not
 * intersect the trim surface, then no output for that primitive will be
 * generated. In extreme cases, it it possible that no output whatsoever will
 * be generated by the filter.
 *
 * @warning
 * This class has been threaded with vtkSMPTools. Using TBB or other
 * non-sequential type (set in the CMake variable
 * VTK_SMP_IMPLEMENTATION_TYPE) may improve performance significantly.
 *
 * @sa
 * vtkLinearExtrusionFilter vtkRotationalExtrusionFilter
*/

#ifndef vtkTrimmedExtrusionFilter_h
#define vtkTrimmedExtrusionFilter_h

#include "vtkFiltersModelingModule.h" // For export macro
#include "vtkPolyDataAlgorithm.h"

class vtkAbstractCellLocator;

class VTKFILTERSMODELING_EXPORT vtkTrimmedExtrusionFilter : public vtkPolyDataAlgorithm
{
public:
  vtkTypeMacro(vtkTrimmedExtrusionFilter,vtkPolyDataAlgorithm);
  void PrintSelf(ostream& os, vtkIndent indent) override;

  /**
   * Create object with extrusion direction (0,0,1) and capping on.
   */
  static vtkTrimmedExtrusionFilter *New();

  //@{
  /**
   * Set/Get the extrusion direction.
   */
  vtkSetVector3Macro(ExtrusionDirection,double);
  vtkGetVectorMacro(ExtrusionDirection,double,3);
  //@}

  //@{
  /**
   * Specify the surface which trims the surface.  Note that the method
   * SetTrimSurfaceData does not connect the pipeline. The algorithm will
   * work on the input data as it is without updating the producer of the
   * data.  The method SetTrimSurfaceConnection connects the pipeline.
   */
  void SetTrimSurfaceData(vtkPolyData *pd);
  void SetTrimSurfaceConnection(vtkAlgorithmOutput* algOutput);
  //@}

  //@{
  /**
   * Return a pointer to the enclosing surface.
   */
  vtkPolyData *GetTrimSurface();
  vtkPolyData *GetTrimSurface(vtkInformationVector *sourceInfo);
  //@}

  //@{
  /**
   * Turn on/off the capping of the extruded skirt.
   */
  vtkSetMacro(Capping,int);
  vtkGetMacro(Capping,int);
  vtkBooleanMacro(Capping,int);
  //@}

  // How to extrude data. Either determine boundary edges and sweep them; or
  // sweep all edges.
  enum ExtrusionStrategy
  {
    BOUNDARY_EDGES=0,
    ALL_EDGES=1
  };

  //@{
  /**
   * Specify a strategy for extrusion. If the strategy is set to
   * "BOUNDARY_EDGES" then the boundary edges of the input polygons and
   * triangle strips are swept. (A boundary edge is an edge used by only one
   * 2D primitive, e.g., polygon or triangle.) Alternatively, all edges can
   * be swept. (This is particularly useful when only sinple disconnected
   * polygons exist in the input and so boundary calculation can be avoided.)
   * By default boundary edges are extruded.
   */
  vtkSetMacro(ExtrusionStrategy,int);
  vtkGetMacro(ExtrusionStrategy,int);
  void SetExtrusionStrategyToBoundaryEdges()
    { this->SetExtrusionStrategy(BOUNDARY_EDGES); }
  void SetExtrusionStrategyToAllEdges()
    { this->SetExtrusionStrategy(ALL_EDGES); }
  //@}

  // How to cap data.
  enum CappingStrategy
  {
    INTERSECTION=0,
    MINIMUM_DISTANCE=1,
    MAXIMUM_DISTANCE=2,
    AVERAGE_DISTANCE=3,
  };

  //@{
  /**
   * Specify a strategy for capping. By default the points of the cap
   * polygons are located where the extrusion intersects the capping surface.
   * However, to preserve planarity, or to place the capping surface at the
   * average/minimum/maximum distance of extrusion, different strategies can
   * be used. By default the average distance is used.
   *
   * Note if none of the extrusion rays intersect the trim surface, then
   * capping is not performed, nor is an extrusion skirt sent to the
   * output. Also note that if the capping strategy is set to INTERSECTION,
   * and one of the extrusion rays of the generating primitive does not
   * intersect the trim surface, then no output will be generated for that
   * primitive. However if any other capping strategy is used, capping will
   * succeed if at least one extrusion ray strikes the trim surface (although
   * missed extrusion ray intersections will not factor into the
   * determination of final cap location).
   *
   * Finally, note that any capping strategy other than INTERSECTION may
   * produce more points than expected because the output primitives may
   * have to be "split apart" to satisy the capping constraint.
   */
  vtkSetMacro(CappingStrategy,int);
  vtkGetMacro(CappingStrategy,int);
  void SetCappingStrategyToIntersection()
    { this->SetCappingStrategy(INTERSECTION); }
  void SetCappingStrategyToMinimumDistance()
    { this->SetCappingStrategy(MINIMUM_DISTANCE); }
  void SetCappingStrategyToMaximumDistance()
    { this->SetCappingStrategy(MAXIMUM_DISTANCE); }
  void SetCappingStrategyToAverageDistance()
    { this->SetCappingStrategy(AVERAGE_DISTANCE); }
  //@}

  //@{
  /**
   * Specify a cell locator. By default a vtkStaticCellLocator is
   * used. The locator performs efficient searches to intersect cells.
   */
  void SetLocator(vtkAbstractCellLocator *locator);
  vtkGetObjectMacro(Locator,vtkAbstractCellLocator);
  //@}

protected:
  vtkTrimmedExtrusionFilter();
  ~vtkTrimmedExtrusionFilter() override;

  int Capping;
  double ExtrusionDirection[3];
  int ExtrusionStrategy;
  int CappingStrategy;
  vtkAbstractCellLocator *Locator;

  void AdjustPoints(vtkPolyData *mesh, vtkIdType numPts, vtkIdType numCells,
                    unsigned char *hots, vtkPoints *newPts);

  void ExtrudeEdges(vtkPolyData *input, vtkPolyData *output,
                    vtkIdType numPts, vtkIdType numCells);

  vtkIdType GetNeighborCount(vtkPolyData *mesh, vtkIdType inCellId,
                             vtkIdType p1, vtkIdType p2, vtkIdList *cellIds);

  int RequestData(vtkInformation *, vtkInformationVector **, vtkInformationVector *) override;
  int FillInputPortInformation(int, vtkInformation *) override;

private:
  vtkTrimmedExtrusionFilter(const vtkTrimmedExtrusionFilter&) = delete;
  void operator=(const vtkTrimmedExtrusionFilter&) = delete;
};

#endif
