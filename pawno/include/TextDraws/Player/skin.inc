skin_TD[playerid][0] = CreatePlayerTextDraw(playerid, 439.000000, 383.000000, "box1");
PlayerTextDrawBackgroundColor(playerid, skin_TD[playerid][0], 255);
PlayerTextDrawFont(playerid, skin_TD[playerid][0], 1);
PlayerTextDrawLetterSize(playerid, skin_TD[playerid][0], 0.000000, 3.400001);
PlayerTextDrawUseBox(playerid, skin_TD[playerid][0], 1);
PlayerTextDrawBoxColor(playerid, skin_TD[playerid][0], 80);
PlayerTextDrawTextSize(playerid, skin_TD[playerid][0], 206.000000, 10.000000);
PlayerTextDrawSetSelectable(playerid, skin_TD[playerid][0], 0);

skin_TD[playerid][1] = CreatePlayerTextDraw(playerid, 387.000000, 358.000000, "box2");
PlayerTextDrawBackgroundColor(playerid, skin_TD[playerid][1], 255);
PlayerTextDrawFont(playerid, skin_TD[playerid][1], 1);
PlayerTextDrawLetterSize(playerid, skin_TD[playerid][1], 0.000000, 2.000000);
PlayerTextDrawUseBox(playerid, skin_TD[playerid][1], 1);
PlayerTextDrawBoxColor(playerid, skin_TD[playerid][1], 2132351487);
PlayerTextDrawTextSize(playerid, skin_TD[playerid][1], 258.000000, 10.000000);
PlayerTextDrawSetSelectable(playerid, skin_TD[playerid][1], 0);

skin_TD[playerid][2] = CreatePlayerTextDraw(playerid, 385.000000, 360.000000, "box3");
PlayerTextDrawBackgroundColor(playerid, skin_TD[playerid][2], 255);
PlayerTextDrawFont(playerid, skin_TD[playerid][2], 1);
PlayerTextDrawLetterSize(playerid, skin_TD[playerid][2], 0.000000, 1.600000);
PlayerTextDrawUseBox(playerid, skin_TD[playerid][2], 1);
PlayerTextDrawBoxColor(playerid, skin_TD[playerid][2], 128);
PlayerTextDrawTextSize(playerid, skin_TD[playerid][2], 260.000000, 10.000000);
PlayerTextDrawSetSelectable(playerid, skin_TD[playerid][2], 0);

skin_TD[playerid][3] = CreatePlayerTextDraw(playerid, 268.000000, 361.000000, "Select Action");
PlayerTextDrawBackgroundColor(playerid, skin_TD[playerid][3], 255);
PlayerTextDrawFont(playerid, skin_TD[playerid][3], 2);
PlayerTextDrawLetterSize(playerid, skin_TD[playerid][3], 0.349999, 1.200000);
PlayerTextDrawColor(playerid, skin_TD[playerid][3], -1);
PlayerTextDrawSetOutline(playerid, skin_TD[playerid][3], 0);
PlayerTextDrawSetProportional(playerid, skin_TD[playerid][3], 1);
PlayerTextDrawSetShadow(playerid, skin_TD[playerid][3], 1);
PlayerTextDrawSetSelectable(playerid, skin_TD[playerid][3], 0);

skin_TD[playerid][4] = CreatePlayerTextDraw(playerid, 247.000000, 392.000000, "Accept");
PlayerTextDrawBackgroundColor(playerid, skin_TD[playerid][4], 255);
PlayerTextDrawFont(playerid, skin_TD[playerid][4], 2);
PlayerTextDrawLetterSize(playerid, skin_TD[playerid][4], 0.350000, 1.200000);
PlayerTextDrawColor(playerid, skin_TD[playerid][4], -1);
PlayerTextDrawSetProportional(playerid, skin_TD[playerid][4], 1);
PlayerTextDrawSetSelectable(playerid, skin_TD[playerid][4], 0);

skin_TD[playerid][5] = CreatePlayerTextDraw(playerid, 342.000000, 392.000000, "Cancel");
PlayerTextDrawBackgroundColor(playerid, skin_TD[playerid][5], 255);
PlayerTextDrawFont(playerid, skin_TD[playerid][5], 2);
PlayerTextDrawLetterSize(playerid, skin_TD[playerid][5], 0.350000, 1.200000);
PlayerTextDrawColor(playerid, skin_TD[playerid][5], -1);
PlayerTextDrawSetProportional(playerid, skin_TD[playerid][5], 1);
PlayerTextDrawSetSelectable(playerid, skin_TD[playerid][5], 0);

skin_TD[playerid][6] = CreatePlayerTextDraw(playerid, 396.000000, 345.000000, "selecticon2"); // RIGHT
PlayerTextDrawBackgroundColor(playerid, skin_TD[playerid][6], 0);
PlayerTextDrawFont(playerid, skin_TD[playerid][6], 5);
PlayerTextDrawLetterSize(playerid, skin_TD[playerid][6], 0.500000, 1.000000);
PlayerTextDrawColor(playerid, skin_TD[playerid][6], -1876547841);
PlayerTextDrawTextSize(playerid, skin_TD[playerid][6], 73.000000, 65.000000);
PlayerTextDrawSetPreviewModel(playerid, skin_TD[playerid][6], 19132);
PlayerTextDrawSetPreviewRot(playerid, skin_TD[playerid][6], -40.000000, 90.000000, 90.000000, 1.000000);
PlayerTextDrawSetSelectable(playerid, skin_TD[playerid][6], 1);

