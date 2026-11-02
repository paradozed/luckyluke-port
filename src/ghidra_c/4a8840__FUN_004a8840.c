/* FUN_004a8840 @ 004a8840 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_004a8840(LPWSTR param_1,byte *param_2,uint param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  if (((DAT_004c71e8 != 1) && (DAT_004c71e8 != 2)) &&
     (iVar2 = FUN_004999a0(2,0x4bb8a4,0x4f,0,(byte *)"MB_CUR_MAX == 1 || MB_CUR_MAX == 2"),
     iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  if ((param_2 == (byte *)0x0) || (param_3 == 0)) {
    uVar3 = 0;
  }
  else if (*param_2 == 0) {
    if (param_1 != (LPWSTR)0x0) {
      *param_1 = L'\0';
    }
    uVar3 = 0;
  }
  else if (DAT_004e8e98 == 0) {
    if (param_1 != (LPWSTR)0x0) {
      *param_1 = (ushort)*param_2;
    }
    uVar3 = 1;
  }
  else if ((*(ushort *)(PTR_DAT_004c6fdc + (uint)*param_2 * 2) & 0x8000) == 0) {
    iVar2 = MultiByteToWideChar(DAT_004e8ea8,9,(LPCSTR)param_2,1,param_1,
                                (uint)(param_1 != (LPWSTR)0x0));
    if (iVar2 == 0) {
      DAT_004e8c64 = 0x2a;
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = 1;
    }
  }
  else if (((((int)DAT_004c71e8 < 2) || ((int)param_3 < (int)DAT_004c71e8)) ||
           (iVar2 = MultiByteToWideChar(DAT_004e8ea8,9,(LPCSTR)param_2,DAT_004c71e8,param_1,
                                        (uint)(param_1 != (LPWSTR)0x0)), uVar3 = DAT_004c71e8,
           iVar2 == 0)) && ((param_3 < DAT_004c71e8 || (uVar3 = DAT_004c71e8, param_2[1] == 0)))) {
    DAT_004e8c64 = 0x2a;
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

