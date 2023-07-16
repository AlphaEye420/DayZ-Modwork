CUSTOM LOADING SCREEN PICTURE CAROSEL + MENU MUSIC + CHARACTER MAIN MENU SCENE + BASIC MAIN MENU LAYOUT

To use the example follow all of these steps - match exactly correct or it will not work:

0. Copy the file structure into YourModName directory
1. Remove the text "_EXAMPLE" from the 5 filenames:
	* config_EXAMPLE.cpp -- NEEDED FOR ALL OF IT
	* \gui\main_menu_EXAMPLE.layout  -- NEEDED FOR MAIN MENU LAYOUT
	* \scripts\3_Game\LoadingScreens_EXAMPLE.c -- NEEDED FOR LOADING SCREENS
	* \scripts\5_Mission\MainMenu_EXAMPLE.c -- NEEDED FOR MAIN MENU LAYOUT
	* \scripts\5_Mission\MainMenuMusic_EXAMPLE.c -- NEEDED FOR MENU MUSIC
2. THEN, Open into an editor the 5 files you just renamed

3. Put all of your loading screen edds pictures files and ogg music file in the folder called 'data'
4. Put all of your custom icons and logo files in the folder called 'gui\imagesets' - some standard issue icons provided for you already

5. In the 3 .c scripts AND config.cpp, change the text of "YourModName" to the name of your mod on steam !! DO this in ALL 4 files !!

6. In the config.cpp, change the text of YourSONGName to your ogg file name in the data folder, and fill in the "" for your steam name and ID, then, change the name of the map in the last function to match your server's map name & choose your location x,z,y and time yyyy,mo,d,hh,mm (position y value needs to be near 1)

7. In the LoadingScreen.c file in 3_Game, change the text of 'Your_PIC_#' to your edds file names in the data folder
!! DEFAULT IS 21 PIC CAROSEL, ADJUST TO YOUR NUMBER OF PICS BY ADDING OR DELETING LINES AND ADJUSTING THE RANDOMIZER'S MIN/MAX IN ALL 3 SECTIONS OF THE FILE !!

8. In the \scripts\5_Mission\MainMenu_EXAMPLE.c be sure to change the IP and connection port, then edit the links below that happen on icon click

9. In the \gui\main_menu_EXAMPLE.layout look for "//***********" in the line to see where you need to edit to match your graphics with your sizes and choose font and screen location on main menu
!! It is helpful to match the sizes of your photos to your widget dimensions, though you may experiment with stretching by using different values !!

10. Pack mod


~ if you need only one (1) pic, set the variable i to "int i = 0;" and only have a "if (i==0)" line IN EACH OF THE 3 SECTIONS of \scripts\3_Game\loading_screen.c

~ if you do not need music you can remove the 2 soundshaders functions in config.cpp and delete \scripts\5_Mission\MainMenuMusic.c
~ if you do not need the loading screen pics at all, remove \data edds files and delete \scripts\3_Game\loading_screen.c
~ if you do not need the main menu layout, delete \scripts\5_Mission\MainMenu.c and the \gui folder
~ if you do not need the character scene location the delete the last cfg section in config.cpp

