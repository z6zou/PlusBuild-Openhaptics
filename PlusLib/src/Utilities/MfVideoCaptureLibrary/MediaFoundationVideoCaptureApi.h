/*=Plus=header=begin======================================================
Program: Plus
Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
See License.txt for details.

This file is subject to the Code Project Open Source License.
See http://www.codeproject.com/info/cpol10.aspx

Original work by Evgeny Pereguda
http://www.codeproject.com/Members/Evgeny-Pereguda

Original "videoInput" library at
http://www.codeproject.com/Articles/559437/Capturing-video-from-web-camera-on-Windows-7-and-8

The "videoInput" library has been adapted to fit within a namespace.

=========================================================Plus=header=end*/

#ifndef __MediaFoundationVideoCaptureApi_h
#define __MediaFoundationVideoCaptureApi_h

#include "MediaFoundationVideoDevices.h"

#include <guiddef.h>
#include <mfapi.h>
#include <string>
#include <vector>

struct IMFMediaSource;

namespace MfVideoCapture
{
  // Structure for collecting info about types of video, which are supported by current video device
  class MediaType
  {
  public:
    DWORD StreamId;

    unsigned int MF_MT_FRAME_SIZE;
    unsigned int height;
    unsigned int width;
    unsigned int MF_MT_YUV_MATRIX;
    unsigned int MF_MT_VIDEO_LIGHTING;
    unsigned int MF_MT_DEFAULT_STRIDE;
    unsigned int MF_MT_VIDEO_CHROMA_SITING;

    GUID MF_MT_MAJOR_TYPE;
    GUID MF_MT_SUBTYPE;
    GUID MF_MT_AM_FORMAT_TYPE;

    unsigned int MF_MT_FIXED_SIZE_SAMPLES;
    unsigned int MF_MT_VIDEO_NOMINAL_RANGE;
    unsigned int MF_MT_FRAME_RATE;
    unsigned int MF_MT_FRAME_RATE_low;
    unsigned int MF_MT_PIXEL_ASPECT_RATIO;
    unsigned int MF_MT_PIXEL_ASPECT_RATIO_low;
    unsigned int MF_MT_ALL_SAMPLES_INDEPENDENT;
    unsigned int MF_MT_FRAME_RATE_RANGE_MIN;
    unsigned int MF_MT_FRAME_RATE_RANGE_MIN_low;
    unsigned int MF_MT_SAMPLE_SIZE;
    unsigned int MF_MT_VIDEO_PRIMARIES;
    unsigned int MF_MT_INTERLACE_MODE;
    unsigned int MF_MT_FRAME_RATE_RANGE_MAX;
    unsigned int MF_MT_FRAME_RATE_RANGE_MAX_low;

    std::wstring MF_MT_AM_FORMAT_TYPEName;
    std::wstring MF_MT_MAJOR_TYPEName;
    std::wstring MF_MT_SUBTYPEName;

    MediaType();
    ~MediaType();
    void Clear();
  };

  typedef std::vector<MediaType> FormatList;
  typedef std::vector<FormatList> StreamList;
  typedef StreamList::size_type stream_sizet;
  typedef FormatList::size_type format_sizet;

  // Structure for collecting info about one parameter of current video device
  class Parameter
  {
  public:
    long CurrentValue;
    long Min;
    long Max;
    long Step;
    long Default;
    long Flag;

    Parameter();
  };

  // Structure for collecting info about 17 parameters of current video device
  struct CaptureDeviceParameters
  {
    enum VideoProcParameters
    {
      Brightness,
      Contrast,
      Hue,
      Saturation,
      Sharpness,
      Gamma,
      ColorEnable,
      WhiteBalance,
      BacklightCompensation,
      Gain,
      NUMBER_OF_VIDEO_PROC_PARAMETERS
    };
    Parameter VideoProcParameters[NUMBER_OF_VIDEO_PROC_PARAMETERS];

