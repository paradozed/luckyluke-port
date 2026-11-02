/* FUN_0042fd30 @ 0042fd30 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042fd30(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_78 [16];
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
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_78;
  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_24 = (DAT_004be3c8 * 0x1ae) / 0x280;
  local_28 = (DAT_004be3cc * 0x172) / 0x1e0;
  local_2c = (DAT_004be3c8 * 200) / 0x280;
  local_30 = (DAT_004be3cc * 100) / 0x1e0;
  local_34 = 200;
  local_38 = 100;
  local_20 = 0;
  local_18 = local_28;
  FUN_00458ec0();
  local_10 = 0;
  for (local_c = 0; local_c < 1; local_c = local_c + 1) {
    local_14 = local_24;
    local_1c = 0;
    for (local_8 = 0; local_8 < 1; local_8 = local_8 + 1) {
      *(undefined1 *)(DAT_004f6124 + 6 + local_10 * 0x28) = 0xff;
      *(undefined1 *)(DAT_004f6124 + 5 + local_10 * 0x28) = 0xff;
      *(undefined1 *)(DAT_004f6124 + 4 + local_10 * 0x28) = 0xff;
      *(short *)(DAT_004f6124 + 8 + local_10 * 0x28) = (short)local_14;
      *(short *)(DAT_004f6124 + 0x10 + local_10 * 0x28) = (short)local_14 + (short)local_2c;
      *(short *)(DAT_004f6124 + 0x18 + local_10 * 0x28) = (short)local_14;
      *(short *)(DAT_004f6124 + 0x20 + local_10 * 0x28) = (short)local_14 + (short)local_2c;
      *(short *)(DAT_004f6124 + 10 + local_10 * 0x28) = (short)local_18;
      *(short *)(DAT_004f6124 + 0x12 + local_10 * 0x28) = (short)local_18;
      *(short *)(DAT_004f6124 + 0x1a + local_10 * 0x28) = (short)local_18 + (short)local_30;
      *(short *)(DAT_004f6124 + 0x22 + local_10 * 0x28) = (short)local_18 + (short)local_30;
      *(undefined2 *)(DAT_004f6124 + 0x16 + local_10 * 0x28) = 0xe;
      *(char *)(DAT_004f6124 + 0xc + local_10 * 0x28) = (char)local_1c;
      *(char *)(DAT_004f6124 + 0x14 + local_10 * 0x28) = (char)local_1c + (char)local_34;
      *(char *)(DAT_004f6124 + 0x1c + local_10 * 0x28) = (char)local_1c;
      *(char *)(DAT_004f6124 + 0x24 + local_10 * 0x28) = (char)local_1c + (char)local_34;
      *(char *)(DAT_004f6124 + 0xd + local_10 * 0x28) = (char)local_20;
      *(char *)(DAT_004f6124 + 0x15 + local_10 * 0x28) = (char)local_20;
      *(char *)(DAT_004f6124 + 0x1d + local_10 * 0x28) = (char)local_20 + (char)local_38;
      *(char *)(DAT_004f6124 + 0x25 + local_10 * 0x28) = (char)local_20 + (char)local_38;
      *(byte *)(DAT_004f6124 + 7 + local_10 * 0x28) =
           *(byte *)(DAT_004f6124 + 7 + local_10 * 0x28) | 2;
      local_14 = local_14 + local_2c;
      local_1c = local_1c + local_34;
      local_10 = local_10 + 1;
    }
    local_18 = local_18 + local_30;
    local_20 = local_20 + local_38;
  }
  local_8 = 0x43000f;
  __chkesp();
  return;
}

