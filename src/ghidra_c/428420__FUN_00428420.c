/* FUN_00428420 @ 00428420 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00428420(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  HWND local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  GetDlgItem(DAT_004e82fc,0x3f7);
  local_8 = (HWND)__chkesp();
  SendMessageA(local_8,0x14a,0xffffffff,0x4b4db4);
  __chkesp();
  SendMessageA(local_8,0x14a,0xffffffff,0x4b4db0);
  __chkesp();
  cVar1 = FUN_004283d0();
  if (cVar1 != '\0') {
    SendMessageA(local_8,0x14a,0xffffffff,0x4b4dac);
    __chkesp();
  }
  local_8 = (HWND)0x4284cd;
  __chkesp();
  return;
}

