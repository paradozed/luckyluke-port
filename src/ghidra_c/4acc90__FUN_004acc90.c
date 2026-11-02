/* FUN_004acc90 @ 004acc90 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004acc90(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((((param_2._2_2_ & 0x7ff8) == 0x7ff0) && (((param_2 & 0x7ffff) != 0 || (param_1 != 0)))) ||
     ((param_2._2_2_ & 0x7ff8) == 0x7ff8)) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

