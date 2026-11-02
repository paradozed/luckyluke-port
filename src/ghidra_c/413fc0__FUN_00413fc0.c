/* FUN_00413fc0 @ 00413fc0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00413fc0(int param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 extraout_var;
  void *pvVar6;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  int iVar7;
  ushort uVar8;
  undefined4 *puVar9;
  undefined4 local_48 [16];
  int local_8;
  uint uVar5;
  
  puVar9 = local_48;
  for (iVar7 = 0x11; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = 0xcccccccc;
    puVar9 = puVar9 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  if (sVar1 == DAT_004e8982) {
    DAT_004e8982 = 0;
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  else {
    local_8 = (uint)local_8._1_3_ << 8;
  }
  uVar4 = *(undefined2 *)(&DAT_004f13d8 + (uint)DAT_004f16bc * 0x2c);
  uVar2 = FUN_004074b0(param_2,8);
  uVar3 = FUN_004074b0(param_2,9);
  uVar5 = CONCAT22(extraout_var,uVar3);
  pvVar6 = (void *)FUN_00409d00(param_1);
  FUN_00421f60(pvVar6,uVar5,uVar2,uVar4);
  uVar4 = *(undefined2 *)(&DAT_004f13d4 + (uint)DAT_004f16bc * 0x2c);
  uVar2 = FUN_004074b0(param_2,6);
  uVar3 = FUN_004074b0(param_2,7);
  uVar5 = CONCAT22(extraout_var_00,uVar3);
  pvVar6 = (void *)FUN_00409d00(param_1);
  FUN_00421f60(pvVar6,uVar5,uVar2,uVar4);
  uVar4 = *(undefined2 *)(&DAT_004f13d0 + (uint)DAT_004f16bc * 0x2c);
  uVar2 = FUN_004074b0(param_2,4);
  uVar3 = FUN_004074b0(param_2,5);
  uVar5 = CONCAT22(extraout_var_01,uVar3);
  pvVar6 = (void *)FUN_00409d00(param_1);
  FUN_00421f60(pvVar6,uVar5,uVar2,uVar4);
  uVar8 = (ushort)local_8 & 0xff;
  uVar4 = FUN_004074b0(param_2,2);
  uVar2 = FUN_004074b0(param_2,3);
  uVar5 = CONCAT22(extraout_var_02,uVar2);
  pvVar6 = (void *)FUN_00409d00(param_1);
  FUN_00421f60(pvVar6,uVar5,uVar4,uVar8);
  local_8 = 0x4140e5;
  __chkesp();
  return;
}

