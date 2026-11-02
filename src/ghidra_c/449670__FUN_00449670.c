/* FUN_00449670 @ 00449670 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00449670(void)

{
  ulonglong uVar1;
  ulonglong uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_80 [16];
  uint local_40;
  uint local_3c;
  int local_38;
  int local_34;
  undefined1 local_30 [4];
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  short local_28;
  short local_26;
  undefined1 local_24;
  undefined1 local_23;
  short local_20;
  short local_1e;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined2 local_1a;
  short local_18;
  short local_16;
  undefined1 local_14;
  undefined1 local_13;
  short local_10;
  short local_e;
  undefined1 local_c;
  undefined1 local_b;
  char *local_8;
  
  puVar4 = local_80;
  for (iVar3 = 0x1f; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  local_8 = (char *)FUN_00435000("win\\graphics\\fixgfx.kxp","lucky");
  FUN_00432510(local_8,(uint *)0x4b79a8,0,0,0);
  FUN_00435d90(local_8);
  (*DAT_004e8a24)(0,*DAT_004f58a4);
  __chkesp();
  DAT_004e8488 = 0xbf;
  DAT_004e848c = 0x26;
  uVar1 = ((longlong)(int)DAT_004be3c8 * 0xbf & 0xffffffffU) / 0x280;
  local_3c = (uint)uVar1;
  uVar2 = ((longlong)(int)DAT_004be3cc * 0x26 & 0xffffffffU) / 0x1e0;
  local_40 = (uint)uVar2;
  local_34 = (DAT_004be3c8 >> 1) - local_3c / 2;
  local_38 = (DAT_004be3cc >> 1) - local_40 / 2;
  local_28 = (short)local_34;
  local_26 = (short)local_38;
  local_10 = (short)uVar1;
  local_20 = (short)local_34 + local_10;
  local_1e = (short)local_38;
  local_18 = (short)local_34;
  local_e = (short)uVar2;
  local_16 = (short)local_38 + local_e;
  local_10 = (short)local_34 + local_10;
  local_e = (short)local_38 + local_e;
  local_24 = 0;
  local_23 = 0;
  local_1c = 0xbe;
  local_1b = 0;
  local_14 = 0;
  local_13 = 0x25;
  local_c = 0xbe;
  local_b = 0x25;
  local_2a = 0xff;
  local_2b = 0xff;
  local_2c = 0xff;
  local_1a = 0;
  local_29 = 0;
  (*DAT_004e8a10)(1);
  __chkesp();
  (*DAT_004e8a30)();
  __chkesp();
  (*DAT_004e8a54)(local_30,0x10,0x10,0x10,0x10);
  __chkesp();
  (*DAT_004e8a14)();
  __chkesp();
  (*DAT_004e8a0c)();
  __chkesp();
  local_8 = (char *)0x449839;
  __chkesp();
  return;
}

