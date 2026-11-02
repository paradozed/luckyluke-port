/* FUN_0040d2c0 @ 0040d2c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040d2c0(undefined4 param_1,void *param_2)

{
  short sVar1;
  short sVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int iVar6;
  undefined4 *puVar7;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  uint uVar5;
  
  puVar7 = local_44;
  for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar7 = 0xcccccccc;
    puVar7 = puVar7 + 1;
  }
  sVar1 = FUN_004074b0(param_2,6);
  sVar2 = FUN_004074b0(param_2,5);
  uVar3 = FUN_004074b0(param_2,4);
  uVar4 = FUN_004074b0(param_2,3);
  uVar5 = CONCAT22(extraout_var,uVar4);
  uVar4 = FUN_004074b0(param_2,2);
  FUN_0041f020(CONCAT22(extraout_var_00,uVar4),uVar5,uVar3,sVar2,sVar1);
  uStack_8 = 0x40d324;
  __chkesp();
  return;
}

