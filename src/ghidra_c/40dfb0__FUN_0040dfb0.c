/* FUN_0040dfb0 @ 0040dfb0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040dfb0(int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 local_7c [16];
  int *local_3c;
  int *local_38;
  int local_34 [6];
  int local_1c [5];
  undefined4 uStack_8;
  
  puVar3 = local_7c;
  for (iVar2 = 0x1e; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  iVar2 = FUN_00407580(param_1);
  local_38 = *(int **)(iVar2 + 8);
  sVar1 = FUN_004074b0(param_2,3);
  local_3c = *(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  piVar4 = local_1c;
  sVar1 = FUN_004074b0(param_2,2);
  FUN_0040da10(local_38,(int)sVar1,piVar4);
  piVar4 = local_34;
  sVar1 = FUN_004074b0(param_2,4);
  FUN_0040da10(local_3c,(int)sVar1,piVar4);
  FUN_0040d8b0(local_1c,local_34);
  uStack_8 = 0x40e049;
  __chkesp();
  return;
}

