/* FUN_00409650 @ 00409650 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00409650(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_84 [16];
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int *local_8;
  
  puVar3 = local_84;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,3);
  local_8 = *(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_c = *local_8;
  sVar1 = FUN_004074b0(param_2,2);
  local_20 = sVar1 * 100;
  local_1c = *(int *)(local_c + 0x90);
  local_18 = *(int *)(local_c + 0x94);
  local_14 = *(int *)(local_c + 0x98);
  sVar1 = FUN_004074b0(param_2,5);
  local_30 = (int)sVar1;
  sVar1 = FUN_004074b0(param_2,4);
  local_34 = (int)sVar1;
  local_24 = local_8[2];
  local_28 = local_8[1];
  local_2c = local_8[3];
  iVar2 = ((DAT_004e89e4 * 0x100) / 2) * local_24;
  local_8[2] = (((int)(DAT_004e89e4 * DAT_004e89e4 + (DAT_004e89e4 * DAT_004e89e4 >> 0x1f & 3U)) >>
                2) * local_30) / 2 + ((int)(iVar2 + (iVar2 >> 0x1f & 0xffU)) >> 8);
  local_38 = local_28;
  if (local_28 < 0) {
    local_38 = -local_28;
  }
  if (local_34 < local_38) {
    iVar2 = ((DAT_004e89e4 * 0x100) / 2) * local_28;
    local_8[1] = (((int)(DAT_004e89e4 * DAT_004e89e4 + (DAT_004e89e4 * DAT_004e89e4 >> 0x1f & 3U))
                  >> 2) * local_34) / 2 + ((int)(iVar2 + (iVar2 >> 0x1f & 0xffU)) >> 8);
  }
  else {
    local_8[1] = 0;
  }
  local_3c = local_2c;
  if (local_2c < 0) {
    local_3c = -local_2c;
  }
  if (local_34 < local_3c) {
    iVar2 = ((DAT_004e89e4 * 0x100) / 2) * local_2c;
    local_8[3] = (((int)(DAT_004e89e4 * DAT_004e89e4 + (DAT_004e89e4 * DAT_004e89e4 >> 0x1f & 3U))
                  >> 2) * local_34) / 2 + ((int)(iVar2 + (iVar2 >> 0x1f & 0xffU)) >> 8);
  }
  else {
    local_8[3] = 0;
  }
  FUN_004095d0(local_c,local_1c,local_18,local_14,local_10,(int)local_8,local_20);
  if (local_28 < 0) {
    local_40 = -local_28;
  }
  else {
    local_40 = local_28;
  }
  if (local_40 < local_34) {
    local_8[1] = 0;
  }
  else if (local_28 != 0) {
    if (local_28 < 0) {
      iVar2 = ((DAT_004e89e4 * 0x100) / 2) * local_34;
      local_8[1] = local_28 + ((int)(iVar2 + (iVar2 >> 0x1f & 0xffU)) >> 8);
    }
    else {
      iVar2 = ((DAT_004e89e4 * 0x100) / 2) * local_34;
      local_8[1] = local_28 - ((int)(iVar2 + (iVar2 >> 0x1f & 0xffU)) >> 8);
    }
  }
  if (local_2c < 0) {
    local_44 = -local_2c;
  }
  else {
    local_44 = local_2c;
  }
  if (local_44 < local_34) {
    local_8[3] = 0;
  }
  else if (local_2c != 0) {
    if (local_2c < 0) {
      iVar2 = ((DAT_004e89e4 * 0x100) / 2) * local_34;
      local_8[3] = local_2c + ((int)(iVar2 + (iVar2 >> 0x1f & 0xffU)) >> 8);
    }
    else {
      iVar2 = ((DAT_004e89e4 * 0x100) / 2) * local_34;
      local_8[3] = local_2c - ((int)(iVar2 + (iVar2 >> 0x1f & 0xffU)) >> 8);
    }
  }
  if (local_18 < local_20) {
    iVar2 = ((DAT_004e89e4 * 0x100) / 2) * local_30;
    local_8[2] = local_24 + ((int)(iVar2 + (iVar2 >> 0x1f & 0xffU)) >> 8);
    if (300 < local_8[2]) {
      local_8[2] = 300;
    }
  }
  else if ((short)local_8[5] < 1) {
    local_8[1] = 0;
    local_8[2] = 0;
    local_8[3] = 0;
  }
  else {
    if (*(char *)((int)local_8 + 0x16) == '\0') {
      if (local_8[1] != 0) {
        local_8[1] = -0x14 - (short)local_8[5];
      }
      if (local_8[3] != 0) {
        local_8[3] = -0x14 - (short)local_8[5];
      }
    }
    else {
      if (local_8[1] != 0) {
        local_8[1] = 0x14 - (short)local_8[5];
      }
      if (local_8[3] != 0) {
        local_8[3] = 0x14 - (short)local_8[5];
      }
    }
    local_8[2] = (short)local_8[5] + -10;
    *(short *)(local_8 + 5) = (short)local_8[5] + -1;
  }
  local_8 = (int *)0x409aa0;
  __chkesp();
  return;
}

