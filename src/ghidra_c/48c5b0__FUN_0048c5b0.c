/* FUN_0048c5b0 @ 0048c5b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0048c5b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  int local_1c;
  undefined2 *local_18;
  undefined2 *local_14;
  undefined2 *local_10;
  undefined2 *local_c;
  int local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while (local_8 = param_2 + -1, -1 < local_8) {
    local_c = *(undefined2 **)(param_1 + local_8 * 0x10);
    local_10 = *(undefined2 **)(param_1 + 4 + local_8 * 0x10);
    local_14 = *(undefined2 **)(param_1 + 8 + local_8 * 0x10);
    local_18 = *(undefined2 **)(param_1 + 0xc + local_8 * 0x10);
    if ((((DAT_004e85b8 == 7) && (*(short *)(param_3 + 0x16 + local_8 * 0x28) == 0xc)) &&
        (*(char *)(param_3 + 0xc + local_8 * 0x28) == -3)) &&
       (*(char *)(param_3 + 0xd + local_8 * 0x28) == -0x30)) {
      *(undefined2 *)(param_3 + 0x16 + local_8 * 0x28) = 0xb;
    }
    if ((DAT_004be3d0 == '\0') ||
       (iVar1 = FUN_00482db0(**(undefined4 **)(param_1 + local_8 * 0x10),
                             **(undefined4 **)(param_1 + 4 + local_8 * 0x10),
                             **(undefined4 **)(param_1 + 0xc + local_8 * 0x10)), param_2 = local_8,
       -1 < iVar1)) {
      local_1c = param_3 + local_8 * 0x28;
      *(undefined2 *)(local_1c + 8) = *local_c;
      *(undefined2 *)(local_1c + 10) = local_c[1];
      *(undefined2 *)(local_1c + 0x10) = *local_10;
      *(undefined2 *)(local_1c + 0x12) = local_10[1];
      *(undefined2 *)(local_1c + 0x18) = *local_18;
      *(undefined2 *)(local_1c + 0x1a) = local_18[1];
      *(undefined2 *)(local_1c + 0x20) = *local_14;
      *(undefined2 *)(local_1c + 0x22) = local_14[1];
      if ((*(byte *)(local_1c + 7) & 2) == 0) {
        FUN_0047d910(local_1c,*(int *)(local_c + 2),*(int *)(local_10 + 2),*(int *)(local_18 + 2),
                     *(int *)(local_14 + 2),3);
        param_2 = local_8;
      }
      else {
        FUN_0047d910(local_1c,*(int *)(local_c + 2),*(int *)(local_10 + 2),*(int *)(local_18 + 2),
                     *(int *)(local_14 + 2),3);
        param_2 = local_8;
      }
    }
  }
  local_8 = 0x48c7bd;
  __chkesp();
  return;
}

