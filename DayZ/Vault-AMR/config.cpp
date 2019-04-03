#define _ARMA_

enum {
	destructengine = 2,
	destructdefault = 6,
	destructwreck = 7,
	destructtree = 3,
	destructtent = 4,
	stabilizedinaxisx = 1,
	stabilizedinaxisy = 2,
	destructno = 0,
	stabilizedinaxesboth = 3,
	stabilizedinaxesnone = 0,
	destructman = 5,
	destructbuilding = 1
};

class CfgPatches
{
	class _VaultAMR
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"DZ_Data",
			"DZ_Characters",
			"DZ_Weapons_Firearms",
			"DZ_Weapons_Optics",
			"DZ_Weapons_Muzzles",
			"DZ_Weapons_Magazines",
			"DZ_Weapons_Supports"
		};
	};
};

class Mode_Safe;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class CfgWeapons
{
	class BoltRifle_Base;
	class AMR_Base: BoltRifle_Base
	{	
		scope = 2;
		displayName = "$STR_cfgWeapons_AMR0";
		descriptionShort = "$STR_cfgWeapons_AMR0";
		// animName = "VAULT-DMR";
		weight = 5000;

		absorbency = 0.0;
		repairableWithKits[] = {5,1};
		repairCosts[] = {30.0,25.0};
		ContinuousActions[] = {235};

		optics = 1;
		opticsFlare = 0;
		modelOptics = "-";

		distanceZoomMin = 100;
		distanceZoomMax = 100;
		discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000};
		discreteDistanceInitIndex = 0;

		PPDOFProperties[] = {1,0.5,20,170,4,10};
		WeaponLength = 1.275;
		value = 0;

		chamberSize = 1;
		chamberedRound = "";
		chamberableFrom[] = {"Ammo_762x54","Ammo_762x54Tracer, Mag_SVD_10Rnd"};
		magazines[] = {"Mag_SVD_10Rnd"};
		magazineSwitchTime = 0.25;

		// magazines[] = {"Mag_AMR"};

		barrelArmor = 1800;
		ejectType = 1;

		forceOptics = 1;

		baseAttachments[] = {};

		opticsZoomInit = 0.05;
		opticsZoomMin = 0.0175;
		opticsZoomMax = 0.0500;
		autoFire = 0;
		begin1[] = {"\@Vault\Vault-AMR\Sound\AMR-Close",2.5118864,1,1300};
		soundBegin[] = {"begin1",1};
		drySound[] = {"\@Vault\Vault-AMR\Sound\AMR-Dry",0.5,1,20};
		reloadMagazineSound[] = {"\@Vault\Vault-AMR\Sound\AMR-Reload",1,1,30};
		reloadAction = "ReloadSVD";
		shotAction = "Reloadcz527Shot";
		reloadTime = 0.5;
		// dispersion = 0.0005;
		minRange = 0;
		minRangeProbab = 0.1;
		midRange = 1200;
		midRangeProbab = 0.7;
		maxRange = 1800;
		// maxRangeProbab = 0.05;
		magazineSlot = "magazine";
		recoilModifier[] = {1,1,1};

		hiddenSelectionsMaterials[] = {"\@Vault\Vault-AMR\Vault-AMR.rvmat"};
		hiddenSelectionsTextures[] = {
			"\@Vault\Vault-AMR\data\AMR-Textured.paa",
			"\@Vault\Vault-AMR\data\AMR-nohq.paa",
			"\@Vault\Vault-AMR\data\AMR-smdi.paa"
		};

		modes[] = {"Single"};

