/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#include "PlusConfigure.h"

#include "PlusMath.h"

#include "vnl/vnl_sparse_matrix.h"
#include "vnl/vnl_sparse_matrix_linear_system.h"  
#include "vnl/algo/vnl_lsqr.h"  
#include "vnl/vnl_cross.h"  

#include "vtkMath.h"
#include "vtkTransform.h"

#define MINIMUM_NUMBER_OF_CALIBRATION_EQUATIONS 8

//----------------------------------------------------------------------------
PlusMath::PlusMath()
{

}

//----------------------------------------------------------------------------
PlusMath::~PlusMath()
{

}

//----------------------------------------------------------------------------
PlusStatus PlusMath::LSQRMinimize(const std::vector< std::vector<double> > &aMatrix, const std::vector<double> &bVector, vnl_vector<double> &resultVector, double* mean/*=NULL*/, double* stdev/*=NULL*/,vnl_vector<unsigned int> *notOutliersIndices/*=NULL*/)
{
  LOG_TRACE("PlusMath::LSQRMinimize"); 

  if (aMatrix.size()==0)
  {
    LOG_ERROR("LSQRMinimize: A matrix is empty");
    resultVector.clear();
    return PLUS_FAIL;
  }
  if (bVector.size()==0)
  {
    LOG_ERROR("LSQRMinimize: b vector is empty");
    resultVector.clear();
    return PLUS_FAIL;
  }

  // The coefficient matrix aMatrix should be m-by-n and the column vector bVector must have length m.
  const int n = aMatrix.begin()->size(); 
  const int m = bVector.size();

  std::vector<vnl_vector<double> > aMatrixVnl(m); 
  vnl_vector<double> row(n); 
  for ( unsigned int i = 0; i < aMatrix.size(); ++i )
  {
    for ( unsigned int r = 0; r < aMatrix[i].size(); ++r )
    {
      row[r] = aMatrix[i][r]; 
    }
    aMatrixVnl.push_back(row); 
  }

  return PlusMath::LSQRMinimize(aMatrixVnl, bVector, resultVector, mean, stdev,notOutliersIndices); 
}

//----------------------------------------------------------------------------
PlusStatus PlusMath::LSQRMinimize(const std::vector< vnl_vector<double> > &aMatrix, const std::vector<double> &bVector, vnl_vector<double> &resultVector, double* mean/*=NULL*/, double* stdev/*=NULL*/, vnl_vector<unsigned int>* notOutliersIndices /*=NULL*/)
{
  LOG_TRACE("PlusMath::LSQRMinimize"); 

  if (aMatrix.size()==0)
  {
    LOG_ERROR("LSQRMinimize: A matrix is empty");
    resultVector.clear();
    return PLUS_FAIL;
  }
  if (bVector.size()==0)
  {
    LOG_ERROR("LSQRMinimize: b vector is empty");
    resultVector.clear();
    return PLUS_FAIL;
  }

  // The coefficient matrix aMatrix should be m-by-n and the column vector bVector must have length m.
  const int n = aMatrix.begin()->size(); 
  const int m = bVector.size();

  vnl_sparse_matrix<double> sparseMatrixLeftSide(m, n);
  vnl_vector<double> vectorRightSide(m);

  for(int row = 0; row < m; row++)
  {
    // Populate the sparse matrix
    for ( int i = 0; i < n; i++)
    {
      sparseMatrixLeftSide(row,i) = aMatrix[row].get(i);
    }

    // Populate the vector
    vectorRightSide.put(row, bVector[row]);
  }

  return PlusMath::LSQRMinimize(sparseMatrixLeftSide, vectorRightSide, resultVector, mean, stdev, notOutliersIndices); 
}


