/* __callnewh @ 0049a070 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __callnewh
   
   Library: Visual Studio 2003 Debug */

int __cdecl __callnewh(size_t _Size)

{
  int iVar1;
  
  if ((DAT_004e8cd4 != (code *)0x0) && (iVar1 = (*DAT_004e8cd4)(_Size), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

