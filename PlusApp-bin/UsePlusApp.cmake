#
# This module is provided as PLUSAPP_USE_FILE 
# It can be INCLUDEd in a project to load the needed compiler and linker
# settings to use Plus library.
#

IF(NOT PLUSAPP_USE_FILE_INCLUDED)
  SET(PLUSAPP_USE_FILE_INCLUDED 1)

  ## Set PlusApp binary dir path 
  SET(PlusApp_BINARY_DIR "C:/Project/PlusB-bin/PlusApp-bin" )
  SET(PlusApp_SOURCE_DIR "C:/Project/PlusB-bin/PlusApp" )
    
  # Add include directories needed to use PlusApp library 
  INCLUDE_DIRECTORIES(C:/Project/PlusB-bin/PlusApp;C:/Project/PlusB-bin/PlusApp-bin)

  # Add link directories needed to use Plus library
  LINK_DIRECTORIES()

  SET(PLUSAPP_BUILD_SHARED_LIBS ON)

  ## Find SVN 
  SET (SVN_FOUND )
  IF (SVN_FOUND)
      SET( Subversion_SVN_EXECUTABLE "" CACHE INTERNAL "")
  ENDIF()
ENDIF()
