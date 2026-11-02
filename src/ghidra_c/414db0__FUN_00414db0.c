/* FUN_00414db0 @ 00414db0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00414db0(int param_1,void *param_2)

{
  undefined2 uVar1;
  undefined2 extraout_var;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar1 = FUN_004074b0(param_2,3);
  uVar5 = (undefined1)uVar1;
  uVar1 = FUN_004074b0(param_2,2);
  uVar2 = CONCAT22(extraout_var,uVar1) & 0xffff00ff;
  iVar3 = FUN_00407580(param_1);
  FUN_0046ef20(*(int **)(iVar3 + 8),uVar2,uVar5);
  uStack_8 = 0x414e03;
  __chkesp();
  return;
}

