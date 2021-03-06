/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#ifndef _FIDUCIAL_ALGORITHM_COMMON_H
#define _FIDUCIAL_ALGORITHM_COMMON_H

#include "vtkPlusCalibrationExport.h"

#include <vector>
#include <string>

/*!
\class FidDot
\brief This class defines a single dot made obtained from the segmentation part of the algorithm.
It contains the X and Y coordinate of the dot as well as its intensity. Also contains an operator
to check if dots are equal (both X and Y are the same).
\ingroup PlusLibPatternRecognition
*/
class vtkPlusCalibrationExport PlusFidDot
{
public:
  /*! Compare the intensity of 2 dots */
  static bool IntensityLessThan(const PlusFidDot& dot1, const PlusFidDot& dot2);

  /*! Compare the position of 2 dots */
  static bool PositionLessThan(std::vector<PlusFidDot>::iterator b1, std::vector<PlusFidDot>::iterator b2);

  /*! Set the x coordinate of the dot */
  void SetX(double value);

  /*! Get the x coordinate of the dot */
  double GetX() const;

  /*! Set the y coordinate of the dot */
  void  SetY(double value);

  /*! Get the y coordinate of the dot */
  double GetY() const;

  /*! Set the intensity of the dot */
  void SetDotIntensity(double value);

  /*! Get the intensity of the dot */
  double GetDotIntensity() const;

  /*! Get Euclidean distance from another point */
  double GetDistanceFrom(PlusFidDot& d);

  /*! Compare two dots, coordinate-wise */
  bool operator== (const PlusFidDot& data) const;

protected:
  double  m_X;
  double  m_Y;
  double  m_DotIntensity;
};

//-----------------------------------------------------------------------------
/*!
\class FidLine
\brief This class defines a single line made from a vector of dots obtained from the segmentation part of the algorithm.
It contains the list of indexes of the dots, the length of the line, the origin and the endpoint as well as the
line intensity and its direction vector.
\ingroup PlusLibPatternRecognition
*/
class vtkPlusCalibrationExport PlusFidLine
{
public:
  /*! Compare the intensity of 2 lines */
  static bool lessThan(const PlusFidLine& line1, const PlusFidLine& line2);

  /*! Compare 2 lines to know if they are the same */
  static bool compareLines(const PlusFidLine& line1, const PlusFidLine& line2);

  /*! Compute the angle in radians between the line and the positive x-axis, value between -Pi and +Pi */
  static double ComputeAngleRad(const PlusFidLine& line1);

  /*! Compute the angle difference in radians between two lines, the result value is between 0 and Pi/2 */
  static double ComputeAngleRad(const PlusFidLine& line1, const PlusFidLine& line2);

  /*! Set the point of line
  \param aIndex is the index in the dots vector of the line
  \param aValue is the index of the dot in the general vector of dots
  */
  void SetPoint(int aIndex, int aValue);

  /*! Get the point of the line that has index aIndex */
  int  GetPoint(int aIndex) const;

  /*! Get the number of points making the line */
  unsigned int GetNumberOfPoints() const;

  /*! Set the intensity of the line, which is the sum of its dots intensity */
  void SetIntensity(double value);

  /*! Get the intensity of the line, which is the sum of its dots intensity */
  double GetIntensity() const;

  /*! Set the length of the line */
  void SetLength(double value);

  /*! Get the length of the line */
  double GetLength() const { return Length; };

  /*! Set the direction vector that defines the line */
  void SetDirectionVector(int aIndex, double aValue);

  /*! Get the direction vector that defines the line */
  const double* GetDirectionVector() const;

  /*! Set the start point index of the line. It is an index in the m_DotsVector */
  void  SetStartPointIndex(int index);

  /*! Get the start point index of the line. It is an index in the m_DotsVector */
  int GetStartPointIndex() const;

  /*! Set the other end point of the line. It is the index of the end point in the m_DotsVector */
  void SetEndPointIndex(int index);

  /*! Get the other end point of the line. It is the index of the end point in the m_DotsVector */
  int GetEndPointIndex() const;

  /*! Resize the points vector */
  void ResizePoints(int aNewSize);

  /*! Add a point to the line */
  void AddPoint(int aPoint);

protected:
  /*! indices of points that make up the line */
  std::vector<int>  Points;
  double            Intensity;
  double            Length;
  double            DirectionVector[2];
  /// index of start point of the line, all the other line points are towards the positive m_DirectionVector direction from this point
  int               StartPointIndex;
  /// Index of the endpoint of the line
  int               EndPointIndex;
};

