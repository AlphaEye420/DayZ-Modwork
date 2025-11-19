modded class LoadingScreen {
	
	void LoadingScreen(DayZGame game) {
		Class.CastTo(m_ImageLogoMid, m_WidgetRoot.FindAnyWidget("ImageLogoMid"));
		Class.CastTo(m_ImageLogoCorner, m_WidgetRoot.FindAnyWidget("ImageLogoCorner"));
		Class.CastTo(m_ModdedWarning, m_WidgetRoot.FindAnyWidget("ModdedWarning"));
		m_ImageLogoMid.Show(false);
		m_ImageLogoCorner.Show(false);
		//m_ModdedWarning.Show( false ); // uncomment this call to remove modded server warning
		
		m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_1.edds"); //** Change YourPBOName
		
		m_ImageBackground.LoadMaskTexture("");
		ProgressAsync.SetUserData(m_ImageBackground);
	}

	override void Show()
	{
		Widget lIcon = m_ImageBackground;
		Widget pText = m_ProgressLoading;
		m_ProgressText.SetText("");
		m_ProgressLoading.SetCurrent( 0.0 );
		m_ImageBackground.SetMaskProgress( 0.0 );
		
		if ( !m_WidgetRoot.IsVisible() )
		{
			if ( m_DayZGame.GetUIManager().IsDialogVisible() )
			{
				m_DayZGame.GetUIManager().HideDialog();
			}
			
			if ( m_DayZGame.GetMissionState() == DayZGame.MISSION_STATE_MAINMENU )
			{
				m_ImageWidgetBackground.Show( true );		
				m_TextWidgetStatus.Show(true);
			}
			else
			{
				m_ImageWidgetBackground.Show( true );
				m_TextWidgetStatus.Show(false);
			}
			
			m_WidgetRoot.Show( true );
			m_TextWidgetTitle.SetText( "" );
			m_TextWidgetStatus.SetText( "" );
		}
		
		ProgressAsync.SetProgressData(pText);
		ProgressAsync.SetUserData(lIcon);
	}
}

modded class LoginQueueBase {
	
	override Widget Init() {
		Widget w = super.Init();
		ImageWidget imageWidgetBackground = ImageWidget.Cast( layoutRoot.FindAnyWidget("Background") );
		imageWidgetBackground.LoadMaskTexture("");
		
		imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_1.edds");  //** Change YourPBOName
		
		return w;
	}
}

modded class LoginTimeBase {
	
	override Widget Init() {
		Widget w = super.Init();
		ImageWidget imageWidgetBackground = ImageWidget.Cast( layoutRoot.FindAnyWidget("Background") );
		imageWidgetBackground.LoadMaskTexture("");
		
		imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_1.edds");  //** Change YourPBOName
		
		return w;
	}	
}
