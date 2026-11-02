/* FUN_00487930 @ 00487930 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00487930(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_70 [16];
  short local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined1 local_24 [20];
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_70;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  FUN_004823a0((undefined4 *)&DAT_00508180);
  FUN_004824a0(0x4c63f8);
  local_30 = *(short *)(param_1 + 0x70);
  local_2e = *(undefined2 *)(param_1 + 0x74);
  local_2c = *(undefined2 *)(param_1 + 0x78);
  FUN_004826e0(&local_30,&local_10);
  local_10 = local_10 + DAT_00508194;
  local_c = local_c + DAT_00508198;
  local_8 = local_8 + DAT_0050819c;
  FUN_004824a0((int)local_24);
  FUN_0047fa00(*(int *)(param_1 + 0xbc) + 0x10,*(int *)(param_1 + 0xc0) + 0x10,
               *(int *)(param_1 + 0x14) + -2);
  local_8 = 0x487a00;
  __chkesp();
  return;
}

