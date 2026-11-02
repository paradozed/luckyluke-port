/* FUN_0041f020 @ 0041f020 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041f020(uint param_1,uint param_2,ushort param_3,short param_4,short param_5)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  undefined2 uVar5;
  ushort uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 local_a0 [16];
  int local_60;
  int local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  short local_4c;
  uint local_48;
  ushort local_44;
  undefined2 uStack_42;
  undefined2 local_40;
  undefined2 uStack_3e;
  ushort local_3c;
  undefined2 uStack_3a;
  uint local_38;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_1c;
  int local_18;
  int local_14;
  int local_c;
  int local_8;
  
  puVar8 = local_a0;
  for (iVar7 = 0x27; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = 0xcccccccc;
    puVar8 = puVar8 + 1;
  }
  local_8 = **(int **)(*(int *)(&DAT_004f1e40 + (param_1 & 0xffff) * 4) + 8);
  local_1c = *(int *)(local_8 + 0x90);
  local_18 = *(int *)(local_8 + 0x94);
  local_14 = *(int *)(local_8 + 0x98);
  local_c = **(int **)(*(int *)(&DAT_004f1e40 + (param_2 & 0xffff) * 4) + 8);
  local_2c = *(int *)(local_c + 0x90);
  local_28 = *(int *)(local_c + 0x94);
  local_24 = *(int *)(local_c + 0x98);
  if (local_2c - local_1c < 0) {
    local_50 = -(local_2c - local_1c);
  }
  else {
    local_50 = local_2c - local_1c;
  }
  local_30 = local_50;
  uVar4 = local_30;
  if (local_28 - local_18 < 0) {
    local_54 = -(local_28 - local_18);
  }
  else {
    local_54 = local_28 - local_18;
  }
  local_34 = local_54;
  uVar2 = local_34;
  if (local_24 - local_14 < 0) {
    local_58 = -(local_24 - local_14);
  }
  else {
    local_58 = local_24 - local_14;
  }
  local_38 = local_58;
  uVar1 = local_38;
  local_30._0_2_ = (ushort)local_50;
  uVar3 = (ushort)local_30;
  _local_3c = CONCAT22(uStack_3a,(ushort)local_30);
  local_34._0_2_ = (undefined2)local_54;
  _local_40 = CONCAT22(uStack_3e,(undefined2)local_34);
  local_38._0_2_ = (ushort)local_58;
  uVar6 = (ushort)local_38;
  _local_44 = CONCAT22(uStack_42,(ushort)local_38);
  local_38 = uVar1;
  local_34 = uVar2;
  local_30 = uVar4;
  if ((((local_50 & 0xffff) < local_50) || ((local_54 & 0xffff) < local_54)) ||
     ((local_58 & 0xffff) < local_58)) {
    local_48 = CONCAT22(local_48._2_2_,0xffff);
  }
  else {
    uVar5 = FUN_00420320(uVar3,local_54 & 0xffff,uVar6);
    local_48 = CONCAT22(local_48._2_2_,uVar5);
  }
  uVar6 = (ushort)((ulonglong)(local_48 & 0xffff) / 100);
  local_48 = CONCAT22(local_48._2_2_,uVar6);
  if (uVar6 <= param_3) {
    local_4c = (short)(((int)(short)uVar6 * (int)param_4) / (int)(short)param_3);
    if (-1 < param_4) {
      local_4c = param_4 - local_4c;
    }
    local_4c = (short)((int)local_4c * (int)param_5 + ((int)local_4c * (int)param_5 >> 0x1f & 0xffU)
                      >> 8);
    if (local_4c < 0) {
      local_5c = -(int)local_4c;
    }
    else {
      local_5c = (int)local_4c;
    }
    if (param_4 < 0) {
      local_60 = -(int)param_4;
    }
    else {
      local_60 = (int)param_4;
    }
    if (local_60 < local_5c) {
      local_4c = param_4;
    }
  }
  local_8 = 0x41f25c;
  __chkesp();
  return;
}

