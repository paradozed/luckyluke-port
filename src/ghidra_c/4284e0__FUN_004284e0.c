/* FUN_004284e0 @ 004284e0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004284e0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  HWND local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  GetDlgItem(DAT_004e82fc,0x3f8);
  local_8 = (HWND)__chkesp();
  SendMessageA(local_8,0x14a,0xffffffff,0x4b4dfc);
  __chkesp();
  SendMessageA(local_8,0x14a,0xffffffff,0x4b4df0);
  __chkesp();
  SendMessageA(local_8,0x14a,0xffffffff,0x4b4de8);
  __chkesp();
  SendMessageA(local_8,0x14a,0xffffffff,0x4b4de0);
  __chkesp();
  SendMessageA(local_8,0x14a,0xffffffff,0x4b4dd4);
  __chkesp();
  SendMessageA(local_8,0x14a,0xffffffff,0x4b4dc8);
  __chkesp();
  SendMessageA(local_8,0x14a,0xffffffff,0x4b4dbc);
  __chkesp();
  local_8 = (HWND)0x4285fb;
  __chkesp();
  return;
}

