/* FUN_00443b00 @ 00443b00 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00443b00(void)

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
  if ((DAT_004e8574 != (void *)0x0) && (DAT_004e8574 != (void *)0xdddddddd)) {
    FUN_00495280(DAT_004e8574);
  }
  local_8 = DAT_004e8578;
  while (local_8 != (void *)0x0) {
    local_c = *(void **)((int)local_8 + 0x10);
    if (*(int *)((int)local_8 + 4) != -0x22222223) {
      FUN_00495280(*(void **)((int)local_8 + 4));
    }
    if (local_8 != (void *)0xdddddddd) {
      FUN_00495280(local_8);
    }
    local_8 = local_c;
  }
  DAT_004e8578 = (void *)0x0;
  DAT_004e8574 = (void *)0x0;
  local_8 = (void *)0x443bb5;
  __chkesp();
  return;
}

