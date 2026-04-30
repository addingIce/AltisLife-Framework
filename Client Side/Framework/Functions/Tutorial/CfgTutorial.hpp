class CfgTutorial {
	class Stages {
		class GetCash {
			displayName = "准备 £100k 现金";
			description = "使用 ATM 取出 £100k 现金";
			location[] = { 3640.48, 13082.8, 0 };
			nextStage = "BuyBackpack";
			condition = "ULP_234_Cash >= 100000 || { [""Driving""] call ULP_fnc_hasLicense }";
		};
		class BuyBackpack {
			displayName = "购买背包";
			description = "前往服装店购买一个背包";
			location[] = { 3630.21, 13077.2, 0 };
			nextStage = "BuyLicense";
			condition = "!((backpack player) isEqualTo """") || { [""Driving""] call ULP_fnc_hasLicense }";
		};
		class BuyLicense {
			displayName = "购买驾驶执照";
			description = "前往 DVLA 购买驾驶执照";
			location[] = { 3649.38, 13093.8, 0 };
			nextStage = "BuyCar";
			condition = "[""Driving""] call ULP_fnc_hasLicense";
		};
		class BuyCar {
			displayName = "购买车辆";
			description = "前往车店购买一辆 Offroad";
			location[] = { 3693.8, 13155, 0 };
			nextStage = "StoreCash";
			condition = "!(ULP_Keys isEqualTo [])";
		};
		class StoreCash {
			displayName = "存入现金";
			description = "把车开到 ATM 附近，并把剩余现金存进去。你可以按 <t color='#B92DE0'>U</t> 解锁载具";
			location[] = { 3640.48, 13082.8, 0 };
			nextStage = "GoAppleField";
			condition = "ULP_234_Cash isEqualTo 0";
		};
		class GoAppleField {
			displayName = "前往苹果园";
			description = "前往 Apple Field 苹果园";
			location[] = { 4193.83, 12993.5, 0 };
			nextStage = "GatherApples";
			condition = "(player distance [4193.83,12993.5, 0]) <= 20";
		};
		class GatherApples {
			displayName = "采集苹果";
			description = "按 <t color='#B92DE0'>Left Windows</t> 键采集苹果。这个交互键可以在 <t color='#B92DE0'>Custom Control 10</t> 里重新绑定";
			location[] = { 4193.83, 12993.5, 0 };
			nextStage = "GoMarket";
			condition = """FreshApple"" in ULP_Inventory";
		};
		class GoMarket {
			displayName = "前往综合市场";
			description = "前往 General Market 综合市场";
			location[] = { 3629, 13095, 0 };
			nextStage = "SellApples";
			condition = "(player distance [3629, 13095, 0]) <= 10";
		};
		class SellApples {
			displayName = "出售苹果";
			description = "把你采集到的苹果卖给市场";
			location[] = { 3629, 13095, 0 };
			condition = "!(""FreshApple"" in ULP_Inventory)";
		};
	};
};
