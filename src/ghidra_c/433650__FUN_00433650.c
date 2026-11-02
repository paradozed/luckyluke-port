/* FUN_00433650 @ 00433650 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00433650(HWND param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  HGDIOBJ local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  SendDlgItemMessageA(param_1,0x415,0x173,0,0);
  local_8 = (HGDIOBJ)__chkesp();
  if (local_8 != (HGDIOBJ)0x0) {
    DeleteObject(local_8);
    __chkesp();
  }
  local_c = (uint)DAT_004f17ea;
  switch(local_c) {
  case 0:
    LoadImageA(DAT_004f5b74,(LPCSTR)0x79,0,0x183,0x7f,0);
    local_8 = (HGDIOBJ)__chkesp();
    break;
  case 1:
    LoadImageA(DAT_004f5b74,(LPCSTR)0x7a,0,0x183,0x7f,0);
    local_8 = (HGDIOBJ)__chkesp();
    break;
  case 2:
    LoadImageA(DAT_004f5b74,(LPCSTR)0x7b,0,0x183,0x7f,0);
    local_8 = (HGDIOBJ)__chkesp();
    break;
  case 3:
    LoadImageA(DAT_004f5b74,(LPCSTR)0x7c,0,0x183,0x7f,0);
    local_8 = (HGDIOBJ)__chkesp();
    break;
  case 4:
    LoadImageA(DAT_004f5b74,(LPCSTR)0x7d,0,0x183,0x7f,0);
    local_8 = (HGDIOBJ)__chkesp();
    break;
  case 5:
    LoadImageA(DAT_004f5b74,(LPCSTR)0x7e,0,0x183,0x7f,0);
    local_8 = (HGDIOBJ)__chkesp();
    break;
  case 6:
    LoadImageA(DAT_004f5b74,(LPCSTR)0x7f,0,0x183,0x7f,0);
    local_8 = (HGDIOBJ)__chkesp();
  }
  SendDlgItemMessageA(param_1,0x415,0x172,0,(LPARAM)local_8);
  __chkesp();
  SetDlgItemTextA(param_1,0x3eb,DAT_004f5d80);
  __chkesp();
  SetDlgItemTextA(param_1,0x40b,DAT_004f5d88);
  __chkesp();
  SetDlgItemTextA(param_1,0x40c,DAT_004f5d8c);
  __chkesp();
  SetDlgItemTextA(param_1,0x40d,DAT_004f5d90);
  __chkesp();
  SetDlgItemTextA(param_1,0x40a,DAT_004f5d94);
  __chkesp();
  SetDlgItemTextA(param_1,2,DAT_004f5d98);
  __chkesp();
  SetDlgItemTextA(param_1,0x414,DAT_004f5d9c);
  __chkesp();
  iVar1 = FUN_004334b0();
  if (iVar1 == 0) {
    SetDlgItemTextA(param_1,0x409,DAT_004f5d84);
    __chkesp();
  }
  else {
    SetDlgItemTextA(param_1,0x409,DAT_004f5da0);
    __chkesp();
  }
  SetWindowTextA(param_1,DAT_004f5da4);
  __chkesp();
  local_8 = (HGDIOBJ)0x433948;
  __chkesp();
  return;
}

