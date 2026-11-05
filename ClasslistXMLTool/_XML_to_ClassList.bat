@echo off
echo Working, please wait .. .. ...

:: Check if a file was dragged onto the batch script
if "%~1"=="" (
    echo Drag an XML file onto this batch script to extract names.
    pause
    exit /b
)

:: Get input file and define output text file
set "inputFile=%~1"
set "outputFile=%~dpn1.txt"

:: Extract names without quotes, spaces, or blank lines
powershell -NoProfile -Command ^
    "[xml]$xml = Get-Content -LiteralPath '%inputFile%' -Raw; $xml.SelectNodes('//type[@name]') | ForEach-Object { $_.GetAttribute('name') } | Set-Content -LiteralPath '%outputFile%' -Encoding UTF8"

echo Extracted: "%outputFile%"
pause