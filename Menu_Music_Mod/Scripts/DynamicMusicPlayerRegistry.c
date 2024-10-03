
modded class DynamicMusicPlayerRegistry
{
    override void RegisterTracksMenu()
    {
        m_TracksMenu = new array<ref DynamicMusicTrackData>();
		
		// Don't forget to change YourPBOname! - Stack as many as you want		
        RegisterTrackMenu("YourPBOname_Music_1_SoundSet");		
    } 
}