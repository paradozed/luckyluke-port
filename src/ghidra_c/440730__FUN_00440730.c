/* FUN_00440730 @ 00440730 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00440730(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_70 [16];
  undefined4 local_30 [2];
  short local_28;
  short local_26;
  short local_20;
  short local_1e;
  short local_18;
  short local_16;
  short local_10;
  short local_e;
  int local_8;
  
  puVar2 = local_70;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != 0) {
    for (local_8 = 0; local_8 < *(int *)(param_1 + 400); local_8 = local_8 + 1) {
      FUN_00497690(local_30,(undefined4 *)(param_1 + local_8 * 0x28),0x28);
      if ((*(uint *)(param_1 + 0x1a4) & 1) != 0) {
        local_28 = (short)((local_28 * DAT_004be3c8) / *(int *)(param_1 + 0x194));
        local_20 = (short)((local_20 * DAT_004be3c8) / *(int *)(param_1 + 0x194));
        local_18 = (short)((local_18 * DAT_004be3c8) / *(int *)(param_1 + 0x194));
        local_10 = (short)((local_10 * DAT_004be3c8) / *(int *)(param_1 + 0x194));
        local_26 = (short)((local_26 * DAT_004be3cc) / *(int *)(param_1 + 0x198));
        local_1e = (short)((local_1e * DAT_004be3cc) / *(int *)(param_1 + 0x198));
        local_16 = (short)((local_16 * DAT_004be3cc) / *(int *)(param_1 + 0x198));
        local_e = (short)((local_e * DAT_004be3cc) / *(int *)(param_1 + 0x198));
      }
      FUN_00440610((int)local_30);
      (*DAT_004e8a30)();
      __chkesp();
      (*DAT_004e8a54)(local_30,param_2,param_2,param_2,param_2);
      __chkesp();
    }
  }
  local_8 = 0x4408c0;
  __chkesp();
  return;
}

