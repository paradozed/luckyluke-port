/* FUN_004299c0 @ 004299c0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004299c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  int local_c;
  WPARAM local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x147,0,0);
  local_8 = __chkesp();
  SendDlgItemMessageA(DAT_004e82fc,0x3e9,0x150,local_8,0);
  local_c = __chkesp();
  DAT_004e858c = (uint)*(ushort *)(local_c + 0x24);
  FUN_00497270((uint *)s_3dfx_w3x_004bcecc,(uint *)(local_c + 4));
  local_8 = 0x429a57;
  __chkesp();
  return;
}

