/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

// This file is automatically generated from PlusExport.h.in by GENERATE_EXPORT_DIRECTIVE_FILE macro.

// .NAME __vtkPlusRenderingExport - manage Windows system differences
// .SECTION Description
// The __vtkPlusRenderingExport manages DLL export syntax differences
// between different operating systems.

#ifndef __vtkPlusRenderingExport_h
#define __vtkPlusRenderingExport_h

#if defined(WIN32) && !defined(PlusLib_STATIC)
 #if defined(vtkPlusRendering_EXPORTS)
  #define vtkPlusRenderingExport __declspec( dllexport )
 #else
  #define vtkPlusRenderingExport __declspec( dllimport )
 #endif
#else
 #define vtkPlusRenderingExport
#endif

#endif
