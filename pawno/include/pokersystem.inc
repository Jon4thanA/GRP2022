#if defined _poker_included
	#endinput
#endif
#define _poker_included

#define MAX_POKER_SEATS				(6)

#define POKER_DEFAULT_MIN_BET		(100)
#define POKER_DEFAULT_MAX_BET		(5000)
#define POKER_DEFAULT_SEAT_PRICE	(100)
#define POKER_DEFAULT_BLIND			(100)

#define MAX_pokerTableInfoS			(20)
#define MAX_POKER_HAND_RANKING		(10)
#define MAX_POKER_CHAT_LINE			(10)

#define POKER_CHAT_TD 				(40)
 
enum {
	POKER_STATUS_NONE = 0,
	POKER_STATUS_PRE_STARTING, 
	POKER_STATUS_WAITING, 
	POKER_STATUS_STARTING, 
	POKER_STATUS_ENDING 
};
enum pokerTableInfo_E {
	pokerTableObjectID,
	pokerTableObjects[6],
	pokerChatBuffer[64 * 10],
	pokerTableStatus, 
	Float:pokerTablePos[6],
	pokerTableInterior,
	pokerTableWorld,
	pokerTablePlayers,
	pokerTablePlayersActive,
	pokerTableHandsActive,
	pokerTableSlots[MAX_POKER_SEATS],
	pokerTableLimit,
	pokerTableTimer,
	pokerTableMaxBet,
	pokerTableMinBet,
	pokerTableBlind,
	pokerTableDelay,
	pokerTableSetDelay,
	pokerTablePosID,
	pokerTableSlots_rot,
	pokerTableGuestActive,
	pokerTableGuestActiveSlotID,
	pokerTableRound,
	pokerTableCardsActive,
	pokerTableBet,
	pokerTableLastRaiseID,
	pokerTableDeck[MAX_CASINO_CARDS],
	pokerTableCards[5],
	pokerTablePot,
	pokerTableRot,
	pokerTableWinners,
	pokerTableWinnerID,
	pokerTableEnterPrice,
	Text3D:pokerTableTextID,
	pokerTableAreaID
};
new 
	pokerTableInfo[MAX_pokerTableInfoS][pokerTableInfo_E], 
	Iterator:pokerTables<MAX_pokerTableInfoS>;

enum {
	POKER_KEY_CALL = 1,
	POKER_KEY_CHECK,
	POKER_KEY_RAISE,
	POKER_KEY_FOLD
};
enum {
	POKER_OPTION_NONE = 0,
	POKER_OPTION_RCF, //	RAISE	| CHECK | FOLD
	POKER_OPTION_CRF, //	CALL	| RAISE | FOLD
	POKER_OPTION_CF   //	CHECK	| FOLD
}
enum {
	PM_MENU_BET = 1,
	PM_MENU_CALL, 
	PM_MENU_RAISE
};
enum {
	POKER_HANDRANKING_HIGHCARD = 1,
	POKER_HANDRANKING_ONEPAIR,
	POKER_HANDRANKING_TWOPAIR,
	POKER_HANDRANKING_THREEOFKIND,
	POKER_HANDRANKING_STRAIGHT,
	POKER_HANDRANKING_FLUSH,
	POKER_HANDRANKING_FULLHOUSE,
	POKER_HANDRANKING_FOUROFKIND,
	POKER_HANDRANKING_STRAIGHTFLUSH,
	POKER_HANDRANKING_ROYALFLUSH
}
static const Float:pokerTableInfoOffsets[MAX_POKER_SEATS][4] = {
	{ -1.27, -0.53, 0.1, 180.0 },	//	6
	{ -1.27, 0.470, 0.1, 180.0 },	//	5
	{ 0.030, 1.880, 0.1, 90.00 },	//	1
	{ 1.270, 0.470, 0.1, 0.000 },	//	2
	{ 1.270, -0.53, 0.1, 0.000 },	//	3
	{ -0.03, -1.88, 0.1, -90.0 }  //	4
};
static const poker_hand_ranking[MAX_POKER_HAND_RANKING][1 + 5][] = {
	{"ROYAL FLUSH", "LD_CARD:cd1s", "LD_CARD:cd13s", "LD_CARD:cd12s", "LD_CARD:cd11s", "LD_CARD:cd10s"},
	{"STRAIGHT FLUSH", "LD_CARD:cd9d", "LD_CARD:cd8d", "LD_CARD:cd7d", "LD_CARD:cd6d", "LD_CARD:cd5d"},
	{"4 OF A KIND", "LD_CARD:cd1s", "LD_CARD:cd1h", "LD_CARD:cd1d", "LD_CARD:cd1c", "LD_CARD:cdback"},
	{"FULL HOUSE", "LD_CARD:cd12h", "LD_CARD:cd12s", "LD_CARD:cd12d", "LD_CARD:cd11c", "LD_CARD:cd11d"},
	{"FLUSH", "LD_CARD:cd1h", "LD_CARD:cd11h", "LD_CARD:cd9h", "LD_CARD:cd6h", "LD_CARD:cd3h"},
	{"STRAIGHT", "LD_CARD:cd9c", "LD_CARD:cd8d", "LD_CARD:cd7d", "LD_CARD:cd6d", "LD_CARD:cd5s"},
	{"3 OF A KIND", "LD_CARD:cd2h", "LD_CARD:cd2s", "LD_CARD:cd2d", "LD_CARD:cdback", "LD_CARD:cdback"},
	{"TWO PAIR", "LD_CARD:cd1h", "LD_CARD:cd1c", "LD_CARD:cd13h", "LD_CARD:cd13s", "LD_CARD:cdback"},
	{"PAIR", "LD_CARD:cd1d", "LD_CARD:cd1s", "LD_CARD:cdback", "LD_CARD:cdback", "LD_CARD:cdback"},
	{"HIGH CARD", "LD_CARD:cd1s", "LD_CARD:cd12d", "LD_CARD:cd11c", "LD_CARD:cd6d", "LD_CARD:cd5s"}
};
static const poker_language_massive[2][10][] = {
	{	/* (00) */"BANK", 
		/* (01) */"CURRENT BET",
		/* (02) */"p. won by",
		/* (03) */"won",
		/* (04) */"ROUND WILL BEGIN THROUGH",
		/* (05) */"ROUND WILL END THROUGH",
		/* (06) */"WAITING FOR OTHER PLAYERS",
		/* (07) */"~p~NEW ROUND STARTED!",
		/* (08) */"~w~YOU",
		/* (09) */"~w~YOUR TURN!"
	},
	{	/* (00) */"BANK", 
		/* (01) */"MIMDEBARE FSONI",
		/* (02) */"p. won by",
		/* (03) */"MOGEBA",
		/* (04) */"RAUNDI IWYEBA",
		/* (05) */"ROUND",
		/* (06) */"VELODEVBIT MOTAMASHEEBS",
		/* (07) */"~p~NEW ROUND STARTED!",
		/* (08) */"~w~TQVEN",
		/* (09) */"~w~TQVENI SVLAA!"
	}
};
static 
	Text:Poker_TD[10], PlayerText:Poker_PTD[MAX_PLAYERS][(40 + 10)],
	PlayerText:PokerTutorial_PTD[MAX_PLAYERS], Text:PokerTutorial_TD[4],
	PlayerText:PokerDI_PTD[MAX_PLAYERS][2],

	Text:pokerName_HR_TD[MAX_POKER_HAND_RANKING], 
	Text:pokerCard_HR_TD[MAX_POKER_HAND_RANKING][5]
