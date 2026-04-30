class H_HeadBandage_clean_F {
	displayName = "绷带（Bandage）";
	price = 5;
	reputation = false;
	isMask = false;
	isNV = false;
	class Textures {};
};
class H_HeadBandage_stained_F : H_HeadBandage_clean_F {};
class H_HeadBandage_bloody_F : H_HeadBandage_clean_F {};

class H_Hat_Tinfoil_F : H_HeadBandage_clean_F {
	displayName = "锡纸帽（Tin Foil）";
	price = 5;
	class Textures {};
};

class H_WirelessEarpiece_F : H_HeadBandage_clean_F {
	displayName = "无线耳机（Wireless Earpiece）";
	price = 10;
	class Textures {};
};

class H_Bandanna_gry : H_HeadBandage_clean_F {
	displayName = "头巾（Bandanna）";
	price = 10;
	class Textures {
		class H_Bandanna_gry {
			displayName = "灰色（Gray）";
			condition = "true";
		};
		class H_Bandanna_blu : H_Bandanna_gry { displayName = "蓝色（Blue）"; };
		class H_Bandanna_khk : H_Bandanna_gry { displayName = "卡其色（Khaki）"; };
		class H_Bandanna_cbr : H_Bandanna_gry { displayName = "郊狼色（Coyote）"; };
		class H_Bandanna_sand : H_Bandanna_gry { displayName = "沙色（Sand）"; };
		class H_Bandanna_sgg : H_Bandanna_gry { displayName = "鼠尾草绿（Sage）"; };
		class H_Bandanna_camo : H_Bandanna_gry { displayName = "迷彩（Camo）"; };
		class H_Bandanna_mcamo : H_Bandanna_gry { 
			displayName = "MTP 迷彩（MTP）";
			condition = "[] call ULP_fnc_donatorLevel >= 2"; 
		};
		class H_Bandanna_surfer : H_Bandanna_mcamo { displayName = "冲浪款（Surfer）"; };
		class H_Bandanna_surfer_blk : H_Bandanna_mcamo { displayName = "冲浪款黑色（Surfer, Black）"; };
		class H_Bandanna_surfer_grn : H_Bandanna_mcamo { displayName = "冲浪款绿色（Surfer, Green）"; };
	};
};
class H_Bandanna_blu : H_Bandanna_gry {};
class H_Bandanna_khk : H_Bandanna_gry {};
class H_Bandanna_khk_hs : H_Bandanna_gry {};
class H_Bandanna_cbr : H_Bandanna_gry {};
class H_Bandanna_sand : H_Bandanna_gry {};
class H_Bandanna_sgg : H_Bandanna_gry {};
class H_Bandanna_camo : H_Bandanna_gry {};
class H_Bandanna_mcamo : H_Bandanna_gry {};
class H_Bandanna_surfer : H_Bandanna_gry {};
class H_Bandanna_surfer_blk : H_Bandanna_gry {};
class H_Bandanna_surfer_grn : H_Bandanna_gry {};

