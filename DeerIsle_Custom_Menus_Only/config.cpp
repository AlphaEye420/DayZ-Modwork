class CfgPatches
{
	//*** Change "YourPBOName" where ever you see it below in this and all files
	class YourPBOName_Menus
	{
		units[] = {}; 
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class CfgMods
{
	class DZ_YourPBOName_Menus
	{
	    dir = "YourPBOName"; 
	    picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
	    name = "";
	    credits = "";
	    author = "";
	    authorID = "";
	    version = "1.0";
	    extra = 0;
	    type = "mod";

		dependencies[]= 
		{
			"Game",
			"Mission"
		};
		
		class defs
		{			
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"YourPBOName/Scripts/5_Mission" 
				};
			};
		};
    };
};
