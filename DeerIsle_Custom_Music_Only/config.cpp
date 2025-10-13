class CfgPatches
{
	//*** Change "YourPBOName" & "YourMENUtrackName" where ever you see it below in this and all files
	class YourPBOName_Music
	{
		units[] = {}; 
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Sounds_Effects"
		};
	};
};

class CfgMods
{
	class DZ_YourPBOName_Music
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
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"YourPBOName/Scripts/3_Game" 
				};
			};
		
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

class CfgSoundShaders
{
	// You can make Music_1 Music_2 Music_3 .. etc.. for multiple imported tracks (duplicate whole class below)
	class YourPBOName_Music_1_SoundShader
	{
		samples[] = {{"YourPBOName\Data\YourMENUtrackName",1}};  //*** Change "YourMENUtrackName"
		volume=0.786;
	};
};

class CfgSoundSets
{	
	// match all SoundShaders to a SoundSet
	class YourPBOName_Music_1_SoundSet
	{
		soundShaders[]=
		{
			"YourPBOName_Music_1_SoundShader"
		};
		volumeFactor=1;
		frequencyFactor=1;
		spatial=0;
	};
};