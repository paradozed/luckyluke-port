/* FUN_004988b0 @ 004988b0 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_004988b0(uint *param_1,int param_2,DWORD param_3)

{
  code *pcVar1;
  int iVar2;
  DWORD DVar3;
  
  if ((param_1 == (uint *)0x0) &&
     (iVar2 = FUN_004999a0(2,0x4bafc8,0x92,0,(byte *)"str != NULL"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  if (((param_1[3] & 0x83) == 0) || (((param_3 != 0 && (param_3 != 1)) && (param_3 != 2)))) {
    DAT_004e8c64 = 0x16;
    iVar2 = -1;
  }
  else {
    param_1[3] = param_1[3] & 0xffffffef;
    if (param_3 == 1) {
      iVar2 = FUN_00498dc0(param_1);
      param_2 = param_2 + iVar2;
      param_3 = 0;
    }
    FUN_004990b0((int *)param_1);
    if ((param_1[3] & 0x80) == 0) {
      if ((((param_1[3] & 1) != 0) && ((param_1[3] & 8) != 0)) && ((param_1[3] & 0x400) == 0)) {
        param_1[6] = 0x200;
      }
    }
    else {
      param_1[3] = param_1[3] & 0xfffffffc;
    }
    DVar3 = FUN_004a1a60(param_1[4],param_2,param_3);
    iVar2 = (DVar3 != 0xffffffff) - 1;
  }
  return iVar2;
}

