@ECHO off 
REM Hide all your directories from users

REM Return code is 0 on success and >0 if something failed
SET RETURN_CODE=0

REM First we need to build a Release version 

"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/MSBuild/Current/Bin/MSBuild.exe" ALL_BUILD.vcxproj /p:Configuration=Release /target:build
IF ERRORLEVEL 1 GOTO BUILDFAILED

:BUILDDOCUMENTATION
REM Build documentation
IF OFF==OFF GOTO PACKAGE
call CreateUserManual.bat
IF ERRORLEVEL 1 GOTO BUILDFAILED
ECHO User manual generation DONE

:PACKAGE
REM Build the package 
"C:/Program Files/CMake/bin/cpack.exe" --config ./CPackConfig.cmake
IF ERRORLEVEL 1  GOTO PACKAGINGFAILED
ECHO Packaging DONE

:SUCCESS
ECHO Package generation is successfully completed.
exit /b 0

:BUILDFAILED
ECHO ERROR: Build failed...
timeout /t 30
exit /b 1

:PACKAGINGFAILED
ECHO ERROR: Package generation failed...
timeout /t 30
exit /b 2
