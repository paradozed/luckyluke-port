/* FUN_00449380 @ 00449380 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00449380(void)

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
  (*DAT_004e8a0c)();
  __chkesp();
  uStack_8 = 0x4493b4;
  __chkesp();
  return;
}

