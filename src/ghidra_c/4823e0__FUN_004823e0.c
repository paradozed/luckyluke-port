/* FUN_004823e0 @ 004823e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004823e0(short *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = (short)((int)*param_1 * *param_2 >> 0xc);
  param_1[1] = (short)((int)param_1[1] * param_2[1] >> 0xc);
  param_1[2] = (short)((int)param_1[2] * param_2[2] >> 0xc);
  param_1[3] = (short)((int)param_1[3] * *param_2 >> 0xc);
  param_1[4] = (short)((int)param_1[4] * param_2[1] >> 0xc);
  param_1[5] = (short)((int)param_1[5] * param_2[2] >> 0xc);
  param_1[6] = (short)((uint)((int)param_1[6] * *param_2) >> 0xc);
  param_1[7] = (short)((int)param_1[7] * param_2[1] >> 0xc);
  param_1[8] = (short)((int)param_1[8] * param_2[2] >> 0xc);
  uStack_8 = 0x48248d;
  __chkesp();
  return;
}

