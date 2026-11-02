/* FUN_004a8a70 @ 004a8a70 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_004a8a70(int param_1)

{
  uint local_8;
  
  if (DAT_004c71e8 < 2) {
    local_8 = *(ushort *)(PTR_DAT_004c6fdc + param_1 * 2) & 4;
  }
  else {
    local_8 = FUN_0049c240(param_1,4);
  }
  return local_8;
}