		class Single: Mode_SemiAuto
		{
			soundSetShot[] = {"AMR_DangerClose_SoundShader","AMR_Close_SoundShader","AMR_Mid_SoundShader","AMR_Distant_SoundShader", "AMR-Distant-Reverb", "AMR_DistantTail_SoundShader"};
			reloadTime = 1;
			recoil = "AMRRecoil";
			recoilProne = "AMRRecoilProne";
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class walkErc_L
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_L_SoundSet";
					id = 1;
				};
				class walkErc_R
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_R_SoundSet";
					id = 2;
				};
				class runErc_L
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 3;
				};
				class runErc_R
				{
					soundSet = "Weapon_Movement_Rifle_runErc_R_SoundSet";
					id = 4;
				};
				class sprintErc_L
				{
					soundSet = "Weapon_Movement_Rifle_sprintErc_SoundSet";
					id = 5;
				};
				class sprintErc_R
				{
					soundSet = "Weapon_Movement_Rifle_sprintErc_SoundSet";
					id = 6;
				};
				class walkCro_L
				{
					soundSet = "Weapon_Movement_Rifle_walkCro_SoundSet";
					id = 21;
				};
				class walkCro_R
				{
					soundSet = "Weapon_Movement_Rifle_walkCro_SoundSet";
					id = 22;
				};
				class runCro_L
				{
					soundSet = "Weapon_Movement_Rifle_runCro_SoundSet";
					id = 23;
				};
				class runCro_R
				{
					soundSet = "Weapon_Movement_Rifle_runCro_SoundSet";
					id = 24;
				};
				class walkProne_L
				{
					soundSet = "Weapon_Movement_Rifle_walkCro_SoundSet";
					id = 31;
				};
				class walkProne_R
				{
					soundSet = "Weapon_Movement_Rifle_walkCro_SoundSet";
					id = 32;
				};
				class runProne_L
				{
					soundSet = "Weapon_Movement_Rifle_runCro_SoundSet";
					id = 33;
				};
				class runProne_R
				{
					soundSet = "Weapon_Movement_Rifle_runCro_SoundSet";
					id = 34;
				};
				class jumpErc_L
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 35;
				};
				class jumpErc_R
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 36;
				};
				class landFootErc_L
				{
					soundSet = "Weapon_Movement_Rifle_landFootErc_SoundSet";
					id = 37;
				};
				class landFootErc_R
				{
					soundSet = "Weapon_Movement_Rifle_landFootErc_SoundSet";
					id = 38;
				};
				class walkRasErc_L
				{
					soundSet = "Weapon_Movement_Rifle_walkRasErc_SoundSet";
					id = 51;
				};
				class walkRasErc_R
				{
					soundSet = "Weapon_Movement_Rifle_walkRasErc_SoundSet";
					id = 52;
				};
				class runRasErc_L
				{
					soundSet = "Weapon_Movement_Rifle_runRasErc_SoundSet";
					id = 53;
				};
				class runRasErc_R
				{
					soundSet = "Weapon_Movement_Rifle_runRasErc_SoundSet";
					id = 54;
				};
				class HandStep_L
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_L_SoundSet";
					id = 61;
				};
				class HandStep_R
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_L_SoundSet";
					id = 62;
				};
				class HandStep_Hard_L
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 63;
				};
				class HandStep_Hard_R
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 64;
				};
				class landFeetErc
				{
					soundSet = "Weapon_Movement_Rifle_landFeetErc_SoundSet";
					id = 100;
				};
				class Weapon_Movement_Rifle_Walk
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_L_SoundSet";
					id = 101;
				};
				class Weapon_Movement_Rifle_Run
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 102;
				};
				class Weapon_Movement_Rifle_Sprint
				{
					soundSet = "Weapon_Movement_Rifle_sprintErc_SoundSet";
					id = 103;
				};
				class Weapon_Movement_Rifle_Land
				{
					soundSet = "Weapon_Movement_Rifle_landFeetErc_SoundSet";
					id = 104;
				};
				class Char_Gestures_Hand_Grab_Rifle
				{
					soundSet = "Char_Gestures_Hand_Grab_FabricRifle_SoundSet";
					id = 892;
				};
				class drop
				{
					soundset = "rifle_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class VaultAMR: AMR_Base
	{
		// scope = 2;
		displayName = "Anti-Material Rifle";
		descriptionShort = "A Big-Ass Gun";
		model = "\@Vault\Vault-AMR\Vault-DMR.p3d";
		attachments[] = {"weaponMuzzleMosin","weaponOpticsLRS","weaponBipod","weaponOptics","weaponWrap"};
		itemSize[] = {10, 4};
		dexterity = 1.5;
		spawnDamageRange[] = {0.0,0.6};

		hiddenSelectionsMaterials[] = {"\@Vault\Vault-AMR\Vault-AMR.rvmat"};
		hiddenSelectionsTextures[] = {"\@Vault\Vault-AMR\data\AMR-Textured.paa"};

		class Particles
		{
			class OnFire
			{
				class ChamberFlash
				{
					overridePoint = "Usti hlavne";
					illuminateWorld = 1.5;
					overrideParticle = "weapon_shot_izh18_01";
				};
				class SmokeCloud
				{
					overrideParticle = "weapon_shot_winded_smoke";
				};
				class MuzzleFlash
				{
					overrideParticle = "weapon_shot_izh18_01";
					illuminateWorld = 1.15;
					positionOffset[] = {-0.25,0,0};
				};
			};
		};
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 125;
					// healthLevels[] = {{1.0,{"DZ\weapons\firearms\mosin9130\Data\mosin_9130.rvmat"}},{0.7,{"DZ\weapons\firearms\mosin9130\Data\mosin_9130.rvmat"}},{0.5,{"DZ\weapons\firearms\mosin9130\Data\mosin_9130_damage.rvmat"}},{0.3,{"DZ\weapons\firearms\mosin9130\Data\mosin_9130_damage.rvmat"}},{0.0,{"DZ\weapons\firearms\mosin9130\Data\mosin_9130_destruct.rvmat"}}};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class walkErc_L
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_L_SoundSet";
					id = 1;
				};
				class walkErc_R
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_R_SoundSet";
					id = 2;
				};
				class runErc_L
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 3;
				};
				class runErc_R
				{
					soundSet = "Weapon_Movement_Rifle_runErc_R_SoundSet";
					id = 4;
				};
				class sprintErc_L
				{
					soundSet = "Weapon_Movement_Rifle_sprintErc_SoundSet";
					id = 5;
				};
				class sprintErc_R
				{
					soundSet = "Weapon_Movement_Rifle_sprintErc_SoundSet";
					id = 6;
				};
				class walkCro_L
				{
					soundSet = "Weapon_Movement_Rifle_walkCro_SoundSet";
					id = 21;
				};
				class walkCro_R
				{
					soundSet = "Weapon_Movement_Rifle_walkCro_SoundSet";
					id = 22;
				};
				class runCro_L
				{
					soundSet = "Weapon_Movement_Rifle_runCro_SoundSet";
					id = 23;
				};
				class runCro_R
				{
					soundSet = "Weapon_Movement_Rifle_runCro_SoundSet";
					id = 24;
				};
				class walkProne_L
				{
					soundSet = "Weapon_Movement_Rifle_walkCro_SoundSet";
					id = 31;
				};
				class walkProne_R
				{
					soundSet = "Weapon_Movement_Rifle_walkCro_SoundSet";
					id = 32;
				};
				class runProne_L
				{
					soundSet = "Weapon_Movement_Rifle_runCro_SoundSet";
					id = 33;
				};
				class runProne_R
				{
					soundSet = "Weapon_Movement_Rifle_runCro_SoundSet";
					id = 34;
				};
				class jumpErc_L
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 35;
				};
				class jumpErc_R
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 36;
				};
				class landFootErc_L
				{
					soundSet = "Weapon_Movement_Rifle_landFootErc_SoundSet";
					id = 37;
				};
				class landFootErc_R
				{
					soundSet = "Weapon_Movement_Rifle_landFootErc_SoundSet";
					id = 38;
				};
				class walkRasErc_L
				{
					soundSet = "Weapon_Movement_Rifle_walkRasErc_SoundSet";
					id = 51;
				};
				class walkRasErc_R
				{
					soundSet = "Weapon_Movement_Rifle_walkRasErc_SoundSet";
					id = 52;
				};
				class runRasErc_L
				{
					soundSet = "Weapon_Movement_Rifle_runRasErc_SoundSet";
					id = 53;
				};
				class runRasErc_R
				{
					soundSet = "Weapon_Movement_Rifle_runRasErc_SoundSet";
					id = 54;
				};
				class HandStep_L
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_L_SoundSet";
					id = 61;
				};
				class HandStep_R
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_L_SoundSet";
					id = 62;
				};
				class HandStep_Hard_L
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 63;
				};
				class HandStep_Hard_R
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 64;
				};
				class landFeetErc
				{
					soundSet = "Weapon_Movement_Rifle_landFeetErc_SoundSet";
					id = 100;
				};
				class Weapon_Movement_Rifle_Walk
				{
					soundSet = "Weapon_Movement_Rifle_walkErc_L_SoundSet";
					id = 101;
				};
				class Weapon_Movement_Rifle_Run
				{
					soundSet = "Weapon_Movement_Rifle_runErc_L_SoundSet";
					id = 102;
				};
				class Weapon_Movement_Rifle_Sprint
				{
					soundSet = "Weapon_Movement_Rifle_sprintErc_SoundSet";
					id = 103;
				};
				class Weapon_Movement_Rifle_Land
				{
					soundSet = "Weapon_Movement_Rifle_landFeetErc_SoundSet";
					id = 104;
				};
				class Char_Gestures_Hand_Grab_Rifle
				{
					soundSet = "Char_Gestures_Hand_Grab_FabricRifle_SoundSet";
					id = 892;
				};
				class drop
				{
					soundset = "rifle_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
};

