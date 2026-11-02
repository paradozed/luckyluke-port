/* FUN_00434760 @ 00434760 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00434760(HWND param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_250 [16];
  int local_210;
  BYTE local_20c [260];
  CHAR local_108 [256];
  undefined4 uStack_8;
  
  puVar2 = local_250;
  for (iVar1 = 0x93; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  do {
    iVar1 = FUN_004331b0("Lucky Luke On The Daltons Trail",(uint *)0x0);
    if (iVar1 != 0) {
      GetCurrentDirectoryA(0x104,local_108);
      __chkesp();
      iVar1 = FUN_00442670('\x01');
      if ((iVar1 != 0) && (iVar1 = FUN_004427e0("Source directory",local_20c), iVar1 != 0)) {
        SetCurrentDirectoryA((LPCSTR)local_20c);
        __chkesp();
      }
      FUN_00498cf0((uint *)"extras\\access\\iv5play.exe","extras\\access\\iv5play.exe");
      SetCurrentDirectoryA(local_108);
      __chkesp();
      break;
    }
    MessageBoxA(param_1,DAT_004f5dc8,DAT_004f5de4,5);
    local_210 = __chkesp();
  } while (local_210 != 2);
  uStack_8 = 0x43485a;
  __chkesp();
  return;
}

