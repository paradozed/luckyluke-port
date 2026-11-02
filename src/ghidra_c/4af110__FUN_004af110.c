/* FUN_004af110 @ 004af110 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __fastcall FUN_004af110(int param_1,int *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;
  uint extraout_EDX;
  longlong lVar3;
  undefined4 local_2c [2];
  uint local_24;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  local_8 = param_1;
  SetRect(&local_18,*(int *)(param_1 + 0xc),*(int *)(param_1 + 0x10),*(int *)(param_1 + 0xc),
          *(int *)(param_1 + 0x10));
  lVar3 = FUN_004b1678(&local_18.left,extraout_EDX);
  if ((int)lVar3 != 0) {
    if (DAT_0050a2d8 == 0x10) {
      bVar1 = FUN_004b0264(param_2,local_2c);
      if (CONCAT31(extraout_var,bVar1) == 0) {
        do {
          iVar2 = FUN_004ae250(s_goW95LockScreen_Screen__info__004c826c,0x4c8240,0x2f);
        } while (iVar2 != 0);
      }
      *(short *)(local_1c + ((local_24 >> 1) * local_18.top + local_18.left) * 2) =
           (short)*(undefined4 *)(local_8 + 0x14);
      iVar2 = FUN_004b021a(param_2);
      if (iVar2 == 0) {
        do {
          iVar2 = FUN_004ae250(s_goW95UnlockScreen_Screen__004c82b8,0x4c828c,0x32);
        } while (iVar2 != 0);
      }
    }
    else {
      bVar1 = FUN_004b0264(param_2,local_2c);
      if (CONCAT31(extraout_var_00,bVar1) == 0) {
        do {
          iVar2 = FUN_004ae250(s_goW95LockScreen_Screen__info__004c8300,0x4c82d4,0x3e);
        } while (iVar2 != 0);
      }
      *(undefined1 *)(local_18.top * local_24 + local_18.left + local_1c) =
           *(undefined1 *)(local_8 + 0x14);
      iVar2 = FUN_004b021a(param_2);
      if (iVar2 == 0) {
        do {
          iVar2 = FUN_004ae250(s_goW95UnlockScreen_Screen__004c834c,0x4c8320,0x40);
        } while (iVar2 != 0);
      }
    }
  }
  return 0x18;
}

