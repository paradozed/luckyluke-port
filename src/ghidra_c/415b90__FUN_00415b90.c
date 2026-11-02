/* FUN_00415b90 @ 00415b90 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00415b90(int param_1,void *param_2)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  undefined2 uVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  undefined2 extraout_var;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  undefined4 uVar9;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  
  puVar13 = local_44;
  for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
    *puVar13 = 0xcccccccc;
    puVar13 = puVar13 + 1;
  }
  sVar2 = FUN_004074b0(param_2,0xb);
  sVar3 = FUN_004074b0(param_2,10);
  uVar4 = FUN_004074b0(param_2,9);
  uVar9 = CONCAT22(extraout_var,uVar4);
  uVar4 = FUN_004074b0(param_2,8);
  uVar10 = CONCAT22(extraout_var_00,uVar4);
  sVar5 = FUN_004074b0(param_2,7);
  sVar6 = FUN_004074b0(param_2,6);
  sVar7 = FUN_004074b0(param_2,5);
  sVar8 = FUN_004074b0(param_2,4);
  uVar4 = FUN_004074b0(param_2,3);
  uVar11 = CONCAT22(extraout_var_01,uVar4);
  uVar4 = FUN_004074b0(param_2,2);
  bVar1 = (byte)uVar4;
  iVar12 = FUN_00407580(param_1);
  FUN_00446b90(*(int *)(iVar12 + 8),bVar1,uVar11,sVar8,sVar7,sVar6,sVar5,uVar10,uVar9,sVar3,sVar2);
  uStack_8 = 0x415c37;
  __chkesp();
  return;
}

