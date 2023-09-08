# CHECKLIST FOR TYPING CHANGES:

config_EXAMPLE.cpp
* There are 12+ places to change information! Look for //*** 
* (must do lines 3 5 22 24 50 59 68 70 77 81)
* character scene editing is optional

MainMenu_EXAMPLE.c
* There are 4 places to change information
* "YourModName" (line 8)
* Server IP and Port (line 55)
* Web Addresses for lower left icons (lines 76 81)

main_menu_EXAMPLE.layout
* There are 3 places to change "YourModName" (lines 350 382 619) 
* The locations of your graphics need to match your filename and path
* change fonts if desired

MainMenuMusic_EXAMPLE.c
* There is 1 place to change "YourModName"

LoadingScreens_EXAMPLE.c
* There are 3 places to change ""YOUR_PIC_1"-21, etc or how many pics you plan to have in shuffle
* Make sure the "int i = Math.RandomInt(0,20);" matches the size of the array of pics you use
