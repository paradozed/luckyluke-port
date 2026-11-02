/* FUN_00438800 @ 00438800 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00438800(int param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int *local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != 0) {
    local_8 = *(int **)(param_1 + 0x30);
    while (local_8 != (int *)0x0) {
      local_c = (int *)local_8[1];
      if (*local_8 != 0) {
        *(int *)(*local_8 + 4) = local_8[1];
      }
      if (local_8[1] != 0) {
        *(int *)local_8[1] = *local_8;
      }
      if (local_8 == *(int **)(param_1 + 0x30)) {
        *(int *)(param_1 + 0x30) = local_8[1];
      }
      if (local_8 == *(int **)(param_1 + 0x34)) {
        *(int *)(param_1 + 0x34) = *local_8;
      }
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + local_8[2];
      _memset((void *)local_8[3],0xdd,local_8[2]);
      if (local_8 != (int *)0xdddddddd) {
        FUN_00495280(local_8);
      }
      local_8 = local_c;
    }
  }
  if ((param_2 != '\0') && (DAT_004e84d0 != 0)) {
    local_10 = *(int **)(DAT_004e84d0 + 0x30);
    while (local_10 != (int *)0x0) {
      local_14 = (int *)local_10[1];
      if (*local_10 != 0) {
        *(int *)(*local_10 + 4) = local_10[1];
      }
      if (local_10[1] != 0) {
        *(int *)local_10[1] = *local_10;
      }
      if (local_10 == *(int **)(DAT_004e84d0 + 0x30)) {
        *(int *)(DAT_004e84d0 + 0x30) = local_10[1];
      }
      if (local_10 == *(int **)(DAT_004e84d0 + 0x34)) {
        *(int *)(DAT_004e84d0 + 0x34) = *local_10;
      }
      *(int *)(DAT_004e84d0 + 8) = *(int *)(DAT_004e84d0 + 8) + local_10[2];
      _memset((void *)local_10[3],0xdd,local_10[2]);
      if (local_10 != (int *)0xdddddddd) {
        FUN_00495280(local_10);
      }
      local_10 = local_14;
    }
  }
  local_8 = (int *)0x4389e7;
  __chkesp();
  return;
}

