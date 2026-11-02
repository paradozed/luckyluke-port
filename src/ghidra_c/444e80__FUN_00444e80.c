/* FUN_00444e80 @ 00444e80 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00444e80(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  int local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  FUN_00458ec0();
  DAT_004f25a0 = FUN_00494c40(0xa2,1);
  DAT_004f25a4 = DAT_004f25a0 + 0x12;
  DAT_004f25a8 = DAT_004f25a0 + 0x24;
  DAT_004f25ac = DAT_004f25a0 + 0x36;
  DAT_004f25b0 = DAT_004f25a0 + 0x48;
  DAT_004f25b4 = DAT_004f25a0 + 0x5a;
  DAT_004f25b8 = DAT_004f25a0 + 0x6c;
  DAT_004f25bc = DAT_004f25a0 + 0x7e;
  DAT_004f25c0 = DAT_004f25a0 + 0x90;
  FUN_00458ec0();
  DAT_004f25e0 = FUN_00494c40(0x5a,1);
  DAT_004f25e4 = DAT_004f25e0 + 0x12;
  DAT_004f25e8 = DAT_004f25e0 + 0x24;
  DAT_004f25ec = DAT_004f25e0 + 0x36;
  DAT_004f25f0 = DAT_004f25e0 + 0x48;
  FUN_00458ec0();
  DAT_004e85e8 = FUN_00439930(0x400000);
  FUN_00439c90(DAT_004e85e8);
  DAT_004e85ec = FUN_00439930(0x19000);
  FUN_00458ec0();
  DAT_004f58a4 = FUN_00494c40(0x40,1);
  for (local_8 = 0; local_8 < 0x10; local_8 = local_8 + 1) {
    uVar1 = FUN_00494c40(0x20000,1);
    *(undefined4 *)(DAT_004f58a4 + local_8 * 4) = uVar1;
  }
  DAT_004be184 = DAT_004e8584 != 0;
  local_8 = 0x44503b;
  __chkesp();
  return;
}

