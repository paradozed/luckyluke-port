/* FUN_00436560 @ 00436560 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Removing unreachable block (ram,0x00436d7f) */
/* WARNING: Removing unreachable block (ram,0x00436d58) */
/* WARNING: Removing unreachable block (ram,0x00436d2d) */
/* WARNING: Removing unreachable block (ram,0x00436da6) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00436560(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  longlong lVar3;
  undefined4 local_e8 [16];
  int local_a8;
  int local_a4;
  int local_a0;
  uint local_9c;
  int local_98;
  int local_94;
  int local_90;
  uint local_8c;
  int local_88;
  int local_84;
  int local_80;
  uint local_7c;
  int local_78;
  int local_74;
  int local_70;
  uint local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  int local_c;
  uint local_8;
  
  puVar2 = local_e8;
  for (iVar1 = 0x39; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0;
  local_c = 0;
  local_10 = 0.0;
  local_14 = 25.5;
  local_18 = (float)*(int *)(param_1 + 0x368) / _DAT_004b5d48;
  local_4c = *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x368);
  local_1c = (float)local_4c;
  local_50 = *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x368);
  local_20 = (float)local_50;
  while( true ) {
    for (; (*(int *)(param_1 + 0x340 + local_8 * 4) == 0 && (local_8 < *(uint *)(param_1 + 8)));
        local_8 = local_8 + 1) {
    }
    if (*(uint *)(param_1 + 8) <= local_8) break;
    local_54 = (int)*(short *)(param_1 + 0x1b8 + local_8 * 0x28);
    local_30 = (float)local_54;
    local_58 = (int)*(short *)(param_1 + 0x1c0 + local_8 * 0x28);
    local_2c = (float)local_58 - local_30;
    if (local_1c <= local_30) {
      FUN_00497690((undefined4 *)(param_1 + 0x36c + local_c * 0x28),
                   (undefined4 *)(param_1 + 0x1b0 + local_8 * 0x28),0x28);
      *(undefined2 *)(param_1 + 0x38a + local_c * 0x28) = 0xff;
      local_c = local_c + 1;
    }
    else {
      local_10 = _DAT_004b6324 -
                 (local_1c - local_30) * (_DAT_004b6324 / (float)*(int *)(param_1 + 0x368));
      lVar3 = __ftol();
      local_5c = (int)lVar3;
      local_24 = (float)local_5c * local_14;
      local_28 = local_24 + local_14;
      local_34 = ((local_28 - local_10) / local_14) * local_18;
      while( true ) {
        if (local_2c < local_34) {
          local_34 = local_2c;
        }
        if (_DAT_004b6324 <= local_10) {
          local_34 = local_2c;
        }
        FUN_00497690((undefined4 *)(param_1 + 0x36c + local_c * 0x28),
                     (undefined4 *)(param_1 + 0x1b0 + local_8 * 0x28),0x28);
        lVar3 = __ftol();
        *(short *)(param_1 + 0x374 + local_c * 0x28) = (short)lVar3;
        lVar3 = __ftol();
        *(short *)(param_1 + 0x37c + local_c * 0x28) = (short)lVar3;
        lVar3 = __ftol();
        *(short *)(param_1 + 900 + local_c * 0x28) = (short)lVar3;
        lVar3 = __ftol();
        *(short *)(param_1 + 0x38c + local_c * 0x28) = (short)lVar3;
        local_60 = (int)*(short *)(param_1 + 0x1b8 + local_8 * 0x28);
        local_64 = (int)*(short *)(param_1 + 0x1c0 + local_8 * 0x28) -
                   (int)*(short *)(param_1 + 0x1b8 + local_8 * 0x28);
        local_68 = (uint)*(byte *)(param_1 + 0x1c4 + local_8 * 0x28) -
                   (uint)*(byte *)(param_1 + 0x1bc + local_8 * 0x28);
        local_6c = (uint)*(byte *)(param_1 + 0x1bc + local_8 * 0x28);
        iVar1 = local_c * 0x28;
        lVar3 = __ftol();
        *(char *)(param_1 + 0x378 + iVar1) = (char)lVar3;
        local_70 = (int)*(short *)(param_1 + 0x1b8 + local_8 * 0x28);
        local_74 = (int)*(short *)(param_1 + 0x1c0 + local_8 * 0x28) -
                   (int)*(short *)(param_1 + 0x1b8 + local_8 * 0x28);
        local_78 = (uint)*(byte *)(param_1 + 0x1c4 + local_8 * 0x28) -
                   (uint)*(byte *)(param_1 + 0x1bc + local_8 * 0x28);
        local_7c = (uint)*(byte *)(param_1 + 0x1bc + local_8 * 0x28);
        iVar1 = local_c * 0x28;
        lVar3 = __ftol();
        *(char *)(param_1 + 0x380 + iVar1) = (char)lVar3;
        *(undefined1 *)(param_1 + 0x388 + local_c * 0x28) =
             *(undefined1 *)(param_1 + 0x378 + local_c * 0x28);
        *(undefined1 *)(param_1 + 0x390 + local_c * 0x28) =
             *(undefined1 *)(param_1 + 0x380 + local_c * 0x28);
        lVar3 = __ftol();
        *(short *)(param_1 + 0x38a + local_c * 0x28) = (short)lVar3;
        *(byte *)(param_1 + 0x373 + local_c * 0x28) =
             *(byte *)(param_1 + 0x373 + local_c * 0x28) | 2;
        local_c = local_c + 1;
        local_2c = local_2c - local_34;
        if (local_2c <= _DAT_004b4938) break;
        local_30 = local_30 + local_34;
        local_10 = (local_34 / local_18) * local_14 + local_10;
        local_34 = local_18;
      }
    }
    local_8 = local_8 + 1;
  }
  *(int *)(param_1 + 0xc) = local_c;
  local_c = 0;
  for (local_8 = 0; local_8 < *(uint *)(param_1 + 0xc); local_8 = local_8 + 1) {
    local_80 = (int)*(short *)(param_1 + 0x37c + local_8 * 0x28);
    local_44 = (float)local_80;
    local_84 = (int)*(short *)(param_1 + 0x374 + local_8 * 0x28);
    local_40 = local_44 - (float)local_84;
    if (local_44 <= local_20) {
      FUN_00497690((undefined4 *)(param_1 + 0x5c4 + local_c * 0x28),
                   (undefined4 *)(param_1 + 0x36c + local_8 * 0x28),0x28);
      local_c = local_c + 1;
    }
    else {
      local_10 = _DAT_004b6324 -
                 (local_44 - local_20) * (_DAT_004b6324 / (float)*(int *)(param_1 + 0x368));
      lVar3 = __ftol();
      local_88 = (int)lVar3;
      local_3c = (float)local_88 * local_14;
      local_38 = local_3c + local_14;
      local_48 = ((local_10 - local_3c) / local_14) * local_18;
      while( true ) {
        if (local_40 < local_48) {
          local_48 = local_40;
        }
        if (_DAT_004b6324 <= local_10) {
          local_48 = local_40;
          local_10 = 255.0;
        }
        FUN_00497690((undefined4 *)(param_1 + 0x5c4 + local_c * 0x28),
                     (undefined4 *)(param_1 + 0x36c + local_8 * 0x28),0x28);
        lVar3 = __ftol();
        *(short *)(param_1 + 0x5cc + local_c * 0x28) = (short)lVar3;
        lVar3 = __ftol();
        *(short *)(param_1 + 0x5d4 + local_c * 0x28) = (short)lVar3;
        *(undefined2 *)(param_1 + 0x5dc + local_c * 0x28) =
             *(undefined2 *)(param_1 + 0x5cc + local_c * 0x28);
        *(undefined2 *)(param_1 + 0x5e4 + local_c * 0x28) =
             *(undefined2 *)(param_1 + 0x5d4 + local_c * 0x28);
        local_8c = (uint)*(byte *)(param_1 + 0x380 + local_8 * 0x28);
        local_90 = (int)*(short *)(param_1 + 0x37c + local_8 * 0x28);
        local_94 = (int)*(short *)(param_1 + 0x37c + local_8 * 0x28) -
                   (int)*(short *)(param_1 + 0x374 + local_8 * 0x28);
        local_98 = (uint)*(byte *)(param_1 + 0x380 + local_8 * 0x28) -
                   (uint)*(byte *)(param_1 + 0x378 + local_8 * 0x28);
        iVar1 = local_c * 0x28;
        lVar3 = __ftol();
        *(char *)(param_1 + 0x5d8 + iVar1) = (char)lVar3;
        local_9c = (uint)*(byte *)(param_1 + 0x380 + local_8 * 0x28);
        local_a0 = (int)*(short *)(param_1 + 0x37c + local_8 * 0x28);
        local_a4 = (int)*(short *)(param_1 + 0x37c + local_8 * 0x28) -
                   (int)*(short *)(param_1 + 0x374 + local_8 * 0x28);
        local_a8 = (uint)*(byte *)(param_1 + 0x380 + local_8 * 0x28) -
                   (uint)*(byte *)(param_1 + 0x378 + local_8 * 0x28);
        iVar1 = local_c * 0x28;
        lVar3 = __ftol();
        *(char *)(param_1 + 0x5d0 + iVar1) = (char)lVar3;
        *(undefined1 *)(param_1 + 0x5e0 + local_c * 0x28) =
             *(undefined1 *)(param_1 + 0x5d0 + local_c * 0x28);
        *(undefined1 *)(param_1 + 0x5e8 + local_c * 0x28) =
             *(undefined1 *)(param_1 + 0x5d8 + local_c * 0x28);
        lVar3 = __ftol();
        *(short *)(param_1 + 0x5e2 + local_c * 0x28) = (short)lVar3;
        *(byte *)(param_1 + 0x5cb + local_c * 0x28) =
             *(byte *)(param_1 + 0x5cb + local_c * 0x28) | 2;
        local_c = local_c + 1;
        local_40 = local_40 - local_48;
        if (local_40 <= _DAT_004b4938) break;
        local_44 = local_44 - local_48;
        local_10 = (local_48 / local_18) * local_14 + local_10;
        local_48 = local_18;
      }
    }
  }
  *(int *)(param_1 + 0xc) = local_c;
  local_8 = 0x436ed7;
  __chkesp();
  return;
}

