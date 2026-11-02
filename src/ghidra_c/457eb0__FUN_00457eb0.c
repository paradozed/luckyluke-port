/* FUN_00457eb0 @ 00457eb0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00457eb0(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_d0 [16];
  uint local_90;
  uint local_8c;
  int local_88;
  undefined4 local_84;
  short local_80;
  int *local_7c;
  int *local_78;
  int local_74;
  int local_70 [6];
  int local_58;
  int local_54;
  int local_48;
  int local_3c;
  int local_30 [4];
  int local_20 [4];
  int local_10;
  int local_c;
  int *local_8;
  
  puVar3 = local_d0;
  for (iVar2 = 0x33; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = (int *)param_2[1];
  local_c = *param_1;
  local_10 = *local_8;
  if ((*(ushort *)(param_2 + 2) & 0x80) == 0) {
    FUN_0040da10(param_1,0,local_70 + 6);
    local_20[0] = *(int *)(local_c + 0x90);
    local_20[1] = *(int *)(local_c + 0x94);
    local_20[2] = *(undefined4 *)(local_c + 0x98);
    FUN_0040da10(local_8,0,local_70);
    local_30[0] = *(int *)(local_10 + 0x90);
    local_30[1] = *(int *)(local_10 + 0x94);
    local_30[2] = *(undefined4 *)(local_10 + 0x98);
    local_3c = local_8[0x1a];
    uVar1 = FUN_0040d810(local_70 + 6,local_70);
    if ((short)uVar1 == 0) {
      if ((*(ushort *)(param_2 + 2) & 0x40) != 0) {
        local_8[4] = local_8[4] & 0xffffffeb;
        *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xffbf;
      }
    }
    else {
      local_74 = param_1[0x1a] - local_20[1];
      if (local_30[1] - local_54 < 0) {
        local_88 = -(local_30[1] - local_54);
      }
      else {
        local_88 = local_30[1] - local_54;
      }
      if (((local_88 < 300) && ((local_8[4] & 0x20U) != 0)) || (local_3c <= local_54 + local_74)) {
        local_30[1] = local_54;
        local_8[4] = local_8[4] | 0x28;
        *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | 0x80;
        local_8[4] = local_8[4] & 0xffffffeb;
        *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) & 0xffbf;
        *param_2 = FUN_00457d20;
      }
      else {
        local_74 = local_30[1] - local_70[1];
        if ((local_48 < local_70[1]) || (local_3c - local_74 < local_48)) {
          *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | 0x40;
          local_78 = local_20;
          local_7c = local_30;
          local_8c = *(ushort *)(param_2 + 2) & 0x18;
          if ((*(ushort *)(param_2 + 2) & 0x18) == 0) {
            local_84 = (uint)local_84._2_2_ << 0x10;
          }
          else if (local_8c == 8) {
            local_84 = CONCAT22(local_84._2_2_,1);
          }
          else if (local_8c == 0x10) {
            local_84 = CONCAT22(local_84._2_2_,2);
          }
          else {
            local_84 = (uint)local_84._2_2_ << 0x10;
          }
          if (local_7c[local_84 & 0xffff] <
              (local_70[(local_84 & 0xffff) + 6] + local_70[(local_84 & 0xffff) + 9]) / 2) {
            local_80 = ((short)local_70[(local_84 & 0xffff) + 6] -
                       (short)local_70[(local_84 & 0xffff) + 3]) + -1;
          }
          else {
            local_80 = ((short)local_70[(local_84 & 0xffff) + 9] -
                       (short)local_70[local_84 & 0xffff]) + 1;
          }
          local_90 = param_1[4] & 2;
          if (local_90 == 0) {
            local_8[4] = local_8[4] & 0xfffffffb;
            local_8[4] = local_8[4] | 0x10;
            local_7c[local_84 & 0xffff] = local_7c[local_84 & 0xffff] + (int)local_80;
            FUN_00457ab0(local_10,local_30[0],local_30[1],local_30[2]);
          }
          else if (local_90 == 2) {
            if ((local_8[4] & 0x20U) == 0) {
              local_7c[local_84 & 0xffff] = local_7c[local_84 & 0xffff] + (int)local_80;
              FUN_00457ab0(local_10,local_30[0],local_30[1],local_30[2]);
            }
            else {
              local_8[4] = local_8[4] & 0xffffffef;
              local_8[4] = local_8[4] | 4;
              local_78[local_84 & 0xffff] = local_78[local_84 & 0xffff] - (int)local_80;
              FUN_00457ab0(local_c,local_20[0],local_20[1],local_20[2]);
            }
          }
          if ((*(ushort *)(param_2 + 2) & 0x20) != 0) {
            local_8[4] = local_8[4] & 0xffffffeb;
          }
        }
        else {
          local_30[1] = local_48 + local_74;
          FUN_00457ab0(local_10,local_30[0],local_30[1],local_30[2]);
        }
      }
    }
  }
  local_8 = (int *)0x4582e5;
  __chkesp();
  return;
}

