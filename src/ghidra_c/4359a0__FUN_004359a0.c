/* FUN_004359a0 @ 004359a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004359a0(char *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_64 [16];
  undefined1 local_24;
  undefined3 uStack_23;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  char local_10 [4];
  uint local_c;
  int local_8;
  
  puVar3 = local_64;
  for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((param_1 == (char *)0x0) || (*(int *)(param_1 + 0x24) == 0)) {
    DAT_004e84b0 = 8;
  }
  else {
    local_8 = FUN_00498dc0(*(uint **)(param_1 + 0x24));
    if (*param_1 == '\0') {
      FUN_004988b0(*(uint **)(param_1 + 0x24),
                   *(int *)(param_1 + 0x2c) + 0xd + (param_2 & 0xffff) * 0x11,0);
      FUN_004989e0((char *)&local_14,4,1,*(int **)(param_1 + 0x24));
    }
    else {
      local_14 = *(int *)(*(int *)(param_1 + 0x38) + (param_2 & 0xffff) * 4);
    }
    FUN_004988b0(*(uint **)(param_1 + 0x24),local_14 + 1,0);
    FUN_004989e0(local_10,4,1,*(int **)(param_1 + 0x24));
    FUN_004989e0((char *)&local_1c,4,1,*(int **)(param_1 + 0x24));
    local_18 = 0xffffffff;
    for (local_c = 0; local_c < local_1c; local_c = local_c + 1) {
      uVar1 = FUN_00498340(*(int **)(param_1 + 0x24));
      _local_24 = CONCAT31(uStack_23,(char)uVar1);
      local_20 = uVar1 & 0xff ^ local_18 & 0xff;
      local_18 = local_18 >> 8 ^ *(uint *)(&DAT_004bc764 + local_20 * 4);
    }
    FUN_004988b0(*(uint **)(param_1 + 0x24),local_8,0);
  }
  local_8 = 0x435b22;
  __chkesp();
  return;
}

