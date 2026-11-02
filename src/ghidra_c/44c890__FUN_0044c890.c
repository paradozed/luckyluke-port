/* FUN_0044c890 @ 0044c890 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044c890(void)

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
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x12) = 0;
  if (DAT_004e861c == '\0') {
    DAT_004f23f8 = FUN_0044bf90;
    FUN_0044bf90();
  }
  else {
    DAT_004f2c60 = FUN_0044d830;
    DAT_004f23f8 = FUN_0044ca30;
    FUN_0044ca30();
  }
  uStack_8 = 0x44c908;
  __chkesp();
  return;
}

