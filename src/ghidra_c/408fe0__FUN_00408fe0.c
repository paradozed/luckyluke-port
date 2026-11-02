/* FUN_00408fe0 @ 00408fe0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00408fe0(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_58 [16];
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  int local_8;
  
  puVar3 = local_58;
  for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  sVar1 = FUN_004074b0(param_2,4);
  local_8 = **(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_18 = *(undefined4 *)(local_8 + 0x90);
  local_14 = *(int *)(local_8 + 0x94);
  local_10 = *(undefined4 *)(local_8 + 0x98);
  sVar1 = FUN_004074b0(param_2,2);
  if (sVar1 * 100 < local_14) {
    FUN_004074b0(param_2,3);
  }
  local_8 = 0x409078;
  __chkesp();
  return;
}

