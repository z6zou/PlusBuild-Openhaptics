@ECHO off 
ECHO Build UserManual...

ECHO   Clear old files to force rebuild of documentation
"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/MSBuild/Current/Bin/MSBuild.exe" Documentation/Documentation-PlusApp-UserManual.vcxproj /p:Configuration=Release /target:clean 1> CreateUserManual.log 2>&1 
IF ERRORLEVEL 1 GOTO fail

ECHO   Generating documentation
"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/MSBuild/Current/Bin/MSBuild.exe" Documentation/Documentation-PlusApp-UserManual.vcxproj /p:Configuration=Release /target:rebuild 1>> CreateUserManual.log 2>&1
IF ERRORLEVEL 1 GOTO fail

rem ---------------------------------------

:success
ECHO Documentation available at: C:/Project/PlusB-bin/bin/Doc
exit /b 0

:fail
ECHO Failed to generate documentation
exit /b 1
