CUSTOM LOADING SCREEN PICTURE CAROSEL + ONE CUSTOM MUSIC THEME SONG

To use the example follow all of these steps - match exactly correct or it will not work:

0. Copy the file structure into YourModName directory
1. Remove the text "_example" from the 3 filenames (config_example.cpp becomes config.cpp & same for the 3_Game and 5_mission script .c files)
2. Open 3 code files you just name-edited into an editor 
3. Put all of your edds pictures files and ogg music file in the folder called 'data'
4. In the 2 .c files and config.cpp, change the text of YourModName to the name of your mod on steam !! DO this in ALL 3 files !!
5. In the config.cpp, change the text of YourSONGName to your ogg file name in the data folder, and fill in the "" for your steam name and ID.
6. In the LoadingScreen.c file in 3_Game, change the text of 'Your_PIC_#' to your edds file names in the data folder
!! DEFAULT IS 21 PIC CAROSEL, ADJUST TO YOUR NUMBER OF PICS BY ADDING OR DELETING LINES AND ADJUSTING THE RANDOMIZER'S MIN/MAX IN ALL 3 SECTIONS OF THE FILE !!
7. Pack mod

if you do not need music you can remove the parts that pertain to music and 5_Mission (also delete the last 2 functions in config.cpp)
if you need one pic only, set the variable i to "int i = 0;" and only leave the "if (i==0)" lines in the 3 sections of loading_screen.c
if you do not need the pics at all, you can remove the parts that pertain edds files and 3_Game
