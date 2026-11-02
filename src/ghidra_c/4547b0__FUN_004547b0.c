/* FUN_004547b0 @ 004547b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004547b0(void)

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
  FUN_00454330(&DAT_004f2b6c,(int *)&DAT_004f2b9c);
  FUN_00454330(&DAT_004f2b8c,(int *)&DAT_004f2bc4);
  DAT_004f2bbc = (short)(DAT_004f2b8c >> 0xc);
  DAT_004f2bbe = (short)(DAT_004f2b90 >> 0xc);
  DAT_004f2bc0 = (undefined2)(DAT_004f2b94 >> 0xc);
  FUN_00453190(&DAT_004f2b6c,&DAT_004f2bbc);
  DAT_004f2be4 = DAT_004f2be4 + -1;
  if (DAT_004f2be4 == 0) {
    FUN_00453540(&DAT_004f2b7c,&DAT_004f2b6c);
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
    if ((((DAT_004f2bf8 != 2) && (DAT_004f2bf8 != 3)) && (DAT_004f2bf8 != 4)) && (DAT_004f2bf8 != 5)
       ) {
      DAT_004f2bf8 = 0;
    }
    DAT_004f2b64 = 1;
    PTR_FUN_004bd5d8 = FUN_00453590;
  }
  local_8 = 0x4549c6;
  __chkesp();
  return;
}

