class PresetWeatherPlugin extends PluginBase
{
    static const string PRESET_FILE_NAME = "$mission:weather.json";
    static const string PRESET_TEMPLATE_NAME = "WeatherReport/data/weather.json";
    static const string PERSIST_FILE_NAME = "$mission:storage_%1/presetweatherV2.bin";

    protected float m_PresetWeatherTime = 0.0;
    protected float m_NextChangeTime = 0.0;

    protected bool m_Started = false;
    protected bool m_InitialChange = true;
    protected int m_InstanceID = -1;

    protected ref array<ref WeatherPreset> m_Presets;
    protected ref WeatherPreset m_CurrentWeather;
			
	static void SendChatMessage(string message, int report)
	{
		ref array<Man> players = new array<Man>;
		GetGame().GetPlayers(players);
		foreach(auto player : players)
		{
			if (report == 1)
			{
				Param1<string> m_MessageParam = new Param1<string>(message);
				GetGame().RPCSingleParam(player, ERPCs.RPC_USER_ACTION_MESSAGE, m_MessageParam, true, player.GetIdentity());
			}
			if (report == 2)
			{
				NotificationSystem.SendNotificationToPlayerIdentityExtended( player.GetIdentity(), 10.0, "Weather Alert!", message, "");
			}
		}
	}
		
    protected void Start()
    {
        Print( "WeatherReport: Started" );
        m_Started = true;
        UpdateWeather();
    }

    protected void Stop()
    {
        Print( "WeatherReport: Stopped" );
        m_Started = false;
    }

	// SEND SETTINGS
    protected void SetOvercast( Weather weather, float forecast, float time, float minDuration )
    {
        Print( "WeatherReport: Overcast forecast:" + forecast + " timeToChange:" + time + " duration:" + minDuration );
        weather.GetOvercast().Set( forecast, time, minDuration );
    }

    protected void SetFog( Weather weather, float forecast, float time, float minDuration )
    {
        Print( "WeatherReport: Fog forecast:" + forecast + " timeToChange:" + time + " duration:" + minDuration );
        weather.GetFog().Set( forecast, time, minDuration );
    }

    protected void SetFogBias( Weather weather, float forecast, float time, float minDuration )
    {
        Print( "WeatherReport: Fog bias:" + forecast + " timeToChange:" + time + " duration:" + minDuration);
		weather.SetDynVolFogHeightBias(forecast, minDuration);	
    }

    protected void SetFogHeight( Weather weather, float forecast, float time, float minDuration )
    {
        Print( "WeatherReport: Fog height:" + forecast + " timeToChange:" + time + " duration:" + minDuration);
		weather.SetDynVolFogHeightDensity(forecast, minDuration);
    }

    protected void SetFogDistance( Weather weather, float forecast, float time, float minDuration )
    {
        Print( "WeatherReport: Fog distance:" + forecast + " timeToChange:" + time + " duration:" + minDuration);
		weather.SetDynVolFogDistanceDensity(forecast, minDuration);
    }

    protected void SetWindSpeed( Weather weather, float forecast, float time, float minDuration )
    {
		float halve = time / 2;
		float addto = minDuration + halve;
        Print( "WeatherReport: Wind Speed forecast:" + forecast + " timeToChange:" + halve + " duration:" +  addto);
        weather.GetWindMagnitude().Set( 20 * forecast, halve, addto );
    }

    protected void SetWindDirection( Weather weather, float forecast, float time, float minDuration )
    {
		float pi = (forecast - 0.5) * 3.14 * 2;
		float degree = 180*(pi/3.14) + 180;
		float halve = time / 2;
		float addto = minDuration + halve;
        Print( "WeatherReport: Direction forecast:" + forecast + " degree:" + Math.Round(degree) + " time:" + halve + " dur:" + addto );
        weather.GetWindDirection().Set( pi, halve, addto);
    }

    protected void SetRain( Weather weather, float forecast, float time, float minDuration )
    {
		if (forecast > 0)
		{
			float sp = ( minDuration - time ) * 0.4;
			float md = ( minDuration - time ) * 0.6;
			Print( "WeatherReport: Rain forecast:" + forecast + " Delay:" + time + " timeToChange:" + sp + " duration:" + md );
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLaterByName( weather.GetRain(), "Set", time * 1000, false, new Param3<float, float, float>( forecast, sp, md ) );
		}
		else
		{
			float quarter = time * 0.25;
			float addto = minDuration + (quarter * 3);
			Print( "WeatherReport: Rain forecast:" + forecast + " timeToChange:" + quarter + " duration:" + addto );
			weather.GetRain().Set( 0, quarter, addto);
		}
    }

