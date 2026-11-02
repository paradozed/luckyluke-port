/* FUN_0049f8a0 @ 0049f8a0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0049f8a0(int param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  
  if (((param_1 != 0) && (param_1 != 1)) &&
     (iVar2 = FUN_004999a0(2,0x4bb444,0xa1,0,(byte *)"flag == 0 || flag == 1"), iVar2 == 1)) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (param_1 == 0) {
    if ((param_2[3] & 0x1000U) != 0) {
      FUN_004990b0(param_2);
    }
  }
  else if ((param_2[3] & 0x1000U) != 0) {
    FUN_004990b0(param_2);
    param_2[3] = param_2[3] & 0xffffeeff;
    param_2[6] = 0;
    *param_2 = 0;
    param_2[2] = 0;
  }
  return;
}

