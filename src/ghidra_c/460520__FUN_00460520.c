/* FUN_00460520 @ 00460520 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00460520(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 extraout_var;
  undefined4 *puVar4;
  undefined4 local_64 [16];
  uint local_24;
  undefined2 local_20;
  ushort local_1c;
  uint local_18;
  uint local_14;
  undefined1 local_10;
  undefined3 uStack_f;
  ushort local_c;
  uint local_8;
  
  puVar4 = local_64;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (DAT_004e8914 == 0x16) {
    local_c = 0x14;
    local_14 = CONCAT31(local_14._1_3_,2);
    local_18 = CONCAT31(local_18._1_3_,3);
  }
  else {
    local_24 = (uint)DAT_004f2596;
    if (local_24 == 0) {
      local_c = 0x12;
      local_14 = CONCAT31(local_14._1_3_,1);
      local_18 = CONCAT31(local_18._1_3_,3);
    }
    else if (local_24 == 1) {
      local_c = 0x14;
      local_14 = CONCAT31(local_14._1_3_,2);
      local_18 = CONCAT31(local_18._1_3_,3);
    }
    else {
      local_c = 0x16;
      local_14 = CONCAT31(local_14._1_3_,1);
      local_18 = CONCAT31(local_18._1_3_,2);
    }
  }
  local_8 = CONCAT22(local_8._2_2_,2);
  uVar1 = FUN_0044ce10(CONCAT22((short)((uint)param_2 >> 0x10),local_c));
  _local_10 = CONCAT31(uStack_f,(char)uVar1);
  if (((uVar1 & 0xff) != (uint)DAT_004f2c79) &&
     (((uVar1 & 0xff) == (local_14 & 0xff) || ((uVar1 & 0xff) == (local_18 & 0xff))))) {
    uVar2 = FUN_0041f260(local_8 & 0xffff,(uint)local_c);
    local_1c = (ushort)uVar2;
    uVar2 = FUN_0041f460(CONCAT22((short)((uint)uVar2 >> 0x10),(undefined2)local_8),
                         CONCAT22(extraout_var,local_c));
    local_20 = (undefined2)uVar2;
    FUN_0041f5e0(CONCAT22((short)((uint)uVar2 >> 0x10),local_c),7,0,local_1c,local_20,'\0');
  }
  DAT_004f2c79 = local_10;
  FUN_00461db0('\x01');
  local_8 = 0x460668;
  __chkesp();
  return;
}

