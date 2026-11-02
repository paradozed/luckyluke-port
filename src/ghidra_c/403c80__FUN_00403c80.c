/* FUN_00403c80 @ 00403c80 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00403c80(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_54 [16];
  undefined1 local_14 [8];
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar2 = local_54;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004d1d64 != 0) {
    _memset(local_14,0,0x10);
    local_c = param_1;
    mciSendCommandA(DAT_004d1d60,0x814,0x102,(DWORD_PTR)local_14);
    __chkesp();
  }
  uStack_8 = 0x403cf6;
  __chkesp();
  return;
}

