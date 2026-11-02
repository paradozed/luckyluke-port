/* FUN_004a7980 @ 004a7980 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004a7980(uint param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < DAT_00509260) &&
     ((*(byte *)((&DAT_00509160)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) & 1) != 0)) {
    uVar1 = *(undefined4 *)((&DAT_00509160)[(int)param_1 >> 5] + (param_1 & 0x1f) * 8);
  }
  else {
    DAT_004e8c64 = 9;
    DAT_004e8c68 = 0;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

