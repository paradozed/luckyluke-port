/* FUN_00498710 @ 00498710 */
/* decompiled from Lucky.exe (Game.run) */


char * __cdecl FUN_00498710(char *param_1)

{
  _SYSTEMTIME local_18;
  
  GetLocalTime(&local_18);
  param_1[5] = ':';
  param_1[2] = ':';
  param_1[8] = '\0';
  *param_1 = (char)(local_18.wHour / 10) + '0';
  param_1[1] = (char)(local_18.wHour % 10) + '0';
  param_1[3] = (char)(local_18.wMinute / 10) + '0';
  param_1[4] = (char)(local_18.wMinute % 10) + '0';
  param_1[6] = (char)(local_18.wSecond / 10) + '0';
  param_1[7] = (char)(local_18.wSecond % 10) + '0';
  return param_1;
}

