class U_C_Poor_1 {
	price = 50;
	virtualSpace = 2;
	reputation = false;
	isGas = false;
	class Textures {};
};
class U_C_Farmer : U_C_Poor_1 {};
class U_C_Mechanic_01_F : U_C_Poor_1 {};

class U_C_Poloshirt_blue : U_C_Poor_1 {
	displayName = "平民服装（Commoner Clothes）";
	price = 100;
	class Textures {
		class U_C_Poloshirt_blue { 
			displayName = "蓝色（Blue）";
			condition = "true";
		};
		class U_C_Poloshirt_burgundy : U_C_Poloshirt_blue { displayName = "酒红色（Burgundy）"; };
		class U_C_Poloshirt_stripped : U_C_Poloshirt_blue { displayName = "条纹款（Stripped）"; };
		class U_C_Poloshirt_tricolour : U_C_Poloshirt_blue { displayName = "三色款（Tricolor）"; };
		class U_C_Poloshirt_salmon : U_C_Poloshirt_blue { displayName = "鲑红色（Salmon）"; };
		class U_C_Poloshirt_redwhite : U_C_Poloshirt_blue { displayName = "红白配色（Redwhite）"; };
	};
};
class U_C_Poloshirt_burgundy : U_C_Poloshirt_blue {};
class U_C_Poloshirt_stripped : U_C_Poloshirt_blue {};
class U_C_Poloshirt_tricolour : U_C_Poloshirt_blue {};
class U_C_Poloshirt_salmon : U_C_Poloshirt_blue {};
class U_C_Poloshirt_redwhite : U_C_Poloshirt_blue {};

class U_C_WorkerOveralls : U_C_Poor_1 {
	displayName = "工人连体服（Worker Overalls）";
	price = 150;
	virtualSpace = 4;
	class Textures {
		class U_C_WorkerOveralls { 
			displayName = "旧款（Used）";
			condition = "true";
		};
		class White : U_C_WorkerOveralls { 
			displayName = "白色（White）";
			textures[] = { "\A3\characters_f\common\data\coveralls_grey_co.paa" };
		};
		class Gray : U_C_WorkerOveralls { 
			displayName = "灰色（Gray）";
			textures[] = { "\A3\characters_f\common\data\coveralls_black_co.paa" };
		};
		class Rust : U_C_WorkerOveralls { 
			displayName = "锈色（Rust）";
			textures[] = { "\A3\characters_f\common\data\coveralls_bandit_co.paa" };
		};
		class Camo : U_C_WorkerOveralls { 
			displayName = "迷彩（Camo）";
			textures[] = { "\A3\characters_f\common\data\coveralls_urbancamo_co.paa" };
		};
	};
};

