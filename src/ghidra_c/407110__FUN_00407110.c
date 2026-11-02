/* FUN_00407110 @ 00407110 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00407110(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_90 [16];
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  uint local_40;
  int local_3c;
  undefined4 local_38;
  int local_34;
  int local_2c;
  undefined4 local_28;
  int local_24;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  puVar3 = local_90;
  for (iVar2 = 0x23; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_40 = (int)sVar1 & 0xfff;
  iVar2 = FUN_00407580(param_1);
  local_44 = **(int **)(iVar2 + 8);
  sVar1 = FUN_004074b0(param_2,4);
  local_48 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  sVar1 = FUN_004074b0(param_2,3);
  local_1c = (int)sVar1;
  local_2c = *(int *)(local_44 + 0x90);
  local_28 = *(undefined4 *)(local_44 + 0x94);
  local_24 = *(int *)(local_44 + 0x98);
  local_3c = *(int *)(local_48 + 0x90);
  local_38 = *(undefined4 *)(local_48 + 0x94);
  local_34 = *(int *)(local_48 + 0x98);
  sVar1 = FUN_00407700(local_44,local_48,local_40);
  if (sVar1 != 0) {
    local_14 = local_2c - local_3c;
    local_18 = local_24 - local_34;
    sVar1 = FUN_004074f0(local_44);
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
    if (local_4c < local_1c) {
      FUN_00407530(local_44,0,(short)local_10 + -0x400,0);
    }
    else {
      if ((int)(local_10 - local_c) < 0) {
        local_50 = -(local_10 - local_c);
      }
      else {
        local_50 = local_10 - local_c;
      }
      if (0x7ff < local_50) {
        if ((int)local_10 < (int)local_c) {
          local_10 = local_10 + 0x1000;
        }
        else {
          local_10 = local_10 - 0x1000;
        }
      }
      iVar2 = local_1c;
      if ((int)local_10 < (int)local_c) {
        iVar2 = -local_1c;
      }
      local_c = local_c + iVar2;
      FUN_00407530(local_44,0,(short)local_c + -0x400,0);
    }
  }
  local_8 = 0x407312;
  __chkesp();
  return;
}

