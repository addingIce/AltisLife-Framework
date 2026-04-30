/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_giveVehicleKeys";

_this params [
	["_unit", objNull, [objNull]]
];

if (isNull _unit || { !(isPlayer _unit) } || { (player distance _unit) > 5 }) exitWith {};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), (ULP_Keys apply { 
	([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "_missionCfg", "", "_name" ]; 
	[_picture, format ["%1 (%2m)", _name, (player distance _x)], _x call BIS_fnc_netId, 0];
}), ["Give", "Cancel"], [_unit], {
}), ["交出钥匙", "取消"], [_unit], {
	_this params [
		["_unit", objNull, [objNull]],
		["_display", displayNull, [displayNull]]
	];

	if ((player distance _unit) > 5) exitWith {
		["你离对方不够近，无法把钥匙交给他！"] call ULP_fnc_hint;
	};

	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _vehicle) exitWith { ["你还没有选择要交出钥匙的载具！"] call ULP_fnc_hint; };

	private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
	if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith {};

	_cfg params [
		"", "_missionCfg", "", "_name"
	];

	if !(isClass _missionCfg) exitWith {};

	["KeysGiven", [_vehicle, player]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
	[format ["你已把 <t color='#B92DE0'>%2</t> 的钥匙交给 <t color='#B92DE0'>%1</t>。", name _unit, _name]] call ULP_fnc_hint;
}, false] call ULP_fnc_selectObject;
