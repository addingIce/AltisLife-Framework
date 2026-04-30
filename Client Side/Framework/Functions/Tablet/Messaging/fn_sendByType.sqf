/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_sendByType";

_this params [
	["_button", controlNull, [controlNull]]
];

private _display = ctrlParent _button;
if (isNull _display) exitWith { false };

private _msgCtrl = _display displayCtrl 23037;
private _list = _display displayCtrl 23038;

private _type = missionConfigFile >> "CfgMessages" >> (_list lbData (lbCurSel _list));
if !(isClass _type) exitWith { ["你必须先选择一种消息类型！"] call ULP_fnc_hint; false };

if (!([getNumber (_type >> "ignoreComms")] call ULP_fnc_bool) && { !([] call ULP_fnc_hasComms) }) exitWith {
	["发送这条消息前，你必须先配备通讯设备..."] call ULP_fnc_hint;
};

private _targets = getText (_type >> "targets");
private _message = [ctrlText _msgCtrl] call ULP_fnc_stripString;

if (_message isEqualTo "" || { (count _message) > getNumber (missionConfigFile >> "CfgMessages" >> "length") }) exitWith {
	["请输入你要发送的消息内容！"] call ULP_fnc_hint;
};

if (_targets isEqualTo "") then {
	[(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), getArray (_type >> "sendTo"), [_type, _message], {
		_this params [
			"_type", "_message",
			["_selectDisplay", displayNull, [displayNull]]
		];

		if (isNull _selectDisplay || { isNull _display }) exitWith {};

		private _list = _selectDisplay displayCtrl 3809;

		private _player = (_list tvData (tvCurSel _list)) call BIS_fnc_objectFromNetId;
		if (isNull _player) exitWith {
			["你还没有选择接收对象！"] call ULP_fnc_hint;
		};

		[_type, _message, _player] call ULP_fnc_sendMessage;
	}, true, false] call ULP_fnc_selectPlayer;
} else {
	[_type, _message, _targets] call ULP_fnc_sendMessage;
};

_msgCtrl ctrlSetText "";

true
