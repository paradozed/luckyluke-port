/* FUN_00465a60 @ 00465a60 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00465a60(void)

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
  FUN_0046a6e0((int *)(DAT_004f2458 + 0xac),(int *)(DAT_004f2458 + 0xb0),(int *)&DAT_004bdf00);
  uStack_8 = 0x465aaa;
  __chkesp();
  return;
}

