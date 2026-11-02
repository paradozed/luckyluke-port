/* FUN_0048c270 @ 0048c270 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_0048c270(int param_1,uint param_2)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_58 [16];
  undefined1 local_18 [4];
  undefined1 local_14 [4];
  int local_10;
  int local_c;
  uint local_8;
  
  puVar5 = local_58;
  for (iVar4 = 0x15; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0xcccccccc;
    puVar5 = puVar5 + 1;
  }
  local_10 = *(int *)(param_1 + 4 + DAT_004e8ad8 * 4);
  local_8 = (uint)*(ushort *)(param_1 + 2);
  while (local_8 = local_8 - 1, -1 < (int)local_8) {
    FUN_00470c70(param_2 & 0xffff,local_14,local_18);
    uVar3 = FUN_00470bd0(param_2 & 0xffff);
    *(short *)(*(int *)(local_10 + local_8 * 4) + 0x16) = (short)uVar3;
    uVar3 = FUN_00470c20(param_2 & 0xffff);
    *(short *)(*(int *)(local_10 + local_8 * 4) + 0xe) = (short)uVar3;
    local_c = local_8 * 4;
    cVar1 = local_14[0];
    *(char *)(*(int *)(local_10 + local_8 * 4) + 0xc) =
         *(char *)(*(int *)(param_1 + 0xc) + local_8 * 8) + cVar1;
    cVar2 = local_18[0];
    *(char *)(*(int *)(local_10 + local_8 * 4) + 0xd) =
         *(char *)(*(int *)(param_1 + 0xc) + 1 + local_8 * 8) + cVar2;
    *(char *)(*(int *)(local_10 + local_8 * 4) + 0x14) =
         *(char *)(*(int *)(param_1 + 0xc) + 2 + local_8 * 8) + cVar1;
    *(char *)(*(int *)(local_10 + local_8 * 4) + 0x15) =
         *(char *)(*(int *)(param_1 + 0xc) + 3 + local_8 * 8) + cVar2;
    *(char *)(*(int *)(local_10 + local_8 * 4) + 0x1c) =
         *(char *)(*(int *)(param_1 + 0xc) + 4 + local_8 * 8) + cVar1;
    *(char *)(*(int *)(local_10 + local_8 * 4) + 0x1d) =
         *(char *)(*(int *)(param_1 + 0xc) + 5 + local_8 * 8) + cVar2;
    *(char *)(*(int *)(local_10 + local_8 * 4) + 0x24) =
         *(char *)(*(int *)(param_1 + 0xc) + 6 + local_8 * 8) + cVar1;
    *(char *)(*(int *)(local_10 + local_8 * 4) + 0x25) =
         *(char *)(*(int *)(param_1 + 0xc) + 7 + local_8 * 8) + cVar2;
  }
  local_8 = 0x48c45c;
  __chkesp();
  return;
}

