/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __vtkPlusVolumeReconstructor_h
#define __vtkPlusVolumeReconstructor_h

#include "PlusConfigure.h"
#include "vtkPlusVolumeReconstructionExport.h"
#include "vtkPlusPasteSliceIntoVolume.h"
#include "vtkImageAlgorithm.h"

class PlusTrackedFrame;
class vtkPlusFanAngleDetectorAlgo;
class vtkPlusFillHolesInVolume;
class vtkPlusTrackedFrameList;
class vtkPlusTransformRepository;

/*!
  \class vtkPlusVolumeReconstructor
  \brief Reconstructs a volume from tracked frames

  This is a convenience class for inserting tracked frames into a volume
  using the vtkPlusPasteSliceIntoVolume algorithm.
  It reads/writes reconstruction parameters and the calibration matrix from
  configuration XML data element and can also compute the size of the output
  volume that can contain all the frames.

  Coordinate systems to be used in this class:
  Image: Coordinate system aligned to the frame. Unit: pixels.
    Origin: the first pixel in the image pixel array as stored in memory. Not cropped
    to US content of the image.
  Tool: Unit: mm. Origin: origin of the sensor/DRB mounted on the tracked tool (probe).
  Tracker: Unit: mm. Origin: origin of the tracker device (usually camera or EM transmitter).
  Reference: Unit: mm. Origin: origin of the sensor/DRB mounted on the reference tool
    (DRB fixed to the imaged object)

  If no reference DRB is used then use Identity ReferenceToTracker transforms, and so
  Reference will be the same as Tracker. So we can still refer to the output system as Reference.

  \sa vtkPlusPasteSliceIntoVolume
  \ingroup PlusLibVolumeReconstruction
*/
class vtkPlusVolumeReconstructionExport vtkPlusVolumeReconstructor : public vtkImageAlgorithm
{
public:

  static vtkPlusVolumeReconstructor* New();
  vtkTypeMacro(vtkPlusVolumeReconstructor, vtkImageAlgorithm);
  virtual void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  vtkGetMacro(SkipInterval, int);
  vtkSetMacro(SkipInterval, int);

  /*! Read configuration data (volume reconstruction options and calibration matrix) */
  virtual PlusStatus ReadConfiguration(vtkXMLDataElement* config);
  /*! Write configuration data (volume reconstruction options and calibration matrix) */
  virtual PlusStatus WriteConfiguration(vtkXMLDataElement* config);

  /*!
    Automatically adjusts the reconstruced volume size to enclose all the
    frames in the supplied vtkPlusTrackedFrameList. It clears the reconstructed volume.
  */
  virtual PlusStatus SetOutputExtentFromFrameList(vtkPlusTrackedFrameList* trackedFrameList, vtkPlusTransformRepository* transformRepository, std::string& errorDescription);

  /*!
    Inserts the tracked frame into the volume. The origin, spacing, and extent of the output volume
    must be set before calling this method (either by calling the SetOutputExtentFromFrameList method
    or setting the OutputSpacing, OutputOrigin, and OutputExtent attributes in the configuration data
    element).
  */
  virtual PlusStatus AddTrackedFrame(PlusTrackedFrame* frame, vtkPlusTransformRepository* transformRepository, bool* insertedIntoVolume = NULL);

  /*!
    Makes the reconstructed volume ready to be retrieved.
    The slices are pasted into the volume immediately, but hole filling is performed only when this method is called.
  */
  virtual PlusStatus UpdateReconstructedVolume();

  /*! Load the reconstructed volume into the volume pointer */
  virtual PlusStatus GetReconstructedVolume(vtkImageData* volume);

  /*! Apply hole filling to the reconstructed image, is called by UpdateReconstructedVolume so an explicit call is not needed */
  virtual PlusStatus GenerateHoleFilledVolume();

  /*! Returns the reconstructed volume gray levels from the provided volume */
  virtual PlusStatus ExtractGrayLevels(vtkImageData* volume);

