/* __amsg_exit @ 00499690 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Debug */

void __cdecl __amsg_exit(int param_1)

{
  if (DAT_004e8cc8 == 1) {
    __FF_MSGBANNER();
  }
  FUN_004a47b0(param_1);
  (*(code *)PTR___exit_004c6f80)(0xff);
  return;
}

