class DynamicMusicPlayerRegistryDeerisle : DynamicMusicPlayerRegistry
{
	//*** Change "YourPBOName"  (AND Music_x) !!!  
	//	Make sure you use the soundset names you made in config.cpp, or comment out anything and DayZ should use it's music
	
    void DynamicMusicPlayerRegistryDeerisle()
    {
        m_WorldName = "deerisle";
    }

    override void RegisterTracksMenu()
    {
		// your main menu music
        m_TracksMenu = new array<ref DynamicMusicTrackData>();

        RegisterTrackMenu("YourPBOName_Music_1_SoundSet");
    }

    override void RegisterTracksTime()
    {
        m_TracksTime = new array<ref DynamicMusicTrackData>();
	    
		//DAY
		//RegisterTrackTime("YourPBOName_Music_1_SoundSet", DynamicMusicPlayerTimeOfDay.DAY);
		
		//NIGHT
		//RegisterTrackTime("YourPBOName_Music_2_SoundSet", DynamicMusicPlayerTimeOfDay.NIGHT);
    }
		
	override protected void RegisterTracksLocationStatic()
	{
        m_TracksLocationStatic = new array<ref DynamicMusicTrackData>();
        m_TracksLocationStaticPrioritized = new array<ref DynamicMusicTrackData>();  // This section removes location based music
	}

    override void RegisterTracksLocationDynamic()
    {
        m_TracksLocationDynamic = new array<ref DynamicMusicTrackData>();
		// Contaminated Areas Music (only needed if you want your own music to override otherwise comment out the Registers below)
		RegisterTrackLocationDynamic("YourPBOName_Music_3_SoundSet", DynamicMusicLocationTypes.CONTAMINATED_ZONE, DynamicMusicPlayerTimeOfDay.ANY);
    }
}
