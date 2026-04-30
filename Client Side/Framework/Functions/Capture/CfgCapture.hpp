class CfgCapture {
	class Altis {
		class WestHideout {
			displayName = "西部罪犯藏身处（Western Criminal Hideout）";
			time = 90;
			cooldown = 180;
			class Marker {
				markerType = "loc_Bunker";
				markerColour = "ColorEast";
				defaultName = "罪犯藏身处";
			};
			condition = "[""CriminalHideouts""] call ULP_fnc_hasGroupPerk";
		};
		class EastHideout : WestHideout { displayName = "东部罪犯藏身处（Eastern Criminal Hideout）"; };

		class WesternPowerStation {
			displayName = "西部发电站（Western Power Station）";
			time = 120;
			cooldown = 300;
			class Marker {
				markerType = "loc_Power";
				markerColour = "ColorIndependent";
				defaultName = "西部发电站（Western Power Station）";
			};
			condition = "[] call ULP_fnc_isGroup";
		};
		class EasternPowerStation : WesternPowerStation {
			displayName = "东部发电站（Eastern Power Station）";
			class Marker : Marker { defaultName = "东部发电站（Eastern Power Station）"; };
		};

		class WesternRegion {
			displayName = "西部区域（Western Region）";
			time = 120;
			cooldown = 300;
			class Marker {
				markerType = "MinefieldAP";
				markerColour = "ColorEast";
				defaultName = "西部区域（Western Region）";
			};
			condition = "[] call ULP_fnc_isGroup";
		};
		class NorthEasternRegion : WesternRegion {
			displayName = "东北区域（North-Eastern Region）";
			class Marker : Marker { defaultName = "东北区域（North-Eastern Region）"; };
		};
		class SouthEasternRegion : WesternRegion {
			displayName = "东南区域（South-Eastern Region）";
			class Marker : Marker { defaultName = "东南区域（South-Eastern Region）"; };
		};
		class MilitaryBase : WesternRegion {
			displayName = "军事基地（Military Base）";
			class Marker : Marker { defaultName = "军事基地（Military Base）"; };
		};
	};
};
