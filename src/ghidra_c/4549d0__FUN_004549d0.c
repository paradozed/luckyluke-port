/* FUN_004549d0 @ 004549d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004549d0(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar3 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = DAT_004f2744;
  if (((DAT_004f2744 & 0x800) != 0) && ((DAT_004f2744 & 0x80) != 0)) {
    DAT_004f2c50 = DAT_004f2c50 + -200;
  }
  if (((DAT_004f2744 & 0x800) != 0) && ((DAT_004f2744 & 0x20) != 0)) {
    DAT_004f2c50 = DAT_004f2c50 + 200;
  }
  if (((DAT_004f2744 & 0x800) != 0) && ((DAT_004f2744 & 0x10) != 0)) {
    DAT_004f2c54 = DAT_004f2c54 + -200;
  }
  if (((DAT_004f2744 & 0x800) != 0) && ((DAT_004f2744 & 0x40) != 0)) {
    DAT_004f2c54 = DAT_004f2c54 + 200;
  }
  if (((DAT_004f2744 & 0x800) != 0) && ((DAT_004f2744 & 0x400) != 0)) {
    DAT_004f2c58 = DAT_004f2c58 + -200;
  }
  if (((DAT_004f2744 & 0x800) != 0) && ((DAT_004f2744 & 0x100) != 0)) {
    DAT_004f2c58 = DAT_004f2c58 + 200;
  }
  if (((DAT_004f2744 & 0x200) != 0) && ((DAT_004f2744 & 0x10) != 0)) {
    DAT_004f2c40 = DAT_004f2c40 + -8;
  }
  if (((DAT_004f2744 & 0x200) != 0) && ((DAT_004f2744 & 0x40) != 0)) {
    DAT_004f2c40 = DAT_004f2c40 + 8;
  }
  if (((DAT_004f2744 & 0x200) != 0) && ((DAT_004f2744 & 0x80) != 0)) {
    DAT_004f2c42 = DAT_004f2c42 + 8;
  }
  if (((DAT_004f2744 & 0x200) != 0) && ((DAT_004f2744 & 0x20) != 0)) {
    DAT_004f2c42 = DAT_004f2c42 + -8;
  }
  if (((DAT_004f2744 & 0x200) != 0) && ((DAT_004f2744 & 0x400) != 0)) {
    DAT_004f2c44 = DAT_004f2c44 + -8;
  }
  if (((DAT_004f2744 & 0x200) != 0) && ((DAT_004f2744 & 0x100) != 0)) {
    DAT_004f2c44 = DAT_004f2c44 + 8;
  }
  uVar2 = (int)DAT_004f2c40 & 0x80000fff;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffff000) + 1;
  }
  DAT_004f2c40 = (short)uVar2;
  uVar2 = (int)DAT_004f2c42 & 0x80000fff;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffff000) + 1;
  }
  DAT_004f2c42 = (short)uVar2;
  uVar2 = (int)DAT_004f2c44 & 0x80000fff;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffff000) + 1;
  }
  DAT_004f2c44 = (short)uVar2;
  if (DAT_004f2bfa == 2) {
    if (DAT_004e866c == '\0') {
      if (DAT_004f2c04 < DAT_004f2c50) {
        DAT_004f2c50 = DAT_004f2c04;
      }
      if (DAT_004f2c50 < DAT_004f2c00) {
        DAT_004f2c50 = DAT_004f2c00;
      }
      if (DAT_004f2c0c < DAT_004f2c54) {
        DAT_004f2c54 = DAT_004f2c0c;
      }
      if (DAT_004f2c54 < DAT_004f2c08) {
        DAT_004f2c54 = DAT_004f2c08;
      }
      if (DAT_004f2c14 < DAT_004f2c58) {
        DAT_004f2c58 = DAT_004f2c14;
      }
      if (DAT_004f2c58 < DAT_004f2c10) {
        DAT_004f2c58 = DAT_004f2c10;
      }
    }
    DAT_004e8688 = DAT_004f2c40;
    DAT_004e868a = DAT_004f2c42;
    DAT_004e868c = DAT_004f2c44;
    FUN_00453540(&DAT_004bd6a0,&DAT_004f2c50);
    if (DAT_004f2bf8 != 0xb) {
      FUN_00451500(&DAT_004f2c50,&DAT_004f2c40,DAT_004f2bd4);
    }
  }
  local_8 = 0x454d4c;
  __chkesp();
  return;
}

