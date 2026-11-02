/* FUN_004a89f0 @ 004a89f0 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_004a89f0(int param_1)

{
  uint local_8;
  
  if (DAT_004c71e8 < 2) {
    local_8 = *(ushort *)(PTR_DAT_004c6fdc + param_1 * 2) & 1;
  }
  else {
    local_8 = FUN_0049c240(param_1,1);
  }
  return local_8;
}

