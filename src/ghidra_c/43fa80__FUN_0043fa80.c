/* FUN_0043fa80 @ 0043fa80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043fa80(void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  void *local_c;
  void *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (param_1 != (void *)0x0) {
    local_8 = *(void **)((int)param_1 + 0x100);
    while (local_8 != (void *)0x0) {
      local_c = *(void **)((int)local_8 + 0xc);
      if ((local_8 != (void *)0x0) && (local_8 != (void *)0xdddddddd)) {
        FUN_00495280(local_8);
      }
      local_8 = local_c;
    }
    if (param_1 != (void *)0xdddddddd) {
      FUN_00495280(param_1);
    }
  }
  local_8 = (void *)0x43fb02;
  __chkesp();
  return;
}

