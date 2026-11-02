/* FUN_0043a0f0 @ 0043a0f0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043a0f0(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  int iVar15;
  undefined4 *puVar16;
  undefined4 local_50 [19];
  
  puVar16 = local_50;
  for (iVar15 = 0x13; iVar15 != 0; iVar15 = iVar15 + -1) {
    *puVar16 = 0xcccccccc;
    puVar16 = puVar16 + 1;
  }
  fVar1 = param_2[4];
  fVar2 = *param_3;
  fVar3 = param_2[5];
  fVar4 = param_3[1];
  fVar5 = param_2[6];
  fVar6 = param_3[2];
  fVar7 = param_2[7];
  fVar8 = param_2[8];
  fVar9 = *param_3;
  fVar10 = param_2[9];
  fVar11 = param_3[1];
  fVar12 = param_2[10];
  fVar13 = param_3[2];
  fVar14 = param_2[0xb];
  *param_1 = param_2[2] * param_3[2] + param_2[1] * param_3[1] + *param_2 * *param_3 + param_2[3];
  param_1[1] = fVar5 * fVar6 + fVar3 * fVar4 + fVar1 * fVar2 + fVar7;
  param_1[2] = fVar12 * fVar13 + fVar10 * fVar11 + fVar8 * fVar9 + fVar14;
  return;
}

