class CfgPatches
{
	class ZenCarWorkbench
	{
		requiredVersion = 1.0;
		requiredAddons[] =
		{
			"DZ_Data",
			"DZ_Scripts",
			"DZ_Gear_Tools",
			"DZ_Gear_Consumables"
		};
		units[] = {};
	};
};

class CfgMods
{
	class ZenCarWorkbench
	{
		dir = "ZenCarWorkbench_Exp";
		picture = "";
		action = "";
		hideName = 1;	
		hidePicture = 1;
		name = "ZenCarWorkbench_Exp";
		credits = "";
		author = "";
		authorID = "0";
		version = "1.0";
		type = "mod";
		dependencies[] = { };
		class defs
		{};
	};
};

class CfgVehicles
{
	class Inventory_Base;
	class Zen_CarWorkbench : Inventory_Base
	{
		attachments[] = 
		{
			"ZenCWB_Repair",
			"ZenCWB_ElRepair",
			"CarRadiator",
			"CarBattery",
			"TruckBattery",
			"SparkPlug",
			"ZenCWB_Spark2",
			"GlowPlug",
			"CanisterGasoline",
			"Rags",
			"KeyChain",
			"ExpansionAircraftBattery",
			"ExpansionHelicopterBattery",
			"ExpansionHydraulicHoses",
			"ExpansionIgniterPlug",
			"ZenCWB_Charger",
			"ZenCWB_TireIron",
			"ZenCWB_Pliers",
			"ZenCWB_Screwdriver",
			"ZenCWB_Wrench",
			"ZenCWB_Sledgehammer",
			"MetalWire",
			"ZenCWB_Paint1",
			"ZenCWB_Paint2"
		};
	};
	class BatteryCharger : Inventory_Base
	{
		inventorySlot[] +=
		{	
			"ZenCWB_Charger"
		};
	};
	class ElectronicRepairKit : Inventory_Base
	{
		inventorySlot[] +=
		{	
			"ZenCWB_ElRepair"
		};
	};
	class Hammer : Inventory_Base
	{
		inventorySlot[] +=
		{	
			"ZenCWB_Sledgehammer"
		};
	};
	class ExpansionSpraycanBase: Inventory_Base
	{
		inventorySlot[] +=
		{
			"ZenCWB_Paint1",
			"ZenCWB_Paint2"
		};
	};
}; 
class CfgSlots
{
	class Slot_ZenCWB_ElRepair
	{
		name = "ZenCWB_ElRepair";
		displayName = "Electronic Repair Kit";
		ghostIcon = "set:zencarworkbenchslots image:ElectronicRepairKit";
	};
	class Slot_ZenCWB_Charger
	{
		name = "ZenCWB_Charger";
		displayName = "Battery Charger";
		ghostIcon = "set:zencarworkbenchslots image:BatteryCharger";
	};
};