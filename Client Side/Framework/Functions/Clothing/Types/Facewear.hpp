class G_WirelessEarpiece_F {
	price = 10;
	reputation = false;
	isMask = false;
	isNV = false;
	isGas = false;
	class Textures {};
};

class G_Aviator : G_WirelessEarpiece_F {
	displayName = "飞行员墨镜（Aviator Glasses）";
	price = 10;
	class Textures {};
};

class G_Squares : G_WirelessEarpiece_F {
	displayName = "方框眼镜（Square Spectacles）";
	price = 10;
	class Textures {
		class G_Squares {
			displayName = "透明镜片（Clear）";
			condition = "true";
		};
		class G_Squares_Tinted : G_Squares { 
			displayName = "深色镜片（Tinted）";
			condition = "[] call ULP_fnc_donatorLevel >= 2"; 
		};
	};
};
class G_Squares_Tinted : G_Squares {};

class G_Spectacles : G_WirelessEarpiece_F {
	displayName = "圆框眼镜（Spectacle Glasses）";
	price = 10;
	class Textures {
		class G_Spectacles {
			displayName = "透明镜片（Clear）";
			condition = "true";
		};
		class G_Spectacles_Tinted : G_Spectacles { 
			displayName = "深色镜片（Tinted）";
			condition = "[] call ULP_fnc_donatorLevel >= 2"; 
		};
	};
};
class G_Spectacles_Tinted : G_Spectacles {};

