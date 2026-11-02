/* FUN_00498130 @ 00498130 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00498130(int *param_1,byte *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 == (int *)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4baf3c,0x38,0,(byte *)"str != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  if ((param_2 == (byte *)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4baf3c,0x39,0,(byte *)"format != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  iVar2 = FUN_0049f740(param_1);
  iVar3 = FUN_0049dba0(param_1,param_2,(undefined4 *)&stack0x0000000c);
  FUN_0049f8a0(iVar2,param_1);
  return iVar3;
}

