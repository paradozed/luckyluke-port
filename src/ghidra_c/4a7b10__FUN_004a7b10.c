/* FUN_004a7b10 @ 004a7b10 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint __cdecl FUN_004a7b10(LPCSTR param_1,uint param_2,undefined4 param_3,uint param_4)

{
  DWORD DVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  byte local_3c;
  uint local_38;
  char local_34 [4];
  undefined4 local_30;
  uint local_2c;
  _SECURITY_ATTRIBUTES local_28;
  DWORD local_1c;
  uint local_18;
  uint local_14;
  DWORD local_10;
  DWORD local_c;
  HANDLE local_8;
  
  local_28.nLength = 0xc;
  local_28.lpSecurityDescriptor = (LPVOID)0x0;
  bVar4 = (param_2 & 0x80) == 0;
  if (bVar4) {
    local_3c = 0;
  }
  else {
    local_3c = 0x10;
  }
  local_28.bInheritHandle = (BOOL)bVar4;
  if ((param_2 & 0x8000) == 0) {
    if ((param_2 & 0x4000) == 0) {
      if (DAT_004e8ebc != 0x8000) {
        local_3c = local_3c | 0x80;
      }
    }
    else {
      local_3c = local_3c | 0x80;
    }
  }
  uVar3 = param_2 & 3;
  if (uVar3 == 0) {
    local_38 = 0x80000000;
  }
  else if (uVar3 == 1) {
    local_38 = 0x40000000;
  }
  else {
    if (uVar3 != 2) {
      DAT_004e8c64 = 0x16;
      DAT_004e8c68 = 0;
      return 0xffffffff;
    }
    local_38 = 0xc0000000;
  }
  switch(param_3) {
  case 0x10:
    local_c = 0;
    break;
  default:
    DAT_004e8c64 = 0x16;
    DAT_004e8c68 = 0;
    return 0xffffffff;
  case 0x20:
    local_c = 1;
    break;
  case 0x30:
    local_c = 2;
    break;
  case 0x40:
    local_c = 3;
  }
  uVar3 = param_2 & 0x700;
  if (uVar3 < 0x401) {
    if (uVar3 != 0x400) {
      if (0x200 < uVar3) {
        if (uVar3 != 0x300) {
          DAT_004e8c64 = 0x16;
          DAT_004e8c68 = 0;
          return 0xffffffff;
        }
        local_1c = 2;
        goto LAB_004a7cee;
      }
      if (uVar3 == 0x200) goto LAB_004a7cc0;
      if (uVar3 != 0) {
        if (uVar3 != 0x100) {
          DAT_004e8c64 = 0x16;
          DAT_004e8c68 = 0;
          return 0xffffffff;
        }
        local_1c = 4;
        goto LAB_004a7cee;
      }
    }
    local_1c = 3;
  }
  else {
    if (uVar3 != 0x500) {
      if (uVar3 == 0x600) {
LAB_004a7cc0:
        local_1c = 5;
        goto LAB_004a7cee;
      }
      if (uVar3 != 0x700) {
        DAT_004e8c64 = 0x16;
        DAT_004e8c68 = 0;
        return 0xffffffff;
      }
    }
    local_1c = 1;
  }
LAB_004a7cee:
  local_2c = 0x80;
  if ((param_2 & 0x100) != 0) {
    local_14 = param_4;
    local_30 = 0;
    if ((param_4 & ~DAT_004e8c6c & 0x80) == 0) {
      local_2c = 1;
    }
  }
  if ((param_2 & 0x40) != 0) {
    local_2c = local_2c | 0x4000000;
    local_38 = local_38 | 0x10000;
  }
  if ((param_2 & 0x1000) != 0) {
    local_2c = local_2c | 0x100;
  }
  if ((param_2 & 0x20) == 0) {
    if ((param_2 & 0x10) != 0) {
      local_2c = local_2c | 0x10000000;
    }
  }
  else {
    local_2c = local_2c | 0x8000000;
  }
  local_18 = FUN_004a76d0();
  if (local_18 == 0xffffffff) {
    DAT_004e8c64 = 0x18;
    DAT_004e8c68 = 0;
    local_18 = 0xffffffff;
  }
  else {
    local_8 = CreateFileA(param_1,local_38,local_c,&local_28,local_1c,local_2c,(HANDLE)0x0);
    if (local_8 == (HANDLE)0xffffffff) {
      DVar1 = GetLastError();
      __dosmaperr(DVar1);
      local_18 = 0xffffffff;
    }
    else {
      local_10 = GetFileType(local_8);
      if (local_10 == 0) {
        CloseHandle(local_8);
        DVar1 = GetLastError();
        __dosmaperr(DVar1);
        local_18 = 0xffffffff;
      }
      else {
        if (local_10 == 2) {
          local_3c = local_3c | 0x40;
        }
        else if (local_10 == 3) {
          local_3c = local_3c | 8;
        }
        __set_osfhnd(local_18,(intptr_t)local_8);
        *(byte *)((&DAT_00509160)[(int)local_18 >> 5] + 4 + (local_18 & 0x1f) * 8) = local_3c | 1;
        if ((((local_3c & 0x48) == 0) && (((int)(char)(local_3c | 1) & 0x80U) != 0)) &&
           ((param_2 & 2) != 0)) {
          DVar1 = FUN_004a1a60(local_18,-1,2);
          if (DVar1 == 0xffffffff) {
            if (DAT_004e8c68 != 0x83) {
              FUN_0049fcc0(local_18);
              return 0xffffffff;
            }
          }
          else {
            local_34[0] = '\0';
            iVar2 = FUN_004a1b50(local_18,local_34,1);
            if (((iVar2 == 0) && (local_34[0] == '\x1a')) &&
               (iVar2 = FUN_004acdc0(local_18,DVar1), iVar2 == -1)) {
              FUN_0049fcc0(local_18);
              return 0xffffffff;
            }
            DVar1 = FUN_004a1a60(local_18,0,0);
            if (DVar1 == 0xffffffff) {
              FUN_0049fcc0(local_18);
              return 0xffffffff;
            }
          }
        }
        if (((local_3c & 0x48) == 0) && ((param_2 & 8) != 0)) {
          *(byte *)((&DAT_00509160)[(int)local_18 >> 5] + 4 + (local_18 & 0x1f) * 8) =
               *(byte *)((&DAT_00509160)[(int)local_18 >> 5] + 4 + (local_18 & 0x1f) * 8) | 0x20;
        }
      }
    }
  }
  return local_18;
}

