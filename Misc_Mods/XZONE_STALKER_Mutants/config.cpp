class CfgPatches
{
	class DZ_Characters_Zombies
	{
		units[]=
		{
			/*"Mutant_XZ_Himera1",
			"Mutant_XZ_Himera2",
			"Mutant_XZ_Himera3",
			"Mutant_XZ_Himera3_Super",*/
			"Mutant_XZ_Poltergeist",
			"Mutant_XZ_Pse_Dog1",
			"Mutant_XZ_Pse_Dog2",
			"Mutant_XZ_PGigant",
			"Mutant_XZ_Krovosos1",
			"Mutant_XZ_Krovosos2",
			"Mutant_XZ_Krovosos3",
			"Mutant_XZ_Boar1",
			"Mutant_XZ_Boar2",
			"Mutant_XZ_Cat_Bayn1",
			"Mutant_XZ_Cat_Bayn2",
			"Mutant_XZ_Cat_Bayn3",
			"Mutant_XZ_Dog_Red",
			"Mutant_XZ_Dog_White",
			"Mutant_XZ_Dog_Fur",
			"Mutant_XZ_Dog_Brown",
			"Mutant_XZ_Tushkano1",
			"Mutant_XZ_Tushkano2",
			"Mutant_XZ_Tushkano3",
			"Mutant_XZ_Fresh1",
			"Mutant_XZ_Fresh2",
			"Mutant_XZ_Fresh3",
			"Mutant_XZ_Burer1",
			"Mutant_XZ_Burer2",
			"Mutant_XZ_Izlom1",
			"Mutant_XZ_Izlom2",
			"Mutant_XZ_Izlom3",
			"Mutant_XZ_Snork1",
			"Mutant_XZ_Snork2",
			"Zombi_XZ_Civ_Trup1",
			"Zombi_XZ_Civ_Trup2",
			"Zombi_XZ_Civ_Trup3",
			"Zombi_XZ_Civ_Trup4",
			"Zombi_XZ_Civ_Trup5",
			"Zombi_XZ_Loner_Zorya",
			"Zombi_XZ_Duty_Zorya",
			"Zombi_XZ_Freedom_Zorya",
			"Zombi_XZ_Monolith_Zorya",
			"Zombi_XZ_Novice1",
			"Zombi_XZ_Novice2",
			"Zombi_XZ_Novice3",
			"Zombi_XZ_Novice4",
			"Zombi_XZ_Novice5",
			"Zombi_XZ_Novice6",
			"Zombi_XZ_Novice7"
		};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Characters",
			"DZ_Characters_Zombies",
			"DZ_Data_Bliss",
			"DZ_AI_Bliss",
			"DZ_Animals"
		};
	};
};

class CfgMods
{
	class XZ_STALKER_InvENG_addon
	{
	    dir = "XZ_STALKER_InvENG_addon";
		picture = "";
	    action = "";
	    hideName = 1;
	    hidePicture = 1;
		name = "XZONE STALKER Inventory & English addon";
		credits = "";
	    author = "AlphaEye";
	    authorID = "";
	    version = "0.1";
	    extra = 0;
	    type = "mod";
    };
};

class CfgVehicles
{
	class Animal_UrsusArctos;
	class Mutant_XZ_PGigant_Base: Animal_UrsusArctos
	{
		displayName="Mutant Pseudogiant";
		descriptionShort="The hardest thing to do with this beast is to kill it: it is as tenacious as a tank. The most effective thing I can advise is to try shotgun blasts at point-blank range. The main thing to remember: the giant scatters everything that is not poured on two meters of concrete, no matter how much it weighed. So attack him from above - it's better that way - but make sure that your support is solid.";
	};
	class Mutant_XZ_PGigant: Mutant_XZ_PGigant_Base
	{
		displayName="Mutant Pseudogiant";
	};
	
