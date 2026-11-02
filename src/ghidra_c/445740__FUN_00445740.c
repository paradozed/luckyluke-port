/* FUN_00445740 @ 00445740 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00445740(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_60 [16];
  tagMSG local_20;
  
  puVar2 = local_60;
  for (iVar1 = 0x17; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  while( true ) {
    PeekMessageA(&local_20,(HWND)0x0,0,0,0);
    iVar1 = __chkesp();
    if (iVar1 == 0) break;
    GetMessageA(&local_20,(HWND)0x0,0,0);
    iVar1 = __chkesp();
    if (iVar1 == 0) break;
    TranslateMessage(&local_20);
    __chkesp();
    DispatchMessageA(&local_20);
    __chkesp();
  }
  local_20.pt.y = 0x4457d2;
  __chkesp();
  return;
}

