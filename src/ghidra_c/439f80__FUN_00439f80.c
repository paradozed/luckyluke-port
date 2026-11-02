/* FUN_00439f80 @ 00439f80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439f80(float *param_1,int param_2,int param_3)

{
  int iVar1;
  float *pfVar2;
  undefined4 *puVar3;
  undefined4 local_8c [16];
  int local_4c;
  int local_48;
  float local_44 [16];
  
  puVar3 = local_8c;
  for (iVar1 = 0x22; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  for (local_4c = 0; local_4c < 4; local_4c = local_4c + 1) {
    for (local_48 = 0; local_48 < 4; local_48 = local_48 + 1) {
      local_44[local_48 * 4 + local_4c] =
           *(float *)(param_2 + 0x30 + local_4c * 4) * *(float *)(param_3 + 0xc + local_48 * 0x10) +
           *(float *)(param_2 + 0x20 + local_4c * 4) * *(float *)(param_3 + 8 + local_48 * 0x10) +
           *(float *)(param_2 + 0x10 + local_4c * 4) * *(float *)(param_3 + 4 + local_48 * 0x10) +
           *(float *)(param_2 + local_4c * 4) * *(float *)(param_3 + local_48 * 0x10);
    }
  }
  pfVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

