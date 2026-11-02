/* FUN_00412870 @ 00412870 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00412870(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  ushort uVar4;
  int iVar5;
  undefined4 extraout_ECX;
  uint uVar6;
  undefined4 extraout_ECX_00;
  undefined4 *puVar7;
  undefined4 local_b8 [16];
  uint local_78;
  uint local_74;
  int local_70;
  int local_6c;
  int *local_68;
  uint local_64;
  int local_60;
  int local_5c;
  undefined4 local_58;
  undefined4 local_54;
  ushort local_4c;
  undefined2 uStack_4a;
  undefined2 local_48;
  undefined2 uStack_46;
  uint local_44;
  uint local_40;
  undefined2 local_3c;
  undefined2 uStack_3a;
  undefined2 local_38;
  undefined2 uStack_36;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar7 = local_b8;
  for (iVar5 = 0x2d; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0xcccccccc;
    puVar7 = puVar7 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_60 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  sVar1 = FUN_004074b0(param_2,3);
  local_64 = FUN_00473240(DAT_004f1804,sVar1);
  local_6c = 0;
  uVar3 = extraout_ECX;
  do {
    if ((int)local_64 <= local_6c) {
LAB_00412b75:
      local_8 = 0x412b85;
      __chkesp();
      return;
    }
    uVar6 = CONCAT22((short)((uint)uVar3 >> 0x10),(undefined2)local_6c);
    sVar1 = FUN_004074b0(param_2,3);
    local_68 = (int *)FUN_00473140(DAT_004f1804,sVar1,uVar6);
    if (local_68 == (int *)0x0) {
      local_68 = (int *)0x0;
      uVar3 = extraout_ECX_00;
    }
    else {
      local_34 = *local_68;
      local_30 = local_68[1];
      local_2c = local_68[2];
      local_28 = local_68[3];
      local_24 = local_68[4];
      local_20 = local_68[5];
      local_68 = local_68 + 6;
      uVar2 = FUN_004074b0(param_2,4);
      local_44 = CONCAT22(local_44._2_2_,uVar2);
      uVar2 = FUN_004074b0(param_2,5);
      _local_48 = CONCAT22(uStack_46,uVar2);
      if (local_34 + local_28 < 0) {
        local_70 = -(local_34 + local_28);
      }
      else {
        local_70 = local_34 + local_28;
      }
      local_40 = CONCAT22(local_40._2_2_,(short)(local_70 / 2));
      FUN_00411200(local_60,&local_1c);
      local_10 = local_10 + *(int *)(local_60 + 0x90);
      local_1c = local_1c + *(int *)(local_60 + 0x90);
      local_c = local_c + *(int *)(local_60 + 0x94);
      local_18 = local_18 + *(int *)(local_60 + 0x94);
      local_8 = local_8 + *(int *)(local_60 + 0x98);
      local_14 = local_14 + *(int *)(local_60 + 0x98);
      uVar3 = FUN_0040d810(&local_1c,&local_34);
      if ((short)uVar3 != 0) {
        local_5c = *(int *)(local_60 + 0x90);
        local_58 = *(undefined4 *)(local_60 + 0x94);
        local_54 = *(undefined4 *)(local_60 + 0x98);
        if ((int)(local_5c - (local_40 & 0xffff)) < 0) {
          local_74 = -(local_5c - (local_40 & 0xffff));
        }
        else {
          local_74 = local_5c - (local_40 & 0xffff);
        }
        _local_38 = CONCAT22(uStack_36,(undefined2)local_74);
        if ((int)((local_40 & 0xffff) - local_34) < 0) {
          local_78 = -((local_40 & 0xffff) - local_34);
        }
        else {
          local_78 = (local_40 & 0xffff) - local_34;
        }
        _local_3c = CONCAT22(uStack_3a,(undefined2)local_78);
        if ((int)((local_78 & 0xffff) - 1) < (int)(local_74 & 0xffff)) {
          if (*DAT_004f58a8 != 0x536f6674) {
            FUN_0047d700(local_60,local_44 & 0xffff);
          }
        }
        else {
          uVar4 = (short)_local_48 -
                  (short)((int)((local_44 & 0xffff) * (local_74 & 0xffff)) /
                         (int)(local_78 & 0xffff));
          _local_4c = CONCAT22(uStack_4a,uVar4);
          if (*DAT_004f58a8 != 0x536f6674) {
            FUN_0047d700(local_60,(uint)uVar4);
          }
        }
        goto LAB_00412b75;
      }
      uVar3 = 0;
    }
    local_6c = local_6c + 1;
  } while( true );
}

