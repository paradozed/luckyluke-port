/* FUN_00409ee0 @ 00409ee0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00409ee0(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_80 [16];
  int local_40;
  int local_3c;
  undefined2 local_38;
  undefined2 uStack_36;
  uint local_34;
  uint local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int local_c;
  int local_8;
  
  puVar3 = local_80;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_1c = *(int *)(param_1 + 0x90);
  local_18 = *(undefined4 *)(param_1 + 0x94);
  local_14 = *(int *)(param_1 + 0x98);
  local_2c = *(int *)(param_2 + 0x90);
  local_28 = *(undefined4 *)(param_2 + 0x94);
  local_24 = *(int *)(param_2 + 0x98);
  local_8 = local_2c - local_1c;
  local_c = local_24 - local_14;
  if (local_2c - local_1c < 0) {
    local_3c = -(local_2c - local_1c);
  }
  else {
    local_3c = local_2c - local_1c;
  }
  if (local_3c < 0x1389) {
    if (local_24 - local_14 < 0) {
      local_40 = -(local_24 - local_14);
    }
    else {
      local_40 = local_24 - local_14;
    }
    if (local_40 < 0x1f41) {
      _local_38 = CONCAT22(uStack_36,0x180);
      if ((local_8 != 0) || (local_c != 0)) {
        sVar1 = FUN_004081b0(param_1);
        local_30 = (int)sVar1 + (uint)DAT_004f5558 & 0xfff;
        sVar1 = FUN_004836a0(-local_c,local_8);
        local_34 = sVar1 + -0x400 + local_30 & 0xfff;
      }
    }
  }
  local_8 = 0x40a061;
  __chkesp();
  return;
}

