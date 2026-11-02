/* FUN_00481980 @ 00481980 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00481980(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_6c [16];
  short local_2c;
  undefined2 local_2a;
  undefined2 local_28;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  short local_18;
  short local_16;
  short local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_6c;
  for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_2c = *(short *)(param_1 + 0x70);
  local_2a = *(undefined2 *)(param_1 + 0x74);
  local_28 = *(undefined2 *)(param_1 + 0x78);
  FUN_00482820((undefined4 *)&DAT_00508180,&local_2c,&local_10);
  local_10 = local_10 + DAT_00508194;
  local_c = local_c + DAT_00508198;
  local_8 = local_8 + DAT_0050819c;
  local_24 = DAT_00508180;
  local_22 = DAT_00508182;
  local_20 = DAT_00508184;
  local_1e = DAT_00508186;
  local_1c = DAT_00508188;
  local_1a = DAT_0050818a;
  local_18 = -DAT_0050818c;
  local_16 = -DAT_0050818e;
  local_14 = -DAT_00508190;
  FUN_004823a0((undefined4 *)&local_24);
  FUN_004824a0((int)&local_24);
  FUN_0047fa00(*(int *)(*(int *)(param_1 + 8) + 0xbc) + 0x10,*(int *)(param_1 + 0xc0) + 0x10,
               *(int *)(param_1 + 0x14) + -2);
  local_8 = 0x481aad;
  __chkesp();
  return;
}

