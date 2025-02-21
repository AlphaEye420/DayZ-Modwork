 void SpawnObject( string type, vector position, vector orientation )
 {
	 auto obj = GetGame().CreateObject( type, position );
	 obj.SetPosition( position );
	 obj.SetOrientation( orientation );
	 obj.SetOrientation( obj.GetOrientation() ); // Collision fix
	 obj.Update();
	 obj.SetAffectPathgraph( true, false );
	 if( obj.CanAffectPathgraph() ) GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater( GetGame().UpdatePathgraphRegionByObject, 100, false, obj );
 }