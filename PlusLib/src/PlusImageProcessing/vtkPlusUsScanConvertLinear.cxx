/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/ 

#include "PlusConfigure.h"

#include "vtkPlusUsScanConvertLinear.h"

#include "vtkObjectFactory.h"
#include "vtkXMLDataElement.h"
#include "vtkImageReslice.h"
#include "vtkImageData.h"
#include "vtkAlgorithmOutput.h"

vtkStandardNewMacro(vtkPlusUsScanConvertLinear);

//----------------------------------------------------------------------------
vtkPlusUsScanConvertLinear::vtkPlusUsScanConvertLinear()
{
  this->ImagingDepthMm=50.0;
  this->TransducerWidthMm=38.0;

  this->ImageReslice=vtkImageReslice::New();  
}

//----------------------------------------------------------------------------
vtkPlusUsScanConvertLinear::~vtkPlusUsScanConvertLinear()
{
  this->ImageReslice->Delete();
  this->ImageReslice=NULL;  
}

void vtkPlusUsScanConvertLinear::PrintSelf(ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
  os << indent << "ImagingDepthMm: "<< this->ImagingDepthMm << "\n";
  os << indent << "TransducerWidthMm: "<< this->TransducerWidthMm << "\n";
}

//-----------------------------------------------------------------------------
void vtkPlusUsScanConvertLinear::SetInputConnection(vtkAlgorithmOutput* input)
{
  this->ImageReslice->SetInputConnection(input);
}

//-----------------------------------------------------------------------------
void vtkPlusUsScanConvertLinear::SetInputData(vtkDataObject *input)
{
  this->ImageReslice->SetInputData(input);
}

//-----------------------------------------------------------------------------
void vtkPlusUsScanConvertLinear::Update()
{
  this->ImageReslice->SetOutputExtent(this->OutputImageExtent);
  // In Plus the convention is that the image coordinate system has always unit spacing and zero origin
  this->ImageReslice->SetOutputSpacing(1.0, 1.0, 1.0);

  // The direction cosines give the x, y, and z axes for the output volume.
  // Updating whole extent is needed when the requested extent is smaller than the producer's whole extent
  this->ImageReslice->GetInputConnection(0,0)->GetProducer()->UpdateWholeExtent();
  vtkImageData* inputImage=this->ImageReslice->GetImageDataInput(0);  
  if (inputImage==NULL)
  {
    LOG_ERROR("vtkPlusUsScanConvertLinear::Update failed: no input image is specified");
    return;
  }

  inputImage->GetExtent(this->InputImageExtent);  
  int scanLineLengthPixels=this->InputImageExtent[1]-this->InputImageExtent[0]+1;
  int numberOfScanLines=this->InputImageExtent[3]-this->InputImageExtent[2]+1;

  // xVec: controls the width of the output image, if larger then image becomes narrower
  double inputWidthSpacing=this->TransducerWidthMm/static_cast<double>(numberOfScanLines);
  double xVec[3]={0, (this->OutputImageSpacing[0]/inputWidthSpacing), 0};
  
  // yVec: controls the height of the output image, if larger then image becomes shorter
  double inputDepthSpacing=this->ImagingDepthMm/static_cast<double>(scanLineLengthPixels);
  double yVec[3]={this->OutputImageSpacing[1]/inputDepthSpacing, 0, 0};

  double zVec[3]={0,0,1.0};
  this->ImageReslice->SetResliceAxesDirectionCosines(xVec, yVec, zVec);

  // Default transducer center is horizontally centered, with 0 offset along y axis
  double halfImageWidthPixel=numberOfScanLines/2*inputWidthSpacing/this->OutputImageSpacing[0];
  double transducerCenterPixel[2] = { halfImageWidthPixel, 0};
  if (this->TransducerCenterPixelSpecified)
  {
    transducerCenterPixel[0]=this->TransducerCenterPixel[0];
    transducerCenterPixel[1]=this->TransducerCenterPixel[1];
  }

  this->ImageReslice->SetOutputOrigin(-this->TransducerCenterPixel[0]+halfImageWidthPixel,-this->TransducerCenterPixel[1],0);

  this->ImageReslice->Update();
}

//-----------------------------------------------------------------------------
vtkImageData* vtkPlusUsScanConvertLinear::GetOutput()
{
  return this->ImageReslice->GetOutput();
}

