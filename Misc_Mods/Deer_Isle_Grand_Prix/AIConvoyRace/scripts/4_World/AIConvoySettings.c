modded class AIConvoyGeneralSettings
{
	// This changes the working directory for the Moving AI Convoy Mod
	// Keep your RACE Crew, Route and Vehicle Files in the AIGrandPrix folder
	// It will only load race items and will not call normal convoys nor edit its files

	// Separate Race files from normal Moving AI Convoy mod
    static const string DIR = "$profile:AIConvoy/AIGrandPrix";
    static const string PATH = "$profile:AIConvoy/AIGrandPrix/AIConvoySettings.json";
    static const string VEHICLES_DIR = "$profile:AIConvoy/AIGrandPrix/Vehicles";
    static const string CREWS_DIR = "$profile:AIConvoy/AIGrandPrix/Crews";
    static const string ROUTES_DIR = "$profile:AIConvoy/AIGrandPrix/Routes";
    static const string LOOT_PRESETS_PATH = "$profile:AIConvoy/AIGrandPrix/LootPresets.json";
	
    void AIConvoyGeneralSettings()
    {
        ConfigVersion = CONFIG_VERSION;
        Enabled = true;
        InitialDelaySeconds = 60;
        MinIntervalSeconds = 1;
        MaxIntervalSeconds = 60;

        MaxActiveConvoys = 18;
        NotifyOnSpawn = false;
        NotifyOnAmbush = false;
        ShowCrewKillFeed = false;

        TrackSpawnedVehicles = false;
        RouteRecorderPlayers = new TStringArray;
        RouteRecorderSampleDistance = 15.0;
        TeleportPlayersToStart = new TStringArray;
        DespawnRadius = 2000.0;
        DespawnTimeoutSeconds = 600;
        MaxConvoyLifetimeSeconds = 3600;
        KeepVehicleIfMoved = true;
        FollowGapMeters = 15.0;
        AdminSteamIDs = new TStringArray;

        DefaultVehiclePool = new TStringArray;
        DefaultVehiclePool.Insert("RaceCar_Plum");
        DefaultVehiclePool.Insert("RaceCar_Gold");
        DefaultVehiclePool.Insert("RaceCar_Turquoise");
        DefaultVehiclePool.Insert("RaceCar_MBM");
        DefaultVehiclePool.Insert("RaceCar_SheriffBlack");
        DefaultVehiclePool.Insert("RaceCar_SheriffWhite");
        DefaultVehiclePool.Insert("RaceCar_Yellow");
        DefaultVehiclePool.Insert("RaceCar_DayZ");
        DefaultVehiclePool.Insert("RaceCar_Pink");
        DefaultVehiclePool.Insert("RaceCar_Green");
        DefaultVehiclePool.Insert("RaceCar_Zagorky");
        DefaultVehiclePool.Insert("RaceCar_Fronta");
        DefaultVehiclePool.Insert("RaceCar_NotaCola");
        DefaultVehiclePool.Insert("RaceCar_Spite");
        DefaultVehiclePool.Insert("RaceCar_Red");
        DefaultVehiclePool.Insert("RaceCar_Blue");
        DefaultVehiclePool.Insert("RaceCar_Pipsi");
        DefaultVehiclePool.Insert("RaceCar_DeezBeanz");

        DefaultCrewPool = new TStringArray;
        DefaultCrewPool.Insert("RC_Plum");
        DefaultCrewPool.Insert("RC_Gold");
        DefaultCrewPool.Insert("RC_Turquoise");
        DefaultCrewPool.Insert("RC_MBM");
        DefaultCrewPool.Insert("RC_SheriffBlack");
        DefaultCrewPool.Insert("RC_SheriffWhite");
        DefaultCrewPool.Insert("RC_Yellow");
        DefaultCrewPool.Insert("RC_DayZ");
        DefaultCrewPool.Insert("RC_Pink");
        DefaultCrewPool.Insert("RC_Green");
        DefaultCrewPool.Insert("RC_Zagorky");
        DefaultCrewPool.Insert("RC_Fronta");
        DefaultCrewPool.Insert("RC_NotaCola");
        DefaultCrewPool.Insert("RC_Spite");
        DefaultCrewPool.Insert("RC_Red");
        DefaultCrewPool.Insert("RC_Blue");
        DefaultCrewPool.Insert("RC_Pipsi");
        DefaultCrewPool.Insert("RC_DeezBeanz");

        AdvanceWarningSeconds = 0;
        NotificationTitle = "";
        NotificationStarted = "";
        NotificationStopped = "";
        NotificationAdvance = "";

        LootPresetsPath = "";
        LBmasterPresets = 1;
        MarkerEnabled = true;
        MarkerName = "";
        MarkerNameStopped = "";
        MarkerIconName = "Car";
        Marker3D = false;
        MarkerUpdateSeconds = 10.0;
        MarkerMinMoveMeters = 50.0;

        MarkerColorA = 225;
        MarkerColorR = 225;
        MarkerColorG = 125;
        MarkerColorB = 50;

        MarkerStoppedColorA = 225;
        MarkerStoppedColorR = 225;
        MarkerStoppedColorG = 25;
        MarkerStoppedColorB = 25;
    }
}