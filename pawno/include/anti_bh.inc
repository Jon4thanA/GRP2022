forward KillTimerSprung(playerid);
forward FunktionInSprung(playerid);

new InSprung[MAX_PLAYERS] = 0;
new TimerIDSprung[MAX_PLAYERS];

public OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	new Float:vx,Float:vy,Float:vz;
	GetPlayerVelocity(playerid,vx,vy,vz);
	if (PRESSED(KEY_JUMP) && (vy > 0.01 || vy <-0.01 || vx > 0.01 || vx <-0.01) && IsPlayerInAnyVehicle(playerid) == 0 && InSprung[playerid] == 0)
	{
		if(vz > 0.01 || vz < -0.01) return 1;
		InSprung[playerid] = 1;
		TimerIDSprung[playerid] = SetTimerEx("FunktionInSprung",1,true,"i",playerid);
	}
	return 1;
}

#if defined _ALS_OnPlayerKeyStateChange
    #undef OnPlayerKeyStateChange
#else
    #define _ALS_OnPlayerKeyStateChange
#endif
#define OnPlayerKeyStateChange ANTIBH_OnPlayerKeyStateChange
#if defined ANTIBH_OnPlayerKeyStateChange
    forward ANTIBH_OnPlayerKeyStateChange(playerid, newkeys, oldkeys);
#endif


public KillTimerSprung(playerid)
{
	InSprung[playerid] = 0;
	return 1;
}

public FunktionInSprung(playerid)
{
	new animlib[32];
	new animname[32];
	new Float:vx,Float:vy,Float:vz;
	GetPlayerVelocity(playerid,vx,vy,vz);
	if(vz < -0.5)
	{
	    KillTimer(TimerIDSprung[playerid]);
	    SetTimerEx("KillTimerSprung",1000,false,"i",playerid);
	    return 1;
	}
	GetAnimationName(GetPlayerAnimationIndex(playerid),animlib,32,animname,32);
	if(!strcmp(animname,"JUMP_LAND") || !strcmp(animname,"FALL_LAND"))
	{
		KillTimer(TimerIDSprung[playerid]);
		ClearAnimations(playerid,1);
		//ApplyAnimation(playerid,"ped","FALL_COLLAPSE",4.1,0,1,1,0,0,1);
		SetTimerEx("KillTimerSprung",1000,false,"i",playerid);
	}
	return 1;
}
