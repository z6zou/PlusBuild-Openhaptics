@ECHO off 
ECHO Build PlusLib ApiReference...

ECHO   Clear old files to force rebuild of documentation
"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/MSBuild/Current/Bin/MSBuild.exe" src/Documentation/ApiReference/Documentation-PlusLib-ApiReference.vcxproj /p:Configuration=Release /target:clean 1> CreateDoc.log 2>&1 
IF ERRORLEVEL 1 GOTO fail

ECHO   Generating documentation
"C:/Program Files (x86)/Microsoft Visual Studio/2019/Community/MSBuild/Current/Bin/MSBuild.exe" src/Documentation/ApiReference/Documentation-PlusLib-ApiReference.vcxproj /p:Configuration=Release /target:rebuild 1>> CreateDoc.log 2>&1
IF ERRORLEVEL 1 GOTO fail

rem ---------------------------------------

:success
ECHO Documentation available at: /Doc
goto end

:fail
ECHO Failed to generate documentation
goto end

:end
