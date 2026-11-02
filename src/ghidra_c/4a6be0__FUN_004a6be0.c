/* FUN_004a6be0 @ 004a6be0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_004a6be0(LPSTR param_1,uint param_2)

{
  int iVar1;
  BOOL local_c [2];
  
  if (param_1 == (LPSTR)0x0) {
    iVar1 = 0;
  }
  else if (DAT_004e8e98 == 0) {
    if ((param_2 & 0xffff) < 0x100) {
      *param_1 = (CHAR)param_2;
      iVar1 = 1;
    }
    else {
      DAT_004e8c64 = 0x2a;
      iVar1 = -1;
    }
  }
  else {
    local_c[0] = 0;
    iVar1 = WideCharToMultiByte(DAT_004e8ea8,0x220,(LPCWSTR)&param_2,1,param_1,DAT_004c71e8,
                                (LPCSTR)0x0,local_c);
    if ((iVar1 == 0) || (local_c[0] != 0)) {
      DAT_004e8c64 = 0x2a;
      iVar1 = -1;
    }
  }
  return iVar1;
}