//-----------------------------------------------------------------------------
PlusStatus vtkPlusUsScanConvertLinear::ReadConfiguration(vtkXMLDataElement* scanConversionElement)
{
  LOG_TRACE("vtkPlusUsScanConvertLinear::ReadConfiguration"); 
  
  if (this->Superclass::ReadConfiguration(scanConversionElement)!=PLUS_SUCCESS)
  {
    return PLUS_FAIL;
  }

  XML_READ_SCALAR_ATTRIBUTE_OPTIONAL(double, ImagingDepthMm, scanConversionElement);
  XML_READ_SCALAR_ATTRIBUTE_OPTIONAL(double, TransducerWidthMm, scanConversionElement);
 
  return PLUS_SUCCESS;
}

//-----------------------------------------------------------------------------
PlusStatus vtkPlusUsScanConvertLinear::WriteConfiguration(vtkXMLDataElement* scanConversionElement)
{
  LOG_TRACE("vtkPlusUsScanConvertLinear::WriteConfiguration"); 

  if (this->Superclass::WriteConfiguration(scanConversionElement)!=PLUS_SUCCESS)
  {
    return PLUS_FAIL;
  }

  scanConversionElement->SetDoubleAttribute("ImagingDepthMm", this->ImagingDepthMm);
  scanConversionElement->SetDoubleAttribute("TransducerWidthMm", this->TransducerWidthMm);

  return PLUS_SUCCESS;
}

//-----------------------------------------------------------------------------
PlusStatus vtkPlusUsScanConvertLinear::GetScanLineEndPoints(int scanLineIndex, double scanlineStartPoint_OutputImage[4],double scanlineEndPoint_OutputImage[4])
{
  int numberOfScanLines=this->InputImageExtent[3]-this->InputImageExtent[2]+1;
  if (scanLineIndex<0 || scanLineIndex>=numberOfScanLines)
  {
    LOG_ERROR("GetScanLineEndPoints failed: requestd scanLine="<<scanLineIndex<<" is out of the valid range (0-"<<numberOfScanLines-1<<")");
    return PLUS_FAIL;
  }
  
  int outputImageSizePixel[2]=
  {
    this->OutputImageExtent[1]-this->OutputImageExtent[0]+1,
    this->OutputImageExtent[3]-this->OutputImageExtent[2]+1
  };
  
  // Default transducer center is horizontally centered in the frame, with 0 offset along y axis
  double transducerCenterPixel[2] = { 0.5*outputImageSizePixel[0], 0 };
  if (this->TransducerCenterPixelSpecified)
  {
    transducerCenterPixel[0]=this->TransducerCenterPixel[0];
    transducerCenterPixel[1]=this->TransducerCenterPixel[1];
  }

  double imageWidthPixel=this->TransducerWidthMm/this->OutputImageSpacing[0];
  double transducerCornerPixel[2] = { transducerCenterPixel[0]-0.5*imageWidthPixel, transducerCenterPixel[1] };
  double scanlineSpacingXPixel=imageWidthPixel/double(numberOfScanLines);
  scanlineStartPoint_OutputImage[0] = transducerCornerPixel[0]+double(scanLineIndex)*scanlineSpacingXPixel;
  scanlineStartPoint_OutputImage[1] = transducerCornerPixel[1];
  scanlineStartPoint_OutputImage[2] = 0;
  scanlineStartPoint_OutputImage[3] = 1;

  scanlineEndPoint_OutputImage[0] = scanlineStartPoint_OutputImage[0];
  scanlineEndPoint_OutputImage[1] = transducerCornerPixel[1] + this->ImagingDepthMm/this->OutputImageSpacing[1];
  scanlineEndPoint_OutputImage[2] = 0;
  scanlineEndPoint_OutputImage[3] = 1;

  return PLUS_SUCCESS;
}

//-----------------------------------------------------------------------------
double vtkPlusUsScanConvertLinear::GetDistanceBetweenScanlineSamplePointsMm()
{
  int scanLineLengthPixels=this->InputImageExtent[1]-this->InputImageExtent[0]+1;
  if (scanLineLengthPixels<1)
  {
    LOG_ERROR("Cannot determine DistanceBetweenScanlineSamplePointsMm because scanLineLengthPixels="<<scanLineLengthPixels<<" is invalid");
    return 0.0;
  }
  double distanceBetweenScanlineSamplePointsMm=this->ImagingDepthMm/double(scanLineLengthPixels);
  return distanceBetweenScanlineSamplePointsMm;
}
