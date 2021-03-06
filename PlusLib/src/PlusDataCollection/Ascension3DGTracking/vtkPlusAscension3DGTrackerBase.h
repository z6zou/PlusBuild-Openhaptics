/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#include "vtkPlusDataCollectionExport.h"

#include "vtkPlusDevice.h"

/*!
\class vtkPlusAscension3DGTrackerBase
\brief Interface for the Ascension 3DG magnetic tracker

This class talks with Ascension3DG tracker over the ATC trakSTAR device driver

\ingroup PlusLibDataCollection
*/
class vtkPlusDataCollectionExport vtkPlusAscension3DGTrackerBase : public vtkPlusDevice
{
public:

  static vtkPlusAscension3DGTrackerBase* New();
  vtkTypeMacro(vtkPlusAscension3DGTrackerBase, vtkPlusDevice);
  void PrintSelf(ostream& os, vtkIndent indent);

  virtual bool IsTracker() const { return true; }

  /*! Connect to device */
  PlusStatus InternalConnect();

  /*! Disconnect from device */
  virtual PlusStatus InternalDisconnect();

  /*! Read main configuration from xml data */
  virtual PlusStatus ReadConfiguration(vtkXMLDataElement* config);

  /*! Write main configuration to xml data */
  virtual PlusStatus WriteConfiguration(vtkXMLDataElement* config);

  /*!
  Probe to see if the tracking system is present on the specified serial port.
  If the SerialPort is set to -1, then all serial ports will be checked.
  */
  PlusStatus Probe();

  /*!
  Get an update from the tracking system and push the new transforms
  to the tools.  This should only be used within vtkTracker.cxx.
  This method is called by the tracker thread.
  */
  PlusStatus InternalUpdate();

  vtkGetMacro(NumberOfSensors, int);

  vtkGetMacro(FilterAcWideNotch, int);
  vtkGetMacro(FilterAcNarrowNotch, int);
  vtkGetMacro(FilterDcAdaptive, double);
  vtkGetMacro(FilterLargeChange, int);
  vtkGetMacro(FilterAlpha, bool);
  vtkGetMacro(Hemisphere, int);

  /*! Returns "" if type value is unknown. */
  static std::string GetHemisphereTypeAsString(int type);
  /*! Returns -1 if type string is unknown. */
  static int GetHemisphereTypeFromString(const char* typeStr);

protected:
  vtkSetMacro(FilterAcWideNotch, int);
  vtkSetMacro(FilterAcNarrowNotch, int);
  vtkSetMacro(FilterDcAdaptive, double);
  vtkSetMacro(FilterLargeChange, int);
  vtkSetMacro(FilterAlpha, bool);
  vtkSetMacro(Hemisphere, int);

protected:
  vtkPlusAscension3DGTrackerBase();
  ~vtkPlusAscension3DGTrackerBase();

  /*!
  Start the tracking system.  The tracking system is brought from its ground state into full tracking mode.
  The device will only be reset if communication cannot be established without a reset.
  */
  PlusStatus InternalStartRecording();

  /*! Stop the tracking system and bring it back to its ground state: Initialized, not tracking, at 9600 Baud. */
  PlusStatus InternalStopRecording();

private:  // Definitions.
  enum {TRANSMITTER_OFF = -1};

private:  // Functions.
  vtkPlusAscension3DGTrackerBase(const vtkPlusAscension3DGTrackerBase&);
  void operator=(const vtkPlusAscension3DGTrackerBase&);

  /*! Check return status and log in case of error */
  PlusStatus CheckReturnStatus(int status);

  /*!
    Adds 3 quality values (in the translation component of the transformation matrix) to the buffer.
    For sensors sensorStartIndex, sensorStartIndex+1, and sensorStartIndex+2.
  */
  PlusStatus QualityToolTimeStampedUpdate(const char* qualityToolPortName, unsigned int sensorStartIndex, const std::vector<unsigned short>& qualityValues, double unfilteredTimestamp);

  /*! Returns true if the port name belongs to a virtual tool that stores quality values */
  bool IsQualityPortName(const char* name);
  bool IsQualityPortName(const std::string& name);


private:  // Variables.
  std::vector< bool > SensorSaturated;
  std::vector< bool > SensorAttached;
  std::vector< bool > SensorInMotion;

  void* AscensionRecordBuffer;

  bool TransmitterAttached;

  unsigned int FrameNumber;
  int NumberOfSensors;

  /*! Measurement area (what side of the transmitter the sensors are located).  */
  int Hemisphere;

  /*! AC wide notch filter status: enabled (1) or disabled (0) */
  int FilterAcWideNotch;

  /*! AC narrow notch filter status: enabled (1) or disabled (0) */
  int FilterAcNarrowNotch;

  /*! DC adaptive filter parameter (0.0 for no filtering, 1.0 for maximum filtering) */
  double FilterDcAdaptive;

  /*! Large change filter status: enabled (1) or disabled (0) */
  int FilterLargeChange;

  /*! Alpha filter status: enabled (true) or disabled (false) */
  bool FilterAlpha;
};
