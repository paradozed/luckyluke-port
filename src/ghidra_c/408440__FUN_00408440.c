/* FUN_00408440 @ 00408440 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00408440(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_8c [16];
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  uint local_3c;
  int local_38;
  undefined4 local_34;
  int local_30;
  int local_28;
  undefined4 local_24;
  int local_20;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar3 = local_8c;
  for (iVar2 = 0x22; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_3c = (uint)sVar1;
  local_40 = FUN_00407580(param_1);
  local_44 = **(int **)(local_40 + 8);
  sVar1 = FUN_004074b0(param_2,4);
  local_48 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_28 = *(int *)(local_48 + 0x90);
  local_24 = *(undefined4 *)(local_48 + 0x94);
  local_20 = *(int *)(local_48 + 0x98);
  local_38 = *(int *)(local_44 + 0x90);
  local_34 = *(undefined4 *)(local_44 + 0x94);
  local_30 = *(int *)(local_44 + 0x98);
  local_3c = local_3c & 0xfff;
  sVar1 = FUN_00407700(local_44,local_48,local_3c);
  if (sVar1 != 0) {
    local_14 = local_38 - local_28;
    local_18 = local_30 - local_20;
    sVar1 = FUN_004081b0(local_44);
    local_c = (int)sVar1 + 0x400U & 0xfff;
    sVar1 = FUN_004836a0(local_18,local_14);
    local_10 = (int)sVar1 & 0xfff;
    if ((int)(local_10 - local_c) < 0) {
      local_4c = -(local_10 - local_c);
    }
    else {
      local_4c = local_10 - local_c;
    }
    local_8 = local_4c;
    if (local_4c < 100) {
      FUN_004087d0(local_44,0,(short)local_10 + -0x400,0);
    }
    else {
      if ((int)local_10 < (int)local_c) {
        sVar1 = FUN_004074b0(param_2,3);
        local_c = local_c - (int)sVar1;
      }
      else {
        sVar1 = FUN_004074b0(param_2,3);
        local_c = local_c + (int)sVar1;
      }
      FUN_004087d0(local_44,0,(short)local_c + -0x400,0);
    }
  }
  local_8 = 0x408622;
  __chkesp();
  return;
}

