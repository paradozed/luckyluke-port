/* FUN_00494080 @ 00494080 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00494080(void)

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
  local_8 = 0;
  do {
    if (9 < local_8) {
LAB_004940f7:
      local_8 = 0x494104;
      __chkesp();
      return;
    }
    if ((&DAT_004e8c30)[local_8] != '\0') {
      (&DAT_004e8c30)[local_8] = 0;
      _memset(*(void **)(&DAT_004e8af0 + local_8 * 0x20),0,DAT_00508e2c);
      goto LAB_004940f7;
    }
    local_8 = local_8 + 1;
  } while( true );
}

