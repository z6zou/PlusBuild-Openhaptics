/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

// This file is automatically generated from PlusExport.h.in by GENERATE_EXPORT_DIRECTIVE_FILE macro.

// .NAME __vtkPlusUsSimulatorExport - manage Windows system differences
// .SECTION Description
// The __vtkPlusUsSimulatorExport manages DLL export syntax differences
// between different operating systems.

#ifndef __vtkPlusUsSimulatorExport_h
#define __vtkPlusUsSimulatorExport_h

#if defined(WIN32) && !defined(PlusLib_STATIC)
 #if defined(vtkPlusUsSimulator_EXPORTS)
  #define vtkPlusUsSimulatorExport __declspec( dllexport )
 #else
  #define vtkPlusUsSimulatorExport __declspec( dllimport )
 #endif
#else
 #define vtkPlusUsSimulatorExport
#endif

#endif