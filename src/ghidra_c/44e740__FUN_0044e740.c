/* FUN_0044e740 @ 0044e740 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044e740(void)

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
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
  *(short *)(*(int *)(DAT_004f1578 + 4) + 0x10) = *(short *)(*(int *)(DAT_004f1578 + 4) + 0x10) + 1;
  FUN_00466510(8,FUN_0044e700);
  DAT_004f2c6e = 0xff;
  DAT_004f23f8 = FUN_0044e7c0;
  FUN_0044e7c0();
  uStack_8 = 0x44e7b6;
  __chkesp();
  return;
}

