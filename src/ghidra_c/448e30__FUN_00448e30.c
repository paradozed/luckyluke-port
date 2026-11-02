/* FUN_00448e30 @ 00448e30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00448e30(int *param_1,short *param_2)

{
  int iVar1;
  short sVar2;
  undefined4 *puVar3;
  longlong lVar4;
  undefined4 local_58 [16];
  int local_18;
  uint local_14;
  undefined4 local_10;
  short local_c;
  undefined4 local_8;
  
  puVar3 = local_58;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if ((param_1 != (int *)0x0) && (param_2 != (short *)0x0)) {
    param_2[0xe] = param_2[0xe] + (short)(char)param_2[0x13];
    param_2[0xf] = param_2[0xf] + (short)*(char *)((int)param_2 + 0x27);
    sVar2 = param_2[2] * 0x10;
    local_8 = CONCAT22(local_8._2_2_,sVar2);
    if (sVar2 < param_2[0xe]) {
      param_2[0xe] = param_2[0xe] + param_2[2] * -0x10;
    }
    else if (param_2[0xe] < 0) {
      param_2[0xe] = param_2[0xe] + sVar2;
    }
    local_c = param_2[3] * 0x10;
    if (local_c < param_2[0xf]) {
      param_2[0xf] = param_2[0xf] + param_2[3] * -0x10;
    }
    else if (param_2[0xf] < 0) {
      param_2[0xf] = param_2[0xf] + local_c;
    }
    param_2[4] = (short)((int)((int)param_2[0xe] + ((int)param_2[0xe] >> 0x1f & 0xfU)) >> 4) +
                 (short)((int)param_2[0x10] * *param_1 +
                         ((int)param_2[0x10] * *param_1 >> 0x1f & 0xffU) >> 8);
    if ((short)param_1[4] == 0) {
      param_2[5] = (short)(param_1[1] * (int)param_2[0x11] +
                           (param_1[1] * (int)param_2[0x11] >> 0x1f & 0xffU) >> 8);
    }
    else {
      iVar1 = ((short)param_1[4] + DAT_004e8680 + param_1[1]) * (int)param_2[0x11];
      param_2[5] = (short)(iVar1 + (iVar1 >> 0x1f & 0xffU) >> 8);
    }
    param_2[5] = param_2[5] +
                 (short)((int)((int)param_2[0xf] + ((int)param_2[0xf] >> 0x1f & 0xfU)) >> 4);
    param_2[4] = param_2[4] % param_2[2];
    param_2[5] = param_2[5] % param_2[3];
    param_2[4] = param_2[4] + *param_2;
    param_2[5] = param_2[5] + param_2[1];
    if (DAT_004e85b8 == 0xd) {
      local_14 = (uint)(DAT_004be3cc * 300) / 0x1e0;
      local_18 = DAT_00508198 + -0x6fa;
      lVar4 = __ftol();
      local_10._0_2_ = (short)lVar4;
      param_2[5] = param_2[5] + (short)local_10;
      local_10 = (int)lVar4;
      (*DAT_004e8a2c)(10,200,"Camera Y: %d",DAT_00508198);
      __chkesp();
      (*DAT_004e8a2c)(10,0xd2,"Decrement: %d",local_10);
      __chkesp();
    }
  }
  local_8 = 0x4490e5;
  __chkesp();
  return;
}

