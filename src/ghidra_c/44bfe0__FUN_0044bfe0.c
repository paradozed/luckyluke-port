/* FUN_0044bfe0 @ 0044bfe0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044bfe0(void)

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
  if (DAT_004e8813 == '\0') {
    DAT_004e8813 = '\x01';
    DAT_004f2c6c = DAT_004f2800;
  }
  if (DAT_004e8622 != '\0') {
    FUN_0044cbb0();
  }
  if (DAT_004e861c == '\0') {
    if ((int)(uint)DAT_004bd054 < (int)*(short *)(*(int *)(DAT_004f1578 + 4) + 0x16)) {
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
           *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x14);
      DAT_004f23f8 = FUN_0044c1b0;
      FUN_0044c1b0();
    }
    if (*(short *)(*(int *)(DAT_004f1578 + 4) + 0x18) < 1) {
      *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x18) =
           *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x14);
    }
  }
  else {
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x32) = 0;
    DAT_004f2c60 = FUN_0044d830;
    DAT_004f23f8 = FUN_0044ca30;
    FUN_0044ca30();
  }
  uStack_8 = 0x44c0e4;
  __chkesp();
  return;
}

