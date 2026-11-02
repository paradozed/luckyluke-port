/* FUN_004a8120 @ 004a8120 */
/* decompiled from Lucky.exe (Game.run) */


HANDLE __cdecl FUN_004a8120(int param_1,LPCSTR param_2,char *param_3,LPVOID param_4)

{
  int *piVar1;
  BOOL BVar2;
  int local_94;
  DWORD local_8c;
  HANDLE local_80;
  undefined4 *local_7c;
  uint local_78;
  char *local_74;
  int local_70;
  undefined1 local_6c;
  char local_68;
  undefined4 *local_64;
  ulong local_60;
  _STARTUPINFOA local_5c;
  _PROCESS_INFORMATION local_18;
  int *local_8;
  
  local_8c = 0;
  local_68 = '\0';
  local_6c = 0;
  switch(param_1) {
  case 0:
    break;
  case 1:
    local_6c = 1;
    break;
  case 2:
  case 3:
    break;
  case 4:
    local_68 = '\x01';
    break;
  default:
    DAT_004e8c64 = 0x16;
    DAT_004e8c68 = 0;
    return (HANDLE)0xffffffff;
  }
  local_74 = param_3;
  while (*param_3 != '\0') {
    for (; *param_3 != '\0'; param_3 = param_3 + 1) {
    }
    if (param_3[1] != '\0') {
      *param_3 = ' ';
      param_3 = param_3 + 1;
    }
  }
  _memset(&local_5c,0,0x44);
  local_5c.cb = 0x44;
  local_70 = DAT_00509260;
  while ((local_70 != 0 &&
         (*(char *)((&DAT_00509160)[local_70 + -1 >> 5] + 4 + (local_70 - 1U & 0x1f) * 8) == '\0')))
  {
    local_70 = local_70 + -1;
  }
  local_5c.cbReserved2 = (short)local_70 * 5 + 4;
  piVar1 = (int *)__calloc_dbg((uint)local_5c.cbReserved2,1,2,0x4bb88c,0x76);
  local_5c.lpReserved2._0_2_ = SUB42(piVar1,0);
  local_5c.lpReserved2._2_2_ = (undefined2)((uint)piVar1 >> 0x10);
  *piVar1 = local_70;
  local_8 = piVar1 + 1;
  local_7c = (undefined4 *)((int)piVar1 + local_70 + 4);
  for (local_78 = 0; (int)local_78 < local_70; local_78 = local_78 + 1) {
    local_64 = (undefined4 *)((&DAT_00509160)[(int)local_78 >> 5] + (local_78 & 0x1f) * 8);
    if ((*(byte *)(local_64 + 1) & 0x10) == 0) {
      *(undefined1 *)local_8 = *(undefined1 *)(local_64 + 1);
      *local_7c = *local_64;
    }
    else {
      *(undefined1 *)local_8 = 0;
      *local_7c = 0xffffffff;
    }
    local_8 = (int *)((int)local_8 + 1);
    local_7c = local_7c + 1;
  }
  if (local_68 != '\0') {
    local_78 = 0;
    local_8 = piVar1 + 1;
    local_7c = (undefined4 *)((int)piVar1 + local_70 + 4);
    while( true ) {
      if (local_70 < 3) {
        local_94 = local_70;
      }
      else {
        local_94 = 3;
      }
      if (local_94 <= (int)local_78) break;
      *(undefined1 *)local_8 = 0;
      *local_7c = 0xffffffff;
      local_78 = local_78 + 1;
      local_8 = (int *)((int)local_8 + 1);
      local_7c = local_7c + 1;
    }
    local_8c = 8;
  }
  DAT_004e8c64 = 0;
  DAT_004e8c68 = 0;
  BVar2 = CreateProcessA(param_2,local_74,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,1,
                         local_8c,param_4,(LPCSTR)0x0,&local_5c,&local_18);
  local_60 = GetLastError();
  FUN_004952a0((void *)CONCAT22(local_5c.lpReserved2._2_2_,local_5c.lpReserved2._0_2_),2);
  if (BVar2 == 0) {
    __dosmaperr(local_60);
    local_80 = (HANDLE)0xffffffff;
  }
  else {
    if (param_1 == 2) {
                    /* WARNING: Subroutine does not return */
      __exit(0);
    }
    if (param_1 == 0) {
      WaitForSingleObject(local_18.hProcess,0xffffffff);
      GetExitCodeProcess(local_18.hProcess,(LPDWORD)&local_80);
      CloseHandle(local_18.hProcess);
    }
    else if (param_1 == 4) {
      CloseHandle(local_18.hProcess);
      local_80 = (HANDLE)0x0;
    }
    else {
      local_80 = local_18.hProcess;
    }
    CloseHandle(local_18.hThread);
  }
  return local_80;
}

