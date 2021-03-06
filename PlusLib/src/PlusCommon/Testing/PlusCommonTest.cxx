/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

// Local includes
#include "PlusConfigure.h"
#include "vtkPlusRecursiveCriticalSection.h"

// VTK includes
#include <vtkSmartPointer.h>
#include <vtksys/CommandLineArguments.hxx>

namespace
{
  static const double DOUBLE_THRESHOLD = 0.0001;

  PlusStatus TestStringFunctions()
  {
    // re #1182
    std::string baseline("Testing PLUS is fun!");
    std::string lowercase("Testing plus is fun!");
    if (!PlusCommon::IsEqualInsensitive(baseline, lowercase))
    {
      return PLUS_FAIL;
    }

    std::wstring w_baseline(L"Testing PLUS is fun!");
    std::wstring w_lowercase(L"Testing plus is fun!");
    if (!PlusCommon::IsEqualInsensitive(w_baseline, w_lowercase))
    {
      return PLUS_FAIL;
    }

    if (!PlusCommon::HasSubstrInsensitive(baseline, "PLUS") || !PlusCommon::HasSubstrInsensitive(baseline, "plus"))
    {
      return PLUS_FAIL;
    }
    if (!PlusCommon::HasSubstrInsensitive(w_baseline, L"PLUS") || !PlusCommon::HasSubstrInsensitive(w_baseline, L"plus"))
    {
      return PLUS_FAIL;
    }

    std::string tokenBaseline("Testing;PLUS;is;fun!;;");
    std::vector<std::string> tokens;
    PlusCommon::SplitStringIntoTokens(tokenBaseline, ';', tokens, false);
    if (tokens.size() != 4)
    {
      return PLUS_FAIL;
    }
    if (!PlusCommon::IsEqualInsensitive(tokens[0], "Testing") ||
        !PlusCommon::IsEqualInsensitive(tokens[1], "PLUS") ||
        !PlusCommon::IsEqualInsensitive(tokens[2], "is") ||
        !PlusCommon::IsEqualInsensitive(tokens[3], "fun!"))
    {
      return PLUS_FAIL;
    }
    tokens.clear();
    PlusCommon::SplitStringIntoTokens(tokenBaseline, ';', tokens, true);
    if (tokens.size() != 5)
    {
      return PLUS_FAIL;
    }
    if (!tokens[4].empty())
    {
      return PLUS_FAIL;
    }

    std::string reconstructed;
    PlusCommon::JoinTokensIntoString(tokens, reconstructed, ';');
    if (!PlusCommon::IsEqualInsensitive(reconstructed, "Testing;PLUS;is;fun!;"))
    {
      return PLUS_FAIL;
    }

    std::string spaces(" Testing PLUS is fun!");
    std::string trimmed(spaces);
    PlusCommon::Trim(trimmed);
    if (PlusCommon::IsEqualInsensitive(spaces, trimmed))
    {
      return PLUS_FAIL;
    }

    spaces = "Testing PLUS is fun!";
    trimmed = spaces;
    PlusCommon::Trim(trimmed);
    if (!PlusCommon::IsEqualInsensitive(spaces, trimmed))
    {
      return PLUS_FAIL;
    }

    return PLUS_SUCCESS;
  }

  PlusStatus TestXMLFunctions()
  {
    std::string theXML = "<PlusConfiguration version=\"2.1\"><DataCollection StartupDelaySec = \"1.0\"><DeviceSet></DeviceSet></DataCollection></PlusConfiguration>";
    vtkSmartPointer<vtkXMLDataElement> rootElement = vtkSmartPointer<vtkXMLDataElement>::Take(vtkXMLUtilities::ReadElementFromString(theXML.c_str()));
    if (rootElement == NULL)
    {
      return PLUS_FAIL;
    }

    bool isEqual(false);
    if (PlusCommon::XML::SafeCheckAttributeValueInsensitive(*rootElement, "version", "2.1", isEqual) != PLUS_SUCCESS || !isEqual)
    {
      return PLUS_FAIL;
    }
    double version(0.0);
    if (PlusCommon::XML::SafeGetAttributeValueInsensitive<double>(*rootElement, "version", version) != PLUS_SUCCESS || version != 2.1)
    {
      return PLUS_FAIL;
    }

    return PLUS_SUCCESS;
  }

  PlusStatus TestValidTransformName(std::string from, std::string to)
  {
    PlusTransformName transformName;
    std::string strName = std::string(from) + std::string("To") + std::string(to);
    if (transformName.SetTransformName(strName.c_str()) != PLUS_SUCCESS)
    {
      LOG_ERROR("Failed to create Plus transform name from " << strName);
      return PLUS_FAIL;
    }

    if (STRCASECMP(transformName.From().c_str(), from.c_str()) != 0)
    {
      LOG_ERROR("Expected From coordinate frame name '" << from << "' differ from matched coordinate frame name '" << transformName.From() << "'.");
      return PLUS_FAIL;
    }

    if (STRCASECMP(transformName.To().c_str(), to.c_str()) != 0)
    {
      LOG_ERROR("Expected To coordinate frame name '" << to << "' differ from matched coordinate frame name '" << transformName.To() << "'.");
      return PLUS_FAIL;
    }

    std::string outTransformName;
    if (transformName.GetTransformName(outTransformName) != PLUS_SUCCESS)
    {
      LOG_ERROR("Failed to get transform name from PlusTransformName!");
      return PLUS_FAIL;
    }

    if (STRCASECMP(strName.c_str(), outTransformName.c_str()) != 0)
    {
      LOG_ERROR("Expected transform name '" << strName << "' differ from generated transform name '" << outTransformName << "'.");
      return PLUS_FAIL;
    }

    LOG_INFO("Input: " << strName << "  <From> coordinate frame: " << transformName.From() << "  <To> coordinate frame: " << transformName.To() << "  Output: " << outTransformName);

    return PLUS_SUCCESS;
  }

