/* __nh_malloc @ 00494890 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __nh_malloc
   
   Library: Visual Studio 2003 Debug */

void * __cdecl __nh_malloc(size_t _Size,int _NhFlag)

{
  int *piVar1;
  
  piVar1 = __nh_malloc_dbg(_Size,_NhFlag,1,0,0);
  return piVar1;
}

