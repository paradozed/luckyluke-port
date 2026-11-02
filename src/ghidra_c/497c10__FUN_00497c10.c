/* FUN_00497c10 @ 00497c10 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 * __cdecl FUN_00497c10(LPCSTR param_1,char *param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_1 == (LPCSTR)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4baf24,0x35,0,(byte *)"file != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    puVar3 = (undefined4 *)(*pcVar1)();
    return puVar3;
  }
  if ((*param_1 == '\0') &&
     (iVar2 = FUN_004999a0(2,0x4baf24,0x36,0,(byte *)"*file != _T(\'\\0\')"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    puVar3 = (undefined4 *)(*pcVar1)();
    return puVar3;
  }
  if ((param_2 == (char *)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4baf24,0x37,0,(byte *)"mode != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    puVar3 = (undefined4 *)(*pcVar1)();
    return puVar3;
  }
  if ((*param_2 == '\0') &&
     (iVar2 = FUN_004999a0(2,0x4baf24,0x38,0,(byte *)"*mode != _T(\'\\0\')"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    puVar3 = (undefined4 *)(*pcVar1)();
    return puVar3;
  }
  puVar3 = FUN_004a01e0();
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = FUN_0049fe50(param_1,param_2,param_3,puVar3);
  }
  return puVar3;
}