    protected void SetSnowfall( Weather weather, float forecast, float time, float minDuration )
    {
		if (forecast > 0)
		{
			float sp = ( minDuration - time ) * 0.4;
			float md = ( minDuration - time ) * 0.6;
			Print( "WeatherReport: Snowfall forecast:" + forecast + " Delay:" + time + " timeToChange:" + sp + " duration:" + md );
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLaterByName( weather.GetSnowfall(), "Set", time * 1000, 	false, new Param3<float, float, float>( forecast, sp, md ) );
		}
		else
		{
			float quarter = time * 0.25;
			float addto = minDuration + (quarter * 3);
			Print( "WeatherReport: Snowfall forecast:" + forecast + " timeToChange:" + quarter + " duration:" + addto );
			weather.GetSnowfall().Set( 0, quarter, addto);
		}
    }

	// PRESET APPLICATION
    protected float ApplyPreset( Weather weather, WeatherPreset preset, bool initialChange )
    {
        weather.GetOvercast().SetLimits( 0.0, 1.0 );
        weather.GetOvercast().SetForecastChangeLimits( 0.0, 1.0 );
        weather.GetOvercast().SetForecastTimeLimits( 0.0, 99999.0 );
        weather.GetFog().SetLimits( 0.0, 1.0 );
        weather.GetFog().SetForecastChangeLimits( 0.0, 1.0 );
        weather.GetFog().SetForecastTimeLimits( 0.0, 99999.0 );
        weather.GetRain().SetLimits( 0.0, 1.0 );
        weather.GetRain().SetForecastChangeLimits( 0.0, 1.0 );
        weather.GetRain().SetForecastTimeLimits( 0.0, 99999.0 );
        weather.GetSnowfall().SetLimits( 0.0, 1.0 );
        weather.GetSnowfall().SetForecastChangeLimits( 0.0, 1.0 );
        weather.GetSnowfall().SetForecastTimeLimits( 0.0, 99999.0 );
        weather.GetWindDirection().SetLimits( -3.14, 3.14 );
        weather.GetWindDirection().SetForecastChangeLimits( -3.14, 3.14 );
        weather.GetWindDirection().SetForecastTimeLimits( 0.0, 99999.0 );
        weather.GetWindMagnitude().SetLimits( 0.0, 20.0 );
        weather.GetWindMagnitude().SetForecastChangeLimits( 0.0, 20.0 );
        weather.GetWindMagnitude().SetForecastTimeLimits( 0.0, 99999.0 );

        Print( "WeatherReport: Apply:" + preset.name );
        float duration = Math.RandomFloatInclusive( preset.duration_min, preset.duration_max ) * 60;	
        float speedOfChange = duration * 0.4;
        if ( initialChange )
        {
			duration = 120;
            speedOfChange = 0.0;
			weather.GetRain().Set( 0, 1, duration);
			weather.GetSnowfall().Set( 0, 1, duration);
			weather.SetRainThresholds( 1.0, 1.0, 1.0 );
			weather.SetSnowfallThresholds( 1.0, 1.0, 1.0 );
			Print( "WeatherReport: Rain & Snow: Forced to Zero");
        }
		else if ( preset.transition_min >= 0 && preset.transition_max > 0.0 )
        {
            speedOfChange = Math.RandomFloatInclusive( preset.transition_min, preset.transition_max ) * 60;
            duration += speedOfChange;
        }
		
        float overcast = Math.Clamp( Math.RandomFloatInclusive( preset.overcast_min, preset.overcast_max ), 0, 1);
        SetOvercast( weather, overcast, speedOfChange, duration );
		
        float fog = Math.Clamp( Math.RandomFloatInclusive( preset.fog_min, preset.fog_max ), 0, 1);
		float FogBias = Math.Clamp( preset.fog_bias, -1, 1) * 100;
		float FogHeight = Math.Clamp( preset.fog_height, 0, 1);
		float FogDistance = Math.Clamp( preset.fog_distance_min, 0, 1);	
        SetFog( weather, fog, speedOfChange, duration );
		SetFogBias( weather, FogBias, speedOfChange, duration );
		SetFogHeight( weather, FogHeight, speedOfChange, duration );	
		SetFogDistance( weather, FogDistance, speedOfChange, duration );	
		
        float windSpeed = Math.Clamp( Math.RandomFloatInclusive(  preset.windSpeed_min, preset.windSpeed_max ), 0, 1);
        float windDirection = Math.Clamp( Math.RandomFloatInclusive(  preset.windDirection_min, preset.windDirection_max ), -1, 1);
		if (windDirection < 0) {windDirection = windDirection + 1;}
		float pi = (windDirection - 0.5) * 3.14 * 2;
		float degree = 180*(pi/3.14) + 180;		
        SetWindSpeed( weather, windSpeed, speedOfChange, duration );
        SetWindDirection( weather, windDirection, speedOfChange, duration );
		
        if ( !initialChange )
		{
			float rain = Math.Clamp( Math.RandomFloatInclusive( preset.rain_min, preset.rain_max ), 0, 1);
			float snowfall = Math.Clamp( Math.RandomFloatInclusive(  preset.snowfall_min, preset.snowfall_max ), 0, 1);
			float precipitationMin = Math.Max(0.618, overcast);
			if ( rain > 0.0 )
			{
				weather.SetRainThresholds( precipitationMin * 0.8, Math.Min( precipitationMin * 1.2, 1.0 ), speedOfChange * 0.25 );
				Print( "WeatherReport: SetRainThresholds: " + precipitationMin * 0.8);
			}
			else
			{
				GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLaterByName( weather, "SetRainThresholds", speedOfChange * 250, false, new Param3<float, float, float>( 1, 1, speedOfChange * 0.75 ) );
				//weather.SetRainThresholds( 1.0, 1.0, speedOfChange * 0.5 );
				Print( "WeatherReport: SetRainThresholds: 1");
			}
			precipitationMin = Math.Max(0.5, overcast);
			if ( snowfall > 0.0 )
			{
				weather.SetSnowfallThresholds( precipitationMin * 0.8, Math.Min( precipitationMin * 1.2, 1.0 ), speedOfChange * 0.25 );
				Print( "WeatherReport: SetSnowfallThresholds: " + precipitationMin * 0.8);
			}
			else
			{
				GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLaterByName( weather, "SetSnowfallThresholds", speedOfChange * 250, false, new Param3<float, float, float>( 1, 1, speedOfChange * 0.75 ) );
				//weather.SetSnowfallThresholds( 1.0, 1.0, speedOfChange * 0.5 );
				Print( "WeatherReport: SetSnowfallThresholds: 1");
			}
			SetRain( weather, rain, speedOfChange, duration );
			SetSnowfall( weather, snowfall, speedOfChange, duration );	
		}
		
        if ( preset.storm )
        {
            weather.SetStorm( 1.0, overcast * 0.9, preset.thunder_timeout );
        }
        else
        {
            weather.SetStorm( 0.0, 1.0, 99999.0 );
        }
		
		string WindOutOfThe = "";
		if (windDirection >= 0.9375 || windDirection <= 0.0625){ WindOutOfThe="N"; }
		else if (windDirection > 0.8125 && windDirection < 0.9375){ WindOutOfThe="NW"; }
		else if (windDirection >= 0.6875 && windDirection <= 0.8125){ WindOutOfThe="W"; }
		else if (windDirection > 0.5625 && windDirection < 0.6875){ WindOutOfThe="SW"; }
		else if (windDirection >= 0.4375 && windDirection <= 0.5625){ WindOutOfThe="S"; }
		else if (windDirection > 0.3125 && windDirection < 0.4375){ WindOutOfThe="SE"; }
		else if (windDirection >= 0.1875 && windDirection <= 0.3125){ WindOutOfThe="E"; }
		else if (windDirection > 0.0625 && windDirection < 0.1875){ WindOutOfThe="NE"; }	
		
		string message = "";
		//float dtime = Math.Round(duration/60); for " + dtime + "m
		if (preset.report == 2)
		{
			message = preset.name + " ~ Wind " + WindOutOfThe + "°" + Math.Round(degree) + " " + Math.Round(windSpeed*32.1869) + "km/h";
			SendChatMessage(message, 2);
		}
		else if (preset.report == 1)
		{
			message = "Weather: " + preset.name + " ~ Wind " + WindOutOfThe + "°" + Math.Round(degree) + " " + Math.Round(windSpeed*32.1869) + "km/h";
			SendChatMessage(message, 1);
		}
		Print(message);

        m_CurrentWeather = preset;
				
        return duration;
    }

