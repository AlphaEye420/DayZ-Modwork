## CHECKLIST FOR TYPING CHANGES:
#### root/config.cpp
* There are 12+ places to change information! Look for //*** 
* (must do lines 3 5 22 24 50 59 68 70 77 81)
* character scene editing is optional for Deer Isle only

#### root/scripts/5_Mission/MainMenu.c
* There are 4 places to change information
* "YourModName" (line 8)
* Server IP and Port (line 55)
* Web Addresses for lower left icons (lines 76 81)

#### root/scripts/5_Mission/gui/main_menu.layout
* There are 3 places to change "YourModName" (lines 350 382 619) 
* The locations of your graphics need to match your filename and path
* EXPANSION USERS: Line 619 path must match the last line of GeneralSettings.json (profiles/expansion/settings)
* change fonts if desired

#### root/scripts/5_Mission/MainMenuMusic.c
* There is 1 place to change "YourModName"

#### root/scripts/3_Game/UiHintPanel.c
* There are 3 places to change "YourModName" (lines 9 10 282)

#### root/scripts/3_Game/LoadingScreens.c
* There are 3 places to change "YOUR_PIC_1"-21, etc or how many pics you plan to have in shuffle
* Make sure the "int i = Math.RandomInt(0,20);" matches the size of the array of pics you use

#### root/data/Hints.json
* Create your custom loading screen hints
