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
			"DZ_Sounds_Weapons"
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

class cfgCharacterScenes
{
    class deerisle // your map name
    {
        class loc1
        {
            target[]={x,z,y}; // main menu character location xzy
            position[]={x,z,target y difference}; // position of camera xzy (last value near 1)
            fov=0.69;
            date[]={2033,5,4,1,30}; //yyyy,mo,d,hh,mm - use mili time
            overcast=0;
            rain=0;
            fog=0;
            wind=0.236;
        };
    };
};
