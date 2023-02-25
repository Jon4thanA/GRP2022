/*

• MBuster v0.4 Release •
Founded, Developed and Codded by Giorgi Mugalashvili (Mugala)
(C) 2017-2018 AlphaGaming.Ge

*/
//==================================================================================================================================================
/* MBuster Features:

1) Player Side
• Anti Teleport Hack (aseve ichers FlyHacks da AirBreaks, tumca amatac gaachnia calke AntiCheat-ebi)
• Anti Health Hack
• Anti Armour Hack
• Anti In-Vehicle Teleport Hack
• Anti Vehicle-To-Vehicle Teleport Hack
• Anti Weapon Hack
• Anti Ammo Hack
• Anti Fly Hack
• Anti AirBreak
• Anti Speed Hack
• Anti In-Vehicle Freeze Hack
• Anti Silent-Shot/Damager
• Anti Infinite Ammo
• Anti Ping
• Anti Engine Hack
• Anti Vehicle AirBrk
• Anti Vehicle Teleport
• Anti Vehicle Repair
• Anti CBUg
• Anti RapidFire
• Anti Jetpack
• Anti Fake Kill
• Anti Vehicle Rotation (Side & Backspace)
• Anti IP Changer/Anti Proxy


2) Server Side
• Special Anti Crashers
• Anti Trollers
• Anti Crashers
*/
//==================================================================================================================================================
/* Changelog:
Version - 0.4
ChangeLog Link - http://forum.alphagaming.ge/index.php?/topic/37-changelog/
*/
//==================================================================================================================================================
/* Damatebiti Funqciebi:

• ResetPlayerWeaponM(playerid,weaponid) -> weaponid = iaragis ID romelic waertmeva motamashes.
• MGetVehicleDriverID(vehicleid) -> vehicleid = manqanis ID romlis mdzgolis ID-is gageba shesadzlebeli iqneba.
*/
//==================================================================================================================================================
/* Instruqcia

1) Sachiroa Shecvalot: GameMode-shi MXOLOD shemdeg funqciebs vcvlit da vamatebt M-s boloshi, shemdegnairad
• Tu iyenebt MB02-s: SetPlayerPos(... - SetPlayerPosM(...
• Tu iyenebt MB01-s: SetPlayerHealth(... - SetPlayerHealthM(...
• Tu iyenebt MB01-s: SetPlayerArmour(... - SetPlayerArmourM(...
• Tu iyenebt MB09-s an MB03-s: PutPlayerInVehicle(... - PutPlayerInVehicleM(...
• Tu iyenebt MB05-s: RemovePlayerWeapon(... - RemovePlayerWeaponM(...
• Tu iyenebt MB05-s: GivePlayerWeapon(... - GivePlayerWeaponM(...
• Tu iyenebt MB09-s: RemovePlayerFromVehicle(... - RemovePlayerFromVehicleM(...
• Tu iyenebt MB13-s: SetVehiclePos(... - SetVehiclePosM(...
• Tu iyenebt MB14-s: RepairVehicle(... - RepairVehicleM(...
P.S. Yuradgebit iyavit tqvens axlandel AntiCheat-tan romelic aseve cvlis amave funqciebs.

2) Vamatebt Administratorebs, romlebsac chetze ar eqneba reagireba (survilisamebr)
• OnPlayerUpdate-shi (Gamemode-shi) an raime amdagvar adgilas, vwert shemdeg funqcias: SetPVarInt(playerid,"ServerAdmin",ADMINCODE);
Ra sheidzleba iyos ADMINCODE?
Martiv enaze ro mvtqvat es damokidebulia imaze, tu rogor gaqvt administratori agnishnuli tqvens gamemode-shi.
• PlayerInfo[playerid][pAdmin]
• PlayerInfo[playerid][pAdminLevel]
• PlayerInfo[playerid][bAdmin]
• pInfo[playerid][pAdminLevel]
• pInfo[playerid][pAdmin]
• ase shemdeg..
*MAGALITAD* SetPVarInt(playerid,"ServerAdmin",PlayerInfo[playerid][pAdmin]);

3) !!! GAITVALISWINET • Tu ar sheasrulebt instruqciis pirvel nawils, anticheti ver imushavebs gamartulad. !!!

4) AntiCheat MB07 da MB12 iyenebs shemdeg Plugins - MapAndreas
romlis failebic moyveba folders.
Chautvirtavobis shemtxvevashi AntiCheat MB07 da MB12 gagkikavt uazrot.
*/
/*
MB01 - Anti HP/Armor
MB02 - Anti Teleport
MB03 - In-Vehicle Teleport
MB04 - Vehicle-To-Vehicle Teleport
MB05 - Anti Weapon/Ammo Hack
MB06 - Anti Fly Hack
MB07 - Flying/AirBrk (MapAndreas required)
MB08 - Anti Speed Hack
MB09 - Freeze in Vehicle
MB10 - SilentShot/Damager
MB11 - Engine Hack
MB12 - Veh AirBrk (MapAndreas required)
MB13 - Vehicle Teleport
MB14 - Vehicle Repair
MB15 - Vehicle Rotations
MB16 - Anti Jetpack
MB17 - Anti Fake Kill
MB18 - Anti Rapid Fire + CBug
MB19 - Anti INV (Message to admins)
*/
//================================================================================================//
#include <a_samp>
//========================================== Forwards ============================================//
forward SetPlayerPosM(playerid,Float:XPosM,Float:YPosM,Float:ZPosM);
forward SetPlayerHealthM(playerid,Float:HealthM);
forward SetPlayerArmourM(playerid,Float:ArmourM);
forward PutPlayerInVehicleM(playerid,VehIDM,VehSeatM);
forward GivePlayerWeaponM(playerid,WeaponIDM,WeaponAmmoM);
forward SetPlayerAmmoM(playerid,weaponid,ammo);
forward RemovePlayerFromVehicleM(playerid);
forward SetVehiclePosM(vehicleid, Float:VXPosM,Float:VYPosM,Float:VZPosM);
forward RepairVehicleM(vehicleid);
forward OnPlayerSpawnM(playerid);
forward Callbacker(playerid);
//========================================== Publics ============================================//
public SetPlayerPosM(playerid,Float:XPosM,Float:YPosM,Float:ZPosM)
{
	SetPVarFloat(playerid,"XPosM",XPosM);
	SetPVarFloat(playerid,"YPosM",YPosM);
	SetPVarFloat(playerid,"ZPosM",ZPosM);
	SetPVarInt(playerid,"PosStateM",1);
	SetPlayerPos(playerid,XPosM,YPosM,ZPosM);
	return 1;
}

