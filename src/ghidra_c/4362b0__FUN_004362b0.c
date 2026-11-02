/* FUN_004362b0 @ 004362b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004362b0(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined4 local_80 [16];
  int local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  float local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_80;
  for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = *(int *)(param_1 + 0x18);
  local_c = *(int *)(param_1 + 0x1c);
  FUN_00497690((undefined4 *)(param_1 + 0x1b0 + param_3 * 0x28),param_2,0x28);
  if (*(short *)(param_2 + 4) < local_8) {
    *(undefined4 *)(param_1 + 0x340 + param_3 * 4) = 0;
  }
  else if (local_c < *(short *)(param_2 + 2)) {
    *(undefined4 *)(param_1 + 0x340 + param_3 * 4) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x340 + param_3 * 4) = 1;
    if (*(short *)(param_2 + 2) < local_8) {
      local_14 = local_8 - *(short *)(param_2 + 2);
      local_18 = (int)*(short *)(param_2 + 4) - (int)*(short *)(param_2 + 2);
      local_10 = (float)local_14 / (float)local_18;
      local_1c = (uint)*(byte *)(param_1 + 0x1bc + param_3 * 0x28);
      local_20 = (uint)*(byte *)(param_2 + 5) - (uint)*(byte *)(param_2 + 3);
      lVar3 = __ftol();
      *(char *)(param_1 + 0x1bc + param_3 * 0x28) = (char)lVar3;
      local_24 = (uint)*(byte *)(param_1 + 0x1cc + param_3 * 0x28);
      local_28 = (uint)*(byte *)(param_2 + 9) - (uint)*(byte *)(param_2 + 7);
      lVar3 = __ftol();
      *(char *)(param_1 + 0x1cc + param_3 * 0x28) = (char)lVar3;
      *(undefined2 *)(param_1 + 0x1b8 + param_3 * 0x28) = (undefined2)local_8;
      *(undefined2 *)(param_1 + 0x1c8 + param_3 * 0x28) = (undefined2)local_8;
    }
    if (local_c <= *(short *)(param_2 + 4)) {
      local_2c = *(short *)(param_2 + 4) - local_c;
      local_30 = (int)*(short *)(param_2 + 4) - (int)*(short *)(param_2 + 2);
      local_10 = (float)local_2c / (float)local_30;
      local_34 = (uint)*(byte *)(param_1 + 0x1c4 + param_3 * 0x28);
      local_38 = (uint)*(byte *)(param_2 + 5) - (uint)*(byte *)(param_2 + 3);
      lVar3 = __ftol();
      *(char *)(param_1 + 0x1c4 + param_3 * 0x28) = (char)lVar3;
      local_3c = (uint)*(byte *)(param_1 + 0x1d4 + param_3 * 0x28);
      local_40 = (uint)*(byte *)(param_2 + 9) - (uint)*(byte *)(param_2 + 7);
      lVar3 = __ftol();
      *(char *)(param_1 + 0x1d4 + param_3 * 0x28) = (char)lVar3;
      *(short *)(param_1 + 0x1c0 + param_3 * 0x28) = (short)local_c + -1;
      *(short *)(param_1 + 0x1d0 + param_3 * 0x28) = (short)local_c + -1;
    }
  }
  local_8 = 0x43654f;
  __chkesp();
  return;
}

