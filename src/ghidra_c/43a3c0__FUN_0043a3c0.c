/* FUN_0043a3c0 @ 0043a3c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0043a3c0(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = param_2[1] * param_3[2] - param_2[2] * param_3[1];
  param_1[1] = *param_2 * param_3[2] - param_2[2] * *param_3;
  param_1[2] = *param_2 * param_3[1] - param_2[1] * *param_3;
  return;
}

