/* FUN_00454d50 @ 00454d50 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00454d50(short param_1,int param_2,uint param_3,int param_4,uint param_5)

{
  short sVar1;
  short sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_84 [16];
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34 [4];
  int local_24 [4];
  int local_14;
  int local_10;
  uint local_c;
  undefined4 uStack_8;
  
  puVar4 = local_84;
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  DAT_004f2be8 = param_3;
  if (30000 < param_3) {
    DAT_004f2be8 = 30000;
  }
  if (DAT_004f2be8 == 0) {
    DAT_004f2be8 = 1;
  }
  DAT_004f2bf4 = param_4;
  if (6000 < param_4) {
    DAT_004f2bf4 = 6000;
  }
  if (DAT_004f2bf4 < -6000) {
    DAT_004f2bf4 = -6000;
  }
  DAT_004f2be4 = param_5;
  if (200 < param_5) {
    DAT_004f2be4 = 200;
  }
  if (DAT_004f2be4 < 10) {
    DAT_004f2be4 = 10;
  }
  DAT_004f2be4 = 0xcd - DAT_004f2be4;
  DAT_004f2bbc = param_1;
  if (800 < param_1) {
    DAT_004f2bbc = 800;
  }
  if (DAT_004f2bbc < -800) {
    DAT_004f2bbc = -800;
  }
  if (DAT_004f2bbc == -0x400) {
    DAT_004f2bbc = -0x3ff;
  }
  sVar1 = FUN_00482cb0(DAT_004f2bbc);
  sVar2 = FUN_00482c60(DAT_004f2bbc);
  local_38 = (sVar1 * -0x1000) / (int)sVar2;
  local_3c = local_38 * DAT_004f2be8;
  local_10 = local_3c >> 0xc;
  if (DAT_004e8690 == '\0') {
    if (0x640 < param_2) {
      param_2 = 0x640;
    }
    if (param_2 < -0x640) {
      param_2 = -0x640;
    }
    if (DAT_004f2c2c == 2) {
      param_2 = param_2 + _DAT_004f2c34;
    }
  }
  if (param_2 == -0x400) {
    param_2 = -0x3ff;
  }
  sVar1 = FUN_00482cb0((short)param_2);
  sVar2 = FUN_00482c60((short)param_2);
  local_40 = ((int)sVar1 << 0xc) / (int)sVar2;
  local_44 = local_40 * DAT_004f2be8;
  local_14 = local_44 >> 0xc;
  if (DAT_004f2c2c == 2) {
    local_c = DAT_004f2be8;
  }
  else {
    local_c = -DAT_004f2be8;
  }
  DAT_004f2b8c = *(undefined4 *)(DAT_004f2b68 + 0x90);
  DAT_004f2b90 = *(int *)(DAT_004f2b68 + 0x94);
  DAT_004f2b94 = *(undefined4 *)(DAT_004f2b68 + 0x98);
  if (((DAT_004f2b65 == '\0') || (DAT_004f2b65 == '\x03')) && (DAT_004e8690 == '\0')) {
    DAT_004f2b90 = DAT_004f2c38;
  }
  DAT_004f2b90 = DAT_004f2b90 + DAT_004f2bf4;
  FUN_00453540(local_34,&DAT_004f2b8c);
  FUN_00453540(local_24,&DAT_004f2b8c);
  FUN_00454330(local_24,&local_14);
  if (DAT_004e8691 == '\x01') {
    DAT_004f2b7c = DAT_004e8694;
    DAT_004e8691 = '\0';
  }
  FUN_00455090((int *)&DAT_004f2b9c,local_24,&DAT_004f2b6c,DAT_004f2be4);
  FUN_00455090((int *)&DAT_004f2bac,local_34,&DAT_004f2b7c,DAT_004f2be4);
  DAT_004f2b64 = 0;
  PTR_FUN_004bd5d8 = FUN_00454500;
  uStack_8 = 0x455088;
  __chkesp();
  return;
}

