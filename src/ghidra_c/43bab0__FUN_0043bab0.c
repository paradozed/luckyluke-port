/* FUN_0043bab0 @ 0043bab0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043bab0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int *local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = *(int **)(param_1 + 0x14);
  for (local_8 = 0; local_8 < *(int *)(param_1 + 4); local_8 = local_8 + 1) {
    (*(code *)(&PTR_FUN_004bccd0)[*local_c])(param_1,local_c);
    __chkesp();
    local_c = local_c + 0x15;
  }
  for (local_8 = 0; local_8 < *(int *)(param_1 + 0x58); local_8 = local_8 + 1) {
    FUN_0043bab0(*(int *)(*(int *)(param_1 + 0x5c) + local_8 * 4));
  }
  local_8 = 0x43bb5a;
  __chkesp();
  return;
}

