/* FUN_00435480 @ 00435480 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00435480(char *param_1,undefined1 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_4c [16];
  uint local_c;
  int local_8;
  
  puVar3 = local_4c;
  for (iVar2 = 0x12; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = FUN_00498dc0(*(uint **)(param_1 + 0x24));
  if (*param_1 == '\0') {
    FUN_004988b0(*(uint **)(param_1 + 0x24),*(int *)(param_1 + 0x2c) + (param_3 & 0xffff) * 0x11,0);
    FUN_004989e0(param_2 + 1,0xd,1,*(int **)(param_1 + 0x24));
    FUN_004989e0(param_2 + 0x14,4,1,*(int **)(param_1 + 0x24));
    FUN_004988b0(*(uint **)(param_1 + 0x24),*(int *)(param_2 + 0x14),0);
    uVar1 = FUN_00498340(*(int **)(param_1 + 0x24));
    *param_2 = (char)uVar1;
    FUN_004988b0(*(uint **)(param_1 + 0x24),*(int *)(param_2 + 0x14) + 5,0);
    FUN_004989e0(param_2 + 0x10,4,1,*(int **)(param_1 + 0x24));
  }
  else {
    for (local_c = 0; local_c < 0xd; local_c = local_c + 1) {
      param_2[local_c + 1] =
           *(undefined1 *)(*(int *)(param_1 + 0x34) + (param_3 & 0xffff) * 0xd + local_c);
    }
    *(undefined4 *)(param_2 + 0x14) =
         *(undefined4 *)(*(int *)(param_1 + 0x38) + (param_3 & 0xffff) * 4);
    FUN_004988b0(*(uint **)(param_1 + 0x24),
                 *(int *)(*(int *)(param_1 + 0x38) + (param_3 & 0xffff) * 4),0);
    uVar1 = FUN_00498340(*(int **)(param_1 + 0x24));
    *param_2 = (char)uVar1;
    FUN_004988b0(*(uint **)(param_1 + 0x24),
                 *(int *)(*(int *)(param_1 + 0x38) + (param_3 & 0xffff) * 4) + 5,0);
    FUN_004989e0(param_2 + 0x10,4,1,*(int **)(param_1 + 0x24));
  }
  FUN_004988b0(*(uint **)(param_1 + 0x24),local_8,0);
  local_8 = 0x435667;
  __chkesp();
  return;
}

