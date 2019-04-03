class CfgPatches
{
	class _Clothes
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data", "DZ_Characters"};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};
	class Armband_ColorBase;
	class VaultArmband_Colorbase: Armband_ColorBase
	{
		scope=0;
	};
	class ArmbandSDK: VaultArmband_Colorbase
	{
		scope = 2;
		visibilityModifier = 0.85000002;
        color = "Vault SDK";
        hiddenSelectionsTextures[] = {"\@Vault\Clothing\data\SDK-Armband.paa","\@Vault\Clothing\data\SDK-Armband.paa","\@Vault\Clothing\data\SDK-Armband.paa","\@Vault\Clothing\data\SDK-Armband.paa","\@Vault\Clothing\data\SDK-Armband.paa"};
	};

    class TacticalShirt_ColorBase; 
    class AdminJacket: TacticalShirt_ColorBase
    {
		scope = 2;
		visibilityModifier = 1.0;
        hiddenSelectionsTextures[]=
        {
            "\@Vault\Clothing\data\admin-jacket.paa",
            "\@Vault\Clothing\data\admin-jacket.paa",
            "\@Vault\Clothing\data\admin-jacket.paa"
        };
    };

    class VaultTacticalShirt: TacticalShirt_ColorBase
    {
		scope = 2;
		visibilityModifier = 1.0;
        hiddenSelectionsTextures[]=
        {
            "\@Vault\Clothing\data\Vault-Tactical-Shirt.paa",
            "\@Vault\Clothing\data\Vault-Tactical-Shirt.paa",
            "\@Vault\Clothing\data\Vault-Tactical-Shirt.paa"
        };
    };
    
	class M65Jacket_ColorBase;

    class VaultJacketLogo: M65Jacket_ColorBase
    {
        scope=2;
        repairableWithKits[]={5,2};
        repairCosts[]={30,25};
        hiddenSelectionsTextures[]=
        {
            "\@Vault\Clothing\data\Vault-Jacket-Logo.paa",
            "\@Vault\Clothing\data\Vault-Jacket-Logo.paa",
            "\@Vault\Clothing\data\Vault-Jacket-Logo.paa"
        };
    };

    class VaultJacketLight: M65Jacket_ColorBase
    {
        scope=2;
        repairableWithKits[]={5,2};
        repairCosts[]={30,25};
        hiddenSelectionsTextures[]=
        {
            "\@Vault\Clothing\data\Vault-Jacket-Woodland-Light.paa",
            "\@Vault\Clothing\data\Vault-Jacket-Woodland-Light.paa",
            "\@Vault\Clothing\data\Vault-Jacket-Woodland-Light.paa"
        };
    };

    class GorkaEJacket_ColorBase;
    
    class WulfeJacket: GorkaEJacket_ColorBase
    {
	    scope = 2;
	    visibilityModifier = 0.75;
	    hiddenSelectionsTextures[] = {
            "\@Vault\Clothing\data\Wulfe-Jacket-Base.paa",
            "\@Vault\Clothing\data\Wulfe-Jacket.paa",
            "\@Vault\Clothing\data\Wulfe-Jacket.paa"};
	};
};