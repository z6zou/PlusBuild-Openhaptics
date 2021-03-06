/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#ifndef _FIDUCIAL_LINE_FINDER_H
#define _FIDUCIAL_LINE_FINDER_H

#include "PlusFidPatternRecognitionCommon.h"
#include "PlusConfigure.h"

class vtkXMLDataElement;

/*!
\class FidLineFinder
\brief This class is used to find the n-points lines from a list of dots. The lines have fixed length and tolerance
and their direction vector restricted according to the configuration file. It first finds 2-points lines and
then computes n-points lines from these 2-points lines.
\ingroup PlusLibPatternRecognition
*/

class vtkPlusCalibrationExport PlusFidLineFinder
{
public:
  PlusFidLineFinder();
  virtual ~PlusFidLineFinder();

  /*! Set the size of the frame as an array */
  void SetFrameSize(const FrameSizeType& frameSize);

  /*! Set the values of the candidate fiducials */
  void SetCandidateFidValues(const std::vector<PlusFidDot>& value) { m_CandidateFidValues = value; };

  /*! Set the vector of dots that have been found by FidSegmentation */
  void SetDotsVector(const std::vector<PlusFidDot>& value) { m_DotsVector = value; };

  /*! Set the pattern structure vector, this defines the patterns that the algorithm finds */
  void SetPatterns(const std::vector<PlusFidPattern*>& value) { m_Patterns = value; };

  /*! Set the approximate spacing in Mm per pixel */
  void SetApproximateSpacingMmPerPixel(double value) { m_ApproximateSpacingMmPerPixel = value; };

  /*! Set the minimum angle allowed for a line, in degrees */
  void SetMinThetaDegrees(double angleDeg);

  /*! Set the maximum angle allowed for a line, in degrees */
  void SetMaxThetaDegrees(double angleDeg);

  /*! Set the maximum distance from a point to a line when the point is tested to be a point of the line */
  void SetCollinearPointsMaxDistanceFromLineMm(double value) { m_CollinearPointsMaxDistanceFromLineMm = value; };

  /*! Read the configuration file from a vtk XML data element */
  PlusStatus ReadConfiguration(vtkXMLDataElement* rootConfigElement);

  /*! Find lines, runs the FindLines2Points and FindLinesNPoints and then sort the lines by intensity */
  void FindLines();

  /*! Get the vector of lines, this vector contains all lines of different number of points that match the criteria */
  std::vector<std::vector<PlusFidLine>>& GetLinesVector();

  /*! Get the maximum angle allowed for a line, in radians */
  double GetMaxThetaRad() { return m_MaxThetaRad; };

  /*! Get the minimum angle allowed for a line, in radians */
  double GetMinThetaRad() { return m_MinThetaRad; };

  /*! Get the pattern structure vector, this defines the patterns that the algorithm finds */
  std::vector<PlusFidPattern*>& GetPatterns() { return m_Patterns; };

  /*! Get the NWires vector, these NWires are extracted from the pattern vector */
  std::vector<PlusNWire> GetNWires();

  void SetImageToPhantomTransform(double* matrixElements);

  /*! Clear the member attributes when not needed anymore */
  void Clear();

protected:
  /*! Compute parameters such as the minimum and the maximum angle allowed for one line in the case where the segmentation
  parameters are to be computed. This allows a better precision and possibly an increase of computation speed. */
  void ComputeParameters();

  /*! Find the n-points lines from a list of 2-points lines */
  void FindLinesNPoints();

  /*! Find 2-points lines from a list of Dots */
  void FindLines2Points();

  /*! Compute the length of the segment between 2 dots */
  static double SegmentLength(const PlusFidDot& dot1, const PlusFidDot& dot2);

  /*! Compute the shortest distance from a point: dot, to a line: line */
  double ComputeDistancePointLine(const PlusFidDot& dot, const PlusFidLine& line);

  /*! Compute a line, all that is required is a set origin and the dots part of the line. It computes then the line length,
  the direction vector, the endpoint */
  void ComputeLine(PlusFidLine& line);

  /*! Compute the angle between the line formed by 2 dots and the x-axis, in radian */
  static double ComputeAngleRad(const PlusFidDot& dot1, const PlusFidDot& dot2);

  /*! Return true if a line matches the requirements, false otherwise */
  bool AcceptLine(PlusFidLine& line);

  /*! Return true if an angle is in the allowed angle range, false otherwise */
  bool AcceptAngleRad(double angleRad);

  //Accessors and mutators

  /*! Get the maximum rotation vector, this maximum rotation represents the physical limitation of the probe,
  used for automatic parameters computation */
  double* GetImageNormalVectorInPhantomFrameMaximumRotationAngleDeg() { return m_ImageNormalVectorInPhantomFrameMaximumRotationAngleDeg; };
  void SetImageNormalVectorInPhantomFrameMaximumRotationAngleDeg(double* anglesDeg);

  /*! Get the image to phantom transform matrix */
  double* GetImageToPhantomTransform() { return m_ImageToPhantomTransform; };

protected:
  FrameSizeType m_FrameSize;
  double m_ApproximateSpacingMmPerPixel;
  double m_ImageNormalVectorInPhantomFrameMaximumRotationAngleDeg[6];
  double m_ImageToPhantomTransform[16];

  // line length and line pair distance errors in percent - read from phantom definition
  double m_MaxLinePairDistanceErrorPercent;
  double m_CollinearPointsMaxDistanceFromLineMm;
  double m_MinThetaRad;
  double m_MaxThetaRad;

  std::vector<PlusFidDot> m_CandidateFidValues; // pointer to the fiducial candidates coordinates

  std::vector<PlusFidDot> m_DotsVector;
  std::vector< std::vector<PlusFidLine> > m_LinesVector;

  std::vector<PlusFidPattern*> m_Patterns;
};

#endif // _FIDUCIAL_LINE_FINDER_H
