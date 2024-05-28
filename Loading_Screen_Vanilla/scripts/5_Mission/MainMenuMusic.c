// BROKEN AS OF DAYZ 1.25 !!
modded class MissionMainMenu  // this scripts loads your music
{
	override void PlayMusic()
	{
		ref SoundParams soundParams			= new SoundParams( "YourPBOName_Music_1_SoundSet" ); //********** change "YourPBOName"
		ref SoundObjectBuilder soundBuilder	= new SoundObjectBuilder( soundParams );
		ref SoundObject soundObject			= soundBuilder.BuildSoundObject();
		soundObject.SetKind( WaveKind.WAVEMUSIC );
		m_MenuMusic = GetGame().GetSoundScene().Play2D(soundObject, soundBuilder);
		m_MenuMusic.Loop( true );
		m_MenuMusic.Play();
	}
}

/*
    TO HAVE A RANDOM FILE PLAY:
	1. ADD YOUR OGG FILES TO DATA FOLDER
	2. REPLACE THE "PlayMusic" FUNCION ABOVE & edit to match the number music files you have in data folder
	- BELOW IS SETUP FOR 3 OGG FILES IN DATA FOLDER
	
	override void PlayMusic()
	{
		int i = Math.RandomInt(1,3);
		
		if (i == 1) {ref SoundParams soundParams	= new SoundParams( "YourPBOName_Music_1_SoundSet" )};
		if (i == 2) {ref SoundParams soundParams	= new SoundParams( "YourPBOName_Music_2_SoundSet" )};
		if (i == 3) {ref SoundParams soundParams	= new SoundParams( "YourPBOName_Music_3_SoundSet" )};
		
		ref SoundObjectBuilder soundBuilder	= new SoundObjectBuilder( soundParams );
		ref SoundObject soundObject			= soundBuilder.BuildSoundObject();
		soundObject.SetKind( WaveKind.WAVEMUSIC );
		m_MenuMusic = GetGame().GetSoundScene().Play2D(soundObject, soundBuilder);
		m_MenuMusic.Loop( true );
		m_MenuMusic.Play();
	}
	
	3. ADD SHADERS & ADD SOUND SETS
	- BELOW IS SETUP FOR 3 OGG FILES IN DATA FOLDER
	
	class CfgSoundShaders
	{
		class YourPBOName_Music_1_SoundShader
		{
			samples[] = {{"YourPBOName\data\YourSONGName",1}};
			volume=0.786;
		};
		class YourPBOName_Music_2_SoundShader
		{
			samples[] = {{"YourPBOName\data\YourSONGName",1}};
			volume=0.786;
		};
		class YourPBOName_Music_3_SoundShader
		{
			samples[] = {{"YourPBOName\data\YourSONGName",1}};
			volume=0.786;
		};
	};

	class CfgSoundSets
	{	
		class YourPBOName_Music_1_SoundSet
		{
			soundShaders[]=
			{
				"YourPBOName_Music_1_SoundShader" 
			};
			volumeFactor=1;
			frequencyFactor=1;
			spatial=0;
		};
		class YourPBOName_Music_2_SoundSet
		{
			soundShaders[]=
			{
				"YourPBOName_Music_2_SoundShader" 
			};
			volumeFactor=1;
			frequencyFactor=1;
			spatial=0;
		};
		class YourPBOName_Music_3_SoundSet
		{
			soundShaders[]=
			{
				"YourPBOName_Music_3_SoundShader" 
			};
			volumeFactor=1;
			frequencyFactor=1;
			spatial=0;
		};
	};
	
*/	