class U_C_ConstructionCoverall_Black_F : U_C_WorkerOveralls {
	displayName = "施工连体服（Construction Overalls）";
	class Textures {
		class U_C_ConstructionCoverall_Black_F { 
			displayName = "黑色（Black）";
			condition = "true";
		};
		class U_C_ConstructionCoverall_Red_F : U_C_ConstructionCoverall_Black_F { displayName = "红色（Red）"; };
		class U_C_ConstructionCoverall_Blue_F : U_C_ConstructionCoverall_Black_F { displayName = "蓝色（Blue）"; };
		class U_C_ConstructionCoverall_Vrana_F : U_C_ConstructionCoverall_Black_F { 
			displayName = "Vrana"; 
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
	};
};
class U_C_ConstructionCoverall_Red_F : U_C_WorkerOveralls {};
class U_C_ConstructionCoverall_Blue_F : U_C_WorkerOveralls {};
class U_C_ConstructionCoverall_Vrana_F : U_C_WorkerOveralls {};

class U_C_Man_casual_1_F : U_C_Poor_1 {
	displayName = "休闲服（Casual Clothes）";
	price = 100;
	class Textures {
		class U_C_Man_casual_1_F { 
			displayName = "海军蓝（Navy）";
			condition = "true";
		};
		class U_C_Man_casual_2_F : U_C_Man_casual_1_F { displayName = "蓝色（Blue）"; };
		class U_C_Man_casual_3_F : U_C_Man_casual_1_F { displayName = "绿色（Green）"; };
		class Brown : U_C_Man_casual_1_F { 
			displayName = "棕色（Brown）";
			textures[] = { "A3\Characters_F\Civil\Data\ig_poloshirt_2_co.paa" };
		};
		class Gray : U_C_Man_casual_1_F { 
			displayName = "灰色（Gray）";
			textures[] = { "A3\Characters_F\Civil\Data\ig_poloshirt_1_co.paa" };
		};
	};
};
class U_C_Man_casual_2_F : U_C_Man_casual_1_F{};
class U_C_Man_casual_3_F : U_C_Man_casual_1_F{};

class U_C_ArtTShirt_01_v1_F : U_C_Poor_1 {
	displayName = "休闲 T 恤（Casual T-Shirts）";
	price = 100;
	class Textures {
		class U_C_ArtTShirt_01_v1_F { 
			displayName = "战争艺术（Art of War）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		class U_C_ArtTShirt_01_v2_F : U_C_ArtTShirt_01_v1_F { displayName = "无人机（Drones）"; };
		class U_C_ArtTShirt_01_v3_F : U_C_ArtTShirt_01_v1_F { displayName = "Waltham Robotics"; };
		class U_C_ArtTShirt_01_v4_F : U_C_ArtTShirt_01_v1_F { displayName = "展览款（Exhibition）"; };
		class U_C_ArtTShirt_01_v5_F : U_C_ArtTShirt_01_v1_F { displayName = "Robogeddon"; };
		class U_C_ArtTShirt_01_v6_F : U_C_ArtTShirt_01_v1_F { displayName = "抽象款（Abstract）"; };
	};
};
class U_C_ArtTShirt_01_v2_F : U_C_ArtTShirt_01_v1_F{};
class U_C_ArtTShirt_01_v3_F : U_C_ArtTShirt_01_v1_F{};
class U_C_ArtTShirt_01_v4_F : U_C_ArtTShirt_01_v1_F{};
class U_C_ArtTShirt_01_v5_F : U_C_ArtTShirt_01_v1_F{};
class U_C_ArtTShirt_01_v6_F : U_C_ArtTShirt_01_v1_F{};

class U_C_Man_casual_6_F : U_C_Poor_1 {
	displayName = "夏装（Summer Clothes）";
	price = 100;
	class Textures {
		class U_C_Man_casual_6_F { 
			displayName = "红色（Red）";
			condition = "true";
		};
		class U_C_Man_casual_5_F : U_C_Man_casual_6_F { displayName = "黄色（Yellow）"; };
		class U_C_Man_casual_4_F : U_C_Man_casual_6_F { displayName = "天蓝色（Sky）"; };
	};
};
class U_C_Man_casual_5_F : U_C_Man_casual_6_F{};
class U_C_Man_casual_4_F : U_C_Man_casual_6_F{};

class U_C_man_sport_1_F : U_C_Poor_1 {
	displayName = "运动服（Sport Clothes）";
	price = 100;
	class Textures {
		class U_C_man_sport_1_F { 
			displayName = "海滩款（Beach）";
			condition = "true";
		};
		class U_C_man_sport_2_F : U_C_man_sport_1_F { displayName = "橙色（Orange）"; };
		class U_C_man_sport_3_F : U_C_man_sport_1_F { displayName = "蓝色（Blue）"; };
	};
};
class U_C_man_sport_2_F : U_C_man_sport_1_F{};
class U_C_man_sport_3_F : U_C_man_sport_1_F{};

class U_C_Scientist : U_C_Poor_1 {
	displayName = "科学家服装（Scientist Clothes）";
	price = 100;
	class Textures {
		class U_C_Scientist { 
			displayName = "白色连体服（White Overalls）";
			condition = "true";
		};
		class U_C_Uniform_Scientist_01_F : U_C_Scientist { displayName = "白色（White）"; };
		class U_C_Uniform_Scientist_01_formal_F : U_C_Scientist { displayName = "蓝色（Blue）"; };
		class U_C_Uniform_Scientist_02_F : U_C_Scientist { displayName = "黑色（Black）"; };
		class U_C_Uniform_Scientist_02_formal_F : U_C_Scientist { displayName = "红色（Red）"; };
	};
};
class U_C_Uniform_Scientist_01_F : U_C_Scientist{};
class U_C_Uniform_Scientist_01_formal_F : U_C_Scientist{};
class U_C_Uniform_Scientist_02_F : U_C_Scientist{};
class U_C_Uniform_Scientist_02_formal_F : U_C_Scientist{};

class U_I_C_Soldier_Bandit_1_F : U_C_Poor_1 {
	displayName = "匪徒服装（Bandit Clothes）";
	price = 150;
	virtualSpace = 4;
	class Textures {
		class U_I_C_Soldier_Bandit_1_F { 
			displayName = "Polo 衫（Polo Shirt）";
			condition = "true";
		};
		class U_I_C_Soldier_Bandit_2_F : U_I_C_Soldier_Bandit_1_F { displayName = "骷髅款（Skull）"; };
		class U_I_C_Soldier_Bandit_4_F : U_I_C_Soldier_Bandit_1_F { displayName = "棋盘格（Checkered）"; };
		class U_I_C_Soldier_Bandit_5_F : U_I_C_Soldier_Bandit_1_F { displayName = "背心款（Tank Top）"; };
	};
};
class U_I_C_Soldier_Bandit_2_F : U_I_C_Soldier_Bandit_1_F{};
class U_I_C_Soldier_Bandit_4_F : U_I_C_Soldier_Bandit_1_F{};
class U_I_C_Soldier_Bandit_5_F : U_I_C_Soldier_Bandit_1_F{};

class U_I_C_Soldier_Bandit_3_F : U_C_Poor_1 { 
	displayName = "休闲套装（Casual Outfit）";
	price = 150;
	virtualSpace = 4;
	class Textures {
		class U_I_C_Soldier_Bandit_3_F { 
			displayName = "棕色（Brown）";
			condition = "true";
		};
		class Black : U_I_C_Soldier_Bandit_3_F { 
			displayName = "黑色（Black）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";  
			textures[] = { "\A3\Characters_F_exp\Syndikat\Data\U_I_C_Soldier_Bandit_2_F_2_co.paa" };
		};
		class Red : Black { 
			displayName = "红色（Red）";
			textures[] = { "\A3\Characters_F_exp\Civil\Data\U_C_Man_casual_6_F_1_co.paa" };
		};
		class Blue : Black { 
			displayName = "蓝色（Blue）";
			textures[] = { "\A3\Characters_F_exp\Civil\Data\U_C_Man_casual_4_F_1_co.paa" };
		};
		class Yellow : Black { 
			displayName = "黄色（Yellow）";
			textures[] = { "\A3\Characters_F_exp\Civil\Data\U_C_Man_casual_5_F_1_co.paa" };
		};
	};
};

class U_IG_Guerilla1_1 : U_C_Poor_1 {
	displayName = "游击服装（Guerilla Clothes）";
	price = 150;
	virtualSpace = 4;
	class Textures {
		class U_IG_Guerilla1_1 { 
			displayName = "棕色外衣（Garment (Brown)）";
			condition = "true";
		};
		class U_IG_Guerilla1_2_F : U_IG_Guerilla1_1 { displayName = "橄榄色外衣（Garment (Olive)）"; };
		class U_IG_Guerilla2_1 : U_IG_Guerilla1_1 { displayName = "纯色深款（Plain, Dark）"; };
		class U_IG_Guerilla2_2 : U_IG_Guerilla1_1 { displayName = "花纹款（Pattern）"; };
		class U_IG_Guerilla2_3 : U_IG_Guerilla1_1 { displayName = "纯色浅款（Plain, Light）"; };
		class U_IG_Guerilla3_1 : U_IG_Guerilla1_1 { displayName = "罩衫深款（Smocks (Dark)）"; };
		class U_IG_Guerilla3_2 : U_IG_Guerilla1_1 { displayName = "罩衫浅款（Smocks (Light)）"; };
		class Blackwing : U_IG_Guerilla1_1 {
			displayName = "Blackwing";
			textures[] = { "\a3\characters_f_gamma\Civil\Data\c_cloth1_black.paa" };
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		class Black : Blackwing {
			displayName = "黑色（Black）";
			textures[] = { "\a3\characters_f_gamma\Civil\Data\c_cloth1_black.paa" };
		};
		class Red : Blackwing {
			displayName = "红色（Red）";
			textures[] = { "A3\Characters_F\Civil\Data\c_cloth1_bandit_co.paa" };
		};
		class Blue : Blackwing {
			displayName = "蓝色（Blue）";
			textures[] = { "A3\Characters_F\Civil\Data\c_cloth1_co.paa" };
		};
		class Orange : Blackwing {
			displayName = "橙色（Orange）";
			textures[] = { "A3\Characters_F\Civil\Data\c_cloth1_v3_co.paa" };
		};
		class Yellow : Blackwing {
			displayName = "黄色（Yellow）";
			textures[] = { "A3\Characters_F\Civil\Data\c_cloth1_v2_co.paa" };
		};
		class Brown : Blackwing {
			displayName = "棕色（Brown）";
			textures[] = { "\a3\characters_f_gamma\Civil\Data\c_cloth1_brown.paa" };
		};
		class U_IG_leader : U_IG_Guerilla1_1 { displayName = "制服款（Uniform）"; };
	};
};
class U_IG_Guerilla1_2_F : U_IG_Guerilla1_1 {};
class U_IG_Guerilla2_1 : U_IG_Guerilla1_1 {
	class Textures {
		class U_IG_Guerilla2_1 { 
			displayName = "纯色深款（Plain, Dark）";
			condition = "true";
		};
		// class DMS : U_IG_Guerilla2_1 {
		// 	displayName = "Dunamis";
		// 	textures[] = { "Data\Textures\Groups\DMS\Uniforms\2.paa" };
		// 	condition = "[] call ULP_fnc_isDunamis";
		// };
	};
};
class U_IG_Guerilla2_2 : U_IG_Guerilla1_1 {};
class U_IG_Guerilla2_3 : U_IG_Guerilla1_1 {};
class U_IG_Guerilla3_1 : U_IG_Guerilla1_1 {};
class U_IG_Guerilla3_2 : U_IG_Guerilla1_1 {};
class U_IG_leader : U_IG_Guerilla1_1 {};

class U_C_HunterBody_grn : U_C_Poor_1 {
	displayName = "狩猎服（Hunting Clothes）";
	price = 200;
	virtualSpace = 4;
	class Textures {};
};

class U_C_E_LooterJacket_01_F : U_C_Poor_1 {
	displayName = "拾荒者服装（Looter Clothes）";
	price = 150;
	class Textures {
		class U_C_E_LooterJacket_01_F { 
			displayName = "皮夹克（Leather Jacket）";
			condition = "true";
		};
		class U_I_L_Uniform_01_tshirt_black_F : U_C_E_LooterJacket_01_F { displayName = "黑色 T 恤款（T-Shirt, Black）"; };
		class U_I_L_Uniform_01_tshirt_sport_F : U_C_E_LooterJacket_01_F { displayName = "运动 T 恤款（T-Shirt, Sport）"; };
		class U_I_L_Uniform_01_tshirt_olive_F : U_C_E_LooterJacket_01_F { displayName = "橄榄色 T 恤款（T-Shirt, Olive）"; };
		class U_I_L_Uniform_01_tshirt_skull_F : U_C_E_LooterJacket_01_F { 
			displayName = "骷髅 T 恤款（T-Shirt, Skull）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
	};
};
class U_I_L_Uniform_01_tshirt_skull_F : U_C_E_LooterJacket_01_F {};
class U_I_L_Uniform_01_tshirt_black_F : U_C_E_LooterJacket_01_F {};
class U_I_L_Uniform_01_tshirt_sport_F : U_C_E_LooterJacket_01_F {};
class U_I_L_Uniform_01_tshirt_olive_F : U_C_E_LooterJacket_01_F {};

class U_O_R_Gorka_01_black_F : U_C_Poor_1 {
	displayName = "运动套装（Tracksuit）";
	price = 25000;
	reputation = true;
	virtualSpace = 8;
	class Textures {
		// Police
		class RPU {
			displayName = "RPU";
			textures[] = { "Data\Textures\Uniforms\Police\Units\RPU_tracksuit.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_RPU"", 2] call ULP_fnc_hasAccess }";
		};
		class NCA {
			displayName = "NCA";
			textures[] = { "Data\Textures\Uniforms\Police\Units\NCA_tracksuit.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
		};

