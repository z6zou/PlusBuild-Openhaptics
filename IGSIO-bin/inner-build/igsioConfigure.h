/*=IGSIO=header=begin======================================================
  Program: IGSIO
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================IGSIO=header=end*/

// This file stores values determined during CMake configuration and
// includes commonly needed header files.
// This file has to be the first include in IGSIO cxx files.

#ifndef __IGSIOConfigure_h
#define __IGSIOConfigure_h

#define IGSIO_VERSION "1.0.0"
#define IGSIO_VERSION_MAJOR 1
#define IGSIO_VERSION_MINOR 0
#define IGSIO_VERSION_PATCH 0

#define IGSIO_BUILD_SEQUENCEIO
/* #undef IGSIO_SEQUENCEIO_ENABLE_MKV */
/* #undef IGSIO_USE_VP9 */
/* #undef IGSIO_USE_GPU */

#include "vtkVersionMacros.h"

#endif // __IGSIOConfigure_h
