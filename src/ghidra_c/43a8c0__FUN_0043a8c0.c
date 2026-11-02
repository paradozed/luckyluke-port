/* FUN_0043a8c0 @ 0043a8c0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl
FUN_0043a8c0(int param_1,int param_2,int param_3,int param_4,undefined4 *param_5,undefined4 *param_6
            ,undefined4 *param_7)

{
  int iVar1;
  undefined4 *puVar2;
  float10 fVar3;
  longlong lVar4;
  undefined4 local_6c [16];
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  puVar2 = local_6c;
  for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_28 = *(float *)(*(int *)(param_1 + 0xc) + param_3 * 0xc) -
             *(float *)(*(int *)(param_1 + 0xc) + param_2 * 0xc);
  local_24 = *(float *)(*(int *)(param_1 + 0xc) + 4 + param_3 * 0xc) -
             *(float *)(*(int *)(param_1 + 0xc) + 4 + param_2 * 0xc);
  local_20 = *(float *)(*(int *)(param_1 + 0xc) + 8 + param_3 * 0xc) -
             *(float *)(*(int *)(param_1 + 0xc) + 8 + param_2 * 0xc);
  local_1c = *(float *)(*(int *)(param_1 + 0xc) + param_4 * 0xc) -
             *(float *)(*(int *)(param_1 + 0xc) + param_2 * 0xc);
  local_18 = *(float *)(*(int *)(param_1 + 0xc) + 4 + param_4 * 0xc) -
             *(float *)(*(int *)(param_1 + 0xc) + 4 + param_2 * 0xc);
  local_14 = *(float *)(*(int *)(param_1 + 0xc) + 8 + param_4 * 0xc) -
             *(float *)(*(int *)(param_1 + 0xc) + 8 + param_2 * 0xc);
  FUN_0043a3c0(&local_10,&local_28,&local_1c);
  FUN_0043a490(&local_10);
  if (local_8 <= _DAT_004b4938) {
    local_10 = -local_10;
    local_c = -local_c;
    local_8 = -local_8;
    fVar3 = FUN_0043a440(&local_10,(float *)&DAT_004bcca4);
    local_2c = (float)fVar3;
    lVar4 = __ftol();
    *param_5 = (int)lVar4;
    lVar4 = __ftol();
    *param_6 = (int)lVar4;
    lVar4 = __ftol();
    *param_7 = (int)lVar4;
  }
  else {
    *param_5 = 0;
    *param_6 = 0;
    *param_7 = 0;
  }
  local_8 = 6.214155e-39;
  __chkesp();
  return;
}