		// Medic
		class Paramedic {
			displayName = "护理员（Paramedic）";
			textures[] = { "Data\Textures\Uniforms\Medic\tracksuit.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_HART"", 1] call ULP_fnc_hasAccess || { [""Medic_Main"", 2] call ULP_fnc_hasAccess } }";
		};
		class Doctor {
			displayName = "医疗顾问（Medical Advisor）";
			textures[] = { "Data\Textures\Uniforms\Medic\tracksuit.paa" }; // TODO
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_HART"", 1] call ULP_fnc_hasAccess || { [""Medic_Main"", 4] call ULP_fnc_hasAccess } }";
		};
		class Commander {
			displayName = "事件指挥官（Incident Commander）";
			textures[] = { "Data\Textures\Uniforms\Medic\tracksuit.paa" }; // TODO
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_HART"", 1] call ULP_fnc_hasAccess || { [""Medic_Main"", 5] call ULP_fnc_hasAccess } }";
		};

		// Highways
		class Hato {
			displayName = "交通执勤员（Traffic Officer）";
			textures[] = { "Data\Textures\Uniforms\Hato\tracksuit.paa" };
			condition = "[player, [""Hato""]] call ULP_fnc_isFaction";
		};

		// Civilian
		class U_O_R_Gorka_01_black_F {
			displayName = "黑色（Black）";
			condition = "true";
		};
		class U_O_R_Gorka_01_brown_F : U_O_R_Gorka_01_black_F { displayName = "棕色（Brown）"; };
		class U_O_R_Gorka_01_camo_F : U_O_R_Gorka_01_black_F { displayName = "迷彩（Camo）"; };

