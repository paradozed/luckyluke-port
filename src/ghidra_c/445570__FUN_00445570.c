/* FUN_00445570 @ 00445570 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00445570(HWND param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  UINT local_c;
  int local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e85f8 != (code *)0x0) {
    (*DAT_004e85f8)(param_1,param_2,param_3,param_4);
    local_8 = __chkesp();
    if (local_8 != 0) goto LAB_00445617;
  }
  local_c = param_2;
  if (param_2 != 1) {
    if (param_2 == 0x10) {
      PostQuitMessage(0);
      __chkesp();
    }
    else if (param_2 != 0x111) {
      DefWindowProcA(param_1,param_2,param_3,param_4);
      __chkesp();
    }
  }
LAB_00445617:
  local_8 = 0x445624;
  __chkesp();
  return;
}