class G_Shades_Black : G_WirelessEarpiece_F {
	displayName = "太阳镜（Shades）";
	price = 10;
	class Textures {
		class G_Shades_Black {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class G_Shades_Red : G_Shades_Black { displayName = "红色（Red）"; };
		class G_Shades_Green : G_Shades_Black { displayName = "绿色（Green）"; };
		class G_Shades_Blue : G_Shades_Black { displayName = "蓝色（Blue）"; };
	};
};
class G_Shades_Red : G_Shades_Black {};
class G_Shades_Green : G_Shades_Black {};
class G_Shades_Blue : G_Shades_Black {};

class G_Sport_Red : G_WirelessEarpiece_F {
	displayName = "运动墨镜（Sport Shades）";
	price = 10;
	class Textures {
		class G_Sport_Red {
			displayName = "红色（Red）";
			condition = "true";
		};
		class G_Sport_BlackWhite : G_Sport_Red { displayName = "黑白配色（Black-White）"; };
		class G_Sport_Blackred : G_Sport_Red { displayName = "黑红配色（Black-Red）"; };
		class G_Sport_Blackyellow : G_Sport_Red { displayName = "黑黄配色（Black-Yellow）"; };
		class G_Sport_Greenblack : G_Sport_Red { displayName = "绿黑配色（Green-Black）"; };
		class G_Sport_checkered : G_Sport_Red { displayName = "棋盘格（Checkered）"; };
	};
};
class G_Sport_BlackWhite : G_Sport_Red {};
class G_Sport_Blackred : G_Sport_Red {};
class G_Sport_Blackyellow : G_Sport_Red {};
class G_Sport_Greenblack : G_Sport_Red {};
class G_Sport_checkered : G_Sport_Red {};

class G_Lady_Blue : G_WirelessEarpiece_F {
	displayName = "女士墨镜（Ladies Shades）";
	price = 10;
	class Textures {};
};

class G_Lowprofile : G_WirelessEarpiece_F {
	displayName = "低轮廓护目镜（Low Profile Goggles）";
	price = 50;
	class Textures {};
};

class G_Combat : G_WirelessEarpiece_F {
	displayName = "战斗护目镜（Combat Goggles）";
	price = 100;
	class Textures {
		class G_Combat {
			displayName = "棕色（Brown）";
			condition = "true";
		};
		class G_Combat_Goggles_tna_F : G_Combat { displayName = "绿色（Green）"; };
	};
};
class G_Combat_Goggles_tna_F : G_Combat {};

class G_EyeProtectors_F : G_WirelessEarpiece_F {
	displayName = "护目镜（Eye Protectors）";
	price = 30;
	class Textures {
		class G_EyeProtectors_F {
			displayName = "护目镜（Eye Protectors）";
			condition = "true";
		};
		class G_EyeProtectors_Earpiece_F : G_EyeProtectors_F { displayName = "护目镜+耳机（Eye Protectors + Earpiece）"; };
	};
};
class G_EyeProtectors_Earpiece_F : G_EyeProtectors_F{};

class G_B_Diving : G_WirelessEarpiece_F {
	displayName = "潜水护目镜（Diving Goggles）";
	price = 1500;
	class Textures {
		class G_B_Diving {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class G_O_Diving : G_B_Diving { displayName = "棕色（Brown）"; };
		class G_I_Diving : G_B_Diving { displayName = "绿色（Green）"; };
	};
};
class G_O_Diving : G_B_Diving {};
class G_I_Diving : G_B_Diving {};

class G_Respirator_white_F : G_WirelessEarpiece_F {
	displayName = "口罩（COVID Mask）";
	price = 5;
	isMask = true;
	class Textures {
		class G_Respirator_white_F {
			displayName = "白色（White）";
			condition = "true";
		};
		class G_Respirator_blue_F : G_Respirator_white_F { displayName = "蓝色（Blue）"; };
		class G_Respirator_yellow_F : G_Respirator_white_F { displayName = "黄色（Yellow）"; };
	};
};
class G_Respirator_blue_F : G_Respirator_white_F {};
class G_Respirator_yellow_F : G_Respirator_white_F {};

class G_RegulatorMask_F : G_WirelessEarpiece_F {
	displayName = "调节器面罩（Regulator Mask）";
	price = 10000;
	reputation = true;
	isMask = true;
	isGas = true;
	class Textures {};
};

class G_AirPurifyingRespirator_01_F : G_RegulatorMask_F {
	displayName = "空气净化呼吸器（Air Purifying Respirator）";
	price = 12500;
	reputation = true;
	isNV = true;
	class Textures {
		class G_AirPurifyingRespirator_01_F {
			displayName = "黑色旧款（Black (Old)）";
			condition = "true";
		};
		class G_AirPurifyingRespirator_02_black_F : G_AirPurifyingRespirator_01_F { 
			displayName = "黑色（Black）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		class G_AirPurifyingRespirator_02_olive_F : G_AirPurifyingRespirator_02_black_F { displayName = "橄榄色（Olive）"; };
		class G_AirPurifyingRespirator_02_sand_F : G_AirPurifyingRespirator_02_black_F { displayName = "沙色（Sand）"; };
	};
};
class G_AirPurifyingRespirator_02_black_F : G_AirPurifyingRespirator_01_F {};
class G_AirPurifyingRespirator_02_olive_F : G_AirPurifyingRespirator_01_F {};
class G_AirPurifyingRespirator_02_sand_F : G_AirPurifyingRespirator_01_F {};

class G_Blindfold_01_black_F : G_WirelessEarpiece_F {
	displayName = "眼罩（Blindfold）";
	price = 5;
	class Textures {
		class G_Blindfold_01_black_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class G_Blindfold_01_white_F : G_Blindfold_01_black_F { displayName = "白色（White）"; };
	};
};
class G_Blindfold_01_white_F : G_Blindfold_01_black_F {};

class G_Bandanna_aviator : G_WirelessEarpiece_F {
	displayName = "面罩头巾（Bandanna）";
	price = 1500;
	reputation = true;
	isMask = true;
	class Textures {
		class G_Bandanna_aviator {
			displayName = "黑色+飞行员墨镜（Black + Aviators）";
			condition = "true";
		};
		class G_Bandanna_shades : G_Bandanna_aviator { displayName = "黑色+太阳镜（Black + Shades）"; };
		class G_Bandanna_sport : G_Bandanna_aviator { displayName = "黑色+运动镜（Black + Sport）"; };
		class G_Bandanna_blk : G_Bandanna_aviator { displayName = "黑色（Black）"; };
		class G_Bandanna_khk : G_Bandanna_aviator { displayName = "卡其色（Khaki）"; };
		class G_Bandanna_oli : G_Bandanna_aviator { displayName = "橄榄色（Olive）"; };
		class G_Bandanna_beast : G_Bandanna_aviator { 
			displayName = "野兽款（Beast）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";  
		};
		class G_Bandanna_BlueFlame1 : G_Bandanna_beast { displayName = "蓝焰（Blue Flame）"; };
		class G_Bandanna_BlueFlame2 : G_Bandanna_beast { displayName = "蓝色火焰（Blue Flames）"; };
		class G_Bandanna_CandySkull : G_Bandanna_beast { displayName = "糖果骷髅（Candy Skull）"; };
		class G_Bandanna_OrangeFlame1 : G_Bandanna_beast { displayName = "橙色火焰（Orange Flames）"; };
		class G_Bandanna_RedFlame1 : G_Bandanna_beast { displayName = "红色火焰（Red Flames）"; };
		class G_Bandanna_Skull1 : G_Bandanna_beast { displayName = "骷髅（Skull）"; };
		class G_Bandanna_Skull2 : G_Bandanna_beast { displayName = "装饰骷髅（Skull (Ornamental)）"; };
		class G_Bandanna_Syndikat1 : G_Bandanna_beast { displayName = "Syndikat"; };
		class G_Bandanna_Syndikat2 : G_Bandanna_beast { displayName = "Syndikat"; };
		class G_Bandanna_Vampire_01 : G_Bandanna_beast { displayName = "吸血鬼（Vampire）"; };
	};
};
class G_Bandanna_shades : G_Bandanna_aviator {};
class G_Bandanna_sport : G_Bandanna_aviator {};
class G_Bandanna_beast : G_Bandanna_aviator {};
class G_Bandanna_blk : G_Bandanna_aviator {};
class G_Bandanna_khk : G_Bandanna_aviator {};
class G_Bandanna_oli : G_Bandanna_aviator {};
class G_Bandanna_BlueFlame1 : G_Bandanna_aviator {};
class G_Bandanna_BlueFlame2 : G_Bandanna_aviator {};
class G_Bandanna_CandySkull : G_Bandanna_aviator {};
class G_Bandanna_OrangeFlame1 : G_Bandanna_aviator {};
class G_Bandanna_RedFlame1 : G_Bandanna_aviator {};
class G_Bandanna_Skull1 : G_Bandanna_aviator {};
class G_Bandanna_Skull2 : G_Bandanna_aviator {};
class G_Bandanna_Syndikat1 : G_Bandanna_aviator {};
class G_Bandanna_Syndikat2 : G_Bandanna_aviator {};
class G_Bandanna_Vampire_01 : G_Bandanna_aviator {};

class G_Balaclava_blk : G_Bandanna_aviator {
	displayName = "巴拉克拉法帽（Balaclava）";
	price = 2500;
	class Textures {
		class G_Balaclava_blk {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class G_Balaclava_lowprofile : G_Balaclava_blk { displayName = "黑色+低轮廓护目镜（Black + Lowprofile Goggles）"; };
		class G_Balaclava_combat : G_Balaclava_blk { displayName = "黑色+战斗护目镜（Black + Combat Goggles）"; };
		class G_Balaclava_oli : G_Balaclava_blk { displayName = "橄榄色（Olive）"; };
		class G_Balaclava_BlueStrips : G_Balaclava_blk { 
			displayName = "蓝条纹（Blue Stripe）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		class G_Balaclava_Flecktarn : G_Balaclava_BlueStrips { displayName = "Flecktarn 迷彩（Flecktarn）"; };
		class G_Balaclava_Halloween_01 : G_Balaclava_BlueStrips { displayName = "万圣节款（Halloween）"; };
		class G_Balaclava_Flames1 : G_Balaclava_BlueStrips { displayName = "橙色纹样（Orange Pattern）"; };
		class G_Balaclava_Scarecrow_01 : G_Balaclava_BlueStrips { displayName = "稻草人（Scarecrow）"; };
		class G_Balaclava_Skull1 : G_Balaclava_BlueStrips { displayName = "骷髅（Skull）"; };
		class G_Balaclava_Tropentarn : G_Balaclava_BlueStrips { displayName = "Tropentarn 迷彩（Tropentarn）"; };
	};
};
class G_Balaclava_lowprofile : G_Balaclava_blk {};
class G_Balaclava_combat : G_Balaclava_blk {};
class G_Balaclava_oli : G_Balaclava_blk {};
class G_Balaclava_BlueStrips : G_Balaclava_blk {};
class G_Balaclava_Flecktarn : G_Balaclava_blk {};
class G_Balaclava_Halloween_01 : G_Balaclava_blk {};
class G_Balaclava_Flames1 : G_Balaclava_blk {};
class G_Balaclava_Scarecrow_01 : G_Balaclava_blk {};
class G_Balaclava_Skull1 : G_Balaclava_blk {};
class G_Balaclava_Tropentarn : G_Balaclava_blk {};

class G_Balaclava_TI_blk_F : G_Bandanna_aviator {
	displayName = "隐匿巴拉克拉法帽（Stealth Balaclava）";
	price = 15000;
	class Textures {
		class G_Balaclava_TI_blk_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class G_Balaclava_TI_tna_F : G_Balaclava_TI_blk_F { displayName = "绿色（Green）"; };
	};
};
class G_Balaclava_TI_tna_F : G_Balaclava_TI_blk_F {};

class G_Balaclava_TI_G_blk_F : G_Bandanna_aviator {
	displayName = "隐匿巴拉克拉法帽（夜视）（Stealth Balaclava (NVG)）";
	price = 35000;
	isNV = true;
	class Textures {
		class G_Balaclava_TI_G_blk_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class G_Balaclava_TI_G_tna_F : G_Balaclava_TI_G_blk_F { displayName = "绿色（Green）"; };
	};
};
class G_Balaclava_TI_G_tna_F : G_Balaclava_TI_G_blk_F {};

class G_Tactical_Clear : G_WirelessEarpiece_F {
	displayName = "战术眼镜夜视款（Tactical Glasses NVG）";
	price = 20000;
	reputation = true;
	isNV = true;
	class Textures {
		class G_Tactical_Clear {
			displayName = "透明镜片（Clear）";
			condition = "true";
		};
		class G_Tactical_Black : G_Tactical_Clear { 
			displayName = "黑色（Black）";
			condition = "[] call ULP_fnc_donatorLevel >= 2"; 
		};
	};
};
class G_Tactical_Black : G_Tactical_Clear {};

class G_Goggles_VR {
	displayName = "员工护目镜（Staff Goggles）";
	price = 1000000;
	reputation = false;
	isMask = false;
	isNV = true;
	isGas = true;
	class Textures {};
};
