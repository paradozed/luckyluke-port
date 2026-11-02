/* FID_conflict:_wcomexecmd @ 004a1810 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Multiple Matches With Different Base Names
    _comexecmd
    _wcomexecmd
   
   Library: Visual Studio 2003 Debug */

HANDLE __cdecl FID_conflict__wcomexecmd(int param_1,LPCSTR param_2,int *param_3,int *param_4)

{
  int iVar1;
  char *local_10;
  LPVOID local_c;
  HANDLE local_8;
  
  iVar1 = FUN_004a8480(param_3,param_4,(int *)&local_10,(int *)&local_c);
  if (iVar1 == -1) {
    local_8 = (HANDLE)0xffffffff;
  }
  else {
    local_8 = FUN_004a8120(param_1,param_2,local_10,local_c);
    FUN_004952a0(local_10,2);
    FUN_004952a0(local_c,2);
  }
  return local_8;
}

