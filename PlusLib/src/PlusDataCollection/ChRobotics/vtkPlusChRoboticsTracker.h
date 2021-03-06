/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __vtkPlusChRoboticsTracker_h
#define __vtkPlusChRoboticsTracker_h

#include "vtkPlusDataCollectionExport.h"

#include "ChrDataItem.h"
#include "vtkPlusDevice.h"

class SerialLine;
class ChrSerialPacket;

/*!
\class vtkPlusChRoboticsTracker 
\brief Interface for the CH Robotics CHR-UM6 tracker 

This class talks with CH Robotics CHR-UM6 accelerometer/magnetometer/gyroscope device

\ingroup PlusLibDataCollection
*/
class vtkPlusDataCollectionExport vtkPlusChRoboticsTracker : public vtkPlusDevice
{
public:

  static vtkPlusChRoboticsTracker *New();
  vtkTypeMacro( vtkPlusChRoboticsTracker,vtkPlusDevice );
  void PrintSelf( ostream& os, vtkIndent indent );

  /*! Connect to device */
  PlusStatus InternalConnect();

  /*! Disconnect from device */
  virtual PlusStatus InternalDisconnect();

  /*! 
  Probe to see if the tracking system is present on the specified serial port.  
  */
  PlusStatus Probe();

  /*!
  Get an update from the tracking system and push the new transforms
  to the tools.  This should only be used within vtkTracker.cxx.
  This method is called by the tracker thread.
  */
  PlusStatus InternalUpdate();

  /*! Read configuration from xml data */
  virtual PlusStatus ReadConfiguration(vtkXMLDataElement* config); 

  /*! Write configuration to xml data */
  virtual PlusStatus WriteConfiguration(vtkXMLDataElement* config);  

  virtual bool IsTracker() const { return true; }

  vtkSetMacro(SerialPort, unsigned long);
  vtkSetMacro(BaudRate, unsigned long);
  vtkSetMacro(FirmwareDirectory, std::string);

protected:

  vtkPlusChRoboticsTracker();
  ~vtkPlusChRoboticsTracker();

  /*! 
  Start the tracking system.  The tracking system is brought from its ground state into full tracking mode.
  The device will only be reset if communication cannot be established without a reset.
  */
  PlusStatus InternalStartRecording();

  /*! Stop the tracking system and bring it back to its ground state: Initialized, not tracking, at 9600 Baud. */
  PlusStatus InternalStopRecording();

  /*! 
    Find the firmware definition with the specified id among the firmware definition the XML files.
    If the definition is found then fill the foundDefinition object with the description.
  */
  PlusStatus FindFirmwareDefinition(const std::string& id, vtkXMLDataElement* foundDefinition);

  /*! Utility function for finding all the firmware descriptor files */
  void GetFileNamesFromDirectory(std::vector<std::string> &fileNames, const std::string &dir);

  /*! Query the firmware version of the connected device and load its definition from XML file */
  PlusStatus LoadFirmwareDescriptionForConnectedDevice();

  /*! Read all the needed data item descriptors from the firmware description */
  PlusStatus UpdateDataItemDescriptors();

  /*! Read all the needed data item values from a packet received from the device */
  void UpdateDataItemValues(ChrSerialPacket& packet);

  /*! Find the description of a data item in the firmware description */
  PlusStatus FindDataItemDescriptor(const std::string itemName, ChrDataItem &foundItem);

  /*! Send a packet and wait for and receive a reply packet */
  PlusStatus SendCommand( ChrSerialPacket& requestPacket, ChrSerialPacket& replyPacket );
  
  PlusStatus SendPacket( ChrSerialPacket& packet );
  PlusStatus ReceivePacket( ChrSerialPacket& packet );

  PlusStatus ProcessPacket( ChrSerialPacket& packet );

private:  // Functions.

  vtkPlusChRoboticsTracker( const vtkPlusChRoboticsTracker& );
  void operator=( const vtkPlusChRoboticsTracker& );  


private:  // Variables.

  /*! Serial (RS232) line connection */
  SerialLine* Serial;

  /*! Used COM port number for serial communication (ComPort: 1 => Port name: "COM1")*/
  unsigned long SerialPort; 

  /*! Baud rate for serial communication. */
  unsigned long BaudRate; 

  /*! 
    Directory path containing the XML files that describes the device firmware (available registers, calibration, etc.).
    The path can be relative to the configuration directory.
  */
  std::string FirmwareDirectory;

  vtkPlusDataSource* OrientationSensorTool;

  vtkXMLDataElement* FirmwareDefinition;
  std::string FirmwareVersionId;

  /*! Data item received from the ChRobotics device. Euler angle component (deg). */
  ChrDataItem EulerRoll;
  /*! Data item received from the ChRobotics device. Euler angle component (deg). */
  ChrDataItem EulerPitch;
  /*! Data item received from the ChRobotics device. Euler angle component (deg). */
  ChrDataItem EulerYaw;

};

#endif
