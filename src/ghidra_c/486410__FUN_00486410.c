/* FUN_00486410 @ 00486410 */
/* decompiled from Lucky.exe (Game.run) */


/* WARNING: Type propagation algorithm not settling */

void __cdecl FUN_00486410(ushort param_1,short param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 local_70 [16];
  short local_30 [2];
  byte local_2c [4];
  undefined4 *local_28;
  undefined4 local_24;
  int local_20;
  int local_1c [4];
  undefined4 local_c;
  undefined4 *local_8;
  
  puVar2 = local_70;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_30[0] = 0;
  local_30[1] = 0;
  local_2c[0] = 0;
  local_2c[1] = 0;
  local_2c[2] = 0;
  local_2c[3] = 0;
  local_20 = 0xe8;
  local_24 = 0x16c;
  local_28 = (undefined4 *)FUN_00439af0(0x16c);
  *local_28 = DAT_004c6d50;
  local_28[1] = DAT_004c6d54;
  local_28[2] = DAT_004c6d58;
  local_28[3] = local_24;
  local_28[0xf] = local_20;
  local_28[0xe] = 1;
  *(ushort *)((int)local_28 + local_20) = param_1;
  local_20 = local_20 + 4;
  local_28[4] = 4;
  local_28[5] = 4;
  local_28[6] = 0;
  local_1c[0] = local_20;
  local_8 = local_28;
  FUN_00470c70((uint)param_1,(undefined1 *)local_30,(undefined1 *)(local_30 + 1));
  FUN_00470e20((uint)param_1,local_2c,local_2c + 2);
  FUN_004860b0(0x4c6d38,local_30);
  local_30[0] = 0;
  local_30[1] = 0;
  FUN_00485e70((short *)((int)local_28 + local_20),local_8 + 0x29,local_30,param_2);
  if ((int)local_8[0x29] < (int)local_8[0x2a]) {
    local_8[0x2b] = local_8[0x29];
  }
  else {
    local_8[0x2b] = local_8[0x2a];
  }
  if ((int)local_8[0x2d] < (int)local_8[0x2c]) {
    local_8[0x2e] = local_8[0x2c];
  }
  else {
    local_8[0x2e] = local_8[0x2d];
  }
  local_8[9] = 1;
  local_8[10] = 0;
  local_1c[1] = local_20 + 0x20;
  *(undefined4 *)((int)local_28 + local_20 + 0x20) = 0;
  local_8[7] = 1;
  local_8[8] = 0;
  local_1c[2] = local_20 + 0x24;
  puVar2 = (undefined4 *)((int)local_28 + local_20 + 0x24);
  *puVar2 = DAT_004c6d70;
  puVar2[1] = DAT_004c6d74;
  puVar2[2] = DAT_004c6d78;
  local_8[0xb] = 1;
  local_8[0xc] = 0;
  local_1c[3] = local_20 + 0x30;
  puVar2 = &DAT_004c6d80;
  puVar5 = (undefined4 *)((int)local_28 + local_20 + 0x30);
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar5 = puVar5 + 1;
  }
  local_c = 0x10;
  local_8[0x10] = 0x20;
  local_8[0x11] = local_20 + 0x54;
  piVar3 = local_1c;
  piVar4 = (int *)((int)local_28 + local_20 + 0x54);
  for (iVar1 = 5; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar4 = *piVar3;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  }
  puVar2 = &DAT_004c6d38;
  puVar5 = (undefined4 *)((int)local_28 + local_20 + 0x68);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar5 = puVar5 + 1;
  }
  local_20 = local_20 + 0x80;
  local_8[0x12] = 0x28;
  local_8[0x13] = 0;
  local_8[0x14] = 0;
  local_8[0x31] = 0;
  local_8[0x32] = 0;
  local_8[0x33] = 0;
  local_8[0x2f] = 0;
  local_8[0x30] = 0;
  local_8[0x34] = 0;
  local_8[0x35] = 0;
  puVar2 = &DAT_004c63f8;
  puVar5 = local_8 + 0x17;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar5 = puVar5 + 1;
  }
  puVar2 = &DAT_004c63f8;
  puVar5 = local_8 + 0x1f;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar5 = puVar5 + 1;
  }
  local_8[0x27] = 0;
  local_8[0x28] = 0;
  local_8[0x36] = 0;
  local_8[0x37] = 0;
  local_8[3] = local_20;
  local_8[0xd] = 0;
  local_8 = (undefined4 *)0x4867ba;
  __chkesp();
  return;
}

