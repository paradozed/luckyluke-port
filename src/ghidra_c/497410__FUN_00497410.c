/* FUN_00497410 @ 00497410 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_00497410(uint *param_1)

{
  undefined4 uVar1;
  size_t sVar2;
  uint *puVar3;
  PCNZWCH lpWideCharStr;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  
  if (DAT_0050a2a8 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar6 = 0x7f;
    pcVar5 = "putenv.c";
    uVar4 = 2;
    sVar2 = _strlen((char *)param_1);
    puVar3 = (uint *)FUN_00494860(sVar2 + 1,uVar4,(int)pcVar5,iVar6);
    if (puVar3 == (uint *)0x0) {
      uVar1 = 0xffffffff;
    }
    else {
      FUN_00497270(puVar3,param_1);
      iVar6 = FUN_0049ef30(puVar3,1);
      if (iVar6 == 0) {
        if (DAT_004e8c94 != 0) {
          iVar6 = MultiByteToWideChar(1,0,(LPCSTR)param_1,-1,(LPWSTR)0x0,0);
          if (iVar6 == 0) {
            return 0xffffffff;
          }
          lpWideCharStr = (PCNZWCH)FUN_00494860(iVar6 << 1,2,0x4baebc,0xaf);
          if (lpWideCharStr == (PCNZWCH)0x0) {
            return 0xffffffff;
          }
          iVar6 = MultiByteToWideChar(1,0,(LPCSTR)param_1,-1,lpWideCharStr,iVar6);
          if (iVar6 == 0) {
            return 0xffffffff;
          }
          iVar6 = FUN_0049ead0(lpWideCharStr,0);
          if (iVar6 != 0) {
            return 0xffffffff;
          }
        }
        uVar1 = 0;
      }
      else {
        uVar1 = 0xffffffff;
      }
    }
  }
  return uVar1;
}

