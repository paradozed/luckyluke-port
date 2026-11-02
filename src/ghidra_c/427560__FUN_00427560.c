/* FUN_00427560 @ 00427560 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00427560(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  float local_10;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004d2924 != _DAT_004d2920) {
    if (_DAT_004b4938 <= DAT_004d2924 - _DAT_004d2920) {
      local_10 = DAT_004d2924 - _DAT_004d2920;
    }
    else {
      local_10 = -(DAT_004d2924 - _DAT_004d2920);
    }
    if ((float)_DAT_004b4930 < local_10) {
      if ((float)_DAT_004b4928 <= local_10) {
        _DAT_004d2928 = (_DAT_004d2920 - DAT_004d2924) / local_10;
      }
      else {
        _DAT_004d2928 = (DAT_004d2924 - _DAT_004d2920) / local_10;
      }
    }
    else {
      _DAT_004d2928 = 0.0;
      _DAT_004d2920 = DAT_004d2924;
    }
    _DAT_004d2928 = _DAT_004d2928 + _DAT_004d2928;
  }
  return;
}

