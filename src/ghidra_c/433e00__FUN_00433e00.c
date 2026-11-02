/* FUN_00433e00 @ 00433e00 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00433e00(HWND param_1,int param_2,uint param_3)

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
    FUN_00433c90(param_1);
  }
  else if (param_2 == 0x111) {
    local_c = param_3 & 0xffff;
    if (local_c == 1) {
      SendDlgItemMessageA(param_1,0x413,0x147,0,0);
      DAT_004bc760 = __chkesp();
      _DAT_004e85ac = DAT_004bc760;
      FUN_00432fe0(DAT_004bc760);
      PostMessageA(param_1,0x10,0,0);
      __chkesp();
    }
    if (param_3 >> 0x10 == 1) {
      SendDlgItemMessageA(param_1,0x413,0x147,0,0);
      DAT_004bc760 = __chkesp();
      SetWindowTextA(param_1,DAT_004f5d8c);
      __chkesp();
    }
  }
  local_8 = 0x433f43;
  __chkesp();
  return;
}

