#if defined _casino_included
	#endinput
#endif
#define _casino_included

static const Float:CasinoRouletteTablePos[] = 
	{ 0.00, 4.84 }
;
static const Float:CasinoRouletteChipsPos[][2] = {
	{ 1950.216918, 1742.510498 }, // 0
	{ 1950.367065, 1742.270263 }, // 1
	{ 1950.367065, 1742.510498 }, // 2
	{ 1950.367065, 1742.750732 }, // 3
	{ 1950.521118, 1742.270263 }, // 4
	{ 1950.521118, 1742.510498 }, // 5
	{ 1950.521118, 1742.750732 }, // 6
	{ 1950.675170, 1742.270263 }, // 7
	{ 1950.675170, 1742.510498 }, // 8
	{ 1950.675170, 1742.750732 }, // 9
	{ 1950.829223, 1742.270263 }, // 10
	{ 1950.829223, 1742.510498 }, // 11
	{ 1950.829223, 1742.750732 }, // 12
	{ 1950.983276, 1742.270263 }, // 13
	{ 1950.983276, 1742.510498 }, // 14
	{ 1950.983276, 1742.750732 }, // 15
	{ 1951.137329, 1742.270263 }, // 16
	{ 1951.137329, 1742.510498 }, // 17
	{ 1951.137329, 1742.750732 }, // 18
	{ 1951.291381, 1742.270263 }, // 19
	{ 1951.291381, 1742.510498 }, // 20
	{ 1951.291381, 1742.750732 }, // 21
	{ 1951.445434, 1742.270263 }, // 22
	{ 1951.445434, 1742.510498 }, // 23
	{ 1951.445434, 1742.750732 }, // 24
	{ 1951.599487, 1742.270263 }, // 25
	{ 1951.599487, 1742.510498 }, // 26
	{ 1951.599487, 1742.750732 }, // 27
	{ 1951.753540, 1742.270263 }, // 28
	{ 1951.753540, 1742.510498 }, // 29
	{ 1951.753540, 1742.750732 }, // 30
	{ 1951.907592, 1742.270263 }, // 31
	{ 1951.907592, 1742.510498 }, // 32
	{ 1951.907592, 1742.750732 }, // 33
	{ 1952.061645, 1742.270263 }, // 34
	{ 1952.061645, 1742.510498 }, // 35
	{ 1952.061645, 1742.750732 }, // 36
	{ 1951.361450, 1741.779785 }, // BLACK
	{ 1951.061401, 1741.779785 }, // RED
	{ 1950.601196, 1742.020019 }, //  1st-12
	{ 1951.221191, 1742.020019 }, //  2nd-12
	{ 1951.831787, 1742.020019 }, //  3rd-12
	{ 1950.451416, 1741.779785 }, // 1-18
	{ 1951.971923, 1741.779785 }, // 19-36
	{ 1950.751342, 1741.779785 }, // EVEN
	{ 1951.661621, 1741.779785 }, // ODD
	{ 1952.215698, 1742.270263 }, // 3to1
	{ 1952.215698, 1742.510498 }, // 3to1
	{ 1952.215698, 1742.750732 } // 3to1
};
#define INVALID_DYNAMIC_OBJECT_ID	-1

#define GetName%0(%1)				player_name[%1]
#define COLOR_ERROR 				COLOR_GREY

#define MAX_CASINO_CARDS				52

