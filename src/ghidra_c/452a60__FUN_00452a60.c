/* FUN_00452a60 @ 00452a60 */
/* decompiled from Lucky.exe (Game.run) */


int FUN_00452a60(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e9370 < 0) {
    iVar1 = 0;
  }
  else if ((int)((uint)DAT_004e89f4 * (int)DAT_004bc4e8) < DAT_004e9370) {
    iVar1 = DAT_004e89f4 - 1;
  }
  else {
    iVar1 = DAT_004e9370 / (int)DAT_004bc4e8;
  }
  return iVar1;
}

