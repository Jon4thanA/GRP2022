#if defined _blackjack_included
	#endinput
#endif
#define _blackjack_included

#define MAX_BLACKJACK_PLAYER_CARD		5
#define MAX_BLACKJACK_TABLES			10

#define MAX_BLACKJACK_SEATS				3

#define BLACKJACK_DEFAULT_MIN_BET		1
#define BLACKJACK_DEFAULT_MAX_BET		200

#define BLACKJACK_DEFAULT_SEAT_PRICE	10

enum BLACKJACK_E {
	pBlackJackTableID,
	pBlackJackSeatID,
	pBlackJackActiveID,
	Float:pBlackJackPos[3],
	pBlackJackCard[MAX_BLACKJACK_PLAYER_CARD * 2/* (+ split*2) */],
	pBlackJackCards[2],
	pBlackJackCardsScore[2],
	pBlackJackBet[2],
	pBlackJackLastBet,
	pBlackJackBlockID,
	pBlackJackStatus[2],
	pBlackJackDelay,
	pBlackJackActiveHand,
	pBlackJackOptions,
	pBlackJackGUI,
	pBlackJackSplit,
	pBlackJackLanguage,
	pBlackJackTutorialStep,
	pBlackJackTutorialKey
};
new BJ_PlayerInfo[MAX_PLAYERS][BLACKJACK_E], NULL_BJ_PI[BLACKJACK_E];

static 
	Text:Blackjack_Tutorial_TD[4], PlayerText:Blackjack_Tutorial_PTD[MAX_PLAYERS], 
	Text:Blackjack_TD[6], PlayerText:Blackjack_PTD[MAX_PLAYERS][58];

static const Float:blackjack_TableOffsets[MAX_BLACKJACK_SEATS + 1/*(dealer pos)*/][4] = {
	{-0.0418, -1.6296, 0.0602, 355.5609}, // 1
	{-1.3105, -1.1824, 0.0602, 315.0}, // 2
	{1.3448, -1.1447, 0.0602, 45.0}, // 3
	{0.0311, 0.3729, 0.0602, 175.7082} // dealer
};
enum {
	BLACKJACK_KEY_SPLIT = 1,
	BLACKJACK_KEY_HIT,
	BLACKJACK_KEY_STAY
};
enum {
	BJ_PLAYER_STATUS_NONE,
	BJ_PLAYER_STATUS_DOUBLE,
	BJ_PLAYER_STATUS_SPLIT,
	BJ_PLAYER_STATUS_LOSE,
	BJ_PLAYER_STATUS_WON,
	BJ_PLAYER_STATUS_STAY
};
enum {
	BLACKJACK_STATUS_NONE,
	BLACKJACK_STATUS_STARTING,
	BLACKJACK_STATUS_STARTED,
	BLACKJACK_STATUS_ENDING
};
enum blackjackTableE {
	blackjackTableDealerCard[MAX_BLACKJACK_PLAYER_CARD],
	blackjackTableDealerCards,
	blackjackTableDealerScore,
	blackjackTableDealerDelay,
	blackjackTableDealerHidden,
	blackjackTablePlayerid,
	blackjackTableStatus,
	blackjackTableDelay,
	blackjackTableCardsActive,
	blackjackTableHandsActive,
	blackjackTablePlayersActive,
	blackjackTableObjectID,
	blackjackTableActorID,
	Text3D:blackjackTableTextID,
	blackjackTableAreaID,
	Float:blackjackTablePos[6],
	blackjackTableInterior,
	blackjackTableWorld,
	blackjackTableplayers,
	blackjackTableMinBet,
	blackjackTableMaxBet,
	blackjackTableEnterPrice,
	blackjackTableLimit,
	blackjackTableTimer,
	blackjackTableSlots[MAX_BLACKJACK_SEATS],
	blackjackTableDeck[MAX_CASINO_CARDS]
}
new 
	blackjackTableInfo[MAX_BLACKJACK_TABLES][blackjackTableE], 
	Iterator:blackjackTables<MAX_BLACKJACK_TABLES>;

