/* FUN_00435320 @ 00435320 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00435320(undefined1 *param_1)

{
  undefined4 uVar1;
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
  if ((param_1 == (undefined1 *)0x0) || (*(int *)(param_1 + 0x24) == 0)) {
    DAT_004e84b0 = 8;
  }
  else {
    uVar1 = FUN_00494840(*(int *)(param_1 + 0x30) << 2);
    *(undefined4 *)(param_1 + 0x38) = uVar1;
    if (*(int *)(param_1 + 0x38) == 0) {
      DAT_004e84b0 = 6;
    }
    else {
      uVar1 = FUN_00494840(*(int *)(param_1 + 0x30) * 0xd);
      *(undefined4 *)(param_1 + 0x34) = uVar1;
      if (*(int *)(param_1 + 0x34) == 0) {
        FUN_00495280(*(void **)(param_1 + 0x38));
        DAT_004e84b0 = 6;
      }
      else {
        local_8 = FUN_00498dc0(*(uint **)(param_1 + 0x24));
        FUN_004988b0(*(uint **)(param_1 + 0x24),*(int *)(param_1 + 0x2c),0);
        for (local_c = 0; local_c < *(uint *)(param_1 + 0x30); local_c = local_c + 1) {
          FUN_004989e0((char *)(*(int *)(param_1 + 0x34) + local_c * 0xd),0xd,1,
                       *(int **)(param_1 + 0x24));
          FUN_004989e0((char *)(*(int *)(param_1 + 0x38) + local_c * 4),4,1,
                       *(int **)(param_1 + 0x24));
        }
        FUN_004988b0(*(uint **)(param_1 + 0x24),local_8,0);
        *param_1 = 1;
      }
    }
  }
  local_8 = 0x435477;
  __chkesp();
  return;
}

