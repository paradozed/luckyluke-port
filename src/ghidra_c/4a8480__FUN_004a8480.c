/* FUN_004a8480 @ 004a8480 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004a8480(int *param_1,int *param_2,int *param_3,int *param_4)

{
  char *pcVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  int *local_20;
  int local_18;
  uint *local_14;
  int local_10;
  uint local_c;
  
  local_20 = param_1;
  local_c = 2;
  while (*local_20 != 0) {
    pcVar1 = (char *)*local_20;
    local_20 = local_20 + 1;
    sVar2 = _strlen(pcVar1);
    local_c = local_c + 1 + sVar2;
  }
  iVar3 = FUN_00494860(local_c,2,0x4bb898,0x61);
  *param_3 = iVar3;
  if (*param_3 == 0) {
    *param_4 = 0;
    DAT_004e8c64 = 0xc;
    DAT_004e8c68 = 8;
    uVar4 = 0xffffffff;
  }
  else {
    if (param_2 != (int *)0x0) {
      local_20 = param_2;
      local_c = 2;
      while (*local_20 != 0) {
        pcVar1 = (char *)*local_20;
        local_20 = local_20 + 1;
        sVar2 = _strlen(pcVar1);
        local_c = local_c + 1 + sVar2;
      }
    }
    if (param_2 == (int *)0x0) {
      *param_4 = 0;
    }
    else {
      if ((DAT_004e8cc0 == (LPSTR)0x0) &&
         (DAT_004e8cc0 = FUN_004a4540(), DAT_004e8cc0 == (LPSTR)0x0)) {
        return 0xffffffff;
      }
      for (local_18 = 0; (DAT_004e8cc0[local_18] != '\0' && (DAT_004e8cc0[local_18] != '='));
          local_18 = local_18 + 1 + sVar2) {
        sVar2 = _strlen(DAT_004e8cc0 + local_18);
      }
      for (local_10 = local_18;
          (((DAT_004e8cc0[local_10] == '=' && (DAT_004e8cc0[local_10 + 1] != '\0')) &&
           (DAT_004e8cc0[local_10 + 2] == ':')) && (DAT_004e8cc0[local_10 + 3] == '='));
          local_10 = local_10 + 5 + sVar2) {
        sVar2 = _strlen(DAT_004e8cc0 + local_10 + 4);
      }
      iVar3 = FUN_00494860(local_c + (local_10 - local_18),2,0x4bb898,0xaa);
      *param_4 = iVar3;
      if (*param_4 == 0) {
        FUN_004952a0((void *)*param_3,2);
        *param_3 = 0;
        DAT_004e8c64 = 0xc;
        DAT_004e8c68 = 8;
        return 0xffffffff;
      }
    }
    local_14 = (uint *)*param_3;
    local_20 = param_1;
    if (*param_1 == 0) {
      local_14 = (uint *)((int)local_14 + 1);
    }
    else {
      FUN_00497270(local_14,(uint *)*param_1);
      local_20 = param_1 + 1;
      sVar2 = _strlen((char *)*param_1);
      local_14 = (uint *)((int)local_14 + sVar2 + 1);
    }
    while (*local_20 != 0) {
      FUN_00497270(local_14,(uint *)*local_20);
      pcVar1 = (char *)*local_20;
      local_20 = local_20 + 1;
      sVar2 = _strlen(pcVar1);
      *(undefined1 *)((int)local_14 + sVar2) = 0x20;
      local_14 = (uint *)((undefined1 *)((int)local_14 + sVar2) + 1);
    }
    *(undefined1 *)((int)local_14 + -1) = 0;
    *(undefined1 *)local_14 = 0;
    local_14 = (uint *)*param_4;
    if (param_2 != (int *)0x0) {
      FUN_00497690(local_14,(undefined4 *)(DAT_004e8cc0 + local_18),local_10 - local_18);
      local_14 = (uint *)((int)local_14 + (local_10 - local_18));
      local_20 = param_2;
      while (*local_20 != 0) {
        FUN_00497270(local_14,(uint *)*local_20);
        pcVar1 = (char *)*local_20;
        local_20 = local_20 + 1;
        sVar2 = _strlen(pcVar1);
        local_14 = (uint *)((int)local_14 + sVar2 + 1);
      }
    }
    if (local_14 != (uint *)0x0) {
      if (local_14 == (uint *)*param_4) {
        *(undefined1 *)local_14 = 0;
        local_14 = (uint *)((int)local_14 + 1);
      }
      *(undefined1 *)local_14 = 0;
    }
    FUN_004952a0(DAT_004e8cc0,2);
    DAT_004e8cc0 = (LPSTR)0x0;
    uVar4 = 0;
  }
  return uVar4;
}

