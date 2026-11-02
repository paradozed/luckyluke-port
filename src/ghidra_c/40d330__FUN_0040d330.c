/* FUN_0040d330 @ 0040d330 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040d330(undefined4 param_1,void *param_2)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  uint uVar2;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  FUN_004074b0(param_2,5);
  FUN_004074b0(param_2,4);
  uVar1 = FUN_004074b0(param_2,3);
  uVar2 = CONCAT22(extraout_var,uVar1);
  uVar1 = FUN_004074b0(param_2,2);
  FUN_0041f260(CONCAT22(extraout_var_00,uVar1),uVar2);
  uStack_8 = 0x40d389;
  __chkesp();
  return;
}