public SetPlayerHealthM(playerid,Float:HealthM)
{
	SetPVarFloat(playerid,"HealthM",HealthM);
	SetPlayerHealth(playerid,HealthM);
	return 1;
}

public SetPlayerArmourM(playerid,Float:ArmourM)
{
    SetPVarFloat(playerid,"ArmourM",ArmourM);
	SetPlayerArmour(playerid,ArmourM);
	return 1;
}

public PutPlayerInVehicleM(playerid,VehIDM,VehSeatM)
{
	SetPVarInt(playerid,"VehStateM",1);
	PutPlayerInVehicle(playerid,VehIDM,VehSeatM);
}

public GivePlayerWeaponM(playerid,WeaponIDM,WeaponAmmoM)
{
	if(WeaponIDM == 22 || WeaponIDM == 23 || WeaponIDM == 24)
	{
	    SetPVarInt(playerid,"WeaponIDM1",WeaponIDM);
        SetPVarInt(playerid,"WeaponAmmoM1",WeaponAmmoM);
	}
	if(WeaponIDM == 25 || WeaponIDM == 26 || WeaponIDM == 27)
	{
	    SetPVarInt(playerid,"WeaponIDM2",WeaponIDM);
        SetPVarInt(playerid,"WeaponAmmoM2",WeaponAmmoM);
	}
	if(WeaponIDM == 28 || WeaponIDM == 29 || WeaponIDM == 32)
	{
	    SetPVarInt(playerid,"WeaponIDM3",WeaponIDM);
        SetPVarInt(playerid,"WeaponAmmoM3",WeaponAmmoM);
	}
	if(WeaponIDM == 30 || WeaponIDM == 31)
	{
	    SetPVarInt(playerid,"WeaponIDM4",WeaponIDM);
        SetPVarInt(playerid,"WeaponAmmoM4",WeaponAmmoM);
	}
	if(WeaponIDM == 33 || WeaponIDM == 34)
	{
	    SetPVarInt(playerid,"WeaponIDM5",WeaponIDM);
        SetPVarInt(playerid,"WeaponAmmoM5",WeaponAmmoM);
	}
	GivePlayerWeapon(playerid,WeaponIDM,WeaponAmmoM);
    SetPlayerAmmoM(playerid,WeaponIDM,WeaponAmmoM);
	return 1;
}

public SetPlayerAmmoM(playerid,weaponid,ammo)
{
    new WeaponIDM = weaponid, WeaponAmmoM = ammo;
	if(WeaponIDM == 22 || WeaponIDM == 23 || WeaponIDM == 24)
	{
        SetPVarInt(playerid,"WeaponAmmoM1",WeaponAmmoM);
	}
	if(WeaponIDM == 25 || WeaponIDM == 26 || WeaponIDM == 27)
	{
        SetPVarInt(playerid,"WeaponAmmoM2",WeaponAmmoM);
	}
	if(WeaponIDM == 28 || WeaponIDM == 29 || WeaponIDM == 32)
	{
        SetPVarInt(playerid,"WeaponAmmoM3",WeaponAmmoM);
	}
	if(WeaponIDM == 30 || WeaponIDM == 31)
	{
        SetPVarInt(playerid,"WeaponAmmoM4",WeaponAmmoM);
	}
	if(WeaponIDM == 33 || WeaponIDM == 34)
	{
        SetPVarInt(playerid,"WeaponAmmoM5",WeaponAmmoM);
	}
    SetPlayerAmmo(playerid,weaponid,ammo);
    return 1;
}

