/* FUN_00492c90 @ 00492c90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00492c90(int *param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_64 [16];
  uint local_24;
  undefined1 *local_20;
  short *local_1c;
  undefined1 *local_18;
  uint local_14;
  short *local_10;
  byte *local_c;
  short *local_8;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (*(char *)((int)param_1 + 9) != param_2) {
    if (param_2 == '\x10') {
      local_8 = (short *)FUN_00494840(param_1[1] << 1);
      if (local_8 != (short *)0x0) {
        local_c = (byte *)*param_1;
        local_10 = local_8;
        for (local_14 = 0; local_14 < (uint)param_1[1]; local_14 = local_14 + 1) {
          *local_10 = (ushort)*local_c * 0x100 + -0x8000;
          local_10 = local_10 + 1;
          local_c = local_c + 1;
        }
        FUN_00495280((void *)*param_1);
        *param_1 = (int)local_8;
        param_1[1] = param_1[1] << 1;
        *(undefined1 *)((int)param_1 + 9) = 0x10;
      }
    }
    else if ((param_2 == '\b') &&
            (local_18 = (undefined1 *)FUN_00494840((uint)param_1[1] >> 1),
            local_18 != (undefined1 *)0x0)) {
      local_1c = (short *)*param_1;
      local_20 = local_18;
      for (local_24 = 0; local_24 < (uint)param_1[1]; local_24 = local_24 + 2) {
        *local_20 = (char)(*local_1c + 0x8000 + (*local_1c + 0x8000 >> 0x1f & 0xffU) >> 8);
        local_20 = local_20 + 1;
        local_1c = local_1c + 1;
      }
      FUN_00495280((void *)*param_1);
      *param_1 = (int)local_18;
      param_1[1] = (uint)param_1[1] >> 1;
      *(undefined1 *)((int)param_1 + 9) = 8;
    }
  }
  local_8 = (short *)0x492e49;
  __chkesp();
  return;
}

