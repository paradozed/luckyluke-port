/* FUN_00486ee0 @ 00486ee0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00486ee0(int param_1)

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
  local_8 = **(int **)(param_1 + 0xd8);
  while (local_8 != 0) {
    local_c = *(int *)(*(int *)(local_8 + 0xdc) + 0x3c);
    FUN_00486d00(param_1,local_8);
    local_8 = local_c;
  }
  local_8 = 0x486f40;
  __chkesp();
  return;
}