enum {
	CARD_NUMBER_TWO = 2,
	CARD_NUMBER_THREE,
	CARD_NUMBER_FOUR,
	CARD_NUMBER_FIVE,
	CARD_NUMBER_SIX,
	CARD_NUMBER_SEVEN,
	CARD_NUMBER_EIGHT,
	CARD_NUMBER_NINE,
	CARD_NUMBER_TEN,
	CARD_NUMBER_JACK,
	CARD_NUMBER_QUEEN,
	CARD_NUMBER_KING,
	CARD_NUMBER_ACE
}
enum {
	BJ_CARD_NUMBER_TWO = 1,
	BJ_CARD_NUMBER_THREE,
	BJ_CARD_NUMBER_FOUR,
	BJ_CARD_NUMBER_FIVE,
	BJ_CARD_NUMBER_SIX,
	BJ_CARD_NUMBER_SEVEN,
	BJ_CARD_NUMBER_EIGHT,
	BJ_CARD_NUMBER_NINE,
	BJ_CARD_NUMBER_TEN,
	BJ_CARD_NUMBER_JACK,
	BJ_CARD_NUMBER_QUEEN,
	BJ_CARD_NUMBER_KING,
	BJ_CARD_NUMBER_ACE
}
enum {
	CARD_SUIT_CLUBS = 1,
	CARD_SUIT_DIAMONDS,
	CARD_SUIT_HEARTS,
	CARD_SUIT_SPADES
};
enum CASINO_CARD_ENUM {
	CASINO_CARD_NAME[16],
	CASINO_CARD_SUIT,
	CASINO_CARD_VALUE
};
new CASINO_CARD_INFO[MAX_CASINO_CARDS][CASINO_CARD_ENUM] = {
	{"LD_CARD:cd1c", CARD_SUIT_CLUBS, CARD_NUMBER_ACE},
	{"LD_CARD:cd2c", CARD_SUIT_CLUBS, CARD_NUMBER_TWO},
	{"LD_CARD:cd3c", CARD_SUIT_CLUBS, CARD_NUMBER_THREE},
	{"LD_CARD:cd4c", CARD_SUIT_CLUBS, CARD_NUMBER_FOUR},
	{"LD_CARD:cd5c", CARD_SUIT_CLUBS, CARD_NUMBER_FIVE},
	{"LD_CARD:cd6c", CARD_SUIT_CLUBS, CARD_NUMBER_SIX},
	{"LD_CARD:cd7c", CARD_SUIT_CLUBS, CARD_NUMBER_SEVEN},
	{"LD_CARD:cd8c", CARD_SUIT_CLUBS, CARD_NUMBER_EIGHT},
	{"LD_CARD:cd9c", CARD_SUIT_CLUBS, CARD_NUMBER_NINE},
	{"LD_CARD:cd10c", CARD_SUIT_CLUBS, CARD_NUMBER_TEN},
	{"LD_CARD:cd11c", CARD_SUIT_CLUBS, CARD_NUMBER_JACK},
	{"LD_CARD:cd12c", CARD_SUIT_CLUBS, CARD_NUMBER_QUEEN},
	{"LD_CARD:cd13c", CARD_SUIT_CLUBS, CARD_NUMBER_KING},

	{"LD_CARD:cd1d", CARD_SUIT_DIAMONDS, CARD_NUMBER_ACE},
	{"LD_CARD:cd2d", CARD_SUIT_DIAMONDS, CARD_NUMBER_TWO},
	{"LD_CARD:cd3d", CARD_SUIT_DIAMONDS, CARD_NUMBER_THREE},
	{"LD_CARD:cd4d", CARD_SUIT_DIAMONDS, CARD_NUMBER_FOUR},
	{"LD_CARD:cd5d", CARD_SUIT_DIAMONDS, CARD_NUMBER_FIVE},
	{"LD_CARD:cd6d", CARD_SUIT_DIAMONDS, CARD_NUMBER_SIX},
	{"LD_CARD:cd7d", CARD_SUIT_DIAMONDS, CARD_NUMBER_SEVEN},
	{"LD_CARD:cd8d", CARD_SUIT_DIAMONDS, CARD_NUMBER_EIGHT},
	{"LD_CARD:cd9d", CARD_SUIT_DIAMONDS, CARD_NUMBER_NINE},
	{"LD_CARD:cd10d", CARD_SUIT_DIAMONDS, CARD_NUMBER_TEN},
	{"LD_CARD:cd11d", CARD_SUIT_DIAMONDS, CARD_NUMBER_JACK},
	{"LD_CARD:cd12d", CARD_SUIT_DIAMONDS, CARD_NUMBER_QUEEN},
	{"LD_CARD:cd13d", CARD_SUIT_DIAMONDS, CARD_NUMBER_KING},

	{"LD_CARD:cd1h", CARD_SUIT_HEARTS, CARD_NUMBER_ACE},
	{"LD_CARD:cd2h", CARD_SUIT_HEARTS, CARD_NUMBER_TWO},
	{"LD_CARD:cd3h", CARD_SUIT_HEARTS, CARD_NUMBER_THREE},
	{"LD_CARD:cd4h", CARD_SUIT_HEARTS, CARD_NUMBER_FOUR},
	{"LD_CARD:cd5h", CARD_SUIT_HEARTS, CARD_NUMBER_FIVE},
	{"LD_CARD:cd6h", CARD_SUIT_HEARTS, CARD_NUMBER_SIX},
	{"LD_CARD:cd7h", CARD_SUIT_HEARTS, CARD_NUMBER_SEVEN},
	{"LD_CARD:cd8h", CARD_SUIT_HEARTS, CARD_NUMBER_EIGHT},
	{"LD_CARD:cd9h", CARD_SUIT_HEARTS, CARD_NUMBER_NINE},
	{"LD_CARD:cd10h", CARD_SUIT_HEARTS, CARD_NUMBER_TEN},
	{"LD_CARD:cd11h", CARD_SUIT_HEARTS, CARD_NUMBER_JACK},
	{"LD_CARD:cd12h", CARD_SUIT_HEARTS, CARD_NUMBER_QUEEN},
	{"LD_CARD:cd13h", CARD_SUIT_HEARTS, CARD_NUMBER_KING},

	{"LD_CARD:cd1s", CARD_SUIT_SPADES, CARD_NUMBER_ACE},
	{"LD_CARD:cd2s", CARD_SUIT_SPADES, CARD_NUMBER_TWO},
	{"LD_CARD:cd3s", CARD_SUIT_SPADES, CARD_NUMBER_THREE},
	{"LD_CARD:cd4s", CARD_SUIT_SPADES, CARD_NUMBER_FOUR},
	{"LD_CARD:cd5s", CARD_SUIT_SPADES, CARD_NUMBER_FIVE},
	{"LD_CARD:cd6s", CARD_SUIT_SPADES, CARD_NUMBER_SIX},
	{"LD_CARD:cd7s", CARD_SUIT_SPADES, CARD_NUMBER_SEVEN},
	{"LD_CARD:cd8s", CARD_SUIT_SPADES, CARD_NUMBER_EIGHT},
	{"LD_CARD:cd9s", CARD_SUIT_SPADES, CARD_NUMBER_NINE},
	{"LD_CARD:cd10s", CARD_SUIT_SPADES, CARD_NUMBER_TEN},
	{"LD_CARD:cd11s", CARD_SUIT_SPADES, CARD_NUMBER_JACK},
	{"LD_CARD:cd12s", CARD_SUIT_SPADES, CARD_NUMBER_QUEEN},
	{"LD_CARD:cd13s", CARD_SUIT_SPADES, CARD_NUMBER_KING}
};
enum CASINO_BJ_CARD_ENUM {
	CASINO_BJ_CARD_NAME[16],
	CASINO_BJ_CARD_SUIT,
	CASINO_BJ_CARD_VALUE
};
new CASINO_BJ_CARD_INFO[MAX_CASINO_CARDS][CASINO_BJ_CARD_ENUM] = {
	{"LD_CARD:cd1c", CARD_SUIT_CLUBS, BJ_CARD_NUMBER_ACE},
	{"LD_CARD:cd2c", CARD_SUIT_CLUBS, BJ_CARD_NUMBER_TWO},
	{"LD_CARD:cd3c", CARD_SUIT_CLUBS, BJ_CARD_NUMBER_THREE},
	{"LD_CARD:cd4c", CARD_SUIT_CLUBS, BJ_CARD_NUMBER_FOUR},
	{"LD_CARD:cd5c", CARD_SUIT_CLUBS, BJ_CARD_NUMBER_FIVE},
	{"LD_CARD:cd6c", CARD_SUIT_CLUBS, BJ_CARD_NUMBER_SIX},
	{"LD_CARD:cd7c", CARD_SUIT_CLUBS, BJ_CARD_NUMBER_SEVEN},
	{"LD_CARD:cd8c", CARD_SUIT_CLUBS, BJ_CARD_NUMBER_EIGHT},
	{"LD_CARD:cd9c", CARD_SUIT_CLUBS, BJ_CARD_NUMBER_NINE},
	{"LD_CARD:cd10c", CARD_SUIT_CLUBS, BJ_CARD_NUMBER_TEN},
	{"LD_CARD:cd11c", CARD_SUIT_CLUBS, BJ_CARD_NUMBER_JACK},
	{"LD_CARD:cd12c", CARD_SUIT_CLUBS, BJ_CARD_NUMBER_QUEEN},
	{"LD_CARD:cd13c", CARD_SUIT_CLUBS, BJ_CARD_NUMBER_KING},

	{"LD_CARD:cd1d", CARD_SUIT_DIAMONDS, BJ_CARD_NUMBER_ACE},
	{"LD_CARD:cd2d", CARD_SUIT_DIAMONDS, BJ_CARD_NUMBER_TWO},
	{"LD_CARD:cd3d", CARD_SUIT_DIAMONDS, BJ_CARD_NUMBER_THREE},
	{"LD_CARD:cd4d", CARD_SUIT_DIAMONDS, BJ_CARD_NUMBER_FOUR},
	{"LD_CARD:cd5d", CARD_SUIT_DIAMONDS, BJ_CARD_NUMBER_FIVE},
	{"LD_CARD:cd6d", CARD_SUIT_DIAMONDS, BJ_CARD_NUMBER_SIX},
	{"LD_CARD:cd7d", CARD_SUIT_DIAMONDS, BJ_CARD_NUMBER_SEVEN},
	{"LD_CARD:cd8d", CARD_SUIT_DIAMONDS, BJ_CARD_NUMBER_EIGHT},
	{"LD_CARD:cd9d", CARD_SUIT_DIAMONDS, BJ_CARD_NUMBER_NINE},
	{"LD_CARD:cd10d", CARD_SUIT_DIAMONDS, BJ_CARD_NUMBER_TEN},
	{"LD_CARD:cd11d", CARD_SUIT_DIAMONDS, BJ_CARD_NUMBER_JACK},
	{"LD_CARD:cd12d", CARD_SUIT_DIAMONDS, BJ_CARD_NUMBER_QUEEN},
	{"LD_CARD:cd13d", CARD_SUIT_DIAMONDS, BJ_CARD_NUMBER_KING},

	{"LD_CARD:cd1h", CARD_SUIT_HEARTS, BJ_CARD_NUMBER_ACE},
	{"LD_CARD:cd2h", CARD_SUIT_HEARTS, BJ_CARD_NUMBER_TWO},
	{"LD_CARD:cd3h", CARD_SUIT_HEARTS, BJ_CARD_NUMBER_THREE},
	{"LD_CARD:cd4h", CARD_SUIT_HEARTS, BJ_CARD_NUMBER_FOUR},
	{"LD_CARD:cd5h", CARD_SUIT_HEARTS, BJ_CARD_NUMBER_FIVE},
	{"LD_CARD:cd6h", CARD_SUIT_HEARTS, BJ_CARD_NUMBER_SIX},
	{"LD_CARD:cd7h", CARD_SUIT_HEARTS, BJ_CARD_NUMBER_SEVEN},
	{"LD_CARD:cd8h", CARD_SUIT_HEARTS, BJ_CARD_NUMBER_EIGHT},
	{"LD_CARD:cd9h", CARD_SUIT_HEARTS, BJ_CARD_NUMBER_NINE},
	{"LD_CARD:cd10h", CARD_SUIT_HEARTS, BJ_CARD_NUMBER_TEN},
	{"LD_CARD:cd11h", CARD_SUIT_HEARTS, BJ_CARD_NUMBER_JACK},
	{"LD_CARD:cd12h", CARD_SUIT_HEARTS, BJ_CARD_NUMBER_QUEEN},
	{"LD_CARD:cd13h", CARD_SUIT_HEARTS, BJ_CARD_NUMBER_KING},

	{"LD_CARD:cd1s", CARD_SUIT_SPADES, BJ_CARD_NUMBER_ACE},
	{"LD_CARD:cd2s", CARD_SUIT_SPADES, BJ_CARD_NUMBER_TWO},
	{"LD_CARD:cd3s", CARD_SUIT_SPADES, BJ_CARD_NUMBER_THREE},
	{"LD_CARD:cd4s", CARD_SUIT_SPADES, BJ_CARD_NUMBER_FOUR},
	{"LD_CARD:cd5s", CARD_SUIT_SPADES, BJ_CARD_NUMBER_FIVE},
	{"LD_CARD:cd6s", CARD_SUIT_SPADES, BJ_CARD_NUMBER_SIX},
	{"LD_CARD:cd7s", CARD_SUIT_SPADES, BJ_CARD_NUMBER_SEVEN},
	{"LD_CARD:cd8s", CARD_SUIT_SPADES, BJ_CARD_NUMBER_EIGHT},
	{"LD_CARD:cd9s", CARD_SUIT_SPADES, BJ_CARD_NUMBER_NINE},
	{"LD_CARD:cd10s", CARD_SUIT_SPADES, BJ_CARD_NUMBER_TEN},
	{"LD_CARD:cd11s", CARD_SUIT_SPADES, BJ_CARD_NUMBER_JACK},
	{"LD_CARD:cd12s", CARD_SUIT_SPADES, BJ_CARD_NUMBER_QUEEN},
	{"LD_CARD:cd13s", CARD_SUIT_SPADES, BJ_CARD_NUMBER_KING}
};
enum {
	CASINO_LANGUAGE_ENGLISH = 0,
	CASINO_LANGUAGE_RUSSIAN
};
#define CASINO_DEFAULT_CHIPS_COURSE	(10)
#define CASINO_DEFAULT_DICE_COURSE	(10)

