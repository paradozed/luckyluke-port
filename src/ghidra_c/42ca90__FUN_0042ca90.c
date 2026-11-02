/* FUN_0042ca90 @ 0042ca90 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042ca90(void)

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
  if (DAT_004e8320 != 0) {
    for (local_8 = 0; local_8 < DAT_004e8320; local_8 = local_8 + 1) {
      FUN_0042c280(**(int **)(&DAT_004f7140 + local_8 * 4),
                   *(int *)(*(int *)(&DAT_004f7140 + local_8 * 4) + 4),
                   (byte *)(*(int *)(&DAT_004f7140 + local_8 * 4) + 8));
    }
    DAT_004e8320 = 0;
  }
  local_8 = 0x42cb1a;
  __chkesp();
  return;
}

