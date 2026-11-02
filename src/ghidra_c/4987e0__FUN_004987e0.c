/* FUN_004987e0 @ 004987e0 */
/* decompiled from Lucky.exe (Game.run) */


char * __cdecl FUN_004987e0(char *param_1)

{
  _SYSTEMTIME local_20;
  
  GetLocalTime(&local_20);
  param_1[5] = '/';
  param_1[2] = '/';
  param_1[8] = '\0';
  *param_1 = (char)(local_20.wMonth / 10) + '0';
  param_1[1] = (char)(local_20.wMonth % 10) + '0';
  param_1[3] = (char)((local_20._6_4_ & 0xffff) / 10) + '0';
  param_1[4] = (char)((local_20._6_4_ & 0xffff) % 10) + '0';
  param_1[6] = (char)(((uint)local_20.wYear % 100) / 10) + '0';
  param_1[7] = (char)(((uint)local_20.wYear % 100) % 10) + '0';
  return param_1;
}