//-----------------------------------------------------------------------------
/*!
\class FidWire
\brief This structure defines a single fiducial wire by its name and its endpoint (front and back)
\ingroup PlusLibPatternRecognition
*/
class vtkPlusCalibrationExport PlusFidWire
{
public:
  void SetName(const std::string& aName);
  std::string GetName() const;

  double EndPointFront[3];
  double EndPointBack[3];

protected:
  std::string Name;
};

//-----------------------------------------------------------------------------
/*!
\class FidPattern
\brief This class stores the different Patterns defined in the configuration file. It contains the wires
definition, the distance from the line origin of each expected "dot" and the tolerances on these
distances.
\ingroup PlusLibPatternRecognition
*/
class vtkPlusCalibrationExport PlusFidPattern
{
public:
  virtual ~PlusFidPattern();

  const std::vector<PlusFidWire>& GetWires() const;
  const std::vector<double>& GetDistanceToOriginMm() const;
  const std::vector<double>& GetDistanceToOriginToleranceMm() const;

  void AddWire(const PlusFidWire& wire);
  void AddDistanceToOriginElementMm(double aElement);
  void SetDistanceToOriginElementMm(int index, double aElement);
  void AddDistanceToOriginToleranceElementMm(double aElement);
  void SetDistanceToOriginToleranceElementMm(int index, double aElement);

protected:
  std::vector<PlusFidWire> Wires;
  /// These distances are in mm.
  std::vector<double>  DistanceToOriginMm;
  /// These tolerances are in mm.
  std::vector<double>  DistanceToOriginToleranceMm;
};

//-----------------------------------------------------------------------------
/*!
\class NWire
\brief The struct NWire is a child from FidPattern and has two more features that are the intersections of the NWires
between lines 1 and 2, and, 2 and 3.
\ingroup PlusLibPatternRecognition
*/
class vtkPlusCalibrationExport PlusNWire : public PlusFidPattern
{
public:
  virtual ~PlusNWire();

  double IntersectPosW12[3];
  double IntersectPosW32[3];
};

//-----------------------------------------------------------------------------
/*!
\class CoplanarParallelWires
\brief The struct CoplanarparallelWires is a child from FidPattern and represents an undefinite number of coplanar
parallel fiducial wires.
\ingroup PlusLibPatternRecognition
*/
class vtkPlusCalibrationExport PlusCoplanarParallelWires : public PlusFidPattern
{
public:
  virtual ~PlusCoplanarParallelWires();
};

//-----------------------------------------------------------------------------
/*!
\class PatternRecognitionResult
\brief This class stores the FidPattern Recognition algorithm results.
\ingroup PlusLibPatternRecognition
*/
class vtkPlusCalibrationExport PlusPatternRecognitionResult
{
public:
  PlusPatternRecognitionResult();

  /*! Clear the class attributes once they are not needed anymore */
  void Clear();

  /*! Set the m_DotsFound to true if the algorithm found the corresponding dots, to false otherwise */
  void SetDotsFound(bool value);

  /*! Get m_DotsFound */
  bool GetDotsFound();

  /*! Set the coordinates of the found dots */
  void SetFoundDotsCoordinateValue(std::vector< std::vector<double> > value);

  /*! Get the coordinates of the found dots */
  std::vector< std::vector<double> >&  GetFoundDotsCoordinateValue();

  /*! Set the cumulate intensity of all dots in the pattern */
  void SetIntensity(double value) { Intensity = value; };

  /*! Get the cumulate intensity of all dots in the pattern */
  double GetIntensity() const { return Intensity; };

  /*! Set the number of candidate points that have been found */
  void SetNumDots(double value) { NumDots = value; };

  /*! Get the number of candidate points that have been found */
  double GetNumDots() const { return NumDots; };

  /*! Set the dots that are considered candidates */
  void SetCandidateFidValues(std::vector<PlusFidDot> value);

  /*! Get the dots that are considered candidates */
  const std::vector<PlusFidDot>& GetCandidateFidValues() const;

protected:
  /*! X and Y values of found dots. */
  std::vector< std::vector<double> >  FoundDotsCoordinateValue;

  /*! pointer to the fiducial candidates coordinates */
  std::vector<PlusFidDot>  CandidateFidValues;

  /*! True if the dots are found, false otherwise. */
  bool DotsFound;

  /*! The combined intensity of the dots. This is the sum of the pixel
  values after the morphological operations, with the pixel values on the
  range 0-1.  A good intensity score is over 100. A bad one (but still
  valid) is below 25. */
  double Intensity;

  /*! number of possible fiducial points */
  double NumDots;
};

#endif //_FIDUCIAL_ALGORITHM_COMMON_H
