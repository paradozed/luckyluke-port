/* FUN_00485e70 @ 00485e70 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00485e70(short *param_1,int *param_2,short *param_3,short param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [16];
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_3 = *param_3 * param_4;
  param_3[1] = param_3[1] * param_4;
  param_3[2] = param_3[2] * param_4;
  param_3[3] = param_3[3] * param_4;
  if (DAT_004be3d4 != 1) {
    *param_3 = (short)((uint)(*param_3 * DAT_004be3c8) >> 9);
    param_3[2] = (short)((uint)(param_3[2] * DAT_004be3c8) >> 9);
    if (DAT_004e8adc != 0) {
      param_3[1] = (short)((uint)(param_3[1] * DAT_004be3cc) >> 8);
      param_3[3] = (short)((uint)(param_3[3] * DAT_004be3cc) >> 8);
    }
  }
  *param_1 = *param_3;
  param_1[1] = param_3[1];
  param_1[2] = 0x11;
  param_1[4] = *param_3 + param_3[2];
  param_1[5] = param_3[1];
  param_1[6] = 0x11;
  param_1[8] = *param_3;
  param_1[9] = param_3[1] + param_3[3];
  param_1[10] = 0x11;
  param_1[0xc] = *param_3 + param_3[2];
  param_1[0xd] = param_3[1] + param_3[3];
  param_1[0xe] = 0x11;
  *param_2 = (int)*param_3;
  param_2[1] = (int)param_3[1];
  if (*param_2 < param_2[2]) {
    param_2[2] = *param_2;
  }
  if (param_2[1] < param_2[2]) {
    param_2[2] = param_2[1];
  }
  param_2[3] = (int)*param_3 + (int)param_3[2];
  param_2[4] = (int)param_3[1] + (int)param_3[3];
  if (param_2[5] < param_2[3]) {
    param_2[5] = param_2[3];
  }
  if (param_2[5] < param_2[4]) {
    param_2[5] = param_2[4];
  }
  return;
}

