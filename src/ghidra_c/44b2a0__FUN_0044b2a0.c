/* FUN_0044b2a0 @ 0044b2a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0044b2a0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  uint local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e8601 != '\0') {
    local_8 = local_8 & 0xffffff00;
    while ((local_8 & 0xff) < 0x10) {
      (*DAT_004e8a24)(local_8 & 0xff,*(undefined4 *)(DAT_004f58a4 + (local_8 & 0xff) * 4));
      __chkesp();
      local_8 = CONCAT31(local_8._1_3_,(char)local_8 + '\x01');
    }
  }
  local_8 = 0x44b319;
  __chkesp();
  return;
}

