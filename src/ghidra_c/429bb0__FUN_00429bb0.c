/* FUN_00429bb0 @ 00429bb0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00429bb0(void)

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
  SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x147,0,0);
  local_8 = __chkesp();
  if (local_8 == 0xffffffff) {
    DAT_004f58a8 = 0;
  }
  else {
    SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x150,local_8,0);
    DAT_004f58a8 = __chkesp();
  }
  local_8 = 0x429c3c;
  __chkesp();
  return;
}

