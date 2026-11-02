/* FUN_004ae418 @ 004ae418 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __fastcall FUN_004ae418(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(&DAT_0050a720 + param_1 * 4 + param_2 * 4);
  *(undefined4 *)(&DAT_0050a720 + param_1 * 4 + param_2 * 4) = param_3;
  return uVar1;
}

