/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_vote";

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

private _pollingStation = _display getVariable ["pollingStation", objNull];
if (isNull _pollingStation) exitWith {};

private _list = _display displayCtrl 5202;

private _candidate = (_list lbData (lbCurSel _list));
if (_candidate isEqualTo "") exitWith {
	["你必须先选择一位要投票的候选人。"] call ULP_fnc_hint;
};

closeDialog 0;

if !(missionNamespace getVariable ["ULP_SRV_Setting_Election", false]) exitWith {
	["当前没有正在进行的选举。"] call ULP_fnc_hint;
};

// Easy way to avoid spam, they'd have to relog to get past and server side would block multiple votes
if (player getVariable ["voted", false]) exitWith {
	["你已经在本次选举中投过票了！"] call ULP_fnc_hint;
};

if (player getVariable ["voting", false]) exitWith {
	["你的投票请求正在处理中！"] call ULP_fnc_hint;
};

player setVariable ["voting", true];

["ElectionVoteSubmitted", {
	private _message = _this param [0, "你已成功完成投票。"];
	[_message] call ULP_fnc_hint;

	player setVariable ["voting", nil];

	if (_message isEqualTo "你已成功完成投票。") then {
		player setVariable ["voted", true];

		[player, missionConfigFile >> "CfgReputation" >> "Types" >> "Vote"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];

		["Voter"] call ULP_fnc_achieve;
	};
}, true] call ULP_fnc_addEventHandler;

["正在提交投票..."] call ULP_fnc_hint;
[_pollingStation, player, _candidate] remoteExecCall ["ULP_SRV_fnc_submitVote", RSERV];
