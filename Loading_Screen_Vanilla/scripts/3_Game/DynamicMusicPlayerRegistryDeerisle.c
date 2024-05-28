class DynamicMusicPlayerRegistryDeerisle : DynamicMusicPlayerRegistry
{
    void DynamicMusicPlayerRegistryDeerisle()
    {
        m_WorldName = "deerisle";
    }

    override void RegisterTracksMenu()
    {
        m_TracksMenu = new array<ref DynamicMusicTrackData>();

        RegisterTrackMenu("YourPBOName_Music_1_SoundSet");	//*** Change "YourPBOName" for custom music in config.cpp or use BI's "Menu_Music_Soundset"
    }

    override void RegisterTracksTime()
    {
        m_TracksTime = new array<ref DynamicMusicTrackData>();
    }

    override void RegisterTracksLocationStatic()
    {
        m_TracksLocationStatic = new array<ref DynamicMusicTrackData>();
        m_TracksLocationStaticPrioritized = new array<ref DynamicMusicTrackData>();
    }

    override void RegisterTracksLocationDynamic()
    {
        m_TracksLocationDynamic = new array<ref DynamicMusicTrackData>();
    }
}