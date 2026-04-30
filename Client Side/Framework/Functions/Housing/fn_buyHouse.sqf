/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_buyHouse";

if (canSuspend) exitWith {
    [ULP_fnc_buyHouse, _this] call ULP_fnc_directCall;
};

_this params [
	["_house", objNull, [objNull]]
];

if ([player] call ULP_fnc_onDuty) exitWith {
	["执勤期间不能购买房屋。"] call ULP_fnc_hint;
};

private _objectCfg = [typeOf _house] call ULP_fnc_vehicleCfg;

if !([_house] call ULP_fnc_isHouse || 
	{ isClass (missionConfigFile >> "CfgFactions" >> [player] call ULP_fnc_getFaction >> "Housing") } || 
	{ !([_house] call ULP_fnc_isHouseOwned) } ||
	{ (count _objectCfg) > 0 }
) exitWith {
	["这栋房屋无法购买！"] call ULP_fnc_hint;
};

if !(["Home"] call ULP_fnc_hasLicense) exitWith {
	["你需要拥有房主许可证才能购买房屋。"] call ULP_fnc_hint;
};

if (_house getVariable ["blacklisted", false] || { ["redzone_", [_house]] call ULP_fnc_isUnitsInZone }) exitWith {
	["这栋房屋已被<t color='#B92DE0'>列入黑名单</t>。"] call ULP_fnc_hint;
};

if !(call compile getText (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _house) >> "condition")) exitWith {
	["你当前无法购买这栋房屋。"] call ULP_fnc_hint;
};

private _limit = (getNumber (missionConfigFile >> "CfgHousing" >> "houseLimit")) + ULP_Prestige;
if (["LandLord"] call ULP_fnc_hasPerk) then { _limit = _limit + 1 };
if ((count ([_house] call ULP_fnc_ownedHouses)) >= _limit) exitWith {
	[format ["你已达到可拥有房产数量上限：<t color='#B92DE0'>%1</t>。", _limit]] call ULP_fnc_hint;
};

private _money = getNumber (missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _house) >> "price");
if (["TaxFreeHousing"] call ULP_fnc_hasGroupPerk) then { _money = _money + 0.8 };

_objectCfg params [ "", "", "", "_name" ];

[
	(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "确认", ["是", "否"],
	format ["你确定要花费 <t color='#B92DE0'>%1%2</t> 购买 <t color='#B92DE0'>%3</t> 吗？", "£", [_money] call ULP_fnc_numberText, _name], [_house, _money],
	{	
		_this params [
			["_house", objNull, [objNull]],
			["_money", 0, [0]]
		];

		if (isNull _house) exitWith {};

		if (_house getVariable ["buying", false]) exitWith {
			["这栋房屋已有人正在购买！"] call ULP_fnc_hint;
		};

		_house setVariable ["buying", true];
		closeDialog 0;

		["HouseBought", {
			_this params [
				["_house", objNull, [objNull]],
				["_success", false, [true]],
				["_message", "", [""]],
				["_money", 0, [0]]
			];

			if (_success) then {
				[[_house]] call ULP_fnc_setupHouses;
				["BuyHouse"] call ULP_fnc_achieve;
				
				private _cfg = missionConfigFile >> "CfgHousing" >> "Houses" >> (typeOf _house);
				if (isText (_cfg >> "onBought")) then {
					call compile getText (_cfg >> "onBought");
				};
			} else {
				[_money, true, "房屋购买失败"] call ULP_fnc_addMoney;
			};

			[_message] call ULP_fnc_hint;

			_house setVariable ["buying", nil];
		}, true] call ULP_fnc_addEventHandler;

		if ([_money, true, "购买房屋"] call ULP_fnc_removeMoney) then {
			["正在购买房屋..."] call ULP_fnc_hint;
			[player, _house, _money] remoteExecCall ["ULP_SRV_fnc_buyHouse", RSERV];
		} else {
			[format ["你的资金不足，无法支付 <t color='#B92DE0'>%1%2</t> 购买这处房产！", "£", [_money] call ULP_fnc_numberText]] call ULP_fnc_hint;
			_house setVariable ["buying", nil];
		};
	}, {}, false
] call ULP_fnc_confirm;
