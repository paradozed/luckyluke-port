/* FUN_0040ed50 @ 0040ed50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040ed50(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_58 [16];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 uStack_8;
  
  puVar3 = local_58;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,2);
  local_18 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_14 = *(int *)(local_18 + 0x90);
  local_10 = *(int *)(local_18 + 0x94);
  local_c = *(int *)(local_18 + 0x98);
  sVar1 = FUN_004074b0(param_2,3);
  local_14 = local_14 + sVar1;
  sVar1 = FUN_004074b0(param_2,4);
  local_10 = local_10 + sVar1;
  sVar1 = FUN_004074b0(param_2,5);
  local_c = local_c + sVar1;
  FUN_0040f060(local_18,local_14,local_10,local_c);
  uStack_8 = 0x40ee0c;
  __chkesp();
  return;
}

