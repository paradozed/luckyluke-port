/* FUN_00430510 @ 00430510 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00430510(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_80 [16];
  uint local_40;
  uint local_3c;
  uint local_38;
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
  
  puVar5 = local_80;
  for (iVar4 = 0x1f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_16 = 0xe;
  local_20 = 0;
  local_1f = 0xca;
  local_18 = 0x32;
  local_17 = 0xca;
  local_10 = 0;
  local_f = 0xfb;
  local_8 = CONCAT22(local_8._2_2_,0xfb32);
  local_26 = 0xff;
  local_27 = 0xff;
  local_28 = 0xff;
  local_38 = ((DAT_004be3c8 * 0x32) / 0x280 << 2) / 3;
  local_3c = (uint)(DAT_004be3cc * 0x32) / 0x3c0;
  if (DAT_004e8480 == 1) {
    local_30 = DAT_004be3c8 >> 1;
    local_34 = (uint)(DAT_004be3cc * 0x41) / 0x1e0;
    local_40 = (DAT_004be3c8 * 0x3c) / 0x280;
    sVar2 = (short)local_38;
    sVar1 = (short)local_30;
    local_c = (short)local_40;
    local_24 = (sVar1 - sVar2) + local_c;
    sVar3 = (short)local_3c;
    local_a = (short)local_34;
    local_22 = local_a - sVar3;
    local_1c = sVar1 + sVar2 + local_c;
    local_1a = local_a - sVar3;
    local_14 = (sVar1 - sVar2) + local_c;
    local_12 = local_a + sVar3;
    local_c = sVar1 + sVar2 + local_c;
    local_a = local_a + sVar3;
    (*DAT_004e8a30)();
    __chkesp();
    (*DAT_004e8a54)(local_2c,0x11,0x11,0x11,0x11);
    __chkesp();
  }
  if (DAT_004e8480 == 2) {
    local_30 = DAT_004be3c8 >> 1;
    local_34 = (uint)(DAT_004be3cc * 0x102) / 0x1e0;
    sVar1 = (short)local_38;
    local_c = (short)local_30;
    local_24 = local_c - sVar1;
    sVar2 = (short)local_3c;
    local_a = (short)local_34;
    local_22 = local_a - sVar2;
    local_1c = local_c + sVar1;
    local_1a = local_a - sVar2;
    local_14 = local_c - sVar1;
    local_12 = local_a + sVar2;
    local_c = local_c + sVar1;
    local_a = local_a + sVar2;
    (*DAT_004e8a30)();
    __chkesp();
    (*DAT_004e8a54)(local_2c,0,0,0,0);
    __chkesp();
    local_30 = DAT_004be3c8 >> 1;
    local_34 = (uint)(DAT_004be3cc * 0x154) / 0x1e0;
    sVar1 = (short)local_38;
    local_c = (short)local_30;
    local_24 = local_c - sVar1;
    sVar2 = (short)local_3c;
    local_a = (short)local_34;
    local_22 = local_a - sVar2;
    local_1c = local_c + sVar1;
    local_1a = local_a - sVar2;
    local_14 = local_c - sVar1;
    local_12 = local_a + sVar2;
    local_c = local_c + sVar1;
    local_a = local_a + sVar2;
    (*DAT_004e8a30)();
    __chkesp();
    (*DAT_004e8a54)(local_2c,0,0,0,0);
    __chkesp();
  }
  local_8 = 0x4307c3;
  __chkesp();
  return;
}