//----------------------------------------------------------------------------
PlusStatus PlusMath::LSQRMinimize(const vnl_sparse_matrix<double> &sparseMatrixLeftSide, const vnl_vector<double> &vectorRightSide, vnl_vector<double> &resultVector, double* mean/*=NULL*/, double* stdev/*=NULL*/, vnl_vector<unsigned int>* notOutliersIndices/*NULL*/)
{
  LOG_TRACE("PlusMath::LSQRMinimize"); 

  PlusStatus returnStatus = PLUS_SUCCESS; 

  vnl_sparse_matrix<double> aMatrix(sparseMatrixLeftSide); 
  vnl_vector<double> bVector(vectorRightSide); 

  bool outlierFound(true); 

  while ( outlierFound && (bVector.size()>MINIMUM_NUMBER_OF_CALIBRATION_EQUATIONS) )
  {
    // Construct linear system defined in VNL
    vnl_sparse_matrix_linear_system<double> linearSystem( aMatrix, bVector );

    // Instantiate the LSQR solver
    vnl_lsqr lsqr( linearSystem );

    // call minimize on the solver
    int returnCode = lsqr.minimize( resultVector );

    switch (returnCode)
    {
    case 0: // x = 0  is the exact solution. No iterations were performed.
      returnStatus = PLUS_SUCCESS;
      break;
    case 1: // The equations A*x = b are probably compatible.  "
      // Norm(A*x - b) is sufficiently small, given the "
      // "values of ATOL and BTOL.",
      returnStatus = PLUS_SUCCESS;
      break;
    case 2: // "The system A*x = b is probably not compatible.  "
      // "A least-squares solution has been obtained that is "
      // "sufficiently accurate, given the value of ATOL.",
      returnStatus = PLUS_SUCCESS;
      break;
    case 3: // "An estimate of cond(Abar) has exceeded CONLIM.  "
      //"The system A*x = b appears to be ill-conditioned.  "
      // "Otherwise, there could be an error in subroutine APROD.",
      LOG_WARNING("LSQR fit may be inaccurate, CONLIM exceeded");
      returnStatus = PLUS_SUCCESS;
      break;
    case 4: // "The equations A*x = b are probably compatible.  "
      // "Norm(A*x - b) is as small as seems reasonable on this machine.",
      returnStatus = PLUS_SUCCESS;
      break;
    case 5: // "The system A*x = b is probably not compatible.  A least-squares "
      // "solution has been obtained that is as accurate as seems "
      // "reasonable on this machine.",
      returnStatus = PLUS_SUCCESS;
      break;
    case 6: // "Cond(Abar) seems to be so large that there is no point in doing further "
      // "iterations, given the precision of this machine. "
      // "There could be an error in subroutine APROD.",
      LOG_ERROR("LSQR fit may be inaccurate, ill-conditioned matrix");
      return PLUS_FAIL;
    case 7: // "The iteration limit ITNLIM was reached."
      LOG_WARNING("LSQR fit may be inaccurate, ITNLIM was reached");
      returnStatus = PLUS_SUCCESS;
      break;
    default:
      LOG_ERROR("Unkown LSQR return code "<<returnCode);
      return PLUS_FAIL;
    }

    const double thresholdMultiplier = 3.0; 

    if ( PlusMath::RemoveOutliersFromLSQR(aMatrix, bVector, resultVector, outlierFound, thresholdMultiplier, mean, stdev , notOutliersIndices) != PLUS_SUCCESS )
    {
      LOG_WARNING("Failed to remove outliers from linear equations!"); 
      return PLUS_FAIL; 
    }

    if (bVector.size()<= MINIMUM_NUMBER_OF_CALIBRATION_EQUATIONS)
    {
      LOG_ERROR("It was not possible calibrate! Not enough equations!"); 
      return PLUS_FAIL; 
    }
  }

  return returnStatus; 
}

