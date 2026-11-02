/* FUN_0042c7f0 @ 0042c7f0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042c7f0(void)

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
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    if ((*(int *)(&DAT_004f6140 + local_8 * 4) != 0) &&
       (*(int *)(&DAT_004f6140 + local_8 * 4) != -0x22222223)) {
      FUN_00495280(*(void **)(&DAT_004f6140 + local_8 * 4));
    }
  }
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    if ((*(int *)(&DAT_004f6544 + local_8 * 0xc) != 0) &&
       (*(int *)(&DAT_004f6544 + local_8 * 0xc) != -0x22222223)) {
      FUN_00495280(*(void **)(&DAT_004f6544 + local_8 * 0xc));
    }
  }
  local_8 = 0x42c8b5;
  __chkesp();
  return;
}

