/* FUN_0041c3e0 @ 0041c3e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0041c3e0(int param_1,int param_2,undefined4 param_3,short param_4,short param_5)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_58 [16];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar4 = local_58;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (DAT_004e866c != '\x01') {
    DAT_004f2b6c = param_1;
    DAT_004f2b70 = param_2;
    DAT_004f2b74 = param_3;
    if (DAT_004f2c04 < param_1) {
      DAT_004f2b6c = DAT_004f2c04;
    }
    if (DAT_004f2b6c < DAT_004f2c00) {
      DAT_004f2b6c = DAT_004f2c00;
    }
    if (DAT_004f2c0c < param_2) {
      DAT_004f2b70 = DAT_004f2c0c;
    }
    if (DAT_004f2b70 < DAT_004f2c08) {
      DAT_004f2b70 = DAT_004f2c08;
    }
    DAT_004f2bbc = param_4;
    if (800 < param_4) {
      DAT_004f2bbc = 800;
    }
    if (DAT_004f2bbc < -800) {
      DAT_004f2bbc = -800;
    }
    DAT_004f2bbe = param_5;
    if (0x640 < param_5) {
      DAT_004f2bbe = 0x640;
    }
    if (DAT_004f2bbe < -0x640) {
      DAT_004f2bbe = -0x640;
    }
    if (DAT_004f2c2c == 2) {
      DAT_004f2bbe = DAT_004f2bbe + DAT_004f2c34;
    }
    FUN_0041e370(&DAT_004f2b7c,&DAT_004f2b6c);
    iVar3 = DAT_004f2be8;
    if (DAT_004f2c2c == 2) {
      iVar3 = -DAT_004f2be8;
    }
    DAT_004f2b84 = DAT_004f2b84 + iVar3;
    if (DAT_004f2bbc == -0x400) {
      DAT_004f2bbc = -0x3ff;
    }
    sVar1 = FUN_00482cb0(DAT_004f2bbc);
    sVar2 = FUN_00482c60(DAT_004f2bbc);
    local_c = (sVar1 * -0x1000) / (int)sVar2;
    local_10 = local_c * DAT_004f2be8;
    local_8 = local_10 >> 0xc;
    DAT_004f2b80 = DAT_004f2b80 - local_8;
    if (DAT_004f2bbe == -0x400) {
      DAT_004f2bbe = -0x3ff;
    }
    sVar1 = FUN_00482cb0(DAT_004f2bbe);
    sVar2 = FUN_00482c60(DAT_004f2bbe);
    local_14 = ((int)sVar1 << 0xc) / (int)sVar2;
    local_18 = local_14 * DAT_004f2be8;
    DAT_004f2b7c = DAT_004f2b7c - (local_18 >> 0xc);
    DAT_004f2bec = 0;
    DAT_004f2b68 = 0;
    PTR_FUN_004bd5d8 = FUN_00453590;
  }
  local_8 = 0x41c66b;
  __chkesp();
  return;
}

