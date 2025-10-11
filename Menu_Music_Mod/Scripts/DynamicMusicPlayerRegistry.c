class DynamicMusicPlayerRegistryDeerisle : DynamicMusicPlayerRegistry
{
    void DynamicMusicPlayerRegistryDeerisle()
    {
        m_WorldName = "deerisle";  // must match your map
    }

    override void RegisterTracksMenu()
    {
        m_TracksMenu = new array<ref DynamicMusicTrackData>();
        RegisterTrackMenu("YourPBOName_Music_1_SoundSet");  //*** This name MUST match to config.cpp "class CfgSoundSets" entry (change yourPBOname)
    }
	
    override void RegisterTracksTime()
    {
        m_TracksTime = new array<ref DynamicMusicTrackData>(); //  This section removes day/night music from dayz.  
		// Remove this entire override if you wish to keep default time based music from DayZ
    }		
	override protected void RegisterTracksLocationStatic()
	{
        m_TracksLocationStatic = new array<ref DynamicMusicTrackData>();
        m_TracksLocationStaticPrioritized = new array<ref DynamicMusicTrackData>();
		super.RegisterTracksLocationStatic();  //  This keeps the current setup for Music per location, then you can add more locations here.  Remove this line of code to ensure no location music plays.
	}
    override void RegisterTracksLocationDynamic()
    {
        m_TracksLocationDynamic = new array<ref DynamicMusicTrackData>();
		RegisterTrackLocationDynamic("YourPBOName_Music_2_SoundSet", DynamicMusicLocationTypes.CONTAMINATED_ZONE, DynamicMusicPlayerTimeOfDay.ANY); //Remove only this line to have no toxic zone music (change yourPBOname if keeping)
		// Remove this entire override to keep default toxic zone music
    }
}
