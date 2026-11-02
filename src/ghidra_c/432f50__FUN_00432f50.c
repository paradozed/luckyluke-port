/* FUN_00432f50 @ 00432f50 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00432f50(void)

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
  for (local_8 = 0; local_8 < DAT_004e8490; local_8 = local_8 + 1) {
    if ((&DAT_004f5d80)[local_8] != 0) {
      if ((&DAT_004f5d80)[local_8] != -0x22222223) {
        FUN_00495280((void *)(&DAT_004f5d80)[local_8]);
      }
      (&DAT_004f5d80)[local_8] = 0;
    }
  }
  local_8 = 0x432fd2;
  __chkesp();
  return;
}

