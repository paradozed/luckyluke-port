/* FUN_00493310 @ 00493310 */
/* decompiled from Lucky.exe (Game.run) */


int FUN_00493310(void)

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
  while( true ) {
    if (DAT_00508a10 <= local_8) {
      return 0;
    }
    if (*(int *)(DAT_004e8c44 + local_8 * 0x14) == 0) break;
    local_8 = local_8 + 1;
  }
  return DAT_004e8c44 + local_8 * 0x14;
}

