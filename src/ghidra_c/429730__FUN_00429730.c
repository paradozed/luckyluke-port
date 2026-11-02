/* FUN_00429730 @ 00429730 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00429730(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_48 [16];
  WPARAM local_8;
  
  puVar2 = local_48;
  for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  SendDlgItemMessageA(DAT_004e82fc,0x3ed,0x147,0,0);
  local_8 = __chkesp();
  SendDlgItemMessageA(DAT_004e82fc,0x3ed,0x150,local_8,0);
  DAT_004e82f8 = __chkesp();
  local_8 = 0x4297a6;
  __chkesp();
  return;
}

