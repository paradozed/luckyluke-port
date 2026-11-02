/* FUN_00428b30 @ 00428b30 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00428b30(void)

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
  FUN_00458ec0();
  SetDlgItemInt(DAT_004e82fc,0x3f0,DAT_004be3c8,0);
  __chkesp();
  SetDlgItemInt(DAT_004e82fc,0x3f1,DAT_004be3cc,0);
  __chkesp();
  if (DAT_004e8584 == 0) {
    CheckDlgButton(DAT_004e82fc,0x3ee,0);
    __chkesp();
  }
  else {
    CheckDlgButton(DAT_004e82fc,0x3ee,1);
    __chkesp();
  }
  if (DAT_004e8588 == 0) {
    CheckDlgButton(DAT_004e82fc,0x3ef,0);
    __chkesp();
  }
  else {
    CheckDlgButton(DAT_004e82fc,0x3ef,1);
    __chkesp();
  }
  SendDlgItemMessageA(DAT_004e82fc,0x3ed,0x14e,_DAT_004bcec8 - 1,0);
  __chkesp();
  if (DAT_004e8594 == 0) {
    CheckDlgButton(DAT_004e82fc,0x3f2,0);
    __chkesp();
  }
  else {
    CheckDlgButton(DAT_004e82fc,0x3f2,1);
    __chkesp();
  }
  if (_DAT_004e8598 == 0) {
    CheckDlgButton(DAT_004e82fc,0x3f3,0);
    __chkesp();
  }
  else {
    CheckDlgButton(DAT_004e82fc,0x3f3,1);
    __chkesp();
  }
  if (DAT_004e859c == 0) {
    CheckDlgButton(DAT_004e82fc,0x3f4,0);
    __chkesp();
  }
  else {
    CheckDlgButton(DAT_004e82fc,0x3f4,1);
    __chkesp();
  }
  if (DAT_004bcfcc == 0) {
    CheckDlgButton(DAT_004e82fc,0x3f5,0);
    __chkesp();
  }
  else {
    CheckDlgButton(DAT_004e82fc,0x3f5,1);
    __chkesp();
  }
  if (DAT_004e85a0 == 0) {
    CheckDlgButton(DAT_004e82fc,0x3f6,0);
    __chkesp();
  }
  else {
    CheckDlgButton(DAT_004e82fc,0x3f6,1);
    __chkesp();
  }
  SendDlgItemMessageA(DAT_004e82fc,0x3f7,0x14e,DAT_004e85a8,0);
  __chkesp();
  SendDlgItemMessageA(DAT_004e82fc,0x3f8,0x14e,_DAT_004e85ac,0);
  __chkesp();
  if (DAT_004bcfd0 == 0) {
    CheckDlgButton(DAT_004e82fc,0x3f9,0);
    __chkesp();
  }
  else {
    CheckDlgButton(DAT_004e82fc,0x3f9,1);
    __chkesp();
  }
  if (DAT_004bcfd4 == 0) {
    CheckDlgButton(DAT_004e82fc,0x3fb,0);
    __chkesp();
  }
  else {
    CheckDlgButton(DAT_004e82fc,0x3fb,1);
    __chkesp();
  }
  SetDlgItemInt(DAT_004e82fc,0x3fd,_DAT_004bcfd8,0);
  __chkesp();
  SetDlgItemInt(DAT_004e82fc,0x3fe,_DAT_004bcfdc,0);
  __chkesp();
  if (DAT_004e8750 == 0) {
    CheckDlgButton(DAT_004e82fc,0x3fc,0);
    __chkesp();
  }
  else {
    CheckDlgButton(DAT_004e82fc,0x3fc,1);
    __chkesp();
  }
  SetDlgItemInt(DAT_004e82fc,0x3ff,DAT_004bcfe0,0);
  __chkesp();
  SetDlgItemInt(DAT_004e82fc,0x400,DAT_004bcfe4,0);
  __chkesp();
  uStack_8 = 0x428f5d;
  __chkesp();
  return;
}

