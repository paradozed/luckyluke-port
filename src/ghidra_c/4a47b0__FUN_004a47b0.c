/* FUN_004a47b0 @ 004a47b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004a47b0(int param_1)

{
  code *pcVar1;
  int iVar2;
  size_t sVar3;
  HANDLE hFile;
  DWORD DVar4;
  undefined *lpBuffer;
  DWORD *lpNumberOfBytesWritten;
  LPOVERLAPPED lpOverlapped;
  uint local_1b4 [40];
  uint local_114 [65];
  uint *local_10;
  uint local_c;
  DWORD local_8;
  
  for (local_c = 0; (local_c < 0x12 && (param_1 != *(int *)(&DAT_004c77c0 + local_c * 8)));
      local_c = local_c + 1) {
  }
  if (param_1 == *(int *)(&DAT_004c77c0 + local_c * 8)) {
    if ((param_1 != 0xfc) &&
       (iVar2 = FUN_004999a0(1,0,0,0,(&PTR_s_R6002___floating_point_not_loade_004c77c4)[local_c * 2]
                            ), iVar2 == 1)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if ((DAT_004e8cc8 == 1) || ((DAT_004e8cc8 == 0 && (DAT_004c6f84 == 1)))) {
      lpOverlapped = (LPOVERLAPPED)0x0;
      lpNumberOfBytesWritten = &local_8;
      sVar3 = _strlen((&PTR_s_R6002___floating_point_not_loade_004c77c4)[local_c * 2]);
      lpBuffer = (&PTR_s_R6002___floating_point_not_loade_004c77c4)[local_c * 2];
      hFile = GetStdHandle(0xfffffff4);
      WriteFile(hFile,lpBuffer,sVar3,lpNumberOfBytesWritten,lpOverlapped);
    }
    else if (param_1 != 0xfc) {
      DVar4 = GetModuleFileNameA((HMODULE)0x0,(LPSTR)local_114,0x104);
      if (DVar4 == 0) {
        FUN_00497270(local_114,(uint *)"<program name unknown>");
      }
      local_10 = local_114;
      sVar3 = _strlen((char *)local_10);
      if (0x3c < sVar3 + 1) {
        sVar3 = _strlen((char *)local_114);
        local_10 = (uint *)((int)local_10 + (sVar3 - 0x3b));
        _strncpy((char *)local_10,"...",3);
      }
      FUN_00497270(local_1b4,(uint *)"Runtime Error!\n\nProgram: ");
      FUN_00497280(local_1b4,local_10);
      FUN_00497280(local_1b4,(uint *)&DAT_004bb194);
      FUN_00497280(local_1b4,(uint *)(&PTR_s_R6002___floating_point_not_loade_004c77c4)[local_c * 2]
                  );
      FUN_004a52e0(local_1b4,"Microsoft Visual C++ Runtime Library",0x12010);
    }
  }
  return;
}

