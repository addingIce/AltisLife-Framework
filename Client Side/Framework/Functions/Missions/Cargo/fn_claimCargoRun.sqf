/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_claimCargoRun";

if (canSuspend) exitWith {
    [ULP_fnc_claimCargoRun, _this] call ULP_fnc_directCall;
};

_this params [
	["_trader", objNull, [objNull]],
	["_missionType", "CorporateFreight", [""]],
	["_mission", "Kavala_Freight", [""]]
];

private _missionCfg = missionConfigFile >> "CfgMissions" >> _missionType;
if (isNull _trader || { !isClass _missionCfg }) exitWith {};

if !(call compile getText (_missionCfg >> "condition")) exitWith {
	["你目前不满足接取这趟货运的条件。"] call ULP_fnc_hint;
};

(getArray (_missionCfg >> "vehicleRequirement")) params [ "_vehicles", "_distance" ];

private _near = ((_trader nearEntities [_vehicles, _distance]) select {
	[player, _x] call ULP_fnc_isVehicleOwner
});

if (_near isEqualTo []) exitWith {
	["附近没有你拥有的载具。"] call ULP_fnc_hint;
};

if (_missionType in ULP_Missions) exitWith {
	["这类任务一次只能同时持有一个。"] call ULP_fnc_hint;
};

[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), (_near apply { 
	([typeOf _x] call ULP_fnc_vehicleCfg) params [  "", "", "_picture", "_name" ]; 
	[_picture, _name, _x call BIS_fnc_netId, 0];
}), ["装货", "取消"], [_trader, _missionCfg, _mission, _distance], {
	_this params [
		["_trader", objNull, [objNull]],
		["_missionCfg", configNull, [configNull]],
		["_mission", "Kavala_Freight", [""]],
		["_distance", 10, [0]],
		["_display", displayNull, [displayNull]]
	];

	if ((player distance _trader) > 5) exitWith {
		["你离得太远了。"] call ULP_fnc_hint;
	};

	if (isNull _display) exitWith {};
	private _list = _display displayCtrl 4509;

	private _vehicle = (_list lbData (lbCurSel _list)) call BIS_fnc_objectFromNetId;
	if (isNull _vehicle) exitWith { ["你还没有选择要装货的载具！"] call ULP_fnc_hint; };

	if !([_vehicle, getPos _trader, _distance] call ULP_fnc_isVehicleStationary) exitWith { ["载具必须熄火，并停在标志牌附近！"] call ULP_fnc_hint; };

	private _currentVehicleLoad = [_vehicle] call ULP_fnc_currentLoad;
	private _maxVehicleLoad = [_vehicle] call ULP_fnc_maxLoad;

	private _item = getText (_missionCfg >> "cargoItem");
	if !(isClass (missionConfigFile >> "CfgVirtualItems" >> _item)) exitWith {};

	private _itemWeight = getNumber (missionConfigFile >> "CfgVirtualItems" >> _item >> "weight");

	private _maxQuantity = ( floor ((_maxVehicleLoad - _currentVehicleLoad) / _itemWeight) max 0 );

	if (_maxQuantity <= 0) exitWith { ["这辆载具已经没有空间了，连一件货物都装不下！"] call ULP_fnc_hint; };

	private _time = (_itemWeight * _maxQuantity) / getNumber (_missionCfg >> "timeDivisionAmount");

	private _vehicleCfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;

	if (_item in getArray ((_vehicleCfg select 1) >> "blacklistedItems") && !(_item in getArray ((_vehicleCfg select 1) >> "whitelistedItems"))) exitWith {
		["这辆载具不能用于这项任务。"] call ULP_fnc_hint;
	};

	[format["正在为 %1 装载货物", _vehicleCfg param [3, "载具"]], _time, [_trader, _vehicle, _distance, _maxQuantity, _item, _missionCfg, _mission],
		{ (player distance (_this select 0)) <= 5 && { [(_this select 1), getPos (_this select 0), (_this select 2)] call ULP_fnc_isVehicleStationary } }, 
		{
			_this params [ "_trader", "_vehicle", "", "_maxQuantity", "_item", "_missionCfg", "_mission" ];
			if (isNull _vehicle) exitWith {};

			private _missionType = configName _missionCfg;

			if (_missionType in ULP_Missions) exitWith {
				[getText (_missionCfg >> "Messages" >> "onAlreadyHas")] call ULP_fnc_hint;
			};

			private _cargoParams = [_vehicle, _item, _maxQuantity];

			if !(_cargoParams call ULP_fnc_addToCargo) exitWith {
				["这辆载具无法装下预期数量的货物，请确保装货过程中没有其他人往里塞东西！"] call ULP_fnc_hint;
			};

			if !([_missionType, _mission] call ULP_fnc_claimMission) exitWith {
				_cargoParams call ULP_fnc_removeFromCargo;
			};

			// Save vehicle information
			private _missionInfo = ULP_Missions get _missionType;
			_missionInfo pushBack [_vehicle, _missionType, _maxQuantity];

			ULP_Missions set [_missionType, _missionInfo];

		}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
	}, false] call ULP_fnc_selectObject;
