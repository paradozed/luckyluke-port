/* FUN_00498cf0 @ 00498cf0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00498cf0(uint *param_1,char *param_2)

{
  code *pcVar1;
  int iVar2;
  
  if ((param_1 == (uint *)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4baff4,0x2f,0,(byte *)"filename != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (((char)*param_1 == '\0') &&
     (iVar2 = FUN_004999a0(2,0x4baff4,0x30,0,(byte *)"*filename != _T(\'\\0\')"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if ((param_2 == (char *)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4baff4,0x31,0,(byte *)"arglist != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if ((*param_2 == '\0') &&
     (iVar2 = FUN_004999a0(2,0x4baff4,0x32,0,(byte *)"*arglist != _T(\'\\0\')"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  FUN_004a2080(param_1,(int *)&param_2,(int *)0x0);
  return;
}

