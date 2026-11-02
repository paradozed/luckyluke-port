/* FUN_0041a680 @ 0041a680 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041a680(void *param_1,void *param_2)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_b4 [16];
  int local_74;
  int *local_70;
  int local_6c;
  int local_68;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  ushort local_10;
  undefined4 local_c;
  int local_8;
  
  puVar6 = local_b4;
  for (iVar5 = 0x2c; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  sVar2 = FUN_004074b0(param_2,2);
  local_18 = sVar2 + 1;
  local_1c = *(int *)(DAT_004e8820 + local_18 * 4);
  local_8 = DAT_004e8820 + local_1c;
  DAT_004bc4e8 = *(short *)(local_8 + 10);
  DAT_004bc4ea = -*(short *)(local_8 + 0xc);
  DAT_004bc4ec = *(short *)(local_8 + 0xe);
  DAT_004e89f4 = *(short *)(local_8 + 4);
  DAT_004e89f6 = *(short *)(local_8 + 6);
  DAT_004e89f8 = *(short *)(local_8 + 8);
  DAT_004e89fa = DAT_004e89f4 * DAT_004e89f6 * DAT_004e89f8 + 1;
  DAT_004e89f0 = FUN_00494c40((DAT_004e89fa + 1) * 0x20,1);
  local_c = (uint)local_c._2_2_ << 0x10;
  while ((int)(short)local_c < (int)(DAT_004e89fa + 1)) {
    uVar4 = FUN_00494c40(40000,1);
    *(undefined4 *)(DAT_004e89f0 + 0x1c + (short)local_c * 0x20) = uVar4;
    *(undefined4 *)(DAT_004e89f0 + 0x18 + (short)local_c * 0x20) = 0;
    local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
  }
  FUN_0041a400();
  DAT_004e870c = 0;
  DAT_004e8710 = 0;
  DAT_004e8714 = 0;
  DAT_004d1ea8 = *(uint *)(local_8 + 4 + (uint)DAT_004bc4ee * 4);
  local_68 = local_8 + (uint)DAT_004bc4ee * 4;
  DAT_004d1e74 = local_68 + 0x10;
  _DAT_004d1ea4 = 0;
  _DAT_004d1ea0 = 0;
  DAT_004e85a4 = DAT_004d1ea8;
  while (*(int *)(local_68 + 0xc) != 0) {
    local_68 = local_68 + *(int *)(local_68 + 0xc);
    local_6c = local_68 + 0x10;
    local_c = (uint)local_c._2_2_ << 0x10;
    while ((local_c & 0xffff) < *(uint *)(local_68 + 4)) {
      *(int *)(local_68 + 0x24 + (short)local_c * 0x18) =
           local_8 + *(int *)(local_68 + 0x20 + (short)local_c * 0x18) * 4;
      local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
    }
  }
  local_c = (uint)local_c._2_2_ << 0x10;
  while ((local_c & 0xffff) < DAT_004d1ea8) {
    local_14 = local_8 + *(int *)(DAT_004d1e74 + 0x10 + (short)local_c * 0x18) * 4;
    *(int *)(DAT_004d1e74 + 0x14 + (short)local_c * 0x18) = local_14;
    *(short *)(local_14 + 4) = (short)local_c;
    if ((*(int *)(local_14 + 8) != 0) && (DAT_004f17e8 == '\0')) {
      *(int *)(local_14 + 8) =
           local_8 + *(int *)(DAT_004d1e74 + 0x10 + (*(int *)(local_14 + 8) + -1) * 0x18) * 4;
    }
    DAT_004e870c = DAT_004e870c + *(int *)(local_14 + 0x2c);
    if (*(int *)(local_14 + 8) == 0) {
      DAT_004e8710 = DAT_004e8710 + *(int *)(local_14 + 0x2c);
    }
    else {
      DAT_004e8714 = DAT_004e8714 + *(int *)(local_14 + 0x2c);
    }
    if (*(char *)(local_14 + 1) == '\x01') {
      local_10 = DAT_004e89fa;
      *(short *)(DAT_004e89f0 + (short)DAT_004e89fa * 0x20) =
           *(short *)(DAT_004e89f0 + (short)DAT_004e89fa * 0x20) + 1;
    }
    else {
      *(undefined4 *)(local_14 + 0x70) = *(undefined4 *)(local_14 + 0x90);
      *(undefined4 *)(local_14 + 0x74) = *(undefined4 *)(local_14 + 0x94);
      *(undefined4 *)(local_14 + 0x78) = *(undefined4 *)(local_14 + 0x98);
      local_20 = *(int *)(local_14 + 0xa4);
      local_28 = *(int *)(local_14 + 0xa8);
      local_30 = *(int *)(local_14 + 0xac);
      local_24 = *(int *)(local_14 + 0xb0);
      local_2c = *(int *)(local_14 + 0xb4);
      local_34 = *(int *)(local_14 + 0xb8);
      local_38 = local_24 - local_20;
      local_3c = local_2c - local_28;
      local_40 = local_34 - local_30;
      if (*(short *)(local_14 + 0x80) == -0x1000) {
        *(int *)(local_14 + 0x90) = *(int *)(local_14 + 0x90) - local_38;
      }
      else if (*(short *)(local_14 + 0x7c) == -0x1000) {
        *(int *)(local_14 + 0x90) = *(int *)(local_14 + 0x90) - local_38;
        *(int *)(local_14 + 0x98) = *(int *)(local_14 + 0x98) - local_40;
      }
      else if (*(short *)(local_14 + 0x80) == 0x1000) {
        *(int *)(local_14 + 0x98) = *(int *)(local_14 + 0x98) - local_40;
      }
      *(int *)(local_14 + 0x90) = *(int *)(local_14 + 0x90) + local_38 / 2;
      *(int *)(local_14 + 0x98) = *(int *)(local_14 + 0x98) + local_40 / 2;
      local_10 = FUN_0041af80(local_14);
      if (local_10 != 0xffff) {
        *(short *)(DAT_004e89f0 + (short)local_10 * 0x20) =
             *(short *)(DAT_004e89f0 + (short)local_10 * 0x20) + 1;
      }
    }
    local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
  }
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_00458ec0();
  FUN_0041a500();
  local_c = local_c & 0xffff0000;
  while (uVar1 = DAT_004e89fa, (local_c & 0xffff) < DAT_004d1ea8) {
    local_14 = *(int *)(DAT_004d1e74 + 0x14 + (short)local_c * 0x18);
    if (*(char *)(local_14 + 1) == '\x01') {
      local_10 = DAT_004e89fa;
      *(int *)(*(int *)(DAT_004e89f0 + 0x14 + (short)DAT_004e89fa * 0x20) +
              (uint)*(ushort *)(DAT_004e89f0 + (short)DAT_004e89fa * 0x20) * 4) = local_14;
      *(short *)(DAT_004e89f0 + (short)uVar1 * 0x20) =
           *(short *)(DAT_004e89f0 + (short)uVar1 * 0x20) + 1;
    }
    else {
      local_10 = FUN_0041af80(local_14);
      if (-1 < (short)local_10) {
        local_4c = *(undefined4 *)(local_14 + 0x70);
        local_48 = *(undefined4 *)(local_14 + 0x74);
        local_44 = *(undefined4 *)(local_14 + 0x78);
        iVar5 = FUN_0041aec0(local_14);
        *(int *)(local_14 + 0x70) =
             *(int *)(local_14 + 0x70) - (int)(short)iVar5 * (int)DAT_004bc4e8;
        iVar5 = FUN_0041af00(local_14);
        *(int *)(local_14 + 0x74) =
             *(int *)(local_14 + 0x74) - (int)(short)iVar5 * (int)DAT_004bc4ea;
        iVar5 = FUN_0041af40(local_14);
        *(int *)(local_14 + 0x78) =
             *(int *)(local_14 + 0x78) - (int)(short)iVar5 * (int)DAT_004bc4ec;
        *(undefined4 *)(local_14 + 0x90) = local_4c;
        *(undefined4 *)(local_14 + 0x94) = local_48;
        *(undefined4 *)(local_14 + 0x98) = local_44;
        *(int *)(*(int *)(DAT_004e89f0 + 0x14 + (short)local_10 * 0x20) +
                (uint)*(ushort *)(DAT_004e89f0 + (short)local_10 * 0x20) * 4) = local_14;
        *(short *)(DAT_004e89f0 + (short)local_10 * 0x20) =
             *(short *)(DAT_004e89f0 + (short)local_10 * 0x20) + 1;
      }
    }
    local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
  }
  local_70 = (int *)FUN_00439a90(DAT_004e85ec,0x74);
  _memset(local_70,0,0x74);
  *local_70 = local_8;
  *(undefined2 *)(local_70 + 6) = 0;
  local_74 = FUN_004714a0(DAT_004f1e24);
  uVar3 = FUN_004074b0(param_2,3);
  *(undefined2 *)(local_74 + 0xc) = uVar3;
  *(code **)(local_74 + 4) = FUN_004799a0;
  *(undefined1 *)(local_74 + 0x10) = 1;
  *(undefined1 *)(local_74 + 0x11) = 0;
  *(int **)(local_74 + 8) = local_70;
  *(undefined1 *)(local_74 + 0x12) = 0;
  *(undefined1 *)(local_74 + 0x13) = 0;
  *(undefined1 *)(local_74 + 0x14) = 1;
  *(undefined1 *)(local_74 + 0x15) = 0;
  *(undefined1 *)(local_74 + 0x16) = 0;
  *(undefined1 *)(local_74 + 0x17) = 0;
  FUN_00412c50(param_1,local_74);
  FUN_00412ee0(param_1,FUN_0041a1b0);
  DAT_004f17e8 = 0;
  _DAT_004f289c = 0;
  FUN_00418730();
  FUN_0042f940();
  local_8 = 0x41aeb2;
  __chkesp();
  return;
}

