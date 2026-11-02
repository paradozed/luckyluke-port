/* FUN_0043a1c0 @ 0043a1c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043a1c0(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  undefined4 *puVar6;
  undefined4 local_90 [19];
  float local_44 [4];
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar6 = local_90;
  for (iVar4 = 0x23; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  local_44[0] = *param_1;
  local_34 = param_1[1];
  local_24 = param_1[2];
  local_44[1] = param_1[4];
  local_30 = param_1[5];
  local_20 = param_1[6];
  local_44[2] = param_1[8];
  local_2c = param_1[9];
  local_1c = param_1[10];
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  local_8 = 0x3f800000;
  fVar1 = param_1[3];
  fVar2 = param_1[7];
  fVar3 = param_1[0xb];
  local_44[3] = -(fVar3 * param_1[8] + fVar2 * param_1[4] + fVar1 * *param_1);
  local_28 = -(fVar3 * param_1[9] + fVar2 * param_1[5] + fVar1 * param_1[1]);
  local_18 = -(fVar3 * param_1[10] + fVar2 * param_1[6] + fVar1 * param_1[2]);
  pfVar5 = local_44;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *param_1 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