	/*class Mutant_XZ_Himera_Base: Animal_UrsusArctos
	{
		displayName="Mutant Chimera";
		descriptionShort="Very dangerous predators. Nocturnal. They come up behind you in the dark and jump. If you know that a chimera is nearby, turn your head at three hundred and sixty and don't forget to cover your friends' backs.";
	};
	class Mutant_XZ_Himera1: Mutant_XZ_Himera_Base
	{
		displayName="Mutant Chimera";
	};
	class Mutant_XZ_Himera2: Mutant_XZ_Himera_Base
	{
		displayName="Mutant Chimera";
	};
	class Mutant_XZ_Himera3: Mutant_XZ_Himera_Base
	{
		displayName="Mutant Chimera";
	};
	class Mutant_XZ_Himera3_Super: Mutant_XZ_Himera_Base
	{
		displayName="Mutant Chimera";
	};
	*/
	class Animal_CanisLupus;
	class Mutant_XZ_Pse_Dog_Base: Animal_CanisLupus
	{
		displayName="Mutant Psy Dog";
		descriptionShort="Despite the name, pseudo-dogs are not descended from dogs, but from wolves. Wild animals that lived in the forests of the Zone at the time of the catastrophe became the ancestors of one of the most dangerous mutant species. Pseudo-dogs are as different from mutated dogs as wild wolves are from mongrels. These creatures are territorial and fiercely attack anyone who invades their domain. The pseudo-dog's lightning-fast reactions, incredible mobility, and sharp teeth make it a very serious opponent that even a large mutant or well-armed stalker can't resist.";
	};
	class Mutant_XZ_Pse_Dog1: Mutant_XZ_Pse_Dog_Base
	{
		displayName="Mutant Psy Dog";
	};
	class Mutant_XZ_Pse_Dog2: Mutant_XZ_Pse_Dog_Base
	{
		displayName="Mutant Psy Dog";
	};
	
	class Mutant_XZ_Boar_Base: Animal_CanisLupus
	{
		displayName="Mutant Boar";
		descriptionShort="A large beast, reaching one and a half meters in withers. This animal surpasses its relatives outside the Zone with its survivability and aggressiveness, and is not inferior to most mutants. Mutagenic processes caused by the effects of radiation and anomalies have significantly affected the appearance of these mammals: in some places the latter have gone bald, and in some places, on the contrary, have grown very long, stiff hair. Their hooves changed their shape and became sharper, acquiring some resemblance to claws; their pupils became discolored, pigmentation spots and deep wrinkles appeared on the bald head. Zona boars have a good tolerance for radiation, which allows them to stay in heavily contaminated areas for long periods of time. These animals usually attack from a run, trying to rip open the victim's belly with their fangs or knock him down.";
	};
	class Mutant_XZ_Boar1: Mutant_XZ_Boar_Base
	{
		displayName="Mutant Boar";
	};
	class Mutant_XZ_Boar2: Mutant_XZ_Boar_Base
	{
		displayName="Mutant Boar";
	};
	
	class Mutant_XZ_Cat_Base: Animal_CanisLupus
	{
		displayName="Mutant Cat";
		descriptionShort="Bayun (by analogy with the bayun cat from fairy tales) - a creature of the cat family, which imitates any voices and thus lures victims or scares away pursuers. Upon seeing a human, will not necessarily attack - can simply lure away into a thicket and scamper away. Mutated from a common cat.";
	};
	class Mutant_XZ_Cat_Bayn1: Mutant_XZ_Cat_Base
	{
		displayName="Mutant Cat";
	};
	class Mutant_XZ_Cat_Bayn2: Mutant_XZ_Cat_Base
	{
		displayName="Mutant Cat";
	};
	class Mutant_XZ_Cat_Bayn3: Mutant_XZ_Cat_Base
	{
		displayName="Mutant Cat";
	};
	
	class Mutant_XZ_Dog_Base: Animal_CanisLupus
	{
		displayName="Mutant Dog";
		descriptionShort="Since the first catastrophe, several generations had passed in the canine family, and in each of them the influence of the Zone was increasingly observed. Mutations and evolutionary adaptation led to the strengthening of previously weakly expressed canine abilities, and often to the detriment of the usual ones. The main physiological changes affected eyesight - it turned out to be almost useless after the rapid increase in senses: for example, blind puppies survived in the Zone no worse, if not better than their sighted brethren. As a result, ordinary dogs soon degenerated here completely, giving way to a new species - blind dogs. These animals perfectly recognize and avoid anomalies, radiation and other invisible dangers that swarm the Zone. Like their ancestors, blind dogs hunt in packs; encountering a large group of these creatures means serious danger even for a well-armed stalker.";
	};
	class Mutant_XZ_Dog_Red: Mutant_XZ_Dog_Base
	{
		displayName="Mutant Dog";
	};
	class Mutant_XZ_Dog_White: Mutant_XZ_Dog_Base
	{
		displayName="Mutant Dog";
	};
	class Mutant_XZ_Dog_Fur: Mutant_XZ_Dog_Base
	{
		displayName="Mutant Dog";
	};
	class Mutant_XZ_Dog_Brown: Mutant_XZ_Dog_Base
	{
		displayName="Mutant Dog";
	};
	
