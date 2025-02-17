@echo off

:: This batch file takes a text file list of type names and creates an XML out of them for types.xml in DayZ
:: Simply drag a txt file onto the batch file in Windows Explorer, and an XML of the same name will be created
:: Copy from the created file to paste into your types file of your choosing

setlocal enabledelayedexpansion

:: Check if a file was dragged onto the batch script
if "%~1"=="" (
    echo Drag a .txt file onto this batch script to convert it to XML.
    pause
    exit /b
)

:: Get input file and define output XML file
set "inputFile=%~1"
set "outputFile=%~dpn1.xml"

:: Start writing the XML structure
:: THIS IS WHERE YOU EDIT YOUR DEFAULT TEMPLATE YOUR TEXT FILE ITEMS WILL ALL HAVE
(
    echo ^<?xml version="1.0" encoding="UTF-8" standalone="yes"?^>
    echo ^<types^>

    for /f "delims=" %%A in (%inputFile%) do (
        echo     ^<type name="%%A"^>
        echo         ^<nominal^>0^</nominal^>
        echo         ^<lifetime^>7200^</lifetime^>
        echo         ^<restock^>0^</restock^>
        echo         ^<min^>0^</min^>
        echo         ^<quantmin^>-1^</quantmin^>
        echo         ^<quantmax^>-1^</quantmax^>
        echo         ^<cost^>100^</cost^>
        echo         ^<flags count_in_cargo="0" count_in_hoarder="0" count_in_map="1" count_in_player="0" crafted="0" deloot="0"/^>
        echo         ^<category name="clothes"/^>
        echo     ^</type^>
    )

    echo ^</types^>
) > "%outputFile%"

echo XML file created: "%outputFile%"
pause
