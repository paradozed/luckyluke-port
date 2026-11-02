/* FUN_0043da80 @ 0043da80 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0043da80(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e84fc == 0) {
    DAT_004bcc98 = DAT_004bcc98 + -1;
    DAT_004bcc9c = DAT_004bcc9c + 1;
    if (DAT_004bcc98 == 0) {
      DAT_004e84fc = 1;
      return;
    }
  }
  if (DAT_004e84fc == 1) {
    DAT_004bcc9c = DAT_004bcc9c + -1;
    DAT_004bcca0 = DAT_004bcca0 + 1;
    if (DAT_004bcc9c == 0) {
      DAT_004e84fc = 2;
      return;
    }
  }
  if (DAT_004e84fc == 2) {
    DAT_004bcca0 = DAT_004bcca0 + -1;
    DAT_004bcc98 = DAT_004bcc98 + 1;
    if (DAT_004bcca0 == 0) {
      DAT_004e84fc = 0;
    }
  }
  return;
}

