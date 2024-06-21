## DEER ISLE Shark Spawns for DayZ Shark using Spawner Bubaku
* _Make sure you have @sharkspawner & @spawnerbubaku in server side only, then @dayzshark mod is client level_
* Use the json provided in your profiles folder for spawner bubaku & delete the sharkspawner folder if it exists in profiles folder
* **IN THE JSON**
  * **There are 21 shark spawn locations for Deer Isle** shown in map pic provided _(rectangles with a center dot)_
  * The rectangles are the zones that trigger a shark when a player enters them - no radius is needed for the rectangles
  * Sharks are set to spawn at any of the corners or center dots with a potential spawn radius of 1/2 of the zone size from the randomly chosen dot
  * The larger the zone, the less lethal the encounter as the shark can spawn further away
  * Locations were picked based on swim off points for players and some Deer Isle Lore
  * Y values are based on 75m depth in water for divers to spawn the sharks, and 25m in the air so any boats or low flying helis can trigger them as well
  * Each location has a 30min cool down of its own that doesn't effect the other locations  _(default triggerdelay)_
  * ONLY 1 shark per area _(default bubaknum)_
  * All sharks set to spawn ANY time of day _(default workinghours)_
  * Notifications are set to blank