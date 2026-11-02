/* FUN_00461020 @ 00461020 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00461020(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  uint extraout_ECX;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  undefined4 *puVar6;
  undefined4 local_64 [16];
  uint local_24;
  undefined2 local_20;
  ushort local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  ushort local_c;
  uint local_8;
  
  puVar6 = local_64;
  for (iVar4 = 0x18; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  if (DAT_004e8914 == 0x16) {
    local_c = 0x14;
    local_14 = CONCAT31(local_14._1_3_,2);
    local_18 = CONCAT31(local_18._1_3_,4);
  }
  else {
    local_24 = (uint)DAT_004f2596;
    if (local_24 == 0) {
      local_c = 0x12;
      local_14 = CONCAT31(local_14._1_3_,0xff);
      local_18 = CONCAT31(local_18._1_3_,2);
    }
    else if (local_24 == 1) {
      local_c = 0x14;
      local_14 = CONCAT31(local_14._1_3_,2);
      local_18 = CONCAT31(local_18._1_3_,4);
    }
    else {
      local_c = 0x16;
      local_14 = CONCAT31(local_14._1_3_,0xff);
      local_18 = CONCAT31(local_18._1_3_,2);
    }
  }
  local_8 = CONCAT22(local_8._2_2_,2);
  uVar2 = FUN_0044ce10(CONCAT22((short)((uint)param_2 >> 0x10),local_c));
  local_10 = CONCAT31(local_10._1_3_,(char)uVar2);
  uVar5 = (uint)DAT_004f2c79;
  if ((uVar2 & 0xff) != uVar5) {
    if ((uVar2 & 0xff) == (local_14 & 0xff)) {
      uVar3 = FUN_0041f260(local_8 & 0xffff,(uint)local_c);
      local_1c = (ushort)uVar3;
      local_20 = FUN_0041f460(CONCAT22(extraout_var,(undefined2)local_8),
                              CONCAT22((short)((uint)uVar3 >> 0x10),local_c));
      FUN_0041f5e0(CONCAT22(extraout_var_00,local_c),0,-0x3b6,local_1c,local_20,'\0');
      uVar5 = extraout_ECX;
    }
    if ((local_10 & 0xff) == (local_18 & 0xff)) {
      uVar3 = FUN_0041f260(local_8 & 0xffff,CONCAT22((short)(uVar5 >> 0x10),local_c));
      local_1c = (ushort)uVar3;
      local_20 = FUN_0041f460(CONCAT22(extraout_var_01,(undefined2)local_8),
                              CONCAT22((short)((uint)uVar3 >> 0x10),local_c));
      FUN_0041f5e0(CONCAT22(extraout_var_02,local_c),5,0,local_1c,local_20,'\0');
    }
  }
  DAT_004f2c79 = (undefined1)local_10;
  cVar1 = FUN_00461250();
  if ((((cVar1 == '\0') && (DAT_004e880c == '\0')) && (DAT_004e8844 != 4)) &&
     (DAT_004e87b6 <=
      *(ushort *)(*(int *)(**(int **)(&DAT_004f2580 + (uint)DAT_004f2596 * 4) + 0xc4) + 0x32))) {
    DAT_004e880c = '\x01';
    DAT_004e880e = 1;
    *(short *)(*(int *)(DAT_004f1578 + 4) + 0x12) =
         *(short *)(*(int *)(DAT_004f1578 + 4) + 0x12) + -1;
    DAT_004f23f8 = FUN_00463820;
    FUN_00463820();
  }
  local_8 = 0x46124b;
  __chkesp();
  return;
}

