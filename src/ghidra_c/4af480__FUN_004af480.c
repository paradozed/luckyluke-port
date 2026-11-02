/* FUN_004af480 @ 004af480 */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __fastcall FUN_004af480(int param_1,int *param_2)

{
  uint extraout_EDX;
  longlong lVar1;
  undefined4 local_84 [20];
  undefined4 local_34;
  int local_20;
  int local_1c;
  tagRECT local_18;
  int local_8;
  
  local_84[0] = 100;
  local_34 = *(undefined4 *)(param_1 + 0x1c);
  local_8 = param_1;
  SetRect(&local_18,*(int *)(param_1 + 0xc),*(int *)(param_1 + 0x10),
          *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc),
          *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x10));
  lVar1 = FUN_004b1678(&local_18.left,extraout_EDX);
  local_20 = (int)lVar1;
  if (local_20 != 0) {
    local_1c = (**(code **)(*param_2 + 0x14))(param_2,&local_18,0,0,0x1000400,local_84);
    if (local_1c != 0) {
      FUN_004b0969((uint *)s_goW95PrimDrawRect___IDirectDrawS_004c8398,local_1c);
    }
  }
  return 0x20;
}

