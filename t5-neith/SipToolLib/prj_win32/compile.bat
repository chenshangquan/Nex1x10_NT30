@echo off
echo SipToolLib build begin
rem 创建文件夹

call "%VS100COMNTOOLS%\vsvars32.bat"

echo build clean debug vs2010
@devenv SipToolLib.vcxproj /ReBuild "Debug" /Out ..\..\..\10-common\version\CompileInfo\SipToolLib_d_2010.txt

echo build clean release vs2010
@devenv SipToolLib.vcxproj /ReBuild "Release" /Out ..\..\..\10-common\version\CompileInfo\SipToolLib_r_2010.txt

rem 还原现场
call "%VS60COMNTOOLS%\vcvars32.bat"

echo SipToolLib build end