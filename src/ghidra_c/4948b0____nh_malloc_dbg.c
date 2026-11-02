/* __nh_malloc_dbg @ 004948b0 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __nh_malloc_dbg
   
   Library: Visual Studio 2003 Debug */

int * __cdecl __nh_malloc_dbg(uint param_1,int param_2,uint param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  
  while( true ) {
    piVar1 = FUN_00494920(param_1,param_3,param_4,param_5);
    if (piVar1 != (int *)0x0) {
      return piVar1;
    }
    if (param_2 == 0) break;
    iVar2 = __callnewh(param_1);
    if (iVar2 == 0) {
      return (int *)0x0;
    }
  }
  return (int *)0x0;
}

