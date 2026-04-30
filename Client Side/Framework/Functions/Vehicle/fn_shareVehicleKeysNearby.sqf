/*
** Author: Jack "Scarso" Farhall
** Description:
*/
#include "..\..\script_macros.hpp"
scopeName "fn_shareVehicleKeysNearby";

_this params [
	["_vehicle", objNull, [objNull]]
];

if (isNull _vehicle || { !(_vehicle in ULP_Keys) }) exitWith { false };

private _groupMembersNearby = (units (group player)) select {
	(player distance _x) <= 100 && { !(_x isEqualTo player) }
};

if (_groupMembersNearby isEqualTo []) exitWith {};

["KeysGiven", [_vehicle, player]] remoteExecCall ["ULP_fnc_invokeEvent", _groupMembersNearby];
["你已把这辆载具的钥匙分享给 100 米内的所有队伍成员。"] call ULP_fnc_hint;
