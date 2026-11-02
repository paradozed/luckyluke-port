/* FUN_0046a260 @ 0046a260 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046a260(void)

{
  short sVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_70 [16];
  ushort local_30;
  short local_2c;
  undefined2 local_28;
  undefined2 uStack_26;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_14;
  int local_10;
  int local_c;
  undefined4 uStack_8;
  
  puVar5 = local_70;
  for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  *(undefined2 *)((int)DAT_004f2458 + 0xa6) = *(undefined2 *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x5a)
  ;
  if (DAT_004f2400 != (code *)0x0) {
    (*DAT_004f2400)();
    __chkesp();
    local_24 = *(int *)(*DAT_004f2458 + 0x90);
    local_20 = *(undefined4 *)(*DAT_004f2458 + 0x94);
    local_1c = *(int *)(*DAT_004f2458 + 0x98);
    local_14 = DAT_004f2458[0x2c];
    local_10 = DAT_004f2458[0x2c];
    local_c = DAT_004f2458[0x2c];
    sVar1 = FUN_00482cb0((short)DAT_004f2458[0x29]);
    local_14 = local_14 * sVar1 >> 0xc;
    sVar1 = FUN_00482c60(*(short *)((int)DAT_004f2458 + 0xa6));
    local_14 = local_14 * sVar1 >> 0xc;
    sVar1 = FUN_00482c60((short)DAT_004f2458[0x29]);
    local_c = local_c * sVar1 >> 0xc;
    sVar1 = FUN_00482c60(*(short *)((int)DAT_004f2458 + 0xa6));
    local_c = local_c * sVar1 >> 0xc;
    local_24 = local_24 + local_14;
    local_1c = local_1c - local_c;
    FUN_00467730(*DAT_004f2458,local_24,local_20,local_1c);
  }
  if (*(int *)(*DAT_004f2458 + 0xe4) != 0) {
    uVar2 = FUN_00456150(DAT_004f2438);
    _local_28 = CONCAT22(uStack_26,(short)uVar2);
    local_2c = *(short *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58);
    if ((DAT_004f2458[4] & 0x20000U) == 0) {
      uVar3 = FUN_00456150(DAT_004f2438);
      _local_28 = CONCAT22(uStack_26,(short)uVar3);
      if ((uVar3 & 0xffff) == 8) {
        local_30 = FUN_00467130(*DAT_004f2458);
      }
      else {
        if (((local_2c < 0x201) || (0x5ff < local_2c)) && ((local_2c < 0xa01 || (0xdff < local_2c)))
           ) {
          sVar1 = *(short *)(&DAT_004bddd0 + (uVar3 & 0xffff) * 2);
        }
        else {
          sVar1 = *(short *)(&DAT_004bdde2 + (uVar3 & 0xffff) * 2);
        }
        local_30 = sVar1 + DAT_004e868a;
      }
    }
    else {
      local_30 = FUN_00467130(*DAT_004f2458);
    }
    *(ushort *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x5c) = local_30 & 0xfff;
    (**(code **)(*(int *)(*DAT_004f2458 + 0xe4) + 4))(*(undefined4 *)(*DAT_004f2458 + 0xe4));
    __chkesp();
  }
  uStack_8 = 0x46a556;
  __chkesp();
  return;
}

