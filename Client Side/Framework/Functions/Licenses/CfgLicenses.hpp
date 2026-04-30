class CfgLicenses {
    class BaseLicense {
        factions[] = { "Civilian", "Dunamis" };
        description = "进行货物加工所需的基础许可";
        class Settings {
            isVisible = false;
            isRemovable = false;
        };
        conditions = "true";
    };

    class Driving : BaseLicense {
        displayName = "驾驶执照（Driving Licence）";
        description = "购买汽车或厢式车的基础条件";
        buyPrice = 1000;
        class Settings {
            isVisible = true;
            isRemovable = true;
        };
    };

    class Trucking : Driving {
        displayName = "货运执照（Trucking Licence）";
        description = "购买货运车辆的基础条件";
        buyPrice = 50000;
        class Settings : Settings {};
        conditions = "[""Driving""] call ULP_fnc_hasLicense && { !([] call ULP_fnc_isOnTutorial) }";
    };

    class Boating : Trucking {
        displayName = "船舶执照（Boating Licence）";
        description = "购买船只的基础条件";
        buyPrice = 6500;
        class Settings : Settings {};
    };

    class Piloting : Trucking {
        displayName = "飞行执照（Piloting Licence）";
        description = "购买直升机或飞机的基础条件";
        buyPrice = 500000;
        class Settings : Settings {};
    };

    class Home : Driving {
        displayName = "房产购买许可（Homeowner's Approval）";
        description = "购买房产的基础条件";
        buyPrice = 3000000;
        class Settings : Settings {};
    };

    class Taxi : Driving {
        displayName = "Taxi Altis 从业许可（Taxi Altis Worker）";
        description = "获准在阿尔蒂斯从事出租车司机工作";
        buyPrice = 25000;
        onBought = "[""Employment""] call ULP_fnc_achieve;";
        class Settings : Settings {};
    };

    class Solicitor : Taxi {
        displayName = "Altis Solicitors 执业许可（Altis Solicitors）";
        description = "获准在阿尔蒂斯从事律师工作";
        buyPrice = 30000;
        class Settings : Settings {};
    };

    class News : Taxi {
        displayName = "AAN World News 记者证（AAN World News Reporter）";
        description = "获准在阿尔蒂斯从事新闻记者工作";
        buyPrice = 30000;
        class Settings : Settings {};
    };

    class IDAP : Driving {
        displayName = "IDAP 志愿者（IDAP Volunteer）";
        description = "已报名成为 IDAP 志愿者";
        buyPrice = 0;
        class Settings : Settings {};
    };

    class Handgun : Driving {
        displayName = "手枪持有证（Handgun Certificate）";
        description = "允许持有手枪的许可证明";
        buyPrice = 85000;
        class Settings : Settings {};
    };

    class SMG : Driving {
        displayName = "冲锋枪持有证（SMG Certificate）";
        description = "允许持有冲锋枪的许可证明";
        buyPrice = 100000;
        class Settings : Settings {};
    };

    class Security : Driving {
        displayName = "企业安保许可（Security Contractor）";
        description = "获准以企业安保承包商身份执业";
        buyPrice = 350000;
        class Settings : Settings {};
        conditions = "[""Security""] call ULP_fnc_hasGroupPerk";
    };

    class Protection : Driving {
        displayName = "政要保护许可（Protection Officer）";
        description = "获准以政党保护官身份执业";
        buyPrice = 350000;
        class Settings : Settings {};
        conditions = "[""Protection""] call ULP_fnc_hasGroupPerk";
    };

    class Hunting : Driving {
        displayName = "狩猎许可（Hunting Certificate）";
        description = "允许猎捕野生动物的许可证明";
        buyPrice = 1140000;
        class Settings : Settings {};
    };

    class Rebel : BaseLicense {
        displayName = "Rebel 访问权限（Rebel Access）";
        description = "已购买使用阿尔蒂斯 Rebel 物资的权限";
        buyPrice = 5000000;
        onBought = "[""JoinRebel""] call ULP_fnc_achieve;";
        class Settings {};
    };

    class Blackmarket : BaseLicense {
        displayName = "黑市访问权限（Blackmarket Access）";
        description = "已购买使用阿尔蒂斯黑市物资的权限";
        buyPrice = 10000000;
        class Settings {};
        conditions = "[""Rebel""] call ULP_fnc_hasLicense && { [""Blackmarketer""] call ULP_fnc_hasPerk || [""Blackmarket""] call ULP_fnc_hasGroupPerk }";
    };

    // Processing Sites
    class Schnapps : BaseLicense {
        displayName = "Schnapps 加工许可（Schnapps Processing）";
        buyPrice = 15000;
        class Settings {};
    };

    class Tobacco : BaseLicense {
        displayName = "烟草加工许可（Tobacco Processing）";
        buyPrice = 30000;
        class Settings {};
    };

    class Copper : BaseLicense {
        displayName = "铜矿加工许可（Copper Processing）";
        buyPrice = 25000;
        class Settings {};
    };

    class Silver : BaseLicense {
        displayName = "银矿加工许可（Silver Processing）";
        buyPrice = 40000;
        class Settings {};
    };

    class Iron : BaseLicense {
        displayName = "铁矿加工许可（Iron Processing）";
        buyPrice = 200000;
        class Settings {};
    };

    class Salt : BaseLicense {
        displayName = "盐加工许可（Salt Processing）";
        buyPrice = 150000;
        class Settings {};
    };

    class Sand : BaseLicense {
        displayName = "沙料加工许可（Sand Processing）";
        buyPrice = 90000;
        class Settings {};
    };

    class Oil : BaseLicense {
        displayName = "石油加工许可（Oil Processing）";
        buyPrice = 800000;
        class Settings {};
    };

    class Diamond : BaseLicense {
        displayName = "钻石加工许可（Diamond Processing）";
        buyPrice = 750000;
        class Settings {};
    };

    class Uranium : BaseLicense {
        displayName = "铀矿加工许可（Uranium Processing）";
        buyPrice = 2000000;
        class Settings {};
    };

    class Weed : BaseLicense {
        displayName = "大麻加工许可（Weed Processing）";
        buyPrice = 120000;
        class Settings {};
    };

    class Heroin : BaseLicense {
        displayName = "海洛因加工许可（Heroin Processing）";
        buyPrice = 350000;
        class Settings {};
    };

    class Cocaine : BaseLicense {
        displayName = "可卡因加工许可（Cocaine Processing）";
        buyPrice = 800000;
        class Settings {};
    };

    class Meth : BaseLicense {
        displayName = "冰毒加工许可（Meth Processing）";
        buyPrice = 1000000;
        class Settings {};
    };

    class Weapons : BaseLicense {
        displayName = "武器加工许可（Weapons Processing）";
        buyPrice = 2500000;
        class Settings {};
    };
};
