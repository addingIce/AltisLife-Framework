/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_sellHouse";

_this params [
	["_building", objNull, [objNull]]
];

if ([player] call ULP_fnc_onDuty) exitWith {
	["执勤期间不能出售房屋。"] call ULP_fnc_hint;
};

private _cfg = [typeOf _building] call ULP_fnc_vehicleCfg;

if !(_cfg isEqualTo []) then {
	_cfg params [ "", "", "", "_name" ];

	[
		(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "确认", ["是", "否"],
		format ["你确定要出售 <t color='#B92DE0'>%1</t> 吗？所有已存放的物品都会丢失。", _name], [_building],
		{	
			private _house = _this param [0, objNull];
			if (isNull _house) exitWith {};

			if (_house getVariable ["selling", false]) exitWith {
				["这栋房屋已经在出售中了！"] call ULP_fnc_hint;
			};

			_house setVariable ["selling", true];
			closeDialog 0;

			["HouseSold", {
				_this params [
					["_house", objNull, [objNull]],
					["_success", false, [true]],
					["_message", "", [""]],
					["_money", 0, [0]]
				];

				if (_success) then { [_money, true, "出售房屋"] call ULP_fnc_addMoney; };
				[_message] call ULP_fnc_hint;

				_house setVariable ["selling", nil];
			}, true] call ULP_fnc_addEventHandler;

			["正在出售房屋..."] call ULP_fnc_hint;
			[getPlayerUID player, _house] remoteExecCall ["ULP_SRV_fnc_sellHouse", RSERV];
		}, {}, false
	] call ULP_fnc_confirm;
};
