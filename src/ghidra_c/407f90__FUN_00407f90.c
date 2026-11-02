/* FUN_00407f90 @ 00407f90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00407f90(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_80 [16];
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar3 = local_80;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_30 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_2c = *(int *)(local_30 + 0x90);
  local_28 = *(undefined4 *)(local_30 + 0x94);
  local_24 = *(int *)(local_30 + 0x98);
  sVar1 = FUN_004074b0(param_2,3);
  local_34 = sVar1 * 100;
  sVar1 = FUN_004074b0(param_2,4);
  local_38 = sVar1 * 100;
  sVar1 = FUN_004074b0(param_2,5);
  local_3c = sVar1 * 100;
  local_1c = 0xc00;
  local_14 = local_2c - local_34;
  local_18 = local_24 + sVar1 * -100;
  sVar1 = FUN_004081b0(local_30);
  local_c = (int)sVar1 + 0x400U & 0xfff;
  sVar1 = FUN_004836a0(local_18,local_14);
  local_10 = (int)sVar1 & 0xfff;
  if ((int)(local_10 - local_c) < 0) {
    local_40 = -(local_10 - local_c);
  }
  else {
    local_40 = local_10 - local_c;
  }
  local_8 = local_40;
  local_2c = *(int *)(local_30 + 0x90);
  local_28 = *(int *)(local_30 + 0x94);
  local_24 = *(int *)(local_30 + 0x98);
  if (99 < local_40) {
    if ((int)local_10 < (int)local_c) {
      sVar1 = FUN_004074b0(param_2,6);
      local_c = local_c - (int)sVar1;
    }
    else {
      sVar1 = FUN_004074b0(param_2,6);
      local_c = local_c + (int)sVar1;
    }
    FUN_004087d0(local_30,0,(short)local_c + -0x400,0);
    if (((DAT_004e85b8 != 0xf) || (sVar1 = FUN_004074b0(param_2,3), sVar1 != 0x37)) ||
       (*DAT_004f58a8 != 0x536f6674)) {
      FUN_00407cd0(local_2c,local_28,local_24,local_20,local_34,local_38,local_3c,0x1e);
    }
  }
  local_8 = 0x4081a6;
  __chkesp();
  return;
}

