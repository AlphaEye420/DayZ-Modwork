class CfgPatches
{
	class AIConvoyRace
	{
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[] = { "DZ_Scripts", "DZ_Vehicles_Wheeled", "DayZExpansion_AI_Scripts" };
		units[] = {};
	};
};

class CfgMods
{
	class AIConvoyRace
	{
		dir="AIConvoyRace";
		picture=""; 
		action="";
		hideName=1;
		hidePicture=1;
		name="Deer Isle Grand Prix";
		credits="Triumph"; 
		author="AlphaEye";
		authorID="0";  
		version="1.0";
		extra=0;
		type="mod";
		dependencies[]=
		{
			"World"
		};
		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] =
				{
					"AIConvoyRace/scripts/4_world"
				};
			};
		}
	};
};