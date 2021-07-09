@echo off
pushd ..\build
cl -nologo -Zi -FC ..\source\win32_platform.c user32.lib

popd