/* FUN_00460e00 @ 00460e00 */
/* decompiled from Lucky.exe (Game.run) */


void __fastcall FUN_00460e00(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined4 *puVar5;
  undefined4 local_60 [16];
  uint local_20;
  undefined2 local_1c;
  ushort local_18;
  uint local_14;
  undefined1 local_10;
  undefined3 uStack_f;
  ushort local_c;
  uint local_8;
  
  puVar5 = local_60;
  for (iVar4 = 0x17; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  if (DAT_004e8914 == 0x16) {
    local_c = 0x14;
    local_14 = CONCAT31(local_14._1_3_,5);
  }
  else {
    local_20 = (uint)DAT_004f2596;
    if (local_20 == 0) {
      local_c = 0x12;
      local_14 = CONCAT31(local_14._1_3_,2);
    }
    else if (local_20 == 1) {
      local_c = 0x14;
      local_14 = CONCAT31(local_14._1_3_,5);
    }
    else {
      local_c = 0x16;
      local_14 = CONCAT31(local_14._1_3_,2);
    }
  }
  local_8 = CONCAT22(local_8._2_2_,2);
  uVar2 = FUN_0044ce10(CONCAT22((short)((uint)param_2 >> 0x10),local_c));
  _local_10 = CONCAT31(uStack_f,(char)uVar2);
  if (((uVar2 & 0xff) != (uint)DAT_004f2c79) && ((uVar2 & 0xff) == (local_14 & 0xff))) {
    uVar3 = FUN_0041f260(local_8 & 0xffff,(uint)local_c);
    local_18 = (ushort)uVar3;
    local_1c = FUN_0041f460(CONCAT22(extraout_var,(undefined2)local_8),
                            CONCAT22((short)((uint)uVar3 >> 0x10),local_c));
    FUN_0041f5e0(CONCAT22(extraout_var_00,local_c),5,0,local_18,local_1c,'\0');
  }
  DAT_004f2c79 = local_10;
  cVar1 = FUN_00461250();
  if ((((cVar1 == '\0') && (DAT_004e880c == '\0')) && (DAT_004e8844 != 3)) &&
     ((DAT_004e8844 != 4 &&
      (DAT_004e87ca <=
       *(ushort *)(*(int *)(**(int **)(&DAT_004f2580 + (uint)DAT_004f2596 * 4) + 0xc4) + 0x32))))) {
    DAT_004e880c = '\x01';
    DAT_004e880e = 1;
    *(short *)(*(int *)(DAT_004f1578 + 4) + 0x12) =
         *(short *)(*(int *)(DAT_004f1578 + 4) + 0x12) + -1;
    DAT_004f23f8 = FUN_00463610;
    FUN_00463610();
  }
  local_8 = 0x460fc9;
  __chkesp();
  return;
}

