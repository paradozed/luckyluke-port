/* FUN_0040b6c0 @ 0040b6c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040b6c0(undefined4 param_1,void *param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined2 extraout_var;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar4 = local_4c;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  sVar1 = FUN_004074b0(param_2,4);
  local_c = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  FUN_004074b0(param_2,6);
  FUN_004074b0(param_2,5);
  uVar2 = FUN_004074b0(param_2,3);
  FUN_00476a30(local_8,local_c,CONCAT22(extraout_var,uVar2));
  local_8 = 0x40b752;
  __chkesp();
  return;
}

