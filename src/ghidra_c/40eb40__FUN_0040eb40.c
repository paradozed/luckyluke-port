/* FUN_0040eb40 @ 0040eb40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040eb40(int param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 extraout_var;
  void *pvVar6;
  undefined4 uVar7;
  undefined2 extraout_var_00;
  int iVar8;
  undefined4 *puVar9;
  undefined4 local_48 [16];
  int local_8;
  uint uVar5;
  
  puVar9 = local_48;
  for (iVar8 = 0x11; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar9 = 0xcccccccc;
    puVar9 = puVar9 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = (int)sVar1;
  sVar1 = FUN_0040ec20(local_8);
  sVar1 = -sVar1;
  uVar2 = FUN_004074b0(param_2,5);
  uVar3 = FUN_004074b0(param_2,6);
  uVar5 = CONCAT22(extraout_var,uVar3);
  pvVar6 = (void *)FUN_00409d00(param_1);
  FUN_00421f60(pvVar6,uVar5,uVar2,sVar1);
  uVar7 = FUN_0040ebe0(local_8);
  uVar2 = (undefined2)uVar7;
  uVar3 = FUN_004074b0(param_2,3);
  uVar4 = FUN_004074b0(param_2,4);
  uVar5 = CONCAT22(extraout_var_00,uVar4);
  pvVar6 = (void *)FUN_00409d00(param_1);
  FUN_00421f60(pvVar6,uVar5,uVar3,uVar2);
  local_8 = 0x40ebdb;
  __chkesp();
  return;
}