    protected void UpdateWeather()
    {
        if ( !m_Started ) return;
        if ( !g_Game ) return;

        Weather weather = g_Game.GetWeather();
        if (!weather) return;

        Print( "WeatherReport: Update" );

        m_PresetWeatherTime = 0.0;

        m_InstanceID = GetGame().ServerConfigGetInt( "instanceId" );

        if ( m_InitialChange )
        {
            string name = string.Format( PERSIST_FILE_NAME, m_InstanceID );
            if ( FileExist( name ) )
            {
                FileSerializer serializer = new FileSerializer();
 
                if ( serializer.Open( name, FileMode.READ ) )
                {
                    WeatherPreset preset = new WeatherPreset();
                    if ( serializer.Read( preset ) )
                    {
                        Print( "WeatherReport: Load persistent weather" );
                        m_NextChangeTime = ApplyPreset( weather, preset, m_InitialChange );
                        m_InitialChange = false;
                        serializer.Close();
                        return;
                    }
                    serializer.Close();
                }
            }
        }

        m_NextChangeTime = ApplyPreset( weather, SelectNextWeather(), m_InitialChange );

        m_InitialChange = false;
    }

    protected WeatherPreset SelectNextWeather()
    {
        if ( m_Presets.Count() > 1 )
        {
            WeatherPreset next = m_CurrentWeather;
            while ( next == m_CurrentWeather )
            {
                next = m_Presets.GetRandomElement();
            }
            return next;
        }
        else
        {
            return m_Presets.GetRandomElement();
        }
    }

