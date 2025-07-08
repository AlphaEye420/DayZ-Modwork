@echo off
setlocal enabledelayedexpansion
echo Working, please wait .. .. ..

:: Check if a file was dragged onto the batch script
if "%~1"=="" (
    echo Drag an XML file onto this batch script to extract names.
    pause
    exit /b
)

:: Get input file and define output text file
set "inputFile=%~1"
set "outputFile=%~dpn1.txt"

:: Ensure output file is empty before writing
echo. > "%outputFile%"

:: Read the XML file line by line and extract type names
for /f "tokens=2 delims=<>" %%A in ('findstr /C:"<type name=" "%inputFile%"') do (
    for /f "tokens=2 delims=="" " %%B in ("%%A") do (
        echo %%B >> "%outputFile%"
    )
)

echo Extracted: "%outputFile%"
pause