		// Groups
		class Sentinel : U_O_R_Gorka_01_black_F {
			displayName = "Sentinel";
			textures[] = { "Data\Textures\Groups\Sentinel\U_B_CTRG_Soldier_F.paa" };
			condition = "[3] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_O_R_Gorka_01_brown_F : U_O_R_Gorka_01_black_F {};
class U_O_R_Gorka_01_camo_F : U_O_R_Gorka_01_black_F {};

class U_I_C_Soldier_Para_1_F : U_O_R_Gorka_01_black_F {
	displayName = "准军事服装（Paramilitary Clothes）";
	price = 150;
	class Textures {
		class U_I_C_Soldier_Para_1_F { 
			displayName = "T 恤款（Tee）";
			condition = "true";
		};
		class U_I_C_Soldier_Para_2_F : U_I_C_Soldier_Para_1_F { displayName = "夹克款（Jacket）"; };
		class U_I_C_Soldier_Para_3_F : U_I_C_Soldier_Para_1_F { displayName = "衬衫款（Shirt）"; };
		class U_I_C_Soldier_Para_4_F : U_I_C_Soldier_Para_1_F { displayName = "背心款（Tank Top）"; };
		class U_I_C_Soldier_Para_5_F : U_I_C_Soldier_Para_1_F { 
			displayName = "短裤款（Shorts）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		// class DMS1 : U_I_C_Soldier_Para_1_F {
		// 	displayName = "Dunamis SGT";
		// 	textures[] = { 
		// 		"Data\Textures\Groups\DMS\Uniforms\3_1.paa", 
		// 		"Data\Textures\Groups\DMS\Uniforms\3_2.paa"
		// 	};
		// 	condition = "[] call ULP_fnc_isDunamis && { [""Dunamis_Main"", 3] call ULP_fnc_hasAccess }";
		// };
		// class DMS2 : U_I_C_Soldier_Para_1_F {
		// 	displayName = "Dunamis SSGT";
		// 	textures[] = { 
		// 		"Data\Textures\Groups\DMS\Uniforms\4_1.paa", 
		// 		"Data\Textures\Groups\DMS\Uniforms\3_2.paa"
		// 	};
		// 	condition = "[] call ULP_fnc_isDunamis && { [""Dunamis_Main"", 4] call ULP_fnc_hasAccess }";
		// };
	};
};
class U_I_C_Soldier_Para_2_F : U_I_C_Soldier_Para_1_F {
	class Textures {
		class U_I_C_Soldier_Para_2_F { 
			displayName = "夹克款（Jacket）";
			condition = "true";
		};
		// class DMS : U_I_C_Soldier_Para_2_F {
		// 	displayName = "Dunamis";
		// 	textures[] = { 
		// 		"Data\Textures\Groups\DMS\Uniforms\5_1.paa", 
		// 		"Data\Textures\Groups\DMS\Uniforms\4_1.paa"
		// 	};
		// 	condition = "[] call ULP_fnc_isDunamis";
		// };
	};
};
class U_I_C_Soldier_Para_3_F : U_I_C_Soldier_Para_1_F {};
class U_I_C_Soldier_Para_4_F : U_I_C_Soldier_Para_1_F {
	class Textures {
		class U_I_C_Soldier_Para_4_F { 
			displayName = "背心款（Tank Top）";
			condition = "true";
		};
		// class DMS : U_I_C_Soldier_Para_4_F {
		// 	displayName = "Dunamis";
		// 	textures[] = { 
		// 		"Data\Textures\Groups\DMS\Uniforms\1_1.paa", 
		// 		"Data\Textures\Groups\DMS\Uniforms\1_2.paa"
		// 	};
		// 	condition = "[] call ULP_fnc_isDunamis";
		// };
	};
};
class U_I_C_Soldier_Para_5_F : U_I_C_Soldier_Para_1_F {};

class U_I_E_Uniform_01_F : U_O_R_Gorka_01_black_F {
	displayName = "几何风服装（Geometric Clothes）";
	price = 150;
	class Textures {
		class U_I_E_Uniform_01_F { 
			displayName = "夹克款（Jacket）";
			condition = "true";
		};
		class U_I_E_Uniform_01_shortsleeve_F : U_I_E_Uniform_01_F { displayName = "卷袖夹克款（Jacket (Rolled)）"; };
		class U_I_L_Uniform_01_camo_F : U_I_E_Uniform_01_F { displayName = "迷彩款（Camo）"; };
		class U_I_E_Uniform_01_sweater_F : U_I_E_Uniform_01_F { displayName = "毛衣款（Sweater）"; };
		class U_I_L_Uniform_01_deserter_F : U_I_E_Uniform_01_F { displayName = "T 恤款（T-Shirt）"; };
		class U_I_E_Uniform_01_tanktop_F : U_I_E_Uniform_01_F { displayName = "背心款（Tank Top）"; };
		class U_I_E_Uniform_01_officer_F : U_I_E_Uniform_01_F { 
			displayName = "军官款（Officer）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		// class DMS : U_I_E_Uniform_01_F {
		// 	displayName = "Dunamis";
		// 	textures[] = { 
		// 		"Data\Textures\Groups\DMS\Uniforms\6_1.paa", 
		// 		"Data\Textures\Groups\DMS\Uniforms\6_2.paa"
		// 	};
		// 	condition = "[] call ULP_fnc_isDunamis";
		// };
	};
};
class U_I_E_Uniform_01_shortsleeve_F : U_I_E_Uniform_01_F {};
class U_I_L_Uniform_01_camo_F : U_I_E_Uniform_01_F {};
class U_I_E_Uniform_01_sweater_F : U_I_E_Uniform_01_F {};
class U_I_L_Uniform_01_deserter_F : U_I_E_Uniform_01_F {};
class U_I_E_Uniform_01_tanktop_F : U_I_E_Uniform_01_F {};
class U_I_E_Uniform_01_officer_F : U_I_E_Uniform_01_F {};

class U_B_Wetsuit : U_O_R_Gorka_01_black_F {
	displayName = "潜水服（Wetsuits）";
	price = 2500;
	virtualSpace = 0;
	class Textures {
		// Police
		class MPU {
			displayName = "MPU";
			textures[] = { "Data\Textures\Uniforms\Police\Units\MPU.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_MPU"", 1] call ULP_fnc_hasAccess }";
		};

