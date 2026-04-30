class CfgInteractions {
	class Placeable {
		class Remove {
			title = "移除可放置物";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "_this call ULP_fnc_removeObject; closeDialog 0;";
			condition = "isNull (_this getVariable [""unitDragging"", objNull]) && { [player, [""Police"", ""Medic"", ""Hato""]] call ULP_fnc_isFaction || { [] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""RemovePlaceable"", false] call ULP_fnc_checkPower } } }";
		};

		class Drag {
			title = "拖动可放置物";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "[_this select 0, ""Stretcher""] call ULP_fnc_dragPlaceable; closeDialog 0;";
			condition = "_this isKindOf ""Land_Stretcher_01_F"" && { isNull (_this getVariable [""unitDragging"", objNull]) } && { [player, [""Police"", ""Medic"", ""Hato""]] call ULP_fnc_isFaction || { [] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""RemovePlaceable"", false] call ULP_fnc_checkPower } } }";
		};
	};

	class Person {
		class GiveKeys {
			title = "交出钥匙";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "_this call ULP_fnc_giveVehicleKeys";
			condition = "!([player] call ULP_fnc_isRestrained)";
		};
		class GiveCash : GiveKeys {
			title = "给现金";
			onClick = "if ([_this select 0] call ULP_fnc_giveMoney) then { closeDialog 0; };";
		};
		class GiveItems : GiveKeys {
			title = "给予物品";
			onClick = "_this call ULP_fnc_giveVirtualItems";
		};
		class ShowLicenses : GiveKeys {
			title = "出示许可证";
			onClick = "private _unit = _this select 0; if (isNull _unit) exitWith {}; if (time < (_unit getVariable [""licenses_shown"", 0])) exitWith { [""你刚刚已经向此人出示过许可证了，请稍后再试...""] call ULP_fnc_hint; }; _unit setVariable [""licenses_shown"", time + 5]; [""LicensesShown"", [player, ULP_Licenses, true]] remoteExecCall [""ULP_fnc_invokeEvent"", _unit]; [format [""你已经向 %1 出示了你的许可证..."", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint;";
		};

		class RobCash {
			title = "抢现金";
			factions[] = { "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "closeDialog 0; [0, _this] call ULP_fnc_robMoney;";
			condition = "[_this] call ULP_fnc_isKnocked || { [_this] call ULP_fnc_isSurrendered } || { [_this] call ULP_fnc_isRestrained && (([_this getVariable [""restrained"", objNull]] call ULP_fnc_getFaction) isEqualTo player || [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup) }";
		};

		class Unrestrain : GiveKeys {
			title = "解除束缚";
			onClick = "[_this select 0, player, false] call ULP_fnc_restrain; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || { [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup } || { [player] call ULP_fnc_onDuty } }";
		};
		class Lockpick : Unrestrain {
			title = "撬锁";
			factions[] = { "Civilian", "Dunamis" };
			onClick = "_this call ULP_fnc_lockpick";
			condition = "[_this] call ULP_fnc_isRestrained && { [""Lockpick""] call ULP_fnc_hasItem > 0 }";
		};
		class Escort : Unrestrain {
			title = "押送";
			onClick = "[_this select 0, player, true] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || { [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup } || { [player] call ULP_fnc_onDuty } } && { !([_this] call ULP_fnc_isEscorted) }";
		};
		class StopEscort : Unrestrain {
			title = "停止押送";
			onClick = "[_this select 0, player, false] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || { [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup } || { [player] call ULP_fnc_onDuty } } && { [_this] call ULP_fnc_isEscorted }";
		};
		// class FeedHydrate : Unrestrain { // TODO
		// 	title = "Feed/Hydrate";
		// 	onClick = "hint ""Hello"";";
		// };
		class Blindfold : Unrestrain {
			title = "蒙眼";
			onClick = "_this call ULP_fnc_blindfold";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || { [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup } || { [player] call ULP_fnc_onDuty } } && { ([""Blindfold""] call ULP_fnc_hasItem) > 0 } && { !(_this getVariable [""blindfold"", false]) }";
		};
		class Unblindfold : Blindfold {
			title = "取下眼罩";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || { [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup } || { [player] call ULP_fnc_onDuty } } && { _this getVariable [""blindfold"", false] }";
		};
		class CountCash : Unrestrain {
			title = "清点现金";
			onClick = "[0, _this] call ULP_fnc_checkMoney;";
		};
		class SeizeCash : RobCash {
			title = "没收现金";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || { [player] call ULP_fnc_onDuty } }";
		};
		class InventoryCheck : Unrestrain {
			title = "检查背包";
			onClick = "player action [""Gear"", cursorObject]; closeDialog 0;";
		};
		class LicenseCheck : Unrestrain {
			title = "检查许可证";
			factions[] = { "Police" };
			onClick = "private _unit = _this select 0; if (isNull _unit) exitWith {}; if (_unit getVariable [""licenses_requested"", false]) exitWith { [""你已经向此人请求过许可证了...""] call ULP_fnc_hint; }; _unit setVariable [""licenses_requested"", true]; [""RequestLicenses"", [player]] remoteExecCall [""ULP_fnc_invokeEvent"", _unit]; if !([_unit] call ULP_fnc_isRestrained) then { [format [""你已向 %1 请求出示许可证..."", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint; };";
		};
		class LicenseRequest : LicenseCheck {
			title = "请求许可证";
			condition = "!([_this] call ULP_fnc_isRestrained)";
		};
		class SeizeCommunications : Unrestrain {
			title = "销毁通讯设备";
			onClick = "_this call ULP_fnc_seizeComms;";
			condition = "[_this] call ULP_fnc_hasComms && { [_this] call ULP_fnc_isRestrained } && { [player, [""Police""]] call ULP_fnc_isFaction || { [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup } || { [player] call ULP_fnc_onDuty } }";
		};
		class Ticket {
			title = "开具罚单";
			factions[] = { "Police" };
			onClick = "_this call ULP_fnc_issueTicket;";
			condition = "true";
		};
		class Imprision : Unrestrain {
			title = "送入监狱";
			onClick = "_this call ULP_fnc_setPrisonTime; closeDialog 0;";
			condition = "[player] call ULP_fnc_canImprison && { [_this] call ULP_fnc_canImprisoned }";
		};

		// Admin Commands...
		class AdminHeal {
			title = "管理员治疗";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "(_this select 0) setDamage 0; [format[""You've healed this player using admin powers...""]] call ULP_fnc_hint; [getPlayerUID player, ""Admin"", [""AdminHeal"", serverTime, [name (_this select 0)]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2]; closeDialog 0;";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { (damage _this) > 0 } && { [""Medical"", false] call ULP_fnc_checkPower }";
		};
	};

	class PersonMedical {
		class Revive {
			title = "打开生命体征";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "_this call ULP_fnc_openMedical";
			condition = "true";
		};

		class Unrestrain : Revive {
			title = "解除束缚";
			onClick = "[_this select 0, player, false] call ULP_fnc_restrain; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [player, [""Police""]] call ULP_fnc_isFaction || { [group (_this getVariable [""restrained"", objNull]), player] call ULP_fnc_inGroup } || { [player] call ULP_fnc_onDuty } }";
		};

		class PutOnStretcher {
			title = "放上担架";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "_this call ULP_fnc_toggleOnStretcher; closeDialog 0;";
			condition = "private _stretcher = [_this] call ULP_fnc_nearestStretcher; !isNull (_stretcher) && { (animationState _this) in [""unconsciousrevivedefault"", ""deadstate""] } && { isNull (_stretcher getVariable [""unitAttached"", objNull]) }";
		};

		class TakeOffStretcher : PutOnStretcher {
			title = "从担架上移下";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "_this call ULP_fnc_toggleOnStretcher; closeDialog 0;";
			condition = "private _stretcher = attachedTo _this; !isNull _stretcher && { _stretcher isKindOf ""Land_Stretcher_01_F"" }";
		};

		class PutInNearbyVehicle : Revive {
			title = "放入载具";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "private _unit = _this param [0, player, [objNull]]; private _vehicle = (nearestObjects[_unit, [""Car""], 5]) param [0, objNull]; if (isNull _vehicle || { !(_vehicle in ULP_Keys) }) exitWith { [""你必须把他们带到一辆你有钥匙的载具旁，才能将其放入...""] call ULP_fnc_hint; }; if !(((fullCrew _vehicle) findIf { isNull (_x param [0, objNull]) }) isEqualTo -1) exitWith { [""这辆载具没有空座位了..""] call ULP_fnc_hint; }; if (isNull (attachedTo _unit) || { _this call ULP_fnc_toggleOnStretcher }) then { [_vehicle, _unit] remoteExecCall [""ULP_fnc_putVehicleUnit"", _unit]; [format [""你已将 %1 放入载具..."", [_unit, true] call ULP_fnc_getName]] call ULP_fnc_hint; }; closeDialog 0;";
		};

		class AdministerBlood : Revive {
			title = "输血";
			onClick = "_this call ULP_fnc_administerBlood";
			condition = "(0 max ([""BloodBag""] call ULP_fnc_hasItem)) > 0";
		};

		class InventoryCheck : Revive {
			title = "检查背包";
			onClick = "player action [""Gear"", cursorObject]; closeDialog 0;";
			condition = "[""GraveRobber""] call ULP_fnc_hasPerk && { [player, [""Police""]] call ULP_fnc_isFaction || { [(_this getVariable [""IncapacitatedByGroup"", grpNull]), player] call ULP_fnc_inGroup } }";
		};

		class SeizeCommunications : Revive {
			title = "没收通讯设备";
			onClick = "_this call ULP_fnc_seizeComms;";
			condition = "[_this] call ULP_fnc_hasComms && { [player, [""Police""]] call ULP_fnc_isFaction || { [(_this getVariable [""IncapacitatedByGroup"", grpNull]), player] call ULP_fnc_inGroup } }";
		};

		class SetAssigned {
			title = "设为负责";
			factions[] = { "Medic" };
			onClick = "closeDialog 0; _this call ULP_fnc_setMedicalAssignment";
			condition = "isNull (_this getVariable [""AssignedMedic"", objNull])";
		};

		class SetUnAssigned : SetAssigned {
			title = "取消负责";
			condition = "((_this getVariable [""AssignedMedic"", objNull]) isEqualTo player)";
		};

		// Admin Commands...
		class AdminRevive : Revive {
			title = "管理员复活";
			onClick = "[player] remoteExecCall [""ULP_fnc_revived"", _this select 0]; (_this select 0) setDamage 0; [format[""You've revived this player using admin powers...""]] call ULP_fnc_hint; [getPlayerUID player, ""Admin"", [""AdminRevive"", serverTime, [name (_this select 0)]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2]; closeDialog 0;";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Medical"", false] call ULP_fnc_checkPower }";
		};
	};

	class PersonEscortOnly {
		class StopEscort {
			title = "停止押送";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "[_this select 0, player, false] call ULP_fnc_escort; closeDialog 0;";
			condition = "[_this] call ULP_fnc_isRestrained && { [_this] call ULP_fnc_isEscorted }";
		};
		class PutInVehicle : StopEscort {
			title = "放入载具";
			onClick = "private _vehicle = cursorObject; if (isNull _vehicle || { !((((typeOf _vehicle) call BIS_fnc_objectType) param [1, """"]) in [""Car"", ""Helicopter"", ""Plane"", ""Ship""]) }) exitWith { [""你必须把他们带到一辆载具旁，才能将其放入...""] call ULP_fnc_hint; }; if !(((fullCrew _vehicle) findIf { isNull (_x param [0, objNull]) }) isEqualTo -1) exitWith { [""这辆载具没有空座位了..""] call ULP_fnc_hint; }; [_this select 0, player, false] call ULP_fnc_escort; [_vehicle, _this select 0] remoteExecCall [""ULP_fnc_putVehicleUnit"", _this select 0]; closeDialog 0; [format [""你已将 %1 放入载具..."", [_this select 0, true] call ULP_fnc_getName]] call ULP_fnc_hint;";
		};
	};

	class House {
		class BuyHouse {
			title = "购买房屋";
			factions[] = { "Civilian", "Dunamis" };
			onClick = "_this call ULP_fnc_buyHouse;";
			condition = "isClass (missionConfigFile >> ""CfgFactions"" >> [player] call ULP_fnc_getFaction >> ""Housing"") && { !([_this] call ULP_fnc_isHouseOwned) } && { !(_this getVariable [""blacklisted"", false]) } && { !([""redzone_"", [_this]] call ULP_fnc_isUnitsInZone) }";
		};
	};

	class HouseOwner {
		class SellHouse {
			title = "出售房屋";
			factions[] = { "Civilian", "Dunamis" };
			onClick = "_this call ULP_fnc_sellHouse;";
			condition = "[_this, player, false] call ULP_fnc_isHouseOwner";
		};

		class UpgradeHouse : SellHouse {
			title = "升级房屋";
			onClick = "closeDialog 0; [""DialogUpgrades"", _this] call ULP_UI_fnc_createDialog;";
		};

		class MailBox {
			title = "邮箱";
			factions[] = { "Civilian", "Dunamis" };
			onClick = "closeDialog 0; _this call ULP_fnc_openMailBox";
			condition = "[_this] call ULP_fnc_isHouseOwner && { [_this, ""PersonalMailboxUpgrade""] call ULP_fnc_hasUpgrade }";
		};

		class VehicleGarage {
			title = "载具车库";
			factions[] = { "Civilian", "Dunamis" };
			onClick = "closeDialog 0; [{ !dialog }, _this, { [[""Car""], [[_this select 0] call ULP_fnc_getHouseGarageSpawn]] call ULP_fnc_openGarage; }] call ULP_fnc_waitUntilExecute;";
			condition = "[_this] call ULP_fnc_isHouseOwner && { [_this] call ULP_fnc_isHouseGarage }";
		};

		class StoreVehicle {
			title = "存入载具";
			factions[] = { "Civilian", "Dunamis" };
			onClick = "closeDialog 0; [_this select 0, [""Car""]] call ULP_fnc_storeVehicle;";
			condition = "[_this] call ULP_fnc_isHouseOwner && { [_this] call ULP_fnc_isHouseGarage } && { (player distance _this) <= 10 }";
		};
	};

	class HouseStorage {
		class OpenStorage {
			title = "打开储物";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "if ((missionNamespace getVariable [""ULP_HouseStorageEvent"", -1]) > -1) exitWith { [""已有一个请求正在进行中...""] call ULP_fnc_hint; }; ULP_HouseStorageEvent = [""HouseStorage"", { _this params [ ""_house"", ""_storage"" ]; ULP_HouseStorageEvent = nil; if (isNull _house || { (player distance _house) > 15 }) exitWith { [""你离这栋房子太远，无法访问实体储物...""] call ULP_fnc_hint; }; if (isNull _storage) exitWith { [""这栋房子没有实体储物空间...""] call ULP_fnc_hint; }; player action [""gear"", _storage]; }, true] call ULP_fnc_addEventHandler; [(_this select 0) getVariable [""building"", objNull]] remoteExecCall [""ULP_SRV_fnc_getStorage"", 2]; [""正在请求实体储物...""] call ULP_fnc_hint; closeDialog 0;";
			condition = "(player distance _this) <= 3 && { [_this getVariable [""building"", objNull], player] call ULP_fnc_isHouseOwner || { !(_this getVariable [""locked"", false]) } || { [] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Housing"", false] call ULP_fnc_checkPower } } }";
		};
	};

	class EquipmentBox {
		class ClearBox {
			title = "清空箱子";
			factions[] = { "Police" };
			onClick = "_this call ULP_fnc_clearCargo;";
			condition = "true";
		};
		
		class ResetLoadout {
			title = "重置配装";
			factions[] = { "Police", "Medic", "Hato" };
			onClick = "[] call ULP_fnc_setLoadout;";
			condition = "[[player] call ULP_fnc_getFaction] call ULP_fnc_canResetLoadout;";
		};
	};

	class Vault {
		class Repair {
			title = "修理金库";
			factions[] = { "Police" };
			onClick = "closeDialog 0; [""正在修理金库"", 60, _this, { (player distance (_this select 0)) <= 5 }, { private _object = _this select 0; [""你已成功修复锁具！""] call ULP_fnc_hint; _object setVariable [""locked"", true, true]; }, {}, [""GRAB"", ""CROUCH""]] call ULP_UI_fnc_startProgress;";
			condition = "!(_this getVariable [""locked"", false])";
		};
	};

	class Vehicle {

		class StartMining {
			title = "开始采集";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "_this call ULP_fnc_startVehicleGather";
			condition = "_this in ULP_Keys && { [_this] call ULP_fnc_canVehicleGather } && { !([_this] call ULP_fnc_isVehicleGathering) }";
		};

		class StopMining : StartMining {
			title = "停止采集";
			onClick = "_this call ULP_fnc_stopVehicleGather";
			condition = "_this in ULP_Keys && { [_this] call ULP_fnc_canVehicleGather } && { [_this] call ULP_fnc_isVehicleGathering } && { (_this getVariable [""mining"", objNull]) isEqualTo player }";
		};

		class Repair {
			title = "修理";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "_this call ULP_fnc_repairVehicle";
			condition = """ToolKit"" in (items player)";
		};

		class PatchTyres : Repair {
			title = "修补轮胎";
			condition = "_this call ULP_fnc_hasTyreDamage";
		};

		class Refuel : Repair {
			title = "用油桶加油";
			onClick = "_this call ULP_fnc_fuelCan";
			condition = "[""FuelCan""] call ULP_fnc_hasItem > 0";
		};

		class Lockpick : Repair {
			title = "撬锁";
			onClick = "_this call ULP_fnc_lockpick";
			condition = "!(_this in ULP_Keys) && { [""Lockpick""] call ULP_fnc_hasItem > 0 }";
		};

		class Push : Repair {
			title = "推动";
			onClick = "closeDialog 0; _this call ULP_fnc_pushVehicle";
			condition = "local _this && { alive _this } && { (crew _this) isEqualTo [] } && { (speed _this) <= 3 } && { [_this, [""Plane"", ""Ship""]] call ULP_fnc_isKindOf }";
		};

		class Registration : Repair {
			title = "登记信息";
			onClick = "closeDialog 0; [(_this select 0)] call ULP_fnc_vehicleRegistration";
			factions[] = { "Police", "Hato" };
			condition = "true";
		};

		class Clamp : Repair {
			title = "上夹子";
			onClick = "_this call ULP_fnc_clampVehicle";
			factions[] = { "Police", "Hato" };
			condition = "(_this getVariable [""clamp_fine"", []]) isEqualTo [] && { [""VehicleClamp""] call ULP_fnc_hasItem > 0 }";
		};

		class RemoveClamp : Clamp {
			title = "移除夹子";
			onClick = "_this call ULP_fnc_removeVehicleClamp";
			condition = "!((_this getVariable [""clamp_fine"", []]) isEqualTo []) && { [""VehicleClamp""] call ULP_fnc_hasItem > 0 }";
		};

		class Garage : Repair {
			title = "收进车库";
			onClick = "_this call ULP_fnc_garageVehicle";
			factions[] = { "Police", "Hato" };
			condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess || { [""Hato_Main"", 1] call ULP_fnc_hasAccess }";
		};

		class Impound : Garage {
			title = "扣押";
			onClick = "_this call ULP_fnc_impoundVehicle";
			condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess || { [""Hato_Main"", 2] call ULP_fnc_hasAccess }";
		};

		class Scrap : Repair {
			title = "报废压毁";
			onClick = "_this call ULP_fnc_crushVehicle";
			factions[] = { "Police" };
			condition = "[""Police_Main"", 3] call ULP_fnc_hasAccess && { [""bluezone_""] call ULP_fnc_isUnitsInZone }";
		};

		class PulloutOccupants : Repair {
			title = "拉出乘员";
			onClick = "if (_this call ULP_fnc_ejectVehicleCrew) then { closeDialog 0; };";
			condition = "(speed _this) <= 4 && { !((crew _this) isEqualTo []) } && { _this in ULP_Keys || [player, [""Police"", ""Medic""]] call ULP_fnc_isFaction }";
		};

		class Unflip : Repair {
			title = "扶正载具";
			onClick = "[_this select 0, 0] call ULP_fnc_flipVehicle";
			condition = "_this in ULP_Keys || { ""ToolKit"" in (items player) }";
		};

		// Admin Commands
		class AdminRepair {
			title = "管理员修理";
			factions[] = { "Police", "Medic", "Hato", "Civilian", "Dunamis" };
			onClick = "(_this select 0) setDamage 0; [format[""You've repaired this vehicle using admin powers.""]] call ULP_fnc_hint; [getPlayerUID player, ""Admin"", [""AdminRepair"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
			condition = "[] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Vehicle"", false] call ULP_fnc_checkPower }";
		};
		class AdminRefuel : AdminRepair {
			title = "管理员加油";
			onClick = "if ((count (units (_this select 0))) > 0) exitWith { [""载具内有人时无法进行加油！""] call ULP_fnc_hint; }; [(_this select 0), 1] remoteExecCall [""ULP_fnc_setFuel"", (_this select 0)]; hint format[""你已使用管理员权限为这辆载具加满油...""]; [getPlayerUID player, ""Admin"", [""AdminFuel"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
		};
		class AdminReg : AdminRepair {
			title = "管理员登记";
			onClick = "closeDialog 0; [(_this select 0)] call ULP_fnc_vehicleRegistration; [getPlayerUID player, ""Admin"", [""AdminReg"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
		};
		class AdminGarage : AdminRepair {
			title = "管理员收车";
			onClick = "_this call ULP_fnc_garageVehicle; [getPlayerUID player, ""Admin"", [""AdminGarage"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
		};
		class AdminImpound : AdminRepair {
			title = "管理员扣押";
			onClick = "_this call ULP_fnc_impoundVehicle; [getPlayerUID player, ""Admin"", [""AdminImpound"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
		};
		class AdminScrap : AdminRepair {
			title = "管理员报废";
			onClick = "_this call ULP_fnc_crushVehicle; [getPlayerUID player, ""Admin"", [""AdminScrap"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
		};
		class AdminPulloutOccupants : AdminRepair {
			title = "管理员拉出乘员";
			onClick = "if (_this call ULP_fnc_ejectVehicleCrew) then { closeDialog 0; }; [getPlayerUID player, ""Admin"", [""AdminPulloutOccupants"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
			condition = "(speed _this) <= 4 && { [] call ULP_fnc_isStaff && { [player] call ULP_fnc_onDuty } && { [""Vehicle"", false] call ULP_fnc_checkPower } }";
		};
		class AdminUnflip : AdminRepair {
			title = "管理员扶正";
			onClick = "_this call ULP_fnc_flipVehicle; [getPlayerUID player, ""Admin"", [""AdminUnflip"", serverTime, [(_this select 0) getVariable [""vehicle_id"", -1]]]] remoteExecCall [""ULP_SRV_fnc_logPlayerEvent"", 2];";
		};
	};
};
