/* FUN_00474860 @ 00474860 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00474860(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  DAT_004f1792 = DAT_004f1792 + 2;
  local_8 = CONCAT22(local_8._2_2_,0x10);
  if (0xf < DAT_004f1792) {
    if (DAT_004f1758 == '\0') {
      if (DAT_004f1668 == '\0') {
        if (DAT_004f1800 == '\0') {
          if (DAT_004f16a8 == '\0') {
            DAT_004f1674 = FUN_00474440;
            FUN_00474440();
          }
          else {
            DAT_004e89a8 = 1;
            DAT_004f1674 = FUN_00474810;
            FUN_00474810();
          }
        }
        else {
          DAT_004e89a7 = 1;
          DAT_004f1674 = FUN_004747c0;
          FUN_004747c0();
        }
      }
      else {
        DAT_004e89a6 = 1;
        DAT_004f1674 = FUN_00474710;
        FUN_00474710();
      }
    }
    else {
      DAT_004e89a5 = 1;
      DAT_004f1674 = FUN_004746c0;
      FUN_004746c0();
    }
  }
  local_8 = 0x47494b;
  __chkesp();
  return;
}