skin_TD[playerid][7] = CreatePlayerTextDraw(playerid, 176.000000, 345.000000, "selecticon1"); // LEFT
PlayerTextDrawBackgroundColor(playerid, skin_TD[playerid][7], 0);
PlayerTextDrawFont(playerid, skin_TD[playerid][7], 5);
PlayerTextDrawLetterSize(playerid, skin_TD[playerid][7], 0.500000, 1.000000);
PlayerTextDrawColor(playerid, skin_TD[playerid][7], -1876547841);
PlayerTextDrawTextSize(playerid, skin_TD[playerid][7], 73.000000, 65.000000);
PlayerTextDrawSetPreviewModel(playerid, skin_TD[playerid][7], 19132);
PlayerTextDrawSetPreviewRot(playerid, skin_TD[playerid][7], -40.000000, -90.000000, 90.000000, 1.000000);
PlayerTextDrawSetSelectable(playerid, skin_TD[playerid][7], 1);

skin_TD[playerid][8] = CreatePlayerTextDraw(playerid, 327.000000, 367.000000, "selecticon3"); // ACCEPT
PlayerTextDrawBackgroundColor(playerid, skin_TD[playerid][8], 0);
PlayerTextDrawFont(playerid, skin_TD[playerid][8], 5);
PlayerTextDrawLetterSize(playerid, skin_TD[playerid][8], 0.500000, 1.000000);
PlayerTextDrawColor(playerid, skin_TD[playerid][8], -1876547841);
PlayerTextDrawSetProportional(playerid, skin_TD[playerid][8], 1);
PlayerTextDrawTextSize(playerid, skin_TD[playerid][8], 84.000000, 63.000000);
PlayerTextDrawSetPreviewModel(playerid, skin_TD[playerid][8], 19447);
PlayerTextDrawSetPreviewRot(playerid, skin_TD[playerid][8], -20.000000, 0.000000, 90.000000, 1.000000);
PlayerTextDrawSetSelectable(playerid, skin_TD[playerid][8], 1);

skin_TD[playerid][9] = CreatePlayerTextDraw(playerid, 233.000000, 367.000000, "selecticon3"); // CANCEL
PlayerTextDrawBackgroundColor(playerid, skin_TD[playerid][9], 0);
PlayerTextDrawFont(playerid, skin_TD[playerid][9], 5);
PlayerTextDrawLetterSize(playerid, skin_TD[playerid][9], 0.500000, 1.000000);
PlayerTextDrawColor(playerid, skin_TD[playerid][9], -1876547841);
PlayerTextDrawTextSize(playerid, skin_TD[playerid][9], 84.000000, 63.000000);
PlayerTextDrawSetPreviewModel(playerid, skin_TD[playerid][9], 19447);
PlayerTextDrawSetPreviewRot(playerid, skin_TD[playerid][9], -20.000000, 0.000000, 90.000000, 1.000000);
PlayerTextDrawSetSelectable(playerid, skin_TD[playerid][9], 1);

skin_TD[playerid][10] = CreatePlayerTextDraw(playerid, 541.0000, 194.6874, "Box");
PlayerTextDrawLetterSize(playerid, skin_TD[playerid][10], 0.0000, 1.7499);
PlayerTextDrawTextSize(playerid, skin_TD[playerid][10], 631.0000, 0.0000);
PlayerTextDrawAlignment(playerid, skin_TD[playerid][10], 1);
PlayerTextDrawColor(playerid, skin_TD[playerid][10], -2147483393);
PlayerTextDrawUseBox(playerid, skin_TD[playerid][10], 1);
PlayerTextDrawBoxColor(playerid, skin_TD[playerid][10], -2147483393);
PlayerTextDrawBackgroundColor(playerid, skin_TD[playerid][10], 255);
PlayerTextDrawFont(playerid, skin_TD[playerid][10], 1);
PlayerTextDrawSetProportional(playerid, skin_TD[playerid][10], 1);
PlayerTextDrawSetShadow(playerid, skin_TD[playerid][10], 0);

skin_TD[playerid][11] = CreatePlayerTextDraw(playerid, 546.5998, 197.1000, "Fasi:_7000$");
PlayerTextDrawLetterSize(playerid, skin_TD[playerid][11], 0.4094, 1.0325);
PlayerTextDrawAlignment(playerid, skin_TD[playerid][11], 1);
PlayerTextDrawColor(playerid, skin_TD[playerid][11], -1);
PlayerTextDrawSetOutline(playerid, skin_TD[playerid][11], -1);
PlayerTextDrawBackgroundColor(playerid, skin_TD[playerid][11], 255);
PlayerTextDrawFont(playerid, skin_TD[playerid][11], 1);
PlayerTextDrawSetProportional(playerid, skin_TD[playerid][11], 1);
PlayerTextDrawSetShadow(playerid, skin_TD[playerid][11], 0);

skin_TD[playerid][12] = CreatePlayerTextDraw(playerid, 545.5000, 196.8625, "Box");
PlayerTextDrawLetterSize(playerid, skin_TD[playerid][12], 0.0000, 1.3050);
PlayerTextDrawTextSize(playerid, skin_TD[playerid][12], 625.0000, 0.0000);
PlayerTextDrawAlignment(playerid, skin_TD[playerid][12], 1);
PlayerTextDrawColor(playerid, skin_TD[playerid][12], -1);
PlayerTextDrawUseBox(playerid, skin_TD[playerid][12], 1);
PlayerTextDrawBoxColor(playerid, skin_TD[playerid][12], 255);
PlayerTextDrawBackgroundColor(playerid, skin_TD[playerid][12], 255);
PlayerTextDrawFont(playerid, skin_TD[playerid][12], 1);
PlayerTextDrawSetProportional(playerid, skin_TD[playerid][12], 1);
PlayerTextDrawSetShadow(playerid, skin_TD[playerid][12], 0);