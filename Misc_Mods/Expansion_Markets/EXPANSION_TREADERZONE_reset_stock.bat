@echo off
setlocal enabledelayedexpansion

:: THIS BATCH FILE IS DESIGNED TO TAKE DAYZ EXPANSION MARKET TRADERZONE JSONs AND RESET THEIR INVENTORIES (for your next restart)
:: PLEASE NOTE THAT IS ONLY INTENDED FOR "m_Version 6" files

:: BACK UP TRADERZONE JSON FILES BEFORE YOU USE!!!!

:: TO USE: Simply drag any number of traderzone json files onto this batch file inside of Windows Explorer and it auto resets the files' inventories to null

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
set "tempFile=%temp%\trimmed_json.tmp"

echo Processing: "%inputFile%"

(for /f "usebackq delims=" %%A in ("%inputFile%") do (
    set "line=%%A"

    :: Check if we've reached the Stock line
    echo !line! | findstr /C:"\"Stock\": {" >nul
    if not errorlevel 1 (
        echo  "Stock": {}
        goto :continue
    )

    :: Output the line as-is
    echo !line!
)) > "%tempFile%"

:continue
:: Ensure the final closing bracket is added
echo } >> "%tempFile%"

:: Overwrite the original file
move /Y "%tempFile%" "%inputFile%" >nul
echo Updated: "%inputFile%"

:: Move to the next file
shift
goto :processFile

:done
echo All files updated successfully!
pause
