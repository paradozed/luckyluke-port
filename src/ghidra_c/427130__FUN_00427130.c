/* FUN_00427130 @ 00427130 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00427130(short *param_1,short *param_2)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 *puVar2;
  float10 fVar3;
  longlong lVar4;
  undefined4 local_8c [16];
  double local_4c;
  int local_44;
  double local_40;
  double local_38;
  int local_30;
  double local_2c;
  int local_24;
  double local_20;
  double local_18;
  int local_10;
  short local_c;
  undefined4 local_8;
  
  puVar2 = local_8c;
  for (iVar1 = 0x22; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  *param_1 = *param_1 - (short)DAT_004d28b4;
  *param_2 = *param_2 - (short)DAT_004d28b0;
  local_10 = (int)*param_1;
  local_18 = (double)local_10;
  fVar3 = (float10)FUN_00498004(local_10);
  local_20 = (double)(fVar3 * (float10)local_18);
  local_24 = (int)*param_2;
  local_2c = (double)local_24;
  FUN_00497f54(extraout_ECX);
  lVar4 = __ftol();
  local_8 = CONCAT22(local_8._2_2_,(short)lVar4);
  local_30 = (int)*param_2;
  local_38 = (double)local_30;
  fVar3 = (float10)FUN_00498004(param_2);
  local_40 = (double)(fVar3 * (float10)local_38);
  local_44 = (int)*param_1;
  local_4c = (double)local_44;
  FUN_00497f54(local_44);
  lVar4 = __ftol();
  local_c = (short)lVar4;
  *param_1 = (short)DAT_004d28b4 + (short)local_8;
  *param_2 = (short)DAT_004d28b0 + local_c;
  local_8 = 0x42725c;
  __chkesp();
  return;
}

