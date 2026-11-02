/* FUN_00474540 @ 00474540 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00474540(void)

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
  DAT_004f1792 = DAT_004f1792 + -2;
  local_8 = CONCAT22(local_8._2_2_,0x20);
  if (DAT_004f1792 < -0x1f) {
    DAT_004e89a5 = 0;
    DAT_004e89a6 = 0;
    DAT_004e89a7 = 0;
    DAT_004e89a8 = 0;
    DAT_004e89a9 = 0;
    DAT_004f1674 = FUN_004745d0;
    FUN_004745d0();
  }
  local_8 = 0x4745be;
  __chkesp();
  return;
}

