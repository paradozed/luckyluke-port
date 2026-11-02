/* FUN_0042ab60 @ 0042ab60 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042ab60(HWND param_1,int param_2,uint param_3)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_54 [16];
  int local_14;
  undefined2 local_10;
  undefined2 uStack_e;
  short local_c;
  undefined2 uStack_a;
  HWND local_8;
  
  puVar3 = local_54;
  for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_14 = param_2;
  if (param_2 == 0x10) {
    EndDialog(param_1,0);
    __chkesp();
  }
  else if (param_2 == 0x110) {
    SetWindowTextA(param_1,DAT_004f5d8c);
    __chkesp();
    FUN_00428f70();
    GetDlgItem(param_1,0x402);
    local_8 = (HWND)__chkesp();
    SendMessageA(local_8,0x14a,0xffffffff,0x4b4dfc);
    __chkesp();
    SendMessageA(local_8,0x14a,0xffffffff,0x4b5174);
    __chkesp();
    SendMessageA(local_8,0x14a,0xffffffff,0x4b516c);
    __chkesp();
    SendMessageA(local_8,0x14a,0xffffffff,0x4b5164);
    __chkesp();
    SendMessageA(local_8,0x14a,0xffffffff,0x4b515c);
    __chkesp();
    SendMessageA(local_8,0x14a,0xffffffff,0x4b5154);
    __chkesp();
    SendMessageA(local_8,0x14a,0xffffffff,0x4b5148);
    __chkesp();
    SendMessageA(local_8,0x14e,_DAT_004e85ac,0);
    __chkesp();
  }
  else if (param_2 == 0x111) {
    sVar1 = (short)(param_3 >> 0x10);
    _local_c = CONCAT22(uStack_a,sVar1);
    if (sVar1 == 0) {
      _local_10 = CONCAT22(uStack_e,(undefined2)param_3);
      if ((param_3 & 0xffff) == 1) {
        SendDlgItemMessageA(param_1,0x402,0x147,0,0);
        _DAT_004e85ac = __chkesp();
        FUN_00432fe0(_DAT_004e85ac);
        FUN_00428f70();
        EndDialog(param_1,1);
        __chkesp();
      }
    }
  }
  local_8 = (HWND)0x42ad8c;
  __chkesp();
  return;
}

