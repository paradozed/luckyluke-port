/* FUN_0049d590 @ 0049d590 */
/* decompiled from Lucky.exe (Game.run) */


char * __cdecl FUN_0049d590(undefined4 param_1,char *param_2,size_t param_3)

{
  int iVar1;
  size_t local_14;
  int *local_c;
  char *local_8;
  
  if (DAT_004e8cec == '\0') {
    local_c = (int *)FUN_004a69b0();
    FUN_004a68b0(param_2 + (*local_c == 0x2d),param_3 + local_c[1],(int)local_c);
  }
  else {
    local_c = DAT_004e8ce8;
    if (DAT_004e8cf0 == param_3) {
      iVar1 = DAT_004e8cf0 + (*DAT_004e8ce8 == 0x2d);
      param_2[iVar1] = '0';
      (param_2 + iVar1)[1] = '\0';
    }
  }
  local_8 = param_2;
  if (*local_c == 0x2d) {
    *param_2 = '-';
    local_8 = param_2 + 1;
  }
  if (local_c[1] < 1) {
    __shift(local_8,1);
    *local_8 = '0';
    local_8 = local_8 + 1;
  }
  else {
    local_8 = local_8 + local_c[1];
  }
  if (0 < (int)param_3) {
    __shift(local_8,1);
    *local_8 = DAT_004c71ec;
    if (local_c[1] < 0) {
      if (DAT_004e8cec == '\0') {
        if ((int)param_3 < -local_c[1]) {
          local_14 = param_3;
        }
        else {
          local_14 = -local_c[1];
        }
        param_3 = local_14;
      }
      else {
        param_3 = -local_c[1];
      }
      __shift(local_8 + 1,param_3);
      _memset(local_8 + 1,0x30,param_3);
    }
  }
  return param_2;
}

