/* FUN_0043f8d0 @ 0043f8d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0043f8d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e8508 != 0) {
    local_8 = FUN_0043f590();
  }
  if (local_8 == 0) {
    if (DAT_004e850c != 0) {
      local_8 = FUN_0043f6c0();
    }
    if ((local_8 == 0) && (DAT_004e8514 != 0)) {
      FUN_0043f760();
    }
  }
  local_8 = 0x43f948;
  __chkesp();
  return;
}

