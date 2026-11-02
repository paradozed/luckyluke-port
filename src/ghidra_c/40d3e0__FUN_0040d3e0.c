/* FUN_0040d3e0 @ 0040d3e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040d3e0(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 extraout_var;
  int iVar5;
  undefined2 extraout_var_00;
  uint uVar6;
  undefined4 *puVar7;
  char cVar8;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar7 = local_48;
  for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar7 = 0xcccccccc;
    puVar7 = puVar7 + 1;
  }
  sVar1 = FUN_004074b0(param_2,3);
  local_8 = CONCAT22(local_8._2_2_,sVar1 - DAT_004d2880);
  uVar2 = FUN_004074b0(param_2,7);
  cVar8 = (char)uVar2;
  uVar2 = FUN_004074b0(param_2,6);
  uVar3 = FUN_004074b0(param_2,5);
  sVar1 = FUN_004074b0(param_2,4);
  uVar6 = CONCAT22(extraout_var_00,(undefined2)local_8);
  uVar4 = FUN_004074b0(param_2,2);
  FUN_0041f5e0(CONCAT22(extraout_var,uVar4),uVar6,sVar1,uVar3,uVar2,cVar8);
  local_8 = 0x40d469;
  __chkesp();
  return;
}

