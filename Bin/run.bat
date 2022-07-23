@echo off
@set pwd=%cd%
@set exeRelativePath=/simulator/win32/imgui_ed.exe
@set exeArgs=-workdir %pwd%
@set exeFullPath=%pwd%%exeRelativePath% %exeArgs%
start %exeFullPath%