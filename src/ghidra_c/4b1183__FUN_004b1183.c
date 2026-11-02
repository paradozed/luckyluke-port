/* FUN_004b1183 @ 004b1183 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004b1183(void)

{
  int iVar1;
  undefined4 local_8;
  
  if (DAT_004c84b8 != 0) {
    local_8 = DAT_004c84b8;
    while (local_8 != 0) {
      DAT_004c84b8 = local_8;
      iVar1 = *(int *)(local_8 + 0x88);
      FUN_004b1ae0(local_8);
      local_8 = iVar1;
    }
    DAT_004c84b8 = 0;
  }
  return;
}

