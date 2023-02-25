#if defined _flymode_inc
	#endinput
#endif
#define _flymode_inc

#define FLYMODE_MOVE_SPEED	100.0
#define FLYMODE_ACCEL_RATE	0.03
#define FLYMODE_ACCEL_MODE	true

enum {
	CAMERA_MODE_NONE = 0,
	CAMERA_MODE_FLY,
}
enum { 
	MOVE_FORWARD = 1,
	MOVE_BACK,
	MOVE_LEFT,
	MOVE_RIGHT,
	MOVE_FORWARD_LEFT,
	MOVE_FORWARD_RIGHT,
	MOVE_BACK_LEFT,
	MOVE_BACK_RIGHT,
}
enum FLY_MODE_e {
	flyCameraMode,
	flyObjectID,
	flyMode,
	flyLRold,
	flyUDold,
	flyLastMove,
    bool:flyAccel,
	Float:flyAccelMul,
    Float:flyAccelRate,
    Float:flyMaxSpeed,
}
static FlyModeInfo[MAX_PLAYERS][FLY_MODE_e];

new bool:FlyMode[MAX_PLAYERS];

stock IsFlyMode(playerid) {
	return FlyModeInfo[playerid][flyCameraMode]; 
}

stock GetMoveFlyModeDirectionFromKeys(ud, lr) {
	new direction = 0;

    if (lr < 0) {
		if (ud < 0) direction = MOVE_FORWARD_LEFT;
		else if (ud > 0) direction = MOVE_BACK_LEFT;
		else direction = MOVE_LEFT;
	}
	else if (lr > 0) {
		if (ud < 0) direction = MOVE_FORWARD_RIGHT;
		else if (ud > 0) direction = MOVE_BACK_RIGHT;
		else direction = MOVE_RIGHT;
	}
	else if (ud < 0) direction = MOVE_FORWARD;
	else if (ud > 0) direction = MOVE_BACK;

	return direction;
}
stock MoveFlyModeCamera(playerid) {
	new Float:FV[3], Float:CP[3];
	GetPlayerObjectPos(playerid, FlyModeInfo[playerid][flyObjectID], CP[0], CP[1], CP[2]); 
    GetPlayerCameraFrontVector(playerid, FV[0], FV[1], FV[2]); 

	if (FlyModeInfo[playerid][flyAccelMul] <= 1.0) FlyModeInfo[playerid][flyAccelMul] += FlyModeInfo[playerid][flyAccelRate];

	new 
		Float:X, Float:Y, Float:Z,
		Float:speed = FlyModeInfo[playerid][flyMaxSpeed] * (FlyModeInfo[playerid][flyAccel] ? FlyModeInfo[playerid][flyAccelMul] : 1.0);

	GetNextFlyModeCameraPosition(FlyModeInfo[playerid][flyMode], CP, FV, X, Y, Z);
	MovePlayerObject(playerid, FlyModeInfo[playerid][flyObjectID], X, Y, Z, speed);

	FlyModeInfo[playerid][flyLastMove] = GetTickCount();
	return true;
}
stock SetFlyModePos(playerid, Float:x, Float:y, Float:z) {
	if (FlyMode[playerid]) {
		SetPlayerObjectPos(playerid, FlyModeInfo[playerid][flyObjectID], x, y, z);
		FlyModeInfo[playerid][flyLastMove] = GetTickCount();
		return 1;
	}
	return 0;
}
stock GetFlyModePos(playerid, &Float:x, &Float:y, &Float:z) {
	if (FlyMode[playerid]) {
		GetPlayerObjectPos(playerid, FlyModeInfo[playerid][flyObjectID], x, y, z);
		return true;
	}
	return false;
}
stock GetNextFlyModeCameraPosition(move_mode, const Float:CP[3], const Float:FV[3], &Float:X, &Float:Y, &Float:Z) {
    #define OFFSET_X (FV[0]*6000.0)
	#define OFFSET_Y (FV[1]*6000.0)
	#define OFFSET_Z (FV[2]*6000.0)

	switch (move_mode) {
		case MOVE_FORWARD: {
			X = CP[0] + OFFSET_X;
			Y = CP[1] + OFFSET_Y;
			Z = CP[2] + OFFSET_Z;
		}
		case MOVE_BACK: {
			X = CP[0]-OFFSET_X;
			Y = CP[1]-OFFSET_Y;
			Z = CP[2]-OFFSET_Z;
		}
		case MOVE_LEFT: {
			X = CP[0]-OFFSET_Y;
			Y = CP[1] + OFFSET_X;
			Z = CP[2];
		}
		case MOVE_RIGHT: {
			X = CP[0] + OFFSET_Y;
			Y = CP[1]-OFFSET_X;
			Z = CP[2];
		}
		case MOVE_BACK_LEFT: {
			X = CP[0]+(-OFFSET_X - OFFSET_Y);
 			Y = CP[1]+(-OFFSET_Y + OFFSET_X);
		 	Z = CP[2]-OFFSET_Z;
		}
		case MOVE_BACK_RIGHT: {
			X = CP[0]+(-OFFSET_X + OFFSET_Y);
 			Y = CP[1]+(-OFFSET_Y - OFFSET_X);
		 	Z = CP[2]-OFFSET_Z;
		}
		case MOVE_FORWARD_LEFT: {
			X = CP[0]+(OFFSET_X  - OFFSET_Y);
			Y = CP[1]+(OFFSET_Y  + OFFSET_X);
			Z = CP[2] + OFFSET_Z;
		}
		case MOVE_FORWARD_RIGHT: {
			X = CP[0]+(OFFSET_X  + OFFSET_Y);
			Y = CP[1]+(OFFSET_Y  - OFFSET_X);
			Z = CP[2] + OFFSET_Z;
		}
	}
}
forward DelaySetPos(playerid, Float:x, Float:y, Float:z, unfreeze);
public DelaySetPos(playerid, Float:x, Float:y, Float:z, unfreeze) { 
	SetPlayerPosAC(playerid, x, y, z); 
	if (unfreeze) TogglePlayerControllable(playerid, true);
}
stock StartFlyMode(playerid) {
	if (FlyMode[playerid]) return false;
	new Float:X, Float:Y, Float:Z;
	GetPlayerPos(playerid, X, Y, Z);
	FlyModeInfo[playerid][flyObjectID] = CreatePlayerObject(playerid, 19300, X, Y, Z, 0.0, 0.0, 0.0);

	TogglePlayerSpectating(playerid, true);
	AttachCameraToPlayerObject(playerid, FlyModeInfo[playerid][flyObjectID]);

	FlyMode[playerid] = true;
	FlyModeInfo[playerid][flyCameraMode] = CAMERA_MODE_FLY;

	return true;
}
stock StopFlyMode(playerid) {
	if (!FlyMode[playerid]) return false;
	new Float:playerpos[3], Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, playerpos[0], playerpos[1], playerpos[2]);

	GetPlayerCameraPos(playerid, x, y, z);
	SetTimerEx("DelaySetPos", 500, false, "ifffi", playerid, x, y, z, 0);
	SetTimerEx("DelaySetPos", 1000, false, "ifffi", playerid, x, y, z, 1);

	FlyMode[playerid] = false;
	CancelEdit(playerid);
	TogglePlayerSpectating(playerid, false);
	TogglePlayerControllable(playerid, false);

	SetPlayerPosAC(playerid, playerpos[0] + 0.001, playerpos[1], playerpos[2]);

	DestroyPlayerObject(playerid, FlyModeInfo[playerid][flyObjectID]);
	FlyModeInfo[playerid][flyCameraMode] = CAMERA_MODE_NONE;
	return true;
}
flymode_OnPlayerConnect(playerid) {
	static FlyModeInfoTemp[FLY_MODE_e];
	FlyModeInfo[playerid] = FlyModeInfoTemp;
	FlyModeInfo[playerid][flyCameraMode] = CAMERA_MODE_NONE;
	FlyModeInfo[playerid][flyAccel] = FLYMODE_ACCEL_MODE;
	FlyModeInfo[playerid][flyAccelRate] = FLYMODE_ACCEL_RATE;
	FlyModeInfo[playerid][flyMaxSpeed] = FLYMODE_MOVE_SPEED;
	FlyMode[playerid] = false;
	return true;
}
flymode_OnPlayerUpdate(playerid) {
	if (FlyMode[playerid] && FlyModeInfo[playerid][flyCameraMode] == CAMERA_MODE_FLY) {
		new keys, ud, lr;
		GetPlayerKeys(playerid, keys, ud, lr);

		if (FlyModeInfo[playerid][flyMode] && (GetTickCount() - FlyModeInfo[playerid][flyLastMove] > 100)) {
		    MoveFlyModeCamera(playerid);
		}
		if (FlyModeInfo[playerid][flyUDold] != ud || FlyModeInfo[playerid][flyLRold] != lr) {
			if ((FlyModeInfo[playerid][flyUDold] != 0 || FlyModeInfo[playerid][flyLRold] != 0) && ud == 0 && lr == 0) {  
				StopPlayerObject(playerid, FlyModeInfo[playerid][flyObjectID]);
				FlyModeInfo[playerid][flyMode] = 0;
				FlyModeInfo[playerid][flyAccelMul] = 0.0;
			} else { 
				FlyModeInfo[playerid][flyMode] = GetMoveFlyModeDirectionFromKeys(ud, lr);
				MoveFlyModeCamera(playerid);
			}
		}
		FlyModeInfo[playerid][flyUDold] = ud; 
		FlyModeInfo[playerid][flyLRold] = lr; 

		// return false;
	}
	return true;
}
