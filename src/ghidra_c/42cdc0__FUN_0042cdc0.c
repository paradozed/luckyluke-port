/* FUN_0042cdc0 @ 0042cdc0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0042cdc0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_6c [16];
  undefined1 local_2c [4];
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  short local_24;
  short local_22;
  undefined1 local_20;
  undefined1 local_1f;
  short local_1c;
  short local_1a;
  undefined1 local_18;
  undefined1 local_17;
  undefined2 local_16;
  short local_14;
  short local_12;
  undefined1 local_10;
  undefined1 local_f;
  short local_c;
  short local_a;
  undefined4 local_8;
  
  puVar2 = local_6c;
  for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if ((int)DAT_004bcdcc < 0) {
    DAT_004bcdcc = 0;
  }
  if (DAT_004be3c8 <= DAT_004bcdcc) {
    DAT_004bcdcc = DAT_004be3c8 - 1;
  }
  if ((int)DAT_004bcdd0 < 0) {
    DAT_004bcdd0 = 0;
  }
  if (DAT_004be3cc <= DAT_004bcdd0) {
    DAT_004bcdd0 = DAT_004be3cc - 1;
  }
  local_c = (short)DAT_004bcdcc;
  local_24 = local_c + -7;
  local_a = (short)DAT_004bcdd0;
  local_22 = local_a + -7;
  local_1c = local_c + 7;
  local_1a = local_a + -7;
  local_14 = local_c + -7;
  local_12 = local_a + 7;
  local_c = local_c + 7;
  local_a = local_a + 7;
  local_16 = 0xf;
  local_20 = 0;
  local_1f = 0;
  local_18 = 0xf;
  local_17 = 0;
  local_10 = 0;
  local_f = 0xf;
  local_8 = CONCAT22(local_8._2_2_,0xf0f);
  local_28 = 0xff;
  local_27 = 0xff;
  local_26 = 0xff;
  local_25 = 0;
  (*DAT_004e8a30)();
  __chkesp();
  (*DAT_004e8a54)(local_2c,0,0,0,0);
  __chkesp();
  FUN_004277b0(DAT_004bcdcc,DAT_004bcdd0);
  local_8 = 0x42cf21;
  __chkesp();
  return;
}

