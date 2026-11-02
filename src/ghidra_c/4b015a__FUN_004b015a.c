/* FUN_004b015a @ 004b015a */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_004b015a(void)

{
  bool bVar1;
  HWND hWnd;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  int local_8;
  
  hWnd = (HWND)FUN_004b1b20();
  UpdateWindow(hWnd);
  for (local_8 = 0; local_8 < 3; local_8 = local_8 + 1) {
    bVar1 = FUN_004b02fd(DAT_004e8ecc);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      do {
        iVar2 = FUN_004ae250(s_goW95ClearScreen_goVarScreen2__004c855c,0x4c852c,0x88);
      } while (iVar2 != 0);
    }
    uVar3 = FUN_004ae460((int)DAT_004e8ecc,DAT_004e8ec8);
    if (uVar3 == 0) {
      do {
        iVar2 = FUN_004ae250(s_goShowScreen_goVarScreen2_goVarS_004c85ac,0x4c857c,0x89);
      } while (iVar2 != 0);
    }
  }
  return 1;
}

