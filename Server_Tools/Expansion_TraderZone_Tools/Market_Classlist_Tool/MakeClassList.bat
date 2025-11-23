@echo off
setlocal

if "%~1"=="" (
    echo Drag JSON files onto this script.
    pause
    exit /b
)

set "scriptDir=%~dp0"
set "ps1=%scriptDir%MakeClassList.ps1"

if not exist "%ps1%" (
    echo ERROR: %ps1% not found
    pause
    exit /b
)

REM build a list of all dragged files
set "list=%scriptDir%_filelist.txt"
del "%list%" >nul 2>&1

:collect
if "%~1"=="" goto runps1
echo %~1>>"%list%"
shift
goto collect

:runps1
powershell -NoProfile -ExecutionPolicy Bypass -Command ^
 "& { $files = Get-Content '%list%'; & '%ps1%' -files $files }"

del "%list%" >nul 2>&1

echo.
echo ClassList.txt created.
pause
endlocal
