/* FUN_004b1870 @ 004b1870 */
/* decompiled from Lucky.exe (Game.run) */


bool __fastcall FUN_004b1870(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x7c))(param_1,param_2);
  if (iVar1 != 0) {
    FUN_004b0969((uint *)s_goSetScreenClut___IDirectDrawSur_004d1be0,iVar1);
  }
  return iVar1 == 0;
}