#define CASINO_WORLD_ID				(1)
#define CASINO_INTERIOR_ID			(77)

#define CASINO_DICE_MIN_BET			100
#define CASINO_DICE_MAX_BET			10000

enum casino_enum {
	casinoChipsCourse,
	casinoDiceCourse
};
new casinoDataInfo[casino_enum];

new const Float:casinoDiceAttachOffset[6][3] = {
	{-12.4, 79.400, 3.900},
	{-12.4, 169.80, 3.900},
	{77.80, 0.9000, 101.4},
	{77.80, 0.9000, -82.8},
	{-12.4, -12.40, 3.900},
	{-12.4, -100.7, 3.900}
};
new CasinoArea, PlayerText:CasinoRoulettePTD[MAX_PLAYERS];

#define CASINO_ROULETTE_TABLE_TIMER 	(30)
#define MAX_ROULETTE_TABLE_PLAYERS		15


enum CASINO_ROULETTE_TABLE_E {
	tableMinBet,
	tableMaxBet,

	Float:tablePos[3],
	Float:tableActorPos[4],

	tableWorld,
	tableInterior,

	tableActorID,
	Text3D:tableTextID,

	tableTimer,
	tableTimerID,
	tableTimerDeals,

	tableActiveBets,
	tableActivePlayers,
	tablePlayers[MAX_ROULETTE_TABLE_PLAYERS]
};
new CasinoRouletteTableInfo[][CASINO_ROULETTE_TABLE_E] = {
	{ 25, 500000, {1949.457153, 1742.249267, 1200.661254}, {1948.6173, 1742.4357, 1200.6866, 270.0}, CASINO_WORLD_ID, CASINO_INTERIOR_ID },
	{ 25, 500000, {1949.457153, 1737.408447, 1200.661254}, {1948.6169, 1737.5385, 1200.6866, 270.0}, CASINO_WORLD_ID, CASINO_INTERIOR_ID },

	{ 25, 500000, {1949.457153, 1742.249267, 1200.661254}, {1948.6173, 1742.4357, 1200.6866, 270.0}, CASINO_WORLD_ID + 2, CASINO_INTERIOR_ID },
	{ 25, 500000, {1949.457153, 1737.408447, 1200.661254}, {1948.6169, 1737.5385, 1200.6866, 270.0}, CASINO_WORLD_ID + 2, CASINO_INTERIOR_ID }
};
new const Float:CasinoFishPositions[][6] = {
	{ 1965.161254, 1739.187377, 1201.944576, 0.0, 0.0, 000.0 },
	{ 1964.170288, 1740.867309, 1201.056881, 0.0, 0.0, 090.0 },
	{ 1962.159912, 1739.257080, 1200.69067, 0.0, 0.0, 180.0  },
	{ 1963.430297, 1737.976196, 1202.939694, 0.0, 0.0, 270.0 }
};
new const Float:CasinoDiceTableInfo[][3] = {
	{ 1950.792358, 1728.455566, 1200.171020 },
	{ 1950.792358, 1732.586547, 1200.171020 },

	{ 1950.792358, 1728.455566, 1200.171020 },
	{ 1950.792358, 1732.586547, 1200.171020 }
};
enum CasinoFishEnum {
	cfObjectID,
	cfStep
};
new CasinoFishInfo[sizeof (CasinoFishPositions)][CasinoFishEnum];

casino_OnPlayerLeaveDynamicArea(playerid, areaid) {
	if (areaid == CasinoArea) {
		HideCasinoChipsPTD(playerid);
	}
	if (
		PI[playerid][pDiceTargetID] != INVALID_PLAYER_ID && 
		PI[playerid][pDiceAreaID] != (-1) && 
		areaid == PI[playerid][pDiceAreaID]
	) {
		return casino_ResetDice(playerid, 1), true;
	}
	return false;
}

new CasinoActorsID[6];


