/* FUN_00403b30 @ 00403b30 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00403b30(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_44 [15];
  undefined4 uStack_8;
  
  puVar2 = local_44;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004d1d64 != 0) {
    mciSendCommandA(DAT_004d1d60,0x809,0,0);
    __chkesp();
  }
  uStack_8 = 0x403b8e;
  __chkesp();
  return;
}

