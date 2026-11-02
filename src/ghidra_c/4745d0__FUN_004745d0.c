/* FUN_004745d0 @ 004745d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004745d0(void)

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
  DAT_004e89bc = 0;
  if (((DAT_004f2750 & 0x100) == 0) ||
     ((((DAT_004f1668 != '\0' && (DAT_004f1758 != '\0')) && (DAT_004f1800 != '\0')) &&
      (DAT_004f16a8 != '\0')))) {
    if (DAT_004f1758 == '\0') {
      if (DAT_004f1668 == '\0') {
        if (DAT_004f1800 == '\0') {
          if (DAT_004f16a8 != '\0') {
            DAT_004f1674 = FUN_00474860;
            FUN_00474860();
          }
        }
        else {
          DAT_004f1674 = FUN_00474860;
          FUN_00474860();
        }
      }
      else {
        DAT_004f1674 = FUN_00474860;
        FUN_00474860();
      }
    }
    else {
      DAT_004f1674 = FUN_00474860;
      FUN_00474860();
    }
  }
  else {
    DAT_004f1674 = FUN_00474860;
    FUN_00474860();
  }
  uStack_8 = 0x4746bb;
  __chkesp();
  return;
}

