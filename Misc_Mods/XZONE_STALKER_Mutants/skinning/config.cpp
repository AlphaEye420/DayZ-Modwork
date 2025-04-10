class CfgPatches
{
	class DZ_Mutants
	{
		units[]=
		{
			"brain_mutant",
			"liver_mutant",
			"serdce_mutant",
			"XZ_Boar_liver",
			"XZ_Boar_serdce",
			"XZ_Boar_brain",
			"XZ_Burer_liver",
			"XZ_Burer_serdce",
			"XZ_Burer_brain",
			"XZ_Cat_Bayn_liver",
			"XZ_Cat_Bayn_serdce",
			"XZ_Cat_Bayn_brain",
			"XZ_Dog_liver",
			"XZ_Dog_serdce",
			"XZ_Dog_brain",
			"XZ_Fresh_liver",
			"XZ_Fresh_serdce",
			"XZ_Fresh_brain",
			"XZ_Izlom_liver",
			"XZ_Izlom_serdce",
			"XZ_Izlom_brain",
			"XZ_Krovosos_liver",
			"XZ_Krovosos_serdce",
			"XZ_Krovosos_brain",
			"XZ_Pdog_liver",
			"XZ_Pdog_serdce",
			"XZ_Pdog_brain",
			"XZ_Pgigant_liver",
			"XZ_Pgigant_serdce",
			"XZ_Pgigant_brain",
			"XZ_Poltergeist_liver",
			"XZ_Poltergeist_serdce",
			"XZ_Poltergeist_brain",
			"XZ_Snork_liver",
			"XZ_Snork_serdce",
			"XZ_Snork_brain",
			"XZ_Tushkano_liver",
			"XZ_Tushkano_serdce",
			"XZ_Tushkano_brain",
			"XZ_Zombi_liver",
			"XZ_Zombi_serdce",
			"XZ_Zombi_brain",
			"Mutant_XZ_Zombi_Hand",
			"Mutant_XZ_Tushkano_Head",
			"Mutant_XZ_Snork_Leg",
			"Mutant_XZ_Poltergeist_Eye",
			"Mutant_XZ_Pgigant_Hand",
			"Mutant_XZ_Pdog_Tail",
			"Mutant_XZ_Krovosos_Jaw",
			"Mutant_XZ_Izlom_Hand",
			"Mutant_XZ_Fresh_Eye",
			"Mutant_XZ_Dog_Tail",
			"Mutant_XZ_Cat_Leg",
			"Mutant_XZ_Boar_leg",
			"Mutant_XZ_Burer_Hand"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Characters",
			"DZ_Characters_Zombies",
			"DZ_Data_Bliss",
			"DZ_AI_Bliss",
			"DZ_Animals",
			"DZ_Data"
		};
	};
};

