/* FUN_00469870 @ 00469870 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00469870(void)

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
  else {
    if ((((DAT_004f245c & 0x1000) != 0) && (DAT_004e8580 == '\0')) && (0 < DAT_004f1786)) {
      if ((*(uint *)(DAT_004f2458 + 0x10) & 8) == 0) {
        DAT_004f1786 = DAT_004f1786 + -1;
        DAT_004e8580 = '\x01';
      }
      else if ((*(uint *)(DAT_004f2458 + 0x10) & 0x10000) != 0) {
        DAT_004f1786 = DAT_004f1786 + -1;
        DAT_004e8580 = '\x01';
      }
    }
    FUN_004696b0();
    if ((DAT_004f245c & 0x8000) == 0) {
      if ((DAT_004f2438 & 0x40) == 0) {
        DAT_004f23f8 = FUN_00469c40;
        FUN_00469c40();
      }
      else if ((DAT_004f2438 & 0x2000) != 0) {
        DAT_004f23f8 = FUN_00467f60;
        FUN_00467f60();
      }
    }
    else {
      DAT_004f23f8 = FUN_00466900;
      FUN_00466900();
    }
  }
  uStack_8 = 0x4699a1;
  __chkesp();
  return;
}

