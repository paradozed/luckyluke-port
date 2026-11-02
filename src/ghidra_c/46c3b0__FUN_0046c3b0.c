/* FUN_0046c3b0 @ 0046c3b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046c3b0(void)

{
  short sVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_64 [16];
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_14;
  int local_10;
  int local_c;
  undefined4 uStack_8;
  
  puVar5 = local_64;
  for (iVar4 = 0x18; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_24 = *(int *)(*DAT_004f2458 + 0x90);
  local_20 = *(undefined4 *)(*DAT_004f2458 + 0x94);
  local_1c = *(int *)(*DAT_004f2458 + 0x98);
  local_14 = DAT_004f2458[0x2b];
  local_10 = DAT_004f2458[0x2b];
  local_c = DAT_004f2458[0x2b];
  sVar1 = FUN_00482cb0((short)DAT_004f2458[0x29]);
  local_14 = local_14 * sVar1 >> 0xc;
  sVar1 = FUN_00482c60(*(short *)((int)DAT_004f2458 + 0xa6));
  local_14 = local_14 * sVar1 >> 0xc;
  sVar1 = FUN_00482cb0(*(short *)((int)DAT_004f2458 + 0xa6));
  local_10 = local_10 * sVar1 >> 0xc;
  sVar1 = FUN_00482c60((short)DAT_004f2458[0x29]);
  local_c = local_c * sVar1 >> 0xc;
  sVar1 = FUN_00482c60(*(short *)((int)DAT_004f2458 + 0xa6));
  local_c = local_c * sVar1 >> 0xc;
  local_24 = local_24 + local_14;
  local_1c = local_1c - local_c;
  FUN_00467730(*DAT_004f2458,local_24,local_20,local_1c);
  if (*(int *)(*DAT_004f2458 + 0xe4) != 0) {
    uVar2 = FUN_00467130(*DAT_004f2458);
    *(undefined2 *)(DAT_004f2458 + 0x29) = uVar2;
    *(short *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x5c) = (short)DAT_004f2458[0x29];
    (**(code **)(*(int *)(*DAT_004f2458 + 0xe4) + 4))(*(undefined4 *)(*DAT_004f2458 + 0xe4));
    __chkesp();
    uVar3 = FUN_0046c310((short)DAT_004f2458[0x29],*(short *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58)
                        );
    *(short *)(DAT_004f2458 + 0x29) = (short)uVar3;
    FUN_004674b0(*DAT_004f2458,0,(short)DAT_004f2458[0x29],0);
  }
  uStack_8 = 0x46c60b;
  __chkesp();
  return;
}

