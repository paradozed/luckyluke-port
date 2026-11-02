/* FUN_004ab740 @ 004ab740 */
/* decompiled from Lucky.exe (Game.run) */


float10 __cdecl FUN_004ab740(int param_1,undefined4 param_2,undefined4 param_3)

{
  float10 fVar1;
  
  if (DAT_004c7bc0 == 0) {
    fVar1 = __umatherr(1,param_1,param_2,param_3,0,0,param_2,param_3);
  }
  else {
    DAT_004e8c64 = 0x21;
    FUN_004ac3e0();
    fVar1 = (float10)(double)CONCAT44(param_3,param_2);
  }
  return fVar1;
}

