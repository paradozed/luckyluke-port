/* FUN_00414d60 @ 00414d60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00414d60(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar4 = local_44;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,3);
  iVar3 = (int)sVar1;
  uVar2 = FUN_004074b0(param_2,2);
  FUN_0046ee90(CONCAT22(extraout_var,uVar2),iVar3);
  uStack_8 = 0x414da6;
  __chkesp();
  return;
}

