/* FUN_004a3af0 @ 004a3af0 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_004a3af0(uint param_1)

{
  uint local_c;
  uint local_8;
  
  if (DAT_004c71e8 < 2) {
    local_8 = *(ushort *)(PTR_DAT_004c6fdc + param_1 * 2) & 4;
  }
  else {
    local_8 = FUN_0049c240(param_1,4);
  }
  if (local_8 == 0) {
    local_c = (param_1 & 0xffffffdf) - 7;
  }
  else {
    local_c = param_1;
  }
  return local_c;
}

