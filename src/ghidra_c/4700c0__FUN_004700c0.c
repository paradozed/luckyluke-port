/* FUN_004700c0 @ 004700c0 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_004700c0(int param_1,undefined2 param_2,short param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  undefined4 *puVar6;
  undefined4 local_58 [17];
  short local_14;
  short local_10;
  short local_c;
  
  puVar6 = local_58;
  for (iVar4 = 0x15; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = 0xcccccccc;
    puVar6 = puVar6 + 1;
  }
  uVar1 = **(uint **)(param_1 + 0xc);
  *(short *)(param_1 + 0x3a) = param_3;
  *(undefined2 *)(param_1 + 0x3c) = *(undefined2 *)(*(int *)(param_1 + 0xc) + 0x10 + param_3 * 0x10)
  ;
  *(undefined2 *)(param_1 + 0x3e) = param_2;
  iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 4 + param_3 * 0x10);
  iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8 + param_3 * 0x10);
  iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 0xc + param_3 * 0x10);
  *(int *)(param_1 + 0x20) = iVar4 - *(int *)(param_1 + 0x10);
  *(int *)(param_1 + 0x24) = iVar2 - *(int *)(param_1 + 0x14);
  *(int *)(param_1 + 0x28) = iVar3 - *(int *)(param_1 + 0x18);
  sVar5 = (short)(((int)param_3 + 1U) % uVar1);
  local_14 = (short)*(undefined4 *)(*(int *)(param_1 + 0xc) + 4 + sVar5 * 0x10) - (short)iVar4;
  local_10 = (short)*(undefined4 *)(*(int *)(param_1 + 0xc) + 8 + sVar5 * 0x10) - (short)iVar2;
  local_c = (short)*(undefined4 *)(*(int *)(param_1 + 0xc) + 0xc + sVar5 * 0x10) - (short)iVar3;
  *(short *)(param_1 + 0x30) = local_14;
  *(short *)(param_1 + 0x32) = local_10;
  *(short *)(param_1 + 0x34) = local_c;
  return;
}

