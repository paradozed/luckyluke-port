/* FUN_00440fb0 @ 00440fb0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00440fb0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((DAT_004e853c & 1) == 1) {
    _DAT_004e853e = _DAT_004e853e + -8;
    if (_DAT_004e853e < 1) {
      _DAT_004e853e = 0;
      DAT_004e853c = 0;
      DAT_004f2e0c = 1;
    }
  }
  else if ((DAT_004e853c & 2) == 2) {
    _DAT_004e853e = _DAT_004e853e + 8;
    if (0xfe < _DAT_004e853e) {
      _DAT_004e853e = 0xff;
      DAT_004e853c = 0;
      DAT_004f2e0c = 1;
    }
  }
  else if ((DAT_004e853c & 4) == 4) {
    _DAT_004e853e = 0xff;
  }
  return;
}