enum {
	BLACKJACK_OPTION_NONE = 0,
	BLACKJACK_OPTION_MMBA, //	MIN(1)  MAX(300)  BET(1-300)  AGAIN(300)
	BLACKJACK_OPTION_DSHS, //	DOUBLE  SPLIT  HIT  STAY
};
static const blackjack_language_massive[2][7][] = {
	{	/* (00) */"ROUND WILL BEGIN THROUGH",
		/* (01) */"ROUND WILL END THROUGH",
		/* (02) */"~p~MAKE YOUR BETTING!",
		/* (03) */"~w~CURRENT BET:",
		/* (04) */"~p~NEW ROUND STARTED!",
		/* (05) */"~w~YOU",
		/* (06) */"~w~YOUR TURN!"
	},
	{	/* (00) */"RAUNDI IWYEBA", // –¿”Õƒ Õ¿◊Õ≈“—ﬂ ◊≈–≈«
		/* (01) */"RAUND", // –¿”Õƒ «¿ ŒÕ◊»“—ﬂ ◊≈–≈«
		/* (02) */"~p~DADET FSONI!", // ~p~¬ÕŒ—»“≈ ¬¿ÿ» —“¿¬ »!
		/* (03) */"~w~MIMDENARE FSONI:",	// ~w~“≈ ”Ÿ¿ﬂ —“¿¬ ¿
		/* (04) */"~p~AXALI RAUNDI DAIWYO!", // ~p~ÕŒ¬€… –¿”Õƒ Õ¿◊¿À—ﬂ!
		/* (05) */"~w~TQVEN", // ¬€
		/* (06) */"~w~TQVENI SVLA!"	// ¬¿ÿ ’Œƒ!
	}
};
forward blackjack_Timer();
public blackjack_Timer() {
	foreach(new tableid: blackjackTables) {
		if (!blackjackTableInfo[tableid][blackjackTableTimer]) {
			if (blackjackTableInfo[tableid][blackjackTableStatus] != BLACKJACK_STATUS_NONE)
				blackjack_ResetTable(tableid);
			continue;
		}
		blackjack_TimerID(tableid);
	}
	return true;
}
stock blackjack_TimerID(tableid) {
	if (blackjackTableInfo[tableid][blackjackTableplayers] < 1) {
		blackjack_ResetTable(tableid);
		return false;
	}
	switch (blackjackTableInfo[tableid][blackjackTableStatus]) 
	{
		case BLACKJACK_STATUS_NONE: 
		{
			blackjack_ResetRound(tableid);

			blackjackTableInfo[tableid][blackjackTableStatus] = BLACKJACK_STATUS_STARTING;
			blackjackTableInfo[tableid][blackjackTableDelay] = (15);

			for (new i = 0, playerid; i < MAX_BLACKJACK_SEATS; i++) 
			{
				playerid = blackjackTableInfo[tableid][blackjackTableSlots][i];
				if ((playerid) != INVALID_PLAYER_ID) 
				{
					blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_MMBA);
				}
			}
		}
		case BLACKJACK_STATUS_STARTING: 
		{
			if (blackjackTableInfo[tableid][blackjackTableDelay]) 
			{
				blackjackTableInfo[tableid][blackjackTablePlayerid] = (-1);

				if (--blackjackTableInfo[tableid][blackjackTableDelay] == 0) 
				{
					blackjackTableInfo[tableid][blackjackTableStatus] = BLACKJACK_STATUS_STARTED;
					blackjackTableInfo[tableid][blackjackTablePlayersActive] = 0;

					for (new i = 0, playerid; i < MAX_BLACKJACK_SEATS; i++) 
					{
						playerid = blackjackTableInfo[tableid][blackjackTableSlots][i];
						if (playerid != INVALID_PLAYER_ID) 
						{
							blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_NONE);

							BJ_PlayerInfo[playerid][pBlackJackLanguage] = PI[playerid][pCasinoLanguage];
							Dialog_Close(playerid);

							if (BJ_PlayerInfo[playerid][pBlackJackBet][0]) 
							{
								if (PI[playerid][pCasinoChips] < BJ_PlayerInfo[playerid][pBlackJackBet][0]) 
								{
									BJ_PlayerInfo[playerid][pBlackJackBet][0] = EOS;
									blackjack_LeaveGame(playerid);
									ErrorMessage(playerid, "Tqven ar gaqvt sakmarishi fishkebi.");
								}
								else 
								{
									format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "[BJ]: %s gaaketa fsoni %d fishka (Magida #%d), xeli #1",
										GetName(playerid), BJ_PlayerInfo[playerid][pBlackJackBet][1], tableid + 1
									);
									printf(STRING_GLOBAL), /*WriteLog("logs_casino", STRING_GLOBAL), */STRING_GLOBAL[0] = EOS;

									ApplyAnimation(playerid, "CASINO", "cards_loop", 4.1, 0, 1, 1, 1, 1, 1);
									blackjackTableInfo[tableid][blackjackTablePlayersActive]++;
								}
							}
							else blackjack_LeaveGame(playerid);
						}
					}
					ApplyDynamicActorAnimation(blackjackTableInfo[tableid][blackjackTableActorID], "CASINO", "cards_loop", 4.1, 0, 1, 1, 1, 1);

					blackjack_ShuffleHands(tableid); // shuffle & deal

					if (blackjackTableInfo[tableid][blackjackTablePlayersActive] == 0) 
					{
						if (!blackjackTableInfo[tableid][blackjackTableplayers]) 
						{
							blackjack_ResetTable(tableid);
						}
						else 
						{
							ApplyDynamicActorAnimation(blackjackTableInfo[tableid][blackjackTableActorID], "CASINO", "cards_out", 4.1, 0, 1, 1, 1, 1);
									
							for (new i = 0, playerid; i < MAX_BLACKJACK_SEATS; i++) 
							{
								playerid = blackjackTableInfo[tableid][blackjackTableSlots][i];
								if (playerid != INVALID_PLAYER_ID) 
								{
									blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_NONE);
									Dialog_Close(playerid);

									BJ_PlayerInfo[playerid][pBlackJackDelay] = 
									BJ_PlayerInfo[playerid][pBlackJackActiveID] = 0;
									blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_NONE);
									BJ_PlayerInfo[playerid][pBlackJackStatus][BJ_PlayerInfo[playerid][pBlackJackBlockID]] = BJ_PLAYER_STATUS_STAY;

									PlayerTextDrawHide(playerid, Blackjack_PTD[playerid][54]);
								}
							}

							blackjackTableInfo[tableid][blackjackTableStatus] = BLACKJACK_STATUS_ENDING;
							blackjackTableInfo[tableid][blackjackTableDelay] = (15);
						}
					}
				}
			}
		}
		case BLACKJACK_STATUS_STARTED: 
		{
			if (blackjackTableInfo[tableid][blackjackTablePlayerid] == (-1)) 
			{
				blackjack_NextTurn(tableid);
				blackjack_CheckCards(blackjackTableInfo[tableid][blackjackTablePlayerid]);
			}
		}
		case BLACKJACK_STATUS_ENDING: 
		{
			if (blackjackTableInfo[tableid][blackjackTableDelay]) 
			{
				blackjackTableInfo[tableid][blackjackTablePlayerid] = (-1);

				if (--blackjackTableInfo[tableid][blackjackTableDelay] == 0) 
				{
					blackjack_ResetRound(tableid);

					blackjackTableInfo[tableid][blackjackTableStatus] = BLACKJACK_STATUS_STARTING;
					blackjackTableInfo[tableid][blackjackTableDelay] = (20);

					for (new i = 0, playerid; i < MAX_BLACKJACK_SEATS; i++) 
					{
						playerid = blackjackTableInfo[tableid][blackjackTableSlots][i];
						if (playerid != INVALID_PLAYER_ID) 
						{
							GameTextForPlayer(playerid,"~r~PLACE A BET!", 1500, 1);
							blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_MMBA);
						}
					}
				}
			}
		}
	}
	new
		blackjack_string[128],
		blackjack_td_seats_array[MAX_BLACKJACK_SEATS + 1] = {
			11/* (11-15_s1-1) */, //16/* (16-20_s1-1) */,
			21/* (21-25_s1-1) */, //26/* (26-30_s1-1) */,
			31/* (31-35_s1-1) */, //36/* (36-40_s1-1) */,
			41/* (41-45_dealer) */
		},
		blackjack_td_score_array[MAX_BLACKJACK_SEATS + 1] = {
			46/* (46 - 47) */,
			48/* (48 - 49) */,
			50/* (50 - 51) */,
			52/* (56_dealer) */
		}
	;
	for (new i = 0, playerid; i < MAX_BLACKJACK_SEATS; i++) 
	{
		playerid = blackjackTableInfo[tableid][blackjackTableSlots][i];
		if (playerid != INVALID_PLAYER_ID) 
		{
			new language_id = BJ_PlayerInfo[playerid][pBlackJackLanguage];
			switch (blackjackTableInfo[tableid][blackjackTableStatus]) 
			{
				case BLACKJACK_STATUS_STARTING: 
				{
					if (!BJ_PlayerInfo[playerid][pBlackJackBet][0]) 
					{
						format(blackjack_string, 58, "%s ~r~%d~n~%s",
							blackjack_language_massive[language_id][0], blackjackTableInfo[tableid][blackjackTableDelay],
							blackjack_language_massive[language_id][2]
						);
					}
					else 
					{
						format(blackjack_string, 58, "%s ~r~%d~n~%s ~p~%d",
							blackjack_language_massive[language_id][0], blackjackTableInfo[tableid][blackjackTableDelay],
							blackjack_language_massive[language_id][3], BJ_PlayerInfo[playerid][pBlackJackBet][0]
						);
					}
					PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][53], blackjack_string);
				}
				case BLACKJACK_STATUS_ENDING: 
				{
					format(blackjack_string, 32, "%s ~r~%d", blackjack_language_massive[language_id][1], blackjackTableInfo[tableid][blackjackTableDelay]);
					PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][53], blackjack_string);
				}
				case BLACKJACK_STATUS_STARTED: 
				{
					if (blackjackTableInfo[tableid][blackjackTablePlayerid] == (-1)) 
					{
						PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][53], blackjack_language_massive[language_id][4]);
					}
				}
			}
			if (blackjackTableInfo[tableid][blackjackTableDealerScore]) 
			{
				new dealer_score = blackjackTableInfo[tableid][blackjackTableDealerScore];

				if (blackjackTableInfo[tableid][blackjackTableDealerHidden]) 
				{
					dealer_score -= blackjack_GetCardScore(blackjackTableInfo[tableid][blackjackTableDealerCard][blackjackTableInfo[tableid][blackjackTableDealerCards] - 1]);
				}
				switch (dealer_score) 
				{
					case 0..20: format(blackjack_string, 24, "~y~%d", dealer_score);
					case 21:	format(blackjack_string, 24, "~g~%d", dealer_score);
					default: 	format(blackjack_string, 24, "~r~%d", dealer_score);
				}
				if (blackjackTableInfo[tableid][blackjackTableDealerDelay]) 
				{
					if (--blackjackTableInfo[tableid][blackjackTableDealerDelay] == 0) 
					{
						blackjackTableInfo[tableid][blackjackTableDealerHidden] = 0;

						dealer_score = blackjackTableInfo[tableid][blackjackTableDealerScore];
					
						if (blackjackTableInfo[tableid][blackjackTableDealerHidden]) 
						{
							dealer_score -= blackjack_GetCardScore(blackjackTableInfo[tableid][blackjackTableDealerCard][blackjackTableInfo[tableid][blackjackTableDealerCards] - 1]);
						}
						switch (dealer_score) 
						{
							case 0..20: format(blackjack_string, 24, "~y~%d", dealer_score);
							case 21:	format(blackjack_string, 24, "~g~%d", dealer_score);
							default: 	format(blackjack_string, 24, "~r~%d", dealer_score);
						}
						blackjack_CheckWinners(tableid);

						ApplyDynamicActorAnimation(blackjackTableInfo[tableid][blackjackTableActorID], "CASINO", "cards_out", 4.1, 0, 1, 1, 1, 1);
						blackjackTableInfo[tableid][blackjackTableStatus] = BLACKJACK_STATUS_ENDING;
						blackjackTableInfo[tableid][blackjackTableDelay] = (15);
					}
					else 
					{
						blackjack_CheckCardToDealer(tableid);

						dealer_score = blackjackTableInfo[tableid][blackjackTableDealerScore];
						if (blackjackTableInfo[tableid][blackjackTableDealerHidden])
							dealer_score -= blackjack_GetCardScore(blackjackTableInfo[tableid][blackjackTableDealerCard][blackjackTableInfo[tableid][blackjackTableDealerCards] - 1]);

						switch (dealer_score) 
						{
							case 0..20: format(blackjack_string, 24, "~y~%d", dealer_score);
							case 21:	format(blackjack_string, 24, "~g~%d", dealer_score);
							default: 	format(blackjack_string, 24, "~r~%d", dealer_score);
						}
						format(blackjack_string, 24, "%s~n~~r~00:%02d", blackjack_string, blackjackTableInfo[tableid][blackjackTableDealerDelay]);
					}
				}
				PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[3]], blackjack_string);
			}
			if (blackjackTableInfo[tableid][blackjackTableStatus] == BLACKJACK_STATUS_STARTING) 
			{
				for (new card_id = 0; card_id < 5; card_id++) 
				{
					PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[3] + card_id], "_");
				}
				PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[3]], "_");
			}
			else 
			{
				if (blackjackTableInfo[tableid][blackjackTableDealerCards]) 
				{
					for (new card_id = 0; card_id < (blackjackTableInfo[tableid][blackjackTableDealerCards]); card_id++) 
					{
						if ((blackjackTableInfo[tableid][blackjackTableDealerCards] - 1) == card_id && blackjackTableInfo[tableid][blackjackTableDealerHidden] == 1) 
						{
							PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[3] + card_id], "LD_CARD:cdback");
						}
						else 
						{
							PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[3] + card_id],
								CASINO_BJ_CARD_INFO[blackjackTableInfo[tableid][blackjackTableDealerCard][card_id]][CASINO_BJ_CARD_NAME]
							);
						
						}
					}

				}
			}
			if (BJ_PlayerInfo[playerid][pBlackJackActiveID] && BJ_PlayerInfo[playerid][pBlackJackDelay]) 
			{
				if (blackjackTableInfo[tableid][blackjackTableStatus] == BLACKJACK_STATUS_ENDING) 
				{
					Dialog_Close(playerid);
					PlayerTextDrawHide(playerid, Blackjack_PTD[playerid][54]);

					BJ_PlayerInfo[playerid][pBlackJackDelay] = 
					BJ_PlayerInfo[playerid][pBlackJackActiveID] = 0;

					BJ_PlayerInfo[playerid][pBlackJackStatus][BJ_PlayerInfo[playerid][pBlackJackBlockID]] = BJ_PLAYER_STATUS_STAY;
					blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_NONE);
				}
				if (--BJ_PlayerInfo[playerid][pBlackJackDelay] == 0 && BJ_PlayerInfo[playerid][pBlackJackSeatID] == blackjackTableInfo[tableid][blackjackTablePlayerid]) 
					blackjack_NextTurn(tableid);
			}
			for (new slotid = 0, player_Name[MAX_PLAYER_NAME + 24], targetid; slotid < MAX_BLACKJACK_SEATS; slotid++) 
			{
				targetid = blackjackTableInfo[tableid][blackjackTableSlots][slotid];
				if (targetid != INVALID_PLAYER_ID) 
				{
					strmid(player_Name, GetName(playerid), 0, MAX_PLAYER_NAME + 1);

					if (targetid == playerid) 
					{
						strreplace(player_Name, "_", "~n~~g~~h~");
						format(player_Name, sizeof(player_Name), "~g~~h~%s~n~~p~%d", player_Name, PI[playerid][pCasinoChips]);
					}
					else 
					{ 
						strreplace(player_Name, "_", "~n~");
						format(player_Name, sizeof(player_Name), "%s~n~~p~%d", player_Name, PI[playerid][pCasinoChips]);
					}
					language_id = BJ_PlayerInfo[targetid][pBlackJackLanguage];
					
					if (language_id != PI[targetid][pCasinoLanguage]) 
					{
						PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][3], blackjack_language_massive[language_id][5]);
						PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][54], blackjack_language_massive[language_id][6]);
					}
					PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][i], player_Name), player_Name[0] = EOS;
					PlayerTextDrawShow(targetid, Blackjack_PTD[targetid][i]);

					if (blackjackTableInfo[tableid][blackjackTableStatus] == BLACKJACK_STATUS_STARTING) 
					{
						 for (new card_id = 0, ptd_id; card_id < (MAX_BLACKJACK_PLAYER_CARD * 2); card_id++) 
						 {
							PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][blackjack_td_seats_array[i] + card_id], "_");

							if (card_id >= 2) continue;
							ptd_id = (i + ((card_id == 0) ? (8) : (55)));

							if (0 == card_id && BJ_PlayerInfo[playerid][pBlackJackBet][card_id]) 
							{
								format(blackjack_string, 22, "~g~READY~n~~p~%d", BJ_PlayerInfo[playerid][pBlackJackBet][card_id]);
								PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][ptd_id], blackjack_string);
							}
							else PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][ptd_id], "_");
							PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][blackjack_td_score_array[i] + card_id], "_");
						}
					}
					else if (BJ_PlayerInfo[playerid][pBlackJackActiveHand]) 
					{
						if (BJ_PlayerInfo[playerid][pBlackJackCards][0]) 
						{
							for (new card_id = 0; card_id < (BJ_PlayerInfo[playerid][pBlackJackCards][0]); card_id++) 
							{
								PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][blackjack_td_seats_array[i] + card_id],
									CASINO_BJ_CARD_INFO[BJ_PlayerInfo[playerid][pBlackJackCard][card_id]][CASINO_BJ_CARD_NAME]
								);
							}
						}
						else 
						{
							for (new card_id = 0; card_id < (BJ_PlayerInfo[playerid][pBlackJackCards][0]); card_id++) 
							PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][blackjack_td_seats_array[i] + card_id], "_");

						}
						if (BJ_PlayerInfo[playerid][pBlackJackCards][1]) 
						{
							for (new card_id = 5; card_id < (BJ_PlayerInfo[playerid][pBlackJackCards][1] + 5); card_id++) 
							{
								PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][blackjack_td_seats_array[i] + card_id],
									CASINO_BJ_CARD_INFO[BJ_PlayerInfo[playerid][pBlackJackCard][card_id]][CASINO_BJ_CARD_NAME]
								);
							}
						}
						else 
						{
							for (new card_id = 5; card_id < (BJ_PlayerInfo[playerid][pBlackJackCards][1] + 5); card_id++) 
							PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][blackjack_td_seats_array[i] + card_id], "_");

						}
						for (new card_score_id = 0, ptd_id; card_score_id < 2; card_score_id++) 
						{
							ptd_id = (i + ((card_score_id == 0) ? (8) : (55)));

							if (BJ_PlayerInfo[playerid][pBlackJackCardsScore][card_score_id]) 
							{
								format(blackjack_string, 22, "~p~%d", BJ_PlayerInfo[playerid][pBlackJackBet][card_score_id]);
								if (card_score_id == BJ_PlayerInfo[playerid][pBlackJackBlockID] && BJ_PlayerInfo[playerid][pBlackJackActiveID] && BJ_PlayerInfo[playerid][pBlackJackDelay]) 
								{
									format(blackjack_string, 26, "~r~00:%02d~n~%s", BJ_PlayerInfo[playerid][pBlackJackDelay], blackjack_string);
								}
								else if (BJ_PlayerInfo[playerid][pBlackJackStatus][card_score_id] == BJ_PLAYER_STATUS_STAY) 
								{
									format(blackjack_string, 22, "~y~STAY~n~%s", blackjack_string);
								}
								else if (BJ_PlayerInfo[playerid][pBlackJackStatus][card_score_id] == BJ_PLAYER_STATUS_SPLIT) 
								{
									format(blackjack_string, 22, "~y~SPLIT~n~%s", blackjack_string);
								}
								else if (BJ_PlayerInfo[playerid][pBlackJackStatus][card_score_id] == BJ_PLAYER_STATUS_DOUBLE) 
								{
									format(blackjack_string, 22, "~y~DOUBLE~n~%s", blackjack_string);
								}
								else if (BJ_PlayerInfo[playerid][pBlackJackStatus][card_score_id] == BJ_PLAYER_STATUS_WON) 
								{
									format(blackjack_string, 22, "+~g~%d", BJ_PlayerInfo[playerid][pBlackJackBet][card_score_id]);
								}
								else if (BJ_PlayerInfo[playerid][pBlackJackStatus][card_score_id] == BJ_PLAYER_STATUS_LOSE) 
								{
									format(blackjack_string, 22, "-~r~%d", BJ_PlayerInfo[playerid][pBlackJackBet][card_score_id]);
								}
								else if (0 == BJ_PlayerInfo[playerid][pBlackJackBet][card_score_id]) blackjack_string[0] = EOS;

								PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][ptd_id], blackjack_string);

								switch (BJ_PlayerInfo[playerid][pBlackJackCardsScore][card_score_id]) 
								{
									case 21:	format(blackjack_string, 12, "~g~%d", BJ_PlayerInfo[playerid][pBlackJackCardsScore][card_score_id]);
									case 0..20: format(blackjack_string, 12, "~y~%d", BJ_PlayerInfo[playerid][pBlackJackCardsScore][card_score_id]);
									default: 	format(blackjack_string, 12, "~r~%d", BJ_PlayerInfo[playerid][pBlackJackCardsScore][card_score_id]);
								}
								PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][blackjack_td_score_array[i] + card_score_id], blackjack_string);
							}
							else 
							{
								PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][ptd_id], "_");
								PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][blackjack_td_score_array[i] + card_score_id], "_");
							}
						}
					}
				}
			}
		}
		else {
			for (new slotid = 0, targetid; slotid < MAX_BLACKJACK_SEATS; slotid++) 
			{
				if ((targetid = blackjackTableInfo[tableid][blackjackTableSlots][slotid]) != INVALID_PLAYER_ID) 
				{
					for (new card_id = 0, ptd_id; card_id < (MAX_BLACKJACK_PLAYER_CARD * 2); card_id++)  
					{
						PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][blackjack_td_seats_array[i] + card_id], "_");

						if (card_id >= 2) continue;
						ptd_id = (i + ((card_id == 0) ? (8) : (55)));
						PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][ptd_id], "_");
					}
					for (new card_score_id = 0; card_score_id < 2; card_score_id++) {
						PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][blackjack_td_score_array[i] + card_score_id], "_");
					}
					PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][i], blackjack_language_massive[CASINO_LANGUAGE_ENGLISH][0]);
					PlayerTextDrawHide(targetid, Blackjack_PTD[targetid][i]);
				}
			}
		}
	}
	return true;
}
blackjack_ActionStay(playerid) 
{
	if (
		!BJ_PlayerInfo[playerid][pBlackJackTableID] ||
		!BJ_PlayerInfo[playerid][pBlackJackActiveID] ||
		!BJ_PlayerInfo[playerid][pBlackJackDelay]
	) return;

	new tableid = (BJ_PlayerInfo[playerid][pBlackJackTableID] - 1);
	blackjack_NextTurn(tableid);
}
blackjack_CheckWinners(tableid) 
{
	new player_score = 0, dealer_score = 0;
	for (new i = 0, playerid, cards_win[2]; i < MAX_BLACKJACK_SEATS; i++) if ((playerid = blackjackTableInfo[tableid][blackjackTableSlots][i]) != INVALID_PLAYER_ID) {
		for (new card_score_id = 0; card_score_id < 2; card_score_id++) if (BJ_PlayerInfo[playerid][pBlackJackCardsScore][card_score_id]) {
			player_score = BJ_PlayerInfo[playerid][pBlackJackCardsScore][card_score_id];
			dealer_score = blackjackTableInfo[tableid][blackjackTableDealerScore];

			if (player_score > 21) 
			{ // lose
				PI[playerid][pCasinoChips] -= BJ_PlayerInfo[playerid][pBlackJackBet][card_score_id];
				BJ_PlayerInfo[playerid][pBlackJackStatus][card_score_id] = BJ_PLAYER_STATUS_LOSE;
			}
			else if (dealer_score > 21) 
			{ // win
				format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "[BJ]: %s moigo %d fishka (Magida #%d), xeli #%d",
					GetName(playerid), BJ_PlayerInfo[playerid][pBlackJackBet][card_score_id], tableid + 1, card_score_id + 1
				);
				printf(STRING_GLOBAL), /*WriteLog("logs_casino", STRING_GLOBAL), */STRING_GLOBAL[0] = EOS;

				PI[playerid][pCasinoChips] += BJ_PlayerInfo[playerid][pBlackJackBet][card_score_id];
				BJ_PlayerInfo[playerid][pBlackJackStatus][card_score_id] = BJ_PLAYER_STATUS_WON;
			}
			else if (player_score == dealer_score) 
			{ // draw
				BJ_PlayerInfo[playerid][pBlackJackBet][card_score_id] = 0;
			}
			else if (player_score > dealer_score) 
			{ // win
				format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "[BJ]: %s moigo %d fishka (Magida #%d), xeli #%d",
					GetName(playerid), BJ_PlayerInfo[playerid][pBlackJackBet][card_score_id], tableid + 1, card_score_id + 1
				);
				printf(STRING_GLOBAL), /*WriteLog("logs_casino", STRING_GLOBAL), */STRING_GLOBAL[0] = EOS;

				PI[playerid][pCasinoChips] += BJ_PlayerInfo[playerid][pBlackJackBet][card_score_id];
				BJ_PlayerInfo[playerid][pBlackJackStatus][card_score_id] = BJ_PLAYER_STATUS_WON;
			}
			else 
			{ // lose
				format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "[BJ]: %s waago %d fishka (Magida #%d), xeli #%d",
					GetName(playerid), BJ_PlayerInfo[playerid][pBlackJackBet][card_score_id], tableid + 1, card_score_id + 1
				);
				printf(STRING_GLOBAL), /*WriteLog("logs_casino", STRING_GLOBAL), */STRING_GLOBAL[0] = EOS;

				PI[playerid][pCasinoChips] -= BJ_PlayerInfo[playerid][pBlackJackBet][card_score_id];
				BJ_PlayerInfo[playerid][pBlackJackStatus][card_score_id] = BJ_PLAYER_STATUS_LOSE;
			}
			switch (BJ_PlayerInfo[playerid][pBlackJackStatus][card_score_id]) 
			{
				case BJ_PLAYER_STATUS_LOSE: cards_win[card_score_id] = 0;
				default: cards_win[card_score_id] = 1;
			}
		}
		if (!cards_win[0] && !cards_win[1])
			ApplyAnimation(playerid, "CASINO", "cards_lose", 4.1, 0, 1, 1, 1, 1, 1);
		else ApplyAnimation(playerid, "CASINO", "cards_win", 4.1, 0, 1, 1, 1, 1, 1);
	}
}
blackjack_GiveTurn(playerid, tableid, block_id) {
	new seatid = BJ_PlayerInfo[playerid][pBlackJackSeatID];

	blackjackTableInfo[tableid][blackjackTablePlayerid] = seatid;

	blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_DSHS);

	BJ_PlayerInfo[playerid][pBlackJackDelay] = (30 + 1);
	BJ_PlayerInfo[playerid][pBlackJackActiveID] = 1;

	BJ_PlayerInfo[playerid][pBlackJackBlockID] = block_id;

	ApplyAnimation(playerid, "CASINO", "cards_loop", 4.1, 0, 1, 1, 1, 1, 1);
	PlayerTextDrawShow(playerid, Blackjack_PTD[playerid][54]);
}
blackjack_NextTurn(tableid) {
	if (!blackjackTableInfo[tableid][blackjackTablePlayersActive])
		return false;
	new
		block_id,
		new_playerid = (-1),
		playerid = blackjackTableInfo[tableid][blackjackTablePlayerid],
		last_playerid = blackjackTableInfo[tableid][blackjackTablePlayerid]
	;
	if (playerid == INVALID_PLAYER_ID) playerid = (-1);
	if (playerid != (-1) &&
		(tableid + 1) == BJ_PlayerInfo[blackjackTableInfo[tableid][blackjackTableSlots][playerid]][pBlackJackTableID] &&
		0 == BJ_PlayerInfo[blackjackTableInfo[tableid][blackjackTableSlots][playerid]][pBlackJackBlockID] &&
		BJ_PlayerInfo[blackjackTableInfo[tableid][blackjackTableSlots][playerid]][pBlackJackCards][1]
	) {
		new_playerid = playerid;
		block_id = 1;
	}
	else {
		for (new i = 0; i < MAX_BLACKJACK_SEATS; i++) if ((playerid = blackjackTableInfo[tableid][blackjackTableSlots][i]) != INVALID_PLAYER_ID && !BJ_PlayerInfo[playerid][pBlackJackStatus][0] && BJ_PlayerInfo[playerid][pBlackJackActiveHand] && i > last_playerid) {
			new_playerid = i;
			block_id = 0;
			break;
		}
	}
	if ((playerid = blackjackTableInfo[tableid][blackjackTablePlayerid]) != (-1)) { // +ResetTurn
		playerid = blackjackTableInfo[tableid][blackjackTableSlots][blackjackTableInfo[tableid][blackjackTablePlayerid]];

		ApplyAnimation(playerid, "CASINO", "cards_out", 4.1, 0, 1, 1, 1, 1, 1);
		Dialog_Close(playerid);

		BJ_PlayerInfo[playerid][pBlackJackDelay] = 
		BJ_PlayerInfo[playerid][pBlackJackActiveID] = 0;
		blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_NONE);
		BJ_PlayerInfo[playerid][pBlackJackStatus][BJ_PlayerInfo[playerid][pBlackJackBlockID]] = BJ_PLAYER_STATUS_STAY;
		PlayerTextDrawHide(playerid, Blackjack_PTD[blackjackTableInfo[tableid][blackjackTableSlots][blackjackTableInfo[tableid][blackjackTablePlayerid]]][54]);
	} 
	if (new_playerid != (-1)) 
		blackjack_GiveTurn(blackjackTableInfo[tableid][blackjackTableSlots][new_playerid], tableid, block_id);
	else blackjackTableInfo[tableid][blackjackTableDealerDelay] = 10;

	return new_playerid;
}

