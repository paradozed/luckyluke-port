/* FUN_00466fe0 @ 00466fe0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00466fe0(void)

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
  uVar1 = FUN_0046c310((short)DAT_004f2458[0x29],*(short *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58));
  *(short *)(DAT_004f2458 + 0x29) = (short)uVar1;
  if ((DAT_004f2458[4] & 0x20U) == 0) {
    DAT_004f2458[4] = DAT_004f2458[4] & 0xffffe1ff;
    DAT_004f23f8 = FUN_00467dd0;
    FUN_00467dd0();
  }
  else if ((DAT_004f245c & 0x8000) != 0) {
    DAT_004f23f8 = FUN_00467950;
    FUN_00467950();
  }
  uStack_8 = 0x467091;
  __chkesp();
  return;
}

