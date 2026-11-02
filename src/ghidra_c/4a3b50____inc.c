/* __inc @ 004a3b50 */
/* decompiled from Lucky.exe (Game.run) */


/* Library Function - Single Match
    __inc
   
   Library: Visual Studio 2003 Debug */

uint __cdecl __inc(int *param_1)

{
  uint local_8;
  
  param_1[1] = param_1[1] + -1;
  if (param_1[1] < 0) {
    local_8 = FUN_004a1880(param_1);
  }
  else {
    local_8 = (uint)*(byte *)*param_1;
    *param_1 = *param_1 + 1;
  }
  return local_8;
}

