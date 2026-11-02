/* FUN_0049ef30 @ 0049ef30 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_0049ef30(uint *param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  uint *lpName;
  undefined1 *puVar5;
  bool bVar6;
  uint uVar7;
  char *pcVar8;
  int local_c;
  
  if (((param_1 == (uint *)0x0) || (puVar1 = FUN_004a7000(param_1,0x3d), puVar1 == (uint *)0x0)) ||
     (param_1 == puVar1)) {
    return 0xffffffff;
  }
  bVar6 = *(char *)((int)puVar1 + 1) == '\0';
  if (DAT_004e8c8c == DAT_004e8c90) {
    DAT_004e8c8c = copy_environ(DAT_004e8c8c);
  }
  if (DAT_004e8c8c == (int *)0x0) {
    if ((param_2 == 0) || (DAT_004e8c94 == (undefined4 *)0x0)) {
      if (bVar6) {
        return 0;
      }
      DAT_004e8c8c = (int *)FUN_00494860(4,2,0x4bb3ec,0x87);
      if (DAT_004e8c8c == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_004e8c8c = 0;
      if (DAT_004e8c94 == (undefined4 *)0x0) {
        DAT_004e8c94 = (undefined4 *)FUN_00494860(4,2,0x4bb3ec,0x8e);
        if (DAT_004e8c94 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_004e8c94 = 0;
      }
    }
    else {
      iVar2 = FUN_004a6f50();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_004e8c8c;
  local_c = findenv((uchar *)param_1,(int)puVar1 - (int)param_1);
  if ((local_c < 0) || (*piVar3 == 0)) {
    if (bVar6) {
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
    DAT_004e8c8c = piVar3;
  }
  else if (bVar6) {
    FUN_004952a0((void *)piVar3[local_c],2);
    for (; piVar3[local_c] != 0; local_c = local_c + 1) {
      piVar3[local_c] = piVar3[local_c + 1];
    }
    piVar3 = __realloc_dbg(piVar3,local_c << 2,2,0x4bb3ec,0xb9);
    if (piVar3 != (int *)0x0) {
      DAT_004e8c8c = piVar3;
    }
  }
  else {
    piVar3[local_c] = (int)param_1;
  }
  if (param_2 != 0) {
    iVar2 = 0xe5;
    pcVar8 = "setenv.c";
    uVar7 = 2;
    sVar4 = _strlen((char *)param_1);
    lpName = (uint *)FUN_00494860(sVar4 + 2,uVar7,(int)pcVar8,iVar2);
    if (lpName != (uint *)0x0) {
      FUN_00497270(lpName,param_1);
      puVar5 = (undefined1 *)((int)lpName + ((int)puVar1 - (int)param_1));
      *puVar5 = 0;
      SetEnvironmentVariableA((LPCSTR)lpName,(LPCSTR)(~-(uint)bVar6 & (uint)(puVar5 + 1)));
      FUN_004952a0(lpName,2);
    }
  }
  return 0;
}

