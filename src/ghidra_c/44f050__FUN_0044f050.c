/* FUN_0044f050 @ 0044f050 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044f050(void)

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
  DAT_004e8580 = 0;
  *(undefined2 *)(*(int *)(DAT_004f1578 + 4) + 0x36) = 0;
  *(short *)(*(int *)(DAT_004f1578 + 4) + 0x30) = *(short *)(*(int *)(DAT_004f1578 + 4) + 0x30) + 1;
  DAT_004f2c60 = FUN_0044ec70;
  FUN_0044ec70();
  uStack_8 = 0x44f0b7;
  __chkesp();
  return;
}

