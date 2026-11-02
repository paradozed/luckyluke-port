/* FUN_004300e0 @ 004300e0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004300e0(void)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 *puVar2;
  float10 fVar3;
  longlong lVar4;
  undefined4 local_78 [16];
  uint local_38;
  uint local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  float local_c;
  float local_8;
  
  puVar2 = local_78;
  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e8750 == 0) {
    *(undefined1 *)(DAT_004f6124 + 0xd) = 0;
    *(undefined1 *)(DAT_004f6124 + 0x15) = 0;
    *(undefined1 *)(DAT_004f6124 + 0x1d) = 99;
    *(undefined1 *)(DAT_004f6124 + 0x25) = 99;
  }
  else {
    *(undefined1 *)(DAT_004f6124 + 0xd) = 100;
    *(undefined1 *)(DAT_004f6124 + 0x15) = 100;
    *(undefined1 *)(DAT_004f6124 + 0x1d) = 199;
    *(undefined1 *)(DAT_004f6124 + 0x25) = 199;
  }
  if (DAT_004e8478 == 1) {
    for (local_10 = 0; local_10 < 1; local_10 = local_10 + 1) {
      local_1c = (uint)*(byte *)(DAT_004f6124 + 0xc + local_10 * 0x28);
      local_8 = ((float)local_1c / _DAT_004b5d5c) * _DAT_004b5d58;
      fVar3 = (float10)FUN_00497f54(DAT_004f6124);
      local_20 = (float)fVar3;
      local_24 = (float)fVar3;
      fVar3 = (float10)FUN_00497f54(extraout_ECX);
      local_28 = (float)fVar3;
      local_2c = (float)(fVar3 + (float10)local_24);
      fVar3 = (float10)FUN_00498004(extraout_ECX_00);
      local_30 = (float)fVar3;
      local_c = (float)((fVar3 + (float10)local_2c) * (float10)_DAT_004b5d48 +
                       (float10)_DAT_004bc73c);
      *(float *)(&DAT_004f6120 + local_10 * 4) = local_c;
    }
    local_18 = 0;
    for (local_14 = 0; local_14 < 1; local_14 = local_14 + 1) {
      for (local_10 = 0; local_10 < 1; local_10 = local_10 + 1) {
        if (_DAT_004b4938 <= *(float *)(&DAT_004f6120 + local_10 * 4)) {
          local_34 = (uint)*(byte *)(DAT_004f6124 + 0xd + local_18 * 0x28);
          if (*(float *)(&DAT_004f6120 + local_10 * 4) <= (float)local_34) {
            *(undefined1 *)(DAT_004f6128 + local_18) = 0xff;
          }
          else {
            local_38 = (uint)*(byte *)(DAT_004f6124 + 0xd + local_18 * 0x28);
            lVar4 = __ftol();
            *(char *)(DAT_004f6128 + local_18) = (char)lVar4;
          }
        }
        else {
          *(undefined1 *)(DAT_004f6128 + local_18) = 0xff;
        }
        local_18 = local_18 + 1;
      }
    }
    _DAT_004bc73c = _DAT_004bc73c - _DAT_004b4078;
    _DAT_004bc740 = _DAT_004bc740 - _DAT_004b4078;
  }
  if (DAT_004e8478 == 3) {
    for (local_10 = 0; local_10 < 1; local_10 = local_10 + 1) {
      *(undefined1 *)(DAT_004f6128 + local_10) = 0xff;
    }
  }
  _DAT_004e847c = _DAT_004e847c + _DAT_004b5d40;
  local_8 = 6.154235e-39;
  __chkesp();
  return;
}

