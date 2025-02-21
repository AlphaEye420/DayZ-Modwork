@echo off
setlocal enabledelayedexpansion

:: THIS BATCH FILE IS DESIGNED TO TAKE DAYZ EXPANSION MARKET TRADERZONE JSONs AND ALPABETIZE THEIR INVENTORIES
:: PLEASE NOTE THAT IS ONLY INTENDED FOR "m_Version 6" files	

:: BACK UP TRADERZONE JSON FILES BEFORE YOU USE!!!!

:: YOU MUST HAVE 'sort_stock.ps1' IN THE SAME DIRECTORY AS THIS BATCH FILE !!!!
:: TO USE: Simply drag any number of traderzone json files onto this batch file inside of Windows Explorer and it AUTO SORTS the files' inventories to alphabetical order

:: Ensure at least one file was dragged
if "%~1"=="" (
    echo Drag and drop one or more JSON files onto this script.
    pause
    exit /b
)

:: Process each file
:processFile
if "%~1"=="" goto :done

set "inputFile=%~1"
echo Processing: "%inputFile%"

:: Call PowerShell to sort the "Stock" section
powershell -NoProfile -ExecutionPolicy Bypass -File "%~dp0sort_stock.ps1" "%inputFile%"

echo Updated: "%inputFile%"

:: Move to the next file
shift
goto :processFile

:done
echo All files updated successfully!
pause
