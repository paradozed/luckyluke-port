/* FUN_004ae6a7 @ 004ae6a7 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004ae6a7(void)

{
  void *pvVar1;
  HWND pHVar2;
  DWORD dwStyle;
  DWORD DVar3;
  HMENU pHVar4;
  undefined4 uVar5;
  HWND pHVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  UINT UVar10;
  int iVar11;
  undefined4 uVar12;
  int local_4f0;
  int local_4ec;
  undefined1 local_4e4 [1024];
  int local_e4;
  HDC local_e0;
  uint local_dc;
  int *local_d8;
  uint local_d4;
  int local_d0;
  int local_cc;
  char local_c8;
  int local_c4;
  int local_b4;
  undefined4 local_ac [5];
  int local_98;
  void *local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_70;
  undefined4 local_1c;
  tagRECT local_18;
  void *local_8;
  
  FUN_004b1045((uint)DAT_004c7fb8,&local_d4);
  DAT_0050a2d4 = local_c8;
  DAT_0050a2d8 = local_cc;
  FUN_004b08b6(0,0,local_d4,local_d0);
  FUN_004b1d30();
  iVar11 = -0x10;
  pHVar2 = (HWND)FUN_004b1b20();
  dwStyle = GetWindowLongA(pHVar2,iVar11);
  if ((DAT_0050a2d4 == '\0') || (local_b4 != 0)) {
    if (local_b4 == 0) {
      local_e0 = GetDC((HWND)0x0);
      iVar11 = GetDeviceCaps(local_e0,0xe);
      iVar7 = GetDeviceCaps(local_e0,0xc);
      DAT_0050a2d8 = iVar11 * iVar7;
      ReleaseDC((HWND)0x0,local_e0);
      if (DAT_0050a2d8 == 8) {
        local_4ec = 0;
      }
      else {
        if (DAT_0050a2d8 == 0x10) {
          local_4f0 = 1;
        }
        else {
          local_4f0 = (DAT_0050a2d8 != 0x18) + 2;
        }
        local_4ec = local_4f0;
      }
      DAT_004c7fb8 = (void *)((uint)(local_c4 != 0) << 0x19 | local_4ec << 0x16 | local_d0 << 0xb |
                             local_d4);
    }
    iVar11 = -0x10;
    DVar3 = dwStyle;
    pHVar2 = (HWND)FUN_004b1b20();
    SetWindowLongA(pHVar2,iVar11,DVar3);
    SetRect(&local_18,0,0,local_d4,local_d0);
    iVar11 = -0x14;
    pHVar2 = (HWND)FUN_004b1b20();
    DVar3 = GetWindowLongA(pHVar2,iVar11);
    pHVar2 = (HWND)FUN_004b1b20();
    pHVar4 = GetMenu(pHVar2);
    AdjustWindowRectEx(&local_18,dwStyle,(uint)(pHVar4 != (HMENU)0x0),DVar3);
    UVar10 = 0;
    iVar11 = local_18.bottom - local_18.top;
    iVar7 = local_18.right - local_18.left;
    iVar9 = 0;
    iVar8 = 0;
    pHVar6 = (HWND)0x0;
    pHVar2 = (HWND)FUN_004b1b20();
    SetWindowPos(pHVar2,pHVar6,iVar8,iVar9,iVar7,iVar11,UVar10);
  }
  else {
    iVar11 = -0x10;
    pHVar2 = (HWND)FUN_004b1b20();
    SetWindowLongA(pHVar2,iVar11,dwStyle);
  }
  if (DAT_004e8ee0 == 0) {
    if (DAT_0050a2d0 != (int *)0x0) {
      (**(code **)(*DAT_0050a2d0 + 8))(DAT_0050a2d0);
      DAT_0050a2d0 = (int *)0x0;
    }
    local_e4 = DirectDrawCreate(DAT_004e8eec,&local_d8,0);
    if (local_e4 != 0) {
      FUN_004b0969((uint *)s_goInitScreen__DirectDrawCreate___004c802c,local_e4);
    }
    local_e4 = (**(code **)*local_d8)(local_d8,&DAT_004b8ee0,&DAT_0050a2d0);
    if (local_e4 != 0) {
      FUN_004b0969((uint *)s_goInitScreen__QueryInterface___004c8050,local_e4);
    }
    if (local_d8 != (int *)0x0) {
      (**(code **)(*local_d8 + 8))(local_d8);
    }
    if (DAT_004e8ee8 != (void *)0x0) {
      local_8c = DAT_004e8ee8;
      while (pvVar1 = local_8c, local_8c != (void *)0x0) {
        local_8 = local_8c;
        local_8c = *(void **)((int)local_8c + 0xc);
        FUN_00495280(pvVar1);
      }
      DAT_004e8ee8 = (void *)0x0;
    }
    (**(code **)(*DAT_0050a2d0 + 0x20))(DAT_0050a2d0,0,0,0,FUN_004ae610);
  }
  _memset(&local_84,0,0x6c);
  local_84 = 0x6c;
  if (DAT_0050a2d4 == '\0') {
    uVar12 = 8;
    uVar5 = FUN_004b1b20();
    local_e4 = (**(code **)(*DAT_0050a2d0 + 0x50))(DAT_0050a2d0,uVar5,uVar12);
    if (local_e4 != 0) {
      FUN_004b0969((uint *)s_goInitScreen___SetCooperativeLev_004c8108,local_e4);
    }
    _memset(&local_84,0,0x6c);
    local_84 = 0x6c;
    local_80 = 1;
    local_1c = 0x200;
    if (local_c4 != 0) {
      local_1c = 0x2200;
    }
    local_e4 = (**(code **)(*DAT_0050a2d0 + 0x18))(DAT_0050a2d0,&local_84,&DAT_004e8ec8,0);
    if (local_e4 != 0) {
      FUN_004b0969((uint *)s_goInitScreen___Create_surface___004c8130,local_e4);
    }
    DAT_004e8ecc = (int *)FUN_004b1510(DAT_004c7fb8,DAT_0050a2cc);
  }
  else {
    uVar12 = 0x15;
    uVar5 = FUN_004b1b20();
    local_e4 = (**(code **)(*DAT_0050a2d0 + 0x50))(DAT_0050a2d0,uVar5,uVar12);
    if (local_e4 != 0) {
      FUN_004b0969((uint *)s_goInitScreen___SetCooperativeLev_004c8070,local_e4);
    }
    local_e4 = (**(code **)(*DAT_0050a2d0 + 0x54))(DAT_0050a2d0,local_d4,local_d0,local_cc,0,0);
    if (local_e4 != 0) {
      FUN_004b0969((uint *)s_goInitScreen___Setdisplaymode___004c8098,local_e4);
    }
    _memset(&local_84,0,0x6c);
    local_84 = 0x6c;
    local_80 = 0x21;
    local_70 = 1;
    local_1c = 0x218;
    if (local_c4 != 0) {
      local_1c = 0x2218;
    }
    local_e4 = (**(code **)(*DAT_0050a2d0 + 0x18))(DAT_0050a2d0,&local_84,&DAT_004e8ec8,0);
    if (local_e4 != 0) {
      FUN_004b0969((uint *)s_goInitScreen___Create_surface___004c80bc,local_e4);
    }
    local_88 = 4;
    if (local_c4 != 0) {
      local_88 = 0x2004;
    }
    local_e4 = (**(code **)(*DAT_004e8ec8 + 0x30))(DAT_004e8ec8,&local_88,&DAT_004e8ecc);
    if (local_e4 != 0) {
      FUN_004b0969((uint *)s_goInitScreen___GetAttachedSurfac_004c80e0,local_e4);
    }
  }
  if ((DAT_0050a2d8 == 8) && (DAT_004e8ed8 == 0)) {
    for (local_dc = 0; (int)local_dc < 10; local_dc = local_dc + 1) {
      local_4e4[local_dc * 4 + 2] = (char)((ulonglong)((local_dc & 3) * 0xff) / 3);
      local_4e4[local_dc * 4 + 1] = (char)((ulonglong)(((int)local_dc >> 2 & 7U) * 0xff) / 7);
      local_4e4[local_dc * 4] = (char)((ulonglong)(((int)local_dc >> 5 & 7U) * 0xff) / 7);
      local_4e4[local_dc * 4 + 3] = 0;
    }
    for (local_dc = 10; (int)local_dc < 0xf6; local_dc = local_dc + 1) {
      local_4e4[local_dc * 4 + 2] = (char)((ulonglong)((local_dc & 3) * 0xff) / 3);
      local_4e4[local_dc * 4 + 1] = (char)((ulonglong)(((int)local_dc >> 2 & 7U) * 0xff) / 7);
      local_4e4[local_dc * 4] = (char)((ulonglong)(((int)local_dc >> 5 & 7U) * 0xff) / 7);
      local_4e4[local_dc * 4 + 3] = 1;
    }
    for (local_dc = 0xf6; (int)local_dc < 0x100; local_dc = local_dc + 1) {
      local_4e4[local_dc * 4 + 2] = (char)((ulonglong)((local_dc & 3) * 0xff) / 3);
      local_4e4[local_dc * 4 + 1] = (char)((ulonglong)(((int)local_dc >> 2 & 7U) * 0xff) / 7);
      local_4e4[local_dc * 4] = (char)((ulonglong)(((int)local_dc >> 5 & 7U) * 0xff) / 7);
      local_4e4[local_dc * 4 + 3] = 0;
    }
    local_e4 = (**(code **)(*DAT_0050a2d0 + 0x14))(DAT_0050a2d0,0x44,local_4e4,&DAT_004e8ed8,0);
    if (local_e4 != 0) {
      FUN_004b0969((uint *)s_goInitScreen___Create_Palette___004c8154,local_e4);
    }
    local_e4 = (**(code **)(*DAT_004e8ec8 + 0x7c))(DAT_004e8ec8,DAT_004e8ed8);
    if (local_e4 != 0) {
      FUN_004b0969((uint *)s_goInitScreen___SetPalette1___004c8178,local_e4);
    }
    local_e4 = (**(code **)(*DAT_004e8ecc + 0x7c))(DAT_004e8ecc,DAT_004e8ed8);
    if (local_e4 != 0) {
      FUN_004b0969((uint *)s_goInitScreen___SetPalette2___004c8198,local_e4);
    }
  }
  if (DAT_0050a2d8 == 0x10) {
    local_ac[0] = 0x20;
    local_e4 = (**(code **)(*DAT_004e8ec8 + 0x54))(DAT_004e8ec8,local_ac);
    if (local_e4 != 0) {
      FUN_004b0969((uint *)s_goInitScreen___GetPixelFormat___004c81b8,local_e4);
    }
    DAT_004c7fbc = local_98 == 0x7e0;
  }
  local_e4 = (**(code **)(*DAT_0050a2d0 + 0x10))(DAT_0050a2d0,0,&DAT_004e8edc,0);
  if (local_e4 != 0) {
    FUN_004b0969((uint *)s_goInitScreen___createClipper___004c81dc,local_e4);
  }
  uVar5 = FUN_004b1b20();
  local_e4 = (**(code **)(*DAT_004e8edc + 0x20))(DAT_004e8edc,0,uVar5);
  if (local_e4 != 0) {
    FUN_004b0969((uint *)s_goInitScreen___clipperSetHwnd___004c81fc,local_e4);
  }
  local_e4 = (**(code **)(*DAT_004e8ec8 + 0x70))(DAT_004e8ec8,DAT_004e8edc);
  if (local_e4 != 0) {
    FUN_004b0969((uint *)s_goInitScreen___SetClipper___004c8220,local_e4);
  }
  if ((int)local_d4 < 400) {
    _DAT_004e8ee4 = &DAT_004cea00;
  }
  else {
    _DAT_004e8ee4 = &DAT_004c8d60;
  }
  FUN_004af0d3(0x48,1,FUN_004af09d);
  FUN_004b015a();
  FUN_004af09d();
  DAT_004e8ee0 = 2;
  if (local_b4 != 0) {
    UVar10 = 0;
    iVar9 = 100;
    iVar8 = 100;
    iVar7 = 0;
    iVar11 = 0;
    pHVar6 = (HWND)0x0;
    pHVar2 = (HWND)FUN_004b1b20();
    SetWindowPos(pHVar2,pHVar6,iVar11,iVar7,iVar8,iVar9,UVar10);
  }
  pHVar2 = (HWND)FUN_004b1b20();
  SetForegroundWindow(pHVar2);
  return 1;
}

