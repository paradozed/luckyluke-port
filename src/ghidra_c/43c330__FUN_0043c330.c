/* FUN_0043c330 @ 0043c330 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0043c330(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  void *local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = (void *)FUN_00494c40(0x60,1);
  if (local_8 != (void *)0x0) {
    _memset(local_8,0,0x60);
  }
  local_8 = (void *)0x43c381;
  __chkesp();
  return;
}

