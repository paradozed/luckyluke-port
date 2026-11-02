/* FUN_00458c40 @ 00458c40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00458c40(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_c0 [16];
  uint local_80;
  undefined4 local_7c;
  int *local_78;
  int local_74 [6];
  int local_5c [4];
  int local_4c;
  int local_44;
  int local_40;
  int local_3c;
  int local_34 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_14;
  int local_10;
  uint local_c;
  int *local_8;
  
  puVar3 = local_c0;
  for (iVar2 = 0x2f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = (int *)param_2[1];
  local_c = CONCAT22(local_c._2_2_,*(undefined2 *)(param_2 + 2));
  local_10 = *param_1;
  local_14 = *local_8;
  FUN_0040da10(param_1,0,local_74 + 6);
  local_24 = *(undefined4 *)(local_10 + 0x90);
  local_20 = *(undefined4 *)(local_10 + 0x94);
  local_1c = *(undefined4 *)(local_10 + 0x98);
  FUN_0040da10(local_8,0,local_74);
  local_34[0] = *(int *)(local_14 + 0x90);
  local_34[1] = *(int *)(local_14 + 0x94);
  local_34[2] = *(undefined4 *)(local_14 + 0x98);
  uVar1 = FUN_0040d810(local_74 + 6,local_74);
  if ((short)uVar1 != 0) {
    local_44 = local_8[0x19];
    local_40 = local_8[0x1a];
    local_3c = local_8[0x1b];
    if ((local_8[0x1a] < local_4c) && (local_4c < local_34[1])) {
      local_34[1] = local_4c;
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | 0x80;
      *param_2 = FUN_00458a60;
      local_8[4] = local_8[4] | 0x28;
    }
    else if (local_4c < local_34[1]) {
      local_78 = local_34;
      local_80 = local_c & 0x18;
      if (local_80 == 0) {
        local_7c = (uint)local_7c._2_2_ << 0x10;
      }
      else if (local_80 == 8) {
        local_7c = CONCAT22(local_7c._2_2_,1);
      }
      else if (local_80 == 0x10) {
        local_7c = CONCAT22(local_7c._2_2_,2);
      }
      else {
        local_7c = (uint)local_7c._2_2_ << 0x10;
      }
      if (local_78[local_7c & 0xffff] <
          (local_74[(local_7c & 0xffff) + 6] + local_74[(local_7c & 0xffff) + 9]) / 2) {
        local_78[local_7c & 0xffff] =
             local_78[local_7c & 0xffff] -
             ((local_74[(local_7c & 0xffff) + 3] - local_74[(local_7c & 0xffff) + 6]) + 1);
      }
      else {
        local_78[local_7c & 0xffff] =
             local_78[local_7c & 0xffff] + 1 +
             (local_74[(local_7c & 0xffff) + 9] - local_74[local_7c & 0xffff]);
      }
    }
    FUN_00457ab0(local_14,local_34[0],local_34[1],local_34[2]);
  }
  local_8 = (int *)0x458e8d;
  __chkesp();
  return;
}

