/* FUN_00407850 @ 00407850 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00407850(int param_1,int param_2,uint param_3)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_78 [16];
  int local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  int local_1c;
  int local_18;
  undefined4 local_14;
  int local_c;
  int local_8;
  
  puVar3 = local_78;
  for (iVar2 = 0x1d; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_1c = *(int *)(param_1 + 0x90);
  local_18 = *(int *)(param_1 + 0x94);
  local_14 = *(undefined4 *)(param_1 + 0x98);
  local_2c = *(int *)(param_2 + 0x90);
  local_28 = *(int *)(param_2 + 0x94);
  local_24 = *(undefined4 *)(param_2 + 0x98);
  local_8 = local_2c - local_1c;
  local_c = local_28 - local_18;
  if ((local_8 != 0) || (local_c != 0)) {
    sVar1 = FUN_004081b0(param_1);
    local_30 = (int)sVar1 & 0xfff;
    sVar1 = FUN_004836a0(-local_c,local_8);
    local_34 = sVar1 + -0x400 + local_30 & 0xfff;
    if ((local_34 < (param_3 & 0xfff)) || ((int)(0x1000 - (param_3 & 0xfff)) < (int)local_34)) {
      if (local_2c - local_1c < 0) {
        local_38 = -(local_2c - local_1c);
      }
      else {
        local_38 = local_2c - local_1c;
      }
    }
  }
  local_8 = 0x40798d;
  __chkesp();
  return;
}

