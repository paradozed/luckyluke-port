/* FUN_0042a210 @ 0042a210 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0042a210(HWND param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  int local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  SendDlgItemMessageA(param_1,0x3ed,0x147,0,0);
  local_8 = __chkesp();
  if (local_8 != -1) {
    if ((*(uint *)(&DAT_004f79e0 + local_8 * 0x1c) & 1) == 0) {
      CheckDlgButton(param_1,0x3ea,0);
      __chkesp();
    }
    else {
      CheckDlgButton(param_1,0x3ea,1);
      __chkesp();
    }
    if ((*(uint *)(&DAT_004f79e0 + local_8 * 0x1c) & 2) == 0) {
      CheckDlgButton(param_1,0x3eb,0);
      __chkesp();
    }
    else {
      CheckDlgButton(param_1,0x3eb,1);
      __chkesp();
    }
    if ((*(uint *)(&DAT_004f79e0 + local_8 * 0x1c) & 4) == 0) {
      CheckDlgButton(param_1,0x3ec,0);
      __chkesp();
    }
    else {
      CheckDlgButton(param_1,0x3ec,1);
      __chkesp();
    }
  }
  local_8 = 0x42a33f;
  __chkesp();
  return;
}

