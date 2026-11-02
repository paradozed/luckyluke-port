/* FUN_00443890 @ 00443890 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00443890(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while (DAT_004e8564 != (void *)0x0) {
    FUN_00443740(DAT_004e8564);
  }
  uStack_8 = 0x4438ce;
  __chkesp();
  return;
}

