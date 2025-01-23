modded class PluginManager
{
    override void Init()
    {
        super.Init();

        RegisterPlugin( "PresetWeatherPlugin", false, GetGame().IsDedicatedServer() );
    }
}