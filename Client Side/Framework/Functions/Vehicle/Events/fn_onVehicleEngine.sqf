/*
** Author: Jack "Scarso" Farhall
** Description: 
*/
#include "..\..\..\script_macros.hpp"
scopeName "fn_onVehicleEngine";

_this params [
	["_vehicle", objNull, [objNull]],
	["_engineOn", false, [true]]
];

if !(local _vehicle) exitWith {};

if (_engineOn) then {
	if ([player] call ULP_fnc_isRestrained) exitWIth {
		_vehicle engineOn false;
	};

	private _clamp = _vehicle getVariable ["clamp_fine", []];

	if !(_clamp isEqualTo []) then {
		_vehicle engineOn false;

		_clamp params [ "_finer", "_steamid", "_fine" ];

		if (BANK < _fine) exitWith {
			if (time >= _vehicle getVariable ["clamp_notify", 0]) then {
				[format ["你的载具已被 <t color='#B92DE0'>%1</t> 夹轮，而且你付不起 <t color='#B92DE0'>%2%3</t> 的罚金...", _finer, "£", [_fine] call ULP_fnc_numberText]] call ULP_fnc_hint;
			};
			_vehicle setVariable ["clamp_notify", time + 3];
		};

		[
			(findDisplay getNumber(configFile >> "RscDisplayMission" >> "idd")), "车辆罚单", ["支付", "取消"],
			format ["%1 已对你的载具执行夹轮，并开出了 %2%3 的罚金。", _finer, "£", [_fine] call ULP_fnc_numberText], [_vehicle, _fine, _steamid],
			{	
				_this params [ "_vehicle", "_fine", "_steamid" ];

				if ([_fine, true, "Vehicle Fine"] call ULP_fnc_removeMoney) then {
					_vehicle engineOn true;
					_vehicle setVariable ["clamp_fine", nil, true];

					[format ["你已支付 <t color='#B92DE0'>%1%2</t> 的罚金，载具上的夹轮已被移除...", "£", [_fine] call ULP_fnc_numberText]] call ULP_fnc_hint;

					private _unit = [_steamid] call ULP_fnc_playerByUID;
					if (!(isNull _unit) && { [player, ["Police", "Hato"]] call ULP_fnc_isFaction }) then {
						["ClampFinePaid", [profileName, _vehicle, _fine]] remoteExecCall ["ULP_fnc_invokeEvent", _unit];
					};
				} else {
					["你身上的钱不够支付这笔罚金..."] call ULP_fnc_hint;
				};
			}, {}, false
		] call ULP_fnc_confirm;
	};

	if (isEngineOn _vehicle && { !(isNil { _vehicle getVariable "engineLastOffTime" }) }) then {
		_vehicle setVariable ["engineLastOffTime", nil, true];
	};
} else {
	private _engineLastOffTime = _vehicle getVariable ["engineLastOffTime", 0];

	if ((_engineLastOffTime + 60) <= serverTime) then {
		_vehicle setVariable ["engineLastOffTime", serverTime, true];
	};
};