//----------------------------------------------------------------------------
PlusStatus PlusMath::RemoveOutliersFromLSQR(vnl_sparse_matrix<double> &sparseMatrixLeftSide, 
                                            vnl_vector<double> &vectorRightSide, 
                                            vnl_vector<double> &resultVector, 
                                            bool &outlierFound, 
                                            double thresholdMultiplier/* = 3.0*/, 
                                            double* mean/*=NULL*/, 
                                            double* stdev/*=NULL*/,
                      vnl_vector<unsigned int>* nonOutlierIndices /*NULL*/)
{
  // Set outlierFound flag to false by default 
  outlierFound = false; 

  const unsigned int numberOfEquations = sparseMatrixLeftSide.rows(); 
  const unsigned int numberOfUnknowns = resultVector.size(); 

  if ( vectorRightSide.size() != numberOfEquations )
  {
    LOG_ERROR("Input A matrix and b vector dimensions were not met (number of equations were not the same)!"); 
    return PLUS_FAIL; 
  }

  if ( sparseMatrixLeftSide.cols() != numberOfUnknowns )
  {
    LOG_ERROR("Input A matrix dimension (columns) and number of unknowns are different (cols: " << sparseMatrixLeftSide.cols() << "  unknowns: " << numberOfUnknowns << ")" ); 
    return PLUS_FAIL; 
  }


  vnl_vector<double> differenceVector(numberOfEquations, 0); 
  // Compute the difference between the measured and computed data ( Ax - b )
  for ( unsigned int row = 0; row < numberOfEquations; ++row )
  {
    vnl_sparse_matrix<double>::row matrixRow = sparseMatrixLeftSide.get_row(row);
    double difference(0); 
    // Compute Ax - b for each row
    for ( unsigned int i = 0; i < numberOfUnknowns; ++i )
    {
      // difference = A1x = a11*x1 + a12*x2 + ...
      difference += (matrixRow[i].second * resultVector[i] ); 
    }
    // difference = A1x - b1 = a11*x1 + a12*x2 + ... - b1
    difference -= vectorRightSide[row]; 
    
    // Add the difference to the vector 
    differenceVector.put(row, difference); 
  }

  // Compute the mean difference 
  const double meanDifference = differenceVector.mean(); 

  // Compute the stdev of differences 
  vnl_vector<double> diffFromMean = differenceVector - meanDifference; 
  const double stdevDifference = sqrt( diffFromMean.squared_magnitude() / (1.0 * diffFromMean.size()) ); 

  LOG_DEBUG("Mean = " << std::fixed << meanDifference << "   Stdev = " << stdevDifference); 

  if ( mean != NULL )
  {
    *mean = meanDifference; 
  }

  if ( stdev != NULL )
  {
    *stdev = stdevDifference; 
  }

  // Temporary containers for input data 
  std::vector< vcl_vector<double> > matrixRowsData; 
  std::vector< vcl_vector<int> > matrixRowsIndecies; 
  std::vector<double> bVector;   
  std::vector<double> auxiliarNonOutlierIndicesVector;   
 
  vcl_vector<double> rowData(numberOfUnknowns, 0.0); 
  vcl_vector<int> rowIndecies(numberOfUnknowns, 0); 

  // Look for outliers in each equations 
  // If the difference from mean larger than thresholdMultiplier * stdev, remove it from equation 
  for ( unsigned int row = 0; row < numberOfEquations; ++row )
  {
    if ( fabs(differenceVector[row] - meanDifference) < thresholdMultiplier * stdevDifference )
    { // Not an outlier 

      // Copy data from matrix row in a format which is good for vnl_sparse_matrix<T>::set_row function 
      vnl_sparse_matrix<double>::row matrixRow = sparseMatrixLeftSide.get_row(row);
      for ( unsigned int i = 0; i < matrixRow.size(); ++i )
      {
        rowIndecies[i] = matrixRow[i].first; 
        rowData[i] = matrixRow[i].second; 
      }

      // Save matrix row data, indecies and result vector into std::vectors
      matrixRowsData.push_back(rowData); 
      matrixRowsIndecies.push_back(rowIndecies); 
      bVector.push_back(vectorRightSide[row]); 
      if (nonOutlierIndices != NULL)
      {
        auxiliarNonOutlierIndicesVector.push_back(nonOutlierIndices->get(row));
      }
    }
    else
    {
      // Outlier found
      outlierFound = true; 
      LOG_DEBUG("Outlier: " << std::fixed << differenceVector[row] << "(mean: " << meanDifference << "  stdev: " << stdevDifference << "  outlierTreshold: " << thresholdMultiplier * stdevDifference << ")" ); 
    }
  }

  // Resize matrices only if we found an outlier
  if ( outlierFound ) 
  {
    // Copy back the new aMatrix and bVector 
    vectorRightSide.clear(); 
    vectorRightSide.set_size(bVector.size()); 
    for ( unsigned int i = 0; i < bVector.size(); ++i )
    {
      vectorRightSide.put(i, bVector[i]); 
    }

  if (nonOutlierIndices != NULL)
  {
    (*nonOutlierIndices).clear();
      (*nonOutlierIndices).set_size(auxiliarNonOutlierIndicesVector.size());
    for ( unsigned int i = 0; i < auxiliarNonOutlierIndicesVector.size(); ++i )
      {
      (*nonOutlierIndices).put(i,auxiliarNonOutlierIndicesVector[i]);
      }
  }


    sparseMatrixLeftSide.resize(matrixRowsData.size(), numberOfUnknowns); 
    for ( unsigned int r = 0; r < matrixRowsData.size(); r++ )
    {
      sparseMatrixLeftSide.set_row(r, matrixRowsIndecies[r], matrixRowsData[r]); 
    }
  }
  else
  {
    LOG_DEBUG("*** Outlier removal was successful! No more outlier found!"); 
  }

  return PLUS_SUCCESS; 
}

