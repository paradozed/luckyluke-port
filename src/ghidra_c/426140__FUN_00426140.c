/* FUN_00426140 @ 00426140 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00426140(undefined4 *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_84 [16];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  ushort *local_34;
  byte *local_30;
  undefined2 *local_2c;
  int local_28;
  undefined2 *local_24;
  undefined2 *local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_c;
  undefined4 uStack_8;
  
  iVar2 = DAT_00507f00;
  puVar4 = local_84;
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_c = DAT_00507f00;
  DAT_00507f04 = *(uint *)(DAT_00507f00 + 4) & 7;
  *param_1 = *(undefined4 *)(DAT_00507f00 + 4);
  local_1c = param_1[2];
  if (DAT_00507f04 == 0) {
    param_1[1] = &DAT_004bc4f0;
    param_1[2] = &DAT_004f7f00 + DAT_004d28ac * 0x200;
    if ((*(uint *)(DAT_00507f00 + 4) & 8) == 8) {
      param_1[1] = iVar2 + 0xc;
      param_1[2] = DAT_00507f00 + 0x14;
      param_1[3] = iVar2 + 0x38;
      param_1[4] = DAT_00507f00 + 0x40;
      local_1c = param_1[2];
      *(undefined2 *)param_1[3] = 0;
      *(undefined2 *)(param_1[3] + 2) = 0;
      local_20 = (undefined2 *)
                 FUN_00439af0((int)*(short *)(param_1[3] + 4) * (int)*(short *)(param_1[3] + 6) * 2)
      ;
      local_28 = param_1[4];
      local_18 = 0;
      local_24 = local_20;
      for (local_14 = 0;
          (int)local_14 < (int)*(short *)(param_1[3] + 4) * (int)*(short *)(param_1[3] + 6);
          local_14 = local_14 + 1) {
        if ((local_14 & 1) == 0) {
          *local_24 = *(undefined2 *)(local_1c + (*(byte *)(local_28 + local_18) & 0xf) * 2);
        }
        else {
          *local_24 = *(undefined2 *)
                       (local_1c + ((int)(uint)*(byte *)(local_28 + local_18) >> 4) * 2);
          local_18 = local_18 + 1;
        }
        local_24 = local_24 + 1;
      }
      param_1[4] = local_20;
    }
  }
  else if (DAT_00507f04 == 1) {
    param_1[1] = &DAT_004bc4f0;
    param_1[2] = &DAT_004f7f00 + DAT_004d28ac * 0x200;
    if ((*(uint *)(DAT_00507f00 + 4) & 8) == 8) {
      param_1[1] = iVar2 + 0xc;
      param_1[2] = DAT_00507f00 + 0x14;
      param_1[3] = iVar2 + 0x218;
      param_1[4] = DAT_00507f00 + 0x220;
      local_1c = param_1[2];
      *(undefined2 *)param_1[3] = 0;
      *(undefined2 *)(param_1[3] + 2) = 0;
      local_20 = (undefined2 *)
                 FUN_00439af0((int)*(short *)(param_1[3] + 4) * (int)*(short *)(param_1[3] + 6) * 2)
      ;
      local_30 = (byte *)param_1[4];
      local_2c = local_20;
      for (local_14 = 0;
          (int)local_14 < (int)*(short *)(param_1[3] + 4) * (int)*(short *)(param_1[3] + 6);
          local_14 = local_14 + 1) {
        *local_2c = *(undefined2 *)(local_1c + (uint)*local_30 * 2);
        local_2c = local_2c + 1;
        local_30 = local_30 + 1;
      }
      param_1[4] = local_20;
    }
  }
  else if (DAT_00507f04 == 2) {
    param_1[1] = &DAT_004bc4f0;
    param_1[2] = &DAT_004f7f00 + DAT_004d28ac * 0x200;
    param_1[3] = iVar2 + 0xc;
    param_1[4] = DAT_00507f00 + 0x14;
    local_34 = (ushort *)param_1[4];
    for (local_14 = 0;
        (int)local_14 < (int)*(short *)(param_1[3] + 4) * (int)*(short *)(param_1[3] + 6);
        local_14 = local_14 + 1) {
      uVar1 = *local_34;
      local_38 = CONCAT22(local_38._2_2_,uVar1) & 0xffff001f;
      local_3c = CONCAT22(local_3c._2_2_,(short)((int)(uint)uVar1 >> 5)) & 0xffff001f;
      local_40 = CONCAT22(local_40._2_2_,(short)((int)(uint)uVar1 >> 10)) & 0xffff001f;
      uVar1 = (ushort)local_40 | (ushort)(((int)(uint)uVar1 >> 5 & 0x1fU) << 5) |
              (uVar1 & 0x1f) << 10;
      local_44 = CONCAT22(local_44._2_2_,uVar1) | 0x8000;
      *local_34 = uVar1 | 0x8000;
      local_34 = local_34 + 1;
    }
  }
  else if (DAT_00507f04 == 3) {
    param_1[1] = &DAT_004bc4f0;
    param_1[2] = &DAT_004f7f00 + DAT_004d28ac * 0x200;
    param_1[3] = iVar2 + 0xc;
    param_1[4] = DAT_00507f00 + 0x14;
  }
  else if (DAT_00507f04 == 4) {
    param_1[1] = &DAT_004bc4f0;
    param_1[2] = &DAT_004f7f00 + DAT_004d28ac * 0x200;
    param_1[3] = iVar2 + 0xc;
    param_1[4] = DAT_00507f00 + 0x14;
  }
  else {
    param_1[1] = &DAT_004bc4f0;
    param_1[2] = &DAT_004f7f00 + DAT_004d28ac * 0x200;
    param_1[3] = iVar2 + 0xc;
    param_1[4] = DAT_00507f00 + 0x14;
  }
  uStack_8 = 0x426605;
  __chkesp();
  return;
}

