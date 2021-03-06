/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#include "PlusConfigure.h"

#include "vtksys/CommandLineArguments.hxx"
#include "vtkSmartPointer.h"
#include "vtkTransform.h"
#include "vtkMatrix4x4.h"

#include "PlusMath.h"
#include "vtkPlusTransformRepository.h"
#include "PlusTrackedFrame.h"
#include "vtkXMLUtilities.h"

int main(int argc, char** argv)
{
  // Parse command-line arguments
  bool printHelp(false);
  int verboseLevel(vtkPlusLogger::LOG_LEVEL_UNDEFINED);
  vtksys::CommandLineArguments args;
  args.Initialize(argc, argv);
  args.AddArgument("--help", vtksys::CommandLineArguments::NO_ARGUMENT, &printHelp, "Print this help.");
  args.AddArgument("--verbose", vtksys::CommandLineArguments::EQUAL_ARGUMENT, &verboseLevel, "Verbose level (1=error only, 2=warning, 3=info, 4=debug, 5=trace)");
  if (!args.Parse())
  {
    std::cerr << "Problem parsing arguments" << std::endl;
    std::cout << "Help: " << args.GetHelp() << std::endl;
    exit(EXIT_FAILURE);
  }

  if (printHelp)
  {
    std::cout << args.GetHelp() << std::endl;
    exit(EXIT_SUCCESS);

  }

  vtkPlusLogger::Instance()->SetLogLevel(verboseLevel);

  /////////////////////////////////////////////////////////////////////////////
  // Set up coordinate transforms

  vtkSmartPointer<vtkPlusTransformRepository> transformRepository = vtkSmartPointer<vtkPlusTransformRepository>::New();

  double dProbeToTrackerError(0.1235);
  vtkSmartPointer<vtkMatrix4x4> mxProbeToTracker = vtkSmartPointer<vtkMatrix4x4>::New();
  mxProbeToTracker->Element[0][3] = 15;
  mxProbeToTracker->Element[0][0] = -0.5;
  mxProbeToTracker->Element[1][1] = -0.8;
  PlusTransformName tnProbeToTracker("Probe", "Tracker");
  transformRepository->SetTransform(tnProbeToTracker, mxProbeToTracker, TOOL_INVALID);
  transformRepository->SetTransformPersistent(tnProbeToTracker, true);
  transformRepository->SetTransformError(tnProbeToTracker, dProbeToTrackerError);

  PlusTrackedFrame trackedFrame;
  vtkSmartPointer<vtkMatrix4x4> mxStylusToTracker = vtkSmartPointer<vtkMatrix4x4>::New();
  mxStylusToTracker->Element[1][3] = 25;
  mxStylusToTracker->Element[0][0] = 0.1;
  mxStylusToTracker->Element[1][0] = 0.2;
  mxStylusToTracker->Element[2][0] = -0.4;
  trackedFrame.SetFrameTransform(PlusTransformName("Stylus", "Tracker"), mxStylusToTracker);
  trackedFrame.SetFrameTransformStatus(PlusTransformName("Stylus", "Tracker"), TOOL_OK);

  vtkSmartPointer<vtkMatrix4x4> mxPhantomToTracker = vtkSmartPointer<vtkMatrix4x4>::New();
  mxPhantomToTracker->Element[2][2] = -4;
  mxPhantomToTracker->Element[0][3] = 2;
  mxPhantomToTracker->Element[1][3] = 2;
  mxPhantomToTracker->Element[2][3] = 20;
  trackedFrame.SetFrameTransform(PlusTransformName("Phantom", "Tracker"), mxPhantomToTracker);
  trackedFrame.SetFrameTransformStatus(PlusTransformName("Phantom", "Tracker"), TOOL_OK);

  vtkSmartPointer<vtkMatrix4x4> mxStylusTipToStylus = vtkSmartPointer<vtkMatrix4x4>::New();
  mxStylusTipToStylus->Element[2][3] = 4;
  mxStylusTipToStylus->Element[1][1] = 0.2;
  mxStylusTipToStylus->Element[2][0] = -0.2;
  mxStylusTipToStylus->Element[2][1] = 0.4;
  mxStylusTipToStylus->Element[2][2] = -0.2;
  trackedFrame.SetFrameTransform(PlusTransformName("StylusTip", "Stylus"), mxStylusTipToStylus);
  trackedFrame.SetFrameTransformStatus(PlusTransformName("StylusTip", "Stylus"), TOOL_OK);

  if (transformRepository->SetTransforms(trackedFrame) != PLUS_SUCCESS)
  {
    LOG_ERROR("Failed to set transforms from tracked frame!");
    return EXIT_FAILURE;
  }

  transformRepository->PrintSelf(std::cout, vtkIndent());

  /////////////////////////////////////////////////////////////////////////////
  // Test computation of transform to self
  // Compute with transform Repository
  vtkSmartPointer<vtkMatrix4x4> mxProbeToProbe = vtkSmartPointer<vtkMatrix4x4>::New();
  ToolStatus toolStatus(TOOL_INVALID);
  transformRepository->GetTransform(PlusTransformName("Probe", "Probe"), mxProbeToProbe, &toolStatus);
  LOG_INFO("ProbeToProbe (computed by transformRepository):");
  mxProbeToProbe->PrintSelf(std::cout, vtkIndent());
  // Compute manually
  vtkSmartPointer<vtkMatrix4x4> mxProbeToProbeManual = vtkSmartPointer<vtkMatrix4x4>::New();
  LOG_INFO("PropbeToProbe (computed manually):");
  mxProbeToProbeManual->PrintSelf(std::cout, vtkIndent());
  // Compare
  double posDiff = PlusMath::GetPositionDifference(mxProbeToProbe, mxProbeToProbeManual);
  double orientDiff = PlusMath::GetOrientationDifference(mxProbeToProbe, mxProbeToProbeManual);
  LOG_INFO("Position difference: " << posDiff);
  LOG_INFO("Orientation difference: " << orientDiff);
  if (fabs(posDiff) > 0.001 || fabs(orientDiff) > 0.001)
  {
    LOG_ERROR("Mismatch between transforms computed by transformRepository and manually");
    return EXIT_FAILURE;
  }
  if (!toolStatus)
  {
    LOG_ERROR("ProbeToProbe should be valid");
    return EXIT_FAILURE;
  }

  // Test StylusTipToTracker computation
  // Compute with transform Repository
  vtkSmartPointer<vtkMatrix4x4> mxStylusTipToTracker = vtkSmartPointer<vtkMatrix4x4>::New();
  toolStatus = TOOL_INVALID;
  transformRepository->GetTransform(PlusTransformName("StylusTip", "Tracker"), mxStylusTipToTracker, &toolStatus);
  LOG_INFO("StylusTipToTracker (computed by transformRepository):");
  mxStylusTipToTracker->PrintSelf(std::cout, vtkIndent());
  // Compute manually
  vtkSmartPointer<vtkTransform> transformStylusTipToTrackerManual = vtkSmartPointer<vtkTransform>::New();
  transformStylusTipToTrackerManual->Concatenate(mxStylusToTracker);
  transformStylusTipToTrackerManual->Concatenate(mxStylusTipToStylus);
  vtkMatrix4x4* mxStylusTipToTrackerManual = transformStylusTipToTrackerManual->GetMatrix();
  LOG_INFO("StylusTipToTracker (computed manually):");
  mxStylusTipToTrackerManual->PrintSelf(std::cout, vtkIndent());
  // Compare
  posDiff = PlusMath::GetPositionDifference(mxStylusTipToTracker, mxStylusTipToTrackerManual);
  orientDiff = PlusMath::GetOrientationDifference(mxStylusTipToTracker, mxStylusTipToTrackerManual);
  LOG_INFO("Position difference: " << posDiff);
  LOG_INFO("Orientation difference: " << orientDiff);
  if (fabs(posDiff) > 0.001 || fabs(orientDiff) > 0.001)
  {
    LOG_ERROR("Mismatch between transforms computed by transformRepository and manually");
    return EXIT_FAILURE;
  }
  if (toolStatus != TOOL_OK)
  {
    LOG_ERROR("StylusTipToTracker should be valid");
    return EXIT_FAILURE;
  }


  /////////////////////////////////////////////////////////////////////////////
  // Test PhantomToStylusTip computation
  // Compute with transform Repository
  vtkSmartPointer<vtkMatrix4x4> mxPhantomToStylusTip = vtkSmartPointer<vtkMatrix4x4>::New();
  toolStatus = TOOL_INVALID;
  transformRepository->GetTransform(PlusTransformName("Phantom", "StylusTip"), mxPhantomToStylusTip, &toolStatus);
  LOG_INFO("PhantomToStylusTip (computed by transformRepository):");
  mxPhantomToStylusTip->PrintSelf(std::cout, vtkIndent());
  // Compute manually
  vtkSmartPointer<vtkTransform> transformPhantomToStylusTipManual = vtkSmartPointer<vtkTransform>::New();
  vtkSmartPointer<vtkMatrix4x4> mxStylusToStylusTip = vtkSmartPointer<vtkMatrix4x4>::New();
  vtkMatrix4x4::Invert(mxStylusTipToStylus, mxStylusToStylusTip);
  transformPhantomToStylusTipManual->Concatenate(mxStylusToStylusTip);
  vtkSmartPointer<vtkMatrix4x4> mxTrackerToStylus = vtkSmartPointer<vtkMatrix4x4>::New();
  vtkMatrix4x4::Invert(mxStylusToTracker, mxTrackerToStylus);
  transformPhantomToStylusTipManual->Concatenate(mxTrackerToStylus);
  transformPhantomToStylusTipManual->Concatenate(mxPhantomToTracker);
  vtkMatrix4x4* mxPhantomToStylusTipManual = transformPhantomToStylusTipManual->GetMatrix();
  LOG_INFO("PhantomToStylusTip (computed manually):");
  mxPhantomToStylusTipManual->PrintSelf(std::cout, vtkIndent());
  // Compare
  posDiff = PlusMath::GetPositionDifference(mxPhantomToStylusTip, mxPhantomToStylusTipManual);
  orientDiff = PlusMath::GetOrientationDifference(mxPhantomToStylusTip, mxPhantomToStylusTipManual);
  LOG_INFO("Position difference: " << posDiff);
  LOG_INFO("Orientation difference: " << orientDiff);
  if (fabs(posDiff) > 0.001 || fabs(orientDiff) > 0.001)
  {
    LOG_ERROR("Mismatch between transforms computed by transformRepository and manually");
    return EXIT_FAILURE;
  }
  if (toolStatus != TOOL_OK)
  {
    LOG_ERROR("PhantomToStylusTip should be valid");
    return EXIT_FAILURE;
  }

  /////////////////////////////////////////////////////////////////////////////
  // Test PhantomToStylusTip computation after update of an existing transform
  // Update transform
  mxStylusToTracker->Element[0][0] = 0.9;
  transformRepository->SetTransform(PlusTransformName("Stylus", "Tracker"), mxStylusToTracker);
  // Compute with transform Repository
  transformRepository->GetTransform(PlusTransformName("Phantom", "StylusTip"), mxPhantomToStylusTip, &toolStatus);
  LOG_INFO("PhantomToStylusTip (computed by transformRepository):");
  mxPhantomToStylusTip->PrintSelf(std::cout, vtkIndent());
  // Compute manually
  transformPhantomToStylusTipManual->Identity();
  transformPhantomToStylusTipManual->Concatenate(mxStylusToStylusTip);
  vtkMatrix4x4::Invert(mxStylusToTracker, mxTrackerToStylus);
  transformPhantomToStylusTipManual->Concatenate(mxTrackerToStylus);
  transformPhantomToStylusTipManual->Concatenate(mxPhantomToTracker);
  mxPhantomToStylusTipManual = transformPhantomToStylusTipManual->GetMatrix();
  LOG_INFO("PhantomToStylusTip (computed manually):");
  mxPhantomToStylusTipManual->PrintSelf(std::cout, vtkIndent());
  // Compare
  posDiff = PlusMath::GetPositionDifference(mxPhantomToStylusTip, mxPhantomToStylusTipManual);
  orientDiff = PlusMath::GetOrientationDifference(mxPhantomToStylusTip, mxPhantomToStylusTipManual);
  LOG_INFO("Position difference: " << posDiff);
  LOG_INFO("Orientation difference: " << orientDiff);
  if (fabs(posDiff) > 0.001 || fabs(orientDiff) > 0.001)
  {
    LOG_ERROR("Mismatch between transforms computed by transformRepository and manually");
    return EXIT_FAILURE;
  }
  if (toolStatus != TOOL_OK)
  {
    LOG_ERROR("PhantomToStylusTip should be valid");
    return EXIT_FAILURE;
  }

  transformRepository->PrintSelf(std::cout, vtkIndent());

  /////////////////////////////////////////////////////////////////////////////
  // Check if invalid transform flag is correctly propagated
  bool isValid;
  if (transformRepository->GetTransformValid(PlusTransformName("Probe", "Stylus"), isValid) != PLUS_SUCCESS)
  {
    LOG_ERROR("Cannot get ProbeToStylus transform valid status");
    return EXIT_FAILURE;
  }
  if (isValid)
  {
    LOG_ERROR("The ProbeToStylus transform should be invalid");
    return EXIT_FAILURE;
  }

  if (transformRepository->GetTransformValid(PlusTransformName("Stylus", "Probe"), isValid) != PLUS_SUCCESS)
  {
    LOG_ERROR("Cannot get StylusToProbe transform valid status");
    return EXIT_FAILURE;
  }
  if (isValid)
  {
    LOG_ERROR("The StylusToProbe transform should be invalid");
    return EXIT_FAILURE;
  }

  transformRepository->SetTransform(tnProbeToTracker, mxProbeToTracker, TOOL_OK);

  if (transformRepository->GetTransformValid(PlusTransformName("Probe", "Stylus"), isValid) != PLUS_SUCCESS)
  {
    LOG_ERROR("Cannot get ProbeToStylus transform valid status");
    return EXIT_FAILURE;
  }
  if (!isValid)
  {
    LOG_ERROR("The ProbeToStylus transform should be valid");
    return EXIT_FAILURE;
  }

  if (transformRepository->GetTransformValid(PlusTransformName("Stylus", "Probe"), isValid) != PLUS_SUCCESS)
  {
    LOG_ERROR("Cannot get StylusToProbe transform valid status");
    return EXIT_FAILURE;
  }
  if (!isValid)
  {
    LOG_ERROR("The StylusToProbe transform should be valid");
    return EXIT_FAILURE;
  }


  /////////////////////////////////////////////////////////////////////////////
  // Check if non-existing transforms are handled properly
  if (transformRepository->GetTransformValid(PlusTransformName("Probe", "StylusNonExisting"), isValid) == PLUS_SUCCESS)
  {
    LOG_ERROR("A non-existing transform has been reported to be found");
    return EXIT_FAILURE;
  }

  /////////////////////////////////////////////////////////////////////////////
  // Check circle detection
  vtkSmartPointer<vtkMatrix4x4> mxProbeToPhantom = vtkSmartPointer<vtkMatrix4x4>::New();
  if (transformRepository->SetTransform(PlusTransformName("Probe", "Phantom"), mxProbeToPhantom) == PLUS_SUCCESS)
  {
    LOG_ERROR("Circular reference between transforms is not detected");
    return EXIT_FAILURE;
  }

  if (transformRepository->SetTransform(PlusTransformName("Probe", "Probe"), mxProbeToProbe) == PLUS_SUCCESS)
  {
    LOG_ERROR("Circular reference between transforms (transform to self) is not detected");
    return EXIT_FAILURE;
  }


  /////////////////////////////////////////////////////////////////////////////
  // Check write configuration
  vtkSmartPointer<vtkXMLDataElement> xmlData = vtkSmartPointer<vtkXMLDataElement>::New();
  xmlData->SetName("PlusConfiguration");
  xmlData->SetAttribute("version", "1.0");
  if (transformRepository->WriteConfiguration(xmlData) != PLUS_SUCCESS)
  {
    LOG_ERROR("Failed to write persistent transforms to CoordinateDefinitions");
    return EXIT_FAILURE;
  }
  PlusCommon::XML::PrintXML("CoordinateDefinitions.xml", xmlData);

  /////////////////////////////////////////////////////////////////////////////
  // Check read configuration
  std::string inputConfigFileName = "CoordinateDefinitions.xml";
  vtkSmartPointer<vtkXMLDataElement> configRootElement = vtkSmartPointer<vtkXMLDataElement>::New();
  if (PlusXmlUtils::ReadDeviceSetConfigurationFromFile(configRootElement, inputConfigFileName.c_str()) == PLUS_FAIL)
  {
    LOG_ERROR("Unable to read configuration from file " << inputConfigFileName.c_str());
    return EXIT_FAILURE;
  }
  if (transformRepository->ReadConfiguration(configRootElement) != PLUS_SUCCESS)
  {
    LOG_ERROR("Failed to read persistent transforms from CoordinateDefinitions");
    return EXIT_FAILURE;
  }
  double readProbeToTrackerError(0);
  ToolStatus isProbeToTrackerValid(TOOL_INVALID);
  bool isProbeToTrackerPersistent(false);
  vtkSmartPointer<vtkMatrix4x4> mxProbeToTrackerRead = vtkSmartPointer<vtkMatrix4x4>::New();
  transformRepository->GetTransform(tnProbeToTracker, mxProbeToTrackerRead, &isProbeToTrackerValid);
  transformRepository->GetTransformPersistent(tnProbeToTracker, isProbeToTrackerPersistent);
  transformRepository->GetTransformError(tnProbeToTracker, readProbeToTrackerError);

  posDiff = PlusMath::GetPositionDifference(mxProbeToTracker, mxProbeToTrackerRead);
  orientDiff = PlusMath::GetOrientationDifference(mxProbeToTracker, mxProbeToTrackerRead);
  LOG_INFO("Position difference: " << posDiff);
  LOG_INFO("Orientation difference: " << orientDiff);
  if (fabs(posDiff) > 0.001 || fabs(orientDiff) > 0.001)
  {
    LOG_ERROR("Mismatch between transforms read by transformRepository and original");
    return EXIT_FAILURE;
  }
  if (isProbeToTrackerValid != TOOL_OK)
  {
    LOG_ERROR("ProbeToTracker should be valid");
    return EXIT_FAILURE;
  }
  if (!isProbeToTrackerPersistent)
  {
    LOG_ERROR("ProbeToTracker should be persistent");
    return EXIT_FAILURE;
  }
  if (fabs(dProbeToTrackerError - readProbeToTrackerError) > 0.001)
  {
    LOG_ERROR("Mismatch between transforms error value read by transformRepository and original");
    return EXIT_FAILURE;
  }

  /////////////////////////////////////////////////////////////////////////////
  // Check delete
  if (transformRepository->DeleteTransform(PlusTransformName("Tracker", "Probe")) == PLUS_SUCCESS)
  {
    LOG_ERROR("Only the inverse of the transform has been set, delete should not have been allowed");
    return EXIT_FAILURE;
  }
  if (transformRepository->DeleteTransform(PlusTransformName("Probe", "Tracker")) != PLUS_SUCCESS)
  {
    LOG_ERROR("Transform delete failed");
    return EXIT_FAILURE;
  }

  /////////////////////////////////////////////////////////////////////////////
  // Check circle detection - after delete
  if (transformRepository->SetTransform(PlusTransformName("Probe", "Phantom"), mxProbeToPhantom) != PLUS_SUCCESS)
  {
    LOG_ERROR("Set transform should have been succeeded");
    return EXIT_FAILURE;
  }

  /////////////////////////////////////////////////////////////////////////////
  // Check clear
  transformRepository->Clear();
  if (transformRepository->GetTransform(PlusTransformName("StylusTip", "Tracker"), mxStylusTipToTracker, &toolStatus) == PLUS_SUCCESS)
  {
    LOG_ERROR("GetTransform should have failed after clearing the transform repository");
    return EXIT_FAILURE;
  }

  LOG_INFO("Test successfully completed");
  return EXIT_SUCCESS;
}
