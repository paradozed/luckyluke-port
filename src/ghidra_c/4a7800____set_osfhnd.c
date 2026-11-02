/* __set_osfhnd @ 004a7800 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __set_osfhnd
   
   Library: Visual Studio 2003 Debug */

int __cdecl __set_osfhnd(int param_1,intptr_t param_2)

{
  int iVar1;
  
  if (((uint)param_1 < DAT_00509260) &&
     (*(int *)((&DAT_00509160)[param_1 >> 5] + (param_1 & 0x1fU) * 8) == -1)) {
    if (DAT_004c6f84 == 1) {
      if (param_1 == 0) {
        SetStdHandle(0xfffffff6,(HANDLE)param_2);
      }
      else if (param_1 == 1) {
        SetStdHandle(0xfffffff5,(HANDLE)param_2);
      }
      else if (param_1 == 2) {
        SetStdHandle(0xfffffff4,(HANDLE)param_2);
      }
    }
    *(intptr_t *)((&DAT_00509160)[param_1 >> 5] + (param_1 & 0x1fU) * 8) = param_2;
    iVar1 = 0;
  }
  else {
    DAT_004e8c64 = 9;
    DAT_004e8c68 = 0;
    iVar1 = -1;
  }
  return iVar1;
}

