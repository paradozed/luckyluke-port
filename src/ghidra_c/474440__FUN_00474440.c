/* FUN_00474440 @ 00474440 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00474440(void)

{
  int iVar1;
  ushort uVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  undefined4 local_8;
  
  puVar3 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  DAT_004e89bc = 1;
  if (((DAT_004f2750 & 0x100) == 0) ||
     ((((DAT_004f1668 != '\0' && (DAT_004f1758 != '\0')) && (DAT_004f1800 != '\0')) &&
      (DAT_004f16a8 != '\0')))) {
    for (uVar2 = 0; uVar2 < 5; uVar2 = uVar2 + 1) {
      if (*(int *)(&DAT_004f1798 + (uint)uVar2 * 4) != 0) {
        DAT_004e89a9 = 1;
      }
    }
    if (DAT_004f1758 != '\0') {
      DAT_004e89a5 = 1;
    }
    if (DAT_004f1668 != '\0') {
      DAT_004e89a6 = 1;
    }
    if (DAT_004f1800 != '\0') {
      DAT_004e89a7 = 1;
    }
  }
  else {
    DAT_004f1674 = FUN_00474540;
    FUN_00474540();
  }
  local_8 = 0x47452f;
  __chkesp();
  return;
}

