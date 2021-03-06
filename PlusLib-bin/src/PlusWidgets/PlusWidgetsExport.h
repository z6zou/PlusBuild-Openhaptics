/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

// This file is automatically generated from PlusExport.h.in by GENERATE_EXPORT_DIRECTIVE_FILE macro.

// .NAME __PlusWidgetsExport - manage Windows system differences
// .SECTION Description
// The __PlusWidgetsExport manages DLL export syntax differences
// between different operating systems.

#ifndef __PlusWidgetsExport_h
#define __PlusWidgetsExport_h

#if defined(WIN32) && !defined(PlusLib_STATIC)
 #if defined(PlusWidgets_EXPORTS)
  #define PlusWidgetsExport __declspec( dllexport )
 #else
  #define PlusWidgetsExport __declspec( dllimport )
 #endif
#else
 #define PlusWidgetsExport
#endif

#endif
