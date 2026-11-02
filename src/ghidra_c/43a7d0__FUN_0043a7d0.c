/* FUN_0043a7d0 @ 0043a7d0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043a7d0(int *param_1,float param_2,float param_3,float param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  for (local_8 = 0; local_8 < *param_1; local_8 = local_8 + 1) {
    *(float *)(param_1[4] + local_8 * 0xc) = param_2 * *(float *)(param_1[4] + local_8 * 0xc);
    *(float *)(param_1[4] + 4 + local_8 * 0xc) =
         param_3 * *(float *)(param_1[4] + 4 + local_8 * 0xc);
    *(float *)(param_1[4] + 8 + local_8 * 0xc) =
         param_4 * *(float *)(param_1[4] + 8 + local_8 * 0xc);
  }
  for (local_8 = 0; local_8 < param_1[0x16]; local_8 = local_8 + 1) {
    FUN_0043a7d0(*(int **)(param_1[0x17] + local_8 * 4),param_2,param_3,param_4);
  }
  local_8 = 0x43a8ba;
  __chkesp();
  return;
}

