/* FUN_00434420 @ 00434420 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00434420(HWND param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_25c [16];
  int local_21c;
  int local_218;
  CHAR local_214 [260];
  BYTE local_110 [260];
  undefined4 local_c;
  uint local_8;
  
  puVar2 = local_25c;
  for (iVar1 = 0x96; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = 0;
  local_c = 0;
  do {
    iVar1 = FUN_004331b0("Lucky Luke On The Daltons Trail",(uint *)0x0);
    if (iVar1 != 0) {
      GetCurrentDirectoryA(0x104,local_214);
      __chkesp();
      iVar1 = FUN_00442670('\x01');
      if ((iVar1 != 0) && (iVar1 = FUN_004427e0("Source directory",local_110), iVar1 != 0)) {
        SetCurrentDirectoryA((LPCSTR)local_110);
        __chkesp();
      }
      iVar1 = Ordinal_11(&local_8,&local_c);
      if ((iVar1 != 0) && (0x40006 < local_8)) {
        MessageBoxA(param_1,DAT_004f5dc0,DAT_004f5de4,4);
        local_21c = __chkesp();
        if (local_21c == 7) break;
      }
      SetCurrentDirectoryA("extras\\access");
      __chkesp();
      FUN_00498cf0((uint *)"dx70a.exe","dx70a.exe");
      SetCurrentDirectoryA(local_214);
      __chkesp();
      break;
    }
    MessageBoxA(param_1,DAT_004f5dbc,DAT_004f5de4,5);
    local_218 = __chkesp();
  } while (local_218 != 2);
  local_8 = 0x434589;
  __chkesp();
  return;
}

