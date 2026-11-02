/* FUN_00434d30 @ 00434d30 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00434d30(HWND param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  uint local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_8 = param_2;
  if (param_2 == 0x10) {
    EndDialog(param_1,0);
    __chkesp();
  }
  else if (param_2 == 0x110) {
    FUN_00433500();
    FUN_00432fe0(DAT_004bc760);
    FUN_00433650(param_1);
    FUN_00434360(param_1);
    DAT_004f5b78 = param_1;
  }
  else if (param_2 == 0x111) {
    local_c = param_3 & 0xffff;
    if (local_c < 0x40e) {
      if (local_c == 0x40d) {
        FUN_00434860();
      }
      else if (local_c < 0x40b) {
        if (local_c == 0x40a) {
          FUN_004342c0();
        }
        else if (local_c == 2) {
          FUN_00433970();
          PostMessageA(param_1,0x10,0,0);
          __chkesp();
        }
        else if (local_c == 0x3eb) {
          iVar1 = FUN_004333c0(param_1);
          if (iVar1 != 0) {
            FUN_00433970();
            EndDialog(param_1,1);
            __chkesp();
          }
        }
        else if (local_c == 0x409) {
          MessageBoxA(param_1,DAT_004f5ddc,DAT_004f5de0,0);
          __chkesp();
          FUN_00433970();
          FUN_00433b90(param_1);
        }
      }
      else if (local_c == 0x40b) {
        DialogBoxParamA(DAT_004f5b74,(LPCSTR)0x73,param_1,FUN_00434ae0,0);
        __chkesp();
      }
      else if (local_c == 0x40c) {
        FUN_00433f50(param_1);
        FUN_00433650(param_1);
        FUN_00429a60();
      }
    }
    else {
      local_c = local_c - 0x40f;
      switch(local_c) {
      case 0:
        FUN_004349a0();
        break;
      case 1:
        FUN_004349f0();
        break;
      case 2:
        FUN_00434a40();
        break;
      case 3:
        FUN_00434a90();
        break;
      case 5:
        FUN_0042b3c0();
      }
    }
  }
  local_8 = 0x434f75;
  __chkesp();
  return;
}

