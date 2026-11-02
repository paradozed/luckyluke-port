/* FUN_004817d0 @ 004817d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004817d0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_8c [17];
  undefined1 local_48 [20];
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  short local_24;
  short local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  short local_c;
  undefined2 local_a;
  undefined4 local_8;
  
  puVar2 = local_8c;
  for (iVar1 = 0x22; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_004823a0((undefined4 *)&DAT_00508180);
  FUN_004824a0(0x4c63f8);
  if (DAT_005081a1 == '\0') {
    local_c = *(short *)(param_1 + 0x70);
    local_a = *(undefined2 *)(param_1 + 0x74);
    local_8 = CONCAT22(local_8._2_2_,*(undefined2 *)(param_1 + 0x78));
    FUN_004826e0(&local_c,&local_34);
  }
  else {
    local_1c = *(int *)(param_1 + 0x70);
    local_18 = *(undefined4 *)(param_1 + 0x74);
    local_14 = *(undefined4 *)(param_1 + 0x78);
    FUN_00482760((undefined4 *)&DAT_00508180,&local_1c,&local_34);
  }
  local_34 = local_34 + DAT_00508194;
  local_30 = local_30 + DAT_00508198;
  local_2c = local_2c + DAT_0050819c;
  FUN_004824a0((int)local_48);
  FUN_0047fa00(*(int *)(param_1 + 0xbc) + 0x10,*(int *)(param_1 + 0xc0) + 0x10,
               *(int *)(param_1 + 0x14) + -2);
  local_24 = *(short *)(param_1 + 0x14) + -2;
  iVar1 = *(int *)(param_1 + 0xc0);
  local_28 = iVar1 + 0x10;
  for (local_20 = *(short *)(param_1 + 0x14) + -3; -1 < local_20; local_20 = local_20 + -1) {
    *(short *)(local_28 + local_20 * 8) =
         *(short *)(local_28 + local_20 * 8) +
         (*(short *)(&DAT_004c6534 +
                    ((uint)*(ushort *)(iVar1 + 0x12 + local_20 * 8) +
                     *(int *)(iVar1 + 0x14 + local_20 * 8) + (DAT_004e8abc >> 4) & 0x3f) * 0x20) >>
         7);
  }
  local_8 = 0x481976;
  __chkesp();
  return;
}