casino_OnGameModeInit() {
	AI_CreateActor(11, 1964.0521, 1728.4744, 1200.0021, 4.0417, CASINO_WORLD_ID + 0, CASINO_INTERIOR_ID);
	AI_CreateActor(11, 1964.0521, 1728.4744, 1200.0021, 4.0417, CASINO_WORLD_ID + 2, CASINO_INTERIOR_ID);

	AI_CreateActor(171, 1969.7871, 1738.1400, 1200.0021, 89.9194, CASINO_WORLD_ID + 0, CASINO_INTERIOR_ID);
	AI_CreateActor(171, 1969.7871, 1738.1400, 1200.0021, 89.9194, CASINO_WORLD_ID + 2, CASINO_INTERIOR_ID);

	CasinoActorsID[0] = AI_CreateActor(87, 1963.2107, 1734.4945, 1206.9414, 152.8812, CASINO_WORLD_ID + 0, CASINO_INTERIOR_ID);
	CasinoActorsID[1] = AI_CreateActor(152, 1968.5983, 1738.9155, 1206.9414, 213.6267, CASINO_WORLD_ID + 0, CASINO_INTERIOR_ID);
	CasinoActorsID[2] = AI_CreateActor(178, 1958.6802, 1738.9683, 1206.9414, 186.5108, CASINO_WORLD_ID + 0, CASINO_INTERIOR_ID);
	CasinoActorsID[3] = AI_CreateActor(237, 1963.2107, 1734.4945, 1206.9414, 152.8812, CASINO_WORLD_ID + 2, CASINO_INTERIOR_ID);
	CasinoActorsID[4] = AI_CreateActor(87, 1968.5983, 1738.9155, 1206.9414, 213.6267, CASINO_WORLD_ID + 2, CASINO_INTERIOR_ID);
	CasinoActorsID[5] = AI_CreateActor(152, 1958.6802, 1738.9683, 1206.9414, 186.5108, CASINO_WORLD_ID + 2, CASINO_INTERIOR_ID);


	for(new fish_id = 0; fish_id < sizeof (CasinoFishInfo); fish_id++) {
		new fish_stepid = CasinoFishInfo[fish_id][cfStep] = fish_id;

		CasinoFishInfo[fish_id][cfObjectID] = CreateDynamicObject(1601, 
			CasinoFishPositions[fish_stepid][0], CasinoFishPositions[fish_stepid][1], CasinoFishPositions[fish_stepid][2],
			CasinoFishPositions[fish_stepid][3], CasinoFishPositions[fish_stepid][4], CasinoFishPositions[fish_stepid][5],
			-1, CASINO_INTERIOR_ID, -1, 50.00, 50.00
		);
		fish_stepid = CasinoFishInfo[fish_id][cfStep]++;

		MoveDynamicObject(CasinoFishInfo[fish_id][cfObjectID], 
			CasinoFishPositions[fish_stepid][0], CasinoFishPositions[fish_stepid][1], CasinoFishPositions[fish_stepid][2],
			1.0,
			CasinoFishPositions[fish_stepid][3], CasinoFishPositions[fish_stepid][4], CasinoFishPositions[fish_stepid][5]
		);
	}
	new Float:casinoTablePosZ = CasinoRouletteTableInfo[0][tablePos][2] + 0.25; // CasinoDiceTableInfo[dice_tableid][2] + 0.7

	for (new roulette_tableid = 0; roulette_tableid < sizeof (CasinoRouletteTableInfo); roulette_tableid++) {
		CasinoRouletteTableInfo[roulette_tableid][tableActorID] = AI_CreateActor(11,
			CasinoRouletteTableInfo[roulette_tableid][tableActorPos][0], CasinoRouletteTableInfo[roulette_tableid][tableActorPos][1], 
			CasinoRouletteTableInfo[roulette_tableid][tableActorPos][2], CasinoRouletteTableInfo[roulette_tableid][tableActorPos][3], 
			CasinoRouletteTableInfo[roulette_tableid][tableWorld], CASINO_INTERIOR_ID
		);
		CasinoRouletteTableInfo[roulette_tableid][tableTextID] = CreateDynamic3DTextLabel(
			"{d8284c}Ruletka\n \n{FFFFFF}Daachiret {d8284c}\"ENTER\"", 0xFFFFFFFF, 
			CasinoRouletteTableInfo[roulette_tableid][tablePos][0], CasinoRouletteTableInfo[roulette_tableid][tablePos][1], casinoTablePosZ, 
			5.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, CasinoRouletteTableInfo[roulette_tableid][tableWorld], CASINO_INTERIOR_ID, -1
		);
		CasinoRouletteTableInfo[roulette_tableid][tableTimerDeals] = 0;
		CasinoRouletteTableInfo[roulette_tableid][tableTimerID] = -1;
		CasinoRouletteTableInfo[roulette_tableid][tableTimer] = CASINO_ROULETTE_TABLE_TIMER + 5 + (roulette_tableid * 15);

		for (new slotid = 0; slotid < MAX_ROULETTE_TABLE_PLAYERS; slotid++) {
			CasinoRouletteTableInfo[roulette_tableid][tablePlayers][slotid] = INVALID_PLAYER_ID;
		}
		CasinoRouletteTableInfo[roulette_tableid][tableActiveBets] = 0;
		CasinoRouletteTableInfo[roulette_tableid][tableActivePlayers] = 0;
	}
	/*for (new dice_tableid = 0; dice_tableid < sizeof (CasinoDiceTableInfo); dice_tableid++) {
		CreateDynamic3DTextLabel("{d8284c}Qvebis gagoreba\n \n{FFFFFF}gamoiyenet {d8284c}/dice", 0xFFFFFFFF, 
			CasinoDiceTableInfo[dice_tableid][0], CasinoDiceTableInfo[dice_tableid][1], casinoTablePosZ, 5.0, 
			INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, CASINO_WORLD_ID, CASINO_INTERIOR_ID, -1
		);
	}*/
	casinoDataInfo[casinoChipsCourse] = CASINO_DEFAULT_CHIPS_COURSE;
	casinoDataInfo[casinoDiceCourse] = CASINO_DEFAULT_DICE_COURSE;

	CasinoArea = CreateDynamicSphere(1963.279052, 1723.016357, 1205.734985, 120.0, -1, CASINO_INTERIOR_ID);
}
/*
CMD:dice(playerid, params[]) {
	new targetid, bet;
	if (sscanf(params, "ud", targetid, bet) || targetid == playerid || bet < CASINO_DICE_MIN_BET || bet > CASINO_DICE_MAX_BET) 
		return SendEsp(playerid, "/dice [motamashis ID] [fishkebi raodenoba] ("#CASINO_DICE_MIN_BET" - "#CASINO_DICE_MAX_BET")");
	if (!IsPlayerConnected(targetid)) 
		return ErrorMessage(playerid, "Motamashe ar aris online!"), true;

	new Float:player_pos[3], Float:target_pos[3];
	GetPlayerPos(playerid, player_pos[0], player_pos[1], player_pos[2]);
	GetPlayerPos(targetid, target_pos[0], target_pos[1], target_pos[2]);

	if (PI[playerid][pDiceAttached] || PI[targetid][pDiceAttached])
		return ErrorMessage(playerid, "Scadet mogvianebit!"), true;
	if (!IsPlayerInRangeOfPoint(playerid, 4.0, target_pos[0], target_pos[1], target_pos[2]) || GetPlayerVirtualWorld(playerid) != GetPlayerVirtualWorld(targetid) || GetPlayerInterior(playerid) != GetPlayerInterior(targetid))
		return ErrorMessage(playerid, "Tqven motamashisgan shors xart!"), true;
	if (GetChips(playerid) < bet)
		return ErrorMessage(playerid, "Tqven ar gaqvt sakmarisi fishkebi satamashot!"), true;
	if (GetChips(targetid) < bet)
		return ErrorMessage(playerid, "Motamashes ar aqvs sakmarisi fishkebi satamashot!"), true;
	if (!PI[playerid][pCasinoDice])
		return ErrorMessage(playerid, "Tqven ar gaqvt sakmarisi qvebi satamashot!"), true;
	if (!PI[targetid][pCasinoDice])
		return ErrorMessage(playerid, "Motamashes ar aqvs sakmarisi qvebi!"), true;
	new dice_table_id = -1;
	for (new dice_tableid = 0; dice_tableid < sizeof (CasinoDiceTableInfo); dice_tableid++) {
		if (!IsPlayerInRangeOfPoint(playerid, 4.0, CasinoDiceTableInfo[dice_tableid][0], CasinoDiceTableInfo[dice_tableid][1], CasinoDiceTableInfo[dice_tableid][2]))
			continue;

		if (TI[targetid][tDialog] && (OldDialogID[targetid] == _:DIALOG_CASINO_DICE_1 || OldDialogID[targetid] == _:DIALOG_CASINO_DICE_2))
			return ErrorMessage(playerid, "Mocemul dros motmaashe ver miigebs gamodzaxebas!"), true;
		if (INVALID_PLAYER_ID != PI[targetid][pDiceTargetID]) 
			return ErrorMessage(playerid, "Motamashes ukve shestavazes tamashi!"), true;
		
		PI[playerid][pDiceAreaID] = PI[targetid][pDiceAreaID] = CreateDynamicSphere(
			((player_pos[0] + target_pos[0]) / 2), 
			((player_pos[1] + target_pos[1]) / 2),
			((player_pos[2] + target_pos[2]) / 2),
			10.0, GetPlayerVirtualWorld(playerid), GetPlayerInterior(playerid), -1
		);
		format(STRING_GLOBAL, sizeof(STRING_GLOBAL), 
			"{FFFFFF}Motamashe {d8284c}%s {FFFFFF}shemogtavazat qvebis gagoreba.\n\n\
			{FFFFFF}Fsoni: {d8284c}%d fishka\n\n\
			{FFFFFF}Gsurt tamashi?",
			GetName((PI[targetid][pDiceTargetID] = playerid)), 
			(PI[playerid][pDiceBet] = PI[targetid][pDiceBet] = bet)
		);
		ShowPlayerDialog((PI[playerid][pDiceTargetID] = targetid), DIALOG_CASINO_DICE_1, DIALOG_STYLE_MSGBOX, "{d8284c}Qvebis gagoreba", 
			STRING_GLOBAL, "Ki", "Ara"
		), STRING_GLOBAL[0] = EOS;

		dice_table_id = dice_tableid;
		break;
	}
	if (-1 == dice_table_id)
		return ErrorMessage(playerid, "Tqven unda iyot satamasho magidastan!"), true; 
    return true;
}*/
CB:casino_DiceDeAttach(playerid, targetid) {
	if (playerid != INVALID_PLAYER_ID && PI[playerid][pDiceAttached] && IsPlayerAttachedObjectSlotUsed(playerid, 9)) 
		RemovePlayerAttachedObject(playerid, 9), PI[playerid][pDiceAttached] = 0;
	if (targetid != INVALID_PLAYER_ID && PI[targetid][pDiceAttached] && IsPlayerAttachedObjectSlotUsed(targetid, 9)) 
		RemovePlayerAttachedObject(targetid, 9), PI[targetid][pDiceAttached] = 0;

	ApplyAnimation(playerid, "PED", "FLOOR_hit_f", 4.1, 0, 1, 1, 0, 1); 
	ApplyAnimation(targetid, "PED", "FLOOR_hit_f", 4.1, 0, 1, 1, 0, 1); 
}
stock casino_ResetDice(playerid, message = 0) {
	new targetid = PI[playerid][pDiceTargetID];
	if (targetid == INVALID_PLAYER_ID) 
		return false;
	if (message && IsPlayerConnected(targetid)) 
		SendFormattedMessage(targetid, COLOR_WHITE, "Motamashe {228B22}%s 'm {FFFFFF}uari tqva tamashze.", GetName(playerid));
	if ((-1) != PI[playerid][pDiceAreaID]) {
		new areaid = PI[playerid][pDiceAreaID];
		PI[playerid][pDiceAreaID] = PI[targetid][pDiceAreaID] = (-1);
		DestroyDynamicArea(areaid);
	}
	PI[playerid][pDiceTargetID] = PI[targetid][pDiceTargetID] = INVALID_PLAYER_ID;
	PI[playerid][pDiceBet] = 0;

	return true;
}
CMD:language2(playerid) {
	if(PI[playerid][pAdmin] < 6 || dostup[playerid] == 0) 
		return true;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), 
		"{d8284c}1. {%s}English\n{d8284c}2. {%s}Qartuli", 
		(CASINO_LANGUAGE_ENGLISH == PI[playerid][pCasinoLanguage]) ? ("9ACD32") : ("FFFFFF"),
		(CASINO_LANGUAGE_RUSSIAN == PI[playerid][pCasinoLanguage]) ? ("9ACD32") : ("FFFFFF")
	); 
	ShowPlayerDialog(playerid, DIALOG_CASINO_LANGUAGE, DIALOG_STYLE_LIST, "{d8284c}Interfeisis ena", 
		STRING_GLOBAL, "Migeba", "Gamosvla"
	), STRING_GLOBAL[0] = EOS;
	return true;
}
CMD:lang2(playerid) 
	return callcmd::language2(playerid);
casino_OnPlayerConnect(playerid) {
	PI[playerid][pDiceAreaID] = -1;
	PI[playerid][pDiceTargetID] = INVALID_PLAYER_ID;
	PI[playerid][pDiceBet] =  PI[playerid][pDiceAttached] = 0;

	PI[playerid][pCasinoDice] = 10000;
	return true;
}
casino_OnPlayerDisconnect(playerid) {
	casino_ResetDice(playerid);
	casino_LeaveRouletteTable(playerid);
	HideCasinoChipsPTD(playerid);
	return true;
}
casino_OnPlayerDeath(playerid) {
	casino_ResetDice(playerid);
	casino_LeaveRouletteTable(playerid);
	return true;
}
new PlayerText:CasinoChipsPTD[MAX_PLAYERS][3];

