/* FUN_00466170 @ 00466170 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00466170(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [17];
  undefined4 local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_00456150(DAT_004f2438 & 0xaf);
  local_8 = CONCAT22(local_8._2_2_,(short)uVar1);
  if ((uVar1 & 0xffff) == 8) {
    FUN_0046a6e0(DAT_004f2458 + 0x2b,DAT_004f2458 + 0x2c,(int *)&DAT_004bdf00);
  }
  else {
    uVar1 = FUN_0046c310(*(short *)(&DAT_004bdf80 + (uVar1 & 0xffff) * 2),
                         *(short *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58));
    *(short *)(DAT_004f2458 + 0x29) = (short)uVar1;
    if ((DAT_004f2438 & 0x4000) == 0) {
      FUN_0046a6e0(DAT_004f2458 + 0x2b,DAT_004f2458 + 0x2c,(int *)&DAT_004bdf08);
    }
    else {
      FUN_0046a6e0(DAT_004f2458 + 0x2b,DAT_004f2458 + 0x2c,(int *)&DAT_004bdf10);
    }
  }
  local_8 = 0x466281;
  __chkesp();
  return;
}

