modded class PluginRecipesManagerBase
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		RegisterRecipe(new CraftCodelock);
		RegisterRecipe(new CraftCodelockexp);
		RegisterRecipe(new CraftGoldbar);
		RegisterRecipe(new CraftSilverbar);
	}
}