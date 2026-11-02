/* FUN_004810e0 @ 004810e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004810e0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_88 [16];
  int local_48;
  short local_44;
  short local_40;
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
  
  puVar2 = local_88;
  for (iVar1 = 0x21; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004e8988 != 0) && (*(int *)(param_1 + 0xcc) != 0)) {
    FUN_00485430(param_1);
  }
  if (*(int *)(param_1 + 200) != 0) {
    FUN_00481af0(param_1);
  }
  if (DAT_005081a1 == '\0') {
    local_c = *(short *)(param_1 + 0x70);
    local_a = *(undefined2 *)(param_1 + 0x74);
    local_8 = CONCAT22(local_8._2_2_,*(undefined2 *)(param_1 + 0x78));
    FUN_00482820((undefined4 *)&DAT_00508180,&local_c,&local_28);
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
  FUN_004823a0((undefined4 *)&DAT_004c6418);
  FUN_004824a0((int)local_3c);
  FUN_0047fa00(*(int *)(*(int *)(param_1 + 0x20) + 4),*(int *)(param_1 + 0xc0),
               *(int *)(param_1 + 0x10));
  if (DAT_005081a0 != '\0') {
    local_44 = *(short *)(param_1 + 0x10);
    local_48 = *(int *)(param_1 + 0xc0);
    local_40 = local_44;
    if (*DAT_00507f38 == '\0') {
      while (local_40 = local_40 + -1, -1 < local_40) {
        *(short *)(local_48 + 2 + local_40 * 8) =
             *(short *)(local_48 + 2 + local_40 * 8) +
             (short)((int)*(short *)(&DAT_004c6534 +
                                    ((uint)*(ushort *)(local_48 + local_40 * 8) +
                                     *(int *)(local_48 + 4 + local_40 * 8) +
                                     (uint)*(ushort *)(DAT_00507f38 + 10) & 0x3ff) * 2) /
                    (int)(uint)*(ushort *)(DAT_00507f38 + 8));
      }
    }
    else {
      while (local_40 = local_40 + -1, -1 < local_40) {
        *(short *)(local_48 + local_40 * 8) =
             *(short *)(local_48 + local_40 * 8) +
             (short)((int)*(short *)(&DAT_004c6534 +
                                    ((uint)*(ushort *)(local_48 + 2 + local_40 * 8) +
                                     *(int *)(local_48 + 4 + local_40 * 8) +
                                     (uint)*(ushort *)(DAT_00507f38 + 10) & 0x3ff) * 2) /
                    (int)(uint)*(ushort *)(DAT_00507f38 + 8));
      }
    }
  }
  local_8 = 0x48135b;
  __chkesp();
  return;
}

