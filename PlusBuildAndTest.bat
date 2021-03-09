@ECHO off
REM Update and run all tests
REM Arguments: [mode]
REM mode:
REM  -E experimental (default)
REM  -N nightly
REM  -C continuous

@REM Run PlusBuild tests 
cd /d "C:/Project/PlusB-bin"
call BuildAndTest.bat %1

@REM Run PlusLib tests 
cd /d "C:\Project\PlusB-bin\PlusLib-bin"
call BuildAndTest.bat %1

@REM Run PlusApp tests 
cd /d "C:\Project\PlusB-bin\PlusApp-bin"
call BuildAndTest.bat %1

cd /d "C:\Project\PlusB-bin"
