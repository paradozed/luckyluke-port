/* FUN_00454500 @ 00454500 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00454500(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_6c [16];
  short local_2c;
  short local_2a;
  undefined2 local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_14;
  int local_10;
  int local_c;
  undefined4 uStack_8;
  
  puVar3 = local_6c;
  for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (DAT_004f2b68 != 0) {
    if ((DAT_004f2b65 == '\x02') && (uVar1 = FUN_004544b0(), (uVar1 & 0xff) == 0)) {
      DAT_004f2b65 = '\x01';
    }
    local_24 = *(int *)(DAT_004f2b68 + 0x90);
    local_20 = *(int *)(DAT_004f2b68 + 0x94);
    local_1c = *(undefined4 *)(DAT_004f2b68 + 0x98);
    if (((DAT_004f2b65 == '\0') || (DAT_004f2b65 == '\x03')) && (DAT_004e8690 == '\0')) {
      local_20 = DAT_004f2c38;
    }
    local_20 = local_20 + DAT_004f2bf4;
    FUN_00454390(&local_14,&local_24,&DAT_004f2b8c);
    FUN_00454330(&DAT_004f2b6c,&local_14);
    FUN_00454330(&DAT_004f2b7c,&local_14);
    FUN_00453540(&DAT_004f2b8c,&local_24);
    FUN_00454330(&DAT_004f2b6c,(int *)&DAT_004f2b9c);
    FUN_00454330(&DAT_004f2b7c,(int *)&DAT_004f2bac);
    FUN_00454390(&local_14,&DAT_004f2b7c,&DAT_004f2b6c);
    local_2c = FUN_004836a0(local_10,local_c);
    local_2a = FUN_004836a0(local_14,local_c);
    local_28 = 0;
    if (DAT_004f2c2c == 2) {
      local_2c = (short)_DAT_004f2c34 - local_2c;
    }
    if (0x400 < local_2a) {
      local_2a = local_2a + -0x1000;
    }
    local_2a = -local_2a;
    FUN_00453540(&local_14,&DAT_004f2b6c);
    local_14 = local_14 + DAT_004f2bec;
    FUN_00453190(&local_14,&local_2c);
    DAT_004f2be4 = DAT_004f2be4 + -1;
    if (DAT_004f2be4 == 0) {
      FUN_00453540(&DAT_004f2b8c,&DAT_004f2b7c);
      DAT_004f2bbe = local_2a;
      if (((DAT_004f2bf8 != 2) && (DAT_004f2bf8 != 3)) &&
         ((DAT_004f2bf8 != 4 && (DAT_004f2bf8 != 5)))) {
        DAT_004f2bf8 = 0;
      }
      DAT_004f2b64 = 1;
      if (DAT_004e8690 == '\x01') {
        DAT_004e8690 = '\0';
        DAT_004f2c38 = FUN_00457510(*(int *)(*DAT_004f2458 + 0xe4));
        DAT_004f2458[4] = DAT_004e8698;
      }
      PTR_FUN_004bd5d8 = FUN_00453590;
    }
  }
  uStack_8 = 0x45479d;
  __chkesp();
  return;
}

