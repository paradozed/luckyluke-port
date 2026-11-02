/* FUN_004aae40 @ 004aae40 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl
FUN_004aae40(LCID param_1,DWORD param_2,PCNZWCH param_3,int param_4,LPCWSTR param_5,int param_6,
            UINT param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_30;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004bb910;
  puStack_10 = &LAB_00499320;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (DAT_004e8eb4 == 0) {
    ExceptionList = &local_14;
    iVar1 = CompareStringW(0,0,L"",1,L"",1);
    if (iVar1 == 0) {
      iVar1 = CompareStringA(0,0,"",1,"",1);
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      DAT_004e8eb4 = 2;
    }
    else {
      DAT_004e8eb4 = 1;
    }
  }
  if (0 < param_4) {
    param_4 = FUN_004ab110(param_3,param_4);
  }
  if (0 < param_6) {
    param_6 = FUN_004ab110(param_5,param_6);
  }
  if ((param_4 == 0) || (param_6 == 0)) {
    if (param_4 == param_6) {
      local_30 = 2;
    }
    else {
      local_30 = ((-1 < param_4 - param_6) - 1 & 0xfffffffe) + 3;
    }
  }
  else if (DAT_004e8eb4 == 1) {
    local_30 = CompareStringW(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  else if (DAT_004e8eb4 == 2) {
    if (param_7 == 0) {
      param_7 = DAT_004e8ea8;
    }
    iVar1 = WideCharToMultiByte(param_7,0x220,param_3,param_4,(LPSTR)0x0,0,(LPCSTR)0x0,(LPBOOL)0x0);
    if (iVar1 == 0) {
      local_30 = 0;
    }
    else {
      local_8 = 0;
      FUN_00497180();
      local_8 = 0xffffffff;
      if (&stack0x00000000 == (undefined1 *)0x44) {
        local_30 = 0;
      }
      else {
        iVar2 = WideCharToMultiByte(param_7,0x220,param_3,param_4,&stack0xffffffbc,iVar1,(LPCSTR)0x0
                                    ,(LPBOOL)0x0);
        if (iVar2 == 0) {
          local_30 = 0;
        }
        else {
          iVar2 = WideCharToMultiByte(param_7,0x220,param_5,param_6,(LPSTR)0x0,0,(LPCSTR)0x0,
                                      (LPBOOL)0x0);
          if (iVar2 == 0) {
            local_30 = 0;
          }
          else {
            local_8 = 1;
            FUN_00497180();
            local_8 = 0xffffffff;
            if (&stack0x00000000 == (undefined1 *)0x44) {
              local_30 = 0;
            }
            else {
              iVar3 = WideCharToMultiByte(param_7,0x220,param_5,param_6,&stack0xffffffbc,iVar2,
                                          (LPCSTR)0x0,(LPBOOL)0x0);
              if (iVar3 == 0) {
                local_30 = 0;
              }
              else {
                local_30 = CompareStringA(param_1,param_2,&stack0xffffffbc,iVar1,&stack0xffffffbc,
                                          iVar2);
              }
            }
          }
        }
      }
    }
  }
  else {
    local_30 = 0;
  }
  ExceptionList = local_14;
  return local_30;
}

