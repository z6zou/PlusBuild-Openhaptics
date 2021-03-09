# Install script for directory: C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Project/PlusB-bin/itk-int")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xcppheadersx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ITK-4.12/itkhdf5" TYPE FILE FILES
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5AbstractDs.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Alltypes.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5ArrayType.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5AtomType.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Attribute.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Classes.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5CommonFG.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5CompType.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Cpp.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5CppDoc.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5DataSet.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5DataSpace.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5DataType.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5DcreatProp.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5DxferProp.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5EnumType.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Exception.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5FaccProp.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5FcreatProp.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5File.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5FloatType.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Group.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5IdComponent.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Include.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5IntType.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Library.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Location.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5Object.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5OcreatProp.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5PredType.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5PropList.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5StrType.h"
    "C:/Project/PlusB-bin/itk/Modules/ThirdParty/HDF5/src/itkhdf5/c++/src/H5VarLenType.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xcpplibrariesx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/Debug/libitkhdf5_cpp_DD.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/Release/libitkhdf5_cpp.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/MinSizeRel/libitkhdf5_cpp.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "C:/Project/PlusB-bin/lib/RelWithDebInfo/libitkhdf5_cpp.lib")
  endif()
endif()

