/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_startTutorial";

if !([] call ULP_fnc_isHobo) exitWith {
	["你目前不满足开始教程的条件。"] call ULP_fnc_hint;
	false
};

if ([] call ULP_fnc_isOnTutorial) exitWith {
	["你已经在进行教程了，不能重复开始。"] call ULP_fnc_hint;
	false
};

private _firstStage = (configProperties [missionConfigFile >> "CfgTutorial" >> "Stages", "isClass _x && { !(call compile getText (_x >> ""condition"")) }", true]) param [0, configNull];

if (isNull _firstStage) exitWith {
	["教程所需的全部条件你都已经满足，无需再次进行。"] call ULP_fnc_hint;
	false
};

player setVariable ["isOnTutorial", true, true];

[_firstStage] call ULP_fnc_triggerTutorialStage;
