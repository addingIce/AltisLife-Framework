/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_impoundVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] }) exitWith { if (dialog) then { closeDialog 0; }; };

_cfg params [
	"", "_missionCfg", "_picture", "_name", "_topSpeed", "_armor", "_seats", "_power", "_fuel"
];

if !(isClass _missionCfg) exitWith {};
if !([player, ["Police", "Hato"]] call ULP_fnc_isFaction) exitWith {
	["只有 Police 和 HATO 可以扣押载具。"] call ULP_fnc_hint;
};

if !((crew _vehicle) isEqualTo []) exitWith {
	["扣押载具时，车内不能有人！"] call ULP_fnc_hint;
};

if ((_vehicle getVariable ["vehicle_id", -1]) < 0) exitWith {
	["租赁载具不能被扣押！"] call ULP_fnc_hint;
};

private _time = ["StreetCleaner", getNumber (missionConfigFile >> "CfgSettings" >> "Police" >> "impoundTime")] call ULP_fnc_activatePerk;
if (isNumber (_missionCfg >> "impoundTime")) then {
	_time = _time + getNumber (_missionCfg >> "impoundTime");
};
if ([] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty }) then { _time = 5; };

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), getArray (missionConfigFile >> "CfgSettings" >> "Police" >> "impoundFee"), [_vehicle, _name, _time],
	{
		_this params [ "_vehicle", "_name", "_time",
			["_display", displayNull, [displayNull]],
			["_fee", 1, [0]] 
		];

		if !([format["正在扣押 %1", _name], _time, [_vehicle, _name, _fee], {
			!(isNull (_this select 0)) && { alive (_this select 0) } && { (player distance (_this select 0)) <= 5 }
		}, {
			_this params [ "_vehicle", "_name", "_fee" ];

			if (isNull _vehicle || { !((crew _vehicle) isEqualTo []) }) exitWith {
				["扣押失败，可能是车里有人，或载具已经被移走了！"] call ULP_fnc_hint;
			};

			private _id = _vehicle getVariable ["vehicle_id", -1];

			if (_id < 0) exitWith {
				["租赁载具不能被扣押！"] call ULP_fnc_hint;
			};

			private _owner = (_vehicle getVariable ["vehicle_owners", createHashMap]) getOrDefault [[_vehicle] call ULP_fnc_getVehicleOwner, []];

			[player, "ImpoundVehicle"] remoteExecCall ["ULP_SRV_fnc_reputation", RSERV];
			
			[75, "Impounded Vehicle"] call ULP_fnc_addXP;

			["FirstImpound"] call ULP_fnc_achieve;

			[format["你已提交 <t color='#B92DE0'>%1</t> 的扣押请求，罚金为 <t color='#B92DE0'>%2%3</t>。", _name, "£", [_fee] call ULP_fnc_numberText]] call ULP_fnc_hint;
			["VehicleStored", { ["载具已被扣押。"] call ULP_fnc_hint; }, true] call ULP_fnc_addEventHandler;
			[_vehicle, _fee] remoteExecCall ["ULP_SRV_fnc_storeVehicle", RSERV];

			[round (_fee / 2), true, format ["%1's Impound Fee", _owner]] call ULP_fnc_addMoney;

			["Impounded", [_owner param [0, "某人"], _name, [player, false, true] call ULP_fnc_getName, format ["%1%2", "£", [_fee] call ULP_fnc_numberText]]] remoteExecCall ["ULP_fnc_chatMessage", RCLIENT];
		}, {}] call ULP_UI_fnc_startProgress) exitWith {
			["执行其他动作时，无法扣押载具！"] call ULP_fnc_hint;
		};

		closeDialog 0;
	}, false
] call ULP_fnc_selectNumber;
