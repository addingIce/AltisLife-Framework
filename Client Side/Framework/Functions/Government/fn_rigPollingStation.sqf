/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#define RIG_CFG missionConfigFile >> "CfgGovernment" >> "Rigging" 
#include "..\..\script_macros.hpp"
scopeName "fn_rigPollingStation";

_this params [
	["_pollingStation", objNull, [objNull]]
];

if (isNull _pollingStation || { !(isNil { player getVariable "rigging" }) }) exitWith {};

private _group = group player;
private _groupId = [_group] call ULP_fnc_groupId;

if (_groupId isEqualTo -1 || { !(["PollRigging", _group] call ULP_fnc_hasGroupPerk) }) exitWith {
	["你必须加入具备操纵投票站能力的队伍。"] call ULP_fnc_hint;
};

private _riggedGroup = _pollingStation getVariable ["rigged_group", grpNull];
private _riggedGroupId = [_riggedGroup] call ULP_fnc_groupId;

private _isRigged = !(isNull _riggedGroup && { _riggedGroupId isEqualTo -1 });

if (_isRigged && { _riggedGroupId isEqualTo _groupId }) exitWith {
	["这个投票站已经被你的队伍操纵过了。"] call ULP_fnc_hint;
};

player setVariable ["rigging", true];

private _time = getNumber (RIG_CFG >> "timeToRig");

if (_isRigged) then {
	_time = _time * getNumber (RIG_CFG >> "alreadyRiggedMultiplier");
};

["正在操纵投票站", _time, [_pollingStation, _group, _groupId],
	{ !(((_this select 0) getVariable ["rigged_group", grpNull]) isEqualTo (_this select 1)) && { (player distance (_this select 0)) <= 5 } }, 
	{
		_this params [ "_pollingStation", "_group", "_groupId" ];

		["PollingStationRigged", {
			_this params [
				["_message", "投票站已成功操纵", [""]]
			];

			player setVariable ["rigging", nil];

			[_message] call ULP_fnc_hint;
		}, true] call ULP_fnc_addEventHandler;

		[_pollingStation, player] remoteExecCall ["ULP_SRV_fnc_rigPollingStation", RSERV];
		[player, missionConfigFile >> "CfgReputation" >> "Types" >> "Rig"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];
	}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
