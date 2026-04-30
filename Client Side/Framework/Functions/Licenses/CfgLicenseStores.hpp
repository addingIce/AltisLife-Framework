class CfgLicenseStores {
	class DVLA {
		title = "DVLA 车辆管理局（DVLA）";
		factions[] = { "Civilian", "Dunamis" };
		condition = "!([""Driving""] call ULP_fnc_hasLicense) || { !([""Trucking""] call ULP_fnc_hasLicense) } || { !([""Boating""] call ULP_fnc_hasLicense) } || { !([""Piloting""] call ULP_fnc_hasLicense) }";
		licenses[] = { "Driving", "Trucking", "Boating", "Piloting" };
	};

	class Taxi : DVLA {
		title = "Taxi Altis（Taxi Altis）";
		condition = "!([""Taxi""] call ULP_fnc_hasLicense)";
		licenses[] = { "Taxi" };
	};
	class Solicitor : DVLA {
		title = "Altis Solicitors（Altis Solicitors）";
		condition = "!([""Solicitor""] call ULP_fnc_hasLicense)";
		licenses[] = { "Solicitor" };
	};
	class News : DVLA {
		title = "AAN World News（AAN World News）";
		condition = "!([""News""] call ULP_fnc_hasLicense)";
		licenses[] = { "News" };
	};
	class IDAP : DVLA {
		title = "IDAP 志愿服务（IDAP Volunteer）";
		condition = "!([""IDAP""] call ULP_fnc_hasLicense) && { ULP_Reputation >= 0 }";
		licenses[] = { "IDAP" };
	};

	class Schnapps : DVLA { 
		title = "Schnapps 加工点（Schnapps Processing）";
		condition = "!([""Schnapps""] call ULP_fnc_hasLicense)";
		licenses[] = { "Schnapps" }; 
	};
	class Tobacco : DVLA { 
		title = "烟草加工点（Tobacco Processing）";
		condition = "!([""Tobacco""] call ULP_fnc_hasLicense)";
		licenses[] = { "Tobacco" }; 
	};
	class Copper : DVLA { 
		title = "铜矿加工点（Copper Processing）";
		condition = "!([""Copper""] call ULP_fnc_hasLicense)";
		licenses[] = { "Copper" }; 
	};
	class Silver : DVLA { 
		title = "银矿加工点（Silver Processing）";
		condition = "!([""Silver""] call ULP_fnc_hasLicense)";
		licenses[] = { "Silver" }; 
	};
	class Iron : DVLA { 
		title = "铁矿加工点（Iron Processing）";
		condition = "!([""Iron""] call ULP_fnc_hasLicense)";
		licenses[] = { "Iron" }; 
	};
	class Uranium : DVLA { 
		title = "铀矿加工点（Uranium Processing）";
		condition = "!([""Uranium""] call ULP_fnc_hasLicense)";
		licenses[] = { "Uranium" }; 
	};
	class Diamond : DVLA { 
		title = "钻石加工点（Diamond Processing）";
		condition = "!([""Diamond""] call ULP_fnc_hasLicense)";
		licenses[] = { "Diamond" }; 
	};
	class Salt : DVLA { 
		title = "盐加工点（Salt Processing）";
		condition = "!([""Salt""] call ULP_fnc_hasLicense)";
		licenses[] = { "Salt" }; 
	};
	class Sand : DVLA { 
		title = "沙料加工点（Sand Processing）";
		condition = "!([""Sand""] call ULP_fnc_hasLicense)";
		licenses[] = { "Sand" }; 
	};
	class Oil : DVLA { 
		title = "石油加工点（Oil Processing）";
		condition = "!([""Oil""] call ULP_fnc_hasLicense)";
		licenses[] = { "Oil" }; 
	};
	class Weed : DVLA { 
		title = "大麻加工点（Weed Processing）";
		condition = "!([""Weed""] call ULP_fnc_hasLicense)";
		licenses[] = { "Weed" }; 
	};
	class Heroin : DVLA { 
		title = "海洛因加工点（Heroin Processing）";
		condition = "!([""Heroin""] call ULP_fnc_hasLicense)";
		licenses[] = { "Heroin" }; 
	};
	class Cocaine : DVLA {
		title = "可卡因加工点（Cocaine Processing）";
		condition = "!([""Cocaine""] call ULP_fnc_hasLicense)"; 
		licenses[] = { "Cocaine" }; 
	};
	class Meth : DVLA { 
		title = "冰毒加工点（Meth Processing）";
		condition = "!([""Meth""] call ULP_fnc_hasLicense)";
		licenses[] = { "Meth" }; 
	};
	class Weapons : DVLA { 
		title = "武器加工点（Weapons Processing）";
		condition = "!([""Weapons""] call ULP_fnc_hasLicense)";
		licenses[] = { "Weapons" }; 
	};
	class MultiDrug : DVLA {
		title = "多类毒品加工点（Multi-Drug Processing）";
		condition = "!([""Weed""] call ULP_fnc_hasLicense) || { !([""Heroin""] call ULP_fnc_hasLicense) } || { !([""Cocaine""] call ULP_fnc_hasLicense) } || { !([""ULP_fnc_hasLicense""] call ULP_fnc_hasLicense) }";
		licenses[] = { "Weed", "Heroin", "Cocaine", "Meth" };
	};

	class Home : DVLA {
		title = "房产业主协会（Homeowner's Association）";
		condition = "!([""Home""] call ULP_fnc_hasLicense)";
		licenses[] = { "Home" };
	};

	class Gun : DVLA {
		title = "枪械商店（Gun Store）";
		condition = "!([""Handgun""] call ULP_fnc_hasLicense) || { !([""SMG""] call ULP_fnc_hasLicense) }";
		licenses[] = { "Handgun", "SMG" };
	};
	class Security : DVLA {
		title = "企业安保执照处（Security Contractors）";
		condition = "!([""Security""] call ULP_fnc_hasLicense)";
		licenses[] = { "Security" };
	};
	class Protection : DVLA {
		title = "政府保护执照处（Government Protection）";
		condition = "!([""Protection""] call ULP_fnc_hasLicense)";
		licenses[] = { "Protection" };
	};

	class Hunting : DVLA {
		title = "狩猎营地（Hunting Camp）";
		condition = "!([""Hunting""] call ULP_fnc_hasLicense)";
		licenses[] = { "Hunting" };
	};

	class Rebel : DVLA {
		title = "Rebel 据点（Rebel）";
		condition = "!([""Rebel""] call ULP_fnc_hasLicense)";
		licenses[] = { "Rebel" };
	};

	class Blackmarket : DVLA {
		title = "黑市（Blackmarket）";
		condition = "[""Rebel""] call ULP_fnc_hasLicense && { !([""Blackmarket""] call ULP_fnc_hasLicense) } && { [""Blackmarketer""] call ULP_fnc_hasPerk || [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
		licenses[] = { "Blackmarket" };
	};
}; 
