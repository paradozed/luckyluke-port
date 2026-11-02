/* FUN_0047fbe0 @ 0047fbe0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047fbe0(int param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_64 [17];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  puVar2 = local_64;
  for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0x7fffffff;
  local_10 = 0x7fffffff;
  local_14 = 0x7fffffff;
  local_18 = -0x80000000;
  local_1c = -0x80000000;
  local_20 = -0x80000000;
  iVar1 = *(int *)(param_1 + 0xbc);
  for (local_8 = 2; local_8 < *(int *)(param_1 + 0x10) - 2U; local_8 = local_8 + 1) {
    if (*(short *)(iVar1 + local_8 * 8) < local_c) {
      local_c = (int)*(short *)(iVar1 + local_8 * 8);
    }
    if (local_18 < *(short *)(iVar1 + local_8 * 8)) {
      local_18 = (int)*(short *)(iVar1 + local_8 * 8);
    }
    if (*(short *)(iVar1 + 2 + local_8 * 8) < local_10) {
      local_10 = (int)*(short *)(iVar1 + 2 + local_8 * 8);
    }
    if (local_1c < *(short *)(iVar1 + 2 + local_8 * 8)) {
      local_1c = (int)*(short *)(iVar1 + 2 + local_8 * 8);
    }
    if (*(short *)(iVar1 + 4 + local_8 * 8) < local_14) {
      local_14 = (int)*(short *)(iVar1 + 4 + local_8 * 8);
    }
    if (local_20 < *(short *)(iVar1 + 4 + local_8 * 8)) {
      local_20 = (int)*(short *)(iVar1 + 4 + local_8 * 8);
    }
  }
  *param_2 = local_c;
  param_2[1] = local_10;
  param_2[2] = local_14;
  param_2[3] = local_18;
  param_2[4] = local_1c;
  param_2[5] = local_20;
  return;
}

