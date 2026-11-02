/* FUN_00476a30 @ 00476a30 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00476a30(int param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_70 [16];
  int local_30;
  undefined1 local_2c;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  int local_c;
  undefined4 uStack_8;
  
  puVar2 = local_70;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_14 = *(int *)(param_1 + 0x90);
  local_10 = *(int *)(param_1 + 0x94);
  local_c = *(int *)(param_1 + 0x98);
  local_2c = *(int *)(param_1 + 0x20) != 0;
  if ((bool)local_2c) {
    local_30 = *(int *)(param_1 + 0x20) + (param_3 & 0xffff) * 0x28;
    local_24 = (int)**(short **)(local_30 + 0x10);
    local_20 = (int)*(short *)(*(int *)(local_30 + 0x10) + 2);
    local_1c = (int)*(short *)(*(int *)(local_30 + 0x10) + 4);
    local_14 = local_14 + local_24;
    local_10 = local_10 + local_20;
    local_c = local_c + local_1c;
  }
  FUN_004739f0(param_2,local_14,local_10,local_c);
  uStack_8 = 0x476afd;
  __chkesp();
  return;
}

