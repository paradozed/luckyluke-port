/* FUN_00437ad0 @ 00437ad0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00437ad0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  void *local_c;
  void *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e84d4 != (int *)0x0) {
    local_8 = (void *)*DAT_004e84d4;
    while (local_8 != (void *)0x0) {
      local_c = *(void **)((int)local_8 + 4);
      FUN_00438540();
      FUN_00495280(local_8);
      local_8 = local_c;
    }
    FUN_00495280(DAT_004e84d4);
  }
  FUN_00438130();
  if (DAT_004e84cc != (int *)0x0) {
    FUN_00497b30(DAT_004e84cc);
  }
  DAT_004e84c8 = 0;
  local_8 = (void *)0x437b76;
  __chkesp();
  return;
}

