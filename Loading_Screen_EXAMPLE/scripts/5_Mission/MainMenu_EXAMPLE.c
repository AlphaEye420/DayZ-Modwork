modded class MainMenu
{
	protected Widget				custom_button1;
	protected Widget				custom_button2;

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets( "YourModName/gui/main_menu.layout" ); //********** edit "YourModName" text to match your mod's name
		
		m_Play						= layoutRoot.FindAnyWidget( "play" );
		m_CustomizeCharacter		= layoutRoot.FindAnyWidget( "customize_character" );
		m_SettingsButton			= layoutRoot.FindAnyWidget( "settings_button" );
		m_Exit						= layoutRoot.FindAnyWidget( "exit_button" );

		custom_button1				= layoutRoot.FindAnyWidget( "custom_button1" );
		custom_button2				= layoutRoot.FindAnyWidget( "custom_button2" );

		m_Version					= TextWidget.Cast( layoutRoot.FindAnyWidget( "version" ) );
		m_CharacterRotationFrame	= layoutRoot.FindAnyWidget( "character_rotation_frame" );
		m_Stats						= new MainMenuStats( layoutRoot.FindAnyWidget( "stats_root" ) );	
		m_Mission					= MissionMainMenu.Cast( GetGame().GetMission() );
		m_LastFocusedButton			= m_Play;
		m_ScenePC					= m_Mission.GetIntroScenePC();
		
		if( m_ScenePC )
		{
			m_ScenePC.ResetIntroCamera();
		}
		
		m_PlayerName				= TextWidget.Cast( layoutRoot.FindAnyWidget("character_name_text") );
		
		m_Version.SetText( "Version" );  //********** edit if you want
		
		GetGame().GetUIManager().ScreenFadeOut(0);

		SetFocus( null );
		
		Refresh();
		
		GetDayZGame().GetBacklit().MainMenu_OnShow();
	
		g_Game.SetLoadState( DayZLoadState.MAIN_MENU_CONTROLLER_SELECT );
		
		return layoutRoot;
	}
	
	override bool OnClick( Widget w, int x, int y, int button )
	{
		if( button == MouseState.LEFT )
		{
			if( w == m_Play )
			{
				
				m_LastFocusedButton = m_Play;
				g_Game.ConnectFromServerBrowser( "1.1.1.1", 2302, "" ); //********** edit your connection (IP, Port, "") - leave "" blank
				return true;
			}

			else if ( w == m_CustomizeCharacter )
			{
				OpenMenuCustomizeCharacter();
				return true;
			}
			else if ( w == m_SettingsButton )
			{
				OpenSettings();
				return true;
			}
			else if ( w == m_Exit )
			{
				Exit();
				return true;
			}
			else if ( w == custom_button1 )
			{
				GetGame().OpenURL("https://steamcommunity.com");  //********** Lower left of screen: Right Hand Icon URL link
				return true;
			}
			else if ( w == custom_button2 )
			{
				GetGame().OpenURL("https://discord.gg");  //********** Lower left of screen: Left Hand Icon URL link
				return true;
			}			
		}
		return false;
	}
	
	override bool IsFocusable( Widget w )
	{
		if( w )
		{
			if( w == m_Play || w == m_CustomizeCharacter || w == m_SettingsButton || w == m_Exit || w == custom_button1 || w == custom_button2 );
			{
				return true;
			}
		}
		return false;
	}

	override void LoadMods()
	{
		return;
	}
	
	override void Play()
	{
		return;
	}

	override bool OnMouseButtonDown( Widget w, int x, int y, int button )
	{
		return false;
	}
}