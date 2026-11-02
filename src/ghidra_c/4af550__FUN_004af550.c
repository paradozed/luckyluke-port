/* FUN_004af550 @ 004af550 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __fastcall FUN_004af550(int *param_1,int *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  bVar1 = FUN_004b0264(param_2,(undefined4 *)&DAT_004e8f00);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    do {
      iVar2 = FUN_004ae250(s_goW95LockScreen_Screen__info__004c83f0,0x4c83c8,0x1d);
    } while (iVar2 != 0);
  }
  if (DAT_0050a2d8 == 8) {
    FUN_004af607(param_1);
  }
  else {
    FUN_004afa09(param_1);
  }
  iVar2 = FUN_004b021a(param_2);
  if (iVar2 == 0) {
    do {
      iVar2 = FUN_004ae250(s_goW95UnlockScreen_Screen__004c8438,0x4c8410,0x24);
    } while (iVar2 != 0);
  }
  return 0x20;
}

