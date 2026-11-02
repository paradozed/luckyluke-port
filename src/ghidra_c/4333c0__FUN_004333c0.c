/* FUN_004333c0 @ 004333c0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_004333c0(HWND param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0;
  local_c = 0;
  iVar1 = FUN_00442670('\x01');
  if (iVar1 == 0) {
    _DAT_004e84ac = 1;
  }
  else {
    FUN_00442860("Game Data",(LPBYTE)&local_8);
    FUN_00442860("Movies",(LPBYTE)&local_c);
    if ((local_8 == 0) || (local_c == 0)) {
      do {
        iVar1 = FUN_004331b0("Lucky Luke On The Daltons Trail",(uint *)0x0);
        if (iVar1 != 0) {
          FUN_00442770();
          goto LAB_00433495;
        }
        MessageBoxA(param_1,DAT_004f5df8,DAT_004f5de4,5);
        local_10 = __chkesp();
      } while (local_10 != 2);
      FUN_00442770();
    }
    else {
      FUN_00442770();
    }
  }
LAB_00433495:
  local_8 = 0x4334a2;
  __chkesp();
  return;
}

