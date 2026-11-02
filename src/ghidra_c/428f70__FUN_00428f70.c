/* FUN_00428f70 @ 00428f70 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00428f70(void)

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
  SetWindowTextA(DAT_004e82fc,DAT_004f5d9c);
  __chkesp();
  SetDlgItemTextA(DAT_004e82fc,0x3fa,DAT_004f5d9c);
  __chkesp();
  SetDlgItemTextA(DAT_004e82fc,1,DAT_004f5dd0);
  __chkesp();
  SetDlgItemTextA(DAT_004e82fc,2,DAT_004f5dac);
  __chkesp();
  SetDlgItemTextA(DAT_004e82fc,0x3ec,DAT_004f5d8c);
  __chkesp();
  uStack_8 = 0x429030;
  __chkesp();
  return;
}

