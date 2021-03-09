@ECHO off
REM Hide all your directories from users

SET ORIGPATH=%PATH%

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

SET DIRCMD=0 

if "%TEST_MODE%" == "" goto experimental
if "%TEST_MODE%" == "-E" goto experimental
if "%TEST_MODE%" == "-N" goto nightly
if "%TEST_MODE%" == "-C" goto continuous
if "%TEST_MODE%" == "-I" goto individual

:experimental
"C:/Program Files/CMake/bin/ctest.exe" -D Experimental --output-on-failure --build-and-test %TEST_TRACK%
goto END

:nightly
"C:/Program Files/CMake/bin/ctest.exe" -D Nightly --build-and-test %TEST_TRACK%
goto END

:continuous
"C:/Program Files/CMake/bin/ctest.exe" -D Continuous --build-and-test %TEST_TRACK%
@REM Wait for some time before continue to allow checking the results of the executions
timeout /t 15
goto END

:individual 
@REM Run individual tests with regexp search 
@REM Display the list of tests
"C:/Program Files/CMake/bin/ctest.exe" -R "%INDIVIDUAL_TEST%" -N
@REM Run selected tests
"C:/Program Files/CMake/bin/ctest.exe" -R "%INDIVIDUAL_TEST%" -V
goto END

:BUILDFAILED
ECHO ERROR: Build failed...
GOTO END 

:END
SET PATH=%ORIGPATH%
ECHO DONE
