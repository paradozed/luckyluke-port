/* FUN_004998a0 @ 004998a0 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __cdecl FUN_004998a0(int param_1,uint param_2)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (2 < param_1)) {
    uVar1 = 0xffffffff;
  }
  else if (param_2 == 0xffffffff) {
    uVar1 = *(undefined4 *)(&DAT_004c6fac + param_1 * 4);
  }
  else if ((param_2 & 0xfffffff8) == 0) {
    uVar1 = *(undefined4 *)(&DAT_004c6fac + param_1 * 4);
    *(uint *)(&DAT_004c6fac + param_1 * 4) = param_2;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

