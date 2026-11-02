/* FUN_00481570 @ 00481570 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00481570(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_8c [16];
  int local_4c;
  short local_48;
  short local_44;
  undefined1 local_3c [20];
  int local_28;
  int local_24;
  int local_20;
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
    FUN_004826e0(&local_c,&local_28);
  }
  else {
    local_1c = *(int *)(param_1 + 0x70);
    local_18 = *(undefined4 *)(param_1 + 0x74);
    local_14 = *(undefined4 *)(param_1 + 0x78);
    FUN_00482760((undefined4 *)&DAT_00508180,&local_1c,&local_28);
  }
  local_28 = local_28 + DAT_00508194;
  local_24 = local_24 + DAT_00508198;
  local_20 = local_20 + DAT_0050819c;
  FUN_004824a0((int)local_3c);
  FUN_0047fa00(*(int *)(param_1 + 0xbc) + 0x10,*(int *)(param_1 + 0xc0) + 0x10,
               *(int *)(param_1 + 0x14) + -2);
  if (DAT_005081a0 != '\0') {
    local_44 = *(short *)(param_1 + 0x14);
    local_48 = local_44 + -2;
    iVar1 = *(int *)(param_1 + 0xc0);
    local_4c = iVar1 + 0x10;
    if (*DAT_00507f38 == '\0') {
      for (local_44 = local_44 + -3; -1 < local_44; local_44 = local_44 + -1) {
        *(short *)(iVar1 + 0x12 + local_44 * 8) =
             *(short *)(iVar1 + 0x12 + local_44 * 8) +
             (short)((int)*(short *)(&DAT_004c6534 +
                                    ((uint)*(ushort *)(local_4c + local_44 * 8) +
                                     *(int *)(iVar1 + 0x14 + local_44 * 8) +
                                     (uint)*(ushort *)(DAT_00507f38 + 10) & 0x3ff) * 2) /
                    (int)(uint)*(ushort *)(DAT_00507f38 + 8));
      }
    }
    else {
      for (local_44 = local_44 + -3; -1 < local_44; local_44 = local_44 + -1) {
        *(short *)(local_4c + local_44 * 8) =
             *(short *)(local_4c + local_44 * 8) +
             (short)((int)*(short *)(&DAT_004c6534 +
                                    ((uint)*(ushort *)(iVar1 + 0x12 + local_44 * 8) +
                                     *(int *)(iVar1 + 0x14 + local_44 * 8) +
                                     (uint)*(ushort *)(DAT_00507f38 + 10) & 0x3ff) * 2) /
                    (int)(uint)*(ushort *)(DAT_00507f38 + 8));
      }
    }
  }
  local_8 = 0x4817ca;
  __chkesp();
  return;
}