  PlusStatus TestInvalidTransformName(std::string from, std::string to)
  {
    PlusTransformName transformName;
    std::string strName = std::string(from) + std::string("To") + std::string(to);
    transformName.SetTransformName(strName.c_str());

    if (!transformName.IsValid())
    {
      LOG_INFO("Invalid transform input found: " << strName);
    }
    else
    {
      LOG_ERROR("Invalid transform name expected!");
      return PLUS_FAIL;
    }

    return PLUS_SUCCESS;
  }
}

int main(int argc, char** argv)
{
  bool printHelp(false);
  int verboseLevel = vtkPlusLogger::LOG_LEVEL_UNDEFINED;

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

  // ***********************************************
  // Test string to number conversion
  // ***********************************************
  double doubleResult(0);
  if (PlusCommon::StringToDouble("8.12", doubleResult) != PLUS_SUCCESS)
  {
    LOG_ERROR("Failed to convert '8.12' string to double");
    return EXIT_FAILURE;
  }
  if (fabs(doubleResult - 8.12) > DOUBLE_THRESHOLD)
  {
    LOG_ERROR("Failed to convert '8.12' string to double - difference is larger then threshold: " << std::fixed << DOUBLE_THRESHOLD);
    return EXIT_FAILURE;
  }

  if (PlusCommon::StringToDouble("", doubleResult) != PLUS_FAIL)
  {
    LOG_ERROR("Error expected on empty string to double conversion!");
    return EXIT_FAILURE;
  }

  int intResult(0);
  if (PlusCommon::StringToInt("8", intResult) != PLUS_SUCCESS)
  {
    LOG_ERROR("Failed to convert '8' string to integer!");
    return EXIT_FAILURE;
  }
  if (intResult != 8)
  {
    LOG_ERROR("Failed to convert '8' string to integer - difference is: " << intResult - 8);
    return EXIT_FAILURE;
  }

  if (PlusCommon::StringToInt("", intResult) != PLUS_FAIL)
  {
    LOG_ERROR("Error expected on empty string to integer conversion!");
    return EXIT_FAILURE;
  }

  // ***********************************************
  // Test PlusTransformName
  // ***********************************************

  PlusTransformName trName("tr1", "tr2");
  if (trName.From().compare("Tr1") != 0)
  {
    LOG_ERROR("Capitalization test failed: " << trName.From() << " != Tr1");
    exit(EXIT_FAILURE);
  }
  if (trName.To().compare("Tr2") != 0)
  {
    LOG_ERROR("Capitalization test failed: " << trName.To() << " != Tr2");
    exit(EXIT_FAILURE);
  }

  if (TestValidTransformName("Image", "Probe") != PLUS_SUCCESS) { exit(EXIT_FAILURE); }
  if (TestValidTransformName("Tool", "Tool") != PLUS_SUCCESS) { exit(EXIT_FAILURE); }
  if (TestValidTransformName("TestTool", "OtherTool") != PLUS_SUCCESS) { exit(EXIT_FAILURE); }


  if (TestInvalidTransformName("To", "To") != PLUS_SUCCESS) { exit(EXIT_FAILURE); }
  if (TestInvalidTransformName("ToTol", "TolTo") != PLUS_SUCCESS) { exit(EXIT_FAILURE); }
  if (TestInvalidTransformName("TolTo", "ToTol") != PLUS_SUCCESS) { exit(EXIT_FAILURE); }
  if (TestInvalidTransformName("to", "to") != PLUS_SUCCESS) { exit(EXIT_FAILURE); }

  LOG_INFO("Test recursive critical section");
  vtkPlusRecursiveCriticalSection* critSec = vtkPlusRecursiveCriticalSection::New();
  LOG_INFO(" Lock");
  critSec->Lock();
  LOG_INFO(" Lock again");
  critSec->Lock();
  LOG_INFO(" Unlock");
  critSec->Unlock();
  LOG_INFO(" Unlock again");
  critSec->Unlock();
  LOG_INFO(" Delete");
  critSec->Delete();
  LOG_INFO(" Done");

  if (TestStringFunctions() != PLUS_SUCCESS) { exit(EXIT_FAILURE); }

  if (TestXMLFunctions() != PLUS_SUCCESS) { exit(EXIT_FAILURE); }

  LOG_INFO("Test finished successfully!");
  return EXIT_SUCCESS;
}

