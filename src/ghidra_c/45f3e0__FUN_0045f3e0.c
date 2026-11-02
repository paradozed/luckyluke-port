/* FUN_0045f3e0 @ 0045f3e0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045f3e0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = local_8 & 0xffffff00;
  DAT_004f173a = FUN_0045ea00();
  if (DAT_004f58df != '\0') {
    if (_DAT_004bdcf8 == 0xffffffff) {
      _DAT_004bdcf8 = FUN_0041fef0();
      _DAT_004bdcf8 = _DAT_004bdcf8 & 0xff;
      FUN_0041fe60(0);
    }
    else {
      FUN_0041fe60(DAT_004bdcf8);
      _DAT_004bdcf8 = 0xffffffff;
    }
  }
  if (((DAT_004f17ea == 1) && (DAT_004f58e7 != '\0')) ||
     ((DAT_004f17ea != 1 && (DAT_004f58f2 != '\0')))) {
    if (DAT_004bdcf4 == 0xffffffff) {
      uVar1 = FUN_004202a0();
      DAT_004bdcf4 = uVar1 & 0xff;
      FUN_00420240(0);
    }
    else {
      FUN_00420240((byte)DAT_004bdcf4);
      DAT_004bdcf4 = 0xffffffff;
    }
  }
  local_8 = 0x45f4cd;
  __chkesp();
  return;
}