class H_Cap_blk : H_HeadBandage_clean_F {
	displayName = "鸭舌帽（Cap）";
	price = 50;
	class Textures {
		class H_Cap_blk {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class H_Cap_red : H_Cap_blk { displayName = "红色（Red）"; };
		class H_Cap_blu : H_Cap_blk { displayName = "蓝色（Blue）"; };
		class H_Cap_tan : H_Cap_blk { displayName = "棕褐色（Tan）"; };
		class H_Cap_oli : H_Cap_blk { displayName = "橄榄色（Olive）"; };
		class H_Cap_oli_hs : H_Cap_blk { displayName = "橄榄色带耳机（Olive (Headset)）"; };
		class H_Cap_marshal : H_Cap_blk { displayName = "红色带耳机（Red (Headset)）"; };
		class H_Cap_press : H_Cap_blk { displayName = "媒体（Press）"; };
		class H_Cap_usblack : H_Cap_blk { 
			displayName = "US 黑色款（US (Black)）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		class H_Cap_tan_specops_US : H_Cap_usblack { displayName = "US MTP 款（US (MTP)）"; };
		class H_Cap_khaki_specops_UK : H_Cap_usblack { displayName = "UK"; };
		class H_Cap_brn_SPECOPS : H_Cap_usblack { displayName = "OPFOR"; };
		class H_Cap_blk_Raven : H_Cap_usblack { displayName = "AAF"; };
		class H_Cap_grn_BI : H_Cap_usblack { displayName = "BI"; };
		class H_Cap_blk_ION : H_Cap_usblack { displayName = "ION"; };
		class H_Cap_blk_CMMG : H_Cap_usblack { displayName = "CMMG"; };
		class H_Cap_Black_IDAP_F : H_Cap_usblack { 
			displayName = "IDAP 黑色款（IDAP (Black)）";
			condition = "[""IDAP""] call ULP_fnc_hasLicense";
		};
		class H_Cap_White_IDAP_F : H_Cap_Black_IDAP_F { displayName = "IDAP 白色款（IDAP (White)）"; };
		class H_Cap_Orange_IDAP_F : H_Cap_Black_IDAP_F { displayName = "IDAP 橙色款（IDAP (Orange)）"; };
		class H_Cap_surfer : H_Cap_usblack { displayName = "冲浪款（Surfer）"; };
		class H_Cap_police : H_Cap_blk {
			displayName = "Police";
			condition = "[player, [""Police""]] call ULP_fnc_isFaction";
		};
	};
};
class H_Cap_usblack : H_Cap_blk {};
class H_Cap_tan_specops_US : H_Cap_blk {};
class H_Cap_khaki_specops_UK : H_Cap_blk {};
class H_Cap_brn_SPECOPS : H_Cap_blk {};
class H_Cap_blk_Raven : H_Cap_blk {};
class H_Cap_police : H_Cap_blk {};
class H_Cap_press : H_Cap_blk {};
class H_Cap_grn_BI : H_Cap_blk {};
class H_Cap_blk_ION : H_Cap_blk {};
class H_Cap_blk_CMMG : H_Cap_blk {};
class H_Cap_red : H_Cap_blk {};
class H_Cap_blu : H_Cap_blk {};
class H_Cap_tan : H_Cap_blk {};
class H_Cap_oli : H_Cap_blk {};
class H_Cap_oli_hs : H_Cap_blk {};
class H_Cap_marshal : H_Cap_blk {};
class H_Cap_surfer : H_Cap_blk {};
class H_Cap_Black_IDAP_F : H_Cap_blk {};
class H_Cap_White_IDAP_F : H_Cap_blk {};
class H_Cap_Orange_IDAP_F : H_Cap_blk {};

class H_MilCap_gry : H_HeadBandage_clean_F {
	displayName = "军帽（Military Cap）";
	price = 50;
	class Textures {
		class H_MilCap_gry {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class H_MilCap_blue : H_MilCap_gry { displayName = "蓝色（Blue）"; };
		class H_MilCap_grn : H_MilCap_gry { displayName = "绿色（Green）"; };
		class H_MilCap_wdl : H_MilCap_gry { 
			displayName = "林地迷彩（Woodland）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		class H_MilCap_ghex_F : H_MilCap_wdl { displayName = "绿色六角迷彩（Green Hex）"; };
		class H_MilCap_ocamo : H_MilCap_wdl { displayName = "六角迷彩（Hex）"; };
		class H_MilCap_mcamo : H_MilCap_wdl { displayName = "MTP 迷彩（MTP）"; };
		class H_MilCap_taiga : H_MilCap_wdl { displayName = "Taiga 迷彩（Taiga）"; };
		class H_MilCap_tna_F : H_MilCap_wdl { displayName = "热带迷彩（Tropic）"; };
		class H_MilCap_dgtl : H_MilCap_wdl { displayName = "AAF"; };
		class H_MilCap_eaf : H_MilCap_wdl { displayName = "LDF"; };
	};
};
class H_MilCap_blue : H_MilCap_gry {};
class H_MilCap_grn : H_MilCap_gry {};
class H_MilCap_wdl : H_MilCap_gry {};
class H_MilCap_ghex_F : H_MilCap_gry {};
class H_MilCap_ocamo : H_MilCap_gry {};
class H_MilCap_mcamo : H_MilCap_gry {};
class H_MilCap_taiga : H_MilCap_gry {};
class H_MilCap_tna_F : H_MilCap_gry {};
class H_MilCap_dgtl : H_MilCap_gry {};
class H_MilCap_eaf : H_MilCap_gry {};

class H_Hat_grey : H_HeadBandage_clean_F {
	displayName = "软呢帽（Fedora Hat）";
	price = 50;
	class Textures {
		class H_Hat_grey {
			displayName = "灰色（Grey）";
			condition = "true";
		};
		class H_Hat_blue : H_Hat_grey { displayName = "蓝色（Blue）"; };
		class H_Hat_brown : H_Hat_grey { displayName = "棕色（Brown）"; };
		class H_Hat_tan : H_Hat_grey { displayName = "棕褐色（Tan）"; };
		class H_Hat_checker : H_Hat_grey { 
			displayName = "格纹（Checker）";
			condition = "[] call ULP_fnc_donatorLevel >= 2"; 
		};
		class H_Hat_camo : H_Hat_checker { displayName = "迷彩（Camo）"; };
	};
};
class H_Hat_blue : H_Hat_grey {};
class H_Hat_brown : H_Hat_grey {};
class H_Hat_tan : H_Hat_grey {};
class H_Hat_checker : H_Hat_grey {};
class H_Hat_camo : H_Hat_grey {};

class H_StrawHat : H_HeadBandage_clean_F {
	displayName = "草帽（Straw Hat）";
	price = 50;
	class Textures {
		class H_StrawHat {
			displayName = "浅棕色（Light Brown）";
			condition = "true";
		};
		class H_StrawHat_dark : H_StrawHat { displayName = "深棕色（Dark Brown）"; };
	};
};
class H_StrawHat_dark : H_StrawHat {};

class H_Hat_Safari_sand_F : H_HeadBandage_clean_F {
	displayName = "探险帽（Safari Hat）";
	price = 60;
	class Textures {
		class H_Hat_Safari_sand_F {
			displayName = "沙色（Sand）";
			condition = "true";
		};
		class H_Hat_Safari_olive_F : H_Hat_Safari_sand_F { 
			displayName = "橄榄色（Olive）";
			condition = "[] call ULP_fnc_donatorLevel >= 2"; 
		};
	};
};
class H_Hat_Safari_olive_F : H_Hat_Safari_sand_F {};

class H_Watchcap_blk : H_HeadBandage_clean_F {
	displayName = "毛线帽（Beanie）";
	price = 80;
	class Textures {
		class H_Watchcap_blk {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class H_Watchcap_cbr : H_Watchcap_blk { displayName = "棕色（Brown）"; };
		class H_Watchcap_khk : H_Watchcap_blk { displayName = "卡其色（Khaki）"; };
		class H_Watchcap_camo : H_Watchcap_blk { displayName = "绿色（Green）"; };
	};
};
class H_Watchcap_cbr : H_Watchcap_blk {};
class H_Watchcap_khk : H_Watchcap_blk {};
class H_Watchcap_camo : H_Watchcap_blk {};

class H_Booniehat_khk : H_HeadBandage_clean_F {
	displayName = "奔尼帽（Booniehat）";
	price = 80;
	class Textures {
		class H_Booniehat_khk {
			displayName = "卡其色（Khaki）";
			condition = "true";
		};
		class H_Booniehat_grn : H_Booniehat_khk { displayName = "绿色（Green）"; };
		class H_Booniehat_oli : H_Booniehat_khk { displayName = "橄榄色（Olive）"; };
		class H_Booniehat_tan : H_Booniehat_khk { displayName = "棕褐色（Tan）"; };
		class H_Booniehat_mcamo : H_Booniehat_khk { 
			displayName = "MTP 迷彩（MTP）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		class H_Booniehat_dgtl : H_Booniehat_mcamo { displayName = "数码迷彩（Digital）"; };
		class H_Booniehat_wdl : H_Booniehat_mcamo { displayName = "林地迷彩（Woodland）"; };
		class H_Booniehat_mgrn : H_Booniehat_mcamo { displayName = "浅褪绿色（Green (Faded)）"; };
		class H_Booniehat_taiga : H_Booniehat_mcamo { displayName = "Taiga 迷彩（Taiga）"; };
		class H_Booniehat_tna_F : H_Booniehat_mcamo { displayName = "热带迷彩（Tropic）"; };
		class H_Booniehat_eaf : H_Booniehat_mcamo { displayName = "LDF"; };
	};
};
class H_Booniehat_khk_hs : H_Booniehat_khk {};
class H_Booniehat_grn : H_Booniehat_khk {};
class H_Booniehat_oli : H_Booniehat_khk {};
class H_Booniehat_tan : H_Booniehat_khk {};
class H_Booniehat_mcamo : H_Booniehat_khk {};
class H_Booniehat_dgtl : H_Booniehat_khk {};
class H_Booniehat_wdl : H_Booniehat_khk {};
class H_Booniehat_mgrn : H_Booniehat_khk {};
class H_Booniehat_taiga : H_Booniehat_khk {};
class H_Booniehat_tna_F : H_Booniehat_khk {};
class H_Booniehat_eaf : H_Booniehat_khk {};

class H_Beret_blk : H_HeadBandage_clean_F {
	displayName = "贝雷帽（Beret）";
	price = 1000;
	class Textures {
		// Altis Police Service
		class H_Beret_blk {
			displayName = "Police 巡逻贝雷帽（Police Patrol）";
			condition = "[""Police_Main"", 2] call ULP_fnc_hasAccess";
		};
		class H_Beret_gen_F : H_Beret_blk {
			displayName = "Police 指挥贝雷帽（Police Command）";
			condition = "[""Police_Main"", 8] call ULP_fnc_hasAccess || { [""Police_COL"", 3] call ULP_fnc_hasAccess }";
		};
		class H_Beret_EAF_01_F : H_Beret_blk {
			displayName = "特勤指挥贝雷帽（Spec. Command）";
			condition = "[""Police_SCO"", 4] call ULP_fnc_hasAccess || { [""Police_NCA"", 4] call ULP_fnc_hasAccess } || { [""Police_SEG"", 3] call ULP_fnc_hasAccess }";
		};

