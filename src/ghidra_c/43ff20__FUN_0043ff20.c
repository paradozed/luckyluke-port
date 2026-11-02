/* FUN_0043ff20 @ 0043ff20 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043ff20(uint param_1,uint param_2,short param_3,uint param_4)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  bool bVar4;
  undefined4 local_80 [16];
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  puVar3 = local_80;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = (int)(param_1 + ((int)param_1 >> 0x1f & 0xffU)) >> 8;
  if ((param_1 & 0xff) != 0) {
    local_c = local_c + 1;
  }
  local_10 = (int)(param_2 + ((int)param_2 >> 0x1f & 0xffU)) >> 8;
  if ((param_2 & 0xff) != 0) {
    local_10 = local_10 + 1;
  }
  iVar2 = FUN_00439af0(0x1a8);
  if (iVar2 != 0) {
    bVar4 = *DAT_004f58a8 == 0x536f6674;
    local_2c = (uint)bVar4;
    local_20 = 0;
    for (local_1c = 0; local_1c < local_10; local_1c = local_1c + 1) {
      if ((local_1c == local_10 + -1) && ((param_2 & 0xff) != 0)) {
        local_24 = param_2 & 0xff;
      }
      else {
        local_24 = 0xff;
      }
      for (local_18 = 0; local_18 < local_c; local_18 = local_18 + 1) {
        if ((local_18 == local_c + -1) && ((param_1 & 0xff) != 0)) {
          local_28 = param_1 & 0xff;
        }
        else {
          local_28 = 0xff;
        }
        *(short *)(iVar2 + 8 + local_20 * 0x28) = (short)(local_18 << 8);
        *(short *)(iVar2 + 10 + local_20 * 0x28) = (short)(local_1c << 8);
        *(ushort *)(iVar2 + 0x10 + local_20 * 0x28) =
             (short)(local_18 << 8) + (short)local_28 + 1 + (ushort)bVar4;
        *(short *)(iVar2 + 0x12 + local_20 * 0x28) = (short)(local_1c << 8);
        *(short *)(iVar2 + 0x18 + local_20 * 0x28) = (short)(local_18 << 8);
        *(short *)(iVar2 + 0x1a + local_20 * 0x28) = (short)(local_1c << 8) + 1 + (short)local_24;
        *(ushort *)(iVar2 + 0x20 + local_20 * 0x28) =
             (short)(local_18 << 8) + (short)local_28 + 1 + (ushort)bVar4;
        *(short *)(iVar2 + 0x22 + local_20 * 0x28) = (short)(local_1c << 8) + 1 + (short)local_24;
        *(undefined1 *)(iVar2 + 0xc + local_20 * 0x28) = 0;
        *(undefined1 *)(iVar2 + 0xd + local_20 * 0x28) = 0;
        *(undefined1 *)(iVar2 + 0x14 + local_20 * 0x28) = (undefined1)local_28;
        *(undefined1 *)(iVar2 + 0x15 + local_20 * 0x28) = 0;
        *(undefined1 *)(iVar2 + 0x1c + local_20 * 0x28) = 0;
        *(undefined1 *)(iVar2 + 0x1d + local_20 * 0x28) = (undefined1)local_24;
        *(undefined1 *)(iVar2 + 0x24 + local_20 * 0x28) = (undefined1)local_28;
        *(undefined1 *)(iVar2 + 0x25 + local_20 * 0x28) = (undefined1)local_24;
        *(undefined1 *)(iVar2 + 4 + local_20 * 0x28) = 0xff;
        *(undefined1 *)(iVar2 + 5 + local_20 * 0x28) = 0xff;
        *(undefined1 *)(iVar2 + 6 + local_20 * 0x28) = 0xff;
        *(short *)(iVar2 + 0x16 + local_20 * 0x28) = (short)local_20 + param_3;
        local_20 = local_20 + 1;
      }
    }
    *(int *)(iVar2 + 400) = local_20;
    *(uint *)(iVar2 + 0x194) = param_1;
    *(uint *)(iVar2 + 0x198) = param_2;
    *(int *)(iVar2 + 0x19c) = local_c;
    *(int *)(iVar2 + 0x1a0) = local_10;
    *(uint *)(iVar2 + 0x1a4) = param_4;
    if ((param_4 & 2) != 0) {
      local_30 = (DAT_004be3c8 >> 1) - ((int)param_1 >> 1);
      local_34 = (DAT_004be3cc >> 1) - ((int)param_2 >> 1);
      for (local_18 = 0; local_18 < *(int *)(iVar2 + 400); local_18 = local_18 + 1) {
        *(short *)(iVar2 + 8 + local_18 * 0x28) =
             *(short *)(iVar2 + 8 + local_18 * 0x28) + (short)local_30;
        *(short *)(iVar2 + 0x10 + local_18 * 0x28) =
             *(short *)(iVar2 + 0x10 + local_18 * 0x28) + (short)local_30;
        *(short *)(iVar2 + 0x18 + local_18 * 0x28) =
             *(short *)(iVar2 + 0x18 + local_18 * 0x28) + (short)local_30;
        *(short *)(iVar2 + 0x20 + local_18 * 0x28) =
             *(short *)(iVar2 + 0x20 + local_18 * 0x28) + (short)local_30;
        *(short *)(iVar2 + 10 + local_18 * 0x28) =
             *(short *)(iVar2 + 10 + local_18 * 0x28) + (short)local_34;
        *(short *)(iVar2 + 0x12 + local_18 * 0x28) =
             *(short *)(iVar2 + 0x12 + local_18 * 0x28) + (short)local_34;
        *(short *)(iVar2 + 0x1a + local_18 * 0x28) =
             *(short *)(iVar2 + 0x1a + local_18 * 0x28) + (short)local_34;
        *(short *)(iVar2 + 0x22 + local_18 * 0x28) =
             *(short *)(iVar2 + 0x22 + local_18 * 0x28) + (short)local_34;
      }
    }
    if ((param_4 & 4) != 0) {
      local_38 = 10000;
      local_3c = 0;
      for (local_18 = 0; local_18 < *(int *)(iVar2 + 400); local_18 = local_18 + 1) {
        if (*(short *)(iVar2 + 10 + local_18 * 0x28) < local_38) {
          local_38 = (int)*(short *)(iVar2 + 10 + local_18 * 0x28);
        }
        if (*(short *)(iVar2 + 0x12 + local_18 * 0x28) < local_38) {
          local_38 = (int)*(short *)(iVar2 + 0x12 + local_18 * 0x28);
        }
        if (*(short *)(iVar2 + 0x1a + local_18 * 0x28) < local_38) {
          local_38 = (int)*(short *)(iVar2 + 0x1a + local_18 * 0x28);
        }
        if (*(short *)(iVar2 + 0x22 + local_18 * 0x28) < local_38) {
          local_38 = (int)*(short *)(iVar2 + 0x22 + local_18 * 0x28);
        }
        if (local_3c < *(short *)(iVar2 + 10 + local_18 * 0x28)) {
          local_3c = (int)*(short *)(iVar2 + 10 + local_18 * 0x28);
        }
        if (local_3c < *(short *)(iVar2 + 0x12 + local_18 * 0x28)) {
          local_3c = (int)*(short *)(iVar2 + 0x12 + local_18 * 0x28);
        }
        if (local_3c < *(short *)(iVar2 + 0x1a + local_18 * 0x28)) {
          local_3c = (int)*(short *)(iVar2 + 0x1a + local_18 * 0x28);
        }
        if (local_3c < *(short *)(iVar2 + 0x22 + local_18 * 0x28)) {
          local_3c = (int)*(short *)(iVar2 + 0x22 + local_18 * 0x28);
        }
      }
      local_40 = local_38 + local_3c >> 1;
      for (local_18 = 0; local_18 < *(int *)(iVar2 + 400); local_18 = local_18 + 1) {
        sVar1 = (short)local_40;
        *(short *)(iVar2 + 10 + local_18 * 0x28) =
             sVar1 * 2 - *(short *)(iVar2 + 10 + local_18 * 0x28);
        *(short *)(iVar2 + 0x12 + local_18 * 0x28) =
             sVar1 * 2 - *(short *)(iVar2 + 0x12 + local_18 * 0x28);
        *(short *)(iVar2 + 0x1a + local_18 * 0x28) =
             sVar1 * 2 - *(short *)(iVar2 + 0x1a + local_18 * 0x28);
        *(short *)(iVar2 + 0x22 + local_18 * 0x28) =
             sVar1 * 2 - *(short *)(iVar2 + 0x22 + local_18 * 0x28);
      }
    }
  }
  local_8 = 0x4405c4;
  __chkesp();
  return;
}

