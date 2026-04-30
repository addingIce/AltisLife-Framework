/*
** Author: Jack "Scarso" Farhall
** Description: Allows the removal of a clamp from a vehicle if the player is Police or HATO
*/
#include "..\..\script_macros.hpp"
scopeName "fn_removeVehicleClamp";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

private _clamp = _vehicle getVariable ["clamp_fine", []];

if (_clamp isEqualTo []) exitWith {
	["这辆载具没有被夹轮..."] call ULP_fnc_hint;
	false
};

if !([player, ["Police", "Hato"]] call ULP_fnc_isFaction) exitWith {
	["只有 Police 或 HATO 可以拆除夹轮..."] call ULP_fnc_hint;
	false
};

private _profileName = _clamp param [0, "Unknown"];

closeDialog 0;

[format["正在拆除 %1 的 %2 夹轮", _profileName, (_cfg param [3, "载具"])], 30, [_vehicle, _cfg], { (player distance (_this select 0)) <= 5 }, {
	_this params [
		["_vehicle", objNull, [objNull]],
		["_cfg", configNull, [configNull]]
	];
	
	if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
		["这辆载具已经损毁得太严重了..."] call ULP_fnc_hint;
	};

	_vehicle setVariable ["clamp_fine", nil, true];
	[format ["你已拆除 <t color='#B92DE0'>%1</t> 上的夹轮...", _cfg param [5, "载具"]]] call ULP_fnc_hint;
}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;

true
