@echo off
echo lib_json build begin
rem 创建文件夹

call "%VS100COMNTOOLS%\vsvars32.bat"

echo build clean debug vs2010
@devenv lib_json.vcxproj /ReBuild "Debug" /Out ..\..\..\..\10-common\version\CompileInfo\lib_json_d_2010.txt

echo build clean release vs2010
@devenv lib_json.vcxproj /ReBuild "Release" /Out ..\..\..\..\10-common\version\CompileInfo\lib_json_r_2010.txt

rem 还原现场
call "%VS60COMNTOOLS%\vcvars32.bat"

copy /Y Debug\lib_json.lib ..\..\..\..\10-common\lib\debug\win32_2010\lib_json.lib

copy /Y Release\lib_json.lib ..\..\..\..\10-common\lib\release\win32_2010\lib_json.lib

echo lib_json build end