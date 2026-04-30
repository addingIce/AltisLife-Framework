class CfgMissions {
	class Delivery {
		name = "配送任务";
		description = "你需要把指定包裹送到 %1";
		factions[] = { "Civilian" };
		condition = "true";
		eachFrame = "";
		onClaimed = "";
		onFinished = "";
		class Locations {
			class DP1 {
				pos = "DP_1";
				name = "投递点 1（Delivery Point 1）";
			};
			class DP2 {
				pos = "DP_2";
				name = "投递点 2（Delivery Point 2）";
			};
			class DP3 {
				pos = "DP_3";
				name = "投递点 3（Delivery Point 3）";
			};
			class DP4 {
				pos = "DP_4";
				name = "投递点 4（Delivery Point 4）";
			};
			class DP5 {
				pos = "DP_5";
				name = "投递点 5（Delivery Point 5）";
			};
			class DP6 {
				pos = "DP_6";
				name = "投递点 6（Delivery Point 6）";
			};
			class DP7 {
				pos = "DP_7";
				name = "投递点 7（Delivery Point 7）";
			};
			class DP8 {
				pos = "DP_8";
				name = "投递点 8（Delivery Point 8）";
			};
			class DP9 {
				pos = "DP_9";
				name = "投递点 9（Delivery Point 9）";
			};
			class DP10 {
				pos = "DP_10";
				name = "投递点 10（Delivery Point 10）";
			};
			class DP11 {
				pos = "DP_11";
				name = "投递点 11（Delivery Point 11）";
			};
			class DP12 {
				pos = "DP_12";
				name = "投递点 12（Delivery Point 12）";
			};
			class DP13 {
				pos = "DP_13";
				name = "投递点 13（Delivery Point 13）";
			};
			class DP14 {
				pos = "DP_14";
				name = "投递点 14（Delivery Point 14）";
			};
			class DP15 {
				pos = "DP_15";
				name = "投递点 15（Delivery Point 15）";
			};
			class DP16 {
				pos = "DP_16";
				name = "投递点 16（Delivery Point 16）";
			};
			class DP17 {
				pos = "DP_17";
				name = "投递点 17（Delivery Point 17）";
			};
			class DP18 {
				pos = "DP_18";
				name = "投递点 18（Delivery Point 18）";
			};
		};
		class Rewards {
			moneyReward = 5;
			xpReward = 250;
			repReward = false;
		};
		class Messages {
			onFinishWithoutMission = "你现在没有需要送到这里的包裹...";
			onAlreadyHas = "你已经有一个正在进行的配送任务了，请先完成再来接新的...";
			onNoLocations = "当前没有可接取的配送任务，请稍后再试...";
			onAssigned = "你已接到任务，请把这个包裹送到 %1";
			onFinished = "包裹已成功送达，你获得了 £%1";
		};
	};

	class Patrol {
		name = "巡逻任务";
		description = "你需要前往 %1 巡逻";
		factions[] = { "Police", "Medic", "Hato" };
		condition = "true";
		eachFrame = "";
		onClaimed = "[ { (player distance _this) <= 10 }, _this, { [""Patrol""] call ULP_fnc_finishMission; } ] call ULP_fnc_waitUntilExecute;";
		onFinished = "";
		class Locations {
			// CITIES, TOWNS & KEY LOCATIONS
			class KavalaSquare {
				pos = "civ_spawn_kavala";
				name = "卡瓦拉广场（Kavala Square）";
			};
			class CentralAthira {
				pos = "car_dealership_athira_01";
				name = "阿瑟拉中心（Central Athira）";
			};
			class AgiosCenter {
				pos = "civ_spawn_agios";
				name = "阿吉奥斯中心（Agios Center）";
			};
			class AltisInternational {
				pos = "altis_international";
				name = "阿尔蒂斯国际机场（Altis International）";
			};
			class HuntingCamp {
				pos = "hunting_camp";
				name = "狩猎营地（Hunting Camp）";
			};
			class JewelleryStore {
				pos = "jewellery_store";
				name = "珠宝店（Jewellery Store）";
			};
			class AltisArcheologists {
				pos = "altis_archeologists";
				name = "阿尔蒂斯考古学会（Altis Archeologists）";
			};
			class Supermarket {
				pos = "supermarket";
				name = "超市（Supermarket）";
			};
			class ImpoundFacility {
				pos = "impound_facility";
				name = "扣押中心（Impound Facility）";
			};
			class KavalaStreet {
				pos = "10_kavala_street";
				name = "卡瓦拉街 10 号（10 Kavala Street）";
			};

			// MINOR CRIME SITES
			class WesternRegionalBank {
				pos = "regional_bank_01";
				name = "西部地区银行（Western Regional Bank）";
			};

			// MAJOR CRIME SITES
			class HMTreasury {
				pos = "hm_treasury";
				name = "皇家财政部（HM Treasury）";
			};
			class HMPrisonAltis {
				pos = "hm_prison_altis";
				name = "皇家阿尔蒂斯监狱（HM Prison Altis）";
			};
			class PoliceEvidenceStorage {
				pos = "police_evidence_storage";
				name = "警方证物仓库（Police Evidence Storage）";
			};

			// GATHER, PROCESSING & TRADING SITES
			class AltisMetalExports {
				pos = "altis_metal_exports";
				name = "阿尔蒂斯金属出口站（Altis Metal Exports）";
			};
		};
		class Rewards {
			moneyReward = 3;
			xpReward = 150;
			repReward = false;
		};
		class Messages {
			onFinishWithoutMission = "你当前没有被分配巡逻任务，无法在这里完成...";
			onAlreadyHas = "你已经被分配了巡逻任务，请先完成当前任务再来申请新的...";
			onNoLocations = "当前没有可分配的巡逻点，请稍后再试...";
			onAssigned = "你已被派往 %1 巡逻";
			onFinished = "你已成功完成本次巡逻，获得奖金 £%1";
		};
	};

	class ArchaeologyCommon {
		name = "普通考古点";
		description = "你需要在标记地点使用勘测设备...";
		factions[] = { "Civilian" };
		condition = "true";
		eachFrame = "";
		onClaimed = "ULP_Archaeology_Digging = false; ULP_Archaeology = ""Common""; ULP_SurveyTotal = 0; [""CommonMap"", 1, true] call ULP_fnc_handleItem;";
		onFinished = "";
		class Locations {
			class dig_site_01 {
				pos = "dig_site_01";
				name = "扎罗斯（Zaros）";
			};
			class dig_site_02 {
				pos = "dig_site_02";
				name = "扎罗斯（Zaros）";
			};
			class dig_site_03 {
				pos = "dig_site_03";
				name = "扎罗斯（Zaros）";
			};
			class dig_site_04 {
				pos = "dig_site_04";
				name = "扎罗斯（Zaros）";
			};
			class dig_site_05 {
				pos = "dig_site_05";
				name = "扎罗斯（Zaros）";
			};
			class dig_site_06 {
				pos = "dig_site_06";
				name = "扎罗斯（Zaros）";
			};
			class dig_site_07 {
				pos = "dig_site_07";
				name = "扎罗斯（Zaros）";
			};
			class dig_site_08 {
				pos = "dig_site_08";
				name = "扎罗斯（Zaros）";
			};
			class dig_site_09 {
				pos = "dig_site_09";
				name = "扎罗斯（Zaros）";
			};
			class dig_site_10 {
				pos = "dig_site_10";
				name = "阿利坎波斯（Alikampos）";
			};
			class dig_site_11 {
				pos = "dig_site_11";
				name = "科雷（Kore）";
			};
			class dig_site_12 {
				pos = "dig_site_12";
				name = "锡尔塔（Syrta）";
			};
			class dig_site_13 {
				pos = "dig_site_13";
				name = "阿卜德拉（Abdera）";
			};
			class dig_site_14 {
				pos = "dig_site_14";
				name = "加拉蒂（Galati）";
			};
			class dig_site_15 {
				pos = "dig_site_15";
				name = "加拉蒂（Galati）";
			};
			class dig_site_16 {
				pos = "dig_site_16";
				name = "加拉蒂（Galati）";
			};
			class dig_site_17 {
				pos = "dig_site_17";
				name = "特洛斯（Telos）";
			};
			class dig_site_18 {
				pos = "dig_site_18";
				name = "安斯拉基亚（Anthrakia）";
			};
			class dig_site_19 {
				pos = "dig_site_19";
				name = "查尔基亚（Charkia）";
			};
			class dig_site_20 {
				pos = "dig_site_20";
				name = "多里达（Dorida）";
			};
			class dig_site_21 {
				pos = "dig_site_21";
				name = "多里达（Dorida）";
			};
			class dig_site_22 {
				pos = "dig_site_22";
				name = "多里达（Dorida）";
			};
			class dig_site_23 {
				pos = "dig_site_23";
				name = "多里达（Dorida）";
			};
			class dig_site_24 {
				pos = "dig_site_24";
				name = "哈尔凯亚（Chalkeia）";
			};
			class dig_site_25 {
				pos = "dig_site_25";
				name = "哈尔凯亚（Chalkeia）";
			};
			class dig_site_26 {
				pos = "dig_site_26";
				name = "皮尔戈斯（Pyrgos）";
			};
			class dig_site_27 {
				pos = "dig_site_27";
				name = "哈尔凯亚（Chalkeia）";
			};
			class dig_site_28 {
				pos = "dig_site_28";
				name = "奥雷奥卡斯特罗（Oreokastro）";
			};
			class dig_site_29 {
				pos = "dig_site_29";
				name = "奥雷奥卡斯特罗（Oreokastro）";
			};
			class dig_site_30 {
				pos = "dig_site_30";
				name = "塞里萨（Therisa）";
			};
		};
		class Rewards {
			moneyReward = 0;
			xpReward = 0;
			repReward = false;
		};
		class Messages {
			onFinishWithoutMission = "这个地点并不是你当前被分配的勘测点，无法完成...";
			onAlreadyHas = "你必须先完成当前分配的勘测地点，才能接取新的...";
			onNoLocations = "当前没有可分配的勘测地点，请稍后再试...";
			onAssigned = "你地图上已标出一个位于 %1 附近的考古点";
			onFinished = "";
		};
	};

	class ArchaeologyUncommon : ArchaeologyCommon {
		name = "稀有考古点";
		onClaimed = "ULP_Archaeology_Digging = false; ULP_Archaeology = ""Uncommon""; ULP_SurveyTotal = 0; [""UncommonMap"", 1, true] call ULP_fnc_handleItem;";
		class Rewards : Rewards {};
		class Messages : Messages {};
	};

	class ArchaeologyRare : ArchaeologyCommon {
		name = "珍贵考古点";
		onClaimed = "ULP_Archaeology_Digging = false; ULP_Archaeology = ""Rare""; ULP_SurveyTotal = 0; [""RareMap"", 1, true] call ULP_fnc_handleItem;";
		class Rewards : Rewards {};
		class Messages : Messages {};
	};

	class ArchaeologyLegendary : ArchaeologyCommon {
		name = "传奇考古点";
		onClaimed = "ULP_Archaeology_Digging = false; ULP_Archaeology = ""Legendary""; ULP_SurveyTotal = 0; [""LegendaryMap"", 1, true] call ULP_fnc_handleItem;";
		class Rewards : Rewards {};
		class Messages : Messages {};
	};

	class CorporateFreight {
		name = "企业货运";
		description = "你需要把这批企业货物送到 %1";
		factions[] = { "Civilian" };
		condition = "[""FreightMissions""] call ULP_fnc_hasGroupPerk";
		eachFrame = "_this call ULP_fnc_onEachFrameCargoRun";
		onClaimed = "";
		onFinished = "_this call ULP_fnc_finishCargoRun";
		timeDivisionAmount = 2;
		vehicleRequirement[] = { { "Car" }, 10 };
		cargoItem = "FreightCargo";
		class Locations {
			class Kavala_Freight {
				pos = "freight_mission_1";
				name = "卡瓦拉货运场（Kavala Freight Yard）";
			};
			class Sofia_Freight {
				pos = "freight_mission_2";
				name = "索菲亚货运场（Sofia Freight Yard）";
			};
			class Athira_Freight {
				pos = "freight_mission_3";
				name = "阿瑟拉货运场（Athira Freight Yard）";
			};
			class Pyrgos_Freight {
				pos = "freight_mission_4";
				name = "皮尔戈斯货运场（Pyrgos Freight Yard）";
			};
		};
		class Rewards {
			moneyReward = 55;
			xpReward = 300;
			repReward = false;
		};
		class Messages {
			onFinishWithoutMission = "你现在没有需要送到这里的货物...";
			onAlreadyHas = "你已经有一个正在进行的企业货运任务了，请先完成再来接新的...";
			onNoLocations = "当前没有可接取的企业货运任务，请稍后再试...";
			onAssigned = "你的卡车已经装好货，请把它送到 <t color='#B92DE0'>%1</t>";
			onFinished = "货物已成功送达，你获得了 <t color='#B92DE0'>£%1</t>";
		};
	};

	class FuelHauling : CorporateFreight {
		name = "燃料运输";
		description = "你需要把燃料送到 %1";
		condition = "[""FuelHauling""] call ULP_fnc_hasGroupPerk";
		vehicleRequirement[] = { { "Car" }, 30 };
		cargoItem = "Fuel";
		class Locations {
			// Collection Point
			class Fuel_Storage {
				pos = "Fuel_Storage";
				name = "燃料仓库（Fuel Storage）";
			};
			
			// Fuel Stations
			class fuel_station_01 {
				pos = "fuel_station_01";
				name = "阿格洛霍里燃料站（Aggelorchori Fuel）";
			};
			class fuel_station_02 {
				pos = "fuel_station_02";
				name = "南卡瓦拉燃料站（South Kavala Fuel）";
			};
			class fuel_station_03 {
				pos = "fuel_station_03";
				name = "体育场燃料站（Stadium Fuel）";
			};
			class fuel_station_04 {
				pos = "fuel_station_04";
				name = "科雷燃料站（Kore Fuel）";
			};
			class fuel_station_05 {
				pos = "fuel_station_05";
				name = "阿吉奥斯燃料站（Agios Fuel）";
			};
			class fuel_station_06 {
				pos = "fuel_station_06";
				name = "拉卡燃料站（Lakka Fuel）";
			};
			class fuel_station_07 {
				pos = "fuel_station_07";
				name = "特洛斯燃料站（Telos Fuel）";
			};
			class fuel_station_08 {
				pos = "fuel_station_08";
				name = "机场燃料站（Airport Fuel）";
			};
			class fuel_station_09 {
				pos = "fuel_station_09";
				name = "格拉维亚燃料站（Gravia Fuel）";
			};
			class fuel_station_10 {
				pos = "fuel_station_10";
				name = "查尔基亚燃料站（Charkia Fuel）";
			};
			class fuel_station_12 {
				pos = "fuel_station_12";
				name = "北皮尔戈斯燃料站（North Pyrgos Fuel）";
			};
			class fuel_station_13 {
				pos = "fuel_station_13";
				name = "阿瑟拉燃料站（Athira Fuel）";
			};
			class fuel_station_14 {
				pos = "fuel_station_14";
				name = "皮尔戈斯燃料站（Pyrgos Fuel）";
			};
			class fuel_station_15 {
				pos = "fuel_station_15";
				name = "北卡瓦拉燃料站（North Kavala Fuel）";
			};
			class fuel_station_16 {
				pos = "fuel_station_16";
				name = "哈尔凯亚燃料站（Chalkeia Fuel）";
			};
			class fuel_station_17 {
				pos = "fuel_station_17";
				name = "塞拉卡诺燃料站（Selakano Fuel）";
			};
			class fuel_station_20 {
				pos = "fuel_station_20";
				name = "锡尔塔燃料站（Syrta Fuel）";
			};
			class fuel_station_21 {
				pos = "fuel_station_21";
				name = "尼奥霍里燃料站（Neochori Fuel）";
			};
			class fuel_station_22 {
				pos = "fuel_station_22";
				name = "扎罗斯燃料站（Zaros Fuel）";
			};
		};
		class Rewards {
			moneyReward = 70;
			xpReward = 400;
			repReward = false;
		};
		class Messages {
			onFinishWithoutMission = "你现在没有需要送到这里的燃料...";
			onAlreadyHas = "你已经有一个正在进行的燃料运输任务了，请先完成再来接新的...";
			onNoLocations = "当前没有可接取的燃料运输任务，请稍后再试...";
			onAssigned = "你的卡车已经装好燃料，请把它送到 <t color='#B92DE0'>%1</t>";
			onFinished = "燃料已成功送达，你获得了 <t color='#B92DE0'>£%1</t>";
		};
	};

	class FoodDelivery : CorporateFreight {
		name = "食品配送";
		description = "你需要把这批食品送到 %1";
		condition = "true";
		timeDivisionAmount = 1;
		vehicleRequirement[] = { { "Car" }, 25 };
		cargoItem = "Foodstuffs";
		class Locations {
			// Collection Point
			class Food_Shipment {
				pos = "Food_Shipment";
				name = "食品装运点（Food Shipment）";
			};
			
			// Supermarkets
			class supermarket {
				pos = "supermarket";
				name = "科雷超市（Kore Supermarket）";
			};
			class supermarket_1 {
				pos = "supermarket_1";
				name = "阿吉奥斯超市（Agios Supermarket）";
			};
			class supermarket_2 {
				pos = "supermarket_2";
				name = "拉卡超市（Lakka Supermarket）";
			};
			class supermarket_3 {
				pos = "supermarket_3";
				name = "特洛斯超市（Telos Supermarket）";
			};
		};
		class Rewards {
			moneyReward = 18;
			xpReward = 250;
			repReward = false;
		};
		class Messages {
			onFinishWithoutMission = "你现在没有需要送到这里的食品...";
			onAlreadyHas = "你已经有一个正在进行的食品配送任务了，请先完成再来接新的...";
			onNoLocations = "当前没有可接取的食品配送任务，请稍后再试...";
			onAssigned = "你的载具已经装好食品，请把它送到 <t color='#B92DE0'>%1</t>";
			onFinished = "食品已成功送达，你获得了 <t color='#B92DE0'>£%1</t>";
		};
	};

	class DunamisPropagandaMission : CorporateFreight {
		name = "宣传任务";
		description = "你需要把这批宣传物资送到 %1";
		condition = "[] call ULP_fnc_isDunamis";
		timeDivisionAmount = 1;
		vehicleRequirement[] = { { "Car" }, 35 };
		cargoItem = "DunamisPropaganda";
		class Locations {
			// Collection Point
			class dms_mission_1 {
				pos = "dms_mission_1";
				name = "杜纳米斯营地（Dunamis Camp）";
			};
			
			// Sympathisers
			class dms_mission_2 {
				pos = "dms_mission_2";
				name = "阿瑟拉同情者据点（Athira Sympathiser）";
			};
			class dms_mission_4 {
				pos = "dms_mission_4";
				name = "尼奥霍里同情者据点（Neochori Sympathiser）";
			};
			class dms_mission_5 {
				pos = "dms_mission_5";
				name = "阿吉奥斯同情者据点（Agios Sympathiser）";
			};
			class dms_mission_6 {
				pos = "dms_mission_6";
				name = "扎罗斯同情者据点（Zaros Sympathiser）";
			};
			class dms_mission_7 {
				pos = "dms_mission_7";
				name = "卡瓦拉同情者据点（Kavala Sympathiser）";
			};
		};
		class Rewards {
			moneyReward = 12;
			xpReward = 350;
			repReward = false;
		};
		class Messages {
			onFinishWithoutMission = "你现在没有需要送到这里的宣传物资...";
			onAlreadyHas = "你已经有一个正在进行的宣传配送任务了，请先完成再来接新的...";
			onNoLocations = "当前没有可接取的宣传物资任务，请稍后再试...";
			onAssigned = "你的载具已经装好宣传物资，请把它送到 <t color='#B92DE0'>%1</t>";
			onFinished = "宣传物资已成功送达，你获得了 <t color='#B92DE0'>£%1</t>";
		};
	};

	class CriminalSmuggling : CorporateFreight {
		name = "走私货运";
		description = "你需要把这批赃物送到 %1";
		condition = "[""SeaSmuggling""] call ULP_fnc_hasGroupPerk";
		timeDivisionAmount = 4;
		vehicleRequirement[] = { { "Ship" }, 50 };
		cargoItem = "StolenCargo";
		class Locations {
			class Sunken_Grove {
				pos = "smuggling_location_1";
				name = "沉林湾（Sunken Grove）";
			};
			class Discovery_Ridge {
				pos = "smuggling_location_2";
				name = "发现山脊（Discovery Ridge）";
			};
			class Lookout_Point {
				pos = "smuggling_location_3";
				name = "瞭望点（Lookout Point）";
			};
		};
		class Rewards {
			moneyReward = 0;
			xpReward = 150;
			repReward = false;
		};
		class Messages {
			onFinishWithoutMission = "你现在没有需要送到这里的赃物...";
			onAlreadyHas = "你已经有一个正在进行的走私任务了，请先完成再来接新的...";
			onNoLocations = "当前没有可接取的走私任务，请稍后再试...";
			onAssigned = "你的船已经装好赃物，请把它送到 <t color='#B92DE0'>%1</t>";
			onFinished = "赃物已成功送达，你获得了 <t color='#B92DE0'>£%1</t>";
		};
	};

	class CriminalSmugglingAir : CriminalSmuggling {
		condition = "[""AirSmuggling""] call ULP_fnc_hasGroupPerk";
		vehicleRequirement[] = { { "Plane" }, 50 };
		timeDivisionAmount = 1;
		class Locations {
			class Therisa_Airfield {
				pos = "smuggling_location_air_1";
				name = "塞里萨机场（Therisa Airfield）";
			};
			class Abdera_Airfield {
				pos = "smuggling_location_air_2";
				name = "阿卜德拉机场（Abdera Airfield）";
			};
			class Selakano_Airfield {
				pos = "smuggling_location_air_3";
				name = "塞拉卡诺机场（Selakano Airfield）";
			};
			class Molos_Airfield {
				pos = "smuggling_location_air_4";
				name = "莫洛斯机场（Molos Airfield）";
			};
			class Almyra_Airfield {
				pos = "smuggling_location_air_5";
				name = "阿尔米拉机场（Almyra Airfield）";
			};
		};
		class Rewards {
			moneyReward = 0;
			xpReward = 300;
			repReward = false;
		};
		class Messages : Messages {};
	};

	class HumanitarianMission : CorporateFreight {
		name = "人道援助任务";
		description = "你需要把补给送到 %1";
		condition = "[""IDAP""] call ULP_fnc_hasLicense";
		vehicleRequirement[] = { { "Car", "Helicopter" }, 30 };
		cargoItem = "HumanitarianSupplies";
		class Locations {
			class IDAP_HQ {
				pos = "idap_camp";
				name = "国际开发与援助计划总部（IDAP HQ）";
			};
			class IDAP_Camp_1 {
				pos = "idap_camp_1";
				name = "南岛营地（Southern Island Camp）";
			};
			class IDAP_Camp_2 {
				pos = "idap_camp_2";
				name = "奥雷奥卡斯特罗营地（Oreokastro Camp）";
			};
			class IDAP_Camp_3 {
				pos = "idap_camp_3";
				name = "费雷斯营地（Feres Camp）";
			};
			class IDAP_Camp_4 {
				pos = "idap_camp_4";
				name = "莫洛斯营地（Molos Camp）";
			};
		};
		class Rewards {
			moneyReward = 0;
			xpReward = 1000;
			repReward = true;
		};
		class Messages {
			onFinishWithoutMission = "你现在没有需要送到这里的援助补给...";
			onAlreadyHas = "你已经有一个正在进行的人道援助任务了，请先完成再来接新的...";
			onNoLocations = "当前没有可接取的人道援助任务，请稍后再试...";
			onAssigned = "你的卡车已经装好补给，请把它送到 <t color='#B92DE0'>%1</t>";
			onFinished = "补给已成功送达，你获得了 <t color='#B92DE0'>£%1</t>";
		};
	};
};
