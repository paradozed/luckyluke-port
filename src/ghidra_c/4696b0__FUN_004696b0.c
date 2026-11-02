/* FUN_004696b0 @ 004696b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004696b0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_64 [16];
  int local_24;
  undefined4 local_20;
  short local_1c;
  short local_10;
  ushort local_c;
  undefined4 local_8;
  
  puVar3 = local_64;
  for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_00456150(DAT_004f2438);
  local_8 = CONCAT22(local_8._2_2_,(short)uVar1);
  if ((uVar1 & 0xffff) != 8) {
    local_10 = *(short *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58);
    if (((DAT_004e868a & 0xfff) < 0xc01) && (0x3ff < (DAT_004e868a & 0xfff))) {
      local_20 = 0x800;
    }
    else {
      local_20 = 0;
    }
    local_c = *(short *)(&DAT_004bdf80 + (uVar1 & 0xffff) * 2) + (short)local_20 & 0xfff;
    if ((int)(short)local_c - (int)local_10 < 0) {
      local_24 = -((int)(short)local_c - (int)local_10);
    }
    else {
      local_24 = (int)(short)local_c - (int)local_10;
    }
    local_1c = (short)local_24;
    if ((((short)local_24 < 0x2ab) || (0x554 < (short)local_24)) &&
       (((short)local_24 < 0xaab || (0xd54 < (short)local_24)))) {
      uVar1 = FUN_0046c310(*(short *)(&DAT_004bdf80 + (uVar1 & 0xffff) * 2) + (short)local_20 &
                           0xfff,local_10);
      local_c = (ushort)uVar1;
      *(ushort *)(DAT_004f2458 + 0x29) = local_c;
      FUN_00467440(*DAT_004f2458,0,local_c,0);
    }
    else {
      FUN_00469410(DAT_004f2458);
    }
  }
  local_8 = 0x469844;
  __chkesp();
  return;
}

