/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_renameHouse";

if (canSuspend) exitWith {
    [ULP_fnc_renameHouse, _this] call ULP_fnc_directCall;
};

_this params [
	["_house", objNull, [objNull]],
	["_onRename", {}, [{}]],
	["_params", [], [[]]]
];

if (isNull _house) exitWith { false };

if !([_house, player, false] call ULP_fnc_isHouseOwner) exitWith {
	["只有房主才能修改房屋名称！"] call ULP_fnc_hint;
	false
};

// Stop spam...
if (time < (_house getVariable ["building_last_renamed", 0])) exitWith {
	["你刚刚修改过这栋房屋的名称，请稍后再试。"] call ULP_fnc_hint;
	false
};
_house setVariable ["building_last_renamed", time + 5];

if (_house getVariable ["selling", false]) exitWith {
	["这栋房屋正在出售中..."] call ULP_fnc_hint;
	false
};

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "输入房屋名称", ["确认", "取消"],
	"在这里输入房屋名称...", [_house, [_params, _onRename]],
	{	
		_this params [
			["_house", objNull, [objNull]],
			["_fnc", [[], {}], [[]]],
			["_name", "", [""]]
		];
		
		_name = [_name] call ULP_fnc_stripString;

		if (isNull _house) exitWith {};

		if (_house getVariable ["selling", false]) exitWith {
			["这栋房屋已经在出售中了！"] call ULP_fnc_hint;
		};

		if ((count _name) > getNumber (missionConfigFile >> "CfgHousing" >> "nameLength")) exitWith {
			["这个名称太长了！"] call ULP_fnc_hint;
		};

		if ((_house getVariable ["building_name", ""]) isEqualTo _name) exitWith {
			["新的房屋名称不能和当前名称相同！"] call ULP_fnc_hint;
		};

		_house setVariable ["building_name", ([_name, nil] select (_name isEqualTo "")), true];

		["HouseRenamed", [_house]] call ULP_fnc_invokeEvent;

		if ([_house] call ULP_fnc_isHouseShared) then {
			{
				["HouseRenamed", [_house]] remoteExecCall ["ULP_fnc_invokeEvent", _x];
			} forEach ((units (group player)) select {
				!(_x isEqualTo player)
			});
		};

		[_house getVariable ["building_id", -1], _name] remoteExecCall ["ULP_SRV_fnc_setHouseName", RSERV];
		[format ["你已将这栋房屋重命名为 <t color='#B92DE0'>%1</t>。", _name]] call ULP_fnc_hint;

		(_fnc select 0) call (_fnc select 1);
	}, false
] call ULP_fnc_enterString;
true
