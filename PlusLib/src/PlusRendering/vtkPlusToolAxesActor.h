/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __vtkPlusToolAxesActor_h
#define __vtkPlusToolAxesActor_h

// Local includes
#include "vtkPlusRenderingExport.h"

// PlusLib includes
#include <PlusConfigure.h>

// VTK includes
#include <vtkSetGet.h>
#include <vtkProp3D.h>

class vtkActor;
class vtkCaptionActor2D;
class vtkConeSource;
class vtkLineSource;
class vtkPropCollection;
class vtkTubeFilter;

/*!
  \class vtkPlusToolAxesActor
  \brief Actor for displaying coordinate system axes

  The actor's UserTransform shall be the tool to world transform.
*/
class vtkPlusRenderingExport vtkPlusToolAxesActor : public vtkProp3D
{
public:
  static vtkPlusToolAxesActor* New();
  vtkTypeMacro(vtkPlusToolAxesActor, vtkProp3D);
  virtual void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  /*!
    For some exporters and other other operations we must be
    able to collect all the actors or volumes. These methods
    are used in that process.
  */
  virtual void GetActors(vtkPropCollection*);

  /*! Support the standard render methods. */
  virtual int RenderOpaqueGeometry(vtkViewport* viewport);
  /*! Support the standard render methods. */
  virtual int RenderTranslucentPolygonalGeometry(vtkViewport* viewport);
  /*! Support the standard render methods. */
  virtual int RenderOverlay(vtkViewport* viewport);

  /*! Does this prop have some translucent polygonal geometry? */
  virtual int HasTranslucentPolygonalGeometry();

  /*!
    Release any graphics resources that are being consumed by this actor.
    The parameter window could be used to determine which graphic
    resources to release.
  */
  void ReleaseGraphicsResources(vtkWindow*);

  /*!
    Get the bounds for this Actor as (Xmin,Xmax,Ymin,Ymax,Zmin,Zmax). (The
    method GetBounds(double bounds[6]) is available from the superclass.)
  */
  void GetBounds(double bounds[6]);
  /*!
    Get the bounds for this Actor as (Xmin,Xmax,Ymin,Ymax,Zmin,Zmax). (The
    method GetBounds(double bounds[6]) is available from the superclass.)
  */
  double* GetBounds();

  /*! Get the actors mtime plus consider its properties and texture if set. */
  vtkMTimeType GetMTime();

  /*!
    Return the mtime of anything that would cause the rendered image to
    appear differently. Usually this involves checking the mtime of the
    prop plus anything else it depends on such as properties, textures
    etc.
  */
  vtkMTimeType GetRedrawMTime();

  /*!
    Set the name of the coordinate frame that is displayed as a label
    in the origin.
  */
  void SetName(const std::string& name);

  /*! Set shaft length */
  void SetShaftLength(double shaftLength);
  /*! Get shaft length */
  vtkGetMacro(ShaftLength, double);

  /*! Set show labels flag */
  vtkSetMacro(ShowLabels, bool);
  vtkBooleanMacro(ShowLabels, bool);
  /*! Get show labels flag */
  vtkGetMacro(ShowLabels, bool);

  /*! Set show name flag */
  vtkSetMacro(ShowName, bool);
  vtkBooleanMacro(ShowName, bool);
  /*! Get show name flag */
  vtkGetMacro(ShowName, bool);

protected:
  /*!
    \class AxisInfo
    \brief Stores rendering objects for each axis
  */
  class AxisInfo
  {
  public:
    AxisInfo();
    virtual ~AxisInfo();
    void ReleaseGraphicsResources(vtkWindow* win);

    vtkActor* ArrowShaftActor;
    vtkLineSource* ArrowShaftLineSource;
    vtkTubeFilter* TubeFilter;
    vtkConeSource* ArrowTipConeSource;
    vtkCaptionActor2D* LabelActor;
    double AxisShaftStart[3];
    double AxisShaftEnd[3];

    void UpdateActor();
  };

protected:
  vtkPlusToolAxesActor();
  ~vtkPlusToolAxesActor();

  void UpdateProps();

  void ExtendMaxBounds(vtkActor* actor, double* bounds);

protected:
  AxisInfo Axes[3];

  vtkCaptionActor2D* NameLabelActor;

  double ShaftLength;
  bool ShowLabels;
  bool ShowName;

private:
  vtkPlusToolAxesActor(const vtkPlusToolAxesActor&);  // Not implemented.
  void operator=(const vtkPlusToolAxesActor&);  // Not implemented.
};

#endif

