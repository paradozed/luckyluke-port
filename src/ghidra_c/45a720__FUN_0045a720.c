/* FUN_0045a720 @ 0045a720 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0045a720(void)

{
  int iVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 local_60 [16];
  int local_20;
  ushort *local_1c;
  ushort *local_18;
  ushort *local_14;
  ushort *local_10;
  uint local_c;
  undefined4 local_8;
  
  puVar3 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  FUN_004823a0((undefined4 *)&DAT_00508180);
  FUN_004824a0(0x508180);
  FUN_0047fa00(DAT_004f2ac8,DAT_004f2abc,0xa9);
  for (uVar2 = 0; uVar2 < 0xc; uVar2 = uVar2 + 1) {
    local_c = local_c & 0xffff0000;
    while ((local_c & 0xffff) < 0xc) {
      local_20 = (&DAT_004f2ac0)[DAT_004e89d8] + ((uint)uVar2 * 0xc + (local_c & 0xffff)) * 0x1c;
      local_10 = (ushort *)(DAT_004f2abc + (uint)uVar2 * 0x68 + (local_c & 0xffff) * 8);
      local_14 = (ushort *)(DAT_004f2abc + (uint)uVar2 * 0x68 + 8 + (local_c & 0xffff) * 8);
      local_1c = (ushort *)(DAT_004f2abc + (uVar2 + 1) * 0x68 + (local_c & 0xffff) * 8);
      local_18 = (ushort *)(DAT_004f2abc + (uVar2 + 1) * 0x68 + 8 + (local_c & 0xffff) * 8);
      if (((((((0xfc00 < *local_10) || (*local_10 < 0x3ff)) &&
             ((0xfc00 < *local_14 || (*local_14 < 0x3ff)))) &&
            ((0xfc00 < *local_18 || (*local_18 < 0x3ff)))) &&
           ((0xfc00 < *local_1c || (*local_1c < 0x3ff)))) &&
          ((((0xfc00 < local_10[1] || (local_10[1] < 0x3ff)) &&
            ((0xfc00 < local_14[1] || (local_14[1] < 0x3ff)))) &&
           ((0xfc00 < local_18[1] || (local_18[1] < 0x3ff)))))) &&
         ((0xfc00 < local_1c[1] || (local_1c[1] < 0x3ff)))) {
        *(ushort *)(local_20 + 8) = *local_10;
        *(ushort *)(local_20 + 10) = local_10[1];
        *(ushort *)(local_20 + 0xc) = *local_14;
        *(ushort *)(local_20 + 0xe) = local_14[1];
        *(ushort *)(local_20 + 0x10) = *local_18;
        *(ushort *)(local_20 + 0x12) = local_18[1];
        *(ushort *)(local_20 + 0x14) = *local_1c;
        *(ushort *)(local_20 + 0x16) = local_1c[1];
      }
      local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
    }
  }
  local_8 = 0x45aa1b;
  __chkesp();
  return;
}

