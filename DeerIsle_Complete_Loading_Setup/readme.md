## FULL CUSTOM LOADING SETUP for Deer Isle
### LOADING SCREEN & HINTS + MAINMENU CHAR SCENE & LAYOUT + InGameMENU + MENU MUSIC
*! THIS PACKABLE PBO WAS MADE FOR DEERISLE 5.9 / works with DAYZ 1.28 and only supported as such !*
### To use this template follow all of these steps - match exactly correct or it will not work:
~~~
First note there is no pbo to download.  You add your pics and music to a directory, edit text and pack your own pbo.
Your mod name and pbo name may or may not be the same, it is up to you.  Just be sure the pbo name is used in editing.

Note: You should set your DayZ Tools Addon Builder Options (top text field) to ensure a good pack: 
*.emat;*.edds;*.ptc;*.c;*.imageset;*.layout;*.ogg;*.png;*.paa;*.rvmat;*.wrp;*.json
~~~

Download the directory structure [from this link](https://download-directory.github.io/?url=https%3A%2F%2Fgithub.com%2FAlphaEye420%2FDayZ-Modwork%2Ftree%2Fmain%2FLoading_Screen_Vanilla) and make a copy of the structure into YourPBOName directory
* 1. Open into an editor ALL of the files you created _(files other than your ogg and edds)_
* 2. Put all of your loading screen edds pictures files and ogg music files in the folder called 'data'
* 3. Put all of your custom icons and logo files in the folder called '/Scripts/5_Mission/gui/imagesets' - some standard issue icons provided for you already
* 4. In all of your open files in editor, change the text of "YourPBOName" to the name of the pbo in your mod you are going to upload to Steam _!! DO a search for YourPBOName in all files NP++ can do it in 1 click !!_
* 5. In the config.cpp, change YourSONGName(s) to match your ogg filename(s) in the data folder, and fill in the "" for your steam name and ID. Then, change the name of the map in the last function to match your server's map name & configure character scene
* 6. In the LoadingScreen.c file in 3_Game, change the text of 'Your_PIC_#' to your edds file names in the data folder _!! DEFAULT IS 21 PIC CAROUSEL, ADJUST TO YOUR NUMBER OF PICS BY ADDING OR DELETING LINES AND ADJUSTING THE RANDOMIZER'S MIN/MAX IN ALL 3 SECTIONS OF THE FILE !!_
* 7. In the MainMenu.c be sure to change the IP and connection port, then edit the links below that happen on icon click
* 8. In the main_menu.layout look for //*** to see where you can edit to match your graphics with your sizes, choose font and graphics locations !! It is helpful to match the sizes of your photos to your widget dimensions, though you may experiment with stretching by using different values !!
* 9. In Hints.json in data folder, customize the text of the hints ~ backing images & layout are broken but the text can be customized
* 10. In DynamicMusicPlayerRegistryDeerisle.c edit your menu music name, and then the military and city coordinates for ambient tracks; comment out with 2 slashes anything you don't need to register _(this is setup for DEER ISLE ONLY!)_
* 11. Pack your loading screen pbo, then pack a mod with this pbo included

### SHOULD YOU WANT ONLY A PORTION: **LOOK IN THIS GIT FOR 'ONLY' ATTACHED TO THE FOLDER NAME**

**BE SURE TO CHANGE YourPBOname** in all of the files!!  Use an editor and search for them all. See the scripts folder readme too.
_____
*___Troubleshooting:___*
* Loading Screen
  * White Screen = corrupt edds file
  * DI Screen = path in loadingscreen.c is wrong, or your logic for randomizing is incorrect
* Music not playing
  * Your ogg file failed _(try other music files, and make sure to use mp3s and convert using my provided link)_
  * Your config.cpp is setup incorrectly with either soundset/shaders or paths
* Logo missing
  * 5_mission/gui 2 main menu layouts have a path for your logo, 
    * Say data/ folder if you put it in there, or move or copy your edds file to the imagesets folder
  * Your edds file is corrupt if you see a white box
  * If stretched, then in the above layouts you may have misrepresented the size
* Play button doesn't work = Set your IP in mainmenu.c
* Discord button customization
  * Icon links are set in mainmenu.c
  * *_(Keep DeerIsle icon set to JMC's website so people don't come here trying to find the server admin!)_*
* Expansion: general settings: set 3 settings for loading to 0, then set the path to your logo at bottom
_____
You can contact me (AlphaEye) via my discord server general-chat channel https://discord.gg/BdkSUQENhM
