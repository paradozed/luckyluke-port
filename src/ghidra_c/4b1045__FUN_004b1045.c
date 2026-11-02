/* FUN_004b1045 @ 004b1045 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004b1045(uint param_1,uint *param_2)

{
  byte bVar1;
  byte local_8;
  
  _memset(param_2,0,0x28);
  *param_2 = param_1 & 0x7ff;
  param_2[1] = param_1 >> 0xb & 0x7ff;
  param_2[2] = (param_1 >> 0x16 & 3) * 8 + 8;
  param_2[3] = param_1 >> 0x18 & 1;
  bVar1 = (byte)(param_1 >> 0x18);
  local_8 = bVar1 >> 1;
  if ((param_1 >> 0x19 & 1) == 0) {
    param_2[4] = 0;
  }
  else {
    param_2[4] = 1;
  }
  if ((local_8 & 2) == 0) {
    param_2[5] = 0;
  }
  else {
    param_2[5] = 1;
  }
  local_8 = bVar1 >> 1;
  if ((param_1 >> 0x19 & 4) == 0) {
    param_2[6] = 0;
  }
  else {
    param_2[6] = 1;
  }
  if ((local_8 & 8) == 0) {
    param_2[7] = 0;
  }
  else {
    param_2[7] = 1;
  }
  if ((local_8 & 0x10) == 0) {
    param_2[8] = 0;
  }
  else {
    param_2[8] = 1;
  }
  if ((local_8 & 0x20) == 0) {
    param_2[9] = 0;
  }
  else {
    param_2[9] = 1;
  }
  return;
}

