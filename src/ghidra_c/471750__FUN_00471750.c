/* FUN_00471750 @ 00471750 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00471750(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  int *local_10;
  uint local_c;
  uint local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = (uint)*(ushort *)(DAT_004f1e24 + 1);
  for (local_8 = 0; local_8 < local_c; local_8 = local_8 + 1) {
    local_10 = *(int **)(*DAT_004f1e24 + local_8 * 4);
    if (((local_10 != (int *)0x0) && ((char)local_10[4] != '\0')) &&
       ((code *)*local_10 == FUN_004743d0)) {
      (*(code *)local_10[1])(local_10);
      __chkesp();
    }
  }
  if (DAT_004e8988 != 0) {
    FUN_00477930();
  }
  local_8 = 0x4717f7;
  __chkesp();
  return;
}

