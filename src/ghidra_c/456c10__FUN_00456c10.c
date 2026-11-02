/* FUN_00456c10 @ 00456c10 */
/* decompiled from Lucky.exe (Game.run) */


void __cdecl FUN_00456c10(int *param_1,ushort param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_48 [16];
  int local_8;
  
  puVar3 = local_48;
  for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0xcccccccc;
    puVar3 = puVar3 + 1;
  }
  local_8 = 0;
  if (*(ushort *)(param_1 + 2) < 10) {
    uVar1 = FUN_00456f30(param_2);
    *(undefined4 *)(*param_1 + (uint)*(ushort *)(param_1 + 2) * 4) = uVar1;
    local_8 = *(int *)(*param_1 + (uint)*(ushort *)(param_1 + 2) * 4);
    *(short *)(param_1 + 2) = (short)param_1[2] + 1;
    uVar1 = FUN_004570b0(local_8);
    *(undefined4 *)(param_1[1] + (uint)*(ushort *)((int)param_1 + 10) * 4) = uVar1;
    *(short *)((int)param_1 + 10) = *(short *)((int)param_1 + 10) + 1;
  }
  local_8 = 0x456cd7;
  __chkesp();
  return;
}

