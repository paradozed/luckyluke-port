/* FUN_0044fd50 @ 0044fd50 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044fd50(void)

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
  DAT_004e8610 = 0;
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x16) = 0;
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x12) = 0;
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x10) = 0;
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
       *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x14);
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x32) = 0;
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x30) = 0;
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x38) =
       *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x14);
  DAT_004f2c6f = 0;
  DAT_004f2c78 = 0;
  DAT_004e861e = 0;
  DAT_004e861f = 0;
  DAT_004f2c6c = DAT_004f2800;
  DAT_004f23f8 = FUN_0044fe50;
  FUN_0044fe50();
  uStack_8 = 0x44fe45;
  __chkesp();
  return;
}

