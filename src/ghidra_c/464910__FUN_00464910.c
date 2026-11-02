/* FUN_00464910 @ 00464910 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00464910(void)

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
  if ((DAT_004f2744 & 0x8000) == 0) {
    if (((DAT_004f2744 & 0x10) == 0) || ((DAT_004f2750 & 0x4000) == 0)) {
      if (((DAT_004f2744 & 0x40) == 0) || ((DAT_004f2750 & 0x4000) == 0)) {
        if ((DAT_004f2750 & 0x4000) != 0) {
          DAT_004e8816 = 4;
          if (DAT_004bdd4c == '\0') {
            DAT_004e8814 = 0;
            DAT_004bdd4c = '\x01';
            DAT_004f23f8 = FUN_00463e00;
          }
          else {
            DAT_004e8814 = 1;
            DAT_004bdd4c = '\0';
            DAT_004f23f8 = FUN_00463c70;
          }
        }
      }
      else {
        DAT_004e8816 = 2;
        if (DAT_004bdd4c == '\0') {
          DAT_004e8814 = 4;
          DAT_004bdd4c = '\x01';
          DAT_004f23f8 = FUN_004645f0;
        }
        else {
          DAT_004e8814 = 5;
          DAT_004bdd4c = '\0';
          DAT_004f23f8 = FUN_00464450;
        }
      }
    }
    else {
      DAT_004e8816 = 4;
      if (DAT_004bdd4c == '\0') {
        DAT_004e8814 = 2;
        DAT_004bdd4c = '\x01';
        DAT_004f23f8 = FUN_004641f0;
      }
      else {
        DAT_004e8814 = 3;
        DAT_004bdd4c = '\0';
        DAT_004f23f8 = FUN_00463f90;
      }
    }
  }
  else if ((DAT_004f2744 & 0x40) == 0) {
    DAT_004f23f8 = FUN_00463bd0;
    FUN_00463bd0();
  }
  else {
    DAT_004f23f8 = FUN_00463b20;
    FUN_00463b20();
  }
  uStack_8 = 0x464aa8;
  __chkesp();
  return;
}

