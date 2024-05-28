## CUSTOM LOADING SCREEN

### ATTENTION: DAYZ 1.25 HAS BROKEN MAIN MENU MUSIC
PLEASE IGNORE THIS SECTION OF THE SYSTEM UNTIL FURTHER NOTICE
Don't use mainmenumusic.c
#### Features: GAME HINTS + MENU MUSIC + MAIN MENU SCENE + BASIC MENU LAYOUT
! THIS PACKABLE PBO WAS MADE FOR DEERISLE 5.3 / DAYZ 1.23 and only supported as such
~~~
There is no pbo to download.  You add your pics and music to a directory, edit text and pack your own pbo.
Note: your mod name and pbo name may or may not be the same, it is up to you.  Just be sure the pbo name is used in editing.
To use this template follow all of these steps - match exactly correct or it will not work:
~~~

* Download the "Directory Structure.zip" from github and copy the structure into YourPBOName directory
* 1. Open into an editor the 7 files from the checklist below
* 2. Put all of your loading screen edds pictures files and ogg music file in the folder called 'data'
* 3. Put all of your custom icons and logo files in the folder called '/scripts/5_Mission/gui/imagesets' - some standard issue icons provided for you already
* 4. In the first 5 of the 7 checklist files, change the text of "YourPBOName" to the name of the pbo in your mod you are going to upload to Steam !! DO this in 5 files !!
* 5. In the config.cpp, change the text of YourSONGName to your ogg file name in the data folder, and fill in the "" for your steam name and ID. Then, change the name of the map in the last function to match your server's map name & configure character scene
* 6. In the LoadingScreen.c file in 3_Game, change the text of 'Your_PIC_#' to your edds file names in the data folder !! DEFAULT IS 21 PIC CAROSEL, ADJUST TO YOUR NUMBER OF PICS BY ADDING OR DELETING LINES AND ADJUSTING THE RANDOMIZER'S MIN/MAX IN ALL 3 SECTIONS OF THE FILE !!
* 7. In the MainMenu.c be sure to change the IP and connection port, then edit the links below that happen on icon click
* 8. In the main_menu.layout look for //*** to see where you can edit to match your graphics with your sizes, choose font and graphics locations !! It is helpful to match the sizes of your photos to your widget dimensions, though you may experiment with stretching by using different values !!
* 9. In Hints.json in data folder, customize the text of the hints ~ backing images & layout are broken but the text can be customized
* 10. Pack your loading screen pbo, then pack a mod with this pbo included

### SHOULD YOU WANT TO REMOVE A SECTION:
* if you need only one (1) pic, set the variable i to "int i = 0;" and only have a "if (i==0)" line IN EACH OF THE 3 SECTIONS of /scripts/3_Game/loading_screen.c
* To remove music you can delete the 2 soundshaders functions in config.cpp and delete /scripts/5_Mission/MainMenuMusic.c
* To remove the loading screen pictures, remove your /data edds files and delete /scripts/3_Game/loading_screen.c
* To remove the main menu layout, delete /scripts/5_Mission/MainMenu.c and the "/scripts/5_Mission/gui" folder
* To remove the character scene location the delete the last cfg section in config.cpp
* To remove the custom hints delete the hints.json in data folder +and+ within /Scripts/3_Game/ delete HintPage.c, UiHintPanal.c. and delete /Scripts/3_Game/gui folder

## CHECKLIST FOR TYPING CHANGES:
#### root/config.cpp
* There are 12+ places to change information! Look for //*** 
* (must do lines 3 5 22 24 50 59 68 70 77 81)
* character scene editing is optional for Deer Isle only

#### root/scripts/5_Mission/MainMenu.c
* There are 4 places to change information
* "YourPBOName" (line 8)
* Server IP and Port (line 55)
* Web Addresses for lower left icons (lines 76 81)

#### root/scripts/5_Mission/gui/main_menu.layout
* There are 3 places to change "YourPBOName" (lines 350 382 619) 
* The locations of your graphics need to match your filename and path
* change fonts if desired
* EXPANSION USERS: Line 619 path must be copied into the last line of /profiles/expansion/settings/GeneralSettings.json/"InGameMenuLogoPath"

#### root/scripts/5_Mission/MainMenuMusic.c
* There is 1 place to change "YourPBOName"

#### root/scripts/3_Game/UiHintPanel.c
* There are 3 places to change "YourPBOName" (lines 9 10 282)

#### root/scripts/3_Game/LoadingScreens.c
* There are 3 places to change "YOUR_PIC_1"-21, etc or how many pics you plan to have in shuffle
* Make sure the "int i = Math.RandomInt(0,20);" matches the size of the array of pics you use

#### root/data/Hints.json
* Create your custom loading screen hints

#### Expansion Users:
~~~
Not compatible with DayZ Expansion loading screens, so turn it off completely in their settings!
"UseExpansionMainMenuLogo": 0,
"UseExpansionMainMenuIcons": 0,
"UseExpansionMainMenuIntroScene": 0,
"InGameMenuLogoPath": "graphicsFile" <-- match to your /scripts/5_Mission/gui/main_menu.layout line 619
~~~

You can contact me (AlphaEye) via my discord server general-chat channel https://discord.gg/BdkSUQENhM
