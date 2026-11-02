/* FUN_0049e990 @ 0049e990 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0049e990(char *param_1,int param_2,int *param_3,int *param_4)

{
  char cVar1;
  
  do {
    if (param_2 < 1) {
      return;
    }
    cVar1 = *param_1;
    param_1 = param_1 + 1;
    FUN_0049e8d0((int)cVar1,param_3,param_4);
    param_2 = param_2 + -1;
  } while (*param_4 != -1);
  return;
}

