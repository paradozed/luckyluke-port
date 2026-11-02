/* FUN_0047ce30 @ 0047ce30 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0047ce30(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = 0; local_8 < 0x400; local_8 = local_8 + 1) {
    *(short *)(&DAT_004c6534 + local_8 * 2) = *(short *)(&DAT_004c6534 + local_8 * 2) >> 3;
  }
  return;
}

