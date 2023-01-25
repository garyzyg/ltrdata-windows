SET SED=C:\msys64\usr\bin\sed.exe

PUSHD .
FOR %%I IN (C:\WinDDK\7600.16385.1) DO CALL %%I\bin\setenv.bat %%I fre %Platform% WIN7 no_oacr
POPD

SET CPU=i386
IF %_BUILDARCH%==AMD64 SET CPU=%_BUILDARCH%
SET Lib=%Lib%\Crt\%CPU%;%DDK_LIB_DEST%\%CPU%;%Lib%

SET Include=%Include%;%CRT_INC_PATH%

SET Path=%CD%;C:\Program Files\Microsoft SDKs\Windows\v7.1\Bin;%Path%

CD winstrct
%BUILD_MAKE_PROGRAM%
MOVE /Y *.lib ..\win32\lib

CD ..\win32\exe
SET Include=..\include;%Include%
SET Lib=..\lib;%Lib%
FOR %%I IN (
"/Zi	 "
"/Ox	/O1 /GL /DNDEBUG /GS-"
"/debug	 "
) DO FOR /F "TOKENS=1,* DELIMS=	" %%J IN (%%I) DO %SED% "s@%%J@%%K@" -i Makefile

FOR /F "DELIMS=" %%I IN ('TYPE ..\..\filelist.txt') DO %BUILD_MAKE_PROGRAM% %%I CPU=%CPU%

MOVE *.exe ..\..

CD ..\..
