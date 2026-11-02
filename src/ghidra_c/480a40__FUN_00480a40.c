/* FUN_00480a40 @ 00480a40 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00480a40(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_a0 [16];
  short local_60;
  short local_5e;
  short local_5c;
  short local_58;
  short local_56;
  short local_54;
  short local_50;
  short local_4e;
  short local_4c;
  undefined2 local_48 [8];
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  int *local_30;
  int local_2c;
  int local_28;
  undefined1 local_24 [20];
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_a0;
  for (iVar1 = 0x27; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_2c = *(int *)(param_1 + 0xc4);
  iVar1 = *(int *)(param_1 + 0x20);
  local_28 = iVar1 + 0x28;
  local_30 = (int *)(local_2c + 0x14);
  local_38 = **(undefined2 **)(iVar1 + 0x2c);
  local_36 = *(undefined2 *)(*(int *)(iVar1 + 0x2c) + 2);
  local_34 = *(undefined2 *)(*(int *)(iVar1 + 0x2c) + 4);
  FUN_004824a0(0x4c63f8);
  FUN_00480c10(*(short *)(local_2c + 0x28),local_48,*(short *)(local_28 + 0x1c) - (short)*local_30,
               *(short *)(local_28 + 0x1e) - (short)local_30[1],
               *(short *)(local_28 + 0x20) - (short)local_30[2],*(undefined2 *)(local_28 + 0x1c),
               *(undefined2 *)(local_28 + 0x1e),*(undefined2 *)(local_28 + 0x20));
  FUN_004823a0((undefined4 *)(param_1 + 0x5c));
  FUN_0047f6d0((int)local_48,(int)&local_60,3);
  *local_30 = (int)*(short *)(local_28 + 0x1c);
  local_30[1] = (int)*(short *)(local_28 + 0x1e);
  local_30[2] = (int)*(short *)(local_28 + 0x20);
  *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + (int)local_60;
  *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + (int)local_5e;
  *(int *)(param_1 + 0x98) = *(int *)(param_1 + 0x98) + (int)local_5c;
  *(short *)(local_2c + 0x2a) = local_60;
  *(short *)(local_2c + 0x2c) = local_5e;
  *(short *)(local_2c + 0x2e) = local_5c;
  local_10 = (int)local_50 + (int)local_58;
  local_c = (int)local_4e + (int)local_56;
  local_8 = (int)local_4c + (int)local_54;
  FUN_004824a0((int)local_24);
  local_8 = 0x480bfd;
  __chkesp();
  return;
}

