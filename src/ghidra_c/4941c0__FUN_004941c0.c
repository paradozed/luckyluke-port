/* FUN_004941c0 @ 004941c0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_004941c0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  char local_c;
  uint local_8;
  
  uVar1 = 0xcccccccc;
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_c = '\0';
  local_8 = 0;
  while (local_8 < 10) {
    if ((&DAT_004e8c30)[local_8] == '\0') {
      local_c = local_c + '\x01';
    }
    uVar1 = local_8 + 1;
    local_8 = uVar1;
  }
  return CONCAT31((int3)(uVar1 >> 8),local_c);
}

