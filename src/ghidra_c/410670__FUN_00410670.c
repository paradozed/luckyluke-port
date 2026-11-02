/* FUN_00410670 @ 00410670 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00410670(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_5c [16];
  int local_1c;
  int local_18;
  int local_14;
  int local_c;
  int local_8;
  
  puVar4 = local_5c;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  sVar1 = FUN_004074b0(param_2,3);
  local_c = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_1c = *(int *)(local_8 + 0x90);
  local_18 = *(int *)(local_8 + 0x94);
  local_14 = *(int *)(local_8 + 0x98);
  sVar1 = FUN_004074b0(param_2,6);
  iVar2 = local_14 + sVar1;
  sVar1 = FUN_004074b0(param_2,5);
  iVar3 = local_18 + sVar1;
  sVar1 = FUN_004074b0(param_2,4);
  FUN_00411c90(local_c,local_1c + sVar1,iVar3,iVar2);
  local_8 = 0x410736;
  __chkesp();
  return;
}

