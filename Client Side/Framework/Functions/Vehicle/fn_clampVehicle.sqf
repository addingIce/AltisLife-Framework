/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_clampVehicle";

_this params [
	["_vehicle", objNull, [objNull]]
];

private _cfg = [typeOf _vehicle] call ULP_fnc_vehicleCfg;
if (isNull _vehicle || { _cfg isEqualTo [] } || { ((["VehicleClamp"] call ULP_fnc_hasItem) < 1) }) exitWith { if (dialog) then { closeDialog 0; }; };

private _clamp = _vehicle getVariable ["clamp_fine", []];

if !(_clamp isEqualTo []) exitWith {
	["这辆载具已经被夹轮了..."] call ULP_fnc_hint;
	false
};

if !([player, ["Police", "Hato"]] call ULP_fnc_isFaction) exitWith {
	["只有 HATO 才能使用夹轮器..."] call ULP_fnc_hint;
	false
};

if ([player, ["Police"]] call ULP_fnc_isFaction && { [["Hato"]] call ULP_fnc_onlineFaction > 0 }) exitWith {
	["当前有 HATO 在线，夹轮应由 HATO 负责处理..."] call ULP_fnc_hint;
	false
};

closeDialog 0;

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), getArray (missionConfigFile >> "CfgSettings" >> "Police" >> "clampFee"), [_vehicle, _cfg],
	{
		_this params [
			["_vehicle", objNull, [objNull]],
			["_cfg", configNull, [configNull]],
			["_display", displayNull, [displayNull]],
			["_fine", 1, [0]]
		];

		[format["正在对 %1 执行夹轮", (_cfg param [3, "载具"])], 30, [_vehicle, _cfg, _fine], { (player distance (_this select 0)) <= 5 }, {
			_this params [
				["_vehicle", objNull, [objNull]],
				["_cfg", configNull, [configNull]],
				["_fine", 1, [0]]
			];
			
			if (isNull _vehicle || { !(alive _vehicle) }) exitWith {
				["这辆载具损毁过于严重，无法执行夹轮..."] call ULP_fnc_hint;
			};

			if (["VehicleClamp", 1, true] call ULP_fnc_handleItem) then {
				_vehicle setVariable ["clamp_fine", [profileName, getPlayerUID player, _fine], true];
				[format ["你已对 <t color='#B92DE0'>%1</t> 执行夹轮，罚金为 <t color='#B92DE0'>%2%3</t>...", _cfg param [5, "载具"], "£", [_fine] call ULP_fnc_numberText]] call ULP_fnc_hint;

				[50, "Clamped Vehicle"] call ULP_fnc_addXP;
				[round (_fine * 0.75), true, format ["Clamping a %1", _vehicle]] call ULP_fnc_addMoney;
			
				["ClampVeh"] call ULP_fnc_achieve;
			} else {
				["你需要一个夹轮器才能执行夹轮..."] call ULP_fnc_hint;
			};
		}, {}, ["GRAB", "CROUCH"]] call ULP_UI_fnc_startProgress;
	}, false, "format [""%1%2"", ""£"", [_this select 1] call ULP_fnc_numberText]", false
] call ULP_fnc_selectNumber;

true
