/* FUN_004207b0 @ 004207b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004207b0(uint param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  int *local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  iVar1 = FUN_00494c40(param_1 << 2,1);
  *local_8 = iVar1;
  iVar1 = FUN_00494c40(param_1 << 2,1);
  local_8[1] = iVar1;
  local_8[2] = param_1;
  local_8[3] = param_2;
  for (local_c = 0; local_c < param_1; local_c = local_c + 1) {
    *(undefined4 *)(*local_8 + local_c * 4) = 0;
  }
  for (local_c = 0; local_c < param_2; local_c = local_c + 1) {
    *(undefined4 *)(local_8[1] + local_c * 4) = 0;
  }
  local_8 = (int *)0x420870;
  __chkesp();
  return;
}

