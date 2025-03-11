## DayZ Expansion Traderzones Restock App
### To Install:
* Unzip the folder into a working directory NOT ON THE SERVER
* Follow the readme.md provided in the unzipped folder

### 📂 Folder Structure
```
Restock_Market\
├── Restock_Market.exe & its needed accompanying files
├── README.md (instructions for safe use)
├── NPP_Log_Language_Coloring.xml (import to Notepad++ Languages section for best look for the /USER/Restock.log)
├── Traderzones\
│   └── (Your trader JSON files here)
├── USER\
│   ├── thresholds.json
│   ├── chances.json
│   ├── settings.json
│   ├── Restock.log (app will create on first use by itself)
│   └── Debug.log (app will create on first use by itself)
└── Backup_timestamp\
    └── (Your backup trader JSON files made when in Inventory Reset Mode)
```
### Source Code:
_The provided Open_Source/DayZ_Exp_Traderzones_Restock_App.cs will return exactly what is in the zip folder so long as you have setup the /Traderzones & /USER folders' files correctly.  Create a C# Console app project in Visual Studio, and use this provide .cs as your program.cs, and with folder structure, you have a mod-able version of this app._ :-)