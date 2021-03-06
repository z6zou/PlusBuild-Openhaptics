/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __vtkPlusPhidgetSpatialTracker_h
#define __vtkPlusPhidgetSpatialTracker_h

#include "vtkPlusDataCollectionExport.h"

#include "vtkPlusDevice.h"

class AhrsAlgo;

/*!
\class vtkPlusPhidgetSpatialTracker 
\brief Interface for the Phidget 3/3/3 tracker 

This class talks with PhidgetSpatial 3/3/3 accelerometer/magnetometer/gyroscope device.

Tracker coordinate system: South-West-Down.

Sensor coordinate system is drawn on the sensor PCB. If the PCB is laying flat on the table
with cable socket towards East then the axis directions are: South-West-Down.

Tools:
  Accelerometer, Gyroscope, Magnetometer: Raw sensor measurements.
    The values are stored in the translation part of the transformation matrix.
    The rotation part is identity.
  TiltSensor: 2-DOF sensor tilt is computed as a rotation matrix. Only the accelerometer is used.
  FilteredTiltSensor: Modifies OrientationSensor output, with one axis constrained to always point west.  Used to constrain rotational error
  around the Z axis.
  OrientationSensor: 3-DOF sensor orientation is computed using sensor fusion.
    With ...IMU algorithm only the accelerometer and gyroscope data are used.
    With ...AHRS algorithm accelerometer, gyroscope, and magnetometer data are used.

Gyroscope zeroing is performed automatically at device connect, therefore the sensor shall not be moved
for 2 seconds after the vtkPlusPhidgetSpatialTracker::Connect() call if the OrientationSensor or Accelerometer tool is used.

AHRS algorithm gain values:
 The Madgwick method uses only one parameter (beta). A value of 1.0 works well at 125Hz.
 The Mahony method uses two parameters (proportional and integral). A value of proportional=15.0, integral=1.0 work well at 125Hz.

If magnetic fields nearby the sensor have non-negligible effect then compass can be ignored by choosing an ..._IMU AHRS algorithm
(as opposed to ..._MARG) or compass correction may be performed (see http://www.phidgets.com/docs/Compass_Primer). If compass correction
parameters cannot be stored in the device flash then they should be set in vtkPlusPhidgetSpatialTracker::Connect().

The magnetometer has an internal calibration mechanism, which is running continuously. During this internal calibration no measurement
data can be retrieved from the magnetometer. When magnetometer data is not available then the associated tool status is set to INVALID.

\ingroup PlusLibDataCollection
*/

// Number of parameters required by CPhidgetSpatial_setCompassCorrectionParameters
#define PHIDGET_NUMBER_OF_COMPASS_CORRECTION_PARAMETERS 13

class vtkPlusDataCollectionExport vtkPlusPhidgetSpatialTracker : public vtkPlusDevice
{
public:

  static vtkPlusPhidgetSpatialTracker *New();
  vtkTypeMacro( vtkPlusPhidgetSpatialTracker,vtkPlusDevice );
  void PrintSelf( ostream& os, vtkIndent indent );

  virtual bool IsTracker() const { return true; }

  /*! Connect to device */
  PlusStatus InternalConnect();

  /*! Disconnect from device */
  virtual PlusStatus InternalDisconnect();

  /*! 
  Probe to see if the tracking system is present on the specified serial port.  
  */
  PlusStatus Probe();

  /*! Read configuration from xml data */
  virtual PlusStatus ReadConfiguration(vtkXMLDataElement* config); 

  /*! Write configuration to xml data */
  virtual PlusStatus WriteConfiguration(vtkXMLDataElement* config);

  /*
  * Override the default resettable behavior of the device
  * because Phidget trackers can be reset
  */
  virtual bool IsResettable();

  /*!
    Reset the device
  */
  virtual PlusStatus Reset();

  vtkSetMacro(ZeroGyroscopeOnConnect, bool);

  /*!
    Serial number of the hardware device that will be connected
  */
  vtkSetMacro(SerialNumber, int);
  vtkGetMacro(SerialNumber, int);

  friend class PhidgetSpatialCallbackClass;

protected:

  vtkPlusPhidgetSpatialTracker();
  ~vtkPlusPhidgetSpatialTracker();

  /*! 
  Start the tracking system.  The tracking system is brought from its ground state into full tracking mode.
  The device will only be reset if communication cannot be established without a reset.
  */
  PlusStatus InternalStartRecording();

  /*! Stop the tracking system and bring it back to its ground state: Initialized, not tracking, at 9600 Baud. */
  PlusStatus InternalStopRecording();

