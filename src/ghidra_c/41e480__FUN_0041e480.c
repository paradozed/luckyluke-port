/* FUN_0041e480 @ 0041e480 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041e480(int *param_1,short *param_2,short *param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = (((int)*param_2 - (int)*param_3) * 0x1000) / param_4;
  param_1[1] = (((int)param_2[1] - (int)param_3[1]) * 0x1000) / param_4;
  param_1[2] = (((int)param_2[2] - (int)param_3[2]) * 0x1000) / param_4;
  return;
}

