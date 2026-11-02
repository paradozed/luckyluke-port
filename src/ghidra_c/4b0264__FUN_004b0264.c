/* FUN_004b0264 @ 004b0264 */
/* decompiled from Lucky.exe (Game.run) */


bool __fastcall FUN_004b0264(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_70 [2];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_4c;
  undefined4 local_1c;
  
  local_70[0] = 0x6c;
  iVar1 = (**(code **)(*param_1 + 100))(param_1,0,local_70,0x801,0);
  if (iVar1 != 0) {
    FUN_004b0969((uint *)s_goW95LockScreen___IDirectDrawSur_004c8608,iVar1);
  }
  param_2[1] = local_64;
  *param_2 = local_68;
  param_2[2] = local_60;
  param_2[3] = local_1c;
  param_2[4] = local_4c;
  return iVar1 == 0;
}

