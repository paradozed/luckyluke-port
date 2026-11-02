/* FUN_0041d430 @ 0041d430 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl
FUN_0041d430(int param_1,int param_2,int param_3,short param_4,short param_5,uint param_6)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_4c [16];
  short local_c;
  short local_a;
  uint local_8;
  
  puVar2 = local_4c;
  for (iVar1 = 0x12; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  if (DAT_004e866c != '\x01') {
    DAT_004f2b7c = param_1;
    DAT_004f2b80 = param_2;
    DAT_004f2b84 = param_3;
    if (DAT_004f2c04 < param_1) {
      DAT_004f2b7c = DAT_004f2c04;
    }
    if (DAT_004f2b7c < DAT_004f2c00) {
      DAT_004f2b7c = DAT_004f2c00;
    }
    if (DAT_004f2c0c < param_2) {
      DAT_004f2b80 = DAT_004f2c0c;
    }
    if (DAT_004f2b80 < DAT_004f2c08) {
      DAT_004f2b80 = DAT_004f2c08;
    }
    if (DAT_004f2c14 < param_3) {
      DAT_004f2b84 = DAT_004f2c14;
    }
    if (DAT_004f2b84 < DAT_004f2c10) {
      DAT_004f2b84 = DAT_004f2c10;
    }
    local_c = param_4;
    if (800 < param_4) {
      local_c = 800;
    }
    if (local_c < -800) {
      local_c = -800;
    }
    local_a = param_5;
    if (0x640 < param_5) {
      local_a = 0x640;
    }
    if (local_a < -0x640) {
      local_a = -0x640;
    }
    if (DAT_004f2c2c == 2) {
      local_a = local_a + DAT_004f2c34;
    }
    local_8 = local_8 & 0xffff0000;
    DAT_004f2be4 = param_6;
    if (200 < param_6) {
      DAT_004f2be4 = 200;
    }
    if (DAT_004f2be4 < 10) {
      DAT_004f2be4 = 10;
    }
    DAT_004f2be4 = 0xcd - DAT_004f2be4;
    DAT_004f2b6c = DAT_004f2b6c + DAT_004f2bec;
    DAT_004f2bec = 0;
    FUN_0041e410((int *)&DAT_004f2b9c,&DAT_004f2b7c,&DAT_004f2b6c,DAT_004f2be4);
    FUN_0041e480((int *)&DAT_004f2bc4,&local_c,&DAT_004f2bbc,DAT_004f2be4);
    DAT_004f2b8c = (int)DAT_004f2bbc << 0xc;
    DAT_004f2b90 = (int)DAT_004f2bbe << 0xc;
    DAT_004f2b94 = (int)DAT_004f2bc0 << 0xc;
    DAT_004f2b64 = 0;
    DAT_004f2b62 = 0;
    DAT_004f2b68 = 0;
    PTR_FUN_004bd5d8 = FUN_004547b0;
  }
  local_8 = 0x41d67a;
  __chkesp();
  return;
}

