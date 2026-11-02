/* FUN_00420320 @ 00420320 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00420320(ushort param_1,uint param_2,ushort param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_50 [16];
  ushort local_10;
  undefined2 uStack_e;
  short local_c;
  uint local_8;
  
  puVar4 = local_50;
  for (iVar3 = 0x13; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0xcccccccc;
    puVar4 = puVar4 + 1;
  }
  if (param_3 == 0) {
    local_8 = CONCAT22(local_8._2_2_,param_1);
  }
  else {
    local_c = FUN_004836a0((uint)param_1,(uint)param_3);
    uVar1 = FUN_00482c60(local_c);
    _local_10 = CONCAT22(uStack_e,uVar1);
    if (uVar1 < 499) {
      local_8 = CONCAT22(local_8._2_2_,param_1);
    }
    else {
      local_8 = CONCAT22(local_8._2_2_,(short)(((uint)param_3 << 0xc) / (uint)uVar1));
    }
  }
  if ((local_8 & 0xffff) != 0) {
    local_c = FUN_004836a0(param_2 & 0xffff,local_8 & 0xffff);
    uVar2 = FUN_00482c60(local_c);
    _local_10 = CONCAT22(uStack_e,uVar2);
  }
  local_8 = 0x420487;
  __chkesp();
  return;
}

