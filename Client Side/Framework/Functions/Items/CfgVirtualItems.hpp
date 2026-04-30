class CfgVirtualItems {
	// Fresh Food
	class FreshApple {
		displayName = "新鲜苹果（Fresh Apples）";
		description = "从本地果树上采摘的新鲜水果，可在市场出售";
		icon = "Data\Icons\freshApples.paa";
		buyPrice = -1;
		sellPrice = 140;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 40;
			thirst = 0;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class FreshPeach : FreshApple {
		displayName = "新鲜桃子（Fresh Peaches）";
		icon = "Data\Icons\freshPeaches.paa";
		sellPrice = 155;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};
	
	// Regular Food
	class Apple {
		displayName = "苹果（Apple）";
		description = "常见食物，可让你保持饱腹";
		icon = "Data\Icons\apple.paa";
		buyPrice = 90;
		sellPrice = 45;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 20;
			thirst = 10;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class Peach : Apple {
		displayName = "桃子（Peach）";
		icon = "Data\Icons\peach.paa";
		buyPrice = 102;
		sellPrice = 51;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};
	class Bacon : Apple {
		displayName = "培根（Bacon）";
		icon = "Data\Icons\bacon.paa";
		buyPrice = 130;
		sellPrice = 65;
		class Settings : Settings {};
		class Sustain {
			hunger = 25;
			thirst = 0;
		};
		class Events : Events {};
	};
	class SausageRoll : Apple {
		displayName = "VEEgan 香肠卷（VEEgan Sausage Roll）";
		icon = "Data\Icons\sausageRoll.paa";
		buyPrice = 150;
		sellPrice = 75;
		class Settings : Settings {};
		class Sustain {
			hunger = 40;
			thirst = 0;
		};
		class Events : Events { onUse = "[""Vegan""] call ULP_fnc_achieve; [(_this select 0)] call ULP_fnc_addSustenance;"; };
	};
	class Burger : Bacon {
		displayName = "汉堡（Burger）";
		icon = "Data\Icons\burger.paa";
		buyPrice = 165;
		sellPrice = 83;
		class Settings : Settings {};
		class Sustain {
			hunger = 70;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Hotdog : Bacon {
		displayName = "热狗（Hotdog）";
		icon = "Data\Icons\hotdog.paa";
		buyPrice = 140;
		sellPrice = 70;
		class Settings : Settings {};
		class Sustain {
			hunger = 40;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Chips : Bacon {
		displayName = "薯片（Chips）";
		icon = "Data\Icons\chips.paa";
		buyPrice = 105;
		sellPrice = 53;
		class Settings : Settings {};
		class Sustain {
			hunger = 30;
			thirst = 0;
		};
		class Events : Events {};
	};
	class RationPack : Bacon {
		displayName = "口粮包（Ration Pack）";
		icon = "Data\Icons\rationPack.paa";
		buyPrice = 325;
		sellPrice = 162;
		class Settings : Settings {};
		class Sustain {
			hunger = 50;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Doughnut : Bacon {
		displayName = "甜甜圈（Doughnut）";
		icon = "Data\Icons\doughnut.paa";
		buyPrice = 20;
		sellPrice = 10;
		class Settings : Settings {};
		class Sustain {
			hunger = 15;
			thirst = 0;
		};
		class Events : Events {};
	};
	class Sweetie : Bacon {
		displayName = "糖果（Sweetie）";
		icon = "Data\Icons\sweetie.paa";
		buyPrice = 8;
		sellPrice = 4;
		class Settings : Settings {};
		class Sustain {
			hunger = 5;
			thirst = 5;
		};
		class Events : Events {};
	};

	// Regular Drinks
	class Water {
		displayName = "饮用水（Water）";
		description = "用于补充水分的常见饮品";
		icon = "Data\Icons\bottle.paa";
		buyPrice = 10;
		sellPrice = 5;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 0;
			thirst = 50;
		};
		class Events { onUse = "[(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class Coffee : Water {
		displayName = "咖啡（Coffee）";
		icon = "Data\Icons\coffee.paa";
		buyPrice = 35;
		sellPrice = 18;
		class Settings : Settings {};
		class Sustain {
			hunger = 0;
			thirst = 25;
		};
		class Events : Events {};
	};
	class Tea : Coffee {
		displayName = "茶（Tea）";
		icon = "Data\Icons\tea.paa";
		buyPrice = 30;
		sellPrice = 15;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};

	// Energy Drinks
	class Redbull {
		displayName = "红牛（Redbull）";
		description = "一种能让人反应更快的能量饮料";
		icon = "Data\Icons\can.paa";
		buyPrice = 2100;
		sellPrice = 1050;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 0;
			thirst = 30;
		};
		class Events { onUse = "if ([(_this select 0)] call ULP_fnc_addSustenance) then { player setCustomAimCoef 0.5; [ { !(alive player) || { player getVariable [""isIncapacitated"", false] } || { diag_tickTime > (_this select 0) } }, [diag_tickTime + (3 * 60)], { player setCustomAimCoef 1; }] call ULP_fnc_waitUntilExecute; };"; };
		conditions = "true";
	};

	// Alcoholic Drinks
	class Beer {
		displayName = "啤酒（Beer）";
		description = "一种会带来不适副作用的酒精饮品";
		icon = "Data\Icons\beer.paa";
		buyPrice = 290;
		sellPrice = 145;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Sustain {
			hunger = 0;
			thirst = 10;
		};
		class Events { onUse = "[""FirstDrink""] call ULP_fnc_achieve; [(_this select 0)] call ULP_fnc_addSustenance;"; };
		conditions = "true";
	};
	class Schnapps : Beer {
		displayName = "Schnapps 烈酒（Schnapps）";
		icon = "Data\Icons\schnapps.paa";
		buyPrice = 860;
		sellPrice = 430;
		class Settings : Settings { 
			onMarket = true; 
			isEventItem = true;
		};
		class Sustain : Sustain {};
		class Events : Events {};
	};
	class Gin : Beer {
		displayName = "杜松子酒（Gin）";
		icon = "Data\Icons\gin.paa";
		buyPrice = 375;
		sellPrice = 188;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};
	class Whiskey : Beer {
		displayName = "威士忌（Whiskey）";
		icon = "Data\Icons\whiskey.paa";
		buyPrice = 495;
		sellPrice = 248;
		class Settings : Settings {};
		class Sustain : Sustain {};
		class Events : Events {};
	};

	// XP Rewards
	class TinyXPReward {
		displayName = "微量经验奖励（Tiny XP Reward）";
		description = "一个可提供宝贵经验值的瓶子";
		icon = "Data\Icons\xpReward.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [100, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
		conditions = "true";
	};
	class SmallXPReward : TinyXPReward {
		displayName = "小型经验奖励（Small XP Reward）";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [500, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};
	class MediumXPReward : TinyXPReward {
		displayName = "中型经验奖励（Medium XP Reward）";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [1000, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};
	class LargeXPReward : TinyXPReward {
		displayName = "大型经验奖励（Large XP Reward）";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [5000, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};
	class HugeXPReward : TinyXPReward {
		displayName = "巨量经验奖励（Huge XP Reward）";
		class Settings : Settings {};
		class Events { onUse = "if ([(_this select 0), 1, true] call ULP_fnc_handleItem) then { [10000, ""Used XP Reward""] call ULP_fnc_addXP; };"; };
	};

	// Event Triggers
	class AirdropTrigger {
		displayName = "空投触发器（Airdrop Trigger）";
		description = "用于触发特定事件的道具";
		icon = "Data\Icons\airdropTrigger.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Events { onUse = "[_this # 0, missionConfigFile >> ""CfgRandomEvents"" >> ""Airdrop""] call ULP_fnc_triggerEvent"; };
		conditions = "true";
	};

	class ShipwreckTrigger : AirdropTrigger {
		displayName = "沉船触发器（Shipwreck Trigger）";
		icon = "Data\Icons\shipwreckTrigger.paa";
		class Settings : Settings {};
		class Events { onUse = "[_this # 0, missionConfigFile >> ""CfgRandomEvents"" >> ""Shipwreck""] call ULP_fnc_triggerEvent"; };
	};

	class PopupTrigger : AirdropTrigger {
		displayName = "快闪事件触发器（Popup Trigger）";
		icon = "Data\Icons\popupTrigger.paa";
		class Settings : Settings {};
		class Events { onUse = "[_this # 0, missionConfigFile >> ""CfgRandomEvents"" >> ""PopupCartel""] call ULP_fnc_triggerEvent"; };
	};

	// General Items
	class DroppedMoney {
		displayName = "£%1";
		description = "从尸袋中找到的现金";
		icon = "Data\Icons\cash.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
			isScripted = true;
			isSystemItem = false;
		};
		conditions = "true";
	};

	class Identification {
		displayName = "%1's ID";
		description = "一张记录个人身份信息的卡片";
		icon = "Data\Icons\identification.paa";
		buyPrice = 75000;
		sellPrice = -1;
		weight = 0;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = true;
			isSystemItem = false;
		};
		class Events {
			onUse = "_this call ULP_fnc_disguiseIdentity;";
			onRemove = "if ((player getVariable [""name"", """"]) isEqualTo (_this select 1)) then { player setVariable [""name"", nil, true]; [""You've lost the ID card you were disguising yourself with!""] call ULP_fnc_hint; };";
		};
		conditions = "true";
	};

	class Pickaxe {
		displayName = "鹤嘴镐（Pickaxe）";
		description = "用于采集物资的工具";
		icon = "Data\Icons\pickaxe.paa";
		buyPrice = 1200;
		sellPrice = 600;
		weight = 3;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class LumberAxe : Pickaxe {
		displayName = "伐木斧（Lumber Axe）";
		icon = "Data\Icons\lumberAxe.paa";
		buyPrice = 1180;
		sellPrice = 590;
		class Settings : Settings {};
	};
	class Shovel : Pickaxe {
		displayName = "铲子（Shovel）";
		icon = "Data\Icons\shovel.paa";
		buyPrice = 1100;
		sellPrice = 550;
		class Settings : Settings {};
	};
	class Extractor : Pickaxe {
		displayName = "提取器（Extractor）";
		icon = "Data\Icons\extractor.paa";
		buyPrice = 1950;
		sellPrice = 975;
		class Settings : Settings {};
	};
	class FishingNet : Pickaxe {
		displayName = "渔网（Fishing Net）";
		description = "可从船上部署，用于捕鱼的网具";
		icon = "Data\Icons\fishingNet.paa";
		buyPrice = 750;
		sellPrice = 375;
		weight = 4;
		class Settings : Settings {};
		class Events { onUse = "[] call ULP_fnc_dropFishingNet;"; };
	};
	class FuelCan : Pickaxe {
		displayName = "油桶（Fuel Can）";
		description = "用于给你的载具加油";
		icon = "Data\Icons\fuelCan.paa";
		buyPrice = 3000;
		sellPrice = 1500;
		weight = 12;
		class Settings : Settings {};
	};
	class Breathalyser : Pickaxe {
		displayName = "酒精测试仪（Breathalyser）";
		description = "用于检测当前酒精摄入程度的设备";
		icon = "Data\Icons\breathalyser.paa";
		buyPrice = 8400;
		sellPrice = 4200;
		weight = 1;
		class Settings : Settings {};
	};
	class Ziptie : Pickaxe {
		displayName = "扎带（Ziptie）";
		description = "在没有手铐时可用于束缚玩家";
		icon = "Data\Icons\ziptie.paa";
		buyPrice = 13500;
		sellPrice = 6750;
		weight = 1;
		class Settings : Settings {};
	};
	class Blindfold : Pickaxe {
		displayName = "眼罩（Blindfold）";
		description = "用于蒙住他人的眼睛";
		icon = "Data\Icons\blindfold.paa";
		buyPrice = 17000;
		sellPrice = 8500;
		weight = 1;
		class Settings : Settings {};
	};
	class Toolbox : Pickaxe {
		displayName = "工具箱（Toolbox）";
		description = "一箱可将物品拆解为基础材料的工具";
		icon = "Data\Icons\toolbox.paa";
		buyPrice = 25000;
		sellPrice = 12500;
		weight = 4;
		class Settings : Settings {};
	};
	class VehicleClamp : Pickaxe {
		displayName = "车辆夹轮器（Vehicle Clamp）";
		description = "可部署的夹轮装置，用于阻止车辆移动";
		icon = "Data\Icons\vehicleClamp.paa";
		buyPrice = 18200;
		sellPrice = 9700;
		weight = 8;
		class Settings : Settings {};
		class Events { onUse = "[] call ULP_fnc_clampVehicle;"; };
	};
	class Lighter : Pickaxe {
		displayName = "打火机（Lighter）";
		description = "可用于生火的简易打火机";
		icon = "Data\Icons\lighter.paa";
		buyPrice = 890;
		sellPrice = 445;
		weight = 1;
		class Settings : Settings {};
	};
	class Lockpick : Pickaxe {
		displayName = "开锁器（Lockpick）";
		description = "用于撬开载具和手铐的锁";
		icon = "Data\Icons\lockpick.paa";
		buyPrice = 2500;
		sellPrice = 1250;
		weight = 1;
		class Settings : Settings {};
	};
	class BoltCutter : Pickaxe {
		displayName = "断线钳（Bolt Cutter）";
		description = "用于剪断房产、空投和沉船上的锁";
		icon = "Data\Icons\boltCutter.paa";
		buyPrice = 345000;
		sellPrice = 172500;
		weight = 8;
		class Settings : Settings { isIllegal = true; };
		class Events { onUse = "[] call ULP_fnc_boltcut;"; };
		class Deconstruction {
			time = 40;
			workbench = false;
			blueprints[] = { { "HandheldTools", "B_BoltCutter" } };
			materials[] = { {"SteelPlate", 2} };
		};
	};
	class BigRedKey : BoltCutter {
		displayName = "大红钥匙（Big Red Key）";
		buyPrice = 31200;
		sellPrice = 15600;
		weight = 14;
		class Settings : Settings {};
		class Events : Events {};
		conditions = "[""Police_Main"", 5] call ULP_fnc_hasAccess";
	};
	class ExplosiveCharge : Pickaxe {
		displayName = "炸药包（Explosive Charge）";
		description = "用于炸毁加固锁具";
		icon = "Data\Icons\explosiveCharge.paa";
		buyPrice = 750000;
		sellPrice = 375000;
		weight = 3;
		class Settings : Settings { isIllegal = true; };
		class Deconstruction {
			time = 180;
			workbench = true;
			blueprints[] = { { "HandheldTools", "B_ExplosiveCharge" } };
			materials[] = { 
				{"SteelPlate", 2},
				{"CopperWiring", 1}
			};
		};
	};
	class IndustrialDrill : Pickaxe {
		displayName = "工业钻机（Industrial Drill）";
		icon = "Data\Icons\industrialDrill.paa";
		description = "用于破坏重度加固的锁具";
		buyPrice = 600000;
		sellPrice = 300000;
		weight = 16;
		class Settings : Settings { isIllegal = true; };
		class Events { onUse = "[] call ULP_fnc_drill;"; };
		class Deconstruction {
			time = 180;
			workbench = true;
			blueprints[] = { { "HandheldTools", "B_IndustrialDrill" } };
			materials[] = { {"SteelPlate", 1} };
		};
	};

	// Medical Supplies
	class Painkillers {
		displayName = "止痛药（Painkillers）";
		description = "两片可恢复少量生命值的药片";
		icon = "Data\Icons\painkillers.paa";
		buyPrice = 800;
		sellPrice = 400;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Bandage : Painkillers {
		displayName = "通用绷带（Generic Bandage）";
		description = "可作为医疗物资的制作材料";
		icon = "Data\Icons\bandage.paa";
		buyPrice = 850;
		sellPrice = 425;
		class Settings : Settings {};
	};
	class FieldDressing : Bandage {
		displayName = "战地敷料（Field Dressing）";
		icon = "Data\Icons\fieldDressing.paa";
		description = "适合处理擦伤的绷带";
	};
	class Packing : Bandage {
		displayName = "填塞绷带（Packing Bandage）";
		icon = "Data\Icons\packingBandage.paa";
		description = "适合处理擦伤和撕脱伤的绷带";
		buyPrice = 1000;
		sellPrice = 655;
	};
	class Elastic : Bandage {
		displayName = "弹性绷带（Elastic Bandage）";
		icon = "Data\Icons\elasticBandage.paa";
		description = "适合处理擦伤和裂伤的绷带";
		buyPrice = 1085;
		sellPrice = 750;
	};
	class QuickClot : Bandage {
		displayName = "速凝敷料（QuikClot）";
		icon = "Data\Icons\quikClot.paa";
		description = "适合处理擦伤和裂伤的止血敷料";
		buyPrice = 345;
		sellPrice = 125;
	};
	class BloodBag : Painkillers {
		displayName = "血袋（Blood Bag）";
		description = "用于防止失去行动能力的人失血过多";
		icon = "Data\Icons\bloodbag.paa";
		buyPrice = 1000;
		sellPrice = 500;
		weight = 2;
		class Settings : Settings {};
	};
	class Morphine : Painkillers {
		displayName = "吗啡（Morphine）";
		description = "用于降低心率，以便进行复苏";
		icon = "Data\Icons\injector.paa";
		buyPrice = 1200;
		sellPrice = 600;
		class Settings : Settings {};
	};
	class Epinephrine : Morphine {
		displayName = "肾上腺素（Epinephrine）";
		description = "用于提高心率，以便进行复苏";
		class Settings : Settings {};
	};
	class FirstAidKit : Painkillers {
		displayName = "急救包（First Aid Kit）";
		description = "内含多种医疗工具的急救套件";
		icon = "Data\Icons\firstAidKit.paa";
		buyPrice = 1500;
		sellPrice = 750;
		weight = 3;
		class Settings : Settings {};
	};
	class MediKit : FirstAidKit {
		displayName = "医疗包（MediKit）";
		icon = "Data\Icons\mediKit.paa";
		buyPrice = 28700;
		sellPrice = 14350;
		weight = 3;
		class Settings : Settings {};
	};
	class Defibrillator : MediKit {
		displayName = "除颤器（Defibrillator）";
		description = "用于识别并处理致命性心律失常的设备";
		icon = "Data\Icons\defibrillator.paa";
		buyPrice = 32600;
		sellPrice = 16300;
		weight = 3;
		class Settings : Settings {};
	};

	// Placeable Items
	class Stinger  {
		displayName = "破胎带（Stinger）";
		description = "可部署的尖刺条，用于刺破车辆轮胎";
		icon = "Data\Icons\stinger.paa";
		buyPrice = 8400;
		sellPrice = 8400;
		weight = 5;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Deconstruction {
			time = 45;
			workbench = true;
			blueprints[] = { { "HandheldTools", "B_MakeshiftStinger" } };
			materials[] = { 
				{"SteelBar", 3},
				{"IronBar", 1}
			};
		};
		class Events { onUse = "_this call ULP_fnc_spikeStrip;"; };
		conditions = "true";
	};
	class MakeshiftStinger : Stinger {
		displayName = "简易破胎带（Makeshift Stinger）";
		class Settings : Settings {};
		class Events : Events {};
	};

	class Stretcher {
		displayName = "担架（Stretcher）";
		description = "一种轻便可携带的架具，用于转运伤者或失去行动能力的人";
		icon = "Data\Icons\stretcher.paa";
		buyPrice = 12500;
		sellPrice = 12500;
		weight = 3;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Deconstruction {
			time = 15;
			workbench = true;
			blueprints[] = { { "MedicalSupplies", "B_Stretcher" } };
			materials[] = { {"SteelPlate", 1} };
		};
		class Events { onUse = "[""Stretcher"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[player, [""Police"", ""Medic"", ""Hato"", ""Dunamis""]] call ULP_fnc_isFaction || { ULP_Level >= 5 }";
	};

	class RoadCone_F : Stretcher { 
		displayName = "路锥（Road Cone）";
		description = "可随时部署的捆扎道具";
		icon = "Data\Icons\cone.paa";
		buyPrice = 800;
		sellPrice = 800;
		weight = 2;
		class Settings : Settings {};
		class Deconstruction {};
		class Events { onUse = "[""RoadCone_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class RoadCone_L_F : RoadCone_F { 
		displayName = "发光路锥（Road Cone (Light)）";
		buyPrice = 900;
		sellPrice = 900;
		class Settings : Settings {};
		class Events { onUse = "[""RoadCone_L_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Pole_F : RoadCone_F { 
		displayName = "立杆（Pole）";
		buyPrice = 300;
		sellPrice = 300;
		class Settings : Settings {};
		class Events { onUse = "[""Pole_F"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[] call ULP_fnc_donatorLevel >= 3";
	};

	class Land_PortableLight_single_F : RoadCone_F { 
		displayName = "便携照明灯（单头）（Portable Light (Single)）";
		icon = "Data\Icons\portableLight.paa";
		buyPrice = 1500;
		sellPrice = 1500;
		weight = 3;
		class Settings : Settings {};
		class Events { onUse = "[""Land_PortableLight_single_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_PortableLight_double_F : Land_PortableLight_single_F { 
		displayName = "便携照明灯（双头）（Portable Light (Double)）";
		buyPrice = 1700;
		sellPrice = 1700;
		class Settings : Settings {};
		class Events { onUse = "[""Land_PortableLight_double_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_PortableLight_02_single_yellow_F : Land_PortableLight_single_F { 
		displayName = "便携工地灯（单头黄灯）（Portable Lamp (Single, Yellow)）";
		buyPrice = 800;
		sellPrice = 800;
		weight = 2;
		class Settings : Settings {};
		class Events { onUse = "[""Land_PortableLight_02_single_yellow_F"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[] call ULP_fnc_donatorLevel >= 3";
	};
	class Land_PortableLight_02_double_yellow_F : Land_PortableLight_02_single_yellow_F { 
		displayName = "便携工地灯（双头黄灯）（Portable Lamp (Double, Yellow)）";
		class Settings : Settings {};
		class Events { onUse = "[""Land_PortableLight_02_double_yellow_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_PortableLight_02_quad_yellow_F : Land_PortableLight_02_single_yellow_F { 
		displayName = "便携工地灯（四头黄灯）（Portable Lamp (Quad, Yellow)）";
		class Settings : Settings {};
		class Events { onUse = "[""Land_PortableLight_02_quad_yellow_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	class Land_BarGate_F : RoadCone_F { 
		displayName = "栏杆门（Bar Gate）";
		icon = "Data\Icons\barGate.paa";
		buyPrice = 18000;
		sellPrice = 18000;
		weight = 12;
		class Settings : Settings {};
		class Events { onUse = "[""Land_BarGate_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_RoadBarrier_01_F : Land_BarGate_F { 
		displayName = "栏杆门 V2（Bar Gate (V2)）";
		class Settings : Settings {};
		class Events { onUse = "[""Land_RoadBarrier_01_F"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[] call ULP_fnc_donatorLevel >= 3";
	};

	class TapeSign_F : RoadCone_F { 
		displayName = "红白警戒带（Red-White Tape）";
		icon = "Data\Icons\roadBarrier.paa";
		buyPrice = 500;
		sellPrice = 500;
		weight = 2;
		class Settings : Settings {};
		class Events { onUse = "[""TapeSign_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class RoadBarrier_F : TapeSign_F { 
		displayName = "道路护栏（Road Barrier）";
		buyPrice = 4300;
		sellPrice = 4300;
		weight = 3;
		class Settings : Settings {};
		class Events { onUse = "[""RoadBarrier_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class RoadBarrier_small_F : RoadBarrier_F { 
		displayName = "小型道路护栏（Road Barrier (Small)）";
		buyPrice = 3600;
		sellPrice = 3600;
		weight = 2;
		class Settings : Settings {};
		class Events { onUse = "[""RoadBarrier_small_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PlasticBarrier_03_orange_F : RoadBarrier_F { 
		displayName = "塑料护栏（大型橙色）（Plastic Barrier (Large, Orange)）";
		buyPrice = 3500;
		sellPrice = 3500;
		weight = 6;
		class Settings : Settings {};
		class Events { onUse = "[""PlasticBarrier_03_orange_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PlasticBarrier_03_blue_F : PlasticBarrier_03_orange_F { 
		displayName = "塑料护栏（大型蓝色）（Plastic Barrier (Large, Blue)）";
		class Settings : Settings {};
		class Events { onUse = "[""PlasticBarrier_03_blue_F"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[] call ULP_fnc_donatorLevel >= 3";
	};
	class PlasticBarrier_02_yellow_F : RoadBarrier_F { 
		displayName = "塑料护栏（中型黄色）（Plastic Barrier (Medium, Yellow)）";
		buyPrice = 3100;
		sellPrice = 3100;
		weight = 4;
		class Settings : Settings {};
		class Events { onUse = "[""PlasticBarrier_02_yellow_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PlasticBarrier_02_grey_F : PlasticBarrier_02_yellow_F { 
		displayName = "塑料护栏（中型灰色）（Plastic Barrier (Medium, Grey)）";
		class Settings : Settings {};
		class Events { onUse = "[""PlasticBarrier_02_grey_F"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[] call ULP_fnc_donatorLevel >= 3";
	};
	class Land_CncBarrier_F : RoadBarrier_F { 
		displayName = "混凝土路障（Concrete Barrier）";
		buyPrice = 8000;
		sellPrice = 8000;
		weight = 10;
		class Settings : Settings {};
		class Events { onUse = "[""Land_CncBarrier_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_CncBarrier_stripes_F : Land_CncBarrier_F { 
		displayName = "混凝土路障（条纹）（Concrete Barrier (Stripes)）";
		class Settings : Settings {};
		class Events { onUse = "[""Land_CncBarrier_stripes_F"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[] call ULP_fnc_donatorLevel >= 3";
	};

	class Land_SandbagBarricade_01_half_F : RoadCone_F { 
		displayName = "短型沙袋掩体（Sandbag Barricade (Short)）";
		icon = "Data\Icons\sandbag.paa";
		buyPrice = 6000;
		sellPrice = 6000;
		weight = 3;
		class Settings : Settings {};
		class Events { onUse = "[""Land_SandbagBarricade_01_half_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_BagFence_Long_F : Land_SandbagBarricade_01_half_F { 
		displayName = "长型沙袋墙（Sandbag Wall (Long)）";
		buyPrice = 4000;
		sellPrice = 4000;
		weight = 2;
		class Settings : Settings {};
		class Events { onUse = "[""Land_BagFence_Long_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_BagFence_Short_F : Land_BagFence_Long_F { 
		displayName = "短型沙袋墙（Sandbag Wall (Short)）";
		class Settings : Settings {};
		class Events { onUse = "[""Land_BagFence_Short_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_BagFence_Round_F : Land_BagFence_Long_F { 
		displayName = "弧形沙袋墙（Sandbag Wall (Round)）";
		class Settings : Settings {};
		class Events { onUse = "[""Land_BagFence_Round_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	class Land_CzechHedgehog_01_old_F : RoadCone_F { 
		displayName = "捷克刺猬桩（Czech Hedgehog）";
		icon = "Data\Icons\hedgehog.paa";
		buyPrice = 16000;
		sellPrice = 16000;
		weight = 5;
		class Settings : Settings {};
		class Events { onUse = "[""Land_CzechHedgehog_01_old_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	class Land_CampingTable_white_F : RoadCone_F { 
		displayName = "露营桌（白色）（Camping Table (White)）";
		icon = "Data\Icons\table.paa";
		buyPrice = 2000;
		sellPrice = 2000;
		weight = 3;
		class Settings : Settings {};
		class Events { onUse = "[""Land_CampingTable_white_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_CampingTable_small_white_F : Land_CampingTable_white_F { 
		displayName = "小型露营桌（白色）（Camping Table (Small, White)）";
		buyPrice = 1500;
		sellPrice = 1500;
		weight = 2;
		class Settings : Settings {};
		class Events { onUse = "[""Land_CampingTable_small_white_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_CampingChair_V2_white_F : RoadCone_F { 
		displayName = "露营椅（白色）（Camping Chair (White)）";
		icon = "Data\Icons\chair.paa";
		buyPrice = 900;
		sellPrice = 900;
		weight = 2;
		class Settings : Settings {};
		class Events { onUse = "[""Land_CampingChair_V2_white_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Land_FieldToilet_F : RoadCone_F { 
		displayName = "野战厕所（Field Toilet）";
		icon = "Data\Icons\toilet.paa";
		buyPrice = 1800;
		sellPrice = 1800;
		weight = 5;
		class Settings : Settings {};
		class Events { onUse = "[""Land_FieldToilet_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	class Target_F : RoadCone_F { 
		displayName = "基础靶标（Simple Target）";
		icon = "Data\Icons\target.paa";
		buyPrice = 900;
		sellPrice = 900;
		weight = 2;
		class Settings : Settings {};
		class Events { onUse = "[""Target_F"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[] call ULP_fnc_donatorLevel >= 3";
	};
	class Land_Target_Dueling_01_F : Target_F { 
		displayName = "对决靶标（Dueling Target）";
		buyPrice = 200;
		sellPrice = 200;
		weight = 2;
		class Settings : Settings {};
		class Events { onUse = "[""Land_Target_Dueling_01_F"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[] call ULP_fnc_donatorLevel >= 3";
	};
	class Scarecrow_01_F : RoadCone_F { 
		displayName = "稻草人（Scarecrow）";
		icon = "Data\Icons\scarecrow.paa";
		buyPrice = 100;
		sellPrice = 100;
		weight = 2;
		class Settings : Settings {};
		class Events { onUse = "[""Scarecrow_01_F"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[] call ULP_fnc_donatorLevel >= 3";
	};

	class Flag_UK_F : RoadCone_F { 
		displayName = "旗帜（英国）（Flag (UK)）";
		icon = "Data\Icons\flag.paa";
		buyPrice = 900;
		sellPrice = 900;
		weight = 2;
		class Settings : Settings {};
		class Events { onUse = "[""Flag_UK_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class Flag_AltisColonial_F : Flag_UK_F { 
		displayName = "旗帜（Altis 殖民地）（Flag (Altis Colonial)）";
		class Settings : Settings {};
		class Events { onUse = "[""Flag_AltisColonial_F"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[] call ULP_fnc_donatorLevel >= 3";
	};
	class Flag_RedCrystal_F : Flag_UK_F { 
		displayName = "旗帜（Red Crystal）（Flag (Red Crystal)）";
		class Settings : Settings {};
		class Events { onUse = "[""Flag_RedCrystal_F"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[] call ULP_fnc_donatorLevel >= 3";
	};

	class PortableHelipadLight_01_yellow_F : RoadCone_F { 
		displayName = "便携灯（黄色）（Portable Light (Yellow)）";
		icon = "Data\Icons\portableLamp.paa";
		buyPrice = 400;
		sellPrice = 400;
		weight = 1;
		class Settings : Settings {};
		class Events { onUse = "[""PortableHelipadLight_01_yellow_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PortableHelipadLight_01_white_F : PortableHelipadLight_01_yellow_F { 
		displayName = "便携灯（白色）（Portable Light (White)）";
		class Settings : Settings {};
		class Events { onUse = "[""PortableHelipadLight_01_white_F"", _this select 0] call ULP_fnc_placeObject;"; };
		conditions = "[] call ULP_fnc_donatorLevel >= 3";
	};
	class PortableHelipadLight_01_red_F : PortableHelipadLight_01_white_F { 
		displayName = "便携灯（红色）（Portable Light (Red)）";
		class Settings : Settings {};
		class Events { onUse = "[""PortableHelipadLight_01_red_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PortableHelipadLight_01_green_F : PortableHelipadLight_01_white_F { 
		displayName = "便携灯（绿色）（Portable Light (Green)）";
		class Settings : Settings {};
		class Events { onUse = "[""PortableHelipadLight_01_green_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PortableHelipadLight_01_blue_F : PortableHelipadLight_01_white_F { 
		displayName = "便携灯（蓝色）（Portable Light (Blue)）";
		class Settings : Settings {};
		class Events { onUse = "[""PortableHelipadLight_01_blue_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};
	class PortableHelipadLight_01_F : PortableHelipadLight_01_white_F { 
		displayName = "便携灯（粉色）（Portable Light (Pink)）";
		class Settings : Settings {};
		class Events { onUse = "[""PortableHelipadLight_01_F"", _this select 0] call ULP_fnc_placeObject;"; };
	};

	// Major Crime Items
	class MarkedGold {
		displayName = "已标记黄金（Marked Gold）";
		description = "来自 HM Treasury、印有国王徽记的黄金";
		icon = "Data\Icons\ingot.paa";
		buyPrice = -1;
		sellPrice = 312500;
		weight = 16;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
			canSlingLoad = false;
		};
		conditions = "true";
	};
	class UnmarkedGold : MarkedGold {
		displayName = "未标记黄金（Unmarked Gold）";
		description = "来自 HM Treasury、已去除标识的黄金";
		sellPrice = 875000;
		class Settings : Settings {};
	};
	class EncryptedDrive : MarkedGold {
		displayName = "加密硬盘（Encrypted Drive）";
		description = "来自 HMS Liberty 指挥甲板的加密硬盘";
		icon = "Data\Icons\drive.paa";
		sellPrice = 500000;
		weight = 8;
		class Settings : Settings {};
	};
	class DecryptedDrive : EncryptedDrive {
		displayName = "解密硬盘（Decrypted Drive）";
		description = "来自 HMS Liberty 指挥甲板的已解密硬盘";
		sellPrice = 1250000;
		class Settings : Settings {};
	};
	class SpaceCapsuleDataDrive : DecryptedDrive {
		displayName = "太空舱数据盘（Space Capsule Data Drive）";
		description = "来自太空舱、藏有未知秘密的数据盘";
		sellPrice = 25000000;
		weight = 25;
		class Settings : Settings {};
	};
	class SeizedContraband : MarkedGold {
		displayName = "查获违禁品（Seized Contraband）";
		description = "由 Police 查获并存放在安全设施中的违禁品";
		icon = "Data\Icons\seizedContraband.paa";
		sellPrice = 297000;
		weight = 4;
		class Settings : Settings {};
	};
	class LargeGalleryPiece : MarkedGold {
		displayName = "大型画廊藏品（Large Gallery Piece）";
		description = "陈列在艺术馆中的一件艺术品";
		icon = "Data\Icons\galleryPiece.paa";
		sellPrice = 915625;
		weight = 14;
		class Settings : Settings {};
	};
	class MediumGalleryPiece : LargeGalleryPiece {
		displayName = "中型画廊藏品（Medium Gallery Piece）";
		sellPrice = 620000;
		weight = 10;
		class Settings : Settings {};
	};
	class SmallGalleryPiece : LargeGalleryPiece {
		displayName = "小型画廊藏品（Small Gallery Piece）";
		sellPrice = 456250;
		weight = 6;
		class Settings : Settings {};
	};

	// Unprocessed Materials
	class Tobacco {
		displayName = "烟草（Tobacco）";
		description = "可加工成香烟或雪茄的烟草叶";
		icon = "Data\Icons\tobacco.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 4;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Rock : Tobacco {
		displayName = "岩石（Rock）";
		description = "在 His Majesty's Pleasure 服刑期间开采出的石块";
		icon = "Data\Icons\ore.paa";
		sellPrice = 3;
		weight = 3;
		class Settings : Settings {};
		conditions = "ULP_Imprisioned";
	};
	class Coal : Tobacco {
		displayName = "煤炭（Coal）";
		description = "未经加工、可直接在 Coal Plant 出售的煤块";
		icon = "Data\Icons\ore.paa";
		buyPrice = -1;
		sellPrice = 2400;
		weight = 4;
		class Settings : Settings {
			onMarket = true;
			isSavable = true;
			isEventItem = true;
		};
	};
	class Coral : Coal {
		displayName = "珊瑚（Coral）";
		description = "在 Kavala 附近采集、未经加工即可出售的珊瑚";
		icon = "Data\Icons\coral.paa";
		sellPrice = 3675;
		weight = 7;
		class Settings : Settings { isIllegal = true; };
		conditions = "true";
	};
	class CopperOre : Tobacco {
		displayName = "铜矿石（Copper Ore）";
		description = "用镐开采后仍需进一步加工的矿石";
		icon = "Data\Icons\ore.paa";
		weight = 3;
		class Settings : Settings {};
	};
	class SilverOre : CopperOre {
		displayName = "银矿石（Silver Ore）";
		icon = "Data\Icons\ore.paa";
		class Settings : Settings {};
	};
	class IronOre : CopperOre {
		displayName = "铁矿石（Iron Ore）";
		icon = "Data\Icons\ore.paa";
		weight = 5;
		class Settings : Settings {};
	};
	class UraniumOre : CopperOre {
		displayName = "铀矿石（Uranium Ore）";
		icon = "Data\Icons\ore.paa";
		weight = 6;
		class Settings : Settings { isIllegal = true; };
	};
	class Sand : CopperOre {
		displayName = "沙子（Sand）";
		description = "用铲子收集后仍需进一步加工的沙子";
		icon = "Data\Icons\sand.paa";
		weight = 2;
		class Settings : Settings {};
	};
	class UnrefinedSalt : CopperOre {
		displayName = "粗盐（Unrefined Salt）";
		description = "用镐开采后仍需加工的盐矿";
		icon = "Data\Icons\saltUnrefined.paa";
		weight = 3;
		class Settings : Settings {};
	};
	class UnprocessedOil : CopperOre {
		displayName = "原油（Unrefined Oil）";
		description = "使用抽取设备钻取的石油，需要液罐卡车并进一步加工";
		icon = "Data\Icons\liquid.paa";
		weight = 4;
		class Settings : Settings {};
	};
	class UncutDiamond : CopperOre {
		displayName = "钻石原矿（Diamond Ore）";
		icon = "Data\Icons\ore.paa";
		description = "用镐开采后仍需切割加工的宝石原矿";
		class Settings : Settings {};
	};

	// Processed Materials
	class Cigarette {
		displayName = "香烟（Cigarette）";
		description = "可出售或自行吸食的一卷烟草";
		icon = "Data\Icons\cigarette.paa";
		buyPrice = -1;
		sellPrice = 3290;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = true;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Cigar : Cigarette {
		displayName = "雪茄（Cigar）";
		icon = "Data\Icons\cigar.paa";
		sellPrice = 3750;
		class Settings : Settings { isIllegal = true; };
	};
	class CopperBar : Cigarette {
		displayName = "铜锭（Copper Bar）";
		description = "可在 Altis Metal Exports 出售的金属锭";
		icon = "Data\Icons\ingot.paa";
		buyPrice = -1;
		sellPrice = 2375;
		weight = 2;
		class Settings : Settings {};
	};
	class SilverBar : CopperBar {
		displayName = "银锭（Silver Bar）";
		sellPrice = 2750;
		class Settings : Settings {};
	};
	class IronBar : CopperBar {
		displayName = "铁锭（Iron Bar）";
		sellPrice = 7187;
		class Settings : Settings {};
	};
	class UraniumBar : CopperBar {
		displayName = "铀锭（Uranium Bar）";
		description = "在专属商人处出售的金属锭";
		sellPrice = 12300;
		weight = 3;
		class Settings : Settings { 
			isIllegal = true; 
			isEventItem = false;
		};
	};
	class Glass : CopperBar {
		displayName = "玻璃（Glass）";
		description = "本质上就是加热后的沙子，可直接出售";
		icon = "Data\Icons\glass.paa";
		buyPrice = 2400;
		sellPrice = 1200;
		weight = 1;
		class Settings : Settings { isEventItem = false; };
	};
	class RefinedSalt : CopperBar {
		displayName = "精炼盐（Refined Salt）";
		description = "精炼完成、可直接出售的盐块";
		icon = "Data\Icons\saltRefined.paa";
		sellPrice = 3000;
		class Settings : Settings {};
	};
	class ProcessedOil : CopperBar {
		displayName = "精炼油（Refined Oil）";
		description = "已经装桶、可直接出售的精炼油";
		icon = "Data\Icons\oil.paa";
		buyPrice = 21150;
		sellPrice = 7050;
		weight = 3;
		class Settings : Settings { isEventItem = false; };
	};
	class CutDiamond : CopperBar {
		displayName = "切割钻石（Cut Diamond）";
		description = "经过精细切割、可直接出售的宝石";
		icon = "Data\Icons\gem.paa";
		sellPrice = 4600;
		class Settings : Settings {};
	};
	class CutBloodDiamond : CutDiamond {
		displayName = "切割血钻（Cut Blood Diamond）";
		icon = "Data\Icons\gem.paa";
		sellPrice = 2450;
		class Settings : Settings { 
			isIllegal = true;
			isEventItem = false;
		};
	};
	class FlawlessDiamond : CutDiamond {
		displayName = "无瑕钻石（Flawless Diamond）";
		sellPrice = 32200;
		class Settings : Settings { isEventItem = false; };
	};

	// Unprocessed Drugs
	class UnprocessedWeed {
		displayName = "未加工大麻（Unprocessed Weed）";
		description = "需要进一步加工成毒品的原料";
		icon = "Data\Icons\weedUnprocessed.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 4;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class UnprocessedHeroin : UnprocessedWeed {
		displayName = "鸦片（Opium）";
		icon = "Data\Icons\heroinUnprocessed.paa";
		weight = 5;
		class Settings : Settings {};
	};
	class UnprocessedCocaine : UnprocessedHeroin {
		displayName = "古柯叶（Coca Leaf）";
		icon = "Data\Icons\cocaineUnprocessed.paa";
		weight = 6;
		class Settings : Settings {};
	};
	class EphedrineBarrel : UnprocessedWeed {
		displayName = "麻黄碱桶（Ephedrine Barrel）";
		description = "制造冰毒的基础原料";
		icon = "Data\Icons\methUnprocessed.paa";
		buyPrice = 4500;
		weight = 8;
		class Settings : Settings { onMarket = true; };
	};

	// Processed Drugs
	class ProcessedWeed {
		displayName = "大麻（Weed）";
		description = "可在 Drug Dealer 处出售的毒品";
		icon = "Data\Icons\weedProcessed.paa";
		buyPrice = 10275;
		sellPrice = 3425;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
			isEventItem = true;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class ProcessedHeroin : ProcessedWeed {
		displayName = "海洛因（Heroin）";
		icon = "Data\Icons\heroinProcessed.paa";
		buyPrice = 17550;
		sellPrice = 5850;
		weight = 4;
		class Settings : Settings {};
	};
	class ProcessedCocaine : ProcessedWeed {
		displayName = "可卡因（Cocaine）";
		icon = "Data\Icons\cocaineProcessed.paa";
		buyPrice = 21600;
		sellPrice = 7200;
		weight = 5;
		class Settings : Settings {};
	};
	class ProcessedMeth : ProcessedWeed {
		displayName = "冰毒（Meth）";
		icon = "Data\Icons\methProcessed.paa";
		buyPrice = 54600;
		sellPrice = 18125;
		weight = 5;
		class Settings : Settings {};
	};
	class Ecstasy : ProcessedWeed {
		displayName = "摇头丸（Ecstasy）";
		icon = "Data\Icons\ecstasy.paa";
		buyPrice = 19688;
		sellPrice = 6563;
		weight = 1;
		class Settings : Settings {};
	};

	// Purified Drugs
	class PurifiedWeed {
		displayName = "纯化大麻（Purified Weed）";
		description = "控制 Northern Drug Cartel 后可制作的高纯度毒品";
		icon = "Data\Icons\weedProcessed.paa";
		buyPrice = 30825;
		sellPrice = 10275;
		weight = 3;
		class Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
			isScripted = false;
			isEventItem = true;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class PurifiedHeroin : PurifiedWeed {
		displayName = "纯化海洛因（Purified Heroin）";
		icon = "Data\Icons\heroinProcessed.paa";
		buyPrice = 52650;
		sellPrice = 17550;
		weight = 4;
		class Settings : Settings {};
	};
	class PurifiedCocaine : PurifiedWeed {
		displayName = "纯化可卡因（Purified Cocaine）";
		icon = "Data\Icons\cocaineProcessed.paa";
		buyPrice = 64800;
		sellPrice = 21600;
		weight = 5;
		class Settings : Settings {};
	};
	class PurifiedMeth : PurifiedWeed {
		displayName = "纯化冰毒（Purified Meth）";
		icon = "Data\Icons\methProcessed.paa";
		buyPrice = 163125;
		sellPrice = 54375;
		weight = 5;
		class Settings : Settings {};
	};

	// Weapons
	class WeaponParts {
		displayName = "武器零件（Weapon Parts）";
		description = "控制 Church Arms Cartel 后可加工得到的武器零件";
		icon = "Data\Icons\weaponParts.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 6;
		class Settings {
			onMarket = false;
			isIllegal = true;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class WeaponCrate : WeaponParts {
		displayName = "武器箱（Weapon Crate）";
		description = "控制 Church Arms Cartel 后可加工并出售的武器箱";
		icon = "Data\Icons\weaponCrate.paa";
		buyPrice = -1;
		sellPrice = 73375;
		weight = 5;
		class Settings : Settings { isSavable = true; };
	};

	// Cargo Mission Items
	class FreightCargo {
		displayName = "货运货物（Freight Cargo）";
		description = "只能装载在车辆上的贵重货箱";
		icon = "Data\Icons\freightCargo.paa";
		buyPrice = -1;
		sellPrice = 15700;
		weight = 24;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = false;
			isScripted = false;
			isEventItem = false;
			isSystemItem = true;
			canSlingLoad = false;
		};
		conditions = "true";
	};
	class StolenCargo : FreightCargo {
		displayName = "失窃货物（Stolen Cargo）";
		description = "明显来路不正、可进行走私的货物";
		icon = "Data\Icons\crate.paa";
		sellPrice = 89200;
		weight = 28;
		class Settings : Settings { isIllegal = true; };
	};
	class HumanitarianSupplies : FreightCargo {
		displayName = "人道援助物资（Humanitarian Supplies）";
		description = "运送给最需要帮助人群的救援物资";
		icon = "Data\Icons\humanitarianSupplies.paa";
		sellPrice = 0;
		weight = 1;
		class Settings : Settings {};
	};
	class Foodstuffs : FreightCargo {
		displayName = "食品物资（Foodstuffs）";
		description = "供应本地超市的食品货物";
		icon = "Data\Icons\foodstuffs.paa";
		sellPrice = 450;
		weight = 3;
		class Settings : Settings {};
	};
	class DunamisPropaganda : FreightCargo {
		displayName = "Dunamis 宣传物（Dunamis Propaganda）";
		description = "准备分发给地区同情者的 Dunamis 宣传材料";
		icon = "Data\Icons\dunamisPropaganda.paa";
		sellPrice = 0;
		weight = 1;
		class Settings : Settings {};
	};
	class Fuel : FreightCargo {
		displayName = "燃料（Fuel）";
		description = "需要运输到加油站的燃料";
		icon = "Data\Icons\fuel.paa";
		sellPrice = 600;
		weight = 1;
		class Settings : Settings {};
	};

	// Raw Fish
	class Salema_F_Raw {
		displayName = "生萨莱马鱼（Raw Salema）";
		description = "可在 Fish Market 出售或在 Cookhouse 烹饪的生鱼";
		icon = "Data\Icons\fish.paa";
		buyPrice = -1;
		sellPrice = 563;
		weight = 2;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = false;
			isScripted = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Ornate_random_F_Raw : Salema_F_Raw {
		displayName = "生华丽鱼（Raw Ornate）";
		sellPrice = 825;
		class Settings : Settings {};
	};
	class Mackerel_F_Raw : Salema_F_Raw {
		displayName = "生鲭鱼（Raw Mackerel）";
		sellPrice = 925;
		class Settings : Settings {};
	};
	class Tuna_F_Raw : Salema_F_Raw {
		displayName = "生金枪鱼（Raw Tuna）";
		sellPrice = 1028;
		class Settings : Settings {};
	};
	class Mullet_F_Raw : Salema_F_Raw {
		displayName = "生鲻鱼（Raw Mullet）";
		sellPrice = 1238;
		class Settings : Settings {};
	};
	class CatShark_F_Raw : Salema_F_Raw {
		displayName = "生猫鲨（Raw Catshark）";
		sellPrice = 1237;
		class Settings : Settings {};
	};
	class Turtle_F_Raw : Salema_F_Raw {
		displayName = "海龟（Turtle）";
		description = "猎获后可卖给特定商人的海龟";
		icon = "Data\Icons\turtle.paa";
		sellPrice = 35625;
		weight = 5;
		class Settings : Settings {
			onMarket = true;
			isIllegal = true;
			isSavable = true;
			isEventItem = true;
		};
	};

	// Cooked Fish
	class CookedSalema {
		displayName = "熟萨莱马鱼（Cooked Salema）";
		description = "可在 Fish Market 出售的熟鱼";
		icon = "Data\Icons\fish.paa";
		buyPrice = 2813;
		sellPrice = 1406;
		weight = 2;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class CookedOrnate : CookedSalema {
		displayName = "熟华丽鱼（Cooked Ornate）";
		buyPrice = 4125;
		sellPrice = 2063;
		class Settings : Settings {};
	};
	class CookedMackerel : CookedSalema {
		displayName = "熟鲭鱼（Cooked Mackerel）";
		buyPrice = 4625;
		sellPrice = 2313;
		class Settings : Settings {};
	};
	class CookedTuna : CookedSalema {
		displayName = "熟金枪鱼（Cooked Tuna）";
		buyPrice = 5140;
		sellPrice = 2570;
		class Settings : Settings {};
	};
	class CookedMullet : CookedSalema {
		displayName = "熟鲻鱼（Cooked Mullet）";
		buyPrice = 6188;
		sellPrice = 3094;
		class Settings : Settings {};
	};
	class CookedCatshark : CookedSalema {
		displayName = "熟猫鲨（Cooked Catshark）";
		buyPrice = 7733;
		sellPrice = 3866;
		class Settings : Settings {};
	};

	// Crafting Materials
	class Clay {
		displayName = "黏土（Clay）";
		description = "用于制作配方的基础材料";
		icon = "Data\Icons\clay.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class Wood : Clay {
		displayName = "木材（Wood）";
		icon = "Data\Icons\wood.paa";
		sellPrice = 450;
		weight = 2;
		class Settings : Settings {};
	};
	class Plank : Clay {
		displayName = "木板（Plank）";
		description = "可用于制作，也可在 Market 出售的材料";
		icon = "Data\Icons\plank.paa";
		sellPrice = 1688;
		weight = 2;
		class Settings {
			onMarket = true;
			isEventItem = true;
		};
	};
	class Rubber : Clay {
		displayName = "橡胶（Rubber）";
		icon = "Data\Icons\rubber.paa";
		class Settings : Settings {};
	};
	class SteelBar : Clay {
		displayName = "钢锭（Steel Bar）";
		icon = "Data\Icons\ingot.paa";
		weight = 2;
		class Settings : Settings {};
	};
	class GlassPanel : Clay {
		displayName = "玻璃板（Glass Panel）";
		icon = "Data\Icons\glass.paa";
		class Settings : Settings {};
	};
	class ReinforcedGlassPanel : GlassPanel {
		displayName = "强化玻璃板（Reinforced Glass Panel）";
		class Settings : Settings {};
	};
	class CopperWiring : Clay {
		displayName = "铜线（Copper Wiring）";
		icon = "Data\Icons\copperWiring.paa";
		class Settings : Settings {};
	};
	class CopperPlate : Clay {
		displayName = "铜板（Copper Plate）";
		icon = "Data\Icons\metalPlate.paa";
		class Settings : Settings {};
	};
	class IronPlate : CopperPlate {
		displayName = "铁板（Iron Plate）";
		class Settings : Settings {};
	};
	class SilverPlate : CopperPlate {
		displayName = "银板（Silver Plate）";
		class Settings : Settings {};
	};
	class SteelPlate : CopperPlate {
		displayName = "钢板（Steel Plate）";
		class Settings : Settings {};
	};
	class PackedOil : CopperPlate {
		displayName = "封装油料（Packed Oil）";
		icon = "Data\Icons\oil.paa";
		class Settings : Settings {};
	};
	class DiamondDrillBit : Clay {
		displayName = "金刚石钻头（Diamond Drill Bit）";
		icon = "Data\Icons\drillBit.paa";
		class Settings : Settings {};
	};
	class ExplosiveMaterials : Clay {
		displayName = "爆炸材料（Explosive Materials）";
		icon = "Data\Icons\explosiveMaterials.paa";
		weight = 3;
		class Settings : Settings {};
		class Deconstruction {
			time = 90;
			workbench = true;
			blueprints[] = { { "CraftingMaterials", "B_ExplosiveMaterials" } };
			materials[] = { 
				{"CopperWiring", 8},
				{"SteelPlate", 1}
			};
		};
	};

	// Archaeology Items
	class SurveyingEquipment {
		displayName = "勘测设备（Surveying Equipment）";
		description = "用于勘测挖掘点、定位文物的设备";
		icon = "Data\Icons\surveyingEquipment.paa";
		buyPrice = 28900;
		sellPrice = 14450;
		weight = 6;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Events { onUse = "[ULP_Archaeology] call ULP_fnc_surveySite;"; };
		class Deconstruction {
			time = 25;
			workbench = true;
			blueprints[] = { { "HandheldTools", "B_SurveyingEquipment" } };
			materials[] = { {"SilverPlate", 1} };
		};
		conditions = "true";
	};
	class ArchaeologistsEquipment : SurveyingEquipment {
		displayName = "考古设备（Archaeologists' Equipment）";
		description = "用于在挖掘点开掘文物的设备";
		icon = "Data\Icons\archaeologistsEquipment.paa";
		buyPrice = 24500;
		sellPrice = 12250;
		class Settings : Settings {};
		class Events { onUse = "[ULP_Archaeology] call ULP_fnc_digSite;"; };
		class Deconstruction {
			time = 25;
			workbench = true;
			blueprints[] = { { "HandheldTools", "B_ArchaeologistsEquipment" } };
			materials[] = { {"SilverPlate", 1} };
		};
	};

	class CommonMap {
		displayName = "普通藏宝图（Common Map）";
		description = "标注 Altis 各处文物点位的地图";
		icon = "Data\Icons\map.paa";
		buyPrice = 20000;
		sellPrice = 12500;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		class Events { onUse = "[""Common""] call ULP_fnc_getSite;"; };
		conditions = "true";
	};
	class UncommonMap : CommonMap {
		displayName = "不常见藏宝图（Uncommon Map）";
		buyPrice = -1;
		sellPrice = 168750;
		class Settings : Settings {};
		class Events { onUse = "[""Uncommon""] call ULP_fnc_getSite;"; };
	};
	class RareMap : UncommonMap {
		displayName = "稀有藏宝图（Rare Map）";
		sellPrice = 225000;
		class Settings : Settings {};
		class Events { onUse = "[""Rare""] call ULP_fnc_getSite;"; };
	};
	class LegendaryMap : UncommonMap {
		displayName = "传奇藏宝图（Legendary Map）";
		sellPrice = 312500;
		class Settings : Settings {};
		class Events { onUse = "[""Legendary""] call ULP_fnc_getSite;"; };
	};

	class CommonMapFragment {
		displayName = "普通地图碎片（Common Map Fragment）";
		description = "一张未完成地图的碎片";
		icon = "Data\Icons\mapFragment.paa";
		buyPrice = -1;
		sellPrice = 18750;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class UncommonMapFragment : CommonMapFragment {
		displayName = "不常见地图碎片（Uncommon Map Fragment）";
		sellPrice = 37500;
		class Settings : Settings {};
	};
	class RareMapFragment : CommonMapFragment {
		displayName = "稀有地图碎片（Rare Map Fragment）";
		sellPrice = 56250;
		class Settings : Settings {};
	};
	class LegendaryMapFragment : CommonMapFragment {
		displayName = "传奇地图碎片（Legendary Map Fragment）";
		sellPrice = 75000;
		class Settings : Settings {};
	};

	class OldCoin {
		displayName = "古旧硬币（Old Coin）";
		description = "可在 Altis Archaeologists 出售的文物";
		icon = "Data\Icons\oldCoin.paa";
		buyPrice = -1;
		sellPrice = 9109;
		weight = 1;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class CoinBundle : OldCoin {
		displayName = "硬币捆（Coin Bundle）";
		icon = "Data\Icons\coinBundle.paa";
		sellPrice = 388476;
		weight = 2;
		class Settings : Settings {};
	};
	class BrokenPot : OldCoin {
		displayName = "破损陶罐（Broken Pot）";
		icon = "Data\Icons\brokenPot.paa";
		sellPrice = 19469;
		weight = 4;
		class Settings : Settings {};
	};
	class RestoredPot : BrokenPot {
		displayName = "修复陶罐（Restored Pot）";
		icon = "Data\Icons\restoredPot.paa";
		sellPrice = 49296;
		class Settings : Settings {};
	};
	class BluntStoneKnife : OldCoin {
		displayName = "钝石刀（Blunt Stone Knife）";
		icon = "Data\Icons\bluntStoneKnife.paa";
		sellPrice = 30969;
		weight = 2;
		class Settings : Settings {};
	};
	class SharpStoneKnife : OldCoin {
		displayName = "锋利石刀（Sharp Stone Knife）";
		icon = "Data\Icons\sharpStoneKnife.paa";
		sellPrice = 96171;
		weight = 2;
		class Settings : Settings {};
	};
	class FossilisedBone : OldCoin {
		displayName = "化石骨（Fossilised Bone）";
		icon = "Data\Icons\fossilisedBone.paa";
		sellPrice = 39494;
		weight = 2;
		class Settings : Settings {};
	};
	class UnidentifiedSkull : OldCoin {
		displayName = "未鉴定头骨（Unidentified Skull）";
		sellPrice = 82313;
		weight = 4;
		class Settings : Settings {};
	};
	class IdentifiedSkull : UnidentifiedSkull {
		displayName = "已鉴定头骨（Identified Skull）";
		icon = "Data\Icons\unidentifiedSkull.paa";
		sellPrice = 2423750;
		class Settings : Settings {};
	};
	class PetrifiedShield : OldCoin {
		displayName = "石化盾牌（Petrified Shield）";
		icon = "Data\Icons\petrifiedShield.paa";
		sellPrice = 87875;
		weight = 6;
		class Settings : Settings {};
	};
	class WeatheredSculpture : OldCoin {
		displayName = "风化雕像（Weathered Sculpture）";
		icon = "Data\Icons\weatheredSculpture.paa";
		sellPrice = 102188;
		weight = 5;
		class Settings : Settings {};
	};
	class AncientAmber : OldCoin {
		displayName = "远古琥珀（Ancient Amber）";
		icon = "Data\Icons\ancientAmber.paa";
		sellPrice = 113659;
		class Settings : Settings {};
	};
	class ReligiousTotem : OldCoin {
		displayName = "宗教图腾（Religious Totem）";
		icon = "Data\Icons\religiousTotem.paa";
		sellPrice = 122438;
		weight = 2;
		class Settings : Settings {};
	};
	class StrongMetalRing : OldCoin {
		displayName = "坚固金属戒（Strong Metal Ring）";
		icon = "Data\Icons\strongMetalRing.paa";
		sellPrice = 148625;
		class Settings : Settings {};
	};
	class DiamondRing : OldCoin {
		displayName = "钻石金属戒（Diamond Metal Ring）";
		icon = "Data\Icons\diamondRing.paa";
		sellPrice = 307625;
		class Settings : Settings {};
	};
	class EmeraldAmulet : OldCoin {
		displayName = "翡翠护符（Emerald Amulet）";
		icon = "Data\Icons\emeraldAmulet.paa";
		sellPrice = 250781;
		weight = 1;
		class Settings : Settings {};
	};
	class AncientLedger : OldCoin {
		displayName = "远古账本（Ancient Ledger）";
		icon = "Data\Icons\ancientLedger.paa";
		sellPrice = 296546;
		weight = 3;
		class Settings : Settings {};
	};
	class HandSmoothedRunestone : OldCoin {
		displayName = "手工磨制符文石（Hand-Smoothed Runestone）";
		icon = "Data\Icons\handSmoothedRunestone.paa";
		sellPrice = 348796;
		weight = 4;
		class Settings : Settings {};
	};
	class JeweledNecklace : OldCoin {
		displayName = "珠宝项链（Jeweled Necklace）";
		icon = "Data\Icons\jeweledNecklace.paa";
		sellPrice = 415421;
		class Settings : Settings {};
	};
	class BrokenTimepiece : OldCoin {
		displayName = "损坏时计（Broken Timepiece）";
		icon = "Data\Icons\brokenTimepiece.paa";
		sellPrice = 385594;
		weight = 1;
		class Settings : Settings {};
	};
	class RestoredTimepiece : BrokenTimepiece {
		displayName = "修复时计（Restored Timepiece）";
		sellPrice = 580125;
		weight = 1;
		class Settings : Settings {};
	};

	// Electronics
	class Capacitor {
		displayName = "电容（Capacitor）";
		description = "用于制作电子设备的元件";
		icon = "Data\Icons\capacitor.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 1;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class ElectronicCircuit : Capacitor {
		displayName = "电子电路（Electronic Circuit）";
		icon = "Data\Icons\electronicCircuit.paa";
		class Settings : Settings {};
	};
	class PrintedCircuitBoard : Capacitor {
		displayName = "印刷电路板（Printed Circuit Board）";
		icon = "Data\Icons\electronicCircuit.paa";
		class Settings : Settings {};
	};
	class Motherboard : Capacitor {
		displayName = "主板（Motherboard）";
		icon = "Data\Icons\motherboard.paa";
		class Settings : Settings {};
	};
	class CentralProcessingUnit : Capacitor {
		displayName = "中央处理器（Central Processing Unit）";
		icon = "Data\Icons\cpu.paa";
		class Settings : Settings {};
	};
	class GraphicsProcessingUnit : Capacitor {
		displayName = "图形处理器（Graphics Processing Unit）";
		icon = "Data\Icons\gpu.paa";
		weight = 2;
		class Settings : Settings {};
	};
	class RandomAccessMemory : Capacitor {
		displayName = "随机存取内存（Random Access Memory）";
		icon = "Data\Icons\ram.paa";
		class Settings : Settings {};
	};
	class SolidStateDrive : Capacitor {
		displayName = "固态硬盘（Solid State Drive）";
		icon = "Data\Icons\ssd.paa";
		class Settings : Settings {};
	};
	class PowerSupplyUnit : Capacitor {
		displayName = "电源供应器（Power Supply Unit）";
		icon = "Data\Icons\psu.paa";
		weight = 2;
		class Settings : Settings {};
	};
	class Laptop : Capacitor {
		displayName = "笔记本电脑（Laptop）";
		description = "可在 Altis Electronics 出售的电子设备";
		icon = "Data\Icons\laptop.paa";
		sellPrice = 654345;
		weight = 10;
		class Settings {
			onMarket = true;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
	};
	class Desktop : Laptop {
		displayName = "台式电脑（Desktop）";
		icon = "Data\Icons\desktop.paa";
		sellPrice = 1056444;
		weight = 15;
		class Settings : Settings {};
	};
	class MiningRig : Laptop {
		displayName = "矿机（Mining Rig）";
		icon = "Data\Icons\miningRig.paa";
		sellPrice = 5962147;
		weight = 64;
		class Settings : Settings {};
	};
	class SignalJammer : Laptop {
		displayName = "信号干扰器（Signal Jammer）";
		icon = "Data\Icons\signalJammer.paa";
		weight = 1;
		sellPrice = 82725;
		class Settings : Settings {};
	};
	class HackingDevice : Laptop {
		displayName = "黑客设备（Hacking Device）";
		description = "用于进入 Major Crime 现场的设备";
		icon = "Data\Icons\hackingDevice.paa";
		buyPrice = 475000;
		sellPrice = 237500;
		weight = 1;
		class Settings : Settings {};
		class Deconstruction {
			time = 100;
			workbench = true;
			blueprints[] = { { "Electronics", "B_HackingDevice" } };
			materials[] = { {"ElectronicCircuit", 1} };
		};
	};
	class PanicButton : Capacitor {
		displayName = "紧急报警器（Panic Button）";
		description = "可向 Police 发送警报的装置";
		icon = "Data\Icons\panicButton.paa";
		buyPrice = 900;
		sellPrice = 450;
		weight = 1;
		class Settings : Settings {};
		class Deconstruction {
			time = 45;
			workbench = false;
			blueprints[] = { { "Electronics", "B_PanicButton" } };
			materials[] = { {"CopperWiring", 1} };
		};
		class Events { onUse = "[] call ULP_fnc_panic;"; };
	};

	// Vehicle Components
	class Tyre {
		displayName = "轮胎（Tyre）";
		description = "用于制造载具的零部件";
		icon = "Data\Icons\tyre.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 5;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class ReinforcedTyre : Tyre {
		displayName = "强化轮胎（Reinforced Tyre）";
		weight = 10;
		class Settings : Settings {};
	};
	class LightArmourPlate : Tyre {
		displayName = "轻型装甲板（Light Armour Plate）";
		icon = "Data\Icons\armourPlate.paa";
		class Settings : Settings {};
	};
	class HeavyArmourPlate : LightArmourPlate {
		displayName = "重型装甲板（Heavy Armour Plate）";
		weight = 15;
		class Settings : Settings {};
	};
	class SmallCargoBed : Tyre {
		displayName = "小型货斗（Small Cargo Bed）";
		icon = "Data\Icons\cargoBed.paa";
		weight = 10;
		class Settings : Settings {};
	};
	class LargeCargoBed : SmallCargoBed {
		displayName = "大型货斗（Large Cargo Bed）";
		weight = 20;
		class Settings : Settings {};
	};
	class GuidanceSystem : Tyre {
		displayName = "制导系统（Guidance System）";
		icon = "Data\Icons\guidanceSystem.paa";
		class Settings : Settings {};
	};
	class EngineComponent : Tyre {
		displayName = "发动机部件（Engine Component）";
		icon = "Data\Icons\engineComponent.paa";
		weight = 20;
		class Settings : Settings {};
	};
	class BasicFlightInstruments : Tyre {
		displayName = "基础飞行仪表（Basic Flight Instruments）";
		icon = "Data\Icons\flightInstruments.paa";
		class Settings : Settings {};
	};
	class AdvancedFlightInstruments : BasicFlightInstruments {
		displayName = "高级飞行仪表（Advanced Flight Instruments）";
		class Settings : Settings {};
	};
	class VehicleParts : Tyre {
		displayName = "载具零件（Vehicle Parts）";
		icon = "Data\Icons\vehicleParts.paa";
		buyPrice = 200000;
		weight = 1;
		class Settings : Settings {};
	};
	class SimpleVehicleComponent : Tyre {
		displayName = "基础载具部件（Simple Vehicle Component）";
		icon = "Data\Icons\vehicleComponent.paa";
		class Settings : Settings {};
	};
	class ImprovedVehicleComponent : SimpleVehicleComponent {
		displayName = "改良载具部件（Improved Vehicle Component）";
		weight = 10;
		class Settings : Settings {};
	};
	class PerfectedVehicleComponent : SimpleVehicleComponent {
		displayName = "完善载具部件（Perfected Vehicle Component）";
		weight = 15;
		class Settings : Settings {};
	};

	// Vehicle Upgrades
	class ImprovedStorageUpgrade {
		displayName = "改良储存升级（Improved Storage Upgrade）";
		description = "将储存容量提升 10%";
		icon = "Data\Icons\improvedStorageUpgrade.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 10;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class ImprovedLocksUpgrade : ImprovedStorageUpgrade {
		displayName = "改良车锁升级（Improved Locks Upgrade）";
		description = "使撬锁所需时间增加 50%";
		icon = "Data\Icons\improvedLocksUpgrade.paa";
		class Settings : Settings {};
	};
	class ImprovedHullUpgrade : ImprovedStorageUpgrade {
		displayName = "改良车体升级（Improved Hull Upgrade）";
		description = "使车体装甲值提升 25%";
		icon = "Data\Icons\improvedHullUpgrade.paa";
		class Settings : Settings {};
	};
	class ImprovedTyresUpgrade : ImprovedStorageUpgrade {
		displayName = "改良轮胎升级（Improved Tyres Upgrade）";
		description = "使轮胎装甲值提升 25%";
		icon = "Data\Icons\tyre.paa";
		class Settings : Settings {};
	};
	class PerformanceEngineUpgrade : ImprovedStorageUpgrade {
		displayName = "性能引擎升级（Performance Engine Upgrade）";
		description = "加速度提升 10%，最高速度提升 5% [与 Efficient Engine 互斥]";
		icon = "Data\Icons\improvedEngineUpgrade.paa";
		class Settings : Settings {};
	};
	class EfficientEngineUpgrade : ImprovedStorageUpgrade {
		displayName = "节能引擎升级（Efficient Engine Upgrade）";
		description = "燃油消耗降低 30% [与 Performance Engine 互斥]";
		icon = "Data\Icons\improvedEngineUpgrade.paa";
		class Settings : Settings {};
	};
	class StongCasingUpgrade : ImprovedStorageUpgrade {
		displayName = "加固外壳升级（Stong Casing Upgrade）";
		description = "使拆解流程耗时增加 50%";
		icon = "Data\Icons\stongCasingUpgrade.paa";
		class Settings : Settings {};
	};
	class TrackingDeviceUpgrade : ImprovedStorageUpgrade {
		displayName = "追踪装置升级（Tracking Device Upgrade）";
		description = "每 15 秒在地图上更新一次载具位置";
		icon = "Data\Icons\trackingDeviceUpgrade.paa";
		class Settings : Settings {};
	};
	class ClonedPlatesUpgrade : ImprovedStorageUpgrade {
		displayName = "克隆车牌升级（Cloned Plates Upgrade）";
		description = "为应对 ANPR 系统而随机化载具车牌";
		icon = "Data\Icons\clonedPlatesUpgrade.paa";
		class Settings : Settings {};
	};
	class AutomaticLoaderUpgrade : ImprovedStorageUpgrade {
		displayName = "自动装载升级（Automatic Loader Upgrade）";
		description = "允许自动处理载具内的货物";
		icon = "Data\Icons\clonedPlatesUpgrade.paa";
		class Settings : Settings {};
	};

	// Housing Upgrades
	class PersonalAlarmUpgrade {
		displayName = "个人警报升级（Personal Alarm Upgrade）";
		description = "有人闯入你的房产时会通知你";
		icon = "Data\Icons\personalAlarmUpgrade.paa";
		buyPrice = -1;
		sellPrice = -1;
		weight = 20;
		class Settings {
			onMarket = false;
			isIllegal = false;
			isSavable = true;
			isScripted = false;
			isEventItem = false;
			isSystemItem = false;
		};
		conditions = "true";
	};
	class CentralAlarmUpgrade : PersonalAlarmUpgrade {
		displayName = "中央警报升级（Central Alarm Upgrade）";
		description = "有人闯入你的房产时会通知你的 Group";
		class Settings : Settings {};
	};
	class ImprovedDoorsUpgrade : PersonalAlarmUpgrade {
		displayName = "强化门锁升级（Improved Doors Upgrade）";
		description = "使破坏门锁所需时间增加 50%";
		icon = "Data\Icons\improvedDoorsUpgrade.paa";
		class Settings : Settings {};
	};
	class BulletproofWindowsUpgrade : PersonalAlarmUpgrade {
		displayName = "防弹窗升级（Bulletproof Windows Upgrade）";
		description = "使玻璃窗装甲值提升 25%";
		icon = "Data\Icons\bulletproofGlassUpgrade.paa";
		class Settings : Settings {};
	};
	class ImprovedContainerUpgrade : PersonalAlarmUpgrade {
		displayName = "改良容器升级（Improved Container Upgrade）";
		description = "将 vItem 存储容量提升 10%";
		icon = "Data\Icons\improvedStorageUpgrade.paa";
		class Settings : Settings {};
	};
	class SingalJammerUpgrade : PersonalAlarmUpgrade {
		displayName = "信号干扰升级（Singal Jammer Upgrade）";
		description = "阻断你房产内部的 GPS 和无线电信号";
		icon = "Data\Icons\singalJammerUpgrade.paa";
		class Settings : Settings {};
	};
	class PersonalFridgeUpgrade : PersonalAlarmUpgrade {
		displayName = "私人冰箱升级（Personal Fridge Upgrade）";
		description = "提供冰箱使用权限，可补充食物与水分";
		icon = "Data\Icons\personalFridgeUpgrade.paa";
		class Settings : Settings {};
	};
	class PersonalWorkbenchUpgade : PersonalAlarmUpgrade {
		displayName = "私人工作台升级（Personal Workbench Upgade）";
		description = "提供工作台使用权限";
		icon = "Data\Icons\personalWorkbenchUpgade.paa";
		class Settings : Settings {};
	};
	class PersonalMailboxUpgrade : PersonalAlarmUpgrade {
		displayName = "私人邮箱升级（Personal Mailbox Upgrade）";
		description = "提供邮箱使用权限";
		icon = "Data\Icons\personalMailboxUpgrade.paa";
		class Settings : Settings {};
	};
};
