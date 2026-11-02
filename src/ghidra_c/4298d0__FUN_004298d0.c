/* FUN_004298d0 @ 004298d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004298d0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_50 [16];
  int local_10;
  uint local_c;
  uint local_8;
  
  puVar2 = local_50;
  for (iVar1 = 0x13; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  SendDlgItemMessageA(DAT_004e82fc,0x3ed,0x146,0,0);
  local_8 = __chkesp();
  local_c = 0;
  do {
    if (local_8 <= local_c) {
      SendDlgItemMessageA(DAT_004e82fc,0x3ed,0x14e,0,0);
      __chkesp();
LAB_004299aa:
      local_8 = 0x4299b7;
      __chkesp();
      return;
    }
    SendDlgItemMessageA(DAT_004e82fc,0x3ed,0x150,local_c,0);
    local_10 = __chkesp();
    if (local_10 == DAT_004e82f8) {
      SendDlgItemMessageA(DAT_004e82fc,0x3ed,0x14e,local_c,0);
      __chkesp();
      goto LAB_004299aa;
    }
    local_c = local_c + 1;
  } while( true );
}

