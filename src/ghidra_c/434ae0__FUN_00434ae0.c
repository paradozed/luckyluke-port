/* FUN_00434ae0 @ 00434ae0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00434ae0(HWND param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  uint local_10;
  int local_c;
  LPARAM local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = param_2;
  if (param_2 == 0x10) {
    EndDialog(param_1,0);
    __chkesp();
  }
  else if (param_2 == 0x110) {
    LoadImageA(DAT_004f5b74,(LPCSTR)0x6f,0,0x32,0x32,0);
    local_8 = __chkesp();
    SendDlgItemMessageA(param_1,0x3eb,0xf7,0,local_8);
    __chkesp();
    LoadImageA(DAT_004f5b74,(LPCSTR)0x6e,0,0x32,0x32,0);
    local_8 = __chkesp();
    SendDlgItemMessageA(param_1,0x3ec,0xf7,0,local_8);
    __chkesp();
    LoadImageA(DAT_004f5b74,(LPCSTR)0x70,0,0x32,0x16,0);
    local_8 = __chkesp();
    SendDlgItemMessageA(param_1,0x3ed,0xf7,0,local_8);
    __chkesp();
    SetWindowTextA(param_1,DAT_004f5da8);
    __chkesp();
    SetDlgItemTextA(param_1,2,DAT_004f5dac);
    __chkesp();
  }
  else if (param_2 == 0x111) {
    local_10 = param_3 & 0xffff;
    if (local_10 < 0x3ed) {
      if (local_10 == 0x3ec) {
        FUN_00434630(param_1);
        EndDialog(param_1,0);
        __chkesp();
      }
      else if (local_10 == 2) {
        PostMessageA(param_1,0x10,0,0);
        __chkesp();
      }
      else if (local_10 == 0x3eb) {
        FUN_00434420(param_1);
        EndDialog(param_1,0);
        __chkesp();
      }
    }
    else if (local_10 == 0x3ed) {
      FUN_00434760(param_1);
      EndDialog(param_1,0);
      __chkesp();
    }
  }
  local_8 = 0x434d24;
  __chkesp();
  return;
}

