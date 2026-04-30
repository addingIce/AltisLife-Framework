class CfgVehicles {
	retrievalPerc = 0.01;
	chopKeepChance = 80;
	crushPerc = 0.1;
	chopPerc = 0.35;
	chopTime = 300;

	class Base {
		description = "";
		virtualSpace = 0;
		garageLimit = 10;
		fuelConsumptionRate = 1.5;
		isHouse = false;
		canTransfer = true;
		canChop = true;
		conditions = "true";
		inventory[] = { 
			{ "FirstAidKit", 2 }, 
			{ "Sweetie", 1 } 
		};
		blacklistedItems[] = { 
			"UnprocessedOil",

			"HumanitarianSupplies",
			"FreightCargo",
			"StolenCargo",
			"Fuel"
		};
		class Textures {};
	};

	class BaseShip : Base {
		whitelistedItems[] = { "StolenCargo" };
		class Textures {};
	};

	class BaseTruck : Base {
		garageLimit = 5;
		garageDelay = 10;
		enableRope = false;
		whitelistedItems[] = { "FreightCargo" };
		class Textures {};
	};

	class BaseHeli : BaseTruck {
		retrievalPerc = 0.005;
		turrets[] = {};
		blacklistedItems[] = { 
			"Coal",
			"Coral",
			"Tobacco",
			"Sand",

			"CopperOre",
			"SilverOre",
			"IronOre",
			"UraniumOre",
			"UncutDiamond",
			"CutBloodDiamond",
			"UnrefinedSalt",
			"UnprocessedOil",

			"EphedrineBarrel",
			"UnprocessedWeed",
			"UnprocessedHeroin",
			"UnprocessedCocaine",

			"WeaponParts",

			"Turtle_F_Raw",

			"SeizedContraband",
			"SpaceCapsuleDataDrive",
			"SmallGalleryPiece",
			"MediumGalleryPiece",
			"LargeGalleryPiece",
			"MarkedGold",
			"UnmarkedGold",
			"EncryptedDrive",
			"DecryptedDrive",

			"Foodstuffs",
			"HumanitarianSupplies",
			"DunamisPropaganda",
			"FreightCargo",
			"StolenCargo",
			"Fuel"
		};
		class Actions {
			class PilotEject {
				actionTitle = "Eject";
				actionCode = "moveOut (_this select 1)";
				params[] = {};
				priority = 6.1;
				condition = "_target isEqualTo (vehicle _this) && { (locked _target) isEqualTo 0 } && { ((driver _target) isEqualTo _this) }";
				radius = 25;
			};
		};
	};

	class BasePlane : BaseHeli {
		garageLimit = 1;
		retrievalPerc = 0.003;
		canChop = false;
		pylons[] = { "", "", "", "", "", "", "", "", "", "", "", "", "" };
	};

	class BaseContainer : Base {
		buyPrice = 1000000;
		chopKeepChance = 100;
		chopPerc = 1;
		garageLimit = 1;
		canChop = false;
		class Textures {};
	};

	// LIGHTS --------------------------------------------------------------------------------------
	class PoliceColour {
		leftColour[] = {0.1, 0.1, 20};
		rightColour[] = {0.1, 0.1, 20};
	};
	class MedicColour {
		leftColour[] = {0.1, 0.1, 20};
		rightColour[] = {0.1, 0.1, 20};
	};
	class HatoColour {
		leftColour[] = {10, 5, 0};
		rightColour[] = {10, 5, 0};
	};

	// TEXTURES --------------------------------------------------------------------------------------
	class BaseTexture {
		displayName = "默认（Default）";
		buyPrice = 0;
		factions[] = { "Civilian", "Dunamis" };
		textures[] = {};
		locked = false;
		conditions = "true";
	};

	// Base without lights (for helis)
	class PoliceTextureBase : BaseTexture {
		factions[] = { "Police" };
		upgrades[] = { 
			"TrackingDeviceUpgrade",
			"ImprovedLocksUpgrade" 
		};
		class Siren { SFX[] = { "Siren_1", "Siren_2", "Siren_5" }; };
		class Actions {
			class PNC {
				actionTitle = "Police National Computer";
				actionCode = "[] call ULP_fnc_openPNC";
				params[] = {};
				priority = 1;
				condition = "_target isEqualTo (vehicle _this) && { ([_this, [""Police""]] call ULP_fnc_isFaction) || ((driver _target) isEqualTo _this) }";
				radius = 25;
			};
			class PilotEject {
				actionTitle = "Eject";
				actionCode = "moveOut (_this select 1)";
				params[] = {};
				priority = 6.1;
				condition = "_target isEqualTo (vehicle _this) && { (locked _target) isEqualTo 0 } && { ((driver _target) isEqualTo _this) }";
				radius = 25;
			};
		};
	};

	// Full with sirens and lights
	class PoliceTexture : PoliceTextureBase {
		remoteGates = true;
		class Lights : PoliceColour {};
	};

	class MedicTextureBase : BaseTexture {
		factions[] = { "Medic" };
		upgrades[] = { 
			"TrackingDeviceUpgrade",
			"ImprovedStorageUpgrade" 
		};
		class Siren { SFX[] = { "Siren_6", "Siren_4", "Siren_3" }; };
		class Actions {
			class NHSDispatcher {
				actionTitle = "NHS Dispatcher";
				actionCode = "[] call ULP_fnc_openMedicMap";
				params[] = {};
				priority = 1;
				condition = "_target isEqualTo (vehicle _this) && { [player, [""Medic""]] call ULP_fnc_isFaction }";
				radius = 25;
			};
		};
	};
	
	class MedicTexture : MedicTextureBase {
		remoteGates = true;
		class Lights : MedicColour {};
	};

	class HatoTexture : BaseTexture {
		factions[] = { "Hato" };
		upgrades[] = { 
			"TrackingDeviceUpgrade",
			"ImprovedStorageUpgrade" 
		};
		remoteGates = true;
		class Siren {};
		class Lights : HatoColour {};
	};

	class BaseChromeGreen : BaseTexture {
		displayName = "镀铬绿（Chrome Green）";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\green.rvmat" };
		locked = true;
	};
	class BaseChromeBlue : BaseChromeGreen {
		displayName = "镀铬蓝（Chrome Blue）";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\blue.rvmat" };
	};
	class BaseChromeRed : BaseChromeGreen {
		displayName = "镀铬红（Chrome Red）";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\red.rvmat" };
	};
	class BaseChromeSilver : BaseChromeGreen {
		displayName = "镀铬银（Chrome Silver）";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\silver.rvmat" };
	};
	class BaseChromeGold : BaseChromeGreen {
		displayName = "镀铬金（Chrome Gold）";
		materials[] = { "Data\Textures\Vehicles\Global\Chrome\gold.rvmat" };
	};

	// CARS --------------------------------------------------------------------------------------
	class C_Kart_01_Blu_F : Base {
		description = "Kart 是一种小型四轮车，可由重力、燃油或电力驱动。它配备 4 冲程发动机，最大可输出约 20 马力，不建议未满 18 岁的驾驶者操作。";
		buyPrice = 2500;
	};
	class C_Kart_01_Fuel_F : C_Kart_01_Blu_F{};
    class C_Kart_01_Red_F : C_Kart_01_Blu_F{};
    class C_Kart_01_Vrana_F : C_Kart_01_Blu_F{};
    class C_Kart_01_black_F : C_Kart_01_Blu_F{};
    class C_Kart_01_white_F : C_Kart_01_Blu_F{};
    class C_Kart_01_green_F : C_Kart_01_Blu_F{};
    class C_Kart_01_orange_F : C_Kart_01_Blu_F{};
    class C_Kart_01_yellow_F : C_Kart_01_Blu_F{};

	class C_Quadbike_01_F : Base {
		description = "Quadbike 是一款全地形四轮车，采用低压轮胎和车把转向。军方常用它执行侦察任务，并进入重型载具难以到达的地形。";
		buyPrice = 9300;
		virtualSpace = 15;
		class Textures {
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_black_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "白色（White）";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_white_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "红色（Red）";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_red_co.paa" }; 
			};
			class Blue : BaseTexture { 
				displayName = "蓝色（Blue）";
				textures[] = { "\A3\Soft_F_beta\Quadbike_01\Data\quadbike_01_civ_blue_co.paa" }; 
			};
			class Tan : BaseTexture { 
				displayName = "沙色（Tan）";
				textures[] = { "\A3\Soft_F\Quadbike_01\Data\Quadbike_01_co.paa" }; 
			};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};

	class C_Hatchback_01_F : Base {
		description = "这是一款在远东地区大规模量产的四座掀背车，用来满足不断增长的家用车需求，同时也提供运动版本。";
		buyPrice = 17450;
		virtualSpace = 25;
		class Textures {
			// Police
			class PoliceWhite : PoliceTexture { 
				displayName = "常规巡逻（General Response）";
				textures[] = { "Data\Textures\Vehicles\Land\Police\hatchback_white.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class PoliceBlack : PoliceWhite { 
				displayName = "武装巡逻（Armed Response）";
				conditions = "[""Police_RPU"", 1] call ULP_fnc_hasAccess && { [""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } }";
				textures[] = { "Data\Textures\Vehicles\Land\Police\hatchback_black.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class PoliceANPR : PoliceWhite { 
				displayName = "ANPR 拦截车（ANPR Interceptor）";
				anpr = true;
				textures[] = { "Data\Textures\Vehicles\Land\Police\hatchback_ANPR.paa" }; 
				inventory[] = { 
					{ "Stinger", 1 },
					{ "RoadCone_F", 4 }
				};
				class Lights : PoliceColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class UnmarkedBlack : PoliceTexture {
				displayName = "黑色（Black）";
				anpr = true;
				conditions = "[""Police_RPU"", 2] call ULP_fnc_hasAccess || { [""Police_RPU"", 1] call ULP_fnc_hasAccess && { [""Police_NCA"", 1] call ULP_fnc_hasAccess } }";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base09_co.paa" };
				inventory[] = { 
					{ "Stinger", 1 },
					{ "RoadCone_F", 4 }
				};
				class Lights : PoliceColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};
			class UnmarkedBlackWhiteSport : UnmarkedBlack {
				displayName = "黑白运动款（Black/White Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedGrey : UnmarkedBlack {
				displayName = "灰色（Grey）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base08_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedWhite : UnmarkedBlack {
				displayName = "白色（White）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base07_co.paa" };
				class Lights : Lights {}; 
			};
			class UnmarkedBeige : UnmarkedBlack {
				displayName = "米色（Beige）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base01_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedBeigeSport : UnmarkedBlack {
				displayName = "米色运动款（Beige Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport05_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedRedSport : UnmarkedBlack {
				displayName = "红色运动款（Red Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport01_co.paa" };
				class Lights : Lights {}; 
			};
			class UnmarkedBlue : UnmarkedBlack {
				displayName = "蓝色（Blue）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base03_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedBlueSport : UnmarkedBlack {
				displayName = "蓝色运动款（Blue Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedDarkBlue : UnmarkedBlack {
				displayName = "深蓝色（Dark Blue）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base04_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedDarkBlueSport : UnmarkedBlack {
				displayName = "深蓝运动款（Dark Blue Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport02_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedGreen : UnmarkedBlack {
				displayName = "绿色（Green）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base02_co.paa" };
				class Lights : Lights {};
			};
			class UnmarkedGreenSport : UnmarkedBlack {
				displayName = "绿色运动款（Green Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedYellow : UnmarkedBlack {
				displayName = "黄色（Yellow）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base06_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedOrangeSport : UnmarkedBlack {
				displayName = "橙色运动款（Orange Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport03_co.paa" }; 
				class Lights : Lights {};
			};

			// Medic
			class Medic : MedicTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Medic\hatchback.paa" }; 
				inventory[] = { 
					{ "Packing", 10 }, 
					{ "Elastic", 12 },  
					{ "BloodBag", 1 } 
				};
				class Lights : MedicColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};

			// Highways
			class Hato : HatoTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Hato\hatchback.paa" }; 
				class Lights : HatoColour {
					leftPos[] = {0.458496,1.77002,-0.899953};
					rightPos[] = {-0.52002,1.75732,-0.94257};
				};
			};

			// Civilian
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base09_co.paa" };
			};
			class BlackWhiteSport : BaseTexture {
				displayName = "黑白运动款（Black/White Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport04_co.paa" }; 
			};
			class Grey : BaseTexture {
				displayName = "灰色（Grey）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base08_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "白色（White）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base07_co.paa" }; 
			};
			class Beige : BaseTexture { 
				displayName = "米色（Beige）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base01_co.paa" }; 
			};
			class BeigeSport : BaseTexture { 
				displayName = "米色运动款（Beige Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport05_co.paa" }; 
			};
			class RedSport : BaseTexture { 
				displayName = "红色运动款（Red Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport01_co.paa" }; 
			};
			class Blue : BaseTexture { 
				displayName = "蓝色（Blue）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base03_co.paa" }; 
			};
			class BlueSport : BaseTexture { 
				displayName = "蓝色运动款（Blue Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE04_CO.paa" }; 
			};
			class DarkBlue : BaseTexture { 
				displayName = "深蓝色（Dark Blue）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base04_co.paa" }; 
			};
			class DarkBlueSport : BaseTexture { 
				displayName = "深蓝运动款（Dark Blue Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport02_co.paa" }; 
			};
			class Green : BaseTexture { 
				displayName = "绿色（Green）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base02_co.paa" }; 
			};
			class GreenSport : BaseTexture { 
				displayName = "绿色运动款（Green Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\Hatchback_01_ext_BASE02_CO.paa" }; 
			};
			class Yellow : BaseTexture { 
				displayName = "黄色（Yellow）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_base06_co.paa" }; 
			};
			class OrangeSport : BaseTexture { 
				displayName = "橙色运动款（Orange Sport）";
				textures[] = { "\a3\soft_f_gamma\Hatchback_01\data\hatchback_01_ext_sport03_co.paa" }; 
			};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};

			// Civilian Faction
			// class DMS : BaseTexture {
			// 	displayName = "DMS";
			// 	conditions = "[] call ULP_fnc_isDunamis";
			// 	textures[] = { "Data\Textures\Groups\DMS\Vehicles\hatchback.paa" };
			// };
		};
	};
	class C_Hatchback_01_sport_F : C_Hatchback_01_F { buyPrice = 276500; };

	class C_Offroad_01_F : Base {
		description = "这款由 Generic Motors 推出的 4x4 皮卡拥有耐用底盘和强劲发动机，专为应对地中海地区崎岖地形而设计。";
		buyPrice = 35800;
		virtualSpace = 60;
		class Textures {
			// Civilian
			class White : BaseTexture {
				displayName = "白色（White）";
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE02_CO.paa" 
				}; 
			};
			class Red : BaseTexture { 
				displayName = "红色（Red）";
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_co.paa" 
				}; 
			};
			class DarkRed : BaseTexture { 
				displayName = "深红色（DarkRed）";
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE04_CO.paa" 
				}; 
			};
			class Blue : BaseTexture { 
				displayName = "蓝色（Blue）";
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE03_CO.paa" 
				}; 
			};
			class BlueWhite : BaseTexture { 
				displayName = "蓝白配色（Blue/White）";
				textures[] = { 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa", 
					"\A3\soft_F\Offroad_01\Data\offroad_01_ext_BASE05_CO.paa" 
				}; 
			};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};

			// Civilian Faction
			// class DMS : BaseTexture {
			// 	displayName = "DMS";
			// 	conditions = "[] call ULP_fnc_isDunamis";
			// 	textures[] = { "Data\Textures\Groups\DMS\Vehicles\offroad.paa" };
			// };

			// Groups
			class Ridge : BaseTexture { 
				displayName = "山脊涂装（Ridge）";
				locked = true;
				textures[] = { "Data\Textures\Vehicles\Land\Civilian\Offroad\ridge.paa" }; 
			};
		};
	};
	class B_G_Offroad_01_armed_F : C_Offroad_01_F { 
		buyPrice = 4280000; 
		virtualSpace = 20;
		retrievalPerc = 0.15;
		garageLimit = 1;
		enableRope = false;
	};
	class B_GEN_Offroad_01_gen_F : C_Offroad_01_F {};
	class C_IDAP_Offroad_01_F : C_Offroad_01_F {
		whitelistedItems[] = { "HumanitarianSupplies" };
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP（IDAP）";
				textures[] = { 
					"\a3\soft_f_orange\Data\Offroad_01_ext_IDAP_CO.paa"
				}; 
			};
		};
	};
	class C_Offroad_01_covered_F : C_Offroad_01_F {
		buyPrice = 39100;
		virtualSpace = 75;
		class Textures {
			// Highways
			class Hato : HatoTexture { 
				displayName = "HATO（HATO）";
				textures[] = { "Data\Textures\Vehicles\Land\Hato\offroad.paa" }; 
			};

			// Civilian
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				textures[] = {
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_blk_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_blk_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_cover_blk_co.paa"
				}; 
			};
			class Green : BaseTexture { 
				displayName = "绿色（Green）";
				textures[] = { 
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_grn_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_ext_grn_co.paa",
					"\a3\soft_f_enoch\offroad_01\data\offroad_01_cover_grn_co.paa"
				}; 
			};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};
	class C_Offroad_01_comms_F : C_Offroad_01_covered_F { buyPrice = 44450; };
	class C_Offroad_01_repair_F : C_Offroad_01_covered_F { buyPrice = 44450; };

	class C_Offroad_02_unarmed_F : Base {
		description = "MB 4WD 是一款现代四驱越野车，拥有独特车身结构、强劲发动机、坚固底盘以及出色的机动性。";
		buyPrice = 31750;
		virtualSpace = 55;
		class Textures {
			// Police
			class Police : PoliceTexture { 
				displayName = "常规巡逻（General Response）";
				textures[] = { "Data\Textures\Vehicles\Land\Police\MB4.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.757324,1.83252,-0.379596};
					rightPos[] = {-0.844727,1.82861,-0.379596};
				};
			};

			// Medic
			class Medic : MedicTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Medic\MB4.paa" }; 
				inventory[] = { 
					{ "Packing", 25 }, 
					{ "Elastic", 25 },  
					{ "BloodBag", 2 } 
				};
				class Lights : MedicColour {
					leftPos[] = {0.757324,1.83252,-0.379596};
					rightPos[] = {-0.844727,1.82861,-0.379596};
				};
			};

			// Civilian
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_black_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "白色（White）";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_white_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "红色（Red）";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_red_co.paa" }; 
			};
			class Blue : BaseTexture { 
				displayName = "蓝色（Blue）";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_blue_co.paa" }; 
			};
			class Orange : BaseTexture { 
				displayName = "橙色（Orange）";
				textures[] = { "\A3\Soft_F_Exp\Offroad_02\Data\offroad_02_ext_orange_co.paa" }; 
			};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};

			// Civilian Faction
			// class DMS : BaseTexture {
			// 	displayName = "DMS";
			// 	conditions = "[] call ULP_fnc_isDunamis";
			// 	textures[] = { "Data\Textures\Groups\DMS\Vehicles\mb4.paa" };
			// };

			// Groups
			class Ridge : BaseTexture { 
				displayName = "山脊涂装（Ridge）";
				locked = true;
				textures[] = { "Data\Textures\Vehicles\Land\Civilian\MB4_WD\ridge.paa" }; 
			};
		};
	};
	class C_IDAP_Offroad_02_unarmed_F : C_Offroad_02_unarmed_F {
		whitelistedItems[] = { "HumanitarianSupplies" };
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP（IDAP）";
				textures[] = { 
					"\a3\soft_f_orange\Data\Offroad_02_ext_IDAP_CO.paa"
				}; 
			};
		};
	};
	class I_C_Offroad_02_LMG_F : C_Offroad_02_unarmed_F { 
		buyPrice = 670300; 
		virtualSpace = 45;
		retrievalPerc = 0.1;
		garageLimit = 1;
		enableRope = false;
	};

	class C_SUV_01_F : Base {
		description = "这是一款全尺寸豪华跨界 SUV，虽然并不特别适合重度越野，但公路表现优秀。强劲发动机和 4x4 系统让高速驾驶也十分从容。";
		buyPrice = 54200;
		virtualSpace = 45;
		class Textures {
			// Police
			class PoliceWhite : PoliceTexture { 
				displayName = "常规巡逻（General Response）";
				textures[] = { "Data\Textures\Vehicles\Land\Police\SUV_white.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};
			class PoliceBlack : PoliceWhite { 
				displayName = "武装巡逻（Armed Response）";
				conditions = "[""Police_SCO"", 1] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
				textures[] = { "Data\Textures\Vehicles\Land\Police\SUV_black.paa" };
				class Lights : PoliceColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				}; 
			};
			class PoliceANPR : PoliceWhite { 
				displayName = "ANPR 拦截车（ANPR Interceptor）";
				conditions = "[""Police_RPU"", 1] call ULP_fnc_hasAccess";
				anpr = true;
				textures[] = { "Data\Textures\Vehicles\Land\Police\SUV_ANPR.paa" };
				inventory[] = { 
					{ "Stinger", 1 },
					{ "RoadCone_F", 4 }
				};
				class Lights : PoliceColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				}; 
			};
			class UnmarkedBlack : PoliceTexture {
				displayName = "黑色（Black）";
				conditions = "[""Police_RPU"", 2] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess } || { [""Police_SEG"", 1] call ULP_fnc_hasAccess }";
				anpr = true;
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_02_co.paa" }; 
				inventory[] = { 
					{ "Stinger", 1 },
					{ "RoadCone_F", 4 }
				};
				class Lights : PoliceColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};
			class UnmarkedSilver : UnmarkedBlack {
				displayName = "银色（Silver）";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_03_co.paa" }; 
				class Lights : Lights {};
			};
			class UnmarkedRed : UnmarkedBlack {
				displayName = "红色（Red）";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_co.paa" };  
				class Lights : Lights {};
			};
			class UnmarkedOrange : UnmarkedBlack {
				displayName = "橙色（Orange）";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_04_co.paa" }; 
				class Lights : Lights {};
			};

			// Medic
			class Medic : MedicTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Medic\SUV.paa" }; 
				inventory[] = { 
					{ "Packing", 20 }, 
					{ "Elastic", 20 },  
					{ "BloodBag", 2 } 
				};
				class Lights : MedicColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};

			// Highways
			class Hato : HatoTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Hato\SUV.paa" }; 
				class Lights : HatoColour {
					leftPos[] = {0.370605,2.22021,-0.531462};
					rightPos[] = {-0.396484,2.22119,-0.531462};
				};
			};

			// Civilian
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_02_co.paa" }; 
			};
			class Silver : BaseTexture { 
				displayName = "银色（Silver）";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_03_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "红色（Red）";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_co.paa" }; 
			};
			class Orange : BaseTexture { 
				displayName = "橙色（Orange）";
				textures[] = { "\a3\soft_f_gamma\SUV_01\Data\suv_01_ext_04_co.paa" };
			};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};

			// CIvilian Faction
			// class DMS : BaseTexture {
			// 	displayName = "DMS";
			// 	conditions = "[] call ULP_fnc_isDunamis";
			// 	textures[] = { "Data\Textures\Groups\DMS\Vehicles\suv.paa" };
			// };
		};
	};

	class C_Van_02_transport_F : Base {
		description = "这款厢式车用途广泛，拥有较长的装载空间和出色的车内高度，可用于运送乘客、货物，甚至小型载具。";
		buyPrice = 68000;
		virtualSpace = 90;
		enableRope = false;
		class Textures {
			// Police
			class PoliceWhite : PoliceTexture { 
				displayName = "公共秩序（Public Order）";
				textures[] = { "Data\Textures\Vehicles\Land\Police\van.paa" }; 
				animations[] = { { "beacon_front_hide", 0 }, { "beacon_rear_hide", 0 }, { "lights_em_hide", 0 } };
			};
			class UnmarkedBlack : PoliceTexture {
				displayName = "黑色（Black）";
				conditions = "[""Police_RPU"", 2] call ULP_fnc_hasAccess || { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_black_CO.paa" }; 
			};
			class UnmarkedWhite : UnmarkedBlack {
				displayName = "白色（White）";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_white_CO.paa" }; 
			};
			class UnmarkedRed : UnmarkedBlack {
				displayName = "红色（Red）";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Red_CO.paa" }; 
			};
			class UnmarkedOrange : UnmarkedBlack {
				displayName = "橙色（Orange）";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Orange_CO.paa" }; 
			};

			// Medic
			class Medic : MedicTexture { 
				displayName = "救护车（Ambulance）";
				conditions = "[""Medic_Main"", 1] call ULP_fnc_hasAccess";
				textures[] = { "Data\Textures\Vehicles\Land\Medic\van.paa" }; 
				inventory[] = { 
					{ "Packing", 30 }, 
					{ "Elastic", 50 },  
					{ "BloodBag", 5 } 
				};
				animations[] = { { "beacon_front_hide", 0 }, { "beacon_rear_hide", 0 }, { "LED_lights_hide", 0 }, { "lights_em_hide", 0 } };
			};

			// Highways
			class Hato : HatoTexture { 
				displayName = "HATO（HATO）";
				conditions = "[""Hato_Main"", 1] call ULP_fnc_hasAccess";
				textures[] = { "Data\Textures\Vehicles\Land\Hato\van.paa" }; 
			};

			// Civilian
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_black_CO.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "白色（White）";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_white_CO.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "红色（Red）";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Red_CO.paa" }; 
			};
			class Orange : BaseTexture { 
				displayName = "橙色（Orange）";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_Orange_CO.paa" }; 
			};
			class Press : BaseTexture { 
				displayName = "媒体（Press）";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_AAN_CO.paa" }; 
			};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};

			// Civilian Faction
			// class DMS : BaseTexture {
			// 	displayName = "DMS";
			// 	conditions = "[] call ULP_fnc_isDunamis";
			// 	textures[] = { "Data\Textures\Groups\DMS\Vehicles\van.paa" };
			// };
		};
	};
	class B_GEN_Van_02_transport_F : C_Van_02_transport_F {};
	class C_Van_02_medevac_F : C_Van_02_transport_F { virtualSpace = 150; };
	class C_IDAP_Van_02_transport_F : C_Van_02_transport_F {
		whitelistedItems[] = { "HumanitarianSupplies" };
		class Textures {
			class IDAP : BaseTexture { 
				displayName = "IDAP（IDAP）";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_IDAP_CO.paa" }; 
			};
		};
	};
	class C_Van_02_vehicle_F : C_Van_02_transport_F {
		buyPrice = 86650;
		virtualSpace = 110;
	};
	class B_GEN_Van_02_vehicle_F : C_Van_02_vehicle_F {};
	class C_IDAP_Van_02_vehicle_F : C_Van_02_vehicle_F {
		whitelistedItems[] = { "HumanitarianSupplies" };
		class Textures {
			class IDAP : BaseTexture { 
				displayName = "IDAP（IDAP）";
				textures[] = { "\a3\soft_f_orange\van_02\data\van_body_IDAP_CO.paa" }; 
			};
		};
	};
	class C_Van_02_service_F : C_Van_02_vehicle_F {};

	class B_CTRG_LSV_01_light_F : Base {
		description = "Prowler 机动灵活、装甲较轻，主要依靠速度、操控性和越野能力来规避威胁。";
		buyPrice = 380000;
		virtualSpace = 50;
		class Textures {
			// Police
			class Police : PoliceTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Police\prowler.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {0.75293,1.99902,-0.930151};
					rightPos[] = {-0.681152,2.01074,-0.930151};
				};
			};

			// Civilian
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				textures[] = { 
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_black_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_black_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_black_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_black_co.paa" 
				}; 
			};
			class Sand : BaseTexture { 
				displayName = "沙地色（Sand）";
				textures[] = { 
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_sand_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_sand_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_sand_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_sand_co.paa"
				}; 
			};
			class Olive : BaseTexture { 
				displayName = "橄榄绿（Olive）";
				textures[] = { 
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_01_olive_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_02_olive_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_03_olive_co.paa",
					"\a3\soft_f_exp\lsv_01\data\nato_lsv_adds_olive_co.paa"
				}; 
			};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};
	class B_LSV_01_unarmed_black_F : B_CTRG_LSV_01_light_F { buyPrice = 385000; };

	class O_LSV_02_unarmed_F : Base {
		description = "Qilin 兼顾安全与速度，拥有优秀的机动性和操控性，能够适应严苛、崎岖且受限的复杂地形。";
		buyPrice = 475000;
		virtualSpace = 50;
		class Textures {
			// Police
			class Police : PoliceTexture { 
				textures[] = { "Data\Textures\Vehicles\Land\Police\qilin.paa" }; 
				class Lights : PoliceColour {
					leftPos[] = {0.615234,2.03467,-0.40501};
					rightPos[] = {-0.943359,2.02881,-0.398304};
				};
			};

			// Civilian
			class Black : BaseTexture { 
				displayName = "黑色（Black）";
				textures[] = { "\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_01_black_CO.paa", }; 
			};
			class Hex : BaseTexture { 
				displayName = "六角迷彩（Hex）";
				textures[] = { "\a3\soft_f_exp\LSV_02\Data\CSAT_LSV_01_arid_CO.paa", }; 
			};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};

			// Civilian Faction
			// class DMS : BaseTexture {
			// 	displayName = "DMS";
			// 	conditions = "[] call ULP_fnc_isDunamis";
			// 	textures[] = { "Data\Textures\Groups\DMS\Vehicles\qilin.paa" };
			// };
		};
	};
	class O_LSV_02_armed_black_F : O_LSV_02_unarmed_F { 
		buyPrice = 6590000; 
		garageLimit = 1;
		retrievalPerc = 0.15;
		enableRope = false;
	};

	class B_MRAP_01_F : Base {
		description = "Hunter 是一款 MRAP 防雷反伏击载具，装甲车体能够抵御轻型武器攻击，同时搭载强劲发动机。";
		buyPrice = 9800000;
		virtualSpace = 65;
		garageLimit = 2;
		class Textures {
			class Police : PoliceTexture {
				textures[] = {
					"Data\Textures\Vehicles\Land\Police\hunter_01.paa",
					"Data\Textures\Vehicles\Land\Police\hunter_02.paa"
				}; 
				upgrades[] = { 
					"TrackingDeviceUpgrade",
					"ImprovedLocksUpgrade",
					"ImprovedHullUpgrade",
					"ImprovedTyresUpgrade" 
				};
				class Siren { SFX[] = { "Siren_7", "Siren_8", "Siren_9" }; };
				class Lights : PoliceColour {
					leftPos[] = {0.95459,-2.73975,0.559029};
					rightPos[] = {-0.94873,-2.73975,0.557981};
				};
			};

			class ChromeGreen : BaseChromeGreen {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\green.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\green.rvmat"
				};
			};
			class ChromeBlue : BaseChromeBlue {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\blue.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\blue.rvmat"
				};
			};
			class ChromeRed : BaseChromeRed {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\red.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\red.rvmat"
				};
			};
			class ChromeSilver : BaseChromeSilver {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\silver.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\silver.rvmat"  
				};
			};
			class ChromeGold : BaseChromeGold {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\gold.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\gold.rvmat"  
				};
			};
		};
	};

	class O_MRAP_02_F : B_MRAP_01_F {
		description = "Ifrit 是一款在俄罗斯设计制造的 MRAP 载具，其优势在于极端天气下的可靠性以及对乘员的良好保护。";
		buyPrice = 5500000;
		virtualSpace = 65;
		turrets[] = {};
		class Textures {
			// Civilian
			class Hex : BaseTexture { 
				displayName = "六角迷彩（Hex）";
				textures[] = { 
					"\A3\soft_F\MRAP_02\data\MRAP_02_ext_01_CO.paa", 
					"\A3\soft_F\MRAP_02\data\MRAP_02_ext_02_CO.paa"
				}; 
			};
			class GoldLine : BaseTexture { 
				displayName = "金线涂装（Gold Line）";
				buyPrice = 450000;
				condition = "[] call ULP_fnc_donatorLevel >= 2"; 
				textures[] = { 
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\goldLine_01.paa",
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\goldLine_02.paa"
				}; 
			};
			class Oil : GoldLine { 
				displayName = "油污涂装（Oil Spill）";
				buyPrice = 315700;
				textures[] = { 
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\oil_01.paa",
					"Data\Textures\Vehicles\Land\Civilian\Ifrit\oil_02.paa"
				}; 
			};

			class ChromeGreen : BaseChromeGreen {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\green.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\green.rvmat"
				};
			};
			class ChromeBlue : BaseChromeBlue {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\blue.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\blue.rvmat"
				};
			};
			class ChromeRed : BaseChromeRed {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\red.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\red.rvmat"
				};
			};
			class ChromeSilver : BaseChromeSilver {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\silver.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\silver.rvmat"  
				};
			};
			class ChromeGold : BaseChromeGold {
				materials[] = { 
					"Data\Textures\Vehicles\Global\Chrome\gold.rvmat",
					"Data\Textures\Vehicles\Global\Chrome\gold.rvmat"  
				};
			};

			// Civilian Faction
			// class DMS : BaseTexture {
			// 	displayName = "DMS";
			// 	conditions = "[] call ULP_fnc_isDunamis";
			// 	textures[] = { 
			// 		"Data\Textures\Groups\DMS\Vehicles\ifrit_01.paa",
			// 		"Data\Textures\Groups\DMS\Vehicles\ifrit_02.paa"
			// 	};
			// };
		};
	};

	class I_MRAP_03_F : B_MRAP_01_F {
		description = "Strider 是一款中型全地形载具，具备两栖能力并强化了乘员防护，适合执行侦察与运兵任务。";
		buyPrice = 3550000;
		virtualSpace = 65;
		turrets[] = {};
		class Textures {
			class Tan : BaseTexture { 
				displayName = "沙色（Tan）";
				textures[] = { 
					"\A3\soft_f_beta\mrap_03\data\mrap_03_ext_co.paa", 
					"\A3\data_f\vehicles\turret_co.paa"
				}; 
			};
			class Asiimov : BaseTexture { 
				displayName = "艾西莫夫（Asiimov）";
				locked = true;
				textures[] = { "Data\Textures\Vehicles\Land\Civilian\Strider\asiimov.paa" }; 
			};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};

	// TRUCKS --------------------------------------------------------------------------------------
	class C_Tractor_01_F : BaseTruck {
		description = "这种常见拖拉机遍布世界各地的农场与谷仓，是一款高扭矩且可靠的工程车辆，可用于牵引拖车和执行多种农业任务。";
		buyPrice = 23150;
		virtualSpace = 10;
		class Textures {
			class Red : BaseTexture {
				displayName = "红色（Red）";
				textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_red_co.paa" }; 
			};
			class Blue : BaseTexture { 
				displayName = "蓝色（Blue）";
				textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_blue_co.paa" }; 
			};
			class Green : BaseTexture { 
				displayName = "绿色（Green）";
				textures[] = { "\a3\soft_f_enoch\tractor_01\data\tractor_01_2_green_co.paa" }; 
			};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};

	class C_Van_01_transport_F : BaseTruck {
		description = "这款民用 4x4 卡车具备很高的可定制性和越野能力。它延续了复古外观设计，同时采用现代发动机与电子系统。";
		buyPrice = 105500;
		virtualSpace = 125;
		class Textures {
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_black_co.paa" }; 
			};
			class White : BaseTexture { 
				displayName = "白色（White）";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_co.paa" }; 
			};
			class Red : BaseTexture { 
				displayName = "红色（Red）";
				textures[] = { "\a3\soft_f_gamma\Van_01\Data\van_01_ext_red_co.paa" }; 
			};
			class Brown : BaseTexture { 
				displayName = "棕色（Brown）";
				textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_brn_co.paa" }; 
			};
			class Olive : BaseTexture { 
				displayName = "橄榄绿（Olive）";
				textures[] = { "\a3\soft_f_exp\van_01\data\van_01_ext_oli_co.paa" }; 
			};
			class Aldsa : BaseTexture {
				displayName = "阿尔德萨（Aldsa）";
				locked = true;
				textures[] = { 
					"Data\Textures\Vehicles\Land\Civilian\Truck\aldsa_01.paa", 
					"Data\Textures\Vehicles\Land\Civilian\Truck\aldsa_02.paa"
				}; 
			};
		};
	};
	class C_Van_01_box_F : C_Van_01_transport_F {
		buyPrice = 145500;
		virtualSpace = 150;
	};
	class C_Van_01_fuel_F : C_Van_01_transport_F {
		buyPrice = 200000;
		virtualSpace = 100;
		whitelistedItems[] = { 
			"UnprocessedOil",
			"Fuel" 
		};
		class Textures {
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				textures[] = { 
					"\a3\soft_f_gamma\Van_01\Data\van_01_ext_black_co.paa", 
					"\a3\soft_f_gamma\Van_01\Data\Van_01_tank_CO.paa"
				}; 
			};
			class White : BaseTexture { 
				displayName = "白色（White）";
				textures[] = { 
					"\a3\soft_f_gamma\Van_01\Data\van_01_ext_co.paa", 
					"\a3\soft_f_gamma\Van_01\Data\Van_01_tank_CO.paa" 
				}; 
			};
			class Red : BaseTexture { 
				displayName = "红色（Red）";
				textures[] = { 
					"\a3\soft_f_gamma\Van_01\Data\van_01_ext_red_co.paa", 
					"\a3\soft_f_gamma\Van_01\Data\Van_01_tank_red_CO.paa" 
				}; 
			};
			class Brown : BaseTexture { 
				displayName = "棕色（Brown）";
				textures[] = { 
					"\a3\soft_f_exp\van_01\data\van_01_ext_brn_co.paa", 
					"\a3\soft_f_gamma\Van_01\Data\Van_01_tank_IG_CO.paa"  
				}; 
			};
			class Olive : BaseTexture { 
				displayName = "橄榄绿（Olive）";
				textures[] = { 
					"\a3\soft_f_exp\van_01\data\van_01_ext_oli_co.paa", 
					"\a3\soft_f_gamma\Van_01\Data\Van_01_tank_IG_CO.paa"  
				}; 
			};
		};
	};

	class I_Truck_02_transport_F : BaseTruck {
		description = "Zamak 重型卡车是一款 6x6 运输与多用途载具。它配备强劲的 V8 发动机，即使在恶劣环境下也依然可靠。";
		buyPrice = 505000;
		virtualSpace = 280;
		class Textures {
			class Orange : BaseTexture {
				displayName = "橙色（Orange）";
				textures[] = { 
					"\A3\Soft_F_Beta\Truck_02\data\truck_02_kab_co.paa", 
					"\a3\soft_f_beta\Truck_02\data\truck_02_kuz_co.paa"
				 }; 
			};
			class Blue : BaseTexture { 
				displayName = "蓝色（Blue）";
				textures[] = { 
					"\a3\soft_f_beta\truck_02\data\truck_02_kab_blue_co.paa",
					"\a3\soft_f_beta\truck_02\data\truck_02_kuz_co.paa",
					"\a3\soft_f_beta\truck_02\data\truck_02_int_co.paa"
				};
			}; 
		};
	};
	class C_IDAP_Truck_02_transport_F : I_Truck_02_transport_F {
		whitelistedItems[] = { "HumanitarianSupplies" };
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP（IDAP）";
				textures[] = { 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kab_IDAP_CO.paa",
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kuz_IDAP_CO.paa", 
				 }; 
			};
		};
	};
	class I_Truck_02_covered_F : I_Truck_02_transport_F {
		buyPrice = 560000;
		virtualSpace = 350;
	};
	class C_IDAP_Truck_02_F : I_Truck_02_covered_F {
		whitelistedItems[] = { "HumanitarianSupplies" };
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP（IDAP）";
				textures[] = { 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kab_IDAP_CO.paa", 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kuz_IDAP_CO.paa", 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_int_IDAP_CO.paa"
				 }; 
			};
		};
	};
	class I_Truck_02_fuel_F : I_Truck_02_transport_F {
		buyPrice = 750000;
		virtualSpace = 300;
		whitelistedItems[] = { 
			"UnprocessedOil",
			"Fuel" 
		};
		class Textures {
			class Orange : BaseTexture {
				displayName = "橙色（Orange）";
				textures[] = { 
					"\A3\Soft_F_Beta\Truck_02\data\truck_02_kab_co.paa", 
					"\a3\soft_f_beta\Truck_02\data\truck_02_fuel_co.paa"
				 }; 
			};
			class Blue : BaseTexture { 
				displayName = "蓝色（Blue）";
				textures[] = { 
					"\a3\soft_f_beta\truck_02\data\truck_02_kab_blue_co.paa",
					"\a3\soft_f_beta\truck_02\data\truck_02_fuel_co.paa"
				};
			}; 
		};
	};
	class C_IDAP_Truck_02_water_F : I_Truck_02_fuel_F {
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP（IDAP）";
				textures[] = { 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_kab_IDAP_CO.paa", 
					"\a3\soft_f_orange\Truck_02\Data\truck_02_water_IDAP_CO.paa"
				 }; 
			};
		};
	};

	class O_Truck_03_transport_F : BaseTruck {
		description = "Tempest 是一款 6x6 标准运输卡车，并具备防雷能力。模块化设计让它能够衍生出多种运输版本。";
		buyPrice = 850550;
		virtualSpace = 370;
		class Textures {
			class BrownHex : BaseTexture {
				displayName = "棕色六角迷彩（Brown Hex）";
				textures[] = { 
					"\a3\soft_f_epc\truck_03\data\truck_03_ext01_co.paa",
					"\a3\soft_f_epc\truck_03\data\truck_03_ext02_co.paa",
					"\a3\soft_f_epc\truck_03\data\truck_03_cargo_co.paa"
				 }; 
			};
			class GreenHex : BaseTexture { 
				displayName = "绿色六角迷彩（Green Hex）";
				textures[] = { 
					"\a3\soft_f_exp\truck_03\data\truck_03_ext01_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_ext02_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_cargo_ghex_co.paa"
				};
			}; 
		};
	};
	class O_Truck_03_covered_F : O_Truck_03_transport_F {
		buyPrice = 988600;
		virtualSpace = 410;
		class Textures {
			class BrownHex : BaseTexture {
				displayName = "棕色六角迷彩（Brown Hex）";
				textures[] = { 
					"\a3\soft_f_epc\truck_03\data\truck_03_ext01_co.paa",
					"\a3\soft_f_epc\truck_03\data\truck_03_ext02_co.paa",
					"\a3\soft_f_epc\truck_03\data\truck_03_cover_co.paa"
				 }; 
			};
			class GreenHex : BaseTexture { 
				displayName = "绿色六角迷彩（Green Hex）";
				textures[] = { 
					"\a3\soft_f_exp\truck_03\data\truck_03_ext01_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_ext02_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_cover_ghex_co.paa"
				};
			}; 
		};
	};
	class O_Truck_03_repair_F : O_Truck_03_transport_F {
		buyPrice = 1398000;
		virtualSpace = 485;
	};
	class O_Truck_03_ammo_F : O_Truck_03_transport_F {
		buyPrice = 1280000;
		virtualSpace = 460;
	};
	class O_Truck_03_fuel_F : O_Truck_03_transport_F {
		buyPrice = 1500000;
		virtualSpace = 450;
		whitelistedItems[] = { 
			"UnprocessedOil",
			"Fuel" 
		};
		class Textures {
			class BrownHex : BaseTexture {
				displayName = "棕色六角迷彩（Brown Hex）";
				textures[] = { 
					"\a3\soft_f_epc\truck_03\data\truck_03_ext01_co.paa",
					"\a3\soft_f_epc\truck_03\data\truck_03_ext02_co.paa",
					"\a3\soft_f_epc\truck_03\data\truck_03_fuel_co.paa"
				 }; 
			};
			class GreenHex : BaseTexture { 
				displayName = "绿色六角迷彩（Green Hex）";
				textures[] = { 
					"\a3\soft_f_exp\truck_03\data\truck_03_ext01_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_ext02_ghex_co.paa",
					"\a3\soft_f_exp\truck_03\data\truck_03_fuel_ghex_co.paa"
				};
			}; 
		};
	};
	class O_Truck_03_device_F : O_Truck_03_transport_F {
		buyPrice = 7200000;
		virtualSpace = 150;
		garageLimit = 1;
	};

	class B_Truck_01_mover_F : BaseTruck {
		description = "HEMTT（Heavy Expanded Mobility Tactical Truck）是一款 8x8 柴油越野卡车，拥有多个不同版本，可覆盖基础运输需求。";
		buyPrice = 478500;
		virtualSpace = 10;
		garageLimit = 1;
		class Textures {
			class Hato : HatoTexture { 
				displayName = "HATO（HATO）";
				textures[] = { 
					"data\textures\vehicles\land\HATO\hemtt_1.paa",
					"data\textures\vehicles\land\HATO\hemtt_2.paa",
					"data\textures\vehicles\land\HATO\hemtt_primer.paa"
				};
				class Lights : HatoColour {
					leftPos[] = {0.814453,5.87402,-0.947113};
					rightPos[] = {-0.736816,5.86328,-0.947113};
				};
			}; 
		};
	};
	class B_Truck_01_flatbed_F : B_Truck_01_mover_F {
		buyPrice = 492450;
		virtualSpace = 10;
		class Textures {
			class Hato : HatoTexture { 
				displayName = "HATO（HATO）";
				textures[] = { 
					"data\textures\vehicles\land\HATO\hemtt_1.paa",
					"data\textures\vehicles\land\HATO\hemtt_2.paa",
					"data\textures\vehicles\land\HATO\hemtt_flatbed.paa"
				};
				class Lights : HatoColour {
					leftPos[] = {0.814453,5.87402,-0.947113};
					rightPos[] = {-0.736816,5.86328,-0.947113};
				};
			}; 
		};
	};
	class B_Truck_01_cargo_F : B_Truck_01_mover_F {
		buyPrice = 1170000;
		virtualSpace = 450;
		class Textures {
			class Sand : BaseTexture {
				displayName = "沙地色（Sand）";
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_ammo_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_cargo_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "橄榄绿（Olive）";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_ammo_pacific_co.paa",
					"\a3\soft_f_enoch\truck_01\data\truck_01_cargo_pacific_co.paa"
				};
			}; 
		};
	};
	class B_Truck_01_transport_F : B_Truck_01_mover_F {
		buyPrice = 1596500;
		virtualSpace = 535;
		class Textures {
			class Sand : BaseTexture {
				displayName = "沙地色（Sand）";
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_cargo_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "橄榄绿（Olive）";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_cargo_olive_co.paa"
				};
			}; 
		};
	};
	class B_Truck_01_covered_F : B_Truck_01_transport_F {
		buyPrice = 1834550;
		virtualSpace = 590;
		class Textures {
			class Sand : BaseTexture {
				displayName = "沙地色（Sand）";
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_cargo_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_cover_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "橄榄绿（Olive）";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_cargo_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_cover_olive_co.paa"
				};
			}; 
		};
	};
	class B_Truck_01_ammo_F : B_Truck_01_transport_F {
		buyPrice = 2156000;
		virtualSpace = 650;
		class Textures {
			class Sand : BaseTexture {
				displayName = "沙地色（Sand）";
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_gamma\truck_01\data\truck_01_ammo_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "橄榄绿（Olive）";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ammo_olive_co.paa"
				};
			}; 
		};
	};
	class B_Truck_01_fuel_F : B_Truck_01_transport_F {
		buyPrice = 3000000;
		virtualSpace = 750;
		whitelistedItems[] = { 
			"UnprocessedOil",
			"Fuel" 
		};
		class Textures {
			class Sand : BaseTexture {
				displayName = "沙地色（Sand）";
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_gamma\truck_01\data\truck_01_fuel_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "橄榄绿（Olive）";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_fuel_olive_co.paa"
				};
			}; 
		};
	};
	class B_Truck_01_box_F : B_Truck_01_transport_F {
		buyPrice = 2610000;
		virtualSpace = 800;
		class Textures {
			class Sand : BaseTexture {
				displayName = "沙地色（Sand）";
				textures[] = { 
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_01_co.paa",
					"\a3\soft_f_beta\truck_01\data\truck_01_ext_02_co.paa",
					"\a3\soft_f_gamma\truck_01\data\truck_01_mprimer_co.paa",
					"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
				 }; 
			};
			class Olive : BaseTexture { 
				displayName = "橄榄绿（Olive）";
				textures[] = { 
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_01_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ext_02_olive_co.paa",
					"\a3\soft_f_exp\truck_01\data\truck_01_ammo_olive_co.paa",
					"\a3\structures_f\data\metal\containers\containers_02_set_co.paa"
				};
			}; 
			class Ridge : BaseTexture { 
				displayName = "山脊涂装（Ridge）";
				locked = true;
				textures[] = { 
					"data\textures\vehicles\land\civilian\ridge_hemtt_1.paa",
					"data\textures\vehicles\land\civilian\ridge_hemtt_2.paa",
					"data\textures\vehicles\land\civilian\ridge_hemtt_3.paa",
					"data\textures\vehicles\land\civilian\ridge_hemtt_4.paa"
				};
			}; 
		};
	};

	// ARMOURED -----------------------------------------------------------------------------------
	class B_AFV_Wheeled_01_cannon_F : Base {
		description = "Rhino MGS 是一款轮式坦克歼击车，便于快速运送到危机地区。其轻量化 120mm 火炮可使用常规炮弹，有效射程最高可达 8km。";
		buyPrice = 67800000;
		virtualSpace = 30;
		garageLimit = 1;
		canTransfer = false;
		canChop = false;
		turrets[] = {};
	};
	class I_LT_01_scout_F : B_AFV_Wheeled_01_cannon_F {
		description = "AWC 300 Nyx 是一款小型轻装甲履带载具，配备强力雷达，能够在远距离发现潜在威胁。";
		buyPrice = 20150000;
		virtualSpace = 5;
	};

	// BOATS --------------------------------------------------------------------------------------
	class C_Scooter_Transport_01_F : BaseShip {
		description = "这是一种坐式个人水上摩托，强劲的引擎和灵活的操控让它驾驶起来非常有乐趣。";
		buyPrice = 14300;
		virtualSpace = 5;
		whitelistedItems[] = { "StolenCargo" };
		class Textures {
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_black_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_black_co.paa"
				 }; 
			};
			class White : BaseTexture { 
				displayName = "白色（White）";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_White_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_White_co.paa"
				};
			}; 
			class Grey : BaseTexture { 
				displayName = "灰色（Grey）";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Grey_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Grey_co.paa"
				};
			}; 
			class Red : BaseTexture { 
				displayName = "红色（Red）";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Red_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Red_co.paa"
				};
			}; 
			class Blue : BaseTexture { 
				displayName = "蓝色（Blue）";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_blue_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_blue_co.paa"
				};
			}; 
			class Green : BaseTexture { 
				displayName = "绿色（Green）";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Green_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Green_co.paa"
				};
			}; 
			class Yellow : BaseTexture { 
				displayName = "黄色（Yellow）";
				textures[] = { 
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_Yellow_co.paa",
					"\a3\boat_f_exp\scooter_transport_01\data\scooter_transport_01_vp_Yellow_co.paa"
				};
			}; 

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};

	class C_Rubberboat : BaseShip {
		description = "充气艇常被昵称为“rubber duck”，是一种由充气气室构成的轻型船只。";
		buyPrice = 4150;
		virtualSpace = 50;
	};

	class C_Boat_Civil_01_F : BaseShip {
		description = "这款豪华摩托艇采用引擎驱动，既是 Police 的常用船只之一，也深受阿尔蒂斯富人青睐。";
		buyPrice = 153200;
		virtualSpace = 75;
		class Textures {
			class Civilian : BaseTexture {}; 
			class Police : PoliceTexture { textures[] = { "Data\Textures\Vehicles\Sea\Police\motorboat.paa" }; };
			class Medic : MedicTexture { textures[] = { "Data\Textures\Vehicles\Sea\Medic\motorboat.paa" }; };

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};
	class C_Boat_Civil_01_police_F : C_Boat_Civil_01_F {};

	class C_Boat_Transport_02_F : BaseShip {
		description = "这款海军特种作战 RHIB（刚性充气艇）速度快、浮力高、可全天候使用，设计上可搭载一支全副武装的 8 人小队及 3 名船员。";
		buyPrice = 297600;
		virtualSpace = 125;
		class Textures {
			class Civilian : BaseTexture {}; 
			class Police : PoliceTexture {
				textures[] = { 
					"Data\Textures\Vehicles\Sea\Police\RHIB_01.paa",
					"Data\Textures\Vehicles\Sea\Police\RHIB_02.paa"
				}; 
			};
			class Medic : MedicTexture {};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};
	class I_C_Boat_Transport_02_F : C_Boat_Transport_02_F {};

	class B_Boat_Armed_01_minigun_F : BaseShip {
		description = "这款快艇在速度和机动性方面表现出色，常用于海岸巡防和特种作战任务。";
		buyPrice = 14360500;
		virtualSpace = 80;
		garageLimit = 1;
		enableRope = false;
		turrets[] = { { { 1 },  { "LMG_Minigun" },  { "2000Rnd_65x39_belt_Tracer_Red" } } };
		class Textures {
			class Police : PoliceTexture {
				textures[] = { 
					"Data\Textures\Vehicles\Sea\Police\speedboat_01.paa", 
					"Data\Textures\Vehicles\Sea\Police\speedboat_02.paa"
				};
			};
		};
	};

	class B_SDV_01_F : BaseShip {
		description = "SDV 是一种有人潜航器，可在水下长距离运送潜水小队，队员既可依附艇体行动，也可使用自带的 SCUBA 装备。";
		buyPrice = 389500;
		virtualSpace = 5;
		class Textures {
			class Police : PoliceTextureBase {
				displayName = "MPU（MPU）";
				textures[] = { "Data\Textures\Vehicles\Sea\Police\sdv.paa" }; 
			};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};

	// HELICOPTERS --------------------------------------------------------------------------------------
	class B_UAV_01_F : BaseHeli {
		description = "Darter AR-2 是一款微型遥控四旋翼无人机，非常适合执行侦察和监视任务。";
		buyPrice = 98700;
	};
	class C_UAV_06_medical_F : B_UAV_01_F {
		description = "这款现成商用多用途无人机采用 6 旋翼设计，可在外部货舱中运送小型载荷。";
		buyPrice = 109700;
	};
	
	class C_Heli_Light_01_civil_F : BaseHeli {
		description = "这是一款轻型单发直升机，自越战时期起就被美军用于多种特种作战任务。";
		buyPrice = 465000;
		virtualSpace = 5;
		class Textures {
			// Police
			class Police : PoliceTextureBase { 
				displayName = "NPAS（NPAS）";
				textures[] = { "Data\Textures\Vehicles\Air\Police\hummingbird.paa" }; 
			};
			class PoliceSEG : PoliceTextureBase { 
				displayName = "SEG（SEG）";
				conditions = "[""Police_SEG"", 1] call ULP_fnc_hasAccess";
				textures[] = { "Data\Textures\Vehicles\Air\Police\PMHummingbird.paa" }; 
			};

			// Medic
			class Medic : MedicTextureBase { textures[] = { "Data\Textures\Vehicles\Air\Medic\hummingbird.paa" }; };

			// Civilian
			class TotalRed : BaseTexture {
				displayName = "全红涂装（Total Red）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_co.paa" }; 
			};
			class TotalBlue : BaseTexture { 
				displayName = "全蓝涂装（Total Blue）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa" };
			}; 
			class Sheriff : BaseTexture { 
				displayName = "治安官（Sheriff）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa" };
			}; 
			class Blueline : BaseTexture { 
				displayName = "蓝线涂装（Blueline）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueline_co.paa" };
			}; 
			class Elliptical : BaseTexture { 
				displayName = "椭圆涂装（Elliptical）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa" };
			}; 
			class Furious : BaseTexture { 
				displayName = "狂怒涂装（Furious）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa" };
			}; 
			class JeansBlue : BaseTexture { 
				displayName = "牛仔蓝（Jeans Blue）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa" };
			}; 
			class SpeedyRedline : BaseTexture { 
				displayName = "极速红线（Speedy Redline）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa" };
			}; 
			class Sunset : BaseTexture { 
				displayName = "落日涂装（Sunset）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa" };
			}; 
			class Vrana : BaseTexture { 
				displayName = "弗拉纳（Vrana）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa" };
			}; 
			class WavesBlue : BaseTexture { 
				displayName = "海浪蓝（Waves Blue）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa" };
			}; 
			class Shadow : BaseTexture { 
				displayName = "暗影涂装（Shadow）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\Heli_Light_01_ext_shadow_co.paa" };
			}; 
			class GrayWatcher : BaseTexture { 
				displayName = "灰色守望者（Gray Watcher）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\Heli_Light_01_ext_graywatcher_co.paa" };
			}; 
			class Wasp : BaseTexture { 
				displayName = "黄蜂涂装（Wasp）";
				textures[] = { "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wasp_co.paa" };
			}; 

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};

			// Civilian Faction
			// class DMS : BaseTexture {
			// 	displayName = "DMS";
			// 	conditions = "[] call ULP_fnc_isDunamis";
			// 	textures[] = { "Data\Textures\Groups\DMS\Vehicles\hummingbird.paa" };
			// };
		};
	};
	class B_Heli_Light_01_F : C_Heli_Light_01_civil_F { buyPrice = 580000; };
	class B_Heli_Light_01_armed_F : C_Heli_Light_01_civil_F { 
		buyPrice = 9050000; 
		garageLimit = 1;
		class Textures : Textures {
			// class DMS : DMS {
			// 	turrets[] = { { { -1 },  { "M134_minigun" },  { "5000Rnd_762x51_Yellow_Belt" } } };
			// };
		};
	};

	class O_Heli_Light_02_unarmed_F : BaseHeli {
		description = "PO-30 Orca 是一款以运输和通用支援为主的直升机，最初主要为俄罗斯空军开发。";
		buyPrice = 1850000;
		virtualSpace = 25;
		class Textures {
			class Police : PoliceTextureBase { textures[] = { "Data\Textures\Vehicles\Air\Police\orca.paa" }; };
			class Medic : MedicTextureBase { 
				textures[] = { "Data\Textures\Vehicles\Air\Medic\orca.paa" };
				inventory[] = { 
					{ "Packing", 10 }, 
					{ "Elastic", 12 },  
					{ "BloodBag", 1 } 
				}; 
			};

			// Civilian
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				textures[] = { "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_CO.paa" }; 
			};
			class BlackWhite : BaseTexture {
				displayName = "黑白配色（Black / White）";
				textures[] = { "\a3\air_f_heli\heli_light_02\data\heli_light_02_ext_opfor_v2_co.paa" }; 
			};
			class WhiteBlue : BaseTexture { 
				displayName = "白蓝配色（White / Blue）";
				textures[] = { "\a3\air_f\Heli_Light_02\Data\heli_light_02_ext_civilian_co.paa" };
			}; 

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};

			// Civilian Faction
			// class DMS : BaseTexture {
			// 	displayName = "DMS";
			// 	conditions = "[] call ULP_fnc_isDunamis";
			// 	textures[] = { "Data\Textures\Groups\DMS\Vehicles\orca.paa" };
			// };
		};
	};

	class I_Heli_light_03_unarmed_F : BaseHeli {
		description = "WY-55 Hellcat 是一款多用途直升机，特别适合执行通用支援与有限运载任务。";
		buyPrice = 2130000;
		virtualSpace = 20;
		class Textures {
			class Police : PoliceTextureBase { textures[] = { "Data\Textures\Vehicles\Air\Police\hellcat.paa" }; };

			// Civilian
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				textures[] = { "#(rgb,8,8,3)color(0.03,0.03,0.03,1)" }; 
			};
			class Green : BaseTexture {
				displayName = "绿色（Green）";
				textures[] = { "\a3\air_f_epb\Heli_Light_03\data\Heli_Light_03_base_CO.paa" }; 
			};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};

			// Civilian Faction
			// class DMS : BaseTexture {
			// 	displayName = "DMS";
			// 	conditions = "[] call ULP_fnc_isDunamis";
			// 	textures[] = { "Data\Textures\Groups\DMS\Vehicles\hellcat.paa" };
			// };
		};
	};
	class I_Heli_light_03_F : I_Heli_light_03_unarmed_F {
		buyPrice = 23450000;
		garageLimit = 1;
		class Textures : Textures {
			class Police : Police {
				turrets[] = { { { -1 },  { "M134_minigun" },  { "5000Rnd_762x51_Yellow_Belt" } } };
			};
		};
	};

	class B_Heli_Transport_01_F : BaseHeli {
		description = "UH-80 Ghost Hawk 是一款具备隐身设计的中型通用运输直升机。";
		buyPrice = 19450000;
		virtualSpace = 30;
		garageLimit = 1;
		class Textures {
			class Police : PoliceTextureBase {
				turrets[] = { 
					{ { 1 },  { "LMG_coax" },  { "2000Rnd_762x51_Belt_T_Red" } },
					{ { 2 },  { "LMG_coax" },  { "2000Rnd_762x51_Belt_T_Red" } }
				};
			};
			class Civilian : BaseTexture {};

			class ChromeGreen : BaseChromeGreen {};
			class ChromeBlue : BaseChromeBlue {};
			class ChromeRed : BaseChromeRed {};
			class ChromeSilver : BaseChromeSilver {};
			class ChromeGold : BaseChromeGold {};
		};
	};

	class I_Heli_Transport_02_F : BaseHeli {
		description = "CH-49 Mohawk 是广泛服役的 Merlin 后继机型，核心定位为主力运输直升机，同时也衍生出撤离、反潜与武装空中支援等多种版本。";
		buyPrice = 13240000;
		virtualSpace = 160;
		garageLimit = 2;
		class Textures {
			class Medic : MedicTextureBase {
				textures[] = { 
					"Data\Textures\Vehicles\Air\Medic\mohawk_01.paa",
					"Data\Textures\Vehicles\Air\Medic\mohawk_02.paa",
					"Data\Textures\Vehicles\Air\Medic\mohawk_03.paa"
				}; 
				inventory[] = { 
					{ "Packing", 60 }, 
					{ "Elastic", 80 },  
					{ "BloodBag", 10 } 
				}; 
			};
			class Ion : BaseTexture {
				displayName = "艾昂（Ion）";
				textures[] = { 
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_1_ion_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_2_ion_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_3_ion_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\heli_transport_02_int_02_co.paa"
				 }; 
			};
			class Dahoman : BaseTexture {
				displayName = "达霍曼（Dahoman）";
				textures[] = { 
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_1_dahoman_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_2_dahoman_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\skins\heli_transport_02_3_dahoman_co.paa",
					"\a3\air_f_beta\heli_transport_02\data\heli_transport_02_int_02_co.paa" 
				}; 
			};
		};
	};

	class C_IDAP_Heli_Transport_02_F : I_Heli_Transport_02_F {
		whitelistedItems[] = { "HumanitarianSupplies" };
		class Textures {
			class IDAP : BaseTexture {
				displayName = "IDAP（IDAP）";
				textures[] = { 
					"\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_1_IDAP_CO.paa",
					"\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_2_IDAP_CO.paa",
					"\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_3_IDAP_CO.paa",
					"\a3\air_f_orange\heli_transport_02\data\Heli_Transport_02_int_02_IDAP_CO.paa" 
				}; 
			};
		};
	};

	class O_Heli_Transport_04_black_F : BaseHeli {
		description = "Mi-290 Taru 是一款采用共轴旋翼和独特模块化结构的重型通用直升机。不同任务舱让 Taru 能够胜任多种角色。";
		buyPrice = 11350000;
		garageLimit = 2;
		class Textures {
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				factions[] = { "Civilian", "Police" };
			};
		};
	};
	class O_Heli_Transport_04_bench_black_F : O_Heli_Transport_04_black_F { buyPrice = 11176500; };
	class O_Heli_Transport_04_covered_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 12670000;
		virtualSpace = 35;
	};
	class O_Heli_Transport_04_box_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 28900500;
		virtualSpace = 250;
	};
	class O_Heli_Transport_04_ammo_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 29460000;
		virtualSpace = 280;
	};
	class O_Heli_Transport_04_fuel_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 13640000;
		virtualSpace = 150;
		whitelistedItems[] = { 
			"UnprocessedOil", 
			"Fuel"
		};
	};
	class O_Heli_Transport_04_medevac_black_F : O_Heli_Transport_04_black_F {
		buyPrice = 11983000;
		virtualSpace = 40;
		class Textures {
			class Medic : MedicTextureBase {
				textures[] = { 
					"Data\Textures\Vehicles\Air\Medic\taru_01.paa", 
					"Data\Textures\Vehicles\Air\Medic\taru_02.paa", 
					"Data\Textures\Vehicles\Air\Medic\taru_03.paa", 
					"Data\Textures\Vehicles\Air\Medic\taru_04.paa"
				}; 
				inventory[] = { 
					{ "Packing", 10 }, 
					{ "Elastic", 20 },  
					{ "BloodBag", 10 } 
				}; 
			};
		};
	};

	class B_Heli_Transport_03_unarmed_F : BaseHeli {
		description = "这是一款双发串列双旋翼重型运输直升机，主要用于运送部队、载具和货物。";
		buyPrice = 33400750;
		virtualSpace = 500;
		garageLimit = 2;
		class Textures {
			class Black : BaseTexture {
				displayName = "黑色（Black）";
				factions[] = { "Civilian", "Police" };
				textures[] = { 
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext01_black_co.paa",
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_black_co.paa"
				 }; 
			};
			class Olive : BaseTexture {
				displayName = "橄榄绿（Olive）";
				textures[] = { 
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext01_co.paa",
					"\a3\air_f_heli\heli_transport_03\data\heli_transport_03_ext02_co.paa"
				}; 
			};
		};
	};

	class B_Heli_Attack_01_F : BaseHeli {
		description = "这是一款双座侦察与目标指示直升机，主要任务是为武装直升机搜索并标定目标。";
		buyPrice = 146560000;
		garageLimit = 1;
		canChop = false;
		canTransfer = false;
	};
	class O_Heli_Attack_02_F : B_Heli_Attack_01_F {
		description = "Mi-48 Kajman（代号 “Hornet”）是 Mi-24 的多用途后继机型，属于大型武装攻击直升机，并具备 8 名乘客的运兵能力。";
		buyPrice = 212340000;
		virtualSpace = 30;
	};

	// PLANES --------------------------------------------------------------------------------------
	class C_Plane_Civil_01_F : BasePlane {
		description = "Caesar BTT 是固定起落架单发活塞机中速度最快的机型之一，在 25,000 英尺（7,600 m）高度可达到 235 节（435 km/h）真空速。";
		buyPrice = 1256000;
		virtualSpace = 140;
		whitelistedItems[] = { "StolenCargo" };
	};
	class C_Plane_Civil_01_racing_F : C_Plane_Civil_01_F { buyPrice = 1375000; };

	class B_T_VTOL_01_infantry_F : BasePlane {
		description = "V-44X Blackfish 采用第三代倾转旋翼 VTOL 技术，使这款长航时飞机能够方便地使用多种机场和跑道。";
		buyPrice = 75500000;
		virtualSpace = 650;
	};
	class B_T_VTOL_01_vehicle_F : B_T_VTOL_01_infantry_F {
		buyPrice = 85750000;
		virtualSpace = 700;
	};

	class O_T_VTOL_02_infantry_F : BasePlane {
		description = "这款由 CSAT 工程师打造的前沿原型机采用极具未来感的设计，融合了多项独特特性与尖端技术。";
		buyPrice = 115650000;
		virtualSpace = 180;
	};
	class O_T_VTOL_02_vehicle_F : O_T_VTOL_02_infantry_F {
		buyPrice = 125530000;
		virtualSpace = 230;
	};

	class I_Plane_Fighter_03_CAS_F : BasePlane {
		description = "A-143 Buzzard 是一款单座轻型多用途战机，能够挂载多种装备与武器。";
		buyPrice = 73350000;
	};
	class I_Plane_Fighter_04_F : BasePlane { 
		description = "A-149 Gryphon 是一款第四代单座单发全天候战术战斗机。";
		buyPrice = 75500000; 
	};
	
	class B_Plane_CAS_01_F : BasePlane { 
		description = "A-164 Wipeout 是一款单座攻击机，主要用于近距空中支援与空中阻绝任务。";
		buyPrice = 90500000; 
	};
	class B_Plane_Fighter_01_F : BasePlane { 
		description = "F/A-181 Black Wasp II 是一款第五代单座双发全天候战术战斗机。";
		buyPrice = 105500000; 
	};
	class B_Plane_Fighter_01_Stealth_F : B_Plane_Fighter_01_F { buyPrice = 115600000; };

	class O_Plane_CAS_02_F : BasePlane { 
		description = "To-199 Neophron 是 CSAT 空军的新锐机型。这款机动灵活的单座战机既能执行近距空中支援，也具备对空作战能力。";
		buyPrice = 86500000; 
	};
	class O_Plane_Fighter_02_F : BasePlane { 
		description = "To-201 Shikra 是一款第五代单座双发全天候战术战斗机。";
		buyPrice = 115500000;
	};
	class O_Plane_Fighter_02_Stealth_F : O_Plane_Fighter_02_F { buyPrice = 130500000; };

	// CONTAINERS --------------------------------------------------------------------------------------
	class Land_Pod_Heli_Transport_04_box_black_F : BaseContainer { virtualSpace = 300; };
	class Land_Pod_Heli_Transport_04_fuel_black_F : Land_Pod_Heli_Transport_04_box_black_F {
		whitelistedItems[] = { 
			"UnprocessedOil", 
			"Fuel"
		};
	};

	class B_Slingload_01_Cargo_F : BaseContainer { virtualSpace = 500; };
	class B_Slingload_01_Fuel_F : B_Slingload_01_Cargo_F {
		whitelistedItems[] = { 
			"UnprocessedOil", 
			"Fuel"
		};
	};

	// TEMP --------------------------------------------------------------------------------------
	class Land_Bodybag_01_black_F : Base {
		virtualSpace = 0;
		garageLimit = 0;
		tempStorage = true;
	};

	// HOUSING --------------------------------------------------------------------------------------
	class Land_PlasticCase_01_small_F : Base { // Addon House
		virtualSpace = 1000;
		garageLimit = 0;
		isHouse = true;
	};
	class Land_PlasticCase_01_medium_F : Land_PlasticCase_01_small_F { virtualSpace = 2000; }; // Small House
	class Land_PlasticCase_01_large_F : Land_PlasticCase_01_small_F { virtualSpace = 3000; }; // Small House
	class Land_PlasticCase_01_large_gray_F : Land_PlasticCase_01_small_F { virtualSpace = 2000; }; // Lighthouse
	class B_supplyCrate_F : Land_PlasticCase_01_small_F { virtualSpace = 6000; }; // Big House
	class Land_Cargo10_red_F : Land_PlasticCase_01_small_F { virtualSpace = 6000; };
	// Warehouse / Boat
	class Land_Cargo20_white_F : Land_PlasticCase_01_small_F {
		virtualSpace = 10000;
		supply = "B_supplyCrate_F";
	};
	// Needed for evidence locker as it needs virtual space
	class Land_Cargo20_red_F : Land_Cargo20_white_F {};
	class Land_Cargo20_grey_F : Land_Cargo20_white_F { virtualSpace = 40000; }; // Military Offices
	class CargoNet_01_box_F : Land_PlasticCase_01_small_F { virtualSpace = 20000; }; // DMT
	class C_IDAP_supplyCrate_F : Land_PlasticCase_01_small_F { virtualSpace = 1800; }; // Office Building

	class Land_CargoBox_V1_F : Base {
		virtualSpace = 1;
		garageLimit = 0;
		requireItems = true; 
	};
	class Land_PortableServer_01_black_F : Land_CargoBox_V1_F {};

	// SOUNDS --------------------------------------------------------------------------------------
	class Siren_1 { sound = "Siren_1"; };
	class Siren_2 { sound = "Siren_2"; };
	class Siren_3 { sound = "Siren_3"; };
	class Siren_4 { sound = "Siren_4"; };
	class Siren_5 { sound = "Siren_5"; };
	class Siren_6 { sound = "Siren_6"; };
	class Siren_7 { sound = "Siren_7"; };
	class Siren_8 { sound = "Siren_8"; };
	class Siren_9 { sound = "Siren_9"; };
	class Factory_Processing { sound = "Factory_Processing"; };
};