stock ShowCasinoChipsPTD(playerid) {
	if (TI[playerid][tCasinoChipsPTD]) 
		return false;
	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "~p~%d", PI[playerid][pCasinoChips]);
	CasinoChipsPTD[playerid][0] = CreatePlayerTextDraw(playerid, 608.214538, 282.716491 + 7.0, STRING_GLOBAL), STRING_GLOBAL[0] = EOS;

	PlayerTextDrawLetterSize(playerid, CasinoChipsPTD[playerid][0], 0.300030, 1.390000);
	PlayerTextDrawTextSize(playerid, CasinoChipsPTD[playerid][0], 0.000000, 64.000000);
	PlayerTextDrawAlignment(playerid, CasinoChipsPTD[playerid][0], 2);
	PlayerTextDrawColor(playerid, CasinoChipsPTD[playerid][0], -1);
	PlayerTextDrawUseBox(playerid, CasinoChipsPTD[playerid][0], 1);
	PlayerTextDrawBoxColor(playerid, CasinoChipsPTD[playerid][0], 252645375);
	PlayerTextDrawSetShadow(playerid, CasinoChipsPTD[playerid][0], 0);
	PlayerTextDrawSetOutline(playerid, CasinoChipsPTD[playerid][0], 1);
	PlayerTextDrawBackgroundColor(playerid, CasinoChipsPTD[playerid][0], 255);
	PlayerTextDrawFont(playerid, CasinoChipsPTD[playerid][0], 1);
	PlayerTextDrawSetProportional(playerid, CasinoChipsPTD[playerid][0], 1);

	CasinoChipsPTD[playerid][1 + 0] = CreatePlayerTextDraw(playerid, 559.631164, 276.133331 + 7.0, "ld_beat:chit");
	PlayerTextDrawTextSize(playerid, CasinoChipsPTD[playerid][1 + 0], 26.000000, 26.000000);
	PlayerTextDrawAlignment(playerid, CasinoChipsPTD[playerid][1 + 0], 1);
	PlayerTextDrawColor(playerid, CasinoChipsPTD[playerid][1 + 0], 252645375);
	PlayerTextDrawSetShadow(playerid, CasinoChipsPTD[playerid][1 + 0], 0);
	PlayerTextDrawBackgroundColor(playerid, CasinoChipsPTD[playerid][1 + 0], 255);
	PlayerTextDrawFont(playerid, CasinoChipsPTD[playerid][1 + 0], 4);
	PlayerTextDrawSetProportional(playerid, CasinoChipsPTD[playerid][1 + 0], 0);

	CasinoChipsPTD[playerid][1 + 1] = CreatePlayerTextDraw(playerid, 555.014526, 269.333343 + 7.0, "_");
	PlayerTextDrawTextSize(playerid, CasinoChipsPTD[playerid][1 + 1], 35.000000, 35.000000);
	PlayerTextDrawAlignment(playerid, CasinoChipsPTD[playerid][1 + 1], 1);
	PlayerTextDrawColor(playerid, CasinoChipsPTD[playerid][1 + 1], -1);
	PlayerTextDrawSetShadow(playerid, CasinoChipsPTD[playerid][1 + 1], 0);
	PlayerTextDrawBackgroundColor(playerid, CasinoChipsPTD[playerid][1 + 1], 0);
	PlayerTextDrawFont(playerid, CasinoChipsPTD[playerid][1 + 1], 5);
	PlayerTextDrawSetProportional(playerid, CasinoChipsPTD[playerid][1 + 1], 0);
	PlayerTextDrawSetPreviewModel(playerid, CasinoChipsPTD[playerid][1 + 1], 1910);
	PlayerTextDrawSetPreviewRot(playerid, CasinoChipsPTD[playerid][1 + 1], 270.000000, 0.000000, 0.000000, 1.000000);

	for (new textdraw_id = 0; textdraw_id < 3; textdraw_id++)
		PlayerTextDrawShow(playerid, CasinoChipsPTD[playerid][textdraw_id]);
	TI[playerid][tCasinoChipsPTD] = 1;

	UpdateCasinoChipsPTD(playerid);
	return true;
}
stock HideCasinoChipsPTD(playerid) {
	if (!TI[playerid][tCasinoChipsPTD]) 
		return false;
	for (new textdraw_id = 0; textdraw_id < 3; textdraw_id++) {
		PlayerTextDrawHide(playerid, CasinoChipsPTD[playerid][textdraw_id]);
		PlayerTextDrawDestroy(playerid, CasinoChipsPTD[playerid][textdraw_id]);
	}
	return TI[playerid][tCasinoChipsPTD] = 0;
}
stock UpdateCasinoChipsPTD(playerid) {
	if (!TI[playerid][tCasinoChipsPTD]) return;
	if (PI[playerid][pPokerTableID])
		format(STRING_GLOBAL, sizeof (STRING_GLOBAL), "~p~%d", PI[playerid][pPokerChips]);
	else format(STRING_GLOBAL, sizeof (STRING_GLOBAL), "~p~%d", PI[playerid][pCasinoChips]);

	PlayerTextDrawSetString(playerid, CasinoChipsPTD[playerid][0], STRING_GLOBAL), STRING_GLOBAL[0] = EOS;
}
SetPlayerPosObjectOffset(objectid, playerid, Float:offset_x, Float:offset_y, Float:offset_z)
{
	new Float:object_px,
        Float:object_py,
        Float:object_pz,
        Float:object_rx,
        Float:object_ry,
        Float:object_rz;

    GetDynamicObjectPos(objectid, object_px, object_py, object_pz);
    GetDynamicObjectRot(objectid, object_rx, object_ry, object_rz);

    new Float:cos_x = floatcos(object_rx, degrees),
        Float:cos_y = floatcos(object_ry, degrees),
        Float:cos_z = floatcos(object_rz, degrees),
        Float:sin_x = floatsin(object_rx, degrees),
        Float:sin_y = floatsin(object_ry, degrees),
        Float:sin_z = floatsin(object_rz, degrees);

	new Float:x, Float:y, Float:z;

    x = object_px + offset_x * cos_y * cos_z - offset_x * sin_x * sin_y * sin_z - offset_y * cos_x * sin_z + offset_z * sin_y * cos_z + offset_z * sin_x * cos_y * sin_z;
    y = object_py + offset_x * cos_y * sin_z + offset_x * sin_x * sin_y * cos_z + offset_y * cos_x * cos_z + offset_z * sin_y * sin_z - offset_z * sin_x * cos_y * cos_z;
    z = object_pz - offset_x * cos_x * sin_y + offset_y * sin_x + offset_z * cos_x * cos_y;

	SetPlayerPos(playerid, x, y, z);
	return 1;
}
CameraRadiusSetPos(playerid, Float:x, Float:y, Float:z, Float:degree = 0.0, Float:height = 3.0, Float:radius = 8.0)
{
	new Float:deltaToX = x + radius * floatsin(-degree, degrees);
	new Float:deltaToY = y + radius * floatcos(-degree, degrees);
	new Float:deltaToZ = z + height;

	SetPlayerCameraPos(playerid, deltaToX, deltaToY, deltaToZ);
	SetPlayerCameraLookAt(playerid, x, y, z); return 1;
}
ArraySort(array[], size) {
	new i, j, app;
	for (i = 1; i < size; i++) {
		app = array[i];
		for (j = i - 1; (j >= 0) && (array[j] > app); j--)
			array[j + 1 ] = array[j];
		array[j + 1] = app;
	}
	return 1;
}
stock strreplace(string[], const search[], const replacement[], bool:ignorecase = false, pos = 0, limit = -1, maxlength = sizeof(string)) {
	if (limit == 0)
		return 0;
	new
		sublen = strlen(search),
		replen = strlen(replacement),
		bool:packed = ispacked(string),
		maxlen = maxlength,
		len = strlen(string),
		count = 0
	;
	if (packed)
		maxlen *= 4;
	if (!sublen)
		return 0;
	while (-1 != (pos = strfind(string, search, ignorecase, pos))) {
		strdel(string, pos, pos + sublen);
 
		len -= sublen;

		if (replen && len + replen < maxlen) {
			strins(string, replacement, pos, maxlength);
			pos += replen, len += replen;
		}
		if (limit != (-1) && (++count) >= limit)
			break;
	}
	return count;
}
stock Dialog_Close(playerid) {
	return ShowPlayerDialog(playerid, -1, 0, "", "", "", "");
}

