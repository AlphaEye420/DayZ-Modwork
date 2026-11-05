Make a shortcut in the folder along with the .ps1 file.

Goto properties of the shortcut and edit the target to this: 

(change the folder name)

C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe -NoProfile -ExecutionPolicy Bypass -File "C:\YourFolders\ __Search-Files.ps1"

The shortcut should run the app.

1. Enter a folder to search press enter
2. Enter text to search for press enter - list appears

Up arrow to get to previously typed information.
Press enter with nothing typed in line to exit or close with X button.
