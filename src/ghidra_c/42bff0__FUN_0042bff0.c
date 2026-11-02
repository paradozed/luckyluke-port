/* FUN_0042bff0 @ 0042bff0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042bff0(void)

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
  if (DAT_004e831c != 0) {
    FUN_0042be50();
    (*DAT_004e8a30)();
    __chkesp();
    FUN_004442e0((int *)&DAT_004f7310,9,9,9,9);
  }
  uStack_8 = 0x42c047;
  __chkesp();
  return;
}

