/* FUN_00463310 @ 00463310 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_00463310(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined4 *puVar5;
  undefined4 local_58 [16];
  undefined2 local_18;
  ushort local_14;
  undefined1 local_10;
  undefined3 uStack_f;
  ushort local_c [2];
  uint local_8;
  
  puVar5 = local_58;
  for (iVar4 = 0x15; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  FUN_00465630((undefined2 *)&local_8,local_c);
  uVar2 = FUN_0044ce10(CONCAT22(extraout_var,(undefined2)local_8));
  _local_10 = CONCAT31(uStack_f,(char)uVar2);
  if (((uVar2 & 0xff) != (uint)DAT_004f2c6e) && ((uVar2 & 0xff) == 3)) {
    uVar3 = FUN_0041f260((uint)local_c[0],local_8 & 0xffff);
    local_14 = (ushort)uVar3;
    uVar3 = FUN_0041f460(CONCAT22((short)((uint)uVar3 >> 0x10),local_c[0]),
                         CONCAT22(extraout_var_00,(undefined2)local_8));
    local_18 = (undefined2)uVar3;
    FUN_0041f5e0(CONCAT22((short)((uint)uVar3 >> 0x10),(undefined2)local_8),0,300,local_14,local_18,
                 '\0');
  }
  DAT_004f2c6e = local_10;
  FUN_00464ab0();
  if (DAT_004e880d == '\0') {
    FUN_00464910();
  }
  if (*(char *)(DAT_004f2458 + 0x74) == '\0') {
    bVar1 = FUN_00463120();
    if (bVar1) {
      DAT_004f23f8 = FUN_00462ff0;
      FUN_00462ff0();
    }
    else {
      bVar1 = FUN_00463160();
      if (!bVar1) {
        DAT_004f23f8 = FUN_00462ff0;
        FUN_00462ff0();
      }
    }
  }
  else {
    bVar1 = FUN_00463160();
    if (bVar1) {
      DAT_004f23f8 = FUN_00462ff0;
      FUN_00462ff0();
    }
    else {
      bVar1 = FUN_00463120();
      if (!bVar1) {
        DAT_004f23f8 = FUN_00462ff0;
        FUN_00462ff0();
      }
    }
  }
  local_8 = 0x463473;
  __chkesp();
  return;
}

