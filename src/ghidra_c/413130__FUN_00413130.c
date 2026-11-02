/* FUN_00413130 @ 00413130 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00413130(int param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined2 extraout_var;
  void *pvVar5;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  int iVar6;
  undefined4 *puVar7;
  undefined2 uVar8;
  undefined4 local_74 [16];
  undefined2 local_34;
  undefined2 local_30;
  undefined2 local_2c;
  undefined2 local_28;
  undefined2 local_24;
  undefined2 local_20;
  undefined2 local_1c;
  undefined2 local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar7 = local_74;
  for (iVar6 = 0x1c; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0xcccccccc;
    puVar7 = puVar7 + 1;
  }
  local_14 = local_14 & 0xffffff00;
  uVar4 = FUN_004971c0();
  uVar4 = uVar4 & 0x80000007;
  if ((int)uVar4 < 0) {
    uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
  }
  DAT_004d1e4c = (ushort)uVar4;
  local_8 = CONCAT22(local_8._2_2_,1);
  do {
    if (7 < (local_8 & 0xffff)) {
      DAT_004d1e5c = (&DAT_004d1e5c)[DAT_004d1e4c];
      DAT_004d1e5e = (&DAT_004d1e5c)[DAT_004d1e4e];
      DAT_004d1e60 = (&DAT_004d1e5c)[DAT_004d1e50];
      DAT_004d1e62 = (&DAT_004d1e5c)[DAT_004d1e52];
      DAT_004d1e64 = (&DAT_004d1e5c)[DAT_004d1e54];
      DAT_004d1e66 = (&DAT_004d1e5c)[DAT_004d1e56];
      DAT_004d1e68 = (&DAT_004d1e5c)[DAT_004d1e58];
      DAT_004d1e6a = (&DAT_004d1e5c)[DAT_004d1e5a];
      local_34 = DAT_004d1e6a;
      local_30 = DAT_004d1e68;
      local_2c = DAT_004d1e66;
      local_28 = DAT_004d1e64;
      local_24 = DAT_004d1e62;
      local_20 = DAT_004d1e60;
      local_1c = DAT_004d1e5e;
      local_18 = DAT_004d1e5c;
      uVar8 = DAT_004d1e6a;
      uVar2 = FUN_004074b0(param_2,0x10);
      uVar3 = FUN_004074b0(param_2,0x11);
      uVar4 = CONCAT22(extraout_var,uVar3);
      pvVar5 = (void *)FUN_00409d00(param_1);
      FUN_00421f60(pvVar5,uVar4,uVar2,uVar8);
      uVar8 = DAT_004d1e68;
      uVar2 = FUN_004074b0(param_2,0xe);
      uVar3 = FUN_004074b0(param_2,0xf);
      uVar4 = CONCAT22(extraout_var_00,uVar3);
      pvVar5 = (void *)FUN_00409d00(param_1);
      FUN_00421f60(pvVar5,uVar4,uVar2,uVar8);
      uVar8 = DAT_004d1e66;
      uVar2 = FUN_004074b0(param_2,0xc);
      uVar3 = FUN_004074b0(param_2,0xd);
      uVar4 = CONCAT22(extraout_var_01,uVar3);
      pvVar5 = (void *)FUN_00409d00(param_1);
      FUN_00421f60(pvVar5,uVar4,uVar2,uVar8);
      uVar8 = DAT_004d1e64;
      uVar2 = FUN_004074b0(param_2,10);
      uVar3 = FUN_004074b0(param_2,0xb);
      uVar4 = CONCAT22(extraout_var_02,uVar3);
      pvVar5 = (void *)FUN_00409d00(param_1);
      FUN_00421f60(pvVar5,uVar4,uVar2,uVar8);
      uVar8 = DAT_004d1e62;
      uVar2 = FUN_004074b0(param_2,8);
      uVar3 = FUN_004074b0(param_2,9);
      uVar4 = CONCAT22(extraout_var_03,uVar3);
      pvVar5 = (void *)FUN_00409d00(param_1);
      FUN_00421f60(pvVar5,uVar4,uVar2,uVar8);
      uVar8 = DAT_004d1e60;
      uVar2 = FUN_004074b0(param_2,6);
      uVar3 = FUN_004074b0(param_2,7);
      uVar4 = CONCAT22(extraout_var_04,uVar3);
      pvVar5 = (void *)FUN_00409d00(param_1);
      FUN_00421f60(pvVar5,uVar4,uVar2,uVar8);
      uVar8 = DAT_004d1e5e;
      uVar2 = FUN_004074b0(param_2,4);
      uVar3 = FUN_004074b0(param_2,5);
      uVar4 = CONCAT22(extraout_var_05,uVar3);
      pvVar5 = (void *)FUN_00409d00(param_1);
      FUN_00421f60(pvVar5,uVar4,uVar2,uVar8);
      uVar8 = DAT_004d1e5c;
      uVar2 = FUN_004074b0(param_2,2);
      uVar3 = FUN_004074b0(param_2,3);
      uVar4 = CONCAT22(extraout_var_06,uVar3);
      pvVar5 = (void *)FUN_00409d00(param_1);
      FUN_00421f60(pvVar5,uVar4,uVar2,uVar8);
      local_8 = 0x4134f9;
      __chkesp();
      return;
    }
    uVar4 = FUN_004971c0();
    uVar4 = uVar4 & 0x80000007;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xfffffff8) + 1;
    }
    (&DAT_004d1e4c)[local_8 & 0xffff] = (short)uVar4;
    local_c = local_c & 0xffff0000;
    while ((local_c & 0xffff) < (local_8 & 0xffff)) {
      local_10 = local_10 & 0xffff0000;
      while ((local_10 & 0xffff) <= (local_8 & 0xffff)) {
        sVar1 = (&DAT_004d1e4c)[local_8 & 0xffff];
        iVar6 = FUN_004975e0((local_10 & 0xffff) - (local_c & 0xffff));
        if (sVar1 == (&DAT_004d1e4c)[iVar6]) {
          local_8 = CONCAT22(local_8._2_2_,(short)local_8 + -1);
          local_14 = CONCAT31(local_14._1_3_,1);
          break;
        }
        if ((local_10 & 0xffff) == (local_c & 0xffff)) break;
        local_10 = CONCAT22(local_10._2_2_,(short)local_10 + 1);
      }
      if ((local_14 & 0xff) != 0) {
        local_14 = local_14 & 0xffffff00;
        break;
      }
      local_c = CONCAT22(local_c._2_2_,(short)local_c + 1);
    }
    local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
  } while( true );
}

