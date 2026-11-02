/* FUN_00473c50 @ 00473c50 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00473c50(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_ac [16];
  int local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint local_5c;
  uint local_58;
  short local_54;
  short local_50;
  short local_4c;
  short local_48;
  short local_46;
  short local_44;
  short local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  byte *local_2c;
  byte *local_28;
  byte *local_24;
  byte *local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  puVar2 = local_ac;
  for (iVar1 = 0x2a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_c = 0;
  local_10 = 0;
  if (DAT_004f1794 == 0) {
    local_20 = (byte *)**(undefined4 **)(DAT_004f16e0 + 8);
    local_24 = (byte *)**(undefined4 **)(DAT_004f16ec + 8);
    local_28 = (byte *)**(undefined4 **)(DAT_004f16f0 + 8);
    local_2c = (byte *)**(undefined4 **)(DAT_004f16e4 + 8);
    local_30 = FUN_0046e8d0((int)*(short *)(*(int *)(DAT_004f16e0 + 8) + 0x14));
    local_34 = FUN_0046e8d0((int)*(short *)(*(int *)(DAT_004f16ec + 8) + 0x14));
    local_38 = FUN_0046e8d0((int)*(short *)(*(int *)(DAT_004f16f0 + 8) + 0x14));
    local_3c = FUN_0046e8d0((int)*(short *)(*(int *)(DAT_004f16e4 + 8) + 0x14));
    if (DAT_004e89a5 == '\0') {
      FUN_004856f0(local_20,local_30,0,0,0x18);
    }
    else {
      if (DAT_004e89a2 == '\0') {
        FUN_004856f0(local_20,local_30,0,0xc,0x18);
        DAT_004e89a2 = '\x01';
      }
      local_14 = *(int *)(local_20 + 0xcc);
      if (*(short *)(local_14 + 4) == 0xc) {
        DAT_004e89a2 = '\0';
        DAT_004f1758 = 0;
        DAT_004e89a5 = '\0';
      }
    }
    if (DAT_004e89a6 == '\0') {
      FUN_004856f0(local_24,local_34,0,0,0x10);
    }
    else {
      local_18 = *(int *)(local_24 + 0xcc);
      if (DAT_004e89a3 == '\0') {
        FUN_004856f0(local_24,local_34,0,0xb,0x10);
        DAT_004e89a3 = '\x01';
      }
      if ((*(short *)(local_18 + 4) == *(short *)(local_18 + 0xe)) && (DAT_004e89bc != '\0')) {
        DAT_004e89a3 = '\0';
        DAT_004f1668 = 0;
        DAT_004e89a6 = '\0';
        DAT_004f16a8 = 0;
        DAT_004e89a8 = '\0';
      }
      else if ((*(short *)(local_18 + 4) == *(short *)(local_18 + 0xe)) && (DAT_004e89bc == '\0')) {
        DAT_004e89a3 = '\0';
        DAT_004e89b8 = DAT_004e8abc >> 5;
        if (DAT_004e89b4 == 0) {
          DAT_004e89b4 = DAT_004e8abc >> 5;
        }
        if (0x19 < DAT_004e89b8 - DAT_004e89b4) {
          DAT_004e89b4 = 0;
          DAT_004f1668 = 0;
          DAT_004e89a6 = '\0';
          DAT_004e89a3 = '\0';
          DAT_004f16a8 = 0;
          DAT_004e89a8 = '\0';
        }
      }
    }
    if (DAT_004e89a7 == '\0') {
      FUN_004856f0(local_28,local_38,0,0,0x10);
    }
    else {
      if (DAT_004e89a4 == '\0') {
        FUN_004856f0(local_28,local_38,0,0xc,0x10);
        DAT_004e89a4 = '\x01';
      }
      local_1c = *(int *)(local_28 + 0xcc);
      if (*(short *)(local_1c + 4) == 0xc) {
        DAT_004e89a4 = '\0';
        DAT_004f1800 = 0;
        DAT_004e89a7 = '\0';
        DAT_004f16a8 = 0;
        DAT_004e89a8 = '\0';
      }
    }
    if (DAT_004e89bc != '\0') {
      DAT_004f16a8 = 0;
    }
    if (DAT_004e89a8 != '\0') {
      DAT_004e89b0 = DAT_004e8abc >> 5;
      if (DAT_004e89ac == 0) {
        DAT_004e89ac = DAT_004e8abc >> 5;
      }
      if (0x32 < DAT_004e89b0 - DAT_004e89ac) {
        DAT_004e89ac = 0;
        DAT_004f16a8 = 0;
        DAT_004e89a8 = '\0';
      }
    }
    local_40 = (short)((uint)((DAT_004f1792 + 0x10) * DAT_004be3cc) >> 8);
    local_48 = (short)((uint)(DAT_004be3c8 * 0x73) >> 9);
    local_46 = (short)((uint)(DAT_004be3c8 * 0xa2) >> 9);
    local_44 = (short)((uint)(DAT_004be3c8 * 0xdc) >> 9);
    FUN_004739f0((int)local_28,(int)local_48,(int)local_40,0x11);
    FUN_004739f0((int)local_20,(int)local_46,(int)local_40,0x11);
    FUN_004739f0((int)local_24,(int)local_44,(int)local_40,0x11);
    local_6c = (int)DAT_004f1782;
    switch(local_6c) {
    case 0:
      FUN_004856f0(local_2c,local_3c,3,3,0x10);
      break;
    case 1:
      FUN_004856f0(local_2c,local_3c,2,2,0x10);
      break;
    case 2:
      FUN_004856f0(local_2c,local_3c,1,1,0x10);
      break;
    case 3:
      FUN_004856f0(local_2c,local_3c,0,0,0x10);
    }
    local_4c = (short)((uint)(DAT_004be3c8 * 0x32) >> 9);
    local_50 = (short)((uint)((DAT_004f1792 + 10) * DAT_004be3cc) >> 8);
    FUN_004739f0((int)local_2c,(int)local_4c,(int)local_50,0x11);
    local_8 = (uint)local_8._2_2_ << 0x10;
    while ((local_8 & 0xffff) < 5) {
      if (*(int *)(&DAT_004f1798 + (local_8 & 0xffff) * 4) != 0) {
        local_c = *(int *)(&DAT_004f1798 + (local_8 & 0xffff) * 4);
        local_10 = *(undefined4 *)(local_c + 0x90);
        local_54 = (short)((uint)((DAT_004f1792 + 0x10) * DAT_004be3cc) >> 8);
        FUN_004739f0(*(int *)(&DAT_004f1798 + (local_8 & 0xffff) * 4),local_10,(int)local_54,0x11);
      }
      local_8 = CONCAT22(local_8._2_2_,(short)local_8 + 1);
    }
    local_68 = (uint)((DAT_004f1792 + 0x1a) * DAT_004be3cc) >> 8;
    local_64 = (uint)(DAT_004be3c8 * 0x46) >> 9;
    local_60 = (uint)(DAT_004be3c8 * 0x78) >> 9;
    local_5c = (uint)(DAT_004be3c8 * 0xb3) >> 9;
    local_58 = (uint)(DAT_004be3c8 * 0xe5) >> 9;
    FUN_00473bf0(&DAT_004b33d4,(int)DAT_004f1780,local_64,local_68);
    FUN_00473bf0(&DAT_004b33d4,(int)DAT_004f1788,local_60,local_68);
    FUN_00473bf0(&DAT_004b33d4,(int)DAT_004f1786,local_5c,local_68);
    FUN_00473bf0(&DAT_004b33d4,(int)DAT_004f1784,local_58,local_68);
  }
  else {
    *(undefined1 *)(DAT_004f16e0 + 0x14) = 0;
    *(undefined1 *)(DAT_004f16ec + 0x14) = 0;
    *(undefined1 *)(DAT_004f16f0 + 0x14) = 0;
    *(undefined1 *)(DAT_004f16e4 + 0x14) = 0;
    DAT_004e89a3 = '\0';
    DAT_004f1668 = 0;
    DAT_004e89a6 = '\0';
    DAT_004e89a2 = '\0';
    DAT_004f1758 = 0;
    DAT_004e89a5 = '\0';
    DAT_004e89a4 = '\0';
    DAT_004f1800 = 0;
    DAT_004e89a7 = '\0';
    DAT_004f16a8 = 0;
    DAT_004e89a8 = '\0';
  }
  local_8 = 0x474306;
  __chkesp();
  return;
}