  /*! 
    Determine the gyroscope sensors offset by integrating the gyroscope values for 2 seconds while the sensor is stationary.
    The offset may slightly change as the temperature of the sensor changes.
  */  
  void ZeroGyroscope();

  vtkSetVector2Macro(AhrsAlgorithmGain, double);
  vtkSetVector2Macro(FilteredTiltSensorAhrsAlgorithmGain, double);
  
  vtkSetVectorMacro(CompassCorrectionParameters, double, PHIDGET_NUMBER_OF_COMPASS_CORRECTION_PARAMETERS);

  /*! Returns true if compass correction parameters are defined (any of the parameters is non-zero) */
  bool IsCompassCorrectionParametersDefined();

private:  // Functions.

  vtkPlusPhidgetSpatialTracker( const vtkPlusPhidgetSpatialTracker& );
  void operator=( const vtkPlusPhidgetSpatialTracker& ); 

  //void Get3x3RotMatrixFromIMUQuat(double rotMatrix[3][3], AhrsAlgo* AhrsAlgo);

private:  // Variables.  

  void* SpatialDeviceHandle;

  // Device-specific identifier that can be used to choose a particular device when multiple devices are connected
  // If the default value (-1) is kept then it connects to the first available device.
  int SerialNumber;

  unsigned int FrameNumber;
  double TrackerTimeToSystemTimeSec; // time_System = time_Tracker + TrackerTimeToSystemTimeSec
  bool TrackerTimeToSystemTimeComputed; // the time offset is always computed when the first frame is received after start tracking  

  vtkMatrix4x4* LastAccelerometerToTrackerTransform;
  vtkMatrix4x4* LastGyroscopeToTrackerTransform;
  vtkMatrix4x4* LastMagnetometerToTrackerTransform;
  vtkMatrix4x4* LastTiltSensorToTrackerTransform;
  vtkMatrix4x4* LastFilteredTiltSensorToTrackerTransform;
  vtkMatrix4x4* LastOrientationSensorToTrackerTransform;

  vtkPlusDataSource* AccelerometerTool;
  vtkPlusDataSource* GyroscopeTool;
  vtkPlusDataSource* MagnetometerTool;
  vtkPlusDataSource* TiltSensorTool;
  vtkPlusDataSource* FilteredTiltSensorTool;
  vtkPlusDataSource* OrientationSensorTool;

  enum AHRS_METHOD
  {
    AHRS_MADGWICK,
    AHRS_MAHONY
  };

  AhrsAlgo* FilteredTiltSensorAhrsAlgo;

  AhrsAlgo* AhrsAlgo;

  /*!
    If AhrsUseMagnetometer enabled (a ..._MARG algorithm is chosen) then heading will be estimated using magnetometer data.
    Otherwise (when a ..._IMU algorithm is chosen) only the gyroscope data will be used for getting the heading information.
    IMU may be more noisy, but not sensitive to magnetic field distortions.
  */
  bool AhrsUseMagnetometer;

  /*!
    Gain values used by the AHRS algorithm (Mahony: first parameter is proportional, second is integral gain; Madgwick: only the first parameter is used)
    Higher gain gives higher reliability to accelerometer&magnetometer data.
  */
  double AhrsAlgorithmGain[2];
  double FilteredTiltSensorAhrsAlgorithmGain[2];

  /*! last AHRS update time (in system time) */
  double AhrsLastUpdateTime;
  double FilteredTiltSensorAhrsLastUpdateTime;

  /*!
    In tilt sensor mode we don't use the magnetometer, so we have to provide a direction reference.
    The orientation is specified by specifying an axis that will always point to the "West" direction.
    Recommended values:
    If sensor axis 0 points down (the sensor plane is about vertical) => TiltSensorDownAxisIndex = 2.
    If sensor axis 1 points down (the sensor plane is about vertical) => TiltSensorDownAxisIndex = 0.
    If sensor axis 2 points down (the sensor plane is about horizontal) => TiltSensorDownAxisIndex = 1.
  */
  int TiltSensorWestAxisIndex;
  int FilteredTiltSensorWestAxisIndex;

  /*! Zero the gyroscope when connecting to the device */
  bool ZeroGyroscopeOnConnect;

  /*! Compass calibration parameters as defined in PhidgetSpatial API (see also http://www.phidgets.com/docs/Compass_Primer). */
  double CompassCorrectionParameters[PHIDGET_NUMBER_OF_COMPASS_CORRECTION_PARAMETERS];
};

#endif
