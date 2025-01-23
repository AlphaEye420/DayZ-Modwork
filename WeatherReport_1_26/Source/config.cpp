class CfgPatches
{
	class PresetWeather
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};
class CfgMods
{
	class PresetWeather
	{
		dir="WeatherReport";
		action="";
		hideName=0;
		hidePicture=1;
		name="WeatherReport";
		author="AlphaEye";
		credits="affenb3rt";
		authorID="";
		version="1.26";
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
				value="";
				files[]=
				{
					"WeatherReport/scripts/4_World"
				};
			};
		};
	};
};
