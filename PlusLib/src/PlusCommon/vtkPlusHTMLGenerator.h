/*=Plus=header=begin======================================================
  Program: Plus
  Copyright (c) Laboratory for Percutaneous Surgery. All rights reserved.
  See License.txt for details.
=========================================================Plus=header=end*/

#ifndef __vtkPlusHTMLGenerator_H
#define __vtkPlusHTMLGenerator_H

#include "vtkPlusCommonExport.h"

#include "vtkObject.h"

class vtkTable;

/*!
  \class vtkPlusHTMLGenerator
  \brief class for generating basic html tags
  \ingroup PlusLibCommon
*/
class vtkPlusCommonExport vtkPlusHTMLGenerator : public vtkObject
{
public:

  /*! HTML headings  */
  enum HEADINGS
  {
    H1,
    H2,
    H3,
    H4,
    H5,
    H6
  };

  static vtkPlusHTMLGenerator* New();
  vtkTypeMacro(vtkPlusHTMLGenerator, vtkObject);
  virtual void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  /*! Write the report to html file. Create file in the output directory, including the application start time in the filename. */
  virtual std::string SaveHtmlPageAutoFilename();

  /*!
    Add image to document.
    \param filenamePostfix Should contain only a simple filename and extension (for example: ErrorHistogram.png).
    \return Full path to the image file
  */
  virtual std::string AddImageAutoFilename(const char* filenamePostfix, const char* description, const int widthPx = 0, const int heightPx = 0);

  /*! Add paragraph to document */
  virtual void AddParagraph(const char* paragraph);

  /*! Add text to document */
  virtual void AddText(const char* text, HEADINGS h, const char* style = NULL);

  /*! Add table to document */
  virtual void AddTable(vtkTable* table, int borderPx);

  /*! Add a link to the document*/
  virtual void AddLink(const char* linkText, const char* url);

  /*! Add horizontal line separator to the document */
  virtual void AddHorizontalLine();

  /*! Set the page title */
  vtkSetStringMacro(Title);
  /*! Get the page title */
  vtkGetStringMacro(Title);

  /*! Set the output directory */
  vtkSetStringMacro(OutputDirectory);
  /*! Get the output directory */
  vtkGetStringMacro(OutputDirectory);

  /*!
    Set the base filename.
    The base filename is used for generating output file names (html, images, etc).
    Set it before adding any images, because image file names are generated using this base filename.
  */
  vtkSetStringMacro(BaseFilename);
  /*! Get the base filename. The base filename is used for generating output file names (html, images, etc). */
  vtkGetStringMacro(BaseFilename);

protected:

  /*! Write the report to html file. Deprecated - use SaveHtmlPageAutoFilename instead. */
  virtual void SaveHtmlPage(const char* fileName);

  /*! Add image to document */
  virtual void AddImage(const char* imageSource, const char* alt, const int widthPx = 0, const int heightPx = 0);

  /*! Get the body */
  virtual std::string GetHtmlBody();

  /*! Get the html page source */
  virtual std::string GetHtmlPage();

  vtkPlusHTMLGenerator();
  virtual ~vtkPlusHTMLGenerator();

  char* Title;
  char* OutputDirectory;
  char* BaseFilename;

  std::ostringstream HtmlBody;

private:
  vtkPlusHTMLGenerator(const vtkPlusHTMLGenerator&);  // Not implemented.
  void operator=(const vtkPlusHTMLGenerator&);  // Not implemented.
};

#endif
