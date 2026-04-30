class V_LegStrapBag_black_F {
	displayName = "腿挂包（Leg Strap）";
	price = 800;
	virtualSpace = 12;
	reputation = false;
	class Textures {
		class V_LegStrapBag_black_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class V_LegStrapBag_coyote_F : V_LegStrapBag_black_F { displayName = "郊狼色（Coyote）"; };
		class V_LegStrapBag_olive_F : V_LegStrapBag_black_F { displayName = "橄榄色（Olive）"; };
	};
};
class V_LegStrapBag_coyote_F : V_LegStrapBag_black_F {};
class V_LegStrapBag_olive_F : V_LegStrapBag_black_F {};

class V_Plain_medical_F : V_LegStrapBag_black_F {
	displayName = "识别背心（Identification Vest）";
	price = 50;
	virtualSpace = 0;
	class Textures {
		class V_Plain_medical_F {
			displayName = "IDAP";
			condition = "true";
		};
		class V_Plain_crystall_F : V_Plain_medical_F { displayName = "水晶（Crystal）"; };
	};
};
class V_Plain_crystall_F : V_Plain_medical_F {};

class V_Pocketed_black_F : V_LegStrapBag_black_F {
	displayName = "多口袋背心（Pocketed Vest）";
	price = 1000;
	virtualSpace = 14;
	class Textures {
		class V_Pocketed_black_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class V_Pocketed_coyote_F : V_Pocketed_black_F { displayName = "郊狼色（Coyote）"; };
		class V_Pocketed_olive_F : V_Pocketed_black_F { displayName = "橄榄色（Olive）"; };
	};
};
class V_Pocketed_coyote_F : V_Pocketed_black_F {};
class V_Pocketed_olive_F : V_Pocketed_black_F {};

class V_Safety_yellow_F : V_LegStrapBag_black_F {
	displayName = "安全背心（Safety Vest）";
	price = 250;
	virtualSpace = 3;
	class Textures {
		class V_Safety_yellow_F {
			displayName = "黄色（Yellow）";
			condition = "true";
		};
		class V_Safety_orange_F : V_Safety_yellow_F { displayName = "橙色（Orange）"; };
		class V_Safety_blue_F : V_Safety_orange_F { displayName = "蓝色（Blue）"; };
	};
};
class V_Safety_orange_F : V_Safety_yellow_F {};
class V_Safety_blue_F : V_Safety_yellow_F {};

class V_Press_F : V_LegStrapBag_black_F {
	price = 10000;
	virtualSpace = 11;
	class Textures {};
};

