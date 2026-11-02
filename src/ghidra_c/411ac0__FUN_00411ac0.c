/* FUN_00411ac0 @ 00411ac0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00411ac0(int param_1,void *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  void *pvVar4;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  int iVar5;
  undefined4 *puVar6;
  undefined2 uVar7;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  uint uVar3;
  
  puVar6 = local_44;
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  uVar7 = DAT_004f1788;
  uVar1 = FUN_004074b0(param_2,10);
  uVar2 = FUN_004074b0(param_2,0xb);
  uVar3 = CONCAT22(extraout_var,uVar2);
  pvVar4 = (void *)FUN_00409d00(param_1);
  FUN_00421f60(pvVar4,uVar3,uVar1,uVar7);
  uVar7 = DAT_004f1786;
  uVar1 = FUN_004074b0(param_2,8);
  uVar2 = FUN_004074b0(param_2,9);
  uVar3 = CONCAT22(extraout_var_00,uVar2);
  pvVar4 = (void *)FUN_00409d00(param_1);
  FUN_00421f60(pvVar4,uVar3,uVar1,uVar7);
  uVar7 = DAT_004f1784;
  uVar1 = FUN_004074b0(param_2,6);
  uVar2 = FUN_004074b0(param_2,7);
  uVar3 = CONCAT22(extraout_var_01,uVar2);
  pvVar4 = (void *)FUN_00409d00(param_1);
  FUN_00421f60(pvVar4,uVar3,uVar1,uVar7);
  uVar7 = DAT_004f1782;
  uVar1 = FUN_004074b0(param_2,4);
  uVar2 = FUN_004074b0(param_2,5);
  uVar3 = CONCAT22(extraout_var_02,uVar2);
  pvVar4 = (void *)FUN_00409d00(param_1);
  FUN_00421f60(pvVar4,uVar3,uVar1,uVar7);
  uVar7 = DAT_004f1780;
  uVar1 = FUN_004074b0(param_2,2);
  uVar2 = FUN_004074b0(param_2,3);
  uVar3 = CONCAT22(extraout_var_03,uVar2);
  pvVar4 = (void *)FUN_00409d00(param_1);
  FUN_00421f60(pvVar4,uVar3,uVar1,uVar7);
  uStack_8 = 0x411bc4;
  __chkesp();
  return;
}

