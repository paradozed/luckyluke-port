/* FUN_00437760 @ 00437760 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00437760(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_68 [16];
  uint local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  void *local_c;
  char *local_8;
  
  puVar2 = local_68;
  for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (char *)FUN_00435000("win\\graphics\\presskey.kxp","lucky");
  local_c = (void *)FUN_00431fe0(local_8,(uint *)"pak_e.pcx");
  FUN_00435d90(local_8);
  local_1c = param_3 * 0x200 + param_2;
  local_18 = 0;
  for (local_14 = 0; (local_14 < DAT_004e848c && (local_14 + param_3 < 0x100));
      local_14 = local_14 + 1) {
    for (local_10 = 0; local_10 < DAT_004e8488; local_10 = local_10 + 1) {
      if (*(short *)((int)local_c + local_18 * 2) != 0) {
        if (*DAT_004f58a8 == 0x536f6674) {
          local_20 = (uint)(((int)(uint)*(ushort *)(param_1 + local_1c * 2) >> 0xb) * 0x32) / 100;
          local_24 = (((int)(uint)*(ushort *)(param_1 + local_1c * 2) >> 5 & 0x3fU) * 0x32) / 100;
          local_28 = ((*(ushort *)(param_1 + local_1c * 2) & 0x1f) * 0x32) / 100;
          *(ushort *)(param_1 + local_1c * 2) =
               (ushort)local_28 | (ushort)(local_24 << 5) | (ushort)(local_20 << 0xb);
        }
        else {
          local_20 = (((int)(uint)*(ushort *)(param_1 + local_1c * 2) >> 10 & 0x1fU) * 0x32) / 100;
          local_24 = (((int)(uint)*(ushort *)(param_1 + local_1c * 2) >> 5 & 0x1fU) * 0x32) / 100;
          local_28 = ((*(ushort *)(param_1 + local_1c * 2) & 0x1f) * 0x32) / 100;
          *(ushort *)(param_1 + local_1c * 2) =
               (ushort)local_28 | (ushort)(local_24 << 5) | (ushort)(local_20 << 10) | 0x8000;
        }
      }
      local_18 = local_18 + 1;
      local_1c = local_1c + 1;
    }
    local_1c = local_1c + (0x200 - DAT_004e8488);
  }
  if (local_c != (void *)0xdddddddd) {
    FUN_00495280(local_c);
  }
  local_8 = (char *)0x4379ac;
  __chkesp();
  return;
}

