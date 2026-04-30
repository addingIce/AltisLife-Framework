class CfgGovernment {
	electionInternal = 14;

	class Rigging {
		timeToRig = 30;
		alreadyRiggedMultiplier = 1.5;
	};
	
	class Legislation {
		class Tax {
			displayName = "全岛税率";
			tooltip = "调整全岛部分价格所适用的税率。";
			type = "NUMBER";
			format = "format [""%2%1"", ""%"", [_this select 1] call ULP_fnc_numberText]";
			values[] = { { 1, 10 }, 5 };
		};
		class Paychecks {
			displayName = "工资补贴";
			tooltip = "调整发放给 Altis 公民工资中的额外补贴金额。";
			type = "NUMBER";
			format = "format [""%1%2"", ""£"", [_this select 1] call ULP_fnc_numberText]";
			values[] = { { 2500, 7500 }, 5000 };
		};
		class Mission {
			displayName = "工作报酬补助";
			tooltip = "调整政府对完成工作任务所提供的额外补助金额。";
			type = "NUMBER";
			format = "format [""%1%2"", ""£"", [_this select 1] call ULP_fnc_numberText]";
			values[] = { { 0, 5 }, 0 };
		};
		class Service {
			displayName = "航空服务定价";
			tooltip = "调整航空服务站每单位燃料的价格。";
			type = "NUMBER";
			format = "format [""%1%2"", ""£"", [_this select 1] call ULP_fnc_numberText]";
			values[] = { { 500, 1500 }, 1000 };
		};
		class Revival {
			displayName = "救治费用";
			tooltip = "调整医护人员执行救治时获得的报酬金额。";
			type = "NUMBER";
			format = "format [""%1%2"", ""£"", [_this select 1] call ULP_fnc_numberText]";
			values[] = { { 10000, 25000 }, 17500 };
		};
	};
};
