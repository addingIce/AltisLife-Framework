/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_replyMessage";

_this params [
	"_ctrl"
];

private _display = ctrlParent _ctrl;
if (isNull _display) exitWith {};

private _inbox = _display displayCtrl 23048;
private _row = lnbCurSelRow _inbox;

private _forIndex = _inbox lnbValue [_row, 0];
private _messages = + (missionProfileNamespace getVariable ["ULP_Messages", []]);
private _message = _messages param [_forIndex, []];

if (_message isEqualTo []) exitWith {
	["你需要先选择一条要回复的消息！"] call ULP_fnc_hint;
};

_message params [
	"_type", "_sender"
];

private _cfg = missionConfigFile >> "CfgMessages" >> _type;
if !(isClass _cfg) exitWith {};

if !([getNumber (_cfg >> "canReply")] call ULP_fnc_bool) exitWith {
	["这条消息无法回复！"] call ULP_fnc_hint;
};

_sender params [ "_name", "_steamid" ];

private _unit = [_steamid] call ULP_fnc_playerByUID;
if (isNull _unit) exitWith {
	["发送者已经不在线了，无法回复这条消息！"] call ULP_fnc_hint;
};

private _msgCtrl = _display displayCtrl 23041;
private _message = [ctrlText _msgCtrl] call ULP_fnc_stripString;

if (_message isEqualTo "" || { (count _message) > getNumber (missionConfigFile >> "CfgMessages" >> "length") }) exitWith {
	["请输入你要发送的消息内容！"] call ULP_fnc_hint;
};

[missionConfigFile >> "CfgMessages" >> "Reply", _message, _unit] call ULP_fnc_sendMessage;
_msgCtrl ctrlSetText "";
