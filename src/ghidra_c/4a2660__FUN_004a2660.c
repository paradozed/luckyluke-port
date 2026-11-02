/* FUN_004a2660 @ 004a2660 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004a2660(uint param_1)

{
  HANDLE hFile;
  BOOL BVar1;
  DWORD local_8;
  
  if (((param_1 < DAT_00509260) &&
      ((*(byte *)((&DAT_00509160)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) &&
     ((*(byte *)((&DAT_00509160)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    hFile = (HANDLE)FUN_004a7980(param_1);
    BVar1 = FlushFileBuffers(hFile);
    if (BVar1 == 0) {
      local_8 = GetLastError();
    }
    else {
      local_8 = 0;
    }
    if (local_8 == 0) {
      return 0;
    }
    DAT_004e8c68 = local_8;
  }
  DAT_004e8c64 = 9;
  return 0xffffffff;
}

