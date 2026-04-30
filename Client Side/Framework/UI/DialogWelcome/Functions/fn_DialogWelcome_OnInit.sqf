/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_DialogWelcome_OnInit";
disableSerialization;

_this params [ "_display", "_params" ];

if (isNull _display) exitWith {};

_display displaySetEventHandler ["keyDown","_this call ULP_UI_fnc_blockEsc"];

private _info = _display displayCtrl 6001;
private _continueButton = _display displayCtrl 6002;
private _tutorialButton = _display displayCtrl 6003;

_info ctrlSetStructuredText parsetext format [
	"<br /><img image = 'Data\Tags\logo.paa' shadow='0' align='center' size='4.5' /><br /><br />
	欢迎来到 Mantle 的 Altis Life。<br /><br />
	我们的服务器于 2025 年 1 月上线，基于完全自研框架打造，力求带来更有新鲜感的 Altis Life 体验。这里是一个角色扮演服务器，如果你是新玩家，建议先阅读服务器规则；违反规则可能会导致你被移出服务器。<br /><br />
	前往官网注册并绑定 Steam 账号后，你可以领取一笔 <t color='#B92DE0'>£500,000</t> 的新手奖励。<br /><br />
	• <a href='https://mantlenetwork.co.uk/' color='#D96600'>官网</a><br />
	• <a href='https://mantlenetwork.co.uk/discord' color='#D96600'>Discord</a>"
];

[_info] call ULP_UI_fnc_setToTextHeight;

if ([] call ULP_fnc_isHobo && { [player, ["Civilian"]] call ULP_fnc_isFaction } && { !ULP_Imprisioned }) exitWith {
	_continueButton ctrlEnable false;

	[[_continueButton, time + 10], {
		_this params ["_continueButton", "_delay"];
		
		if (isNull _continueButton) exitWith { [_thisEventHandler] call ULP_fnc_removeEachFrame; };

		if (time < _delay) then {
			_continueButton ctrlSetStructuredText parseText format["<t align = 'center'>继续（%1）</t>", [_delay - time, "SS.MS"] call BIS_fnc_secondsToString];
		} else {
			_continueButton ctrlSetStructuredText parseText "<t align = 'center'>继续</t>";
			_continueButton ctrlEnable true;
			[_thisEventHandler] call ULP_fnc_removeEachFrame;
		};
	}] call ULP_fnc_addEachFrame;
};

_tutorialButton ctrlShow false;