class CfgVehicles
{
	class Edible_Base;
	class WolfSteakMeat;
	class Mutant_XZ_Zombi_Hand: Edible_Base
	{
		displayName="Zombie Hand";
		descriptionShort="Scientists are trying to figure out how such a rotten body was able to retain the muscles that allow Zombies to strike so hard.";
	}
	class Mutant_XZ_Tushkano_Head: Edible_Base
	{
		displayName="Mutant Rodent Head";
		descriptionShort="The gopher tortoise has a highly developed gregarious intelligence. Scientists are trying to figure out how a tiny brain can hold a large amount of information and everything else. Scientists make serums from their brains, but all the product is exported from the Zone, and what they are used for is unknown.";
	}
	class Mutant_XZ_Snork_Leg: Edible_Base
	{
		displayName="Snork Foot";
		descriptionShort="The snorkel's foot, unlike the human foot, contains a greater number of tendons that are remarkably elastic. This explains their ability to make incredible jumps.";
	}
	class Mutant_XZ_Poltergeist_Eye: Edible_Base
	{
		displayName="Poltergeist Eye";
		descriptionShort="For unknown reasons the eye of poltergeist is able to become invisible in the source of ultraviolet radiation, if scientists will be able to understand the properties of the eye it will be possible to recreate equipment that will disappear in certain conditions. You can contribute to science.";
	}
	class Mutant_XZ_Pgigant_Hand: Edible_Base
	{
		displayName="Pseudo-Giant Arm";
		descriptionShort="For unknown reasons, the hand of a young pseudo-giant can quickly heal wounds, if scientists will understand from what happens healing effect will be a real breakthrough in medicine.";
	}
	class Mutant_XZ_Pdog_Tail: Edible_Base
	{
		displayName="Psy Dog Tail";
		descriptionShort="The resistance of the skin of mutated dogs to chemical and electrical effects has long attracted the attention of scientists. Because of the lack of fatty deposits, dog tails are the most suitable for laboratory research.";
	}
	class Mutant_XZ_Krovosos_Jaw: Edible_Base
	{
		displayName="Bloodsucker Tentacle";
		descriptionShort="The tentacles of the bloodsucker contain a special gland: it secretes an enzyme that dissolves the victim's skin while preventing blood from clotting. If scientists are able to determine the structure of the enzyme, it could lead to a medical breakthrough.";
	}
	class Mutant_XZ_Izlom_Hand: Edible_Base
	{
		displayName="Fractured Izlom Hand";
		descriptionShort="Scientists are not interested in the hand itself, but in the synovial canals of the tendons. For unknown reasons, the fluid contained there has properties that far exceed those of all known antitumor drugs. Its molecular composition does not differ from the usual, but under the influence of specific irradiation, the properties have radically changed. Attempts to create an analog in laboratory conditions proved fruitless. The overwhelming amount of the product goes abroad due to the devastation and poverty of both Ukrainian and Russian science and medicine.";
	}
	class Mutant_XZ_Fresh_Eye: Edible_Base
	{
		displayName="Mutant Pig Eye";
		descriptionShort="After mutation, the enlarged flesh eye has acquired a number of properties, the most useful of which is the ability to regenerate the lens. The details of this mechanism are unknown, but this discovery promises to revolutionize medicine. You can contribute to science by selling the flesh eye to scientists for research.";
	}
	class Mutant_XZ_Dog_Tail: Edible_Base
	{
		displayName="Mutant Dog Tail";
		descriptionShort="The resistance of the skin of mutated dogs to chemical and electrical effects has long attracted the attention of scientists. Because of the lack of fatty deposits, dog tails are the most suitable for laboratory research. Since the first catastrophe several generations have passed in the canine family, and in each of them the influence of the Zone has been increasingly observed. Mutations and evolutionary adaptation have led to the strengthening of previously weakly expressed canine abilities, and often to the detriment of the usual ones. The main physiological changes affected eyesight - it turned out to be almost useless after the rapid increase in senses: for example, blind puppies survived in the Zone no worse, if not better than their sighted brethren. As a result, ordinary dogs soon degenerated here completely, giving way to a new species - blind dogs. These animals perfectly recognize and avoid anomalies, radiation and other invisible dangers that swarm the Zone. Like their ancestors, blind dogs hunt in packs; encountering a large group of these creatures means serious danger even for a well-armed stalker.";
	}
	class Mutant_XZ_Cat_Leg: Edible_Base
	{
		displayName="Mutant Cat Paw";
		descriptionShort="A cat's paw is used by scientists to make a number of medicines, the most common of which is a radioprotector. Bayun (by analogy with the bayun cat from fairy tales) - a creature of the cat family, which imitates any voices and thus lures victims or scares away pursuers. Upon seeing a human, will not necessarily attack - can simply lure away into a thicket and scamper away. Mutated from a common cat.";
	}
	class Mutant_XZ_Burer_Hand: Edible_Base
	{
		displayName="Burer Hand";
		descriptionShort="The burer's arm has acquired a number of properties, the most useful of which is a strong resistance to radiation. The details of this mechanism are unknown. You can contribute to science by selling the Boorer Hand to scientists for research.";
	}
	class Mutant_XZ_Boar_leg: Edible_Base
	{
		displayName="Mutant Boar Hoof";
		descriptionShort="The Mutated Boar's hoof is used by scientists to make a number of medicines, the most common of which is an anti-radiation serum.";
	}
	
