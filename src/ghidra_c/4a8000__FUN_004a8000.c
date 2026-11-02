/* FUN_004a8000 @ 004a8000 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004a8000(LPCSTR param_1,uint param_2)

{
  DWORD DVar1;
  undefined4 uVar2;
  
  DVar1 = GetFileAttributesA(param_1);
  if (DVar1 == 0xffffffff) {
    DVar1 = GetLastError();
    __dosmaperr(DVar1);
    uVar2 = 0xffffffff;
  }
  else if (((DVar1 & 1) == 0) || ((param_2 & 2) == 0)) {
    uVar2 = 0;
  }
  else {
    DAT_004e8c64 = 0xd;
    DAT_004e8c68 = 5;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

