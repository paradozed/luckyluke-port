/* FUN_0045fe30 @ 0045fe30 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_0045fe30(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined4 *puVar4;
  undefined4 local_60 [16];
  uint local_20;
  undefined2 local_1c;
  ushort local_18;
  uint local_14;
  undefined1 local_10;
  undefined3 uStack_f;
  ushort local_c;
  uint local_8;
  
  puVar4 = local_60;
  for (iVar3 = 0x17; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (DAT_004e8914 == 0x16) {
    local_c = 0x14;
  }
  else {
    local_20 = (uint)DAT_004f2596;
    if (local_20 == 0) {
      local_c = 0x12;
    }
    else if (local_20 == 1) {
      local_c = 0x14;
    }
    else {
      local_c = 0x16;
    }
  }
  local_8 = CONCAT22(local_8._2_2_,2);
  local_14 = CONCAT31(local_14._1_3_,1);
  uVar1 = FUN_0044ce10(CONCAT22((short)((uint)param_2 >> 0x10),local_c));
  _local_10 = CONCAT31(uStack_f,(char)uVar1);
  if (((uVar1 & 0xff) != (uint)DAT_004f2c79) && ((uVar1 & 0xff) == (local_14 & 0xff))) {
    uVar2 = FUN_0041f260(local_8 & 0xffff,(uint)local_c);
    local_18 = (ushort)uVar2;
    local_1c = FUN_0041f460(CONCAT22(extraout_var,(undefined2)local_8),
                            CONCAT22((short)((uint)uVar2 >> 0x10),local_c));
    FUN_0041f5e0(CONCAT22(extraout_var_00,local_c),0xb,0,local_18,local_1c,'\0');
  }
  DAT_004f2c79 = local_10;
  FUN_00461bf0();
  local_8 = 0x45ff4d;
  __chkesp();
  return;
}