;
poker_OnGameModeInit() {
	poker_createTD();

	poker_CreateTable(1976.189208, 1732.255859, 1200.190, 0.000000, 0.000000, 90.000000, CASINO_WORLD_ID + 1, CASINO_INTERIOR_ID); // FOR TUTORIAL
	poker_CreateTable(1976.189208, 1732.255859, 1200.190, 0.000000, 0.000000, 90.000000, CASINO_WORLD_ID, CASINO_INTERIOR_ID); 
	poker_CreateTable(1976.189208, 1742.897216, 1200.190, 0.000000, 0.000000, 90.000000, CASINO_WORLD_ID, CASINO_INTERIOR_ID);
	poker_CreateTable(1976.189208, 1737.536499, 1200.190, 0.000000, 0.000000, 90.000000, CASINO_WORLD_ID, CASINO_INTERIOR_ID);

	poker_CreateTable(1976.189208, 1732.255859, 1200.190, 0.000000, 0.000000, 90.000000, 2 + CASINO_WORLD_ID + 1, CASINO_INTERIOR_ID); // FOR TUTORIAL
	poker_CreateTable(1976.189208, 1732.255859, 1200.190, 0.000000, 0.000000, 90.000000, 2 + CASINO_WORLD_ID, CASINO_INTERIOR_ID); 
	poker_CreateTable(1976.189208, 1742.897216, 1200.190, 0.000000, 0.000000, 90.000000, 2 + CASINO_WORLD_ID, CASINO_INTERIOR_ID);
	poker_CreateTable(1976.189208, 1737.536499, 1200.190, 0.000000, 0.000000, 90.000000, 2 + CASINO_WORLD_ID, CASINO_INTERIOR_ID);
}
poker_OnPlayerClickPTextDraw(playerid, PlayerText:playertextid) {
	if (PI[playerid][pPokerTableID] && !GetPVarInt(playerid, "Anticheat::Dialog_Showed")) {
		if (playertextid == Poker_PTD[playerid][38]) {
			poker_ShowHandRanking(playerid, 1);
			return true;
		}
		else if (playertextid == Poker_PTD[playerid][39]) {
			poker_ShowHandRanking(playerid, 2);
			return true;
		}
	}
	return false;
}
stock poker_OnPlayerClickTextDraw(playerid, Text:clickedid) {
	if (PI[playerid][pPokerTableID]) {
		if (!GetPVarInt(playerid, "Anticheat::Dialog_Showed")) {
			if (clickedid == PokerTutorial_TD[2]) { // << BACK
				poker_TutorialNextStep(playerid, PI[playerid][pPokerTutorialStep] - 1, 0);
				return true;
			}
			if (clickedid == PokerTutorial_TD[3]) { // >> NEXT
				poker_TutorialNextStep(playerid, PI[playerid][pPokerTutorialStep] + 1);
				return true;
			}
			new tableid = (PI[playerid][pPokerTableID] - 1);
			if (clickedid == Poker_TD[4]) switch (PI[playerid][pPokerOptions]) {
				case POKER_OPTION_RCF: {
					if (!PI[playerid][pPokerTutorialStep]) {
						pokerTableInfo[tableid][pokerTableRot] = 0;
						poker_ActionRaise(playerid);
						return true;
					}
					else if (PI[playerid][pPokerTutorialKey] == POKER_KEY_RAISE)
						poker_TutorialNextStep(playerid, (PI[playerid][pPokerTutorialStep] + 1), 0);
				}
				case POKER_OPTION_CRF: {
					if (!PI[playerid][pPokerTutorialStep]) {
						poker_ActionCall(playerid);
						return true;
					}
					else if (PI[playerid][pPokerTutorialKey] == POKER_KEY_CALL) {
						poker_TutorialNextStep(playerid, (PI[playerid][pPokerTutorialStep] + 1), 0);
					}
				}
				case POKER_OPTION_CF: {
					if (!PI[playerid][pPokerTutorialStep]) {
						poker_ActionCheck(playerid);
						poker_NextTurn(tableid);
						return true;
					}
					else if (PI[playerid][pPokerTutorialKey] == POKER_KEY_CHECK) {
						poker_TutorialNextStep(playerid, (PI[playerid][pPokerTutorialStep] + 1), 0);
					}
				}
				default: return true;
			}
			else if (clickedid == Poker_TD[5]) switch (PI[playerid][pPokerOptions]) {
				case POKER_OPTION_RCF: {
					if (!PI[playerid][pPokerTutorialStep]) {
						poker_ActionCheck(playerid);
						return poker_NextTurn(tableid), true;
					}
					else if (PI[playerid][pPokerTutorialKey] == POKER_KEY_CHECK)
						poker_TutorialNextStep(playerid, (PI[playerid][pPokerTutorialStep] + 1), 0);
				}
				case POKER_OPTION_CRF: {
					if (!PI[playerid][pPokerTutorialStep]) {
						pokerTableInfo[tableid][pokerTableRot] = 0;
						return poker_ActionRaise(playerid), true;
					}
					else if (PI[playerid][pPokerTutorialKey] == POKER_KEY_RAISE)
						poker_TutorialNextStep(playerid, (PI[playerid][pPokerTutorialStep] + 1), 0);
				}
				case POKER_OPTION_CF: {
					if (!PI[playerid][pPokerTutorialStep]) {
						poker_ActionFold(playerid);
						return poker_NextTurn(tableid), true;
					}
					else if (PI[playerid][pPokerTutorialKey] == POKER_KEY_FOLD)
						poker_TutorialNextStep(playerid, (PI[playerid][pPokerTutorialStep] + 1), 0);
				}
				default: return true;
			}
			else if (clickedid == Poker_TD[6]) switch (PI[playerid][pPokerOptions]) {
				case POKER_OPTION_RCF: {
					if (!PI[playerid][pPokerTutorialStep]) {
						poker_ActionFold(playerid);
						return poker_NextTurn(tableid), true;
					}
					else if (PI[playerid][pPokerTutorialKey] == POKER_KEY_FOLD)
						poker_TutorialNextStep(playerid, (PI[playerid][pPokerTutorialStep] + 1), 0);
				}
				case POKER_OPTION_CRF: {
					if (!PI[playerid][pPokerTutorialStep]) {
						poker_ActionFold(playerid);
						return poker_NextTurn(tableid), true;
					}
					else if (PI[playerid][pPokerTutorialKey] == POKER_KEY_FOLD)
						poker_TutorialNextStep(playerid, (PI[playerid][pPokerTutorialStep] + 1), 0);
				}
				default: return true;
			}
			else if (clickedid == Poker_TD[2]) {
				if (PI[playerid][pPokerTutorialStep])
					ShowPlayerDialog(playerid, DIALOG_POKER_LEAVE, DIALOG_STYLE_MSGBOX, "{d8284c}Texas Holdem Poker", "{FFFFFF}Gsurt daasrulot swavla?", "Ki", "Gauqmeba");
				else ShowPlayerDialog(playerid, DIALOG_POKER_LEAVE, DIALOG_STYLE_MSGBOX, "{d8284c}Texas Holdem Poker", "{FFFFFF}Gsurt datovot satamasho magida?", "Ki", "Gauqmeba");
				return true;
			}
			else if (clickedid == Poker_TD[8]) {
				return poker_ShowHandRanking(playerid), true;
			}
		}
		if (_:clickedid == INVALID_TEXT_DRAW) {
			return SelectTextDraw(playerid, 0x191919FF), true;
		}
	}
	return false;
}
poker_OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	new bool:poker_joined = false;
	if (!PI[playerid][pPokerTableID] && (newkeys & KEY_SECONDARY_ATTACK && oldkeys != KEY_SECONDARY_ATTACK)) {
		foreach(new poker_id: pokerTables) {
			if (IsPlayerInDynamicArea(playerid, pokerTableInfo[poker_id][pokerTableAreaID], 1)) {
				poker_JoinGame(playerid, poker_id), poker_joined = true;
				break;
			}
		}
	}
	return poker_joined;
}
poker_OnPlayerDisconnect(playerid) {
	poker_LeaveGame(playerid);
	return true;
}
poker_OnPlayerDeath(playerid) {
	poker_LeaveGame(playerid);
	return true;
}
stock poker_SendChat(tableid, const text_td[]) {
	strdel(pokerTableInfo[tableid][pokerChatBuffer], 0, (strfind(pokerTableInfo[tableid][pokerChatBuffer], "~n~", true) + 3));
	strcat(pokerTableInfo[tableid][pokerChatBuffer], "~n~"), strcat(pokerTableInfo[tableid][pokerChatBuffer], text_td);

	for (new lineid = 0, string[64], n_symbolid[MAX_POKER_CHAT_LINE]; lineid < MAX_POKER_CHAT_LINE; lineid++) {
		for (new idx = 0, i = 2; i != strlen(pokerTableInfo[tableid][pokerChatBuffer]); i++) {
			if (
				(pokerTableInfo[tableid][pokerChatBuffer][i - 0] == '~') && 
				(pokerTableInfo[tableid][pokerChatBuffer][i - 1] == 'n') && 
				(pokerTableInfo[tableid][pokerChatBuffer][i - 2] == '~') &&
				(++idx) < sizeof(n_symbolid)
			) n_symbolid[idx] = i;
		}
		if (0 == lineid) 
			strmid(string, pokerTableInfo[tableid][pokerChatBuffer], 0, (n_symbolid[1] - 2));
		else if ((sizeof(n_symbolid) - 1) == lineid) {
			strmid(string, pokerTableInfo[tableid][pokerChatBuffer], (n_symbolid[lineid] + 1), strlen(pokerTableInfo[tableid][pokerChatBuffer]));
			format(string, 64, "~>~ %s", string);
		}
		else strmid(string, pokerTableInfo[tableid][pokerChatBuffer], (n_symbolid[lineid] + 1), (n_symbolid[lineid + 1] - 2));

		for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][POKER_CHAT_TD + lineid], string);
		}
	}
	return true;
}
stock poker_update_chat(tableid) {
	for (new lineid = 0, string[64], n_symbolid[MAX_POKER_CHAT_LINE]; lineid < MAX_POKER_CHAT_LINE; lineid++) {
		for (new idx = 0, i = 2; i != strlen(pokerTableInfo[tableid][pokerChatBuffer]); i++) {
			if (
				(pokerTableInfo[tableid][pokerChatBuffer][i - 0] == '~') && 
				(pokerTableInfo[tableid][pokerChatBuffer][i - 1] == 'n') && 
				(pokerTableInfo[tableid][pokerChatBuffer][i - 2] == '~') &&
				(++idx) < sizeof(n_symbolid)
			) n_symbolid[idx] = i;
		}
		if (0 == lineid) 
			strmid(string, pokerTableInfo[tableid][pokerChatBuffer], 0, (n_symbolid[1] - 2));
		else if ((sizeof(n_symbolid) - 1) == lineid) {
			strmid(string, pokerTableInfo[tableid][pokerChatBuffer], (n_symbolid[lineid] + 1), strlen(pokerTableInfo[tableid][pokerChatBuffer]));
			format(string, 64, "~>~ %s", string);
		}
		else strmid(string, pokerTableInfo[tableid][pokerChatBuffer], (n_symbolid[lineid] + 1), (n_symbolid[lineid + 1] - 2));

		for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][POKER_CHAT_TD + lineid], string);
		}
	}
	return true;
}
poker_WinnerHand(const cards[5], const hands[2], &p_value, &p_kicker) {
	new best_value, value, best_kicker, kicker;
	for (new i = 0; i < 21; i++) {
		switch (i) {
			case 0: poker_AnalyzeHand(cards[0], cards[1], cards[2], cards[3], cards[4], value, kicker);
			case 1: poker_AnalyzeHand(cards[0], cards[1], cards[2], hands[0], hands[1], value, kicker);
			case 2: poker_AnalyzeHand(cards[0], cards[1], cards[3], hands[0], hands[1], value, kicker);
			case 3: poker_AnalyzeHand(cards[0], cards[1], cards[4], hands[0], hands[1], value, kicker);
			case 4: poker_AnalyzeHand(cards[0], cards[2], cards[3], hands[0], hands[1], value, kicker);
			case 5: poker_AnalyzeHand(cards[0], cards[2], cards[4], hands[0], hands[1], value, kicker);
			case 6: poker_AnalyzeHand(cards[0], cards[3], cards[4], hands[0], hands[1], value, kicker);
			case 7: poker_AnalyzeHand(cards[1], cards[2], cards[3], hands[0], hands[1], value, kicker);
			case 8: poker_AnalyzeHand(cards[1], cards[2], cards[4], hands[0], hands[1], value, kicker);
			case 9: poker_AnalyzeHand(cards[1], cards[3], cards[4], hands[0], hands[1], value, kicker);
			case 10: poker_AnalyzeHand(cards[2], cards[3], cards[4], hands[0], hands[1], value, kicker);
			case 11: poker_AnalyzeHand(cards[0], cards[1], cards[2], cards[3], hands[0], value, kicker);
			case 12: poker_AnalyzeHand(cards[0], cards[1], cards[2], cards[4], hands[0], value, kicker);
			case 13: poker_AnalyzeHand(cards[0], cards[1], cards[3], cards[4], hands[0], value, kicker);
			case 14: poker_AnalyzeHand(cards[0], cards[2], cards[3], cards[4], hands[0], value, kicker);
			case 15: poker_AnalyzeHand(cards[1], cards[2], cards[3], cards[4], hands[0], value, kicker);
			case 16: poker_AnalyzeHand(cards[0], cards[1], cards[2], cards[3], hands[1], value, kicker);
			case 17: poker_AnalyzeHand(cards[0], cards[1], cards[2], cards[4], hands[1], value, kicker);
			case 18: poker_AnalyzeHand(cards[0], cards[1], cards[3], cards[4], hands[1], value, kicker);
			case 19: poker_AnalyzeHand(cards[0], cards[2], cards[3], cards[4], hands[1], value, kicker);
			case 20: poker_AnalyzeHand(cards[1], cards[2], cards[3], cards[4], hands[1], value, kicker);
		}
        if (value > best_value) 
			best_value = value, best_kicker = kicker;
        else if (value == best_value && kicker > best_kicker) best_kicker = kicker;
	}
	p_value = best_value, p_kicker = best_kicker; 

	return true;
}
poker_AnalyzeHand(card_1, card_2, card_3, card_4, card_5, &value, &kicker) {
    new card[5], card_suit[5], card_value[5];

	card[0] = card_1, card[1] = card_2, card[2] = card_3, card[3] = card_4, card[4] = card_5;

	for (new i, tmp_card_id; i < sizeof(card); i++) {
	    tmp_card_id = card[i];
		card_suit[i] = CASINO_CARD_INFO[tmp_card_id][CASINO_CARD_SUIT];
		card_value[i] = CASINO_CARD_INFO[tmp_card_id][CASINO_CARD_VALUE];
		/*if (card_value[i] == CARD_NUMBER_ACE)
			card_value[i] = 11;
		else if (card_value[i] >= CARD_NUMBER_TEN && card_value[i] < CARD_NUMBER_ACE)
			card_value[i] = 10;*/
	}
	ArraySort(card_value, sizeof(card_value));

	if (card_value[0] == card_value[1] - 1 && card_value[1] == card_value[2] - 1 && card_value[2] == card_value[3] - 1 && 
		card_value[3] == card_value[4] - 1 && card_suit[0] == card_suit[1] && card_suit[1] == card_suit[2] && 
		card_suit[2] == card_suit[3] && card_suit[3] == card_suit[4]
	) {
		value = (card_value[4] == CARD_NUMBER_ACE) ? POKER_HANDRANKING_ROYALFLUSH : POKER_HANDRANKING_STRAIGHTFLUSH;
		kicker = (card_value[4] == CARD_NUMBER_ACE) ? CARD_NUMBER_ACE : card_value[4];
	}
	else if (
		card_value[0] == CARD_NUMBER_TWO && card_value[1] == CARD_NUMBER_THREE && card_value[2] == CARD_NUMBER_FOUR && 
		card_value[3] == CARD_NUMBER_FIVE && card_value[4] == CARD_NUMBER_ACE &&
		card_suit[0] == card_suit[1] && card_suit[1] == card_suit[2] && card_suit[2] == card_suit[3] && card_suit[3] == card_suit[4]
	) {
		value = POKER_HANDRANKING_STRAIGHTFLUSH;
		kicker = CARD_NUMBER_FIVE;
	}
	else if (card_value[0] == card_value[1] && card_value[1] == card_value[2] && card_value[2] == card_value[3]) {
		value = POKER_HANDRANKING_FOUROFKIND;
		kicker = card_value[0] * 20 + card_value[4];
	}
	else if (card_value[1] == card_value[2] && card_value[2] == card_value[3] && card_value[3] == card_value[4]) {
		value = POKER_HANDRANKING_FOUROFKIND;
		kicker = card_value[1] * 20 + card_value[0];
	}
	else if (card_value[0] == card_value[1] && card_value[2] == card_value[3] && card_value[3] == card_value[4]) {
		value = POKER_HANDRANKING_FULLHOUSE;
		kicker = card_value[0] + card_value[2] * 20;
	}
	else if (card_value[0] == card_value[1] && card_value[1] == card_value[2] && card_value[3] == card_value[4]) {
		value = POKER_HANDRANKING_FULLHOUSE;
		kicker = card_value[0] * 20 + card_value[3];
	}
	else if (
		card_suit[0] == card_suit[1] && card_suit[1] == card_suit[2] && 
		card_suit[2] == card_suit[3] && card_suit[3] == card_suit[4]
	) {
		value = POKER_HANDRANKING_FLUSH;
		kicker = (card_value[4] * 160000 + card_value[3] * 8000 + card_value[2] * 400 + card_value[1] * 20 + card_value[0]);
	}
	else if (
		card_value[0] == card_value[1] - 1 && card_value[1] == card_value[2] - 1 && 
		card_value[2] == card_value[3] - 1 && card_value[3] == card_value[4] - 1
	) {
		value = POKER_HANDRANKING_STRAIGHT;
		kicker = card_value[4];
	}
	else if (
		card_value[0] == CARD_NUMBER_TWO && card_value[1] == CARD_NUMBER_THREE && card_value[2] == CARD_NUMBER_FOUR && 
		card_value[3] == CARD_NUMBER_FIVE && card_value[4] == CARD_NUMBER_ACE
	) {
		value = POKER_HANDRANKING_STRAIGHT;
	    kicker = CARD_NUMBER_FIVE;
	}
	else if (card_value[0] == card_value[1] && card_value[1] == card_value[2]) {
		value = POKER_HANDRANKING_THREEOFKIND;
		kicker = (card_value[0] * 400 + card_value[3] + card_value[4] * 20);
	}
	else if (card_value[1] == card_value[2] && card_value[2] == card_value[3]) {
		value = POKER_HANDRANKING_THREEOFKIND;
		kicker = card_value[1] * 400 + card_value[0] + card_value[4] * 20;
	}
	else if (card_value[2] == card_value[3] && card_value[3] == card_value[4]) {
		value = POKER_HANDRANKING_THREEOFKIND;
		kicker = (card_value[1] * 400 + card_value[0] + card_value[1] * 20);
	}
	else if (card_value[0] == card_value[1] && card_value[2] == card_value[3]) {
		value = POKER_HANDRANKING_TWOPAIR;
		kicker = (card_value[0] * 20 + card_value[2] * 400 + card_value[4]);
	}
	else if (card_value[0] == card_value[1] && card_value[3] == card_value[4]) {
		value = POKER_HANDRANKING_TWOPAIR;
		kicker = (card_value[0] * 20 + card_value[3] * 400 + card_value[2]);
	}
	else if (card_value[1] == card_value[2] && card_value[3] == card_value[4]) {
		value = POKER_HANDRANKING_TWOPAIR;
		kicker = (card_value[1] * 20 + card_value[3] * 400 + card_value[0]);
	}
	else if (card_value[0] == card_value[1]) {
		value = POKER_HANDRANKING_ONEPAIR;
		kicker = (card_value[0] * 8000 + card_value[2] + card_value[3] * 20 + card_value[4] * 400);
	}
	else if (card_value[1] == card_value[2]) {
		value = POKER_HANDRANKING_ONEPAIR;
		kicker = (card_value[1] * 8000 + card_value[0] + card_value[3] * 20 + card_value[4] * 400);
	}
	else if (card_value[2] == card_value[3]) {
		value = POKER_HANDRANKING_ONEPAIR;
		kicker = (card_value[2] * 8000 + card_value[0] + card_value[1] * 20 + card_value[4] * 400);
	}
	else if (card_value[3] == card_value[4]) {
		value = POKER_HANDRANKING_ONEPAIR;
		kicker = (card_value[3] * 8000 + card_value[0] + card_value[1] * 20 + card_value[2] * 400);
	}
	else {
		value = POKER_HANDRANKING_HIGHCARD;
		kicker = (card_value[4] * 160000 + card_value[3] * 8000 + card_value[2] * 400 + card_value[1] * 20 + card_value[0]);
	}
	return true;
}
forward poker_Timer(); 
public poker_Timer() {
	foreach(new tableid: pokerTables) {
		if (!pokerTableInfo[tableid][pokerTableStatus])
			pokerTableInfo[tableid][pokerTableTimer] = 0;
		if (!pokerTableInfo[tableid][pokerTableTimer]) 
			continue;
		poker_TimerID(tableid);
	}
	return true;
}
stock poker_TimerID(tableid) {
	if (pokerTableInfo[tableid][pokerTablePlayers] < 1) 
		return poker_ResetTable(tableid);
	for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
		SetPlayerArmedWeapon(playerid, 0);

		if (random(100) >= 90) {
			new Float:object_angle = 0.0;
			GetDynamicObjectRot(pokerTableInfo[tableid][pokerTableObjectID], object_angle, object_angle, object_angle);
			SetPlayerPosObjectOffset(pokerTableInfo[tableid][pokerTableObjectID], playerid, pokerTableInfoOffsets[i][0], pokerTableInfoOffsets[i][1], pokerTableInfoOffsets[i][2]);
			SetPlayerFacingAngle(playerid, (pokerTableInfoOffsets[i][3] + 90.0 + object_angle));
			SetPlayerInterior(playerid, pokerTableInfo[tableid][pokerTableInterior]);
			SetPlayerVirtualWorld(playerid, pokerTableInfo[tableid][pokerTableWorld]);

			if (PI[playerid][pPokerActiveHand]) ApplyAnimation(playerid, "CASINO", "cards_loop", 4.1, 0, 1, 1, 1, 1, 1);
		}
		else continue;
	}
	if (pokerTableInfo[tableid][pokerTablePlayersActive] >= 2 && pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_WAITING) for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) {
		if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID && PI[playerid][pPokerChips]) {
			pokerTableInfo[tableid][pokerTableStatus] = POKER_STATUS_STARTING;
			pokerTableInfo[tableid][pokerTableDelay] = pokerTableInfo[tableid][pokerTableSetDelay]; 
			break;
		}
	}
	if (pokerTableInfo[tableid][pokerTablePlayers] < 2 && (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_STARTING || pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_ENDING)) for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) {
		if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID/* && PI[playerid][pPokerChips]*/) {
			if (pokerTableInfo[tableid][pokerTablePot] && PI[playerid][pPokerBet] > 100) {


				if ((PI[playerid][pPokerBet] - 100) > 0) {
					format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "%s ar arian motamasheebi #%d dabruneba %d",
						GetName(playerid), tableid + 1, PI[playerid][pPokerBet]-100
					);
					printf(STRING_GLOBAL), /*WriteLog("logs_casino", STRING_GLOBAL), */STRING_GLOBAL[0] = EOS;
					PI[playerid][pPokerChips] += (PI[playerid][pPokerBet] - 100);//pokerTableInfo[tableid][pokerTablePot];
				}
			}
			PI[playerid][pPokerBet] = 0;
			poker_LeaveGame(playerid);
		}
		else continue;
	}
	if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_ENDING) {
		if (pokerTableInfo[tableid][pokerTableDelay] == 20) for (new i = 0; i < MAX_POKER_SEATS; i++) if (pokerTableInfo[tableid][pokerTableSlots][i] != INVALID_PLAYER_ID) {
			PlayerPlaySound(pokerTableInfo[tableid][pokerTableSlots][i], 5826, 0.0, 0.0, 0.0);
			poker_UpdateOptions(pokerTableInfo[tableid][pokerTableSlots][i], POKER_OPTION_NONE);
		}
		if (pokerTableInfo[tableid][pokerTableDelay] > 0) {
			pokerTableInfo[tableid][pokerTableDelay]--;
			if (pokerTableInfo[tableid][pokerTableDelay] <= 5 && pokerTableInfo[tableid][pokerTableDelay] > 0) for (new i = 0; i < MAX_POKER_SEATS; i++) 
				if (pokerTableInfo[tableid][pokerTableSlots][i] != INVALID_PLAYER_ID) 
					PlayerPlaySound(pokerTableInfo[tableid][pokerTableSlots][i], 1139, 0.0, 0.0, 0.0);
			if (pokerTableInfo[tableid][pokerTableDelay] == 0) 
				return poker_ResetRound(tableid);
		}
		if (pokerTableInfo[tableid][pokerTableDelay] == 19) {
			new cards[5], hands[2];
			for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
				if (PI[playerid][pPokerActiveHand]) {
					for (new card_id; card_id < 5; card_id++)
						cards[card_id] = pokerTableInfo[tableid][pokerTableCards][card_id];
					hands[0] = PI[playerid][pPokerCard][0];
					hands[1] = PI[playerid][pPokerCard][1];
					poker_WinnerHand(cards, hands, PI[playerid][pPokerResult][0], PI[playerid][pPokerResult][1]);
				}
				else continue;
			}
			new best_value, best_kicker;
			for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
				if (!PI[playerid][pPokerActiveHand])
					continue;
				if (PI[playerid][pPokerResult][0] == best_value && PI[playerid][pPokerResult][1] > best_kicker) {
					best_kicker = PI[playerid][pPokerResult][1];
				}
				else if (PI[playerid][pPokerResult][0] > best_value) {
    			    best_value = PI[playerid][pPokerResult][0];
    			    best_kicker = PI[playerid][pPokerResult][1];
				}
			}
			for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
				if (PI[playerid][pPokerResult][0] == best_value && PI[playerid][pPokerResult][1] == best_kicker) pokerTableInfo[tableid][pokerTableWinners]++;
			}
			for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
				if (PI[playerid][pPokerResult][0] == best_value && PI[playerid][pPokerResult][1] == best_kicker) {
					switch (best_value) {
						case POKER_HANDRANKING_HIGHCARD: format(PI[playerid][pPokerResult_STR], 32, "_~n~~g~HIGH CARD");
						case POKER_HANDRANKING_ONEPAIR: format(PI[playerid][pPokerResult_STR], 32, "_~n~~g~PAIR");
						case POKER_HANDRANKING_TWOPAIR: format(PI[playerid][pPokerResult_STR], 32, "_~n~~g~TWO PAIR");
						case POKER_HANDRANKING_THREEOFKIND: format(PI[playerid][pPokerResult_STR], 32, "_~n~~g~3 OF A KIND");
						case POKER_HANDRANKING_STRAIGHT: format(PI[playerid][pPokerResult_STR], 32, "_~n~~g~STRAIGHT");
						case POKER_HANDRANKING_FLUSH: format(PI[playerid][pPokerResult_STR], 32, "_~n~~g~FLUSH");
						case POKER_HANDRANKING_FULLHOUSE: format(PI[playerid][pPokerResult_STR], 32, "_~n~~g~FULL HOUSE");
						case POKER_HANDRANKING_FOUROFKIND: format(PI[playerid][pPokerResult_STR], 32, "_~n~~g~4 OF A KIND");
						case POKER_HANDRANKING_STRAIGHTFLUSH: format(PI[playerid][pPokerResult_STR], 32, "~g~STRAIGHT~n~FLUSH");
						case POKER_HANDRANKING_ROYALFLUSH: format(PI[playerid][pPokerResult_STR], 32, "~g~ROYAL~n~FLUSH");
					}
					new poker_splitpot = (pokerTableInfo[tableid][pokerTablePot] / pokerTableInfo[tableid][pokerTableWinners]), poker_text_td[34];

					PI[playerid][pPokerWinner] = 1;
					if (pokerTableInfo[tableid][pokerTableWinners] < 2) {
						new poker_active_table, poker_active_bet = pokerTableInfo[tableid][pokerTableBet];

						for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID) {
							if (PI[targetid][pPokerBet]) poker_active_table++;
						}
						poker_active_bet = poker_splitpot = PI[playerid][pPokerBet];

						for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID && PI[targetid][pPokerBet]) {
							if (targetid == playerid) continue;

							poker_splitpot += PI[targetid][pPokerBet];

							if (PI[targetid][pPokerBet] > poker_active_bet) {
								poker_splitpot -= (PI[targetid][pPokerBet] - poker_active_bet);
								PI[targetid][pPokerChips] += (PI[targetid][pPokerBet] - poker_active_bet);
							}
						}
						pokerTableInfo[tableid][pokerTableWinnerID] = playerid;
						PlayerPlaySound(playerid, 5847, 0.0, 0.0, 0.0);

						if (pokerTableInfo[tableid][pokerTableDelay] == 17) {
							format(poker_text_td, sizeof(poker_text_td), "%s: ~g~~h~WON ~p~%d", 
								GetName(playerid), poker_splitpot
							);
							poker_SendChat(tableid, poker_text_td);
						}
					}
					else {
						new poker_active_table, poker_active_bet = pokerTableInfo[tableid][pokerTableBet];

						for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID) {
							if (PI[targetid][pPokerBet]) poker_active_table++;
						}
						poker_active_bet = poker_splitpot = PI[playerid][pPokerBet];

						for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID && PI[targetid][pPokerBet]) {
							if (PI[targetid][pPokerResult][0] == best_value && PI[targetid][pPokerResult][1] == best_kicker)
								continue;
							poker_splitpot += PI[targetid][pPokerBet] / pokerTableInfo[tableid][pokerTableWinners];

							if (PI[targetid][pPokerBet] > poker_active_bet) {
								poker_splitpot -= (PI[targetid][pPokerBet] / pokerTableInfo[tableid][pokerTableWinners] - poker_active_bet / pokerTableInfo[tableid][pokerTableWinners]);
								PI[targetid][pPokerChips] += (PI[targetid][pPokerBet] - poker_active_bet / pokerTableInfo[tableid][pokerTableWinners]);
							}
						}
						pokerTableInfo[tableid][pokerTableWinnerID] = playerid;
						
						PlayerPlaySound(playerid, 5821, 0.0, 0.0, 0.0);
						if (pokerTableInfo[tableid][pokerTableDelay] == 17) {
							format(poker_text_td, sizeof(poker_text_td), "%d ~g~~h~PEOPLE WON %d",
								pokerTableInfo[tableid][pokerTableWinners], pokerTableInfo[tableid][pokerTablePot] //poker_splitpot
							);
							poker_SendChat(tableid, poker_text_td);
						}
					}
					PI[playerid][pPokerChips] += poker_splitpot;
					
					format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "%s выйграл %d fishkebi. Всего: %d",
						GetName(playerid), poker_splitpot, PI[playerid][pPokerChips]
					);
					printf(STRING_GLOBAL), /*WriteLog("logs_casino", STRING_GLOBAL), */STRING_GLOBAL[0] = EOS;
				}
				else PlayerPlaySound(playerid, 31202, 0.0, 0.0, 0.0);

				if (pokerTableInfo[tableid][pokerTableWinners] == 1) {
					if (PI[playerid][pPokerWinner]) 
						ApplyAnimation(playerid, "CASINO", "cards_win", 4.1, 0, 1, 1, 1, 1, 1);
					else if (0 != PI[playerid][pPokerBet]) 
						ApplyAnimation(playerid, "CASINO", "cards_lose", 4.1, 0, 1, 1, 1, 1, 1);
				}
				else {
					if (pokerTableInfo[tableid][pokerTableWinners] > 1) 
						ApplyAnimation(playerid, "CASINO", "cards_win", 4.1, 0, 1, 1, 1, 1, 1);
					else if (0 != PI[playerid][pPokerBet]) 
						ApplyAnimation(playerid, "CASINO", "cards_lose", 4.1, 0, 1, 1, 1, 1, 1);
				}
			}
			else continue;

		}
		
	}
	if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_STARTING) {
		if (pokerTableInfo[tableid][pokerTableHandsActive] == 1 && pokerTableInfo[tableid][pokerTableRound] == 1) {
			for (new i = 0, playerid = INVALID_PLAYER_ID; i < MAX_POKER_SEATS; i++) if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
				if (PI[playerid][pPokerActiveHand]) PI[playerid][pPokerHide] = 1;
			}
			pokerTableInfo[tableid][pokerTableCardsActive] = 0;

			pokerTableInfo[tableid][pokerTableStatus] = POKER_STATUS_ENDING;
			pokerTableInfo[tableid][pokerTableDelay] = (20 + 1);
		}
		if (pokerTableInfo[tableid][pokerTableDelay] > 0) {
			pokerTableInfo[tableid][pokerTableDelay]--;
			if (pokerTableInfo[tableid][pokerTableDelay] <= 5 && pokerTableInfo[tableid][pokerTableDelay] > 0) 
				for (new i = 0; i < MAX_POKER_SEATS; i++) if (pokerTableInfo[tableid][pokerTableSlots][i] != INVALID_PLAYER_ID)  {
					PlayerPlaySound(pokerTableInfo[tableid][pokerTableSlots][i], 1139, 0.0, 0.0, 0.0);
				}
		}
		if (pokerTableInfo[tableid][pokerTableRound] == 0 && pokerTableInfo[tableid][pokerTableDelay] == 5) {
			for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
				if (PI[playerid][pPokerChips] <= 0) {
					ErrorMessage(playerid, "У вас недостаточно fishkebi.");
					poker_LeaveGame(playerid);
				}
				else PI[playerid][pPokerStatus] = 1;
			}
			poker_AssignBlinds(tableid);
		}
		if (pokerTableInfo[tableid][pokerTableRound] == 0 && pokerTableInfo[tableid][pokerTableDelay] == 0) {
			pokerTableInfo[tableid][pokerTableRound] = 1;

			poker_SendChat(tableid, "_");
			poker_SendChat(tableid, "~p~NEW ROUND STARTED!");

			for (new i = 0, targetid; i < MAX_POKER_SEATS; i++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
				if (PI[targetid][pPokerLanguage] != PI[targetid][pCasinoLanguage]) {
					PlayerTextDrawSetString(targetid, Poker_PTD[targetid][29], 
						poker_language_massive[(PI[targetid][pPokerLanguage] = PI[targetid][pCasinoLanguage])][8]
					);
				}
				PI[targetid][pPokerStatus_STR] = '\0';
			}
			poker_ShuffleHands(tableid), poker_NextTurn(tableid);
		}
		for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) if (pokerTableInfo[tableid][pokerTableSlots][i] != INVALID_PLAYER_ID) {
			if (PI[(playerid = pokerTableInfo[tableid][pokerTableSlots][i])][pPokerActiveID]) {
				PI[playerid][pPokerTime]--;
				if (PI[playerid][pPokerTime])
					continue;
				if (PI[playerid][pPokerActionActive]) {
					PI[playerid][pPokerActionActive] = 0;
					Dialog_Close(playerid);
				}
				poker_ActionFold(playerid), poker_NextTurn(tableid);
				if (GetPVarInt(playerid, "AFK_Time") >= 5) poker_LeaveGame(playerid);
			}
			else continue;
		}
	}
	new 
		poker_string[128], 
		poker_td_array[MAX_POKER_SEATS] = {0, 4, 8, 12, 16, 20}
	;
	for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) {
		if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][29], poker_language_massive[PI[playerid][pPokerLanguage]][8]);
			PlayerTextDrawShow(playerid, Poker_PTD[playerid][29]);

			new player_Name[MAX_PLAYER_NAME + 24];

			for (new slotid = 0, targetid; slotid < MAX_POKER_SEATS; slotid++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][slotid]) != INVALID_PLAYER_ID) {
				strmid(player_Name, GetName(playerid), 0, MAX_PLAYER_NAME + 1);
				if (targetid == playerid) {
					strreplace(player_Name, "_", "~n~~g~~h~");
					format(player_Name, sizeof(player_Name), "~g~~h~%s~n~~p~%d", player_Name, PI[playerid][pPokerChips]);
				}
				else {
					strreplace(player_Name, "_", "~n~");
					format(player_Name, sizeof(player_Name), "%s~n~~p~%d", player_Name, PI[playerid][pPokerChips]);
				}
				PlayerTextDrawSetString(targetid, Poker_PTD[targetid][poker_td_array[i] + 0], player_Name), player_Name[0] = 0;
				PlayerTextDrawShow(targetid, Poker_PTD[targetid][poker_td_array[i] + 0]);

				if (PI[playerid][pPokerActiveHand]) {
					if (playerid != targetid) {
						if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_ENDING && pokerTableInfo[tableid][pokerTableDelay] <= 19 && PI[playerid][pPokerHide] != 1) {
							strmid(poker_string, CASINO_CARD_INFO[PI[playerid][pPokerCard][0] + 0][CASINO_CARD_NAME], 0, 16);
							PlayerTextDrawSetString(targetid, Poker_PTD[targetid][poker_td_array[i] + 2], poker_string);

							strmid(poker_string, CASINO_CARD_INFO[PI[playerid][pPokerCard][1] + 0][CASINO_CARD_NAME], 0, 16);
							PlayerTextDrawSetString(targetid, Poker_PTD[targetid][poker_td_array[i] + 3], poker_string);
						}
						else {
							PlayerTextDrawSetString(targetid, Poker_PTD[targetid][poker_td_array[i] + 2], "LD_CARD:cdback");
							PlayerTextDrawSetString(targetid, Poker_PTD[targetid][poker_td_array[i] + 3], "LD_CARD:cdback");
						}
						continue;
					}
					strmid(poker_string, CASINO_CARD_INFO[PI[playerid][pPokerCard][0]][CASINO_CARD_NAME], 0, 16);
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[i] + 2], poker_string);

					strmid(poker_string, CASINO_CARD_INFO[PI[playerid][pPokerCard][1]][CASINO_CARD_NAME], 0, 16);
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[i] + 3], poker_string);

					PlayerTextDrawColor(playerid, Poker_PTD[playerid][poker_td_array[i] + 2], -1);
					PlayerTextDrawColor(playerid, Poker_PTD[playerid][poker_td_array[i] + 3], -1);
				}
				else {
					PlayerTextDrawSetString(targetid, Poker_PTD[targetid][poker_td_array[i] + 2], "LD_CARD:cdback");
					PlayerTextDrawSetString(targetid, Poker_PTD[targetid][poker_td_array[i] + 3], "LD_CARD:cdback");

					if (!PI[playerid][pPokerStatus] || PI[playerid][pPokerChips] <= 0 ||
						pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_WAITING || 
						(pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_STARTING && pokerTableInfo[tableid][pokerTableDelay] > 3)
					) {
						PlayerTextDrawColor(targetid, Poker_PTD[targetid][poker_td_array[i] + 2], -201);
						PlayerTextDrawColor(targetid, Poker_PTD[targetid][poker_td_array[i] + 3], -201);
					}
					else { 
						PlayerTextDrawColor(targetid, Poker_PTD[targetid][poker_td_array[i] + 2], -1);
						PlayerTextDrawColor(targetid, Poker_PTD[targetid][poker_td_array[i] + 3], -1);
					}
				}
				PlayerTextDrawShow(targetid, Poker_PTD[targetid][poker_td_array[i] + 2]);
				PlayerTextDrawShow(targetid, Poker_PTD[targetid][poker_td_array[i] + 3]);
				continue;
			}
			if (pokerTableInfo[tableid][pokerTableStatus] < POKER_STATUS_STARTING)  {
				if (0 == PI[playerid][pPokerBet])
					format(poker_string, sizeof(poker_string), "_");
				else format(poker_string, 32, "_~n~~p~%d", PI[playerid][pPokerBet]);
			}
			else if (PI[playerid][pPokerActiveID] && pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_STARTING) {
				if (0 == PI[playerid][pPokerBet]) 
					format(poker_string, sizeof(poker_string), "_~n~~r~00:%02d", PI[playerid][pPokerTime]);
				else format(poker_string, sizeof(poker_string), "~p~%d~n~~r~00:%02d", PI[playerid][pPokerBet], PI[playerid][pPokerTime]);
			}
			else {
				if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_STARTING && pokerTableInfo[tableid][pokerTableDelay] > 5)  {
					if (0 == PI[playerid][pPokerBet]) {
						format(poker_string, sizeof(poker_string), "_");
						PI[playerid][pPokerStatus_STR] = '\0';
					}
					else {
						format(poker_string, 32, "_~n~~p~%d", PI[playerid][pPokerBet]);
						format(PI[playerid][pPokerStatus_STR], 32, "_~n~~p~%d", PI[playerid][pPokerBet]);
					}
				}
				if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_ENDING && pokerTableInfo[tableid][pokerTableDelay] == 19) {
					poker_string[0] = '\0';
					if (pokerTableInfo[tableid][pokerTableWinners] == 1) {
						if (PI[playerid][pPokerWinner]) {
							new poker_splitpot, poker_active_table, poker_active_bet = pokerTableInfo[tableid][pokerTableBet];

							for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID) {
								if (PI[targetid][pPokerBet]) poker_active_table++;
							}
							poker_active_bet = poker_splitpot = PI[playerid][pPokerBet];

							for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID && PI[targetid][pPokerBet]) {
								if (targetid == playerid) continue;

								poker_splitpot += PI[targetid][pPokerBet];

								if (PI[targetid][pPokerBet] > poker_active_bet) {
									poker_splitpot -= (PI[targetid][pPokerBet] - poker_active_bet);
								}
							}
							format(poker_string, sizeof(poker_string), "_~n~~p~+%d", poker_splitpot);
							format(PI[playerid][pPokerStatus_STR], 32, poker_string);
						}
						else if (0 != PI[playerid][pPokerBet]) {
							new winnerid = pokerTableInfo[tableid][pokerTableWinnerID];
							if (winnerid != INVALID_PLAYER_ID) {
								new winner_bet = PI[winnerid][pPokerBet];
								if (PI[playerid][pPokerBet] > winner_bet) 
									format(poker_string, sizeof(poker_string), "_~n~~r~-%d", winner_bet);
								else format(poker_string, sizeof(poker_string), "_~n~~r~-%d", PI[playerid][pPokerBet]);
							}
							else {
								format(poker_string, sizeof(poker_string), "_~n~~r~-%d", PI[playerid][pPokerBet]);
							}
						}
					}
					else {
						if (pokerTableInfo[tableid][pokerTableWinners] > 1) {
							new poker_splitpot, poker_active_table, poker_active_bet = pokerTableInfo[tableid][pokerTableBet];

							for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID) {
								if (PI[targetid][pPokerBet]) poker_active_table++;
							}
							poker_active_bet = poker_splitpot = PI[playerid][pPokerBet];

							for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID && PI[targetid][pPokerBet]) {
								//if (targetid == playerid) continue;
								if (PI[targetid][pPokerWinner])
									continue;
								poker_splitpot += PI[targetid][pPokerBet] / pokerTableInfo[tableid][pokerTableWinners];

								if (PI[targetid][pPokerBet] > poker_active_bet) {
									poker_splitpot -= (PI[targetid][pPokerBet] / pokerTableInfo[tableid][pokerTableWinners] - poker_active_bet / pokerTableInfo[tableid][pokerTableWinners]);
									//PI[targetid][pPokerChips] += (PI[targetid][pPokerBet] - poker_active_bet / pokerTableInfo[tableid][pokerTableWinners]);
								}
							}
							pokerTableInfo[tableid][pokerTableWinnerID] = playerid;
							//poker_splitpot /= pokerTableInfo[tableid][pokerTableWinners];
							format(poker_string, sizeof(poker_string), "_~n~~p~+%d", poker_splitpot);
							format(PI[playerid][pPokerStatus_STR], 32, poker_string);
						}
						else if (0 != PI[playerid][pPokerBet]) {
							new poker_splitpot_main, poker_splitpot, poker_active_table, poker_active_bet = pokerTableInfo[tableid][pokerTableBet];
							for (new idx = 0, winnerid; idx < MAX_POKER_SEATS; idx++) if ((winnerid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID && PI[winnerid][pPokerBet]) {
								if (!PI[winnerid][pPokerWinner])
									continue;
								for (new idx_2 = 0, targetid; idx_2 < MAX_POKER_SEATS; idx_2++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx_2]) != INVALID_PLAYER_ID) {
									if (PI[targetid][pPokerBet]) poker_active_table++;
								}
								poker_active_bet = poker_splitpot = PI[winnerid][pPokerBet];

								for (new idx_2 = 0, targetid; idx_2 < MAX_POKER_SEATS; idx_2++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx_2]) != INVALID_PLAYER_ID && PI[targetid][pPokerBet]) {
									//if (targetid == winnerid) continue;
									if (PI[targetid][pPokerWinner])
										continue;
									poker_splitpot += PI[targetid][pPokerBet] / pokerTableInfo[tableid][pokerTableWinners];

									if (PI[targetid][pPokerBet] > poker_active_bet) {
										poker_splitpot -= (PI[targetid][pPokerBet] / pokerTableInfo[tableid][pokerTableWinners] - poker_active_bet / pokerTableInfo[tableid][pokerTableWinners]);
										//PI[targetid][pPokerChips] += (PI[targetid][pPokerBet] - poker_active_bet);
									}
								}
								pokerTableInfo[tableid][pokerTableWinnerID] = winnerid;
								//poker_splitpot /= pokerTableInfo[tableid][pokerTableWinners];
								poker_splitpot_main += poker_splitpot;
							}
							format(poker_string, sizeof(poker_string), "_~n~~r~-%d", PI[playerid][pPokerBet]);
						}
					}
					format(PI[playerid][pPokerStatus_STR], 32, poker_string);

					if (PI[playerid][pPokerWinner] && PI[playerid][pPokerActiveHand] && PI[playerid][pPokerHide] != 1)
						format(PI[playerid][pPokerStatus_STR], 32, PI[playerid][pPokerResult_STR]);
				}
				if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_ENDING && pokerTableInfo[tableid][pokerTableDelay] == 10) {
					poker_string[0] = '\0';

					if (pokerTableInfo[tableid][pokerTableWinners] == 1) {
						if (PI[playerid][pPokerWinner]) {

							new poker_splitpot, poker_active_table, poker_active_bet = pokerTableInfo[tableid][pokerTableBet];

							for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID) {
								if (PI[targetid][pPokerBet]) poker_active_table++;
							}
							poker_active_bet = poker_splitpot = PI[playerid][pPokerBet];

							for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID && PI[targetid][pPokerBet]) {
								if (targetid == playerid) continue;

								poker_splitpot += PI[targetid][pPokerBet];

								if (PI[targetid][pPokerBet] > poker_active_bet) {
									poker_splitpot -= (PI[targetid][pPokerBet] - poker_active_bet);
								}
							}
							format(poker_string, sizeof(poker_string), "_~n~~p~+%d", poker_splitpot);
							format(PI[playerid][pPokerStatus_STR], 32, poker_string);
						
						}
						else if (0 != PI[playerid][pPokerBet]) {
							new winnerid = pokerTableInfo[tableid][pokerTableWinnerID];
							if (winnerid != INVALID_PLAYER_ID) {
								new winner_bet = PI[winnerid][pPokerBet];
								if (PI[playerid][pPokerBet] > winner_bet) 
									format(poker_string, sizeof(poker_string), "_~n~~r~-%d", winner_bet);
								else format(poker_string, sizeof(poker_string), "_~n~~r~-%d", PI[playerid][pPokerBet]);
							}
							else {
								format(poker_string, sizeof(poker_string), "_~n~~r~-%d", PI[playerid][pPokerBet]);
							}
						}
					}
					else {
						if (PI[playerid][pPokerWinner]) {
							new poker_splitpot, poker_active_table, poker_active_bet = pokerTableInfo[tableid][pokerTableBet];

							for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID) {
								if (PI[targetid][pPokerBet]) poker_active_table++;
							}
							poker_active_bet = poker_splitpot = PI[playerid][pPokerBet];

							for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID && PI[targetid][pPokerBet]) {
								//if (targetid == playerid) continue;
								if (PI[targetid][pPokerWinner])
									continue;
								poker_splitpot += PI[targetid][pPokerBet] / pokerTableInfo[tableid][pokerTableWinners];

								if (PI[targetid][pPokerBet] > poker_active_bet) {
									poker_splitpot -= (PI[targetid][pPokerBet] / pokerTableInfo[tableid][pokerTableWinners] - poker_active_bet / pokerTableInfo[tableid][pokerTableWinners]);
									PI[targetid][pPokerChips] += (PI[targetid][pPokerBet] / pokerTableInfo[tableid][pokerTableWinners] - poker_active_bet / pokerTableInfo[tableid][pokerTableWinners]);
								}
							}
							pokerTableInfo[tableid][pokerTableWinnerID] = playerid;
							//poker_splitpot /= pokerTableInfo[tableid][pokerTableWinners];
							
							format(poker_string, sizeof(poker_string), "_~n~~p~+%d", poker_splitpot);
							format(PI[playerid][pPokerStatus_STR], 32, poker_string);
						}
						else if (0 != PI[playerid][pPokerBet]) {
							new poker_splitpot_main, poker_splitpot, poker_active_table, poker_active_bet = pokerTableInfo[tableid][pokerTableBet];
							for (new idx = 0, winnerid; idx < MAX_POKER_SEATS; idx++) if ((winnerid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID && PI[winnerid][pPokerBet]) {
								if (!PI[winnerid][pPokerWinner])
									continue;
								for (new idx_2 = 0, targetid; idx_2 < MAX_POKER_SEATS; idx_2++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx_2]) != INVALID_PLAYER_ID) {
									if (PI[targetid][pPokerBet]) poker_active_table++;
								}
								poker_active_bet = poker_splitpot = PI[winnerid][pPokerBet];

								for (new idx_2 = 0, targetid; idx_2 < MAX_POKER_SEATS; idx_2++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx_2]) != INVALID_PLAYER_ID && PI[targetid][pPokerBet]) {
									//if (targetid == winnerid) continue;
									if (PI[targetid][pPokerWinner])
										continue;
									poker_splitpot += PI[targetid][pPokerBet] / pokerTableInfo[tableid][pokerTableWinners];

									if (PI[targetid][pPokerBet] > poker_active_bet) {
										poker_splitpot -= (PI[targetid][pPokerBet] / pokerTableInfo[tableid][pokerTableWinners] - poker_active_bet / pokerTableInfo[tableid][pokerTableWinners]);
										//PI[targetid][pPokerChips] += (PI[targetid][pPokerBet] - poker_active_bet);
									}
								}
								pokerTableInfo[tableid][pokerTableWinnerID] = winnerid;
								//poker_splitpot /= pokerTableInfo[tableid][pokerTableWinners];
								poker_splitpot_main += poker_splitpot;
							}
							format(poker_string, sizeof(poker_string), "_~n~~r~-%d", poker_splitpot_main);
						}
					}
					format(PI[playerid][pPokerStatus_STR], 32, poker_string);
				}
				format(poker_string, 32, PI[playerid][pPokerStatus_STR]);
			}
			for (new slotid = 0, targetid; slotid < MAX_POKER_SEATS; slotid++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][slotid]) != INVALID_PLAYER_ID) 
				PlayerTextDrawSetString(targetid, Poker_PTD[targetid][poker_td_array[i] + 1], poker_string);
			new language_id = PI[playerid][pPokerLanguage];

			if (pokerTableInfo[tableid][pokerTableRound] == 1) {
				if (pokerTableInfo[tableid][pokerTablePot] < 5)
					format(poker_string, sizeof(poker_string), "%s: ~p~0", poker_language_massive[language_id][0]);
				else format(poker_string, sizeof(poker_string), "%s: ~p~%d", poker_language_massive[language_id][0], pokerTableInfo[tableid][pokerTablePot]);
				PlayerTextDrawSetString(playerid, Poker_PTD[playerid][26], poker_string);
			}			
			if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_STARTING) {
				if (pokerTableInfo[tableid][pokerTablePot] < 5)
					format(poker_string, sizeof(poker_string), "%s: ~p~0", poker_language_massive[language_id][0]);
				else format(poker_string, sizeof(poker_string), "%s: ~p~%d", poker_language_massive[language_id][0], pokerTableInfo[tableid][pokerTablePot]);
				PlayerTextDrawSetString(playerid, Poker_PTD[playerid][26], poker_string);
			}
			else if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_ENDING && pokerTableInfo[tableid][pokerTableDelay] < 19) {
				if (pokerTableInfo[tableid][pokerTableWinnerID] != INVALID_PLAYER_ID) {
					new winner_id = pokerTableInfo[tableid][pokerTableWinnerID];
					new poker_splitpot, poker_active_table, poker_active_bet = pokerTableInfo[tableid][pokerTableBet];

					for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID) {
						if (PI[targetid][pPokerBet]) poker_active_table++;
					}
					poker_active_bet = poker_splitpot = PI[winner_id][pPokerBet];

					for (new idx = 0, targetid; idx < MAX_POKER_SEATS; idx++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][idx]) != INVALID_PLAYER_ID && PI[targetid][pPokerBet]) {
						if (targetid == winner_id) continue;

						poker_splitpot += PI[targetid][pPokerBet];

						if (PI[targetid][pPokerBet] > poker_active_bet) {
							poker_splitpot -= (PI[targetid][pPokerBet] - poker_active_bet);
						}
					}
					format(poker_string, sizeof(poker_string), "~y~%s ~w~%s ~p~%d", 
						GetName(pokerTableInfo[tableid][pokerTableWinnerID]), poker_language_massive[language_id][3], poker_splitpot
					);
				}
				else if (pokerTableInfo[tableid][pokerTableWinners] > 1) {
					new poker_splitpot = (pokerTableInfo[tableid][pokerTablePot] / pokerTableInfo[tableid][pokerTableWinners]);
					format(poker_string, sizeof(poker_string), "~y~%d ~w~%s~p~%d", 
						pokerTableInfo[tableid][pokerTableWinners], poker_language_massive[language_id][2], poker_splitpot
					);
				}
				PlayerTextDrawSetString(playerid, Poker_PTD[playerid][26], poker_string);
			}
			else PlayerTextDrawSetString(playerid, Poker_PTD[playerid][26], "_");

			if (pokerTableInfo[tableid][pokerTableDelay] > 0 && pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_STARTING) {
				format(poker_string, sizeof(poker_string), "%s ~r~%d", 
					poker_language_massive[language_id][4], pokerTableInfo[tableid][pokerTableDelay]
				);
				PlayerTextDrawSetString(playerid, Poker_PTD[playerid][25], poker_string);
			}
			else if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_WAITING) {
				format(poker_string, sizeof(poker_string), "%s...", poker_language_massive[language_id][6]);
				PlayerTextDrawSetString(playerid, Poker_PTD[playerid][25], poker_string);
			}
			else if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_STARTING) {
				for (new slotid = 0; slotid < MAX_POKER_SEATS; slotid++) {
					new targetid = pokerTableInfo[tableid][pokerTableSlots][slotid];
					if (targetid != INVALID_PLAYER_ID && PI[targetid][pPokerTime] && PI[targetid][pPokerOptions]) {
						format(poker_string, sizeof(poker_string), "%s: ~p~%d", poker_language_massive[language_id][1], pokerTableInfo[tableid][pokerTableBet]);
						PlayerTextDrawSetString(playerid, Poker_PTD[playerid][25], poker_string);
						break;
					}
				}
			}
			else if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_ENDING) {
				format(poker_string, sizeof(poker_string), "%s ~r~%d~w~~h~", 
					poker_language_massive[language_id][5], pokerTableInfo[tableid][pokerTableDelay]
				);
				PlayerTextDrawSetString(playerid, Poker_PTD[playerid][25], poker_string);
			}
			else PlayerTextDrawSetString(playerid, Poker_PTD[playerid][25], "_");

			switch (pokerTableInfo[tableid][pokerTableCardsActive]) {
				case 0: {
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][30], "LD_CARD:cdback");
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][31], "LD_CARD:cdback");
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][32], "LD_CARD:cdback");
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][33], "LD_CARD:cdback");
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][34], "LD_CARD:cdback");

					PlayerTextDrawColor(playerid, Poker_PTD[playerid][33], -1523963137), PlayerTextDrawShow(playerid, Poker_PTD[playerid][33]);
					PlayerTextDrawColor(playerid, Poker_PTD[playerid][34], -1523963137), PlayerTextDrawShow(playerid, Poker_PTD[playerid][34]);
				}
				case 1: {
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][30], CASINO_CARD_INFO[pokerTableInfo[tableid][pokerTableCards][0] + 0][CASINO_CARD_NAME]);
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][31], CASINO_CARD_INFO[pokerTableInfo[tableid][pokerTableCards][1] + 0][CASINO_CARD_NAME]);
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][32], CASINO_CARD_INFO[pokerTableInfo[tableid][pokerTableCards][2] + 0][CASINO_CARD_NAME]);
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][33], "LD_CARD:cdback");
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][34], "LD_CARD:cdback");
					PlayerTextDrawColor(playerid, Poker_PTD[playerid][33], -1523963137), PlayerTextDrawShow(playerid, Poker_PTD[playerid][33]);
					PlayerTextDrawColor(playerid, Poker_PTD[playerid][34], -1523963137), PlayerTextDrawShow(playerid, Poker_PTD[playerid][34]);
				}
				case 2: {
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][30], CASINO_CARD_INFO[pokerTableInfo[tableid][pokerTableCards][0] + 0][CASINO_CARD_NAME]);
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][31], CASINO_CARD_INFO[pokerTableInfo[tableid][pokerTableCards][1] + 0][CASINO_CARD_NAME]);
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][32], CASINO_CARD_INFO[pokerTableInfo[tableid][pokerTableCards][2] + 0][CASINO_CARD_NAME]);
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][33], CASINO_CARD_INFO[pokerTableInfo[tableid][pokerTableCards][3] + 0][CASINO_CARD_NAME]);
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][34], "LD_CARD:cdback");
					PlayerTextDrawColor(playerid, Poker_PTD[playerid][33], -1), PlayerTextDrawShow(playerid, Poker_PTD[playerid][33]);
					PlayerTextDrawColor(playerid, Poker_PTD[playerid][34], -1523963137), PlayerTextDrawShow(playerid, Poker_PTD[playerid][34]);
				}
				case 3, 4: {
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][30], CASINO_CARD_INFO[pokerTableInfo[tableid][pokerTableCards][0] + 0][CASINO_CARD_NAME]);
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][31], CASINO_CARD_INFO[pokerTableInfo[tableid][pokerTableCards][1] + 0][CASINO_CARD_NAME]);
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][32], CASINO_CARD_INFO[pokerTableInfo[tableid][pokerTableCards][2] + 0][CASINO_CARD_NAME]);
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][33], CASINO_CARD_INFO[pokerTableInfo[tableid][pokerTableCards][3] + 0][CASINO_CARD_NAME]);
					PlayerTextDrawSetString(playerid, Poker_PTD[playerid][34], CASINO_CARD_INFO[pokerTableInfo[tableid][pokerTableCards][4] + 0][CASINO_CARD_NAME]);
					PlayerTextDrawColor(playerid, Poker_PTD[playerid][33], -1), PlayerTextDrawShow(playerid, Poker_PTD[playerid][33]);
					PlayerTextDrawColor(playerid, Poker_PTD[playerid][34], -1), PlayerTextDrawShow(playerid, Poker_PTD[playerid][34]);
				}
				default: continue;
			}
		}
		else for (new slotid = 0, targetid; slotid < MAX_POKER_SEATS; slotid++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][slotid]) != INVALID_PLAYER_ID) {
			PlayerTextDrawSetString(targetid, Poker_PTD[targetid][poker_td_array[i] + 0], "MECЏO~n~C‹OЂOѓHO");
			PlayerTextDrawHide(targetid, Poker_PTD[targetid][poker_td_array[i] + 0]);
			PlayerTextDrawSetString(targetid, Poker_PTD[targetid][poker_td_array[i] + 1], "_");

			PlayerTextDrawSetString(targetid, Poker_PTD[targetid][poker_td_array[i] + 2], "_");
			PlayerTextDrawSetString(targetid, Poker_PTD[targetid][poker_td_array[i] + 3], "_");

			PlayerTextDrawColor(targetid, Poker_PTD[targetid][poker_td_array[i] + 2], -201);
			PlayerTextDrawColor(targetid, Poker_PTD[targetid][poker_td_array[i] + 3], -201);

			PlayerTextDrawShow(targetid, Poker_PTD[targetid][poker_td_array[i] + 2]);
			PlayerTextDrawShow(targetid, Poker_PTD[targetid][poker_td_array[i] + 3]);
		}
		continue;
	}
	return true;
}

