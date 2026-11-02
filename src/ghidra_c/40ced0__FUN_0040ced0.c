/* FUN_0040ced0 @ 0040ced0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0040ced0(undefined4 param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_70 [16];
  ushort local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_1c;
  int local_18;
  int local_14;
  int *local_c;
  int *local_8;
  
  puVar3 = local_70;
  for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_30 = 0;
  sVar1 = FUN_004074b0(param_2,2);
  local_8 = *(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  sVar1 = FUN_004074b0(param_2,3);
  local_c = *(int **)(*(int *)(&DAT_004f1e40 + sVar1 * 4) + 8);
  local_1c = *(int *)(*local_8 + 0x90);
  local_18 = *(int *)(*local_8 + 0x94);
  local_14 = *(int *)(*local_8 + 0x98);
  local_2c = *(int *)(*local_c + 0x90);
  local_28 = *(int *)(*local_c + 0x94);
  local_24 = *(int *)(*local_c + 0x98);
  if (local_1c < local_2c) {
    local_30 = local_30 | 1;
  }
  if (local_28 < local_18) {
    local_30 = local_30 | 2;
  }
  if (local_24 < local_14) {
    local_30 = local_30 | 4;
  }
  local_8 = (int *)0x40cfbf;
  __chkesp();
  return;
}