public SetVehiclePosM(vehicleid, Float:VXPosM,Float:VYPosM,Float:VZPosM)
{
    SetPVarInt(MGetVehicleDriverID(vehicleid),"VPosUpdate",1);
    SetVehiclePos(vehicleid, VXPosM, VYPosM, VZPosM);
	return 1;
}

public RemovePlayerFromVehicleM(playerid)
{
	SetPVarInt(playerid,"VehStateM",2);
	return 1;
}

public RepairVehicleM(vehicleid)
{
	if(MGetVehicleDriverID(vehicleid) != INVALID_PLAYER_ID) SetPVarInt(MGetVehicleDriverID(vehicleid),"VRepairM",1);
	else RepairVehicle(vehicleid);
}

public Callbacker(playerid)
{
	if(GetPVarInt(playerid,"CheckStatus") == 1) SetPVarInt(playerid,"CheckStatus",0), CallRemoteFunction("OnPlayerSpawnM", "i", playerid);
    return 1;
}
//========================================== Stocks ============================================//
stock ResetPlayerWeaponM(playerid, weaponid)
{
	new WeaponIDM[12], WeaponAmmoM[12];
	for(new SLOT = 0; SLOT != 12; SLOT++)
	{
		new wepExtra, ammoExtra;
		GetPlayerWeaponData(playerid, SLOT, wepExtra, ammoExtra);
		if(wepExtra != weaponid)
		{
			GetPlayerWeaponData(playerid, SLOT, WeaponIDM[SLOT], WeaponAmmoM[SLOT]);
		}
	}
	ResetPlayerWeapons(playerid);
	for(new SLOT = 0; SLOT != 12; SLOT++)
	{
		GivePlayerWeapon(playerid, WeaponIDM[SLOT], WeaponAmmoM[SLOT]);
	}
}

stock ResetPlayerWeaponsM(playerid)
{
	SetPVarInt(playerid,"WeaponAmmoM1",0);
	SetPVarInt(playerid,"WeaponAmmoM2",0);
	SetPVarInt(playerid,"WeaponAmmoM3",0);
	SetPVarInt(playerid,"WeaponAmmoM4",0);
	SetPVarInt(playerid,"WeaponAmmoM5",0);
	SetPVarInt(playerid,"WeaponIDM1",0);
	SetPVarInt(playerid,"WeaponIDM2",0);
	SetPVarInt(playerid,"WeaponIDM3",0);
	SetPVarInt(playerid,"WeaponIDM4",0);
	SetPVarInt(playerid,"WeaponIDM5",0);
	SetPVarInt(playerid,"WeaponStateM",0);
	ResetPlayerWeapons(playerid);
}

stock MGetVehicleDriverID(vehicleid)
{
    for(new i,l=GetPlayerPoolSize()+1; i<l; i++)
	{
	    if(GetPlayerState(i) == PLAYER_STATE_DRIVER && IsPlayerInVehicle(i,vehicleid)) return i;
	}
	return -1;
}

forward KickPl(playerid);
public KickPl(playerid)
{
	anticheatkick(playerid);
	return 1;
}


stock Punish(playerid,reason[])
{
    if(GetPVarInt(playerid,"ServerAdmin") >= 1) return 1;
    if(GetPVarInt(playerid,"PlayerKicked") == 1) return 1;
    SetPVarInt(playerid,"PlayerKicked",1);
    new text111[1024];
    new ip[32],name[64],atext[512],data[64],day,month,year,hour,minuite,second;
    GetPlayerIp(playerid,ip,sizeof(ip));
    getdate(year, month, day);
    gettime(hour,minuite,second);
    format(data, sizeof(data), "%02d/%02d/%d | %02d:%d",day,month,year,hour,minuite);
    GetPlayerName(playerid,name,sizeof(name));
    format(atext,sizeof(atext),"[MBuster] {FF0000}[ID:%d] %s (IP:%s) Kicked, Reason:{FFFFFF} %s",playerid,name,ip,reason);
    format(text111,sizeof(text111),"{FFFFFF}Tqven Gaikicket Serveridan by MBuster | GRP\n\nMizezi: %s\n{FF0000}_____________________{FFFFFF}\n\nSaxeli: %s\nDro: %s\n\n\n    Daachiret {11FF11}F8{FFFFFF}-s rom gadaigot {11FF11}Screen\n\n\t\t\t\t{008080}MBuster v0.4 | GRP ANTICHEAT",reason,name,data);
    ShowPlayerDialog(playerid,9999,DIALOG_STYLE_MSGBOX,"{FF5733}Genuine RP AntiCheat {FFFFFF}| Kick Informacia",text111,"X","");
    TogglePlayerControllable(playerid,0);
    ResetPlayerWeaponsM(playerid);
    SetTimerEx("KickPl",200,0,"i",playerid);
    return 1;
}

