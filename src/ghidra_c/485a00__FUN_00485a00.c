/* FUN_00485a00 @ 00485a00 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00485a00(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = *(int *)(param_1 + 0xcc) + 0x2c;
  if (*(short *)(*(int *)(param_1 + 0xcc) + 0x2e) != 0) {
    do {
      local_8 = *(int *)(local_c + 0x10);
      FUN_00439c30(*(PVOID *)(local_c + 4));
      local_c = local_8;
    } while (local_8 != 0);
  }
  local_8 = 0x485a65;
  __chkesp();
  return;
}

