/* FUN_004091f0 @ 004091f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004091f0(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_7c [16];
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24 [6];
  int *local_c;
  int *local_8;
  
  puVar3 = local_7c;
  for (iVar2 = 0x1e; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = *(int **)(*(int *)(DAT_004f2458 + 0x9c) + 8);
  sVar1 = FUN_004074b0(param_2,2);
  local_c = *(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  FUN_0040da10(local_8,0,local_24);
  FUN_0040da10(local_c,0,&local_3c);
  sVar1 = FUN_004074b0(param_2,3);
  local_3c = local_3c + sVar1;
  sVar1 = FUN_004074b0(param_2,4);
  local_38 = local_38 + sVar1;
  sVar1 = FUN_004074b0(param_2,5);
  local_34 = local_34 + sVar1;
  sVar1 = FUN_004074b0(param_2,6);
  local_30 = local_30 + sVar1;
  sVar1 = FUN_004074b0(param_2,7);
  local_2c = local_2c + sVar1;
  sVar1 = FUN_004074b0(param_2,8);
  local_28 = local_28 + sVar1;
  FUN_0040d810(local_24,&local_3c);
  local_8 = (int *)0x409302;
  __chkesp();
  return;
}

