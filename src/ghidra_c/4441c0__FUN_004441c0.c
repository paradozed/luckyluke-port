/* FUN_004441c0 @ 004441c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004441c0(undefined2 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_74 [16];
  uint local_34;
  uint local_30;
  undefined1 local_2c [4];
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
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
  
  puVar2 = local_74;
  for (iVar1 = 0x1c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  _memset(local_2c,0,0x28);
  local_30 = DAT_004be3c8 >> 1;
  local_34 = DAT_004be3cc >> 1;
  local_c = (short)local_30;
  local_24 = local_c + -0x80;
  local_1c = local_c + 0x80;
  local_14 = local_c + -0x80;
  local_c = local_c + 0x80;
  local_a = (short)local_34;
  local_22 = local_a + -0x80;
  local_1a = local_a + -0x80;
  local_12 = local_a + 0x80;
  local_a = local_a + 0x80;
  local_26 = 0xff;
  local_27 = 0xff;
  local_28 = 0xff;
  local_20 = 0;
  local_1f = 0;
  local_18 = 0xff;
  local_17 = 0;
  local_10 = 0;
  local_f = 0xff;
  local_8 = CONCAT22(local_8._2_2_,0xffff);
  local_16 = param_1;
  (*DAT_004e8a30)();
  __chkesp();
  (*DAT_004e8a54)(local_2c,10,10,10,10);
  __chkesp();
  local_8 = 0x4442d5;
  __chkesp();
  return;
}

