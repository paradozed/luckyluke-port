/* FUN_0045a2e0 @ 0045a2e0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0045a2e0(uint param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_15c [16];
  uint local_11c;
  uint local_118;
  char local_114 [256];
  int local_14;
  char *local_10;
  short local_c;
  short local_a;
  undefined4 local_8;
  
  puVar2 = local_15c;
  for (iVar1 = 0x56; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_10 = &DAT_80700000;
  local_118 = param_1 & 0xffff;
  if (local_118 == 0) {
    local_c = 0;
    local_a = 0;
    local_8 = 0x1000200;
  }
  else if (local_118 == 1) {
    local_c = 0;
    local_a = 0;
    local_8 = 0x1ff03ff;
  }
  else {
    FUN_00497610((byte *)"Error: File %s, Line %d");
  }
  FUN_004260f0();
  local_10[0] = '\x10';
  local_10[1] = '\0';
  local_10[2] = '\0';
  local_10[3] = '\0';
  local_10[4] = '\x02';
  local_10[5] = '\0';
  local_10[6] = '\0';
  local_10[7] = '\0';
  *(int *)(local_10 + 8) = (int)(short)local_8 * (int)local_8._2_2_ * 2 + 0xc;
  *(int *)(local_10 + 0xc) = local_a * 0x10000 + (int)local_c;
  *(int *)(local_10 + 0x10) = local_8._2_2_ * 0x10000 + (int)(short)local_8;
  local_11c = (uint)DAT_004e86f8;
  DAT_004e86f8 = DAT_004e86f8 + 1;
  FUN_00497080(local_114,0x4b7e74);
  local_14 = FUN_004ae160(local_114,2);
  if (local_14 != 0) {
    FUN_004ae110(local_14,local_10,(int)(short)local_8 * (int)local_8._2_2_ * 2 + 0x14);
    FUN_004ae0c0(local_14);
  }
  local_8 = 0x45a461;
  __chkesp();
  return;
}

