modded class AIConvoyManager
{
	// Using the race track with a column can work okay, but it slows the race down a lot
	// Normal is max 6 columns * 3 convoys = 18 vehicle max
	
	// WARNING !!
	// For server performance you should keep the multiplied-together result at or lower than 18	

	// 1 column & 18 convoys makes it so that several cars on a race track fight for position
    static const int MAX_COLUMN_VEHICLES = 1; 
    static const int MAX_ACTIVE_CONVOYS = 18;
	
	// Faster re-spawn for keeping the track full of cars; Normally 10 min & 180 max
    static const int MIN_INTERVAL_MINUTES = 0;  
    static const int MAX_INTERVAL_MINUTES = 180; 
	
	//  AUTOMATION FOR CREATING NEEDED FILES & READY TO USE RIGHT OUT OF THE BOX
    protected ref AIConvoyGeneralSettings m_Settings;
    protected ref map<string, ref AIConvoyVehiclePreset> m_Vehicles;
    protected ref map<string, ref AIConvoyCrewPreset> m_Crews;
    protected ref array<ref AIConvoyRoute> m_Routes;
    protected ref array<ref AIConvoySlot> m_Slots;
    protected bool m_WarnClampLogged;
    protected ref AIConvoyMarker m_Marker;
    protected ref AIConvoyLootPresets m_LootPresets;
    protected ref AIConvoyRouteRecorder m_Recorder;
    protected ref map<string, string> m_RouteFiles;
    protected ref TStringArray m_MenuDeniedLogged;
	
    override protected void InstallBundledDefaults()
    {
        // Only creates these if they are not found, it will not overwrite files	
        InstallBundledRaceLoot("LootPresets");	
		// INSTALL VEHICLES
        InstallBundledRaceVehicle("RaceCar_Pipsi");
        InstallBundledRaceVehicle("RaceCar_Blue");
        InstallBundledRaceVehicle("RaceCar_Red");
        InstallBundledRaceVehicle("RaceCar_DeezBeanz");
        InstallBundledRaceVehicle("RaceCar_Fronta");
        InstallBundledRaceVehicle("RaceCar_NotaCola");
        InstallBundledRaceVehicle("RaceCar_Spite");
        InstallBundledRaceVehicle("RaceCar_Zagorky");
        InstallBundledRaceVehicle("RaceCar_DayZ");
        InstallBundledRaceVehicle("RaceCar_Green");
        InstallBundledRaceVehicle("RaceCar_Pink");
        InstallBundledRaceVehicle("RaceCar_Yellow");
        InstallBundledRaceVehicle("RaceCar_MBM");
        InstallBundledRaceVehicle("RaceCar_SheriffBlack");
        InstallBundledRaceVehicle("RaceCar_SheriffWhite");
        InstallBundledRaceVehicle("RaceCar_Turquoise");
        InstallBundledRaceVehicle("RaceCar_Gold");
        InstallBundledRaceVehicle("RaceCar_Plum");
		// INSTALL CREWS
        InstallBundledRaceCrew("RC_Pipsi");
        InstallBundledRaceCrew("RC_Blue");
        InstallBundledRaceCrew("RC_Red");
        InstallBundledRaceCrew("RC_DeezBeanz");
        InstallBundledRaceCrew("RC_Fronta");
        InstallBundledRaceCrew("RC_NotaCola");
        InstallBundledRaceCrew("RC_Spite");
        InstallBundledRaceCrew("RC_Zagorky");
        InstallBundledRaceCrew("RC_DayZ");
        InstallBundledRaceCrew("RC_Green");
        InstallBundledRaceCrew("RC_Pink");
        InstallBundledRaceCrew("RC_Yellow");
        InstallBundledRaceCrew("RC_MBM");
        InstallBundledRaceCrew("RC_SheriffBlack");
        InstallBundledRaceCrew("RC_SheriffWhite");
        InstallBundledRaceCrew("RC_Turquoise");
        InstallBundledRaceCrew("RC_Gold");
        InstallBundledRaceCrew("RC_Plum");
		// INSTALL ROUTES
        InstallBundledRaceRoute("RockenheimRace01_Pipsi");
        InstallBundledRaceRoute("RockenheimRace02_Blue");
        InstallBundledRaceRoute("RockenheimRace03_Red");
        InstallBundledRaceRoute("RockenheimRace04_DeezBeanz");
        InstallBundledRaceRoute("RockenheimRace05_Fronta");
        InstallBundledRaceRoute("RockenheimRace06_NotaCola");
        InstallBundledRaceRoute("RockenheimRace07_Spite");
        InstallBundledRaceRoute("RockenheimRace08_Zagorky");
        InstallBundledRaceRoute("RockenheimRace09_DayZ");
        InstallBundledRaceRoute("RockenheimRace10_Green");
        InstallBundledRaceRoute("RockenheimRace11_Pink");
        InstallBundledRaceRoute("RockenheimRace12_Yellow");
        InstallBundledRaceRoute("RockenheimRace13_MBM");
        InstallBundledRaceRoute("RockenheimRace14_SheriffBlack");
        InstallBundledRaceRoute("RockenheimRace15_SheriffWhite");
        InstallBundledRaceRoute("RockenheimRace16_Turquoise");
        InstallBundledRaceRoute("RockenheimRace17_Gold");
        InstallBundledRaceRoute("RockenheimRace18_Plum");
		// INSTALL LOADOUTS
        string loadoutDir = "$profile:ExpansionMod/Loadouts";
        if (!FileExist("$profile:ExpansionMod"))
            MakeDirectory("$profile:ExpansionMod");
        if (!FileExist(loadoutDir))
            MakeDirectory(loadoutDir);
        InstallBundledRaceLoadout("RC_Pipsi", loadoutDir);
        InstallBundledRaceLoadout("RC_Blue", loadoutDir);
        InstallBundledRaceLoadout("RC_Red", loadoutDir);
        InstallBundledRaceLoadout("RC_DeezBeanz", loadoutDir);
        InstallBundledRaceLoadout("RC_Fronta", loadoutDir);
        InstallBundledRaceLoadout("RC_NotaCola", loadoutDir);
        InstallBundledRaceLoadout("RC_Spite", loadoutDir);
        InstallBundledRaceLoadout("RC_Zagorky", loadoutDir);
        InstallBundledRaceLoadout("RC_DayZ", loadoutDir);
        InstallBundledRaceLoadout("RC_Green", loadoutDir);
        InstallBundledRaceLoadout("RC_Pink", loadoutDir);
        InstallBundledRaceLoadout("RC_Yellow", loadoutDir);
        InstallBundledRaceLoadout("RC_MBM", loadoutDir);
        InstallBundledRaceLoadout("RC_SheriffBlack", loadoutDir);
        InstallBundledRaceLoadout("RC_SheriffWhite", loadoutDir);
        InstallBundledRaceLoadout("RC_Turquoise", loadoutDir);
        InstallBundledRaceLoadout("RC_Gold", loadoutDir);
        InstallBundledRaceLoadout("RC_Plum", loadoutDir);
    }
	
    protected void InstallBundledRaceLoot(string name)
    {
        string path = AIConvoyGeneralSettings.LOOT_PRESETS_PATH;
		if (!FileExist(path)) InstallBundledRaceFile(name + ".json", path);
    }
	
    protected void InstallBundledRaceVehicle(string name)
    {
        string path = AIConvoyGeneralSettings.VEHICLES_DIR + "/" + name + ".json";
		if (!FileExist(path)) InstallBundledRaceFile("Vehicles/" + name + ".json", path);
    }
	
    protected void InstallBundledRaceCrew(string name)
    {
        string path = AIConvoyGeneralSettings.CREWS_DIR + "/" + name + ".json";
		if (!FileExist(path)) InstallBundledRaceFile("Crews/" + name + ".json", path);
    }
	
    protected void InstallBundledRaceRoute(string name)
    {
        string path = AIConvoyGeneralSettings.ROUTES_DIR + "/" + name + ".json";
		if (!FileExist(path)) InstallBundledRaceFile("Routes/" + name + ".json", path);
    }
	
    protected void InstallBundledRaceLoadout(string name, string loadoutDir)
    {
        string path = loadoutDir + "/" + name + ".json";
		if (!FileExist(path)) InstallBundledRaceFile("Loadouts/" + name + ".json", path);
    }
	
	// RACE FILES INSTALL EXECUTE & LOG
    protected void InstallBundledRaceFile(string relPath, string destPath)
    {
        if (FileExist(destPath))
            return;
        string srcPath = "AIConvoyRace/AIGrandPrix/" + relPath;
        if (!FileExist(srcPath))
        {
            Print("[AIConvoyRace] ERROR: bundled race item missing from PBO: " + srcPath);
            return;
        }
        if (CopyFile(srcPath, destPath))
            Print("[AIConvoyRace] Installed bundled race item: " + destPath);
        else
            Print("[AIConvoyRace] ERROR installing race item: " + destPath);
    }
	
	// LOAD & LOG
    override protected void LoadVehiclePresets()
	{
        m_Vehicles = new map<string, ref AIConvoyVehiclePreset>;
        TStringArray names;
        AIConvoyConfigDir.ListJsonFiles(AIConvoyGeneralSettings.VEHICLES_DIR, names);		
        if (names.Count() == 0) return;
        foreach (string name : names)
        {

            string vehPath = AIConvoyGeneralSettings.VEHICLES_DIR + "/" + name + ".json";
            Print("[AIConvoyRace] Reading Race Car " + vehPath);

            AIConvoyVehiclePreset loaded = new AIConvoyVehiclePreset();
            string loadError;
            if (JsonFileLoader<AIConvoyVehiclePreset>.LoadFile(vehPath, loaded, loadError))
            {
                m_Vehicles.Set(name, loaded);
                continue;
            }

            Print("[AIConvoyRace] ERROR loading vehicle preset '" + name + "': " + loadError);

            AIConvoyVehiclePreset healed = LoadBundledVehicle(name);
            if (healed)
            {
                m_Vehicles.Set(name, healed);
                Print("[AIConvoyRace] Using the built-in default for vehicle preset '" + name + "' until " + name + ".json is fixed. Your file was not changed - it is usually a missing comma or bracket.");
            }
        }
        Print("[AIConvoyRace] Vehicle presets: " + names.Count() + " file(s), " + m_Vehicles.Count() + " loaded");
	};
	
    override protected AIConvoyVehiclePreset LoadBundledVehicle(string name)
    {
        string bundledSrc = "AIConvoy/AIGrandPrix/BundledConfigs/Vehicles/" + name + ".json";
        if (!FileExist(bundledSrc))
        {
            Print("[AIConvoyRace] No built-in default for vehicle preset '" + name + "' - it is skipped until its file is fixed.");
            return null;
        }

        AIConvoyVehiclePreset preset = new AIConvoyVehiclePreset();
        string err;
        if (!JsonFileLoader<AIConvoyVehiclePreset>.LoadFile(bundledSrc, preset, err))
        {
            Print("[AIConvoyRace] ERROR reading the built-in default for '" + name + "': " + err);
            return null;
        }
        return preset;
    }
    
	override protected void LoadCrewPresets()
	{
        m_Crews = new map<string, ref AIConvoyCrewPreset>;

        TStringArray names;
        AIConvoyConfigDir.ListJsonFiles(AIConvoyGeneralSettings.CREWS_DIR, names);
        if (names.Count() == 0) return;
        foreach (string name : names)
        {
            string crewPath = AIConvoyGeneralSettings.CREWS_DIR + "/" + name + ".json";
            Print("[AIConvoyRace] Reading Race Driver " + crewPath);

            AIConvoyCrewPreset loaded = new AIConvoyCrewPreset();
            string loadError;
            if (JsonFileLoader<AIConvoyCrewPreset>.LoadFile(crewPath, loaded, loadError))
                m_Crews.Set(name, loaded);
            else
                Print("[AIConvoyRace] ERROR loading crew preset '" + name + "': " + loadError);
        }
        Print("[AIConvoyRace] Crew presets: " + names.Count() + " file(s), " + m_Crews.Count() + " loaded");
    }
    
	override protected void LoadRoutes()
    {
        m_Routes = new array<ref AIConvoyRoute>;
        m_RouteFiles = new map<string, string>;
        TStringArray names;
        AIConvoyConfigDir.ListJsonFiles(AIConvoyGeneralSettings.ROUTES_DIR, names);
        if (names.Count() == 0) return;
        foreach (string name : names)
        {
            string routePath = AIConvoyGeneralSettings.ROUTES_DIR + "/" + name + ".json";
            Print("[AIConvoyRace] Reading Race Position " + routePath);

            AIConvoyRoute route = new AIConvoyRoute();
            string loadError;
            if (JsonFileLoader<AIConvoyRoute>.LoadFile(routePath, route, loadError))
            {
                if (route.Name == "" || route.Name == "Unnamed Route")
                    route.Name = name;
                ApplyLegacyVehiclePin(route, routePath);

                if (m_RouteFiles.Contains(route.Name))
                    Print("[AIConvoyRace] WARNING: route files '" + m_RouteFiles.Get(route.Name) + ".json' and '" + name + ".json' both use the Name '" + route.Name + "'. Only the first is reachable by name (admin menu, TriggerConvoy). Give each route a unique Name.");
                else
                    m_RouteFiles.Set(route.Name, name);

                m_Routes.Insert(route);
            }
            else
            {
                Print("[AIConvoyRace] ERROR loading route '" + name + "': " + loadError);
            }
        }
        Print("[AIConvoyRace] Routes: " + names.Count() + " file(s), " + m_Routes.Count() + " loaded");
    }
}