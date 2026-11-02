/* FUN_00494170 @ 00494170 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00494170(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = 0; local_8 < 10; local_8 = local_8 + 1) {
    (&DAT_004e8c30)[local_8] = 1;
  }
  return;
}

