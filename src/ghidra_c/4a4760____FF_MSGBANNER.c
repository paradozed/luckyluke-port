/* __FF_MSGBANNER @ 004a4760 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __FF_MSGBANNER
   
   Library: Visual Studio 2003 Debug */

void __cdecl __FF_MSGBANNER(void)

{
  if ((DAT_004e8cc8 == 1) || ((DAT_004e8cc8 == 0 && (DAT_004c6f84 == 1)))) {
    FUN_004a47b0(0xfc);
    if (DAT_004e8e28 != (code *)0x0) {
      (*DAT_004e8e28)();
    }
    FUN_004a47b0(0xff);
  }
  return;
}

