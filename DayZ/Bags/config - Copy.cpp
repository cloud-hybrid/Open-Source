class CfgPatches
{
	class _Bags
	{
		units[]={};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Characters"};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing: Clothing_Base{};

	class ExampleAssaultBag_Base: Clothing
	{
			displayName="$STR_cfgVehicles_AssaultBag_ColorBase0";
			descriptionShort="$STR_cfgVehicles_AssaultBag_ColorBase1";
			model="\dz\characters\backpacks\boulder_m53_g.p3d";
			inventorySlot="Back";
			simulation="clothing";
			itemInfo[]=
			{
				"Clothing",
				"Back"
			};
			rotationFlags=16;
			itemsCargoSize[]={10,9};
			itemSize[]={10,9};
			weight=900;
			absorbency=0.40000001;
			heatIsolation=0.1;
			repairableWithKits[]={5,3};
			repairCosts[]={30,25};
			soundAttType="Military";
			randomQuantity=4;
			hiddenSelections[]=
			{
				"camoGround",
				"camoMale",
				"camoFemale"
			};
			class ClothingTypes
			{
				male="\DZ\characters\backpacks\boulder_m53_m.p3d";
				female="\DZ\characters\backpacks\boulder_m53_f.p3d";
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
									"DZ\Characters\backpacks\data\boulder_m53.rvmat"
								}
							},
							
							{
								0.69999999,
								{}
							},
							
							{
								0.5,
								
								{
									"DZ\Characters\backpacks\data\boulder_m53_damage.rvmat"
								}
							},
							
							{
								0.30000001,
								{}
							},
							
							{
								0,
								
								{
									"DZ\Characters\backpacks\data\boulder_m53_destruct.rvmat"
								}
							}
						};
					};
				};
			};
			class AnimEvents
			{
				class SoundWeapon
				{
					class pickUpItem_Light
					{
						soundSet="pickUpBackPack_Metal_Light_SoundSet";
						id=796;
					};
					class pickUpItem
					{
						soundSet="pickUpBackPack_Metal_SoundSet";
						id=797;
					};
				};
			};
		};

	class ExampleAssaultBag: ExampleAssaultBag_Base
	{
		scope=2;
		descriptionShort="Vault Woodland Assault Bag";
		visibilityModifier=0.94999999;
		hiddenSelectionsTextures[]=
		{
			"\@Vault\Bags\data\Vault-Assault-Woodland.paa",
			"\@Vault\Bags\data\Vault-Assault-Woodland.paa",
			"\@Vault\Bags\data\Vault-Assault-Woodland.paa"
		};
	};
};