/* FUN_004a75c0 @ 004a75c0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_004a75c0(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  float10 fVar3;
  
  uVar1 = FUN_004acce0(param_1,param_2);
  if ((uVar1 & 0x90) == 0) {
    fVar3 = FUN_004ac750((double)CONCAT44(param_2,param_1));
    if ((double)fVar3 == (double)CONCAT44(param_2,param_1)) {
      fVar3 = FUN_004ac750((double)CONCAT44(param_2,param_1) / _DAT_004bb878);
      if ((float10)(double)CONCAT44(param_2,param_1) / (float10)_DAT_004bb878 == fVar3) {
        uVar2 = 2;
      }
      else {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

