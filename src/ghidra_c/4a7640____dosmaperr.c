/* __dosmaperr @ 004a7640 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __dosmaperr
   
   Library: Visual Studio 2003 Debug */

void __cdecl __dosmaperr(ulong param_1)

{
  uint local_8;
  
  DAT_004e8c68 = param_1;
  local_8 = 0;
  while( true ) {
    if (0x2c < local_8) {
      if ((param_1 < 0x13) || (0x24 < param_1)) {
        if ((param_1 < 0xbc) || (0xca < param_1)) {
          DAT_004e8c64 = 0x16;
        }
        else {
          DAT_004e8c64 = 8;
        }
      }
      else {
        DAT_004e8c64 = 0xd;
      }
      return;
    }
    if (param_1 == *(ulong *)(&DAT_004c7880 + local_8 * 8)) break;
    local_8 = local_8 + 1;
  }
  DAT_004e8c64 = *(undefined4 *)(&DAT_004c7884 + local_8 * 8);
  return;
}