		// Civilian
		class U_B_Wetsuit { 
			displayName = "黑色（Black）";
			condition = "true";
		};
		class U_O_Wetsuit : U_B_Wetsuit { displayName = "棕色（Brown）"; };
		class U_I_Wetsuit : U_B_Wetsuit { displayName = "绿色（Green）"; };
	};
};
class U_O_Wetsuit : U_B_Wetsuit{};
class U_I_Wetsuit : U_B_Wetsuit{};

class U_Marshal : U_C_Poor_1 {
	displayName = "安保制服（Protection Uniform）";
	price = 1000;
	class Textures {};
};

class U_C_Driver_1_black : U_C_Poor_1 {
	displayName = "赛车服（Driver Clothes）";
	price = 500;
	class Textures {
		class U_C_Driver_1_black { 
			displayName = "黑色（Black）";
			condition = "true";
		};
		class U_C_Driver_1_blue : U_C_Driver_1_black { displayName = "蓝色（Blue）"; };
		class U_C_Driver_1_green : U_C_Driver_1_black { displayName = "绿色（Green）"; };
		class U_C_Driver_1_red : U_C_Driver_1_black { displayName = "红色（Red）"; };
		class U_C_Driver_1_white : U_C_Driver_1_black { displayName = "白色（White）"; };
		class U_C_Driver_1_yellow : U_C_Driver_1_black { displayName = "黄色（Yellow）"; };
		class U_C_Driver_1_orange : U_C_Driver_1_black { displayName = "橙色（Orange）"; };
		class U_C_Driver_1 : U_C_Driver_1_black { 
			displayName = "Fuel"; 
			condition = "[] call ULP_fnc_donatorLevel >= 2";
		};
		class U_C_Driver_2 : U_C_Driver_1 { displayName = "Bluking"; };
		class U_C_Driver_3 : U_C_Driver_1 { displayName = "Redstone"; };
		class U_C_Driver_4 : U_C_Driver_1 { displayName = "Vrana"; };
	};
};
class U_C_Driver_1_blue : U_C_Driver_1_black{};
class U_C_Driver_1_green : U_C_Driver_1_black{};
class U_C_Driver_1_red : U_C_Driver_1_black{};
class U_C_Driver_1_white : U_C_Driver_1_black{};
class U_C_Driver_1_yellow : U_C_Driver_1_black{};
class U_C_Driver_1_orange : U_C_Driver_1_black{};
class U_C_Driver_1 : U_C_Driver_1_black{};
class U_C_Driver_2 : U_C_Driver_1_black{};
class U_C_Driver_3 : U_C_Driver_1_black{};
class U_C_Driver_4 : U_C_Driver_1_black{};

class U_C_IDAP_Man_shorts_F : U_C_Poor_1 {
	displayName = "IDAP 服装（IDAP Clothes）";
	price = 500;
	class Textures {
		class U_C_IDAP_Man_shorts_F { 
			displayName = "Polo 衫短裤款（Polo, Shorts）";
			condition = "[""IDAP""] call ULP_fnc_hasLicense";
		};
		class U_C_IDAP_Man_casual_F : U_C_IDAP_Man_shorts_F { displayName = "Polo 衫款（Polo）"; };
		class U_C_IDAP_Man_cargo_F : U_C_IDAP_Man_shorts_F { displayName = "工装裤款（Cargo）"; };
		class U_C_IDAP_Man_Tee_F : U_C_IDAP_Man_shorts_F { displayName = "T 恤款（Tee）"; };
		class U_C_IDAP_Man_Jeans_F : U_C_IDAP_Man_shorts_F { displayName = "牛仔裤款（Jeans）"; };
		class U_C_IDAP_Man_TeeShorts_F : U_C_IDAP_Man_shorts_F { displayName = "T 恤短裤款（Tee, Shorts）"; };
	};
};
class U_C_IDAP_Man_casual_F : U_C_IDAP_Man_shorts_F{};
class U_C_IDAP_Man_cargo_F : U_C_IDAP_Man_shorts_F{ };
class U_C_IDAP_Man_Tee_F : U_C_IDAP_Man_shorts_F{
	class Textures {
		class HMP {
			displayName = "HMP";
			textures[] = { "Data\Textures\Uniforms\Global\hmp_uniform.paa" };
			condition = "true";
		};
	};
};
class U_C_IDAP_Man_Jeans_F : U_C_IDAP_Man_shorts_F{};
class U_C_IDAP_Man_TeeShorts_F : U_C_IDAP_Man_shorts_F{};

class U_C_Journalist : U_C_Poor_1 {
	price = 100;
	class Textures {};
};

class U_Rangemaster : U_C_Poor_1 {
	displayName = "巡逻制服（Patrol Uniform）";
	price = 100;
	class Textures {
		class CC {
			displayName = "总警司（Chief Constable）";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\CC.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 11] call ULP_fnc_hasAccess }";
		};
		class DCC {
			displayName = "副总警司（Deputy Chief Constable）";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\DCC.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 10] call ULP_fnc_hasAccess }";
		};
		class CSU {
			displayName = "总警监（Chief Superindendent）";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\CSU.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 9] call ULP_fnc_hasAccess }";
		};
		class SU {
			displayName = "警监（Superindendent）";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\SU.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 8] call ULP_fnc_hasAccess }";
		};
		class CI {
			displayName = "总督察（Chief Inspector）";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\CI.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 7] call ULP_fnc_hasAccess }";
		};
		class PI {
			displayName = "警察督察（Police Inspector）";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\PI.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 6] call ULP_fnc_hasAccess }";
		};
		class PS {
			displayName = "警长（Police Sergeant）";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\PS.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 5] call ULP_fnc_hasAccess }";
		};
		class SC {
			displayName = "高级警员（Senior Police Constable）";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\SC.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 4] call ULP_fnc_hasAccess }";
		};
		class PC {
			displayName = "警员（Police Constable）";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\PC.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_Main"", 2] call ULP_fnc_hasAccess }";
		};
		class PCSO {
			displayName = "社区支援警员（Police Community Support Officer）";
			textures[] = { "Data\Textures\Uniforms\Police\Ranks\PCSO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction";
		};
		class SEG {
			displayName = "特别护送组（Special Escort Group）";
			textures[] = { "Data\Textures\Uniforms\Police\Units\SEG.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SEG"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_Competitor : U_C_Poor_1 {
	displayName = "响应制服（Response Uniform）";
	price = 100;
	virtualSpace = 12;
	class Textures {
		class DR {
			displayName = "顾问医师（Consultant）";
			textures[] = { "Data\Textures\Uniforms\Medic\main_03.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 5] call ULP_fnc_hasAccess }";
		};
		class PAR {
			displayName = "医生（Doctor）";
			textures[] = { "Data\Textures\Uniforms\Medic\main_02.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 4] call ULP_fnc_hasAccess }";
		};
		class STU {
			displayName = "实习学员（Student）";
			textures[] = { "Data\Textures\Uniforms\Medic\main_01.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_Main"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_B_GEN_Commander_F : U_C_Poor_1 {
	displayName = "巡逻毛衣（Patrol Jumper）";
	price = 200;
	class Textures {
		class College {
			displayName = "警务学院（College of Policing）";
			textures[] = { "Data\Textures\Uniforms\Police\Units\COL.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_COL"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_BG_Guerrilla_6_1 : U_B_GEN_Commander_F {
	displayName = "旧款毛衣（Worn Jumper）";
	class Textures {
		// Police
		class NCA {
			displayName = "NCA";
			textures[] = { "Data\Textures\Uniforms\Police\Units\NCA_main.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_NCA"", 1] call ULP_fnc_hasAccess }";
		};

		// Civilian
		class U_BG_Guerrilla_6_1 { 
			displayName = "绿色（Green）";
			condition = "true"; 
		};
	};
};

class U_OrestesBody : U_C_Poor_1 {
	displayName = "新潮造型（New Look）";
	price = 1000;
	class Textures {};
};

class U_NikosBody : U_C_Poor_1 {
	displayName = "休闲造型（Casual Look）";
	price = 1000;
	class Textures {};
};

class U_NikosAgedBody : U_C_Poor_1 {
	displayName = "精致西装（Fine Suit）";
	price = 3500;
	class Textures {};
};

class U_C_FormalSuit_01_tshirt_black_F : U_C_Poor_1 {
	displayName = "正式西装 T 恤款（Formal Suit, T-Shirt）";
	price = 5000;
	class Textures {
		class U_C_FormalSuit_01_tshirt_black_F { 
			displayName = "黑色（Black）";
			condition = "true";
		};
		class U_C_FormalSuit_01_tshirt_gray_F : U_C_FormalSuit_01_tshirt_black_F { displayName = "灰色（Gray）"; };

		// Group
		class Ridge : U_C_FormalSuit_01_tshirt_gray_F {
			displayName = "Ridge 正式制服（Ridge Formal Uniform）";
			textures[] = { "Data\Textures\Groups\Ridge\U_C_FormalSuit_01_tshirt_gray_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_C_FormalSuit_01_tshirt_gray_F : U_C_FormalSuit_01_tshirt_black_F {};

class U_C_FormalSuit_01_black_F : U_C_Poor_1 {
	displayName = "正式西装（Formal Suit）";
	price = 6000;
	class Textures {
		class U_C_FormalSuit_01_black_F { 
			displayName = "黑色（Black）";
			condition = "true";
		};
		class U_C_FormalSuit_01_gray_F : U_C_FormalSuit_01_black_F { displayName = "灰色（Gray）"; };
		class U_C_FormalSuit_01_blue_F : U_C_FormalSuit_01_black_F { displayName = "蓝色（Blue）"; };
		class U_C_FormalSuit_01_khaki_F : U_C_FormalSuit_01_black_F { 
			displayName = "卡其色（Khaki）";
			condition = "[] call ULP_fnc_donatorLevel >= 2";  
		};
	};
};
class U_C_FormalSuit_01_gray_F : U_C_FormalSuit_01_black_F {};
class U_C_FormalSuit_01_blue_F : U_C_FormalSuit_01_black_F {};
class U_C_FormalSuit_01_khaki_F : U_C_FormalSuit_01_black_F {};

class U_I_ParadeUniform_01_AAF_decorated_F : U_C_Poor_1 {
	displayName = "指挥礼服（Command Parade Uniform）";
	price = 10000;
	class Textures {
		class Command { 
			displayName = "礼服（Parade Uniform）";
			textures[] = { 
				"Data\Textures\Uniforms\Police\parade_01.paa",
				"Data\Textures\Uniforms\Police\parade_02.paa",
				"Data\Textures\Uniforms\Police\parade_03.paa"
			};
			condition = "true";
		};
	};
};
class U_I_ParadeUniform_01_AAF_F : U_I_ParadeUniform_01_AAF_decorated_F {
	displayName = "礼服（Parade Uniform）";
	class Textures {
		class Main { 
			displayName = "礼服（Parade Uniform）";
			condition = "true";
			textures[] = { 
				"Data\Textures\Uniforms\Police\parade_01.paa",
				"Data\Textures\Uniforms\Police\parade_02.paa",
				"Data\Textures\Uniforms\Police\parade_03.paa"
			};
		};
	};
};

class U_B_survival_uniform : U_C_Poor_1 {
	price = 15000;
	reputation = true;
	class Textures {
		// Civilian
		class U_B_survival_uniform { 
			displayName = "MTP 迷彩（MTP）";
			condition = "true";
		};

		// Group
		class Ridge : U_B_survival_uniform {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class 44th : U_B_survival_uniform {
			displayName = "44th";
			textures[] = { "Data\Textures\Groups\44th\U_B_CTRG_Soldier_F.paa" };
			condition = "[121] call ULP_fnc_isGroupPremium";
		};
	};
};

class U_B_CombatUniform_mcam_worn : U_B_survival_uniform {
	displayName = "交通制服（Traffic Uniform）";
	price = 1000;
	virtualSpace = 4;
	class Textures {
		class RPU {
			displayName = "交通制服（Traffic Uniform）";
			textures[] = { "Data\Textures\Uniforms\Police\Units\RPU_main.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_RPU"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_I_CombatUniform : U_B_survival_uniform {
	displayName = "战斗作训服（Combat Fatigues）";
	price = 1500;
	virtualSpace = 4;
	class Textures {
		// Civilian
		class U_I_CombatUniform { 
			displayName = "AAF 基础款（AAF (Base)）";
			condition = "true";
		};

		// Group
		class NUMS : U_I_CombatUniform {
			displayName = "NUMS";
			textures[] = { "Data\Textures\Groups\NUMS\U_B_CTRG_Soldier_F.paa" };
			condition = "[115] call ULP_fnc_isGroupPremium";
		};
	};
};

class U_I_CombatUniform_shortsleeve : U_I_CombatUniform {
	displayName = "卷袖战斗作训服（Combat Fatigues (Rolled)）";
	class Textures {
		// Civilian
		class U_I_CombatUniform_shortsleeve { 
			displayName = "AAF 卷袖款（AAF (Rolled)）";
			condition = "true";
		};

		// Group
		class NUMS : U_I_CombatUniform_shortsleeve {
			displayName = "NUMS";
			textures[] = { "Data\Textures\Groups\NUMS\U_B_CTRG_Soldier_F.paa" };
			condition = "[115] call ULP_fnc_isGroupPremium";
		};
	};
};

class U_B_CombatUniform_mcam : U_B_survival_uniform {
	displayName = "战斗服（Combat Clothes）";
	price = 1500;
	virtualSpace = 4;
	class Textures {
		// Civilian
		class U_B_CombatUniform_mcam { 
			displayName = "MTP 迷彩（MTP）";
			condition = "true";
		};
		class U_B_CombatUniform_mcam_wdl_f : U_B_CombatUniform_mcam { displayName = "林地迷彩（WDL）"; };
		class U_B_T_Solider_F : U_B_CombatUniform_mcam { displayName = "热带迷彩（Tropic）"; };

		// Group
		class Ridge : U_B_CombatUniform_mcam {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class 44th : U_B_CombatUniform_mcam {
			displayName = "44th";
			textures[] = { "Data\Textures\Groups\44th\U_B_CTRG_Soldier_F.paa" };
			condition = "[121] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_B_CombatUniform_mcam_wdl_f : U_B_CombatUniform_mcam {};
class U_B_T_Solider_F : U_B_CombatUniform_mcam {};

class U_B_CombatUniform_mcam_vest : U_B_CombatUniform_mcam {
	displayName = "卷袖战斗服（Combat Clothes (Rolled)）";
	class Textures {
		// Civilian
		class U_B_CombatUniform_mcam_vest { 
			displayName = "MTP 迷彩（MTP）";
			condition = "true";
		};
		class U_B_CombatUniform_vest_mcam_wdl_f : U_B_CombatUniform_mcam_vest { displayName = "林地迷彩（WDL）"; };
		class U_B_T_Solider_SL_F : U_B_CombatUniform_mcam_vest { displayName = "热带迷彩（Tropic）"; };

		// Group
		class Ridge : U_B_CombatUniform_mcam_vest {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class 44th : U_B_CombatUniform_mcam_vest {
			displayName = "44th";
			textures[] = { "Data\Textures\Groups\44th\U_B_CTRG_Soldier_F.paa" };
			condition = "[121] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_B_CombatUniform_vest_mcam_wdl_f : U_B_CombatUniform_mcam {};
class U_B_T_Solider_SL_F : U_B_CombatUniform_mcam {};

class U_B_CombatUniform_mcam_tshirt : U_B_CombatUniform_mcam {
	displayName = "T 恤战斗服（Combat Clothes (Tee)）";
	class Textures {
		// Civilian
		class U_B_CombatUniform_mcam_tshirt { 
			displayName = "MTP 基础款（MTP (Base)）";
			condition = "true";
		};
		class U_B_CombatUniform_tshirt_mcam_wdL_f : U_B_CombatUniform_mcam_tshirt { displayName = "林地迷彩（WDL）"; };
		class U_B_T_Solider_AR_F : U_B_CombatUniform_mcam_tshirt { displayName = "热带迷彩（Tropic）"; };

		// Group
		class Ridge : U_B_CombatUniform_mcam_tshirt {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class 44th : U_B_CombatUniform_mcam_tshirt {
			displayName = "44th";
			textures[] = { "Data\Textures\Groups\44th\U_B_CTRG_Soldier_F.paa" };
			condition = "[121] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_B_CombatUniform_tshirt_mcam_wdL_f : U_B_CombatUniform_mcam {};
class U_B_T_Solider_AR_F : U_B_CombatUniform_mcam {};

class U_B_CTRG_Soldier_F : U_B_survival_uniform {
	displayName = "隐匿制服（Stealth Uniform）";
	price = 35000;
	virtualSpace = 4;
	class Textures {
		// Police
		class SCO19 {
			displayName = "SCO19";
			textures[] = { "Data\Textures\Uniforms\Police\Units\SCO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SCO"", 2] call ULP_fnc_hasAccess }";
		};
		class AFO : SCO19 {
			displayName = "AFO";
			textures[] = { "Data\Textures\Uniforms\Police\Units\AFO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SFO"", 1] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } }";
		};

		// Civilian
		class U_B_CTRG_Soldier_F {
			displayName = "热带迷彩（Tropic）";
			condition = "true";
		};
		class U_B_CTRG_Soldier_Arid_F : U_B_CTRG_Soldier_F { displayName = "干旱迷彩（Arid）"; };
		class U_B_CTRG_Soldier_urb_1_F : U_B_CTRG_Soldier_F { displayName = "城市迷彩（Urban）"; };

		// Group
		class Ridge : U_B_CTRG_Soldier_F {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class 44th : U_B_CombatUniform_mcam {
			displayName = "44th";
			textures[] = { "Data\Textures\Groups\44th\U_B_CTRG_Soldier_F.paa" };
			condition = "[121] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_B_CTRG_Soldier_Arid_F : U_B_CTRG_Soldier_F {};
class U_B_CTRG_Soldier_urb_1_F : U_B_CTRG_Soldier_F {};

class U_B_CTRG_Soldier_3_F : U_B_CTRG_Soldier_F {
	displayName = "卷袖隐匿制服（Stealth Uniform (Rolled)）";
	class Textures {
		// Police
		class SCO19 {
			displayName = "SCO19";
			textures[] = { "Data\Textures\Uniforms\Police\Units\SCO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SCO"", 2] call ULP_fnc_hasAccess }";
		};
		class AFO : SCO19 {
			displayName = "AFO";
			textures[] = { "Data\Textures\Uniforms\Police\Units\AFO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SFO"", 1] call ULP_fnc_hasAccess || { [""Police_SCO"", 1] call ULP_fnc_hasAccess } }";
		};

		// Civilian
		class U_B_CTRG_Soldier_3_F { 
			displayName = "热带迷彩（Tropic）";
			condition = "true";
		};
		class U_B_CTRG_Soldier_3_Arid_F : U_B_CTRG_Soldier_3_F { displayName = "干旱迷彩（Arid）"; };
		class U_B_CTRG_Soldier_urb_3_F : U_B_CTRG_Soldier_3_F { displayName = "城市迷彩（Urban）"; };

		// Group
		class Ridge : U_B_CTRG_Soldier_3_F {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class 44th : U_B_CTRG_Soldier_3_F {
			displayName = "44th";
			textures[] = { "Data\Textures\Groups\44th\U_B_CTRG_Soldier_F.paa" };
			condition = "[121] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_B_CTRG_Soldier_3_Arid_F : U_B_CTRG_Soldier_3_F {};
class U_B_CTRG_Soldier_urb_3_F : U_B_CTRG_Soldier_3_F {};

class U_B_CTRG_Soldier_2_Arid_F : U_B_CTRG_Soldier_F {
	displayName = "T 恤隐匿制服（Stealth Uniform (Tee)）";
	class Textures {
		// Police
		class SCO19 {
			displayName = "SCO19";
			textures[] = { "Data\Textures\Uniforms\Police\Units\SCO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SCO"", 4] call ULP_fnc_hasAccess }";
		};
		class AFO : SCO19 {
			displayName = "AFO";
			textures[] = { "Data\Textures\Uniforms\Police\Units\AFO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SFO"", 1] call ULP_fnc_hasAccess || { [""Police_SCO"", 4] call ULP_fnc_hasAccess } }";
		};

		// Civilian
		class U_B_CTRG_Soldier_2_Arid_F { 
			displayName = "干旱迷彩（Arid）";
			condition = "true";
		};
		class U_B_CTRG_Soldier_2_F : U_B_CTRG_Soldier_2_Arid_F { displayName = "热带迷彩（Tropic）"; };
		class U_B_CTRG_Soldier_urb_2_F : U_B_CTRG_Soldier_2_Arid_F { displayName = "城市迷彩（Urban）"; };

		// Group
		class Ridge : U_B_CTRG_Soldier_2_Arid_F {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class 44th : U_B_CTRG_Soldier_2_Arid_F {
			displayName = "44th";
			textures[] = { "Data\Textures\Groups\44th\U_B_CTRG_Soldier_F.paa" };
			condition = "[121] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_B_CTRG_Soldier_2_F : U_B_CTRG_Soldier_2_Arid_F {};
class U_B_CTRG_Soldier_urb_2_F : U_B_CTRG_Soldier_2_Arid_F {};

class U_B_GhillieSuit : U_B_survival_uniform {
	displayName = "半身吉利服（Half-Ghillies）";
	price = 65000;
	virtualSpace = 4;
	isMask = true;
	class Textures {
		// Police
		class SCO19 {
			displayName = "SCO19";
			textures[] = { "Data\Textures\Uniforms\Police\Units\SCO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SCO"", 3] call ULP_fnc_hasAccess }";
		};
		class AFO : SCO19 {
			displayName = "AFO";
			textures[] = { "Data\Textures\Uniforms\Police\Units\AFO.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_SFO"", 1] call ULP_fnc_hasAccess || { [""Police_SCO"", 3] call ULP_fnc_hasAccess } }";
		};

		// Civilian
		class U_B_GhillieSuit { 
			displayName = "MTP 迷彩（MTP）";
			condition = "true";
		};
		class U_O_GhillieSuit : U_B_GhillieSuit { displayName = "六角迷彩（Hex）"; };
		class U_I_GhillieSuit : U_B_GhillieSuit { displayName = "数码迷彩（Digi）"; };
		class U_B_T_Sniper_F : U_B_GhillieSuit { displayName = "热带迷彩（Tropic）"; };

		// Group
		class Ridge : U_B_GhillieSuit {
			displayName = "Ridge";
			textures[] = { "Data\Textures\Groups\Ridge\U_B_CTRG_Soldier_F.paa" };
			condition = "[1] call ULP_fnc_isGroupPremium";
		};
		class 44th : U_B_GhillieSuit {
			displayName = "44th";
			textures[] = { "Data\Textures\Groups\44th\U_B_CTRG_Soldier_F.paa" };
			condition = "[121] call ULP_fnc_isGroupPremium";
		};
	};
};
class U_O_GhillieSuit : U_B_GhillieSuit {};
class U_I_GhillieSuit : U_B_GhillieSuit {};
class U_B_T_Sniper_F : U_B_GhillieSuit {};

class U_B_FullGhillie_ard : U_B_GhillieSuit {
	displayName = "全身吉利服（Full-Ghillies）";
	price = 100000;
	class Textures {
		class U_B_FullGhillie_ard { 
			displayName = "干旱迷彩（Arid）";
			condition = "true";
		};
		class U_B_FullGhillie_sard : U_B_FullGhillie_ard { displayName = "半干旱迷彩（Semi-Arid）"; };
		class U_B_FullGhillie_lsh : U_B_FullGhillie_ard { displayName = "繁茂地形（Lush）"; };
		class U_B_T_FullGhillie_tna_F : U_B_FullGhillie_ard { displayName = "丛林迷彩（Jungle）"; };
	};
};
class U_B_FullGhillie_sard : U_B_FullGhillie_ard {};
class U_B_FullGhillie_lsh : U_B_FullGhillie_ard {};
class U_B_T_FullGhillie_tna_F : U_B_FullGhillie_ard {};

class U_B_HeliPilotCoveralls : U_B_survival_uniform {
	displayName = "飞行服（Flight Clothes）";
	price = 3000;
	virtualSpace = 4;
	class Textures {
		class U_B_HeliPilotCoveralls { 
			displayName = "绿色（Green）";
			condition = "true";
		};
		class U_I_HeliPilotCoveralls : U_B_HeliPilotCoveralls { displayName = "棕褐色（Tan）"; };
		class U_I_E_Uniform_01_coveralls_F : U_B_HeliPilotCoveralls { displayName = "几何纹（Geometric）"; };
	};
};
class U_I_HeliPilotCoveralls : U_B_HeliPilotCoveralls {};
class U_I_E_Uniform_01_coveralls_F : U_B_HeliPilotCoveralls {};

class U_O_PilotCoveralls : U_B_survival_uniform {
	displayName = "飞行服（Flight Clothes）";
	price = 20000;
	virtualSpace = 8;
	class Textures {
		// Police
		class NPAS {
			displayName = "NPAS 制服（NPAS Uniform）";
			textures[] = { "Data\Textures\Uniforms\Police\Units\NPAS.paa" };
			condition = "[player, [""Police""]] call ULP_fnc_isFaction && { [""Police_NPAS"", 1] call ULP_fnc_hasAccess }";
		};

		// Medic
		class AAA {
			displayName = "AAA 制服（AAA Uniform）";
			textures[] = { "Data\Textures\Uniforms\Medic\aa.paa" };
			condition = "[player, [""Medic""]] call ULP_fnc_isFaction && { [""Medic_AA"", 1] call ULP_fnc_hasAccess }";
		};
	};
};

class U_C_CBRN_Suit_01_White_F : U_B_survival_uniform {
	displayName = "CBRN 防化服（CBRN Suits）";
	price = 50000;
	isGas = true;
	class Textures {
		class U_C_CBRN_Suit_01_White_F { 
			displayName = "白色（White）";
			condition = "true";
		};
		class U_C_CBRN_Suit_01_Blue_F : U_C_CBRN_Suit_01_White_F { displayName = "蓝色（Blue）"; };
		class U_B_CBRN_Suit_01_MTP_F : U_C_CBRN_Suit_01_White_F { displayName = "MTP 迷彩（MTP）"; };
		class U_B_CBRN_Suit_01_Wdl_F : U_C_CBRN_Suit_01_White_F { displayName = "林地迷彩（WDL）"; };
		class U_I_CBRN_Suit_01_AAF_F : U_C_CBRN_Suit_01_White_F { displayName = "数码迷彩（DIGI）"; };
		class U_I_E_CBRN_Suit_01_EAF_F : U_C_CBRN_Suit_01_White_F { displayName = "LDF"; };
		class U_I_CBRN_Suit_01_Tropic_F : U_C_CBRN_Suit_01_White_F { displayName = "热带迷彩（Tropic）"; };
	};
};
class U_C_CBRN_Suit_01_Blue_F : U_C_CBRN_Suit_01_White_F {};
class U_B_CBRN_Suit_01_MTP_F : U_C_CBRN_Suit_01_White_F {};
class U_B_CBRN_Suit_01_Wdl_F : U_C_CBRN_Suit_01_White_F {};
class U_I_CBRN_Suit_01_AAF_F : U_C_CBRN_Suit_01_White_F {};
class U_I_E_CBRN_Suit_01_EAF_F : U_C_CBRN_Suit_01_White_F {};
class U_I_CBRN_Suit_01_Tropic_F : U_C_CBRN_Suit_01_White_F {};

class U_C_Protagonist_VR : U_B_survival_uniform {
	displayName = "员工套装（Staff Suits）";
	price = 1000000;
	virtualSpace = 100;
	isGas = true;
	class Textures {
		class U_C_Protagonist_VR { 
			displayName = "紫色（Purple）";
			condition = "true";
		};
		class Black : U_C_Protagonist_VR {
			displayName = "黑色（Black）";
			textures[] = { "\A3\Characters_F\Common\Data\basicbody_black_co.paa" };
		};
		class Gray : U_C_Protagonist_VR { 
			displayName = "灰色（Gray）";
			textures[] = { "\A3\Characters_F\Common\Data\basicbody_grey_co.paa" };
		};
		class U_O_Protagonist_VR : U_C_Protagonist_VR { displayName = "红色（Red）"; };
		class U_B_Protagonist_VR : U_C_Protagonist_VR { displayName = "蓝色（Blue）"; };
		class DullBlue : U_C_Protagonist_VR { 
			displayName = "暗蓝色（Dull Blue）";
			textures[] = { "\A3\Characters_F\Common\Data\basicbody_blue_co.paa" };
		};
		class U_I_Protagonist_VR : U_C_Protagonist_VR { displayName = "绿色（Green）"; };
		class DullGreen : U_C_Protagonist_VR { 
			displayName = "暗绿色（Dull Green）";
			textures[] = { "\A3\Characters_F\Common\Data\basicbody_green_co.paa" };
		};
		class Brown : U_C_Protagonist_VR { 
			displayName = "棕色（Brown）";
			textures[] = { "\A3\Characters_F\Common\Data\basicbody_brown_co.paa" };
		};
	};
};
class U_O_Protagonist_VR : U_C_Protagonist_VR {};
class U_B_Protagonist_VR : U_C_Protagonist_VR {};
class U_I_Protagonist_VR : U_C_Protagonist_VR {};
