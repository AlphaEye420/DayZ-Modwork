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
		RegisterTrackTime("YourPBOName_Music_2_SoundSet", DynamicMusicPlayerTimeOfDay.NIGHT);
		
		//DAWN
		//RegisterTrackTime("YourPBOName_Music_3_SoundSet", DynamicMusicPlayerTimeOfDay.DAWN);
		
		//DUSK
		//RegisterTrackTime("YourPBOName_Music_4_SoundSet", DynamicMusicPlayerTimeOfDay.DUSK);
    }
		
	override protected void RegisterTracksLocationStatic()
	{
        m_TracksLocationStatic = new array<ref DynamicMusicTrackData>();
        m_TracksLocationStaticPrioritized = new array<ref DynamicMusicTrackData>();
		super.RegisterTracksLocationStatic();

		//===================================================================================DEER ISLE=============================================================
		//
		// Military (default any time of day)
		//
		
		array<ref TVectorArray> militaryNorthTemple;
		militaryNorthTemple = {
			{"12917.3 1.54578 15907.7", "13285.1 3.67773 15138.1"},
			{"15506.3 12.9616 16226.6", "15571.9 302.857 14789.5"},
		};
		
		array<ref TVectorArray> militarySouthTemple;
		militarySouthTemple = {
			{"18.4928 0.517373 2211.46", "1146.27 113.519 10.003"},
		};

		array<ref TVectorArray> militaryCrater;
		militaryCrater = {
			{"13948.9 5.8791 2266.2", "14133.3 16.4145 2088.89"},
		};

		array<ref TVectorArray> militaryKmcu;
		militaryKmcu = {
			{"7163.42 222.74 11668", "7313.55 606.463 11522.1"},
		};

		array<ref TVectorArray> militaryAreafortytwo;
		militaryAreafortytwo = {
			{"12900.9 0.36245 10087.3", "13783.4 4.35831 9590.18"},
		};

		array<ref TVectorArray> militaryAirfield;
		militaryAirfield = {
			{"5127.66 73.9908 3792.06", "5795.74 72.4094 3226.89"},
		};

		array<ref TVectorArray> militaryCampeagle;
		militaryAirfield = {
			{"8746.42 41.912 3841.97", "8896.31 42.8878 3695.24"},
		};

		array<ref TVectorArray> militaryCampbear;
		militaryAirfield = {
			{"8554.78 1.84933 6089.51", "9067.06 14.05766 5907.19"},
		};
				
		RegisterTrackLocationStaticMultiRectangle("YourPBOName_Music_3_SoundSet", militaryCrater, DynamicMusicPlayerTimeOfDay.ANY, true); 
		RegisterTrackLocationStaticMultiRectangle("YourPBOName_Music_4_SoundSet", militarySouthTemple, DynamicMusicPlayerTimeOfDay.ANY, true);
		RegisterTrackLocationStaticMultiRectangle("YourPBOName_Music_4_SoundSet", militaryNorthTemple, DynamicMusicPlayerTimeOfDay.ANY, true);
		RegisterTrackLocationStaticMultiRectangle("YourPBOName_Music_3_SoundSet", militaryKmcu, DynamicMusicPlayerTimeOfDay.ANY, true); 
		RegisterTrackLocationStaticMultiRectangle("Music_loc_tisy_SoundSet", militaryAreafortytwo, DynamicMusicPlayerTimeOfDay.ANY, true); 
		RegisterTrackLocationStaticMultiRectangle("Music_loc_tisy_SoundSet", militaryCampeagle, DynamicMusicPlayerTimeOfDay.ANY, true); 
		RegisterTrackLocationStaticMultiRectangle("Music_loc_tisy_SoundSet", militaryCampbear, DynamicMusicPlayerTimeOfDay.ANY, true); 
		
		//
		// City Day/Night Timed music (default is NOT using custom music and using BI's music - change soundsets to yours if needed ~ comment out what you don't want)
		//
		/* NOTE: DAYZ HAS THIS SECTION TURNED OFF STILL */

		array<ref TVectorArray> cityGraveyard;
		cityGraveyard = {
			{"9701.21 39.2017 5499.97", "9861.56 39.3532 5383.83"},
		};
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityParis, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityParis, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("YourPBOName_Music_3_SoundSet", cityParis, DynamicMusicPlayerTimeOfDay.NIGHT);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityParis, DynamicMusicPlayerTimeOfDay.NIGHT);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityParis, DynamicMusicPlayerTimeOfDay.NIGHT);

		array<ref TVectorArray> cityParis;
		cityParis = {
			{"2341.35 7.45032 4405.33", "2928.5 8.3107 3211.99"},
		};
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityParis, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityParis, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityParis, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityParis, DynamicMusicPlayerTimeOfDay.NIGHT);
	
		array<ref TVectorArray> citySwamp;
		citySwamp = {
			{"3562.65 11.3478 8963.72", "3824.71 10.3697 8650.33"},
		};
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", citySwamp, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", citySwamp, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", citySwamp, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", citySwamp, DynamicMusicPlayerTimeOfDay.NIGHT);
	
		array<ref TVectorArray> cityPowerplant;
		cityPowerplant = {
			{"3824.71 10.3697 8650.33", "4875.87 17.1748 6934.26"},
		};
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityPowerplant, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityPowerplant, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityPowerplant, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityPowerplant, DynamicMusicPlayerTimeOfDay.NIGHT);
	
		array<ref TVectorArray> cityKushville;
		cityKushville = {
			{"7432.93 21.6037 4039.05", "7627.83 23.7041 3765.2"},
		};
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityKushville, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityKushville, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityKushville, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityKushville, DynamicMusicPlayerTimeOfDay.NIGHT);
	
		array<ref TVectorArray> cityAshville;
		cityAshville = {
			{"7216.56 42.1 2673.76", "7399.03 46.2505 2545.41"},
		};
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityAshville, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityAshville, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityAshville, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityAshville, DynamicMusicPlayerTimeOfDay.NIGHT);
	
		array<ref TVectorArray> cityDuskar;
		cityDuskar = {
			{"7775.53 8.75768 8179.74", "8194.54 160.141 7908.62"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityDuskar, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityDuskar, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityDuskar, DynamicMusicPlayerTimeOfDay.NIGHT);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityDuskar, DynamicMusicPlayerTimeOfDay.NIGHT);
	
		array<ref TVectorArray> cityFairfield;
		cityFairfield = {
			{"9818.65 24.9374 6908.31", "10104.8 23.2611 6670.33"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityFairfield, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityFairfield, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityFairfield, DynamicMusicPlayerTimeOfDay.NIGHT);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityFairfield, DynamicMusicPlayerTimeOfDay.NIGHT);
	
		array<ref TVectorArray> cityEastbrook;
		cityEastbrook = {
			{"10030.2 10.6601 8035.33", "10506.2 15.6422 7627.36"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityEastbrook, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityEastbrook, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityEastbrook, DynamicMusicPlayerTimeOfDay.NIGHT);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityEastbrook, DynamicMusicPlayerTimeOfDay.NIGHT);
	
		array<ref TVectorArray> cityPortland;
		cityPortland = {
			{"5730.88 5.49272 15285.5", "6320.92 25.91 13972.5"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityPortland, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityPortland, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityPortland, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityPortland, DynamicMusicPlayerTimeOfDay.NIGHT);
		
		array<ref TVectorArray> cityStonington;
		cityStonington = {
			{"6686.49 43.6637 2173.71", "7181.64 36.1783 1785.95"},
			{"6878.22 5.88889 1588.24", "7185.89 0.38301 1272.68"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityStonington, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityStonington, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityStonington, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityStonington, DynamicMusicPlayerTimeOfDay.NIGHT);
		

		array<ref TVectorArray> cityThreepwood;
		cityThreepwood = {
			{"8931.77 31.2741 7890.38", "9206.41 23.8633 7698.48"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityThreepwood, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityThreepwood, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityThreepwood, DynamicMusicPlayerTimeOfDay.NIGHT);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityThreepwood, DynamicMusicPlayerTimeOfDay.NIGHT);
		
		
		array<ref TVectorArray> cityNorthhaven;
		cityNorthhaven = {
			{"449.485 8.12 15335.5", "864.417 14.3194 14950.8"},
			{"1182.67 2.12 15716.2", "1674.62 2.52095 15355.9"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityNorthhaven, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityNorthhaven, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityNorthhaven, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityNorthhaven, DynamicMusicPlayerTimeOfDay.NIGHT);
		

		array<ref TVectorArray> cityDeepwater;
		cityDeepwater = {		
			{"379.343 6.9841 12635.7", "906.95 51.2111 11877.3"},
			{"855.594 7.35069 13701.7", "1211.18 7.00205 13228.9"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityDeepwater, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityDeepwater, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityDeepwater, DynamicMusicPlayerTimeOfDay.NIGHT);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityDeepwater, DynamicMusicPlayerTimeOfDay.NIGHT);
		

		array<ref TVectorArray> cityBayville;
		cityBayville = {		
			{"9803.63 25.8134 12482.7", "10391.5 7.41816 11889.3"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityBayville, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityBayville, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityBayville, DynamicMusicPlayerTimeOfDay.NIGHT);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityBayville, DynamicMusicPlayerTimeOfDay.NIGHT);
		

		array<ref TVectorArray> cityMountainville;
		cityMountainville = {		
			{"7160.79 10.0372 8626.84", "7353.04 4.92554 8362.5"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityMountainville, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityMountainville, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityMountainville, DynamicMusicPlayerTimeOfDay.NIGHT);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityMountainville, DynamicMusicPlayerTimeOfDay.NIGHT);
		
		
		array<ref TVectorArray> cityRockenheim;
		cityRockenheim = {		
			{"8194.54 102.141 7908.62", "10265.8 1.92746 10615"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityRockenheim, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityRockenheim, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityRockenheim, DynamicMusicPlayerTimeOfDay.NIGHT);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityRockenheim, DynamicMusicPlayerTimeOfDay.NIGHT);
		
		
		array<ref TVectorArray> cityEastharbor;
		cityEastharbor = {		
			{"10870.1 4.33871 10420.9", "11742.5 6.2541 9883.65"},
		};
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityEastharbor, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityEastharbor, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityEastharbor, DynamicMusicPlayerTimeOfDay.NIGHT);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityEastharbor, DynamicMusicPlayerTimeOfDay.NIGHT);
		
		
		array<ref TVectorArray> citySunsetcross;
		citySunsetcross = {
			{"6300.01 18.7964 6763.53", "6705.16 15.09 6469.72"},
			{"6341.76 15.09 6315.09", "6759.28 15.4276 6208.39"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", citySunsetcross, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", citySunsetcross, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", citySunsetcross, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", citySunsetcross, DynamicMusicPlayerTimeOfDay.NIGHT);
		
		
		array<ref TVectorArray> citySandybay;
		citySandybay = {
			{"5174.09 9.84869 7525.75", "5464.79 10.0808 7408.25"},
			{"5355.01 6.30671 7833.48", "5540.57 1.89756 7666.47"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", citySandybay, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", citySandybay, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", citySandybay, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", citySandybay, DynamicMusicPlayerTimeOfDay.NIGHT);
		
		
		array<ref TVectorArray> cityGeorgetown;
		cityGeorgetown = {
			{"4582.64 18.4772 4548.49", "4840.52 18.0251 4333.08"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityGeorgetown, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityGeorgetown, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityGeorgetown, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityGeorgetown, DynamicMusicPlayerTimeOfDay.NIGHT);
		
		
		array<ref TVectorArray> cityWarrencove;
		cityWarrencove = {
			{"6759.28 15.4276 6208.39", "7186.63 0.913061 5213.72"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityWarrencove, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityWarrencove, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityWarrencove, DynamicMusicPlayerTimeOfDay.NIGHT);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityWarrencove, DynamicMusicPlayerTimeOfDay.NIGHT);
				
		array<ref TVectorArray> cityOceanville;
		cityOceanville = {
			{"10169.8 44.5949 5036.73", "10314.1 39.9019 4706.76"},
			{"9662.2 12.1786 4461.74", "9812.68 1.67669 4291.17"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityOceanville, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityOceanville, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityOceanville, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityOceanville, DynamicMusicPlayerTimeOfDay.NIGHT);
				
		array<ref TVectorArray> cityOldtown;
		cityOldtown = {
			{"1769.19 9.19 9137.85", "2058.84 9.78813 8818.8"},
		};
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityOldtown, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityOldtown, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityOldtown, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityOldtown, DynamicMusicPlayerTimeOfDay.NIGHT);
		
		array<ref TVectorArray> cityWestbrook;
		cityWestbrook = {
			{"3131.12 17.2472 6665.12", "3696.32 20.4944 6458.31"},
			{"3231.61 22.2495 6197.68", "3535.95 22.1801 6064.9"},
		};
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityWestbrook, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityWestbrook, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityWestbrook, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityWestbrook, DynamicMusicPlayerTimeOfDay.NIGHT);
				
		array<ref TVectorArray> cityWaldoboro;
		cityWaldoboro = {
			{"8210.03 5.47331 9046.92", "9130.15 2.25217 8553.28"},
			{"8823.33 27.1089 9859.73", "9447.7 3.04127 9345.79"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityWaldoboro, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityWaldoboro, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityWaldoboro, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityWaldoboro, DynamicMusicPlayerTimeOfDay.NIGHT);
				
		array<ref TVectorArray> cityArchipelago;
		cityArchipelago = {
			{"2397.64 0.725803 14036.5", "2785.69 24.9896 13783.5"},
		};
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityArchipelago, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityArchipelago, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityArchipelago, DynamicMusicPlayerTimeOfDay.NIGHT);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityArchipelago, DynamicMusicPlayerTimeOfDay.NIGHT);
				
		array<ref TVectorArray> cityHazelands;
		cityHazelands = {
			{"4297.81 2.67 2850.67", "4819.65 10.2822 2535.14"},
		};
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityHazelands, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityHazelands, DynamicMusicPlayerTimeOfDay.DAY);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityHazelands, DynamicMusicPlayerTimeOfDay.NIGHT);
		//RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityHazelands, DynamicMusicPlayerTimeOfDay.NIGHT);

		/*BI's example if you don't import your own music:
			RegisterTrackLocationStaticMultiRectangle("Music_loc_vybor_day1_SoundSet", militaryVybor, DynamicMusicPlayerTimeOfDay.DAY, true);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_vybor_day2_SoundSet", militaryVybor, DynamicMusicPlayerTimeOfDay.DAY, true);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_vybor_night_SoundSet", militaryVybor, DynamicMusicPlayerTimeOfDay.NIGHT, true);
			They use this one: RegisterTrackLocationStaticMultiRectangle("Music_loc_tisy_SoundSet", militaryTisy, DynamicMusicPlayerTimeOfDay.ANY, true);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_tisy_day2_SoundSet", militaryTisy, DynamicMusicPlayerTimeOfDay.DAY, true);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_tisy_night1_SoundSet", militaryTisy, DynamicMusicPlayerTimeOfDay.NIGHT, true);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_tisy_night2_SoundSet", militaryTisy, DynamicMusicPlayerTimeOfDay.NIGHT, true);
		
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityChernohorsk, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityChernohorsk, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityChernohorsk, DynamicMusicPlayerTimeOfDay.NIGHT);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityChernohorsk, DynamicMusicPlayerTimeOfDay.NIGHT);

			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityZelenogorsk, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityZelenogorsk, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityZelenogorsk, DynamicMusicPlayerTimeOfDay.NIGHT);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityZelenogorsk, DynamicMusicPlayerTimeOfDay.NIGHT);

			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityNovajaPetrovka, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityNovajaPetrovka, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityNovajaPetrovka, DynamicMusicPlayerTimeOfDay.NIGHT);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityNovajaPetrovka, DynamicMusicPlayerTimeOfDay.NIGHT);
			
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", citySeverograd, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", citySeverograd, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", citySeverograd, DynamicMusicPlayerTimeOfDay.NIGHT);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", citySeverograd, DynamicMusicPlayerTimeOfDay.NIGHT);
			
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityNovodmytrovsk, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityNovodmytrovsk, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityNovodmytrovsk, DynamicMusicPlayerTimeOfDay.NIGHT);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityNovodmytrovsk, DynamicMusicPlayerTimeOfDay.NIGHT);
			
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", citySvetlojarsk, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", citySvetlojarsk, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", citySvetlojarsk, DynamicMusicPlayerTimeOfDay.NIGHT);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", citySvetlojarsk, DynamicMusicPlayerTimeOfDay.NIGHT);

			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityBerezeno, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityBerezeno, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityBerezeno, DynamicMusicPlayerTimeOfDay.NIGHT);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityBerezeno, DynamicMusicPlayerTimeOfDay.NIGHT);
			
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_1_SoundSet", cityElectrozavodsk, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_day_2_SoundSet", cityElectrozavodsk, DynamicMusicPlayerTimeOfDay.DAY);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_1_SoundSet", cityElectrozavodsk, DynamicMusicPlayerTimeOfDay.NIGHT);
			RegisterTrackLocationStaticMultiRectangle("Music_loc_city_night_2_SoundSet", cityElectrozavodsk, DynamicMusicPlayerTimeOfDay.NIGHT);
		*/
	}

    override void RegisterTracksLocationDynamic()
    {
        m_TracksLocationDynamic = new array<ref DynamicMusicTrackData>();
		// Contaminated Areas Music (only needed if you want your own music to override otherwise comment out the Registers below)
		RegisterTrackLocationDynamic("YourPBOName_Music_5_SoundSet", DynamicMusicLocationTypes.CONTAMINATED_ZONE, DynamicMusicPlayerTimeOfDay.DAY);
		RegisterTrackLocationDynamic("YourPBOName_Music_6_SoundSet", DynamicMusicLocationTypes.CONTAMINATED_ZONE, DynamicMusicPlayerTimeOfDay.NIGHT);
    }
}