/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

// This file stores values determined during CMake configuration and
// includes commonly needed header files.
// This file has to be the first include in Plus cxx files.

#ifndef __PlusConfigure_h
#define __PlusConfigure_h

#ifdef _WIN32_WINNT
#undef _WIN32_WINNT
#endif
#define _WIN32_WINNT 0x0602

// disable warnings for sprintf
#define _CRT_SECURE_NO_WARNINGS
// disable warnings for std::copy
#define _SCL_SECURE_NO_WARNINGS

#if defined(_WIN32) && !defined(VTKSLICER_STATIC)
#pragma warning ( disable : 4275 )
#endif

#if defined(_MSC_VER)
#pragma warning ( disable : 4786 )
#endif

#define PLUS_USE_OpenIGTLink

#define BUILD_SHARED_LIBS

#ifndef BUILD_SHARED_LIBS
#define VTKSLICER_STATIC
#define PlusLib_STATIC
#endif

#include <vtkType.h>

#ifndef VTK_HAS_MTIME_TYPE
typedef unsigned long int vtkMTimeType;
#endif

#define PLUSLIB_VERSION "2.8.0"
#define PLUSLIB_VERSION_MAJOR 2
#define PLUSLIB_VERSION_MINOR 8
#define PLUSLIB_VERSION_PATCH 0
#define DATA_PATH ""

// OpenIGTLink does not define version in header file
// therefore we need to add the version information in Plus
#define OPENIGTLINK_VERSION_MAJOR 3
#define OPENIGTLINK_VERSION_MINOR 1
#define OPENIGTLINK_VERSION_PATCH 0
#define OPENIGTLINK_VERSION "3.1.0"

#include "vtkVersionMacros.h"

/* #undef PLUS_USE_3dConnexion_TRACKER */
/* #undef PLUS_USE_aruco */
/* #undef PLUS_USE_Ascension3DG */
/* #undef PLUS_USE_Ascension3DGm */
/* #undef PLUS_USE_BKPROFOCUS_CAMERALINK */
/* #undef PLUS_USE_BKPROFOCUS_VIDEO */
/* #undef PLUS_TEST_BKPROFOCUS */
/* #undef PLUS_USE_BRACHY_TRACKER */
/* #undef PLUS_USE_NDI_CERTUS */
/* #undef PLUS_USE_EPIPHAN */
/* #undef PLUS_USE_ICCAPTURING_VIDEO */
/* #undef PLUS_USE_INTELREALSENSE */
/* #undef PLUS_USE_OPTICAL_MARKER_TRACKER */
/* #undef PLUS_USE_ATRACSYS */
/* #undef PLUS_USE_CAPISTRANO_VIDEO */
/* #undef PLUS_USE_WINPROBE_VIDEO */
/* #undef PLUS_USE_INTERSON_VIDEO */
/* #undef PLUS_USE_INTERSONSDKCXX_VIDEO */
/* #undef PLUS_USE_INTERSONARRAYSDKCXX_VIDEO */
/* #undef PLUS_USE_MICRONTRACKER */
/* #undef PLUS_USE_MMF_VIDEO */
/* #undef PLUS_USE_TELEMED_VIDEO */
/* #undef PLUS_USE_OPTITRACK */
/* #undef PLUS_USE_OPTIMET_CONOPROBE */
/* #undef PLUS_USE_THORLABS_VIDEO */
/* #undef PLUS_USE_PHIDGET_SPATIAL_TRACKER */
/* #undef PLUS_USE_NDI */
/* #undef PLUS_USE_ULTRASONIX_VIDEO */
/* #undef PLUS_USE_VFW_VIDEO */
/* #undef PLUS_USE_STEALTHLINK */
/* #undef PLUS_USE_IntuitiveDaVinci */
/* #undef PLUS_USE_PHILIPS_3D_ULTRASOUND */
/* #undef PLUS_USE_TextRecognizer */
/* #undef PLUS_TEST_TextRecognizer */
/* #undef PLUS_USE_OpenCV */
/* #undef PLUS_USE_USDIGITALENCODERS_TRACKER */
/* #undef PLUS_USE_NVIDIA_DVP */
/* #undef PLUS_USE_OvrvisionPro */
/* #undef PLUS_USE_AGILENT */
/* #undef PLUS_USE_OpenCV_VIDEO */
#define PLUS_USE_OPENHAPTICS
/* #undef PLUS_USE_V4L2 */
/* #undef PLUS_USE_VTKVIDEOIO_MKV */
/* #undef PLUS_USE_INFRARED_SEEK_CAM */
/* #undef PLUS_USE_INFRARED_TEQ1_CAM */
/* #undef PLUS_USE_INTELREALSENSE_CAM */
/* #undef PLUS_USE_WITMOTIONTRACKER */

/* #undef PLUS_USE_SIMPLE_TIMER */
#define PLUS_TEST_HIGH_ACCURACY_TIMING

/* #undef PLUS_USE_INTEL_MKL */

#define PLUS_ULTRASONIX_SDK_MAJOR_VERSION 
#define PLUS_ULTRASONIX_SDK_MINOR_VERSION 
#define PLUS_ULTRASONIX_SDK_PATCH_VERSION 

#define MOTIVE_VERSION_MAJOR 
#define MOTIVE_VERSION_MINOR 
#define MOTIVE_VERSION_PATCH 

#undef DO_CALIBRATION_FILE_CALCULATIONS

//High tolerance defined for to use in calibration tests in order to pass under linux (see #590)
#define LINUXTOLERANCE 0.5
#define LINUXTOLERANCEPERCENT 8

#define HAVE_FUTURE

// Frequently needed STL includes
#include <sstream>
#include <iostream>

// Frequently needed VTK includes
#include "vtkSmartPointer.h"
#include "vtkObjectFactory.h"

// Frequently needed Plus includes
#include "vtkPlusAccurateTimer.h"
#include "PlusCommon.h"
#include "vtkPlusLogger.h"
#include "vtkPlusConfig.h"

#endif // __PlusConfigure_h
