/* FUN_0049a630 @ 0049a630 */
/* decompiled from Lucky.exe (Game.run) */


uint __cdecl FUN_0049a630(int param_1)

{
  uint local_c;
  
  local_c = DAT_0050a298;
  while( true ) {
    if (DAT_0050a298 + DAT_0050a294 * 0x14 <= local_c) {
      return 0;
    }
    if ((uint)(param_1 - *(int *)(local_c + 0xc)) < 0x100000) break;
    local_c = local_c + 0x14;
  }
  return local_c;
}

