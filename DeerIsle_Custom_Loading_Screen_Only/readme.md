## Deer Isle Custom Loading Screen
**Change "YourPBOName" where ever you see it in all files**
### Files included and what to do with them:
* config.cpp - name changes needed
* data/hints.json - edit to suit, these are the hints that will be picked randomly to appear on loading screen
* data folder is where you store your **1920x1080 pixel edds files**
* scripts/3_game  has 3 files and a folder
  * HintPage.c - nothing to do
  * UiHintPanel.c - name changes at top and bottom of file
  * LoadingScreens.c - change the pbo names AND the edds file names to match yours 
    * *(note that the first class has different syntax for calling the edds than the last two classes in the file)*
  * GUI folder has the two layouts for hints (on load, and in main menu lobby) 
    * No need to edit, and careful if you decide to edit, challenging to fix syntax errors