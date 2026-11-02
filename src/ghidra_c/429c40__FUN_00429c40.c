/* FUN_00429c40 @ 00429c40 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00429c40(void)

{
  uint *puVar1;
  HWND pHVar2;
  int iVar3;
  undefined4 *puVar4;
  BOOL BVar5;
  undefined4 local_148 [16];
  uint local_108 [64];
  WPARAM local_8;
  
  puVar4 = local_148;
  for (iVar3 = 0x51; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x147,0,0);
  local_8 = __chkesp();
  if (local_8 != 0xffffffff) {
    SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x148,local_8,(LPARAM)local_108);
    iVar3 = __chkesp();
    if (iVar3 != -1) {
      puVar1 = FUN_004981e0(local_108,"Software");
      if (puVar1 == (uint *)0x0) {
        BVar5 = 0;
        GetDlgItem(DAT_004e82fc,0x3f6);
        pHVar2 = (HWND)__chkesp();
        EnableWindow(pHVar2,BVar5);
        __chkesp();
        BVar5 = 0;
        GetDlgItem(DAT_004e82fc,0x3f7);
        pHVar2 = (HWND)__chkesp();
        EnableWindow(pHVar2,BVar5);
        __chkesp();
      }
      else {
        BVar5 = 1;
        GetDlgItem(DAT_004e82fc,0x3f6);
        pHVar2 = (HWND)__chkesp();
        EnableWindow(pHVar2,BVar5);
        __chkesp();
        BVar5 = 1;
        GetDlgItem(DAT_004e82fc,0x3f7);
        pHVar2 = (HWND)__chkesp();
        EnableWindow(pHVar2,BVar5);
        __chkesp();
      }
    }
  }
  local_8 = 0x429da0;
  __chkesp();
  return;
}

