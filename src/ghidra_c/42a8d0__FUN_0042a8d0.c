/* FUN_0042a8d0 @ 0042a8d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042a8d0(HWND param_1,uint param_2,uint param_3)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_a0 [16];
  uint local_60;
  uint local_5c;
  uint local_58;
  HDC local_54;
  tagPAINTSTRUCT local_50;
  undefined2 local_10;
  undefined2 uStack_e;
  uint local_c;
  undefined4 uStack_8;
  
  puVar3 = local_a0;
  for (iVar2 = 0x27; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_58 = param_2;
  if (param_2 < 0x111) {
    if (param_2 == 0x110) {
      FUN_00428130(param_1);
      FUN_0042a210(param_1);
      FUN_0042a510((BITMAPINFO *)&DAT_004f7760,&DAT_004f79c8,0x42,0x3f,0x10);
      _memset(DAT_004f79c8,0xff,0x207c);
      FUN_0042a6d0(param_1);
    }
    else if (param_2 == 0xf) {
      BeginPaint(param_1,&local_50);
      __chkesp();
      GetDC(param_1);
      local_54 = (HDC)__chkesp();
      FUN_0042a610(0x4f7760,local_54,0xe2,0x32);
      ReleaseDC(param_1,local_54);
      __chkesp();
      EndPaint(param_1,&local_50);
      __chkesp();
    }
    else if (param_2 == 0x10) {
      FUN_0042a0e0();
      EndDialog(param_1,0);
      __chkesp();
    }
  }
  else if (param_2 == 0x111) {
    sVar1 = (short)(param_3 >> 0x10);
    local_c = CONCAT22(local_c._2_2_,sVar1);
    if (sVar1 == 0) {
      _local_10 = CONCAT22(uStack_e,(undefined2)param_3);
      local_5c = param_3 & 0xffff;
      if (local_5c < 0x405) {
        if (local_5c == 0x404) {
          FUN_0042a370(param_1,0);
          FUN_0042a6d0(param_1);
        }
        else if (local_5c == 1) {
          SendMessageA(param_1,0x10,0,0);
          __chkesp();
        }
        else if ((0x3e9 < local_5c) && (local_5c < 0x3ed)) {
          FUN_0042a350();
          FUN_0042a6d0(param_1);
        }
      }
      else if (local_5c == 0x405) {
        FUN_0042a370(param_1,1);
        FUN_0042a6d0(param_1);
      }
    }
    if ((local_c & 0xffff) == 1) {
      _local_10 = CONCAT22(uStack_e,(undefined2)param_3);
      local_60 = param_3 & 0xffff;
      if (local_60 == 0x3ed) {
        FUN_0042a210(param_1);
        FUN_0042a6d0(param_1);
      }
    }
  }
  uStack_8 = 0x42ab53;
  __chkesp();
  return;
}

