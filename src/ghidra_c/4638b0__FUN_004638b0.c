/* FUN_004638b0 @ 004638b0 */
/* decompiled from Lucky.exe (Game.run) */


void FUN_004638b0(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined4 *puVar4;
  undefined8 uVar5;
  undefined4 local_58 [16];
  undefined2 local_18;
  ushort local_14;
  uint local_10;
  ushort local_c [2];
  uint local_8;
  
  puVar4 = local_58;
  for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  FUN_00465630((undefined2 *)&local_8,local_c);
  uVar1 = FUN_0044ce10(CONCAT22(extraout_var_00,(undefined2)local_8));
  local_10 = CONCAT31(local_10._1_3_,(char)uVar1);
  if ((uVar1 & 0xff) != (uint)DAT_004f2c6e) {
    uVar5 = 0;
    if ((uVar1 & 0xff) == 1) {
      uVar2 = FUN_0041f260((uint)local_c[0],local_8 & 0xffff);
      local_14 = (ushort)uVar2;
      uVar2 = FUN_0041f460(CONCAT22((short)((uint)uVar2 >> 0x10),local_c[0]),
                           CONCAT22(extraout_var_01,(undefined2)local_8));
      local_18 = (undefined2)uVar2;
      uVar5 = FUN_0041f5e0(CONCAT22((short)((uint)uVar2 >> 0x10),(undefined2)local_8),10,0,local_14,
                           local_18,'\0');
    }
    if ((local_10 & 0xff) == 3) {
      local_14 = FUN_0041f260(CONCAT22((short)((ulonglong)uVar5 >> 0x10),local_c[0]),
                              CONCAT22((short)((ulonglong)uVar5 >> 0x30),(undefined2)local_8));
      local_18 = FUN_0041f460(CONCAT22(extraout_var_02,local_c[0]),
                              CONCAT22(extraout_var,(undefined2)local_8));
      FUN_0041f5e0(CONCAT22(extraout_var_03,(undefined2)local_8),0xd,0,local_14,local_18,'\0');
    }
  }
  DAT_004f2c6e = (undefined1)local_10;
  local_8 = 0x4639d1;
  __chkesp();
  return;
}

