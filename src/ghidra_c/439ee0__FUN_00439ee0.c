/* FUN_00439ee0 @ 00439ee0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00439ee0(float *param_1)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 *puVar2;
  float10 fVar3;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_00439d40(param_1);
  fVar3 = (float10)FUN_00498004(extraout_ECX);
  *param_1 = (float)fVar3;
  fVar3 = (float10)FUN_00497f54(param_1);
  param_1[4] = (float)-fVar3;
  fVar3 = (float10)FUN_00497f54(extraout_ECX_00);
  param_1[1] = (float)fVar3;
  fVar3 = (float10)FUN_00498004(extraout_ECX_01);
  param_1[5] = (float)fVar3;
  uStack_8 = 0x439f6e;
  __chkesp();
  return;
}

