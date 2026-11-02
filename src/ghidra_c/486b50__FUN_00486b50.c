/* FUN_00486b50 @ 00486b50 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00486b50(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_50 [16];
  int *local_10;
  int *local_c;
  int local_8;
  
  puVar3 = local_50;
  for (iVar2 = 0x13; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  if (*(int *)(param_2 + 0xd8) == 0) {
    FUN_00486f50(param_2);
  }
  local_c = *(int **)(param_2 + 0xd8);
  if (*local_c == 0) {
    *local_c = param_1;
  }
  else {
    local_8 = *local_c;
    if (local_8 == -0x22222223) goto LAB_00486ce6;
    while (*(int *)(*(int *)(local_8 + 0xdc) + 0x3c) != 0) {
      local_8 = *(int *)(*(int *)(local_8 + 0xdc) + 0x3c);
    }
    *(int *)(*(int *)(local_8 + 0xdc) + 0x3c) = param_1;
  }
  uVar1 = FUN_00439af0(0x40);
  *(undefined4 *)(param_1 + 0xdc) = uVar1;
  local_10 = *(int **)(param_1 + 0xdc);
  local_10[0xf] = 0;
  if (*(int *)(param_2 + 0xdc) == 0) {
    local_10[1] = param_2;
  }
  else {
    local_10[1] = *(int *)(*(int *)(param_2 + 0xdc) + 4);
  }
  *local_10 = param_2;
  *(int *)(*(int *)(local_10[1] + 0xd8) + 4) =
       *(int *)(*(int *)(local_10[1] + 0xd8) + 4) + *(int *)(param_1 + 0x10);
  *(int *)(*(int *)(local_10[1] + 0xd8) + 8) =
       *(int *)(*(int *)(local_10[1] + 0xd8) + 8) + *(int *)(param_1 + 0x2c);
  if (*(int *)(param_1 + 0xd8) == 0) {
    *(undefined1 *)(param_1 + 1) = 4;
  }
  else {
    *(undefined1 *)(param_1 + 1) = 3;
  }
  *(undefined ***)(param_1 + 0xd0) = &PTR_FUN_004c6480 + (uint)*(byte *)(param_1 + 1) * 5;
  puVar3 = &DAT_004c6438;
  puVar4 = (undefined4 *)(*(int *)(param_1 + 0xdc) + 8);
  for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_00486820(param_2,(short *)(local_10 + 2));
LAB_00486ce6:
  local_8 = 0x486cf3;
  __chkesp();
  return;
}

