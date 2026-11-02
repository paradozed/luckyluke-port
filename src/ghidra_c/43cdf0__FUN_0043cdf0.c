/* FUN_0043cdf0 @ 0043cdf0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043cdf0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (((param_1 != 0) && (param_2 != 0)) && (*(int *)(param_1 + 0x5c) != 0)) {
    if (*(int *)(param_1 + 0x58) == 1) {
      if (*(int *)(param_1 + 0x5c) != -0x22222223) {
        FUN_00495280(*(void **)(param_1 + 0x5c));
      }
      *(undefined4 *)(param_1 + 0x5c) = 0;
      *(undefined4 *)(param_1 + 0x58) = 0;
    }
    else {
      local_c = *(int *)(param_1 + 0x58) + -1;
      local_8 = FUN_00494c40(local_c * 4,1);
      if (local_8 != 0) {
        local_14 = 0;
        for (local_10 = 0; local_10 < local_c; local_10 = local_10 + 1) {
          if (*(int *)(*(int *)(param_1 + 0x5c) + local_14 * 4) == param_2) {
            local_14 = local_14 + 1;
          }
          *(undefined4 *)(local_8 + local_10 * 4) =
               *(undefined4 *)(*(int *)(param_1 + 0x5c) + local_14 * 4);
          local_14 = local_14 + 1;
        }
        if (*(int *)(param_1 + 0x5c) != -0x22222223) {
          FUN_00495280(*(void **)(param_1 + 0x5c));
        }
        *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + -1;
        *(int *)(param_1 + 0x5c) = local_8;
      }
    }
  }
  local_8 = 0x43cf35;
  __chkesp();
  return;
}