  /*!
    Returns the accumulation buffer (alpha channel) of the provided volume.
    If a voxel is filled in the reconstructed volume, then the corresponding voxel
    in the alpha channel is non-zero.
  */
  virtual PlusStatus ExtractAccumulation(vtkImageData* volume);

  /*!
    Save reconstructed volume to file
    \param filename Path and filename of the output file
    \accumulation True if accumulation buffer needs to be saved, false if gray levels (default)
    \useCompression True if compression is turned on (default), false otherwise
  */
  PlusStatus SaveReconstructedVolumeToFile(const std::string& filename, bool accumulation = false, bool useCompression = true);
  PlusStatus SaveReconstructedVolumeToMetafile(const std::string& filename, bool accumulation = false, bool useCompression = true) { return SaveReconstructedVolumeToFile(filename, accumulation, useCompression); }

  /*!
    Save reconstructed volume to file
    \param volumeToSave Reconstructed volume to be saved
    \param filename Path and filename of the output file
    \useCompression True if compression is turned on (default), false otherwise
  */
  static PlusStatus SaveReconstructedVolumeToFile(vtkImageData* volumeToSave, const std::string& filename, bool useCompression = true);
  static PlusStatus SaveReconstructedVolumeToMetafile(vtkImageData* volumeToSave, const std::string& filename, bool useCompression = true) { return vtkPlusVolumeReconstructor::SaveReconstructedVolumeToFile(volumeToSave, filename, useCompression); }

  /*! Get/set the Image coordinate system name. It overrides the value read from the config file. */
  vtkGetStdStringMacro(ImageCoordinateFrame);
  vtkSetStdStringMacro(ImageCoordinateFrame);

  /*! Get/set the Reference coordinate system name. It overrides the value read from the config file. */
  vtkGetStdStringMacro(ReferenceCoordinateFrame);
  vtkSetStdStringMacro(ReferenceCoordinateFrame);

  vtkGetMacro(EnableFanAnglesAutoDetect, bool);
  vtkSetMacro(EnableFanAnglesAutoDetect, bool);

  /*!
    Get the clip rectangle origin to apply to the image in pixel coordinates.
  */
  int* GetClipRectangleOrigin();
  void SetClipRectangleOrigin(int* origin);

  /*! Get the clip rectangle size in pixels */
  int* GetClipRectangleSize();
  void SetClipRectangleSize(int* size);

  /*! Clear the reconstructed volume */
  void Reset();

  /*! Set the output volume's origin in the Reference coordinate system*/
  void SetOutputOrigin(double* origin);

  /*! Set the output volume's spacing in the Reference coordinate system's unit (usually mm)*/
  void SetOutputSpacing(double* spacing);

  /*! Set the output volume's extent (xStart, xEnd, yStart, yEnd, zStart, zEnd) in voxels */
  void SetOutputExtent(int* extent);

  /*! Set the number of threads used for volume reconstruction and hole filling */
  void SetNumberOfThreads(int numberOfThreads);

  /*! Set the fan-shaped clipping region for curvilinear probes. */
  void SetFanAnglesDeg(double* fanAngles);
  /*! Set the fan-shaped clipping region for curvilinear probes. */
  void SetFanOriginPixel(double* fanOriginPixel);
  /*! Set the fan-shaped clipping region for curvilinear probes. */
  void SetFanRadiusStartPixel(double fanRadiusPixel);
  /*! Set the fan-shaped clipping region for curvilinear probes. */
  void SetFanRadiusStopPixel(double fanRadiusPixel);

  /*! DEPRECATED: use SetFanAnglesDeg instead. */
  void SetFanAngles(double* fanAnglesDeg);
  /*! DEPRECATED: use SetFanOriginPixel instead. */
  void SetFanOrigin(double* fanOriginPixel);
  /*! DEPRECATED: use SetFanRadiusStopPixel instead. */
  void SetFanDepth(double fanDepthPixel);
  /*! DEPRECATED: use SetCompoundingMode instead. */
  void SetCompounding(int compounding);
  /*! DEPRECATED: use SetCompoundingMode instead. */
  void SetCalculation(vtkPlusPasteSliceIntoVolume::CalculationTypeDeprecated type);

