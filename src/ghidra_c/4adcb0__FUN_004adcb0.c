/* FUN_004adcb0 @ 004adcb0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_004adcb0(short *param_1,int param_2)

{
  int local_c;
  short *local_8;
  
  local_c = param_2;
  for (local_8 = param_1; (local_c != 0 && (*local_8 != 0)); local_8 = local_8 + 1) {
    local_c = local_c + -1;
  }
  if (*local_8 == 0) {
    param_2 = (int)local_8 - (int)param_1 >> 1;
  }
  return param_2;
}

