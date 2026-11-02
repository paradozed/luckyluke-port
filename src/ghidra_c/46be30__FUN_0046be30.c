/* FUN_0046be30 @ 0046be30 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_0046be30(void)

{
  char cVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_70 [16];
  ushort local_30;
  undefined2 local_2c;
  short local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  undefined4 local_10;
  int local_c;
  undefined4 uStack_8;
  
  puVar5 = local_70;
  for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  if ((DAT_004f2438 & 0x8000) == 0) {
    DAT_004f2458[4] = DAT_004f2458[4] | 0x40000;
  }
  local_2c = *(undefined2 *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58);
  local_30 = (short)DAT_004f2458[0x29] - *(short *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58) & 0xfff;
  if (0x400 < local_30) {
    local_30 = 0x1000 - local_30;
  }
  if ((short)local_30 < 0x400) {
    *(undefined2 *)(DAT_004f2458 + 0x29) = *(undefined2 *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58);
    *(undefined2 *)((int)DAT_004f2458 + 0xa6) =
         *(undefined2 *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x5a);
  }
  else {
    *(ushort *)(DAT_004f2458 + 0x29) =
         *(short *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x58) + 0x800U & 0xfff;
    *(short *)((int)DAT_004f2458 + 0xa6) = -*(short *)(*(int *)(*DAT_004f2458 + 0xe4) + 0x5a);
  }
  (*DAT_004f2400)();
  __chkesp();
  local_14 = *(int *)(*DAT_004f2458 + 0x90);
  local_10 = *(undefined4 *)(*DAT_004f2458 + 0x94);
  local_c = *(int *)(*DAT_004f2458 + 0x98);
  local_24 = DAT_004f2458[0x2c];
  local_20 = DAT_004f2458[0x2c];
  local_1c = DAT_004f2458[0x2c];
  sVar2 = FUN_00482cb0((short)DAT_004f2458[0x29]);
  local_24 = local_24 * sVar2 >> 0xc;
  sVar2 = FUN_00482c60(*(short *)((int)DAT_004f2458 + 0xa6));
  local_24 = local_24 * sVar2 >> 0xc;
  sVar2 = FUN_00482c60((short)DAT_004f2458[0x29]);
  local_1c = local_1c * sVar2 >> 0xc;
  sVar2 = FUN_00482c60(*(short *)((int)DAT_004f2458 + 0xa6));
  local_1c = local_1c * sVar2 >> 0xc;
  local_14 = local_14 + local_24;
  local_c = local_c - local_1c;
  FUN_00467730(*DAT_004f2458,local_14,local_10,local_c);
  if ((DAT_004f2458[4] & 0x20U) == 0) {
    FUN_0047c7f0((undefined2 *)(*DAT_004f2458 + 0x5c),0,-(short)DAT_004f2458[0x29],
                 (short)DAT_004f2458[0x2a]);
  }
  else {
    FUN_0047c7f0((undefined2 *)(*DAT_004f2458 + 0x5c),*(short *)((int)DAT_004f2458 + 0xa6),
                 -(short)DAT_004f2458[0x29],(short)DAT_004f2458[0x2a]);
  }
  if (((DAT_004f2458[4] & 0x100U) != 0) && ((DAT_004f1794 & 1) == 0)) {
    DAT_004f1782 = 3;
    DAT_004f1780 = DAT_004f1780 + -1;
    DAT_004f1794 = DAT_004f1794 | 1;
  }
  uVar3 = FUN_0041ff20();
  if ((uVar3 & 0xff) == 1) {
    if (((DAT_004f2458[4] & 0x20U) == 0) || ((DAT_004f2458[4] & 0x100U) != 0)) {
      FUN_0041fa80(DAT_004f245e,0,0x400);
    }
    else {
      local_28 = (short)(DAT_004f2458[0x2b] * 0x400 + (DAT_004f2458[0x2b] * 0x400 >> 0x1f & 0xffU)
                        >> 8) + -200;
      if (local_28 < -200) {
        local_28 = -200;
      }
      if (0xaf0 < local_28) {
        local_28 = 0xaf0;
      }
      cVar1 = FUN_0041fbb0(DAT_004f245e);
      if (cVar1 == '\0') {
        FUN_0041fc80(DAT_004f245e);
        DAT_004f245e = FUN_0041f5e0(2,0,local_28,7000,0x400,'\0');
        FUN_0041fc30(DAT_004f245e);
      }
      else {
        FUN_0041f9f0(DAT_004f245e,local_28);
        FUN_0041fa80(DAT_004f245e,7000,0x400);
      }
    }
  }
  uStack_8 = 0x46c2aa;
  __chkesp();
  return;
}

