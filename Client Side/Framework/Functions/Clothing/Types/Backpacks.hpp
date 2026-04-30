class B_LegStrapBag_black_F {
	displayName = "腿挂包（Leg Strap）";
	price = 800;
	reputation = false;
	virtualSpace = 12;
	class Textures {
		class B_LegStrapBag_black_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class B_LegStrapBag_coyote_F : B_LegStrapBag_black_F { displayName = "郊狼色（Coyote）"; };
		class B_LegStrapBag_olive_F : B_LegStrapBag_black_F { displayName = "橄榄色（Olive）"; };
	};
};
class B_LegStrapBag_coyote_F : B_LegStrapBag_black_F {};
class B_LegStrapBag_olive_F : B_LegStrapBag_black_F {};

class B_Messenger_Black_F : B_LegStrapBag_black_F {
	displayName = "邮差包（Messenger Bag）";
	price = 1000;
	virtualSpace = 14;
	class Textures {
		class B_Messenger_Black_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class B_Messenger_Gray_F : B_Messenger_Black_F { displayName = "灰色（Gray）"; };
		class B_Messenger_Coyote_F : B_Messenger_Black_F { displayName = "郊狼色（Coyote）"; };
		class B_Messenger_Olive_F : B_Messenger_Black_F { displayName = "橄榄色（Olive）"; };
		class B_Messenger_IDAP_F : B_Messenger_Black_F { 
			displayName = "IDAP"; 
			condition = "[""IDAP""] call ULP_fnc_hasLicense";
		};
	};
};
class B_Messenger_Gray_F : B_Messenger_Black_F {};
class B_Messenger_Coyote_F : B_Messenger_Black_F {};
class B_Messenger_Olive_F : B_Messenger_Black_F {};
class B_Messenger_IDAP_F : B_Messenger_Black_F {};

class B_SCBA_01_F : B_LegStrapBag_black_F {
	displayName = "SCBA 呼吸装置（SCBA）";
	price = 10000;
	virtualSpace = 0;
	class Textures {};
};

class B_CominationUnitRespirator_01_F : B_SCBA_01_F {
	displayName = "组合式呼吸器（Combination Unit Respirator）";
	price = 10000;
	class Textures {};
};

