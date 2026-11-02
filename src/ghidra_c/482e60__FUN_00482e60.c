/* FUN_00482e60 @ 00482e60 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00482e60(short *param_1,short *param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  int local_14;
  int local_10;
  int local_c;
  undefined4 uStack_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_14 = (int)DAT_00508840 * (int)*param_1 + (int)DAT_00508842 * (int)param_1[1] +
             (int)DAT_00508844 * (int)param_1[2] >> 0xc;
  local_10 = (int)DAT_00508846 * (int)*param_1 + (int)DAT_00508848 * (int)param_1[1] +
             (int)DAT_0050884a * (int)param_1[2] >> 0xc;
  local_c = (int)DAT_0050884c * (int)*param_1 + (int)DAT_0050884e * (int)param_1[1] +
            (int)DAT_00508850 * (int)param_1[2] >> 0xc;
  iVar1 = local_10 + DAT_00508858;
  _DAT_004e8ab0 = local_c + DAT_0050885c;
  if (_DAT_004e8ab0 == 0) {
    _DAT_004e8ab0 = 0;
    local_c = 0;
    *param_2 = (short)(local_14 + DAT_00508854) * (short)DAT_004be3dc + (short)DAT_004e8aa8;
    param_2[1] = (short)iVar1 * (short)DAT_004be3e0 + (short)DAT_004e8aac;
  }
  else {
    *param_2 = (short)(((local_14 + DAT_00508854) * DAT_004be3dc) / _DAT_004e8ab0) +
               (short)DAT_004e8aa8;
    param_2[1] = (short)((iVar1 * DAT_004be3e0) / _DAT_004e8ab0) + (short)DAT_004e8aac;
  }
  _DAT_00508830 = _DAT_00508830 + _DAT_004e8ab0;
  *param_3 = _DAT_004e8ab0 >> 2;
  uStack_8 = 0x482f9e;
  __chkesp();
  return;
}

