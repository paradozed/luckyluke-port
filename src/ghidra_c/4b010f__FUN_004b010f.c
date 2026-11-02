/* FUN_004b010f @ 004b010f */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __fastcall FUN_004b010f(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(&DAT_0050a300 + param_1 * 4);
  *(undefined4 *)(&DAT_0050a300 + param_1 * 4) = param_2;
  return uVar1;
}

