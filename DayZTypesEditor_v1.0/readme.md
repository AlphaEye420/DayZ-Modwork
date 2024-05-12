# DayZ Types Editor v1.0.beta

_Written by AlphaEye_

_To install, just unzip and run the .exe_

**ALWAYS MAKE BACKUPS OF YOUR FILES BEFORE EDITING!**
___
## MENU Contents:
+ **FILE MENU:**
	+ **IMPORT:** Begin a session with a valid types.xml file import, then edit the data to suit
	+ **MERGE:** Add rows to the table by importing and merging a second xml
	+ **WRITE:** Exports the table to a file of your choosing  (Ready to use in DayZ Servers!)
		+ Checks will happen upon write, so it may be better for you to use the Checks Tool before writing to file 
	+ **RESET:** Go Back to the 'Initial State' that the Table Grid was upon first importing
	+ **EXIT:** Closes the Application  (You may also click the X in upper right of the main window)
+ **VIEW MENU:**
	+ Set font and colors, and the app stores your selection as default for you
+ **TOOLS MENU:**
	+ **CHECKS:** Check the data for errors, and in most cases this automatically corrects them
	+ **LISTS:** A tool for admins, helps to combat against corrupt server-mission definitions
	+ **STATS:** Quickly sums the 'Min' and 'Nominal' spawns in specific datasets from the table
	+ **TRADER:** Quickly saves your sorted grid in the form of DayZ Trader Mod syntax (.txt file)
	+ **COPY & PASTE:** You can copy a SINGLE CELL to the clipboard to paste to MULTIPLE CELLS at a time
		+ This can take longer to complete if you select a large batch cells before pasting - paste to small groups
		+ If you select multiple cells and hit copy you will get bad results when hitting paste
		+ **Control C to _COPY a SINGLE CELL_ and Control V to paste to a selected group of cells**
+ **HELP MENU:**
	+ **Help Me! (F1 key)**
	+ **About (F2 key)**
___
## BUTTONS:
+ **SEARCH FILTER:** Used to find text in any row and hide the others; type text in popup *(blank=reset)*
+ **RESET:** Returns filtered rows to view
+ **CHECKBOXES:** Hides columns from view if unchecked; other buttons may force these to a checked state
+ **CREATE PRESET:** Sets the USAGES & VALUES as a checkbox array, using the current selected cell as default
	+ When LOCKING IN your preset, the next button will force these checkboxes to the grid
+ **FORCE PRESET TO SELECTED ROW(s):** Quickly Match the Clolumns of Selected Rows to your preset
	+ Read the popup for details *(using confirmation required)*
	+ **Confirmation Required Checkbox:** Unchecking this will result in the Force Preset not having a popup
