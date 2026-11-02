/* FUN_00474a20 @ 00474a20 */
/* decompiled from Lucky.exe (Game.run) */


uint FUN_00474a20(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_48 [17];
  
  uVar1 = DAT_004e8916;
  puVar4 = local_48;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  uVar2 = (uint)DAT_004e8916;
  if (uVar2 == 0x1d) {
    DAT_004e8916 = 0;
    uVar2 = CONCAT31((uint3)(byte)(uVar1 >> 8),1);
  }
  else if ((((DAT_004e8914 == 3) || (DAT_004e8914 == 0xb)) ||
           (uVar2 = (uint)DAT_004e8914, uVar2 == 0x18)) ||
          ((DAT_004e8914 == 0x15 || (DAT_004e8914 == 0x16)))) {
    uVar2 = CONCAT31((int3)(uVar2 >> 8),1);
  }
  else if (DAT_004e8914 == 1) {
    uVar2 = 1;
  }
  else if (DAT_004f1788 < 4) {
    if (DAT_004f1784 < 0x1e) {
      if ((DAT_004e89c8 == '\0') && (DAT_004e89c9 == '\0')) {
        uVar2 = (uint)(byte)(DAT_004e8914 >> 8) << 8;
      }
      else {
        DAT_004e89c8 = '\0';
        DAT_004e89c9 = '\0';
        DAT_004e8914 = DAT_004e8916;
        DAT_004e8916 = 0;
        uVar2 = (uint)(uVar1 >> 8) << 8;
      }
    }
    else if (DAT_004e89c8 == '\0') {
      if ((DAT_004e89c9 == '\0') &&
         (((((DAT_004e8916 == 4 || (DAT_004e8916 == 6)) || (DAT_004e8916 == 8)) ||
           ((DAT_004e8916 == 0xc || (DAT_004e8916 == 0xe)))) ||
          ((DAT_004e8916 == 0x10 || (DAT_004e8916 == 0x13)))))) {
        DAT_004e8916 = DAT_004e8914;
        uVar2 = DAT_004e8914 & 0xffffff00;
      }
      else {
        if (DAT_004e89c9 == '\0') {
          DAT_004e8916 = DAT_004e8914;
        }
        DAT_004e8914 = DAT_004be1f6;
        DAT_004e89c9 = '\0';
        DAT_004e89c8 = '\x01';
        uVar2 = CONCAT31((uint3)(byte)(DAT_004be1f6 >> 8),1);
      }
    }
    else {
      DAT_004e89c8 = '\0';
      DAT_004e8914 = DAT_004e8916;
      uVar2 = (uint)(DAT_004e8916 >> 8) << 8;
    }
  }
  else {
    DAT_004e89c9 = '\x01';
    DAT_004e8916 = DAT_004e8914;
    DAT_004f1788 = 0;
    DAT_004e898e = DAT_004e898e + 1;
    if (2 < DAT_004e898e) {
      DAT_004e898e = 0;
    }
    DAT_004e8914 = (&DAT_004be1f0)[DAT_004e898e];
    uVar2 = CONCAT31((uint3)(byte)(DAT_004e8914 >> 8),1);
  }
  return uVar2;
}