//----------------------------------------------------------------------------
double PlusMath::GetPositionDifference(vtkMatrix4x4* aMatrix, vtkMatrix4x4* bMatrix)
{
  LOG_TRACE("PlusMath::GetPositionDifference"); 
  vtkSmartPointer<vtkTransform> aTransform = vtkSmartPointer<vtkTransform>::New(); 
  aTransform->SetMatrix(aMatrix); 

  vtkSmartPointer<vtkTransform> bTransform = vtkSmartPointer<vtkTransform>::New(); 
  bTransform->SetMatrix(bMatrix); 

  double ax = aTransform->GetPosition()[0]; 
  double ay = aTransform->GetPosition()[1]; 
  double az = aTransform->GetPosition()[2]; 

  double bx = bTransform->GetPosition()[0]; 
  double by = bTransform->GetPosition()[1]; 
  double bz = bTransform->GetPosition()[2]; 

  // Euclidean distance
  double distance = sqrt( pow(ax-bx,2) + pow(ay-by,2) + pow(az-bz,2) ); 

  return distance; 
}

//----------------------------------------------------------------------------
double PlusMath::GetOrientationDifference(vtkMatrix4x4* aMatrix, vtkMatrix4x4* bMatrix)
{
  vtkSmartPointer<vtkMatrix4x4> diffMatrix = vtkSmartPointer<vtkMatrix4x4>::New(); 
  vtkSmartPointer<vtkMatrix4x4> invBmatrix = vtkSmartPointer<vtkMatrix4x4>::New(); 

  vtkMatrix4x4::Invert(bMatrix, invBmatrix);  

  vtkMatrix4x4::Multiply4x4(aMatrix, invBmatrix, diffMatrix); 

  vtkSmartPointer<vtkTransform> diffTransform = vtkSmartPointer<vtkTransform>::New(); 
  diffTransform->SetMatrix(diffMatrix); 

  double angleDiff_rad= vtkMath::RadiansFromDegrees(diffTransform->GetOrientationWXYZ()[0]);

  double normalizedAngleDiff_rad = atan2( sin(angleDiff_rad), cos(angleDiff_rad) ); // normalize angle to domain -pi, pi 

  return vtkMath::DegreesFromRadians(normalizedAngleDiff_rad);
}

