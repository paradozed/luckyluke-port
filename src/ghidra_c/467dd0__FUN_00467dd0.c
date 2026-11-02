/* FUN_00467dd0 @ 00467dd0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00467dd0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [20];
  undefined4 uStack_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)(DAT_004f2458 + 0xb4) = 0x40;
  DAT_004f2400 = FUN_00465e70;
  *(uint *)(DAT_004f2458 + 0x10) = *(uint *)(DAT_004f2458 + 0x10) & 0xffffffdf;
  *(uint *)(DAT_004f2458 + 0x10) = *(uint *)(DAT_004f2458 + 0x10) | 0x40;
  FUN_00466510(0x12,FUN_00467bb0);
  DAT_004f23f8 = FUN_00467bd0;
  FUN_00467bd0();
  uStack_8 = 0x467e54;
  __chkesp();
  return;
}

