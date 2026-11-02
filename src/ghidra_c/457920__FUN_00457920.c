/* FUN_00457920 @ 00457920 */
/* decompiled from Lucky.exe (Game.run) */


int __cdecl FUN_00457920(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_68 [16];
  int local_28;
  int local_24;
  int local_20;
  int local_10 [3];
  
  puVar3 = local_68;
  for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_10[0] = *param_2 - *(int *)(param_1 + 0x28);
  local_10[1] = param_2[1] - *(int *)(param_1 + 0x2c);
  local_10[2] = param_2[2] - *(int *)(param_1 + 0x30);
  if (*(short *)(param_1 + 0x20) < 0) {
    local_24 = -(int)*(short *)(param_1 + 0x20);
  }
  else {
    local_24 = (int)*(short *)(param_1 + 0x20);
  }
  if (*(short *)(param_1 + 0x24) < 0) {
    local_28 = -(int)*(short *)(param_1 + 0x24);
  }
  else {
    local_28 = (int)*(short *)(param_1 + 0x24);
  }
  if (local_28 < local_24) {
    local_20 = 0;
  }
  else {
    local_20 = 2;
  }
  iVar2 = (local_10[local_20] * (int)*(short *)(param_1 + 0x26)) /
          (int)*(short *)(param_1 + 0x20 + local_20 * 2);
  iVar1 = (iVar2 << 0x10) / (int)*(short *)(param_1 + 0x26);
  if (local_20 == 0) {
    *param_3 = *(int *)(param_1 + 0x28) + local_10[0];
    param_3[1] = *(int *)(param_1 + 0x2c) + (*(short *)(param_1 + 0x22) * iVar1 >> 0x10);
    param_3[2] = *(int *)(param_1 + 0x30) + (*(short *)(param_1 + 0x24) * iVar1 >> 0x10);
  }
  else {
    *param_3 = *(int *)(param_1 + 0x28) + (*(short *)(param_1 + 0x20) * iVar1 >> 0x10);
    param_3[1] = *(int *)(param_1 + 0x2c) + (*(short *)(param_1 + 0x22) * iVar1 >> 0x10);
    param_3[2] = *(int *)(param_1 + 0x30) + local_10[2];
  }
  return iVar2;
}

