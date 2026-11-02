/* FUN_004551a0 @ 004551a0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004551a0(void)

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
  DAT_004e8664 = DAT_004e8664 + 1;
  if (DAT_004e8662 == '\x01') {
    for (local_8 = 0; local_8 < DAT_004bd5dc; local_8 = local_8 + 1) {
      FUN_004266b0();
    }
  }
  else {
    FUN_004266b0();
  }
  local_8 = 0x455260;
  __chkesp();
  return;
}

