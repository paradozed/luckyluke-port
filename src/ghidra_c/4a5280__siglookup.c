/* siglookup @ 004a5280 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    _siglookup
   
   Library: Visual Studio 2003 Debug */

undefined4 * __cdecl siglookup(int param_1)

{
  undefined4 *local_8;
  
  local_8 = &DAT_004c7738;
  do {
    if (local_8[1] == param_1) break;
    local_8 = local_8 + 3;
  } while (local_8 < &DAT_004c7738 + DAT_004c77b8 * 3);
  if ((&DAT_004c7738 + DAT_004c77b8 * 3 <= local_8) || (local_8[1] != param_1)) {
    local_8 = (undefined4 *)0x0;
  }
  return local_8;
}

