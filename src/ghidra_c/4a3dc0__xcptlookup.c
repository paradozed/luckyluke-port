/* xcptlookup @ 004a3dc0 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    _xcptlookup
   
   Library: Visual Studio 2003 Debug */

int * __cdecl xcptlookup(int param_1)

{
  int *local_8;
  
  local_8 = &DAT_004c7738;
  do {
    if (*local_8 == param_1) break;
    local_8 = local_8 + 3;
  } while (local_8 < &DAT_004c7738 + DAT_004c77b8 * 3);
  if ((&DAT_004c7738 + DAT_004c77b8 * 3 <= local_8) || (*local_8 != param_1)) {
    local_8 = (int *)0x0;
  }
  return local_8;
}

