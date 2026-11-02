/* FUN_004ae460 @ 004ae460 */
/* decompiled from Lucky.exe (Game.run) */


uint __fastcall FUN_004ae460(int param_1,int *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  HWND pHVar3;
  tagRECT *lpRect;
  tagPOINT *lpPoint;
  tagRECT local_4c;
  int local_3c;
  tagPOINT local_38;
  uint local_30;
  int local_2c;
  uint local_8;
  
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_2 == DAT_004e8ec8) {
    if (DAT_0050a2d4 == '\0') {
      lpRect = &local_4c;
      pHVar3 = (HWND)FUN_004b1b20();
      GetClientRect(pHVar3,lpRect);
      local_38.y = 0;
      local_38.x = 0;
      lpPoint = &local_38;
      pHVar3 = (HWND)FUN_004b1b20();
      ClientToScreen(pHVar3,lpPoint);
      OffsetRect(&local_4c,local_38.x,local_38.y);
      local_3c = (**(code **)(*param_2 + 0x14))(param_2,&local_4c,param_1,0,0,0);
      if (local_3c != 0) {
        FUN_004b0969((uint *)s_goShowScreen___IDirectDrawSurfac_004c7f8c,local_3c);
      }
    }
    else if (param_1 == DAT_004e8ecc) {
      local_3c = (**(code **)(*param_2 + 0x2c))(param_2,0,0);
    }
    else {
      FUN_004b1045(DAT_004c7fb8,&local_30);
      if (((local_30 == 0x140) || (local_2c == 200)) || (local_2c == 0xf0)) {
        local_8 = local_8 & 0xffffff00;
      }
      else {
        SetRect(&local_4c,0,0,local_30,local_2c);
        bVar1 = FUN_004b0370(param_1,param_2);
        if (CONCAT31(extraout_var,bVar1) == 0) {
          do {
            iVar2 = FUN_004ae250(s_goW95CopyScreen_src_DestRect_dst_004c7f60,0x4c7f30,0x27);
          } while (iVar2 != 0);
        }
      }
    }
  }
  else {
    local_8 = (uint)local_8._1_3_ << 8;
  }
  (*DAT_0050a848)(param_1);
  return local_8 & 0xff;
}

