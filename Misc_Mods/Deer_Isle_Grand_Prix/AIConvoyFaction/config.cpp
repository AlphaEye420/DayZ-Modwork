class CfgPatches
{
	class AIConvoyFactions
	{
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
		units[] = {};
	};
};

class CfgMods
{
	class AIConvoyFactions
	{
		dir="AIConvoyFactions";
		picture=""; 
		action="";
		hideName=1;
		hidePicture=1;
		name="AIConvoyFactions";
		credits=""; 
		author="";
		authorID="0";  
		version="1.0";
		extra=0;
		type="mod";
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
					"AIConvoyFactions/scripts/3_Game"
				};
			};
		}
	};
};