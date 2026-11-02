/* FUN_0046e0f0 @ 0046e0f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0046e0f0(short *param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  uint local_1c;
  int local_18;
  uint local_14;
  uint local_10;
  undefined2 *local_c;
  undefined2 *local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_18 = *param_1 * 4;
  local_8 = (undefined2 *)(*(int *)(DAT_004f58a4 + param_2 * 4) + param_1[1] * 0x200 + *param_1 * 8)
  ;
  local_c = (undefined2 *)(*(int *)(DAT_004f58a4 + param_3 * 4) + param_5 * 0x200 + param_4 * 8);
  iVar1 = (int)param_1[2];
  local_1c = iVar1 * 4;
  for (local_14 = 0; local_14 < (uint)(int)param_1[3]; local_14 = local_14 + 1) {
    for (local_10 = 0; local_10 < local_1c; local_10 = local_10 + 1) {
      *local_c = *local_8;
      local_c = local_c + 1;
      local_8 = local_8 + 1;
    }
    local_c = local_c + iVar1 * -4 + 0x100;
    local_8 = local_8 + iVar1 * -4 + 0x100;
  }
  (*DAT_004e8a24)(param_3,*(undefined4 *)(DAT_004f58a4 + param_3 * 4));
  __chkesp();
  local_8 = (undefined2 *)0x46e214;
  __chkesp();
  return;
}

