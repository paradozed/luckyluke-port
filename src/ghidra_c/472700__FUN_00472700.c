/* FUN_00472700 @ 00472700 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00472700(void)

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
  for (local_8 = 0; local_8 < 2; local_8 = local_8 + 1) {
    if ((*(int *)(&DAT_004f1820 + local_8 * 4) != 0) &&
       (*(int *)(&DAT_004f1820 + local_8 * 4) != -0x22222223)) {
      FUN_00495280(*(void **)(&DAT_004f1820 + local_8 * 4));
    }
  }
  DAT_004e8974 = 0;
  local_8 = 0x472776;
  __chkesp();
  return;
}

