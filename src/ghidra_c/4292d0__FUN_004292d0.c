/* FUN_004292d0 @ 004292d0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004292d0(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  int *local_10;
  uint local_c;
  uint local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x146,0,0);
  local_8 = __chkesp();
  for (local_c = 0; local_c < local_8; local_c = local_c + 1) {
    SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x150,local_c,0);
    local_10 = (int *)__chkesp();
    iVar2 = _strcmp((char *)(local_10 + 1),s_3dfx_w3x_004bcecc);
    if ((iVar2 == 0) && (DAT_004e858c == *(ushort *)(local_10 + 9))) {
      SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x14e,local_c,0);
      __chkesp();
      goto LAB_0042965c;
    }
  }
  for (local_c = 0; local_c < local_8; local_c = local_c + 1) {
    SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x150,local_c,0);
    local_10 = (int *)__chkesp();
    if (*local_10 == 0x33446678) {
      SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x14e,local_c,0);
      __chkesp();
      goto LAB_0042965c;
    }
  }
  for (local_c = 0; local_c < local_8; local_c = local_c + 1) {
    SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x150,local_c,0);
    local_10 = (int *)__chkesp();
    if ((*local_10 == 0x6d443344) && ((short)local_10[9] != 0)) {
      SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x14e,local_c,0);
      __chkesp();
      goto LAB_0042965c;
    }
  }
  for (local_c = 0; local_c < local_8; local_c = local_c + 1) {
    SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x150,local_c,0);
    local_10 = (int *)__chkesp();
    if ((*local_10 == 0x6d443344) && ((short)local_10[9] == 0)) {
      SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x14e,local_c,0);
      __chkesp();
      goto LAB_0042965c;
    }
  }
  cVar1 = FUN_004283d0();
  if (cVar1 == '\0') {
    for (local_c = 0; local_c < local_8; local_c = local_c + 1) {
      SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x150,local_c,0);
      local_10 = (int *)__chkesp();
      if ((*local_10 == 0x536f6674) && ((short)local_10[9] == 0)) {
        SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x14e,local_c,0);
        __chkesp();
        break;
      }
    }
  }
  else {
    for (local_c = 0; local_c < local_8; local_c = local_c + 1) {
      SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x150,local_c,0);
      local_10 = (int *)__chkesp();
      if ((*local_10 == 0x536f6674) && ((short)local_10[9] != 0)) {
        SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x14e,local_c,0);
        __chkesp();
        break;
      }
    }
  }
LAB_0042965c:
  local_8 = 0x429669;
  __chkesp();
  return;
}

