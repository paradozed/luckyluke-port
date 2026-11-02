/* FUN_0043a520 @ 0043a520 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043a520(int *param_1,int param_2)

{
  int iVar1;
  float *pfVar2;
  undefined4 *puVar3;
  float *pfVar4;
  undefined4 local_88 [16];
  float local_48 [16];
  int local_8;
  
  puVar3 = local_88;
  for (iVar1 = 0x21; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  pfVar2 = (float *)(param_1 + 6);
  pfVar4 = local_48;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar4 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfVar4 = pfVar4 + 1;
  }
  FUN_00439f80(local_48,(int)local_48,param_2);
  for (local_8 = 0; local_8 < *param_1; local_8 = local_8 + 1) {
    FUN_0043a0f0((float *)(param_1[3] + local_8 * 0xc),local_48,
                 (float *)(param_1[4] + local_8 * 0xc));
  }
  for (local_8 = 0; local_8 < param_1[0x16]; local_8 = local_8 + 1) {
    FUN_0043a520(*(int **)(param_1[0x17] + local_8 * 4),(int)local_48);
  }
  local_8 = 0x43a5f2;
  __chkesp();
  return;
}

