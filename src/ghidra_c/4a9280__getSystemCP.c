/* getSystemCP @ 004a9280 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    _getSystemCP
   
   Library: Visual Studio 2003 Debug */

UINT __cdecl getSystemCP(UINT param_1)

{
  DAT_004e8e8c = 0;
  if (param_1 == 0xfffffffe) {
    DAT_004e8e8c = 1;
    param_1 = GetOEMCP();
  }
  else if (param_1 == 0xfffffffd) {
    DAT_004e8e8c = 1;
    param_1 = GetACP();
  }
  else if (param_1 == 0xfffffffc) {
    DAT_004e8e8c = 1;
    param_1 = DAT_004e8ea8;
  }
  return param_1;
}

