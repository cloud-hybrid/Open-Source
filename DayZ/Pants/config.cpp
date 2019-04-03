class CfgPatches
{
	class _Pants
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};
class CfgVehicles
{
	class CargoPants_ColorBase;

    class VaultPants: CargoPants_ColorBase
    {
		scope = 2;
		visibilityModifier = 0.9;
        hiddenSelectionsTextures[]=
        {
            "\@Vault\Pants\data\Vault-Pants-Woodland.paa",
            "\@Vault\Pants\data\Vault-Pants-Woodland-Base.paa",
            "\@Vault\Pants\data\Vault-Pants-Woodland-Base.paa"
        };
    };
};