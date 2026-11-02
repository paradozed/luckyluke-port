/* FUN_00428030 @ 00428030 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00428030(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_50 [16];
  short local_10;
  HWND local_c;
  undefined4 local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  FUN_00458ec0();
  GetDlgItem(DAT_004e82fc,0x3e9);
  local_c = (HWND)__chkesp();
  FUN_00458ec0();
  local_8 = (uint)local_8._2_2_ << 0x10;
  while ((local_8 & 0xffff) < (uint)DAT_004e2b68) {
    SendMessageA(local_c,0x14a,0xffffffff,(LPARAM)(&DAT_004e57fe + (local_8 & 0xffff) * 0x228));
    uVar1 = __chkesp();
    local_10 = (short)uVar1;
    SendMessageA(local_c,0x151,(int)local_10,(LPARAM)(&DAT_004e57d8 + (local_8 & 0xffff) * 0x8a));
    __chkesp();
    local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
  }
  local_8 = 0x428125;
  __chkesp();
  return;
}