poker_AssignBlinds(tableid) {
	if (pokerTableInfo[tableid][pokerTablePosID] >= pokerTableInfo[tableid][pokerTablePlayers]) 
		pokerTableInfo[tableid][pokerTablePosID] = 0;
	new playerid = INVALID_PLAYER_ID, pos_id = pokerTableInfo[tableid][pokerTablePosID];

	pokerTableInfo[tableid][pokerTablePosID]++;
	if (pokerTableInfo[tableid][pokerTablePlayersActive] > 2) {
		playerid = poker_FindPlayersOrder(tableid, pos_id);

		if (playerid != INVALID_PLAYER_ID) {
			PI[playerid][pPokerDealer] = 1;
			if (0 == PI[playerid][pPokerBet])
				PI[playerid][pPokerStatus_STR] = '\0';
			else format(PI[playerid][pPokerStatus_STR], 32, "_~n~~p~%d", PI[playerid][pPokerBet]);

			for (new i = 0, targetid; i < MAX_POKER_SEATS; i++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID)
				poker_CreateDealerIcon(targetid, pos_id);
		}
		else return poker_AssignBlinds(tableid);
		pos_id++;
	}
	if (pokerTableInfo[tableid][pokerTablePlayersActive] > 1) {
		if (pos_id >= pokerTableInfo[tableid][pokerTablePlayers]) pos_id = 0;
		playerid = poker_FindPlayersOrder(tableid, pos_id);

		if (playerid != INVALID_PLAYER_ID) {
			format(PI[playerid][pPokerStatus_STR], 32, "_~n~~r~-%d", pokerTableInfo[tableid][pokerTableBlind] / 2);

			pokerTableInfo[tableid][pokerTablePot] += (pokerTableInfo[tableid][pokerTableBlind] / 2 > PI[playerid][pPokerChips]) ? PI[playerid][pPokerChips] : pokerTableInfo[tableid][pokerTableBlind] / 2;
			PI[playerid][pPokerChips] = (pokerTableInfo[tableid][pokerTableBlind] / 2 > PI[playerid][pPokerChips]) ? 0 : PI[playerid][pPokerChips] - (pokerTableInfo[tableid][pokerTableBlind] / 2);

			PI[playerid][pPokerBet] = pokerTableInfo[tableid][pokerTableBet] = (pokerTableInfo[tableid][pokerTableBlind] / 2);
		}
		else return poker_AssignBlinds(tableid);

		pos_id++; if (pos_id >= pokerTableInfo[tableid][pokerTablePlayers]) pos_id = 0;
		playerid = poker_FindPlayersOrder(tableid, pos_id);

		if (playerid != INVALID_PLAYER_ID) {
			format(PI[playerid][pPokerStatus_STR], 32, "_~n~~r~-%d", pokerTableInfo[tableid][pokerTableBlind]);

			pokerTableInfo[tableid][pokerTablePot] += (PI[playerid][pPokerChips] < pokerTableInfo[tableid][pokerTableBlind]) ? PI[playerid][pPokerChips] : pokerTableInfo[tableid][pokerTableBlind];
			PI[playerid][pPokerChips] = (PI[playerid][pPokerChips] < pokerTableInfo[tableid][pokerTableBlind]) ? 0 : PI[playerid][pPokerChips]  - pokerTableInfo[tableid][pokerTableBlind];

			PI[playerid][pPokerBet] = pokerTableInfo[tableid][pokerTableBet] = (pokerTableInfo[tableid][pokerTableBlind]);
		}
		else return poker_AssignBlinds(tableid);
	}
	return true;
}
poker_ShuffleHands(tableid) {
 	for (new i = 0; i < MAX_POKER_SEATS; i++) if (pokerTableInfo[tableid][pokerTableSlots][i] != INVALID_PLAYER_ID) 
 		PlayerPlaySound(pokerTableInfo[tableid][pokerTableSlots][i], 5600, 0.0, 0.0, 0.0);
	for (new i = 0; i < MAX_CASINO_CARDS; i++) 
		pokerTableInfo[tableid][pokerTableDeck][i] = i;
	new rand, tmp, i;

	for (i = MAX_CASINO_CARDS; i > 1; i--) {
		rand = random(MAX_CASINO_CARDS) % i;
		tmp = pokerTableInfo[tableid][pokerTableDeck][rand];
		pokerTableInfo[tableid][pokerTableDeck][rand] = pokerTableInfo[tableid][pokerTableDeck][i - 1];
		pokerTableInfo[tableid][pokerTableDeck][i - 1] = tmp;
	}
	poker_DealHands(tableid); 

	return true;
}
poker_DealHands(tableid) {
	new tmp_id = 0;
	for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
		if (PI[playerid][pPokerStatus] && PI[playerid][pPokerChips] > 0) {
			PI[playerid][pPokerCard][0] = pokerTableInfo[tableid][pokerTableDeck][tmp_id + 0];
			PI[playerid][pPokerCard][1] = pokerTableInfo[tableid][pokerTableDeck][tmp_id + 1];

			PI[playerid][pPokerActiveHand] = 1;

			pokerTableInfo[tableid][pokerTableHandsActive]++;

			PlayerPlaySound(playerid, 5602, 0.0, 0.0, 0.0);
			ApplyAnimation(playerid, "CASINO", "cards_in", 4.1, 0, 1, 1, 1, 1, 1);

			tmp_id += 2;
		}
		else continue;
	}
	for (new i = 0; i < 5; i++) {
		pokerTableInfo[tableid][pokerTableCards][i] = pokerTableInfo[tableid][pokerTableDeck][tmp_id];
		tmp_id++;
	}
	return true;
}
poker_FindPlayersOrder(tableid, index) {
	new index_id;
	for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
		if (PI[playerid][pPokerStatus] == 1 && index_id == index) 
			return playerid;
		index_id++;
	}
	return INVALID_PLAYER_ID;
}
poker_NextTurn(tableid) {
	new next_playerid = INVALID_PLAYER_ID, last_playerid = INVALID_PLAYER_ID, last_slotid = INVALID_PLAYER_ID;

	if (pokerTableInfo[tableid][pokerTableGuestActive] != INVALID_PLAYER_ID) {
		last_playerid = pokerTableInfo[tableid][pokerTableGuestActive];

		for (new i = 0; i < MAX_POKER_SEATS; i++) if (pokerTableInfo[tableid][pokerTableSlots][i] == last_playerid) 
			last_slotid = i;
		PI[last_playerid][pPokerActiveID] = 
		PI[last_playerid][pPokerTime] = 0;
		poker_UpdateOptions(last_playerid, POKER_OPTION_NONE);
	}
	if (pokerTableInfo[tableid][pokerTableRot] == 0 && last_playerid == INVALID_PLAYER_ID && last_slotid == INVALID_PLAYER_ID) for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) {
		if (!PI[(playerid = pokerTableInfo[tableid][pokerTableSlots][i])][pPokerDealer]) 
			continue;
		next_playerid = pokerTableInfo[tableid][pokerTableGuestActive] = playerid;
	
		pokerTableInfo[tableid][pokerTableSlots_rot] = 
		pokerTableInfo[tableid][pokerTableGuestActiveSlotID] = i;
		pokerTableInfo[tableid][pokerTableRot]++;
	}
	else if (pokerTableInfo[tableid][pokerTableRot] >= 6) {
		pokerTableInfo[tableid][pokerTableRot] = 0;
		pokerTableInfo[tableid][pokerTableCardsActive]++;

		if (pokerTableInfo[tableid][pokerTableCardsActive] > 3) {
			pokerTableInfo[tableid][pokerTableStatus] = POKER_STATUS_ENDING;
			pokerTableInfo[tableid][pokerTableDelay] = (20 + 1);
			
			return true;
		}
		pokerTableInfo[tableid][pokerTableSlots_rot]++, pokerTableInfo[tableid][pokerTableRot]++;
		if (pokerTableInfo[tableid][pokerTableSlots_rot] >= 6) 
			pokerTableInfo[tableid][pokerTableSlots_rot] -= 6;

		new playerid = poker_FindPlayersOrder(tableid, pokerTableInfo[tableid][pokerTableSlots_rot]);

		if (playerid != INVALID_PLAYER_ID) {
			next_playerid = pokerTableInfo[tableid][pokerTableGuestActive] = playerid;
			pokerTableInfo[tableid][pokerTableGuestActiveSlotID] = pokerTableInfo[tableid][pokerTableSlots_rot];
		}
		else poker_NextTurn(tableid);
	}
	else {
		pokerTableInfo[tableid][pokerTableSlots_rot]++, pokerTableInfo[tableid][pokerTableRot]++;
		if (pokerTableInfo[tableid][pokerTableSlots_rot] >= 6) 
			pokerTableInfo[tableid][pokerTableSlots_rot] -= 6;

		new playerid = poker_FindPlayersOrder(tableid, pokerTableInfo[tableid][pokerTableSlots_rot]);

		if (playerid != INVALID_PLAYER_ID) {
			next_playerid = pokerTableInfo[tableid][pokerTableGuestActive] = playerid;
			pokerTableInfo[tableid][pokerTableGuestActiveSlotID] = pokerTableInfo[tableid][pokerTableSlots_rot];
		}
		else poker_NextTurn(tableid);
	}
	if (next_playerid != INVALID_PLAYER_ID && PI[next_playerid][pPokerActiveHand]) {
		new currentBet = PI[next_playerid][pPokerBet], poker_actual_bet = pokerTableInfo[tableid][pokerTableBet];
		PlayerPlaySound(next_playerid, 5809, 0.0, 0.0, 0.0);

		if (PI[next_playerid][pPokerChips] < 1) 
			poker_UpdateOptions(next_playerid, POKER_OPTION_CF);
		else if (currentBet >= poker_actual_bet) 
			poker_UpdateOptions(next_playerid, POKER_OPTION_RCF);
		else if (currentBet < poker_actual_bet) 
			poker_UpdateOptions(next_playerid, POKER_OPTION_CRF);
		else poker_UpdateOptions(next_playerid, POKER_OPTION_NONE);

		PI[next_playerid][pPokerTime] = (30 + 1);
		PI[next_playerid][pPokerActiveID] = 1;
	}
	return true;
}

