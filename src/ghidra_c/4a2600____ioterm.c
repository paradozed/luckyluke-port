/* __ioterm @ 004a2600 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __ioterm
   
   Library: Visual Studio 2003 Debug */

void __cdecl __ioterm(void)

{
  int local_8;
  
  for (local_8 = 0; local_8 < 0x40; local_8 = local_8 + 1) {
    if ((&DAT_00509160)[local_8] != 0) {
      FUN_004952a0((void *)(&DAT_00509160)[local_8],2);
      (&DAT_00509160)[local_8] = 0;
    }
  }
  return;
}

