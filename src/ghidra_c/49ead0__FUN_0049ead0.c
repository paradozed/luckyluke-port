/* FUN_0049ead0 @ 0049ead0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_0049ead0(PCNZWCH param_1,int param_2)

{
  PCNZWCH pWVar1;
  int iVar2;
  int *piVar3;
  LPCWSTR lpName;
  bool bVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  int local_c;
  
  if (((param_1 == (PCNZWCH)0x0) || (pWVar1 = FUN_004a6e80(param_1,0x3d), pWVar1 == (PCNZWCH)0x0))
     || (param_1 == pWVar1)) {
    return 0xffffffff;
  }
  bVar4 = pWVar1[1] == L'\0';
  if (DAT_004e8c94 == DAT_004e8c98) {
    DAT_004e8c94 = copy_environ(DAT_004e8c94);
  }
  if (DAT_004e8c94 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_004e8c8c == (undefined4 *)0x0)) {
      if (bVar4) {
        return 0;
      }
      if (DAT_004e8c8c == (undefined4 *)0x0) {
        DAT_004e8c8c = (undefined4 *)FUN_00494860(4,2,0x4bb3ec,0x87);
        if (DAT_004e8c8c == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_004e8c8c = 0;
      }
      if (DAT_004e8c94 == (int *)0x0) {
        DAT_004e8c94 = (int *)FUN_00494860(4,2,0x4bb3ec,0x8e);
        if (DAT_004e8c94 == (int *)0x0) {
          return 0xffffffff;
        }
        *DAT_004e8c94 = 0;
      }
    }
    else {
      iVar2 = FUN_004a6dd0();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_004e8c94;
  local_c = FUN_0049edc0(param_1,(int)pWVar1 - (int)param_1 >> 1);
  if ((local_c < 0) || (*piVar3 == 0)) {
    if (bVar4) {
      return 0;
    }
    if (local_c < 0) {
      local_c = -local_c;
    }
    piVar3 = __realloc_dbg(piVar3,local_c * 4 + 8,2,0x4bb3ec,0xce);
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar3[local_c] = (int)param_1;
    piVar3[local_c + 1] = 0;
    DAT_004e8c94 = piVar3;
  }
  else if (bVar4) {
    FUN_004952a0((void *)piVar3[local_c],2);
    for (; piVar3[local_c] != 0; local_c = local_c + 1) {
      piVar3[local_c] = piVar3[local_c + 1];
    }
    piVar3 = __realloc_dbg(piVar3,local_c << 2,2,0x4bb3ec,0xb9);
    if (piVar3 != (int *)0x0) {
      DAT_004e8c94 = piVar3;
    }
  }
  else {
    piVar3[local_c] = (int)param_1;
  }
  if (param_2 != 0) {
    iVar7 = 0xe5;
    pcVar6 = "setenv.c";
    uVar5 = 2;
    iVar2 = FUN_004a6da0(param_1);
    lpName = (LPCWSTR)FUN_00494860(iVar2 * 2 + 4,uVar5,(int)pcVar6,iVar7);
    if (lpName != (LPCWSTR)0x0) {
      FUN_004a6d60(lpName,param_1);
      lpName[(int)pWVar1 - (int)param_1 >> 1] = L'\0';
      SetEnvironmentVariableW
                (lpName,(LPCWSTR)(~-(uint)bVar4 &
                                 (uint)(lpName + ((int)pWVar1 - (int)param_1 >> 1) + 1)));
      FUN_004952a0(lpName,2);
    }
  }
  return 0;
}

