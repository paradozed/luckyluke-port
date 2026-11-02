/* FUN_0044c640 @ 0044c640 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044c640(void)

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
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
       *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x14);
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x12) = 0;
  *(short *)(*(int *)(DAT_004f1578 + 4) + 0x10) = *(short *)(*(int *)(DAT_004f1578 + 4) + 0x10) + 1;
  DAT_004f23f8 = FUN_0044bf90;
  FUN_0044bf90();
  uStack_8 = 0x44c6c7;
  __chkesp();
  return;
}

