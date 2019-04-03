class CfgPatches
{
	class _Vests
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};

	class SmershVest;
    class VaultVest: SmershVest
    {
		scope = 2;
		visibilityModifier = 0.85;
        hiddenSelectionsTextures[]=
        {
            "\@Vault\Vests\data\Vault-Smersh-Woodland.paa",
            "\@Vault\Vests\data\Vault-Smersh-Woodland.paa",
            "\@Vault\Vests\data\Vault-Smersh-Woodland.paa"
        };
    };

	class VaultPlateCarrierVest: Clothing
	{
		displayName="$STR_CfgVehicles_PlateCarrierBlank0";
		descriptionShort="$STR_CfgVehicles_PlateCarrierBlank1";
		model="\DZ\characters\vests\plate_carrier_complete_g.p3d";
		inventorySlot="Vest";
		itemInfo[]=
		{
			"Clothing",
			"Vest"
		};
		attachments[]=
		{
			"Pistol"
		};
		weight=5000;
		itemSize[]={6,5};
		itemsCargoSize[]={5,5};
		absorbency=0.1;
		heatIsolation=0.1;
		repairableWithKits[]={5,3};
		repairCosts[]={30,25};
		hiddenSelections[]=
		{
			"camoGround",
			"camoMale",
			"camoFemale"
		};
		hiddenSelectionsTextures[]=
		{
		"DZ\characters\vests\Data\BallisticVest_co.paa",
		"DZ\characters\vests\Data\BallisticVest_co.paa",
		"DZ\characters\vests\Data\BallisticVest_co.paa"
		};
		class ClothingTypes
		{
			male="\DZ\characters\vests\plate_carrier_complete_m.p3d";
			female="\DZ\characters\vests\plate_carrier_complete_f.p3d";
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\characters\vests\Data\BallisticVest.rvmat"
							}
						},
						
						{
							0.69999999,
							{}
						},
						
						{
							0.5,
							
							{
								"DZ\characters\vests\Data\BallisticVest_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							{}
						},
						
						{
							0,
							
							{
								"DZ\characters\vests\Data\BallisticVest_destruct.rvmat"
							}
						}
					};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					Health=0.40000001;
					Blood=0.40000001;
					Shock=0.5;
				};
				class Melee
				{
					Health=0.69999999;
					Blood=0.60000002;
					Shock=0.80000001;
				};
				class Infected
				{
					Health=0.69999999;
					Blood=0.60000002;
					Shock=0.80000001;
				};
			};
		};
	};
	class VaultPlateCarrierSDK: VaultPlateCarrierVest
	{
		scope=2;
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\@Vault\Vests\data\Plate-SDK.paa",
			"\@Vault\Vests\data\Plate-SDK.paa",
			"\@Vault\Vests\data\Plate-SDK.paa"
		};
	};
};