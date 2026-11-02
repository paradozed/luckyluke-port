/* FUN_0045aa20 @ 0045aa20 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045aa20(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  uint local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = 0; local_8 < 0xd; local_8 = local_8 + 1) {
    for (local_c = 0; local_c < 0xd; local_c = local_c + 1) {
      *(short *)(DAT_004f2ac8 + (local_8 * 0xd + local_c) * 8) = ((short)local_8 + -4) * 0x9c4;
      *(undefined2 *)(DAT_004f2ac8 + 2 + (local_8 * 0xd + local_c) * 8) = 0;
      *(short *)(DAT_004f2ac8 + 4 + (local_8 * 0xd + local_c) * 8) = (short)local_c * 0x9c4;
      *(undefined2 *)(DAT_004f2ac8 + 6 + (local_8 * 0xd + local_c) * 8) = 0;
    }
  }
  return;
}

