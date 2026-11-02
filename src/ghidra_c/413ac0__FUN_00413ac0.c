/* FUN_00413ac0 @ 00413ac0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00413ac0(int param_1,void *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  void *pvVar4;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  int iVar5;
  undefined4 *puVar6;
  ushort uVar7;
  undefined2 uVar8;
  undefined4 local_5c [16];
  uint local_1c;
  ushort local_18;
  undefined2 uStack_16;
  ushort local_14;
  ushort local_10;
  ushort local_c;
  uint local_8;
  uint uVar3;
  
  puVar6 = local_5c;
  for (iVar5 = 0x16; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  uVar3 = local_8 >> 0x10;
  local_8 = local_8 & 0xffff0000;
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  local_1c = local_1c & 0xffffff00;
  do {
    if (9 < (local_1c & 0xff)) {
LAB_00413bd0:
      uVar7 = local_14;
      uVar1 = FUN_004074b0(param_2,8);
      uVar2 = FUN_004074b0(param_2,9);
      uVar3 = CONCAT22(extraout_var,uVar2);
      pvVar4 = (void *)FUN_00409d00(param_1);
      FUN_00421f60(pvVar4,uVar3,uVar1,uVar7);
      uVar7 = local_10;
      uVar1 = FUN_004074b0(param_2,6);
      uVar2 = FUN_004074b0(param_2,7);
      uVar3 = CONCAT22(extraout_var_00,uVar2);
      pvVar4 = (void *)FUN_00409d00(param_1);
      FUN_00421f60(pvVar4,uVar3,uVar1,uVar7);
      uVar7 = local_c;
      uVar1 = FUN_004074b0(param_2,4);
      uVar2 = FUN_004074b0(param_2,5);
      uVar3 = CONCAT22(extraout_var_01,uVar2);
      pvVar4 = (void *)FUN_00409d00(param_1);
      FUN_00421f60(pvVar4,uVar3,uVar1,uVar7);
      uVar8 = (undefined2)local_8;
      uVar1 = FUN_004074b0(param_2,2);
      uVar2 = FUN_004074b0(param_2,3);
      uVar3 = CONCAT22(extraout_var_02,uVar2);
      pvVar4 = (void *)FUN_00409d00(param_1);
      FUN_00421f60(pvVar4,uVar3,uVar1,uVar8);
      local_8 = 0x413c85;
      __chkesp();
      return;
    }
    if (*(short *)(&DAT_004be1ae + (local_1c & 0xff) * 6) == DAT_004e8916) {
      uVar7 = *(ushort *)(&DAT_004be1ac + (local_1c & 0xff) * 6);
      local_14 = uVar7 & 0xf;
      local_10 = uVar7 >> 4 & 0xf;
      local_c = uVar7 >> 8 & 0xf;
      _local_18 = CONCAT22(uStack_16,uVar7 >> 0xc);
      local_8 = CONCAT22((short)uVar3,uVar7 >> 0xc);
      DAT_004e898c = *(undefined2 *)(&DAT_004be1b0 + (local_1c & 0xff) * 6);
      goto LAB_00413bd0;
    }
    local_1c = CONCAT31(local_1c._1_3_,(char)local_1c + '\x01');
  } while( true );
}

