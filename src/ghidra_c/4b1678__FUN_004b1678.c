/* FUN_004b1678 @ 004b1678 */
/* decompiled from Lucky.exe (Game.run) */


longlong __fastcall FUN_004b1678(int *param_1,uint param_2)

{
  if ((((*param_1 < DAT_0050a2c4) && (param_1[1] < DAT_0050a2bc)) && (DAT_0050a2c8 < param_1[2])) &&
     (DAT_0050a2c0 < param_1[3])) {
    if (*param_1 <= DAT_0050a2c8) {
      *param_1 = DAT_0050a2c8;
    }
    if (param_1[1] <= DAT_0050a2c0) {
      param_1[1] = DAT_0050a2c0;
    }
    if (DAT_0050a2c4 < param_1[2]) {
      param_1[2] = DAT_0050a2c4;
    }
    if (DAT_0050a2bc < param_1[3]) {
      param_1[3] = DAT_0050a2bc;
    }
    return CONCAT44(param_2,1);
  }
  return (ulonglong)param_2 << 0x20;
}

