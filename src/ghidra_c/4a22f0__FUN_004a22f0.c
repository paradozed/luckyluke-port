/* FUN_004a22f0 @ 004a22f0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004a22f0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  DWORD DVar3;
  HANDLE hFile;
  DWORD local_70;
  UINT local_6c;
  UINT local_68;
  byte *local_64;
  int local_60;
  uint local_5c;
  undefined4 *local_54;
  _STARTUPINFOA local_4c;
  byte *local_8;
  
  local_54 = (undefined4 *)FUN_00494860(0x100,2,0x4bb508,0x81);
  if (local_54 == (undefined4 *)0x0) {
    __amsg_exit(0x1b);
  }
  DAT_00509260 = 0x20;
  DAT_00509160 = local_54;
  for (; local_54 < DAT_00509160 + 0x40; local_54 = local_54 + 2) {
    *(undefined1 *)(local_54 + 1) = 0;
    *local_54 = 0xffffffff;
    *(undefined1 *)((int)local_54 + 5) = 10;
  }
  GetStartupInfoA(&local_4c);
  if ((local_4c.cbReserved2 != 0) &&
     (CONCAT22(local_4c.lpReserved2._2_2_,local_4c.lpReserved2._0_2_) != 0)) {
    local_6c = *(UINT *)CONCAT22(local_4c.lpReserved2._2_2_,local_4c.lpReserved2._0_2_);
    local_8 = (byte *)(CONCAT22(local_4c.lpReserved2._2_2_,local_4c.lpReserved2._0_2_) + 4);
    local_64 = local_8 + local_6c;
    if (0x7ff < (int)local_6c) {
      local_6c = 0x800;
    }
    local_68 = local_6c;
    local_60 = 1;
    while ((int)DAT_00509260 < (int)local_6c) {
      local_54 = (undefined4 *)FUN_00494860(0x100,2,0x4bb508,0xb6);
      if (local_54 == (undefined4 *)0x0) {
        local_68 = DAT_00509260;
        break;
      }
      (&DAT_00509160)[local_60] = local_54;
      DAT_00509260 = DAT_00509260 + 0x20;
      for (; local_54 < (undefined4 *)((int)(&DAT_00509160)[local_60] + 0x100);
          local_54 = local_54 + 2) {
        *(undefined1 *)(local_54 + 1) = 0;
        *local_54 = 0xffffffff;
        *(undefined1 *)((int)local_54 + 5) = 10;
      }
      local_60 = local_60 + 1;
    }
    for (local_5c = 0; (int)local_5c < (int)local_68; local_5c = local_5c + 1) {
      if (((*(int *)local_64 != -1) && ((*local_8 & 1) != 0)) &&
         (((*local_8 & 8) != 0 || (DVar3 = GetFileType(*(HANDLE *)local_64), DVar3 != 0)))) {
        puVar1 = (undefined4 *)((int)(&DAT_00509160)[(int)local_5c >> 5] + (local_5c & 0x1f) * 8);
        *puVar1 = *(undefined4 *)local_64;
        *(byte *)(puVar1 + 1) = *local_8;
      }
      local_8 = local_8 + 1;
      local_64 = local_64 + 4;
    }
  }
  for (local_5c = 0; (int)local_5c < 3; local_5c = local_5c + 1) {
    piVar2 = DAT_00509160 + local_5c * 2;
    if (*piVar2 == -1) {
      *(undefined1 *)(piVar2 + 1) = 0x81;
      if (local_5c == 0) {
        local_70 = 0xfffffff6;
      }
      else {
        local_70 = 0xfffffff5 - (local_5c != 1);
      }
      hFile = GetStdHandle(local_70);
      if ((hFile == (HANDLE)0xffffffff) || (DVar3 = GetFileType(hFile), DVar3 == 0)) {
        *(byte *)(piVar2 + 1) = *(byte *)(piVar2 + 1) | 0x40;
      }
      else {
        *piVar2 = (int)hFile;
        if ((DVar3 & 0xff) == 2) {
          *(byte *)(piVar2 + 1) = *(byte *)(piVar2 + 1) | 0x40;
        }
        else if ((DVar3 & 0xff) == 3) {
          *(byte *)(piVar2 + 1) = *(byte *)(piVar2 + 1) | 8;
        }
      }
    }
    else {
      *(byte *)(piVar2 + 1) = *(byte *)(piVar2 + 1) | 0x80;
    }
  }
  SetHandleCount(DAT_00509260);
  return;
}

