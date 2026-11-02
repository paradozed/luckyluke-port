/* FUN_004a52e0 @ 004a52e0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_004a52e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  HMODULE hModule;
  int iVar1;
  int local_8;
  
  local_8 = 0;
  if (DAT_004e8e40 == (FARPROC)0x0) {
    hModule = LoadLibraryA("user32.dll");
    if (hModule != (HMODULE)0x0) {
      DAT_004e8e40 = GetProcAddress(hModule,"MessageBoxA");
      if (DAT_004e8e40 != (FARPROC)0x0) {
        DAT_004e8e44 = GetProcAddress(hModule,"GetActiveWindow");
        DAT_004e8e48 = GetProcAddress(hModule,"GetLastActivePopup");
        goto LAB_004a5353;
      }
    }
    iVar1 = 0;
  }
  else {
LAB_004a5353:
    if (DAT_004e8e44 != (FARPROC)0x0) {
      local_8 = (*DAT_004e8e44)();
    }
    if ((local_8 != 0) && (DAT_004e8e48 != (FARPROC)0x0)) {
      local_8 = (*DAT_004e8e48)(local_8);
    }
    iVar1 = (*DAT_004e8e40)(local_8,param_1,param_2,param_3);
  }
  return iVar1;
}

