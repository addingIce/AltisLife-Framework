class CfgNotifications {
	class AchievementUnlocked {
		title = "成就已解锁";
		iconPicture = "\a3\ui_f\data\GUI\Cfg\Ranks\general_gs.paa";
		description = "%1";
		priority = 0;
	};

	class GoalReward : AchievementUnlocked {
		title = "个人目标";
	};

	class TitleUnlocked : AchievementUnlocked {
		title = "称号已解锁";
	};
};
