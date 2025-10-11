class CfgPatches
{
	//*** Change "YourPBOName" where ever you see it below in this and all files
	class YourPBOName_LoadingScreenOnly
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
	class DZ_YourPBOName_LoadingScreenOnly
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
			"Game"
		};
		
		class defs
		{
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"YourPBOName/Scripts/3_Game" 
				};
			};
		};
    };
};