	class Inventory_Base;
	class brain_mutant: Inventory_Base
	{
		displayName="Mutant Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
	class liver_mutant: Inventory_Base
	{
		displayName="Mutant Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	}
	class serdce_mutant: Inventory_Base
	{
		displayName="Mutant Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	
	class XZ_Boar_liver: liver_mutant
	{
		displayName="Mutant Boar Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	};
	class XZ_Boar_serdce: serdce_mutant
	{
		displayName="Mutant Boar Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	class XZ_Boar_brain: brain_mutant
	{
		displayName="Mutant Boar Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
	
	class XZ_Burer_liver: liver_mutant
	{
		displayName="Burer Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	};
	class XZ_Burer_serdce: serdce_mutant
	{
		displayName="Burer Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	class XZ_Burer_brain: brain_mutant
	{
		displayName="Burer Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
	
	class XZ_Cat_Bayn_liver: liver_mutant
	{
		displayName="Mutant Cat Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	};
	class XZ_Cat_Bayn_serdce: serdce_mutant
	{
		displayName="Mutant Cat Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	class XZ_Cat_Bayn_brain: brain_mutant
	{
		displayName="Mutant Cat Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
	
	class XZ_Dog_liver: liver_mutant
	{
		displayName="Mutant Dog Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	};
	class XZ_Dog_serdce: serdce_mutant
	{
		displayName="Mutant Dog Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	class XZ_Dog_brain: brain_mutant
	{
		displayName="Mutant Dog Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
	
	class XZ_Fresh_liver: liver_mutant
	{
		displayName="Mutant Pig Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	};
	class XZ_Fresh_serdce: serdce_mutant
	{
		displayName="Mutant Pig Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	class XZ_Fresh_brain: brain_mutant
	{
		displayName="Mutant Pig Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
	
	class XZ_Izlom_liver: liver_mutant
	{
		displayName="Izlom Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	};
	class XZ_Izlom_serdce: serdce_mutant
	{
		displayName="Izlom Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	class XZ_Izlom_brain: brain_mutant
	{
		displayName="Izlom Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
	
	class XZ_Krovosos_liver: liver_mutant
	{
		displayName="Krovosos Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	};
	class XZ_Krovosos_serdce: serdce_mutant
	{
		displayName="Krovosos Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	class XZ_Krovosos_brain: brain_mutant
	{
		displayName="Krovosos Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
	
	class XZ_Pdog_liver: liver_mutant
	{
		displayName="Psy Dog Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	};
	class XZ_Pdog_serdce: serdce_mutant
	{
		displayName="Psy Dog Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	class XZ_Pdog_brain: brain_mutant
	{
		displayName="Psy Dog Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
	
	class XZ_Pgigant_liver: liver_mutant
	{
		displayName="Pseudo-Giant Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	};
	class XZ_Pgigant_serdce: serdce_mutant
	{
		displayName="Pseudo-Giant Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	class XZ_Pgigant_brain: brain_mutant
	{
		displayName="Pseudo-Giant Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
	
	class XZ_Poltergeist_liver: liver_mutant
	{
		displayName="Poltergeist Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	};
	class XZ_Poltergeist_serdce: serdce_mutant
	{
		displayName="Poltergeist Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	class XZ_Poltergeist_brain: brain_mutant
	{
		displayName="Poltergeist Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
	
	class XZ_Snork_liver: liver_mutant
	{
		displayName="Snork Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	};
	class XZ_Snork_serdce: serdce_mutant
	{
		displayName="Snork Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	class XZ_Snork_brain: brain_mutant
	{
		displayName="Snork Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
	
	class XZ_Tushkano_liver: liver_mutant
	{
		displayName="Mutant Rodent Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	};
	class XZ_Tushkano_serdce: serdce_mutant
	{
		displayName="Mutant Rodent Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	class XZ_Tushkano_brain: brain_mutant
	{
		displayName="Mutant Rodent Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
	
	class XZ_Zombi_liver: liver_mutant
	{
		displayName="Zombie Liver";
		descriptionShort="A liver savaged by an extreme exposure to radiation.";
	};
	class XZ_Zombi_serdce: serdce_mutant
	{
		displayName="Zombie Heart";
		descriptionShort="A heart cut out from a mutant.";
	}
	class XZ_Zombi_brain: brain_mutant
	{
		displayName="Zombie Brain";
		descriptionShort="A brain with evidence of radiation poisoning.";
	}
};