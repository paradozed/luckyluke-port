/* FUN_004568c0 @ 004568c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004568c0(int param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_94 [16];
  int local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  int local_44;
  int local_40;
  int local_3c [4];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  char *local_18;
  uint local_14;
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  puVar2 = local_94;
  for (iVar1 = 0x24; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = *(int *)(*(int *)(param_1 + 0x14) + 4);
  local_10 = *(int *)(*(int *)(param_1 + 0x14) + 8);
  local_8 = (undefined4 *)(*(int *)(param_1 + 0x14) + 0x14);
  local_14 = CONCAT22(local_14._2_2_,*(undefined2 *)(*(int *)(param_1 + 0x14) + 0x10));
  do {
    if ((local_14 & 0xffff) == 0) {
LAB_00456bf5:
      local_8 = (undefined4 *)0x456c05;
      __chkesp();
      return;
    }
    local_18 = (char *)*local_8;
    if (((((*(int *)(local_18 + 4) != local_c) && (*(int *)(local_18 + 8) != local_c)) &&
         (*(int *)(local_18 + 4) != local_10)) &&
        ((*(int *)(local_18 + 8) != local_10 &&
         (*(int *)(*(int *)(local_18 + 4) + 4) <= *(int *)(local_c + 4))))) && (*local_18 != '\x01')
       ) {
      local_3c[3] = *param_2 - **(int **)(local_18 + 4);
      local_2c = param_2[1] - *(int *)(*(int *)(local_18 + 4) + 4);
      local_28 = param_2[2] - *(int *)(*(int *)(local_18 + 4) + 8);
      local_3c[0] = *param_3 - **(int **)(local_18 + 4);
      local_3c[1] = param_3[1] - *(int *)(*(int *)(local_18 + 4) + 4);
      local_3c[2] = param_3[2] - *(int *)(*(int *)(local_18 + 4) + 8);
      local_50 = **(int **)(local_18 + 8) - **(int **)(local_18 + 4);
      local_24 = local_50;
      local_20 = *(int *)(*(int *)(local_18 + 8) + 4) - *(int *)(*(int *)(local_18 + 4) + 4);
      local_54 = *(int *)(*(int *)(local_18 + 8) + 8) - *(int *)(*(int *)(local_18 + 4) + 8);
      local_1c = local_54;
      if (local_50 < 0) {
        local_50 = -local_50;
      }
      if (local_54 < 0) {
        local_54 = -local_54;
      }
      if (local_54 < local_50) {
        local_48 = (uint)local_48._2_2_ << 0x10;
      }
      else {
        local_48 = CONCAT22(local_48._2_2_,2);
      }
      local_40 = (local_3c[(local_48 & 0xffff) + 3] * *(int *)(local_18 + 0xc)) /
                 local_3c[(local_48 & 0xffff) + 6];
      local_44 = (local_3c[local_48 & 0xffff] * *(int *)(local_18 + 0xc)) /
                 local_3c[(local_48 & 0xffff) + 6];
      if ((0 < local_40) && (local_40 < *(int *)(local_18 + 0xc))) {
        local_4c = (local_20 * local_40) / *(int *)(local_18 + 0xc);
        local_2c = local_2c - local_4c;
        if (local_2c < 0) {
          FUN_004562f0(param_1,(int)local_18);
          goto LAB_00456bf5;
        }
        if ((local_44 < 1) || (*(int *)(local_18 + 0xc) <= local_44)) {
          if (local_2c < (int)(*(ushort *)(local_18 + 2) + 0x708)) {
            if (local_40 < *(int *)(local_18 + 0xc) / 2) {
              *param_4 = **(int **)(local_18 + 4);
              param_4[1] = param_2[1];
              param_4[2] = *(int *)(*(int *)(local_18 + 4) + 8);
            }
            else {
              *param_4 = **(int **)(local_18 + 8);
              param_4[1] = param_2[1];
              param_4[2] = *(int *)(*(int *)(local_18 + 8) + 8);
            }
            goto LAB_00456bf5;
          }
        }
        else if (local_2c < (int)(*(ushort *)(local_18 + 2) + 0x708)) {
          *param_4 = *param_2;
          param_4[1] = *(int *)(*(int *)(local_18 + 4) + 4) + (uint)*(ushort *)(local_18 + 2) +
                       0x708 + local_4c;
          param_4[2] = param_2[2];
          goto LAB_00456bf5;
        }
      }
    }
    local_14 = CONCAT22(local_14._2_2_,(short)local_14 + -1);
    local_8 = local_8 + 1;
  } while( true );
}

