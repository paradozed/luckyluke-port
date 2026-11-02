/* FUN_004b03de @ 004b03de */
/* decompiled from Lucky.exe (Game.run) */


undefined4 __fastcall FUN_004b03de(int *param_1,LPCSTR param_2)

{
  bool bVar1;
  HGLOBAL hResData;
  undefined3 extraout_var;
  int iVar2;
  HMODULE hInst;
  BOOL BVar3;
  UINT type;
  int cy;
  UINT fuLoad;
  uint local_4b0;
  undefined4 local_4ac;
  undefined4 local_4a8;
  int local_4a4;
  int local_4a0;
  int local_440;
  HANDLE local_43c;
  uint local_438;
  HRSRC local_434;
  undefined1 local_430 [1024];
  HDC local_30;
  undefined1 local_2c [4];
  int local_28;
  int local_24;
  undefined4 local_14;
  uint *local_10;
  HDC local_c;
  int local_8;
  
  for (local_438 = 0; (int)local_438 < 0x100; local_438 = local_438 + 1) {
    local_430[local_438 * 4] = (char)(((local_438 >> 5 & 7) * 0xff) / 7);
    local_430[local_438 * 4 + 1] = (char)(((local_438 >> 2 & 7) * 0xff) / 7);
    local_430[local_438 * 4 + 2] = (char)(((local_438 & 3) * 0xff) / 3);
    local_430[local_438 * 4 + 3] = 0;
  }
  if ((param_2 == (LPCSTR)0x0) ||
     (local_434 = FindResourceA((HMODULE)0x0,param_2,(LPCSTR)0x2), local_434 == (HRSRC)0x0)) {
    OutputDebugStringA(s_resource_not_found_004c86ac);
  }
  else {
    hResData = LoadResource((HMODULE)0x0,local_434);
    local_10 = LockResource(hResData);
    if (local_10 == (uint *)0x0) {
      OutputDebugStringA(s_lock_resource_failed_004c8694);
    }
    else {
      local_8 = *local_10 + (int)local_10;
      if ((local_10 == (uint *)0x0) || (*local_10 < 0x28)) {
        local_4b0 = 0;
      }
      else if (*(ushort *)((int)local_10 + 0xe) < 9) {
        if (local_10[8] == 0) {
          local_4b0 = 1 << (*(byte *)((int)local_10 + 0xe) & 0x1f);
        }
        else {
          local_4b0 = local_10[8];
        }
      }
      else {
        local_4b0 = 0;
      }
      for (local_438 = 0; (int)local_438 < (int)local_4b0; local_438 = local_438 + 1) {
        local_430[local_438 * 4] = *(undefined1 *)(local_8 + 2 + local_438 * 4);
        local_430[local_438 * 4 + 1] = *(undefined1 *)(local_8 + 1 + local_438 * 4);
        local_430[local_438 * 4 + 2] = *(undefined1 *)(local_8 + local_438 * 4);
        local_430[local_438 * 4 + 3] = 0;
      }
    }
  }
  local_440 = (**(code **)(*DAT_0050a2d0 + 0x14))(DAT_0050a2d0,4,local_430,&local_14,0);
  if (local_440 != 0) {
    FUN_004b0969((uint *)s_goW95LoadBitmap___IDirectDraw2_C_004c86c4,local_440);
  }
  bVar1 = FUN_004b1870(DAT_004e8ed0,local_14);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    do {
      iVar2 = FUN_004ae250(s_goSetScreenClut_goVarScreenShow__004c8724,0x4c86f4,0x125);
    } while (iVar2 != 0);
  }
  fuLoad = 0x2000;
  cy = 0;
  iVar2 = 0;
  type = 0;
  hInst = GetModuleHandleA((LPCSTR)0x0);
  local_43c = LoadImageA(hInst,param_2,type,iVar2,cy,fuLoad);
  if (local_43c == (HANDLE)0x0) {
    local_14 = 0;
  }
  else {
    local_440 = (**(code **)(*param_1 + 0x6c))(param_1);
    if (local_440 != 0) {
      FUN_004b0969((uint *)s_goW95LoadBitmap___IDirectDrawSur_004c874c,local_440);
    }
    local_c = CreateCompatibleDC((HDC)0x0);
    if (local_c == (HDC)0x0) {
      OutputDebugStringA(s_goW95LoadBitmap___createcompatib_004c885c);
    }
    else {
      SelectObject(local_c,local_43c);
      GetObjectA(local_43c,0x18,local_2c);
      local_4ac = 0x6c;
      local_4a8 = 6;
      local_440 = (**(code **)(*param_1 + 0x58))(param_1,&local_4ac);
      if (local_440 != 0) {
        FUN_004b0969((uint *)s_goW95LoadBitmap___IDirectDrawSur_004c877c,local_440);
      }
      local_440 = (**(code **)(*param_1 + 0x44))(param_1,&local_30);
      if (local_440 != 0) {
        FUN_004b0969((uint *)s_goW95LoadBitmap___IDirectDrawSur_004c87b4,local_440);
      }
      StretchBlt(local_30,0,0,local_4a0,local_4a4,local_c,0,0,local_28,local_24,0xcc0020);
      local_440 = (**(code **)(*param_1 + 0x68))(param_1,local_30);
      if (local_440 != 0) {
        FUN_004b0969((uint *)s_goW95LoadBitmap___IDirectDrawSur_004c87e4,local_440);
      }
      BVar3 = DeleteDC(local_c);
      if (BVar3 == 0) {
        do {
          iVar2 = FUN_004ae250(s_DeleteDC_hdcImage__004c8848,0x4c8818,0x14d);
        } while (iVar2 != 0);
      }
    }
    DeleteObject(local_43c);
  }
  return local_14;
}

