/* FUN_0044dec0 @ 0044dec0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044dec0(void)

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
  if (*(ushort *)(*(int *)(DAT_004f1578 + 4) + 0x10) < 0xb) {
    FUN_0044cbb0();
    if (DAT_004e8610 != '\0') {
      DAT_004e8610 = '\0';
      DAT_004f23f8 = FUN_0044dfa0;
      FUN_0044dfa0();
    }
  }
  else {
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x10) = 0;
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x30) = 0;
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x32) = 0;
    *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x12) = 0;
    DAT_004f2c60 = FUN_0044f330;
    DAT_004f23f8 = FUN_0044e8e0;
    FUN_0044e8e0();
  }
  uStack_8 = 0x44df94;
  __chkesp();
  return;
}

