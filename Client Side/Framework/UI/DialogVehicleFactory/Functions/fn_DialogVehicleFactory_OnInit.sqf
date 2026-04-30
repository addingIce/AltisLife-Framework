/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogVehicleFactory_OnInit";
disableSerialization;

_this params [ "_display", "_params" ];

if (isNull _display) exitWith {};

_params params [
	["_factory", objNull, [objNull]]
];

private _factoryCfg = missionConfigFile >> "CfgFactories" >> worldName >> (_factory getVariable ["factory", ""]);
if !(isClass _factoryCfg) exitWith { _display closeDisplay 2; };

private _requiredPower = getNumber (_factoryCfg >> "requiredPower");
private _factoryPower = _factory getVariable ["power", 0];

if (_factoryPower < _requiredPower) exitWith {
	[format ["这座工厂需要 <t color='#B92DE0'>%1 级</t>电力，目前只有 <t color='#B92DE0'>%2 级</t>。", _requiredPower, _factoryPower]] call ULP_fnc_hint;
	_display closeDisplay 2;
};

_display setVariable ["factory", _factory];

(_display displayCtrl 6201) ctrlSetText format ["%1 | 电力等级：%2", getText (_factoryCfg >> "displayName"), _factoryPower];

private _list = _display displayCtrl 6202;

{
	private _itemCfg = [configName _x] call ULP_fnc_vehicleCfg;

	if (_itemCfg isEqualTo []) exitWith {};

	_itemCfg params [ "", "", "_picture", "_name" ];

	private _index = _list lbAdd _name;
	_list lbSetPicture [_index, _picture];
	_list lbSetData [_index, configName _x];
} forEach ("isClass _x" configClasses (_factoryCfg >> "Products"));

_display setVariable ["eachFrameHandle", ([[_list], { _this call ULP_UI_fnc_DialogVehicleFactory_OnEachFrame }] call ULP_fnc_addEachFrame)];
