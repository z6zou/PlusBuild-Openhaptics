/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

/*!
  \file vtkDataCollectorTest2.cxx
  \brief This a test program acquires both video and tracking data and writes them into separate metafiles
*/

// Local includes
#include "PlusConfigure.h"
#include "vtkPlusBuffer.h"
#include "vtkPlusChannel.h"
#include "vtkPlusDataCollector.h"
#include "vtkPlusDataSource.h"
#include "vtkPlusDevice.h"
#include "vtkPlusSavedDataSource.h"

// VTK includes
#include <vtkSmartPointer.h>
#include <vtkTimerLog.h>
#include <vtkXMLUtilities.h>
#include <vtksys/CommandLineArguments.hxx>
#include <vtksys/SystemTools.hxx>

int main(int argc, char** argv)
{
  int numberOfFailures(0);
  std::string inputConfigFileName;
  double inputAcqTimeLength(20);
  std::string outputTrackerBufferSequenceFileName("TrackerBufferMetafile.nrrd");
  std::string outputVideoBufferSequenceFileName("VideoBufferMetafile.nrrd");
  std::string inputVideoBufferMetafile;
  std::string inputTrackerBufferMetafile;
  bool outputCompressed(true);

  int verboseLevel = vtkPlusLogger::LOG_LEVEL_UNDEFINED;

  vtksys::CommandLineArguments args;
  args.Initialize(argc, argv);

  args.AddArgument("--config-file", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &inputConfigFileName, "Name of the input configuration file.");
  args.AddArgument("--acq-time-length", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &inputAcqTimeLength, "Length of acquisition time in seconds (Default: 20s)");
  args.AddArgument("--video-buffer-seq-file", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &inputVideoBufferMetafile, "Video buffer sequence metafile.");
  args.AddArgument("--tracker-buffer-seq-file", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &inputTrackerBufferMetafile, "Tracker buffer sequence metafile.");
  args.AddArgument("--output-tracker-buffer-seq-file", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &outputTrackerBufferSequenceFileName, "Filename of the output tracker buffer sequence metafile (Default: TrackerBufferMetafile)");
  args.AddArgument("--output-video-buffer-seq-file", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &outputVideoBufferSequenceFileName, "Filename of the output video buffer sequence metafile (Default: VideoBufferMetafile)");
  args.AddArgument("--output-compressed", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &outputCompressed, "Compressed output (0=non-compressed, 1=compressed, default:compressed)");
  args.AddArgument("--verbose", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &verboseLevel, "Verbose level (1=error only, 2=warning, 3=info, 4=debug, 5=trace)");

  if (!args.Parse())
  {
    std::cerr << "Problem parsing arguments" << std::endl;
    std::cout << "Help: " << args.GetHelp() << std::endl;
    exit(EXIT_FAILURE);
  }

  vtkPlusLogger::Instance()->SetLogLevel(verboseLevel);

  if (inputConfigFileName.empty())
  {
    std::cerr << "input-config-file-name is required" << std::endl;
    exit(EXIT_FAILURE);
  }

  ///////////////

  vtkSmartPointer<vtkXMLDataElement> configRootElement = vtkSmartPointer<vtkXMLDataElement>::New();
  if (PlusXmlUtils::ReadDeviceSetConfigurationFromFile(configRootElement, inputConfigFileName.c_str()) == PLUS_FAIL)
  {
    LOG_ERROR("Unable to read configuration from file " << inputConfigFileName.c_str());
    return EXIT_FAILURE;
  }

  vtkPlusConfig::GetInstance()->SetDeviceSetConfigurationData(configRootElement);

  vtkSmartPointer<vtkPlusDataCollector> dataCollector = vtkSmartPointer<vtkPlusDataCollector>::New();

  if (dataCollector->ReadConfiguration(configRootElement) != PLUS_SUCCESS)
  {
    LOG_ERROR("Unable to configure data collector in configuration file specified by: " << inputConfigFileName);
    exit(EXIT_FAILURE);
  }
  vtkPlusDevice* videoDevice = NULL;
  vtkPlusDevice* trackerDevice = NULL;

  if (!inputVideoBufferMetafile.empty())
  {
    if (dataCollector->GetDevice(videoDevice, "VideoDevice") != PLUS_SUCCESS)
    {
      LOG_ERROR("Unable to locate the device with Id=\"VideoDevice\". Check config file.");
      exit(EXIT_FAILURE);
    }
    vtkPlusSavedDataSource* videoSource = dynamic_cast<vtkPlusSavedDataSource*>(videoDevice);
    if (videoSource == NULL)
    {
      LOG_ERROR("Unable to cast device to vtkPlusSavedDataSource.");
      exit(EXIT_FAILURE);
    }
    videoSource->SetSequenceFile(inputVideoBufferMetafile.c_str());
  }

  if (!inputTrackerBufferMetafile.empty())
  {
    if (dataCollector->GetDevice(trackerDevice, "TrackerDevice") != PLUS_SUCCESS)
    {
      LOG_ERROR("Unable to locate the device with Id=\"TrackerDevice\". Check config file.");
      exit(EXIT_FAILURE);
    }
    vtkPlusSavedDataSource* tracker = dynamic_cast<vtkPlusSavedDataSource*>(trackerDevice);
    if (tracker == NULL)
    {
      LOG_ERROR("Unable to cast tracker to vtkPlusSavedDataSource");
      exit(EXIT_FAILURE);
    }
    tracker->SetSequenceFile(inputTrackerBufferMetafile.c_str());
  }

  if (dataCollector->Connect() != PLUS_SUCCESS)
  {
    LOG_ERROR("Failed to connect to data collector!");
    exit(EXIT_FAILURE);
  }

  if (dataCollector->Start() != PLUS_SUCCESS)
  {
    LOG_ERROR("Failed to start data collection");
    exit(EXIT_FAILURE);
  }

  const double acqStartTime = vtkTimerLog::GetUniversalTime();

  while (acqStartTime + inputAcqTimeLength > vtkTimerLog::GetUniversalTime())
  {
    LOG_INFO(acqStartTime + inputAcqTimeLength - vtkTimerLog::GetUniversalTime() << " seconds left...");
    vtksys::SystemTools::Delay(1000);
  }

  vtkSmartPointer<vtkPlusBuffer> videobuffer = vtkSmartPointer<vtkPlusBuffer>::New();
  vtkPlusChannel* aChannel(NULL);
  vtkPlusDataSource* aSource(NULL);
  if (videoDevice == NULL || videoDevice->GetOutputChannelByName(aChannel, "VideoStream") != PLUS_SUCCESS || aChannel == NULL || aChannel->GetVideoSource(aSource) != PLUS_SUCCESS)
  {
    LOG_ERROR("Unable to retrieve the video source.");
    exit(EXIT_FAILURE);
  }

  aSource->DeepCopyBufferTo(*videobuffer);

  vtkSmartPointer<vtkPlusDevice> tracker = vtkSmartPointer<vtkPlusDevice>::New();
  if (trackerDevice != NULL)
  {
    LOG_INFO("Copy tracker");
    tracker->DeepCopy(*trackerDevice);
  }

  if (videoDevice != NULL)
  {
    std::string fullPath = vtkPlusConfig::GetInstance()->GetOutputPath(outputVideoBufferSequenceFileName);
    LOG_INFO("Write video buffer to " << fullPath);
    videobuffer->WriteToSequenceFile(fullPath.c_str(), outputCompressed);
  }

  if (trackerDevice != NULL)
  {
    std::string fullPath = vtkPlusConfig::GetInstance()->GetOutputPath(outputTrackerBufferSequenceFileName);
    LOG_INFO("Write tracker buffer to " << fullPath);
    tracker->WriteToolsToSequenceFile(fullPath.c_str(), outputCompressed);
  }

  if (videoDevice != NULL)
  {
    std::string fullPath = vtkPlusConfig::GetInstance()->GetOutputPath(outputVideoBufferSequenceFileName);
    if (vtksys::SystemTools::FileExists(fullPath.c_str(), true))
    {
      LOG_INFO("Remove generated video metafile!");
      if (!vtksys::SystemTools::RemoveFile(fullPath.c_str()))
      {
        LOG_ERROR("Unable to remove generated video buffer: " << fullPath);
        numberOfFailures++;
      }
    }
    else
    {
      LOG_ERROR("Unable to find video buffer at: " << fullPath);
      numberOfFailures++;
    }
  }

  if (trackerDevice != NULL)
  {
    std::string fullPath = vtkPlusConfig::GetInstance()->GetOutputPath(outputTrackerBufferSequenceFileName);
    if (vtksys::SystemTools::FileExists(fullPath.c_str(), true))
    {
      LOG_INFO("Remove generated tracker metafile!");
      if (!vtksys::SystemTools::RemoveFile(fullPath.c_str()))
      {
        LOG_ERROR("Unable to remove generated tracker buffer: " << fullPath);
        numberOfFailures++;
      }
    }
    else
    {
      LOG_ERROR("Unable to find tracker buffer at: " << fullPath);
      numberOfFailures++;
    }
  }

  if (dataCollector->Stop() != PLUS_SUCCESS)
  {
    LOG_ERROR("Failed to stop data collection!");
    numberOfFailures++;
  }

  if (numberOfFailures > 0)
  {
    LOG_ERROR("Number of failures: " << numberOfFailures);
    return EXIT_FAILURE;
  }

  std::cout << "Test completed successfully!" << std::endl;
  return EXIT_SUCCESS;
}