/* FUN_00467550 @ 00467550 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00467550(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar3 = local_44;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_0046c310(0x400,*(short *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58));
  *(short *)(DAT_004f2458 + 0x29) = (short)uVar1;
  FUN_00467440(*DAT_004f2458,0,(short)DAT_004f2458[0x29],0);
  DAT_004f2458[0x2d] = -0x80;
  DAT_004f2400 = FUN_00466120;
  DAT_004f2458[4] = DAT_004f2458[4] & 0xffffffdf;
  FUN_00466510(0xf,FUN_00467620);
  DAT_004f23f8 = FUN_00467660;
  FUN_00467660();
  uStack_8 = 0x46760f;
  __chkesp();
  return;
}

