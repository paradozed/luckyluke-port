/* FUN_00435670 @ 00435670 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00435670(char *param_1,uint *param_2)

{
  char cVar1;
  size_t sVar2;
  uint uVar3;
  int iVar4;
  undefined2 extraout_var;
  undefined2 uVar5;
  undefined2 extraout_var_00;
  undefined4 *puVar6;
  undefined4 local_90 [16];
  uint local_50 [4];
  undefined1 local_40 [16];
  uint local_30;
  char *local_28;
  byte local_24;
  undefined3 uStack_23;
  char local_20 [16];
  size_t local_10;
  uint local_c;
  int local_8;
  
  puVar6 = local_90;
  for (iVar4 = 0x23; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  if ((param_1 == (char *)0x0) || (*(int *)(param_1 + 0x24) == 0)) {
    DAT_004e84b0 = 8;
  }
  else {
    FUN_00497270(local_50,param_2);
    FUN_004b2410(local_50);
    if (*param_1 == '\0') {
      FUN_004988b0(*(uint **)(param_1 + 0x24),*(int *)(param_1 + 0x2c),0);
      for (local_c = 0; local_c < *(uint *)(param_1 + 0x30); local_c = local_c + 1) {
        FUN_004989e0(local_20,0xd,1,*(int **)(param_1 + 0x24));
        FUN_004989e0((char *)&local_8,4,1,*(int **)(param_1 + 0x24));
        for (local_10 = 0;
            (*(char *)((int)local_50 + local_10) != '\0' &&
            (local_20[local_10] == *(char *)((int)local_50 + local_10))); local_10 = local_10 + 1) {
        }
        sVar2 = _strlen(local_20);
        if (local_10 == sVar2) break;
      }
      if (local_c == *(uint *)(param_1 + 0x30)) {
        DAT_004e84b0 = 7;
        goto LAB_0043598a;
      }
    }
    else {
      for (local_c = 0; local_c < *(uint *)(param_1 + 0x30); local_c = local_c + 1) {
        for (local_10 = 0;
            (*(char *)((int)local_50 + local_10) != '\0' &&
            (*(char *)(*(int *)(param_1 + 0x34) + local_c * 0xd + local_10) ==
             *(char *)((int)local_50 + local_10))); local_10 = local_10 + 1) {
        }
        sVar2 = _strlen((char *)(*(int *)(param_1 + 0x34) + local_c * 0xd));
        if (local_10 == sVar2) break;
      }
      if (local_c == *(uint *)(param_1 + 0x30)) {
        DAT_004e84b0 = 7;
        goto LAB_0043598a;
      }
      local_8 = *(int *)(*(int *)(param_1 + 0x38) + local_c * 4);
    }
    FUN_004988b0(*(uint **)(param_1 + 0x24),local_8 + 9,0);
    uVar5 = 0;
    if (param_1[1] != '\0') {
      cVar1 = FUN_004359a0(param_1,CONCAT22(extraout_var_00,(undefined2)local_c));
      uVar5 = extraout_var;
      if (cVar1 == '\0') {
        DAT_004e84b0 = 9;
        goto LAB_0043598a;
      }
    }
    FUN_00435480(param_1,local_40,CONCAT22(uVar5,(undefined2)local_c));
    local_28 = (char *)FUN_00494840(local_30);
    if (local_28 == (char *)0x0) {
      DAT_004e84b0 = 6;
    }
    else {
      local_10 = 0;
      if (param_1[0x28] == '\0') {
        FUN_004989e0(local_28,local_30,1,*(int **)(param_1 + 0x24));
      }
      else {
        for (local_c = 0; local_c < local_30; local_c = local_c + 1) {
          uVar3 = FUN_00498340(*(int **)(param_1 + 0x24));
          _local_24 = CONCAT31(uStack_23,(byte)uVar3);
          if (((uVar3 & 0xff) != 0) && ((uVar3 & 0xff) != (uint)(byte)param_1[local_10 + 2])) {
            _local_24 = CONCAT31(uStack_23,(byte)uVar3 ^ param_1[local_10 + 2]);
          }
          local_28[local_c] = local_24;
          local_10 = (local_10 + 1) % (uint)(byte)param_1[0x28];
        }
      }
    }
  }
LAB_0043598a:
  local_8 = 0x43599a;
  __chkesp();
  return;
}

