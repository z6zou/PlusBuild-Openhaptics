
if(NOT "C:/Project/PlusB-bin/vtk-prefix/src/vtk-stamp/vtk-gitinfo.txt" IS_NEWER_THAN "C:/Project/PlusB-bin/vtk-prefix/src/vtk-stamp/vtk-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: 'C:/Project/PlusB-bin/vtk-prefix/src/vtk-stamp/vtk-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "C:/Project/PlusB-bin/vtk"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: 'C:/Project/PlusB-bin/vtk'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "C:/Program Files/Git/cmd/git.exe"  clone --no-checkout "https://github.com/kitware/vtk.git" "vtk"
    WORKING_DIRECTORY "C:/Project/PlusB-bin"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/kitware/vtk.git'")
endif()

execute_process(
  COMMAND "C:/Program Files/Git/cmd/git.exe"  checkout v8.2.0 --
  WORKING_DIRECTORY "C:/Project/PlusB-bin/vtk"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'v8.2.0'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "C:/Program Files/Git/cmd/git.exe"  submodule update --recursive --init 
    WORKING_DIRECTORY "C:/Project/PlusB-bin/vtk"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: 'C:/Project/PlusB-bin/vtk'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "C:/Project/PlusB-bin/vtk-prefix/src/vtk-stamp/vtk-gitinfo.txt"
    "C:/Project/PlusB-bin/vtk-prefix/src/vtk-stamp/vtk-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: 'C:/Project/PlusB-bin/vtk-prefix/src/vtk-stamp/vtk-gitclone-lastrun.txt'")
endif()

