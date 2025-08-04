@echo off
setlocal

:: Ensure a file was dragged
if "%~1"=="" (
    echo ❌ No file provided.
    pause
    exit /b
)

:: Run the PowerShell script with full path to dragged file
powershell -NoLogo -NoProfile -ExecutionPolicy Bypass -File "%~dp0generate_object_count.ps1" "%~1"

:: Keep window open
echo.
echo Done.
pause
