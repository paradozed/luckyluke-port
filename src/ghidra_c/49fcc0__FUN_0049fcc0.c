/* FUN_0049fcc0 @ 0049fcc0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_0049fcc0(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  undefined4 uVar4;
  ulong local_8;
  
  if ((DAT_00509260 <= param_1) ||
     ((*(byte *)((&DAT_00509160)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) == 0)) {
    DAT_004e8c64 = 9;
    DAT_004e8c68 = 0;
    return 0xffffffff;
  }
  iVar1 = FUN_004a7980(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_004a7980(1);
      iVar2 = FUN_004a7980(2);
      if (iVar1 == iVar2) goto LAB_0049fd59;
    }
    hObject = (HANDLE)FUN_004a7980(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      local_8 = GetLastError();
      goto LAB_0049fd6b;
    }
  }
LAB_0049fd59:
  local_8 = 0;
LAB_0049fd6b:
  FUN_004a78b0(param_1);
  *(undefined1 *)((&DAT_00509160)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) = 0;
  if (local_8 == 0) {
    uVar4 = 0;
  }
  else {
    __dosmaperr(local_8);
    uVar4 = 0xffffffff;
  }
  return uVar4;
}

