## CHECKLIST FOR TYPING CHANGES:
#### root/config.cpp
* There are many places to change information! Look for `yourPBOname` or `//***` to find places you may need to edit before packing!

#### root/Scripts/5_Mission/MainMenu.c - needed for your main menu to work
* There are 4 places to change information
* "YourPBOName" _(line 8)_
* Server IP and Port _(line 55)_
* Web Addresses for lower left icons _(lines 76, 81)_

#### root/Scripts/5_Mission/gui/main_menu.layout - needed for customized menu layouts
* There are 3 places to change "YourPBOName" _(lines 350, 382, 619)_
* The locations of your graphics need to match your filename and path
* change fonts if desired
* EXPANSION USERS: Line 619 path must be copied into the last line of /profiles/expansion/settings/GeneralSettings.json/"InGameMenuLogoPath"

#### root/Scripts/5_Mission/MainMenuMusic.c - needed for menu music
* There is 1 place to change "YourPBOName"

#### root/Scripts/3_Game/DynamicMusicPlayerRegistryDeerisle.c - needed for menu music - optional for ambient tracks
* There are MANY places to change "YourPBOName" _(most importantly lines 16, 27)_
* Anything you want as a sound triggered needs to match the soundset from your config.cpp _(or BI's original soundset for the situation)_
* Should you comment-out all the registries of a city, no music will ever play there
* You can delete lines 51 -to- 432 _(to have NO deer isle location based ambient tracks used)_ 
* You can delete lines 439 -to- 440 _(to have NO music for contaminated areas)_

#### root/Scripts/3_Game/LoadingScreens.c - needed for random loading screen
* There are 3 places to change "YOUR_PIC_1"-21, etc or how many pics you plan to have in shuffle
* Make sure the "int i = Math.RandomInt(0,20);" matches the size of the array of pics you use

#### root/Scripts/3_Game/UiHintPanel.c - needed for your hints overriding
* There is 3 place to change "YourPBOName"  _(lines 9, 10, 282)_

#### root/Scripts/5_Mission/gui/in_game_hints.layout and in_game_hints_load.layout - needed for customized hints layouts

#### root/Data/Hints.json - completely overrides BI's hints
* Create your custom loading screen hints
* Must add the orignal hints back into your new creation if you want BI's hints still
