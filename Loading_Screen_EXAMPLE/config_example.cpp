class CfgPatches
{
	class YourModName_LoadingScreen
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Consumables",
			"DZ_Vehicles_Wheeled",
			"DZ_Structures_Residential",
			"DZ_Sounds_Effects",
			"DZ_Sounds_Weapons",
			"DayZExpansion_Scripts",
            "DayZExpansion_Worlds_IntroScenes"
		};
	};
};

class CfgMods
{
	class DZ_YourModName_LoadingScreen
	{
	    dir = "YourModName";
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
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"YourModName/Scripts/3_Game"
				};
			};
			
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"YourModName/Scripts/5_Mission"
				};
			};
		};
    };
};

class CfgSoundShaders
{
	class YourModName_Music_1_SoundShader
	{
		samples[] = {{"YourModName\data\YourSONGName",1}};
		volume=0.786;
	};
};

class CfgSoundSets
{	
	class YourModName_Music_1_SoundSet
	{
		soundShaders[]=
		{
			"YourModName_Music_1_SoundShader"
		};
		volumeFactor=1;
		frequencyFactor=1;
		spatial=0;
	};
};