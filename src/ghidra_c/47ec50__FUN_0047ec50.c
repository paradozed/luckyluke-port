/* FUN_0047ec50 @ 0047ec50 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0047ec50(byte *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_78 [16];
  short local_38;
  byte *local_34;
  int local_30;
  int local_2c;
  int local_28;
  byte *local_24;
  int local_20;
  byte *local_1c;
  ushort *local_18;
  byte *local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  puVar2 = local_78;
  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_38 = 0;
  *param_1 = *param_1 | 1;
  if (*(int *)(param_1 + 8) == 0) {
    local_24 = param_1;
    local_34 = param_1 + *(int *)(param_1 + 0x44);
  }
  else {
    local_24 = *(byte **)(param_1 + 8);
    local_34 = local_24 + *(int *)(local_24 + 0x44);
    FUN_00497690(*(undefined4 **)(param_1 + 0x30),
                 (undefined4 *)(local_24 + *(int *)(local_34 + 0xc)),*(uint *)(local_34 + 0x10));
  }
  local_10 = *(int *)(param_1 + 0x20);
  local_14 = local_24 + *(int *)(local_34 + 8);
  local_28 = *(int *)(param_1 + 0x18);
  local_2c = *(int *)(param_1 + 0xbc);
  local_30 = *(int *)(param_1 + 0xc0);
  for (local_8 = 0; local_8 < *(uint *)(param_1 + 0x1c); local_8 = local_8 + 1) {
    *(uint *)(local_10 + 0x10 + local_8 * 0x28) =
         local_2c + (uint)*(ushort *)(local_14 + local_8 * 0xc + 6) * 8;
    *(uint *)(local_10 + 4 + local_8 * 0x28) =
         local_28 + (uint)*(ushort *)(local_14 + local_8 * 0xc + 4) * 8;
    *(uint *)(local_10 + 8 + local_8 * 0x28) =
         local_2c + (uint)*(ushort *)(local_14 + local_8 * 0xc + 4) * 8;
    *(uint *)(local_10 + 0xc + local_8 * 0x28) =
         local_30 + (uint)*(ushort *)(local_14 + local_8 * 0xc + 4) * 8;
    *(undefined2 *)(local_10 + local_8 * 0x28) = *(undefined2 *)(local_14 + local_8 * 0xc);
    *(undefined2 *)(local_10 + 2 + local_8 * 0x28) = *(undefined2 *)(local_14 + local_8 * 0xc + 2);
    *(byte *)(local_10 + 0x15 + local_8 * 0x28) = local_14[local_8 * 0xc + 8];
    *(undefined1 *)(local_10 + 0x14 + local_8 * 0x28) = 0;
    *(undefined2 *)(local_10 + 0x16 + local_8 * 0x28) = 0;
    *(undefined2 *)(local_10 + 0x18 + local_8 * 0x28) = 0;
    *(undefined2 *)(local_10 + 0x1a + local_8 * 0x28) = 0;
    *(undefined2 *)(local_10 + 0x1c + local_8 * 0x28) = 0;
    *(undefined2 *)(local_10 + 0x1e + local_8 * 0x28) = 0;
    *(undefined2 *)(local_10 + 0x20 + local_8 * 0x28) = 0;
    *(undefined2 *)(local_10 + 0x22 + local_8 * 0x28) = 0;
    *(undefined2 *)(local_10 + 0x24 + local_8 * 0x28) = 0;
    *(undefined2 *)(local_10 + 0x26 + local_8 * 0x28) = 0;
  }
  local_18 = *(ushort **)(param_1 + 0x30);
  local_1c = local_34 + 0x14;
  _DAT_0050815c = *(undefined4 *)(param_1 + 0x3c);
  local_20 = *(int *)(param_1 + 0x4c);
  local_c = 0;
  do {
    (**(code **)(&DAT_00507f84 + (uint)*local_18 * 0x34))
              (local_18 + 10,local_1c,local_18[1],local_30);
    __chkesp();
    (**(code **)(&DAT_00507f80 + (uint)*local_18 * 0x34))
              (local_18 + 10,local_1c,local_18[1],local_20,*(undefined4 *)(param_1 + 0xc0),
               *(undefined4 *)(param_1 + 0x3c));
    __chkesp();
    local_1c = local_1c + *(int *)(local_18 + 4);
    local_c = local_c + local_18[1];
    local_20 = local_20 + *(int *)(local_18 + 6);
    if (local_c < *(uint *)(param_1 + 0x2c)) {
      *(uint *)(local_18 + 8) = (int)local_18 + *(int *)(local_18 + 2) * (uint)local_18[1] + 0x14;
    }
    else {
      local_18[8] = 0;
      local_18[9] = 0;
    }
    local_18 = *(ushort **)(local_18 + 8);
    local_38 = local_38 + 1;
  } while (local_18 != (ushort *)0x0);
  FUN_00497690(*(undefined4 **)(param_1 + 0x50),*(undefined4 **)(param_1 + 0x4c),
               *(uint *)(param_1 + 0x48));
  if ((*param_1 & 2) == 0) {
    param_1[0xe0] = 0;
    param_1[0xe1] = 0;
    param_1[0xe2] = 0;
    param_1[0xe3] = 0;
    param_1[0xe4] = 0;
    param_1[0xe5] = 0;
    param_1[0xe6] = 0;
    param_1[0xe7] = 0;
    param_1[0xc4] = 0;
    param_1[0xc5] = 0;
    param_1[0xc6] = 0;
    param_1[199] = 0;
    param_1[200] = 0;
    param_1[0xc9] = 0;
    param_1[0xca] = 0;
    param_1[0xcb] = 0;
    param_1[0xcc] = 0;
    param_1[0xcd] = 0;
    param_1[0xce] = 0;
    param_1[0xcf] = 0;
  }
  *(undefined ***)(param_1 + 0xd0) = &PTR_FUN_004c6480 + (uint)param_1[1] * 5;
  *(undefined ***)(param_1 + 0xd4) = &PTR_FUN_004c6470;
  if (*(int *)(param_1 + 0x34) != 0) {
    FUN_0047e7c0((int)param_1,*(int *)(param_1 + 0x4c));
    FUN_0047e7c0((int)param_1,*(int *)(param_1 + 0x50));
  }
  if (1 < *(uint *)(param_1 + 0x1c)) {
    FUN_0047f410((int)param_1,'\0');
  }
  if (param_1[1] == 1) {
    if (*(int *)(param_1 + 0x54) == 0) {
      param_1[0x54] = 0;
      param_1[0x55] = 1;
      param_1[0x56] = 0;
      param_1[0x57] = 0;
    }
    FUN_0047d700((int)param_1,*(undefined4 *)(param_1 + 0x54));
  }
  local_8 = 0x47f0e5;
  __chkesp();
  return;
}

