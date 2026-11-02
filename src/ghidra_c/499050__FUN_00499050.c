/* FUN_00499050 @ 00499050 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00499050(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    iVar1 = FUN_00499180(0);
  }
  else {
    iVar1 = FUN_004990b0(param_1);
    if (iVar1 == 0) {
      if ((param_1[3] & 0x4000U) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = FUN_004a2660(param_1[4]);
        iVar1 = -(uint)(iVar1 != 0);
      }
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}

