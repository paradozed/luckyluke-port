/* FUN_004297b0 @ 004297b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004297b0(void)

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
  SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x146,0,0);
  local_8 = __chkesp();
  local_c = 0;
  do {
    if (local_8 <= local_c) {
      SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x14e,0,0);
      __chkesp();
LAB_004298b5:
      local_8 = 0x4298c2;
      __chkesp();
      return;
    }
    SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x150,local_c,0);
    local_10 = __chkesp();
    iVar1 = _strcmp(&DAT_004f77a4,(char *)(local_10 + 4));
    if (iVar1 == 0) {
      iVar1 = _strcmp(&DAT_004f77c6,(char *)(local_10 + 0x26));
      if (iVar1 == 0) {
        SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x14e,local_c,0);
        __chkesp();
        goto LAB_004298b5;
      }
    }
    local_c = local_c + 1;
  } while( true );
}

