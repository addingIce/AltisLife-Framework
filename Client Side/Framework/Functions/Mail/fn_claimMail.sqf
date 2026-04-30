/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_claimMail";

_this params [
	"_button"
];

private _display = ctrlParent _button;
if (isNull _display) exitWith {};

if (player getVariable ["claiming_mail", false]) exitWith { closeDialog 0; };

private _list = _display displayCtrl 5303;

private _selected = _list lnbData [lnbCurSelRow _list, 0];
if (_selected isEqualTo "") exitWith {
	["你必须先从邮箱中选择一个要领取的物品。"] call ULP_fnc_hint;
};

_button ctrlEnable false;

player setVariable ["claiming_mail", true];

private _lbData = parseSimpleArray _selected;

_lbData params [
	"_id", 
	"_type", 
	"_className", 
	"_data"
];

private _claimedAmount = 0;
private _totalAmount = 0;

if (_data isEqualType 0) then {
	_totalAmount = _data;
};

switch (_type) do {
	case "Vehicle";
	case "Texture": {
		_totalAmount = _data param [0, 0];
		private _texture = _data param [1, ""];

		if (_totalAmount isEqualTo 0 && { [_className, _texture] call ULP_fnc_isTextureUnlocked }) exitWith {
			["这款涂装你已经解锁过了。"] call ULP_fnc_hint;
			player setVariable ["claiming_mail", nil];
			_button ctrlEnable true;
			breakOut "fn_claimMail";
		};

		[_className, _texture] call ULP_fnc_unlockTexture;

		// It's more than a texture unlock
		if (_totalAmount > 0) then {
			private _faction = [player] call ULP_fnc_getFaction;

			[
				0, 
				getPlayerUID player, 
				profileName, 
				_faction, 
				_className, 
				_texture
			] remoteExecCall ["ULP_SRV_fnc_createVehicle", RSERV];
		};

		// These ensure we tell the user they've claimed all and update database
		_claimedAmount = 1;
		_totalAmount = 1;
	};
	case "VirtualItem": {
		private _itemCfg = missionConfigFile >> "CfgVirtualItems" >> _className;

		if !(isClass _itemCfg) exitWith { ["领取物品时发生错误。"] call ULP_fnc_hint; };

		private _weight = getNumber (_itemCfg >> "weight");

		private _maxQuantity = _totalAmount;

		if (_weight > 0) then {
			_maxQuantity = [_weight] call ULP_fnc_getMaxQuantity;
		};

		_claimedAmount = _maxQuantity min _totalAmount;

		if (_claimedAmount <= 0 || { !([_className, _claimedAmount, false] call ULP_fnc_handleItem) } ) exitWith {
			["你的空间不足，无法领取这些物品。"] call ULP_fnc_hint;
			player setVariable ["claiming_mail", nil];
			_button ctrlEnable true;
			breakOut "fn_claimMail";
		};

		_data = (_totalAmount - _claimedAmount) max 0;
	};
	case "Money": {
		if ([_totalAmount, false, _className] call ULP_fnc_addMoney) then {
			_claimedAmount = _totalAmount;
		};
	};
	default {
		for "_i" from 1 to _totalAmount do {
			if ([_className, false] call ULP_fnc_handleGear) then {
				_claimedAmount = _claimedAmount + 1;
			};
		};

		_data = (_totalAmount - _claimedAmount) max 0;
	};
};

if (_claimedAmount <= 0) exitWith {
	["你的空间不足，无法领取这些物品。"] call ULP_fnc_hint;
	player setVariable ["claiming_mail", nil];
	_button ctrlEnable true;
};

[getPlayerUID player, "Mail", [_id, _type, _className, _data, _totalAmount, _claimedAmount]] remoteExecCall ["ULP_SRV_fnc_logPlayerEvent", RSERV];

[format ["你已领取%1", [
	format ["其中 %1 件已成功领取，但你没法一次带走全部物品", _claimedAmount],
	"全部物品"
] select (_claimedAmount isEqualTo _totalAmount)]] call ULP_fnc_hint;

_display setVariable ["mail_claimed", (["MailClaimed", {
		[getPlayerUID player] remoteExecCall ["ULP_SRV_fnc_getMail", RSERV];
		player setVariable ["claiming_mail", nil];
	}, true] call ULP_fnc_addEventHandler)];

[_id, _data, _totalAmount, _claimedAmount] remoteExecCall ["ULP_SRV_fnc_updateMail", RSERV];
