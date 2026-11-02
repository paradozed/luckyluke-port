/* FUN_00466740 @ 00466740 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00466740(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((*(uint *)(DAT_004f2458 + 0x10) & 0x20) == 0) {
    DAT_004f23f8 = FUN_00467dd0;
    FUN_00467dd0();
  }
  else if ((DAT_004f2438 & 0x2000) == 0) {
    if (((DAT_004f2438 & 0x8000) == 0) || ((*(uint *)(DAT_004f2458 + 0x10) & 0x40000) == 0)) {
      iVar1 = FUN_004696b0();
      if (iVar1 == 0) {
        if ((DAT_004f2438 & 0x40) == 0) {
          if ((((DAT_004f245c & 0x1000) != 0) && (DAT_004e8580 == '\0')) && (0 < DAT_004f1786)) {
            if ((*(uint *)(DAT_004f2458 + 0x10) & 8) == 0) {
              DAT_004f1786 = DAT_004f1786 + -1;
              DAT_004e8580 = '\x01';
              DAT_004f23f8 = FUN_00469b00;
              FUN_00469b00();
            }
            else if ((*(uint *)(DAT_004f2458 + 0x10) & 0x10000) != 0) {
              DAT_004f1786 = DAT_004f1786 + -1;
              DAT_004e8580 = '\x01';
              DAT_004f23f8 = FUN_00469b00;
              FUN_00469b00();
            }
          }
        }
        else {
          DAT_004f23f8 = FUN_00469b00;
          FUN_00469b00();
        }
      }
      else {
        DAT_004f23f8 = FUN_00466cf0;
        FUN_00466cf0();
      }
    }
    else if ((DAT_004f2438 & 0x4000) == 0) {
      DAT_004f23f8 = FUN_004678c0;
      FUN_004678c0();
    }
    else {
      DAT_004f23f8 = FUN_00467830;
      FUN_00467830();
    }
  }
  else {
    DAT_004f23f8 = FUN_00467f60;
    FUN_00467f60();
  }
  uStack_8 = 0x4668f0;
  __chkesp();
  return;
}

