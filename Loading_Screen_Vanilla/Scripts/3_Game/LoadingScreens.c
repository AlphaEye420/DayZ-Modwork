modded class LoadingScreen {
	
	void LoadingScreen(DayZGame game) {
		Class.CastTo(m_ImageLogoMid, m_WidgetRoot.FindAnyWidget("ImageLogoMid"));
		Class.CastTo(m_ImageLogoCorner, m_WidgetRoot.FindAnyWidget("ImageLogoCorner"));
		m_ImageLogoMid.Show(false);
		m_ImageLogoCorner.Show(false);
		//m_ModdedWarning.Show( false ); // uncomment this call to remove modded server warning
		int i = Math.RandomInt(0,20);
		
		if (i == 0) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_1.edds")};
		if (i == 1) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_2.edds")};
		if (i == 2) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_3.edds")};
		if (i == 3) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_4.edds")};
		if (i == 4) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_5.edds")};
		if (i == 5) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_6.edds")};
		if (i == 6) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_7.edds")};
		if (i == 7) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_8.edds")};
		if (i == 8) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_9.edds")};
		if (i == 9) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_10.edds")};
		if (i == 10) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_11.edds")};
		if (i == 11) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_12.edds")};
		if (i == 12) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_13.edds")};
		if (i == 13) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_14.edds")};
		if (i == 14) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_15.edds")};
		if (i == 15) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_16.edds")};
		if (i == 16) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_17.edds")};
		if (i == 17) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_18.edds")};
		if (i == 18) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_19.edds")};
		if (i == 19) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_20.edds")};
		if (i == 20) {m_ImageBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_21.edds")};
		
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
		
		int i = Math.RandomInt(0,20);
		
		if (i == 0) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_1.edds")};  // NOTICE THAT YOU CAN'T JUST COPY PASTE FROM ABOVE, YOU ALSO HAVE A DIFFERENT VARIABLE NAME HERE THAN ABOVE
		if (i == 1) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_2.edds")};
		if (i == 2) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_3.edds")};
		if (i == 3) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_4.edds")};
		if (i == 4) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_5.edds")};
		if (i == 5) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_6.edds")};
		if (i == 6) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_7.edds")};
		if (i == 7) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_8.edds")};
		if (i == 8) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_9.edds")};
		if (i == 9) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_10.edds")};
		if (i == 10) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_11.edds")};
		if (i == 11) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_12.edds")};
		if (i == 12) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_13.edds")};
		if (i == 13) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_14.edds")};
		if (i == 14) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_15.edds")};
		if (i == 15) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_16.edds")};
		if (i == 16) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_17.edds")};
		if (i == 17) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_18.edds")};
		if (i == 18) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_19.edds")};
		if (i == 19) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_20.edds")};
		if (i == 20) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_21.edds")};
		
		return w;
	}
}

modded class LoginTimeBase {
	
	override Widget Init() {
		Widget w = super.Init();
		ImageWidget imageWidgetBackground = ImageWidget.Cast( layoutRoot.FindAnyWidget("Background") );
		imageWidgetBackground.LoadMaskTexture("");
		
		int i = Math.RandomInt(0,20);
		
		if (i == 0) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_1.edds")};  // YOU CAN COPY AND PASTE THE SECTION DIRECTLY ABOVE TO HERE
		if (i == 1) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_2.edds")};
		if (i == 2) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_3.edds")};
		if (i == 3) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_4.edds")};
		if (i == 4) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_5.edds")};
		if (i == 5) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_6.edds")};
		if (i == 6) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_7.edds")};
		if (i == 7) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_8.edds")};
		if (i == 8) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_9.edds")};
		if (i == 9) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_10.edds")};
		if (i == 10) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_11.edds")};
		if (i == 11) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_12.edds")};
		if (i == 12) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_13.edds")};
		if (i == 13) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_14.edds")};
		if (i == 14) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_15.edds")};
		if (i == 15) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_16.edds")};
		if (i == 16) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_17.edds")};
		if (i == 17) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_18.edds")};
		if (i == 18) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_19.edds")};
		if (i == 19) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_20.edds")};
		if (i == 20) {imageWidgetBackground.LoadImageFile(0, "YourPBOName/Data/YOUR_PIC_21.edds")};
		
		return w;
	}	
}
