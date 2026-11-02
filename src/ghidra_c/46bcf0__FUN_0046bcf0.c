/* FUN_0046bcf0 @ 0046bcf0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046bcf0(void)

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
  *(uint *)(DAT_004f2458 + 0x10) = *(uint *)(DAT_004f2458 + 0x10) | 0x40;
  *(undefined4 *)(DAT_004f2458 + 0xb4) = 0;
  DAT_004f23f8 = FUN_0046bb80;
  FUN_0046bb80();
  uStack_8 = 0x46bd47;
  __chkesp();
  return;
}

