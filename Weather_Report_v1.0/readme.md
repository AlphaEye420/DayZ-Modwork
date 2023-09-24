# WEATHER REPORT by AlphaEye
**CREDIT TO affenb3rt FOR [PRESET WEATHER](https://steamcommunity.com/sharedfiles/filedetails/?id=2844108808)** ~ *this mod is 100% of PresetWeather mod with added code*

### What does this mod do?
* The **weather.json** file should automatically appear in your **missions folder** when you start the server after installing the mod
* The Mod changes the weather based on an array of weather conditions you set in the json, which are randomly picked at set times
* These parameters determine ranges for fog, clouds, rain, wind, duration of the condition, & time it takes to fully transition
* PRINTS the name & duration *(irl minutes)* of the of a newly chosen condition in your server's global chat ingame
* PRINTS specific details of a newly chosen condition in your server's script_.log found in profiles folder

**JSON NOTES:**
* **Transition & duration values are in minutes**
* **Fog, clouds, rain, wind range limits are 0.0 to 1.0**
* **Storm is a 1 0 boolean on/off** _(on = lightning)_
* **Thunder_Timeout is the minimum seconds between lightning strikes** _(picks a random time >= timeout)_
* Edit weather.json in the missions folder to suit, just remember to backup your old ones in case something doesn't work
* The original weather.json file is provided in the extras folder should you want to go back to or compare to its settings
* The "name" field in the json is exactly what you see in global chat for forecast text, _caps are suggested for consistency, but not required_
* There are several weather conditions in the provided json with the same name; This lowers the chance of the rain conditions firing
* To have more rain, you can delete a few of the duplicates or add rain conditions to the json
* To have less rain, you can delete some of the rain conditions or duplicate the clear conditions in the json

## How to Install Mod
!! **THIS IS A SERVER SIDE ONLY MOD** !!
* Download the zip, unzip and copy the @WeatherReport folder into your server root directory next to your others.  
* Copy the key from the @WeatherReport/keys folder into your server keys folder 
* **!! USE _at least_ -servermod=@WeatherReport; IN YOUR START.BAT !!** (_If you were to put it after -mod= then your clients will not be able to login to the server_) ~ Note: GTX & other server hosts may have a different place for you to add `@WeatherReport;` to the server side only section of an entry form
* **YOU MUST TURN THE WEATHER OFF** in "cfgweather.xml" inside missions folder ~ set to: `<weather reset="1" enable="0">`
* Start Server, it will create the weather.json file for you to edit if you want for the next restart, but editing isn't necessary
* To ensure it is working, check the beginning of the script_.log _(in profiles folder)_ to see which condition and settings it picked

### You **cannot turn off** the global chat notifications
* If you would like these weather patterns without spamming chat, then take the weather.json file provided in extras folder an use it with:
* [@PresetWeather in Steam Workshop](https://steamcommunity.com/sharedfiles/filedetails/?id=2844108808)