class B_AssaultPack_blk : B_LegStrapBag_black_F {
	displayName = "突击背包（Assault Pack）";
	price = 1300;
	virtualSpace = 16;
	class Textures {
		class B_AssaultPack_blk {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class B_AssaultPack_cbr : B_AssaultPack_blk { displayName = "郊狼色（Coyote）"; };
		class B_AssaultPack_khk : B_AssaultPack_blk { displayName = "卡其色（Khaki）"; };
		class B_AssaultPack_rgr : B_AssaultPack_blk { displayName = "绿色（Green）"; };
		class B_AssaultPack_sgg : B_AssaultPack_blk { displayName = "鼠尾草绿（Sage）"; };
		class B_AssaultPack_wdl_F : B_AssaultPack_blk { 
			displayName = "林地迷彩（Woodland）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		class B_AssaultPack_eaf_F : B_AssaultPack_wdl_F { displayName = "几何纹（Geometric）"; };
	};
};
class B_AssaultPack_cbr : B_AssaultPack_blk {};
class B_AssaultPack_khk : B_AssaultPack_blk {};
class B_AssaultPack_rgr : B_AssaultPack_blk {};
class B_AssaultPack_sgg : B_AssaultPack_blk {};
class B_AssaultPack_wdl_F : B_AssaultPack_blk {};
class B_AssaultPack_eaf_F : B_AssaultPack_blk {};

class B_FieldPack_blk : B_LegStrapBag_black_F {
	displayName = "野战背包（Field Pack）";
	price = 2000;
	virtualSpace = 16;
	class Textures {
		class B_FieldPack_blk {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class B_FieldPack_cbr : B_FieldPack_blk { displayName = "郊狼色（Coyote）"; };
		class B_FieldPack_khk : B_FieldPack_blk { displayName = "卡其色（Khaki）"; };
		class B_FieldPack_oli : B_FieldPack_blk { displayName = "橄榄色（Olive）"; };
		class B_FieldPack_green_F : B_FieldPack_blk { displayName = "绿色（Green）"; };
	};
};
class B_FieldPack_cbr : B_FieldPack_blk {};
class B_FieldPack_khk : B_FieldPack_blk {};
class B_FieldPack_oli : B_FieldPack_blk {};
class B_FieldPack_green_F : B_FieldPack_blk {};

class B_Kitbag_cbr : B_LegStrapBag_black_F {
	displayName = "装备袋（Kitbag）";
	price = 3000;
	virtualSpace = 24;
	class Textures {
		class B_Kitbag_cbr {
			displayName = "郊狼色（Coyote）";
			condition = "true";
		};
		class B_Kitbag_tan : B_Kitbag_cbr { displayName = "棕褐色（Tan）"; };
		class B_Kitbag_rgr : B_Kitbag_cbr { displayName = "绿色（Green）"; };
		class B_Kitbag_sgg : B_Kitbag_cbr { displayName = "鼠尾草绿（Sage）"; };
		class B_Kitbag_mcamo : B_Kitbag_cbr { 
			displayName = "MTP 迷彩（MTP）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
	};
};
class B_Kitbag_tan : B_Kitbag_cbr {};
class B_Kitbag_rgr : B_Kitbag_cbr {};
class B_Kitbag_sgg : B_Kitbag_cbr {};
class B_Kitbag_mcamo : B_Kitbag_cbr {};

class B_TacticalPack_blk : B_LegStrapBag_black_F {
	displayName = "战术背包（Tactical Pack）";
	price = 3500;
	virtualSpace = 20;
	class Textures {
		class B_TacticalPack_blk {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class B_TacticalPack_oli : B_TacticalPack_blk { displayName = "橄榄色（Olive）"; };
		class B_TacticalPack_rgr : B_TacticalPack_blk { displayName = "绿色（Green）"; };
	};
};
class B_TacticalPack_oli : B_TacticalPack_blk {};
class B_TacticalPack_rgr : B_TacticalPack_blk {};

class B_CivilianBackpack_01_Everyday_Black_F : B_LegStrapBag_black_F {
	displayName = "民用背包（Civilian Pack）";
	price = 2000;
	virtualSpace = 20;
	class Textures {
		class B_CivilianBackpack_01_Everyday_Black_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class B_CivilianBackpack_01_Everyday_Astra_F : B_CivilianBackpack_01_Everyday_Black_F { 
			displayName = "Astra"; 
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		class B_CivilianBackpack_01_Everyday_Vrana_F : B_CivilianBackpack_01_Everyday_Astra_F { displayName = "Vrana"; };
	};
};
class B_CivilianBackpack_01_Everyday_Astra_F : B_CivilianBackpack_01_Everyday_Black_F {};
class B_CivilianBackpack_01_Everyday_Vrana_F : B_CivilianBackpack_01_Everyday_Black_F {};

class B_CivilianBackpack_01_Sport_Blue_F : B_CivilianBackpack_01_Everyday_Black_F {
	displayName = "运动背包（Sports Pack）";
	class Textures {
		class B_CivilianBackpack_01_Sport_Blue_F {
			displayName = "蓝色（Blue）";
			condition = "true";
		};
		class B_CivilianBackpack_01_Sport_Green_F : B_CivilianBackpack_01_Sport_Blue_F { displayName = "绿色（Green）"; };
		class B_CivilianBackpack_01_Sport_Red_F : B_CivilianBackpack_01_Sport_Blue_F { displayName = "红色（Red）"; };
	};
};
class B_CivilianBackpack_01_Sport_Green_F : B_CivilianBackpack_01_Sport_Blue_F {};
class B_CivilianBackpack_01_Sport_Red_F : B_CivilianBackpack_01_Sport_Blue_F {};

class B_Carryall_cbr : B_LegStrapBag_black_F {
	displayName = "大型背囊（Carryall）";
	price = 5000;
	virtualSpace = 25;
	class Textures {
		// Factions
		class INVIS {
			displayName = "隐藏款（Invisible）";
			textures[] = { "" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction || [player, [""Medic""]] call ULP_fnc_isFaction || [player, [""Hato""]] call ULP_fnc_isFaction";
		};

