/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

// This file is automatically generated from PlusExport.h.in by GENERATE_EXPORT_DIRECTIVE_FILE macro.

// .NAME __vtkPlusVolumeReconstructionExport - manage Windows system differences
// .SECTION Description
// The __vtkPlusVolumeReconstructionExport manages DLL export syntax differences
// between different operating systems.

#ifndef __vtkPlusVolumeReconstructionExport_h
#define __vtkPlusVolumeReconstructionExport_h

#if defined(WIN32) && !defined(PlusLib_STATIC)
 #if defined(vtkPlusVolumeReconstruction_EXPORTS)
  #define vtkPlusVolumeReconstructionExport __declspec( dllexport )
 #else
  #define vtkPlusVolumeReconstructionExport __declspec( dllimport )
 #endif
#else
 #define vtkPlusVolumeReconstructionExport
#endif

#endif