	class Mutant_XZ_Tushkano_Base: Animal_CanisLupus
	{
		displayName="Mutant Rodent";
		descriptionShort="The hunter's terror! One of the stupidest mistakes you can make in life is to underestimate animals because of their small size. Tushkans are insanely fast and agile and always move in large packs. When they start pulling you apart one little piece at a time, you'll have an epiphany! The main thing is that it's not too late. You see, the most unpleasant thing here? It's very hard to hit a tushkan. That's why I advise all stalkers in such a case always carry a shotgun with a supply of ammunition.";
	};
	class Mutant_XZ_Tushkano1: Mutant_XZ_Tushkano_Base
	{
		displayName="Mutant Rodent";
	};
	class Mutant_XZ_Tushkano2: Mutant_XZ_Tushkano_Base
	{
		displayName="Mutant Rodent";
	};
	class Mutant_XZ_Tushkano3: Mutant_XZ_Tushkano_Base
	{
		displayName="Mutant Rodent";
	};
	
	class Mutant_XZ_Fresh_Base: Animal_CanisLupus
	{
		displayName="Mutant Pig";
		descriptionShort="Domestic pigs in the Zone, like many other living organisms, have undergone severe mutation. As genes controlling metabolic processes were affected, the animal's phenotype changed dramatically. Mutated pig, which stalkers call “flesh” - one of the most obvious examples of the Zone's abuse of nature. These creatures have formed a scaly-bone protective cover, significantly increased the body's ability to regenerate, and the nervous system has become more complex. Like an ordinary pig, the “flesh” is omnivorous, so, being hungry, it may well attack a stalker.";
	};
	class Mutant_XZ_Fresh1: Mutant_XZ_Fresh_Base
	{
		displayName="Mutant Pig";
	};
	class Mutant_XZ_Fresh2: Mutant_XZ_Fresh_Base
	{
		displayName="Mutant Pig";
	};
	class Mutant_XZ_Fresh3: Mutant_XZ_Fresh_Base
	{
		displayName="Mutant Pig";
	};
	
	class ZombieMaleBase;
	class Mutant_XZ_Burer_Base: ZombieMaleBase
	{
		displayName="Mutant Burer";
		descriptionShort="A humanoid-type creature with hypertrophied facial features, wearing a black hooded cloak. It is small in stature and moves rather quickly, but clumsily. Afraid of bright light, so it lives only in dark and gloomy dungeons and caves. Eats corpses.";
		class Cargo
		{
			itemsCargoSize[]={5,7};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
	};
	class Mutant_XZ_Burer1: Mutant_XZ_Burer_Base
	{
		displayName="Mutant Burer";
	};
	class Mutant_XZ_Burer2: Mutant_XZ_Burer_Base
	{
		displayName="Mutant Burer";
	};
	
	class ZmbM_HermitSkinny_Base;
	class Mutant_XZ_Poltergeist_Base: ZmbM_HermitSkinny_Base
	{
		displayName="Mutant Poltergeist";
		descriptionShort="Truly supernatural invisible creatures, found only in the depths of the Zone, dwell, as a rule, inside dilapidated buildings. About the origin of nothing is not reliably known; there is a legend that they are the spirits of stalkers who fell under a powerful release. The mechanism of manifestation of these invisible do correspond to the legends of poltergeist (whence the name) and is characterized by variety: from periodic howling and laughter to appear out of nowhere dangerous fireballs. Unfortunately, all information about this phenomenon is drawn from vague and rather contradictory stories, the veracity of which is questionable.";
		class Cargo
		{
			itemsCargoSize[]={3,4};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
	};
	class Mutant_XZ_Poltergeist: Mutant_XZ_Poltergeist_Base
	{
		displayName="Mutant Poltergeist";
	};
	
