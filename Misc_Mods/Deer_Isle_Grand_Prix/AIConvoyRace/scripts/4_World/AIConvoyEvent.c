modded class AIConvoyEvent
{
	// WARNING !!
	// Using this mod means you intend to only have race cars on the track, normal convoys will crash often if used!
    //
	// Normally 6.0, bigger to avoid AI trying to get back to a waypoint they were pushed away from by another AI
	protected static const float WAYPOINT_REACHED_DIST = 10.0;
	
	// Normally 2.0 which is needed for cars on DayZ Roads; Set for harder breaking on the race track
    protected static const float CURVE_BRAKE_ACCEL = 3.33; 
	
	// Normally 10 which is needed for cars on DayZ Roads; Most cars struggle with any speed faster than 75 on the track
    protected static const float CURVE_MIN_KMH = 75;
}