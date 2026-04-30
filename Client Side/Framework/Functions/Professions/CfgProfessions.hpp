class CfgProfessions {
	class Repairing {
		displayName = "维修";
		icon = "Data\UI\Professions\repairing.paa";
		effectDescription = "减少维修所需时间 %1%2";
		effectCalculation = "5 * (_this select 0)"; // (_this select 0) refers to the level of this profession and (_this select 1) is the current xp.
		xpLevel = 100;
		maxLevel = 5;
	};

	class Fishing : Repairing {
		displayName = "捕鱼";
		icon = "Data\UI\Professions\fishing.paa";
		effectDescription = "减少捕鱼所需时间 %1%2";
	};

	class Gathering : Repairing {
		displayName = "采集";
		icon = "Data\UI\Professions\gathering.paa";
		effectDescription = "减少采集所需时间 %1%2";
		effectCalculation = "5 * (_this select 0)";
		maxLevel = 10;
	};

	class Mining : Repairing {
		displayName = "采矿";
		icon = "Data\UI\Professions\mining.paa";
		effectDescription = "减少采矿所需时间 %1%2";
		effectCalculation = "5 * (_this select 0)";
		maxLevel = 10;
	};

	class Processing : Repairing {
		displayName = "加工";
		icon = "Data\UI\Professions\processing.paa";
		effectDescription = "减少加工所需时间 %1%2";
		effectCalculation = "5 * (_this select 0)";
	};

	class Cooking : Repairing {
		displayName = "烹饪";
		icon = "Data\UI\Professions\cooking.paa";
		effectDescription = "减少烹饪所需时间 %1%2";
		effectCalculation = "5 * (_this select 0)";
	};

	class Smelting : Repairing {
		displayName = "冶炼";
		icon = "Data\UI\Professions\smelting.paa";
		effectDescription = "减少冶炼所需时间 %1%2";
		effectCalculation = "5 * (_this select 0)";
	};

	class Archeology : Repairing {
		displayName = "考古";
		icon = "Data\UI\Professions\archeology.paa";
		effectDescription = "减少勘探和挖掘所需时间 %1%2";
	};

	class Crafting : Repairing {
		displayName = "制作";
		icon = "Data\UI\Professions\crafting.paa";
		effectDescription = "减少制作所需时间 %1%2";
	};

	class Reviving : Repairing {
		displayName = "救治";
		icon = "Data\UI\Professions\reviving.paa";
		effectDescription = "减少复苏所需时间 %1%2";
	};
};
