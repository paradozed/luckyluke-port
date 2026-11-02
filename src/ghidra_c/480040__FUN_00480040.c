/* FUN_00480040 @ 00480040 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00480040(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_5c [16];
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = local_5c;
  for (iVar1 = 0x16; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xcccccccc;
    puVar2 = puVar2 + 1;
  }
  local_1c = *(int *)(param_1 + 0xa4) + *(int *)(param_1 + 0x70);
  local_10 = *(int *)(param_1 + 0xb0) + *(int *)(param_1 + 0x70);
  local_18 = *(int *)(param_1 + 0xa8) + *(int *)(param_1 + 0x74);
  local_c = *(int *)(param_1 + 0xb4) + *(int *)(param_1 + 0x74);
  local_14 = *(int *)(param_1 + 0xac) + *(int *)(param_1 + 0x78);
  local_8 = *(int *)(param_1 + 0xb8) + *(int *)(param_1 + 0x78);
  FUN_00488260(param_1);
  FUN_00490cc0((undefined2 *)&local_1c,param_2,param_3,param_4);
  local_8 = 0x4800f5;
  __chkesp();
  return;
}

