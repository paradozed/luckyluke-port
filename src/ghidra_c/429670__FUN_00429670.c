/* FUN_00429670 @ 00429670 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00429670(void)

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
  if (local_c != 0) {
    _DAT_004f77c4 = *(undefined2 *)(local_c + 0x24);
    FUN_00497270((uint *)&DAT_004f77a4,(uint *)(local_c + 4));
    FUN_00497270((uint *)&DAT_004f77c6,(uint *)(local_c + 0x26));
  }
  local_8 = 0x429720;
  __chkesp();
  return;
}

