/* FUN_004b18d0 @ 004b18d0 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_004b18d0(int param_1)

{
  uint extraout_EDX;
  longlong lVar1;
  tagRECT local_50;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  tagRECT local_1c;
  ushort *local_c;
  int local_8;
  
  local_40 = 0;
  local_3c = 0;
  local_c = (ushort *)((uint)*(byte *)(param_1 + 2) * 0x10 + *(int *)(param_1 + 0xc));
  local_20 = (int)*(short *)(param_1 + 4) - (uint)*local_c;
  local_24 = (((int)*(short *)(param_1 + 6) - (uint)local_c[1]) - *(int *)(local_c + 4)) + 1;
  local_38 = param_1;
  SetRect(&local_1c,local_20,local_24,*(int *)(local_c + 2) + local_20,
          *(int *)(local_c + 4) + local_24);
  lVar1 = FUN_004b1678(&local_1c.left,extraout_EDX);
  local_30 = (int)lVar1;
  if (local_30 != 0) {
    local_2c = local_1c.left - local_20;
    local_8 = local_1c.bottom - local_24;
    local_34 = local_1c.right - local_20;
    SetRect(&local_50,local_2c,local_1c.top - local_24,local_34,local_8);
    if (DAT_0050a2d8 == 8) {
      local_28 = (**(code **)(**(int **)(local_38 + 8) + 0x1c))
                           (*(undefined4 *)(local_38 + 8),local_1c.left,local_1c.top,
                            *(undefined4 *)(local_c + 6),&local_50,0x11);
      if (local_28 != 0) {
        FUN_004b0969((uint *)s_iDrawSprite___IDirectDrawSurface_004d1c14,local_28);
      }
    }
    else if (DAT_0050a2d8 == 0x10) {
      FUN_004b11de(*(int **)(local_38 + 8),local_1c.left,local_1c.top,*(int **)(local_c + 6),
                   local_50.left,local_50.top,local_50.right,local_50.bottom,
                   *(int *)(local_38 + 0x10));
    }
  }
  return;
}