class V_RebreatherB : V_LegStrapBag_black_F {
	displayName = "呼吸器（Rebreather）";
	price = 15000;
	virtualSpace = 5;
	class Textures {
		class V_RebreatherB {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class V_RebreatherIR : V_RebreatherB { displayName = "棕色（Brown）"; };
		class V_RebreatherIA : V_RebreatherB { displayName = "绿色（Green）"; };
	};
};
class V_RebreatherIR : V_RebreatherB {};
class V_RebreatherIA : V_RebreatherB {};

class V_Rangemaster_belt : V_LegStrapBag_black_F {
	displayName = "弹药腰带（Ammo Belt）";
	price = 2000;
	virtualSpace = 6;
	class Textures {};
};

class V_BandollierB_blk : V_LegStrapBag_black_F {
	displayName = "斜挎弹带（Bandollier）";
	price = 2500;
	virtualSpace = 10;
	class Textures {
		class V_BandollierB_blk {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class V_BandollierB_cbr : V_BandollierB_blk { displayName = "郊狼色（Coyote）"; };
		class V_BandollierB_khk : V_BandollierB_blk { displayName = "卡其色（Khaki）"; };
		class V_BandollierB_oli : V_BandollierB_blk { displayName = "橄榄色（Olive）"; };
		class V_BandollierB_rgr : V_BandollierB_blk { displayName = "绿色（Green）"; };
	};
};
class V_BandollierB_cbr : V_BandollierB_blk {};
class V_BandollierB_khk : V_BandollierB_blk {};
class V_BandollierB_oli : V_BandollierB_blk {};
class V_BandollierB_rgr : V_BandollierB_blk {};

class V_HarnessO_brn : V_LegStrapBag_black_F {
	displayName = "战斗吊带（Combat Harness）";
	price = 3000;
	virtualSpace = 14;
	class Textures {
		class V_HarnessO_brn {
			displayName = "棕色（Brown）";
			condition = "true";
		};
		class V_HarnessO_gry : V_HarnessO_brn { displayName = "灰色（Gray）"; };
		class V_HarnessO_ghex_F : V_HarnessO_brn { displayName = "绿色六角迷彩（Green Hex）"; };
		class V_HarnessOGL_brn : V_HarnessO_brn { 
			displayName = "棕色榴弹型（Brown (GL)）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		class V_HarnessOGL_gry : V_HarnessO_brn { displayName = "灰色榴弹型（Gray (GL)）"; };
		class V_HarnessOGL_ghex_F : V_HarnessO_brn { displayName = "绿色六角迷彩榴弹型（Green Hex (GL)）"; };
	};
};
class V_HarnessO_gry : V_HarnessO_brn {};
class V_HarnessO_ghex_F : V_HarnessO_brn {};
class V_HarnessOGL_brn : V_HarnessO_brn {};
class V_HarnessOGL_gry : V_HarnessO_brn {};
class V_HarnessOGL_ghex_F : V_HarnessO_brn {};

class V_TacVestIR_blk : V_LegStrapBag_black_F {
	displayName = "Raven 背心（Raven Vest）";
	price = 5000;
	virtualSpace = 15;
	class Textures {};
};

class V_Chestrig_blk : V_LegStrapBag_black_F {
	displayName = "胸挂（Chest Rig）";
	price = 8000;
	virtualSpace = 16;
	class Textures {
		class V_Chestrig_blk {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class V_Chestrig_khk : V_Chestrig_blk { displayName = "卡其色（Khaki）"; };
		class V_Chestrig_oli : V_Chestrig_blk { displayName = "橄榄色（Olive）"; };
		class V_Chestrig_rgr : V_Chestrig_blk { displayName = "绿色（Green）"; };
	};
};
class V_Chestrig_khk : V_Chestrig_blk {};
class V_Chestrig_oli : V_Chestrig_blk {};
class V_Chestrig_rgr : V_Chestrig_blk {};

class V_TacChestrig_cbr_F : V_LegStrapBag_black_F {
	displayName = "战术胸挂（Tactical Rig）";
	price = 8500;
	virtualSpace = 18;
	class Textures {
		class V_TacChestrig_cbr_F {
			displayName = "郊狼色（Coyote）";
			condition = "true";
		};
		class V_TacChestrig_oli_F : V_TacChestrig_cbr_F { displayName = "橄榄色（Olive）"; };
		class V_TacChestrig_grn_F : V_TacChestrig_cbr_F { displayName = "绿色（Green）"; };
	};
};
class V_TacChestrig_oli_F : V_TacChestrig_cbr_F {};
class V_TacChestrig_grn_F : V_TacChestrig_cbr_F {};

class V_SmershVest_01_F : V_LegStrapBag_black_F {
	displayName = "Kipchak 背心（Kipchak Vest）";
	price = 9000;
	virtualSpace = 15;
	reputation = true;
	class Textures {
		class V_SmershVest_01_F {
			displayName = "默认款（Default）";
			condition = "true";
		};
		class V_SmershVest_01_radio_F : V_SmershVest_01_F { 
			displayName = "默认款（带无线电）（Default w/radio）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
	};
};
class V_SmershVest_01_radio_F : V_SmershVest_01_F {};

class V_DeckCrew_white_F : V_SmershVest_01_F {
	displayName = "甲板机组背心（Deck Crew Vest）";
	price = 17500;
	virtualSpace = 10;
	class Textures {
		class V_DeckCrew_white_F {
			displayName = "白色（White）";
			condition = "true";
		};
		class V_DeckCrew_blue_F : V_DeckCrew_white_F { 
			displayName = "蓝色（Blue）";
			condition = "[] call ULP_fnc_donatorLevel >= 2"; 
		};
		class V_DeckCrew_red_F : V_DeckCrew_blue_F { displayName = "红色（Red）"; };
		class V_DeckCrew_green_F : V_DeckCrew_blue_F { displayName = "绿色（Green）"; };
		class V_DeckCrew_yellow_F : V_DeckCrew_blue_F { displayName = "黄色（Yellow）"; };
		class V_DeckCrew_violet_F : V_DeckCrew_blue_F { displayName = "紫罗兰色（Violet）"; };
		class V_DeckCrew_brown_F : V_DeckCrew_blue_F { displayName = "棕色（Brown）"; };
	};
};
class V_DeckCrew_blue_F : V_DeckCrew_white_F {};
class V_DeckCrew_red_F : V_DeckCrew_white_F {};
class V_DeckCrew_green_F : V_DeckCrew_white_F {};
class V_DeckCrew_yellow_F : V_DeckCrew_white_F {};
class V_DeckCrew_violet_F : V_DeckCrew_white_F {};
class V_DeckCrew_brown_F : V_DeckCrew_white_F {};

class V_TacVest_blk : V_SmershVest_01_F {
	displayName = "战术背心（Tactical Vest）";
	price = 15000;
	virtualSpace = 20;
	class Textures {
		class V_TacVest_blk {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class V_TacVest_brn : V_TacVest_blk { displayName = "棕色（Brown）"; };
		class V_TacVest_khk : V_TacVest_blk { displayName = "卡其色（Khaki）"; };
		class V_TacVest_oli : V_TacVest_blk { displayName = "橄榄色（Olive）"; };
		class V_TacVest_camo : V_TacVest_blk { 
			displayName = "迷彩（Camo）";
			condition = "[] call ULP_fnc_donatorLevel >= 2"; 
		};
		class V_TacVest_blk_POLICE : V_TacVest_blk { 
			displayName = "Police"; 
			condition = "[player, [""Police""]] call ULP_fnc_isFaction";
		};
	};
};
class V_TacVest_blk_POLICE : V_TacVest_blk {};
class V_TacVest_camo : V_TacVest_blk {};
class V_TacVest_brn : V_TacVest_blk {};
class V_TacVest_khk : V_TacVest_blk {};
class V_TacVest_oli : V_TacVest_blk {};

class V_PlateCarrierIA1_dgtl : V_SmershVest_01_F {
	displayName = "GA 板甲背心（GA Plate Carrier）";
	price = 20000;
	virtualSpace = 13;
	class Textures {
		class V_PlateCarrierIA1_dgtl {
			displayName = "轻型（Light）";
			condition = "true";
		};
		class V_PlateCarrierIA2_dgtl : V_PlateCarrierIA1_dgtl { displayName = "重型（Heavy）"; };
	};
};
class V_PlateCarrierIA2_dgtl : V_PlateCarrierIA1_dgtl {};

class V_CarrierRigKBT_01_Olive_F : V_SmershVest_01_F {
	displayName = "模块化板甲背心（Modular Carrier Vest）";
	price = 18500;
	virtualSpace = 15;
	class Textures {
		class V_CarrierRigKBT_01_Olive_F {
			displayName = "橄榄色（Olive）";
			condition = "true";
		};
		class V_CarrierRigKBT_01_EAF_F : V_CarrierRigKBT_01_Olive_F { displayName = "几何纹（Geometric）"; };
	};
};
class V_CarrierRigKBT_01_EAF_F : V_CarrierRigKBT_01_Olive_F {};

class V_CarrierRigKBT_01_light_Olive_F : V_SmershVest_01_F {
	displayName = "模块化板甲挂具（Modular Carrier Rig）";
	price = 25000;
	virtualSpace = 17;
	class Textures {
		class V_CarrierRigKBT_01_light_Olive_F {
			displayName = "橄榄色（Olive）";
			condition = "true";
		};
		class V_CarrierRigKBT_01_light_EAF_F : V_CarrierRigKBT_01_light_Olive_F { displayName = "几何纹（Geometric）"; };
	};
};
class V_CarrierRigKBT_01_light_EAF_F : V_CarrierRigKBT_01_light_Olive_F {};

class V_PlateCarrier1_blk : V_SmershVest_01_F {
	displayName = "轻型板甲背心（Carrier Lite）";
	price = 45000;
	virtualSpace = 23;
	class Textures {
		class V_PlateCarrier1_blk {
			displayName = "黑色（Black）";
			condition = "[] call ULP_fnc_donatorLevel >= 2 || { [player, [""Police""]] call ULP_fnc_isFaction } || { [] call ULP_fnc_isProtection } || { [] call ULP_fnc_isSecurity }";
		};
		class V_PlateCarrier1_rgr : V_PlateCarrier1_blk { 
			displayName = "绿色（Green）";
			condition = "true";
		};
		class V_PlateCarrier1_rgr_noflag_F : V_PlateCarrier1_rgr { displayName = "绿色无旗版（Green (No Flag)）"; };
		class V_PlateCarrier1_wdl : V_PlateCarrier1_rgr { displayName = "林地迷彩（Woodland）"; };
		class V_PlateCarrier1_tna_F : V_PlateCarrier1_rgr { 
			displayName = "热带迷彩（Tropic）";
			condition = "[] call ULP_fnc_donatorLevel >= 2"; 
		};
		class V_PlateCarrierL_CTRG : V_PlateCarrier1_tna_F { displayName = "CTRG"; };
	};
};
class V_PlateCarrier1_rgr : V_PlateCarrier1_blk {};
class V_PlateCarrier1_rgr_noflag_F : V_PlateCarrier1_blk {};
class V_PlateCarrier1_wdl : V_PlateCarrier1_blk {};
class V_PlateCarrier1_tna_F : V_PlateCarrier1_blk {};
class V_PlateCarrierL_CTRG : V_PlateCarrier1_blk {};

class V_PlateCarrier2_blk : V_SmershVest_01_F {
	displayName = "板甲挂具（Carrier Rig）";
	price = 70000;
	virtualSpace = 25;
	class Textures {
		class V_PlateCarrier2_blk {
			displayName = "黑色（Black）";
			condition = "[] call ULP_fnc_donatorLevel >= 2 || { [player, [""Police""]] call ULP_fnc_isFaction }";
		};
		class V_PlateCarrier2_rgr : V_PlateCarrier2_blk { 
			displayName = "绿色（Green）";
			condition = "true";
		};
		class V_PlateCarrier2_rgr_noflag_F : V_PlateCarrier2_rgr { displayName = "绿色无旗版（Green (No Flag)）"; };
		class V_PlateCarrier2_wdl : V_PlateCarrier2_rgr { displayName = "林地迷彩（Woodland）"; };
		class V_PlateCarrier2_tna_F : V_PlateCarrier2_rgr { 
			displayName = "热带迷彩（Tropic）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";  
		};
		class V_PlateCarrierH_CTRG : V_PlateCarrier2_tna_F { displayName = "CTRG"; };
	};
};
class V_PlateCarrier2_rgr : V_PlateCarrier2_blk {};
class V_PlateCarrier2_rgr_noflag_F : V_PlateCarrier2_blk {};
class V_PlateCarrier2_wdl : V_PlateCarrier2_blk {};
class V_PlateCarrier2_tna_F : V_PlateCarrier2_blk {};
class V_PlateCarrierH_CTRG : V_PlateCarrier2_blk {};
