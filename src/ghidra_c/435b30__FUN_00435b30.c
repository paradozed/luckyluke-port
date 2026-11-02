/* FUN_00435b30 @ 00435b30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00435b30(char *param_1,int param_2)

{
  size_t sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_68 [16];
  char local_28 [16];
  size_t local_18;
  char local_14 [4];
  int local_10;
  uint local_c;
  int local_8;
  
  puVar3 = local_68;
  for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = FUN_00498dc0(*(uint **)(param_1 + 0x24));
  for (local_c = 0; *(char *)(param_2 + local_c) != '\0'; local_c = local_c + 1) {
    if ((0x60 < *(byte *)(param_2 + local_c)) && (*(byte *)(param_2 + local_c) < 0x7b)) {
      *(char *)(param_2 + local_c) = *(char *)(param_2 + local_c) + -0x20;
    }
  }
  if (*param_1 == '\0') {
    FUN_004988b0(*(uint **)(param_1 + 0x24),*(int *)(param_1 + 0x2c),0);
    for (local_c = 0; local_c < *(uint *)(param_1 + 0x30); local_c = local_c + 1) {
      FUN_004989e0(local_28,0xd,1,*(int **)(param_1 + 0x24));
      for (local_18 = 0;
          (*(char *)(param_2 + local_18) != '\0' &&
          (local_28[local_18] == *(char *)(param_2 + local_18))); local_18 = local_18 + 1) {
      }
      sVar1 = _strlen(local_28);
      if (local_18 == sVar1) break;
    }
    if (local_c == *(uint *)(param_1 + 0x30)) {
      DAT_004e84b0 = 7;
      goto LAB_00435d7c;
    }
    FUN_004989e0((char *)&local_10,4,1,*(int **)(param_1 + 0x24));
  }
  else {
    for (local_c = 0; local_c < *(uint *)(param_1 + 0x30); local_c = local_c + 1) {
      for (local_18 = 0;
          (*(char *)(param_2 + local_18) != '\0' &&
          (*(char *)(*(int *)(param_1 + 0x34) + local_c * 0xd + local_18) ==
           *(char *)(param_2 + local_18))); local_18 = local_18 + 1) {
      }
      sVar1 = _strlen((char *)(*(int *)(param_1 + 0x34) + local_c * 0xd));
      if (local_18 == sVar1) break;
    }
    if (local_c == *(uint *)(param_1 + 0x30)) {
      DAT_004e84b0 = 7;
      goto LAB_00435d7c;
    }
    local_10 = *(int *)(*(int *)(param_1 + 0x38) + local_c * 4);
  }
  FUN_004988b0(*(uint **)(param_1 + 0x24),local_10 + 5,0);
  FUN_004989e0(local_14,4,1,*(int **)(param_1 + 0x24));
  FUN_004988b0(*(uint **)(param_1 + 0x24),local_8,0);
LAB_00435d7c:
  local_8 = 0x435d89;
  __chkesp();
  return;
}

