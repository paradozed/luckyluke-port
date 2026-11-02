/* FUN_00452ad0 @ 00452ad0 */
/* decompiled from Lucky.exe (Game.run) */


int FUN_00452ad0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e9374 < 1) {
    if ((int)((uint)DAT_004e89f6 * (int)DAT_004bc4ea) < DAT_004e9374) {
      iVar1 = DAT_004e9374 / (int)DAT_004bc4ea;
    }
    else {
      iVar1 = DAT_004e89f6 - 1;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

