/* FUN_00480ee0 @ 00480ee0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00480ee0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_70 [16];
  int local_30;
  short local_2c;
  short local_28;
  undefined4 local_24 [7];
  undefined4 uStack_8;
  
  puVar2 = local_70;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_005081a1 == '\0') {
    FUN_00482640((undefined4 *)&DAT_00508180,param_1 + 0x5c,local_24);
  }
  else {
    FUN_00480e20((undefined4 *)&DAT_00508180,param_1 + 0x5c,local_24);
  }
  FUN_004823a0(local_24);
  FUN_004824a0((int)local_24);
  FUN_0047fa00(*(int *)(*(int *)(param_1 + 0x20) + 4),*(int *)(param_1 + 0xc0),
               *(int *)(param_1 + 0x10));
  if (DAT_005081a0 != '\0') {
    if (*(int *)(param_1 + 0x14) == 0) {
      local_2c = *(short *)(param_1 + 0x10);
    }
    else {
      local_2c = *(short *)(param_1 + 0x14);
    }
    local_30 = *(int *)(param_1 + 0xc0);
    local_28 = local_2c;
    if (*DAT_00507f38 == '\0') {
      while (local_28 = local_28 + -1, -1 < local_28) {
        *(short *)(local_30 + 2 + local_28 * 8) =
             *(short *)(local_30 + 2 + local_28 * 8) +
             (short)((int)*(short *)(&DAT_004c6534 +
                                    ((uint)*(ushort *)(local_30 + local_28 * 8) +
                                     *(int *)(local_30 + 4 + local_28 * 8) +
                                     (uint)*(ushort *)(DAT_00507f38 + 10) & 0x3ff) * 2) /
                    (int)(uint)*(ushort *)(DAT_00507f38 + 8));
      }
    }
    else {
      while (local_28 = local_28 + -1, -1 < local_28) {
        *(short *)(local_30 + local_28 * 8) =
             *(short *)(local_30 + local_28 * 8) +
             (short)((int)*(short *)(&DAT_004c6534 +
                                    ((uint)*(ushort *)(local_30 + 2 + local_28 * 8) +
                                     *(int *)(local_30 + 4 + local_28 * 8) +
                                     (uint)*(ushort *)(DAT_00507f38 + 10) & 0x3ff) * 2) /
                    (int)(uint)*(ushort *)(DAT_00507f38 + 8));
      }
    }
  }
  uStack_8 = 0x4810d2;
  __chkesp();
  return;
}