blackjack_GetCardScore(card_id) {
	new card_value = CASINO_BJ_CARD_INFO[card_id][CASINO_BJ_CARD_VALUE], card_score = (card_value + 1);
	switch (card_value) {
		case BJ_CARD_NUMBER_TEN..BJ_CARD_NUMBER_KING:
			card_score = 10;
		case BJ_CARD_NUMBER_ACE: card_score = 11;
	}
	return card_score;
}
blackjack_ShuffleHands(tableid) {
 	for (new i = 0; i < MAX_BLACKJACK_SEATS; i++) if (blackjackTableInfo[tableid][blackjackTableSlots][i] != INVALID_PLAYER_ID)
 		PlayerPlaySound(blackjackTableInfo[tableid][blackjackTableSlots][i], 5600, 0.0, 0.0, 0.0);
	for (new i = 0; i < MAX_CASINO_CARDS; i++)
		blackjackTableInfo[tableid][blackjackTableDeck][i] = i;
	new rand, tmp, i;

	for (i = MAX_CASINO_CARDS; i > 1; i--) {
		rand = random(MAX_CASINO_CARDS) % i;
		tmp = blackjackTableInfo[tableid][blackjackTableDeck][rand];
		blackjackTableInfo[tableid][blackjackTableDeck][rand] = blackjackTableInfo[tableid][blackjackTableDeck][i - 1];
		blackjackTableInfo[tableid][blackjackTableDeck][i - 1] = tmp;
	}
	blackjack_DealHands(tableid);

	return true;
}
blackjack_DealHands(tableid) {
	new tmp_id = 0;
	for (new i = 0, playerid, card_value[2]; i < MAX_BLACKJACK_SEATS; i++) if ((playerid = blackjackTableInfo[tableid][blackjackTableSlots][i]) != INVALID_PLAYER_ID) {
		if (BJ_PlayerInfo[playerid][pBlackJackBet][0] && PI[playerid][pCasinoChips] >= BJ_PlayerInfo[playerid][pBlackJackBet][0]) {
			BJ_PlayerInfo[playerid][pBlackJackCard][0] = blackjackTableInfo[tableid][blackjackTableDeck][tmp_id + 0];
			BJ_PlayerInfo[playerid][pBlackJackCard][1] = blackjackTableInfo[tableid][blackjackTableDeck][tmp_id + 1];

			BJ_PlayerInfo[playerid][pBlackJackActiveHand] = 1;

			blackjackTableInfo[tableid][blackjackTableHandsActive]++;

			PlayerPlaySound(playerid, 5602, 0.0, 0.0, 0.0);
			ApplyAnimation(playerid, "CASINO", "cards_in", 4.1, 0, 1, 1, 1, 1, 1);
			BJ_PlayerInfo[playerid][pBlackJackCards][0] = 2;
			blackjack_CheckCards(playerid);

			card_value[0] = CASINO_BJ_CARD_INFO[BJ_PlayerInfo[playerid][pBlackJackCard][0]][CASINO_BJ_CARD_VALUE];
			if (card_value[0] >= BJ_CARD_NUMBER_TEN && card_value[0] <= BJ_CARD_NUMBER_KING) card_value[0] = BJ_CARD_NUMBER_TEN;
			card_value[1] = CASINO_BJ_CARD_INFO[BJ_PlayerInfo[playerid][pBlackJackCard][1]][CASINO_BJ_CARD_VALUE];
			if (card_value[1] >= BJ_CARD_NUMBER_TEN && card_value[1] <= BJ_CARD_NUMBER_KING) card_value[1] = BJ_CARD_NUMBER_TEN;
		
			if ((card_value[0] + card_value[1]) != (BJ_CARD_NUMBER_ACE * 2) && card_value[0] == card_value[1])
				BJ_PlayerInfo[playerid][pBlackJackSplit] = 1;
			else BJ_PlayerInfo[playerid][pBlackJackSplit] = 0;

			tmp_id += 2;
		}
		else continue;
	}
	blackjackTableInfo[tableid][blackjackTableDealerCards] = blackjackTableInfo[tableid][blackjackTableDealerScore] = 0;

	for (new i = 0; i < 2; i++) {
		blackjackTableInfo[tableid][blackjackTableDealerCard][i] = blackjackTableInfo[tableid][blackjackTableDeck][tmp_id];
		blackjackTableInfo[tableid][blackjackTableDealerScore] += blackjack_GetCardScore(blackjackTableInfo[tableid][blackjackTableDealerCard][i]);
		blackjackTableInfo[tableid][blackjackTableDealerCards]++;
		blackjackTableInfo[tableid][blackjackTableDealerHidden] = 1;
		tmp_id++;
	}
	ApplyDynamicActorAnimation(blackjackTableInfo[tableid][blackjackTableActorID], "CASINO", "cards_in", 4.1, 0, 1, 1, 1, 1);
	blackjackTableInfo[tableid][blackjackTableCardsActive] = tmp_id;

	return true;
}
blackjack_CheckCards(playerid, cards_block = 0) {
	if (playerid == -1 || !BJ_PlayerInfo[playerid][pBlackJackTableID]) return 0;
	new tableid = (BJ_PlayerInfo[playerid][pBlackJackTableID] - 1), total_score = 0;
	if (0 == cards_block) for (new card_id = 0; card_id < BJ_PlayerInfo[playerid][pBlackJackCards][cards_block]; card_id++)
		total_score += blackjack_GetCardScore(BJ_PlayerInfo[playerid][pBlackJackCard][card_id]);
	else for (new card_id = 5; card_id < (BJ_PlayerInfo[playerid][pBlackJackCards][cards_block] + 5); card_id++)
		total_score += blackjack_GetCardScore(BJ_PlayerInfo[playerid][pBlackJackCard][card_id]);
	if (total_score >= 21 && BJ_PlayerInfo[playerid][pBlackJackActiveID])
		blackjack_NextTurn(tableid);
	return (BJ_PlayerInfo[playerid][pBlackJackCardsScore][cards_block] = total_score);
}
blackjack_ActionSplit(playerid) {
	if (PI[playerid][pCasinoChips] < BJ_PlayerInfo[playerid][pBlackJackBet][0] * 2) return;
	new
		tableid = (BJ_PlayerInfo[playerid][pBlackJackTableID] - 1),
		card_id = blackjackTableInfo[tableid][blackjackTableCardsActive]
	;
	ApplyAnimation(playerid, "CASINO", "cards_raise", 4.1, 0, 1, 1, 1, 1, 1);

	BJ_PlayerInfo[playerid][pBlackJackStatus][0] = BJ_PLAYER_STATUS_SPLIT;
	BJ_PlayerInfo[playerid][pBlackJackSplit] = 0;

	BJ_PlayerInfo[playerid][pBlackJackCard][5 + 0] = BJ_PlayerInfo[playerid][pBlackJackCard][1];
	BJ_PlayerInfo[playerid][pBlackJackCard][1] = blackjackTableInfo[tableid][blackjackTableDeck][card_id];
	BJ_PlayerInfo[playerid][pBlackJackCard][5 + 1] = blackjackTableInfo[tableid][blackjackTableDeck][card_id + 1];
	BJ_PlayerInfo[playerid][pBlackJackCards][0] = BJ_PlayerInfo[playerid][pBlackJackCards][1] = 2;

	blackjackTableInfo[tableid][blackjackTableCardsActive] += 2;
	blackjackTableInfo[tableid][blackjackTablePlayerid] = BJ_PlayerInfo[playerid][pBlackJackSeatID];

	blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_DSHS);

	BJ_PlayerInfo[playerid][pBlackJackDelay] = (30 + 1);
	BJ_PlayerInfo[playerid][pBlackJackActiveID] = 1;
	BJ_PlayerInfo[playerid][pBlackJackBlockID] = 0;

	BJ_PlayerInfo[playerid][pBlackJackBet][1] = BJ_PlayerInfo[playerid][pBlackJackBet][0];
	PlayerTextDrawShow(playerid, Blackjack_PTD[playerid][54]);

	blackjack_CheckCards(playerid, 0), blackjack_CheckCards(playerid, 1);
}
blackjack_ActionDouble(playerid) {
	if (GetChips(playerid)/*BJ_PlayerInfo[playerid][pBlackJackBet][0]*/ < BJ_PlayerInfo[playerid][pBlackJackBet][0] * 2) {
		ErrorMessage(playerid, "Tqven ar gaqvt sakmarishi fishkebi.");
		return;
	}
	if (BJ_PlayerInfo[playerid][pBlackJackCards][0] != 2) return;



	ApplyAnimation(playerid, "CASINO", "cards_raise", 4.1, 0, 1, 1, 1, 1, 1);

	BJ_PlayerInfo[playerid][pBlackJackStatus][0] = BJ_PLAYER_STATUS_DOUBLE;
	BJ_PlayerInfo[playerid][pBlackJackBet][0] *= 2;
	blackjack_ActionHit(playerid);
	new tableid = (BJ_PlayerInfo[playerid][pBlackJackTableID] - 1);
	if (BJ_PlayerInfo[playerid][pBlackJackActiveID]) blackjack_NextTurn(tableid);
}
blackjack_ActionHit(playerid, cards_block = 0) {
	if (!BJ_PlayerInfo[playerid][pBlackJackBet][cards_block] /*|| !BJ_PlayerInfo[playerid][pBlackJackCards][cards_block]*/) return;

	new
		tableid = (BJ_PlayerInfo[playerid][pBlackJackTableID] - 1),
		player_card_id = (BJ_PlayerInfo[playerid][pBlackJackCards][cards_block]),
		card_id = blackjackTableInfo[tableid][blackjackTableCardsActive]
	;
	if (player_card_id == MAX_BLACKJACK_PLAYER_CARD)
		return;
	ApplyAnimation(playerid, "CASINO", "cards_in", 4.1, 0, 1, 1, 1, 1, 1);

	if (cards_block) player_card_id += 5;

	BJ_PlayerInfo[playerid][pBlackJackCard][player_card_id] = blackjackTableInfo[tableid][blackjackTableDeck][card_id];
	BJ_PlayerInfo[playerid][pBlackJackCards][cards_block]++;
	blackjackTableInfo[tableid][blackjackTableCardsActive]++;

	blackjack_UpdateOptions(playerid, BJ_PlayerInfo[playerid][pBlackJackOptions]);
	blackjack_CheckCards(playerid, cards_block);
}
blackjack_CheckCardToDealer(tableid) {
	if (blackjackTableInfo[tableid][blackjackTableDealerScore] >= 17) return;

	new
		dealer_card_id = blackjackTableInfo[tableid][blackjackTableDealerCards],
		card_id = blackjackTableInfo[tableid][blackjackTableCardsActive]
	;
	if (dealer_card_id == MAX_BLACKJACK_PLAYER_CARD)
		return;
	ApplyDynamicActorAnimation(blackjackTableInfo[tableid][blackjackTableActorID], "CASINO", "cards_in", 4.1, 0, 1, 1, 1, 1);

	blackjackTableInfo[tableid][blackjackTableDealerCard][dealer_card_id] = blackjackTableInfo[tableid][blackjackTableDeck][card_id];
	blackjackTableInfo[tableid][blackjackTableDealerScore] += blackjackTableInfo[tableid][blackjackTableDealerCard][dealer_card_id];
	blackjackTableInfo[tableid][blackjackTableDealerCards]++;
	blackjackTableInfo[tableid][blackjackTableCardsActive]++;

	blackjackTableInfo[tableid][blackjackTableDealerScore] = 0;
	for (new card__id = 0; card__id < blackjackTableInfo[tableid][blackjackTableDealerCards]; card__id++)
		blackjackTableInfo[tableid][blackjackTableDealerScore] += blackjack_GetCardScore(blackjackTableInfo[tableid][blackjackTableDealerCard][card__id]);
}
blackjack_ResetRound(tableid) {
	blackjackTableInfo[tableid][blackjackTableDealerCards] =
	blackjackTableInfo[tableid][blackjackTableDealerScore] =
	blackjackTableInfo[tableid][blackjackTableDealerHidden] =
	blackjackTableInfo[tableid][blackjackTableDealerDelay] =

	blackjackTableInfo[tableid][blackjackTableCardsActive] =
	blackjackTableInfo[tableid][blackjackTableHandsActive] = 0;
	blackjackTableInfo[tableid][blackjackTableDelay] = 0;

	blackjackTableInfo[tableid][blackjackTablePlayerid] = (-1);

	for (new i = 0, playerid; i < MAX_BLACKJACK_SEATS; i++) if ((playerid = blackjackTableInfo[tableid][blackjackTableSlots][i]) != INVALID_PLAYER_ID) {
		BJ_PlayerInfo[playerid][pBlackJackDelay] =
		BJ_PlayerInfo[playerid][pBlackJackActiveHand] =
		BJ_PlayerInfo[playerid][pBlackJackActiveID] =
		BJ_PlayerInfo[playerid][pBlackJackBlockID] =
		BJ_PlayerInfo[playerid][pBlackJackBet][0] = BJ_PlayerInfo[playerid][pBlackJackBet][1] =
		BJ_PlayerInfo[playerid][pBlackJackCards][0] = BJ_PlayerInfo[playerid][pBlackJackCards][1] =
		BJ_PlayerInfo[playerid][pBlackJackCardsScore][0] = BJ_PlayerInfo[playerid][pBlackJackCardsScore][1] =
		BJ_PlayerInfo[playerid][pBlackJackStatus][0] = BJ_PlayerInfo[playerid][pBlackJackStatus][1] = 0;

		ApplyAnimation(playerid, "CASINO", "cards_out", 4.1, 0, 1, 1, 1, 1, 1);
	}
	ApplyDynamicActorAnimation(blackjackTableInfo[tableid][blackjackTableActorID], "CASINO", "cards_out", 4.1, 0, 1, 1, 1, 1);
	return true;
}
blackjack_ResetTable(tableid) {
	blackjackTableInfo[tableid][blackjackTableMaxBet] = BLACKJACK_DEFAULT_MAX_BET;
	blackjackTableInfo[tableid][blackjackTableMinBet] = BLACKJACK_DEFAULT_MIN_BET;
	blackjackTableInfo[tableid][blackjackTableEnterPrice] = BLACKJACK_DEFAULT_SEAT_PRICE;
	blackjackTableInfo[tableid][blackjackTableStatus] = BLACKJACK_STATUS_NONE;

	blackjackTableInfo[tableid][blackjackTableDealerCards] =
	blackjackTableInfo[tableid][blackjackTableDealerScore] =
	blackjackTableInfo[tableid][blackjackTableDealerHidden] =
	blackjackTableInfo[tableid][blackjackTableDealerDelay] =

	blackjackTableInfo[tableid][blackjackTableCardsActive] =
	blackjackTableInfo[tableid][blackjackTableHandsActive] =
	blackjackTableInfo[tableid][blackjackTableTimer] =

	blackjackTableInfo[tableid][blackjackTableDelay] =
	blackjackTableInfo[tableid][blackjackTableplayers] =
	blackjackTableInfo[tableid][blackjackTableTimer] = 0;

	for (new targetid = 0; targetid < (blackjackTableInfo[tableid][blackjackTableLimit] = MAX_BLACKJACK_SEATS); targetid++)
		blackjackTableInfo[tableid][blackjackTableSlots][targetid] = INVALID_PLAYER_ID;

	ApplyDynamicActorAnimation(blackjackTableInfo[tableid][blackjackTableActorID], "CASINO", "cards_out", 4.1, 0, 1, 1, 1, 1);
	ClearDynamicActorAnimations(blackjackTableInfo[tableid][blackjackTableActorID]);
	ApplyDynamicActorAnimation(blackjackTableInfo[tableid][blackjackTableActorID], "CARRY", "crry_prtial", 1.0, 0, 0, 0, 0, 0);
	return true;
}
blackjack_LeaveGame(playerid) {
	if (!BJ_PlayerInfo[playerid][pBlackJackTableID]) return false;
	SetPVarInt(playerid,"blackjack_JoinGameTick",GetTickCount());

	new tableid = (BJ_PlayerInfo[playerid][pBlackJackTableID] - 1);
	PlayerPlaySound(playerid, 5852, 0.0, 0.0, 0.0);

			
	if ((tableid + 1)) {
		switch (blackjackTableInfo[tableid][blackjackTableStatus]) {
			case BLACKJACK_STATUS_STARTED: {
				if (BJ_PlayerInfo[playerid][pBlackJackBet][0] && BJ_PlayerInfo[playerid][pBlackJackStatus][0] != BJ_PLAYER_STATUS_WON && BJ_PlayerInfo[playerid][pBlackJackStatus][0] != BJ_PLAYER_STATUS_LOSE) {
					format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "[BJ]: %s gavida magididan da waago %d fishka (Magida #%d), xeli #1",
						GetName(playerid), BJ_PlayerInfo[playerid][pBlackJackBet][0], tableid + 1
					);
					printf(STRING_GLOBAL), /*WriteLog("logs_casino", STRING_GLOBAL), */STRING_GLOBAL[0] = EOS;
					PI[playerid][pCasinoChips] -= BJ_PlayerInfo[playerid][pBlackJackBet][0];
				}
				if (BJ_PlayerInfo[playerid][pBlackJackBet][1] && BJ_PlayerInfo[playerid][pBlackJackStatus][1] != BJ_PLAYER_STATUS_WON && BJ_PlayerInfo[playerid][pBlackJackStatus][1] != BJ_PLAYER_STATUS_LOSE) {
					format(STRING_GLOBAL, sizeof(STRING_GLOBAL), "[BJ]: %s gavida magididan da waago %d fishka (Magida #%d), xeli #2",
						GetName(playerid), BJ_PlayerInfo[playerid][pBlackJackBet][1], tableid + 1
					);
					printf(STRING_GLOBAL), /*WriteLog("logs_casino", STRING_GLOBAL), */STRING_GLOBAL[0] = EOS;
					PI[playerid][pCasinoChips] -= BJ_PlayerInfo[playerid][pBlackJackBet][1];
				}
			}
		}
		if (--blackjackTableInfo[tableid][blackjackTableplayers]) {
			if (BJ_PlayerInfo[playerid][pBlackJackBet][0] || BJ_PlayerInfo[playerid][pBlackJackBet][1])
				blackjackTableInfo[tableid][blackjackTablePlayersActive]--;
			if (BJ_PlayerInfo[playerid][pBlackJackActiveHand])
				blackjackTableInfo[tableid][blackjackTableHandsActive]--;
			if (BJ_PlayerInfo[playerid][pBlackJackActiveID] && BJ_PlayerInfo[playerid][pBlackJackDelay] && BJ_PlayerInfo[playerid][pBlackJackSeatID] == blackjackTableInfo[tableid][blackjackTablePlayerid]) {
				blackjack_NextTurn(tableid);
			}
		}
		new blackjack_seatid = BJ_PlayerInfo[playerid][pBlackJackSeatID];
		blackjackTableInfo[tableid][blackjackTableSlots][blackjack_seatid] = INVALID_PLAYER_ID;
		/*
	
		for (new i = 0, targetid; i < MAX_BLACKJACK_SEATS; i++) 
		{
			targetid = blackjackTableInfo[tableid][blackjackTableSlots][i];
			if (targetid != INVALID_PLAYER_ID) {

				for (new card_id = 0; card_id < (BJ_PlayerInfo[playerid][pBlackJackCards][0]); card_id++) 
				PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][blackjack_td_seats_array[blackjack_seatid] + card_id], "_");

				for (new card_id = 5; card_id < (BJ_PlayerInfo[playerid][pBlackJackCards][1] + 5); card_id++) 
				PlayerTextDrawSetString(targetid, Blackjack_PTD[targetid][blackjack_td_seats_array[blackjack_seatid] + card_id], "_");
			}
		}*/
		/*if (!blackjackTableInfo[tableid][blackjackTableround] && blackjackTableInfo[tableid][blackjackTableDelay] < 5)
			blackjack_ResetRound(tableid); */
		Streamer_ToggleItem(playerid, STREAMER_TYPE_3D_TEXT_LABEL, blackjackTableInfo[tableid][blackjackTableTextID], true);
		Streamer_Update(playerid, STREAMER_TYPE_3D_TEXT_LABEL);

		SetPlayerInterior(playerid, blackjackTableInfo[tableid][blackjackTableInterior]);
		SetPlayerVirtualWorld(playerid, blackjackTableInfo[tableid][blackjackTableWorld]);

		if (!blackjackTableInfo[tableid][blackjackTableplayers]) blackjack_ResetTable(tableid);
	}
	SetPlayerPos(playerid, BJ_PlayerInfo[playerid][pBlackJackPos][0], BJ_PlayerInfo[playerid][pBlackJackPos][1], BJ_PlayerInfo[playerid][pBlackJackPos][2] + 0.1);
	Dialog_Close(playerid);

	blackjack_DestroyGUI(playerid);

	/*BJ_PlayerInfo[playerid][pBlackJackTableID] =
	BJ_PlayerInfo[playerid][pBlackJackSeatID] =

	BJ_PlayerInfo[playerid][pBlackJackDelay] =
	BJ_PlayerInfo[playerid][pBlackJackActiveID] =
	BJ_PlayerInfo[playerid][pBlackJackActiveHand] = 0;

	for (new card_id = 0; card_id < 2; card_id++) {
		BJ_PlayerInfo[playerid][pBlackJackStatus][card_id] = BJ_PLAYER_STATUS_NONE;
		BJ_PlayerInfo[playerid][pBlackJackCards][card_id] =
		BJ_PlayerInfo[playerid][pBlackJackCardsScore][card_id] =
		BJ_PlayerInfo[playerid][pBlackJackBet][card_id] = 0;
	}
	BJ_PlayerInfo[playerid][pBlackJackPos][0] =
	BJ_PlayerInfo[playerid][pBlackJackPos][1] =
	BJ_PlayerInfo[playerid][pBlackJackPos][2] = 0.0;*/

	BJ_PlayerInfo[playerid] = NULL_BJ_PI;


	TogglePlayerControllable(playerid, true);
	SetCameraBehindPlayer(playerid);
	CancelSelectTextDraw(playerid);

	ClearAnimations(playerid);
	ApplyAnimation(playerid, "CARRY", "crry_prtial", 1.0, 0, 0, 0, 0, 0);

	return true;
}
blackjack_DestroyGUI(playerid) {
	if (!BJ_PlayerInfo[playerid][pBlackJackGUI])
		return false;

	for (new i = 0; i < sizeof(Blackjack_TD); i++)
		TextDrawHideForPlayer(playerid, Blackjack_TD[i]);
	for (new i = 0; i < 58; i++)
		PlayerTextDrawDestroy(playerid, Blackjack_PTD[playerid][i]);
	BJ_PlayerInfo[playerid][pBlackJackGUI] = 0;
	return true;
}
blackjack_JoinGame(playerid, tableid) {
	/*if (Server::Settings[Server::BLACKJACK] == 0) 
		return ErrorMessage(playerid, "Mocemul droshi black jack miuwvdomelia.");*/
	/*#pragma unused tableid
	return ErrorMessage(playerid, "Mocemul droshi black jack miuwvdomelia.");*/
	if ((GetTickCount() - GetPVarInt(playerid,"blackjack_JoinGameTick")) < 1200)
		return false;
	SetPVarInt(playerid,"blackjack_JoinGameTick",GetTickCount());

	if (blackjackTableInfo[tableid][blackjackTableplayers] >= blackjackTableInfo[tableid][blackjackTableLimit])
		return ErrorMessage(playerid, "Ar aris tavisufali adgilebi."), false;
	// if (blackjackTableInfo[tableid][blackjackTableactive] == 1) return false;
	if (blackjackTableInfo[tableid][blackjackTableEnterPrice] && GetPlayerMoneyEx(playerid) < blackjackTableInfo[tableid][blackjackTableEnterPrice])
		return SendFormattedMessage(playerid, COLOR_ERROR, ""NO"*"G" Tqven ar gaqvt sakmarisi tanxa, satamashot sachiroa $%d.", blackjackTableInfo[tableid][blackjackTableEnterPrice]);

	for (new targetid = 0, Float:object_angle = 0.0; targetid < MAX_BLACKJACK_SEATS; targetid++) if (blackjackTableInfo[tableid][blackjackTableSlots][targetid] == INVALID_PLAYER_ID) {
		BJ_PlayerInfo[playerid][pBlackJackLanguage] = PI[playerid][pCasinoLanguage];
		GivePlayerMoney(playerid, -blackjackTableInfo[tableid][blackjackTableEnterPrice]);

	    blackjack_CreatePTD(playerid, targetid);
		blackjack_ShowGUI(playerid);

		SelectTextDraw(playerid, 0x000000FF);

		blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_NONE);

		BJ_PlayerInfo[playerid][pBlackJackTableID] = (tableid + 1);
		BJ_PlayerInfo[playerid][pBlackJackSeatID] = targetid;
		BJ_PlayerInfo[playerid][pBlackJackDelay] =
		BJ_PlayerInfo[playerid][pBlackJackActiveID] =
		BJ_PlayerInfo[playerid][pBlackJackLastBet] =
		BJ_PlayerInfo[playerid][pBlackJackBlockID] =
		BJ_PlayerInfo[playerid][pBlackJackActiveHand] = 0;

		for (new card_id = 0; card_id < 2; card_id++) {
			BJ_PlayerInfo[playerid][pBlackJackStatus][card_id] = BJ_PLAYER_STATUS_NONE;
			BJ_PlayerInfo[playerid][pBlackJackCards][card_id] =
			BJ_PlayerInfo[playerid][pBlackJackCardsScore][card_id] =
			BJ_PlayerInfo[playerid][pBlackJackBet][card_id] = 0;
		}
		blackjackTableInfo[tableid][blackjackTableplayers]++;
		if (blackjackTableInfo[tableid][blackjackTableplayers] == 1)
			blackjackTableInfo[tableid][blackjackTableTimer] = 1;
		blackjackTableInfo[tableid][blackjackTableSlots][targetid] = playerid;

		Streamer_ToggleItem(playerid, STREAMER_TYPE_3D_TEXT_LABEL, blackjackTableInfo[tableid][blackjackTableTextID], false);
		Streamer_Update(playerid, STREAMER_TYPE_3D_TEXT_LABEL);

		GetDynamicObjectRot(blackjackTableInfo[tableid][blackjackTableObjectID], object_angle, object_angle, object_angle);

		CameraRadiusSetPos(playerid,
			blackjackTableInfo[tableid][blackjackTablePos][0], blackjackTableInfo[tableid][blackjackTablePos][1], blackjackTableInfo[tableid][blackjackTablePos][2],
			(object_angle + 180.0), 2.3, 3.2
		);
		GetPlayerPos(playerid, BJ_PlayerInfo[playerid][pBlackJackPos][0], BJ_PlayerInfo[playerid][pBlackJackPos][1], BJ_PlayerInfo[playerid][pBlackJackPos][2]);
        SetPlayerInterior(playerid, blackjackTableInfo[tableid][blackjackTableInterior]);
		SetPlayerVirtualWorld(playerid, blackjackTableInfo[tableid][blackjackTableWorld]);

		ApplyAnimation(playerid, "CASINO", "cards_out", 4.1, 0, 1, 1, 1, 1, 1);
		TogglePlayerControllable(playerid, false);

		SetPlayerFacingAngle(playerid, (blackjack_TableOffsets[targetid][3] + object_angle));
		SetPlayerPosObjectOffset(blackjackTableInfo[tableid][blackjackTableObjectID], playerid, blackjack_TableOffsets[targetid][0], blackjack_TableOffsets[targetid][1], blackjack_TableOffsets[targetid][2]);

		if (blackjackTableInfo[tableid][blackjackTableStatus] == BLACKJACK_STATUS_STARTING && blackjackTableInfo[tableid][blackjackTableDelay] > 2)
			blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_MMBA);
		break;
	}
	return true;
}
blackjack_ShowGUI(playerid) {
	for (new i = 0; i < 2; i++)
		TextDrawShowForPlayer(playerid, Blackjack_TD[i]);
	PlayerTextDrawHide(playerid, Blackjack_PTD[playerid][0]);
	for (new i = 3; i < 58; i++) {
		switch (i) {
			case 54: continue;
		}
		PlayerTextDrawShow(playerid, Blackjack_PTD[playerid][i]);
	}
	return true;
}
blackjack_OnPlayerDisconnect(playerid) {
	blackjack_LeaveGame(playerid);
	return true;
}
blackjack_OnPlayerDeath(playerid) {
	blackjack_LeaveGame(playerid);
	return true;
}
blackjack_OnPlayerKStateChange(playerid, newkeys, oldkeys) {
	new bool:blackjack_joined = false;
	if (!BJ_PlayerInfo[playerid][pBlackJackTableID] && (newkeys & KEY_SECONDARY_ATTACK && oldkeys != KEY_SECONDARY_ATTACK)) {
		foreach(new blackjack_id: blackjackTables) {
			if (IsPlayerInDynamicArea(playerid, blackjackTableInfo[blackjack_id][blackjackTableAreaID], 1)) {
				blackjack_JoinGame(playerid, blackjack_id), blackjack_joined = true;
				break;
			}
		}
	}
	return blackjack_joined;
}
stock blackjack_OnPlayerClickTextDraw(playerid, Text:clickedid) {
	if (BJ_PlayerInfo[playerid][pBlackJackTableID]) {
		new tableid = (BJ_PlayerInfo[playerid][pBlackJackTableID] - 1);

		if (clickedid == Blackjack_Tutorial_TD[1]) { // << BACK
			blackjack_TutorialNextStep(playerid, BJ_PlayerInfo[playerid][pBlackJackTutorialStep] - 1, 0);
			return true;
		}
		if (clickedid == Blackjack_Tutorial_TD[2]) { // >> NEXT
			blackjack_TutorialNextStep(playerid, BJ_PlayerInfo[playerid][pBlackJackTutorialStep] + 1);
			return true;
		}
		switch (BJ_PlayerInfo[playerid][pBlackJackTutorialKey]) {
			case BLACKJACK_KEY_SPLIT: if (clickedid == Blackjack_TD[3]) blackjack_TutorialNextStep(playerid, (BJ_PlayerInfo[playerid][pBlackJackTutorialStep] + 1), 0);
			case BLACKJACK_KEY_HIT: if (clickedid == Blackjack_TD[4]) blackjack_TutorialNextStep(playerid, (BJ_PlayerInfo[playerid][pBlackJackTutorialStep] + 1), 0);
			case BLACKJACK_KEY_STAY: if (clickedid == Blackjack_TD[5]) blackjack_TutorialNextStep(playerid, (BJ_PlayerInfo[playerid][pBlackJackTutorialStep] + 1), 0);
		}
		if (clickedid == Blackjack_TD[0]) {
			if (BJ_PlayerInfo[playerid][pBlackJackTutorialStep]) {
				blackjack_StopTutorial(playerid);
			}
			else {
				SelectTextDraw(playerid, 0x000000FF);
				return ShowPlayerDialog(playerid, DIALOG_BLACKJACK_LEAVE, DIALOG_STYLE_MSGBOX, "{d8284c}Black Jack", "{FFFFFF}¬Gusrt datovot satamasho magida?", "Ki", "Gauqmeba"), true;
			}
			return true;
		}
		if (_:clickedid == INVALID_TEXT_DRAW) {
			return SelectTextDraw(playerid, 0x000000FF), true;
		}
		if (BJ_PlayerInfo[playerid][pBlackJackTutorialStep])
			return false;
		switch (BJ_PlayerInfo[playerid][pBlackJackOptions]) {
			case BLACKJACK_OPTION_MMBA: if (!TI[playerid][tDialog]) {
				if (clickedid == Blackjack_TD[2]) {
					ApplyAnimation(playerid, "CASINO", "cards_raise", 4.1, 0, 1, 1, 1, 1, 1);

					BJ_PlayerInfo[playerid][pBlackJackLastBet] =
					BJ_PlayerInfo[playerid][pBlackJackBet][BJ_PlayerInfo[playerid][pBlackJackBlockID]] = blackjackTableInfo[tableid][blackjackTableMinBet];
					return true;
				}
				else if (clickedid == Blackjack_TD[3]) {
					ApplyAnimation(playerid, "CASINO", "cards_raise", 4.1, 0, 1, 1, 1, 1, 1);

					BJ_PlayerInfo[playerid][pBlackJackLastBet] =
					BJ_PlayerInfo[playerid][pBlackJackBet][BJ_PlayerInfo[playerid][pBlackJackBlockID]] = blackjackTableInfo[tableid][blackjackTableMaxBet];
					return true;
				}
				else if (clickedid == Blackjack_TD[4]) {
					format(STRING_GLOBAL, sizeof(STRING_GLOBAL),
						"{FFFFFF}Sheiyvanet fsonis raodenoba {d8284c}(%d - %d){FFFFFF}:\n\ntqven gaqvt: {d8284c}%d fishka",
						blackjackTableInfo[tableid][blackjackTableMinBet], blackjackTableInfo[tableid][blackjackTableMaxBet], PI[playerid][pCasinoChips]
					);

					ShowPlayerDialog(playerid, DIALOG_BLACKJACK_BET, DIALOG_STYLE_INPUT, "{d8284c}Black Jack", STRING_GLOBAL, "Migeba", "Gamosvla"), STRING_GLOBAL[0] = EOS;
					return true;
				}
				else if (clickedid == Blackjack_TD[5]) {
					ApplyAnimation(playerid, "CASINO", "cards_raise", 4.1, 0, 1, 1, 1, 1, 1);

					BJ_PlayerInfo[playerid][pBlackJackBet][BJ_PlayerInfo[playerid][pBlackJackBlockID]] = BJ_PlayerInfo[playerid][pBlackJackLastBet];
					return true;
				}
			}
			case BLACKJACK_OPTION_DSHS: {
				if (clickedid == Blackjack_TD[2]) {
					blackjack_ActionDouble(playerid);
					return true;
				}
				else if (clickedid == Blackjack_TD[3] && BJ_PlayerInfo[playerid][pBlackJackSplit])  {
					if (BJ_PlayerInfo[playerid][pBlackJackCards][1] > 0 || BJ_PlayerInfo[playerid][pBlackJackCards][0] > 2)
						return false;
					blackjack_ActionSplit(playerid);
					return true;
				}
				else if (clickedid == Blackjack_TD[4]) {
					blackjack_ActionHit(playerid, BJ_PlayerInfo[playerid][pBlackJackBlockID]);
					return true;
				}
				else if (clickedid == Blackjack_TD[5]) {
					blackjack_ActionStay(playerid);
					return true;
				}
			}
		}

	}
	return false;
}
blackjack_UpdateOptions(playerid, option = BLACKJACK_OPTION_NONE) {
	if (playerid == INVALID_PLAYER_ID) return false;
	new tableid = (BJ_PlayerInfo[playerid][pBlackJackTableID] - 1);
	if (tableid == -1) return false;
	switch (option) {
		case BLACKJACK_OPTION_NONE: { //	(null)
			TextDrawHideForPlayer(playerid, Blackjack_TD[2]), PlayerTextDrawHide(playerid, Blackjack_PTD[playerid][4]);
			TextDrawHideForPlayer(playerid, Blackjack_TD[3]), PlayerTextDrawHide(playerid, Blackjack_PTD[playerid][5]);
			TextDrawHideForPlayer(playerid, Blackjack_TD[4]), PlayerTextDrawHide(playerid, Blackjack_PTD[playerid][6]);
			TextDrawHideForPlayer(playerid, Blackjack_TD[5]), PlayerTextDrawHide(playerid, Blackjack_PTD[playerid][7]);
		}
		case BLACKJACK_OPTION_MMBA: { //	MIN  MAX  (1-300)  300
			BJ_PlayerInfo[playerid][pBlackJackActiveID] = 1;

			new blackjack_string[18];
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][4], "~w~~h~MIN");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][5], "~w~~h~MAX");

			if (tableid != -1) {
				format(blackjack_string, sizeof(blackjack_string), "~w~~h~(%d-%d)",
					blackjackTableInfo[tableid][blackjackTableMinBet],
					blackjackTableInfo[tableid][blackjackTableMaxBet]
				);
				PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][6], blackjack_string);
			}
			if (BJ_PlayerInfo[playerid][pBlackJackLastBet])
				format(blackjack_string, sizeof(blackjack_string), "~w~%d", BJ_PlayerInfo[playerid][pBlackJackLastBet]);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][7], blackjack_string);

			if (BLACKJACK_OPTION_NONE == BJ_PlayerInfo[playerid][pBlackJackOptions]) {
				TextDrawShowForPlayer(playerid, Blackjack_TD[2]), PlayerTextDrawShow(playerid, Blackjack_PTD[playerid][4]);
				TextDrawShowForPlayer(playerid, Blackjack_TD[3]), PlayerTextDrawShow(playerid, Blackjack_PTD[playerid][5]);
				TextDrawShowForPlayer(playerid, Blackjack_TD[4]), PlayerTextDrawShow(playerid, Blackjack_PTD[playerid][6]);
				if (BJ_PlayerInfo[playerid][pBlackJackLastBet])
					TextDrawShowForPlayer(playerid, Blackjack_TD[5]), PlayerTextDrawShow(playerid, Blackjack_PTD[playerid][7]);
				else TextDrawHideForPlayer(playerid, Blackjack_TD[5]), PlayerTextDrawHide(playerid, Blackjack_PTD[playerid][7]);
			}
		}
		case BLACKJACK_OPTION_DSHS: { //	DOUBLE  SPLIT  HIT  STAY
			BJ_PlayerInfo[playerid][pBlackJackActiveID] = 1;
			if (BJ_PlayerInfo[playerid][pBlackJackCards][0] < 3 && BJ_PlayerInfo[playerid][pBlackJackCards][1] == 0)
				blackjack_CheckCards(playerid);

			if (BJ_PlayerInfo[playerid][pBlackJackCards][0] == 2)
				PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][4], "~w~~h~DOUBLE");
			else PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][4], "DOUBLE");

			if (BJ_PlayerInfo[playerid][pBlackJackSplit])
				PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][5], "~w~~h~SPLIT");
			else PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][5], "SPLIT");

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][6], "~w~~h~HIT");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][7], "~w~~h~STAY");

			if (BLACKJACK_OPTION_NONE == BJ_PlayerInfo[playerid][pBlackJackOptions]) {
				TextDrawShowForPlayer(playerid, Blackjack_TD[2]), PlayerTextDrawShow(playerid, Blackjack_PTD[playerid][4]);
				TextDrawShowForPlayer(playerid, Blackjack_TD[3]), PlayerTextDrawShow(playerid, Blackjack_PTD[playerid][5]);
				TextDrawShowForPlayer(playerid, Blackjack_TD[4]), PlayerTextDrawShow(playerid, Blackjack_PTD[playerid][6]);
				TextDrawShowForPlayer(playerid, Blackjack_TD[5]), PlayerTextDrawShow(playerid, Blackjack_PTD[playerid][7]);
			}
		}
		default: return true;
	}
	return (BJ_PlayerInfo[playerid][pBlackJackOptions] = option);
}
blackjack_CreateTable(Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid) {
	if (Iter_Count(blackjackTables) >= MAX_BLACKJACK_TABLES)
		return false;
	new tableid = Iter_Free(blackjackTables), objectid;

	objectid = blackjackTableInfo[tableid][blackjackTableObjectID] = CreateDynamicObject(2188,
		(blackjackTableInfo[tableid][blackjackTablePos][0] = x), (blackjackTableInfo[tableid][blackjackTablePos][1] = y),
		(blackjackTableInfo[tableid][blackjackTablePos][2] = z), (blackjackTableInfo[tableid][blackjackTablePos][3] = rx),
		(blackjackTableInfo[tableid][blackjackTablePos][4] = ry), (blackjackTableInfo[tableid][blackjackTablePos][5] = rz),
		(blackjackTableInfo[tableid][blackjackTableWorld] = worldid), (blackjackTableInfo[tableid][blackjackTableInterior] = interiorid), (-1)
	);
	blackjackTableInfo[tableid][blackjackTableAreaID] = CreateDynamicSphere(
	   	blackjackTableInfo[tableid][blackjackTablePos][0], blackjackTableInfo[tableid][blackjackTablePos][1], blackjackTableInfo[tableid][blackjackTablePos][2],
	   	2.0, blackjackTableInfo[tableid][blackjackTableWorld], blackjackTableInfo[tableid][blackjackTableInterior], -1
   	);
   	blackjackTableInfo[tableid][blackjackTableTextID] = CreateDynamic3DTextLabel("{d8284c}Black Jack\n \n{FFFFFF}Daachiret {d8284c}\"ENTER\"", -1,
		blackjackTableInfo[tableid][blackjackTablePos][0], blackjackTableInfo[tableid][blackjackTablePos][1], blackjackTableInfo[tableid][blackjackTablePos][2] + 0.9, 5.0,
		INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 1, blackjackTableInfo[tableid][blackjackTableWorld], blackjackTableInfo[tableid][blackjackTableInterior], -1
	);
    Iter_Add(blackjackTables, tableid);

	new Float:object_px, Float:object_py, Float:object_pz,
        Float:object_rx, Float:object_ry, Float:object_rz;

    GetDynamicObjectPos(objectid, object_px, object_py, object_pz);
    GetDynamicObjectRot(objectid, object_rx, object_ry, object_rz);

    new Float:cos_x = floatcos(object_rx, degrees),
        Float:cos_y = floatcos(object_ry, degrees),
        Float:cos_z = floatcos(object_rz, degrees),
        Float:sin_x = floatsin(object_rx, degrees),
        Float:sin_y = floatsin(object_ry, degrees),
        Float:sin_z = floatsin(object_rz, degrees)
    ;
    x = object_px + blackjack_TableOffsets[3][0] * cos_y * cos_z - blackjack_TableOffsets[3][0] * sin_x * sin_y * sin_z - blackjack_TableOffsets[3][1] * cos_x * sin_z + blackjack_TableOffsets[3][2] * sin_y * cos_z + blackjack_TableOffsets[3][2] * sin_x * cos_y * sin_z;
    y = object_py + blackjack_TableOffsets[3][0] * cos_y * sin_z + blackjack_TableOffsets[3][0] * sin_x * sin_y * cos_z + blackjack_TableOffsets[3][1] * cos_x * cos_z + blackjack_TableOffsets[3][2] * sin_y * sin_z - blackjack_TableOffsets[3][2] * sin_x * cos_y * cos_z;
    z = object_pz - blackjack_TableOffsets[3][0] * cos_x * sin_y + blackjack_TableOffsets[3][1] * sin_x + blackjack_TableOffsets[3][2] * cos_x * cos_y;

	blackjackTableInfo[tableid][blackjackTableActorID] = AI_CreateActor(171,
		x, y, z, (blackjack_TableOffsets[3][3] + object_rz), worldid, interiorid
	);
	blackjack_ResetTable(tableid);
	return (tableid + 1);
}
stock blackjack_CreateTD() {
	Blackjack_TD[0] = TextDrawCreate(560.0, 400.5, "click_exit");
	TextDrawTextSize(Blackjack_TD[0], 79.000000, 48.000000);
	TextDrawAlignment(Blackjack_TD[0], 1);
	TextDrawColor(Blackjack_TD[0], 336860415);
	TextDrawSetShadow(Blackjack_TD[0], 0);
	TextDrawFont(Blackjack_TD[0], 5);
	TextDrawSetProportional(Blackjack_TD[0], 0);
	TextDrawBackgroundColor(Blackjack_TD[0], 0);
	TextDrawSetSelectable(Blackjack_TD[0], true);
	TextDrawSetPreviewModel(Blackjack_TD[0], 10955);
	TextDrawSetPreviewRot(Blackjack_TD[0], 90.000000, 0.000000, 0.000000, 0.828445);

	Blackjack_TD[1] = TextDrawCreate(600.629699, 418.066802, "~p~EXIT");
	TextDrawLetterSize(Blackjack_TD[1], 0.477306, 2.002500);
	TextDrawAlignment(Blackjack_TD[1], 2);
	TextDrawColor(Blackjack_TD[1], -1400377345);
	TextDrawSetShadow(Blackjack_TD[1], 0);
	TextDrawSetOutline(Blackjack_TD[1], 1);
	TextDrawBackgroundColor(Blackjack_TD[1], 255);
	TextDrawFont(Blackjack_TD[1], 1);
	TextDrawSetProportional(Blackjack_TD[1], 1);

	Blackjack_TD[2] = TextDrawCreate(179.797958, 392.23, "click_1");
	Blackjack_TD[3] = TextDrawCreate(247.297805, 392.23, "click_2");
	Blackjack_TD[4] = TextDrawCreate(315.797729, 392.23, "click_3");
	Blackjack_TD[5] = TextDrawCreate(384.297729, 392.23, "click_4");

	for (new td_id = 2; td_id < 6; td_id++) { 
		TextDrawTextSize(Blackjack_TD[td_id], 75.000000, 39.000000);
		TextDrawAlignment(Blackjack_TD[td_id], 1);
		TextDrawColor(Blackjack_TD[td_id], 168430320);
		TextDrawSetShadow(Blackjack_TD[td_id], 0);
		TextDrawFont(Blackjack_TD[td_id], 5);
		TextDrawSetProportional(Blackjack_TD[td_id], 0);
		TextDrawBackgroundColor(Blackjack_TD[td_id], 0);
		TextDrawSetSelectable(Blackjack_TD[td_id], true);
		TextDrawSetPreviewModel(Blackjack_TD[td_id], 10955);
		TextDrawSetPreviewRot(Blackjack_TD[td_id], 90.000000, 0.000000, 0.000000, 1.000000);
	}
	Blackjack_Tutorial_TD[0] = TextDrawCreate(22.942874, 346.716857, "title_bg");
	TextDrawLetterSize(Blackjack_Tutorial_TD[0], 0.000000, 9.109807);
	TextDrawTextSize(Blackjack_Tutorial_TD[0], 172.000000, 0.000000);
	TextDrawAlignment(Blackjack_Tutorial_TD[0], 1);
	TextDrawColor(Blackjack_Tutorial_TD[0], -1);
	TextDrawUseBox(Blackjack_Tutorial_TD[0], 1);
	TextDrawBoxColor(Blackjack_Tutorial_TD[0], 336860415);
	TextDrawSetShadow(Blackjack_Tutorial_TD[0], 0);
	TextDrawBackgroundColor(Blackjack_Tutorial_TD[0], 255);
	TextDrawFont(Blackjack_Tutorial_TD[0], 1);
	TextDrawSetProportional(Blackjack_Tutorial_TD[0], 1);

	Blackjack_Tutorial_TD[1] = TextDrawCreate(61.992675, 414.550170, "~w~<< ~w~~h~START");
	TextDrawLetterSize(Blackjack_Tutorial_TD[1], 0.219619, 1.214998);
	TextDrawTextSize(Blackjack_Tutorial_TD[1], 10.000000, 73.000000);
	TextDrawAlignment(Blackjack_Tutorial_TD[1], 2);
	TextDrawColor(Blackjack_Tutorial_TD[1], -1);
	TextDrawUseBox(Blackjack_Tutorial_TD[1], 1);
	TextDrawBoxColor(Blackjack_Tutorial_TD[1], -1523963137);
	TextDrawSetShadow(Blackjack_Tutorial_TD[1], 0);
	TextDrawBackgroundColor(Blackjack_Tutorial_TD[1], 255);
	TextDrawFont(Blackjack_Tutorial_TD[1], 1);
	TextDrawSetProportional(Blackjack_Tutorial_TD[1], 1);
	TextDrawSetSelectable(Blackjack_Tutorial_TD[1], true);

	Blackjack_Tutorial_TD[2] = TextDrawCreate(132.992675, 414.550170, "~w~>> ~w~~h~NEXT");
	TextDrawLetterSize(Blackjack_Tutorial_TD[2], 0.219619, 1.214998);
	TextDrawTextSize(Blackjack_Tutorial_TD[2], 10.000000, 73.000000);
	TextDrawAlignment(Blackjack_Tutorial_TD[2], 2);
	TextDrawColor(Blackjack_Tutorial_TD[2], -1);
	TextDrawUseBox(Blackjack_Tutorial_TD[2], 1);
	TextDrawBoxColor(Blackjack_Tutorial_TD[2], 8388863);
	TextDrawSetShadow(Blackjack_Tutorial_TD[2], 0);
	TextDrawBackgroundColor(Blackjack_Tutorial_TD[2], 255);
	TextDrawFont(Blackjack_Tutorial_TD[2], 1);
	TextDrawSetProportional(Blackjack_Tutorial_TD[2], 1);
	TextDrawSetSelectable(Blackjack_Tutorial_TD[2], true);

	Blackjack_Tutorial_TD[3] = TextDrawCreate(97.469276, 331.300262, "STOP");
	TextDrawLetterSize(Blackjack_Tutorial_TD[3], 0.302547, 1.343333);
	TextDrawTextSize(Blackjack_Tutorial_TD[3], 0.000000, 149.500000);
	TextDrawAlignment(Blackjack_Tutorial_TD[3], 2);
	TextDrawColor(Blackjack_Tutorial_TD[3], -1);
	TextDrawUseBox(Blackjack_Tutorial_TD[3], 1);
	TextDrawBoxColor(Blackjack_Tutorial_TD[3], -1523963166);
	TextDrawSetShadow(Blackjack_Tutorial_TD[3], 0);
	TextDrawBackgroundColor(Blackjack_Tutorial_TD[3], 255);
	TextDrawFont(Blackjack_Tutorial_TD[3], 1);
	TextDrawSetProportional(Blackjack_Tutorial_TD[3], 1);
}
blackjack_CreatePTD(playerid, seatid) {
	new Float:blackjack_ptd_float[MAX_BLACKJACK_SEATS][2] = {
			{320.0, 346.0}, {110.0, 290.0}, {536.0, 290.0}
		},
		language_id = BJ_PlayerInfo[playerid][pBlackJackLanguage]
	;
	Blackjack_PTD[playerid][0] = CreatePlayerTextDraw(playerid, blackjack_ptd_float[0][0], blackjack_ptd_float[0][1], "_"); // Monsieur~n~Developer~n~~p~1,000
	Blackjack_PTD[playerid][1] = CreatePlayerTextDraw(playerid, blackjack_ptd_float[1][0], blackjack_ptd_float[1][1], "_"); // Monsieur~n~Developer~n~~p~1,000
	Blackjack_PTD[playerid][2] = CreatePlayerTextDraw(playerid, blackjack_ptd_float[2][0], blackjack_ptd_float[2][1], "_"); // Monsieur~n~Developer~n~~p~1,000

	for (new ptd_id = 0; ptd_id < 3; ptd_id++) {
		PlayerTextDrawLetterSize(playerid, Blackjack_PTD[playerid][ptd_id], 0.189631, 0.940832);
		PlayerTextDrawTextSize(playerid, Blackjack_PTD[playerid][ptd_id], 0.000000, 61.000000);
		PlayerTextDrawAlignment(playerid, Blackjack_PTD[playerid][ptd_id], 2);
		PlayerTextDrawColor(playerid, Blackjack_PTD[playerid][ptd_id], -1);
		PlayerTextDrawUseBox(playerid, Blackjack_PTD[playerid][ptd_id], 1);
		PlayerTextDrawBoxColor(playerid, Blackjack_PTD[playerid][ptd_id], 168430335);
		PlayerTextDrawSetShadow(playerid, Blackjack_PTD[playerid][ptd_id], 0);
		PlayerTextDrawSetOutline(playerid, Blackjack_PTD[playerid][ptd_id], 1);
		PlayerTextDrawBackgroundColor(playerid, Blackjack_PTD[playerid][ptd_id], 255);
		PlayerTextDrawFont(playerid, Blackjack_PTD[playerid][ptd_id], 1);
		PlayerTextDrawSetProportional(playerid, Blackjack_PTD[playerid][ptd_id], 1);
	}
	Blackjack_PTD[playerid][3] = CreatePlayerTextDraw(playerid,
		(blackjack_ptd_float[seatid][0] + 34.42456), (blackjack_ptd_float[seatid][1] + 25.416534), blackjack_language_massive[language_id][5]
	);
	PlayerTextDrawLetterSize(playerid, Blackjack_PTD[playerid][3], 0.178856, 0.894164);
	PlayerTextDrawTextSize(playerid, Blackjack_PTD[playerid][3], 0.000000, 12.000000);
	PlayerTextDrawAlignment(playerid, Blackjack_PTD[playerid][3], 2);
	PlayerTextDrawColor(playerid, Blackjack_PTD[playerid][3], -1);
	PlayerTextDrawUseBox(playerid, Blackjack_PTD[playerid][3], 1);
	PlayerTextDrawBoxColor(playerid, Blackjack_PTD[playerid][3], -2139094785);
	PlayerTextDrawSetShadow(playerid, Blackjack_PTD[playerid][3], 0);
	PlayerTextDrawBackgroundColor(playerid, Blackjack_PTD[playerid][3], 255);
	PlayerTextDrawFont(playerid, Blackjack_PTD[playerid][3], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack_PTD[playerid][3], 1);

	Blackjack_PTD[playerid][4] = CreatePlayerTextDraw(playerid, 218.368286, 407.250030, "_");
	Blackjack_PTD[playerid][5] = CreatePlayerTextDraw(playerid, 284.081756, 407.250000, "_");
	Blackjack_PTD[playerid][6] = CreatePlayerTextDraw(playerid, 353.423278, 407.250030, "_");
	Blackjack_PTD[playerid][7] = CreatePlayerTextDraw(playerid, 421.358795, 407.250000, "_");

	for (new ptd_id = 4; ptd_id < 8; ptd_id++) {
		PlayerTextDrawLetterSize(playerid, Blackjack_PTD[playerid][ptd_id], 0.300000, 1.399999);
		PlayerTextDrawAlignment(playerid, Blackjack_PTD[playerid][ptd_id], 2);
		PlayerTextDrawColor(playerid, Blackjack_PTD[playerid][ptd_id], -2139062017); // -1
		PlayerTextDrawSetShadow(playerid, Blackjack_PTD[playerid][ptd_id], 0);
		PlayerTextDrawBackgroundColor(playerid, Blackjack_PTD[playerid][ptd_id], 255);
		PlayerTextDrawFont(playerid, Blackjack_PTD[playerid][ptd_id], 1);
		PlayerTextDrawSetProportional(playerid, Blackjack_PTD[playerid][ptd_id], 1);
	}
	Blackjack_PTD[playerid][8] = CreatePlayerTextDraw(playerid, 280.000000, 316.000000, "_");
	Blackjack_PTD[playerid][9] = CreatePlayerTextDraw(playerid, 71.000000, 262.500000, "_");
	Blackjack_PTD[playerid][10] = CreatePlayerTextDraw(playerid, 496.000000, 262.500000, "_");

	for (new ptd_id = 8; ptd_id < 11; ptd_id++) {
		PlayerTextDrawLetterSize(playerid, Blackjack_PTD[playerid][ptd_id], 0.176045, 0.870832);
		PlayerTextDrawTextSize(playerid, Blackjack_PTD[playerid][ptd_id], 0.000000, 47.000000);
		PlayerTextDrawAlignment(playerid, Blackjack_PTD[playerid][ptd_id], 2);
		PlayerTextDrawColor(playerid, Blackjack_PTD[playerid][ptd_id], 255);
		PlayerTextDrawSetShadow(playerid, Blackjack_PTD[playerid][ptd_id], 0);
		PlayerTextDrawSetOutline(playerid, Blackjack_PTD[playerid][ptd_id], 1);
		PlayerTextDrawBackgroundColor(playerid, Blackjack_PTD[playerid][ptd_id], 255);
		PlayerTextDrawFont(playerid, Blackjack_PTD[playerid][ptd_id], 1);
		PlayerTextDrawSetProportional(playerid, Blackjack_PTD[playerid][ptd_id], 1);
	} // player hands

	// seatid = 1 [1] * center
	Blackjack_PTD[playerid][11] = CreatePlayerTextDraw(playerid, 249.233200, 240.233398, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][12] = CreatePlayerTextDraw(playerid, 267.233062, 244.233337, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][13] = CreatePlayerTextDraw(playerid, 285.233123, 248.233367, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][14] = CreatePlayerTextDraw(playerid, 259.232971, 270.233123, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][15] = CreatePlayerTextDraw(playerid, 277.233062, 274.233123, "_"); // "LD_CARD:cdback");
	// seatid = 1 [2] * center
	Blackjack_PTD[playerid][16] = CreatePlayerTextDraw(playerid, 327.932128, 240.333389, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][17] = CreatePlayerTextDraw(playerid, 345.932586, 244.333374, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][18] = CreatePlayerTextDraw(playerid, 363.933990, 248.333374, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][19] = CreatePlayerTextDraw(playerid, 337.931945, 270.333129, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][20] = CreatePlayerTextDraw(playerid, 355.933349, 274.233123, "_"); // "LD_CARD:cdback");
	// seatid = 2 [1] * left
	Blackjack_PTD[playerid][21] = CreatePlayerTextDraw(playerid, 39.804260, 185.983444, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][22] = CreatePlayerTextDraw(playerid, 57.804054, 189.983444, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][23] = CreatePlayerTextDraw(playerid, 75.804084, 193.983444, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][24] = CreatePlayerTextDraw(playerid, 49.804023, 215.983367, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][25] = CreatePlayerTextDraw(playerid, 67.804054, 219.983337, "_"); // "LD_CARD:cdback");
	// seatid = 2 [2] * left
	Blackjack_PTD[playerid][26] = CreatePlayerTextDraw(playerid, 118.503059, 186.083450, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][27] = CreatePlayerTextDraw(playerid, 136.503509, 190.083450, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][28] = CreatePlayerTextDraw(playerid, 154.504913, 194.083450, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][29] = CreatePlayerTextDraw(playerid, 128.502868, 216.083374, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][30] = CreatePlayerTextDraw(playerid, 146.504272, 219.983337, "_"); // "LD_CARD:cdback");
	// seatid = 3 [1] * right
	Blackjack_PTD[playerid][31] = CreatePlayerTextDraw(playerid, 465.223480, 185.983444, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][32] = CreatePlayerTextDraw(playerid, 483.224670, 189.983444, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][33] = CreatePlayerTextDraw(playerid, 501.226074, 193.983444, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][34] = CreatePlayerTextDraw(playerid, 475.224029, 215.983367, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][35] = CreatePlayerTextDraw(playerid, 493.225433, 219.983337, "_"); // "LD_CARD:cdback");
	// seatid = 3 [2] * right
	Blackjack_PTD[playerid][36] = CreatePlayerTextDraw(playerid, 543.918518, 186.083450, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][37] = CreatePlayerTextDraw(playerid, 561.914245, 190.083450, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][38] = CreatePlayerTextDraw(playerid, 579.910156, 194.083450, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][39] = CreatePlayerTextDraw(playerid, 553.916015, 216.083374, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][40] = CreatePlayerTextDraw(playerid, 571.911926, 219.983337, "_"); // "LD_CARD:cdback");
	// seatid = dealer * top center
	Blackjack_PTD[playerid][41] = CreatePlayerTextDraw(playerid, 257.640502, 125.216728, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][42] = CreatePlayerTextDraw(playerid, 283.877990, 125.216728, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][43] = CreatePlayerTextDraw(playerid, 310.115264, 125.216728, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][44] = CreatePlayerTextDraw(playerid, 336.352600, 125.216720, "_"); // "LD_CARD:cdback");
	Blackjack_PTD[playerid][45] = CreatePlayerTextDraw(playerid, 362.589904, 125.216720, "_"); // "LD_CARD:cdback");

	for (new ptd_id = 11; ptd_id < 46; ptd_id++) {
		PlayerTextDrawTextSize(playerid, Blackjack_PTD[playerid][ptd_id], 25.000000, 40.000000);
		PlayerTextDrawAlignment(playerid, Blackjack_PTD[playerid][ptd_id], 1);
		PlayerTextDrawColor(playerid, Blackjack_PTD[playerid][ptd_id], -1);
		PlayerTextDrawSetShadow(playerid, Blackjack_PTD[playerid][ptd_id], 0);
		PlayerTextDrawBackgroundColor(playerid, Blackjack_PTD[playerid][ptd_id], 255);
		PlayerTextDrawFont(playerid, Blackjack_PTD[playerid][ptd_id], 4);
		PlayerTextDrawSetProportional(playerid, Blackjack_PTD[playerid][ptd_id], 0);
	}
	// seatid = 1 [1] * center
	Blackjack_PTD[playerid][46] = CreatePlayerTextDraw(playerid, 280.507141, 220.500000/* - 6.0*/, "_"); // 21
	Blackjack_PTD[playerid][47] = CreatePlayerTextDraw(playerid, 358.750244, 220.500000/* - 6.0*/, "_"); // 21
	// seatid = 2 [1] * left
	Blackjack_PTD[playerid][48] = CreatePlayerTextDraw(playerid, 71.200607, 166.500000/* - 6.0*/, "_"); // 21
	Blackjack_PTD[playerid][49] = CreatePlayerTextDraw(playerid, 149.789825, 166.500000/* - 6.0*/, "_"); // 21
	// seatid = 3 [1] * right
	Blackjack_PTD[playerid][50] = CreatePlayerTextDraw(playerid, 495.558532, 166.500000/* - 6.0*/, "_"); // 21
	Blackjack_PTD[playerid][51] = CreatePlayerTextDraw(playerid, 575.207336, 166.500000/* - 6.0*/, "_"); // 21
	// seatid = dealer * top center
	Blackjack_PTD[playerid][52] = CreatePlayerTextDraw(playerid, 324.079559, 106.900000 - 6.0, "_"); // 21

	for (new ptd_id = 46; ptd_id < 53; ptd_id++) {
		PlayerTextDrawLetterSize(playerid, Blackjack_PTD[playerid][ptd_id], 0.265534, 1.104166);
		PlayerTextDrawTextSize(playerid, Blackjack_PTD[playerid][ptd_id], 0.000000, 59.000000);
		PlayerTextDrawAlignment(playerid, Blackjack_PTD[playerid][ptd_id], 2);
		PlayerTextDrawColor(playerid, Blackjack_PTD[playerid][ptd_id], -1);
		PlayerTextDrawSetShadow(playerid, Blackjack_PTD[playerid][ptd_id], 0);
		PlayerTextDrawSetOutline(playerid, Blackjack_PTD[playerid][ptd_id], 1);
		PlayerTextDrawBackgroundColor(playerid, Blackjack_PTD[playerid][ptd_id], 255);
		PlayerTextDrawFont(playerid, Blackjack_PTD[playerid][ptd_id], 1);
		PlayerTextDrawSetProportional(playerid, Blackjack_PTD[playerid][ptd_id], 1);
	}
	Blackjack_PTD[playerid][53] = CreatePlayerTextDraw(playerid, 320.000000, 168.000000, "_");
	PlayerTextDrawLetterSize(playerid, Blackjack_PTD[playerid][53], 0.227115, 0.987499);
	PlayerTextDrawTextSize(playerid, Blackjack_PTD[playerid][53], 0.000000, 160.000000);
	PlayerTextDrawAlignment(playerid, Blackjack_PTD[playerid][53], 2);
	PlayerTextDrawColor(playerid, Blackjack_PTD[playerid][53], -1);
	PlayerTextDrawSetShadow(playerid, Blackjack_PTD[playerid][53], 0);
	PlayerTextDrawSetOutline(playerid, Blackjack_PTD[playerid][53], 1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack_PTD[playerid][53], 255);
	PlayerTextDrawFont(playerid, Blackjack_PTD[playerid][53], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack_PTD[playerid][53], 1);

	Blackjack_PTD[playerid][54] = CreatePlayerTextDraw(playerid, 320.000000, 386.099639, blackjack_language_massive[language_id][6]);
	PlayerTextDrawLetterSize(playerid, Blackjack_PTD[playerid][54], 0.228989, 1.004999);
	PlayerTextDrawTextSize(playerid, Blackjack_PTD[playerid][54], 0.000000, 81.000000);
	PlayerTextDrawAlignment(playerid, Blackjack_PTD[playerid][54], 2);
	PlayerTextDrawColor(playerid, Blackjack_PTD[playerid][54], -1);
	PlayerTextDrawUseBox(playerid, Blackjack_PTD[playerid][54], 1);
	PlayerTextDrawBoxColor(playerid, Blackjack_PTD[playerid][54], -1523963137);
	PlayerTextDrawSetShadow(playerid, Blackjack_PTD[playerid][54], 0);
	PlayerTextDrawBackgroundColor(playerid, Blackjack_PTD[playerid][54], 255);
	PlayerTextDrawFont(playerid, Blackjack_PTD[playerid][54], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack_PTD[playerid][54], 1);

	Blackjack_PTD[playerid][55] = CreatePlayerTextDraw(playerid, 359.000000, 316.000000, "_");
	Blackjack_PTD[playerid][56] = CreatePlayerTextDraw(playerid, 150.000000, 262.500000, "_");
	Blackjack_PTD[playerid][57] = CreatePlayerTextDraw(playerid, 575.000000, 262.500000, "_");

	for (new ptd_id = 55; ptd_id < 58; ptd_id++) {
		PlayerTextDrawLetterSize(playerid, Blackjack_PTD[playerid][ptd_id], 0.176045, 0.870832);
		PlayerTextDrawTextSize(playerid, Blackjack_PTD[playerid][ptd_id], 0.000000, 47.000000);
		PlayerTextDrawAlignment(playerid, Blackjack_PTD[playerid][ptd_id], 2);
		PlayerTextDrawColor(playerid, Blackjack_PTD[playerid][ptd_id], 255);
		PlayerTextDrawSetShadow(playerid, Blackjack_PTD[playerid][ptd_id], 0);
		PlayerTextDrawSetOutline(playerid, Blackjack_PTD[playerid][ptd_id], 1);
		PlayerTextDrawBackgroundColor(playerid, Blackjack_PTD[playerid][ptd_id], 255);
		PlayerTextDrawFont(playerid, Blackjack_PTD[playerid][ptd_id], 1);
		PlayerTextDrawSetProportional(playerid, Blackjack_PTD[playerid][ptd_id], 1);
	}
	Blackjack_Tutorial_PTD[playerid] = CreatePlayerTextDraw(playerid, 24.992675, 349.550140, "_");
	PlayerTextDrawLetterSize(playerid, Blackjack_Tutorial_PTD[playerid], 0.206496, 1.109997);
	PlayerTextDrawTextSize(playerid, Blackjack_Tutorial_PTD[playerid], 155.000000, 0.000000);
	PlayerTextDrawAlignment(playerid, Blackjack_Tutorial_PTD[playerid], 1);
	PlayerTextDrawColor(playerid, Blackjack_Tutorial_PTD[playerid], -1);
	PlayerTextDrawSetShadow(playerid, Blackjack_Tutorial_PTD[playerid], 0);
	PlayerTextDrawSetOutline(playerid, Blackjack_Tutorial_PTD[playerid], 1);
	PlayerTextDrawBackgroundColor(playerid, Blackjack_Tutorial_PTD[playerid], 255);
	PlayerTextDrawFont(playerid, Blackjack_Tutorial_PTD[playerid], 1);
	PlayerTextDrawSetProportional(playerid, Blackjack_Tutorial_PTD[playerid], 1);

	BJ_PlayerInfo[playerid][pBlackJackGUI] = 1;
}
blackjack_OnGameModeInit() {
	blackjack_CreateTD();

	new worldid = CASINO_WORLD_ID;
	blackjack_CreateTable(
		1978.076171, 1726.402832, 1200.613, 0.0, 0.0, 180.0,
		.worldid = (worldid + 1), .interiorid = CASINO_INTERIOR_ID
	);
	blackjack_CreateTable(
		1978.076171, 1726.402832, 1200.613, 0.0, 0.0, 180.0,
		.worldid = worldid, .interiorid = CASINO_INTERIOR_ID
	);
	blackjack_CreateTable(
		1974.146240, 1726.402832, 1200.613, 0.0, 0.0, 180.0,
		.worldid = worldid, .interiorid = CASINO_INTERIOR_ID
	);
	worldid = CASINO_WORLD_ID + 2; 

	blackjack_CreateTable(
		1978.076171, 1726.402832, 1200.613, 0.0, 0.0, 180.0,
		.worldid = (worldid + 1), .interiorid = CASINO_INTERIOR_ID
	);
	blackjack_CreateTable(
		1978.076171, 1726.402832, 1200.613, 0.0, 0.0, 180.0,
		.worldid = worldid, .interiorid = CASINO_INTERIOR_ID
	);
	blackjack_CreateTable(
		1974.146240, 1726.402832, 1200.613, 0.0, 0.0, 180.0,
		.worldid = worldid, .interiorid = CASINO_INTERIOR_ID
	);
}