poker_ActionCall(playerid)
	return poker_ShowMenu(playerid, PM_MENU_CALL);
poker_ActionRaise(playerid)
	return poker_ShowMenu(playerid, PM_MENU_RAISE);
poker_ActionCheck(playerid) {
	if (PI[playerid][pPokerActiveHand])  {
		new tableid = (PI[playerid][pPokerTableID] - 1), poker_text_td[MAX_PLAYER_NAME + 10];
		format(poker_text_td, sizeof(poker_text_td), "%s ~y~CHECK", GetName(playerid));
		poker_SendChat(tableid, poker_text_td);
		format(PI[playerid][pPokerStatus_STR], 32, "~p~%d~n~~y~CHECK", PI[playerid][pPokerBet]);
	}
	return ApplyAnimation(playerid, "CASINO", "cards_raise", 4.1, 0, 1, 1, 1, 1, 1);
}
poker_ActionFold(playerid) {
	if (PI[playerid][pPokerActiveHand] < 1) 
		return false;
	PI[playerid][pPokerCard][0] = PI[playerid][pPokerCard][1] = 
	PI[playerid][pPokerActiveHand] = PI[playerid][pPokerStatus] = 0;

	new tableid = (PI[playerid][pPokerTableID] - 1), poker_text_td[MAX_PLAYER_NAME + 8];
	
	pokerTableInfo[tableid][pokerTableHandsActive]--;
	if (0 == PI[playerid][pPokerBet])
		format(PI[playerid][pPokerStatus_STR], 32, "_~n~~y~FOLD");
	else format(PI[playerid][pPokerStatus_STR], 32, "~p~%d~n~~y~FOLD", PI[playerid][pPokerBet]);

	format(poker_text_td, sizeof(poker_text_td), "%s ~y~FOLD", GetName(playerid));
	poker_SendChat(tableid, poker_text_td);

	for (new i = 0, targetid; i < MAX_POKER_SEATS; i++) if ((targetid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) 
		PlayerPlaySound(targetid, 5602, 0.0, 0.0, 0.0);
	ApplyAnimation(playerid, "CASINO", "cards_out", 4.1, 0, 1, 1, 1, 1, 1);
	 
	return true;
}
poker_CreateTable(Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid) {
	if (Iter_Count(pokerTables) >= MAX_pokerTableInfoS)
		return false;
	new tableid = Iter_Free(pokerTables), tmp_objectid;

	pokerTableInfo[tableid][pokerTableObjectID] = tmp_objectid = CreateDynamicObject(19474, 
		(pokerTableInfo[tableid][pokerTablePos][0] = x), (pokerTableInfo[tableid][pokerTablePos][1] = y), 
		(pokerTableInfo[tableid][pokerTablePos][2] = z), (pokerTableInfo[tableid][pokerTablePos][3] = rx), 
		(pokerTableInfo[tableid][pokerTablePos][4] = ry), (pokerTableInfo[tableid][pokerTablePos][5] = rz), 
		(pokerTableInfo[tableid][pokerTableWorld] = worldid), (pokerTableInfo[tableid][pokerTableInterior] = interiorid), (-1)
	);
	SetDynamicObjectMaterial(tmp_objectid, 1, 14789, "ab_sfgymmain", "ab_wood02", 0x00000000);
	SetDynamicObjectMaterial(tmp_objectid, 2, 14581, "ab_mafiasuitea", "ab_wood01", 0x00000000);

	tmp_objectid = CreateAttachDynamicObject(pokerTableInfo[tableid][pokerTableObjectID],
		1714, 0.000492, -2.650637, -0.553, 0.000000, 0.000000, 180.000000, worldid, interiorid, (-1)
	), SetDynamicObjectMaterial(tmp_objectid, 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	tmp_objectid = CreateAttachDynamicObject(pokerTableInfo[tableid][pokerTableObjectID],
		1714, 0.000492, 2.550362, -0.553, 0.000000, 0.000000, 0.000000, worldid, interiorid, (-1)
	), SetDynamicObjectMaterial(tmp_objectid, 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	tmp_objectid = CreateAttachDynamicObject(pokerTableInfo[tableid][pokerTableObjectID],
		1714, -1.940507, 0.500362, -0.553, 0.000000, 0.000000, 90.000000, worldid, interiorid, (-1)
	), SetDynamicObjectMaterial(tmp_objectid, 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	tmp_objectid = CreateAttachDynamicObject(pokerTableInfo[tableid][pokerTableObjectID],
		1714, -1.940507, -0.759637, -0.553, 0.000000, 0.000000, 90.000000, worldid, interiorid, (-1)
	), SetDynamicObjectMaterial(tmp_objectid, 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	tmp_objectid = CreateAttachDynamicObject(pokerTableInfo[tableid][pokerTableObjectID],
		1714, 1.930492, -0.759637, -0.553, -0.000002, 0.000000, -89.999969, worldid, interiorid, (-1)
	), SetDynamicObjectMaterial(tmp_objectid, 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);
	tmp_objectid = CreateAttachDynamicObject(pokerTableInfo[tableid][pokerTableObjectID],
		1714, 1.930492, 0.500362, -0.553, -0.000002, 0.000000, -89.999969, worldid, interiorid, (-1)
	), SetDynamicObjectMaterial(tmp_objectid, 0, 14668, "711c", "bwtilebroth", 0xFFFFFFFF);

	poker_ResetTable(tableid);

	pokerTableInfo[tableid][pokerTableAreaID] = CreateDynamicSphere(
	   	pokerTableInfo[tableid][pokerTablePos][0], pokerTableInfo[tableid][pokerTablePos][1], pokerTableInfo[tableid][pokerTablePos][2], 
	   	2.0, pokerTableInfo[tableid][pokerTableWorld], pokerTableInfo[tableid][pokerTableInterior], -1
   	);
   	pokerTableInfo[tableid][pokerTableTextID] = CreateDynamic3DTextLabel("{d8284c}Texas Holdem Poker\n \n{FFFFFF}Daachiret {d8284c}\"ENTER\"", -1, 
		pokerTableInfo[tableid][pokerTablePos][0], pokerTableInfo[tableid][pokerTablePos][1], pokerTableInfo[tableid][pokerTablePos][2] + 1.3, 5.0, 
		INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, pokerTableInfo[tableid][pokerTableWorld], pokerTableInfo[tableid][pokerTableInterior], -1
	);
    Iter_Add(pokerTables, tableid);

	return (tableid + 1);
}
poker_ResetTable(tableid) {
	pokerTableInfo[tableid][pokerTableBlind] = POKER_DEFAULT_BLIND;
	pokerTableInfo[tableid][pokerTableMaxBet] = POKER_DEFAULT_MAX_BET;
	pokerTableInfo[tableid][pokerTableMinBet] = POKER_DEFAULT_MIN_BET;
	pokerTableInfo[tableid][pokerTableEnterPrice] = POKER_DEFAULT_SEAT_PRICE;

	pokerTableInfo[tableid][pokerTableStatus] = pokerTableInfo[tableid][pokerTablePosID] = 
	pokerTableInfo[tableid][pokerTableRound] = pokerTableInfo[tableid][pokerTableCardsActive] = 
	pokerTableInfo[tableid][pokerTableBet] = pokerTableInfo[tableid][pokerTableDelay] = 
	pokerTableInfo[tableid][pokerTablePot] = pokerTableInfo[tableid][pokerTableRot] = 
	pokerTableInfo[tableid][pokerTableSlots_rot] = pokerTableInfo[tableid][pokerTableWinners] = 
	pokerTableInfo[tableid][pokerTablePlayers] = pokerTableInfo[tableid][pokerTablePlayersActive] = 
	pokerTableInfo[tableid][pokerTableTimer] = 0;

	pokerTableInfo[tableid][pokerTableWinnerID] = INVALID_PLAYER_ID;
	pokerTableInfo[tableid][pokerTableSetDelay] = 15;

	for (new targetid = 0; targetid < (pokerTableInfo[tableid][pokerTableLimit] = MAX_POKER_SEATS); targetid++) 
		pokerTableInfo[tableid][pokerTableSlots][targetid] = INVALID_PLAYER_ID;
	format(pokerTableInfo[tableid][pokerChatBuffer], (64 * 10), "_~n~_~n~_~n~_~n~_~n~_~n~_~n~_~n~_~n~_");

	return true;
}
poker_ResetRound(tableid) {
	pokerTableInfo[tableid][pokerTableRound] = 
	pokerTableInfo[tableid][pokerTableCardsActive] = 
	pokerTableInfo[tableid][pokerTableBet] = 
	pokerTableInfo[tableid][pokerTablePot] = 
	pokerTableInfo[tableid][pokerTableRot] = 
	pokerTableInfo[tableid][pokerTableSlots_rot] = 
	pokerTableInfo[tableid][pokerTableWinners] = 
	pokerTableInfo[tableid][pokerTableHandsActive] = 0;

	pokerTableInfo[tableid][pokerTableLastRaiseID] = INVALID_PLAYER_ID;

	pokerTableInfo[tableid][pokerTableStatus] = POKER_STATUS_WAITING;
	pokerTableInfo[tableid][pokerTableWinnerID] = INVALID_PLAYER_ID;
	pokerTableInfo[tableid][pokerTableDelay] = pokerTableInfo[tableid][pokerTableSetDelay];

	for (new i = 0, playerid; i < MAX_POKER_SEATS; i++) if ((playerid = pokerTableInfo[tableid][pokerTableSlots][i]) != INVALID_PLAYER_ID) {
		PI[playerid][pPokerActiveHand] = 
		PI[playerid][pPokerWinner] = 
		PI[playerid][pPokerDealer] = 
		PI[playerid][pPokerTime] = 
		PI[playerid][pPokerBet] = 
		PI[playerid][pPokerHide] =
		PI[playerid][pPokerCard][0] = 
		PI[playerid][pPokerCard][1] = 
		PI[playerid][pPokerActiveID] = 0;
		PI[playerid][pPokerResult_STR] = '\0';

		poker_DestroyDealerIcon(playerid);
		ApplyAnimation(playerid, "CASINO", "cards_out", 4.1, 0, 1, 1, 1, 1, 1);
	}
	return true;
}
poker_createTD() {
	Poker_TD[0] = TextDrawCreate(10.000000, 318.000000, "bg_chat");
	TextDrawLetterSize(Poker_TD[0], 0.000000, 13.800023);
	TextDrawTextSize(Poker_TD[0], 154.000000, 0.000000);
	TextDrawAlignment(Poker_TD[0], 1);
	TextDrawColor(Poker_TD[0], -1);
	TextDrawUseBox(Poker_TD[0], 1);
	TextDrawBoxColor(Poker_TD[0], 245);
	TextDrawSetShadow(Poker_TD[0], 0);
	TextDrawBackgroundColor(Poker_TD[0], 255);
	TextDrawFont(Poker_TD[0], 1);
	TextDrawSetProportional(Poker_TD[0], 1);

	Poker_TD[1] = TextDrawCreate(255.000000, 211.000000, "bg_main_cards");
	TextDrawLetterSize(Poker_TD[1], 0.000000, 4.612007);
	TextDrawTextSize(Poker_TD[1], 385.000000, 0.000000);
	TextDrawAlignment(Poker_TD[1], 1);
	TextDrawColor(Poker_TD[1], -1);
	TextDrawUseBox(Poker_TD[1], 1);
	TextDrawBoxColor(Poker_TD[1], -1523963137);
	TextDrawSetShadow(Poker_TD[1], 0);
	TextDrawBackgroundColor(Poker_TD[1], 255);
	TextDrawFont(Poker_TD[1], 1);
	TextDrawSetProportional(Poker_TD[1], 1);

	Poker_TD[2] = TextDrawCreate(560.000000, 400.500000, "click_exit");
	TextDrawTextSize(Poker_TD[2], 79.000000, 48.000000);
	TextDrawAlignment(Poker_TD[2], 1);
	TextDrawColor(Poker_TD[2], 336860401);
	TextDrawSetShadow(Poker_TD[2], 0);
	TextDrawFont(Poker_TD[2], 5);
	TextDrawSetProportional(Poker_TD[2], 0);
	TextDrawSetSelectable(Poker_TD[2], true);
	TextDrawSetPreviewModel(Poker_TD[2], 10955);
	TextDrawBackgroundColor(Poker_TD[2], 0);
	TextDrawSetPreviewRot(Poker_TD[2], 90.000000, 0.000000, 0.000000, 1.000000);

	Poker_TD[3] = TextDrawCreate(600.629699, 418.066802, "EXIT");
	TextDrawLetterSize(Poker_TD[3], 0.477306, 2.002500);
	TextDrawAlignment(Poker_TD[3], 2);
	TextDrawColor(Poker_TD[3], -1400377345);
	TextDrawSetShadow(Poker_TD[3], 0);
	TextDrawSetOutline(Poker_TD[3], 1);
	TextDrawBackgroundColor(Poker_TD[3], 255);
	TextDrawFont(Poker_TD[3], 1);
	TextDrawSetProportional(Poker_TD[3], 1);

	Poker_TD[4] = TextDrawCreate(214.000000, 390.000000, "Click_1");
	TextDrawTextSize(Poker_TD[4], 75.000000, 39.000000);
	TextDrawAlignment(Poker_TD[4], 1);
	TextDrawColor(Poker_TD[4], 168430320);
	TextDrawSetShadow(Poker_TD[4], 0);
	TextDrawFont(Poker_TD[4], 5);
	TextDrawSetProportional(Poker_TD[4], 0);
	TextDrawSetSelectable(Poker_TD[4], true);
	TextDrawSetPreviewModel(Poker_TD[4], 10955);
	TextDrawBackgroundColor(Poker_TD[4], 0);
	TextDrawSetPreviewRot(Poker_TD[4], 90.000000, 0.000000, 0.000000, 1.000000);

	Poker_TD[5] = TextDrawCreate(281.500000, 390.000000, "Click_2");
	TextDrawTextSize(Poker_TD[5], 75.000000, 39.000000);
	TextDrawAlignment(Poker_TD[5], 1);
	TextDrawColor(Poker_TD[5], 168430320);
	TextDrawSetShadow(Poker_TD[5], 0);
	TextDrawFont(Poker_TD[5], 5);
	TextDrawSetProportional(Poker_TD[5], 0);
	TextDrawSetSelectable(Poker_TD[5], true);
	TextDrawSetPreviewModel(Poker_TD[5], 10955);
	TextDrawBackgroundColor(Poker_TD[5], 0);
	TextDrawSetPreviewRot(Poker_TD[5], 90.000000, 0.000000, 0.000000, 1.000000);

	Poker_TD[6] = TextDrawCreate(350.000000, 390.000000, "Click_3");
	TextDrawTextSize(Poker_TD[6], 75.000000, 39.000000);
	TextDrawAlignment(Poker_TD[6], 1);
	TextDrawColor(Poker_TD[6], 168430320);
	TextDrawSetShadow(Poker_TD[6], 0);
	TextDrawFont(Poker_TD[6], 5);
	TextDrawSetProportional(Poker_TD[6], 0);
	TextDrawSetSelectable(Poker_TD[6], true);
	TextDrawSetPreviewModel(Poker_TD[6], 10955);
	TextDrawBackgroundColor(Poker_TD[6], 0);
	TextDrawSetPreviewRot(Poker_TD[6], 90.000000, 0.000000, 0.000000, 1.000000);

	Poker_TD[7] = TextDrawCreate(509.568420, 32.666698, "bg_hand_ranking");
	TextDrawTextSize(Poker_TD[7], 119.000000, 236.000000);
	TextDrawAlignment(Poker_TD[7], 1);
	TextDrawColor(Poker_TD[7], -1);
	TextDrawSetShadow(Poker_TD[7], 0);
	TextDrawBackgroundColor(Poker_TD[7], 168430335);
	TextDrawFont(Poker_TD[7], 5);
	TextDrawSetProportional(Poker_TD[7], 0);
	TextDrawSetPreviewModel(Poker_TD[7], 0);
	TextDrawSetPreviewRot(Poker_TD[7], 0.000000, 0.000000, 0.000000, 100.000000);

	Poker_TD[8] = TextDrawCreate(562.144042, 368.681732, "click_handranking");
	TextDrawTextSize(Poker_TD[8], 75.000000, 39.000000);
	TextDrawAlignment(Poker_TD[8], 1);
	TextDrawColor(Poker_TD[8], 673720575);
	TextDrawSetShadow(Poker_TD[8], 0);
	TextDrawFont(Poker_TD[8], 5);
	TextDrawSetProportional(Poker_TD[8], 0);
	TextDrawSetSelectable(Poker_TD[8], true);
	TextDrawSetPreviewModel(Poker_TD[8], 10955);
	TextDrawBackgroundColor(Poker_TD[8], 0);
	TextDrawSetPreviewRot(Poker_TD[8], 90.000000, 0.000000, 0.000000, 1.000000);

	Poker_TD[9] = TextDrawCreate(601.081176, 382.265106, "~w~HAND~n~~w~RANKING");
	TextDrawLetterSize(Poker_TD[9], 0.223627, 0.909995);
	TextDrawAlignment(Poker_TD[9], 2);
	TextDrawColor(Poker_TD[9], -2139094785);
	TextDrawSetShadow(Poker_TD[9], 0);
	TextDrawSetOutline(Poker_TD[9], 1);
	TextDrawBackgroundColor(Poker_TD[9], 255);
	TextDrawFont(Poker_TD[9], 1);
	TextDrawSetProportional(Poker_TD[9], 1);

	for (new hr_id = 0, td_id; hr_id < (MAX_POKER_HAND_RANKING); hr_id++) {
		if ((td_id = hr_id) >= 5) td_id -= 5;
		pokerName_HR_TD[hr_id] = TextDrawCreate(
			(515.685974), (39.083385 + (45.0 * td_id)), 
			poker_hand_ranking[hr_id][0]
		);
		TextDrawLetterSize(pokerName_HR_TD[hr_id], 0.228052, 0.913330);
		TextDrawTextSize(pokerName_HR_TD[hr_id], 610.000000, 0.000000);
		TextDrawAlignment(pokerName_HR_TD[hr_id], 1);
		TextDrawColor(pokerName_HR_TD[hr_id], -1524159745);
		TextDrawSetShadow(pokerName_HR_TD[hr_id], 0);
		TextDrawSetOutline(pokerName_HR_TD[hr_id], 1);
		TextDrawBackgroundColor(pokerName_HR_TD[hr_id], -1);
		TextDrawFont(pokerName_HR_TD[hr_id], 1);
		TextDrawSetProportional(pokerName_HR_TD[hr_id], 1);

		for (new card_id = 0; card_id < 5; card_id++) {
			pokerCard_HR_TD[hr_id][card_id] = TextDrawCreate(
				(514.685974 + (22.0 * card_id)), 
				(47.583393 + (45.0 * td_id)), 
				poker_hand_ranking[hr_id][card_id + 1]
			);
			TextDrawTextSize(pokerCard_HR_TD[hr_id][card_id], 21.000000, 35.000000);
			TextDrawAlignment(pokerCard_HR_TD[hr_id][card_id], 1);
			TextDrawColor(pokerCard_HR_TD[hr_id][card_id], -1);
			TextDrawSetShadow(pokerCard_HR_TD[hr_id][card_id], 0);
			TextDrawBackgroundColor(pokerCard_HR_TD[hr_id][card_id], 255);
			TextDrawFont(pokerCard_HR_TD[hr_id][card_id], 4);
			TextDrawSetProportional(pokerCard_HR_TD[hr_id][card_id], 0);
		}
	}
	PokerTutorial_TD[0] = TextDrawCreate(7.950197, 177.166702, "BG_TUTORIAL");
	TextDrawLetterSize(PokerTutorial_TD[0], 0.000000, 9.109808);
	TextDrawTextSize(PokerTutorial_TD[0], 157.000000, 0.000000);
	TextDrawAlignment(PokerTutorial_TD[0], 1);
	TextDrawColor(PokerTutorial_TD[0], -1);
	TextDrawUseBox(PokerTutorial_TD[0], 1);
	TextDrawBoxColor(PokerTutorial_TD[0], 336860415);
	TextDrawSetShadow(PokerTutorial_TD[0], 0);
	TextDrawBackgroundColor(PokerTutorial_TD[0], 255);
	TextDrawFont(PokerTutorial_TD[0], 1);
	TextDrawSetProportional(PokerTutorial_TD[0], 1);

	PokerTutorial_TD[1] = TextDrawCreate(82.476600, 161.850128, "SWAVLA"); 
	TextDrawLetterSize(PokerTutorial_TD[1], 0.302547, 1.343333);
	TextDrawTextSize(PokerTutorial_TD[1], 0.000000, 149.500000);
	TextDrawAlignment(PokerTutorial_TD[1], 2);
	TextDrawColor(PokerTutorial_TD[1], -1);
	TextDrawUseBox(PokerTutorial_TD[1], 1);
	TextDrawBoxColor(PokerTutorial_TD[1], -1523963166);
	TextDrawSetShadow(PokerTutorial_TD[1], 0);
	TextDrawBackgroundColor(PokerTutorial_TD[1], 255);
	TextDrawFont(PokerTutorial_TD[1], 1);
	TextDrawSetProportional(PokerTutorial_TD[1], 1);

	PokerTutorial_TD[2] = TextDrawCreate(47.000000, 245.000000, "~w~<< ~w~~h~UKAN");
	TextDrawLetterSize(PokerTutorial_TD[2], 0.219619, 1.214999);
	TextDrawTextSize(PokerTutorial_TD[2], 10.000000, 73.000000);
	TextDrawAlignment(PokerTutorial_TD[2], 2);
	TextDrawColor(PokerTutorial_TD[2], -1);
	TextDrawUseBox(PokerTutorial_TD[2], 1);
	TextDrawBoxColor(PokerTutorial_TD[2], -1523963137);
	TextDrawSetShadow(PokerTutorial_TD[2], 0);
	TextDrawBackgroundColor(PokerTutorial_TD[2], 255);
	TextDrawFont(PokerTutorial_TD[2], 1);
	TextDrawSetProportional(PokerTutorial_TD[2], 1);
	TextDrawSetSelectable(PokerTutorial_TD[2], true);

	PokerTutorial_TD[3] = TextDrawCreate(118.000000, 245.000000, "~w~>> ~w~~h~SHEMDEG");
	TextDrawLetterSize(PokerTutorial_TD[3], 0.219619, 1.214999);
	TextDrawTextSize(PokerTutorial_TD[3], 10.000000, 73.000000);
	TextDrawAlignment(PokerTutorial_TD[3], 2);
	TextDrawColor(PokerTutorial_TD[3], -1);
	TextDrawUseBox(PokerTutorial_TD[3], 1);
	TextDrawBoxColor(PokerTutorial_TD[3], 8388863);
	TextDrawSetShadow(PokerTutorial_TD[3], 0);
	TextDrawBackgroundColor(PokerTutorial_TD[3], 255);
	TextDrawFont(PokerTutorial_TD[3], 1);
	TextDrawSetProportional(PokerTutorial_TD[3], 1);
	TextDrawSetSelectable(PokerTutorial_TD[3], true);
}
stock poker_ShowHandRanking(playerid, page = 0) {
	if (0 == page) {
		if (PI[playerid][pPokerHandRanking]) 
			return poker_HideHandRanking(playerid);
		else page = 1;
	}
	if (PI[playerid][pPokerHandRanking] == page) 
		return false;
	else if (PI[playerid][pPokerHandRanking] != 0) {
		new tmp_page = PI[playerid][pPokerHandRanking];
		for (new hr_id = 0 + (5 * (tmp_page - 1)); hr_id < (5 * tmp_page); hr_id++) {
			for (new card_id = 0; card_id < 5; card_id++) 
				TextDrawHideForPlayer(playerid, pokerCard_HR_TD[hr_id][card_id]);
			TextDrawHideForPlayer(playerid, pokerName_HR_TD[hr_id]);
		}
	}
	for (new hr_id = 0 + (5 * (page - 1)); hr_id < (5 * page); hr_id++) {
		for (new card_id = 0; card_id < 5; card_id++) 
			TextDrawShowForPlayer(playerid, pokerCard_HR_TD[hr_id][card_id]);
		TextDrawShowForPlayer(playerid, pokerName_HR_TD[hr_id]);
	}
	if (0 == PI[playerid][pPokerHandRanking]) 
		TextDrawShowForPlayer(playerid, Poker_TD[7]);
	
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][38], (1 == page) ? (8388863) : (255));
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][39], (2 == page) ? (8388863) : (255));

	PlayerTextDrawShow(playerid, Poker_PTD[playerid][38]);
	PlayerTextDrawShow(playerid, Poker_PTD[playerid][39]);

	return (PI[playerid][pPokerHandRanking] = page);
}
stock poker_HideHandRanking(playerid) {
	if (0 == PI[playerid][pPokerHandRanking]) 
		return false;

	new tmp_page = PI[playerid][pPokerHandRanking];
	for (new hr_id = 0 + (5 * (tmp_page - 1)); hr_id < (5 * tmp_page); hr_id++) {
		for (new card_id = 0; card_id < 5; card_id++) 
			TextDrawHideForPlayer(playerid, pokerCard_HR_TD[hr_id][card_id]);
		TextDrawHideForPlayer(playerid, pokerName_HR_TD[hr_id]);
	}
	PlayerTextDrawHide(playerid, Poker_PTD[playerid][38]);
	PlayerTextDrawHide(playerid, Poker_PTD[playerid][39]);
	TextDrawHideForPlayer(playerid, Poker_TD[7]);
	return (PI[playerid][pPokerHandRanking] = 0), true;
}

poker_CreatePTD(playerid, seatid) {
	if (PI[playerid][pPokerGUI]) 
		return false;
	new language_id = PI[playerid][pPokerLanguage];

	#define Poker_TD_1 (4 * 0)
	#define Poker_TD_2 (4 * 1)
	#define Poker_TD_3 (4 * 2)
	#define Poker_TD_4 (4 * 3)
	#define Poker_TD_5 (4 * 4)
	#define Poker_TD_6 (4 * 5)

	/* (1 POKER TABLE SLOT) */
	Poker_PTD[playerid][Poker_TD_1 + 0] = CreatePlayerTextDraw(playerid, 384.000000, 346.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][Poker_TD_1 + 0], 0.189631, 0.940832);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_1 + 0], 0.000000, 61.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_1 + 0], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_1 + 0], -1);
	PlayerTextDrawUseBox(playerid, Poker_PTD[playerid][Poker_TD_1 + 0], 1);
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][Poker_TD_1 + 0], 168430335);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_1 + 0], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][Poker_TD_1 + 0], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_1 + 0], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_1 + 0], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_1 + 0], 1);
	PlayerTextDrawHide(playerid, Poker_PTD[playerid][Poker_TD_1 + 0]);

	Poker_PTD[playerid][Poker_TD_1 + 1] = CreatePlayerTextDraw(playerid, 379.000000, 260.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][Poker_TD_1 + 1], 0.17601, 0.870832);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_1 + 1], 0.000000, 47.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_1 + 1], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_1 + 1], 255);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_1 + 1], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][Poker_TD_1 + 1], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_1 + 1], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_1 + 1], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_1 + 1], 1);

	Poker_PTD[playerid][Poker_TD_1 + 2] = CreatePlayerTextDraw(playerid, 353.000000, 277.000000, "_"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_1 + 2], 25.000000, 40.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_1 + 2], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_1 + 2], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_1 + 2], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_1 + 2], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_1 + 2], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_1 + 2], 0);

	Poker_PTD[playerid][Poker_TD_1 + 3] = CreatePlayerTextDraw(playerid, 379.000000, 277.000000, "_"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_1 + 3], 25.000000, 40.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_1 + 3], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_1 + 3], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_1 + 3], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_1 + 3], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_1 + 3], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_1 + 3], 0);

	/* (2 POKER TABLE SLOT) */
	Poker_PTD[playerid][Poker_TD_2 + 0] = CreatePlayerTextDraw(playerid, 256.000000, 346.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][Poker_TD_2 + 0], 0.189631, 0.940832);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_2 + 0], 0.000000, 61.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_2 + 0], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_2 + 0], -1);
	PlayerTextDrawUseBox(playerid, Poker_PTD[playerid][Poker_TD_2 + 0], 1);
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][Poker_TD_2 + 0], 168430335);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_2 + 0], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][Poker_TD_2 + 0], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_2 + 0], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_2 + 0], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_2 + 0], 1);

	Poker_PTD[playerid][Poker_TD_2 + 1] = CreatePlayerTextDraw(playerid, 262.000000, 260.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][Poker_TD_2 + 1], 0.176045, 0.870832);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_2 + 1], 0.000000, 47.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_2 + 1], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_2 + 1], 255);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_2 + 1], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][Poker_TD_2 + 1], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_2 + 1], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_2 + 1], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_2 + 1], 1);

	Poker_PTD[playerid][Poker_TD_2 + 2] = CreatePlayerTextDraw(playerid, 236.000000, 277.000000, "_"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_2 + 2], 25.000000, 40.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_2 + 2], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_2 + 2], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_2 + 2], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_2 + 2], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_2 + 2], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_2 + 2], 0);

	Poker_PTD[playerid][Poker_TD_2 + 3] = CreatePlayerTextDraw(playerid, 262.000000, 277.000000, "_"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_2 + 3], 25.000000, 40.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_2 + 3], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_2 + 3], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_2 + 3], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_2 + 3], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_2 + 3], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_2 + 3], 0);

	/* (3 POKER TABLE SLOT) */
	Poker_PTD[playerid][Poker_TD_3 + 0] = CreatePlayerTextDraw(playerid, 131.000000, 272.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][Poker_TD_3 + 0], 0.189631, 0.940832);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_3 + 0], 0.000000, 61.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_3 + 0], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_3 + 0], -1);
	PlayerTextDrawUseBox(playerid, Poker_PTD[playerid][Poker_TD_3 + 0], 1);
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][Poker_TD_3 + 0], 168430335);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_3 + 0], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][Poker_TD_3 + 0], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_3 + 0], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_3 + 0], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_3 + 0], 1);

	Poker_PTD[playerid][Poker_TD_3 + 1] = CreatePlayerTextDraw(playerid, 209.500000, 186.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][Poker_TD_3 + 1], 0.176045, 0.870832);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_3 + 1], 0.000000, 47.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_3 + 1], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_3 + 1], 255);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_3 + 1], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][Poker_TD_3 + 1], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_3 + 1], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_3 + 1], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_3 + 1], 1);

	Poker_PTD[playerid][Poker_TD_3 + 2] = CreatePlayerTextDraw(playerid, 184.000000, 203.000000, "_"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_3 + 2], 25.000000, 40.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_3 + 2], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_3 + 2], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_3 + 2], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_3 + 2], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_3 + 2], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_3 + 2], 0);

	Poker_PTD[playerid][Poker_TD_3 + 3] = CreatePlayerTextDraw(playerid, 210.000000, 203.000000, "_"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_3 + 3], 25.000000, 40.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_3 + 3], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_3 + 3], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_3 + 3], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_3 + 3], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_3 + 3], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_3 + 3], 0);

	/* (4 POKER TABLE SLOT) */
	Poker_PTD[playerid][Poker_TD_4 + 0] = CreatePlayerTextDraw(playerid, 256.000000, 76.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][Poker_TD_4 + 0], 0.189631, 0.940832);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_4 + 0], 0.000000, 61.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_4 + 0], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_4 + 0], -1);
	PlayerTextDrawUseBox(playerid, Poker_PTD[playerid][Poker_TD_4 + 0], 1);
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][Poker_TD_4 + 0], 168430335);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_4 + 0], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][Poker_TD_4 + 0], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_4 + 0], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_4 + 0], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_4 + 0], 1);

	Poker_PTD[playerid][Poker_TD_4 + 1] = CreatePlayerTextDraw(playerid, 262.000000, 125.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][Poker_TD_4 + 1], 0.176045, 0.870832);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_4 + 1], 0.000000, 47.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_4 + 1], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_4 + 1], 255);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_4 + 1], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][Poker_TD_4 + 1], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_4 + 1], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_4 + 1], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_4 + 1], 1);

	Poker_PTD[playerid][Poker_TD_4 + 2] = CreatePlayerTextDraw(playerid, 236.000000, 142.000000, "_"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_4 + 2], 25.000000, 40.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_4 + 2], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_4 + 2], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_4 + 2], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_4 + 2], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_4 + 2], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_4 + 2], 0);

	Poker_PTD[playerid][Poker_TD_4 + 3] = CreatePlayerTextDraw(playerid, 262.000000, 142.000000, "_"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_4 + 3], 25.000000, 40.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_4 + 3], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_4 + 3], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_4 + 3], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_4 + 3], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_4 + 3], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_4 + 3], 0);

	/* (5 POKER TABLE SLOT) */
	Poker_PTD[playerid][Poker_TD_5 + 0] = CreatePlayerTextDraw(playerid, 384.000000, 76.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][Poker_TD_5 + 0], 0.189631, 0.940832);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_5 + 0], 0.000000, 61.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_5 + 0], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_5 + 0], -1);
	PlayerTextDrawUseBox(playerid, Poker_PTD[playerid][Poker_TD_5 + 0], 1);
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][Poker_TD_5 + 0], 168430335);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_5 + 0], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][Poker_TD_5 + 0], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_5 + 0], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_5 + 0], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_5 + 0], 1);

	Poker_PTD[playerid][Poker_TD_5 + 1] = CreatePlayerTextDraw(playerid, 379.000000, 125.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][Poker_TD_5 + 1], 0.176045, 0.870832);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_5 + 1], 0.000000, 47.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_5 + 1], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_5 + 1], 255);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_5 + 1], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][Poker_TD_5 + 1], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_5 + 1], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_5 + 1], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_5 + 1], 1);

	Poker_PTD[playerid][Poker_TD_5 + 2] = CreatePlayerTextDraw(playerid, 353.000000, 142.000000, "_"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_5 + 2], 25.000000, 40.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_5 + 2], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_5 + 2], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_5 + 2], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_5 + 2], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_5 + 2], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_5 + 2], 0);

	Poker_PTD[playerid][Poker_TD_5 + 3] = CreatePlayerTextDraw(playerid, 379.000000, 142.000000, "_"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_5 + 3], 25.000000, 40.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_5 + 3], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_5 + 3], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_5 + 3], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_5 + 3], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_5 + 3], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_5 + 3], 0);

	/* (6 POKER TABLE SLOT) */
	Poker_PTD[playerid][Poker_TD_6 + 0] = CreatePlayerTextDraw(playerid, 508.000000, 272.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][Poker_TD_6 + 0], 0.189631, 0.940832);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_6 + 0], 0.000000, 61.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_6 + 0], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_6 + 0], -1);
	PlayerTextDrawUseBox(playerid, Poker_PTD[playerid][Poker_TD_6 + 0], 1);
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][Poker_TD_6 + 0], 168430335);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_6 + 0], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][Poker_TD_6 + 0], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_6 + 0], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_6 + 0], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_6 + 0], 1);

	Poker_PTD[playerid][Poker_TD_6 + 1] = CreatePlayerTextDraw(playerid, 430.000000, 186.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][Poker_TD_6 + 1], 0.176045, 0.870832);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_6 + 1], 0.000000, 47.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_6 + 1], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_6 + 1], 255);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_6 + 1], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][Poker_TD_6 + 1], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_6 + 1], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_6 + 1], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_6 + 1], 1);

	Poker_PTD[playerid][Poker_TD_6 + 2] = CreatePlayerTextDraw(playerid, 405.000000, 203.000000, "_"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_6 + 2], 25.000000, 40.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_6 + 2], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_6 + 2], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_6 + 2], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_6 + 2], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_6 + 2], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_6 + 2], 0);

	Poker_PTD[playerid][Poker_TD_6 + 3] = CreatePlayerTextDraw(playerid, 431.000000, 203.000000, "_"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][Poker_TD_6 + 3], 25.000000, 40.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][Poker_TD_6 + 3], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][Poker_TD_6 + 3], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][Poker_TD_6 + 3], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][Poker_TD_6 + 3], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][Poker_TD_6 + 3], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][Poker_TD_6 + 3], 0);


	Poker_PTD[playerid][25] = CreatePlayerTextDraw(playerid, 320.000000, 256.300018, "_"); // ДО КОНЦА ХОДА ~y~23 ~w~~h~CEK.
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][25], 0.163396, 0.789164);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][25], 0.000000, 131.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][25], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][25], -1);
	PlayerTextDrawUseBox(playerid, Poker_PTD[playerid][25], 1);
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][25], -1523963392);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][25], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][25], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][25], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][25], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][25], 1);

	Poker_PTD[playerid][26] = CreatePlayerTextDraw(playerid, 320.000000, 194.000244, "_"); // БАНК: ~p~15,000
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][26], 0.245387, 1.092500);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][26], 0.000000, 157.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][26], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][26], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][26], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][26], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][26], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][26], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][26], 1);

	Poker_PTD[playerid][27] = CreatePlayerTextDraw(playerid, 320.000000, 429.016571, "_"); // ВАШ БАНК: ~p~23,000
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][27], 0.240702, 1.115833);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][27], 0.000000, 183.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][27], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][27], -1);
	PlayerTextDrawUseBox(playerid, Poker_PTD[playerid][27], 1);
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][27], 255);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][27], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][27], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][27], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][27], 1);

	Poker_PTD[playerid][28] = CreatePlayerTextDraw(playerid, 320.000000, 386.099639, poker_language_massive[language_id][9]);
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][28], 0.228989, 1.004999);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][28], 0.000000, 81.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][28], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][28], -1);
	PlayerTextDrawUseBox(playerid, Poker_PTD[playerid][28], 1);
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][28], -1523963137);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][28], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][28], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][28], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][28], 1);

	new Float:poker_ptd_float[MAX_POKER_SEATS][2] = {
		{418.39, 371.39}, {290.39, 371.39},
		{165.39, 297.39}, {290.39, 101.40},
		{418.39, 101.40}, {542.40, 297.39}
	};
	Poker_PTD[playerid][29] = CreatePlayerTextDraw(playerid, poker_ptd_float[seatid][0], poker_ptd_float[seatid][1], poker_language_massive[language_id][8]);
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][29], 0.178856, 0.894164);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][29], 0.000000, 12.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][29], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][29], -1);
	PlayerTextDrawUseBox(playerid, Poker_PTD[playerid][29], 1);
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][29], -2139094785);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][29], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][29], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][29], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][29], 1);

	/* (MAIN POKER CARDS) */
	Poker_PTD[playerid][30] = CreatePlayerTextDraw(playerid, 255.500000, 212.000000, "LD_CARD:cdback"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][30], 25.000000, 39.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][30], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][30], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][30], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][30], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][30], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][30], 0);

	Poker_PTD[playerid][31] = CreatePlayerTextDraw(playerid, 281.500000, 212.000000, "LD_CARD:cdback"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][31], 25.000000, 39.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][31], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][31], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][31], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][31], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][31], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][31], 0);

	Poker_PTD[playerid][32] = CreatePlayerTextDraw(playerid, 307.500000, 212.000000, "LD_CARD:cdback"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][32], 25.000000, 39.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][32], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][32], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][32], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][32], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][32], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][32], 0);

	Poker_PTD[playerid][33] = CreatePlayerTextDraw(playerid, 333.500000, 212.000000, "LD_CARD:cdback"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][33], 25.000000, 39.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][33], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][33], -1523963137);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][33], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][33], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][33], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][33], 0);

	Poker_PTD[playerid][34] = CreatePlayerTextDraw(playerid, 359.500000, 212.000000, "LD_CARD:cdback"); // LD_CARD:cdback
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][34], 25.000000, 39.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][34], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][34], -1523963137);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][34], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][34], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][34], 4);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][34], 0);

	Poker_PTD[playerid][35] = CreatePlayerTextDraw(playerid, 252.000000, 405.500030, "_"); // key 1
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][35], 0.300000, 1.399999);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][35], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][35], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][35], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][35], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][35], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][35], 1);

	Poker_PTD[playerid][36] = CreatePlayerTextDraw(playerid, 320.000000, 405.500030, "_"); // key 2
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][36], 0.300000, 1.399999);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][36], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][36], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][36], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][36], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][36], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][36], 1);

	Poker_PTD[playerid][37] = CreatePlayerTextDraw(playerid, 387.500030, 405.500030, "_"); // key 3
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][37], 0.300000, 1.399999);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][37], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][37], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][37], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][37], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][37], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][37], 1);

	Poker_PTD[playerid][38] = CreatePlayerTextDraw(playerid, 593.132995, 272.250091, "1");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][38], 0.335343, 1.424998);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][38], 12.000000, 20.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][38], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][38], -1);
	PlayerTextDrawUseBox(playerid, Poker_PTD[playerid][38], 1);
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][38], 255);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][38], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][38], -1);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][38], 1);
	PlayerTextDrawSetSelectable(playerid, Poker_PTD[playerid][38], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][38], 1);

	Poker_PTD[playerid][39] = CreatePlayerTextDraw(playerid, 616.559143, 272.250061, "2");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][39], 0.335343, 1.424998);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][39], 12.000000, 20.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][39], 2);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][39], -1);
	PlayerTextDrawUseBox(playerid, Poker_PTD[playerid][39], 1);
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][39], 255);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][39], 0);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][39], -1);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][39], 1);
	PlayerTextDrawSetSelectable(playerid, Poker_PTD[playerid][39], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][39], 1);

	Poker_PTD[playerid][POKER_CHAT_TD + 0] = CreatePlayerTextDraw(playerid, 13.000000, 320.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 0], 0.201811, 1.034165);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 0], 175.895996, 0.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 0], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 0], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 0], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 0], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 0], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 0], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 0], 1);

	Poker_PTD[playerid][POKER_CHAT_TD + 1] = CreatePlayerTextDraw(playerid, 13.000000, 332.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 1], 0.201811, 1.034165);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 1], 175.499908, 0.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 1], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 1], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 1], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 1], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 1], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 1], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 1], 1);

	Poker_PTD[playerid][POKER_CHAT_TD + 2] = CreatePlayerTextDraw(playerid, 13.000000, 345.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 2], 0.201811, 1.034165);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 2], 175.499908, 0.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 2], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 2], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 2], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 2], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 2], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 2], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 2], 1);

	Poker_PTD[playerid][POKER_CHAT_TD + 3] = CreatePlayerTextDraw(playerid, 13.000000, 357.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 3], 0.201811, 1.034165);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 3], 175.499908, 0.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 3], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 3], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 3], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 3], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 3], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 3], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 3], 1);

	Poker_PTD[playerid][POKER_CHAT_TD + 4] = CreatePlayerTextDraw(playerid, 13.000000, 369.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 4], 0.201811, 1.034165);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 4], 175.499908, 0.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 4], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 4], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 4], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 4], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 4], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 4], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 4], 1);

	Poker_PTD[playerid][POKER_CHAT_TD + 5] = CreatePlayerTextDraw(playerid, 13.000000, 381.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 5], 0.201811, 1.034165);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 5], 175.499908, 0.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 5], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 5], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 5], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 5], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 5], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 5], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 5], 1);

	Poker_PTD[playerid][POKER_CHAT_TD + 6] = CreatePlayerTextDraw(playerid, 13.000000, 393.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 6], 0.201811, 1.034165);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 6], 175.499908, 0.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 6], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 6], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 6], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 6], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 6], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 6], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 6], 1);

	Poker_PTD[playerid][POKER_CHAT_TD + 7] = CreatePlayerTextDraw(playerid, 13.000000, 405.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 7], 0.201811, 1.034165);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 7], 175.499908, 0.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 7], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 7], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 7], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 7], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 7], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 7], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 7], 1);

	Poker_PTD[playerid][POKER_CHAT_TD + 8] = CreatePlayerTextDraw(playerid, 13.000000, 417.000000, "_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 8], 0.201811, 1.034165);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 8], 175.499908, 0.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 8], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 8], -1);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 8], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 8], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 8], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 8], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 8], 1);

	Poker_PTD[playerid][POKER_CHAT_TD + 9] = CreatePlayerTextDraw(playerid, 13.000000, 430.000000, "~>~_");
	PlayerTextDrawLetterSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 9], 0.197595, 1.022498);
	PlayerTextDrawTextSize(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 9], 151.094451, 0.000000);
	PlayerTextDrawAlignment(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 9], 1);
	PlayerTextDrawColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 9], -1523963137);
	PlayerTextDrawUseBox(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 9], 1);
	PlayerTextDrawBoxColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 9], 336860415);
	PlayerTextDrawSetShadow(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 9], 0);
	PlayerTextDrawSetOutline(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 9], 1);
	PlayerTextDrawBackgroundColor(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 9], 255);
	PlayerTextDrawFont(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 9], 1);
	PlayerTextDrawSetProportional(playerid, Poker_PTD[playerid][POKER_CHAT_TD + 9], 1);

	#undef Poker_TD_1 
	#undef Poker_TD_2
	#undef Poker_TD_3
	#undef Poker_TD_4
	#undef Poker_TD_5
	#undef Poker_TD_6

	PokerTutorial_PTD[playerid] = CreatePlayerTextDraw(playerid, 10.000000, 180.000000, "_"); // Текст обучения
	PlayerTextDrawLetterSize(playerid, PokerTutorial_PTD[playerid], 0.206499, 1.109998);
	PlayerTextDrawTextSize(playerid, PokerTutorial_PTD[playerid], 155.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, PokerTutorial_PTD[playerid], 1);
	PlayerTextDrawColor(playerid, PokerTutorial_PTD[playerid], -1);
	PlayerTextDrawSetShadow(playerid, PokerTutorial_PTD[playerid], 0);
	PlayerTextDrawSetOutline(playerid, PokerTutorial_PTD[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, PokerTutorial_PTD[playerid], 255);
	PlayerTextDrawFont(playerid, PokerTutorial_PTD[playerid], 1);
	PlayerTextDrawSetProportional(playerid, PokerTutorial_PTD[playerid], 1);

	return (PI[playerid][pPokerGUI] = 1);
}
poker_DestroyGUI(playerid) {
	if (!PI[playerid][pPokerGUI]) 
		return false;
	poker_HideHandRanking(playerid);
	poker_DestroyDealerIcon(playerid);

	for (new i = 0; i < sizeof(Poker_TD); i++) 
		TextDrawHideForPlayer(playerid, Poker_TD[i]);
	for (new i = 0; i < sizeof(PokerTutorial_TD); i++) 
		TextDrawHideForPlayer(playerid, PokerTutorial_TD[i]);
	for (new i = 0; i < (40 + 10); i++) 
		if (i != 24) PlayerTextDrawDestroy(playerid, Poker_PTD[playerid][i]);
	PlayerTextDrawDestroy(playerid, PokerTutorial_PTD[playerid]);
	PI[playerid][pPokerGUI] = 0;
	return true;
}
poker_ShowGUI(playerid) {
	poker_DestroyDealerIcon(playerid);

	for (new i = 0; i < 10; i++) {
		switch (i) {
			case 4..7: continue;	// options | hr_backgroud
		}
		TextDrawShowForPlayer(playerid, Poker_TD[i]);
	}
	for (new i = 1; i < (40 + 10); i++) {
		switch (i) {
			case 0, 4, 8, 12, 16, 20/* << motamashis saxeli */, 27/* tqveni BANK */, 28/* tqveni svla */, 29 /* you */, 38, 39: continue;
		}
		PlayerTextDrawShow(playerid, Poker_PTD[playerid][i]);
	}
	PlayerTextDrawHide(playerid, Poker_PTD[playerid][0]);

	return true;
}
poker_DestroyDealerIcon(playerid) {
	if (0 != PI[playerid][pPokerDealerIcon]) {
		PlayerTextDrawDestroy(playerid, PokerDI_PTD[playerid][0]);
		PlayerTextDrawDestroy(playerid, PokerDI_PTD[playerid][1]);
		PI[playerid][pPokerDealerIcon] = 0;
	}
}
poker_CreateDealerIcon(playerid, position) {
	new tableid = (PI[playerid][pPokerTableID] - 1);
	if (!(tableid + 1)) return;

	new Float:poker_icon_float[6][2] = { 
		/*
			|*	4	5	*|	
			|3			6|
			|*	2	1	*|
		*/
		{338.0, 288.0},	{287.0, 288.0},	{235.0, 215.5},	
		{287.0, 153.0},	{338.0, 153.0},	{390.0, 215.5}
	};
	if (0 != PI[playerid][pPokerDealerIcon]) {
		PlayerTextDrawDestroy(playerid, PokerDI_PTD[playerid][0]);
		PlayerTextDrawDestroy(playerid, PokerDI_PTD[playerid][1]);
		PI[playerid][pPokerDealerIcon] = 0;
	}
	PokerDI_PTD[playerid][0] = CreatePlayerTextDraw(playerid, poker_icon_float[position][0], poker_icon_float[position][1], "ld_beat:chit"); 
	PlayerTextDrawTextSize(playerid, PokerDI_PTD[playerid][0], 15.000000, 18.000000);
	PlayerTextDrawAlignment(playerid, PokerDI_PTD[playerid][0], 1);
	PlayerTextDrawColor(playerid, PokerDI_PTD[playerid][0], -1061109505);
	PlayerTextDrawSetShadow(playerid, PokerDI_PTD[playerid][0], 0);
	PlayerTextDrawBackgroundColor(playerid, PokerDI_PTD[playerid][0], 255);
	PlayerTextDrawFont(playerid, PokerDI_PTD[playerid][0], 4);
	PlayerTextDrawSetProportional(playerid, PokerDI_PTD[playerid][0], 0);
	PlayerTextDrawShow(playerid, PokerDI_PTD[playerid][0]);

	PokerDI_PTD[playerid][1] = CreatePlayerTextDraw(playerid, (playerid, poker_icon_float[position][0] + 8.0), (playerid, poker_icon_float[position][1] + 3.5), "D");
	PlayerTextDrawLetterSize(playerid, PokerDI_PTD[playerid][1], 0.223835, 1.089998);
	PlayerTextDrawAlignment(playerid, PokerDI_PTD[playerid][1], 2);
	PlayerTextDrawColor(playerid, PokerDI_PTD[playerid][1], 255);
	PlayerTextDrawSetShadow(playerid, PokerDI_PTD[playerid][1], 0);
	PlayerTextDrawBackgroundColor(playerid, PokerDI_PTD[playerid][1], 255);
	PlayerTextDrawFont(playerid, PokerDI_PTD[playerid][1], 2);
	PlayerTextDrawSetProportional(playerid, PokerDI_PTD[playerid][1], 1);
	PlayerTextDrawShow(playerid, PokerDI_PTD[playerid][1]);

	PI[playerid][pPokerDealerIcon] = 1;
}
poker_UpdateOptions(playerid, option) {
	switch (option) {
		case POKER_OPTION_NONE: {
			TextDrawHideForPlayer(playerid, Poker_TD[4]), PlayerTextDrawHide(playerid, Poker_PTD[playerid][35]);
			TextDrawHideForPlayer(playerid, Poker_TD[5]), PlayerTextDrawHide(playerid, Poker_PTD[playerid][36]);
			TextDrawHideForPlayer(playerid, Poker_TD[6]), PlayerTextDrawHide(playerid, Poker_PTD[playerid][37]);

			PI[playerid][pPokerTutorialKey] = 0;
		}
		case POKER_OPTION_RCF: {
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][35], "RAISE");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][36], "CHECK");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][37], "FOLD");

			TextDrawShowForPlayer(playerid, Poker_TD[4]), PlayerTextDrawShow(playerid, Poker_PTD[playerid][35]);
			TextDrawShowForPlayer(playerid, Poker_TD[5]), PlayerTextDrawShow(playerid, Poker_PTD[playerid][36]);
			TextDrawShowForPlayer(playerid, Poker_TD[6]), PlayerTextDrawShow(playerid, Poker_PTD[playerid][37]);
		}
		case POKER_OPTION_CRF: {
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][35], "CALL");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][36], "RAISE");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][37], "FOLD");

			TextDrawShowForPlayer(playerid, Poker_TD[4]), PlayerTextDrawShow(playerid, Poker_PTD[playerid][35]);
			TextDrawShowForPlayer(playerid, Poker_TD[5]), PlayerTextDrawShow(playerid, Poker_PTD[playerid][36]);
			TextDrawShowForPlayer(playerid, Poker_TD[6]), PlayerTextDrawShow(playerid, Poker_PTD[playerid][37]);
		}
		case POKER_OPTION_CF: {
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][35], "CHECK");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][36], "FOLD");

			TextDrawShowForPlayer(playerid, Poker_TD[4]), PlayerTextDrawShow(playerid, Poker_PTD[playerid][35]);
			TextDrawShowForPlayer(playerid, Poker_TD[5]), PlayerTextDrawShow(playerid, Poker_PTD[playerid][36]);
		}
		default: return true;
	}
	return (PI[playerid][pPokerOptions] = option);
}
poker_JoinGame(playerid, tableid) {
/*	if (Server::Settings[Server::POKER] == 0) 
		return SCM(playerid, COLOR_GREY, "pokeri mocemul droshi miuwvdomelia.");*/
	if ((GetTickCount() - GetPVarInt(playerid,"poker_JoinGameTick")) < 1200)
		return false;
	SetPVarInt(playerid,"poker_JoinGameTick",GetTickCount());

	if (pokerTableInfo[tableid][pokerTablePlayers] >= pokerTableInfo[tableid][pokerTableLimit]) 
		return ErrorMessage(playerid, "Ar aris tavisufali adgilebi."), false;
	/* if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_PRE_STARTING) 
		return ErrorMessage(playerid, "gtxovt daelodet.."), false; */
	if (PI[playerid][pCasinoChips] < pokerTableInfo[tableid][pokerTableMinBet]) 
		return SendFormattedMessage(playerid, COLOR_ERROR, ""NO"*"G" Tqven ar gaqvt sakamarisi fishkebi, satamashot sachiroa %d.", pokerTableInfo[tableid][pokerTableMinBet]);
 /*
	if (pokerTableInfo[tableid][pokerTableEnterPrice] && GetPlayerMoneyEx(playerid) < pokerTableInfo[tableid][pokerTableEnterPrice]) 
		return SendFormattedMessage(playerid, COLOR_ERROR, "Tqven ar gaqvt sakmarisi tanxa, satamashot sachiroa $%d.", pokerTableInfo[tableid][pokerTableEnterPrice]);
*/
	for (new targetid = 0, Float:object_angle = 0.0; targetid < MAX_POKER_SEATS; targetid++) if (pokerTableInfo[tableid][pokerTableSlots][targetid] == INVALID_PLAYER_ID) {
		PI[playerid][pPokerLanguage] = PI[playerid][pCasinoLanguage];

		//GiveMoney(playerid, -pokerTableInfo[tableid][pokerTableEnterPrice], 0);

	    poker_CreatePTD(playerid, targetid);
		poker_ShowGUI(playerid);
	    
		poker_UpdateOptions(playerid, POKER_OPTION_NONE);

		PI[playerid][pPokerRaisedTime] = 0;
		PI[playerid][pPokerRaised] = 0;
		PI[playerid][pPokerTableID] = (tableid + 1);
		PI[playerid][pPokerSeatID] = targetid;
		PI[playerid][pPokerTutorialStep] = 0;

		pokerTableInfo[tableid][pokerTablePlayers]++;
		pokerTableInfo[tableid][pokerTableSlots][targetid] = playerid;

		if (pokerTableInfo[tableid][pokerTablePlayers] == 1 && pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_NONE) {
			format(pokerTableInfo[tableid][pokerChatBuffer], (64 * 10), "_~n~_~n~_~n~_~n~_~n~_~n~_~n~_~n~_~n~_");
			pokerTableInfo[tableid][pokerTableStatus] = POKER_STATUS_PRE_STARTING;
		}
		// poker_ShowMenu(playerid, PM_MENU_BET);

		pokerTableInfo[tableid][pokerTablePlayersActive]++;

		PI[playerid][pPokerChips] = PI[playerid][pCasinoChips];
		PI[playerid][pCasinoChips] = 0;
		//SetPlayerInt(GetName(playerid), "casino_chips", PI[playerid][pPokerChips]);

		format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "%s shemouertda pokers #%d, fishkebi %d",
			GetName(playerid), PI[playerid][pPokerTableID], PI[playerid][pPokerChips]
		);
		printf(STRING_GLOBAL), /*WriteLog("logs_casino", STRING_GLOBAL), */STRING_GLOBAL[0] = EOS;

		if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_STARTING && pokerTableInfo[tableid][pokerTableRound] == 0 && pokerTableInfo[tableid][pokerTableDelay] >= 6) 
			PI[playerid][pPokerStatus] = 1;
		if (pokerTableInfo[tableid][pokerTableStatus] < POKER_STATUS_STARTING) 
			PI[playerid][pPokerStatus] = 1;
		if (pokerTableInfo[tableid][pokerTableStatus] == POKER_STATUS_PRE_STARTING) {
			pokerTableInfo[tableid][pokerTableStatus] = POKER_STATUS_WAITING;
			pokerTableInfo[tableid][pokerTableTimer] = 1;
		}
		// pokerTableInfo[tableid][pokerTableTimer] = 1;

		SelectTextDraw(playerid, 0x191919FF);
		
		poker_update_chat(tableid);

		//

		Streamer_ToggleItem(playerid, STREAMER_TYPE_3D_TEXT_LABEL, pokerTableInfo[tableid][pokerTableTextID], false);
		Streamer_Update(playerid, STREAMER_TYPE_3D_TEXT_LABEL);
		
		GetDynamicObjectRot(pokerTableInfo[tableid][pokerTableObjectID], object_angle, object_angle, object_angle);
		CameraRadiusSetPos(playerid, pokerTableInfo[tableid][pokerTablePos][0], pokerTableInfo[tableid][pokerTablePos][1], pokerTableInfo[tableid][pokerTablePos][2], (object_angle + 90.000000), 4.2, 0.1);

		GetPlayerPos(playerid, PI[playerid][pPokerPos][0], PI[playerid][pPokerPos][1], PI[playerid][pPokerPos][2]);
        SetPlayerInterior(playerid, pokerTableInfo[tableid][pokerTableInterior]);
		SetPlayerVirtualWorld(playerid, pokerTableInfo[tableid][pokerTableWorld]);

		ApplyAnimation(playerid, "CASINO", "cards_out", 4.1, 0, 1, 1, 1, 1, 1);
		TogglePlayerControllable(playerid, false);

		SetPlayerPosObjectOffset(pokerTableInfo[tableid][pokerTableObjectID], playerid, pokerTableInfoOffsets[targetid][0], pokerTableInfoOffsets[targetid][1], pokerTableInfoOffsets[targetid][2]);
		SetPlayerFacingAngle(playerid, (pokerTableInfoOffsets[targetid][3] + 90.0 + object_angle));

		break;
	}
	return true;
}
poker_LeaveGame(playerid) {
	if (!PI[playerid][pPokerTableID]) return false;
	SetPVarInt(playerid,"poker_JoinGameTick",GetTickCount());

	new tableid = (PI[playerid][pPokerTableID] - 1);

	PlayerPlaySound(playerid, 5852, 0.0, 0.0, 0.0);
	if (PI[playerid][pPokerChips] < 0) PI[playerid][pPokerChips] = 0;
	PI[playerid][pCasinoChips] = PI[playerid][pPokerChips];
	PI[playerid][pPokerChips] = 0;
	//SetPlayerInt(GetName(playerid), "casino_chips", PI[playerid][pCasinoChips]);

	format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "%s gavida pokeridan #%d da waigo fishkebi = %d",
		GetName(playerid), PI[playerid][pPokerTableID], PI[playerid][pCasinoChips]
	);
	printf(STRING_GLOBAL), /*WriteLog("logs_casino", STRING_GLOBAL), */STRING_GLOBAL[0] = EOS;

	if ((tableid + 1)) {
		pokerTableInfo[tableid][pokerTablePlayers]--;
		if (PI[playerid][pPokerStatus]) 
			pokerTableInfo[tableid][pokerTablePlayersActive]--;
		new poker_seatid = PI[playerid][pPokerSeatID]; 
		pokerTableInfo[tableid][pokerTableSlots][poker_seatid] = INVALID_PLAYER_ID;

		if (!pokerTableInfo[tableid][pokerTableRound] && pokerTableInfo[tableid][pokerTableDelay] < 5)
			poker_ResetRound(tableid);

		Streamer_ToggleItem(playerid, STREAMER_TYPE_3D_TEXT_LABEL, pokerTableInfo[tableid][pokerTableTextID], true);
		Streamer_Update(playerid, STREAMER_TYPE_3D_TEXT_LABEL);

		SetPlayerInterior(playerid, pokerTableInfo[tableid][pokerTableInterior]);
		SetPlayerVirtualWorld(playerid, pokerTableInfo[tableid][pokerTableWorld]);

		if (PI[playerid][pPokerActiveHand])
			pokerTableInfo[tableid][pokerTableHandsActive]--;
		if (PI[playerid][pPokerActiveID])
			poker_NextTurn(tableid);
		if (!pokerTableInfo[tableid][pokerTablePlayers])
			poker_ResetTable(tableid);
	}
	SetPlayerPos(playerid, PI[playerid][pPokerPos][0], PI[playerid][pPokerPos][1], PI[playerid][pPokerPos][2] + 0.1);
	Dialog_Close(playerid);

	PI[playerid][pPokerTableID] = 
	PI[playerid][pPokerSeatID] = 
	PI[playerid][pPokerWinner] = 
	PI[playerid][pPokerBet] = 
	PI[playerid][pPokerChips] = 
	PI[playerid][pPokerStatus] = 
	PI[playerid][pPokerDealer] = 
	PI[playerid][pPokerCard][0] = 
	PI[playerid][pPokerCard][1] = 
	PI[playerid][pPokerActiveID] = 
	PI[playerid][pPokerActiveHand] = 
	PI[playerid][pPokerHide] = 0;

	PI[playerid][pPokerStatus_STR] = '\0';

	PI[playerid][pPokerPos][0] = 
	PI[playerid][pPokerPos][1] = 
	PI[playerid][pPokerPos][2] = 0.0;

	poker_DestroyGUI(playerid);

	TogglePlayerControllable(playerid, true);
	SetCameraBehindPlayer(playerid);
	CancelSelectTextDraw(playerid);

	ClearAnimations(playerid);
	ApplyAnimation(playerid, "CARRY", "crry_prtial", 1.0, 0, 0, 0, 0, 0);

	return true;
}
poker_ShowMenu(playerid, menuid) {
	new tableid = (PI[playerid][pPokerTableID] - 1);
	switch (menuid) {
		case PM_MENU_CALL: {
		    PI[playerid][pPokerActionActive] = 1;

			if (PI[playerid][pPokerChips] <= 0) {
				PlayerPlaySound(playerid, 5823, 0.0, 0.0, 0.0);
				return ErrorMessage(playerid, "Tqven ar gaqvt sakamarisi fishkebi.");
			}
			new poker_actual_bet = (pokerTableInfo[tableid][pokerTableBet] - PI[playerid][pPokerBet]);

			if (poker_actual_bet > PI[playerid][pPokerChips]) {
				format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "{FFFFFF}Gusrt gaatolot {d8284c}%d 'mde{FFFFFF}?", poker_actual_bet);
				return ShowPlayerDialog(playerid, DIALOG_POKER_CALL, DIALOG_STYLE_MSGBOX, "{d8284c}Fsonis gatoleba", STRING_GLOBAL, "Bank", "ukan"), STRING_GLOBAL[0] = EOS;
			}
			format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "{FFFFFF}Gusrt gaatolot {d8284c}%d 'mde{FFFFFF}?", poker_actual_bet);
			ShowPlayerDialog(playerid, DIALOG_POKER_CALL, DIALOG_STYLE_MSGBOX, "{d8284c}Fsonis gatoleba", STRING_GLOBAL, "Ki", "ukan"), STRING_GLOBAL[0] = EOS;
		}
		case PM_MENU_RAISE: {
			
			if (
				pokerTableInfo[tableid][pokerTableLastRaiseID] == playerid && 
				PI[playerid][pPokerRaised] == pokerTableInfo[tableid][pokerTableCardsActive] &&
				PI[playerid][pPokerRaisedTime] >= 2
			) return ErrorMessage(playerid, "Tqven ver gazrdit fsonis metjer.");
			
			PI[playerid][pPokerActionActive] = 1;

			if (PI[playerid][pPokerBet] + PI[playerid][pPokerChips] > pokerTableInfo[tableid][pokerTableBet] + pokerTableInfo[tableid][pokerTableBlind] / 2)  {
				format(STRING_GLOBAL, sizeof(STRING_GLOBAL), 
					"{FFFFFF}Sheiyvanet tanxa gasazardad {d8284c}(%d - %d){FFFFFF}:",
					(pokerTableInfo[tableid][pokerTableBet] + pokerTableInfo[tableid][pokerTableBlind] / 2), (PI[playerid][pPokerBet] + PI[playerid][pPokerChips])
				);
				return ShowPlayerDialog(playerid, DIALOG_POKER_RAISE, DIALOG_STYLE_INPUT, "{d8284c}Повысить ставку", STRING_GLOBAL, "Migeba", "ukan"), STRING_GLOBAL[0] = EOS;
			}
			else if (PI[playerid][pPokerBet] + PI[playerid][pPokerChips] == pokerTableInfo[tableid][pokerTableBet] + pokerTableInfo[tableid][pokerTableBlind] / 2)  {
				format(STRING_GLOBAL, sizeof(STRING_GLOBAL), 
					"{FFFFFF}Sheiyvanet tanxa gasazardad {d8284c}(%d){FFFFFF}:",
					(pokerTableInfo[tableid][pokerTableBet] + pokerTableInfo[tableid][pokerTableBlind] / 2)
				);
				return ShowPlayerDialog(playerid, DIALOG_POKER_RAISE, DIALOG_STYLE_INPUT, "{d8284c}Fsonis gazrda", STRING_GLOBAL, "bank", "Ukan"), STRING_GLOBAL[0] = EOS;
			}

			ErrorMessage(playerid, "У вас недостаточно fishkebi.");
			PlayerPlaySound(playerid, 5823, 0.0, 0.0, 0.0);
		}
		/*case PM_MENU_BET: {
			ShowPlayerDialog(playerid, DIALOG_POKER_BET, DIALOG_STYLE_INPUT, "{d8284c}Texas Holdem Poker", "{FFFFFF}sheiyvanet fsonis raodenoba {d8284c}(%d - %d){FFFFFF}:\n\ntqven gaqvt: {d8284c}%d fishkebi", "Migeba", "Gamosvla", pokerTableInfo[tableid][pokerTableMinBet], pokerTableInfo[tableid][pokerTableMaxBet], PI[playerid][pCasinoChips]);
		}*/
	}
	return true;
}
stock poker_StartTutorial(playerid) {
	new tableid = 0, Float:object_angle = 0.0;

	PI[playerid][pPokerLanguage] = CASINO_LANGUAGE_RUSSIAN;

	SetPVarInt(playerid, "casinoTempWorldID", GetPlayerVirtualWorld(playerid));

    poker_CreatePTD(playerid, 0);
	poker_ShowGUI(playerid);

	for (new td_id = 0; td_id < sizeof(PokerTutorial_TD); td_id++)
		TextDrawShowForPlayer(playerid, PokerTutorial_TD[td_id]);
	PlayerTextDrawShow(playerid, PokerTutorial_PTD[playerid]);

	PI[playerid][pPokerTableID] = (tableid + 1);
	PI[playerid][pPokerSeatID] = 0;
	PI[playerid][pPokerTutorialStep] = 0;
	Streamer_ToggleItem(playerid, STREAMER_TYPE_3D_TEXT_LABEL, pokerTableInfo[tableid][pokerTableTextID], false);
	Streamer_Update(playerid, STREAMER_TYPE_3D_TEXT_LABEL);
	
	GetDynamicObjectRot(pokerTableInfo[tableid][pokerTableObjectID], object_angle, object_angle, object_angle);
	CameraRadiusSetPos(playerid, pokerTableInfo[tableid][pokerTablePos][0], pokerTableInfo[tableid][pokerTablePos][1], pokerTableInfo[tableid][pokerTablePos][2], (object_angle + 90.000000), 4.2, 0.1);

	GetPlayerPos(playerid, PI[playerid][pPokerPos][0], PI[playerid][pPokerPos][1], PI[playerid][pPokerPos][2]);
    SetPlayerInterior(playerid, pokerTableInfo[tableid][pokerTableInterior]);
	SetPlayerVirtualWorld(playerid, pokerTableInfo[tableid][pokerTableWorld]);

	ApplyAnimation(playerid, "CASINO", "cards_out", 4.1, 0, 1, 1, 1, 1, 1);
	TogglePlayerControllable(playerid, false);

	SetPlayerPosObjectOffset(pokerTableInfo[0][pokerTableObjectID], playerid, pokerTableInfoOffsets[0][0], pokerTableInfoOffsets[0][1], pokerTableInfoOffsets[0][2]);
	SetPlayerFacingAngle(playerid, (pokerTableInfoOffsets[0][3] + 90.0 + object_angle));
	
	SelectTextDraw(playerid, 0x191919FF);
	poker_TutorialNextStep(playerid);
	return true;
}

