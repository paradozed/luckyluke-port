/* FUN_00474710 @ 00474710 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00474710(void)

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
  if (DAT_004e89a6 == '\0') {
    DAT_004e89c4 = DAT_004e8abc >> 5;
    if (DAT_004e89c0 == 0) {
      DAT_004e89c0 = DAT_004e8abc >> 5;
    }
    if (500 < DAT_004e89c4 - DAT_004e89c0) {
      DAT_004e89b4 = 0;
      DAT_004f1668 = '\0';
    }
  }
  if (DAT_004f1668 == '\0') {
    DAT_004e89b4 = 0;
    DAT_004f1674 = FUN_00474540;
    FUN_00474540();
  }
  uStack_8 = 0x4747af;
  __chkesp();
  return;
}