	class Mutant_XZ_Krovosos_Base: ZmbM_HermitSkinny_Base
	{
		displayName="Mutant Bloodsucker";
		descriptionShort="A semi-legendary monster - Stalkers describe it as a tall, slouching humanoid with a multitude of tentacles where its mouth used to be. According to them, with the help of tentacles this creature feeds: by digging them into the neck of a living victim, it paralyzes its prey and sucks its blood; after such a procedure, the person is left with only a dried, mummy-like shell. The most amazing thing about the bloodsucker is its ability to become invisible. Apparently, these creatures are responsible for the deaths of a large number of stalkers. Few of the eyewitnesses survived - and judging by the stories of these lucky ones, the bloodsuckers prefer damp places like swamps and dungeons.";
		class Cargo
		{
			itemsCargoSize[]={6,8};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
	};
	class Mutant_XZ_Krovosos1: Mutant_XZ_Krovosos_Base
	{
		displayName="Mutant Bloodsucker";
	};
	class Mutant_XZ_Krovosos2: Mutant_XZ_Krovosos_Base
	{
		displayName="Mutant Bloodsucker";
	};
	class Mutant_XZ_Krovosos3: Mutant_XZ_Krovosos_Base
	{
		displayName="Mutant Bloodsucker";
	};
	
	class Mutant_XZ_Izlom_Base: ZmbM_HermitSkinny_Base
	{
		displayName="Mutant Izlom";
		descriptionShort="Mutant, descended from a human (can be understood by the structure of the lower limbs, which have not undergone mutation, as well as by clothing). Also known as 'kinks'.";
		class Cargo
		{
			itemsCargoSize[]={3,4};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
	};
	class Mutant_XZ_Izlom1: Mutant_XZ_Izlom_Base
	{
		displayName="Mutant Izlom";
	};
	class Mutant_XZ_Izlom2: Mutant_XZ_Izlom_Base
	{
		displayName="Mutant Izlom";
	};
	class Mutant_XZ_Izlom3: Mutant_XZ_Izlom_Base
	{
		displayName="Mutant Izlom";
	};
	
	class Mutant_XZ_Snork_Base: ZmbM_HermitSkinny_Base
	{
		displayName="Mutant Snork";
		descriptionShort="These creatures appear to have once been human, though it's hard to imagine what conditions could drive a human to such a state. Snorks are crazy, animalistic creatures that are not much different from the predatory monsters of the Zone. They move on four limbs, bouncing above the ground and constantly sniffing it to catch the scent of their prey. They hunt cautiously and calculatingly, sneaking up on stalkers like predatory animals. Lightning-fast reflexes and hypertrophied muscles allow snorkels to make long, precise jumps and tear their prey to shreds in seconds. Some of them still have parts of army uniforms or separate parts of equipment, which suggests that they are missing military or stalkers.";
		class Cargo
		{
			itemsCargoSize[]={4,5};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
	};
	class Mutant_XZ_Snork1: Mutant_XZ_Snork_Base
	{
		displayName="Mutant Snork";
	};
	class Mutant_XZ_Snork2: Mutant_XZ_Snork_Base
	{
		displayName="Mutant Snork";
	};
	
	class Zombi_XZ_Civilian_Base: ZmbM_HermitSkinny_Base
	{
		displayName="Mutant Civilian";
		descriptionShort="Those who have been exposed to long-term radiation from the Yantar or some other sectors. Careless stalkers quickly go crazy, turning into wandering half-corpses. There are many of them wandering around the Zone, some even reach the perimeter. One way or another, it is already impossible to help them: the process of personality destruction is irreversible. Although zombified stalkers can still use their weapons, they are quite stupid. When you meet them, you can hear them muttering fragments of phrases under their breath - which, however, are completely devoid of meaning. Over time, zombified stalkers completely lose all their previous skills and turn into zombies. As a rule, they are very aggressive and pose a serious threat in significant numbers.";
		class Cargo
		{
			itemsCargoSize[]={3,4};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
	};
	class Zombi_XZ_Civ_Trup1: Zombi_XZ_Civilian_Base
	{
		displayName="Mutant Civilian";
	};
	class Zombi_XZ_Civ_Trup2: Zombi_XZ_Civilian_Base
	{
		displayName="Mutant Civilian";
	};
	class Zombi_XZ_Civ_Trup3: Zombi_XZ_Civilian_Base
	{
		displayName="Mutant Civilian";
	};
	class Zombi_XZ_Civ_Trup4: Zombi_XZ_Civilian_Base
	{
		displayName="Mutant Civilian";
	};
	class Zombi_XZ_Civ_Trup5: Zombi_XZ_Civilian_Base
	{
		displayName="Mutant Civilian";
	};
	
