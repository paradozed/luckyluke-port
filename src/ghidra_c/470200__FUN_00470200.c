/* FUN_00470200 @ 00470200 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00470200(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  uint local_18;
  uint local_14;
  short local_10;
  short local_c;
  uint local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = **(int **)(param_1 + 0xc) - 1;
  local_c = *(short *)(param_1 + 0x3a);
  local_10 = *(short *)(param_1 + 0x3e);
  if (local_10 < 1) {
    if (local_c + -1 < 0) {
      *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) | 0x40;
      local_18 = *(ushort *)(param_1 + 0x40) & 3;
      if ((*(ushort *)(param_1 + 0x40) & 3) == 0) {
        local_c = (short)local_8;
        local_10 = *(short *)(*(int *)(param_1 + 0xc) + 0x10 + (short)local_8 * 0x10);
      }
      else if (local_18 == 1) {
        local_10 = 0;
      }
      else if (local_18 == 2) {
        local_10 = 0;
        *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) & 0xfff7;
      }
    }
    else {
      local_c = local_c + -1;
      local_10 = local_10 + *(short *)(*(int *)(param_1 + 0xc) + 0x10 + local_c * 0x10);
    }
  }
  else if ((int)local_c + 1U < local_8) {
    local_10 = local_10 - *(short *)(param_1 + 0x3c);
    local_c = local_c + 1;
  }
  else {
    *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) | 0x40;
    local_14 = *(ushort *)(param_1 + 0x40) & 3;
    if ((*(ushort *)(param_1 + 0x40) & 3) == 0) {
      local_c = 0;
      local_10 = 0;
    }
    else if (local_14 == 1) {
      local_10 = *(short *)(param_1 + 0x3c);
    }
    else if (local_14 == 2) {
      local_10 = *(short *)(param_1 + 0x3c);
      *(ushort *)(param_1 + 0x40) = *(ushort *)(param_1 + 0x40) | 8;
    }
  }
  FUN_004700c0(param_1,local_10,local_c);
  local_8 = 0x4703ad;
  __chkesp();
  return;
}

