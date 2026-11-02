/* FUN_00434630 @ 00434630 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00434630(HWND param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_250 [16];
  BYTE local_210 [260];
  CHAR local_10c [260];
  int local_8;
  
  puVar2 = local_250;
  for (iVar1 = 0x93; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  MessageBoxA(param_1,DAT_004f5db4,DAT_004f5de4,4);
  local_8 = __chkesp();
  if (local_8 != 7) {
    do {
      iVar1 = FUN_004331b0("Lucky Luke On The Daltons Trail",(uint *)0x0);
      if (iVar1 != 0) {
        GetCurrentDirectoryA(0x104,local_10c);
        __chkesp();
        iVar1 = FUN_00442670('\x01');
        if ((iVar1 != 0) && (iVar1 = FUN_004427e0("Source directory",local_210), iVar1 != 0)) {
          SetCurrentDirectoryA((LPCSTR)local_210);
          __chkesp();
        }
        FUN_00498cf0((uint *)"extras\\access\\rkvg.exe","extras\\access\\rkvg.exe");
        SetCurrentDirectoryA(local_10c);
        __chkesp();
        break;
      }
      MessageBoxA(param_1,DAT_004f5dc4,DAT_004f5de4,5);
      local_8 = __chkesp();
    } while (local_8 != 2);
  }
  local_8 = 0x434754;
  __chkesp();
  return;
}

