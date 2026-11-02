/* FUN_004064e0 @ 004064e0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_004064e0(void)

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
  if (DAT_004e85b8 == 1) {
    DAT_004f1794 = DAT_004f1794 & 0xfffe;
    DAT_004e866c = '\0';
    DAT_004d1db5 = '\0';
  }
  if ((((DAT_004f1794 & 1) == 0) || (DAT_004e866c == '\0')) && (DAT_004d1db5 == '\0')) {
    local_8 = 0;
  }
  else {
    local_8 = 1;
  }
  return local_8;
}

