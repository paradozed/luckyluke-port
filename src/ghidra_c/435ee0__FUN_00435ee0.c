/* FUN_00435ee0 @ 00435ee0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00435ee0(byte param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_68 [16];
  uint local_28;
  int local_24;
  int local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  puVar2 = local_68;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_24 = 0;
  local_8 = (int *)FUN_00494c40(0x9ac,1);
  if (local_8 != (int *)0x0) {
    *local_8 = param_2;
    local_8[1] = param_3;
    local_10 = *local_8;
    local_c = 0;
    local_20 = 0;
    local_28 = (uint)param_1;
    while( true ) {
      local_14 = 0x100;
      if (local_10 < 0x100) {
        local_14 = local_10;
      }
      for (local_1c = 0; local_1c < param_3; local_1c = local_1c + 1) {
        for (local_18 = 0; (int)local_18 < local_14; local_18 = local_18 + 1) {
          *(undefined2 *)
           (*(int *)(DAT_004f58a4 + (uint)param_1 * 4) +
           ((local_1c + local_c) * 0x100 + local_18) * 2) =
               *(undefined2 *)(param_4 + (local_1c * *local_8 + local_20 + local_18) * 2);
        }
      }
      *(undefined1 *)(local_8 + local_24 * 10 + 0xb) = 0;
      *(char *)((int)local_8 + local_24 * 0x28 + 0x2d) = (char)local_c;
      *(char *)(local_8 + local_24 * 10 + 0xd) = (char)local_14 + -1;
      *(char *)((int)local_8 + local_24 * 0x28 + 0x35) = (char)local_c;
      *(undefined1 *)(local_8 + local_24 * 10 + 0xf) = 0;
      *(char *)((int)local_8 + local_24 * 0x28 + 0x3d) = (char)local_c + (char)param_3;
      *(char *)(local_8 + local_24 * 10 + 0x11) = (char)local_14 + -1;
      *(char *)((int)local_8 + local_24 * 0x28 + 0x45) = (char)local_c + (char)param_3;
      *(short *)(local_8 + local_24 * 10 + 10) = (short)local_20;
      *(undefined2 *)((int)local_8 + local_24 * 0x28 + 0x2a) = 0;
      *(short *)(local_8 + local_24 * 10 + 0xc) = (short)local_20 + (short)local_14;
      *(undefined2 *)((int)local_8 + local_24 * 0x28 + 0x32) = 0;
      *(short *)(local_8 + local_24 * 10 + 0xe) = (short)local_20;
      *(undefined2 *)((int)local_8 + local_24 * 0x28 + 0x3a) = (undefined2)param_3;
      *(short *)(local_8 + local_24 * 10 + 0x10) = (short)local_20 + (short)local_14;
      *(undefined2 *)((int)local_8 + local_24 * 0x28 + 0x42) = (undefined2)param_3;
      *(ushort *)((int)local_8 + local_24 * 0x28 + 0x36) = (ushort)param_1;
      *(undefined1 *)(local_8 + local_24 * 10 + 9) = 0xff;
      *(undefined1 *)((int)local_8 + local_24 * 0x28 + 0x25) = 0xff;
      *(undefined1 *)((int)local_8 + local_24 * 0x28 + 0x26) = 0xff;
      local_24 = local_24 + 1;
      local_20 = local_20 + local_14;
      local_10 = local_10 - local_14;
      local_c = local_c + param_3;
      if (local_10 < 1) break;
      if (0xff < local_c + param_3) {
        local_c = 0;
        param_1 = param_1 + 1;
      }
    }
    local_8[2] = local_24;
    for (local_18 = local_28; (int)local_18 < (int)(param_1 + 1); local_18 = local_18 + 1) {
      (*DAT_004e8a24)(local_18,*(undefined4 *)(DAT_004f58a4 + local_18 * 4));
      __chkesp();
    }
  }
  local_8 = (int *)0x4361e5;
  __chkesp();
  return;
}

