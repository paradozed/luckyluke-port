/* __CrtSetReportFile @ 00499900 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __CrtSetReportFile
   
   Library: Visual Studio 2003 Debug */

undefined4 __cdecl __CrtSetReportFile(int param_1,int param_2)

{
  undefined4 uVar1;
  HANDLE pvVar2;
  
  if ((param_1 < 0) || (2 < param_1)) {
    uVar1 = 0xfffffffe;
  }
  else if (param_2 == -6) {
    uVar1 = *(undefined4 *)(&DAT_004c6fb8 + param_1 * 4);
  }
  else {
    uVar1 = *(undefined4 *)(&DAT_004c6fb8 + param_1 * 4);
    if (param_2 == -4) {
      pvVar2 = GetStdHandle(0xfffffff5);
      *(HANDLE *)(&DAT_004c6fb8 + param_1 * 4) = pvVar2;
    }
    else if (param_2 == -5) {
      pvVar2 = GetStdHandle(0xfffffff4);
      *(HANDLE *)(&DAT_004c6fb8 + param_1 * 4) = pvVar2;
    }
    else {
      *(int *)(&DAT_004c6fb8 + param_1 * 4) = param_2;
    }
  }
  return uVar1;
}

