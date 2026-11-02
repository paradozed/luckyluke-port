/* FUN_0049d720 @ 0049d720 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0049d720(undefined4 param_1,char *param_2,size_t param_3,int param_4)

{
  int iVar1;
  char *pcVar2;
  char *local_8;
  
  DAT_004e8ce8 = (int *)FUN_004a69b0();
  DAT_004e8cf0 = DAT_004e8ce8[1] + -1;
  iVar1 = *DAT_004e8ce8;
  FUN_004a68b0(param_2 + (iVar1 == 0x2d),param_3,(int)DAT_004e8ce8);
  DAT_004e8cf4 = DAT_004e8cf0 < DAT_004e8ce8[1] + -1;
  DAT_004e8cf0 = DAT_004e8ce8[1] + -1;
  if ((DAT_004e8cf0 < -4) || ((int)param_3 <= DAT_004e8cf0)) {
    __cftoe_g(param_1,param_2,param_3,param_4);
  }
  else {
    pcVar2 = param_2 + (iVar1 == 0x2d);
    if ((bool)DAT_004e8cf4) {
      do {
        local_8 = pcVar2;
        pcVar2 = local_8 + 1;
      } while (*local_8 != '\0');
      local_8[-1] = '\0';
    }
    __cftof_g(param_1,param_2,param_3);
  }
  return;
}

