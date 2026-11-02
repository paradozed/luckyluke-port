/* FUN_0042ada0 @ 0042ada0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Removing unreachable block (ram,0x0042b132) */
/* WARNING: Removing unreachable block (ram,0x0042b0ae) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042ada0(HWND param_1,int param_2,uint param_3)

{
  short sVar1;
  char cVar2;
  HINSTANCE pHVar3;
  HWND pHVar4;
  int iVar5;
  undefined4 *puVar6;
  LPCSTR pCVar7;
  UINT UVar8;
  code *pcVar9;
  WPARAM WVar10;
  LPARAM LVar11;
  undefined4 local_54 [16];
  uint local_14;
  int local_10;
  undefined2 local_c;
  undefined2 uStack_a;
  uint local_8;
  
  puVar6 = local_54;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  local_10 = param_2;
  if (param_2 == 0x10) {
    EndDialog(param_1,0);
    __chkesp();
  }
  else if (param_2 == 0x110) {
    iVar5 = 5;
    GetDlgItem(param_1,0x3eb);
    pHVar4 = (HWND)__chkesp();
    ShowWindow(pHVar4,iVar5);
    __chkesp();
    iVar5 = 0;
    GetDlgItem(param_1,0x401);
    pHVar4 = (HWND)__chkesp();
    ShowWindow(pHVar4,iVar5);
    __chkesp();
    iVar5 = 0;
    GetDlgItem(param_1,0x3ec);
    pHVar4 = (HWND)__chkesp();
    ShowWindow(pHVar4,iVar5);
    __chkesp();
    DAT_004e82fc = param_1;
    FUN_00458ec0();
    FUN_00427ff0();
    FUN_00428130(param_1);
    FUN_00428420();
    FUN_004284e0();
    FUN_004289e0();
    FUN_00428b30();
    FUN_00428030();
    FUN_00458ec0();
    FUN_004292d0();
    FUN_00429c40();
    FUN_00458ec0();
    FUN_00458ec0();
    FUN_00428f70();
  }
  else if (param_2 == 0x111) {
    sVar1 = (short)(param_3 >> 0x10);
    local_8 = CONCAT22(local_8._2_2_,sVar1);
    if (sVar1 == 0) {
      _local_c = CONCAT22(uStack_a,(undefined2)param_3);
      local_14 = param_3 & 0xffff;
      if (local_14 < 0x3ef) {
        if (local_14 == 0x3ee) {
          IsDlgButtonChecked(param_1,0x3ee);
          iVar5 = __chkesp();
          if (iVar5 != 0) {
            CheckDlgButton(DAT_004e82fc,0x3f4,0);
            __chkesp();
          }
        }
        else if (local_14 < 0x3ec) {
          if (local_14 == 0x3eb) {
            if (DAT_004e8308 == 0) {
              FUN_00428010();
            }
            else {
              FUN_00427ff0();
            }
          }
          else if (local_14 == 1) {
            cVar2 = FUN_00429bb0();
            if (cVar2 == '\0') {
              EndDialog(param_1,0);
              __chkesp();
            }
            else {
              FUN_004299c0();
              FUN_00429a60();
              EndDialog(param_1,1);
              __chkesp();
            }
          }
          else if (local_14 == 2) {
            EndDialog(param_1,0);
            __chkesp();
          }
        }
        else if (local_14 == 0x3ec) {
          LVar11 = 0;
          pcVar9 = FUN_0042ab60;
          pCVar7 = (LPCSTR)0x68;
          pHVar4 = param_1;
          pHVar3 = (HINSTANCE)FUN_00445840();
          DialogBoxParamA(pHVar3,pCVar7,pHVar4,pcVar9,LVar11);
          __chkesp();
          LVar11 = 0;
          WVar10 = 0;
          UVar8 = 0x14b;
          GetDlgItem(param_1,0x3e9);
          pHVar4 = (HWND)__chkesp();
          SendMessageA(pHVar4,UVar8,WVar10,LVar11);
          __chkesp();
          FUN_004279c0(FUN_00427bc0);
          FUN_00428030();
          FUN_004292d0();
        }
      }
      else if (local_14 == 0x3f4) {
        IsDlgButtonChecked(param_1,0x3f4);
        iVar5 = __chkesp();
        if (iVar5 == 0) {
          DAT_004e859c = 0;
        }
        else {
          DAT_004e859c = 1;
          CheckDlgButton(DAT_004e82fc,0x3ee,0);
          __chkesp();
        }
        FUN_00429730();
        FUN_00428130(param_1);
        FUN_004298d0();
      }
      else if (local_14 == 0x401) {
        FUN_00429db0();
      }
      else if (local_14 == 0x407) {
        LVar11 = 0;
        pcVar9 = FUN_0042a8d0;
        pCVar7 = (LPCSTR)0x69;
        pHVar4 = param_1;
        pHVar3 = (HINSTANCE)FUN_00445840();
        DialogBoxParamA(pHVar3,pCVar7,pHVar4,pcVar9,LVar11);
        __chkesp();
      }
    }
    if ((local_8 & 0xffff) == 1) {
      if ((param_3 & 0xffff) == 0x3f8) {
        SendDlgItemMessageA(DAT_004e82fc,0x3f8,0x147,0,0);
        _DAT_004e85ac = __chkesp();
        FUN_00428f70();
        LVar11 = 0;
        WVar10 = 0;
        UVar8 = 0x14b;
        GetDlgItem(param_1,0x3e9);
        pHVar4 = (HWND)__chkesp();
        SendMessageA(pHVar4,UVar8,WVar10,LVar11);
        __chkesp();
        FUN_004279c0(FUN_00427bc0);
        FUN_00428030();
        FUN_004292d0();
      }
      FUN_00429c40();
    }
  }
  local_8 = 0x42b25c;
  __chkesp();
  return;
}