stock poker_TutorialNextStep(playerid, step = 1, from_next_key = 1) {
	if (!step) step = 1;

	new
		slots_id[3] = {0/* (вы) */, 3/* (Maurice) */, 4/* (John) */},
		poker_td_array[MAX_POKER_SEATS] = {0, 4, 8, 12, 16, 20}
	;
	switch (step) {
		case 1: {
			poker_UpdateOptions(playerid, POKER_OPTION_NONE);

			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("~w~Tamasshi monawileobas ~y~2 - 6 motamashe~w~.~n~\
				yovelma unda aagrovos ~y~5 kartis kombinacia~w~.~n~\
				Vinc aagrovebs met kombinacias, ~g~gaimarjvebs.")
			);
			poker_HideHandRanking(playerid);
		}
		case 2: {
			poker_ShowHandRanking(playerid, 1);

			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("~w~merjvniv tqevn xedavt ~y~10 ~w~shesadzlebel kombinacias ~y~(HAND RANKING),~n~\
				~w~ganyofilia simaglis mixedvit dablidan - qvebot (dabla dabali kombinaciaa).")
			);
		}
		case 3: {
			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("Gadavidet tamashze.")
			);
			for (new targetid = 0; targetid < sizeof(slots_id); targetid++) 
				PlayerTextDrawHide(playerid, Poker_PTD[playerid][poker_td_array[slots_id[targetid]] + 0]);
			PlayerTextDrawHide(playerid, Poker_PTD[playerid][29]);
		}
		case 4: {
			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("~w~Tqveni adgilia ~g~~h~(ВЫ) ~w~aris magidis qvemota nawilshi, da~n~\
				tqve gaqvt ~p~1000 fishkebi.~n~\
				~w~tqveni miwinaagmdegeebi ~g~Maurice & John ~w~arian magidis maglita mxares.")
			);
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[1]] + 0], "Maurice~n~Tutorial~n~~p~1000");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[2]] + 0], "John~n~Tutorial~n~~p~1000");

			new player_Name[MAX_PLAYER_NAME + 24];
			format(player_Name, sizeof(player_Name), "%s", GetName(playerid)), strreplace(player_Name, "_", "~n~~g~~h~");
			format(player_Name, sizeof(player_Name), "~g~~h~%s~n~~p~1000", player_Name);
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[0]] + 0], player_Name), player_Name[0] = 0;

			for (new targetid = 0; targetid < sizeof(slots_id); targetid++) 
				PlayerTextDrawShow(playerid, Poker_PTD[playerid][poker_td_array[slots_id[targetid]] + 0]);
			PlayerTextDrawShow(playerid, Poker_PTD[playerid][29]);
		}
		case 5: {
			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("jer ori motamashe, romelic dgas dieris ukan, aketeben~n~\
				savaldebulo fsonebs - ~y~mcire da didi blind'i~w~.")
			);
			for (new targetid = 0; targetid < sizeof(slots_id); targetid++) {
				PlayerTextDrawHide(playerid, Poker_PTD[playerid][poker_td_array[slots_id[targetid]] + 2]);
				PlayerTextDrawHide(playerid, Poker_PTD[playerid][poker_td_array[slots_id[targetid]] + 3]);
			}
		}
		case 6: {
			for (new targetid = 1; targetid < sizeof(slots_id); targetid++) {
				PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[targetid]] + 2], "LD_CARD:cdback");
				PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[targetid]] + 3], "LD_CARD:cdback");
				PlayerTextDrawShow(playerid, Poker_PTD[playerid][poker_td_array[slots_id[targetid]] + 2]);
				PlayerTextDrawShow(playerid, Poker_PTD[playerid][poker_td_array[slots_id[targetid]] + 3]);
			}
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[0]] + 2], "LD_CARD:cd11c"); // Валет-крести
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[0]] + 3], "LD_CARD:cd13c"); // Король-крести
			PlayerTextDrawShow(playerid, Poker_PTD[playerid][poker_td_array[slots_id[0]] + 2]);
			PlayerTextDrawShow(playerid, Poker_PTD[playerid][poker_td_array[slots_id[0]] + 3]);

			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("Затем всем игрокам раздается по ~y~2 карты~w~.")
			);
		}
		case 7: {
			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("Tqven shegxvdat kai karti ~g~(erti mastis kako da valeti)~w~.~n~\
				sheidzleba fsonis gaketeba.")
			);
			poker_UpdateOptions(playerid, POKER_OPTION_NONE);
		}
		case 8: {
			PI[playerid][pPokerTutorialKey] = POKER_KEY_CALL;
			poker_UpdateOptions(playerid, POKER_OPTION_CRF);

			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("Magalitad, modit gavutolot momdevno motamashis fsons ~y~(CALL)~w~.")
			);
			for (new targetid = 0; targetid < sizeof(slots_id); targetid++) {
				PlayerTextDrawHide(playerid, Poker_PTD[playerid][poker_td_array[slots_id[targetid]] + 1]);
			}
		}
		case 9: {
			if (from_next_key) return;

			poker_UpdateOptions(playerid, POKER_OPTION_NONE);

			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[0]] + 1], "_~n~~y~CALLED");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[1]] + 1], "_~n~~y~CALLED");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[2]] + 1], "_~n~~y~CHECK");
			for (new targetid = 0; targetid < sizeof(slots_id); targetid++) 
				PlayerTextDrawShow(playerid, Poker_PTD[playerid][poker_td_array[slots_id[targetid]] + 1]);
			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("~g~tqvenma oponentebma ~w~ gaatoles fsonebi ~y~(CALLED)~w~.")
			);
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][30], "LD_CARD:cdback");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][31], "LD_CARD:cdback");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][32], "LD_CARD:cdback");

		}
		case 10: {
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][30], "LD_CARD:cd12d");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][31], "LD_CARD:cd9c");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][32], "LD_CARD:cd2c");

			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("fsonebis 1 wris shemdeg rigdeba ~y~3 karti (ELOP)~w~.")
			);
		}
		case 11: {
			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("Tqven gaqvt vaketebis wyvili da shansi aagrovot fleshi ~y~(FLUSH)~w~.~n~\
				Es kai kombinaciaa, sachiroa tamasshi darchena.")
			);
			poker_UpdateOptions(playerid, POKER_OPTION_NONE);
		}
		case 12: {
			PI[playerid][pPokerTutorialKey] = POKER_KEY_CHECK;
			poker_UpdateOptions(playerid, POKER_OPTION_RCF);

			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("Vetanxmebit shemdegi kartis naxvas. cheki ~y~(CHECK)")
			);
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][33], "LD_CARD:cdback");
			PlayerTextDrawColor(playerid, Poker_PTD[playerid][33], -1523963137), PlayerTextDrawShow(playerid, Poker_PTD[playerid][33]);
		}
		case 13: { 
			if (from_next_key) return;

			poker_UpdateOptions(playerid, POKER_OPTION_NONE);
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[0]] + 1], "_~n~~y~CHECK");

			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][33], "LD_CARD:cd12s");
			PlayerTextDrawColor(playerid, Poker_PTD[playerid][33], -1), PlayerTextDrawShow(playerid, Poker_PTD[playerid][33]);

			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("Rigdeba kidev erti ~y~karti (earn)~w~.")
			);
		}
		case 14: {
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[1]] + 1], "_~n~~y~RAISED");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[2]] + 1], "_~n~~y~FOLD");

			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("~g~Maurice ~w~gazarda fsoni ~y~(RAISED)~w~, а ~g~John ~w~chamoyara kartebi ~y~(FOLD)~w~."));
		}
		case 15: {
			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("~w~shesadzloa, У ~g~Maurice ~w~xelshi ~y~damebis wyvili~w~, romelic sheidzleba~n~\
				chvenze magali ikos.")
			);
		}
		case 16: {
			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("~g~Maurice ~w~gaaketa patara fsoni. sheidzleba gautolot da~n~\
				naxot shemdegi karti.")
			);
			poker_UpdateOptions(playerid, POKER_OPTION_NONE);
		}
		case 17: {
			PI[playerid][pPokerTutorialKey] = POKER_KEY_CALL;

			poker_UpdateOptions(playerid, POKER_OPTION_CRF);
			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("amisatvis daachiret - gatoleba ~y~(CALL)~w~.")
			);
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][34], "LD_CARD:cdback");
			PlayerTextDrawColor(playerid, Poker_PTD[playerid][34], -1523963137), PlayerTextDrawShow(playerid, Poker_PTD[playerid][34]);
		}
		case 18: {
			if (from_next_key) return;

			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[0]] + 1], "_~n~~y~CALLED");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][34], "LD_CARD:cd5c");
			PlayerTextDrawColor(playerid, Poker_PTD[playerid][34], -1), PlayerTextDrawShow(playerid, Poker_PTD[playerid][34]);
			
			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("rigdeba ~y~mexute karti (OVER)~w~."));
			poker_UpdateOptions(playerid, POKER_OPTION_NONE);
		}
		case 19: {
			PI[playerid][pPokerTutorialKey] = POKER_KEY_RAISE;
			poker_UpdateOptions(playerid, POKER_OPTION_RCF);

			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("Amisatvis gavzrdit fsons ~y~(RAISE)~w~."));
		}
		case 20: {
			if (from_next_key) return;

			poker_UpdateOptions(playerid, POKER_OPTION_NONE);

			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[0]] + 1], "_~n~~y~RAISED");
			PlayerTextDrawSetString(playerid, Poker_PTD[playerid][poker_td_array[slots_id[1]] + 1], "_~n~~y~CALLED");

			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("~g~Maurice ~w~gaatola tqveni fsoni ~y~(CALLED)~w~."));
		}
		case 21: {
			PlayerTextDrawSetString(playerid, PokerTutorial_PTD[playerid], 
				TranslateText("~w~esec ase, yvela karti ghiaa da ~g~tqven - Gaimarjvet!~n~ ~n~\
				~p~Gilocavt!")
			);
		}
		case 22: poker_StopTutorial(playerid);
	}
	PI[playerid][pPokerTutorialStep] = step;
}
stock poker_StopTutorial(playerid) {
	PlayerPlaySound(playerid, 5852, 0.0, 0.0, 0.0);

	SetPlayerInterior(playerid, pokerTableInfo[1][pokerTableInterior]);
	SetPlayerVirtualWorld(playerid, GetPVarInt(playerid, "casinoTempWorldID")/*pokerTableInfo[1][pokerTableWorld]*/);
	SetPlayerPos(playerid, PI[playerid][pPokerPos][0], PI[playerid][pPokerPos][1], PI[playerid][pPokerPos][2] + 0.1);
	Dialog_Close(playerid);

	PI[playerid][pPokerTutorialStep] = 
	PI[playerid][pPokerTutorialKey] = 
	PI[playerid][pPokerTableID] = 
	PI[playerid][pPokerSeatID] = 
	PI[playerid][pPokerWinner] = 
	PI[playerid][pPokerBet] = 
	PI[playerid][pPokerChips] = 
	PI[playerid][pPokerStatus] = 
	PI[playerid][pPokerDealer] = 
	PI[playerid][pPokerCard][0] = 
	PI[playerid][pPokerCard][1] = 
	PI[playerid][pPokerActiveID] = 
	PI[playerid][pPokerActiveHand] = 
	PI[playerid][pPokerHide] = 0;

	PI[playerid][pPokerPos][0] = 
	PI[playerid][pPokerPos][1] = 
	PI[playerid][pPokerPos][2] = 0.0;

	poker_DestroyGUI(playerid);

	TogglePlayerControllable(playerid, true);
	SetCameraBehindPlayer(playerid);
	CancelSelectTextDraw(playerid);
	ClearAnimations(playerid);
}
stock CreateAttachDynamicObject(objectid, model, Float:off_x, Float:off_y, Float:off_z, Float:off_rx, Float:off_ry, Float:off_rz, worldid = -1, interiorid = -1, playerid = -1) {
	new object_id = INVALID_DYNAMIC_OBJECT_ID;

	if (!IsValidDynamicObject(objectid))
		return objectid;
	new Float:sin[3], Float:cos[3], Float:object_pos[6];
	GetDynamicObjectPos(objectid, object_pos[0], object_pos[1], object_pos[2]);
	GetDynamicObjectRot(objectid, object_pos[3], object_pos[4], object_pos[5]);

	AOP_FloatEulerFix(object_pos[3], object_pos[4], object_pos[5]);

	cos[0] = floatcos(object_pos[3], degrees); cos[1] = floatcos(object_pos[4], degrees); cos[2] = floatcos(object_pos[5], degrees); sin[0] = floatsin(object_pos[3], degrees); sin[1] = floatsin(object_pos[4], degrees); sin[2] = floatsin(object_pos[5], degrees);
	object_pos[0] = object_pos[0] + off_x * cos[1] * cos[2] - off_x * sin[0] * sin[1] * sin[2] - off_y * cos[0] * sin[2] + off_z * sin[1] * cos[2] + off_z * sin[0] * cos[1] * sin[2];
	object_pos[1] = object_pos[1] + off_x * cos[1] * sin[2] + off_x * sin[0] * sin[1] * cos[2] + off_y * cos[0] * cos[2] + off_z * sin[1] * sin[2] - off_z * sin[0] * cos[1] * cos[2];
	object_pos[2] = object_pos[2] - off_x * cos[0] * sin[1] + off_y * sin[0] + off_z * cos[0] * cos[1];
	object_pos[3] = asin(cos[0] * cos[1]); object_pos[4] = atan2(sin[0], cos[0] * sin[1]) + off_rz; object_pos[5] = atan2(cos[1] * cos[2] * sin[0] - sin[1] * sin[2], cos[2] * sin[1] - cos[1] * sin[0] * -sin[2]);
	cos[0] = floatcos(object_pos[3], degrees); cos[1] = floatcos(object_pos[4], degrees); cos[2] = floatcos(object_pos[5], degrees); sin[0] = floatsin(object_pos[3], degrees); sin[1] = floatsin(object_pos[4], degrees); sin[2] = floatsin(object_pos[5], degrees);
	object_pos[3] = asin(cos[0] * sin[1]); object_pos[4] = atan2(cos[0] * cos[1], sin[0]); object_pos[5] = atan2(cos[2] * sin[0] * sin[1] - cos[1] * sin[2], cos[1] * cos[2] + sin[0] * sin[1] * sin[2]);
	cos[0] = floatcos(object_pos[3], degrees); cos[1] = floatcos(object_pos[4], degrees); cos[2] = floatcos(object_pos[5], degrees); sin[0] = floatsin(object_pos[3], degrees); sin[1] = floatsin(object_pos[4], degrees); sin[2] = floatsin(object_pos[5], degrees);
	object_pos[3] = atan2(sin[0], cos[0] * cos[1]) + off_rx; object_pos[4] = asin(cos[0] * sin[1]); object_pos[5] = atan2(cos[2] * sin[0] * sin[1] + cos[1] * sin[2], cos[1] * cos[2] - sin[0] * sin[1] * sin[2]);
	cos[0] = floatcos(object_pos[3], degrees); cos[1] = floatcos(object_pos[4], degrees); cos[2] = floatcos(object_pos[5], degrees); sin[0] = floatsin(object_pos[3], degrees); sin[1] = floatsin(object_pos[4], degrees); sin[2] = floatsin(object_pos[5], degrees);
	object_pos[3] = asin(cos[1] * sin[0]); object_pos[4] = atan2(sin[1], cos[0] * cos[1]) + off_ry; object_pos[5] = atan2(cos[0] * sin[2] - cos[2] * sin[0] * sin[1], cos[0] * cos[2] + sin[0] * sin[1] * sin[2]);

	object_id = CreateDynamicObject(model,
		object_pos[0], object_pos[1], object_pos[2], 
		object_pos[3], object_pos[4], object_pos[5],
		worldid, interiorid, playerid
	);
	return object_id;
}