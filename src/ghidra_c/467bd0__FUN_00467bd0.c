/* FUN_00467bd0 @ 00467bd0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00467bd0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_5c [16];
  ushort local_1c;
  short local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 uStack_8;
  
  puVar3 = local_5c;
  for (iVar2 = 0x16; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  FUN_0046a6e0(DAT_004f2458 + 0x2d,DAT_004f2458 + 0x2e,(int *)&DAT_004bdf40);
  local_14 = *(undefined4 *)(*DAT_004f2458 + 0x90);
  local_c = *(undefined4 *)(*DAT_004f2458 + 0x98);
  local_10 = *(int *)(*DAT_004f2458 + 0x94) + DAT_004f2458[0x2e];
  FUN_00467730(*DAT_004f2458,local_14,local_10,local_c);
  uVar1 = FUN_0041ff20();
  if ((uVar1 & 0xff) == 1) {
    DAT_004f240c = DAT_004f240c + 1;
    if (((DAT_004f2458[4] & 0x100U) == 0) && (DAT_004f240c == 0x28)) {
      FUN_0041f5e0(0,2,-0x32,0x1fff,0x400,'\0');
    }
    if ((DAT_004f2458[4] & 0x20U) != 0) {
      local_18 = (short)((uint)DAT_004f240c * -0x200 +
                         ((int)((uint)DAT_004f240c * -0x200) >> 0x1f & 0xffU) >> 8) + -400;
      if (local_18 < -700) {
        local_18 = -700;
      }
      if (-400 < local_18) {
        local_18 = -400;
      }
      local_1c = (ushort)(((int)((uint)DAT_004f240c * 0x400) >> 8) + 0xdac);
      if ((short)local_1c < 0xdac) {
        local_1c = 0xdac;
      }
      if (0x1194 < (short)local_1c) {
        local_1c = 0x1194;
      }
      FUN_0041f5e0(0,3,local_18,local_1c,0x400,'\0');
    }
  }
  if ((DAT_004f2458[4] & 0x20U) != 0) {
    DAT_004f2458[0x2d] = 0;
    DAT_004f23f8 = FUN_00466900;
  }
  uStack_8 = 0x467dbf;
  __chkesp();
  return;
}

