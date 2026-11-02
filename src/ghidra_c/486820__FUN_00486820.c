/* FUN_00486820 @ 00486820 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00486820(int param_1,short *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_1a8 [16];
  int local_168 [43];
  int local_bc [42];
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  puVar3 = local_1a8;
  for (iVar2 = 0x69; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  local_8 = (int *)(*(int *)(param_1 + 0x28) + -4);
  do {
    iVar2 = local_14;
    local_8 = local_8 + 1;
    local_168[0] = *local_8;
    if (local_168[0] == -3) {
      local_c = local_168[local_14];
    }
    else if (local_168[0] == -2) {
      local_14 = local_14 + -1;
      local_c = local_168[iVar2];
    }
    else if (local_168[0] == -1) {
      local_168[local_14 + 1] = local_10;
      local_14 = local_14 + 1;
      local_10 = local_c;
    }
    else {
      local_bc[local_c] = *local_8;
      local_c = local_c + 1;
    }
  } while (*local_8 != (int)*param_2);
  *(int *)(param_2 + 0x16) = local_c;
  uVar1 = FUN_00439af0(local_c << 2);
  *(undefined4 *)(param_2 + 0x18) = uVar1;
  FUN_00497690(*(undefined4 **)(param_2 + 0x18),local_bc,local_c << 2);
  local_8 = (int *)0x486949;
  __chkesp();
  return;
}

