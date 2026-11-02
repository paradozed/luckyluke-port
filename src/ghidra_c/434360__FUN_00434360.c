/* FUN_00434360 @ 00434360 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00434360(HWND param_1)

{
  HWND pHVar1;
  int iVar2;
  undefined4 *puVar3;
  BOOL BVar4;
  undefined4 local_148 [16];
  BYTE local_108 [256];
  undefined4 uStack_8;
  
  puVar3 = local_148;
  for (iVar2 = 0x51; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  iVar2 = FUN_00442670('\x01');
  if (iVar2 == 0) {
    BVar4 = 0;
    GetDlgItem(param_1,0x40a);
    pHVar1 = (HWND)__chkesp();
    EnableWindow(pHVar1,BVar4);
    __chkesp();
  }
  else {
    iVar2 = FUN_004427e0("Target directory",local_108);
    if (iVar2 == 0) {
      BVar4 = 0;
      GetDlgItem(param_1,0x40a);
      pHVar1 = (HWND)__chkesp();
      EnableWindow(pHVar1,BVar4);
      __chkesp();
    }
    FUN_00442770();
  }
  uStack_8 = 0x43440f;
  __chkesp();
  return;
}