casino_Timer() {
	for (new tableid = 0; tableid < sizeof (CasinoRouletteTableInfo); tableid++) {
		if (CasinoRouletteTableInfo[tableid][tableTimer]) {
			if (CasinoRouletteTableInfo[tableid][tableActiveBets] == 0) { 
				CasinoRouletteTableInfo[tableid][tableTimer] = CASINO_ROULETTE_TABLE_TIMER + 1;
				format(COMMAND_GLOBAL, sizeof (COMMAND_GLOBAL), 
					"{d8284c}Ruletka\n \n\
					"W"Minimaluri fsoni: {d8284c}%d\n\
					"W"Maksimaluri fsoni: {d8284c}%d\n \n\
					"G"Pirveli fsonis molodinshia.\n \n\
					"W"Daachiret {d8284c}\"ENTER\"",
					CasinoRouletteTableInfo[tableid][tableMinBet],
					CasinoRouletteTableInfo[tableid][tableMaxBet],
					CasinoRouletteTableInfo[tableid][tableTimer]
				);
			} 
			else if (--CasinoRouletteTableInfo[tableid][tableTimer] <= 0) {
				ApplyDynamicActorAnimation(CasinoRouletteTableInfo[tableid][tableActorID], "BD_FIRE", "wash_up", 4.1, 0, 1, 1, 1, 1);

				CasinoRouletteTableInfo[tableid][tableTimerDeals] = RandomEx(35, 45);
				CasinoRouletteTableInfo[tableid][tableTimerID] = SetTimerEx("casino_RouletteTimer", 250, false, "i", tableid);
				CasinoRouletteTableInfo[tableid][tableTimer] = 0;

				format(COMMAND_GLOBAL, sizeof (COMMAND_GLOBAL), 
					"{d8284c}Ruletka\n \n\
					"W"Minimaluri fsoni: {d8284c}%d\n\
					"W"Maksimaluri fsoni: {d8284c}%d\n \n\
					"P"Ruletka dawyebulia!\n \n\
					"W"Daachiret {d8284c}\"ENTER\"",
					CasinoRouletteTableInfo[tableid][tableMinBet],
					CasinoRouletteTableInfo[tableid][tableMaxBet]
				);
				for (new slotid = 0, playerid; slotid < MAX_ROULETTE_TABLE_PLAYERS; slotid++) {
					playerid = CasinoRouletteTableInfo[tableid][tablePlayers][slotid];
					if (playerid == INVALID_PLAYER_ID)
						continue;
					if (TI[playerid][tCasinoRouletteTable] != tableid + 1) 
						continue;
					if (TI[playerid][tCasinoRouletteBet] == 0 && TI[playerid][tCasinoRouletteChipsObject] != -1) 
						DestroyDynamicObject(TI[playerid][tCasinoRouletteChipsObject]);
				}
			} else {
				format(COMMAND_GLOBAL, sizeof (COMMAND_GLOBAL), 
					"{d8284c}Ruletka\n \n\
					"W"Minimaluri fsoni: {d8284c}%d\n\
					"W"Maksimaluri fsoni: {d8284c}%d\n \n\
					"W"Daiwyeba "P"%i "W"wamshi.\n \n\
					"W"Daachiret {d8284c}\"ENTER\"",
					CasinoRouletteTableInfo[tableid][tableMinBet],
					CasinoRouletteTableInfo[tableid][tableMaxBet],
					CasinoRouletteTableInfo[tableid][tableTimer]
				);
			}
			UpdateDynamic3DTextLabelText(CasinoRouletteTableInfo[tableid][tableTextID], 0xFFFFFFFF, COMMAND_GLOBAL);

			COMMAND_GLOBAL[0] = EOS;
		}
	}
}
CB:casino_RouletteTimer(tableid) {
	CasinoRouletteTableInfo[tableid][tableTimerDeals]--;

	new 
		win_Line = 4, win_Color = 3,
		win_Number = random(37);

	switch (win_Number) {
		case 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36: win_Color = 1; // RED
		case 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35: win_Color = 2; // BLACK
	}
	switch (win_Number) {
		case 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36: win_Line = 3; // –яƒ
		case 2, 5, 8, 11, 14, 17, 20, 23, 26, 29, 32, 35: win_Line = 2; // –яƒ
		case 1, 4, 7, 10, 13, 16, 19, 22, 25, 28, 31, 34: win_Line = 1; // –яƒ
	}
	new color[10];
	switch (win_Number) {
		case 0: {
			format(color, sizeof (color), "{228B22}");
			format(COMMAND_GLOBAL, sizeof (COMMAND_GLOBAL), "~g~%d", win_Number);
		}
		case 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36:  { 
			format(color, sizeof (color), "{DC143C}");
			format(COMMAND_GLOBAL, sizeof (COMMAND_GLOBAL), "~r~%d", win_Number);
		}
		case 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35: {
			format(color, sizeof (color), "{2E2E2E}");
			format(COMMAND_GLOBAL, sizeof (COMMAND_GLOBAL), "%d", win_Number);
		}
	}
	if (CasinoRouletteTableInfo[tableid][tableTimerDeals] <= 0) {

		new Float:objectPos[3];
		
		for (new slotid = 0, playerid; slotid < MAX_ROULETTE_TABLE_PLAYERS; slotid++) {
			playerid = CasinoRouletteTableInfo[tableid][tablePlayers][slotid];
			if (playerid == INVALID_PLAYER_ID)
				continue;
			if (TI[playerid][tCasinoRouletteTable] != tableid + 1) 
				continue;
			PlayerTextDrawSetString(playerid, CasinoRoulettePTD[playerid], COMMAND_GLOBAL), COMMAND_GLOBAL[0] = EOS;

			if(
				TI[playerid][tCasinoRouletteChips] <= 36 && TI[playerid][tCasinoRouletteChips] >= 0 && 
				win_Number == TI[playerid][tCasinoRouletteChips] // „исла 
			) {
				casino_OnPlayerWinRoulette(playerid, 20, win_Number, color); 
			}
			else if(
				(win_Color == 1 && TI[playerid][tCasinoRouletteChips] == 38) ||
				(win_Color == 2 && TI[playerid][tCasinoRouletteChips] == 37) // „ерное или красное
			) {
				casino_OnPlayerWinRoulette(playerid, 2, win_Number, color); 
			}
			else if(TI[playerid][tCasinoRouletteChips] == 39 && win_Number >= 1 && win_Number <= 12) // 1-12
				casino_OnPlayerWinRoulette(playerid, 3, win_Number, color); 
			else if(TI[playerid][tCasinoRouletteChips] == 40 && win_Number >= 13 && win_Number <= 24) // 13-24
				casino_OnPlayerWinRoulette(playerid, 3, win_Number, color); 
			else if(TI[playerid][tCasinoRouletteChips] == 41 && win_Number >= 25 && win_Number <= 36) // 25-36
				casino_OnPlayerWinRoulette(playerid, 3, win_Number, color); 
			else if(TI[playerid][tCasinoRouletteChips] == 42 && win_Number >= 1 && win_Number <= 18) // 1-18
				casino_OnPlayerWinRoulette(playerid, 2, win_Number, color); 
			else if(TI[playerid][tCasinoRouletteChips] == 43 && win_Number >= 19 && win_Number <= 36) // 19-36
				casino_OnPlayerWinRoulette(playerid, 2, win_Number, color); 
			else if(TI[playerid][tCasinoRouletteChips] == 44 && win_Number >= 2 && win_Number <= 36 && IsEven(win_Number)) // „етное
				casino_OnPlayerWinRoulette(playerid, 2, win_Number, color); 
			else if(TI[playerid][tCasinoRouletteChips] == 45 && win_Number >= 1 && win_Number <= 35 && !IsEven(win_Number)) // Ќечетное
				casino_OnPlayerWinRoulette(playerid, 2, win_Number, color); 
			else if(TI[playerid][tCasinoRouletteChips] == 46 && win_Line == 1) // 1 р€д
				casino_OnPlayerWinRoulette(playerid, 3, win_Number, color); 
			else if(TI[playerid][tCasinoRouletteChips] == 47 && win_Line == 2) // 2 р€д
				casino_OnPlayerWinRoulette(playerid, 3, win_Number, color); 
			else if(TI[playerid][tCasinoRouletteChips] == 48 && win_Line == 3) // 3 р€д
				casino_OnPlayerWinRoulette(playerid, 3, win_Number, color); 
			else if (TI[playerid][tCasinoRouletteBet]) {
				format(COMMAND_GLOBAL, sizeof (COMMAND_GLOBAL), 
					"Amovida cifri Ч %s%d"G". Tqven waaget {d8284c}%d Fishkebi"G"!", 
					color, win_Number, TI[playerid][tCasinoRouletteBet]
				);
				SendOk(playerid, COMMAND_GLOBAL);
			}
			else {
				format(COMMAND_GLOBAL, sizeof (COMMAND_GLOBAL), 
					"Amovida cifri Ч %s%d"G". tqven ar gaaketet fsoni!", 
					color, win_Number, TI[playerid][tCasinoRouletteBet]
				);
				SendOk(playerid, COMMAND_GLOBAL);
			}
			TI[playerid][tCasinoRouletteChipsPos] = 0;
			TI[playerid][tCasinoRouletteChips] = 0;
			TI[playerid][tCasinoRouletteBet] = 0;

			PlayerTextDrawSetString(playerid, InformationPTD[playerid][0], " ");
			PlayerTextDrawSetString(playerid, InformationPTD[playerid][1], " ");
			PlayerTextDrawSetString(playerid, InformationPTD[playerid][2], "~w~~h~YOUR BET:~n~~w~~h~AMOUNT:");

			if (TI[playerid][tCasinoRouletteChipsObject] != -1) 
				DestroyDynamicObject(TI[playerid][tCasinoRouletteChipsObject]);
			GetRouletteChipsPos(tableid, TI[playerid][tCasinoRouletteChipsPos], objectPos[0], objectPos[1], objectPos[2]);
			TI[playerid][tCasinoRouletteChipsObject] = CreateDynamicObject(1913,
				objectPos[0], objectPos[1], objectPos[2], 0.0, 0.0, 0.0, 
				CasinoRouletteTableInfo[tableid][tableWorld], CASINO_INTERIOR_ID, -1, 50, 50
			);
			Streamer_Update(playerid, STREAMER_TYPE_OBJECT);
		}
		CasinoRouletteTableInfo[tableid][tableActiveBets] = 0;
		CasinoRouletteTableInfo[tableid][tableTimerDeals] = 0;
		CasinoRouletteTableInfo[tableid][tableTimerID] = -1;
		CasinoRouletteTableInfo[tableid][tableTimer] = CASINO_ROULETTE_TABLE_TIMER + 5;
	} else {
		for (new slotid = 0, playerid; slotid < MAX_ROULETTE_TABLE_PLAYERS; slotid++) {
			playerid = CasinoRouletteTableInfo[tableid][tablePlayers][slotid];
			if (playerid == INVALID_PLAYER_ID)
				continue;
			if (TI[playerid][tCasinoRouletteTable] != tableid + 1) 
				continue;
			PlayerTextDrawSetString(playerid, CasinoRoulettePTD[playerid], COMMAND_GLOBAL), COMMAND_GLOBAL[0] = EOS;
		}
		CasinoRouletteTableInfo[tableid][tableTimerID] = SetTimerEx("casino_RouletteTimer", 250, false, "i", tableid);
	}
	COMMAND_GLOBAL[0] = EOS;
}
casino_OnPlayerWinRoulette(playerid, multiplier, win_Number, const color[]) {
	new win_Money = (TI[playerid][tCasinoRouletteBet] * multiplier) - ((TI[playerid][tCasinoRouletteBet] * multiplier) / 10);

	format(COMMAND_GLOBAL, sizeof (COMMAND_GLOBAL), 
		"Amovida cifri Ч %s%d"G". Tqven moiget {d8284c}%d fishka"G"!",
		color, win_Number, win_Money
	);
	SendOk(playerid, COMMAND_GLOBAL);

	GiveChips(playerid, win_Money, "OnPlayerWinRoulette");

	//PlayerTextDrawSetString(playerid, casino_roulette_PTD[playerid][1], "~w~BС BETS: ~y~-~n~~w~TQVENI FSONI: ~g~$0");

	return true;
}

