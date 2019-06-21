echo off
echo SipTool.exe build begin


if not exist "debug" (
	mkdir "debug"
)
if not exist "release" (
	mkdir "release"
)


if exist "..\..\..\10-common\version\debug\win32\SipTool" (
rmdir /s/q "..\..\..\10-common\version\debug\win32\SipTool"
)
if not exist "..\..\..\10-common\version\debug\win32\SipTool" (
	mkdir "..\..\..\10-common\version\debug\win32\SipTool"
)

if exist "..\..\..\10-common\version\release\win32\SipTool" (
rmdir /s/q "..\..\..\10-common\version\release\win32\SipTool"
)
if not exist "..\..\..\10-common\version\release\win32\SipTool" (
	mkdir "..\..\..\10-common\version\release\win32\SipTool"
)



call "%VS100COMNTOOLS%\vsvars32.bat"
echo build clean debug vs2010
@devenv SipTool.vcxproj /ReBuild "Debug" /Out ..\..\..\10-common\version\CompileInfo\SipTool_d.txt

echo build clean release vs2010
@devenv SipTool.vcxproj /ReBuild "Release" /Out ..\..\..\10-common\version\CompileInfo\SipTool_r.txt

rem 还原现场
call "%VS60COMNTOOLS%\vcvars32.bat"



copy /Y Debug\SipTool.exe ..\..\..\10-common\version\debug\win32\SipTool\SipTool.exe
copy /Y Release\SipTool.exe ..\..\..\10-common\version\release\win32\SipTool\SipTool.exe

rem pdb调试文件
copy /Y Release\SipTool.pdb ..\..\..\10-common\version\release\win32\SipTool\SipTool.pdb

if not exist "..\..\..\10-common\version\release\win32\SipTool\skin" (
	mkdir "..\..\..\10-common\version\release\win32\SipTool\skin"
)

copy /Y system.xml ..\..\..\10-common\version\debug\win32\SipTool\system.xml
copy /Y system.xml  ..\..\..\10-common\version\release\win32\SipTool\system.xml 

xcopy  skin\*.* ..\..\..\10-common\version\release\win32\SipTool\skin /y /k /s 
copy /Y Release\SipTool.map ..\..\..\10-common\version\release\win32\SipTool\SipTool.map

echo build SipTool.exe over
echo on