class CfgSoundShaders
{
	class AMR_DangerClose_SoundShader
	{
		samples[] = {{"@Vault\Vault-AMR\Sound\AMR-Danger-Close",1}};
		volume = 1.75;
		range = 150;
		rangeCurve = "closeShotCurve";
	};
	class AMR_Close_SoundShader
	{
		samples[] = {{"@Vault\Vault-AMR\Sound\AMR-Close",1}};
		volume = 1.15;
		range = 500;
		rangeCurve[] = {{0,0.2},{50,1},{300,0},{500,0}};
	};
	class AMR_Mid_SoundShader
	{
		samples[] = {{"@Vault\Vault-AMR\Sound\AMR-Mid",1}};
		volume = 1.00;
		range = 1500;
		rangeCurve[] = {{0,0.2},{50,1},{300,0},{1500,0}};
	};
	class AMR_Distant_SoundShader
	{
		samples[] = {{"@Vault\Vault-AMR\Sound\AMR-Distant-Open",1}};
		volume = 1;
		range = 2000;
		rangeCurve[] = {{0,0},{50,0},{300,1},{1750,1}};
	};
	class AMR_DistantTail_SoundShader
	{
		samples[] = {{"@Vault\Vault-AMR\Sound\AMR-Distant-Reverb",1}};
		volume = 1.75;
		range = 2000;
		rangeCurve[] = {{0,0},{300,0.7},{2000,1}};
		limitation = 1;
	};
	class AMR_DistantTailForest_SoundShader
	{
		samples[] = {{"@Vault\Vault-AMR\Sound\AMR-Distant-Forest",1}};
		volume = 1.375;
		range = 2000;
		rangeCurve[] = {{0,1},{2000,0.3}};
		limitation = 1;
	};
};

class CfgSoundSets
{
	class Rifle_Shot_Base_SoundSet;
	class AMR_Shot_SoundSet: Rifle_Shot_Base_SoundSet
	{
		soundShaders[] = {"AMR_DangerClose_SoundShader","AMR_Close_SoundShader","AMR_Mid_SoundShader","AMR_Distant_SoundShader", "AMR-Distant-Reverb", "AMR_DistantTail_SoundShader"};
	};
};

class CfgRecoils
{
	AMRRecoil[] = {0,0,0,0.1,0.2,2,0.05,-0.02,-0.03,0.05,0,0};
	AMRRecoilProne[] = {0,0,0,0.1,0.1,0.005,0.05,-0.2,-0.01,0.05,0,0};
};
