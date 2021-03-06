/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

// Local includes
#include "PlusConfigure.h"
#include "PlusFidPatternRecognition.h"
#include "PlusPatternLocResultFile.h"
#include "vtkFcsvReader.h"

// STL includes
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>

// VTK includes
#include <vtksys/CommandLineArguments.hxx>
#include <vtkXMLDataElement.h>
#include <vtkXMLUtilities.h>

// ITK includes
#include "itkLandmarkSpatialObject.h"

//----------------------------------------------------------------------------
void WriteFiducialPositions(std::ofstream& outFile, const std::string& inputTestcaseName, const std::string& inputImageSequenceFileName, const std::string& fiducialPosFileName)
{
  vtkSmartPointer<vtkFcsvReader> readerf = vtkSmartPointer<vtkFcsvReader>::New();
  readerf->SetFileName(fiducialPosFileName);
  readerf->Update();
  auto fcsvData = readerf->GetFcsvDataObject();

  double sumFiducialNum = 0;  // divide by frame number

  LOG_DEBUG("Number Of Points: " << fcsvData.points.size());
  if (fcsvData.points.size() == 0)
  {
    LOG_ERROR("No fiducial points.");
    exit(EXIT_FAILURE);
  }

  std::vector<FcsvPoint>::iterator it = fcsvData.points.begin();
  //int fidNum = 7 ; // number of fiducials for a vector, 7 because 7 is max number of fiducials visible in the phantom
  int firstFrameIndex = std::numeric_limits<int>::max();
  int lastFrameIndex = -1;
  while (it != fcsvData.points.end())
  {
    int frameIndex = (*it).position[2];
    if (firstFrameIndex > frameIndex)
    {
      firstFrameIndex = frameIndex;
    }
    if (lastFrameIndex < frameIndex)
    {
      lastFrameIndex = frameIndex;
    }
    it++;
  }
  int numberOfFrames = lastFrameIndex - firstFrameIndex + 1;

  for (int currentFrameIndex = firstFrameIndex; currentFrameIndex <= lastFrameIndex; currentFrameIndex++)
  {
    std::vector<FcsvPoint>::iterator it = fcsvData.points.begin();
    std::vector<std::vector<double>> foundDotsCoordinateValue;
    int validFidNum = 0;
    while (it != fcsvData.points.end())
    {
      if (currentFrameIndex == (*it).position[2])
      {
        // done to comply with earlier code ( see Segmentation.cpp void Segmentation::segment )
        std::vector<double> fiducial(4, 0);
        fiducial[0] = (*it).position[0];
        fiducial[1] = (*it).position[1];
        fiducial[2] = 0;
        fiducial[3] = 1;
        if ((*it).position[0] != 0.0 || (*it).position[1] != 0.0)
        {
          // if coordinates are 0,0 it means that the fiducial was not found
          validFidNum++;
        }
        foundDotsCoordinateValue.push_back(fiducial);
      }
      it++;
    }

    PlusPatternRecognitionResult patRecognitionResults;
    patRecognitionResults.SetFoundDotsCoordinateValue(foundDotsCoordinateValue);
    patRecognitionResults.SetDotsFound(true);

    sumFiducialNum = sumFiducialNum + validFidNum;

    PlusUsFidSegResultFile::WriteSegmentationResults(outFile, patRecognitionResults, inputTestcaseName, currentFrameIndex, inputImageSequenceFileName);

    if (vtkPlusLogger::Instance()->GetLogLevel() >= vtkPlusLogger::LOG_LEVEL_DEBUG)
    {
      PlusUsFidSegResultFile::WriteSegmentationResults(std::cout, patRecognitionResults, inputTestcaseName, currentFrameIndex, inputImageSequenceFileName);
    }

  }

  double meanFid = sumFiducialNum / numberOfFrames;
  PlusUsFidSegResultFile::WriteSegmentationResultsStats(outFile,  meanFid);
}

//----------------------------------------------------------------------------
int main(int argc, char** argv)
{
  std::string inputTestDataDir;
  std::string inputFcsvFileName;
  std::string inputImageSequenceFileName;
  std::string inputTestcaseName;
  std::string outputXmlFileName;

  int verboseLevel(vtkPlusLogger::LOG_LEVEL_UNDEFINED);

  vtksys::CommandLineArguments args;
  args.Initialize(argc, argv);

  args.AddArgument("--test-data-dir", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &inputTestDataDir, "Test data directory");
  args.AddArgument("--fcsv-file", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &inputFcsvFileName, "Name of file storing fiducial point coordinates");
  args.AddArgument("--img-seq-file", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &inputImageSequenceFileName, "Filename of the input image sequence. Segmentation will be performed for all frames of the sequence.");
  args.AddArgument("--testcase", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &inputTestcaseName, "Name of the test case that will be printed to the output");
  args.AddArgument("--output-xml-file", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &outputXmlFileName, "Name of file storing results of a new segmentation (fiducial coordinates, intensity, angle)");
  args.AddArgument("--verbose", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &verboseLevel, "Verbose level (1=error only, 2=warning, 3=info, 4=debug, 5=trace)");

  if (!args.Parse())
  {
    std::cerr << "Problem parsing arguments" << std::endl;
    std::cout << "Help: " << args.GetHelp() << std::endl;
    exit(EXIT_FAILURE);
  }

  vtkPlusLogger::Instance()->SetLogLevel(verboseLevel);

  if (inputImageSequenceFileName.empty() || inputFcsvFileName.empty() || inputTestcaseName.empty() || outputXmlFileName.empty())
  {
    std::cerr << "--img-seq-file, --input-fcsv-file, --input-testcase-name, and --output-xml-file parameters are required" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::ofstream outputXmlFile;
  outputXmlFile.open(outputXmlFileName.c_str());
  PlusUsFidSegResultFile::WriteSegmentationResultsHeader(outputXmlFile);

  PlusFidPatternRecognition patternRecognition;
  PlusUsFidSegResultFile::WriteSegmentationResultsParameters(outputXmlFile, patternRecognition, inputFcsvFileName);

  std::string inputFcsvFilePath = inputTestDataDir + "/" + inputFcsvFileName;
  WriteFiducialPositions(outputXmlFile, inputTestcaseName, inputImageSequenceFileName, inputFcsvFilePath);
  PlusUsFidSegResultFile::WriteSegmentationResultsFooter(outputXmlFile);
  outputXmlFile.close();

  return EXIT_SUCCESS;
}