//----------------------------------------------------------------------------
// Spherical linear interpolation between two rotation quaternions.
// t is a value between 0 and 1 that interpolates between from and to (t=0 means the results is the same as "from").
// Precondition: no aliasing problems to worry about ("result" can be "from" or "to" param).
// Parameters: adjustSign - If true, then slerp will operate by adjusting the sign of the slerp to take shortest path. True is recommended, otherwise the interpolation sometimes give unexpected results. 
// References: From Adv Anim and Rendering Tech. Pg 364
void PlusMath::Slerp(double *result, double t, double *from, double *to, bool adjustSign /*= true*/)   
{
  const double* p = from; // just an alias to match q

  // calc cosine theta
  double cosom = from[0]*to[0]+from[1]*to[1]+from[2]*to[2]+from[3]*to[3]; // dot( from, to )

  // adjust signs (if necessary)
  double q[4];
  if (adjustSign && (cosom < (double)0.0))
  {
    cosom = -cosom;
    q[0] = -to[0];   // Reverse all signs
    q[1] = -to[1];
    q[2] = -to[2];
    q[3] = -to[3];
  }
  else
  {
    q[0] = to[0];
    q[1] = to[1];
    q[2] = to[2];
    q[3] = to[3];
  }

  // Calculate coefficients
  double sclp, sclq;
  if (((double)1.0 - cosom) > (double)0.0001) // 0.0001 -> some epsillon
  {
    // Standard case (slerp)
    double omega, sinom;
    omega = acos( cosom ); // extract theta from dot product's cos theta
    sinom = sin( omega );
    sclp  = sin( ((double)1.0 - t) * omega ) / sinom;
    sclq  = sin( t * omega ) / sinom;
  }
  else
  {
    // Very close, do linear interp (because it's faster)
    sclp = (double)1.0 - t;
    sclq = t;
  }

  for (int i=0; i<4; i++)
  {
    result[i] = sclp * p[i] + sclq * q[i];
  }
}

//----------------------------------------------------------------------------
PlusStatus PlusMath::ConstrainRotationToTwoAxes(double downVector_Sensor[3], int notRotatingAxisIndex, vtkMatrix4x4* sensorToSouthWestDownTransform)
{
  if (notRotatingAxisIndex<0 || notRotatingAxisIndex>=3)
  {
    LOG_ERROR("Invalid notRotatingAxisIndex is specified (valid values are 0, 1, 2). Use default: 1.");
    notRotatingAxisIndex = 1;
  }

  // Sensor axis vector that is assumed to always point to West. This is chosen so that cross(westVector_Sensor, downVector_Sensor) = southVector_Sensor.
  double westVector_Sensor[4]={0,0,0,0};
  double southVector_Sensor[4] = {0,0,0,0};

  westVector_Sensor[notRotatingAxisIndex]=1; 

  vtkMath::Cross(westVector_Sensor, downVector_Sensor, southVector_Sensor); // compute South
  vtkMath::Normalize(southVector_Sensor);
  vtkMath::Cross(downVector_Sensor, southVector_Sensor, westVector_Sensor); // compute West
  vtkMath::Normalize(westVector_Sensor);

  // row 0
  sensorToSouthWestDownTransform->SetElement(0,0,southVector_Sensor[0]);
  sensorToSouthWestDownTransform->SetElement(0,1,southVector_Sensor[1]);
  sensorToSouthWestDownTransform->SetElement(0,2,southVector_Sensor[2]);
  // row 1
  sensorToSouthWestDownTransform->SetElement(1,0,westVector_Sensor[0]);
  sensorToSouthWestDownTransform->SetElement(1,1,westVector_Sensor[1]);
  sensorToSouthWestDownTransform->SetElement(1,2,westVector_Sensor[2]);
  // row 2
  sensorToSouthWestDownTransform->SetElement(2,0,downVector_Sensor[0]);
  sensorToSouthWestDownTransform->SetElement(2,1,downVector_Sensor[1]);
  sensorToSouthWestDownTransform->SetElement(2,2,downVector_Sensor[2]);

  if (notRotatingAxisIndex<0 || notRotatingAxisIndex>=3)
  {
    return PLUS_FAIL;
  }
  else
  {
    return PLUS_SUCCESS;  
  }

}