stock blackjack_TutorialNextStep(playerid, step = 1, from_next_key = 1) {
	if (!step) step = 1;

	new
		blackjack_td_score_array[MAX_BLACKJACK_SEATS + 1] = {
			46/* (46 - 47) */,
			48/* (48 - 49) */,
			50/* (50 - 51) */,
			52/* (56_dealer) */
		},
		blackjack_td_seats_array[MAX_BLACKJACK_SEATS + 1] = {
			11/* (11-15_s1-1) */, //16/* (16-20_s1-1) */,
			21/* (21-25_s1-1) */, //26/* (26-30_s1-1) */,
			31/* (31-35_s1-1) */, //36/* (36-40_s1-1) */,
			41/* (41-45_dealer) */
		},
		slots_id[2] = {0, 3}
	;
	switch (step) {
		case 1: {
			blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_NONE);

			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~w~tamasshi monawileobs ~y~1-3 motamashemde~w~.~n~\
				yvela motamashe kribavs kartebis kombinaciebs.~n~\
				tamashi midis dileris winaagmdeg.")
			);
			BJ_PlayerInfo[playerid][pBlackJackTutorialKey] = 0;
		}
		case 2: {
			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~w~moigebs is, visac eqneba meti qula, vidre dilers aqvs. ~n~\
				tu jamshi gamodis ~y~21 qula~w~, mashin fsoni ~r~wamgebia~w~.")
			);
		}
		case 3: {
			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~w~kartebi ~y~2-9 mde ~w~itvleba nominalit, kartis miuxedavad. ~n~\
				~y~oriani ~w~- ~g~2 qula~w~, ~y~samiani ~w~- ~g~3 qula ~w~da ase shemdeg.")
			);
		}
		case 4: {
			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~y~atiani da naxatebiani ~w~- ~g~10 qula~w~. ~y~tuzi ~w~- ~g~11 qula~w~.")
			);
		}
		case 5: {
			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"gadavidet damatebit shesadzleblobebze.")
			);
		}
		case 6: {
			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~y~SPLIT ~w~- tu motamashem miigo erti da igive nominalis karti, ~n~\
				~w~mas sheudzlia isini gayos, ris shedegadac fsoni izrdeba orjer.")
			);
		}
		case 7: {
			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~w~yoveli gayofili karti - gadzlevt axali kombinaciis dasawyiss, ~n~\
				~w~mattan rigdeba +1 karti xolo ukve 2 xelze. ~n~\
				~w~gamonaklisi - ~y~tuzebi~w~.")
			);
		}
		case 8: {
			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~y~DOUBLE ~w~- \"gaormageba\", mimdinare fsonis gaormageba, ~n~\
				~w~amis dros savaldebulod chadis mxolo 1 karti.")
			);
		}
		case 9: {
			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~y~HIT ~w~- \"kide\", kide erti kartis ageba. ~n~\
				~y~STAY ~w~- \"gamotoveba\", svlis gamotoveba.")
			);
		}
		case 10: {
			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"Ki‚‡ÈÚÂ ÔÂÂÈ‰ÂÏ Û Ë„Â.")
			);
			blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_NONE);

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][0], "_");
			PlayerTextDrawHide(playerid, Blackjack_PTD[playerid][0]);
		}
		case 11: {
			new player_Name[MAX_PLAYER_NAME + 24];
			strmid(player_Name, GetName(playerid), 0, MAX_PLAYER_NAME + 1);
			strreplace(player_Name, "_", "~n~~g~~h~");
			format(player_Name, sizeof(player_Name), "~g~~h~%s~n~~p~%d", player_Name, 1000);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][0], player_Name), player_Name[0] = EOS;
			PlayerTextDrawShow(playerid, Blackjack_PTD[playerid][0]);

			blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_MMBA);

			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~w~œÂÂ‰ Ì‡˜‡ÎÓÏ Ë„˚, Ë„ÓÍË ‚ÌÓÒˇÚ Ò‚ÓË ~y~ÒÚ‡‚ÍË~w~.")
			);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[1]] + 0], "_");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[1]] + 1], "_");

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[0]] + 0], "_");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[0]] + 1], "_");

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[slots_id[0]]], "_");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[slots_id[1]]], "_");

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][8], "_");
		}
		case 12: {
			new player_Name[MAX_PLAYER_NAME + 24];
			strmid(player_Name, GetName(playerid), 0, MAX_PLAYER_NAME + 1);
			strreplace(player_Name, "_", "~n~~g~~h~");
			format(player_Name, sizeof(player_Name), "~g~~h~%s~n~~p~%d", player_Name, 700);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][0], player_Name), player_Name[0] = EOS;

			blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_NONE);

			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~w~Shemdeg dilers da motamasheebs urigdeba ~y~2 karti~w~. ~n~\
				amis dros ~y~erti dileris karta ~w~imaleba.")
			);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[slots_id[0]]], "~y~16");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[slots_id[1]]], "~y~9");

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[1]] + 0], "LD_CARD:cd9c");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[1]] + 1], "LD_CARD:cdback");

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[0]] + 0], "LD_CARD:cd8c");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[0]] + 1], "LD_CARD:cd8d");

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][8], "~g~READY~n~~p~300");
		}
		case 13: {
			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~w~Shemdeg rig rigobit aketeben ~y~svlebs~w~.")
			);
			BJ_PlayerInfo[playerid][pBlackJackSplit] = 1;

			blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_NONE);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][8], "~g~READY~n~~p~300");
		}
		case 14: {
			new player_Name[MAX_PLAYER_NAME + 24];
			strmid(player_Name, GetName(playerid), 0, MAX_PLAYER_NAME + 1);
			strreplace(player_Name, "_", "~n~~g~~h~");
			format(player_Name, sizeof(player_Name), "~g~~h~%s~n~~p~%d", player_Name, 700);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][0], player_Name), player_Name[0] = EOS;

			ApplyAnimation(playerid, "CASINO", "cards_loop", 4.1, 0, 1, 1, 1, 1, 1);

			blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_DSHS);

			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~w~Tqvenj mogces erti da igive nominalis karti, tqven ~n~\
				shegidzliat gayot isini da gaaormagot fsoni ~y~SPLIT~w~.")
			);
			BJ_PlayerInfo[playerid][pBlackJackTutorialKey] = BLACKJACK_KEY_SPLIT;

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[slots_id[0]] + 0], "~y~16");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[slots_id[0]] + 1], "_");

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][8], "~r~00:30~n~~p~300");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][55], "_");
		}
		case 15: {
			new player_Name[MAX_PLAYER_NAME + 24];
			strmid(player_Name, GetName(playerid), 0, MAX_PLAYER_NAME + 1);
			strreplace(player_Name, "_", "~n~~g~~h~");
			format(player_Name, sizeof(player_Name), "~g~~h~%s~n~~p~%d", player_Name, 400);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][0], player_Name), player_Name[0] = EOS;

			if (from_next_key) return;

			ApplyAnimation(playerid, "CASINO", "cards_raise", 4.1, 0, 1, 1, 1, 1, 1);

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[0] + 0] + 0], "LD_CARD:cd8c");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[0] + 0] + 1], "LD_CARD:cd3h");

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[0]] + 5 + 0], "LD_CARD:cd8d");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[0]] + 5 + 1], "LD_CARD:cd9s");

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[slots_id[0]] + 0], "~y~11");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[slots_id[0]] + 1], "~y~17");

			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~w~Tqven ~y~gayavit kartebi~w~, tqven gedzlevat 2 svla ~y~or xelze~w~.")
			);
			BJ_PlayerInfo[playerid][pBlackJackSplit] = 0;
			BJ_PlayerInfo[playerid][pBlackJackTutorialKey] = 0;

			blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_DSHS);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][55], "~g~READY~n~~p~300");
		}
		case 16: {
			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~w~pirveli svla, tqven pirvel xelshi jamshi cota qula gaqvt. ~n~\
				sheidzleba kide aigot ~y~erti karti~w~, daachiret ~y~HIT~w~.")
			);
			BJ_PlayerInfo[playerid][pBlackJackTutorialKey] = BLACKJACK_KEY_HIT;
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[slots_id[0]] + 0], "~y~11");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][8], "~r~00:30~n~~p~300");
		}
		case 17: {
			if (from_next_key) return;

			ApplyAnimation(playerid, "CASINO", "cards_in", 4.1, 0, 1, 1, 1, 1, 1);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[0] + 0] + 2], "LD_CARD:cd11s");

			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"Kargia! ~w~” tqven jamshi agigrovdat ~y~21 qula ~g~(BLACKJACK). ~n~\
				~w~’Ó‰ ÔÂÂ‰‡ÂÚÒˇ Ì‡ ‚‡¯Û ~y~‚ÚÓÛ˛ ÛÍÛ~w~.")
			);
			BJ_PlayerInfo[playerid][pBlackJackTutorialKey] = 0;
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[slots_id[0]] + 0], "~g~21");

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][8], "~y~STAY~n~~p~300");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][55], "~g~READY~n~~p~300");
		}
		case 18: {
			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~w~am xelshi jamshi ~y~17 qula~w~, girchevt gmaotovot es svla.~n~\
				Daachiret ~y~STAY~w~.")
			);
			BJ_PlayerInfo[playerid][pBlackJackTutorialKey] = BLACKJACK_KEY_STAY;

			blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_DSHS);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][55], "~r~00:30~n~~p~300");
		}
		case 19: {
			if (from_next_key) return;

			new player_Name[MAX_PLAYER_NAME + 24];
			strmid(player_Name, GetName(playerid), 0, MAX_PLAYER_NAME + 1);
			strreplace(player_Name, "_", "~n~~g~~h~");
			format(player_Name, sizeof(player_Name), "~g~~h~%s~n~~p~%d", player_Name, 400);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][0], player_Name), player_Name[0] = EOS;

			ApplyAnimation(playerid, "CASINO", "cards_out", 4.1, 0, 1, 1, 1, 1, 1);
			blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_NONE);

			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"igi iyideba dilerze.")
			);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[slots_id[1]]], "~y~9");
			blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_NONE);

			BJ_PlayerInfo[playerid][pBlackJackTutorialKey] = 0;

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][8], "~y~STAY~n~~p~300");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][55], "~y~STAY~n~~p~300");
		}
		case 20: {
			new player_Name[MAX_PLAYER_NAME + 24];
			strmid(player_Name, GetName(playerid), 0, MAX_PLAYER_NAME + 1);
			strreplace(player_Name, "_", "~n~~g~~h~");
			format(player_Name, sizeof(player_Name), "~g~~h~%s~n~~p~%d", player_Name, 700);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][0], player_Name), player_Name[0] = EOS;

			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_seats_array[slots_id[1]] + 1], "LD_CARD:cd8s");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][blackjack_td_score_array[slots_id[1]]], "~y~19");

			PlayerTextDrawSetString(playerid, Blackjack_Tutorial_PTD[playerid], TranslateText(
				"~w~samwuxarod, tqveni meore fsoni wamgebia, radgan dilers~n~\
				meti qula aqvs - ~y~19~w~. xolo pirveli svla - ~g~momgebia~w~.")
			);
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][8], "~g~+300");
			PlayerTextDrawSetString(playerid, Blackjack_PTD[playerid][55], "~r~-300");

			ApplyAnimation(playerid, "CASINO", "cards_win", 4.1, 0, 1, 1, 1, 1, 1);
		}
		case 21: blackjack_StopTutorial(playerid);
	}
	BJ_PlayerInfo[playerid][pBlackJackTutorialStep] = step;
}
stock blackjack_StartTutorial(playerid) {
	new tableid = 0, Float:object_angle = 0.0;
 
	BJ_PlayerInfo[playerid][pBlackJackLanguage] = CASINO_LANGUAGE_RUSSIAN;

	SetPVarInt(playerid, "casinoTempWorldID", GetPlayerVirtualWorld(playerid));

    blackjack_CreatePTD(playerid, 0);
	blackjack_ShowGUI(playerid);

	SelectTextDraw(playerid, 0x000000FF);
	for (new td_id = 0; td_id < sizeof(Blackjack_Tutorial_TD); td_id++)
		TextDrawShowForPlayer(playerid, Blackjack_Tutorial_TD[td_id]);
	PlayerTextDrawShow(playerid, Blackjack_Tutorial_PTD[playerid]);

	blackjack_UpdateOptions(playerid, BLACKJACK_OPTION_NONE);

	BJ_PlayerInfo[playerid][pBlackJackTutorialStep] = 0;
	blackjack_TutorialNextStep(playerid, BJ_PlayerInfo[playerid][pBlackJackTutorialStep] + 1);

	BJ_PlayerInfo[playerid][pBlackJackTableID] = (tableid + 1);
	BJ_PlayerInfo[playerid][pBlackJackSeatID] =
	BJ_PlayerInfo[playerid][pBlackJackDelay] =
	BJ_PlayerInfo[playerid][pBlackJackActiveID] =
	BJ_PlayerInfo[playerid][pBlackJackLastBet] =
	BJ_PlayerInfo[playerid][pBlackJackBlockID] =
	BJ_PlayerInfo[playerid][pBlackJackActiveHand] = 0;

	for (new card_id = 0; card_id < 2; card_id++) {
		BJ_PlayerInfo[playerid][pBlackJackStatus][card_id] = BJ_PLAYER_STATUS_NONE;
		BJ_PlayerInfo[playerid][pBlackJackCards][card_id] =
		BJ_PlayerInfo[playerid][pBlackJackCardsScore][card_id] =
		BJ_PlayerInfo[playerid][pBlackJackBet][card_id] = 0;
	}
	Streamer_ToggleItem(playerid, STREAMER_TYPE_3D_TEXT_LABEL, blackjackTableInfo[tableid][blackjackTableTextID], false);
	Streamer_Update(playerid, STREAMER_TYPE_3D_TEXT_LABEL);

	GetDynamicObjectRot(blackjackTableInfo[tableid][blackjackTableObjectID], object_angle, object_angle, object_angle);

	CameraRadiusSetPos(playerid,
		blackjackTableInfo[tableid][blackjackTablePos][0], blackjackTableInfo[tableid][blackjackTablePos][1], blackjackTableInfo[tableid][blackjackTablePos][2],
		(object_angle + 180.0), 2.3, 3.2
	);
	GetPlayerPos(playerid, BJ_PlayerInfo[playerid][pBlackJackPos][0], BJ_PlayerInfo[playerid][pBlackJackPos][1], BJ_PlayerInfo[playerid][pBlackJackPos][2]);
    SetPlayerInterior(playerid, blackjackTableInfo[tableid][blackjackTableInterior]);
	SetPlayerVirtualWorld(playerid, blackjackTableInfo[tableid][blackjackTableWorld]);

	ApplyAnimation(playerid, "CASINO", "cards_out", 4.1, 0, 1, 1, 1, 1, 1);
	TogglePlayerControllable(playerid, false);

	SetPlayerFacingAngle(playerid, (blackjack_TableOffsets[0][3] + object_angle));
	SetPlayerPosObjectOffset(blackjackTableInfo[tableid][blackjackTableObjectID], playerid, blackjack_TableOffsets[0][0], blackjack_TableOffsets[0][1], blackjack_TableOffsets[0][2]);

	SelectTextDraw(playerid, 0x191919FF);
	blackjack_TutorialNextStep(playerid);
	return true;
}
stock blackjack_StopTutorial(playerid) {
	PlayerPlaySound(playerid, 5852, 0.0, 0.0, 0.0);

	SetPlayerInterior(playerid, blackjackTableInfo[1][blackjackTableInterior]);
	SetPlayerVirtualWorld(playerid, GetPVarInt(playerid, "casinoTempWorldID")/*blackjackTableInfo[1][blackjackTableWorld]*/);

	SetPlayerPos(playerid, BJ_PlayerInfo[playerid][pBlackJackPos][0], BJ_PlayerInfo[playerid][pBlackJackPos][1], BJ_PlayerInfo[playerid][pBlackJackPos][2] + 0.1);
	Dialog_Close(playerid);

	BJ_PlayerInfo[playerid][pBlackJackTableID] =
	BJ_PlayerInfo[playerid][pBlackJackSeatID] =

	BJ_PlayerInfo[playerid][pBlackJackDelay] =
	BJ_PlayerInfo[playerid][pBlackJackActiveID] =
	BJ_PlayerInfo[playerid][pBlackJackActiveHand] = 
	BJ_PlayerInfo[playerid][pBlackJackTutorialStep] = 0;


	for (new card_id = 0; card_id < 2; card_id++) {
		BJ_PlayerInfo[playerid][pBlackJackStatus][card_id] = BJ_PLAYER_STATUS_NONE;
		BJ_PlayerInfo[playerid][pBlackJackCards][card_id] =
		BJ_PlayerInfo[playerid][pBlackJackCardsScore][card_id] =
		BJ_PlayerInfo[playerid][pBlackJackBet][card_id] = 0;
	}
	BJ_PlayerInfo[playerid][pBlackJackPos][0] =
	BJ_PlayerInfo[playerid][pBlackJackPos][1] =
	BJ_PlayerInfo[playerid][pBlackJackPos][2] = 0.0;

	blackjack_DestroyGUI(playerid);

	for (new td_id = 0; td_id < sizeof(Blackjack_Tutorial_TD); td_id++)
		TextDrawHideForPlayer(playerid, Blackjack_Tutorial_TD[td_id]);
	PlayerTextDrawDestroy(playerid, Blackjack_Tutorial_PTD[playerid]);

	TogglePlayerControllable(playerid, true);
	SetCameraBehindPlayer(playerid);
	CancelSelectTextDraw(playerid);

	ClearAnimations(playerid);
	ApplyAnimation(playerid, "CARRY", "crry_prtial", 1.0, 0, 0, 0, 0, 0);
}