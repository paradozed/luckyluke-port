/* FUN_004a8f10 @ 004a8f10 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004a8f10(uint param_1,uint param_2,byte param_3)

{
  uint local_8;
  
  if (((&DAT_00509041)[param_1 & 0xff] & param_3) == 0) {
    if (param_2 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = *(ushort *)(&DAT_004c6fe6 + (param_1 & 0xff) * 2) & param_2;
    }
    if (local_8 == 0) {
      return 0;
    }
  }
  return 1;
}

