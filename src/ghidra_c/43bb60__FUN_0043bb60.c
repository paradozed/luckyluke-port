/* FUN_0043bb60 @ 0043bb60 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043bb60(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  undefined4 local_10;
  int *local_c;
  int local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = *(int **)(param_1 + 0x14);
  local_10 = *(undefined4 *)(param_1 + 8);
  for (local_8 = 0; local_8 < *(int *)(param_1 + 4); local_8 = local_8 + 1) {
    (*DAT_004e8a30)();
    __chkesp();
    (*(code *)(&PTR_FUN_004bccb0)[*local_c])(local_10,local_c);
    __chkesp();
    local_c = local_c + 0x15;
  }
  for (local_8 = 0; local_8 < *(int *)(param_1 + 0x58); local_8 = local_8 + 1) {
    FUN_0043bb60(*(int *)(*(int *)(param_1 + 0x5c) + local_8 * 4));
  }
  local_8 = 0x43bc22;
  __chkesp();
  return;
}

