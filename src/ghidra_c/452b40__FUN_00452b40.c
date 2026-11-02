/* FUN_00452b40 @ 00452b40 */
/* decompiled from Lucky.exe (Game.run) */


int FUN_00452b40(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e9378 < 0) {
    iVar1 = 0;
  }
  else if (DAT_004e9378 < (int)((uint)DAT_004e89f8 * (int)DAT_004bc4ec)) {
    iVar1 = DAT_004e9378 / (int)DAT_004bc4ec;
  }
  else {
    iVar1 = DAT_004e89f8 - 1;
  }
  return iVar1;
}

