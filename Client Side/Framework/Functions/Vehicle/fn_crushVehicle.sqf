/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_crushVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

_cfg params [
	"", "_missionCfg", "_picture", "_name", "_topSpeed", "_armor", "_seats", "_power", "_fuel"
];

if !(isClass _missionCfg) exitWith {};
if !([player, ["Police"]] call ULP_fnc_isFaction) exitWith {
	["只有 Police 可以销毁载具！"] call ULP_fnc_hint;
};

if !((crew _vehicle) isEqualTo []) exitWith {
	["销毁载具时，车内不能有人！"] call ULP_fnc_hint;
};

if ((_vehicle getVariable ["vehicle_id", -1]) < 0) exitWith {
	["租赁载具不能被销毁！"] call ULP_fnc_hint;
};

private _time = ["StreetCleaner", getNumber (missionConfigFile >> "CfgSettings" >> "Police" >> "crushTime")] call ULP_fnc_activatePerk;
if (isNumber (_missionCfg >> "crushTime")) then {
	_time = _time + getNumber (_missionCfg >> "crushTime");
};
if ([] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty }) then { _time = 5; };

if !([format["正在销毁 %1", _name], _time, [_vehicle, _name, _fee], {
	!(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 5 }
}, {
	_this params [ "_vehicle", "_name", "_fee" ];

	if (isNull _vehicle || { !((crew _vehicle) isEqualTo []) }) exitWith {
		["销毁失败，可能是车里有人，或载具已经被移走了！"] call ULP_fnc_hint;
	};

	private _id = _vehicle getVariable ["vehicle_id", -1];
	if (_id >= 0) then {
		[_id] remoteExecCall ["ULP_SRV_fnc_destroyVehicle", RSERV];
	};

	private _owner = (_vehicle getVariable ["vehicle_owners", createHashMap]) getOrDefault [[_vehicle] call ULP_fnc_getVehicleOwner, []];

	deleteVehicle _vehicle;

	[player, "CrushVehicle"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];

	["FirstCrush"] call ULP_fnc_achieve;

	["载具已被销毁！"] call ULP_fnc_hint;
	["Crushed", [_owner param [0, "某人"], _name, [player, false, true] call ULP_fnc_getName]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];

	private _crushValue = getNumber (_cfg >> "buyPrice") * ([
		getNumber (missionConfigFile >> "CfgVehicles" >> "crushPerc"),
		getNumber (_cfg >> "crushPerc")
	] select (isNumber (_cfg >> "crushPerc")));

	[round _crushValue, true, format ["%1's Crush Value", _owner]] call ULP_fnc_addMoney;
}, {}] call ULP_UI_fnc_startProgress) exitWith {
	["执行其他动作时，无法销毁载具！"] call ULP_fnc_hint;
};

closeDialog 0;
