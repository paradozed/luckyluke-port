/* FUN_0047e8d0 @ 0047e8d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047e8d0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int local_14;
  SIZE_T local_10;
  int *local_c;
  int local_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = (*(int *)(param_1 + 0x10) + 0x14) * 0x10 + *(int *)(param_1 + 0x1c) * 0x28 + 12000 +
             *(int *)(param_1 + 0x48) * 2;
  if (*(int *)(param_1 + 8) == 0) {
    local_8 = param_1;
    local_c = (int *)(param_1 + *(int *)(param_1 + 0x44));
  }
  else {
    local_8 = *(int *)(param_1 + 8);
    local_c = (int *)(local_8 + *(int *)(local_8 + 0x44));
    local_10 = local_10 + local_c[4];
  }
  local_14 = FUN_00439af0(local_10);
  *(int *)(param_1 + 0xbc) = local_14;
  iVar1 = *(int *)(param_1 + 0x10) * 8;
  *(int *)(param_1 + 0xc0) = local_14 + iVar1 + 0xa0;
  iVar1 = iVar1 + 0x140 + *(int *)(param_1 + 0x10) * 8;
  *(int *)(param_1 + 0x20) = local_14 + iVar1;
  iVar1 = iVar1 + *(int *)(param_1 + 0x1c) * 0x28;
  *(int *)(param_1 + 0x4c) = local_14 + iVar1;
  iVar1 = iVar1 + 6000 + *(int *)(param_1 + 0x48);
  *(int *)(param_1 + 0x50) = local_14 + iVar1;
  local_10 = iVar1 + 6000 + *(int *)(param_1 + 0x48);
  *(int *)(param_1 + 0x18) = local_8 + *local_c;
  *(int *)(param_1 + 0x28) = local_8 + local_c[1];
  if (*(int *)(param_1 + 8) == 0) {
    *(int *)(param_1 + 0x30) = local_8 + local_c[3];
  }
  else {
    *(SIZE_T *)(param_1 + 0x30) = local_14 + local_10;
  }
  local_8 = 0x47ea45;
  __chkesp();
  return;
}

