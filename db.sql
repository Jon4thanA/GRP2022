-- phpMyAdmin SQL Dump
-- version 5.3.0-dev+20220611.3e6b0abbe2
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Sep 30, 2022 at 04:39 PM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 8.1.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `db`
--

-- --------------------------------------------------------

--
-- Table structure for table `accounts`
--

CREATE TABLE `accounts` (
  `pID` bigint(20) UNSIGNED NOT NULL,
  `Name` varchar(32) COLLATE cp1251_bin NOT NULL,
  `pKey` varchar(32) COLLATE cp1251_bin NOT NULL,
  `pLevel` int(11) NOT NULL,
  `pForma` int(11) NOT NULL,
  `pAdmin` int(11) NOT NULL,
  `pReporter` int(11) NOT NULL,
  `pPasport` int(11) NOT NULL,
  `pReptool` int(11) NOT NULL,
  `pIp` varchar(127) COLLATE cp1251_bin NOT NULL,
  `pvIp` varchar(128) COLLATE cp1251_bin NOT NULL,
  `pIpReg` varchar(128) COLLATE cp1251_bin NOT NULL,
  `pHousecash` int(11) NOT NULL,
  `pCheckip` int(11) NOT NULL,
  `pText` int(11) NOT NULL,
  `pKeyip` varchar(32) COLLATE cp1251_bin NOT NULL,
  `pProcents` int(11) NOT NULL,
  `pHP` int(11) NOT NULL,
  `pCar` int(11) NOT NULL,
  `pDonateRank` int(11) NOT NULL,
  `pMats` int(11) NOT NULL,
  `pSex` int(11) NOT NULL,
  `pMuted` int(11) NOT NULL,
  `pColor31` int(11) NOT NULL,
  `pColor32` int(11) NOT NULL,
  `pExp` int(11) NOT NULL,
  `pCash` int(11) NOT NULL,
  `pPayCheck` int(11) NOT NULL,
  `pJailed` int(11) NOT NULL,
  `pJailTime` int(11) NOT NULL,
  `pProcents2` int(11) NOT NULL,
  `pDrugs` int(11) NOT NULL,
  `pLeader` int(11) NOT NULL,
  `pMember` int(11) NOT NULL,
  `pRank` int(11) NOT NULL,
  `pChar` int(11) NOT NULL,
  `pJob` int(11) NOT NULL,
  `pModel` int(11) NOT NULL,
  `pPnumber` int(11) NOT NULL,
  `pCarLic` int(11) NOT NULL,
  `pProcents1` int(11) NOT NULL,
  `pFlyLic` int(11) NOT NULL,
  `pBoatLic` int(11) NOT NULL,
  `pFishLic` int(11) NOT NULL,
  `pGunLic` int(11) NOT NULL,
  `pBizLic` int(11) NOT NULL,
  `pPhousekey` int(11) NOT NULL,
  `pPbiskey` int(11) NOT NULL,
  `pHotelKey` int(11) NOT NULL,
  `pZakonp` int(11) NOT NULL,
  `pAddiction` int(11) NOT NULL,
  `pVig` int(11) NOT NULL,
  `pMarried` int(11) NOT NULL,
  `pMarriedTo` varchar(128) COLLATE cp1251_bin NOT NULL,
  `pMuteTime` int(11) NOT NULL,
  `pBank` int(11) NOT NULL,
  `pBanMounth` int(11) NOT NULL,
  `pMobile` int(11) NOT NULL,
  `pDostup` varchar(32) COLLATE cp1251_bin NOT NULL,
  `pLocked` int(11) NOT NULL,
  `pWantedLevel` int(11) NOT NULL,
  `ptaxiexp` int(11) NOT NULL,
  `ptaxilvl` int(11) NOT NULL,
  `pBoxstyle` int(11) NOT NULL,
  `pKstyle` int(11) NOT NULL,
  `pKickstyle` int(11) NOT NULL,
  `pBoxSkill` int(11) NOT NULL,
  `pKongfuSkill` int(11) NOT NULL,
  `pKickboxSkill` int(11) NOT NULL,
  `pWheels` int(11) NOT NULL,
  `pPaintJob` int(11) NOT NULL,
  `pSpoiler` int(11) NOT NULL,
  `pBumper1` int(11) NOT NULL,
  `pBumper2` int(11) NOT NULL,
  `pColor1` int(11) NOT NULL,
  `pColor2` int(11) NOT NULL,
  `pColor21` int(11) NOT NULL,
  `pColor22` int(11) NOT NULL,
  `pNitro` int(11) NOT NULL,
  `pHydrawlic` int(11) NOT NULL,
  `pOnline` varchar(128) COLLATE cp1251_bin NOT NULL,
  `pChar1` int(11) NOT NULL,
  `pCigarettes` int(11) NOT NULL,
  `pChar2` int(11) NOT NULL,
  `pViborChar` int(11) NOT NULL,
  `pOnlineLid` varchar(32) COLLATE cp1251_bin NOT NULL,
  `pLogin` int(11) NOT NULL,
  `pQira` int(11) NOT NULL,
  `pNeon` int(11) NOT NULL,
  `pVipTime` int(11) NOT NULL,
  `pWheels1` int(11) NOT NULL,
  `pPaintJob1` int(11) NOT NULL,
  `pSpoiler1` int(11) NOT NULL,
  `pNeon1` int(11) NOT NULL,
  `pNitro1` int(11) NOT NULL,
  `pHydrawlic1` int(11) NOT NULL,
  `pCar1` int(11) NOT NULL,
  `pBonus` int(11) NOT NULL,
  `pCar2` int(11) NOT NULL,
  `pHealme` int(11) NOT NULL,
  `pQuest` int(11) NOT NULL,
  `pQuestis` int(11) NOT NULL,
  `pWheels2` int(11) NOT NULL,
  `pPaintJob2` int(11) NOT NULL,
  `pSpoiler2` int(11) NOT NULL,
  `pNitro2` int(11) NOT NULL,
  `pHydrawlic2` int(11) NOT NULL,
  `pNeon2` int(11) NOT NULL,
  `pPhonePlayer` int(11) NOT NULL,
  `pBumper11` int(11) NOT NULL,
  `pBumper21` int(11) NOT NULL,
  `pBumper31` int(11) NOT NULL,
  `pBumper32` int(11) NOT NULL,
  `pArmyBilet` int(11) NOT NULL,
  `pArmyTime` int(11) NOT NULL,
  `pCar3` int(11) NOT NULL,
  `pWheels3` int(11) NOT NULL,
  `pSpoiler3` int(11) NOT NULL,
  `pNeon3` int(11) NOT NULL,
  `pNitro3` int(11) NOT NULL,
  `pHydrawlic3` int(11) NOT NULL,
  `pBumper41` int(11) NOT NULL,
  `pBumper42` int(11) NOT NULL,
  `pColor41` int(11) NOT NULL,
  `pColor42` int(11) NOT NULL,
  `pProcents3` int(11) NOT NULL,
  `pSlotItem1` int(11) NOT NULL,
  `pSlotItem2` int(11) NOT NULL,
  `pSlotItem3` int(11) NOT NULL,
  `pSlotItem4` int(11) NOT NULL,
  `pSlotItem5` int(11) NOT NULL,
  `pSlotItem6` int(11) NOT NULL,
  `pSlotItem7` int(11) NOT NULL,
  `pSlotItem8` int(11) NOT NULL,
  `pJackpot` int(11) NOT NULL,
  `pDonateman` int(11) NOT NULL,
  `pDjetx` int(11) NOT NULL,
  `pPromoUse` int(11) NOT NULL,
  `pRoofAir1` int(11) NOT NULL,
  `pRoofAir2` int(11) NOT NULL,
  `pRoofAir3` int(11) NOT NULL,
  `pRoofAir4` int(11) NOT NULL,
  `pGrushiteli1` int(11) NOT NULL,
  `pGrushiteli2` int(11) NOT NULL,
  `pGrushiteli3` int(11) NOT NULL,
  `pGrushiteli4` int(11) NOT NULL,
  `pLowerAir1` int(11) NOT NULL,
  `pLowerAir2` int(11) NOT NULL,
  `pLowerAir3` int(11) NOT NULL,
  `pLowerAir4` int(11) NOT NULL,
  `pFish` int(11) NOT NULL,
  `pQashayi` int(11) NOT NULL,
  `pOraguli` int(11) NOT NULL,
  `pKalmaxi` int(11) NOT NULL,
  `pTut` int(11) NOT NULL,
  `pDataReg` int(11) NOT NULL,
  `pDonatemoney` int(11) NOT NULL,
  `pDrug` int(11) NOT NULL,
  `pBanDay` int(11) NOT NULL,
  `Online_status` int(11) NOT NULL,
  `pTecAdmin` int(11) NOT NULL,
  `pInventory1` int(11) NOT NULL,
  `pInventory2` int(11) NOT NULL,
  `pInventory3` int(11) NOT NULL,
  `pInventory4` int(11) NOT NULL,
  `pInventory5` int(11) NOT NULL,
  `pInventory6` int(11) NOT NULL,
  `pBankomat` int(11) NOT NULL,
  `pKills` int(11) NOT NULL,
  `pDeaths` int(11) NOT NULL,
  `pAdminWarning` int(11) NOT NULL,
  `pElections` int(11) NOT NULL,
  `pCar4` int(11) NOT NULL,
  `pBumper51` int(11) NOT NULL,
  `pBumper52` int(11) NOT NULL,
  `pColor51` int(11) NOT NULL,
  `pColor52` int(11) NOT NULL,
  `pSpoiler4` int(11) NOT NULL,
  `pProcents4` int(11) NOT NULL,
  `pHydrawlic4` int(11) NOT NULL,
  `pPaintJob4` int(11) NOT NULL,
  `pWheels4` int(11) NOT NULL,
  `pNeon4` int(11) NOT NULL,
  `pRoofAir5` int(11) NOT NULL,
  `pGrushiteli5` int(11) NOT NULL,
  `pLowerAir5` int(11) NOT NULL,
  `pCarSlot` int(11) NOT NULL,
  `pBonuscar` int(11) NOT NULL,
  `pWarns` int(11) NOT NULL,
  `punWarns` int(11) NOT NULL,
  `punWarnstime` int(11) NOT NULL,
  `pMusiclic` int(11) NOT NULL,
  `pMagida` int(11) NOT NULL,
  `pAngel` int(11) NOT NULL,
  `pDeath` int(11) NOT NULL,
  `pPubgSkin` int(11) NOT NULL,
  `pSparta` int(11) NOT NULL,
  `pGhostRider` int(11) NOT NULL,
  `pDemon` int(11) NOT NULL,
  `pAxaliskini` int(11) NOT NULL,
  `pPirbade` int(11) NOT NULL,
  `pDancec` int(11) NOT NULL,
  `pGangKills` int(11) NOT NULL,
  `pPaintJob3` int(11) NOT NULL,
  `pLocal` int(11) NOT NULL,
  `pInt` int(11) NOT NULL,
  `pSpawnloc` int(11) NOT NULL,
  `pNitro4` int(11) NOT NULL,
  `pDartWaider` int(11) NOT NULL,
  `SpawnChange` int(11) NOT NULL DEFAULT 0,
  `pFamilyMember` int(11) NOT NULL,
  `pFamilyRank` int(11) NOT NULL,
  `pCarPos` int(11) NOT NULL,
  `pCarPos1` int(11) NOT NULL,
  `pCarPos2` int(11) NOT NULL,
  `pCarPos3` int(11) NOT NULL,
  `pSatiety` int(11) NOT NULL,
  `pHtune` int(11) NOT NULL,
  `pKiborg` int(11) NOT NULL,
  `pObjikt` int(11) NOT NULL,
  `pTrunckStatus` int(11) NOT NULL,
  `pBoat` int(11) NOT NULL,
  `pBoatPos1` int(11) NOT NULL,
  `pBoatPos2` int(11) NOT NULL,
  `pBoatPos3` int(11) NOT NULL,
  `pBoatPos4` int(11) NOT NULL,
  `pCarStatus` int(11) NOT NULL,
  `pCarPenalty1` int(11) NOT NULL,
  `pCarPenalty2` int(11) NOT NULL,
  `pCarPenalty3` int(11) NOT NULL,
  `pCarPenalty4` int(11) NOT NULL,
  `pCarPenalty5` int(11) NOT NULL,
  `pBronzeRoulette` int(11) NOT NULL,
  `pSilverRoulette` int(11) NOT NULL,
  `pGoldRoulette` int(11) NOT NULL,
  `pRouletteMoney` int(11) NOT NULL,
  `pAnswerYes` int(11) NOT NULL,
  `pAnswerNo` int(11) NOT NULL,
  `pVehicleNumberOne` varchar(30) CHARACTER SET utf8 NOT NULL,
  `pVehicleNumberTwo` varchar(30) CHARACTER SET utf8 NOT NULL,
  `pVehicleNumberThree` varchar(30) CHARACTER SET utf8 NOT NULL,
  `pVehicleNumberFour` varchar(30) CHARACTER SET utf8 NOT NULL,
  `pVehicleNumberFive` varchar(30) CHARACTER SET utf8 NOT NULL,
  `pOwnerChat` int(11) NOT NULL,
  `last_pX` float NOT NULL,
  `last_pY` float NOT NULL,
  `last_pZ` float NOT NULL,
  `last_pA` float NOT NULL,
  `last_VW` int(11) NOT NULL,
  `last_INT` int(11) NOT NULL,
  `pTurbo` int(11) NOT NULL,
  `pBoombox` int(11) NOT NULL,
  `pSecretAdmin` int(11) NOT NULL,
  `pCarHouse` int(11) NOT NULL,
  `pNewModskin` int(11) NOT NULL,
  `pPinCode` int(11) NOT NULL,
  `pPinCodeHave` int(11) NOT NULL,
  `pInvItem1` int(11) NOT NULL,
  `pInvItem2` int(11) NOT NULL,
  `pInvItem3` int(11) NOT NULL,
  `pInvItem4` int(11) NOT NULL,
  `pInvItem5` int(11) NOT NULL,
  `pInvItem6` int(11) NOT NULL,
  `pInvItem7` int(11) NOT NULL,
  `pInvItem8` int(11) NOT NULL,
  `pInvItem9` int(11) NOT NULL,
  `pInvItem10` int(11) NOT NULL,
  `pInvItem11` int(11) NOT NULL,
  `pInvItem12` int(11) NOT NULL,
  `pInvItem13` int(11) NOT NULL,
  `pInvItem14` int(11) NOT NULL,
  `pInvItem15` int(11) NOT NULL,
  `pInvItem16` int(11) NOT NULL,
  `pInvItem17` int(11) NOT NULL,
  `pInvItem18` int(11) NOT NULL,
  `pInvItem19` int(11) NOT NULL,
  `pInvItem20` int(11) NOT NULL,
  `pInvItem21` int(11) NOT NULL,
  `pInvItem22` int(11) NOT NULL,
  `pInvItem23` int(11) NOT NULL,
  `pInvItem24` int(11) NOT NULL,
  `pInvItem25` int(11) NOT NULL,
  `pCasinoBlock` int(11) NOT NULL,
  `pGoldCard` int(11) NOT NULL,
  `pGoldTime` int(11) NOT NULL,
  `pMedCard` int(11) NOT NULL,
  `pQuestUsed` int(11) NOT NULL,
  `pNarcoLomka` int(11) NOT NULL,
  `pUsedAcs1` int(11) NOT NULL,
  `pUsedAcs2` int(11) NOT NULL,
  `pUsedAcs3` int(11) NOT NULL,
  `pUsedAcs4` int(11) NOT NULL,
  `pUsedAcs5` int(11) NOT NULL,
  `pUsedAcs6` int(11) NOT NULL,
  `pUsedAcs7` int(11) NOT NULL,
  `pUsedAcs8` int(11) NOT NULL,
  `pDirectory` int(11) NOT NULL,
  `pWater` int(11) NOT NULL,
  `pFood` int(11) NOT NULL,
  `pChanta` int(11) NOT NULL,
  `pRobCar` int(11) NOT NULL,
  `pDonatemoneys` int(11) NOT NULL,
  `pRouletMoney` int(11) NOT NULL,
  `pMobileBank` int(11) NOT NULL,
  `pMBCode` int(11) NOT NULL,
  `pParkPerm` int(11) NOT NULL,
  `pParkTime` int(11) NOT NULL,
  `pParkingUse` int(11) NOT NULL,
  `pParkX` float NOT NULL,
  `pParkY` float NOT NULL,
  `pParkZ` float NOT NULL,
  `pParkC` float NOT NULL,
  `pSupport` int(11) NOT NULL,
  `pTireStatus` int(11) NOT NULL,
  `pInvDeagle` int(11) NOT NULL,
  `pInvM4` int(11) NOT NULL,
  `pInvMP5` int(11) NOT NULL,
  `pInvFood` int(11) NOT NULL,
  `pInvDrink` int(11) NOT NULL,
  `pDazgveva` int(11) NOT NULL,
  `pDazgveva1` int(11) NOT NULL,
  `pDazgveva2` int(11) NOT NULL,
  `pDazgveva3` int(11) NOT NULL,
  `pDazgveva4` int(11) NOT NULL,
  `pFuel` int(11) NOT NULL,
  `pFuelcar` float NOT NULL,
  `pFuelcar1` float NOT NULL,
  `pFuelcar2` float NOT NULL,
  `pFuelcar3` float NOT NULL,
  `pFuelcar4` float NOT NULL,
  `pQurdi` int(11) NOT NULL,
  `pPrefix` varchar(128) COLLATE cp1251_bin NOT NULL,
  `pTicketStatus` int(11) NOT NULL,
  `pTotalTicket` int(11) NOT NULL,
  `pBlockedCard` int(11) NOT NULL,
  `pSupportWarning` int(11) NOT NULL,
  `pGiftCoin` int(11) NOT NULL,
  `pGiftTiming` int(11) NOT NULL,
  `pGiftHour` int(11) NOT NULL,
  `pGiftMin` int(11) NOT NULL,
  `pGiftSec` int(11) NOT NULL,
  `pRoadBlock` int(11) NOT NULL,
  `pDeadPool` int(11) NOT NULL,
  `pGaataraPayday` int(11) NOT NULL,
  `pTakedGifts` int(11) NOT NULL,
  `pDaeswroPaydays` int(11) NOT NULL,
  `pNarkoTime` int(11) NOT NULL,
  `pLari` int(11) NOT NULL,
  `pVideoCard` int(11) NOT NULL,
  `pKarta` int(11) NOT NULL,
  `pBITCOIN` int(11) NOT NULL,
  `pPadvali` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin;

-- --------------------------------------------------------

--
-- Table structure for table `admin_ips`
--

CREATE TABLE `admin_ips` (
  `ID` int(11) NOT NULL,
  `nick` varchar(45) COLLATE cp1251_bin NOT NULL,
  `ip` varchar(127) COLLATE cp1251_bin NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin;

--
-- Dumping data for table `admin_ips`
--

INSERT INTO `admin_ips` (`ID`, `nick`, `ip`) VALUES
(1, 'Aleksandre_Kinkladze', '82.211.147.159'),
(2, 'Lucky_White', '149.34.244.151');

-- --------------------------------------------------------

--
-- Table structure for table `anticheat_settings`
--

CREATE TABLE `anticheat_settings` (
  `ac_code` int(2) NOT NULL,
  `ac_code_trigger_type` int(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `anticheat_settings`
--

INSERT INTO `anticheat_settings` (`ac_code`, `ac_code_trigger_type`) VALUES
(0, 1),
(1, 1),
(2, 1),
(3, 1),
(4, 1),
(5, 1),
(6, 1),
(7, 1),
(8, 2),
(9, 0),
(10, 1),
(11, 1),
(12, 1),
(13, 0),
(14, 0),
(15, 2),
(16, 1),
(17, 1),
(18, 1),
(19, 1),
(20, 1),
(21, 2),
(22, 1),
(23, 2),
(24, 2),
(25, 1),
(26, 1),
(27, 2),
(28, 1),
(29, 1),
(30, 1),
(31, 2),
(32, 1),
(33, 1),
(34, 1),
(35, 1),
(36, 0),
(37, 0),
(38, 0),
(39, 1),
(40, 1),
(41, 0),
(42, 0),
(43, 2),
(44, 1),
(45, 1),
(46, 1),
(47, 2),
(48, 0),
(49, 1),
(50, 2),
(51, 2),
(52, 0);

-- --------------------------------------------------------

--
-- Table structure for table `autosalon`
--

CREATE TABLE `autosalon` (
  `ID` int(11) NOT NULL,
  `CarPosX` float NOT NULL,
  `CarPosY` float NOT NULL,
  `CarPosZ` float NOT NULL,
  `CarPosC` float NOT NULL,
  `CarOwner` varchar(32) NOT NULL,
  `CarID` int(11) NOT NULL,
  `CarPrice` int(11) NOT NULL,
  `CarStatus` int(11) NOT NULL,
  `CarSlot` int(11) NOT NULL,
  `CarTime` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `autosalon`
--

INSERT INTO `autosalon` (`ID`, `CarPosX`, `CarPosY`, `CarPosZ`, `CarPosC`, `CarOwner`, `CarID`, `CarPrice`, `CarStatus`, `CarSlot`, `CarTime`) VALUES
(1, 1410.37, -2262.07, 13.2275, 0, 'None', 462, 0, 0, 0, 0),
(2, 1403.85, -2262.07, 13.2275, 0, 'Tony_Beliakovi', 543, 200000000, 1, 3, 1),
(3, 1397.3, -2262.07, 13.2275, 0, 'Nizam_Padishah', 579, 35000000, 1, 1, 0),
(4, 1390.7, -2262.07, 13.2275, 0, 'None', 462, 0, 0, 0, 0),
(5, 1384.14, -2262.07, 13.2275, 0, 'None', 462, 0, 0, 0, 0),
(6, 1411.3, -2242.38, 13.2275, 180, 'Georg_Anderson', 533, 90000000, 1, 2, 0),
(7, 1404.78, -2242.39, 13.2275, 180, 'Murman_Manjavidze', 475, 150000000, 1, 4, 1),
(8, 1398.25, -2242.39, 13.2275, 180, 'None', 462, 0, 0, 0, 0),
(9, 1391.7, -2242.39, 13.2275, 180, 'None', 462, 0, 0, 0, 0),
(10, 1385.15, -2242.39, 13.2275, 180, 'None', 462, 0, 0, 0, 0),
(11, 1411.28, -2225.13, 13.2275, 0, 'None', 462, 0, 0, 0, 0),
(12, 1404.75, -2225.13, 13.2275, 0, 'None', 462, 0, 0, 0, 0),
(13, 1398.15, -2225.13, 13.2275, 0, 'None', 462, 0, 0, 0, 0),
(14, 1391.65, -2225.13, 13.2275, 0, 'None', 462, 0, 0, 0, 0),
(15, 1385.05, -2225.14, 13.2275, 0, 'None', 462, 0, 0, 0, 0),
(16, 1411.33, -2207.99, 13.2275, 180, 'Vako_Siradzee', 496, 3000000, 1, 2, 1),
(17, 1404.8, -2208, 13.2275, 180, 'None', 462, 0, 0, 0, 0),
(18, 1398.2, -2208, 13.2275, 180, 'None', 462, 0, 0, 0, 0),
(19, 1391.65, -2208.01, 13.2275, 180, 'None', 462, 0, 0, 0, 0),
(20, 1385.12, -2208.01, 13.2275, 180, 'None', 462, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `banip`
--

CREATE TABLE `banip` (
  `ID` int(11) NOT NULL,
  `IP` varchar(128) CHARACTER SET cp1251 COLLATE cp1251_bin NOT NULL,
  `Dge` int(11) NOT NULL,
  `Admin` varchar(128) CHARACTER SET cp1251 COLLATE cp1251_bin NOT NULL,
  `Tarigi` varchar(128) CHARACTER SET cp1251 COLLATE cp1251_bin NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=cp1251;

-- --------------------------------------------------------

--
-- Table structure for table `banlog`
--

CREATE TABLE `banlog` (
  `ID` int(11) NOT NULL,
  `Text` varchar(255) NOT NULL,
  `Name` varchar(128) NOT NULL,
  `NameAdmin` varchar(128) NOT NULL,
  `Date` varchar(128) NOT NULL,
  `Day` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=cp1251;

-- --------------------------------------------------------

--
-- Table structure for table `bizz`
--

CREATE TABLE `bizz` (
  `bID` int(11) NOT NULL,
  `bOwned` int(11) NOT NULL,
  `bOwner` varchar(32) NOT NULL,
  `bMessage` varchar(64) NOT NULL,
  `bEntranceX` float NOT NULL,
  `bEntranceY` float NOT NULL,
  `bEntranceZ` float NOT NULL,
  `bExitX` float NOT NULL,
  `bExitY` float NOT NULL,
  `bExitZ` float NOT NULL,
  `bBuyPrice` int(11) NOT NULL,
  `bEntranceCost` int(11) NOT NULL,
  `bTill` int(11) NOT NULL,
  `bInterior` int(11) NOT NULL,
  `bProducts` int(11) NOT NULL,
  `bPrice` int(11) NOT NULL,
  `bBarX` float NOT NULL,
  `bBarY` float NOT NULL,
  `bBarZ` float NOT NULL,
  `bMafia` int(11) NOT NULL,
  `bType` int(11) NOT NULL,
  `bVirtualWorld` int(11) NOT NULL,
  `bEnterPosX` float NOT NULL,
  `bEnterPosY` float NOT NULL,
  `bEnterPosZ` float NOT NULL,
  `bExitPosX` float NOT NULL,
  `bExitPosY` float NOT NULL,
  `bExitPosZ` float NOT NULL,
  `bStavka` int(11) NOT NULL,
  `bNameStavka` varchar(50) NOT NULL,
  `bLastStavka` int(11) NOT NULL,
  `bTimeStavka` int(11) NOT NULL,
  `bMinStavka` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `bizz`
--

INSERT INTO `bizz` (`bID`, `bOwned`, `bOwner`, `bMessage`, `bEntranceX`, `bEntranceY`, `bEntranceZ`, `bExitX`, `bExitY`, `bExitZ`, `bBuyPrice`, `bEntranceCost`, `bTill`, `bInterior`, `bProducts`, `bPrice`, `bBarX`, `bBarY`, `bBarZ`, `bMafia`, `bType`, `bVirtualWorld`, `bEnterPosX`, `bEnterPosY`, `bEnterPosZ`, `bExitPosX`, `bExitPosY`, `bExitPosZ`, `bStavka`, `bNameStavka`, `bLastStavka`, `bTimeStavka`, `bMinStavka`) VALUES
(1, 1, 'Soso_Willson', 'Alhambra', 1836.51, -1682.58, 13.345, 493.487, -24.9609, 1000.67, 15000000, 1000, 24603, 17, 5388, 1000, 499.97, -20.7076, 1000.68, 6, 1, 1, 1834.31, -1682.79, 13.4367, 492.998, -22.1078, 1000.68, 0, '', 0, 0, 0),
(2, 1, 'Irakli_Machxaneli', 'PigPen', 2421.59, -1219.51, 25.5444, 1204.67, -13.8521, 1000.92, 15000000, 100, 700, 2, 19976, 1000, 1215.29, -13.2987, 1000.92, 5, 1, 2, 2421.25, -1221.78, 25.3987, 1205.03, -11.4166, 1000.92, 0, '', 0, 0, 0),
(3, 1, 'Andria_Axalaia', 'Seven Supermarket', 1112.04, -1370.03, 13.9844, 2586, 1437.58, 1800.97, 20000000, 1000, 963799, 6, 7164, 1000, 2580.79, 1424.88, 1800.97, 6, 3, 3, 1030.29, 1847.8, 11.4683, -2240.47, 137.06, 1035.41, 0, '', 0, 0, 0),
(4, 1, 'Aleksandre_Kinkladze', 'Casino Adjara', 2019.6, 1007.8, 10.8203, 1133.19, -15.8001, 1000.68, 1000000000, 1000, 234920899, 12, 25000, 1000, 0, 0, 0, 6, 2, 4, 2021.64, 1007.76, 10.8203, 1133.09, -12.6875, 1000.68, 0, '', 0, 0, 0),
(5, 1, 'Luka_Khutsishvili', 'Grove Street Bar', 2309.95, -1643.42, 14.8269, 501.903, -67.563, 998.758, 10000000, 1000, 3000, 11, 9958, 1000, 497.353, -76.0409, 998.758, 5, 1, 5, 2309.99, -1645.96, 14.827, 501.739, -69.8445, 998.758, 0, '', 0, 0, 0),
(6, 1, 'Bigjaz_Brooson', 'Seven Supermarket', 1445.11, -1418.48, 13.5409, 2586, 1437.58, 1800.97, 10000000, 1000, 252400, 6, 2740, 1000, 2580.79, 1424.88, 1800.97, 5, 3, 6, 1531.59, 2705.88, 10.8125, -2238.59, 136.443, 1035.41, 0, '', 0, 0, 0),
(7, 1, 'Hardin_Scott', 'Idelwood 24/7', 1928.6, -1776.17, 13.5468, 2586, 1437.58, 1800.97, 20000000, 1000, 724331, 6, 1558, 1000, 2580.79, 1424.88, 1800.97, 6, 3, 12, 1930.81, -1776.1, 13.5469, -2239.64, 134.628, 1035.41, 0, '', 0, 0, 0),
(8, 1, 'Tedo_Axalaia', 'MiniMarket', 1833.78, -1842.6, 13.5781, 2586, 1437.58, 1800.97, 20000000, 1000, 3110200, 6, 6927, 1000, 2580.79, 1424.88, 1800.97, 6, 3, 14, 1830.92, -1842.62, 13.5781, -2238.47, 136.996, 1035.41, 0, '', 0, 0, 0),
(9, 1, 'Aleks_Johnos', 'Mullholand 24/7', 1000.59, -919.911, 42.328, 2586, 1437.58, 1800.97, 20000000, 1000, 8509800, 6, 13404, 1000, 2580.79, 1424.88, 1800.97, 6, 3, 15, 997.831, -919.912, 42.1797, -2238.12, 136.471, 1035.41, 0, '', 0, 0, 0),
(10, 1, 'Sasha_Boyka', 'Jizzy', 1419.27, -1640.18, 13.5469, -2636.68, 1402.46, 906.461, 1000000000, 0, 0, 3, 20000, 1000, -2654.02, 1407.91, 906.277, 6, 1, 16, -2623.64, 1409, 7.1016, -2639.81, 1405.72, 906.461, 0, '', 0, 0, 0),
(11, 1, 'Guga_Kalashnikov', 'Seven Supermarket', 1315.51, -898.154, 39.5781, 2586, 1437.58, 1800.97, 20000000, 100, 4702800, 6, 2419, 1000, 2580.79, 1424.88, 1800.97, 6, 3, 17, 1600.29, 2220.33, 11.0625, -2237.77, 137.028, 1035.41, 0, '', 0, 0, 0),
(12, 1, 'Soul_Corleone', 'Smart', 2481.59, -1758.02, 13.5469, 2586, 1437.58, 1800.97, 20000000, 0, 17200, 6, 19831, 1000, 2580.79, 1424.88, 1800.97, 6, 3, 18, 2482.02, -1755.31, 13.5469, -2237.77, 136.906, 1035.41, 0, '', 0, 0, 0),
(13, 1, 'Xurci_Falconry', 'Night Market', 2502.58, 1622.59, 10.8203, 2586, 1437.58, 1800.97, 20000000, 1000, 42900, 6, 19019, 1000, 2580.79, 1424.88, 1800.97, 6, 3, 19, 2502.35, 1620.36, 10.8203, -2237.63, 136.591, 1035.41, 0, '', 0, 0, 0),
(14, 1, 'Federico_Restock', 'Idelwood Gas', 1940.93, -1772.94, 13.6406, 0, 0, 0, 10000000, 0, 19807, 0, 9900, 1000, 0, 0, 0, 6, 4, 20, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0),
(15, 0, 'The State', 'Mullholand Gas', 1003.76, -936.11, 42.3281, 0, 0, 0, 10000000, 0, 0, 0, 0, 1000, 0, 0, 0, 6, 4, 21, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0),
(16, 1, 'Frady_Parker', 'Nikora', 1352.35, -1759.25, 13.5078, 2586, 1437.58, 1800.97, 1000000000, 1000, 27681100, 6, 4847326, 1000, 2580.79, 1424.88, 1800.97, 6, 3, 22, 1352.67, -1757.1, 13.5078, -2238.27, 136.885, 1035.41, 0, '', 0, 0, 0),
(17, 1, 'Ponchika_Lansky', 'Cerry Market', 2007.42, 1167.46, 10.8203, 2586, 1437.58, 1800.97, 20000000, 0, 16400, 6, 16815, 1000, 2580.79, 1424.88, 1800.97, 6, 3, 24, 2009.87, 1167.22, 10.8203, -2238.16, 137.334, 1035.41, 0, '', 0, 0, 0),
(18, 1, 'Diego_Rose', 'Grey Market', 1207.18, -1459.7, 13.3828, 2586, 1437.58, 1800.97, 20000000, 100, 0, 0, 20000, 500, 0, 0, 0, 6, 3, 30, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0),
(19, 1, 'Kawie_Falcone', 'LS Bank', 1411.63, -1699.61, 13.5395, 304.781, 1329.32, 2023.84, 50000000, 1000, 52473, 1, 25000, 1000, 0, 0, 0, 6, 5, 15, 1461.86, -1013.85, 26.7938, 1319.33, 12.4075, 2068.51, 0, '', 0, 0, 0),
(20, 1, 'Tomass_Black', 'Magniti 24/7', 387.88, -1836.34, 7.8359, 2586, 1437.58, 1800.97, 10000000, 1000, 15000, 6, 7127, 1000, 2580.79, 1424.88, 1800.97, 6, 3, 25, 1930.81, -1776.1, 13.5469, -2239.64, 134.628, 1035.41, 0, '', 0, 0, 0),
(21, 1, 'Noah_Reyli', 'GunShop', 1368.99, -1279.7, 13.5469, 315.783, -143.665, 999.602, 10000000, 1000, 6072000, 7, 25000, 1000, -2236.11, 130.158, 1035.41, 6, 5, 0, 1930.81, -1776.1, 13.5469, -2239.64, 134.628, 1035.41, 0, '', 0, 0, 0),
(22, 0, 'The State', 'SkinShop', 461.711, -1500.84, 31.0448, 207.031, -140.376, 1003.51, 10000000, 1000, 24235200, 3, 2000, 1000, 0, 0, 0, 6, 5, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0),
(23, 1, 'Son_Hells', 'Ori Nabiji', 1328.92, -1557.57, 13.5469, 2586, 1437.58, 1800.97, 20000000, 0, 1000, 6, 19803, 1000, 2580.79, 1424.88, 1800.97, 6, 3, 23, 1356.35, -1550.04, 13.5469, -2238.27, 136.885, 1035.41, 0, '', 0, 0, 0),
(24, 1, 'Eazy_Rasala', 'Club QuissKhana', 512.008, -1486.86, 14.5116, -2636.68, 1402.46, 906.461, 1000000000, 1000, 18000, 3, 18322, 1000, -2654.02, 1407.91, 906.277, 6, 1, 19, -2623.64, 1409, 7.1016, -2639.81, 1405.72, 906.461, 0, '', 0, 0, 0),
(25, 0, 'The State', 'Gulf Store', -1676, 432.099, 7.1797, 2586, 1437.58, 1800.97, 20000000, 0, 0, 6, 0, 1000, 2580.79, 1424.88, 1800.97, 6, 3, 26, 1356.35, -1550.04, 13.5469, -2238.27, 136.885, 1035.41, 0, '', 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `carhousebase`
--

CREATE TABLE `carhousebase` (
  `ID` int(11) NOT NULL,
  `Owner` varchar(24) DEFAULT NULL,
  `Class` int(11) NOT NULL DEFAULT 0,
  `Lock` int(11) NOT NULL DEFAULT 0,
  `Color` int(11) NOT NULL DEFAULT 0,
  `CamperPosX` float NOT NULL DEFAULT 0,
  `CamperPosY` float NOT NULL DEFAULT 0,
  `CamperPosZ` float NOT NULL DEFAULT 0,
  `CamperPosA` float NOT NULL DEFAULT 0
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- --------------------------------------------------------

--
-- Table structure for table `carkeys`
--

CREATE TABLE `carkeys` (
  `ID` int(11) NOT NULL,
  `Owner` varchar(28) NOT NULL,
  `Player` varchar(28) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `cmds`
--

CREATE TABLE `cmds` (
  `Name` varchar(45) CHARACTER SET cp1251 COLLATE cp1251_bin NOT NULL,
  `CMD` varchar(45) CHARACTER SET cp1251 COLLATE cp1251_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `cmds`
--

INSERT INTO `cmds` (`Name`, `CMD`) VALUES
('Max_Harris', 'mafialeader'),
('Goldz_Kartvela', 'gangleader'),
('Lucky_White', 'otherleader'),
('Luka_Xizanashvili', 'supporttest');

-- --------------------------------------------------------

--
-- Table structure for table `family`
--

CREATE TABLE `family` (
  `FamilyID` int(11) NOT NULL,
  `FamilyName` varchar(20) NOT NULL,
  `FamilyLeader` varchar(32) NOT NULL,
  `FamilyCoLeader` varchar(32) NOT NULL,
  `FamilyType` int(11) NOT NULL,
  `FamilyColor` int(11) NOT NULL,
  `FamilyHouseID` int(11) NOT NULL,
  `FamilySkinID` int(11) NOT NULL,
  `FamilyMaterials` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `family`
--

INSERT INTO `family` (`FamilyID`, `FamilyName`, `FamilyLeader`, `FamilyCoLeader`, `FamilyType`, `FamilyColor`, `FamilyHouseID`, `FamilySkinID`, `FamilyMaterials`) VALUES
(1, 'Anderson', 'David_Anderson', 'Garik_Anderson', 1, 13, 999, 102, 670091),
(2, 'Vikings', 'Jonnie_Anderson', 'None', 1, 13, 836, 102, 0),
(3, 'Sorryiwin', 'Giorgi_Nozadze', 'Arekoj_Yksnabusizav', 1, 11, 999, 49, 0),
(4, 'Troller', 'Biwadze_King', 'None', 3, 16, 999, 203, 1000),
(5, 'MS 13 Gang', 'Miki_Zetas', 'Gon_Zetas', 1, 13, 537, 107, 101020),
(6, 'Bucxrika', 'Xurci_Falconry', 'None', 3, 11, 999, 107, 1000),
(7, 'Qurdixar', 'Tobias_Bondys', 'None', 1, 13, 999, 149, 101000),
(8, 'Red Evils', 'Giorgi_Ruxadze', 'None', 3, 13, 999, 102, 100000),
(9, 'Bandidos', 'Ragnar_Lodbrok', 'Ponchika_Lansky', 1, 2, 999, 264, 2022328),
(10, 'Lovers', 'Nica_Williams', 'None', 5, 13, 999, 230, 19950),
(11, 'TAL1BAN', 'Abraham_Valasquez', 'None', 6, 11, 999, 107, 609903),
(12, 'Scaglietti', 'Tommy_Vercetti', 'Vasili_Petrovich', 5, 10, 999, 173, 999075),
(13, 'Pajarnikk', 'Xamshikka_Pajarnik', 'Alex_Chutkera', 3, 13, 454, 279, 1118800),
(14, 'Syndicate', 'Yuri_Boyka', 'John_Lee', 4, 13, 149, 271, 2140876),
(15, 'K.O.N.O.', 'Leonardo_Davinch', 'None', 6, 5, 999, 203, 20375),
(16, 'BARATHEON', 'Lubecki_Jhonson', 'Luke_Jefferson', 1, 0, 999, 230, 700),
(17, 'The Budzex', 'Tony_Stark', 'None', 7, 13, 880, 279, 300700),
(18, 'S.N.O.W', 'Brian_Grate', 'Freddy_Williams', 4, 9, 999, 124, 320005),
(19, 'Sureno St.', 'Alex_Mazer', 'None', 1, 9, 999, 230, 4448035),
(20, '<KING>', 'Isaac_King', 'Tedo_Xatidzee', 6, 9, 999, 102, 102000),
(21, 'Ruxexx', 'Gio_Ruxadze', 'None', 1, 15, 999, 230, 0),
(22, '48 Impulse', 'Glock_Impulse', 'None', 2, 3, 999, 271, 235500),
(23, 'Almighty', '186 0', 'None', 1, 14, 999, 230, 199877),
(24, 'Vatutino', 'Tommy_Milner', 'Murdoc_Milner', 1, 19, 999, 19, 89300),
(25, 'Uchiha', 'Eazy_Rider', 'None', 1, 6, 999, 230, 201000),
(26, '#Mefeebi', 'Xurci_Falconry', 'None', 3, 13, 999, 22, 7612850),
(27, 'Casino <3', 'Bukhra_Brown', 'Tony_Goldmeno', 1, 15, 999, 195, 223000),
(28, 'TSLrojebi', 'Alexi_Xuroshvili', 'None', 2, 11, 999, 294, 130000),
(29, 'Scarface', 'James_Glik', 'None', 5, 18, 999, 10, 45),
(30, 'JeansGeneration', 'Harley_Milner', 'Sandro_Paul', 1, 9, 999, 252, 0),
(31, 'Slayers ', 'Medic_Slayer', 'Tatsumi_Slayer', 1, 13, 999, 230, 0),
(32, 'LeosSadzmo', 'Xurci_Falconry', 'None', 1, 2, 999, 115, 1239350),
(33, 'Matterazzo', 'Tonny_Kingston', 'Gazallo_Matterazzo', 1, 13, 999, 114, 1269055),
(34, '¶°•JDM•°¶', 'Sebastian_Wiliams', 'None', 7, 13, 999, 116, 200050),
(35, 'Prada', 'Rage_Prada', 'Harvin_Welaso', 2, 6, 999, 230, 0),
(36, 'noFaceGanq', 'Guro_Bigubdate', 'Guro_Gamer', 2, 6, 999, 230, 368999),
(37, 'RESTOCK', 'Federico_Restock', 'None', 7, 6, 999, 230, 2389800),
(38, 'Camorra', 'Luka_Khutsoshvili', 'Natlia_Corleone', 1, 13, 999, 97, 334850),
(39, 'Umbrella', 'Misho_Topuria', 'None', 4, 13, 999, 285, 1706928),
(40, 'StoneStreetRasala', 'nSP.Serendipity', 'None', 1, 5, 999, 230, 1376502),
(41, 'Corleone', 'Tony_Morningstar', 'None', 1, 13, 999, 230, 20000),
(42, 'Pajarnik', 'Biwadze_King', 'None', 1, 0, 999, 279, 0),
(43, 'JUICE 1970', 'Naamah_Yggrasil', 'Shavi_Yggrasil', 2, 15, 999, 107, 1080200),
(44, 'Luther', 'Vato_Gorgiladze', 'Beqa_Chachua', 1, 13, 390, 173, 1929747),
(45, 'Government', 'Giorgi_Shekriladze', 'Shota_Rustaveli', 4, 11, 999, 230, 1401400),
(46, 'The Blood$', 'Dato_Cirekidze', 'None', 1, 13, 999, 173, 205),
(47, 'FireDept.', 'Niikusha_Abashiidze', 'None', 3, 13, 999, 61, 343985),
(48, 'SETOS', 'Boogie_Bando', 'None', 1, 9, 999, 29, 236161),
(49, 'Babulikebi', 'Max_Wilsoni', 'None', 1, 19, 999, 294, 274634),
(50, 'GSC Niggaz', 'Frady_Parker', 'Deme_Sane', 0, 0, 999, 277, 585039),
(51, 'PRIMEIRO', 'Curse_Primeiro', 'None', 1, 15, 999, 252, 822000),
(52, 'Gilmore', 'Frank_Gilmore', 'None', 3, 2, 999, 230, 210),
(53, 'Old Rogers', 'Luka_Makharoblidze', 'None', 1, 13, 999, 116, 100000),
(54, 'Blackwood', 'Beqson_Blackwood', 'None', 1, 2, 999, 120, 569222),
(55, 'Kapono', 'Al_Kapono', 'None', 0, 0, 0, 0, 0),
(56, 'LAMYAT', 'Nika_Sadoiani', 'None', 1, 13, 999, 230, 104000),
(57, 'WHITE', 'Luka_White', 'None', 3, 13, 999, 203, 99025),
(58, 'Beats', 'Temuka_Gelashvili', 'Giorgi_Woworia', 1, 13, 999, 140, 999800),
(59, 'Goldminee', 'Tony_Goldminee', 'None', 1, 15, 999, 102, 200041),
(60, 'mind 90 s', 'James_Masson', 'None', 1, 13, 999, 61, 48726),
(61, 'Asesinos', 'ROOT', 'None', 6, 13, 999, 294, 430001),
(62, 'NORTE XIV', 'Tayvion_Gerrard', 'None', 7, 13, 999, 230, 10001),
(63, 'Wu Tang', 'Fushiguro_Megumi', 'None', 6, 13, 999, 102, 98550),
(64, 'Gruzinsky', 'David_Mirzoev', 'None', 1, 7, 999, 272, 0),
(65, 'Soviet', 'Koki_Jonson', 'None', 1, 17, 999, 68, 0),
(66, 'Paradise', 'Koll_Mikelson', 'None', 1, 2, 999, 106, 99350),
(67, 'McDock', 'Demon_Shinki', 'Spooky_McDock', 1, 13, 999, 104, 1017851),
(68, 'Felony', 'Lil_Felony', 'None', 1, 1, 999, 298, 200000),
(69, 'Old School', 'Kniaz_Sunjaevi', 'Gia_Kallashnikov', 0, 19, 999, 203, 0),
(70, 'Eucliffe', 'Zura_Eucliffe', 'Uta_Eucliffe', 1, 14, 999, 149, 401799),
(71, 'SwissGuard', 'Kodak_Blizzard', 'Fernando_Sucre', 0, 8, 999, 241, 0),
(72, 'Blackstar', 'Rezi_Blackstar', 'Maverick_Blackstar', 1, 13, 999, 155, 723850),
(73, 'DAnGeLO', 'Giorgi_Macharashvili', 'Rezi_Chxikvadze', 1, 2, 999, 108, 0),
(74, 'Skrezz', 'Noname_Boss', 'Angel_Skrezz', 1, 13, 999, 230, 961198),
(75, 'SKREEZ', 'Beqa_Sixarulidze', 'None', 1, 3, 999, 116, 19301),
(76, 'Them TKC', 'King_Pachko', 'None', 1, 15, 999, 241, 200030),
(77, '*SUS*', 'Rey_Sanchez', 'None', 3, 11, 999, 106, 0),
(78, '-BAD.BOYS-', 'Deny_Devito', 'Donie_Willson', 3, 13, 999, 264, 900874),
(79, 'P.I.X.E.L', 'No_Baby', 'None', 1, 13, 999, 203, 10000),
(80, 'Ganabebi', 'Georg_Anderson', 'None', 1, 3, 999, 292, 0),
(81, 'KazinoKing', 'Jack_Frost', 'None', 1, 13, 999, 203, 100000),
(82, 'BigNiggas~', 'Shyxz_Painz', 'None', 1, 19, 999, 116, 0),
(83, 'Batumski', 'Zuka_Nakasha', 'None', 0, 13, 999, 230, 0),
(84, 'Buggers', 'Asterex_Msroleli', 'None', 4, 13, 999, 173, 0),
(85, 'AMIIN', 'Sofia_Amn', 'None', 1, -1, 999, 195, 0),
(86, '48Street ', 'Kobrava', 'None', 1, 19, 999, 230, 1),
(87, 'Blackstarr', 'Maverick_Blackstar', 'Tupac_Shakury', 1, 0, 999, 108, 61420),
(88, 'StreetGXNG', 'Aliance_Sage', 'Dato_Kepashvili', 1, 11, 999, 230, 400000),
(89, 'Adams', 'Tony_Adams', 'Karchav_Adams', 7, 9, 999, 149, 0),
(90, 'The Bigs', 'Luka_Nation', 'Devil_Interactive', 1, 6, 999, 102, 100001),
(91, 'Legends', 'Donnie_Anderson', 'None', 6, 16, 999, 240, 1000),
(92, '°¶TRADE¶°', 'Sergo_Nemsadze', 'Nika_Bakuridze', 4, 19, 999, 167, 100000),
(93, 'Westies', 'Bob_Westie', 'Dansky_Westie', 1, 6, 999, 116, 50500),
(94, 'Sukonka', 'Carco_Shinki', 'Tengiz_Malaymadze', 7, 6, 999, 287, 300400),
(95, 'Clowtons', 'Pain_Clowton', 'None', 7, 13, 999, 28, 0),
(96, 'Dacva', 'Karela', 'Xupe_Shniki', 4, 8, 999, 285, 0),
(97, '>{METRO}<', 'Ani_Metreveli', 'None', 1, 13, 999, 172, 0),
(98, 'Alania', 'Daci_Alania', 'King_Tam', 0, 13, 999, 253, 0),
(99, '>MONTANA<', 'Jhonny_Montana', 'None', 1, 9, 999, 174, 0),
(100, 'DIDKLIANI', 'Yung_Melleme', 'None', 2, 6, 999, 230, 0),
(101, 'VERSACE', 'Tengiza_Maziashvili', 'Bacho_Lataria', 1, 0, 999, 230, 715100),
(102, 'Impala', 'Cold_Thmicy', 'Hustlah_Impala', 1, 6, 999, 230, 600000),
(103, 'Kortesia', 'Fallen', 'None', 1, 6, 999, 230, 0),
(104, 'Rustavsky', 'Zvezda_Onia', 'Victor_Orena', 7, 3, 999, 293, 0),
(105, 'Nemsa', 'Sergo_Nemsadze', 'Tony_Enkeyes', 0, 13, 999, 104, 0),
(106, 'AlbanianMF', 'Darshon_Foster', 'None', 5, 13, 999, 124, 100100),
(107, 'Toman', 'Sebastian_Malboro', 'None', 2, 13, 999, 116, 320110),
(108, '>BATUMSKI<', 'Samo_Batumski', 'None', 0, 3, 999, 30, 0),
(109, 'Hesoyam', 'Mate_Rikadze', 'None', 1, 19, 999, 108, 100000),
(110, 'Avangarde', 'Babu_Black', 'None', 3, 2, 999, 230, 0),
(111, 'Mafia', 'Leon_Wiliams', 'None', 1, 13, 33, 108, 1007600),
(112, 'Drifter', 'Suzi_Drifter', 'Deadly_Drifter', 1, 15, 999, 116, 3018150),
(113, 'Naxalovsky', 'Ikako', 'None', 1, 6, 999, 62, 0),
(114, 'AEZAKMI', 'Klaus_Grimenhausen', 'Sanex_Disaiz', 4, 13, 999, 230, 0),
(115, 'BadBoys', 'Nick_Williamz', 'Nika_Xarshiladze', 3, 7, 999, 203, 0),
(116, 'CAMILLE', 'Camille_Ottoponymi', 'Tolga_Gergishvili', 3, 19, 999, 271, 2),
(117, 'KOSHMARI', 'Tommy', 'Tommy_Mesaflave', 1, 4, 999, 62, 0),
(118, 'Mashvelebi', 'Lasha_Giorgadze', 'None', 3, 19, 999, 230, 0),
(119, '50 Niggaz', 'George_McCalister', 'Big_Noyd', 1, 13, 999, 270, 0),
(120, 'Texassky', 'Saba_Abulashvili', 'Strike_Offer', 1, 13, 999, 230, 0),
(121, 'BLOODS', 'Sarjvela', 'Mamuka_Chagelishvili', 1, 19, 999, 270, 410002),
(122, '{BANDIDOS}', 'Muri_Bandidoss', 'None', 1, 2, 999, 285, 0),
(123, 'Samp-Grup', 'Jack_Willson', 'None', 1, 16, 999, 111, 0),
(124, 'CasinoDone', 'Benjamen_Caligula', 'None', 1, 11, 999, 94, 0),
(125, 'ABASHA', 'Giorgi_Abashidze', 'Tsotne_Ghost', 2, 18, 999, 108, 0),
(126, 'BMW CLUB', 'Frexx_Xkresli', 'Gio_Roinishvili', 1, 13, 999, 271, 0),
(127, 'KJKSZPJ', 'Aleksandre_Kinkladze', 'None', 2, 13, 999, 230, 1200),
(128, 'Wise Fools', 'Shady_Shades', 'Miss_Snake', 0, 13, 999, 116, 0),
(129, 'This If', 'Georg_Anderson', 'Camille_Ottoponymi', 4, 9, 999, 155, 0),
(130, 'Maladoy', 'Tomy_Maladoy', 'Chad_Kruzo', 1, 7, 999, 230, 0),
(131, '90Bulldogs', 'Rick_Desanta', 'Sandrexa_Soxumsky', 0, 5, 999, 230, 0),
(132, 'Samargana', 'Mate_Samarganishvili', 'None', 6, 13, 999, 294, 175000),
(133, 'Aryan', 'Giorgi_Mgeladze', 'None', 3, 3, 999, 116, 99700),
(134, 'S.O.A', 'Niikusha_Abashiidze', 'None', 7, 13, 999, 230, 0),
(135, 'Sulitzangi', 'Tony_Johnos', 'None', 1, 9, 999, 102, 964000),
(136, 'MC Club 0', 'Akaki_Jobava', 'Rollo_Clay', 1, 13, 999, 254, 100011),
(137, 'ALFA King', 'James_Harder', 'Mark_Argikadro', 1, 13, 999, 230, 800002),
(138, 'Argents', 'Tupac_Makaveli', 'None', 1, 8, 999, 116, 0),
(139, 'Valhalla', 'James_Fireman', 'Ikson_Jigante', 7, 19, 999, 116, 91400),
(140, 'Zvezdochka', 'Odell_Qurdinsky', 'None', 0, 18, 999, 126, 0),
(141, 'KarelaGang', 'Dave_Vendetta', 'None', 7, 13, 999, 102, 0),
(142, 'GelashaN1', 'Giorgi_Gelashvili', 'None', 1, 13, 999, 116, 0),
(143, 'samegrelo', 'Mose_Margvelashvili', 'None', 1, 0, 999, 116, 100000),
(144, 'Crips', 'Najaxx_Gorsky', 'None', 1, 19, 999, 116, 0),
(145, 'Colombo', 'Joseph_Colombo', 'Joseph_Yacovelli', 1, 2, 999, 230, 0),
(146, '?MOEBIUS?', 'Sebastian_Malboro', 'Don_Xose', 7, 13, 999, 116, 0),
(147, 'Brown', 'Tony_Johnos', 'Levani_Robbertson', 1, 13, 999, 106, 307000),
(148, 'Bloody', 'Luka_Chubini', 'Mate_Bermudadze', 1, 13, 999, 293, 0),
(149, 'Blaze', 'Natvreye_Blaze', 'Memphis_Blaze', 1, 13, 999, 230, 0),
(150, 'BANDIDO MC', 'Randall_Lanausse', 'None', 1, 16, 999, 230, 0),
(151, '	Colombo', 'Bigjaz_Brooson', 'None', 1, 15, 999, 230, 0),
(152, 'Tactical', 'Giorgi_Taruashvili', 'Deathise_Tripplex', 1, 13, 999, 208, 0),
(153, '$HEGA\"Q\"E', 'Armando_Diaz', 'Lukka_Chaachua', 4, 13, 999, 230, 0),
(154, 'Kutaisi', 'Max_Asa', 'Tornike_Gelashvili', 1, 16, 999, 115, 0),
(155, 'Gotti', 'Kosta_Gotti', 'None', 2, 5, 999, 240, 0),
(156, 'S.O.M', 'Sefo_Lyons', 'None', 5, 13, 999, 230, 0),
(157, 'RACGINDA', 'Aleksandre_Kinkladze', 'Gigi_Bochorishvili', 1, 4, 999, 230, 0),
(158, 'Falcons', 'Tony_Falcone', 'None', 6, 3, 999, 240, 0),
(159, 'GSH Family', 'Zuka_Mumladzs', 'James_Inui', 1, 11, 999, 271, 0),
(160, 'Ruthless Thieves', 'Kevin_Kallashnikov', 'Kosmos_Kallashnikov', 7, 2, 999, 230, 0),
(161, 'OFTEN', 'Alexaa_Morrison', 'Krossline_Often', 1, 19, 999, 230, 0),
(162, 'Hiraeth', 'Shwb_Hiraeth', 'Strike_Offer', 1, 13, 999, 230, 0),
(163, 'ARMENIA', 'Temo_Cagareishvili', 'None', 3, 7, 999, 230, 0),
(164, 'TesliGang', 'Hentai_Skrezz', 'None', 1, 13, 999, 230, 0),
(165, '18th S.G', 'Martin_DIaz', 'Oscar_Diaz', 7, 4, 999, 230, 0),
(166, 'LOTUS', 'Giorgi_Inashvili', 'Leqso_Tabukashvili', 7, 11, 999, 230, 0),
(167, '50Niggaz', 'Ik_Clowton', 'Pain_Clowton', 7, 13, 999, 106, 0),
(168, 'CPlayers >', 'Achi_Todriaa', 'Alkapone_Wich', 4, 13, 999, 303, 0),
(169, 'Flake', 'Giorgi_Gama', 'John_Devis', 5, 3, 999, 106, 0),
(170, 'Regicide', 'Lux_Hardison', 'Mikasa_Ackerman', 5, 6, 999, 195, 0),
(171, 'BlacKStars', 'Lika_Shonia', 'Beqa_Black', 5, 7, 999, 116, 0),
(172, 'Ripper', 'Tony_Goldmeno', 'Xurci_Falconry', 2, 17, 999, 230, 0),
(173, 'Strawhat', 'Nate_Impulse', 'Carl_Weedy', 7, 7, 999, 116, 0),
(174, 'G.M Mafia', 'Hardin_Scott', 'Luka_Xizanashvili', 1, 13, 999, 120, 0),
(175, 'Niggers', 'Levani_Gomurashvili', 'Vexo_Galaxvaridze', 1, 13, 999, 116, 0),
(176, 'Hunters', 'Pablo_Escobarii', 'None', 0, 2, 999, 230, 0),
(177, 'sherekili', 'Levan_Brown', 'None', 3, 19, 330, 230, 0),
(178, 'Mxedrions', 'Zuka_Mumladzs', 'None', 7, 13, 999, 119, 0),
(179, 'Black', 'Denny_Black', 'Luke_Black', 1, 13, 999, 230, 0),
(180, '*BLATATA*', 'Giorgi_Gurgenishvili', 'Maladoi_Parin', 7, 17, 451, 120, 0),
(181, 'Ramos', 'John_Ramos', 'Samuel_Grigorovi', 7, 9, 462, 104, 0);

-- --------------------------------------------------------

--
-- Table structure for table `fracbank`
--

CREATE TABLE `fracbank` (
  `BallasBank` int(11) NOT NULL,
  `VagosBank` int(11) NOT NULL,
  `GroveBank` int(11) NOT NULL,
  `AztecaBank` int(11) NOT NULL,
  `RifaBank` int(11) NOT NULL,
  `YakuzaBank` int(11) NOT NULL,
  `LCNBank` int(11) NOT NULL,
  `RMBank` int(11) NOT NULL,
  `LSNewsBank` int(11) NOT NULL,
  `CityHallBank` int(11) NOT NULL,
  `healpric` int(11) NOT NULL,
  `BTCPRICE` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `fracbank`
--

INSERT INTO `fracbank` (`BallasBank`, `VagosBank`, `GroveBank`, `AztecaBank`, `RifaBank`, `YakuzaBank`, `LCNBank`, `RMBank`, `LSNewsBank`, `CityHallBank`, `healpric`, `BTCPRICE`) VALUES
(0, 1000, 0, 0, 0, 0, 0, 6, 1401520, 86742122, 1000, 200000);

-- --------------------------------------------------------

--
-- Table structure for table `fracwh`
--

CREATE TABLE `fracwh` (
  `BallasMat` int(11) NOT NULL,
  `VagosMat` int(11) NOT NULL,
  `GroveMat` int(11) NOT NULL,
  `AztecaMat` int(11) NOT NULL,
  `RifaMat` int(11) NOT NULL,
  `BallasDrugs` int(11) NOT NULL,
  `VagosDrugs` int(11) NOT NULL,
  `GroveDrugs` int(11) NOT NULL,
  `AztecaDrugs` int(11) NOT NULL,
  `RifaDrugs` int(11) NOT NULL,
  `YakuzaMat` int(11) NOT NULL,
  `LCNMat` int(11) NOT NULL,
  `RMMat` int(11) NOT NULL,
  `NewfracDrugs` int(11) NOT NULL,
  `BandidosMat` int(11) NOT NULL,
  `healpric` int(11) NOT NULL,
  `StreetMat` int(11) NOT NULL,
  `CripsMat` int(11) NOT NULL,
  `TotalNumbers` int(11) NOT NULL,
  `NewFrac` int(11) NOT NULL,
  `BloodsMat` int(11) NOT NULL,
  `NewCrips` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `fracwh`
--

INSERT INTO `fracwh` (`BallasMat`, `VagosMat`, `GroveMat`, `AztecaMat`, `RifaMat`, `BallasDrugs`, `VagosDrugs`, `GroveDrugs`, `AztecaDrugs`, `RifaDrugs`, `YakuzaMat`, `LCNMat`, `RMMat`, `NewfracDrugs`, `BandidosMat`, `healpric`, `StreetMat`, `CripsMat`, `TotalNumbers`, `NewFrac`, `BloodsMat`, `NewCrips`) VALUES
(10680, 5890172, 167174, 5191859, 3521328, 3520, 0, 4850, 0, 4075, 11671189, 13407647, 11174798, 0, 0, 50000, 0, 0, 18, 0, 87300, 2800);

-- --------------------------------------------------------

--
-- Table structure for table `house`
--

CREATE TABLE `house` (
  `hID` int(11) NOT NULL,
  `hEntrancex` float NOT NULL,
  `hEntrancey` float NOT NULL,
  `hEntrancez` float NOT NULL,
  `hExitx` float NOT NULL,
  `hExity` float NOT NULL,
  `hExitz` float NOT NULL,
  `hCarx` float NOT NULL,
  `hCary` float NOT NULL,
  `hCarz` float NOT NULL,
  `hCarc` float NOT NULL,
  `hOwner` varchar(40) NOT NULL,
  `hValue` int(11) NOT NULL,
  `hInt` int(11) NOT NULL,
  `hLock` int(11) NOT NULL,
  `hOwned` int(11) NOT NULL,
  `hDate` int(11) NOT NULL,
  `hKlass` int(11) NOT NULL,
  `hM1` varchar(40) NOT NULL,
  `hM2` varchar(40) NOT NULL,
  `hNarko` int(11) NOT NULL,
  `hDgl` int(11) NOT NULL,
  `hEm` int(11) NOT NULL,
  `hShot` int(11) NOT NULL,
  `hGarageStatus` int(11) NOT NULL,
  `hBalance` int(11) NOT NULL,
  `hTax` int(11) NOT NULL,
  `hShesvlax` float NOT NULL,
  `hShesvlay` float NOT NULL,
  `hShesvlaz` float NOT NULL,
  `hBtcStatus` int(11) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 PACK_KEYS=0 ROW_FORMAT=DYNAMIC;

--
-- Dumping data for table `house`
--

INSERT INTO `house` (`hID`, `hEntrancex`, `hEntrancey`, `hEntrancez`, `hExitx`, `hExity`, `hExitz`, `hCarx`, `hCary`, `hCarz`, `hCarc`, `hOwner`, `hValue`, `hInt`, `hLock`, `hOwned`, `hDate`, `hKlass`, `hM1`, `hM2`, `hNarko`, `hDgl`, `hEm`, `hShot`, `hGarageStatus`, `hBalance`, `hTax`, `hShesvlax`, `hShesvlay`, `hShesvlaz`, `hBtcStatus`) VALUES
(1, -2158.03, 150.868, 35.3203, 225.705, 1021.86, 1084.02, 1105.74, -1629.02, 13.6312, 266.821, 'The State', 8000000, 7, 1, 0, 0, 4, 'Mikheil_Uzumaki', 'None', 300, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(2, 263.63, 2895.48, 10.5314, 225.705, 1021.86, 1084.02, 263.974, 2902.65, 7.90546, 3.10148, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(3, 1370.81, -1361.37, 13.5469, 2308.8, -1212.84, 1049.02, 1362.91, -1361.82, 13.5469, 358.911, 'Eduard_Korleone', 200000, 6, 0, 1, 0, 0, 'None', 'None', 55, 30, 601, 200, 0, 7700, 300, 2308.59, -1210.86, 1049.02, 0),
(4, 1382.15, -1088.75, 28.2129, 225.705, 1021.86, 1084.02, 1366.17, -1092.76, 24.2247, 240.83, 'Zuka_Hamiliton', 8000000, 7, 1, 1, 0, 4, 'Beqa_Yalichava', 'None', 0, 0, 0, 0, 0, 41800, 1100, 225.671, 1023.69, 1084.01, 0),
(5, 2016.97, 1919.8, 12.3424, 83.0589, 1322.55, 1083.87, 2024.74, 1918.59, 12.3386, 263.891, 'The State', 3000000, 9, 1, 0, 0, 2, 'Nika_Kadone', 'None', 0, 0, 0, 0, 0, 8400, 700, 83.0539, 1324.44, 1083.86, 0),
(6, -1016.89, 1911.98, 447.984, 83.0589, 1322.55, 1083.87, 1425.33, -1555.95, 13.5391, 177.114, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(7, 1498.44, -1580.84, 13.5498, 225.705, 1021.86, 1084.02, 1500.6, -1587.76, 13.3828, 89.6234, 'Tony_Enkeyes', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 300, 0, 0, 0, 0, 119900, 1100, 225.671, 1023.69, 1084.01, 1),
(8, -2875.1, 2807.4, 251.645, 225.705, 1021.86, 1084.02, -2843.63, 2794.95, 243.474, 24.0784, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 165000, 1100, 225.671, 1023.69, 1084.01, 0),
(9, 485.139, -1114.2, 82.3594, 225.705, 1021.86, 1084.02, 479.806, -1090.71, 83.7294, 15.9094, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(10, -1020.44, 1912.45, 446.765, 83.0589, 1322.55, 1083.87, 1426.64, -1566.06, 13.3516, 175.931, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(11, -1031.95, 1918.65, 438.865, 2308.8, -1212.84, 1049.02, 1424.2, -1566.23, 13.5469, 345.895, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(12, 1976.21, -1634.03, 18.569, 225.705, 1021.86, 1084.02, 1955.37, -1622.74, 14.9059, 99.503, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Nika_Chiaberashvili', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(13, -892.338, 1933.71, 476.24, 83.0589, 1322.55, 1083.87, 1425.18, -1626.79, 13.3828, 180.781, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(14, 1872.26, -1911.79, 15.2568, 83.0589, 1322.55, 1083.87, 1874.53, -1925.18, 13.5469, 99.6358, 'Alberto_Valachi', 3000000, 9, 1, 1, 0, 2, 'None', 'None', 0, 0, 0, 0, 1, 82600, 700, 83.0539, 1324.44, 1083.86, 0),
(15, 2163.47, 2056.96, 10.8203, 234.138, 1063.9, 1084.21, 2146.7, 2053.25, 10.6797, 180.986, 'The State', 5000000, 6, 1, 0, 0, 3, 'Dylan_Obrien', 'Kevin_Autumn', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(16, 141.932, 1875.48, 17.8434, 2270.05, -1210.46, 1047.56, 186.701, 1898.04, 17.6406, 312.61, 'Freddy_Marlboro', 1000000, 10, 1, 1, 0, 1, 'Xeteqsa_Scaglietti', 'John_Lee', 0, 0, 0, 0, 0, 61500, 500, 2265.62, -1210.51, 1049.02, 0),
(17, -910.92, 2686.23, 42.3703, 225.705, 1021.86, 1084.02, -902.471, 2696.23, 42.3703, 312.061, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(18, 2017.67, 1905.59, 12.3269, 225.705, 1021.86, 1084.02, 2025.56, 1902.26, 12.2479, 261.541, 'Tornike_Gelashvili', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 82900, 1100, 225.671, 1023.69, 1084.01, 0),
(19, 2523.27, -1679.37, 15.497, 225.705, 1021.86, 1084.02, 2504.17, -1672.78, 13.3633, 255.083, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 58, 0, 0, 0, 0, 163900, 1100, 225.671, 1023.69, 1084.01, 0),
(20, 2513.76, -1650.29, 14.3557, 1972.52, -1553.17, 2451.34, 2507.25, -1666.71, 13.391, 128.692, 'The State', 5000000, 12, 1, 0, 0, 3, 'Meggan_Wiliams', 'Temo_Shalikkiani', 0, 0, 0, 0, 0, 63000, 900, 234.258, 1066.21, 1084.21, 0),
(21, 1496.96, -688.165, 95.5421, 234.138, 1063.9, 1084.21, -2031.56, 172.347, 28.8359, 220.401, 'Pogra_Flashback', 5000000, 6, 1, 1, 0, 3, 'Aleksandre_Nozadze', 'None', 100, 300, 300, 0, 0, 98900, 900, 234.258, 1066.21, 1084.21, 0),
(22, 2362.79, -1643.14, 14.3516, 225.705, 1021.86, 1084.02, 2371.58, -1646.53, 13.5291, 344.574, 'The State', 8000000, 7, 1, 0, 0, 4, 'Nika_Cxoidze', 'Bebe_Destinez', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(23, 1774.5, -1964.33, 324.473, 83.0589, 1322.55, 1083.87, 1775.42, -1963.19, 343.987, 358.985, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(24, 653.596, -1713.91, 14.7648, 225.705, 1021.86, 1084.02, 641.588, -1714.05, 14.3185, 185.458, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(25, 1540.47, -851.399, 64.3361, 2439.13, -95.9364, 1146.88, 1524.59, -847.953, 66.0506, 141.301, 'Aleqsa_Modebadze', 8000000, 6, 1, 1, 0, 4, 'Dachi_Shavashvili', 'Data_Qucniashvili', 0, 0, 0, 0, 1, 119900, 1100, 225.671, 1023.69, 1084.01, 1),
(26, 2322, -1796.27, 13.5469, 225.705, 1021.86, 1084.02, 2330.66, -1796.2, 13.5469, 270.564, 'Cotne_Rodonaia', 8000000, 7, 1, 1, 0, 4, 'Klaus_Corrleone', 'None', 0, 0, 0, 0, 0, 178600, 1100, 225.671, 1023.69, 1084.01, 1),
(27, 2402.53, -1714.78, 14.1328, 234.138, 1063.9, 1084.21, 2397.64, -1726.41, 13.5608, 92.5217, 'Giorgi_Kevlishvili', 5000000, 6, 0, 1, 0, 3, 'Goldz_Impala', 'None', 0, 0, 0, 0, 0, 145500, 900, 234.258, 1066.21, 1084.21, 1),
(28, 303.225, -1151.97, 81.4487, 1548.1, -7.4133, 1501.39, 292.974, -1154.09, 80.9099, 222.277, 'Aleksandre_Kinkladze', 999999999, 5, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 499960400, 1100, 225.671, 1023.69, 1084.01, 0),
(29, 167.897, -1308.28, 70.3513, 83.0589, 1322.55, 1083.87, 165.979, -1340.55, 69.7235, 187.003, 'Levan_Devadze', 3000000, 9, 1, 1, 0, 2, 'Jossef_Martines', 'Pablo_Ernesto', 0, 0, 0, 0, 1, 71500, 700, 83.0539, 1324.44, 1083.86, 0),
(30, 1370.81, -1341.37, 13.5469, 2439.13, -95.9364, 1146.88, 1357.95, -1344.92, 13.3828, 173.479, 'Dachi_Korkelia', 8000000, 6, 0, 1, 0, 4, 'Kokia_Korkelia', 'Beqa_Qveladze', 120, 30, 0, 40, 1, 181100, 1100, 225.671, 1023.69, 1084.01, 1),
(31, 1333.09, -1297.7, 13.5469, 225.705, 1021.86, 1084.02, 1337.93, -1300.94, 13.3951, 174.063, 'Frank_Andersoni', 8000000, 7, 1, 1, 0, 4, 'Sthep_Parker', 'None', 0, 100, 0, 0, 0, 157200, 1100, 225.671, 1023.69, 1084.01, 0),
(32, 416.742, -1154.1, 76.6876, 1548.1, -7.4133, 1501.39, 406.57, -1152.06, 76.9994, 152.567, 'Sabana_Face', 3000000, 5, 1, 1, 0, 2, 'Flenzo_Flex', 'None', 0, 0, 300, 0, 0, 87300, 700, 83.0539, 1324.44, 1083.86, 1),
(33, 992.497, -1817.6, 13.8942, 83.0589, 1322.55, 1083.87, 999.948, -1824.58, 13.7792, 351.148, 'Leon_Wiliams', 3000000, 9, 1, 1, 0, 2, 'None', 'None', 286, 0, 0, 0, 0, 76300, 700, 83.0539, 1324.44, 1083.86, 0),
(34, 980.835, -1814.79, 13.889, 2270.05, -1210.46, 1047.56, 988.038, -1810.49, 14.237, 73.131, 'Cotne_Shermadini', 1000000, 10, 0, 1, 0, 1, 'Deathise_Tripplex', 'Markus_Barqaia', 0, 0, 0, 0, 0, 49600, 500, 2265.62, -1210.51, 1049.02, 0),
(35, 2067.05, -1731.63, 14.2066, 234.138, 1063.9, 1084.21, 2073.48, -1735.25, 13.5469, 359.236, 'Suzzuia_Juzzou', 5000000, 6, 0, 1, 0, 3, 'Zura_Fircxalaishvili', 'None', 0, 0, 0, 0, 0, 58300, 900, 234.258, 1066.21, 1084.21, 1),
(36, 969.468, -1811.99, 13.8835, 234.138, 1063.9, 1084.21, 968.797, -1803.7, 14.2597, 254.226, 'Toxika_Kalashnikov', 5000000, 6, 1, 1, 0, 3, 'Big_Dragon', 'Shota_Armia', 0, 0, 0, 0, 0, 97200, 900, 234.258, 1066.21, 1084.21, 0),
(37, 2065.18, -1703.55, 14.1484, 225.705, 1021.86, 1084.02, 2080.99, -1699.39, 13.3906, 179.314, 'Saba_Khabazi', 8000000, 7, 0, 1, 0, 4, 'Devid_Morningstar', 'None', 0, 0, 0, 0, 0, 81300, 1100, 225.671, 1023.69, 1084.01, 1),
(38, 2066.74, -1656.42, 14.1328, 83.0589, 1322.55, 1083.87, 2073.53, -1655.61, 13.5469, 295.228, 'Nikusha_Yala', 3000000, 9, 0, 1, 0, 2, 'Mchedlo_Imperatori', 'None', 0, 280, 189, 0, 0, 72500, 700, 83.0539, 1324.44, 1083.86, 1),
(39, 1720.03, -1740.98, 13.5469, 225.705, 1021.86, 1084.02, 1721.38, -1735.86, 13.3828, 271.916, 'Sandro_Paul', 8000000, 7, 0, 1, 0, 4, 'Harley_Milner', 'None', 0, 0, 0, 0, 0, 52800, 1100, 225.671, 1023.69, 1084.01, 1),
(40, 2067.7, -1628.8, 14.2066, 225.705, 1021.86, 1084.02, 2064.68, -1636.59, 13.5469, 269.599, 'Saba_Cholokava', 8000000, 7, 0, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 32100, 1100, 225.671, 1023.69, 1084.01, 0),
(41, 958.158, -1809.19, 13.8812, 225.705, 1021.86, 1084.02, 959.894, -1800.8, 14.2734, 261.887, 'Alex_Willam', 8000000, 7, 0, 1, 0, 4, 'None', 'None', 197, 2, 0, 0, 0, 137600, 1100, 225.671, 1023.69, 1084.01, 1),
(42, 933.733, -1805.21, 13.8433, 225.705, 1021.86, 1084.02, 935.907, -1795.79, 13.8193, 261.2, 'Luka_Gringo', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 141100, 1100, 225.671, 1023.69, 1084.01, 0),
(43, 1090.13, -1242.41, 15.8272, 225.705, 1021.86, 1084.02, 1107.63, -1242.77, 15.8203, 309.503, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Gia_Gochita', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(44, 245.681, -1874.96, 405.972, 83.0589, 1322.55, 1083.87, 248.158, -1883.47, 1.30334, 93.4563, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(45, 922.006, -1803.89, 13.8377, 225.705, 1021.86, 1084.02, 925.509, -1796, 13.5469, 315.13, 'Roini_Kodua', 8000000, 7, 1, 1, 0, 4, 'Nini_Gvariashvili', 'None', 0, 100, 100, 0, 0, 97900, 1100, 225.671, 1023.69, 1084.01, 0),
(46, 2018.05, -1630.03, 14.0426, 225.705, 1021.86, 1084.02, 2005.83, -1633.1, 13.3828, 81.4979, 'The State', 8000000, 7, 1, 0, 0, 4, 'Lasha_Papidze', 'None', 179, 150, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(47, 910.116, -1802.67, 13.7994, 225.705, 1021.86, 1084.02, 910.378, -1797.33, 13.5547, 348.775, 'Giorgi_Varazashvili', 8000000, 7, 1, 1, 0, 4, 'None', 'Peter_Defeo', 0, 0, 0, 0, 0, 49400, 1100, 225.671, 1023.69, 1084.01, 0),
(48, 1981.28, -1682.68, 17.0535, 225.705, 1021.86, 1084.02, 1981.83, -1674.42, 17.5065, 276.096, 'Washington_George', 8000000, 7, 1, 1, 0, 4, 'None', 'Anri_Chitadze', 294, 250, 300, 0, 0, 156300, 1100, 225.671, 1023.69, 1084.01, 0),
(49, 1359.34, -339.612, 1474.17, 2308.8, -1212.84, 1049.02, 1368.51, -1089.51, 24.5795, 169.235, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(50, 1091.36, -347.715, 73.9673, 225.705, 1021.86, 1084.02, 1096.69, -344.976, 73.9922, 227.045, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(51, -1463.1, 2628.61, 58.7734, 225.705, 1021.86, 1084.02, -2094.26, 2655.03, 159.766, 42.0364, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(52, 264.024, -1765.46, 4.75678, 225.705, 1021.86, 1084.02, 263.524, -1775.69, 4.19181, 268.349, 'The State', 8000000, 7, 1, 0, 0, 4, 'Zura_Topuridze', 'Ell_Soprano', 0, 268, 198, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(53, 192.869, -1769.39, 4.32859, 225.705, 1021.86, 1084.02, 193.797, -1778.43, 3.67594, 186.755, 'Venom_Uchiha', 8000000, 7, 0, 1, 0, 4, 'Giorgi_Luxutashvili', 'James_Monta', 0, 0, 0, 0, 0, 26900, 1100, 225.671, 1023.69, 1084.01, 0),
(54, 168.499, -1769.82, 4.45038, 2270.05, -1210.46, 1047.56, 165.057, -1777.17, 4.25654, 273.312, 'Liam_Crystal', 1000000, 10, 0, 1, 0, 1, 'Gigsona_Green', 'None', 0, 0, 0, 0, 0, 13000, 500, 2265.62, -1210.51, 1049.02, 1),
(55, 1188.15, -959.246, 42.901, 225.705, 1021.86, 1084.02, 1194.83, -952.193, 42.6884, 86.7664, 'Luca_Changretta', 8000000, 7, 0, 1, 0, 4, 'None', 'None', 200, 200, 200, 300, 0, 102300, 1100, 225.671, 1023.69, 1084.01, 1),
(56, 652.665, -1694.01, 14.5501, 2270.05, -1210.46, 1047.56, 654.775, -1679.76, 14.4705, 92.7586, 'Luke_Vichenso', 1000000, 10, 1, 1, 0, 1, 'Bako_Shelby', 'None', 300, 300, 300, 300, 0, 75000, 500, 2265.62, -1210.51, 1049.02, 0),
(57, 907.7, -917.866, 42.6016, 225.705, 1021.86, 1084.02, 915.743, -929.348, 42.6016, 96.6117, 'Nika_Endeladze', 8000000, 7, 0, 1, 0, 4, 'David_Malaymadze', 'None', 0, 0, 0, 0, 0, 136600, 1100, 225.671, 1023.69, 1084.01, 1),
(58, 883.144, -1800.39, 13.8014, 2439.13, -95.9364, 1146.88, 884.306, -1785.75, 13.5506, 261.075, 'Nika_Tarielashvili', 5000000, 6, 1, 1, 0, 3, 'Aleqsi_Gelishvili', 'Giusha_Ganabi', 0, 0, 0, 0, 0, 147600, 900, 234.258, 1066.21, 1084.21, 1),
(59, 866.56, -1798.93, 13.8157, 225.705, 1021.86, 1084.02, 873.731, -1789.06, 13.6317, 274.828, 'Don_Sentoro', 8000000, 7, 1, 1, 0, 4, 'Solo_Zhamutashvili', 'None', 300, 184, 450, 220, 0, 124000, 1100, 225.671, 1023.69, 1084.01, 0),
(60, 802.697, -1795.76, 13.0234, 225.705, 1021.86, 1084.02, 797.794, -1791.16, 13.2564, 91.2371, 'Tato_Aduashvili', 8000000, 7, 0, 1, 0, 4, 'None', 'None', 63, 0, 0, 0, 0, 35000, 1100, 225.671, 1023.69, 1084.01, 1),
(61, 690.946, -583.28, 16.3281, 225.705, 1021.86, 1084.02, 686.766, -579.786, 16.3359, 359.305, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(62, -1691.94, 1367.68, 7.17969, 225.705, 1021.86, 1084.02, -1709.35, 1338.01, 7.17529, 134.795, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(63, -2016.35, 897.62, 45.4453, 225.705, 1021.86, 1084.02, -86.3939, -1572.51, 2.61719, 238.436, 'The State', 8000000, 7, 1, 0, 0, 4, 'Gam_Hellboy', 'None', 0, 0, 0, 0, 0, 24595, 1100, 225.671, 1023.69, 1084.01, 0),
(64, 561.47, -1504.88, 14.539, 225.705, 1021.86, 1084.02, 556.387, -1504.01, 14.5382, 97.7939, 'Nick_Halden', 8000000, 7, 1, 1, 0, 4, 'Tupac_Makaveli', 'Vetran_Morgen', 0, 0, 0, 0, 0, 170500, 1100, 225.671, 1023.69, 1084.01, 0),
(65, 1695.38, -2125.83, 13.8101, 225.705, 1021.86, 1084.02, 1704.71, -2124.72, 13.5469, 3.12644, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Hirurg_Moskovskiy', 0, 300, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(66, 1298.52, -798.491, 84.1406, -1036.53, -2205.94, 1501.09, 1291.11, -787.52, 96.4554, 182.894, 'Ricky_Moon', 3000000, 10, 1, 1, 0, 2, 'Mad_Cotne', 'None', 0, 0, 0, 0, 0, 499974800, 700, 83.0539, 1324.44, 1083.86, 0),
(67, -2094.1, 795.741, 69.5684, 225.705, 1021.86, 1084.02, 2135.25, -1476.33, 23.9553, 0.282548, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(68, 2149.86, -1433.8, 26.0703, 234.138, 1063.9, 1084.21, 2140.13, -1429.79, 24.1663, 93.6493, 'The State', 5000000, 6, 1, 0, 0, 3, 'Mamuli_Tavadze', 'Tommy_Kallashnikov', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(69, 989.904, -828.601, 95.4686, 234.138, 1063.9, 1084.21, 976.373, -824.583, 96.5353, 25.5347, 'Deme_Giorgadze', 5000000, 6, 0, 1, 0, 3, 'None', 'Itachi_Luther', 0, 0, 0, 0, 0, 91200, 900, 234.258, 1066.21, 1084.21, 0),
(70, 984.698, -1829.77, 13.3306, 225.705, 1021.86, 1084.02, 979.735, -1836.85, 12.6141, 253.476, 'Momcela_Momcelaze', 8000000, 7, 1, 1, 0, 4, 'Max_Asa', 'None', 0, 200, 0, 0, 0, 20900, 1100, 225.671, 1023.69, 1084.01, 0),
(71, 1440.13, -926.062, 39.6477, 225.705, 1021.86, 1084.02, 1451.81, -923.871, 37.6094, 173.279, 'George_Washingtons', 8000000, 7, 0, 1, 0, 4, 'Scott_Brock', 'None', 0, 0, 0, 0, 0, 181100, 1100, 225.671, 1023.69, 1084.01, 1),
(72, 315.809, -1769.43, 4.62176, 1548.1, -7.4133, 1501.39, 325.104, -1788.05, 4.79349, 181.186, 'Close_Lovely', 8000000, 5, 0, 1, 0, 4, 'Suxo_Suhei', 'None', 300, 300, 300, 300, 1, 160600, 1100, 225.671, 1023.69, 1084.01, 1),
(73, 870.537, -24.9787, 63.9751, 225.705, 1021.86, 1084.02, 866.777, -16.741, 63.1953, 68.0195, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Yung_Luxe', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(74, -1942.14, 2379.46, 49.7031, 2308.8, -1212.84, 1049.02, -1933.1, 2428.57, 52.5928, 124.106, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 300, 300, 2308.59, -1210.86, 1049.02, 0),
(75, 1172.31, -1129.81, 23.8773, 225.705, 1021.86, 1084.02, 1166.86, -1133.1, 23.6562, 185.162, 'Buchukuri_Gio', 8000000, 7, 0, 1, 0, 4, 'Mazmishvili_Vaxo', 'None', 0, 0, 0, 0, 0, 33000, 1100, 225.671, 1023.69, 1084.01, 0),
(76, -2358.51, 656.837, 35.1719, 225.705, 1021.86, 1084.02, 550.091, -2058.01, 8.72676, 306.36, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 100, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(77, -307.932, 1538.85, 75.5625, 225.705, 1021.86, 1084.02, -281.603, 1531.55, 75.357, 109.784, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(78, 761.359, -1564.38, 13.838, 225.705, 1021.86, 1084.02, 767.355, -1565.33, 13.5469, 354.057, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(79, 2323.85, 162.213, 28.4416, 225.705, 1021.86, 1084.02, 2330.12, 156.051, 27.09, 268.896, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(80, 2015.35, -1732.62, 14.2344, 225.705, 1021.86, 1084.02, 2005.91, -1736.83, 13.3828, 83.7544, 'Sayen_Goldrise', 8000000, 7, 0, 1, 0, 4, 'None', 'Kniaz_Sunjaevi', 0, 300, 200, 300, 1, 72100, 1100, 225.671, 1023.69, 1084.01, 1),
(81, -911.387, 2672.85, 42.3703, 225.705, 1021.86, 1084.02, -900.502, 2685.85, 42.3703, 41.4013, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 67800, 1100, 225.671, 1023.69, 1084.01, 0),
(82, 1496.6, -688.318, 506.234, 2308.8, -1212.84, 1049.02, 1489.9, -696.65, 94.75, 226.474, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(83, -2230.13, -1649.58, 611.788, 83.0589, 1322.55, 1083.87, -2312.19, -1633.18, 483.703, 216.751, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 86240, 700, 83.0539, 1324.44, 1083.86, 0),
(84, -801.592, -821.579, 149.778, 225.705, 1021.86, 1084.02, -786.778, -843.042, 148.883, 172.821, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Lost_Soul', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(85, -1659.23, 1368.28, 7.17219, 225.705, 1021.86, 1084.02, 605.809, -2080.83, 10.2713, 91.4138, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Reziko_Cercvadze', 50, 250, 300, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(86, -2627.9, 179.11, 4.34019, 234.138, 1063.9, 1084.21, -2628.53, 181.981, 4.34089, 129.962, 'The State', 5000000, 6, 1, 0, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(87, 2323.85, 116.126, 28.4416, 225.705, 1021.86, 1084.02, 2328.97, 124.233, 27.275, 274.45, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(88, 1189.03, -1018.22, 32.5469, 1548.1, -7.4133, 1501.39, 1193.67, -1024.42, 32.5469, 173.62, 'Beqa_Chachua', 8000000, 5, 1, 1, 0, 4, 'None', 'None', 0, 20, 0, 0, 0, 145000, 1100, 225.671, 1023.69, 1084.01, 1),
(89, 2364, 116.096, 28.4416, 225.705, 1021.86, 1084.02, 2356.74, 122.121, 26.9302, 92.0706, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(90, 1073.01, -1113.56, 24.328, 83.0589, 1322.55, 1083.87, 1070.1, -1108.68, 24.3892, 88.82, 'Giga_Axalaia', 3000000, 9, 1, 1, 0, 2, 'Jack_Luther', 'Rob_Stone', 0, 0, 0, 0, 0, 78400, 700, 83.0539, 1324.44, 1083.86, 1),
(91, 1411.16, -920.869, 38.4219, 225.705, 1021.86, 1084.02, 1422.2, -919.785, 36.0469, 170.504, 'Kopi_Moyaa', 8000000, 7, 1, 1, 0, 4, 'Alice_Williams', 'Kira_Watson', 0, 0, 0, 0, 0, 182400, 1100, 225.671, 1023.69, 1084.01, 1),
(92, 946.302, -710.702, 122.62, 234.138, 1063.9, 1084.21, 946.442, -702.923, 122.211, 32.8705, 'Temo_Magradze', 5000000, 6, 0, 1, 0, 3, 'Sergo_Nemsadze', 'None', 50, 0, 0, 0, 0, 87300, 900, 234.258, 1066.21, 1084.21, 0),
(93, 743.162, -509.319, 18.0129, 83.0589, 1322.55, 1083.87, 751.371, -509.062, 16.9454, 184.162, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'Luka_Tabatadz', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(94, -2721.36, -320.947, -109.31, 83.0589, 1322.55, 1083.87, -2733.4, -310.563, 7.1875, 314.388, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(95, 776.737, -503.483, 18.0129, 225.705, 1021.86, 1084.02, 774.288, -510.065, 17.1411, 107.842, 'The State', 8000000, 7, 1, 0, 0, 4, 'Gio_Rage', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(96, 795.144, -506.148, 18.0129, 225.705, 1021.86, 1084.02, 785.973, -489.177, 17.3439, 180.147, 'Cedric_Decelle', 8000000, 7, 0, 1, 0, 4, 'Akaki_Wereteli', 'None', 0, 0, 0, 0, 0, 130900, 1100, 225.671, 1023.69, 1084.01, 1),
(97, 818.485, -509.319, 18.0129, 225.705, 1021.86, 1084.02, 821.618, -516.25, 16.8866, 166.654, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 112300, 1100, 225.671, 1023.69, 1084.01, 0),
(98, 766.579, -556.784, 18.0129, 225.705, 1021.86, 1084.02, 772.216, -551.615, 17.2339, 359.529, 'Hardin_Scott', 8000000, 7, 0, 1, 0, 4, 'Zvezda_Onia', 'Dato_Nadirashvili', 0, 0, 0, 0, 0, 88600, 1100, 225.671, 1023.69, 1084.01, 0),
(99, 745.673, -591.072, 18.0129, 225.705, 1021.86, 1084.02, 753.798, -582.046, 17.3359, 89.6583, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 90, 0, 0, 0, 0, 18700, 1100, 225.671, 1023.69, 1084.01, 1),
(100, 2567.92, 1579.19, 13.4062, 225.705, 1021.86, 1084.02, 2562.59, 1574.95, 10.8203, 109.375, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(101, 767.56, -570.412, 18.0133, 225.705, 1021.86, 1084.02, 736.39, -590.475, 16.7953, 90.0645, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 69300, 1100, 225.671, 1023.69, 1084.01, 0),
(102, 742.312, -495.646, 18.0129, 225.705, 1021.86, 1084.02, 751.685, -495.545, 17.3281, 183.241, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(103, 796.095, -492.402, 18.0133, 234.138, 1063.9, 1084.21, 786.073, -489.26, 17.3439, 180.38, 'The State', 5000000, 6, 1, 0, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 129300, 900, 234.258, 1066.21, 1084.21, 0),
(104, 3365.67, -365.057, 4.56975, 2308.8, -1212.84, 1049.02, -2011.35, 171.56, 27.5391, 193.221, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 300, 300, 2308.59, -1210.86, 1049.02, 0),
(105, 1103.4, -1092.67, 28.4688, 225.705, 1021.86, 1084.02, 1094.79, -1101.57, 25.1193, 90.067, 'Vladimer_Zelenski', 8000000, 7, 1, 1, 0, 4, 'None', 'Godfather_Terjolsky', 0, 0, 0, 0, 0, 118400, 1100, 225.671, 1023.69, 1084.01, 0),
(106, 2187, 1113.51, 12.6538, 225.705, 1021.86, 1084.02, 2174.04, 1120.98, 12.6859, 156.567, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 30700, 1100, 225.671, 1023.69, 1084.01, 0),
(107, 697.28, -1627.05, 3.74917, 225.705, 1021.86, 1084.02, 706.474, -1628.16, 3.4375, 180.155, 'Luka_Xergiani', 8000000, 7, 1, 1, 0, 4, 'Tamar_Glonti', 'Shako_Cecxladze', 0, 0, 0, 0, 0, 139700, 1100, 225.671, 1023.69, 1084.01, 0),
(108, 1310.09, -1366.99, 13.5147, 225.705, 1021.86, 1084.02, 1315.87, -1374.03, 13.6349, 181.724, 'The State', 8000000, 7, 1, 0, 0, 4, 'Guro_Kalandadze', 'Honeyst_Instenty', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(109, 1328.2, -1271.28, 13.5469, 225.705, 1021.86, 1084.02, 1326.43, -1275.5, 13.5469, 157.288, 'Saba_Siradze', 8000000, 7, 1, 1, 0, 4, 'Eren_Jaeger', 'Tony_MaladoI', 0, 0, 0, 0, 0, 136700, 1100, 225.671, 1023.69, 1084.01, 0),
(110, 1671.58, -1330.29, 17.4591, 225.705, 1021.86, 1084.02, 1646.33, -1319.92, 17.4399, 91.0116, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(111, -427.617, -392.72, 16.5802, 225.705, 1021.86, 1084.02, -415.884, -350.854, -0.507354, 281.894, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(112, 2039.62, 2766.54, 10.8265, 234.138, 1063.9, 1084.21, 2026.95, 2751.43, 10.8203, 241.865, 'Sandro_Abazadze', 5000000, 6, 0, 1, 0, 3, 'Goga_Gewadze', 'Data_Manjgaladze', 0, 0, 0, 0, 0, 34600, 900, 234.258, 1066.21, 1084.21, 1),
(113, 487.14, -1639.36, 23.7031, 225.705, 1021.86, 1084.02, 481.377, -1652.33, 23.2486, 262.856, 'Luciano_Shelby', 8000000, 7, 1, 1, 0, 4, 'Albert_Mamedov', 'None', 0, 0, 0, 0, 0, 172700, 1100, 225.671, 1023.69, 1084.01, 0),
(114, 2398.34, 111.763, 28.4416, 225.705, 1021.86, 1084.02, 2420.2, 96.2447, 26.4766, 87.274, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 184800, 1100, 225.671, 1023.69, 1084.01, 0),
(115, -2329.45, -1622.38, 485.19, 225.705, 1021.86, 1084.02, -2314.16, -1643.24, 483.703, 234.025, 'Rick_Parker', 8000000, 7, 1, 1, 0, 4, 'Leqso_Tabukashvili', 'None', 0, 0, 0, 0, 1, 166900, 1100, 225.671, 1023.69, 1084.01, 1),
(116, 2373.85, 71.1332, 28.4416, 225.705, 1021.86, 1084.02, 2379.24, 77.9637, 27.2299, 266.717, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(117, 331.264, -40.2378, 2.22552, 234.138, 1063.9, 1084.21, 327.395, -48.7659, 1.5307, 90.3917, 'The State', 5000000, 6, 1, 0, 0, 3, 'Irakli_Moistss', 'None', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(118, 1932.03, 147.558, 37.2812, 2308.8, -1212.84, 1049.02, 1920.87, 135.454, 34.1033, 71.9421, 'The State', 200000, 6, 1, 0, 0, 0, 'Zura_Corleon', 'Lomakov_Dmitry', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(119, 2481.77, -1331.94, 28.3065, 225.705, 1021.86, 1084.02, 2455.85, -1348.19, 23.8359, 357.373, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Jack_Marroquin', 0, 0, 0, 0, 0, 148500, 1100, 225.671, 1023.69, 1084.01, 0),
(120, 930.815, -1557.95, 13.5527, 225.705, 1021.86, 1084.02, 940.467, -1561.11, 13.5624, 63.5598, 'Ceasar_Sepeli', 8000000, 7, 1, 1, 0, 4, 'Scrooge_McDock', 'None', 8, 0, 0, 0, 0, 80800, 1100, 225.671, 1023.69, 1084.01, 0),
(121, 2364, 142.063, 28.4416, 225.705, 1021.86, 1084.02, 2366, 146.242, 27.8438, 85.3319, 'The State', 8000000, 7, 1, 0, 0, 4, 'Niko_Taylor', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(122, -394.479, -428.558, 16.2031, 225.705, 1021.86, 1084.02, 679.524, -1285.88, 13.6021, 144.377, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(123, 2323.85, 191.15, 28.4416, 225.705, 1021.86, 1084.02, 2328.64, 199.182, 27.3283, 269.642, 'The State', 8000000, 7, 1, 0, 0, 4, 'Luka_Ohigava', 'None', 0, 0, 0, 0, 0, 75400, 1100, 225.671, 1023.69, 1084.01, 0),
(124, 852.261, -1423.16, 14.1425, 225.705, 1021.86, 1084.02, 859.967, -1419.89, 12.7621, 7.4991, 'Alika_Petriashvili', 8000000, 7, 0, 1, 0, 4, 'Giorgi_Taruashvili', 'Lucas_Blassed', 0, 0, 0, 0, 0, 99700, 1100, 225.671, 1023.69, 1084.01, 0),
(125, -2157.05, 159.988, 35.3203, 225.705, 1021.86, 1084.02, 1107.46, -1608.99, 13.6226, 261.811, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 70, 30, 200, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(126, 1242.09, -1076.53, 31.5547, 225.705, 1021.86, 1084.02, 1254.94, -1062.39, 29.6798, 179.223, 'Nina_Kamiani', 8000000, 7, 0, 1, 0, 4, 'None', 'Trapovka_Triplozz', 0, 0, 0, 0, 0, 181600, 1100, 225.671, 1023.69, 1084.01, 0),
(127, 252.689, -92.3535, 3.53539, 225.705, 1021.86, 1084.02, 248.138, -86.5798, 2.43061, 92.7822, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(128, 1566.49, 23.3716, 24.1641, 234.138, 1063.9, 1084.21, 1544.46, 15.9796, 24.1323, 286.521, 'Thomas_Morrison', 5000000, 6, 0, 1, 0, 3, 'None', 'None', 100, 0, 0, 0, 1, 24600, 900, 234.258, 1066.21, 1084.21, 1),
(129, 1422.13, -885.777, 50.6699, 1972.52, -1553.17, 2451.34, 1430.53, -883.449, 50.741, 0.758211, 'Sinsa_Stone', 8000000, 12, 1, 1, 0, 4, 'Galaxy_Jealmen', 'None', 0, 0, 0, 0, 0, 81400, 1100, 225.671, 1023.69, 1084.01, 0),
(130, 876.21, -1512.87, 14.3487, 225.705, 1021.86, 1084.02, 873.887, -1504.49, 12.8246, 99.3168, 'The State', 8000000, 7, 1, 0, 0, 4, 'Carl_Winnston', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(131, -2632.49, -164.914, 4.32812, 83.0589, 1322.55, 1083.87, -2656.45, -164.507, 4.00619, 188.589, 'The State', 3000000, 9, 1, 0, 0, 2, 'Mamasha_Ardizzone', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(132, 17.7528, 909.489, 23.9279, 225.705, 1021.86, 1084.02, -1077.09, -1631.85, 76.3672, 281.213, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 80300, 1100, 225.671, 1023.69, 1084.01, 0),
(133, 2013.56, -1656.4, 14.1363, 225.705, 1021.86, 1084.02, 2026.45, -1649.68, 13.5547, 91.8802, 'Mate_Berodze', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 101900, 1100, 225.671, 1023.69, 1084.01, 1),
(134, -64.3649, -2143.37, 1154.92, 83.0589, 1322.55, 1083.87, 144.054, -1949.38, 3.77344, 331.375, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(135, 160.049, -2452.43, 637.618, 83.0589, 1322.55, 1083.87, 1955.15, -1039.62, 24.2157, 232.795, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(136, 980.428, -677.298, 121.976, 225.705, 1021.86, 1084.02, 1007.45, -663.086, 121.145, 28.8263, 'Saba_Xurcidze', 8000000, 7, 0, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 10845800, 1100, 225.671, 1023.69, 1084.01, 0),
(137, 768.233, -503.483, 18.0129, 225.705, 1021.86, 1084.02, 762.412, -506.963, 17.3432, 183.041, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(138, 1535.03, -800.458, 72.8495, 225.705, 1021.86, 1084.02, 1530.09, -813.271, 71.9866, 93.0241, 'Nodo_Scorp', 8000000, 7, 1, 1, 0, 4, 'None', 'Lucifer_Morningstar', 0, 0, 0, 0, 0, 177200, 1100, 225.671, 1023.69, 1084.01, 1),
(139, 993.707, -1058.86, 33.6995, 83.0589, 1322.55, 1083.87, 982.242, -1046.26, 30.4716, 90.8437, 'Gabelia_Akaki', 3000000, 9, 1, 1, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 63700, 700, 83.0539, 1324.44, 1083.86, 1),
(140, -683.935, 940.399, 13.6328, 83.0589, 1322.55, 1083.87, -684.083, 966.1, 12.1328, 91.1323, 'The State', 3000000, 9, 1, 0, 0, 2, 'Hira_Scott', 'Henry_Beinars', 300, 300, 300, 300, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(141, 1442.66, -628.835, 95.7186, 83.0589, 1322.55, 1083.87, 1460.62, -635.289, 95.8569, 176.978, 'Joni_Antadze', 3000000, 9, 0, 1, 0, 2, 'Wei_Killaz', 'None', 0, 0, 0, 0, 0, 105400, 700, 83.0539, 1324.44, 1083.86, 0),
(142, 745.197, -556.772, 18.0129, 225.705, 1021.86, 1084.02, 750.674, -551.559, 17.2296, 0.934396, 'The State', 8000000, 7, 1, 0, 0, 4, 'Marcus_Imerles', 'Luka_Belqania', 0, 0, 0, 0, 0, 7206, 1100, 225.671, 1023.69, 1084.01, 0),
(143, 252.708, -121.402, 3.53539, 234.138, 1063.9, 1084.21, 247.977, -127.426, 2.40867, 90.5604, 'The State', 5000000, 6, 1, 0, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(144, 977.494, -771.718, 112.203, 225.705, 1021.86, 1084.02, 974.115, -758.688, 112.035, 96.6553, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 130, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(145, 1094.99, -661.067, 113.648, 2439.13, -95.9364, 1146.88, 1088.86, -636.662, 113.088, 264.414, 'Murman_Manjavidze', 8000000, 6, 0, 1, 0, 4, 'Mamuka_Sapanadze', 'None', 0, 0, 0, 0, 0, 114499, 1100, 225.671, 1023.69, 1084.01, 1),
(146, 936.426, -1612.72, 14.9375, 225.705, 1021.86, 1084.02, 939.483, -1629.47, 13.5546, 72.4325, 'Ghoul_Luffy', 8000000, 7, 1, 1, 0, 4, 'Giorgi_Bacardi', 'None', 0, 0, 0, 0, 0, 177400, 1100, 225.671, 1023.69, 1084.01, 1),
(147, 824.007, -1424.2, 14.4988, 2270.05, -1210.46, 1047.56, 827.093, -1411.6, 13.4433, 328.585, 'Saba_Abesa', 1000000, 10, 0, 1, 0, 1, 'Aleqsa_Gafrinda', 'None', 46, 0, 0, 0, 0, 22500, 500, 2265.62, -1210.51, 1049.02, 0),
(148, 2323.85, 136.405, 28.4416, 225.705, 1021.86, 1084.02, 2322.24, 132.098, 27.8438, 268.269, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(149, 1329.16, -984.977, 33.8966, 225.705, 1021.86, 1084.02, 1352.71, -985.866, 29.615, 274.158, 'The State', 20000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 150, 300, 150, 0, 117015, 1100, 225.671, 1023.69, 1084.01, 1),
(150, 988.888, -1752.84, 13.5022, 83.0589, 1322.55, 1083.87, 983.852, -1763.68, 13.8145, 180, 'Shako_Cecxladze', 3000000, 9, 0, 1, 0, 2, 'None', 'Shisui_Yukimura', 161, 0, 0, 0, 0, 93500, 700, 83.0539, 1324.44, 1083.86, 0),
(151, -2372.53, 692.733, 35.1641, 225.705, 1021.86, 1084.02, 528.795, -2064.36, 9.43689, 138.44, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 10, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(152, -2521.01, -624.726, 132.784, 225.705, 1021.86, 1084.02, -2520.62, -601.536, 132.562, 178.806, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 124300, 1100, 225.671, 1023.69, 1084.01, 0),
(153, 1112.64, -742.242, 100.133, 225.705, 1021.86, 1084.02, 1110.37, -731.998, 100.273, 87.2529, 'Davita_Gorgiladze', 8000000, 7, 0, 1, 0, 4, 'Mariam_Bagrationi', 'None', 0, 0, 0, 0, 0, 118400, 1100, 225.671, 1023.69, 1084.01, 1),
(154, -2168.77, 1081.44, 80.0131, 83.0589, 1322.55, 1083.87, -2159.69, 1089.14, 79.8516, 102.862, 'The State', 3000000, 9, 1, 0, 0, 2, 'Mari_Gvalia', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(155, 1546.47, 32.2625, 24.1406, 234.138, 1063.9, 1084.21, 1557.29, 31.0776, 24.1641, 14.4234, 'The State', 5000000, 6, 1, 0, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(156, 1017.15, -763.363, 112.563, 225.705, 1021.86, 1084.02, 1022.13, -780.153, 102.771, 107.563, 'Nika_Asanidze', 8000000, 7, 1, 1, 0, 4, 'Nika_Kvesadze', 'None', 0, 0, 0, 0, 0, 53500, 1100, 225.671, 1023.69, 1084.01, 0),
(157, 398.158, -1271.37, 50.0198, 225.705, 1021.86, 1084.02, 406.459, -1264.09, 50.3844, 22.4018, 'Otiko_Tik', 8000000, 7, 1, 1, 0, 4, 'Nika_Yul', 'None', 0, 0, 0, 0, 0, 124200, 1100, 225.671, 1023.69, 1084.01, 0),
(158, 1535.66, -885.177, 57.6575, 225.705, 1021.86, 1084.02, 1529.04, -886.338, 61.1224, 41.2011, 'Luka_Xizanashvili', 8000000, 7, 1, 1, 0, 4, 'Nick_Crown', 'Niikusha_Abashiidze', 0, 50, 0, 0, 0, 63300, 1100, 225.671, 1023.69, 1084.01, 0),
(159, 1297.63, -1423.88, 14.9531, 225.705, 1021.86, 1084.02, 1295.96, -1410.93, 13.3767, 84.3756, 'Ghost_Drifter', 8000000, 7, 0, 1, 0, 4, 'None', 'Ghost_Rider', 0, 0, 0, 0, 0, 100100, 1100, 225.671, 1023.69, 1084.01, 0),
(160, 827.656, -858.037, 70.3308, 225.705, 1021.86, 1084.02, 837.013, -872.662, 68.8494, 106.215, 'Reismus_Marley', 8000000, 7, 0, 1, 0, 4, 'Katarina_Morgan', 'None', 0, 0, 0, 0, 0, 125600, 1100, 225.671, 1023.69, 1084.01, 0),
(161, 201.467, -120.235, 1.55143, 225.705, 1021.86, 1084.02, 215.812, -127.778, 1.57549, 264.08, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(162, 923.874, -853.322, 93.4565, 225.705, 1021.86, 1084.02, 926.449, -850.845, 93.5033, 8.03451, 'Apollo_Malishava', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 1, 98700, 1100, 225.671, 1023.69, 1084.01, 1),
(163, 305.311, -1770.78, 4.53823, 83.0589, 1322.55, 1083.87, 321.532, -1787.59, 4.73796, 177.662, 'Lazvina_Ace', 3000000, 9, 1, 1, 0, 2, 'Dato_Korleone', 'None', 100, 0, 300, 200, 0, 58400, 700, 83.0539, 1324.44, 1083.86, 0),
(164, 724.835, -999.444, 52.7344, 234.138, 1063.9, 1084.21, 726.111, -995.576, 52.7344, 58.6039, 'Nika_Chelishvili', 5000000, 6, 0, 1, 0, 3, 'Guka_Janski', 'None', 0, 100, 0, 0, 0, 87900, 900, 234.258, 1066.21, 1084.21, 1),
(165, 700.433, -1060.02, 49.4217, 225.705, 1021.86, 1084.02, 675.058, -1046.81, 49.959, 152.243, 'Ann_Blackstar', 8000000, 7, 1, 1, 0, 4, 'Baji_Keisuke', 'None', 0, 0, 0, 0, 0, 171200, 1100, 225.671, 1023.69, 1084.01, 0),
(166, -2174.77, 75.9789, 35.3203, 225.705, 1021.86, 1084.02, 1276.14, -1264.02, 13.5194, 18.3151, 'The State', 8000000, 7, 1, 0, 0, 4, 'Jon_Maklery', 'None', 0, 150, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(167, 312.721, -121.382, 3.53539, 225.705, 1021.86, 1084.02, 317.663, -127.344, 2.39953, 268.951, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(168, 558.606, -1161.18, 54.4297, 225.705, 1021.86, 1084.02, 566.582, -1144.98, 51.3128, 70.6874, 'Zukito_Montana', 8000000, 7, 0, 1, 0, 4, 'Niko_Moseshvili', 'Aleko_Mose', 58, 0, 0, 0, 0, 77800, 1100, 225.671, 1023.69, 1084.01, 1),
(169, 312.721, -92.3476, 3.53539, 83.0589, 1322.55, 1083.87, 317.894, -85.23, 2.36012, 272.926, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(170, -2625.67, -191.057, 7.20312, 2270.05, -1210.46, 1047.56, -2615.96, -194.884, 4.33594, 275.783, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'Scarlett_Johansson', 0, 0, 0, 0, 0, 30000, 500, 2265.62, -1210.51, 1049.02, 0),
(171, 612.334, -1085.75, 58.8267, 225.705, 1021.86, 1084.02, 628.908, -1100.01, 46.7244, 192.125, 'Tengo_Costelo', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 182900, 1100, 225.671, 1023.69, 1084.01, 1),
(172, 1299.31, -795.493, 996.991, 2308.8, -1212.84, 1049.02, 281.556, -1255.77, 73.8831, 305.489, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(173, 2014.22, 775.194, 11.4609, 225.705, 1021.86, 1084.02, 2009.42, 768.947, 11.3594, 192.584, 'Camille_Ottoponymi', 8000000, 7, 0, 1, 0, 4, 'Giorgi_Mgeladze', 'None', 0, 0, 0, 0, 0, 133100, 1100, 225.671, 1023.69, 1084.01, 1),
(174, 251.663, -1220.57, 76.0143, 225.705, 1021.86, 1084.02, 258.682, -1230.18, 73.6763, 213.682, 'Nodo_Babaiani', 8000000, 7, 1, 1, 0, 4, 'Jack_Clown', 'None', 0, 0, 0, 0, 0, 111100, 1100, 225.671, 1023.69, 1084.01, 1),
(175, 1685.02, -2098.35, 13.8343, 225.705, 1021.86, 1084.02, 1709.43, -2112.73, 13.3828, 83.4902, 'The State', 8000000, 7, 1, 0, 0, 4, 'Andre_Bryant', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(176, 2459.31, -1691.12, 13.5475, 225.705, 1021.86, 1084.02, 2501.3, -1685.02, 13.4592, 26.2193, 'The State', 8000000, 7, 1, 0, 0, 4, 'Akiraa_Restock', 'Peregrinski_Restock', 300, 50, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(177, 605.337, -2060.39, 8.84689, 83.0589, 1322.55, 1083.87, 563.559, -2023.67, 1.99018, 1.26315, 'Maladoi_Parin', 3000000, 9, 0, 1, 0, 2, 'Mariam_Cecxladze', 'Starik_Primeiro', 0, 0, 0, 0, 0, 85300, 700, 83.0539, 1324.44, 1083.86, 0),
(178, 355.146, -1281.14, 53.7036, 225.705, 1021.86, 1084.02, 355.575, -1277.15, 53.8628, 289.486, 'Ken_Rosenberg', 8000000, 7, 0, 1, 0, 4, 'Marry_Jane', 'None', 0, 0, 0, 0, 0, 74400, 1100, 225.671, 1023.69, 1084.01, 0),
(179, 470.721, -1163.57, 67.2178, 234.138, 1063.9, 1084.21, 472.176, -1168.45, 65.9077, 200.138, 'Theodor_Bagwall', 5000000, 6, 1, 1, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 107100, 900, 234.258, 1066.21, 1084.21, 1),
(180, 1952.05, 1342.88, 15.3746, 225.705, 1021.86, 1084.02, 1967.26, 1315.89, 9.25781, 145.848, 'Giorgi_Mskhaladze', 8000000, 7, 0, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 83600, 1100, 225.671, 1023.69, 1084.01, 0),
(181, 23.4998, -2646.69, 40.4645, 225.705, 1021.86, 1084.02, 30.9835, -2660.54, 40.539, 93.2585, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Oldboy_Drifter', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(182, 33.9791, -2649.87, 40.7285, 225.705, 1021.86, 1084.02, 26.3254, -2633.92, 40.4054, 86.9328, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Alonzo_Fallen', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(183, 1105.15, -785.849, 105.773, 225.705, 1021.86, 1084.02, 1089.47, -782.696, 107.483, 65.4701, 'Animeshnik_Paparsky', 8000000, 7, 1, 1, 0, 4, 'None', 'Bryne_Anderson', 0, 0, 0, 0, 0, 166100, 1100, 225.671, 1023.69, 1084.01, 0),
(184, 858.688, -828.66, 89.5017, 234.138, 1063.9, 1084.21, 860.508, -849.351, 77.2069, 213.101, 'Micheal_Korleone', 5000000, 6, 1, 1, 0, 3, 'None', 'None', 0, 0, 0, 0, 1, 121500, 900, 234.258, 1066.21, 1084.21, 1),
(185, 910.506, -817.482, 103.126, 225.705, 1021.86, 1084.02, 912.943, -834.645, 92.5944, 199.272, 'Tamo_Intex', 8000000, 7, 0, 1, 0, 4, 'Daviti_Bolkvadze', 'None', 0, 0, 0, 0, 0, 161100, 1100, 225.671, 1023.69, 1084.01, 1),
(186, -75.2984, -1580.73, 3.423, 234.138, 1063.9, 1084.21, -69.0324, -1580.4, 2.61719, 223.891, 'Nikusha_Nonikashvili', 5000000, 6, 1, 1, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 129100, 900, 234.258, 1066.21, 1084.21, 1),
(187, -90.6999, -1592.67, 3.00431, 234.138, 1063.9, 1084.21, -100.899, -1584.72, 2.61719, 292.903, 'Jora_Jorashvili', 5000000, 6, 1, 1, 0, 3, 'Zuck_Marley', 'Luck_Papillon', 0, 0, 0, 0, 0, 79480, 900, 234.258, 1066.21, 1084.21, 0),
(188, -45.1169, -1564.13, 2.59987, 234.138, 1063.9, 1084.21, -52.6072, -1565.06, 2.61719, 111.869, 'Nikita_Kravchenko', 5000000, 6, 1, 1, 0, 3, 'Utu_Miqa', 'None', 0, 0, 0, 0, 0, 76900, 900, 234.258, 1066.21, 1084.21, 1),
(189, 1045.23, -642.551, 120.117, 225.705, 1021.86, 1084.02, 1038.91, -640.288, 121.163, 8.83682, 'David_Bagrationi', 8000000, 7, 1, 1, 0, 4, 'Tako_Teresa', 'Irakli_Khasaia', 0, 0, 0, 0, 0, 169400, 1100, 225.671, 1023.69, 1084.01, 0),
(190, 1564.63, -1897.91, 13.5609, 225.705, 1021.86, 1084.02, 1561.17, -1879.15, 13.5469, 72.4843, 'Nika_Shalamberidze', 8000000, 7, 0, 1, 0, 4, 'Guga_Power', 'None', 0, 0, 0, 0, 0, 141500, 1100, 225.671, 1023.69, 1084.01, 0),
(191, 701.5, -518.479, 16.3245, 83.0589, 1322.55, 1083.87, 703.751, -529.292, 16.1875, 12.236, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'Luka_Gabo', 0, 0, 0, 0, 0, 39900, 700, 83.0539, 1324.44, 1083.86, 0),
(192, 2307.23, -1785.73, 13.5571, 234.138, 1063.9, 1084.21, 2299.36, -1786.17, 13.5469, 2.84359, 'Dato_Khatchapuridze', 5000000, 6, 1, 1, 0, 3, 'Nata_Kazimov', 'Alucard_Goldmeno', 0, 0, 0, 0, 0, 138600, 900, 234.258, 1066.21, 1084.21, 1),
(193, -1655.09, 1411.9, 7.17969, 225.705, 1021.86, 1084.02, 1679.26, -1460.04, 13.5469, 271.983, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 150, 300, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(194, -2278.83, 747.929, 49.4393, 225.705, 1021.86, 1084.02, 367.752, -2030.74, 7.67188, 359.293, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 288, 300, 200, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(195, 2486.46, -1644.53, 14.0772, 234.138, 1063.9, 1084.21, 2486.61, -1659.59, 13.3359, 179.86, 'The State', 5000000, 6, 1, 0, 0, 3, 'Shamowine_Undead', 'None', 0, 220, 310, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(196, 865.117, -1634.3, 14.9297, 225.705, 1021.86, 1084.02, 858.707, -1663.02, 13.55, 267.72, 'Sofia_Amn', 8000000, 7, 0, 1, 0, 4, 'Blood_Impulse', 'Sofia_Damn', 240, 0, 0, 0, 0, 91700, 1100, 225.671, 1023.69, 1084.01, 0),
(197, 344.626, -71.1878, 2.43081, 225.705, 1021.86, 1084.02, 338.875, -80.3998, 1.51758, 83.6126, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(198, -2447.37, 821.619, 35.1797, 2270.05, -1210.46, 1047.56, -2436.54, 815.709, 35.1797, 179.486, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'Luke_Anderson', 0, 0, 0, 0, 0, 500, 500, 2265.62, -1210.51, 1049.02, 0),
(199, -2402.42, 829.309, 36.8767, 83.0589, 1322.55, 1083.87, -2400.93, 824.64, 36.0308, 267.007, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 700, 700, 83.0539, 1324.44, 1083.86, 0),
(200, 965.116, -1612.78, 14.9441, 83.0589, 1322.55, 1083.87, 939.069, -1625.96, 13.5469, 92.0902, 'Nika_Mirvadze', 3000000, 9, 0, 1, 0, 2, 'Beqa_Gotti', 'Nutsa_Kurdadze', 300, 0, 0, 0, 0, 59500, 700, 83.0539, 1324.44, 1083.86, 0),
(201, 1527.8, -772.569, 80.5781, 225.705, 1021.86, 1084.02, 1515.97, -766.675, 80.0146, 137.966, 'Frank_Kamikaze', 8000000, 7, 1, 1, 0, 4, 'Hector_Disepticon', 'None', 0, 0, 0, 0, 0, 114474, 1100, 225.671, 1023.69, 1084.01, 0),
(202, 207.091, -1768.88, 4.37034, 225.705, 1021.86, 1084.02, 208.381, -1774.91, 3.7954, 91.1649, 'Suicide_Paranoia', 8000000, 7, 1, 1, 0, 4, 'None', 'Levi_Ackerman', 0, 0, 0, 0, 1, 181500, 1100, 225.671, 1023.69, 1084.01, 1),
(203, -53.7472, -1557.98, 2.61719, 225.705, 1021.86, 1084.02, -36.8473, -1575.44, 4.0126, 331.293, 'Ketrin_Devon', 8000000, 7, 1, 1, 0, 4, 'Nika_Bagatelia', 'Ghoste_Mane', 0, 0, 0, 0, 0, 171600, 1100, 225.671, 1023.69, 1084.01, 1),
(204, 750.586, -1806.52, 13.0234, 225.705, 1021.86, 1084.02, 755.771, -1817.64, 13.0234, 358.943, 'Jeims_Broun', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 163900, 1100, 225.671, 1023.69, 1084.01, 0),
(205, 295.117, -54.5434, 2.77721, 225.705, 1021.86, 1084.02, 287.617, -52.6357, 1.57812, 184.022, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(206, 2373.85, 42.2528, 28.4416, 225.705, 1021.86, 1084.02, 2378.62, 37.8374, 27.3364, 269.586, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(207, 1845.44, 741.353, 11.4609, 234.138, 1063.9, 1084.21, 1851.01, 734.719, 11.3831, 272.426, 'Synexx_Oldback', 5000000, 6, 1, 1, 0, 3, 'Tommy_Black', 'Someone_Fellow', 0, 0, 0, 0, 0, 145900, 900, 234.258, 1066.21, 1084.21, 1),
(208, 1093.82, -806.941, 107.42, 225.705, 1021.86, 1084.02, 1090.26, -785.149, 107.353, 62.4766, 'Frady_Parker', 8000000, 7, 1, 1, 0, 4, 'Georg_Moralez', 'None', 0, 0, 0, 0, 0, 182700, 1100, 225.671, 1023.69, 1084.01, 0),
(209, -1005.28, 1848.29, 780.666, 83.0589, 1322.55, 1083.87, -2547.87, 913.964, 64.9844, 176.794, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(210, 1863.78, -1597.28, 14.3062, 83.0589, 1322.55, 1083.87, 1862.98, -1603.38, 13.5391, 171.65, 'Jack_Godson', 3000000, 9, 0, 1, 0, 2, 'Martin_Diaz', 'Nick_Montana', 0, 0, 101, 0, 0, 79800, 700, 83.0539, 1324.44, 1083.86, 0),
(211, 1567.94, -1898.01, 13.5609, 225.705, 1021.86, 1084.02, 1570.87, -1872.93, 13.3828, 91.1909, 'Tony_Beliakovi', 8000000, 7, 1, 1, 0, 4, 'Koko_Stochker', 'Meggan_Wiliams', 0, 0, 400, 300, 0, 178300, 1100, 225.671, 1023.69, 1084.01, 1),
(212, 771.127, -1510.69, 13.5469, 225.705, 1021.86, 1084.02, 775.891, -1515.56, 13.5547, 171.29, 'Aleks_Johnos', 8000000, 7, 1, 1, 0, 4, 'None', 'Saba_Tchelidze', 0, 0, 0, 0, 0, 129800, 1100, 225.671, 1023.69, 1084.01, 1),
(213, 739.151, -1418.51, 13.5234, 225.705, 1021.86, 1084.02, 708.652, -1423.26, 13.5318, 1.42244, 'Giorgi_Maruashvili', 8000000, 7, 0, 1, 0, 4, 'Curse_Primeiro', 'Suicideboy_Undead', 0, 0, 0, 0, 1, 83600, 1100, 225.671, 1023.69, 1084.01, 0),
(214, 1396.92, -1569.9, 14.2683, 225.705, 1021.86, 1084.02, 1381.64, -1567.07, 13.5921, 170.085, 'Nika_Cabadze', 8000000, 7, 1, 1, 0, 4, 'Logan_Purdy', 'Maik_Lukas', 0, 0, 0, 0, 0, 152900, 1100, 225.671, 1023.69, 1084.01, 1),
(215, -1005.94, 1846.86, 788.778, 83.0589, 1322.55, 1083.87, 1403.76, -1597.8, 13.5469, 261.842, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(216, 849.596, -1519.94, 14.3482, 1972.52, -1553.17, 2451.34, 855.78, -1512.25, 13.2923, 265.709, 'Seabstian_Uiop', 8000000, 12, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 144500, 1100, 225.671, 1023.69, 1084.01, 0),
(217, 2439.59, -1357.19, 24.1007, 225.705, 1021.86, 1084.02, 2443.52, -1352.26, 24, 355.557, 'The State', 8000000, 7, 1, 0, 0, 4, 'Jack_Gallagher', 'None', 0, 0, 0, 0, 0, 44300, 1100, 225.671, 1023.69, 1084.01, 0),
(218, 1909.71, -1597.72, 14.3062, 225.705, 1021.86, 1084.02, 1915.69, -1605.68, 13.5469, 263.987, 'The State', 8000000, 7, 1, 0, 0, 4, 'Romani_Kodua', 'Luka_Mazmishvilii', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(219, 1274.18, 2522.49, 10.8203, 225.705, 1021.86, 1084.02, 1285.05, 2528.58, 10.8203, 136.052, 'The State', 8000000, 7, 1, 0, 0, 4, 'Erekle_Flacko', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(220, 2439.59, -1338.98, 24.1016, 234.138, 1063.9, 1084.21, 2444.47, -1331.77, 24, 165.548, 'The State', 5000000, 6, 1, 0, 0, 3, 'None', 'Diamond_Master', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(221, 295.289, -1764.12, 4.86897, 225.705, 1021.86, 1084.02, 303.713, -1734.67, 4.29855, 46.6164, 'Zura_Costello', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 300, 0, 0, 1, 1100, 1100, 225.671, 1023.69, 1084.01, 1),
(222, 1285.26, -1090.16, 28.2578, 225.705, 1021.86, 1084.02, 1278.19, -1098.96, 26.0518, 81.1308, 'Tomas_Williams', 8000000, 7, 1, 1, 0, 4, 'None', 'Kaxa_Ortoidze', 0, 0, 0, 0, 0, 141500, 1100, 225.671, 1023.69, 1084.01, 0),
(223, 1094.54, -647.384, 113.648, -1036.53, -2205.94, 1501.09, 1088.73, -633.592, 112.586, 270.008, 'Andria_Axalaia', 8000000, 10, 1, 1, 0, 4, 'None', 'Hawk_Raven', 0, 0, 0, 0, 1, 134200, 1100, 225.671, 1023.69, 1084.01, 1),
(224, 1359.34, -339.612, 1474.17, 2308.8, -1212.84, 1049.02, 1368.51, -1089.51, 24.5795, 169.235, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(225, 1377.81, -1753.14, 14.1406, 225.705, 1021.86, 1084.02, 1376.02, -1771.35, 13.5469, 269.557, 'Pako_Michelson', 8000000, 7, 0, 1, 0, 4, 'Wolter_Bishop', 'None', 0, 0, 0, 0, 0, 91000, 1100, 225.671, 1023.69, 1084.01, 0),
(226, 2751.5, -1914.05, 13.5469, 225.705, 1021.86, 1084.02, 2763.07, -1906.21, 11.6888, 183.795, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(227, 1242.26, -1099.42, 27.9766, 225.705, 1021.86, 1084.02, 1254.37, -1105.15, 25.3486, 179.215, 'King_Pachko', 8000000, 7, 0, 1, 0, 4, 'Sabski_Manson', 'Giorgi_Bichiashvili', 0, 0, 0, 0, 0, 171600, 1100, 225.671, 1023.69, 1084.01, 1),
(228, 2433.93, -1320.66, 25.3234, 234.138, 1063.9, 1084.21, 2443.09, -1325.94, 24, 183.44, 'Giorgi_Khetsuriani', 5000000, 6, 0, 1, 0, 3, 'Akaki_Tsinadze', 'None', 0, 0, 0, 0, 0, 83700, 900, 234.258, 1066.21, 1084.21, 1),
(229, 1362.87, 2525.6, 10.8203, 234.138, 1063.9, 1084.21, 1369.23, 2519.22, 10.8203, 82.9565, 'The State', 5000000, 6, 1, 0, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(230, -798.726, 2263.61, 58.847, 83.0589, 1322.55, 1083.87, -802.535, 2260.88, 58.6757, 171.039, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0);
INSERT INTO `house` (`hID`, `hEntrancex`, `hEntrancey`, `hEntrancez`, `hExitx`, `hExity`, `hExitz`, `hCarx`, `hCary`, `hCarz`, `hCarc`, `hOwner`, `hValue`, `hInt`, `hLock`, `hOwned`, `hDate`, `hKlass`, `hM1`, `hM2`, `hNarko`, `hDgl`, `hEm`, `hShot`, `hGarageStatus`, `hBalance`, `hTax`, `hShesvlax`, `hShesvlay`, `hShesvlaz`, `hBtcStatus`) VALUES
(231, 2162.71, -1815.23, 13.5469, 234.138, 1063.9, 1084.21, 2157.11, -1798.27, 13.3665, 265.842, 'Federico_Restock', 5000000, 6, 1, 1, 0, 3, 'None', 'None', 100, 0, 51, 0, 0, 26900, 900, 234.258, 1066.21, 1084.21, 0),
(232, 2155.79, -1815.23, 13.5469, 2270.05, -1210.46, 1047.56, 2159.63, -1807.52, 13.373, 319.498, 'Giorgi_Vardukadze', 1000000, 10, 1, 1, 0, 1, 'None', 'None', 297, 0, 0, 0, 1, 79644, 500, 2265.62, -1210.51, 1049.02, 1),
(233, 2257.04, -1643.94, 15.8082, 225.705, 1021.86, 1084.02, 2256.57, -1649.69, 15.4759, 180.781, 'The State', 8000000, 7, 1, 0, 0, 4, 'Stiv_Mornigstar', 'Zeni_Agatasuma', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(234, 2441.38, -1389.83, 24, 225.705, 1021.86, 1084.02, 2446.45, -1384.91, 23.824, 1.28298, 'The State', 8000000, 7, 1, 0, 0, 4, 'Sam_Konson', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(235, 2326.88, -1681.89, 14.9297, 225.705, 1021.86, 1084.02, 2328.76, -1677.51, 14.425, 266.199, 'Sergi_Qiria', 8000000, 7, 1, 1, 0, 4, 'None', 'Elisa_Destinez', 0, 0, 0, 0, 0, 101100, 1100, 225.671, 1023.69, 1084.01, 0),
(236, 1090.15, -1234.85, 15.8203, 225.705, 1021.86, 1084.02, 1084.88, -1218.73, 17.812, 358.315, 'Eric_Eazy', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 70400, 1100, 225.671, 1023.69, 1084.01, 0),
(237, 1583.03, -1274.89, 17.5687, 225.705, 1021.86, 1084.02, 1586.06, -1281.72, 17.5601, 94.3186, 'The State', 8000000, 7, 1, 0, 0, 4, 'Luck_Maccol', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(238, 1704.11, -1578.71, 13.8879, 225.705, 1021.86, 1084.02, 1712.45, -1591.95, 13.3626, 165.067, 'James_Bond', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 175300, 1100, 225.671, 1023.69, 1084.01, 0),
(239, 2441.38, -1382.95, 24, 225.705, 1021.86, 1084.02, 2447.29, -1386.18, 23.8252, 355.768, 'The State', 8000000, 7, 1, 0, 0, 4, 'Infex_Destinez', 'None', 0, 0, 0, 0, 0, 124200, 1100, 225.671, 1023.69, 1084.01, 0),
(240, -311.293, 1303.71, 53.6643, 225.705, 1021.86, 1084.02, -293.25, 1299.42, 53.7951, 84.1418, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 31900, 1100, 225.671, 1023.69, 1084.01, 0),
(241, 1326.26, -1090.56, 27.9766, 225.705, 1021.86, 1084.02, 1336.71, -1100.87, 23.9854, 315.029, 'Manjiro_Sano', 8000000, 7, 1, 1, 0, 4, 'Francesco_Luther', 'None', 0, 0, 0, 0, 0, 75900, 1100, 225.671, 1023.69, 1084.01, 1),
(242, 1084.85, -1158.44, 23.8281, 225.705, 1021.86, 1084.02, 1088.32, -1150.33, 23.6562, 332.878, 'Levaniko_Qobuladze', 8000000, 7, 0, 1, 0, 4, 'Nika_Jayeli', 'None', 7, 126, 0, 0, 0, 130400, 1100, 225.671, 1023.69, 1084.01, 0),
(243, 660.036, -520.652, 16.3359, 225.705, 1021.86, 1084.02, 660.143, -524.388, 16.3359, 252.179, 'The State', 8000000, 7, 1, 0, 0, 4, 'Giigson_Anderson', 'Babu_Ganabsky', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(244, 2460.68, -1343.91, 24, 2270.05, -1210.46, 1047.56, 2456.69, -1345.4, 23.9922, 0.145364, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'Natoshi_Sakamoto', 0, 0, 0, 0, 0, 0, 500, 2265.62, -1210.51, 1049.02, 0),
(245, 2441.38, -1376.09, 24, 234.138, 1063.9, 1084.21, 2444.61, -1380.8, 24, 180.92, 'The State', 5000000, 6, 1, 0, 0, 3, 'Dybalito_Mafioz', 'None', 0, 200, 200, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(246, 1325.95, -1067.87, 31.5547, 83.0589, 1322.55, 1083.87, 1330.74, -1073.27, 28.066, 358.817, 'Luka_Gogolashvili', 3000000, 9, 0, 1, 0, 2, 'Nika_Endeladzee', 'Luka_Focxverashvili', 0, 0, 0, 0, 1, 101825, 700, 83.0539, 1324.44, 1083.86, 0),
(247, 229.331, -1744.51, 4.6981, 225.705, 1021.86, 1084.02, 231.26, -1740.65, 4.36556, 251.232, 'Mark_Personi', 8000000, 7, 0, 1, 0, 4, 'Whiteboy_Carl', 'None', 0, 0, 0, 0, 0, 54600, 1100, 225.671, 1023.69, 1084.01, 0),
(248, -329.943, 1172.66, 20.9399, 225.705, 1021.86, 1084.02, -361.417, 1198.54, 19.7422, 181.746, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(249, 2016.54, -1641.7, 14.1129, 2439.13, -95.9364, 1146.88, 2021.69, -1649.05, 13.5547, 270.062, 'Diazz_Admiral', 200000, 6, 1, 1, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 12600, 300, 2308.59, -1210.86, 1049.02, 1),
(250, 2244.57, -1637.66, 16.2379, 83.0589, 1322.55, 1083.87, 2229.85, -1649.54, 15.311, 156.695, 'Cotne_Vashakidze', 3000000, 9, 1, 1, 0, 2, 'Tornike_Vashakidze', 'None', 100, 0, 0, 0, 0, 88200, 700, 83.0539, 1324.44, 1083.86, 0),
(251, 2129.63, -1361.69, 26.1363, 234.138, 1063.9, 1084.21, 2137.43, -1367.05, 24.9232, 180.114, 'The State', 5000000, 6, 1, 0, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(252, -1006.52, 1845.6, 799.878, 2308.8, -1212.84, 1049.02, 1525.58, -2445.4, 13.5547, 186.831, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(253, 2460.68, -1336.73, 24, 225.705, 1021.86, 1084.02, 2455.35, -1334.55, 23.8359, 186.326, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(254, 1929.52, 2774.33, 10.8203, 225.705, 1021.86, 1084.02, 1918.26, 2767.7, 10.8265, 89.8453, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(255, 2007.06, 2910.17, 47.8231, 225.705, 1021.86, 1084.02, 1993.33, 2912.9, 44.7662, 167.857, 'The State', 8000000, 7, 1, 0, 0, 4, 'Coca_Disepticon', 'Santino_Reina', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(256, 2126.65, -1320.86, 26.624, 225.705, 1021.86, 1084.02, 2135.75, -1320.9, 25.0904, 3.25834, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(257, 1973.8, -1654.83, 15.9688, 83.0589, 1322.55, 1083.87, 1980.21, -1658.44, 15.9688, 272.32, 'Phill_Uwie', 3000000, 9, 1, 1, 0, 2, 'Nika_Unberidze', 'Kostuma_Seyn', 0, 0, 0, 0, 0, 33600, 700, 83.0539, 1324.44, 1083.86, 1),
(258, 2066.25, 2722.31, 10.8203, 2308.8, -1212.84, 1049.02, 2063.63, 2733.86, 10.8203, 25.598, 'Andria_Dzalganian', 200000, 6, 1, 1, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 36700, 300, 2308.59, -1210.86, 1049.02, 1),
(259, 2067.56, -1643.69, 14.1363, 234.138, 1063.9, 1084.21, 2073.19, -1646.72, 13.5469, 354.825, 'The State', 5000000, 6, 1, 0, 0, 3, 'None', 'None', 20, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(260, -2368.82, 711.995, 35.1732, 225.705, 1021.86, 1084.02, 529.26, -2034.1, 4.67262, 275.69, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(261, 937.784, -848.754, 93.5771, 234.138, 1063.9, 1084.21, 944.091, -840.918, 94.2108, 27.6058, 'Temuri_Montana', 5000000, 6, 1, 1, 0, 3, 'None', 'Ruby_Banett', 0, 0, 0, 0, 0, 51500, 900, 234.258, 1066.21, 1084.21, 0),
(262, 1081.04, -1696.79, 13.5469, 225.705, 1021.86, 1084.02, 1079.94, -1706.21, 13.5469, 172.008, 'Levan_Brown', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 200, 200, 100, 0, 141500, 1100, 225.671, 1023.69, 1084.01, 0),
(263, 1892.21, -2328.55, 13.5469, 1972.52, -1553.17, 2451.34, 1902.94, -2335.96, 13.5469, 304.044, 'Goldz_Kartvela', 8000000, 12, 1, 1, 0, 4, 'None', 'Harry_Langston', 0, 0, 0, 0, 0, 55000, 1100, 225.671, 1023.69, 1084.01, 1),
(264, 2282.35, -1641.22, 15.8898, 225.705, 1021.86, 1084.02, 2271.71, -1643.76, 15.3644, 179.914, 'Luka_Tsiklauri', 8000000, 7, 1, 1, 0, 4, 'Irakli_Tedoradze', 'None', 0, 0, 0, 0, 0, 119400, 1100, 225.671, 1023.69, 1084.01, 0),
(265, 1921.71, 2664.22, 10.8203, 234.138, 1063.9, 1084.21, 1929.18, 2655.19, 10.8203, 4.27709, 'The State', 5000000, 6, 1, 0, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(266, 1950.56, 2664.5, 11.2989, 2270.05, -1210.46, 1047.56, 1959.77, 2653.56, 10.8203, 181.706, 'Kate_Moore', 1000000, 10, 0, 1, 0, 1, 'Jhon_Wick', 'None', 0, 0, 0, 0, 0, 48000, 500, 2265.62, -1210.51, 1049.02, 0),
(267, 1377.71, -1794.28, 13.4956, 234.138, 1063.9, 1084.21, 1385.9, -1794.69, 13.3828, 359.276, 'Gergian_Luka', 5000000, 6, 0, 1, 0, 3, 'Edmond_Clowton', 'None', 300, 0, 0, 0, 0, 88300, 900, 234.258, 1066.21, 1084.21, 1),
(268, 1377.71, -1797.91, 13.4955, 225.705, 1021.86, 1084.02, 1384.29, -1805.25, 13.3828, 358.176, 'Giorgi_Anderson', 8000000, 7, 1, 1, 0, 4, 'Giorgi_Gelashvili', 'None', 0, 0, 0, 0, 0, 151559, 1100, 225.671, 1023.69, 1084.01, 1),
(269, -2372.53, 783.928, 35.1154, 225.705, 1021.86, 1084.02, 595.086, -2020.68, 2.88474, 6.17765, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(270, 2364, 187.25, 28.4416, 225.705, 1021.86, 1084.02, 2357.2, 182.834, 27.0035, 272.404, 'The State', 8000000, 7, 1, 0, 0, 4, 'Nika_Qartveladze', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(271, 2483.41, -1995.34, 13.8343, 234.138, 1063.9, 1084.21, 2487.65, -2002.63, 14.7046, 89.6098, 'The State', 5000000, 6, 1, 0, 0, 3, 'West_Side', 'Shyxz_Painz', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(272, 2368.24, 655.065, 11.4609, 225.705, 1021.86, 1084.02, 2363.3, 646.967, 11.2235, 176.164, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(273, 1295.72, 288.063, 19.5547, 83.0589, 1322.55, 1083.87, 1300.09, 289.458, 19.5469, 156.926, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 700, 700, 83.0539, 1324.44, 1083.86, 0),
(274, 1090.14, -1234.85, 19.5917, 225.705, 1021.86, 1084.02, 1106.13, -1240.01, 15.8203, 284.482, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 33500, 1100, 225.671, 1023.69, 1084.01, 0),
(275, 207.709, -1826.33, 4.52425, 225.705, 1021.86, 1084.02, 209.493, -1817.02, 4.30263, 23.0082, 'Mirza_Shinki', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 141500, 1100, 225.671, 1023.69, 1084.01, 0),
(276, 2368.88, 689.8, 11.4605, 225.705, 1021.86, 1084.02, 2363.51, 696.214, 11.354, 50.1438, 'Alex_Chutkera', 8000000, 7, 1, 1, 0, 4, 'Giorgi_Gurgenidze', 'None', 0, 0, 0, 0, 0, 139000, 1100, 225.671, 1023.69, 1084.01, 0),
(277, -2281.2, -79.2389, 35.3203, 225.705, 1021.86, 1084.02, 1397.12, -2252.59, 13.5469, 209.853, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(278, -1664.27, 1406.39, 7.17969, 225.705, 1021.86, 1084.02, 1962.48, -1719.05, 15.9688, 359.568, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 184800, 1100, 225.671, 1023.69, 1084.01, 0),
(279, -2112.35, 795.741, 69.5684, 2750.68, 432.518, 1581.52, -1435.72, -948.127, 201.186, 158.754, 'The State', 8000000, 7, 1, 0, 0, 4, 'Favela_Rasala', 'None', 12, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(280, -2719.04, -318.832, 7.84375, 225.705, 1021.86, 1084.02, -2740.71, -300.192, 7.0139, 57.974, 'The State', 8000000, 7, 1, 0, 0, 4, 'Cotne_Kobaxidze', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(281, 2177.05, 690.802, 11.4609, 225.705, 1021.86, 1084.02, 2170.01, 712.056, 10.6719, 86.4713, 'Georg_Anderson', 8000000, 7, 0, 1, 0, 4, 'Giorgi_Maxaradze', 'None', 300, 147, 30, 0, 0, 184800, 1100, 225.671, 1023.69, 1084.01, 0),
(282, 2228.7, 689.884, 11.4605, 83.0589, 1322.55, 1083.87, 2220.78, 699.184, 11.1193, 355.534, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'Don_Corleone', 0, 100, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(283, 1096.5, -1235.06, 19.584, 225.705, 1021.86, 1084.02, 1102.24, -1238, 15.8203, 272.076, 'Oliver_Johnson', 8000000, 7, 0, 1, 0, 4, 'Girorgi_Surmanidze', 'Sandro_Porcxidze', 0, 0, 0, 0, 0, 122800, 1100, 225.671, 1023.69, 1084.01, 0),
(284, 1096.34, -1234.94, 15.8203, 83.0589, 1322.55, 1083.87, 1099.06, -1219.13, 17.8047, 3.93457, 'Tomass_Luther', 3000000, 9, 0, 1, 0, 2, 'None', 'Luka_Shermadini', 0, 0, 0, 0, 0, 26200, 700, 83.0539, 1324.44, 1083.86, 1),
(285, -1650.03, 1377.49, 7.17219, 225.705, 1021.86, 1084.02, 369.671, -1819.26, 7.6772, 358.381, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(286, 2120.28, 696.087, 11.4531, 225.705, 1021.86, 1084.02, 2128.75, 688.593, 11.2373, 188.976, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(287, 1712.34, 693.367, 11.6511, -1036.53, -2205.94, 1501.09, 1717.38, 717.948, 10.9, 72.9865, 'Luka_Khutsishvili', 5000000, 10, 1, 1, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 79400, 900, 234.258, 1066.21, 1084.21, 1),
(288, 1709.9, 1360.69, 10.7525, 225.705, 1021.86, 1084.02, 1722.28, 1373.34, 10.4922, 194.628, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(289, 1876.78, 760.407, 10.8203, 234.138, 1063.9, 1084.21, 1869.92, 745.347, 10.6719, 3.27279, 'Nika_Johnson', 5000000, 6, 1, 1, 0, 3, 'Omari_Begiashvili', 'None', 0, 0, 0, 0, 0, 17500, 900, 234.258, 1066.21, 1084.21, 1),
(290, 1615.47, 749.34, 11.5805, 1548.1, -7.4133, 1501.39, 1638.28, 763.193, 10.924, 220.727, 'Akaki_Stalone', 8000000, 5, 1, 1, 0, 4, 'El_Padrino', 'None', 140, 300, 0, 0, 0, 135200, 1100, 225.671, 1023.69, 1084.01, 0),
(291, 1634.11, 695.417, 11.4159, 225.705, 1021.86, 1084.02, 1631.07, 710.354, 10.93, 17.9328, 'Giorgi_Shavshishvili', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 72999, 1100, 225.671, 1023.69, 1084.01, 1),
(292, 1680.62, 689.363, 11.6184, 2439.13, -95.9364, 1146.88, 1679.72, 704.474, 10.93, 289.865, 'Sebastian_Malboro', 8000000, 6, 0, 1, 0, 4, 'Ghoul_Trooper', 'Logan_Toreto', 0, 0, 0, 0, 0, 170300, 1100, 225.671, 1023.69, 1084.01, 1),
(293, 1708.25, 1360.9, 10.7521, 83.0589, 1322.55, 1083.87, 1727.27, 1376.76, 10.4922, 15.856, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(294, 2122.39, 731.264, 11.4609, 225.705, 1021.86, 1084.02, 2128.6, 742.105, 11.0132, 338.222, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Marikuna_Kalichava', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(295, 2093.54, 730.361, 11.4531, 225.705, 1021.86, 1084.02, 2085.8, 739.409, 11.1382, 7.70436, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 80300, 1100, 225.671, 1023.69, 1084.01, 0),
(296, 1665.29, 755.594, 11.6184, 225.705, 1021.86, 1084.02, 1662.32, 740.028, 10.924, 82.592, 'Frank_Costello', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 1, 181200, 1100, 225.671, 1023.69, 1084.01, 0),
(297, 848.097, -745.632, 94.9693, 2439.13, -95.9364, 1146.88, 855.046, -747.067, 94.9688, 226.823, 'Nika_Zaalishvili', 8000000, 6, 1, 1, 0, 4, 'Boris_Garuchava', 'Tommy_Mesaflave', 100, 0, 0, 0, 0, 109600, 1100, 225.671, 1023.69, 1084.01, 1),
(298, 2013.67, 730.36, 11.4531, 225.705, 1021.86, 1084.02, 2004.95, 739.481, 11.1232, 5.93065, 'Fred_Green', 8000000, 7, 1, 1, 0, 4, 'Mike_Wilson', 'None', 0, 0, 0, 0, 1, 177800, 1100, 225.671, 1023.69, 1084.01, 0),
(299, 1090.07, -1242.41, 19.5917, 225.705, 1021.86, 1084.02, 1107, -1219.09, 17.8047, 358.466, 'The State', 8000000, 7, 1, 0, 0, 4, 'Paul_Scalleta', 'None', 0, 0, 0, 0, 0, 18700, 1100, 225.671, 1023.69, 1084.01, 0),
(300, 1034.93, -813.144, 101.852, 225.705, 1021.86, 1084.02, 1029.8, -812.155, 101.852, 25.52, 'Jacob_Montana', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 126500, 1100, 225.671, 1023.69, 1084.01, 0),
(301, 2093.5, 774.928, 11.4531, 225.705, 1021.86, 1084.02, 2087.56, 768.666, 11.3122, 174.452, 'Jack_Teller', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 181100, 1100, 225.671, 1023.69, 1084.01, 0),
(302, -419.013, -1759.29, 6.21875, 225.705, 1021.86, 1084.02, -414.714, -1762.54, 5.51307, 287.431, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 300, 300, 300, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(303, 2508.19, -1998.36, 13.9025, 225.705, 1021.86, 1084.02, 2513.05, -2003.34, 13.5469, 85.9154, 'The State', 8000000, 7, 1, 0, 0, 4, 'Zeus_Leafs', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(304, 2507.81, -2021.05, 14.2101, 225.705, 1021.86, 1084.02, 2510.21, -2014.72, 13.5469, 91.1624, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(305, 2486.52, -2021.55, 13.9988, 225.705, 1021.86, 1084.02, 2493.33, -2017.21, 13.5469, 83.9285, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(306, 2465.4, -2020.79, 14.1242, 234.138, 1063.9, 1084.21, 2465.49, -2016.43, 13.5469, 82.2621, 'Gruzinski_Zura', 5000000, 6, 0, 1, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 81962, 900, 234.258, 1066.21, 1084.21, 1),
(307, 2437.96, -2020.84, 13.9025, 225.705, 1021.86, 1084.02, 2441.44, -2014.76, 13.5469, 87.6449, 'The State', 8000000, 7, 1, 0, 0, 4, 'Craig_McDock', 'None', 0, 0, 0, 0, 0, 26400, 1100, 225.671, 1023.69, 1084.01, 0),
(308, 2465.11, -1995.75, 14.0193, 225.705, 1021.86, 1084.02, 2464.16, -2002.03, 15.0008, 90.3391, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(309, 808.286, -759.432, 76.5314, 225.705, 1021.86, 1084.02, 815.029, -766.428, 76.9779, 285.42, 'Sebastian_Wiliams', 8000000, 7, 0, 1, 0, 4, 'None', 'Gangs_Mula', 0, 0, 0, 0, 0, 178900, 1100, 225.671, 1023.69, 1084.01, 1),
(310, 1183.48, -1098.87, 28.2578, 225.705, 1021.86, 1084.02, 1179.74, -1108.16, 25.4369, 82.1766, 'Luka_Managadze', 8000000, 7, 0, 1, 0, 4, 'Black_Deme', 'Gabi_Jvania', 0, 0, 0, 0, 0, 39600, 1100, 225.671, 1023.69, 1084.01, 0),
(311, 1142.12, -1092.85, 28.1875, 225.705, 1021.86, 1084.02, 1144.92, -1101.2, 25.816, 269.918, 'Sio_Slime', 8000000, 7, 1, 1, 0, 4, 'Tony_Morningstar', 'Joji_Prestan', 0, 41, 50, 0, 0, 178800, 1100, 225.671, 1023.69, 1084.01, 1),
(312, 1183.47, -1075.97, 31.6789, 225.705, 1021.86, 1084.02, 1179.07, -1067.47, 28.9869, 87.7667, 'Longurashvili_Gio', 8000000, 7, 1, 1, 0, 4, 'Dato_Pholadashvili', 'None', 0, 0, 0, 0, 0, 30800, 1100, 225.671, 1023.69, 1084.01, 1),
(313, 1141.81, -1070.01, 31.7656, 83.0589, 1322.55, 1083.87, 1136.41, -1079.67, 29.3719, 270.796, 'The State', 3000000, 9, 1, 0, 0, 2, 'Giorgi_Ilura', 'Maxs_Wilson', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(314, 153.278, -1449.5, 32.845, 1548.1, -7.4133, 1501.39, 145.057, -1446.53, 30.7995, 114.945, 'Mate_Macharashvili', 8000000, 5, 1, 1, 0, 4, 'Alexandr_Belov', 'None', 0, 0, 0, 0, 0, 91400, 1100, 225.671, 1023.69, 1084.01, 1),
(315, -1011.99, 1899.58, 560.815, 2270.05, -1210.46, 1047.56, -358.762, 1530.17, 75.3594, 1.87116, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'None', 0, 0, 0, 0, 0, 0, 500, 2265.62, -1210.51, 1049.02, 0),
(316, 739.438, -556.783, 18.0129, 234.138, 1063.9, 1084.21, 750.09, -551.88, 17.2545, 2.22967, 'Davit_Gorgasali', 5000000, 6, 1, 1, 0, 3, 'Davit_Agmashenebelii', 'None', 0, 100, 150, 0, 0, 79200, 900, 234.258, 1066.21, 1084.21, 0),
(317, 693.575, -1705.73, 3.81948, 225.705, 1021.86, 1084.02, 705.801, -1743.66, 14.0445, 183.147, 'Pajarniki_Gela', 8000000, 7, 1, 1, 0, 4, 'George_Aqamkaiani', 'None', 0, 0, 0, 0, 0, 181100, 1100, 225.671, 1023.69, 1084.01, 0),
(318, 693.764, -1645.88, 4.09375, 225.705, 1021.86, 1084.02, 700.673, -1642.87, 3.42376, 265.556, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(319, 769.222, -1696.66, 5.15542, 225.705, 1021.86, 1084.02, 758.071, -1702.6, 5.23499, 3.72373, 'Dimitri_Mchedlidze', 8000000, 7, 1, 1, 0, 4, 'Tomi_Marcano', 'None', 0, 0, 0, 0, 1, 53299, 1100, 225.671, 1023.69, 1084.01, 0),
(320, 769.228, -1745.99, 13.0773, 225.705, 1021.86, 1084.02, 763.08, -1745.97, 12.5372, 12.4145, 'The State', 8000000, 7, 1, 0, 0, 4, 'Maradiko_Bediaa', 'Nastim_Sokaro', 150, 200, 250, 300, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(321, 768.031, -1655.59, 5.60938, 225.705, 1021.86, 1084.02, 765.379, -1660.79, 4.44872, 98.7436, 'Giorgi_Lanski', 8000000, 7, 0, 1, 0, 4, 'Amur_Shakur', 'None', 0, 0, 0, 0, 0, 144600, 1100, 225.671, 1023.69, 1084.01, 0),
(322, 656.734, -1481.07, 14.8516, 225.705, 1021.86, 1084.02, 645.621, -1474.25, 14.6298, 89.9705, 'Gio_Roinishvili', 8000000, 7, 1, 1, 0, 4, 'Mango_Kakurski', 'Lika_Mosiashvili', 0, 0, 0, 0, 0, 46100, 1100, 225.671, 1023.69, 1084.01, 0),
(323, 784.403, -1436, 13.5469, 225.705, 1021.86, 1084.02, 795.86, -1429.61, 13.3828, 181.838, 'Vito_Jenoveze', 8000000, 7, 0, 1, 0, 4, 'Leo_Jenoveze', 'None', 0, 0, 0, 0, 0, 119900, 1100, 225.671, 1023.69, 1084.01, 0),
(324, 822.419, -1505.52, 14.3976, 225.705, 1021.86, 1084.02, 836.433, -1500.76, 13.1819, 120.376, 'The State', 8000000, 7, 1, 0, 0, 4, 'Luka_Khutso', 'Zura_Zolotorev', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(325, 928.754, -1530.43, 13.5415, 225.705, 1021.86, 1084.02, 926.133, -1525.74, 13.5421, 88.6164, 'Harley_Davison', 8000000, 7, 0, 1, 0, 4, 'Sanji_Mumladze', 'Lobja_Lobjanidze', 0, 0, 0, 0, 0, 80100, 1100, 225.671, 1023.69, 1084.01, 0),
(326, 791.35, -1753.22, 13.4603, 225.705, 1021.86, 1084.02, 794.764, -1762.46, 13.5476, 85.7193, 'Jerry_Willam', 8000000, 7, 1, 1, 0, 4, 'Tengo_Willam', 'None', 0, 100, 300, 0, 1, 114900, 1100, 225.671, 1023.69, 1084.01, 0),
(327, 657.398, -1434.11, 14.8516, 225.705, 1021.86, 1084.02, 642.124, -1447.05, 14.142, 55.9779, 'The State', 8000000, 7, 1, 0, 0, 4, 'Encrypted_Hiraeth', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(328, -793.193, -821.646, 149.778, 225.705, 1021.86, 1084.02, -825.219, -869.488, 149.182, 157.952, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(329, 479.575, -1752.11, 14.0481, 225.705, 1021.86, 1084.02, 472.301, -1729.9, 10.8147, 267.261, 'Mama_Montana', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 61500, 1100, 225.671, 1023.69, 1084.01, 0),
(330, 903.914, -1815.57, 13.3018, 225.705, 1021.86, 1084.02, 915.857, -1825.47, 12.5099, 260.079, 'Cotne_Willam', 8000000, 7, 1, 1, 0, 4, 'Bio_Impulse', 'Giorgi_Russell', 0, 0, 0, 0, 0, 175200, 1100, 225.671, 1023.69, 1084.01, 1),
(331, -1171.63, -1637.93, 217.339, 234.138, 1063.9, 1084.21, -1083.77, -1636.88, 76.3672, 265.069, 'The State', 5000000, 6, 1, 0, 0, 3, 'Don_Lester', 'Philip_Morris', 0, 0, 0, 0, 0, 107600, 900, 234.258, 1066.21, 1084.21, 0),
(332, 961.333, -1824.01, 13.3275, 83.0589, 1322.55, 1083.87, 963.428, -1831.67, 12.5974, 233.04, 'Zaza_Costello', 3000000, 9, 1, 1, 0, 2, 'None', 'Jemal_Costello', 0, 150, 300, 270, 0, 69300, 700, 83.0539, 1324.44, 1083.86, 0),
(333, 973.694, -1827.07, 13.3327, 2270.05, -1210.46, 1047.56, 971.393, -1833.61, 12.6095, 226.339, 'Arthur_Marcano', 1000000, 10, 0, 1, 0, 1, 'Gio_Zhorzholiani', 'None', 0, 0, 0, 0, 0, 66500, 500, 2265.62, -1210.51, 1049.02, 0),
(334, 813.691, -1456.64, 14.2256, 2439.13, -95.9364, 1146.88, 800.205, -1462.89, 13.3828, 355.817, 'Saba_Khutso', 1000000, 6, 1, 1, 0, 1, 'None', 'None', 0, 0, 0, 0, 0, 62500, 500, 2265.62, -1210.51, 1049.02, 1),
(335, 596.474, -1249.89, 18.2936, 225.705, 1021.86, 1084.02, 591.08, -1242.62, 18.3002, 292.484, 'Gigla_Gigauri', 8000000, 7, 0, 1, 0, 4, 'None', 'Freddy_Ventas', 0, 0, 0, 0, 0, 119300, 1100, 225.671, 1023.69, 1084.01, 1),
(336, 1510.31, -1061.18, 25.0625, 225.705, 1021.86, 1084.02, 1517.32, -1044.39, 23.7914, 58.9846, 'Sadaga_Moralez', 8000000, 7, 0, 1, 0, 4, 'None', 'Nozeqs_Chukeqs', 0, 0, 0, 0, 0, 120300, 1100, 225.671, 1023.69, 1084.01, 1),
(337, 650.941, -1575.96, 15.4113, 225.705, 1021.86, 1084.02, 651.921, -1579.31, 15.3489, 265.47, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(338, 891.074, -783.206, 101.314, 225.705, 1021.86, 1084.02, 904.569, -775.744, 101.367, 21.7594, 'Jordan_Henderson', 8000000, 7, 0, 1, 0, 4, 'Hirochi_Blast', 'Atanase_Parulava', 0, 0, 0, 0, 0, 113700, 1100, 225.671, 1023.69, 1084.01, 1),
(339, 653.2, -1619.77, 15, 225.705, 1021.86, 1084.02, 641.71, -1621.16, 15.1725, 0.772782, 'Belta_Oldschool', 8000000, 7, 0, 1, 0, 4, 'Tony_Luther', 'None', 0, 51, 100, 50, 0, 108200, 1100, 225.671, 1023.69, 1084.01, 0),
(340, 243.717, -1374.83, 53.1094, -1036.53, -2205.94, 1501.09, 251.354, -1359.4, 53.1094, 303.8, 'Guga_Kalashnikov', 8000000, 10, 0, 1, 0, 4, 'Saba_Vasha', 'Lika_Shonia', 0, 0, 0, 0, 0, 128700, 1100, 225.671, 1023.69, 1084.01, 0),
(341, -2027.83, -40.6095, 38.8047, 83.0589, 1322.55, 1083.87, -2030.57, -53.128, 35.363, 228.435, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(342, 1111.51, -976.44, 42.7656, 225.705, 1021.86, 1084.02, 1109.92, -958.444, 42.511, 273.532, 'Marek_Tobson', 8000000, 7, 0, 1, 0, 4, 'James_Moriarty', 'Louis_Prada', 0, 0, 0, 0, 0, 161100, 1100, 225.671, 1023.69, 1084.01, 0),
(343, 690.72, -1275.88, 13.5601, 225.705, 1021.86, 1084.02, 662.918, -1274.58, 13.4609, 184.42, 'Sasha_Boyka', 8000000, 7, 1, 1, 0, 4, 'Ram_Vendetta', 'None', 0, 0, 0, 0, 0, 170500, 1100, 225.671, 1023.69, 1084.01, 0),
(344, 206.4, -111.773, 4.89647, -1036.62, -2205.85, 1501.09, 192.953, -107.001, 1.5493, 349.742, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Klaus_Luther', 0, 100, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(345, 835.922, -894.786, 68.7689, 2439.13, -95.9364, 1146.88, 837.384, -886.129, 68.6399, 231.82, 'Tedo_Axalaia', 3000000, 6, 0, 1, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 28900, 700, 83.0539, 1324.44, 1083.86, 1),
(346, 2206.56, 691.325, 11.4609, 225.705, 1021.86, 1084.02, 2212.88, 698.81, 11.2539, 356.321, 'Balthazar_Pajarnik', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 160300, 1100, 225.671, 1023.69, 1084.01, 0),
(347, -396.39, -425.081, 16.2594, 234.138, 1063.9, 1084.21, -391.657, -436.642, 16.2031, 74.1969, 'The State', 5000000, 6, 1, 0, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(348, 655.986, -1635.87, 15.8617, 225.705, 1021.86, 1084.02, 644.891, -1639.64, 15.1138, 123.334, 'Clar_Shelby', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 162300, 1100, 225.671, 1023.69, 1084.01, 0),
(349, -28.8918, 2356.83, 24.1406, 225.705, 1021.86, 1084.02, -22.9035, 2363.36, 24.1406, 266.157, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 161700, 1100, 225.671, 1023.69, 1084.01, 0),
(350, 1938.54, -1911.26, 15.2568, 2270.05, -1210.46, 1047.56, 1943.22, -1924.89, 13.5469, 102.663, 'Frank_Moralezz', 1000000, 10, 1, 1, 0, 1, 'None', 'None', 0, 0, 0, 0, 1, 55600, 500, 2265.62, -1210.51, 1049.02, 1),
(351, 1778.52, -1663.14, 14.4368, 225.705, 1021.86, 1084.02, 1752.5, -1664.41, 13.3826, 0.034264, 'Katsuki_Bakugo', 8000000, 7, 0, 1, 0, 4, 'None', 'Leonardo_Dikaprio', 0, 299, 0, 0, 0, 122500, 1100, 225.671, 1023.69, 1084.01, 0),
(352, 648.365, -1058.66, 52.5799, 83.0589, 1322.55, 1083.87, 656.908, -1067.47, 48.7075, 234.231, 'Avto_Chelidze', 3000000, 9, 1, 1, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 64400, 700, 83.0539, 1324.44, 1083.86, 1),
(353, 897.933, -677.099, 116.89, -1036.53, -2205.94, 1501.09, 911.822, -664.668, 116.964, 234.06, 'Guga_Sulaqvelidze', 8000000, 10, 1, 1, 0, 4, 'Anri_Adeishvili', 'None', 0, 0, 0, 0, 0, 36300, 1100, 225.671, 1023.69, 1084.01, 0),
(354, 432.328, -1253.85, 51.5809, 234.138, 1063.9, 1084.21, 418.222, -1254.1, 51.581, 21.1422, 'The State', 5000000, 6, 1, 0, 0, 3, 'Pablo_Escobaro', 'Gio_Jerard', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(355, 914.301, -1004.63, 37.9794, 225.705, 1021.86, 1084.02, 911.213, -989.965, 37.9469, 147.11, 'Zura_Wulaia', 8000000, 7, 0, 1, 0, 4, 'None', 'Brian_Lazarovsky', 62, 0, 0, 0, 0, 65200, 1100, 225.671, 1023.69, 1084.01, 1),
(356, 1280.86, -874.853, 46.8438, 225.705, 1021.86, 1084.02, 1282.2, -886.362, 42.8753, 101.821, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(357, 1431.03, 1131.24, 10.8203, 83.0589, 1322.55, 1083.87, 1428.56, 1118.99, 10.8203, 149.746, 'The State', 3000000, 9, 1, 0, 0, 2, 'Freddy_Miler', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(358, 497.475, -1095.07, 82.3592, 225.705, 1021.86, 1084.02, 480.338, -1089.36, 82.4535, 355.496, 'Sandro_Sadagashvili', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 94, 76, 0, 0, 0, 125000, 1100, 225.671, 1023.69, 1084.01, 0),
(359, 552.976, -1200.27, 44.8315, 225.705, 1021.86, 1084.02, 543.164, -1202.27, 44.5052, 14.5185, 'Chesto_Blackwood', 8000000, 7, 0, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 1, 139800, 1100, 225.671, 1023.69, 1084.01, 1),
(360, 1468.67, -906.185, 54.8359, 225.705, 1021.86, 1084.02, 1458.63, -907.349, 54.8359, 0.578445, 'Ray_Johnson', 8000000, 7, 0, 1, 0, 4, 'Bob_Westie', 'Soul_Corleone', 0, 0, 0, 0, 0, 18100, 1100, 225.671, 1023.69, 1084.01, 0),
(361, 2212.34, 2338.23, 10.8125, 225.705, 1021.86, 1084.02, 2202.37, 2333.82, 10.6719, 322.186, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 182600, 1100, 225.671, 1023.69, 1084.01, 0),
(362, 1103.39, -1068.32, 31.8899, 225.705, 1021.86, 1084.02, 1091.21, -1070.91, 28.192, 180.376, 'Lasha_Gadelia', 8000000, 7, 0, 1, 0, 4, 'Nikolas_Asa', 'None', 0, 0, 50, 0, 0, 77000, 1100, 225.671, 1023.69, 1084.01, 1),
(363, 1096.31, -1242.4, 19.584, 225.705, 1021.86, 1084.02, 1097.77, -1218.82, 17.8047, 357.43, 'The State', 8000000, 7, 1, 0, 0, 4, 'Nikusha_Gagnidze', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(364, 1319.06, 1249.39, 10.8203, 2270.05, -1210.46, 1047.56, 1315.88, 1278.39, 10.8203, 0.492974, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'Irakli_Pirtskhalava', 0, 0, 0, 0, 0, 0, 500, 2265.62, -1210.51, 1049.02, 0),
(365, 1096.45, -1242.41, 15.8203, 83.0589, 1322.55, 1083.87, 1106.1, -1215.97, 17.8047, 350.979, 'Abasho_Gelashvili', 3000000, 9, 1, 1, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 114100, 700, 83.0539, 1324.44, 1083.86, 0),
(366, 1303.93, 1606.52, 10.8203, 2270.05, -1210.46, 1047.56, 1314.91, 1603.87, 10.8203, 0.936908, 'The State', 1000000, 10, 1, 0, 0, 1, 'Saba_Fxakadze', 'None', 0, 0, 0, 0, 0, 0, 500, 2265.62, -1210.51, 1049.02, 0),
(367, 1303.93, 1614.77, 10.8203, 2270.05, -1210.46, 1047.56, 1315.26, 1611.66, 10.8203, 354.924, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'None', 300, 0, 0, 0, 1, 74500, 500, 2265.62, -1210.51, 1049.02, 0),
(368, 940.575, -1085.37, 24.2962, 1548.1, -7.4133, 1501.39, 925.809, -1103.48, 24.2983, 267.759, 'Son_Hells', 8000000, 5, 0, 1, 0, 4, 'Luka_Okreshidze', 'Nika_Lomtadze', 0, 0, 300, 0, 0, 176000, 1100, 225.671, 1023.69, 1084.01, 1),
(369, 167.763, -1758.98, 6.79688, 83.0589, 1322.55, 1083.87, 159.005, -1780.68, 4.21737, 0.490586, 'Iakob_Nachkebia', 3000000, 9, 0, 1, 0, 2, 'Aleksi_Murachashvili', 'Sabuka_Sanchez', 0, 0, 0, 0, 1, 78700, 700, 83.0539, 1324.44, 1083.86, 1),
(370, 2161.06, -99.1524, 2.75808, 83.0589, 1322.55, 1083.87, 2155.47, -106.699, 2.65755, 33.537, 'Mikasa_Ackerman', 3000000, 9, 0, 1, 0, 2, 'Max_Ximenez', 'None', 0, 0, 0, 0, 0, 100700, 700, 83.0539, 1324.44, 1083.86, 0),
(371, 254.587, -1366.98, 53.1094, 2439.13, -95.9364, 1146.88, 254.343, -1356.59, 53.1094, 297.952, 'Balu', 8000000, 6, 1, 1, 0, 4, 'Tonithe_First', 'Anano_Adams', 0, 0, 0, 0, 0, 178300, 1100, 225.671, 1023.69, 1084.01, 1),
(372, 1050.99, -1059.05, 34.7966, 225.705, 1021.86, 1084.02, 1048.47, -1043.84, 31.8757, 270.358, 'Narsik_Enkeyes', 8000000, 7, 1, 1, 0, 4, 'Luka_Kvaracxelia', 'None', 300, 300, 300, 300, 0, 136400, 1100, 225.671, 1023.69, 1084.01, 1),
(373, -31.968, -2487.75, 36.6484, 83.0589, 1322.55, 1083.87, -31.0176, -2493.54, 36.6484, 33.8271, 'The State', 3000000, 9, 1, 0, 0, 2, 'Jey_Winston', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(374, 2173.32, 1285.38, 24.4754, 225.705, 1021.86, 1084.02, 2204.59, 1279.77, 10.8203, 87.772, 'Lincoln_Berouz', 8000000, 7, 0, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 55900, 1100, 225.671, 1023.69, 1084.01, 1),
(375, -1009.53, 1839.07, 845.318, 2308.8, -1212.84, 1049.02, 1408.87, -1584.46, 13.5605, 242.321, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(376, 1965.05, 1623.22, 12.8621, 2270.05, -1210.46, 1047.56, 2013.72, 1622.83, 11.6016, 87.5676, 'The State', 1000000, 10, 1, 0, 0, 1, 'Jack_Costello', 'None', 100, 100, 0, 0, 0, 26400, 500, 2265.62, -1210.51, 1049.02, 0),
(377, 1676.27, -1635.19, 14.2266, 83.0589, 1322.55, 1083.87, 1678.1, -1614.42, 13.5469, 186.149, 'Sally_Costello', 3000000, 9, 1, 1, 0, 2, 'Thesea_Krull', 'Niniko_Shonia', 0, 0, 0, 0, 0, 110880, 700, 83.0539, 1324.44, 1083.86, 0),
(378, 2460.67, -1318.35, 24, 225.705, 1021.86, 1084.02, 2457.52, -1319.04, 24, 186.848, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Gabriel_Morgen', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(379, 2470.37, -1295.45, 30.2332, 225.705, 1021.86, 1084.02, 2457.18, -1289.51, 24, 180.389, 'The State', 8000000, 7, 1, 0, 0, 4, 'Levani_Robbertson', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(380, 211.712, -1238.89, 78.3489, -1036.53, -2205.94, 1501.09, 219.726, -1277.72, 63.092, 162.749, 'Mate_Abuladze', 8000000, 10, 1, 1, 0, 4, 'Elene_Girisashvili', 'None', 0, 300, 0, 300, 1, 171700, 1100, 225.671, 1023.69, 1084.01, 1),
(381, 2597.66, 1900.36, 11.0312, 225.705, 1021.86, 1084.02, 2602.19, 1854.02, 10.8203, 94.5885, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 53809, 1100, 225.671, 1023.69, 1084.01, 0),
(382, -1942.14, 2379.46, 49.7031, 2308.8, -1212.84, 1049.02, -1938.39, 2386.47, 49.4922, 293.965, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(383, 1188.46, -1011.54, 32.5469, 83.0589, 1322.55, 1083.87, 1193.43, -1028.33, 32.181, 181.509, 'Daci_Khutso', 3000000, 9, 0, 1, 0, 2, 'Deadly_Montana', 'Luka_Broladze', 0, 0, 0, 0, 0, 113700, 700, 83.0539, 1324.44, 1083.86, 0),
(384, -2173.32, 84.2588, 35.3203, 225.705, 1021.86, 1084.02, 1290.8, -1596.22, 13.5469, 314.57, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(385, -1003.45, 1901.12, 418.265, 83.0589, 1322.55, 1083.87, -313.144, 1533.45, 75.3594, 165.117, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(386, -1032.81, 1914.36, 441.482, 2308.8, -1212.84, 1049.02, 1482.02, 2790.81, 10.8203, 273.506, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(387, -1425.82, -1529.59, 102.302, 225.705, 1021.86, 1084.02, -23.5852, -2492.05, 36.6484, 120.336, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(388, -1005.44, 1903.16, 420.872, 2308.8, -1212.84, 1049.02, 263.66, -1218.09, 75.1407, 157.762, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(389, 1048.67, 2910.17, 47.8231, 234.138, 1063.9, 1084.21, 1046.58, 2898.07, 45.759, 177.382, 'The State', 5000000, 6, 1, 0, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 109500, 900, 234.258, 1066.21, 1084.21, 0),
(390, 298.677, -1338, 53.4416, 225.705, 1021.86, 1084.02, 290.493, -1331.43, 53.441, 34.055, 'Vato_Gorgiladze', 8000000, 7, 1, 1, 0, 4, 'Nick_Costelo', 'Temo_Cagareishvili', 0, 0, 0, 0, 0, 129400, 1100, 225.671, 1023.69, 1084.01, 1),
(391, -2269.28, -5.4243, 35.3203, 225.705, 1021.86, 1084.02, 1844.08, -1282.41, 13.3882, 269.981, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(392, -1465.68, 2611.99, 56.1797, 2308.8, -1212.84, 1049.02, -1467.25, 2606.04, 55.6875, 269.99, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(393, 1068.42, -1081.32, 27.5482, 1972.52, -1553.17, 2451.34, 1076.64, -1085.01, 26.4778, 186.422, 'Jack_Willson', 8000000, 12, 0, 1, 0, 4, 'John_Sinsin', 'Luka_Gotti', 0, 0, 0, 0, 1, 126400, 1100, 225.671, 1023.69, 1084.01, 1),
(394, 207.654, -1847.66, 4.4863, 225.705, 1021.86, 1084.02, 213.762, -1861.01, 3.06023, 251.802, 'Carco_Shinki', 8000000, 7, 0, 1, 0, 4, 'Tengiz_Malaymadze', 'Bio_Diaz', 0, 0, 0, 0, 0, 143600, 1100, 225.671, 1023.69, 1084.01, 0),
(395, -369.669, 1169.65, 20.2719, 2270.05, -1210.46, 1047.56, -360.937, 1197.97, 19.7422, 177.241, 'The State', 1000000, 10, 1, 0, 0, 1, 'Saba_Cqviti', 'None', 0, 0, 0, 0, 0, 0, 500, 2265.62, -1210.51, 1049.02, 0),
(396, 1913.44, -1911.9, 15.2568, 225.705, 1021.86, 1084.02, 1909.51, -1924.14, 13.5469, 103.065, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 200, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(397, 1456.97, -1137.19, 23.9442, 225.705, 1021.86, 1084.02, 1452.65, -1153.53, 23.8962, 152.594, 'Luka_Darsalia', 8000000, 7, 0, 1, 0, 4, 'None', 'Levani_Zhorzholiani', 0, 300, 300, 300, 0, 15400, 1100, 225.671, 1023.69, 1084.01, 0),
(398, 1524.28, -1114.53, 20.8636, 225.705, 1021.86, 1084.02, 1524.1, -1111.99, 20.8594, 92.2448, 'Beqa_Stefliani', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 300, 300, 300, 1, 106229, 1100, 225.671, 1023.69, 1084.01, 0),
(399, 1441.5, -1863.14, 13.5391, 225.705, 1021.86, 1084.02, 1435.09, -1868.6, 13.3828, 82.2588, 'Meko_Abruzzi', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 82500, 1100, 225.671, 1023.69, 1084.01, 1),
(400, -1023.32, 1912.84, 444.723, 2308.8, -1212.84, 1049.02, 1424.86, -1562.08, 13.5469, 359.047, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(401, -1009.47, 1839.2, 838.331, 2308.8, -1212.84, 1049.02, 1415.68, -1648.68, 13.3754, 267.789, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(402, 1419.45, -1623.67, 13.5469, 225.705, 1021.86, 1084.02, 1437.06, -1626.08, 13.45, 176.444, 'Luka_Girisashvili', 8000000, 7, 1, 1, 0, 4, 'None', 'Jemala_Tyabladze', 0, 0, 0, 0, 0, 35300, 1100, 225.671, 1023.69, 1084.01, 0),
(403, -1008.49, 1841.34, 820.081, 2308.8, -1212.84, 1049.02, 1397.49, -1596.79, 13.8063, 74.2584, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(404, 501.853, -1059.14, 1770.89, 2308.8, -1212.84, 1049.02, 684.14, -1071.26, 49.6416, 84.6426, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(405, 1903.59, -916.737, 893.981, 2308.8, -1212.84, 1049.02, 1451.33, -923.82, 37.6094, 353.908, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(406, 152.729, -1946.41, 544.836, 2308.8, -1212.84, 1049.02, 152.041, -1933.75, 3.76964, 344.799, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(407, -998.99, 1861.91, 715.323, 2308.8, -1212.84, 1049.02, 1531.89, -1842.83, 13.5469, 359.143, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(408, 1838.09, 718.889, -122.668, 2308.8, -1212.84, 1049.02, 1490.3, -1842.31, 13.5469, 89.4341, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(409, 1464.77, -1051.62, 24.0156, 225.705, 1021.86, 1084.02, 1469.59, -1051.73, 23.8277, 261.701, 'Komla_Moralez', 8000000, 7, 1, 1, 0, 4, 'Cosy_Moralez', 'None', 0, 0, 100, 0, 1, 135500, 1100, 225.671, 1023.69, 1084.01, 1),
(410, -968.755, 1908.11, 515.006, 2308.8, -1212.84, 1049.02, 1472.58, -1833.54, 13.5469, 181.867, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(411, 878.49, -725.765, 106.447, 225.705, 1021.86, 1084.02, 872.942, -749.632, 94.9834, 251.909, 'Diego_Rose', 8000000, 7, 0, 1, 0, 4, 'None', 'Mama_Konia', 0, 0, 0, 0, 0, 169200, 1100, 225.671, 1023.69, 1084.01, 1),
(412, -1002.44, 1854.45, 747.403, 2308.8, -1212.84, 1049.02, 1511.96, -1847.06, 13.5469, 345.369, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(413, 155.652, -1946.58, 568.102, 2308.8, -1212.84, 1049.02, 156.706, -1934.26, 3.77344, 16.4319, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(414, -1008.51, 1889.74, 601.904, 83.0589, 1322.55, 1083.87, 1447.07, -1842.94, 13.5469, 355.694, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(415, 2284.75, -1906.6, 14.9297, 225.705, 1021.86, 1084.02, 2272.92, -1911.14, 13.5469, 358.773, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(416, 287.198, -2112.86, 431.001, 2308.8, -1212.84, 1049.02, 149.401, -1939.91, 3.77344, 331.566, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(417, 1046.49, -1131.43, 712.826, 2308.8, -1212.84, 1049.02, 1042.43, -1138.13, 23.664, 268.487, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(418, 981.829, -1162.44, 25.0859, 234.138, 1063.9, 1084.21, 983.863, -1148.03, 23.9793, 273.902, 'Mose_Blackwood', 5000000, 6, 0, 1, 0, 3, 'None', 'Xurci_Falconry', 0, 0, 0, 0, 0, 102300, 900, 234.258, 1066.21, 1084.21, 0),
(419, 979.68, -1233.48, 16.9844, 225.705, 1021.86, 1084.02, 968.964, -1228.39, 16.9536, 88.4935, 'Nikusha_Rizhamadze', 8000000, 7, 1, 1, 0, 4, 'None', 'Donnie_Anderson', 0, 0, 0, 0, 0, 49700, 1100, 225.671, 1023.69, 1084.01, 0),
(420, 1536.74, -2431.15, 841.41, 2308.8, -1212.84, 1049.02, 0, 0, 0, 0, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(421, 541.237, -1817.85, 1062.16, 2308.8, -1212.84, 1049.02, 0, 0, 0, 0, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(422, 455.191, -1796.11, 811.178, 2308.8, -1212.84, 1049.02, 0, 0, 0, 0, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(423, 958.259, -1556.59, 13.5802, 225.705, 1021.86, 1084.02, 956.587, -1564.75, 13.5734, 120.789, 'Luka_Pirtskhelava', 8000000, 7, 1, 1, 0, 4, 'Cigo_Pikanto', 'None', 0, 0, 0, 0, 0, 159500, 1100, 225.671, 1023.69, 1084.01, 0),
(424, -1642.7, 1384.81, 7.17219, 225.705, 1021.86, 1084.02, 386.676, -1859.98, 7.83594, 92.1308, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 1, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(425, -1635.32, 1392.2, 7.17219, 225.705, 1021.86, 1084.02, 2724.68, -1498.64, 30.2812, 194.544, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Gia_Mefe', 0, 0, 0, 0, 0, 92300, 1100, 225.671, 1023.69, 1084.01, 0),
(426, -2278.83, 767.78, 49.4453, 225.705, 1021.86, 1084.02, 370.17, -1893.57, 7.67188, 5.62657, 'The State', 8000000, 7, 1, 0, 0, 4, 'David_Beckham', 'None', 0, 300, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(427, 142.655, -1470.39, 25.2109, 234.138, 1063.9, 1084.21, 150.131, -1467.24, 25.375, 52.7701, 'Dantes_Tagawa', 5000000, 6, 1, 1, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 145500, 900, 234.258, 1066.21, 1084.21, 1),
(428, 2481.77, -1344.98, 27.6595, 225.705, 1021.86, 1084.02, 2469.23, -1350.89, 25.9869, 90.7088, 'The State', 8000000, 7, 1, 0, 0, 4, 'Iveri_Osiashvili', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(429, 1505.8, -2407.12, 458.816, 2308.8, -1212.84, 1049.02, 0, 0, 0, 0, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(430, 711.306, -1080.29, 49.4219, 225.705, 1021.86, 1084.02, 683.39, -1052.79, 49.8942, 134.529, 'Chadu_Padishaxi', 8000000, 7, 0, 1, 0, 4, 'None', 'Ganaby_Galsky', 0, 0, 0, 0, 0, 175600, 1100, 225.671, 1023.69, 1084.01, 0),
(431, 672.976, -1019.76, 55.7596, 225.705, 1021.86, 1084.02, 690.091, -1029.05, 51.1857, 314.873, 'The State', 8000000, 7, 1, 0, 0, 4, 'Eazy_Rider', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(432, 379.931, -913.448, 330.387, 2308.8, -1212.84, 1049.02, 684.874, -1071.68, 49.6102, 67.4576, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(433, 92.7248, -2009.38, 404.862, 2308.8, -1212.84, 1049.02, 155.237, -1924.34, 3.77344, 13.2376, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(434, 3744.08, -673.001, 100.989, 2308.8, -1212.84, 1049.02, 1620.58, -1892.19, 13.549, 355.029, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(435, 3751.23, -667.824, 100.989, 2308.8, -1212.84, 1049.02, 1614.19, -1887.84, 13.5469, 3.2707, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(436, -1008.54, 1906.35, 423.871, 2270.05, -1210.46, 1047.56, 251.95, -1258.86, 70.5983, 299.033, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'None', 0, 0, 0, 0, 0, 0, 500, 2265.62, -1210.51, 1049.02, 0),
(437, -1023.77, 1918.14, 426.898, 2308.8, -1212.84, 1049.02, -317.879, 1515.72, 75.357, 0.055952, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(438, 1317.27, -1184.07, 23.5929, 225.705, 1021.86, 1084.02, 1327.35, -1175.33, 23.6112, 356.636, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Nika_Chelidze', 0, 200, 0, 0, 1, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(439, -2664.39, -3.05299, 6.13281, 225.705, 1021.86, 1084.02, -2679.8, -23.9917, 4.33594, 357.78, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 136311, 1100, 225.671, 1023.69, 1084.01, 0),
(440, 2795.54, -1619.47, 10.9219, 225.705, 1021.86, 1084.02, 2791.21, -1617.72, 10.9219, 2.73817, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(441, 189.639, -1308.47, 70.2491, 225.705, 1021.86, 1084.02, 169.799, -1346.56, 69.4397, 180.705, 'Nika_Robakidze', 8000000, 7, 1, 1, 0, 4, 'Jacob_Imprezza', 'Luka_Beinars', 0, 0, 0, 0, 0, 113900, 1100, 225.671, 1023.69, 1084.01, 1),
(442, -314.406, 1774.56, 43.6406, 225.705, 1021.86, 1084.02, -339.235, 1785.51, 42.744, 347.422, 'The State', 8000000, 7, 1, 0, 0, 4, 'Wolfse_Bolozari', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(443, 1332.17, -633.322, 109.135, -1036.62, -2205.85, 1501.09, 1353.3, -618.486, 109.133, 45.7571, 'Avto_Gagoshidze', 80000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 171500, 1100, -1036.37, -2202.96, 1501.09, 0),
(444, 901.944, -1514.8, 14.3691, 2270.05, -1210.46, 1047.56, 893.839, -1518.71, 13.8671, 178.855, 'Hioku_Akatsuki', 1000000, 10, 1, 1, 0, 1, 'None', 'None', 0, 0, 0, 0, 0, 59000, 500, 2265.62, -1210.51, 1049.02, 1),
(445, -1029.92, 1918.68, 435.966, 2270.05, -1210.46, 1047.56, 1401.01, -1038.98, 24.5234, 93.9869, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'None', 0, 0, 0, 0, 0, 0, 500, 2265.62, -1210.51, 1049.02, 0),
(446, 1635.02, -2212.64, 2055.61, 2270.05, -1210.46, 1047.56, 1632.01, -2232.86, 2055.61, 68.7717, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'None', 0, 0, 0, 0, 0, 0, 500, 2265.62, -1210.51, 1049.02, 0),
(447, 1123.06, 367.83, -283.54, 83.0589, 1322.55, 1083.87, 0, 0, 0, 0, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(448, 1234.93, 360.207, 19.5547, 2270.05, -1210.46, 1047.56, 1225.1, 364.989, 19.5547, 157.109, 'The State', 1000000, 10, 1, 0, 0, 1, 'Stubbly_Tear', 'Sfinx_Morald', 0, 0, 0, 0, 0, 0, 500, 2265.62, -1210.51, 1049.02, 0),
(449, 1123.06, 367.83, -283.54, 2308.8, -1212.84, 1049.02, 0, 0, 0, 0, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(450, 1123.06, 367.83, -283.54, 2270.05, -1210.46, 1047.56, 0, 0, 0, 0, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'None', 0, 0, 0, 0, 0, 0, 500, 2265.62, -1210.51, 1049.02, 0),
(451, 551.089, -2061.22, 6.7702, 1298.95, -796.798, 1084.01, 562.885, -2014.91, 1.99018, 350.586, 'Giorgi_Gurgenishvili', 8000000, 5, 1, 1, 0, 4, 'Anna_Futkaradze', 'None', 0, 0, 0, 0, 0, 127416, 1100, 1299.1, -793.802, 1084.01, 1),
(452, 265.763, -1287.75, 74.6325, 234.138, 1063.9, 1084.21, 276.282, -1266.99, 73.9453, 305.94, 'Roman_Bellic', 5000000, 6, 1, 1, 0, 3, 'Dima_Mosidze', 'None', 0, 0, 0, 0, 0, 33300, 900, 234.258, 1066.21, 1084.21, 0),
(453, 534.813, -1173.67, 58.8097, 234.138, 1063.9, 1084.21, 551.26, -1159.31, 54.1446, 331.415, 'Aleko_Montan', 5000000, 6, 0, 1, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 18200, 900, 234.258, 1066.21, 1084.21, 1),
(454, 1127.83, -1021.56, 34.9922, 225.705, 1021.86, 1084.02, 1138.91, -1030.32, 33.0956, 186.569, 'Xamshikka_Pajarnik', 8000000, 7, 1, 1, 0, 4, 'Nizam_Padishah', 'None', 0, 0, 0, 0, 0, 146300, 1100, 225.671, 1023.69, 1084.01, 1),
(455, -1463.26, 2629.07, 55.8359, 225.705, 1021.86, 1084.02, -2110.63, 2683.32, 159.793, 278.119, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(456, 4035.26, -763.749, 62.3084, 2270.05, -1210.46, 1047.56, 1576.93, -1879.1, 13.5469, 79.8694, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'None', 0, 0, 0, 0, 0, 0, 500, 2265.62, -1210.51, 1049.02, 0),
(457, 4038.66, -766.212, 62.3084, 2270.05, -1210.46, 1047.56, 1584.19, -1878.14, 13.5391, 12.224, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'None', 0, 0, 0, 0, 0, 0, 500, 2265.62, -1210.51, 1049.02, 0),
(458, 1519.78, -1453.35, 14.2071, 225.705, 1021.86, 1084.02, 1522.71, -1443.51, 13.3828, 92.6951, 'Oliver_Montanaa', 8000000, 7, 1, 1, 0, 4, 'Vako_Siradzee', 'None', 0, 0, 0, 0, 0, 61509, 1100, 225.671, 1023.69, 1084.01, 0),
(459, 3791.75, -638.473, 100.989, 2270.05, -1210.46, 1047.56, 1591.21, -1877.83, 13.5391, 344.43, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'None', 0, 0, 0, 0, 0, 0, 500, 2265.62, -1210.51, 1049.02, 0),
(460, 1571.07, -1898.01, 13.5609, 225.705, 1021.86, 1084.02, 1567.79, -1886.26, 13.558, 0.354429, 'Nikson_Hellsize', 8000000, 7, 0, 1, 0, 4, 'Luciano_Bamboo', 'None', 0, 100, 0, 0, 0, 184800, 1100, 225.671, 1023.69, 1084.01, 0),
(461, 271.59, -48.9529, 2.77721, 83.0589, 1322.55, 1083.87, 278.518, -58.2552, 1.57812, 173.732, 'The State', 3000000, 9, 1, 0, 0, 2, 'Gurami_Gabitashvili', 'Nika_Odishelidze', 0, 0, 0, 0, 0, 700, 700, 83.0539, 1324.44, 1083.86, 0),
(462, 1118.13, -1021.62, 34.9922, 225.705, 1021.86, 1084.02, 1108.28, -1024.94, 31.8867, 170.633, 'John_Ramos', 8000000, 7, 1, 1, 0, 4, 'Andria_Shoshiashvili', 'None', 0, 69, 143, 0, 0, 119900, 1100, 225.671, 1023.69, 1084.01, 0);
INSERT INTO `house` (`hID`, `hEntrancex`, `hEntrancey`, `hEntrancez`, `hExitx`, `hExity`, `hExitz`, `hCarx`, `hCary`, `hCarz`, `hCarc`, `hOwner`, `hValue`, `hInt`, `hLock`, `hOwned`, `hDate`, `hKlass`, `hM1`, `hM2`, `hNarko`, `hDgl`, `hEm`, `hShot`, `hGarageStatus`, `hBalance`, `hTax`, `hShesvlax`, `hShesvlay`, `hShesvlaz`, `hBtcStatus`) VALUES
(463, 817.317, -495.731, 18.0129, 234.138, 1063.9, 1084.21, 827.665, -497.474, 17.3281, 177.776, 'The State', 5000000, 6, 1, 0, 0, 3, 'Opie_Winston', 'None', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(464, 986.161, -1232.81, 16.9433, 225.705, 1021.86, 1084.02, 988.853, -1224.95, 16.7792, 271.617, 'Mate_Labo', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 18700, 1100, 225.671, 1023.69, 1084.01, 0),
(465, 1359.85, -1853.89, 13.5703, 225.705, 1021.86, 1084.02, 1372.92, -1891.7, 13.4957, 357.48, 'Jimy_Moriarty', 8000000, 7, 1, 1, 0, 4, 'Shako_Pridonashvili', 'Nini_Gvariadze', 0, 300, 0, 0, 0, 83900, 1100, 225.671, 1023.69, 1084.01, 0),
(466, -3065.27, 3828.9, 205.326, 2308.8, -1212.84, 1049.02, 1306.01, -813.883, 77.7119, 214.955, 'The State', 200000, 6, 1, 0, 0, 0, 'None', 'None', 0, 0, 0, 0, 0, 0, 300, 2308.59, -1210.86, 1049.02, 0),
(467, 1272.37, -1116.35, 24.5731, 225.705, 1021.86, 1084.02, 1270.65, -1132.72, 23.8281, 186.552, 'Luka_Dumbadze', 8000000, 7, 0, 1, 0, 4, 'Mastry_Leafs', 'None', 0, 0, 0, 0, 0, 41800, 1100, 225.671, 1023.69, 1084.01, 0),
(468, 661.363, -573.528, 16.3359, 225.705, 1021.86, 1084.02, 665.41, -583.542, 16.3359, 94.1612, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Nikolas_Vagner', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(469, 614.414, -518.545, 16.3533, 225.705, 1021.86, 1084.02, 619.706, -524.208, 16.3359, 270.048, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 30800, 1100, 225.671, 1023.69, 1084.01, 0),
(470, 691.363, -640.523, 16.3221, 225.705, 1021.86, 1084.02, 687.61, -641.983, 16.2767, 70.3231, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Oliver_Queen', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(471, 929.368, -1420.4, 13.5469, 225.705, 1021.86, 1084.02, 919.326, -1421.45, 13.2391, 221.757, 'James_Blackman', 8000000, 7, 1, 1, 0, 4, 'Tray_Teraffly', 'None', 0, 0, 0, 0, 0, 89100, 1100, 225.671, 1023.69, 1084.01, 0),
(472, 867.67, -716.911, 105.68, 225.705, 1021.86, 1084.02, 865.471, -711.685, 105.68, 327.496, 'Gergian_Tete', 8000000, 7, 0, 1, 0, 4, 'Giorgi_Giorgishvili', 'None', 0, 0, 0, 0, 0, 124000, 1100, 225.671, 1023.69, 1084.01, 1),
(473, 580.199, -1149.53, 53.1801, 225.705, 1021.86, 1084.02, 571.766, -1139.73, 50.5833, 269.163, 'Max_Harris', 8000000, 7, 0, 1, 0, 4, 'None', 'None', 0, 0, 300, 0, 0, 145200, 1100, 225.671, 1023.69, 1084.01, 0),
(474, 154.143, -1946.62, 5.38978, 225.705, 1021.86, 1084.02, 152.678, -1936.55, 3.77344, 0, 'Parkera_Rydaz', 8000000, 7, 1, 1, 0, 4, 'None', 'Keysar_Chiabrishvili', 0, 0, 0, 0, 0, 133700, 1100, 225.671, 1023.69, 1084.01, 0),
(475, 1333.68, -1329.38, 13.5391, 225.705, 1021.86, 1084.02, 1337.55, -1330.96, 13.5391, 187.916, 'Nika_Xarxeli', 8000000, 7, 1, 1, 0, 4, 'None', 'Nikusha_Rockstar', 0, 0, 0, 0, 0, 133100, 1100, 225.671, 1023.69, 1084.01, 1),
(477, 1333.2, -1308.34, 13.5469, 1972.52, -1553.17, 2451.34, 1340.64, -1306.48, 13.4901, 178.281, 'Edmond_Brown', 8000000, 12, 0, 1, 0, 4, 'Frexx_Xkresli', 'Elene_Gogiberidze', 0, 0, 0, 0, 0, 122299, 1100, 225.671, 1023.69, 1084.01, 1),
(478, 1333.79, -1349.03, 13.5469, 225.705, 1021.86, 1084.02, 1339.88, -1355.73, 13.3828, 182.082, 'Mate_Samarganishvili', 8000000, 7, 1, 1, 0, 4, 'Danny_Forest', 'James_Brown', 0, 0, 0, 0, 1, 110000, 1100, 225.671, 1023.69, 1084.01, 1),
(479, 1739.53, -1582.77, 14.1577, 225.705, 1021.86, 1084.02, 1738.69, -1590.88, 13.5462, 78.1853, 'The State', 8000000, 7, 1, 0, 0, 4, 'Taso_Queen', 'Don_Kingston', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(480, 1546.39, -1269.41, 17.4062, 225.705, 1021.86, 1084.02, 1533.62, -1286.97, 15.5213, 129.296, 'Giorgi_Akobidze', 8000000, 7, 0, 1, 0, 4, 'Taso_Queen', 'Don_Kingston', 0, 0, 0, 0, 1, 154500, 1100, 225.671, 1023.69, 1084.01, 1),
(481, 2561.51, 1561.99, 10.8203, 225.705, 1021.86, 1084.02, 2561.99, 1551.7, 10.8203, 92.6043, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(482, -2871.98, 2719.89, 276.198, 225.705, 1021.86, 1084.02, -2872.41, 2716.21, 275.639, 177.231, 'Temuri_Montana', 8000000, 7, 1, 1, 0, 4, 'Seso_Edwards', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(483, 228.291, -1405.17, 51.6094, 2439.13, -95.9364, 1146.88, 235.775, -1405.05, 51.5826, 47.0841, 'Temuri_Montana', 8000000, 6, 1, 1, 0, 4, 'Brucie_Kibbutz', 'None', 0, 0, 0, 0, 0, 62210, 1100, 225.671, 1023.69, 1084.01, 0),
(484, 2469.18, -1278.26, 30.3664, 225.705, 1021.86, 1084.02, 2456.97, -1281.59, 24, 181.744, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(485, 0.446965, 0.060136, 3.11719, 2270.05, -1210.46, 1047.56, -3.03225, -3.76711, 3.11719, 257.431, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'Toko_Rostobaia', 0, 0, 0, 0, 0, 500, 500, 2265.62, -1210.51, 1049.02, 0),
(486, 1285.26, -1067.33, 31.6789, 225.705, 1021.86, 1084.02, 1280.48, -1059.36, 29.5159, 89.0702, 'Jhonny_Montana', 8000000, 7, 1, 1, 0, 4, 'Wiko_Hobbs', 'Dima_Kevlishvili', 0, 0, 0, 0, 0, 41700, 1100, 225.671, 1023.69, 1084.01, 0),
(487, -1675.33, 1376.95, 7.17969, 83.0589, 1322.55, 1083.87, -1523.09, 478.635, 7.1875, 278.17, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'Gigi_Andersoni', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(488, 648.687, -1489.23, 14.8343, 83.0589, 1322.55, 1083.87, 643.291, -1490.31, 14.7818, 6.01187, 'Leqso_Darchia', 3000000, 9, 1, 1, 0, 2, 'Mark_Frost', 'None', 0, 0, 0, 0, 0, 19200, 700, 83.0539, 1324.44, 1083.86, 0),
(489, 662.432, -1467.07, 14.8516, 234.138, 1063.9, 1084.21, 669.139, -1471.36, 14.8516, 55.8744, 'Saba_Brown', 5000000, 6, 1, 1, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 58500, 900, 234.258, 1066.21, 1084.21, 0),
(490, 1196.46, -1016.8, 32.5469, 225.705, 1021.86, 1084.02, 1189.94, -1031.53, 31.9297, 298.888, 'Giorgi_Khozre', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 100, 100, 250, 0, 64900, 1100, 225.671, 1023.69, 1084.01, 0),
(491, 1196.49, -1017.02, 36.2344, 234.138, 1063.9, 1084.21, 1196.68, -1027.85, 32.2103, 186.427, 'Samuel_Grigorovi', 5000000, 6, 1, 1, 0, 3, 'Steve_Stifler', 'Dante_Montana', 0, 0, 0, 0, 0, 123300, 900, 234.258, 1066.21, 1084.21, 0),
(492, 1188.19, -1011.86, 36.2267, 225.705, 1021.86, 1084.02, 1187.33, -1031.57, 31.9418, 174.502, 'The State', 8000000, 7, 1, 0, 0, 4, 'Manki_Banana', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(493, 2434.81, -1289.34, 25.3479, 225.705, 1021.86, 1084.02, 2448.38, -1287.31, 23.8268, 359.364, 'The State', 8000000, 7, 1, 0, 0, 4, 'Lasha_Kituashvili', 'None', 0, 0, 0, 0, 0, 0, 1100, 225.671, 1023.69, 1084.01, 0),
(494, 2433.6, -1275.05, 24.7567, 2270.05, -1210.46, 1047.56, 2444.84, -1276.52, 24, 359.601, 'Jim_Walker', 1000000, 10, 1, 1, 0, 1, 'Oliver_Walker', 'Pash_Harrison', 0, 0, 0, 0, 0, 67000, 500, 2265.62, -1210.51, 1049.02, 0),
(495, 2481.78, -1340.81, 34.8516, 83.0589, 1322.55, 1083.87, 2496.32, -1310.33, 34.8628, 268.277, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'Guga_Power', 198, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0),
(496, 1738.73, 1233.67, 10.8203, 2270.05, -1210.46, 1047.56, 1746.09, 1234.84, 10.6719, 190.825, 'The State', 1000000, 10, 1, 0, 0, 1, 'None', 'Guga_Lannister', 0, 0, 0, 0, 0, 500, 500, 2265.62, -1210.51, 1049.02, 0),
(497, -90.8653, 1229.74, 19.7422, 225.705, 1021.86, 1084.02, -93.0198, 1218.74, 19.7352, 182.287, 'Luka_Gringo', 8000000, 7, 1, 1, 0, 4, 'None', 'None', 0, 0, 0, 0, 0, 1100, 1100, 225.671, 1023.69, 1084.01, 0),
(498, 1732.99, -1582.45, 14.1579, 225.705, 1021.86, 1084.02, 1729.04, -1587.03, 13.5471, 117.9, 'The State', 8000000, 7, 1, 0, 0, 4, 'None', 'Max_Kapono', 0, 250, 300, 295, 0, 150000, 1100, 225.671, 1023.69, 1084.01, 0),
(499, -1706.56, 1353.06, 7.17969, 234.138, 1063.9, 1084.21, -1711.35, 1344.95, 7.17949, 128.922, 'The State', 5000000, 6, 1, 0, 0, 3, 'None', 'None', 0, 0, 0, 0, 0, 0, 900, 234.258, 1066.21, 1084.21, 0),
(500, -1681.34, 1349.87, 7.17219, 83.0589, 1322.55, 1083.87, -1686.79, 1335.43, 7.17969, 48.1367, 'The State', 3000000, 9, 1, 0, 0, 2, 'None', 'None', 0, 0, 0, 0, 0, 0, 700, 83.0539, 1324.44, 1083.86, 0);

-- --------------------------------------------------------

--
-- Table structure for table `ipaddress`
--

CREATE TABLE `ipaddress` (
  `IPAddress` varchar(127) CHARACTER SET cp1251 COLLATE cp1251_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `kazino`
--

CREATE TABLE `kazino` (
  `kID` int(11) NOT NULL,
  `Name` varchar(64) NOT NULL,
  `Mafia` int(11) NOT NULL,
  `Manager` varchar(32) NOT NULL,
  `Manager2` varchar(32) NOT NULL,
  `Manager3` varchar(32) NOT NULL,
  `Manager4` varchar(32) NOT NULL,
  `Manager5` varchar(32) NOT NULL,
  `Krupie` varchar(32) NOT NULL,
  `Krupie2` varchar(32) NOT NULL,
  `Krupie3` varchar(32) NOT NULL,
  `Krupie4` varchar(32) NOT NULL,
  `Krupie5` varchar(32) NOT NULL,
  `Krupie6` varchar(32) NOT NULL,
  `Krupie7` varchar(32) NOT NULL,
  `Krupie8` varchar(32) NOT NULL,
  `Krupie9` varchar(32) NOT NULL,
  `Krupie10` varchar(32) NOT NULL,
  `Manager6` int(11) NOT NULL,
  `Manager7` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `kazino`
--

INSERT INTO `kazino` (`kID`, `Name`, `Mafia`, `Manager`, `Manager2`, `Manager3`, `Manager4`, `Manager5`, `Krupie`, `Krupie2`, `Krupie3`, `Krupie4`, `Krupie5`, `Krupie6`, `Krupie7`, `Krupie8`, `Krupie9`, `Krupie10`, `Manager6`, `Manager7`) VALUES
(1, 'Casino Adjara', 0, 'Tony_Morningstar', 'Deadly_Montana', 'Sam_Marlovsky', 'Martin_Luther', 'Guga_Power', 'Fred_Green', 'Ketrin_Devon', 'Rezi_Gurchiani', 'Frank_Costello', 'Irakli_Khasaia', 'Giorgi_Iremashvili', 'Giorgi_Iremashvili', 'Giorgi_Iremashvili', 'Giorgi_Iremashvili', 'Giorgi_Iremashvili', 0, 0),
(2, 'Caligula', 0, 'Iliko_Revishvili', 'Iliko_Revishvili', 'Iliko_Revishvili', '', '', 'Logan_Paul', 'Zviadi_Gurgenidze', 'Gogsik_Kingston', 'Gogsik_Kingston', 'Gogsik_Kingston', '', '', '', '', '', 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `news`
--

CREATE TABLE `news` (
  `id` int(11) NOT NULL,
  `Title` char(50) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `Url` text NOT NULL,
  `Vk` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `news`
--

INSERT INTO `news` (`id`, `Title`, `Url`, `Vk`) VALUES
(9, 'áƒ¯áƒ’áƒ£áƒ¤áƒ¡ áƒ“áƒáƒ•áƒ£áƒ‘áƒ áƒ£áƒœáƒ“áƒ˜áƒ—', 'https://img.ge/images/23801024287528375772.jpg', 'https://www.facebook.com/GenuineRP/posts/325918872627674'),
(10, 'Non Official', 'https://img.ge/images/66002977839745712036.jpg', 'https://www.facebook.com/GenuineRP/posts/325201416032753'),
(11, 'GRP Launcher V3 Soon', 'https://img.ge/images/34270165131093419660.jpg', '');

-- --------------------------------------------------------

--
-- Table structure for table `penalty`
--

CREATE TABLE `penalty` (
  `ID` int(11) NOT NULL,
  `CarPosX` float NOT NULL,
  `CarPosY` float NOT NULL,
  `CarPoZ` float NOT NULL,
  `CarPosC` float NOT NULL,
  `CarOwner` varchar(32) NOT NULL,
  `CarBringer` varchar(32) NOT NULL,
  `CarID` int(11) NOT NULL,
  `CarPenalty` int(11) NOT NULL,
  `CarStatus` int(11) NOT NULL,
  `CarSlot` int(11) NOT NULL,
  `CarTime` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Dumping data for table `penalty`
--

INSERT INTO `penalty` (`ID`, `CarPosX`, `CarPosY`, `CarPoZ`, `CarPosC`, `CarOwner`, `CarBringer`, `CarID`, `CarPenalty`, `CarStatus`, `CarSlot`, `CarTime`) VALUES
(1, 1411.24, -2347.65, 13.1473, 0, 'None', 'None', 462, 0, 0, 0, 0),
(2, 1404.7, -2347.65, 13.1473, 0, 'None', 'None', 462, 0, 0, 0, 0),
(3, 1398.1, -2347.65, 13.1473, 0, 'None', 'None', 462, 0, 0, 0, 0),
(4, 1391.55, -2347.65, 13.1473, 0, 'None', 'None', 462, 0, 0, 0, 0),
(5, 1385.02, -2347.66, 13.1473, 0, 'None', 'None', 462, 0, 0, 0, 0),
(6, 1411.24, -2330.65, 13.1473, 0, 'None', 'None', 462, 0, 0, 0, 0),
(7, 1404.7, -2330.65, 13.1473, 0, 'None', 'None', 462, 0, 0, 0, 0),
(8, 1398.1, -2330.65, 13.1473, 0, 'None', 'None', 462, 0, 0, 0, 0),
(9, 1391.55, -2330.66, 13.1473, 0, 'None', 'None', 462, 0, 0, 0, 0),
(10, 1385.02, -2330.66, 13.1473, 0, 'None', 'None', 462, 0, 0, 0, 0),
(11, 1411.24, -2313.7, 13.1473, 180, 'None', 'None', 462, 0, 0, 0, 0),
(12, 1404.7, -2313.7, 13.1473, 180, 'None', 'None', 462, 0, 0, 0, 0),
(13, 1398.1, -2313.7, 13.1473, 180, 'None', 'None', 462, 0, 0, 0, 0),
(14, 1391.55, -2313.7, 13.1473, 180, 'None', 'None', 462, 0, 0, 0, 0),
(15, 1385.02, -2313.7, 13.1473, 180, 'None', 'None', 462, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `promocode`
--

CREATE TABLE `promocode` (
  `ID` int(11) NOT NULL,
  `Code` varchar(32) CHARACTER SET utf8 COLLATE utf8_bin NOT NULL,
  `Money` int(11) NOT NULL,
  `Level` int(11) NOT NULL,
  `Used` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `radars`
--

CREATE TABLE `radars` (
  `RadarID` int(11) NOT NULL,
  `RadarPosX` float NOT NULL,
  `RadarPosY` float NOT NULL,
  `RadarPosZ` float NOT NULL,
  `RadarPosC` float NOT NULL,
  `RadarDistance` int(11) NOT NULL,
  `RadarCash` int(11) NOT NULL,
  `RadarSpeed` int(11) NOT NULL,
  `RadarStatus` int(11) NOT NULL,
  `RadarArea` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `support_ips`
--

CREATE TABLE `support_ips` (
  `ID` int(11) NOT NULL,
  `nick` varchar(45) COLLATE cp1251_bin NOT NULL,
  `ip` varchar(127) COLLATE cp1251_bin NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=cp1251 COLLATE=cp1251_bin;

-- --------------------------------------------------------

--
-- Table structure for table `tec_admin_ips`
--

CREATE TABLE `tec_admin_ips` (
  `ID` int(11) NOT NULL,
  `nick` varchar(45) CHARACTER SET cp1251 COLLATE cp1251_bin NOT NULL,
  `ip` varchar(127) CHARACTER SET cp1251 COLLATE cp1251_bin NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `accounts`
--
ALTER TABLE `accounts`
  ADD PRIMARY KEY (`pID`);

--
-- Indexes for table `admin_ips`
--
ALTER TABLE `admin_ips`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `anticheat_settings`
--
ALTER TABLE `anticheat_settings`
  ADD UNIQUE KEY `ac_code` (`ac_code`);

--
-- Indexes for table `autosalon`
--
ALTER TABLE `autosalon`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `banip`
--
ALTER TABLE `banip`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `banlog`
--
ALTER TABLE `banlog`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `bizz`
--
ALTER TABLE `bizz`
  ADD PRIMARY KEY (`bID`);

--
-- Indexes for table `carhousebase`
--
ALTER TABLE `carhousebase`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `carkeys`
--
ALTER TABLE `carkeys`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `family`
--
ALTER TABLE `family`
  ADD PRIMARY KEY (`FamilyID`);

--
-- Indexes for table `house`
--
ALTER TABLE `house`
  ADD PRIMARY KEY (`hID`);

--
-- Indexes for table `news`
--
ALTER TABLE `news`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `penalty`
--
ALTER TABLE `penalty`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `promocode`
--
ALTER TABLE `promocode`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `radars`
--
ALTER TABLE `radars`
  ADD PRIMARY KEY (`RadarID`);

--
-- Indexes for table `support_ips`
--
ALTER TABLE `support_ips`
  ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `tec_admin_ips`
--
ALTER TABLE `tec_admin_ips`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `accounts`
--
ALTER TABLE `accounts`
  MODIFY `pID` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `admin_ips`
--
ALTER TABLE `admin_ips`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=3;

--
-- AUTO_INCREMENT for table `autosalon`
--
ALTER TABLE `autosalon`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=21;

--
-- AUTO_INCREMENT for table `banip`
--
ALTER TABLE `banip`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `banlog`
--
ALTER TABLE `banlog`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `bizz`
--
ALTER TABLE `bizz`
  MODIFY `bID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=26;

--
-- AUTO_INCREMENT for table `carhousebase`
--
ALTER TABLE `carhousebase`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `carkeys`
--
ALTER TABLE `carkeys`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `family`
--
ALTER TABLE `family`
  MODIFY `FamilyID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=182;

--
-- AUTO_INCREMENT for table `house`
--
ALTER TABLE `house`
  MODIFY `hID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=501;

--
-- AUTO_INCREMENT for table `news`
--
ALTER TABLE `news`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT for table `penalty`
--
ALTER TABLE `penalty`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=16;

--
-- AUTO_INCREMENT for table `promocode`
--
ALTER TABLE `promocode`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `radars`
--
ALTER TABLE `radars`
  MODIFY `RadarID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `support_ips`
--
ALTER TABLE `support_ips`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `tec_admin_ips`
--
ALTER TABLE `tec_admin_ips`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;



