/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_finishTutorial";

if !([] call ULP_fnc_isOnTutorial) exitWith { false };

player setVariable ["isOnTutorial", nil, true];

[
	"<t color='#008000' size='1.5px'>教程<br/></t><t color='#ffffff' size='1px'>恭喜，你已经完成了基础入门教程。现在你应该已经掌握了在岛上继续发展的基本方法。不如试着前往 Schnapps Processing 加工你采集到的苹果吧？"
] call ULP_fnc_hint;

["CompletedTutorial"] call ULP_fnc_achieve;

true