casino_PlayerTimer(playerid) {
	UpdateCasinoChipsPTD(playerid);

	if (!TI[playerid][tCasinoRouletteTable]) return;
	new tableid = TI[playerid][tCasinoRouletteTable] - 1;

	if (CasinoRouletteTableInfo[tableid][tableActiveBets] == 0 && CasinoRouletteTableInfo[tableid][tableTimer] == CASINO_ROULETTE_TABLE_TIMER + 1) {
		PlayerTextDrawSetString(playerid, CasinoRoulettePTD[playerid], "~w~WAITING FOR BETS..");
	} else {
		if (0 < CasinoRouletteTableInfo[tableid][tableTimer] <= CASINO_ROULETTE_TABLE_TIMER) {
			format(COMMAND_GLOBAL, sizeof (COMMAND_GLOBAL), "~y~00:%02d",
				CasinoRouletteTableInfo[tableid][tableTimer]
			);
			PlayerTextDrawSetString(playerid, CasinoRoulettePTD[playerid], COMMAND_GLOBAL), COMMAND_GLOBAL[0] = EOS;
		}
	}
}

casino_OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (GetPlayerInterior(playerid) != CASINO_INTERIOR_ID) 
		return false;
	new bool:isReturn = false;

	if((newkeys & KEY_SPRINT) && !(oldkeys & KEY_SPRINT)) {
		if (TI[playerid][tCasinoRouletteTable] && TI[playerid][tCasinoRouletteChipsObject] != -1) {
			new tableid = TI[playerid][tCasinoRouletteTable] - 1;
			if (CasinoRouletteTableInfo[tableid][tableTimer] > 1) {
				format(STRING_GLOBAL, sizeof (STRING_GLOBAL), 
					""W"Sheiyvanet fsonis raodenoba:\n\n\
					"G"Dartva:\n\
					"G"- Minimaluri fsoni: {d8284c}%d\n\
					"G"- Maksimaluri fsoni: {d8284c}%d",
					CasinoRouletteTableInfo[tableid][tableMinBet], 
					CasinoRouletteTableInfo[tableid][tableMaxBet]
				);
				ShowPlayerDialog(playerid, D_CASINO_ROULETTE_BET, DIALOG_STYLE_INPUT, ""P"Ruletka", STRING_GLOBAL, "Migeba", "Gauqmeba"), STRING_GLOBAL[0] = EOS;
				return true;
			}
			else {
				ErrorMessage(playerid, "Ruletka ukve dawyebulia.");
				return true;
			}
		}
	}
	if((newkeys & KEY_SECONDARY_ATTACK) && !(oldkeys & KEY_SECONDARY_ATTACK)) {
		if (!TI[playerid][tCasinoRouletteTable]) {
			for (new tableid = 0; tableid < sizeof (CasinoRouletteTableInfo); tableid++) {
				if (GetPlayerVirtualWorld(playerid) !=  CasinoRouletteTableInfo[tableid][tableWorld]) 
					continue;
				if (!IsPlayerInRangeOfPoint(playerid, 2.5, CasinoRouletteTableInfo[tableid][tablePos][0], CasinoRouletteTableInfo[tableid][tablePos][1], CasinoRouletteTableInfo[tableid][tablePos][2] - 0.5)) 
					continue;
				casino_JoinRouletteTable(playerid, tableid);
				isReturn = true;
				break;
			}
		} else {
			TogglePlayerControllable(playerid, false);
			ShowPlayerDialog(playerid, D_CASINO_ROULETTE_EXIT, DIALOG_STYLE_MSGBOX, ""P"Ruletlka", ""W"Gsurt tamashis dasruleba?", "Ki", "Gauqmeba");
			return true;
		}
		if (isReturn) return true;
	}
	return false;
}