		// Civilian
		class B_Carryall_cbr {
			displayName = "郊狼色（Coyote）";
			condition = "true";
		};
		class B_Carryall_khk : B_Carryall_cbr { displayName = "卡其色（Khaki）"; };
		class B_Carryall_oli : B_Carryall_cbr { displayName = "橄榄色（Olive）"; };
		class B_Carryall_green_F : B_Carryall_cbr { displayName = "绿色（Green）"; };
		class B_Carryall_wdl_F : B_Carryall_cbr { 
			displayName = "林地迷彩（Woodland）";
			condition = "[] call ULP_fnc_donatorLevel >= 2"; 
		};
		class B_Carryall_eaf_F : B_Carryall_wdl_F { displayName = "几何纹（Geometric）"; };
		class B_Carryall_ghex_F : B_Carryall_wdl_F { displayName = "绿色六角迷彩（Green Hex）"; };
		class B_Carryall_ocamo_F : B_Carryall_wdl_F { displayName = "六角迷彩（Hex）"; };
		class B_Carryall_mcamo_F : B_Carryall_wdl_F { displayName = "MTP 迷彩（MTP）"; };
		class B_Carryall_occamo_F : B_Carryall_wdl_F { displayName = "城市迷彩（Urban）"; };
		class B_Carryall_taiga_F : B_Carryall_wdl_F { displayName = "Taiga 迷彩（Taiga）"; };
		class B_Carryall_blk : B_Carryall_wdl_F { 
			displayName = "黑色（Black）";
			condition = "[] call ULP_fnc_donatorLevel >= 2 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
	};
};
class B_Carryall_khk : B_Carryall_cbr {};
class B_Carryall_oli : B_Carryall_cbr {};
class B_Carryall_green_F : B_Carryall_cbr {};
class B_Carryall_wdl_F : B_Carryall_cbr {};
class B_Carryall_ghex_F : B_Carryall_cbr {};
class B_Carryall_ocamo_F : B_Carryall_cbr {};
class B_Carryall_mcamo_F : B_Carryall_cbr {};
class B_Carryall_occamo_F : B_Carryall_cbr {};
class B_Carryall_taiga_F : B_Carryall_cbr {};
class B_Carryall_blk : B_Carryall_cbr {};

class B_ViperLightHarness_blk_F : B_LegStrapBag_black_F {
	displayName = "轻型 Viper 背具（Light Viper Harness）";
	price = 3500;
	reputation = true;
	virtualSpace = 16;
	class Textures {
		class B_ViperLightHarness_blk_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class B_ViperLightHarness_khk_F : B_ViperLightHarness_blk_F { displayName = "卡其色（Khaki）"; };
		class B_ViperLightHarness_oli_F : B_ViperLightHarness_blk_F { displayName = "橄榄色（Olive）"; };
	};
};
class B_ViperLightHarness_khk_F : B_ViperLightHarness_blk_F {};
class B_ViperLightHarness_oli_F : B_ViperLightHarness_blk_F {};

class B_ViperHarness_blk_F : B_ViperLightHarness_blk_F {
	displayName = "Viper 背具（Viper Harness）";
	price = 4000;
	virtualSpace = 24;
	class Textures {
		class B_ViperHarness_blk_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class B_ViperHarness_khk_F : B_ViperHarness_blk_F { displayName = "卡其色（Khaki）"; };
		class B_ViperHarness_oli_F : B_ViperHarness_blk_F { displayName = "橄榄色（Olive）"; };
	};
};
class B_ViperHarness_khk_F : B_ViperHarness_blk_F {};
class B_ViperHarness_oli_F : B_ViperHarness_blk_F {};

class B_Bergen_mcamo_F : B_LegStrapBag_black_F {
	displayName = "Bergen 登山包（Bergen）";
	price = 12500;
	virtualSpace = 30;
	class Textures {	
		// Factions
		class INVIS {
			displayName = "隐藏款（Invisible）";
			textures[] = { "" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction || [player, [""Medic""]] call ULP_fnc_isFaction || [player, [""Hato""]] call ULP_fnc_isFaction";
		};

		// Civilian
		class B_Bergen_mcamo_F {
			displayName = "MTP 迷彩（MTP）";
			condition = "true";
		};
		class B_Bergen_dgtl_F : B_Bergen_mcamo_F { displayName = "数码迷彩（Digital）"; };
		class B_Bergen_hex_F : B_Bergen_mcamo_F { displayName = "六角迷彩（Hex）"; };
		class B_Bergen_tna_F : B_Bergen_mcamo_F { displayName = "热带迷彩（Tropic）"; };
	};
};
class B_Bergen_dgtl_F : B_Bergen_mcamo_F {};
class B_Bergen_hex_F : B_Bergen_mcamo_F {};
class B_Bergen_tna_F : B_Bergen_mcamo_F {};

class B_RadioBag_01_black_F : B_ViperLightHarness_blk_F {
	displayName = "无线电背包（Radio Pack）";
	price = 25000;
	virtualSpace = 8;
	class Textures {
		class B_RadioBag_01_black_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class B_RadioBag_01_digi_F : B_RadioBag_01_black_F { displayName = "数码迷彩（Digi）"; };
		class B_RadioBag_01_eaf_F : B_RadioBag_01_black_F { displayName = "几何纹（Geometric）"; };
		class B_RadioBag_01_ghex_F : B_RadioBag_01_black_F { displayName = "绿色六角迷彩（Green Hex）"; };
		class B_RadioBag_01_hex_F : B_RadioBag_01_black_F { displayName = "六角迷彩（Hex）"; };
		class B_RadioBag_01_mtp_F : B_RadioBag_01_black_F { displayName = "MTP 迷彩（MTP）"; };
		class B_RadioBag_01_tropic_F : B_RadioBag_01_black_F { displayName = "热带迷彩（Tropic）"; };
		class B_RadioBag_01_wdl_F : B_RadioBag_01_black_F { displayName = "林地迷彩（Woodland）"; };
	};
};
class B_RadioBag_01_digi_F : B_RadioBag_01_black_F {};
class B_RadioBag_01_eaf_F : B_RadioBag_01_black_F {};
class B_RadioBag_01_ghex_F : B_RadioBag_01_black_F {};
class B_RadioBag_01_hex_F : B_RadioBag_01_black_F {};
class B_RadioBag_01_mtp_F : B_RadioBag_01_black_F {};
class B_RadioBag_01_tropic_F : B_RadioBag_01_black_F {};
class B_RadioBag_01_wdl_F : B_RadioBag_01_black_F {};

class B_Parachute : B_LegStrapBag_black_F {
	displayName = "降落伞（Parachute）";
	price = 10000;
	virtualSpace = 0;
	class Textures {};
};