	class Zombi_XZ_Loner_Zorya_Base: ZmbM_HermitSkinny_Base
	{
		displayName="Mutant Zarya Stalker";
		descriptionShort="Those who have been exposed to long-term radiation from the Yantar or some other sectors. Careless stalkers quickly go crazy, turning into wandering half-corpses. There are many of them wandering around the Zone, some even reach the perimeter. One way or another, it is already impossible to help them: the process of personality destruction is irreversible. Although zombified stalkers can still use their weapons, they are quite stupid. When you meet them, you can hear them muttering fragments of phrases under their breath - which, however, are completely devoid of meaning. Over time, zombified stalkers completely lose all their previous skills and turn into zombies. As a rule, they are very aggressive and pose a serious threat in significant numbers.";
		attachments[]=
		{
			"Back"
		};
		class InventoryEquipment
		{
			playerSlots[]=
			{
				"Slot_Back"
			};
		};
		class Cargo
		{
			itemsCargoSize[]={5,7};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
	};
	class Zombi_XZ_Loner_Zorya: Zombi_XZ_Loner_Zorya_Base
	{
		displayName="Mutant Zarya Stalker";
	};
	class Zombi_XZ_Duty_Zorya: Zombi_XZ_Loner_Zorya_Base
	{
		displayName="Mutant Zarya Stalker";
	};
	class Zombi_XZ_Freedom_Zorya: Zombi_XZ_Loner_Zorya_Base
	{
		displayName="Mutant Zarya Stalker";
	};
	class Zombi_XZ_Monolith_Zorya: Zombi_XZ_Loner_Zorya_Base
	{
		displayName="Mutant Zarya Stalker";
	};
	
	class Zombi_XZ_Novice_Base: ZmbM_HermitSkinny_Base
	{
		displayName="Mutant Stalker";
		descriptionShort="Those who have been exposed to long-term radiation from the Yantar or some other sectors. Careless stalkers quickly go crazy, turning into wandering half-corpses. There are many of them wandering around the Zone, some even reach the perimeter. One way or another, it is already impossible to help them: the process of personality destruction is irreversible. Although zombified stalkers can still use their weapons, they are quite stupid. When you meet them, you can hear them muttering fragments of phrases under their breath - which, however, are completely devoid of meaning. Over time, zombified stalkers completely lose all their previous skills and turn into zombies. As a rule, they are very aggressive and pose a serious threat in significant numbers.";
		attachments[]=
		{
			"Back"
		};
		class InventoryEquipment
		{
			playerSlots[]=
			{
				"Slot_Back"
			};
		};
		class Cargo
		{
			itemsCargoSize[]={4,5};
			allowOwnedCargoManipulation=1;
			openable=0;
		};
	};
	class Zombi_XZ_Novice1: Zombi_XZ_Novice_Base
	{
		displayName="Mutant Stalker";
	};
	class Zombi_XZ_Novice2: Zombi_XZ_Novice_Base
	{
		displayName="Mutant Stalker";
	};
	class Zombi_XZ_Novice3: Zombi_XZ_Novice_Base
	{
		displayName="Mutant Stalker";
	};
	class Zombi_XZ_Novice4: Zombi_XZ_Novice_Base
	{
		displayName="Mutant Stalker";
	};
	class Zombi_XZ_Novice5: Zombi_XZ_Novice_Base
	{
		displayName="Mutant Stalker";
	};
	class Zombi_XZ_Novice6: Zombi_XZ_Novice_Base
	{
		displayName="Mutant Stalker";
	};
	class Zombi_XZ_Novice7: Zombi_XZ_Novice_Base
	{
		displayName="Mutant Stalker";
	};
};