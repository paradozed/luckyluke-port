/* FUN_004a6f50 @ 004a6f50 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_004a6f50(void)

{
  uint cbMultiByte;
  uint *lpMultiByteStr;
  int iVar1;
  int *local_8;
  
  local_8 = DAT_004e8c94;
  while( true ) {
    if (*local_8 == 0) {
      return 0;
    }
    cbMultiByte = WideCharToMultiByte(1,0,(LPCWSTR)*local_8,-1,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0)
    ;
    if (cbMultiByte == 0) {
      return 0xffffffff;
    }
    lpMultiByteStr = (uint *)FUN_00494860(cbMultiByte,2,0x4bb868,0x3d);
    if (lpMultiByteStr == (uint *)0x0) {
      return 0xffffffff;
    }
    iVar1 = WideCharToMultiByte(1,0,(LPCWSTR)*local_8,-1,(LPSTR)lpMultiByteStr,cbMultiByte,
                                (LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar1 == 0) break;
    FUN_0049ef30(lpMultiByteStr,0);
    local_8 = local_8 + 1;
  }
  return 0xffffffff;
}

