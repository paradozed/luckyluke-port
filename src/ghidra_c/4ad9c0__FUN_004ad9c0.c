/* FUN_004ad9c0 @ 004ad9c0 */
/* decompiled from Lucky.exe (Game.run) */


size_t __cdecl
FUN_004ad9c0(LCID param_1,uint param_2,LPCWSTR param_3,int param_4,LPWSTR param_5,size_t param_6,
            UINT param_7)

{
  int iVar1;
  size_t cchDest;
  int iVar2;
  size_t local_3c;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004bba58;
  puStack_10 = &LAB_00499320;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_004e8ec0 == 0) {
    ExceptionList = &local_14;
    iVar1 = LCMapStringW(0,0x100,L"",1,(LPWSTR)0x0,0);
    if (iVar1 == 0) {
      iVar1 = LCMapStringA(0,0x100,"",1,(LPSTR)0x0,0);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_004e8ec0 = 2;
    }
    else {
      DAT_004e8ec0 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_004adcb0(param_3,param_4);
  }
  if (DAT_004e8ec0 == 1) {
    cchDest = LCMapStringW(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else if (DAT_004e8ec0 == 2) {
    if (param_7 == 0) {
      param_7 = DAT_004e8ea8;
    }
    iVar1 = WideCharToMultiByte(param_7,0x220,param_3,param_4,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar1 == 0) {
      cchDest = 0;
    }
    else {
      local_8 = 0;
      FUN_00497180();
      local_8 = 0xffffffff;
      if (&stack0x00000000 == (undefined1 *)0x48) {
        cchDest = 0;
      }
      else {
        iVar2 = WideCharToMultiByte(param_7,0x220,param_3,param_4,&stack0xffffffb8,iVar1,(LPCSTR)0x0
                                    ,(LPBOOL)0x0);
        if (iVar2 == 0) {
          cchDest = 0;
        }
        else {
          cchDest = LCMapStringA(param_1,param_2,&stack0xffffffb8,iVar1,(LPSTR)0x0,0);
          if (cchDest == 0) {
            cchDest = 0;
          }
          else {
            local_8 = 1;
            FUN_00497180();
            local_8 = 0xffffffff;
            if (&stack0x00000000 == (undefined1 *)0x48) {
              cchDest = 0;
            }
            else {
              iVar1 = LCMapStringA(param_1,param_2,&stack0xffffffb8,iVar1,&stack0xffffffb8,cchDest);
              if (iVar1 == 0) {
                cchDest = 0;
              }
              else if ((param_2 & 0x400) == 0) {
                if (param_6 == 0) {
                  cchDest = MultiByteToWideChar(param_7,1,&stack0xffffffb8,cchDest,(LPWSTR)0x0,0);
                  if (cchDest == 0) {
                    cchDest = 0;
                  }
                }
                else {
                  cchDest = MultiByteToWideChar(param_7,1,&stack0xffffffb8,cchDest,param_5,param_6);
                  if (cchDest == 0) {
                    cchDest = 0;
                  }
                }
              }
              else if (param_6 != 0) {
                local_3c = cchDest;
                if ((int)param_6 < (int)cchDest) {
                  local_3c = param_6;
                }
                _strncpy((char *)param_5,&stack0xffffffb8,local_3c);
              }
            }
          }
        }
      }
    }
  }
  else {
    cchDest = 0;
  }
  ExceptionList = local_14;
  return cchDest;
}

