/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\script_macros.hpp"
scopeName "fn_sendMoney";

if (canSuspend) exitWith {
    [ULP_fnc_sendMoney, _this] call ULP_fnc_directCall;
};

_this params [
	["_unit", objNull, [objNull]],
	["_amount", 0, [0]],
	["_bank", false, [true]]
];

if (isNull _unit || { _unit isEqualTo player } || { [] call ULP_fnc_isRestrained } || { [] call ULP_fnc_isSurrendered } || { isDowned(player) } || { isDowned(_unit) } || { !_bank && ((player distance _unit) > 3) }) exitWith {
	["发放现金时，你必须靠近对方，且自己未被束缚、未投降..."] call ULP_fnc_hint;
};

if (_bank && { [] call ULP_fnc_isHobo }) exitWith {
	["你目前不满足银行转账条件。"] call ULP_fnc_hint;
};

if (_amount < 1) exitWith {
	["你现在没有可转出的资金..."] call ULP_fnc_hint;
};

if !([_amount, _bank, format ["%1 %2", ["Given to", "Transferred to"] select (_bank), name _unit]] call ULP_fnc_removeMoney) exitWith {
	[format ["你没有足够的 <t color='#B92DE0'>%1%2</t> 可用于%3...", "£", [_amount] call ULP_fnc_numberText, ["交给对方", "转账"] select (_bank)]] call ULP_fnc_hint;
};

[player, _amount, _bank] remoteExecCall ["ULP_fnc_recieveMoney", _unit];
[format ["你已向 %4%1 <t color='#B92DE0'>%2%3</t>", ["交付了", "转账了"] select (_bank), "£", [_amount] call ULP_fnc_numberText, name _unit]] call ULP_fnc_hint;

if (_amount >= 5000000) then {
	["Tropical"] call ULP_fnc_achieve; // Charity Worker
};
