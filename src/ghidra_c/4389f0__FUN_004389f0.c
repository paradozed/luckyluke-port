/* FUN_004389f0 @ 004389f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004389f0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  int local_10;
  int *local_c;
  int *local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (param_1 != 0) {
    piVar1 = *(int **)(DAT_004e84d0 + 0x30);
    do {
      local_8 = piVar1;
      if (local_8 == (int *)0x0) goto LAB_00438b03;
      local_c = (int *)local_8[1];
      piVar1 = local_c;
    } while (param_1 != local_8[3]);
    if (*local_8 != 0) {
      *(int *)(*local_8 + 4) = local_8[1];
    }
    if (local_8[1] != 0) {
      *(int *)local_8[1] = *local_8;
    }
    if (local_8 == *(int **)(DAT_004e84d0 + 0x30)) {
      *(int *)(DAT_004e84d0 + 0x30) = local_8[1];
    }
    if (local_8 == *(int **)(DAT_004e84d0 + 0x34)) {
      *(int *)(DAT_004e84d0 + 0x34) = *local_8;
    }
    *(int *)(DAT_004e84d0 + 8) = *(int *)(DAT_004e84d0 + 8) + local_8[2];
    _memset((void *)local_8[3],0xdd,local_8[2]);
    if (local_8 != (int *)0xdddddddd) {
      FUN_00495280(local_8);
    }
    DAT_004e84e0 = DAT_004e84d0;
LAB_00438b03:
    if (local_8 == (int *)0x0) {
      for (local_10 = DAT_004e84d8; local_10 != 0; local_10 = *(int *)(local_10 + 0x38)) {
        if (local_10 != DAT_004e84d0) {
          piVar1 = *(int **)(local_10 + 0x30);
          while (local_8 = piVar1, local_8 != (int *)0x0) {
            local_c = (int *)local_8[1];
            piVar1 = local_c;
            if (param_1 == local_8[3]) {
              if (*local_8 != 0) {
                *(int *)(*local_8 + 4) = local_8[1];
              }
              if (local_8[1] != 0) {
                *(int *)local_8[1] = *local_8;
              }
              if (local_8 == *(int **)(local_10 + 0x30)) {
                *(int *)(local_10 + 0x30) = local_8[1];
              }
              if (local_8 == *(int **)(local_10 + 0x34)) {
                *(int *)(local_10 + 0x34) = *local_8;
              }
              *(int *)(local_10 + 8) = *(int *)(local_10 + 8) + local_8[2];
              _memset((void *)local_8[3],0xdd,local_8[2]);
              DAT_004e84e0 = local_10;
              if (local_8 != (int *)0xdddddddd) {
                FUN_00495280(local_8);
              }
              goto LAB_00438c1b;
            }
          }
        }
      }
    }
  }
LAB_00438c1b:
  local_8 = (int *)0x438c28;
  __chkesp();
  return;
}