  void SetInterpolation(vtkPlusPasteSliceIntoVolume::InterpolationType interpolation);
  void SetCompoundingMode(vtkPlusPasteSliceIntoVolume::CompoundingType compoundingMode);
  void SetOptimization(vtkPlusPasteSliceIntoVolume::OptimizationType optimization);

  vtkSetMacro(FillHoles, bool);
  vtkGetMacro(FillHoles, bool);

  bool FanClippingApplied();

  double* GetFanOrigin();
  double* GetFanAnglesDeg();
  double* GetDetectedFanAnglesDeg();
  double GetFanRadiusStartPixel();
  double GetFanRadiusStopPixel();

  void UpdateFanAnglesFromImage(vtkImageData* frameImage, bool& isImageEmpty);

  void SetFanAnglesAutoDetectBrightnessThreshold(double threshold);
  void SetFanAnglesAutoDetectFilterRadiusPixel(int radiusPixel);

  /*! Pixels that have lower brightness value than this threshold value will not be inserted into the volume */
  void SetPixelRejectionThreshold(double threshold);
  double GetPixelRejectionThreshold();

  vtkGetStdStringMacro(ImportanceMaskFilename);
  vtkSetStdStringMacro(ImportanceMaskFilename);

  /*!
    Force re-reading of image importance mask from ImportanceMaskFilename.
    Volume reconstructor reads the importance mask automatically once, so calling this method
    is only needed if the file is changed since it is last used by the reconstructor.
  */
  PlusStatus UpdateImportanceMask();

protected:
  vtkPlusVolumeReconstructor();
  virtual ~vtkPlusVolumeReconstructor();

  /*! Helper function for computing the extent of the reconstructed volume that encloses all the frames */
  void AddImageToExtent(vtkImageData* image, vtkMatrix4x4* imageToReference, double* extent_Ref);

  /*! Construct ImageToReference transform name from the image and reference coordinate frame member variables */
  PlusStatus GetImageToReferenceTransformName(PlusTransformName& imageToReferenceTransformName);

protected:
  vtkPlusPasteSliceIntoVolume* Reconstructor;
  vtkPlusFillHolesInVolume* HoleFiller;
  vtkPlusFanAngleDetectorAlgo* FanAngleDetector;

  vtkSmartPointer<vtkImageData> ReconstructedVolume;

  /*! Defines the image coordinate system name: it corresponds to the 2D frame of the image data in the tracked frame */
  std::string ImageCoordinateFrame;

  /*!
    Defines the Reference coordinate system name: the volume will be reconstructed in this coordinate system
    (the volume axes are parallel to the Reference coordinate system axes and the volume origin position is defined in
    the Reference coordinate system)
  */
  std::string ReferenceCoordinateFrame;

  /*! If enabled then the hole filling will be applied on output reconstructed volume */
  bool FillHoles;

  /*! Automatically reduce the fan angle to only sector that has proper acoustic coupling */
  bool EnableFanAnglesAutoDetect;

  /*! only every [SkipInterval] images from the input will be used in the reconstruction (Ie this is the number of frames that are skipped when the index is increased) */
  int SkipInterval;

  /*! Modified time when reconstructing. This is used to determine whether re-reconstruction is necessary */
  vtkMTimeType ReconstructedVolumeUpdatedTime;

  /*!
    If EnableFanAnglesAutoDetect is enabled then actually used fan angles will be computed from each frame (these angles define the maximum range.
    If EnableFanAnglesAutoDetect is disabled then these values will be used as fan angles.
  */
  double FanAnglesDeg[2];

  /*! ImportanceMaskFilename set in the configuration */
  std::string ImportanceMaskFilename;
  /*! ImportanceMaskFilename set in the volume reconstuctor */
  std::string ImportanceMaskFilenameInReconstructor;

private:
  vtkPlusVolumeReconstructor(const vtkPlusVolumeReconstructor&);  // Not implemented.
  void operator=(const vtkPlusVolumeReconstructor&);  // Not implemented.
};

#endif
