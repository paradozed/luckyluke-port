/* FUN_00456410 @ 00456410 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00456410(int param_1,int *param_2)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 local_a8 [16];
  int local_68;
  short local_64;
  ushort local_60;
  int local_5c;
  int local_58;
  int local_54;
  int *local_4c;
  char *local_48;
  uint local_44;
  uint local_3c;
  uint local_38;
  short local_34;
  undefined2 local_30;
  ushort local_2c;
  int local_28;
  int local_24 [4];
  int *local_14;
  undefined4 *local_10;
  char *local_c;
  char *local_8;
  
  puVar4 = local_a8;
  for (iVar2 = 0x29; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = (char *)0x0;
  local_c = (char *)0x0;
  local_28 = FUN_00457920(param_1,param_2,local_24);
  if (local_28 < 0) {
    local_14 = *(int **)(*(int *)(param_1 + 0x14) + 4);
  }
  else {
    if (local_28 <= *(int *)(*(int *)(param_1 + 0x14) + 0xc)) goto LAB_00456685;
    local_14 = *(int **)(*(int *)(param_1 + 0x14) + 8);
  }
  local_10 = (undefined4 *)(*(int *)(param_1 + 0x14) + 0x14);
  local_34 = 0x1000;
  local_44 = CONCAT31(local_44._1_3_,**(undefined1 **)(param_1 + 0x14));
  uVar3 = (int)*(short *)(param_1 + 0x58) & 0x800007ff;
  if ((int)uVar3 < 0) {
    uVar3 = (uVar3 - 1 | 0xfffff800) + 1;
  }
  local_30 = (undefined2)uVar3;
  local_3c = local_3c & 0xffff0000;
  local_2c = *(ushort *)(param_1 + 0x5c) & 0xfff;
  local_38 = CONCAT22(local_38._2_2_,*(undefined2 *)(*(int *)(param_1 + 0x14) + 0x10));
  while ((local_38 & 0xffff) != 0) {
    local_48 = (char *)*local_10;
    if (((local_44 & 0xff) == 1) && (*local_48 == '\x01')) {
      local_c = local_48;
    }
    if ((*(int **)(local_48 + 4) == local_14) || (*(int **)(local_48 + 8) == local_14)) {
      local_3c = CONCAT22(local_3c._2_2_,(short)local_3c + 1);
      if (*(int **)(local_48 + 4) == local_14) {
        local_4c = *(int **)(local_48 + 8);
      }
      else {
        local_4c = *(int **)(local_48 + 4);
      }
      local_5c = *local_4c - *local_14;
      local_58 = local_4c[1] - local_14[1];
      local_54 = local_4c[2] - local_14[2];
      sVar1 = FUN_004836a0(local_54,local_5c);
      local_60 = sVar1 + 0x400U & 0xfff;
      if ((int)(short)local_2c - (int)(short)local_60 < 0) {
        local_68 = -((int)(short)local_2c - (int)(short)local_60);
      }
      else {
        local_68 = (int)(short)local_2c - (int)(short)local_60;
      }
      local_64 = (short)local_68;
      if (0x800 < (short)local_68) {
        local_64 = 0x1000 - (short)local_68;
      }
      if (local_64 < local_34) {
        local_8 = local_48;
        local_34 = local_64;
      }
    }
    local_10 = local_10 + 1;
    local_38 = CONCAT22(local_38._2_2_,(short)local_38 + -1);
  }
  if ((local_3c & 0xffff) == 0) {
    if (local_c != (char *)0x0) {
      FUN_004562f0(param_1,(int)local_c);
    }
  }
  else {
    FUN_004562f0(param_1,(int)local_8);
  }
LAB_00456685:
  local_8 = (char *)0x456695;
  __chkesp();
  return;
}

