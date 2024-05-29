## CUSTOM LOADING SCREEN for Deer Isle

### LOADING SCREEN & HINTS + MAINMENU CHAR SCENE & LAYOUT + MENU MUSIC & AMBIENT TRACKS
! THIS PACKABLE PBO WAS MADE FOR DEERISLE 5.3 / DAYZ 1.25 and only supported as such !
#### ATTENTION: DAYZ 1.25 MUSIC** 
* Note that there are new files you need to have in order to have music work in a modded map
* Also, make sure you capitalize the Data and Scripts folder

~~~
There is no pbo to download.  You add your pics and music to a directory, edit text and pack your own pbo.
Your mod name and pbo name may or may not be the same, it is up to you.  Just be sure the pbo name is used in editing.

Note: You should set your DayZ Tools Addon Builder Options (top text field) to ensure a good pack: 
*.emat;*.edds;*.ptc;*.c;*.imageset;*.layout;*.ogg;*.png;*.paa;*.rvmat;*.wrp;*.json
~~~
#### To use this template follow all of these steps - match exactly correct or it will not work:

Download the directory structure [from this link](https://download-directory.github.io/?url=https%3A%2F%2Fgithub.com%2FAlphaEye420%2FDayZ-Modwork%2Ftree%2Fmain%2FLoading_Screen_Vanilla) and make a copy of the structure into YourPBOName directory
* 1. Open into an editor ALL of the files you created _(files other than your ogg and edds)_
* 2. Put all of your loading screen edds pictures files and ogg music files in the folder called 'data'
* 3. Put all of your custom icons and logo files in the folder called '/scripts/5_Mission/gui/imagesets' - some standard issue icons provided for you already
* 4. In all of your open files in editor, change the text of "YourPBOName" to the name of the pbo in your mod you are going to upload to Steam _!! DO a search for YourPBOName in all files NP++ can do it in 1 click !!_
* 5. In the config.cpp, change YourSONGName(s) to match your ogg filename(s) in the data folder, and fill in the "" for your steam name and ID. Then, change the name of the map in the last function to match your server's map name & configure character scene
* 6. In the LoadingScreen.c file in 3_Game, change the text of 'Your_PIC_#' to your edds file names in the data folder _!! DEFAULT IS 21 PIC CAROUSEL, ADJUST TO YOUR NUMBER OF PICS BY ADDING OR DELETING LINES AND ADJUSTING THE RANDOMIZER'S MIN/MAX IN ALL 3 SECTIONS OF THE FILE !!_
* 7. In the MainMenu.c be sure to change the IP and connection port, then edit the links below that happen on icon click
* 8. In the main_menu.layout look for //*** to see where you can edit to match your graphics with your sizes, choose font and graphics locations !! It is helpful to match the sizes of your photos to your widget dimensions, though you may experiment with stretching by using different values !!
* 9. In Hints.json in data folder, customize the text of the hints ~ backing images & layout are broken but the text can be customized
* 10. In DynamicMusicPlayerRegistryDeerisle.c edit your menu music name, and then the military and city coordinates for ambient tracks; comment out with 2 slashes anything you don't need to register _(this is setup for DEER ISLE ONLY!)_
* 11. Pack your loading screen pbo, then pack a mod with this pbo included

### SHOULD YOU WANT TO REMOVE A SECTION:
* if you need only one (1) pic, set the variable i to "int i = 0;" & only have a "if (i==0)" line IN EACH OF THE 3 SECTIONS of /scripts/3_Game/loading_screen.c
* To remove ALL music: delete the soundshaders & soundset functions in config.cpp & delete /scripts/5_Mission/MainMenuMusic.c & /scripts/3_game/DynamicMusicPlayerRegistryDeerisle.c
* To remove only the ambient music and/or the contaminated area music, refer to the [readme.md](https://github.com/AlphaEye420/DayZ-Modwork/blob/main/Loading_Screen_Vanilla/Scripts/readme.md) in Scripts folder
* To remove the loading screen pictures, remove your /data edds files & delete /scripts/3_Game/loading_screen.c
* To remove the main menu layout, delete /scripts/5_Mission/MainMenu.c & the "/scripts/5_Mission/gui" folder
* To remove the character scene location the delete the last cfg section in config.cpp
* To remove the custom hints delete the hints.json in data folder +and+ within /Scripts/3_Game/ delete HintPage.c, UiHintPanal.c. and delete /Scripts/3_Game/gui folder

BE SURE TO CHANGE YourPBOname in all of the files!!  Use an editor and search for them all. See the scripts folder readme too.

You can contact me (AlphaEye) via my discord server general-chat channel https://discord.gg/BdkSUQENhM
