/* FUN_004acdc0 @ 004acdc0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_004acdc0(uint param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  DWORD DVar3;
  DWORD DVar4;
  int iVar5;
  HANDLE hFile;
  BOOL BVar6;
  uint local_1028;
  int local_1020;
  uint local_101c;
  char local_1008 [4064];
  undefined4 uStackY_28;
  
  FUN_00497180();
  local_1020 = 0;
  if ((param_1 < DAT_00509260) &&
     ((*(byte *)((&DAT_00509160)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    if (param_2 < 0) {
      uStackY_28 = 0x4ace40;
      iVar2 = FUN_004999a0(2,0x4bba3c,0x81,0,(byte *)"size >= 0");
      if (iVar2 == 1) {
        pcVar1 = (code *)swi(3);
        iVar2 = (*pcVar1)();
        return iVar2;
      }
    }
    DVar3 = FUN_004a1a60(param_1,0,1);
    if ((DVar3 == 0xffffffff) || (DVar4 = FUN_004a1a60(param_1,0,2), DVar4 == 0xffffffff)) {
      local_1020 = -1;
    }
    else {
      local_101c = param_2 - DVar4;
      if ((int)local_101c < 1) {
        if ((int)local_101c < 0) {
          FUN_004a1a60(param_1,param_2,0);
          hFile = (HANDLE)FUN_004a7980(param_1);
          BVar6 = SetEndOfFile(hFile);
          local_1020 = (BVar6 != 0) - 1;
          if (local_1020 == -1) {
            DAT_004e8c64 = 0xd;
            DAT_004e8c68 = GetLastError();
          }
        }
      }
      else {
        _memset(local_1008,0,0x1000);
        iVar2 = FUN_004ad8c0(param_1,0x8000);
        do {
          if ((int)local_101c < 0x1000) {
            local_1028 = local_101c;
          }
          else {
            local_1028 = 0x1000;
          }
          iVar5 = FUN_004a02d0(param_1,local_1008,local_1028);
          if (iVar5 == -1) {
            if (DAT_004e8c68 == 5) {
              DAT_004e8c64 = 0xd;
            }
            local_1020 = -1;
            break;
          }
          local_101c = local_101c - iVar5;
        } while (0 < (int)local_101c);
        FUN_004ad8c0(param_1,iVar2);
      }
      FUN_004a1a60(param_1,DVar3,0);
    }
  }
  else {
    DAT_004e8c64 = 9;
    local_1020 = -1;
  }
  return local_1020;
}

