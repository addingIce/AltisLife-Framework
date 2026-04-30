class CfgDebriefing {
    class Abort {
        title = "已离开游戏";
        subtitle = "感谢游玩！";
        description = "你的数据已同步，并已返回大厅。";
        pictureBackground = "";
        picture = "\A3\ui_f\data\GUI\Cfg\Hints\Doors_ca.paa";
        pictureColor[] = {1,1,1,1};
    };
    class InitFailed : Abort {
        title = "无法加入";
        subtitle = "玩家数据查询失败";
        description = "请联系管理人员寻求帮助";
    };
    class CheatCheck : InitFailed {
        title = "无法加入";
        subtitle = "状态校验失败";
    };
    class NotWhitelisted : Abort {
        title = "无法加入";
        subtitle = "你当前不在白名单中";
        description = "请联系该阵营的管理人员了解详情";
    };
    class Blacklisted : Abort {
        title = "无法加入";
        subtitle = "你当前已被列入黑名单";
        description = "请联系该阵营的管理人员了解详情";
    };
};
