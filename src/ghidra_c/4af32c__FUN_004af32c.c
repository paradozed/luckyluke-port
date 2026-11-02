/* FUN_004af32c @ 004af32c */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __fastcall FUN_004af32c(int param_1,int *param_2)

{
  uint extraout_EDX;
  longlong lVar1;
  tagRECT local_40;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  tagRECT local_1c;
  int local_c;
  int local_8;
  
  local_c = param_1;
  SetRect(&local_1c,*(int *)(param_1 + 0xc),*(int *)(param_1 + 0x10),
          *(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc),
          *(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x10));
  lVar1 = FUN_004b1678(&local_1c.left,extraout_EDX);
  local_28 = (int)lVar1;
  if (local_28 != 0) {
    local_24 = local_1c.left - *(int *)(local_c + 0xc);
    local_30 = local_1c.top - *(int *)(local_c + 0x10);
    local_8 = local_1c.bottom - *(int *)(local_c + 0x10);
    local_2c = local_1c.right - *(int *)(local_c + 0xc);
    SetRect(&local_40,local_24,local_30,local_2c,local_8);
    local_20 = (**(code **)(*param_2 + 0x1c))
                         (param_2,local_1c.left,local_1c.top,*(undefined4 *)(local_c + 0x1c),
                          &local_40,0x11);
    if (local_20 != 0) {
      FUN_004b0969((uint *)s_goW95PrimBlit___IDirectDrawSurfa_004c8368,local_20);
    }
  }
  return 0x24;
}