	// JSON
    override void OnInit()
    {
        if ( FileExist( PRESET_FILE_NAME ) )
        {
            JsonFileLoader<array<ref WeatherPreset>>.JsonLoadFile( PRESET_FILE_NAME, m_Presets );
        }
        else if ( FileExist( PRESET_TEMPLATE_NAME ) )
        {
            JsonFileLoader<array<ref WeatherPreset>>.JsonLoadFile( PRESET_TEMPLATE_NAME, m_Presets );
            JsonFileLoader<array<ref WeatherPreset>>.JsonSaveFile( PRESET_FILE_NAME, m_Presets );
        }
        else
        {
            m_Presets = new array<ref WeatherPreset>;
            WeatherPreset preset = new WeatherPreset();
            preset.report = 0;
            preset.name = "TEMPLATE";
            preset.transition_min = 1.0;
            preset.transition_max = 2.0;
            preset.duration_min = 30.0;
            preset.duration_max = 60.0;
            preset.overcast_min = 0.0;
            preset.overcast_max = 1.0;
            preset.fog_min = 0.0;
            preset.fog_max = 1.0;
            preset.fog_bias = 0.0;
            preset.fog_height = 0.0;
            preset.fog_distance_min = 0.0;
            preset.windSpeed_min = 0.0;
            preset.windSpeed_max = 1.0;
            preset.windDirection_min = 0.0;
            preset.windDirection_max = 1.0;
            preset.rain_min = 0.0;
            preset.rain_max = 1.0;
            preset.snowfall_min = 0.0;
            preset.snowfall_max = 1.0;
            preset.storm = 0;
            preset.thunder_timeout = 0.0;
            m_Presets.Insert( preset );

            JsonFileLoader<array<ref WeatherPreset>>.JsonSaveFile( PRESET_FILE_NAME, m_Presets );
        }

        if ( !m_Presets || m_Presets.Count() == 0 )
        {
            Error( "WeatherReport: Broken Config!" );
            return;
        }

        Weather weather = g_Game.GetWeather();
        if ( weather )
        {
            weather.MissionWeather( true );
            Start();
        }
    }

    override void OnDestroy()
    {
        string name = string.Format( PERSIST_FILE_NAME, m_InstanceID );
        FileSerializer serializer = new FileSerializer();

         if ( m_CurrentWeather && serializer.Open( name, FileMode.WRITE ) )
         {
            m_CurrentWeather.duration_min = m_CurrentWeather.duration_min * 0.5;
            m_CurrentWeather.duration_max = m_CurrentWeather.duration_max * 0.5;
            serializer.Write( m_CurrentWeather );
            serializer.Close();
        }
    }

    override void OnUpdate( float delta_time )
    {
        if ( !m_Started )
        {
            return;
        }

        m_PresetWeatherTime += delta_time;
        if ( m_PresetWeatherTime >= m_NextChangeTime )
        {
            UpdateWeather();
        }
    }
}
