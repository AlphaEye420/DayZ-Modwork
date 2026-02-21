// Edit the missions folder files to add a dynamic pirate ship event to your server
// You can place whatever you want - Default is seachest with random chance goods

// TYPES.XML  
  <type name="ADM_Wreck_PirateShip">
    <nominal>0</nominal>
    <lifetime>5600</lifetime>
    <restock>600</restock>
    <min>0</min>
    <quantmin>-1</quantmin>
    <quantmax>-1</quantmax>
    <cost>100</cost>
    <flags count_in_cargo="0" count_in_hoarder="0" count_in_map="1" count_in_player="0" crafted="0" deloot="0" />
  </type>
  // (SET SEACHEST DELOOT TO 1 !)
  <type name="SeaChest">
    <nominal>20</nominal>
    <lifetime>3888000</lifetime>
    <restock>0</restock>
    <min>10</min>
    <quantmin>-1</quantmin>
    <quantmax>-1</quantmax>
    <cost>100</cost>
    <flags count_in_cargo="0" count_in_hoarder="0" count_in_map="1" count_in_player="0" crafted="0" deloot="1" />
    <category name="tools" />
    <usage name="Coast" />
  </type>

// CFGEVENTSPAWNS.XML  (add more !)
	<event name="StaticPirateWreck">
		<pos x="3217.686768" z="11402.410156" y="0.763912" a="180" />
		<pos x="6497" z="942" y="0.520128" a="230" />
	</event>	

// EVENTS.XML (set to no more than you have pos's above)
	<event name="StaticPirateWreck">
		<nominal>2</nominal>
		<min>1</min>
		<max>2</max>
		<lifetime>2500</lifetime>
		<restock>0</restock>
		<saferadius>500</saferadius>
		<distanceradius>500</distanceradius>
		<cleanupradius>200</cleanupradius>
        <secondary>InfectedArmyHard</secondary>
		<flags deletable="1" init_random="0" remove_damaged="0" />
		<position>fixed</position>
		<limit>child</limit>
		<active>1</active>
		<children>
		<child lootmax="3" lootmin="1" max="1" min="1" type="ADM_Wreck_PirateShip" />
		</children>
	</event>
	
// MAPGROUPPROTO.XML
		<group name="ADM_Wreck_PirateShip" lootmax="3">
				<dispatch dechance="0.6667">
						<proxy type="Seachest" pos="14.9 6.128350000 0" rpy="0.000000 90.000000 0.000000" dechance="0.6667" />
				</dispatch>
				<dispatch dechance="0.6667">
						<proxy type="Seachest" pos="7.5 3.25115 0" rpy="0.000000 90.000000 0.000000" dechance="0.6667" />
				</dispatch>
				<dispatch dechance="0.6667">
						<proxy type="Seachest" pos="-13.25 3.52294 0" rpy="0.000000 -90.000000 0.000000" dechance="0.6667" />
				</dispatch>
		</group>
		
// CFGRANDOMPRESETS.XML  (suggested change to seachest)
	<type name="SeaChest">
		<cargo preset="mixVillage" />
		<cargo preset="mixHunter" />
		<cargo preset="mixArmy" />
		<cargo preset="ammoArmyJMC" />
		<cargo preset="ammoArmyJMC" />
		<cargo preset="mixArmyJMC" />
		<cargo preset="mixArmyJMC" />
		<cargo preset="WinterSoldier" />
		<cargo preset="STAG_Clothing" />
		<cargo preset="STAG_Vests" />
		<cargo preset="STAG_Bags" />
		<cargo preset="foodVillage" />
		<cargo preset="foodHermit" />
		<cargo preset="foodCity" />
		<cargo preset="foodArmy" />
		<cargo preset="ammoCivil" />
		<cargo preset="ammoPolice" />
		<cargo preset="ammoArmy" />
		<cargo preset="toolsHermit" />
		<cargo preset="toolsVillage" />
		<cargo preset="toolsCity" />
		<cargo preset="toolsMedic" />
		<cargo preset="toolsPolice" />
		<cargo preset="toolsHunter" />
		<cargo preset="toolsIndustrial" />
		<hoarder />

	</type>
