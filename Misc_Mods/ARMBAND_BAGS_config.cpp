// add this to your mod's config.cpp and you will have these bags go into armband slot
// shout out to ArmbandBags mod: https://steamcommunity.com/sharedfiles/filedetails/?id=3141455990
// I added only the sling bags at the bottom

class cfgVehicles
{
	class Clothing;
	class DuffelBagSmall_ColorBase: Clothing
	{
		displayName="$STR_cfgvehicles_DuffelBagSmall_ColorBase0";
		descriptionShort="$STR_cfgvehicles_DuffelBagSmall_ColorBase1";
		model="\dz\characters\backpacks\DuffelBagSmall_g.p3d";
		debug_ItemCategory=9;
		inventorySlot[]=
		{
			"Armband"
		};
		attachments[]=
		{
			"Chemlight",
			"WalkieTalkie"
		};
		itemInfo[]=
		{
			"Clothing",
			"Armband"
		};
		rotationFlags=2;
		itemSize[]={5,4};
		itemsCargoSize[]={7,5};
		weight=1000;
		varWetMax=0.79000002;
		heatIsolation=0.2;
		repairableWithKits[]={5,3};
		repairCosts[]={20,25};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class ClothingTypes
		{
			male="\DZ\characters\backpacks\DuffelBagSmall_m.p3d";
			female="\DZ\characters\backpacks\DuffelBagSmall_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=150;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\Characters\backpacks\data\DuffelBagSmall.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\Characters\backpacks\data\DuffelBagSmall.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\Characters\backpacks\data\DuffelBagSmall_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\Characters\backpacks\data\DuffelBagSmall_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\Characters\backpacks\data\DuffelBagSmall_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpBackPack_Plastic_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBackPack_Plastic_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="taloonbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	
	class CanvasBag_ColorBase: Clothing
	{
		displayName="$STR_cfgvehicles_CanvasBag_ColorBase0";
		descriptionShort="$STR_cfgvehicles_CanvasBag_ColorBase1";
		model="\dz\characters\backpacks\CanvasBag_g.p3d";
		debug_ItemCategory=9;
		inventorySlot[]=
		{
			"Armband"
		};
		attachments[]=
		{
			"Chemlight",
			"WalkieTalkie"
		};
		itemInfo[]=
		{
			"Clothing",
			"Armband"
		};
		rotationFlags=2;
		itemSize[]={5,4};
		itemsCargoSize[]={7,5};
		weight=1000;
		varWetMax=0.79000002;
		heatIsolation=0.2;
		repairableWithKits[]={5,2};
		repairCosts[]={20,25};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class ClothingTypes
		{
			male="\DZ\characters\backpacks\CanvasBag_m.p3d";
			female="\DZ\characters\backpacks\CanvasBag_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpBackPack_Plastic_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBackPack_Plastic_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="taloonbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	
	class ArmyPouch_ColorBase: Clothing
	{
		displayName="$STR_cfgvehicles_ArmyPouch_ColorBase0";
		descriptionShort="$STR_cfgvehicles_ArmyPouch_ColorBase1";
		model="\dz\characters\backpacks\ArmyPouch_g.p3d";
		debug_ItemCategory=9;
		inventorySlot[]=
		{
			"Armband"
		};
		attachments[]=
		{
			"Chemlight",
			"WalkieTalkie"
		};
		itemInfo[]=
		{
			"Clothing",
			"Armband"
		};
		rotationFlags=2;
		itemSize[]={4,5};
		itemsCargoSize[]={7,5};
		weight=700;
		varWetMax=0.79000002;
		heatIsolation=0.1;
		repairableWithKits[]={5,2};
		repairCosts[]={20,25};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class ClothingTypes
		{
			male="\DZ\characters\backpacks\ArmyPouch_m.p3d";
			female="\DZ\characters\backpacks\ArmyPouch_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=130;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\Characters\backpacks\data\ArmyPouch.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\Characters\backpacks\data\ArmyPouch.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\Characters\backpacks\data\ArmyPouch_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\Characters\backpacks\data\ArmyPouch_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\Characters\backpacks\data\ArmyPouch_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpBackPack_Plastic_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBackPack_Plastic_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="taloonbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	
	class DrysackBag_ColorBase: Clothing
	{
		displayName="$STR_cfgvehicles_DrysackBag_ColorBase0";
		descriptionShort="$STR_cfgvehicles_DrysackBag_ColorBase1";
		model="\dz\characters\backpacks\drysackbag_g.p3d";
		debug_ItemCategory=9;
		inventorySlot[]=
		{
			"Armband"
		};
		attachments[]=
		{
			"WalkieTalkie"
		};
		itemInfo[]=
		{
			"Clothing",
			"Armband"
		};
		rotationFlags=17;
		itemSize[]={4,5};
		itemsCargoSize[]={5,4};
		weight=300;
		canBeDigged=1;
		varWetMax=0.249;
		heatIsolation=0.30000001;
		repairableWithKits[]={5,6};
		repairCosts[]={30,25};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class ClothingTypes
		{
			male="\DZ\characters\backpacks\drysackbag_m.p3d";
			female="\DZ\characters\backpacks\drysackbag_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=80;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\containers\data\WaterproofBag.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\containers\data\WaterproofBag.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\containers\data\WaterproofBag_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\containers\data\WaterproofBag_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\containers\data\WaterproofBag_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpBackPack_Plastic_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBackPack_Plastic_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="taloonbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
	
	// Alpha Eye contributed:
	class SlingBag_ColorBase: Clothing
	{
		displayName="SlingBag";
		descriptionShort="A small bag to sling over your shoulder.";
		model="\dz\characters\backpacks\SlingBag_g.p3d";
		debug_ItemCategory=9;
		inventorySlot[]=
		{
			"Armband"
		};
		attachments[]=
		{
			"WalkieTalkie"
		};
		itemInfo[]=
		{
			"Clothing",
			"Armband"
		};
		rotationFlags=2;
		itemSize[]={4,4};
		itemsCargoSize[]={7,5};
		weight=500;
		varWetMax=0.5;
		heatIsolation=0.1;
		repairableWithKits[]={5,2};
		repairCosts[]={20,25};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		class ClothingTypes
		{
			male="\DZ\characters\backpacks\SlingBag_m.p3d";
			female="\DZ\characters\backpacks\SlingBag_f.p3d";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem_Light
				{
					soundSet="pickUpBackPack_Plastic_Light_SoundSet";
					id=796;
				};
				class pickUpItem
				{
					soundSet="pickUpBackPack_Plastic_SoundSet";
					id=797;
				};
				class drop
				{
					soundset="taloonbag_drop_SoundSet";
					id=898;
				};
			};
		};
	};
};

