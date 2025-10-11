/*
	Data model class for Hint json
	Location: 
*/
modded class HintPage 
{
	private string 	m_Headline;			// Headline hint text	
	private string 	m_Description;		// Hint description text
	private string 	m_ImagePath;		// Hint image, can be null  

	override string GetHeadlineText()
	{
		return m_Headline;
	}
	override string GetDescriptionText()
	{
		return m_Description;
	}
	override string GetImagePath()
	{
		return m_ImagePath;
	}
}
