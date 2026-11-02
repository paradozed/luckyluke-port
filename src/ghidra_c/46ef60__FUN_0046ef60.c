/* FUN_0046ef60 @ 0046ef60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046ef60(int param_1)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_130 [16];
  int local_f0;
  uint local_ec [53];
  undefined4 local_18;
  ushort local_14;
  undefined2 uStack_12;
  uint local_10;
  undefined4 local_c;
  int local_8;
  
  uVar2 = DAT_004f2744;
  puVar4 = local_130;
  for (iVar3 = 0x4b; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_10 = local_10 & 0xffff0000;
  local_ec[0] = 0;
  local_ec[1] = 0;
  local_ec[2] = 0;
  local_ec[3] = 1;
  local_ec[4] = 0;
  local_ec[5] = 2;
  local_ec[6] = 0;
  local_ec[7] = 3;
  local_ec[8] = 1;
  local_ec[9] = 3;
  local_ec[10] = 2;
  local_ec[0xb] = 3;
  local_ec[0xc] = 4;
  local_ec[0xd] = 3;
  local_ec[0xe] = 6;
  local_ec[0xf] = 0;
  local_ec[0x10] = 6;
  local_ec[0x11] = 1;
  local_ec[0x12] = 6;
  local_ec[0x13] = 2;
  local_ec[0x14] = 6;
  local_ec[0x15] = 3;
  local_ec[0x16] = 7;
  local_ec[0x17] = 0;
  local_ec[0x18] = 7;
  local_ec[0x19] = 2;
  local_ec[0x1a] = 8;
  local_ec[0x1b] = 0;
  local_ec[0x1c] = 8;
  local_ec[0x1d] = 1;
  local_ec[0x1e] = 8;
  local_ec[0x1f] = 2;
  local_ec[0x20] = 10;
  local_ec[0x21] = 3;
  local_ec[0x22] = 0xc;
  local_ec[0x23] = 0;
  local_ec[0x24] = 0xc;
  local_ec[0x25] = 3;
  local_ec[0x26] = 0xd;
  local_ec[0x27] = 0;
  local_ec[0x28] = 0xd;
  local_ec[0x29] = 1;
  local_ec[0x2a] = 0xd;
  local_ec[0x2b] = 2;
  local_ec[0x2c] = 0xd;
  local_ec[0x2d] = 3;
  local_ec[0x2e] = 0xe;
  local_ec[0x2f] = 0;
  local_ec[0x30] = 0xe;
  local_ec[0x31] = 3;
  local_ec[0x32] = 0x10;
  local_ec[0x33] = 3;
  local_ec[0x34] = DAT_004f2744;
  if ((DAT_004e8701 == '\x01') && (DAT_004f2744 == 0xff10)) {
    DAT_004e8910 = '\x01';
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (((uVar2 & 0x800) == 0) || (DAT_004e8910 != '\x01')) {
    DAT_004e8910 = '\0';
    if ((*(int *)(param_1 + 8) == 0) && (uVar2 = FUN_004971c0(), (int)uVar2 % 100 == 0)) {
      *(undefined4 *)(param_1 + 8) = 9999;
      uVar2 = FUN_004971c0();
      uVar1 = ((ushort)uVar2 & 3) * 0x28 + 0x28;
      local_c = CONCAT22(local_c._2_2_,uVar1);
      if (*(int *)(param_1 + 0xc) < 1) {
        *(uint *)(param_1 + 0xc) = (uint)uVar1;
      }
      else {
        *(uint *)(param_1 + 0xc) = -(uint)uVar1;
      }
    }
    if (*(int *)(param_1 + 8) != 0) {
      local_8 = param_1 + 0x30;
      uVar1 = *(ushort *)(param_1 + 4);
      _local_14 = CONCAT22(uStack_12,uVar1);
      local_f0 = *(int *)(param_1 + 8);
      if (local_f0 == 0x270e) {
        local_18 = (uint)local_18._2_2_ << 0x10;
        local_c = (uint)local_c._2_2_ << 0x10;
        while ((local_c & 0xffff) < (uint)uVar1) {
          if (*(short *)(local_8 + 0x58) < *(short *)(local_8 + 0x5c)) {
            *(short *)(local_8 + 0x58) = *(short *)(local_8 + 0x58) + 1;
          }
          else if (*(short *)(local_8 + 0x5c) < *(short *)(local_8 + 0x58)) {
            *(short *)(local_8 + 0x58) = *(short *)(local_8 + 0x58) + -1;
          }
          else {
            local_18 = CONCAT22(local_18._2_2_,(short)local_18 + 1);
          }
          local_8 = local_8 + 100;
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
        }
        if ((uint)uVar1 == (local_18 & 0xffff)) {
          *(undefined4 *)(param_1 + 8) = 0;
        }
      }
      else if (local_f0 == 9999) {
        local_18 = (uint)local_18._2_2_ << 0x10;
        local_c = (uint)local_c._2_2_ << 0x10;
        while ((local_c & 0xffff) < (uint)uVar1) {
          if ((int)*(short *)(local_8 + 0x58) < *(int *)(param_1 + 0xc)) {
            *(short *)(local_8 + 0x58) = *(short *)(local_8 + 0x58) + 1;
          }
          else if (*(int *)(param_1 + 0xc) < (int)*(short *)(local_8 + 0x58)) {
            *(short *)(local_8 + 0x58) = *(short *)(local_8 + 0x58) + -1;
          }
          else {
            local_18 = CONCAT22(local_18._2_2_,(short)local_18 + 1);
          }
          local_8 = local_8 + 100;
          local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
        }
        if ((uint)uVar1 == (local_18 & 0xffff)) {
          uVar2 = FUN_004971c0();
          *(uint *)(param_1 + 8) = (uVar2 & 0x1f) + 0x14;
        }
      }
      else {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
        if (*(int *)(param_1 + 8) == 1) {
          *(undefined4 *)(param_1 + 8) = 0x270e;
        }
      }
    }
  }
  else {
    local_8 = param_1 + 0x30;
    uVar1 = *(ushort *)(param_1 + 4);
    _local_14 = CONCAT22(uStack_12,uVar1);
    local_18 = local_18 & 0xffff0000;
    local_c = local_c & 0xffff0000;
    while ((local_c & 0xffff) < (uint)uVar1) {
      *(short *)(local_8 + 0x50) =
           (short)local_ec[(local_10 & 0xffff) * 2] * 200 + 6000 +
           (short)*(undefined4 *)(param_1 + 0xc) * 0x1e;
      *(short *)(local_8 + 0x52) = (short)local_ec[(local_10 & 0xffff) * 2 + 1] * 200 + -4000;
      *(undefined2 *)(local_8 + 0x54) = 2000;
      local_8 = local_8 + 100;
      local_10 = CONCAT22(local_10._2_2_,(short)((ulonglong)((local_10 & 0xffff) + 1) % 0x1a));
      local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
    }
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  local_8 = 0x46f4b7;
  __chkesp();
  return;
}

