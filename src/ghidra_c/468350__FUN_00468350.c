/* FUN_00468350 @ 00468350 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00468350(void)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_74 [16];
  int local_34;
  undefined4 local_30;
  int local_2c;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar3 = local_74;
  for (iVar2 = 0x1c; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  (*DAT_004f2400)();
  __chkesp();
  local_34 = *(int *)(*DAT_004f2458 + 0x90);
  local_30 = *(undefined4 *)(*DAT_004f2458 + 0x94);
  local_2c = *(int *)(*DAT_004f2458 + 0x98);
  local_24 = DAT_004f2458[0x2b];
  local_20 = DAT_004f2458[0x2b];
  local_1c = DAT_004f2458[0x2b];
  sVar1 = FUN_00482cb0((short)DAT_004f2458[0x29]);
  local_24 = local_24 * sVar1 >> 0xc;
  sVar1 = FUN_00482c60(*(short *)((int)DAT_004f2458 + 0xa6));
  local_24 = local_24 * sVar1 >> 0xc;
  sVar1 = FUN_00482c60((short)DAT_004f2458[0x29]);
  local_1c = local_1c * sVar1 >> 0xc;
  sVar1 = FUN_00482c60(*(short *)((int)DAT_004f2458 + 0xa6));
  local_1c = local_1c * sVar1 >> 0xc;
  local_34 = local_34 + local_24;
  local_2c = local_2c - local_1c;
  FUN_00467730(*DAT_004f2458,local_34,local_30,local_2c);
  local_14 = *(undefined4 *)(*DAT_004f2458 + 0x90);
  local_10 = *(int *)(*DAT_004f2458 + 0x94);
  local_c = *(undefined4 *)(*DAT_004f2458 + 0x98);
  if ((DAT_004f2438 & 0x400) != 0) {
    local_10 = local_10 + -100;
  }
  if ((DAT_004f2438 & 0x100) != 0) {
    local_10 = local_10 + 100;
  }
  FUN_00467730(*DAT_004f2458,local_14,local_10,local_c);
  FUN_00467440(*DAT_004f2458,0,(short)DAT_004f2458[0x29],0);
  uStack_8 = 0x46855e;
  __chkesp();
  return;
}

