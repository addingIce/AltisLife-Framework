/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_enlist";

if (missionNamespace getVariable ["ULP_SRV_Setting_Election", false]) exitWith {
	["选举进行期间不能报名参选。"] call ULP_fnc_hint;
};

if (!([player, ["Civilian"]] call ULP_fnc_isFaction) || { [] call ULP_fnc_isUndercover }) exitWith {
	["只有 Civilian 阵营玩家才能报名参加下一届选举。"] call ULP_fnc_hint;
};

if !([] call ULP_fnc_isGroup || { ["Governorship"] call ULP_fnc_hasGroupPerk }) exitWith {
	["你的队伍没有参选 Governor 总督的资格。"] call ULP_fnc_hint;
};

if ([] call ULP_fnc_isGovernor) exitWith {
	["你当前是 Governor 总督，无法参加下一届选举。"] call ULP_fnc_hint;
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "确认", ["确认", "取消"],
	format ["你确定要以 %1 的名义竞选 Governor 总督吗？", profileName], [],
	{	
		if (player getVariable ["enlisting", false]) exitWith {
			["你的报名请求正在处理中！"] call ULP_fnc_hint;
		};

		player setVariable ["enlisting", true];

		["Enlistment", {
			[_this param [0, "你已成功报名参加下一届选举。"]] call ULP_fnc_hint;
			player setVariable ["enlisting", nil];
		}, true] call ULP_fnc_addEventHandler;

		["正在提交报名请求..."] call ULP_fnc_hint;
		[player] remoteExecCall ["ULP_SRV_fnc_enlistCandidate", RSERV];
	}, {}, false
] call ULP_fnc_confirm;
