/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __vtkPlusRequestIdsCommand_h
#define __vtkPlusRequestIdsCommand_h

#include "vtkPlusServerExport.h"

#include "vtkPlusCommand.h"

/*!
  \class vtkPlusRequestDeviceIDsCommand
  \brief This command returns the list of devices to the client
  \ingroup PlusLibPlusServer
 */
class vtkPlusServerExport vtkPlusRequestIdsCommand : public vtkPlusCommand
{
public:

  static vtkPlusRequestIdsCommand* New();
  vtkTypeMacro(vtkPlusRequestIdsCommand, vtkPlusCommand);
  virtual void PrintSelf(ostream& os, vtkIndent indent);
  virtual vtkPlusCommand* Clone() { return New(); }

  /*! Executes the command  */
  virtual PlusStatus Execute();

  /*! Get all the command names that this class can execute */
  virtual void GetCommandNames(std::list<std::string>& cmdNames);

  /*! Gets the description for the specified command name. */
  virtual std::string GetDescription(const std::string& commandName);

  void SetNameToRequestChannelIds();
  void SetNameToRequestDeviceIds();
  void SetNameToRequestInputDeviceIds();
  void SetNameToRequestDeviceChannelIds();

  /*! Read command parameters from XML */
  virtual PlusStatus ReadConfiguration(vtkXMLDataElement* aConfig);

  /*! Write command parameters to XML */
  virtual PlusStatus WriteConfiguration(vtkXMLDataElement* aConfig);

  /*! Restrict the returned device IDs to this type */
  vtkGetStdStringMacro(DeviceType);
  vtkSetStdStringMacro(DeviceType);

  vtkGetStdStringMacro(DeviceId);
  vtkSetStdStringMacro(DeviceId);

protected:

  vtkPlusRequestIdsCommand();
  virtual ~vtkPlusRequestIdsCommand();

  std::string DeviceType;
  std::string DeviceId;

private:

  vtkPlusRequestIdsCommand(const vtkPlusRequestIdsCommand&);
  void operator=(const vtkPlusRequestIdsCommand&);

};


#endif

