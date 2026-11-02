/* FUN_00403e00 @ 00403e00 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00403e00(void)

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
  local_c = 3;
  mciSendCommandA(DAT_004d1d60,0x814,0x100,(DWORD_PTR)local_14);
  __chkesp();
  uStack_8 = 0x403e5d;
  __chkesp();
  return;
}

