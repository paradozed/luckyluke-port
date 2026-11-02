/* FUN_0043a640 @ 0043a640 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0043a640(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_78 [16];
  uint local_38;
  undefined4 uStack_34;
  uint local_30;
  undefined4 uStack_2c;
  uint local_28;
  undefined4 uStack_24;
  uint local_20;
  undefined4 uStack_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  int local_8;
  
  puVar2 = local_78;
  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_20 = DAT_004be3c8;
  uStack_1c = 0;
  local_c = (float)DAT_004be3c8 / _DAT_004b5d54;
  local_28 = DAT_004be3cc;
  uStack_24 = 0;
  local_10 = (float)DAT_004be3cc / _DAT_004b5d54;
  local_30 = DAT_004be3c8;
  uStack_2c = 0;
  local_14 = ((float)DAT_004be3c8 / _DAT_004b6a98) * _DAT_004b6a94;
  local_38 = DAT_004be3cc;
  uStack_34 = 0;
  local_18 = ((float)DAT_004be3cc / _DAT_004b5d5c) * _DAT_004b6a94;
  for (local_8 = 0; local_8 < *param_1; local_8 = local_8 + 1) {
    *(float *)(param_1[2] + local_8 * 0xc) =
         (local_14 * *(float *)(param_1[3] + local_8 * 0xc)) /
         *(float *)(param_1[3] + 8 + local_8 * 0xc) + local_c;
    *(float *)(param_1[2] + 4 + local_8 * 0xc) =
         local_10 -
         (local_18 * *(float *)(param_1[3] + 4 + local_8 * 0xc)) /
         *(float *)(param_1[3] + 8 + local_8 * 0xc);
    *(undefined4 *)(param_1[2] + 8 + local_8 * 0xc) =
         *(undefined4 *)(param_1[3] + 8 + local_8 * 0xc);
  }
  for (local_8 = 0; local_8 < param_1[0x16]; local_8 = local_8 + 1) {
    FUN_0043a640(*(int **)(param_1[0x17] + local_8 * 4));
  }
  local_8 = 0x43a7c2;
  __chkesp();
  return;
}

