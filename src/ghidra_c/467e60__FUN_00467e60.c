/* FUN_00467e60 @ 00467e60 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00467e60(void)

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
  *(undefined4 *)(DAT_004f2458 + 0xb4) = 0;
  *(uint *)(DAT_004f2458 + 0x10) = *(uint *)(DAT_004f2458 + 0x10) | 0x40;
  DAT_004f23f8 = FUN_00467bd0;
  FUN_00467bd0();
  uStack_8 = 0x467eb7;
  __chkesp();
  return;
}

