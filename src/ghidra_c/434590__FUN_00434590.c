/* FUN_00434590 @ 00434590 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00434590(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_154 [81];
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar2 = local_154;
  for (iVar1 = 0x54; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0;
  local_c = 0;
  iVar1 = Ordinal_11(&local_8,&local_c);
  if (iVar1 == 0) {
    FUN_00434420((HWND)0x0);
  }
  else if (local_8 < 0x40006) {
    MessageBoxA((HWND)0x0,DAT_004f5e00,DAT_004f5de4,1);
    local_10 = __chkesp();
    if (local_10 == 2) {
      FUN_00496ef0(0xffffffff);
    }
    FUN_00434420((HWND)0x0);
  }
  local_10 = 0x43462c;
  __chkesp();
  return;
}

