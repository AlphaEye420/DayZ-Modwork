@echo off

:: DayZ TXT to XML converter
:: Drag a .txt file onto this batch file.

echo Working, please wait .. .. ...

:: Check if a file was dragged onto the batch script
if "%~1"=="" (
    echo Drag a .txt file onto this batch script to convert it to XML.
    pause
    exit /b
)

:: Get input file and define output XML file
set "inputFile=%~1"
set "outputFile=%~dpn1.xml"

:: Create XML
powershell -NoProfile -Command ^
    "$names = Get-Content -LiteralPath '%inputFile%' | ForEach-Object { $_.Trim() } | Where-Object { $_ -ne '' }; " ^
    "$tab = [char]9; " ^
    "$writer = [System.IO.StreamWriter]::new('%outputFile%', $false, [System.Text.UTF8Encoding]::new($false)); " ^
    "try { " ^
    "$writer.WriteLine('<?xml version=""1.0"" encoding=""UTF-8"" standalone=""yes""?>'); " ^
    "$writer.WriteLine('<types>'); " ^
    "foreach ($name in $names) { " ^
    "$escaped = [System.Security.SecurityElement]::Escape($name); " ^
    "$writer.WriteLine($tab + '<type name="""' + $escaped + '""">'); " ^
    "$writer.WriteLine($tab + $tab + '<nominal>0</nominal>'); " ^
    "$writer.WriteLine($tab + $tab + '<lifetime>7200</lifetime>'); " ^
    "$writer.WriteLine($tab + $tab + '<restock>0</restock>'); " ^
    "$writer.WriteLine($tab + $tab + '<min>0</min>'); " ^
    "$writer.WriteLine($tab + $tab + '<quantmin>-1</quantmin>'); " ^
    "$writer.WriteLine($tab + $tab + '<quantmax>-1</quantmax>'); " ^
    "$writer.WriteLine($tab + $tab + '<cost>100</cost>'); " ^
    "$writer.WriteLine($tab + $tab + '<flags count_in_cargo=""0"" count_in_hoarder=""0"" count_in_map=""1"" count_in_player=""0"" crafted=""0"" deloot=""0""/>'); " ^
    "$writer.WriteLine($tab + $tab + '<category name="""clothes"""/>'); " ^
    "$writer.WriteLine($tab + '</type>'); " ^
    "}; " ^
    "$writer.WriteLine('</types>'); " ^
    "} finally { $writer.Close() }"

if errorlevel 1 (
    echo ERROR: XML creation failed.
    pause
    exit /b 1
)

echo XML Created: "%outputFile%"
pause