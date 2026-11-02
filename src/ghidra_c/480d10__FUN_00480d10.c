/* FUN_00480d10 @ 00480d10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00480d10(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_7c [17];
  short local_38;
  short local_36;
  undefined2 local_34;
  int *local_30;
  int local_2c;
  int local_28;
  undefined1 local_24 [20];
  int local_10 [2];
  undefined4 uStack_8;
  
  puVar2 = local_7c;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_2c = *(int *)(param_1 + 0xc4);
  iVar1 = *(int *)(param_1 + 0x20);
  local_28 = iVar1 + 0x28;
  local_30 = (int *)(local_2c + 0x14);
  *local_30 = (int)*(short *)(iVar1 + 0x44);
  *(int *)(local_2c + 0x18) = (int)*(short *)(iVar1 + 0x46);
  *(int *)(local_2c + 0x1c) = (int)*(short *)(iVar1 + 0x48);
  local_38 = *(short *)(iVar1 + 0x44) + **(short **)(iVar1 + 0x2c);
  local_36 = *(short *)(iVar1 + 0x46) + *(short *)(*(int *)(iVar1 + 0x2c) + 2);
  local_34 = *(undefined2 *)(*(int *)(iVar1 + 0x2c) + 4);
  FUN_004823a0((undefined4 *)(param_1 + 0x5c));
  FUN_004824a0(0x4c63f8);
  FUN_004826e0(&local_38,local_10);
  FUN_004824a0((int)local_24);
  *(undefined2 *)(local_2c + 0x2a) = 0;
  *(undefined2 *)(local_2c + 0x2c) = 0;
  *(undefined2 *)(local_2c + 0x2e) = 0;
  uStack_8 = 0x480e0e;
  __chkesp();
  return;
}

