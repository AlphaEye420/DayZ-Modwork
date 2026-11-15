[eAIRegisterFaction(eAIFactionConvoy)]
class eAIFactionConvoy : eAIFaction
{
	void eAIFactionConvoy()
	{
		m_Loadout = "WestLoadout";
	}

	override bool IsFriendly(notnull eAIFaction other)
	{
		if (other.IsInherited(eAIFactionConvoy)) return true;
		if (other.IsGuard()) return true;
		return false;
	}

	override string GetDisplayName()
	{
		return "Convoy";
	}
};