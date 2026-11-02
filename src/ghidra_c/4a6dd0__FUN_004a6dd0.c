/* FUN_004a6dd0 @ 004a6dd0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 FUN_004a6dd0(void)

{
  int iVar1;
  PCNZWCH lpWideCharStr;
  int *local_10;
  
  local_10 = DAT_004e8c8c;
  while( true ) {
    if (*local_10 == 0) {
      return 0;
    }
    iVar1 = MultiByteToWideChar(1,0,(LPCSTR)*local_10,-1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    lpWideCharStr = (PCNZWCH)FUN_00494860(iVar1 << 1,2,0x4bb85c,0x3c);
    if (lpWideCharStr == (PCNZWCH)0x0) {
      return 0xffffffff;
    }
    iVar1 = MultiByteToWideChar(1,0,(LPCSTR)*local_10,-1,lpWideCharStr,iVar1);
    if (iVar1 == 0) break;
    FUN_0049ead0(lpWideCharStr,0);
    local_10 = local_10 + 1;
  }
  return 0xffffffff;
}

