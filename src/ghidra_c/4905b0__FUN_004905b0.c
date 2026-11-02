/* FUN_004905b0 @ 004905b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004905b0(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_58 [16];
  int local_18;
  undefined2 *local_14;
  undefined2 *local_10;
  undefined2 *local_c;
  int local_8;
  
  puVar2 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while (local_8 = param_2 + -1, -1 < local_8) {
    local_c = *(undefined2 **)(param_1 + local_8 * 0xc);
    local_10 = *(undefined2 **)(param_1 + 4 + local_8 * 0xc);
    local_14 = *(undefined2 **)(param_1 + 8 + local_8 * 0xc);
    if ((DAT_004be3d0 == '\0') ||
       (iVar1 = FUN_00482db0(**(undefined4 **)(param_1 + local_8 * 0xc),
                             **(undefined4 **)(param_1 + 4 + local_8 * 0xc),
                             **(undefined4 **)(param_1 + 8 + local_8 * 0xc)), param_2 = local_8,
       -1 < iVar1)) {
      local_18 = param_3 + local_8 * 0x1c;
      *(undefined2 *)(local_18 + 8) = *local_c;
      *(undefined2 *)(local_18 + 10) = local_c[1];
      *(undefined2 *)(local_18 + 0x10) = *local_10;
      *(undefined2 *)(local_18 + 0x12) = local_10[1];
      *(undefined2 *)(local_18 + 0x18) = *local_14;
      *(undefined2 *)(local_18 + 0x1a) = local_14[1];
      if ((*(byte *)(local_18 + 7) & 2) == 0) {
        FUN_0047d910(local_18,*(int *)(local_c + 2),*(int *)(local_10 + 2),*(int *)(local_14 + 2),0,
                     4);
        param_2 = local_8;
      }
      else {
        FUN_0047d910(local_18,*(int *)(local_c + 2),*(int *)(local_10 + 2),*(int *)(local_14 + 2),0,
                     4);
        param_2 = local_8;
      }
    }
  }
  local_8 = 0x49072c;
  __chkesp();
  return;
}

