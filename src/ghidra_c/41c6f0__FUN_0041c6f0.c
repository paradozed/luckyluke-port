/* FUN_0041c6f0 @ 0041c6f0 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0041c6f0(undefined4 param_1,void *param_2)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_60 [16];
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar5 = local_60;
  for (iVar4 = 0x17; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  if ((DAT_004e866c != '\x01') &&
     (sVar2 = FUN_004074b0(param_2,2), *(int *)(&DAT_004f1e40 + sVar2 * 4) != 0)) {
    PTR_FUN_004bd5d8 = FUN_00453590;
    sVar2 = FUN_004074b0(param_2,2);
    DAT_004f2b68 = **(int **)(*(int *)(&DAT_004f1e40 + sVar2 * 4) + 8);
    DAT_004f2b8c = *(undefined4 *)(DAT_004f2b68 + 0x90);
    DAT_004f2b90 = *(int *)(DAT_004f2b68 + 0x94);
    DAT_004f2b94 = *(undefined4 *)(DAT_004f2b68 + 0x98);
    if ((DAT_004f2bf8 != 2) && (((DAT_004f2bf8 != 3 && (DAT_004f2bf8 != 4)) && (DAT_004f2bf8 != 5)))
       ) {
      DAT_004f2bf8 = 0;
    }
    local_8 = DAT_004f2b68;
    sVar2 = FUN_004074b0(param_2,5);
    DAT_004f2be8 = (uint)sVar2;
    if (30000 < DAT_004f2be8) {
      DAT_004f2be8 = 30000;
    }
    if (DAT_004f2be8 == 0) {
      DAT_004f2be8 = 1;
    }
    sVar2 = FUN_004074b0(param_2,6);
    DAT_004f2bf4 = (int)sVar2;
    if (6000 < DAT_004f2bf4) {
      DAT_004f2bf4 = 6000;
    }
    if (DAT_004f2bf4 < -6000) {
      DAT_004f2bf4 = -6000;
    }
    DAT_004f2b90 = DAT_004f2b90 + DAT_004f2bf4;
    FUN_0041e370(&DAT_004f2b6c,&DAT_004f2b8c);
    uVar1 = DAT_004f2be8;
    if (DAT_004f2c2c != 2) {
      uVar1 = -DAT_004f2be8;
    }
    DAT_004f2b74 = DAT_004f2b74 + uVar1;
    DAT_004f2bec = 0;
    DAT_004f2bbc = FUN_004074b0(param_2,3);
    if (800 < DAT_004f2bbc) {
      DAT_004f2bbc = 800;
    }
    if (DAT_004f2bbc < -800) {
      DAT_004f2bbc = -800;
    }
    if (DAT_004f2bbc == -0x400) {
      DAT_004f2bbc = -0x3ff;
    }
    sVar2 = FUN_00482cb0(DAT_004f2bbc);
    sVar3 = FUN_00482c60(DAT_004f2bbc);
    local_14 = (sVar2 * -0x1000) / (int)sVar3;
    local_18 = local_14 * DAT_004f2be8;
    local_10 = local_18 >> 0xc;
    DAT_004f2b70 = DAT_004f2b70 + local_10;
    sVar2 = FUN_004074b0(param_2,4);
    local_c = (int)sVar2;
    if (0x640 < local_c) {
      local_c = 0x640;
    }
    if (local_c < -0x640) {
      local_c = -0x640;
    }
    if (DAT_004f2c2c == 2) {
      local_c = local_c + _DAT_004f2c34;
    }
    if (local_c == -0x400) {
      local_c = -0x3ff;
    }
    sVar2 = FUN_00482cb0((short)local_c);
    sVar3 = FUN_00482c60((short)local_c);
    local_1c = ((int)sVar2 << 0xc) / (int)sVar3;
    local_20 = local_1c * DAT_004f2be8;
    local_10 = local_20 >> 0xc;
    DAT_004f2b6c = DAT_004f2b6c + local_10;
  }
  local_8 = 0x41ca0b;
  __chkesp();
  return;
}

