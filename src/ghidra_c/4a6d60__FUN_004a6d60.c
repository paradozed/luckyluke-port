/* FUN_004a6d60 @ 004a6d60 */
/* decompiled from Lucky.exe (Game.run) */


short * __cdecl FUN_004a6d60(short *param_1,short *param_2)

{
  short sVar1;
  short *local_8;
  
  local_8 = param_1;
  do {
    *local_8 = *param_2;
    sVar1 = *local_8;
    local_8 = local_8 + 1;
    param_2 = param_2 + 1;
  } while (sVar1 != 0);
  return param_1;
}