		// Altis Ambulance Service
		class H_Beret_02 : H_Beret_blk {
			displayName = "救护服务总监贝雷帽（Directors' of Ambulance Services）";
			condition = "[""Medic_Main"", 7] call ULP_fnc_hasAccess";
		};
		class H_Beret_Colonel : H_Beret_blk {
			displayName = "部门主管贝雷帽（Department Head）";
			condition = "[""Medic_Main"", 6] call ULP_fnc_hasAccess";
		};

		// Civilian Faction
		class H_Beret_CSAT_01_F : H_Beret_blk {
			displayName = "Dunamis 贝雷帽（Dunamis Beret）";
			condition = "[] call ULP_fnc_isDunamis";
		};
	};
};
class H_Beret_gen_F : H_Beret_blk {};
class H_Beret_EAF_01_F : H_Beret_blk {};
class H_Beret_02 : H_Beret_blk {};
class H_Beret_Colonel : H_Beret_blk {};
class H_Beret_CSAT_01_F : H_Beret_blk {};

class H_ShemagOpen_khk : H_HeadBandage_clean_F {
	displayName = "头巾围巾（Shemag）";
	price = 2000;
	reputation = true;
	isMask = true;
	class Textures {
		class H_ShemagOpen_khk {
			displayName = "白色（White）";
			condition = "true";
		};
		class H_Shemag_tan : H_ShemagOpen_khk { displayName = "棕褐色（Tan）"; };
		class H_Shemag_olive : H_ShemagOpen_khk { displayName = "橄榄色（Olive）"; };
		class H_Shemag_olive_hs : H_ShemagOpen_khk { 
			displayName = "橄榄色带耳机（Olive (Headset)）";
			condition = "[] call ULP_fnc_donatorLevel >= 2"; 
		};
	};
};
class H_Shemag_tan : H_ShemagOpen_khk {};
class H_Shemag_olive : H_ShemagOpen_khk {};
class H_Shemag_olive_hs : H_ShemagOpen_khk {};

class H_EarProtectors_black_F : H_HeadBandage_clean_F {
	displayName = "护耳器（Ear Protectors）";
	price = 100;
	class Textures {
		class H_EarProtectors_black_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class H_HeadSet_black_F : H_EarProtectors_black_F { displayName = "黑色带耳机（Black (Headset)）"; };
		class H_EarProtectors_white_F : H_EarProtectors_black_F { displayName = "白色（White）"; };
		class H_HeadSet_white_F : H_EarProtectors_black_F { displayName = "白色带耳机（White (Headset)）"; };
		class H_EarProtectors_red_F : H_EarProtectors_black_F { displayName = "红色（Red）"; };
		class H_HeadSet_red_F : H_EarProtectors_black_F { displayName = "红色带耳机（Red (Headset)）"; };
		class H_EarProtectors_orange_F : H_EarProtectors_black_F { displayName = "橙色（Orange）"; };
		class H_HeadSet_orange_F : H_EarProtectors_black_F { displayName = "橙色带耳机（Orange (Headset)）"; };
		class H_EarProtectors_yellow_F : H_EarProtectors_black_F { displayName = "黄色（Yellow）"; };
		class H_HeadSet_yellow_F : H_EarProtectors_black_F { displayName = "黄色带耳机（Yellow (Headset)）"; };
	};
};
class H_EarProtectors_white_F : H_EarProtectors_black_F {};
class H_EarProtectors_red_F : H_EarProtectors_black_F {};
class H_EarProtectors_orange_F : H_EarProtectors_black_F {};
class H_EarProtectors_yellow_F : H_EarProtectors_black_F {};
class H_HeadSet_black_F : H_EarProtectors_black_F {};
class H_HeadSet_white_F : H_EarProtectors_black_F {};
class H_HeadSet_red_F : H_EarProtectors_black_F {};
class H_HeadSet_orange_F : H_EarProtectors_black_F {};
class H_HeadSet_yellow_F : H_EarProtectors_black_F {};

class H_Construction_basic_black_F : H_HeadBandage_clean_F {
	displayName = "安全帽（Hard Hat）";
	price = 150;
	class Textures {
		class H_Construction_basic_black_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class H_Construction_headset_black_F : H_Construction_basic_black_F { displayName = "黑色带耳机（Black (Headset)）"; };
		class H_Construction_basic_white_F : H_Construction_basic_black_F { displayName = "白色（White）"; };
		class H_Construction_headset_white_F : H_Construction_basic_black_F { displayName = "白色带耳机（White (Headset)）"; };
		class H_Construction_basic_red_F : H_Construction_basic_black_F { displayName = "红色（Red）"; };
		class H_Construction_headset_red_F : H_Construction_basic_black_F { displayName = "红色带耳机（Red (Headset)）"; };
		class H_Construction_basic_orange_F : H_Construction_basic_black_F { displayName = "橙色（Orange）"; };
		class H_Construction_headset_orange_F : H_Construction_basic_black_F { displayName = "橙色带耳机（Orange (Headset)）"; };
		class H_Construction_basic_yellow_F : H_Construction_basic_black_F { displayName = "黄色（Yellow）"; };
		class H_Construction_headset_yellow_F : H_Construction_basic_black_F { displayName = "黄色带耳机（Yellow (Headset)）"; };
		class H_Construction_basic_vrana_F : H_Construction_basic_black_F { displayName = "Virana"; };
		class H_Construction_headset_vrana_F : H_Construction_basic_black_F { displayName = "Virana 带耳机款（Virana (Headset)）"; };
	};
};
class H_Construction_headset_black_F : H_Construction_basic_black_F {};
class H_Construction_basic_white_F : H_Construction_basic_black_F {};
class H_Construction_headset_white_F : H_Construction_basic_black_F {};
class H_Construction_basic_red_F : H_Construction_basic_black_F {};
class H_Construction_headset_red_F : H_Construction_basic_black_F {};
class H_Construction_basic_orange_F : H_Construction_basic_black_F {};
class H_Construction_headset_orange_F : H_Construction_basic_black_F {};
class H_Construction_basic_yellow_F : H_Construction_basic_black_F {};
class H_Construction_headset_yellow_F : H_Construction_basic_black_F {};
class H_Construction_basic_vrana_F : H_Construction_basic_black_F {};
class H_Construction_headset_vrana_F : H_Construction_basic_black_F {};

class H_Helmet_Skate : H_HeadBandage_clean_F {
	displayName = "滑板头盔（Skate Helmet）";
	price = 300;
	class Textures {};
};

class H_RacingHelmet_1_black_F : H_HeadBandage_clean_F {
	displayName = "赛车头盔（Racing Helmet）";
	price = 1500;
	isMask = true;
	class Textures {
		class H_RacingHelmet_1_black_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class H_RacingHelmet_1_white_F : H_RacingHelmet_1_black_F { displayName = "白色（White）"; };
		class H_RacingHelmet_1_red_F : H_RacingHelmet_1_black_F { displayName = "红色（Red）"; };
		class H_RacingHelmet_1_blue_F : H_RacingHelmet_1_black_F { displayName = "蓝色（Blue）"; };
		class H_RacingHelmet_1_green_F : H_RacingHelmet_1_black_F { displayName = "绿色（Green）"; };
		class H_RacingHelmet_1_orange_F : H_RacingHelmet_1_black_F { displayName = "橙色（Orange）"; };
		class H_RacingHelmet_1_yellow_F : H_RacingHelmet_1_black_F { displayName = "黄色（Yellow）"; };
		class H_RacingHelmet_4_F : H_RacingHelmet_1_black_F { 
			displayName = "Vrana";
			condition = "[] call ULP_fnc_donatorLevel >= 2"; 
		};
		class H_RacingHelmet_3_F : H_RacingHelmet_4_F { displayName = "Redstone"; };
		class H_RacingHelmet_2_F : H_RacingHelmet_4_F { displayName = "Bluking"; };
		class H_RacingHelmet_1_F : H_RacingHelmet_4_F { displayName = "Fuel"; };
	};
};
class H_RacingHelmet_1_white_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_1_red_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_1_blue_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_1_green_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_1_orange_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_1_yellow_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_4_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_3_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_2_F : H_RacingHelmet_1_black_F {};
class H_RacingHelmet_1_F : H_RacingHelmet_1_black_F {};

class H_PASGT_basic_black_F : H_HeadBandage_clean_F {
	displayName = "基础头盔（Basic Helmet）";
	price = 5000;
	reputation = true;
	class Textures {
		class H_PASGT_basic_black_F {
			displayName = "黑色（Black）";
			condition = "[""Police_COL"", 1] call ULP_fnc_hasAccess";
		};
		class H_PASGT_basic_blue_F : H_PASGT_basic_black_F { 
			displayName = "蓝色（Blue）";
			condition = "[""Police_NCA"", 1] call ULP_fnc_hasAccess";
		};
		class H_PASGT_basic_white_F : H_PASGT_basic_black_F { 
			displayName = "白色（White）";
			condition = "[""Police_MPU"", 1] call ULP_fnc_hasAccess";
		};
		class H_PASGT_basic_olive_F : H_PASGT_basic_black_F { 
			displayName = "橄榄色（Olive）";
			condition = "true";
		};
		class H_PASGT_basic_blue_press_F : H_PASGT_basic_black_F { displayName = "媒体（Press）"; };
		class H_PASGT_neckprot_blue_press_F : H_PASGT_basic_black_F { 
			displayName = "媒体护颈款（Press (Neck Protection)）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
	};
};
class H_PASGT_basic_blue_F : H_PASGT_basic_black_F {};
class H_PASGT_basic_white_F : H_PASGT_basic_black_F {};
class H_PASGT_basic_olive_F : H_PASGT_basic_black_F {};
class H_PASGT_basic_blue_press_F : H_PASGT_basic_black_F {};
class H_PASGT_neckprot_blue_press_F : H_PASGT_basic_black_F {};

class H_PilotHelmetHeli_B : H_HeadBandage_clean_F {
	displayName = "飞行头盔（Flight Helmet）";
	price = 35000;
	reputation = true;
	isMask = true;
	class Textures {
		class H_PilotHelmetHeli_B {
			displayName = "飞行员黑色款（Pilot (Black)）";
			condition = "true";
		};
		class H_PilotHelmetHeli_O : H_PilotHelmetHeli_B { displayName = "飞行员橄榄色款（Pilot (Olive)）"; };
		class H_PilotHelmetHeli_I : H_PilotHelmetHeli_B { displayName = "飞行员数码款（Pilot (Digi)）"; };
		class H_CrewHelmetHeli_B : H_PilotHelmetHeli_B { 
			displayName = "机组黑色款（Crew (Black)）";
			condition = "[] call ULP_fnc_donatorLevel >= 2 || { [player, [""Police""]] call ULP_fnc_isFaction }  || { [player, [""Medic""]] call ULP_fnc_isFaction }";
		};
		class H_CrewHelmetHeli_O : H_CrewHelmetHeli_B { displayName = "机组橄榄色款（Crew Olive)）"; };
		class H_CrewHelmetHeli_I : H_CrewHelmetHeli_B { displayName = "机组数码款（Crew (Digi)）"; };
	};
};
class H_PilotHelmetHeli_O : H_PilotHelmetHeli_B {};
class H_PilotHelmetHeli_I : H_PilotHelmetHeli_B {};
class H_CrewHelmetHeli_B : H_PilotHelmetHeli_B {};
class H_CrewHelmetHeli_O : H_PilotHelmetHeli_B {};
class H_CrewHelmetHeli_I : H_PilotHelmetHeli_B {};

class H_HelmetIA : H_HeadBandage_clean_F {
	displayName = "IA 战斗头盔（IA Combat Helmet）";
	price = 10000;
	reputation = true;
	class Textures {};
};

class H_HelmetB_light : H_HelmetIA {
	displayName = "轻型战斗头盔（Light Combat Helment）";
	price = 10000;
	reputation = true;
	class Textures {
		class H_HelmetB_light {
			displayName = "绿色（Green）";
			condition = "true";
		};
		class H_HelmetB_light_black : H_HelmetB_light { 
			displayName = "黑色（Black）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		class H_HelmetB_light_desert : H_HelmetB_light { displayName = "沙漠迷彩（Desert）"; };
		class H_HelmetB_light_sand : H_HelmetB_light { displayName = "沙色（Sand）"; };
		class H_HelmetB_light_snakeskin : H_HelmetB_light { displayName = "蛇纹迷彩（Snakeskin）"; };
		class H_HelmetB_light_grass : H_HelmetB_light { displayName = "草地迷彩（Grass）"; };
		class H_HelmetB_light_wdl : H_HelmetB_light { displayName = "林地迷彩（Woodland）"; };
	};
};
class H_HelmetB_light_black : H_HelmetB_light {};
class H_HelmetB_light_desert : H_HelmetB_light {};
class H_HelmetB_light_sand : H_HelmetB_light {};
class H_HelmetB_light_snakeskin : H_HelmetB_light{ };
class H_HelmetB_light_grass : H_HelmetB_light {};
class H_HelmetB_light_wdl : H_HelmetB_light {};

class H_HelmetB : H_HelmetB_light {
	displayName = "战斗头盔（Combat Helment）";
	price = 20000;
	class Textures {
		class H_HelmetB {
			displayName = "绿色（Green）";
			condition = "true";
		};
		class H_HelmetB_plain_blk : H_HelmetB { 
			displayName = "黑色（Black）";
			condition = "[] call ULP_fnc_donatorLevel >= 2 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class H_HelmetB_desert : H_HelmetB { displayName = "沙漠迷彩（Desert）"; };
		class H_HelmetB_sand : H_HelmetB { displayName = "沙色（Sand）"; };
		class H_HelmetB_snakeskin : H_HelmetB { displayName = "蛇纹迷彩（Snakeskin）"; };
		class H_HelmetB_grass : H_HelmetB { displayName = "草地迷彩（Grass）"; };
		class H_HelmetB_camo : H_HelmetB { displayName = "迷彩（Camo）"; };
		class H_HelmetB_paint : H_HelmetB { displayName = "喷漆款（Spraypaint）"; };
		class H_HelmetB_plain_wdl : H_HelmetB { displayName = "林地迷彩（Woodland）"; };
	};
};
class H_HelmetB_plain_blk : H_HelmetB {};
class H_HelmetB_desert : H_HelmetB {};
class H_HelmetB_sand : H_HelmetB {};
class H_HelmetB_snakeskin : H_HelmetB {};
class H_HelmetB_grass : H_HelmetB {};
class H_HelmetB_camo : H_HelmetB {};
class H_HelmetB_paint : H_HelmetB {};
class H_HelmetB_plain_wdl : H_HelmetB {};

class H_HelmetSpecB : H_HelmetB_light {
	displayName = "强化战斗头盔（Enhanced Combat Helment）";
	price = 50000;
	class Textures {
		class H_HelmetSpecB {
			displayName = "绿色（Green）";
			condition = "true";
		};
		class H_HelmetSpecB_blk : H_HelmetSpecB { 
			displayName = "黑色（Black）";
			condition = "[] call ULP_fnc_donatorLevel >= 2 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class H_HelmetSpecB_paint2 : H_HelmetSpecB { displayName = "沙漠迷彩（Desert）"; };
		class H_HelmetSpecB_sand : H_HelmetSpecB { displayName = "沙色（Sand）"; };
		class H_HelmetSpecB_snakeskin : H_HelmetSpecB { displayName = "蛇纹迷彩（Snakeskin）"; };
		class H_HelmetSpecB_paint1 : H_HelmetSpecB { displayName = "草地迷彩（Grass）"; };
		class H_HelmetSpecB_wdl : H_HelmetSpecB { displayName = "林地迷彩（Woodland）"; };
	};
};
class H_HelmetSpecB_blk : H_HelmetSpecB {};
class H_HelmetSpecB_paint2 : H_HelmetSpecB {};
class H_HelmetSpecB_sand : H_HelmetSpecB {};
class H_HelmetSpecB_snakeskin : H_HelmetSpecB {};
class H_HelmetSpecB_paint1 : H_HelmetSpecB {};
class H_HelmetSpecB_wdl : H_HelmetSpecB {};

class H_HelmetB_TI_arid_F : H_HelmetB_light {
	displayName = "隐匿战斗头盔（Stealth Combat Helment）";
	price = 75000;
	isMask = true;
	class Textures {
		class H_HelmetB_TI_arid_F {
			displayName = "干旱迷彩（Arid）";
			condition = "true";
		};
		class H_HelmetB_TI_tna_F : H_HelmetB_TI_arid_F { displayName = "绿色（Green）"; };
	};
};
class H_HelmetB_TI_tna_F : H_HelmetB_TI_arid_F {};

class H_HelmetHBK_F : H_HelmetB_light {
	displayName = "高级模块化头盔（Advanced Modular Helmet）";
	price = 25000;
	class Textures {
		class H_HelmetHBK_F {
			displayName = "橄榄色（Olive）";
			condition = "true";
		};
		class H_HelmetHBK_headset_F : H_HelmetHBK_F { displayName = "耳机款（Headset）"; };
		class H_HelmetHBK_ear_F : H_HelmetHBK_F { 
			displayName = "护耳款（Ear Protectors）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		class H_HelmetHBK_chops_F : H_HelmetHBK_ear_F { displayName = "护腮款（Chops）"; };
	};
};
class H_HelmetHBK_headset_F : H_HelmetHBK_F {};
class H_HelmetHBK_ear_F : H_HelmetHBK_F {};
class H_HelmetHBK_chops_F : H_HelmetHBK_F {};

class H_HelmetAggressor_F : H_HelmetB_light {
	displayName = "Aggressor 头盔（Avenger Helmet）";
	price = 50000;
	class Textures {
		class H_HelmetAggressor_F {
			displayName = "橄榄色（Olive）";
			condition = "true";
		};
		class H_HelmetAggressor_cover_F : H_HelmetAggressor_F { displayName = "覆盖款（Covered）"; };
		class H_HelmetAggressor_cover_taiga_F : H_HelmetAggressor_F { 
			displayName = "Taiga 迷彩（Taiga）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
	};
};
class H_HelmetAggressor_cover_F : H_HelmetAggressor_F {};
class H_HelmetAggressor_cover_taiga_F : H_HelmetAggressor_F {};
