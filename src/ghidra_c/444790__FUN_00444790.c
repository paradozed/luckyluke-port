/* FUN_00444790 @ 00444790 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00444790(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 local_70 [16];
  byte *local_30;
  ushort *local_2c;
  ushort *local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint *local_c;
  uint *local_8;
  
  puVar4 = local_70;
  for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (((param_1 != (int *)0x0) && ((char)param_1[1] != '\x02')) &&
     (local_8 = (uint *)FUN_00494c40(param_1[2] * param_1[3] * 4,1), local_8 != (uint *)0x0)) {
    local_c = local_8;
    if ((char)param_1[1] == '\x01') {
      local_24 = param_1[2] * param_1[3];
      local_28 = (ushort *)*param_1;
      for (local_20 = 0; local_20 < local_24; local_20 = local_20 + 1) {
        uVar1 = (int)(uint)*local_28 >> 8 & 0xf;
        uVar3 = (int)(uint)*local_28 >> 4 & 0xf;
        local_1c = ((int)(uint)*local_28 >> 0xc) << 4;
        local_10 = uVar1 << 4;
        local_14 = uVar3 << 4;
        local_18 = (*local_28 & 0xf) << 4;
        *local_c = ((int)(uint)*local_28 >> 0xc) << 0x1c | uVar1 << 0x14 | uVar3 << 0xc | local_18;
        local_28 = local_28 + 1;
        local_c = local_c + 1;
      }
    }
    else if ((char)param_1[1] == '\x03') {
      local_24 = param_1[2] * param_1[3];
      local_2c = (ushort *)*param_1;
      for (local_20 = 0; local_20 < local_24; local_20 = local_20 + 1) {
        uVar3 = (int)(uint)*local_2c >> 10 & 0x1f;
        uVar1 = (int)(uint)*local_2c >> 5 & 0x1f;
        local_1c = ((int)(uint)*local_2c >> 0xf) << 7;
        local_10 = uVar3 << 3;
        local_14 = uVar1 << 3;
        local_18 = (*local_2c & 0x1f) << 3;
        *local_c = ((int)(uint)*local_2c >> 0xf) << 0x1f | uVar3 << 0x13 | uVar1 << 0xb | local_18;
        local_2c = local_2c + 1;
        local_c = local_c + 1;
      }
    }
    else if ((char)param_1[1] == '\x04') {
      local_24 = param_1[2] * param_1[3];
      local_30 = (byte *)*param_1;
      for (local_20 = 0; local_20 < local_24; local_20 = local_20 + 1) {
        local_1c = 1;
        local_10 = (uint)local_30[2];
        local_14 = (uint)local_30[1];
        local_18 = (uint)*local_30;
        *local_c = local_10 << 0x10 | 0x1000000 | local_14 << 8 | local_18;
        local_30 = local_30 + 3;
        local_c = local_c + 1;
      }
    }
    if (*param_1 != -0x22222223) {
      FUN_00495280((void *)*param_1);
    }
    *param_1 = (int)local_8;
  }
  local_8 = (uint *)0x444a92;
  __chkesp();
  return;
}

