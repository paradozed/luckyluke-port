/* FUN_0047e6b0 @ 0047e6b0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0047e6b0(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  undefined4 *local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0;
  local_10 = *(undefined4 **)(param_1 + 0x4c + DAT_004e8ad8 * 4);
  for (local_8 = *(int *)(param_1 + 0x30); local_8 != 0; local_8 = *(int *)(local_8 + 0x10)) {
    local_10 = (undefined4 *)((int)local_10 + *(int *)(local_8 + 0xc));
    if (*(int *)(local_8 + 0x10) == 0) {
      local_c = local_8;
    }
  }
  if (local_c != 0) {
    FUN_00497690(local_10,param_3,*(uint *)(param_2 + 0xc));
    *(int *)(local_c + 0x10) = param_2;
  }
  local_8 = 0x47e747;
  __chkesp();
  return;
}

