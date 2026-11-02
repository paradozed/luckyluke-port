/* FUN_004566a0 @ 004566a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004566a0(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_8c [16];
  int local_4c;
  int local_48;
  int local_44;
  undefined4 local_40;
  int local_3c;
  int local_38 [4];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  undefined2 local_18;
  uint local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  puVar2 = local_8c;
  for (iVar1 = 0x22; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = *(int *)(*(int *)(param_1 + 0x14) + 4);
  local_10 = *(int *)(*(int *)(param_1 + 0x14) + 8);
  local_18 = 0;
  local_1c = 0x7fffffff;
  local_8 = (int *)(*(int *)(param_1 + 0x14) + 0x14);
  local_14 = CONCAT22(local_14._2_2_,*(undefined2 *)(*(int *)(param_1 + 0x14) + 0x10));
  while ((local_14 & 0xffff) != 0) {
    local_20 = *local_8;
    if ((((*(int *)(local_20 + 4) != local_c) && (*(int *)(local_20 + 8) != local_c)) &&
        (*(int *)(local_20 + 4) != local_10)) && (*(int *)(local_20 + 8) != local_10)) {
      local_38[0] = *param_2 - **(int **)(local_20 + 4);
      local_38[1] = param_2[1] - *(int *)(*(int *)(local_20 + 4) + 4);
      local_38[2] = param_2[2] - *(int *)(*(int *)(local_20 + 4) + 8);
      local_48 = **(int **)(local_20 + 8) - **(int **)(local_20 + 4);
      local_38[3] = local_48;
      local_28 = *(int *)(*(int *)(local_20 + 8) + 4) - *(int *)(*(int *)(local_20 + 4) + 4);
      local_4c = *(int *)(*(int *)(local_20 + 8) + 8) - *(int *)(*(int *)(local_20 + 4) + 8);
      local_24 = local_4c;
      if (local_48 < 0) {
        local_48 = -local_48;
      }
      if (local_4c < 0) {
        local_4c = -local_4c;
      }
      if (local_4c < local_48) {
        local_40 = (uint)local_40._2_2_ << 0x10;
      }
      else {
        local_40 = CONCAT22(local_40._2_2_,2);
      }
      local_3c = (local_38[local_40 & 0xffff] * *(int *)(local_20 + 0xc)) /
                 local_38[(local_40 & 0xffff) + 3];
      if (((0 < local_3c) && (local_3c < *(int *)(local_20 + 0xc))) &&
         ((local_44 = (local_28 * local_3c) / *(int *)(local_20 + 0xc), local_38[1] < local_44 &&
          (*(int *)(*(int *)(local_20 + 4) + 4) + local_44 < local_1c)))) {
        local_1c = *(int *)(*(int *)(local_20 + 4) + 4) + local_44;
        FUN_004562f0(param_1,local_20);
        local_18 = 1;
      }
    }
    local_8 = local_8 + 1;
    local_14 = CONCAT22(local_14._2_2_,(short)local_14 + -1);
  }
  local_8 = (int *)0x4568ad;
  __chkesp();
  return;
}