    enum CameraControlParameters
    {
      Pan,
      Tilt,
      Roll,
      Zoom,
      Exposure,
      Iris,
      Focus,
      NUMBER_OF_CAMERA_CONTROL_PARAMETERS
    };
    Parameter CameraControlParameters[NUMBER_OF_CAMERA_CONTROL_PARAMETERS];
  };

  /// The only visible class for controlling of video devices in format singleton
  class MediaFoundationVideoCaptureApi
  {
  public:
    // Getting of static instance of videoInput class
    static MediaFoundationVideoCaptureApi& GetInstance();

    // Closing video device with deviceID
    bool CloseDevice( DeviceList::size_type deviceID );

    // Setting callback function for emergency events(for example: removing video device with deviceID) with userData
    bool SetEmergencyStopEvent( DeviceList::size_type deviceID, void* userData, void( *func )( int, void* ) );

    // Closing all devices
    void CloseAllDevices();

    // Tell a device to start recording
    bool StartRecording( DeviceList::size_type deviceID );

    // Tell a device to stop recording
    bool StopRecording( DeviceList::size_type deviceID );

    // Getting of parametrs of video device with deviceID
    CaptureDeviceParameters GetParameters( DeviceList::size_type deviceID );

    // Setting of parametrs of video device with deviceID
    bool SetParameters( DeviceList::size_type deviceID, CaptureDeviceParameters parametrs );

    // List any existing capture devices
    DeviceList::size_type ListDevices();

    // Get a list of existing capture device names
    void GetDeviceNames( std::vector< std::wstring >& deviceNames );

    // Getting numbers of formats, which are supported by videodevice with deviceID
    MfVideoCapture::format_sizet GetNumberOfFormats( DeviceList::size_type deviceID, unsigned int streamIndex );

    // Get active format for the given device
    unsigned int GetDeviceActiveFormat( DeviceList::size_type deviceID );

    // Getting width of image, which is getting from videodevice with deviceID
    unsigned int GetWidth( DeviceList::size_type deviceID );

    // Getting height of image, which is getting from videodevice with deviceID
    unsigned int GetHeight( DeviceList::size_type deviceID );

    // Getting the current frame rate of the videodevice with deviceID
    unsigned int GetFrameRate( DeviceList::size_type deviceID );

    // Getting name of videodevice with deviceID
    wchar_t* GetCaptureDeviceName( DeviceList::size_type deviceID );

    // Getting interface MediaSource for Media Foundation from videodevice with deviceID
    IMFMediaSource* GetMediaSource( DeviceList::size_type deviceID );

    // Getting format with id, which is supported by videodevice with deviceID
    MediaType GetFormat( DeviceList::size_type deviceID, unsigned int streamIndex, unsigned int formatIndex );

    // Getting number of streams provided by videodevice with deviceID
    MfVideoCapture::stream_sizet GetNumberOfStreams( unsigned int deviceID );

    // Checking of existence of the suitable video devices
    bool AreDevicesAccessible() const;

    // Checking of using the videodevice with deviceID
    bool IsDeviceSetup( DeviceList::size_type deviceID );

    // Checking of using MediaSource from videodevice with deviceID
    bool IsDeviceMediaSource( DeviceList::size_type deviceID );

    // Checking of using Raw Data of pixels from video device with deviceID
    bool IsDeviceRawDataSource( DeviceList::size_type deviceID );

    // Initialization of video device with deviceID by media type with id
    bool SetupDevice( DeviceList::size_type deviceID, unsigned int streamIndex, unsigned int formatIndex = 0 );

    // Initialization of video device with deviceID by width w, height h, fps idealFramerate and subtype
    bool SetupDevice( DeviceList::size_type deviceID, unsigned int streamIndex, unsigned int w, unsigned int h, unsigned int idealFramerate = 30, GUID subtype = MFVideoFormat_YUY2 );

  protected:
    MediaFoundationVideoCaptureApi( void );
    virtual ~MediaFoundationVideoCaptureApi( void );
    void UpdateListOfDevices();

  private:
    bool AccessToDevices;
  };

}

#endif