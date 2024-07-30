// Add to your server pack config.cpp
// Halves Splint's size and weight, and increases durability by 25%
	class Clothing;
	class Inventory_Base;
	class Splint_Applied: Clothing
	{
		scope=2;
		displayName="$STR_CfgVehicles_Splint0";
		descriptionShort="$STR_CfgVehicles_Splint1";
		model="\dz\gear\medical\Improvised_fixture.p3d";
		inventorySlot[]=
		{
			"Splint_Right"
		};
		simulation="clothing";
		rotationFlags=17;
		itemSize[]={1,4};
		weight=240;
		absorbency=0.30000001;
		class ClothingTypes
		{
			male="\dz\gear\medical\improvised_fixture_m.p3d";
			female="\dz\gear\medical\improvised_fixture_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\improvised_fixture.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\improvised_fixture.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\improvised_fixture_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\improvised_fixture_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\improvised_fixture_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimationSources
		{
			class cover
			{
				source="user";
				animPeriod=0.5;
				initPhase=1;
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeLightBlunt";
				range=1.4;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1.4;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=3.3;
			};
		};
	};
	class Splint: Inventory_Base
	{
		scope=2;
		displayName="$STR_CfgVehicles_Splint0";
		descriptionShort="$STR_CfgVehicles_Splint1";
		model="\dz\gear\medical\Improvised_fixture.p3d";
		debug_ItemCategory=7;
		rotationFlags=17;
		itemSize[]={1,4};
		weight=240;
		absorbency=0.30000001;
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\medical\data\improvised_fixture.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\medical\data\improvised_fixture.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\medical\data\improvised_fixture_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\medical\data\improvised_fixture_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\medical\data\improvised_fixture_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class MeleeModes
		{
			class Default
			{
				ammo="MeleeLightBlunt";
				range=1.4;
			};
			class Heavy
			{
				ammo="MeleeLightBlunt_Heavy";
				range=1.4;
			};
			class Sprint
			{
				ammo="MeleeLightBlunt_Heavy";
				range=3.3;
			};
		};
	};