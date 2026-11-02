/* FUN_004584d0 @ 004584d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004584d0(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_b4 [16];
  uint local_74;
  int local_70;
  undefined4 local_6c;
  int *local_68;
  int local_64 [6];
  int local_4c [4];
  int local_3c;
  int local_34 [4];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_14;
  int local_10;
  uint local_c;
  int *local_8;
  
  puVar3 = local_b4;
  for (iVar2 = 0x2c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = (int *)param_2[1];
  local_c = CONCAT22(local_c._2_2_,*(undefined2 *)(param_2 + 2));
  local_10 = *param_1;
  local_14 = *local_8;
  FUN_0040da10(param_1,0,local_64 + 6);
  local_24 = *(undefined4 *)(local_10 + 0x90);
  local_20 = *(undefined4 *)(local_10 + 0x94);
  local_1c = *(undefined4 *)(local_10 + 0x98);
  FUN_0040da10(local_8,0,local_64);
  local_34[0] = *(undefined4 *)(local_14 + 0x90);
  local_34[1] = *(int *)(local_14 + 0x94);
  local_34[2] = *(undefined4 *)(local_14 + 0x98);
  uVar1 = FUN_0040d810(local_64 + 6,local_64);
  if ((short)uVar1 != 0) {
    if (local_34[1] - local_3c < 0) {
      local_70 = -(local_34[1] - local_3c);
    }
    else {
      local_70 = local_34[1] - local_3c;
    }
    if ((local_70 < 100) && ((local_8[4] & 0x20U) != 0)) {
      local_34[1] = local_3c;
      *(ushort *)(param_2 + 2) = *(ushort *)(param_2 + 2) | 0x80;
      *param_2 = FUN_004582f0;
      local_8[4] = local_8[4] | 0x28;
    }
    else {
      local_68 = local_64 + 0xc;
      local_74 = local_c & 0x18;
      if (local_74 == 0) {
        local_6c = (uint)local_6c._2_2_ << 0x10;
      }
      else if (local_74 == 8) {
        local_6c = CONCAT22(local_6c._2_2_,1);
      }
      else if (local_74 == 0x10) {
        local_6c = CONCAT22(local_6c._2_2_,2);
      }
      else {
        local_6c = (uint)local_6c._2_2_ << 0x10;
      }
      if (local_68[local_6c & 0xffff] <
          (local_64[(local_6c & 0xffff) + 6] + local_64[(local_6c & 0xffff) + 9]) / 2) {
        local_68[local_6c & 0xffff] =
             local_68[local_6c & 0xffff] -
             ((local_64[(local_6c & 0xffff) + 3] - local_64[(local_6c & 0xffff) + 6]) + 1);
      }
      else {
        local_68[local_6c & 0xffff] =
             local_68[local_6c & 0xffff] + 1 +
             (local_64[(local_6c & 0xffff) + 9] - local_64[local_6c & 0xffff]);
      }
    }
    FUN_00457ab0(local_14,local_34[0],local_34[1],local_34[2]);
  }
  local_8 = (int *)0x45871a;
  __chkesp();
  return;
}

