/* FUN_00498260 @ 00498260 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00498260(int param_1,uint *param_2,char *param_3)

{
  code *pcVar1;
  int iVar2;
  
  if ((param_2 == (uint *)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4baf88,0x36,0,(byte *)"pathname != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (((char)*param_2 == '\0') &&
     (iVar2 = FUN_004999a0(2,0x4baf88,0x37,0,(byte *)"*pathname != _T(\'\\0\')"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if ((param_3 == (char *)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4baf88,0x38,0,(byte *)"arglist != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if ((*param_3 == '\0') &&
     (iVar2 = FUN_004999a0(2,0x4baf88,0x39,0,(byte *)"*arglist != _T(\'\\0\')"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  FUN_004a1610(param_1,param_2,(int *)&param_3,(int *)0x0);
  return;
}