//----------------------------------------------------------------------------
std::string PlusMath::GetTransformParametersString(vtkTransform* transform)
{
  double rotation[3];
  double translation[3];
  double scale[3];
  transform->GetOrientation(rotation);
  transform->GetPosition(translation);
  transform->GetScale(scale);

  std::ostringstream result;
  result << std::setprecision(4) << "Rotation: (" << rotation[0] << ", " << rotation[1] << ", " << rotation[2]
    << ")  Translation: (" << translation[0] << ", " << translation[1] << ", " << translation[2]
    << ")  Scale: (" << scale[0] << ", " << scale[1] << ", " << scale[2] << ")";

  return result.str();
}

//----------------------------------------------------------------------------
std::string PlusMath::GetTransformParametersString(vtkMatrix4x4* matrix)
{
  vtkSmartPointer<vtkTransform> transform = vtkSmartPointer<vtkTransform>::New(); 
  transform->SetMatrix(matrix); 

  return PlusMath::GetTransformParametersString(transform); 
}

//----------------------------------------------------------------------------
void PlusMath::ConvertVtkMatrixToVnlMatrix(const vtkMatrix4x4* inVtkMatrix, vnl_matrix_fixed<double,4,4>& outVnlMatrix )
{
  LOG_TRACE("PlusMath::ConvertVtkMatrixToVnlMatrix"); 

  for (int row = 0; row < 4; row++)
  {
    for (int column = 0; column < 4; column++)
    {
      outVnlMatrix.put(row,column, inVtkMatrix->GetElement(row,column)); 
    }
  }
}

//----------------------------------------------------------------------------
void PlusMath::ConvertVnlMatrixToVtkMatrix(const vnl_matrix_fixed<double,4,4>& inVnlMatrix, vtkMatrix4x4* outVtkMatrix )
{
  LOG_TRACE("PlusMath::ConvertVnlMatrixToVtkMatrix");

  outVtkMatrix->Identity(); 

  for (int row = 0; row < 3; row++)
  {
    for (int column = 0; column < 4; column++)
    {
      outVtkMatrix->SetElement(row,column, inVnlMatrix.get(row, column) ); 
    }
  }
}

//----------------------------------------------------------------------------
void PlusMath::PrintVtkMatrix(vtkMatrix4x4* matrix, std::ostringstream &stream, int precision/* = 3*/)
{
  LOG_TRACE("PlusMath::PrintVtkMatrix");

  for ( int i = 0; i < 4; i++ )
  {
    if (i>0)
    {
      stream << std::endl;
    }
    for ( int j = 0; j < 4; j++ )
    {
      stream << std::fixed << std::setprecision(precision) << std::setw(precision+3) << std::right << matrix->GetElement(i,j) << " ";
    }
  }
}

//----------------------------------------------------------------------------
void PlusMath::PrintMatrix(vnl_matrix_fixed<double,4,4> matrix, std::ostringstream &stream, int precision/* = 3*/)
{
  vtkSmartPointer<vtkMatrix4x4> matrixVtk=vtkSmartPointer<vtkMatrix4x4>::New();
  ConvertVnlMatrixToVtkMatrix(matrix,matrixVtk);
  PrintVtkMatrix(matrixVtk, stream, precision);
}