casino_LeaveRouletteTable(playerid) {
	if (!TI[playerid][tCasinoRouletteTable]) return;
	new tableid = TI[playerid][tCasinoRouletteTable] - 1;

	for (new slotid = 0; slotid < MAX_ROULETTE_TABLE_PLAYERS; slotid++) {
		if (CasinoRouletteTableInfo[tableid][tablePlayers][slotid] != playerid)
			continue;
		CasinoRouletteTableInfo[tableid][tablePlayers][slotid] = INVALID_PLAYER_ID;
		break;
	}
	CasinoRouletteTableInfo[tableid][tableActivePlayers]--;

	if (TI[playerid][tCasinoRouletteBet]) {
		CasinoRouletteTableInfo[tableid][tableActiveBets]--;
		GiveChips(playerid, TI[playerid][tCasinoRouletteBet], "refund Bet");
	}
	PlayerTextDrawHide(playerid, CasinoRoulettePTD[playerid]);

	TI[playerid][tCasinoRouletteChipsPos] = 0;
	TI[playerid][tCasinoRouletteChips] = 0;
	TI[playerid][tCasinoRouletteBet] = 0;
	TI[playerid][tCasinoRouletteTable] = 0;

	SetCameraBehindPlayer(playerid);
	TogglePlayerControllable(playerid, true);

	if (TI[playerid][tCasinoRouletteChipsObject] != -1) {
		DestroyDynamicObject(TI[playerid][tCasinoRouletteChipsObject]);
		TI[playerid][tCasinoRouletteChipsObject] = -1;
	}
	HideJobInfoTD(playerid);
}
casino_JoinRouletteTable(playerid, tableid) {
	if (CasinoRouletteTableInfo[tableid][tableActivePlayers] >= MAX_ROULETTE_TABLE_PLAYERS) {
		ErrorMessage(playerid, "Am magidastan yvela adgili dakavebulia!");
		return false;
	}
	for (new slotid = 0; slotid < MAX_ROULETTE_TABLE_PLAYERS; slotid++) {
		if (CasinoRouletteTableInfo[tableid][tablePlayers][slotid] != INVALID_PLAYER_ID)
			continue;
		CasinoRouletteTableInfo[tableid][tablePlayers][slotid] = playerid;
		break;
	}
	CasinoRouletteTableInfo[tableid][tableActivePlayers]++;

	TI[playerid][tCasinoRouletteTable] = tableid + 1;
	TI[playerid][tCasinoRouletteChipsPos] = 0;

	SendOk(playerid, "Tqven sheuertdit satamasho magidas.");
	SendOk(playerid, "Gamoiyenet "P"\"gadaadgilebis strelkebi  left/right/up/down\""G", fishkebis gadasaadguleblad.");
	SendOk(playerid, "Gamoiyenet "P"\"SPACE\""G", fsonis dadeba.");

	SetPlayerCameraPos(playerid, 1950.811767, 1742.440917 - CasinoRouletteTablePos[tableid], 1200.686 + 3.5);
	SetPlayerCameraLookAt(playerid, 1950.811767, 1742.440917 - CasinoRouletteTablePos[tableid] + 0.05, 1200.686);

	PlayerTextDrawSetString(playerid, CasinoRoulettePTD[playerid], " ");
	PlayerTextDrawShow(playerid, CasinoRoulettePTD[playerid]);

	if (CasinoRouletteTableInfo[tableid][tableTimer] <= 0) {
		ErrorMessage(playerid, "Daelodet am wris dasrulebas..");
		TI[playerid][tCasinoRouletteChipsObject] = -1;
	} else {
		new Float:objectPos[3];
		GetRouletteChipsPos(tableid, TI[playerid][tCasinoRouletteChipsPos], objectPos[0], objectPos[1], objectPos[2]);
		TI[playerid][tCasinoRouletteChipsObject] = CreateDynamicObject(1913,
			objectPos[0], objectPos[1], objectPos[2], 0.0, 0.0, 0.0, 
			CasinoRouletteTableInfo[tableid][tableWorld], CASINO_INTERIOR_ID, -1, 50, 50
		);
		foreach (new i: Player) {
			if (TI[i][tCasinoRouletteTable] != tableid + 1) 
				continue;
			Streamer_Update(playerid, STREAMER_TYPE_OBJECT);
		}
	}
	ShowJobInfoTD(playerid, INFOBAR_ID_CASINO_ROULETTE);

	PlayerTextDrawSetString(playerid, InformationPTD[playerid][0], " ");
	PlayerTextDrawSetString(playerid, InformationPTD[playerid][1], " ");
	
	format(COMMAND_GLOBAL, sizeof(COMMAND_GLOBAL),
		"~w~~h~YOUR BET:~n~\
		~w~~h~AMOUNT:"
	);
	PlayerTextDrawSetString(playerid, InformationPTD[playerid][2], COMMAND_GLOBAL), COMMAND_GLOBAL[0] = EOS;

	TogglePlayerControllable(playerid, false);
	return TI[playerid][tCasinoRouletteTable];
}
GetRouletteChipsPos(tableid, position, &Float:x, &Float:y, &Float:z) {
	if (!(0 <= position < sizeof (CasinoRouletteChipsPos)) || !(0 <= tableid < sizeof (CasinoRouletteTablePos))) 
		return;
	x = CasinoRouletteChipsPos[position][0];
	y = CasinoRouletteChipsPos[position][1] - CasinoRouletteTablePos[tableid];
	z = 1200.545;
}
enum {
	CHIPS_MOVE_TYPE_RIGHT = 1,
	CHIPS_MOVE_TYPE_LEFT,
	CHIPS_MOVE_TYPE_DOWN,
	CHIPS_MOVE_TYPE_UP
}
stock casino_MoveRouletteChips(playerid, type) {
	if (!TI[playerid][tCasinoRouletteTable]) return;
	new tableid = TI[playerid][tCasinoRouletteTable] - 1;

	TogglePlayerControllable(playerid, false);
	switch (type) {
		case CHIPS_MOVE_TYPE_RIGHT: {
			switch (TI[playerid][tCasinoRouletteChipsPos]) {
				case 0: TI[playerid][tCasinoRouletteChipsPos] = 2;
				case 1..33: TI[playerid][tCasinoRouletteChipsPos] += 3;
				case 34..36: TI[playerid][tCasinoRouletteChipsPos] += 12;
				case 39, 40: TI[playerid][tCasinoRouletteChipsPos]++;
				case 42: TI[playerid][tCasinoRouletteChipsPos] = 44;
				case 44: TI[playerid][tCasinoRouletteChipsPos] = 38;
				case 38: TI[playerid][tCasinoRouletteChipsPos] = 37;
				case 37: TI[playerid][tCasinoRouletteChipsPos] = 45;
				case 45: TI[playerid][tCasinoRouletteChipsPos] = 43;
			}
		}
		case CHIPS_MOVE_TYPE_LEFT: {
			switch (TI[playerid][tCasinoRouletteChipsPos]) {
				case 1 .. 36: {
					TI[playerid][tCasinoRouletteChipsPos] -= 3;
					if (TI[playerid][tCasinoRouletteChipsPos] < 0) 
						TI[playerid][tCasinoRouletteChipsPos] = 0;
				}
				case 46 .. 48: TI[playerid][tCasinoRouletteChipsPos] -= 12;
				case 41: TI[playerid][tCasinoRouletteChipsPos] = 40;
				case 40: TI[playerid][tCasinoRouletteChipsPos] = 39;
				case 43: TI[playerid][tCasinoRouletteChipsPos] = 45;
				case 45: TI[playerid][tCasinoRouletteChipsPos] = 37;
				case 37: TI[playerid][tCasinoRouletteChipsPos] = 38;
				case 38: TI[playerid][tCasinoRouletteChipsPos] = 44;
				case 44: TI[playerid][tCasinoRouletteChipsPos] = 42;
			}
		}
		case CHIPS_MOVE_TYPE_DOWN: {
			switch (TI[playerid][tCasinoRouletteChipsPos]) {
				case 2, 3, 5, 6, 8, 9, 11, 12, 14, 15, 17, 18, 20, 21, 23, 24, 26, 27, 29, 30, 32, 33, 35, 36, 47, 48: 
					TI[playerid][tCasinoRouletteChipsPos]--;
				case 39: TI[playerid][tCasinoRouletteChipsPos] = 42;
				case 40: TI[playerid][tCasinoRouletteChipsPos] = 38;
				case 41: TI[playerid][tCasinoRouletteChipsPos] = 45;
				case 1, 4, 7, 10: TI[playerid][tCasinoRouletteChipsPos] = 39;
				case 13, 16, 19, 22: TI[playerid][tCasinoRouletteChipsPos] = 40;
				case 25, 28, 31, 34: TI[playerid][tCasinoRouletteChipsPos] = 41;
			}
		}
		case CHIPS_MOVE_TYPE_UP: {
			switch (TI[playerid][tCasinoRouletteChipsPos]) {
				case 1, 2, 4, 5, 7, 8, 10, 11, 13, 14, 16, 17, 19, 20, 22, 23, 25, 26, 28, 29, 31, 32, 34, 35, 46, 47: 
					TI[playerid][tCasinoRouletteChipsPos]++;
				case 42, 44: TI[playerid][tCasinoRouletteChipsPos] = 39;
				case 37, 38: TI[playerid][tCasinoRouletteChipsPos] = 40;
				case 43, 45: TI[playerid][tCasinoRouletteChipsPos] = 41;
				case 39: TI[playerid][tCasinoRouletteChipsPos] = 1;
				case 40: TI[playerid][tCasinoRouletteChipsPos] = 13;
				case 41: TI[playerid][tCasinoRouletteChipsPos] = 25;
			}
		}
	}
	new Float:objectPos[3];
	GetRouletteChipsPos(tableid, TI[playerid][tCasinoRouletteChipsPos], objectPos[0], objectPos[1], objectPos[2]);
	SetDynamicObjectPos(TI[playerid][tCasinoRouletteChipsObject], objectPos[0], objectPos[1], objectPos[2]);
}

stock GetChips(playerid) 
	return PI[playerid][pCasinoChips];
stock GiveChips(playerid, amount, const logs[]) {
	if (amount == 0) 
		return false;
	PI[playerid][pCasinoChips] += amount;
	UpdatePlayerData(playerid, "CasinoChips", PI[playerid][pCasinoChips]);

	if (amount < 0) 
		format(COMMAND_GLOBAL, sizeof (COMMAND_GLOBAL), "~p~%d", amount);
	else format(COMMAND_GLOBAL, sizeof (COMMAND_GLOBAL), "~p~+%d", amount);

	GameTextForPlayer(playerid, COMMAND_GLOBAL, 500, 1), COMMAND_GLOBAL[0] = EOS;


	return true;
	#pragma unused logs
}