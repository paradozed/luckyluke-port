/* FUN_00444aa0 @ 00444aa0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00444aa0(int *param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_70 [16];
  undefined1 *local_30;
  ushort *local_2c;
  ushort *local_28;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint *local_c;
  ushort *local_8;
  
  puVar2 = local_70;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((param_1 != (int *)0x0) && (param_2 != '\x02')) {
    if (param_2 == '\x01') {
      local_8 = (ushort *)FUN_00494c40(param_1[2] * param_1[3] * 2,1);
    }
    if (param_2 == '\x03') {
      local_8 = (ushort *)FUN_00494c40(param_1[2] * param_1[3] * 2,1);
    }
    if (param_2 == '\x04') {
      local_8 = (ushort *)FUN_00494c40(param_1[2] * param_1[3] * 3,1);
    }
    if (local_8 != (ushort *)0x0) {
      local_c = (uint *)*param_1;
      if (param_2 == '\x01') {
        local_24 = param_1[2] * param_1[3];
        local_28 = local_8;
        for (local_20 = 0; local_20 < local_24; local_20 = local_20 + 1) {
          local_1c = *local_c >> 0x1c;
          local_10 = (*local_c >> 0x10 & 0xff) >> 4;
          local_14 = (*local_c >> 8 & 0xff) >> 4;
          local_18 = (*local_c & 0xff) >> 4;
          *local_28 = (ushort)(local_1c << 0xc) | (ushort)(local_10 << 8) | (ushort)(local_14 << 4)
                      | (ushort)local_18;
          local_c = local_c + 1;
          local_28 = local_28 + 1;
        }
      }
      else if (param_2 == '\x03') {
        local_24 = param_1[2] * param_1[3];
        local_2c = local_8;
        for (local_20 = 0; local_20 < local_24; local_20 = local_20 + 1) {
          local_1c = *local_c >> 0x1f;
          local_10 = (*local_c >> 0x10 & 0xff) >> 3;
          local_14 = (*local_c >> 8 & 0xff) >> 3;
          local_18 = (*local_c & 0xff) >> 3;
          *local_2c = (ushort)(local_1c << 0xf) | (ushort)(local_10 << 10) | (ushort)(local_14 << 5)
                      | (ushort)local_18;
          local_c = local_c + 1;
          local_2c = local_2c + 1;
        }
      }
      else if (param_2 == '\x04') {
        local_24 = param_1[2] * param_1[3];
        local_30 = (undefined1 *)*param_1;
        for (local_20 = 0; local_20 < local_24; local_20 = local_20 + 1) {
          local_10 = *local_c >> 0x10 & 0xff;
          local_14 = *local_c >> 8 & 0xff;
          local_18 = *local_c & 0xff;
          *local_30 = (char)*local_c;
          local_30 = local_30 + 3;
          local_c = local_c + 1;
        }
      }
      if (*param_1 != -0x22222223) {
        FUN_00495280((void *)*param_1);
      }
      *param_1 = (int)local_8;
    }
  }
  local_8 = (ushort *)0x444e05;
  __chkesp();
  return;
}

