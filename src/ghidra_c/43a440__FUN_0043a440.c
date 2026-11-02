/* FUN_0043a440 @ 0043a440 */
/* decompiled from Lucky.exe (Game.run) */


float10 __cdecl FUN_0043a440(float *param_1,float *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  return (float10)param_1[2] * (float10)param_2[2] +
         (float10)param_1[1] * (float10)param_2[1] + (float10)*param_1 * (float10)*param_2;
}

