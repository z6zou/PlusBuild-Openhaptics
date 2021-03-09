@ECHO off

SET ORIGPATH=%PATH%

SET BUILD_TYPE=Release

REM Parse arguments
SET COMMAND=%0
SET TEST_MODE=%1
SHIFT

:loop
IF NOT "%1"=="" (
    IF "%1"=="--test" (
        SET INDIVIDUAL_TEST=%2
        SHIFT
    )
    IF "%1"=="--track" (
        SET TEST_TRACK=--track %2
        SHIFT
    )
    SHIFT
    GOTO :loop
)

REM Skip build step if continuous or individual mode
REM Skip clean build step if not nightly mode
if "%TEST_MODE%" == "-C" goto cleansuccess
if "%TEST_MODE%" == "-I" goto cleansuccess
if "%TEST_MODE%" == "" goto cleansuccess
if "%TEST_MODE%" == "-E" goto cleansuccess

ECHO Clean...
"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/MSBuild/Current/Bin/MSBuild.exe" ALL_BUILD.vcxproj /p:Configuration=Release /target:clean
IF ERRORLEVEL 1 GOTO buildfail

:cleansuccess

rem ---------------------------------------
if "%TEST_MODE%" == "" goto experimental
if "%TEST_MODE%" == "-E" goto experimental
if "%TEST_MODE%" == "-N" goto nightly
if "%TEST_MODE%" == "-C" goto continuous
if "%TEST_MODE%" == "-I" goto individual

:experimental
"C:/Program Files/CMake/bin/ctest.exe" -C %BUILD_TYPE% -D Experimental --output-on-failure %TEST_TRACK%
goto success

:nightly
@REM Clean before the nightly build to enforce all build warnings appear on all nightly dashboard submissions
"C:/Program Files/CMake/bin/ctest.exe" -C %BUILD_TYPE% -D Nightly %TEST_TRACK%
goto success

:continuous
"C:/Program Files/CMake/bin/ctest.exe" -C %BUILD_TYPE% -D Continuous %TEST_TRACK%
@REM Wait for some time before continue to allow checking the results of the executions
timeout /t 15
goto success

:individual 
@REM Run individual tests with regexp search 
@REM Display the list of tests
"C:/Program Files/CMake/bin/ctest.exe" -C %BUILD_TYPE% -R "%INDIVIDUAL_TEST" -N
@REM Run selected tests
"C:/Program Files/CMake/bin/ctest.exe" -C %BUILD_TYPE% -R "%INDIVIDUAL_TEST" -V
goto success

:success
SET PATH=%ORIGPATH%
exit /b 0

:buildfail
ECHO Failed to build PlusLib
SET PATH=%ORIGPATH%
exit /b 1
