/* FUN_00416b70 @ 00416b70 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00416b70(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_5c [16];
  int local_1c;
  int local_18;
  int local_14;
  int local_c;
  int local_8;
  
  puVar3 = local_5c;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_c = *(int *)(local_8 + 0xe4);
  sVar1 = FUN_004074b0(param_2,3);
  local_1c = sVar1 * 100;
  sVar1 = FUN_004074b0(param_2,4);
  local_18 = sVar1 * 100;
  sVar1 = FUN_004074b0(param_2,5);
  local_14 = sVar1 * 100;
  FUN_00457740(local_8,local_c,&local_1c);
  local_8 = 0x416c0a;
  __chkesp();
  return;
}

