/* __isatty @ 004a6bb0 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __isatty
   
   Library: Visual Studio 2003 Debug */

int __cdecl __isatty(int _FileHandle)

{
  uint uVar1;
  
  if ((uint)_FileHandle < DAT_00509260) {
    uVar1 = (int)*(char *)((&DAT_00509160)[_FileHandle >> 5] + 4 + (_FileHandle & 0x1fU) * 8) & 0x40
    ;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

