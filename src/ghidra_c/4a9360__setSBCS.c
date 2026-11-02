/* setSBCS @ 004a9360 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    _setSBCS
   
   Library: Visual Studio 2003 Debug */

void __cdecl setSBCS(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x101; local_8 = local_8 + 1) {
    (&DAT_00509040)[local_8] = 0;
  }
  DAT_00508f20 = 0;
  DAT_00508f3c = 0;
  DAT_00509144 = 0;
  for (local_8 = 0; local_8 < 6; local_8 = local_8 + 1) {
    *(undefined2 *)(&DAT_00508f30 + local_8 * 2) = 0;
  }
  return;
}