//----------------------------------------------------------------------------
void PlusMath::LogVtkMatrix(vtkMatrix4x4* matrix, int precision/* = 3*/)
{
  LOG_TRACE("PlusMath::LogVtkMatrix");

  std::ostringstream matrixStream; 
  PlusMath::PrintVtkMatrix(matrix, matrixStream, precision);
  LOG_INFO(matrixStream.str());
}

//----------------------------------------------------------------------------
void PlusMath::LogMatrix(const vnl_matrix_fixed<double,4,4>& matrix, int precision/* = 3*/)
{
  vtkSmartPointer<vtkMatrix4x4> matrixVtk=vtkSmartPointer<vtkMatrix4x4>::New();
  ConvertVnlMatrixToVtkMatrix(matrix,matrixVtk);
  LogVtkMatrix(matrixVtk, precision);
}

//----------------------------------------------------------------------------
// Description
// Calculate distance between a line (defined by two points) and a point
double PlusMath::ComputeDistanceLinePoint( const double x[3], // linepoint 1
                                           const double y[3], // linepoint 2
                                           const double z[3] // target point
                                           )
{
  double u[3];
  double v[3];
  double w[3];

  u[0] = y[0] - x[0];
  u[1] = y[1] - x[1];
  u[2] = y[2] - x[2];

  vtkMath::Normalize(u);

  v[0] = z[0] - x[0];
  v[1] = z[1] - x[1];
  v[2] = z[2] - x[2];

  double dot = vtkMath::Dot(u,v);

  w[0] = v[0] - dot*u[0];
  w[1] = v[1] - dot*u[1];
  w[2] = v[2] - dot*u[2];

  return sqrt(vtkMath::Dot(w,w));
}

//----------------------------------------------------------------------------
PlusStatus PlusMath::ComputeMeanAndStdev(const std::vector<double> &values, double &mean, double &stdev)
{
  if (values.empty())
  {
    LOG_ERROR("PlusMath::ComputeMeanAndStdev failed, the input vector is empty");
    return PLUS_FAIL;
  }
  double sum=0;
  for (std::vector<double>::const_iterator it=values.begin(); it!=values.end(); ++it)
  {
    sum+=*it;
  }
  mean=sum/double(values.size());
  double variance=0;
  for (std::vector<double>::const_iterator it=values.begin(); it!=values.end(); ++it)
  {
    variance+=(*it-mean)*(*it-mean);
  }
  stdev=sqrt(variance/double(values.size())); 
  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus PlusMath::ComputeRms(const std::vector<double> &values, double &rms)
{
  if (values.empty())
  {
    LOG_ERROR("PlusMath::ComputeRms failed, the input vector is empty");
    return PLUS_FAIL;
  }
  double sumSquares=0;
  for (std::vector<double>::const_iterator it=values.begin(); it!=values.end(); ++it)
  {
    sumSquares+=(*it) * (*it);
  }
  double meanSquares=sumSquares/double(values.size());
  rms=sqrt(meanSquares); 
  return PLUS_SUCCESS;
}

//----------------------------------------------------------------------------
PlusStatus PlusMath::ComputePercentile(const std::vector<double> &values, double percentileToKeep, double &valueMax, double &valueMean, double &valueStdev)
{
  std::vector<double> sortedValues=values;
  std::sort(sortedValues.begin(), sortedValues.end());

  int numberOfKeptValues = PlusMath::Round( (double)sortedValues.size() * percentileToKeep );
  sortedValues.erase(sortedValues.begin()+numberOfKeptValues, sortedValues.end());

  valueMax=sortedValues.back();
  ComputeMeanAndStdev(sortedValues, valueMean, valueStdev);

  return PLUS_SUCCESS;
}

#if _MSC_VER == 1600 // VS 2010
namespace std
{
  double round(double arg)
  {
	  return PlusMath::Round(arg);
  }
}
#endif