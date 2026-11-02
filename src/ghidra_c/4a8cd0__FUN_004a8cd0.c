/* FUN_004a8cd0 @ 004a8cd0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004a8cd0(int param_1)

{
  undefined4 local_c;
  uint local_8;
  
  if (DAT_004c71e8 < 2) {
    local_8 = *(ushort *)(PTR_DAT_004c6fdc + param_1 * 2) & 0x103;
  }
  else {
    local_8 = FUN_0049c240(param_1,0x103);
  }
  if ((local_8 == 0) && (param_1 != 0x5f)) {
    local_c = 0;
  }
  else {
    local_c = 1;
  }
  return local_c;
}

