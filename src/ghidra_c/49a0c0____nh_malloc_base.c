/* __nh_malloc_base @ 0049a0c0 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __nh_malloc_base
   
   Library: Visual Studio 2003 Debug */

int * __cdecl __nh_malloc_base(uint param_1,int param_2)

{
  int iVar1;
  int *local_8;
  
  if (param_1 < 0xffffffe1) {
    do {
      if (param_1 < 0xffffffe1) {
        local_8 = FUN_0049a120(param_1);
      }
      else {
        local_8 = (int *)0x0;
      }
      if (local_8 != (int *)0x0) {
        return local_8;
      }
      if (param_2 == 0) {
        return (int *)0x0;
      }
      iVar1 = __callnewh(param_1);
    } while (iVar1 != 0);
  }
  return (int *)0x0;
}

