/* FUN_00469410 @ 00469410 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00469410(int *param_1)

{
  short sVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_90 [16];
  uint local_50;
  short local_4c;
  undefined2 uStack_4a;
  ushort local_48;
  undefined2 uStack_46;
  ushort local_44;
  int local_40;
  int local_3c;
  int local_38;
  int *local_30;
  char *local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  int *local_18;
  undefined4 *local_14;
  char *local_10;
  int local_c;
  int local_8;
  
  puVar5 = local_90;
  for (iVar4 = 0x23; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_8 = *param_1;
  local_c = *(int *)(local_8 + 0xe4);
  local_10 = (char *)0x0;
  local_20 = (uint)*(short *)(local_c + 0x48);
  if ((local_20 < 0x259) || (*(int *)(*(int *)(local_c + 0x14) + 0xc) - 600U <= local_20)) {
    local_14 = (undefined4 *)(*(int *)(local_c + 0x14) + 0x14);
    local_1c = *(uint *)(*(int *)(local_c + 0x14) + 0x10);
    uVar2 = FUN_00456150((ushort)(byte)DAT_004f2744);
    local_28 = CONCAT22(local_28._2_2_,
                        *(short *)(&DAT_004be014 + (uVar2 & 0xffff) * 2) + DAT_004e868a) &
               0xffff0fff;
    if (local_20 < 0x259) {
      local_18 = *(int **)(*(int *)(local_c + 0x14) + 4);
    }
    else {
      local_18 = *(int **)(*(int *)(local_c + 0x14) + 8);
    }
    for (local_24 = 0; local_24 < local_1c; local_24 = local_24 + 1) {
      local_2c = (char *)*local_14;
      if (*local_2c == '\x01') {
        local_10 = local_2c;
      }
      if ((*(int **)(local_2c + 4) == local_18) || (*(int **)(local_2c + 8) == local_18)) {
        if (*(int **)(local_2c + 4) == local_18) {
          local_30 = *(int **)(local_2c + 8);
        }
        else {
          local_30 = *(int **)(local_2c + 4);
        }
        local_40 = *local_30 - *local_18;
        local_3c = local_30[1] - local_18[1];
        local_38 = local_30[2] - local_18[2];
        sVar1 = FUN_004836a0(local_38,local_40);
        local_44 = sVar1 + 0x400U & 0xfff;
        if ((int)((local_28 & 0xffff) - (int)(short)local_44) < 0) {
          local_50 = -((local_28 & 0xffff) - (int)(short)local_44);
        }
        else {
          local_50 = (local_28 & 0xffff) - (int)(short)local_44;
        }
        uVar3 = (ushort)local_50;
        if (0x800 < (local_50 & 0xffff)) {
          uVar3 = 0x1000 - (ushort)local_50;
        }
        _local_48 = CONCAT22(uStack_46,uVar3);
        if (uVar3 < 0x155) {
          if (local_20 < 600) {
            sVar1 = *(short *)(local_c + 0x58) + 0x800;
          }
          else {
            sVar1 = *(short *)(local_c + 0x58);
          }
          _local_4c = CONCAT22(uStack_4a,sVar1);
          FUN_00467440(*DAT_004f2458,0,sVar1,0);
          *(short *)(param_1 + 0x29) = local_4c;
          break;
        }
      }
      local_14 = local_14 + 1;
    }
  }
  local_8 = 0x4696a4;
  __chkesp();
  return;
}

